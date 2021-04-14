

/*
  This program and the accompanying materials are
  made available under the terms of the Eclipse Public License v2.0 which accompanies
  this distribution, and is available at https://www.eclipse.org/legal/epl-v20.html
  
  SPDX-License-Identifier: EPL-2.0
  
  Copyright Contributors to the Zowe Project.
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <iconv.h>
#include <dirent.h>
#include <pthread.h>
#include <regex.h> 

#include "authService.h"
#include "zowetypes.h"
#include "alloc.h"
#include "utils.h"
#ifdef __ZOWE_OS_ZOS
#include "zos.h"
#endif
#include "logging.h"
#include "json.h"
#include "bpxnet.h"
#include "socketmgmt.h"
#include "zis/client.h"
#include "httpserver.h"
#include "zssLogging.h"

#define SAF_CLASS "ZOWE"
#define JSON_ERROR_BUFFER_SIZE 1024

#define SAF_PASSWORD_RESET_RC_OK                0
#define SAF_PASSWORD_RESET_RC_WRONG_PASSWORD    111
#define SAF_PASSWORD_RESET_RC_WRONG_USER        143
#define SAF_PASSWORD_RESET_RC_TOO_MANY_ATTEMPTS 163
#define SAF_PASSWORD_RESET_RC_NO_NEW_PASSSWORD  168
#define SAF_PASSWORD_RESET_RC_WRONG_FORMAT      169

#define RESPONSE_MESSAGE_LENGTH             100

/*
 * A handler performing the SAF_AUTH check: checks if the user has the
 * specified access to the specified entity in the specified class
 *
 * URL format:
 *   GET .../saf-auth/<USERID>/<CLASS>/<ENTITY>/<READ|UPDATE|ALTER|CONTROL>
 * Example: /saf-auth/PDUSR/FACILITY/CQM.CAE.ADMINISTRATOR/READ
 *
 * Response examples:
 *  - The user is authorized: { "authorized": true }
 *  - Not authorized: { "authorized": false, message: "..." }
 *  - Error: {
 *      "error": true,
 *      "message": "..."
 *    }
 */

static int serveAuthCheck(HttpService *service, HttpResponse *response);

const char* getProfileNameFromRequest(char *url, const char *method, int instanceID);

const char* makeProfileName(
  char *type,
  char *productCode, 
  int instanceID, 
  char *pluginID, 
  char *rootServiceName, 
  char *serviceName,
  char *method,
  char *scope,
  char subUrl[15][128]);

int installAuthCheckService(HttpServer *server) {
//  zowelog(NULL, 0, ZOWE_LOG_DEBUG2, "begin %s\n",
//  __FUNCTION__);
  HttpService *httpService = makeGeneratedService("SAF_AUTH service",
      "/saf-auth/**");
  httpService->authType = SERVICE_AUTH_NATIVE_WITH_SESSION_TOKEN;
  httpService->serviceFunction = &serveAuthCheck;
  httpService->runInSubtask = FALSE;
  // Test SAF query: getProfileNameFromRequest("/plugins", "GET", -1);
  registerHttpService(server, httpService);
//  zowelog(NULL, 0, ZOWE_LOG_DEBUG2, "end %s\n",
//  __FUNCTION__);
  return 0;
}

static int extractQuery(StringList *path, char **entity, char **access) {
  const StringListElt *pathElt;

#define TEST_NEXT_AND_SET($ptr) do { \
  pathElt = pathElt->next;           \
  if (pathElt == NULL) {             \
    return -1;                       \
  }                                  \
  *$ptr = pathElt->string;           \
} while (0)

  pathElt = firstStringListElt(path);
  while (pathElt && (strcmp(pathElt->string, "saf-auth") != 0)) {
    pathElt = pathElt->next;
  }
  if (pathElt == NULL) {
    return -1;
  }
  TEST_NEXT_AND_SET(entity);
  TEST_NEXT_AND_SET(access);
  return 0;
#undef TEST_NEXT_AND_SET
}

static int parseAcess(const char inStr[], int *outNum) {
  int rc;

  if (strcasecmp("ALTER", inStr) == 0) {
    *outNum = SAF_AUTH_ATTR_ALTER;
  } else if (strcasecmp("CONTROL", inStr) == 0) {
    *outNum = SAF_AUTH_ATTR_CONTROL;
  } else if (strcasecmp("UPDATE", inStr) == 0) {
    *outNum = SAF_AUTH_ATTR_UPDATE;
  } else if (strcasecmp("READ", inStr) == 0) {
    *outNum = SAF_AUTH_ATTR_READ;
  } else {
    return -1;
  }
  return 0;
}

static void respond(HttpResponse *res, int rc, const ZISAuthServiceStatus
    *reqStatus) {
  jsonPrinter* p = respondWithJsonPrinter(res);

  setResponseStatus(res, HTTP_STATUS_OK, "OK");
  setDefaultJSONRESTHeaders(res);
  writeHeader(res);
  if (rc == RC_ZIS_SRVC_OK) {
    jsonStart(p); {
      jsonAddBoolean(p, "authorized", true);
    }
    jsonEnd(p);
  } else {
    char errBuf[0x100];

#define FORMAT_ERROR($fmt, ...) snprintf(errBuf, sizeof (errBuf), $fmt, \
    ##__VA_ARGS__)

    ZIS_FORMAT_AUTH_CALL_STATUS(rc, reqStatus, FORMAT_ERROR);
#undef FORMAT_ERROR
    jsonStart(p); {
      if (rc == RC_ZIS_SRVC_SERVICE_FAILED
          && reqStatus->safStatus.safRC != 0) {
        jsonAddBoolean(p, "authorized", false);
      } else {
        jsonAddBoolean(p, "error", true);
      }
      jsonAddString(p, "message", errBuf);
    }
    jsonEnd(p);
  }
  finishResponse(res);
}

static int serveAuthCheck(HttpService *service, HttpResponse *res) {
  HttpRequest *req = res->request;
  char *entity, *accessStr;
  int access = 0;
  int rc = 0, rsn = 0, safStatus = 0;
  ZISAuthServiceStatus reqStatus = {0};
  CrossMemoryServerName *privilegedServerName;
  const char *userName = req->username, *class = SAF_CLASS;
  rc = extractQuery(req->parsedFile, &entity, &accessStr);
  if (rc != 0) {
    respondWithError(res, HTTP_STATUS_BAD_REQUEST, "Broken auth query");
    return 0;
  }
  rc = parseAcess(accessStr, &access);
  if (rc != 0) {
    respondWithError(res, HTTP_STATUS_BAD_REQUEST, "Unexpected access level");
    return 0;
  }
  // printf("\n\nquery: user %s, class %s, entity %s, access %d accessStr %s\n", userName, class,
      // entity, access, accessStr);
  privilegedServerName = getConfiguredProperty(service->server,
      HTTP_SERVER_PRIVILEGED_SERVER_PROPERTY);
  rc = zisCheckEntity(privilegedServerName, userName, class, entity, access,
      &reqStatus);
      printf("\n\nprivileged server name: %s", privilegedServerName);
  respond(res, rc, &reqStatus);
  return 0;
}

const char* getProfileNameFromRequest(char *url, char *method, int instanceID) {
  char type[8]; // core || config || service
  char productCode[128];
  char rootServiceName[128];
  char subUrl[15][128];
  char profileName[1024];
  char scope[128];
  char _p[128], pluginID[128], _s[128], serviceName[128], _v[128];
  char regexStr[] = "^/[A-Za-z0-9]*/plugins/";
  
  regex_t regex;
  int value;
  value = regcomp(&regex, regexStr, REG_EXTENDED);

  if (value != 0) {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_DEBUG2,
           "RegEx compiled successfully.");
  } else {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_DEBUG2,
           "RegEx compilation error %s.", regexStr);
  }
  value = regexec(&regex, url, 0, NULL, 0);
  char urlCpy[1024];
  strcpy(urlCpy, url);
  int index = 0;
  while (urlCpy[index]) { // Capitalize query
      urlCpy[index] = toupper(urlCpy[index]);
      index++;
  }
  if (instanceID < 0) { // Set instanceID
    instanceID = 0;
  }
  if (value == REG_NOMATCH) {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_DEBUG2,
           "RegEx didn't match.");
    char * token = strtok(urlCpy, "/");
    int subUrlIndex = -1;
    while( token != NULL ) {
      if (strcmp(rootServiceName, NULL) == 0)
      {
        strcpy(rootServiceName, token);
      } else {
        strcpy(subUrl[subUrlIndex], token);
      }
      subUrlIndex++;
      token = strtok(NULL, "/");
    }
    strcpy(productCode, "ZLUX");
    strcpy(type, "core");
  }
  else if (!value) {
    char * token = strtok(urlCpy, "/");
    int subUrlIndex;
    subUrlIndex = 0;
    while( token != NULL ) {
      switch(subUrlIndex) {
        case 0:
          strcpy(productCode, token);
          break;
        case 1:
          strcpy(_p, token);
          break;
        case 2:
          strcpy(pluginID, token);
          break;
        case 3:
          strcpy(_s, token);
          break;
        case 4:
          strcpy(serviceName, token);
          break;
        case 5:
          strcpy(_v, token);
          break;
        default:
          strcpy(subUrl[subUrlIndex-6], token); // subtract 6 from maximum index to begin init subUrl array at 0
      }
      
      subUrlIndex++;
      token = strtok(NULL, "/");
    }
    if ((strcmp(pluginID, "ORG.ZOWE.CONFIGJS") == 0) && (strcmp(serviceName, "DATA") == 0))
    {
      strcpy(type, "config");
      strcpy(pluginID, subUrl[0]);
      strcpy(scope, subUrl[1]);
      
    } else {
      strcpy(type, "service");
    }
    char* ch; 
    char* chReplace;
    ch = ".";
    chReplace = "_";
    for (index = 0; index <= strlen(pluginID); index++)
  	{
  		if (pluginID[index] == *ch)  
      {
        pluginID[index] = *chReplace;
      }
    }
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_DEBUG2,
           "RegEx match OK.");
  }
  else {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
           "RegEx match failed.");
  }
  strcpy(profileName, makeProfileName(type, 
    productCode, 
    instanceID, 
    pluginID, 
    rootServiceName,
    serviceName,
    method,
    scope,
    subUrl));
  // printf("\n\nFinal query profileName & URL %s - %s\n\n", profileName, url);
  
  /* Free memory allocated to the pattern buffer by regcomp() */
  regfree(&regex);
  return profileName;
}

const char* makeProfileName(
  char *type,
  char *productCode, 
  int instanceID, 
  char *pluginID, 
  char *rootServiceName, 
  char *serviceName,
  char *method,
  char *scope,
  char subUrl[1024][128]) {
  char profileName[1024] = "";
  if (strcmp(productCode, NULL) == 0) {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
           "Broken SAF query. Missing product code.");
    return NULL;
  }
  if (instanceID == -1) {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
           "Broken SAF query. Missing instance ID.");
    return NULL;
  }
  if (strcmp(method, NULL) == 0) {
    zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
           "Broken SAF query. Missing method.");
    return NULL;
  }
  // char someString[128] = { strcpy(*someString, type) };
  if (strcmp(type, "service") == 0) {
    if (strcmp(pluginID, NULL) == 0) {
      zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
       "Broken SAF query. Missing plugin ID.");
      return NULL;
    }
    if (strcmp(serviceName, NULL) == 0) {
      zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
       "Broken SAF query. Missing service name.");
      return NULL;
    }
    snprintf(profileName, 1024, "%s.%d.SVC.%s.%s.%s", productCode, instanceID, pluginID, serviceName, method);
    return profileName;
    
  } else if (strcmp(type, "config") == 0) {
    if (strcmp(pluginID, NULL) == 0) {
      zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
       "Broken SAF query. Missing plugin ID.");
      return NULL;
    }
    if (strcmp(scope, NULL) == 0) {
      zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
       "Broken SAF query. Missing scope.");
      return NULL;
    }
    snprintf(profileName, 1024, "%s.%d.CFG.%s.%s.%s", productCode, instanceID, pluginID, method, scope); 
    return profileName;
  } else if (strcmp(type, "core") == 0) {
    if (strcmp(rootServiceName, NULL) == 0) {
      zowelog(NULL, LOG_COMP_ID_SECURITY, ZOWE_LOG_WARNING,
       "Broken SAF query. Missing root service name.");
      return NULL;
    }
    snprintf(profileName, 1024, "%s.%d.COR.%s.%s", productCode, instanceID, method, rootServiceName); 
    return profileName;
  }
}

/* Method goes here to do the same thing serveAuthCheck is doing except w/o input HttpService */

void respondWithJsonStatus(HttpResponse *response, const char *status, int statusCode, const char *statusMessage) {
    jsonPrinter *out = respondWithJsonPrinter(response);
    setResponseStatus(response,statusCode,(char *)statusMessage);
    setDefaultJSONRESTHeaders(response);
    writeHeader(response);

    jsonStart(out);
    jsonAddString(out, "status", (char *)status);
    jsonEnd(out);

    finishResponse(response);
}

static int resetPassword(HttpService *service, HttpResponse *response) {
  int returnCode = 0, reasonCode = 0;
  HttpRequest *request = response->request;
  
  if (!strcmp(request->method, methodPOST)) {
    char *inPtr = request->contentBody;
    char *nativeBody = copyStringToNative(request->slh, inPtr, strlen(inPtr));
    int inLen = nativeBody == NULL ? 0 : strlen(nativeBody);
    char errBuf[JSON_ERROR_BUFFER_SIZE];
    char responseString[RESPONSE_MESSAGE_LENGTH];

    if (nativeBody == NULL) {
      respondWithJsonStatus(response, "No body found", HTTP_STATUS_BAD_REQUEST, "Bad Request");
      return HTTP_SERVICE_FAILED;
    }
    
    Json *body = jsonParseUnterminatedString(request->slh, nativeBody, inLen, errBuf, JSON_ERROR_BUFFER_SIZE);
    
    if (body == NULL) {
      respondWithJsonStatus(response, "No body found", HTTP_STATUS_BAD_REQUEST, "Bad Request");
      return HTTP_SERVICE_FAILED;
    }
    
    JsonObject *inputMessage = jsonAsObject(body);
    Json *username = jsonObjectGetPropertyValue(inputMessage,"username");
    Json *password = jsonObjectGetPropertyValue(inputMessage,"password");
    Json *newPassword = jsonObjectGetPropertyValue(inputMessage,"newPassword");
    int usernameLength = 0;
    int passwordLength = 0;
    int newPasswordLength = 0;
    if (username != NULL) {
      if (jsonAsString(username) != NULL) {
        usernameLength = strlen(jsonAsString(username));
      }
    }
    if (password != NULL) {
      if (jsonAsString(password) != NULL) {
        passwordLength = strlen(jsonAsString(password));
      }
    }
    if (newPassword != NULL) {
      if (jsonAsString(newPassword) != NULL) {
        newPasswordLength = strlen(jsonAsString(newPassword));
      }
    }
    if (usernameLength == 0) {
      respondWithJsonStatus(response, "No username provided",
                            HTTP_STATUS_BAD_REQUEST, "Bad Request");
      return HTTP_SERVICE_FAILED;
    }
    if (passwordLength == 0) {
      respondWithJsonStatus(response, "No password provided",
                            HTTP_STATUS_BAD_REQUEST, "Bad Request");
      return HTTP_SERVICE_FAILED;
    }
    if (newPasswordLength == 0) {
      respondWithJsonStatus(response, "No new password provided",
                            HTTP_STATUS_BAD_REQUEST, "Bad Request");
      return HTTP_SERVICE_FAILED;
    }
    resetZosUserPassword(jsonAsString(username),  jsonAsString(password), jsonAsString(newPassword), &returnCode, &reasonCode);

    switch (returnCode) {
      case SAF_PASSWORD_RESET_RC_OK:
        respondWithJsonStatus(response, "Password Successfully Reset", HTTP_STATUS_OK, "OK");
        return HTTP_SERVICE_SUCCESS;
      case SAF_PASSWORD_RESET_RC_WRONG_PASSWORD:
        respondWithJsonStatus(response, "Username or password is incorrect. Please try again.",
                              HTTP_STATUS_UNAUTHORIZED, "Unauthorized");
        return HTTP_SERVICE_FAILED;
      case SAF_PASSWORD_RESET_RC_WRONG_USER:
        respondWithJsonStatus(response, "Username or password is incorrect. Please try again.",
                              HTTP_STATUS_UNAUTHORIZED, "Unauthorized");
        return HTTP_SERVICE_FAILED;
      case SAF_PASSWORD_RESET_RC_NO_NEW_PASSSWORD:
        respondWithJsonStatus(response, "No new password provided",
                              HTTP_STATUS_BAD_REQUEST, "Bad Request");
        return HTTP_SERVICE_FAILED;
      case SAF_PASSWORD_RESET_RC_WRONG_FORMAT:
        respondWithJsonStatus(response, "The new password format is incorrect. Please try again.",
                              HTTP_STATUS_BAD_REQUEST, "Bad Request");
        return HTTP_SERVICE_FAILED;
      case SAF_PASSWORD_RESET_RC_TOO_MANY_ATTEMPTS:
        respondWithJsonStatus(response,
                              "Incorrect password or account is locked. Please contact your administrator.",
                              HTTP_STATUS_TOO_MANY_REQUESTS, "Bad Request");
        return HTTP_SERVICE_FAILED;
      default:
        snprintf(responseString, RESPONSE_MESSAGE_LENGTH, "Password reset FAILED with return code: %d reason code: %d", returnCode, reasonCode);
        respondWithJsonStatus(response, responseString, HTTP_STATUS_BAD_REQUEST, "Bad Request");
        return HTTP_SERVICE_FAILED;
    }
  } else {
    respondWithJsonStatus(response, "Method Not Allowed",
                          HTTP_STATUS_METHOD_NOT_FOUND, "Method Not Allowed");
    return HTTP_SERVICE_FAILED;
  }
}

void installZosPasswordService(HttpServer *server) {
  zowelog(NULL, LOG_COMP_ID_MVD_SERVER, ZOWE_LOG_DEBUG2, "begin %s\n", __FUNCTION__);

  HttpService *httpService = makeGeneratedService("password service", "/password/**");
  httpService->authType = SERVICE_AUTH_NONE;
  httpService->runInSubtask = TRUE;
  httpService->serviceFunction = resetPassword;
  registerHttpService(server, httpService);
  zowelog(NULL, LOG_COMP_ID_MVD_SERVER, ZOWE_LOG_DEBUG2, "end %s\n", __FUNCTION__);
}

/*
  This program and the accompanying materials are
  made available under the terms of the Eclipse Public License v2.0 which accompanies
  this distribution, and is available at https://www.eclipse.org/legal/epl-v20.html
  
  SPDX-License-Identifier: EPL-2.0
  
  Copyright Contributors to the Zowe Project.
*/

