/*
  This program and the accompanying materials are
  made available under the terms of the Eclipse Public License v2.0 which accompanies
  this distribution, and is available at https://www.eclipse.org/legal/epl-v20.html

  SPDX-License-Identifier: EPL-2.0

  Copyright Contributors to the Zowe Project.
*/
    stubVector[ZIS_STUB_DYNZISUD] = (void*)zisdynUndefinedStub;
    stubVector[ZIS_STUB_ZISDYNSV] = (void*)zisdynGetStubVersion;
    stubVector[ZIS_STUB_ZISDYNPV] = (void*)zisdynGetPluginVersion;
    stubVector[ZIS_STUB_ZISGVRSN] = (void*)zisGetServerVersion;
    stubVector[ZIS_STUB_ZISLPADV] = (void*)zisIsLPADevModeOn;
    stubVector[ZIS_STUB_ZISCSRVC] = (void*)zisCallService;
    stubVector[ZIS_STUB_ZISCUSVC] = (void*)zisCallServiceUnchecked;
    stubVector[ZIS_STUB_ZISCVSVC] = (void*)zisCallVersionedService;
    stubVector[ZIS_STUB_ZISGDSNM] = (void*)zisGetDefaultServerName;
    stubVector[ZIS_STUB_ZISCOPYD] = (void*)zisCopyDataFromAddressSpace;
    stubVector[ZIS_STUB_ZISUNPWD] = (void*)zisCheckUsernameAndPassword;
    stubVector[ZIS_STUB_ZISSAUTH] = (void*)zisCheckEntity;
    stubVector[ZIS_STUB_ZISGETAC] = (void*)zisGetSAFAccessLevel;
    stubVector[ZIS_STUB_ZISCNWMS] = (void*)zisCallNWMService;
    stubVector[ZIS_STUB_ZISUPROF] = (void*)zisExtractUserProfiles;
    stubVector[ZIS_STUB_ZISGRROF] = (void*)zisExtractGenresProfiles;
    stubVector[ZIS_STUB_ZISGRAST] = (void*)zisExtractGenresAccessList;
    stubVector[ZIS_STUB_ZISDFPRF] = (void*)zisDefineProfile;
    stubVector[ZIS_STUB_ZISDLPRF] = (void*)zisDeleteProfile;
    stubVector[ZIS_STUB_ZISGAPRF] = (void*)zisGiveAccessToProfile;
    stubVector[ZIS_STUB_ZISRAPRF] = (void*)zisRevokeAccessToProfile;
    stubVector[ZIS_STUB_ZISXGRPP] = (void*)zisExtractGroupProfiles;
    stubVector[ZIS_STUB_ZISXGRPA] = (void*)zisExtractGroupAccessList;
    stubVector[ZIS_STUB_ZISADDGP] = (void*)zisAddGroup;
    stubVector[ZIS_STUB_ZISDELGP] = (void*)zisDeleteGroup;
    stubVector[ZIS_STUB_ZISADDCN] = (void*)zisConnectToGroup;
    stubVector[ZIS_STUB_ZISREMCN] = (void*)zisRemoveFromGroup;
    stubVector[ZIS_STUB_ZISGVSAA] = (void*)zisGenerateOrValidateSafIdtWithAppl;
    stubVector[ZIS_STUB_ZISGVSAF] = (void*)zisGenerateOrValidateSafIdt;
    stubVector[ZIS_STUB_ZISMAKPS] = (void*)zisMakeParmSet;
    stubVector[ZIS_STUB_ZISREMPS] = (void*)zisRemoveParmSet;
    stubVector[ZIS_STUB_ZISRDLIB] = (void*)zisReadParmlib;
    stubVector[ZIS_STUB_ZISRDMPR] = (void*)zisReadMainParms;
    stubVector[ZIS_STUB_ZISPUTPV] = (void*)zisPutParmValue;
    stubVector[ZIS_STUB_ZISGETPV] = (void*)zisGetParmValue;
    stubVector[ZIS_STUB_ZISLOADP] = (void*)zisLoadParmsToCMServer;
    stubVector[ZIS_STUB_ZISITERP] = (void*)zisIterateParms;
    stubVector[ZIS_STUB_ZISCPLGN] = (void*)zisCreatePlugin;
    stubVector[ZIS_STUB_ZISDSTPL] = (void*)zisDestroyPlugin;
    stubVector[ZIS_STUB_ZISPLGAS] = (void*)zisPluginAddService;
    stubVector[ZIS_STUB_ZISPLGCA] = (void*)zisCreatePluginAnchor;
    stubVector[ZIS_STUB_ZISPLGRM] = (void*)zisRemovePluginAnchor;
    stubVector[ZIS_STUB_ZISCRSVC] = (void*)zisCreateService;
    stubVector[ZIS_STUB_ZISCSWSV] = (void*)zisCreateSpaceSwitchService;
    stubVector[ZIS_STUB_ZISCCPSV] = (void*)zisCreateCurrentPrimaryService;
    stubVector[ZIS_STUB_ZISCSVCA] = (void*)zisCreateServiceAnchor;
    stubVector[ZIS_STUB_ZISRSVCA] = (void*)zisRemoveServiceAnchor;
    stubVector[ZIS_STUB_ZISUSVCA] = (void*)zisUpdateServiceAnchor;
    stubVector[ZIS_STUB_ZISUSAUT] = (void*)zisServiceUseSpecificAuth;
    stubVector[ZIS_STUB_ZISAMMDR] = (void*)zisAUXMakeModuleDescriptor;
    stubVector[ZIS_STUB_ZISADMDR] = (void*)zisAUXDestroyModuleDescriptor;
    stubVector[ZIS_STUB_ZISAMIN ] = (void*)zisauxMgrInit;
    stubVector[ZIS_STUB_ZISAMCL ] = (void*)zisauxMgrClean;
    stubVector[ZIS_STUB_ZISAMHS ] = (void*)zisauxMgrSetHostSTC;
    stubVector[ZIS_STUB_ZISAMST ] = (void*)zisauxMgrStartGuest;
    stubVector[ZIS_STUB_ZISAMST2] = (void*)zisauxMgrStartGuest2;
    stubVector[ZIS_STUB_ZISAMSP ] = (void*)zisauxMgrStopGuest;
    stubVector[ZIS_STUB_ZISAICMD] = (void*)zisauxMgrInitCommand;
    stubVector[ZIS_STUB_ZISACCMD] = (void*)zisauxMgrCleanCommand;
    stubVector[ZIS_STUB_ZISAIRQP] = (void*)zisauxMgrInitRequestPayload;
    stubVector[ZIS_STUB_ZISACRQP] = (void*)zisauxMgrCleanRequestPayload;
    stubVector[ZIS_STUB_ZISAIRSP] = (void*)zisauxMgrInitRequestResponse;
    stubVector[ZIS_STUB_ZISACRSP] = (void*)zisauxMgrCleanRequestResponse;
    stubVector[ZIS_STUB_ZISADRSP] = (void*)zisauxMgrCopyRequestResponseData;
    stubVector[ZIS_STUB_ZISAMTM ] = (void*)zisauxMgrSendTermSignal;
    stubVector[ZIS_STUB_ZISAMCM ] = (void*)zisauxMgrSendCommand;
    stubVector[ZIS_STUB_ZISAMWK ] = (void*)zisauxMgrSendWork;
    stubVector[ZIS_STUB_ZISAMWT ] = (void*)zisauxMgrWaitForTerm;
    stubVector[ZIS_STUB_AUXUPPFX] = (void*)auxutilPrintWithPrefix;
    stubVector[ZIS_STUB_AUXUDMSG] = (void*)auxutilDumpWithEmptyMessageID;
    stubVector[ZIS_STUB_AUXUTKNS] = (void*)auxutilTokenizeString;
    stubVector[ZIS_STUB_AUXUGTCB] = (void*)auxutilGetTCBKey;
    stubVector[ZIS_STUB_AUXUGCK ] = (void*)auxutilGetCallersKey;
    stubVector[ZIS_STUB_AUXUWT  ] = (void*)auxutilWait;
    stubVector[ZIS_STUB_AUXUPST ] = (void*)auxutilPost;
    stubVector[ZIS_STUB_AUXUSLP ] = (void*)auxutilSleep;
    stubVector[ZIS_STUB_MALLOC31] = (void*)malloc31;
    stubVector[ZIS_STUB_FREE31  ] = (void*)free31;
    stubVector[ZIS_STUB_SAFEMLLC] = (void*)safeMalloc;
    stubVector[ZIS_STUB_SAFEMLC2] = (void*)safeMalloc2;
    stubVector[ZIS_STUB_SAFMLC31] = (void*)safeMalloc31;
    stubVector[ZIS_STUB_SAFMLC38] = (void*)safeMalloc31Key8;
    stubVector[ZIS_STUB_SAFEFREE] = (void*)safeFree;
    stubVector[ZIS_STUB_SAFFRE31] = (void*)safeFree31;
    stubVector[ZIS_STUB_SAFFRE38] = (void*)safeFree31Key8;
    stubVector[ZIS_STUB_SAFFRE64] = (void*)safeFree64;
    stubVector[ZIS_STUB_SFFRE64T] = (void*)safeFree64ByToken;
    stubVector[ZIS_STUB_SAFMLC64] = (void*)safeMalloc64;
    stubVector[ZIS_STUB_SFMLC64T] = (void*)safeMalloc64ByToken;
    stubVector[ZIS_STUB_SAFRE642] = (void*)safeFree64v2;
    stubVector[ZIS_STUB_SAMLC642] = (void*)safeMalloc64v2;
    stubVector[ZIS_STUB_SAFRE643] = (void*)safeFree64v3;
    stubVector[ZIS_STUB_SAMLC643] = (void*)safeMalloc64v3;
    stubVector[ZIS_STUB_ALLCECSA] = (void*)allocECSA;
    stubVector[ZIS_STUB_FREEECSA] = (void*)freeECSA;
    stubVector[ZIS_STUB_ASCREATE] = (void*)addressSpaceCreate;
    stubVector[ZIS_STUB_ASCREATT] = (void*)addressSpaceCreateWithTerm;
    stubVector[ZIS_STUB_ASTERMIN] = (void*)addressSpaceTerminate;
    stubVector[ZIS_STUB_ASEXTRCT] = (void*)addressSpaceExtractParm;
    stubVector[ZIS_STUB_GETLOCHN] = (void*)getLocalHostName;
    stubVector[ZIS_STUB_GETSOCDI] = (void*)getSocketDebugID;
    stubVector[ZIS_STUB_GETLOCAD] = (void*)getLocalHostAddress;
    stubVector[ZIS_STUB_GETADRBN] = (void*)getAddressByName;
    stubVector[ZIS_STUB_GETSOCNM] = (void*)getSocketName;
    stubVector[ZIS_STUB_GETSOCN2] = (void*)getSocketName2;
    stubVector[ZIS_STUB_TCPCLIE1] = (void*)tcpClient;
    stubVector[ZIS_STUB_GTSKTOPT] = (void*)getSocketOption;
    stubVector[ZIS_STUB_TCPCLIE2] = (void*)tcpClient2;
    stubVector[ZIS_STUB_TCPSERVR] = (void*)tcpServer;
    stubVector[ZIS_STUB_TCPCLIE3] = (void*)tcpClient3;
    stubVector[ZIS_STUB_TCPSERV2] = (void*)tcpServer2;
    stubVector[ZIS_STUB_MAKSPSOC] = (void*)makePipeBasedSyntheticSocket;
    stubVector[ZIS_STUB_BPXSLEEP] = (void*)bpxSleep;
    stubVector[ZIS_STUB_TCPIOCTR] = (void*)tcpIOControl;
    stubVector[ZIS_STUB_UDPPEER ] = (void*)udpPeer;
    stubVector[ZIS_STUB_UDPRECVF] = (void*)udpReceiveFrom;
    stubVector[ZIS_STUB_UDPSENDT] = (void*)udpSendTo;
    stubVector[ZIS_STUB_MAKSOCST] = (void*)makeSocketSet;
    stubVector[ZIS_STUB_FRESOCST] = (void*)freeSocketSet;
    stubVector[ZIS_STUB_SOCSTADD] = (void*)socketSetAdd;
    stubVector[ZIS_STUB_SOCSTREM] = (void*)socketSetRemove;
    stubVector[ZIS_STUB_TCPSTTUS] = (void*)tcpStatus;
    stubVector[ZIS_STUB_SOCREAD ] = (void*)socketRead;
    stubVector[ZIS_STUB_SOCWRITE] = (void*)socketWrite;
    stubVector[ZIS_STUB_SETSKTTO] = (void*)setSocketTimeout;
    stubVector[ZIS_STUB_SETSKTND] = (void*)setSocketNoDelay;
    stubVector[ZIS_STUB_SETSKTWB] = (void*)setSocketWriteBufferSize;
    stubVector[ZIS_STUB_SETSKTRB] = (void*)setSocketReadBufferSize;
    stubVector[ZIS_STUB_SETSOCBM] = (void*)setSocketBlockingMode;
    stubVector[ZIS_STUB_SETSKTOP] = (void*)setSocketOption;
    stubVector[ZIS_STUB_SOCKSEND] = (void*)socketSend;
    stubVector[ZIS_STUB_SOCACCPT] = (void*)socketAccept;
    stubVector[ZIS_STUB_SOCCLOSE] = (void*)socketClose;
    stubVector[ZIS_STUB_EXSELECT] = (void*)extendedSelect;
    stubVector[ZIS_STUB_MACSOCAD] = (void*)makeSocketAddr;
    stubVector[ZIS_STUB_MACSOCA6] = (void*)makeSocketAddrIPv6;
    stubVector[ZIS_STUB_FRESOCAD] = (void*)freeSocketAddr;
    stubVector[ZIS_STUB_SOCFREE ] = (void*)socketFree;
    stubVector[ZIS_STUB_CPASIZE ] = (void*)cellpoolGetDWordAlignedSize;
    stubVector[ZIS_STUB_CPFREE  ] = (void*)cellpoolFree;
    stubVector[ZIS_STUB_CPGET   ] = (void*)cellpoolGet;
    stubVector[ZIS_STUB_CPDELETE] = (void*)cellpoolDelete;
    stubVector[ZIS_STUB_CPBUILD ] = (void*)cellpoolBuild;
    stubVector[ZIS_STUB_CMCPWDK ] = (void*)cmCopyWithDestinationKey;
    stubVector[ZIS_STUB_CMCPWSK ] = (void*)cmCopyWithSourceKey;
    stubVector[ZIS_STUB_CMCPTSSK] = (void*)cmCopyToSecondaryWithCallerKey;
    stubVector[ZIS_STUB_CMCPFSSK] = (void*)cmCopyFromSecondaryWithCallerKey;
    stubVector[ZIS_STUB_CMCPTPSK] = (void*)cmCopyToPrimaryWithCallerKey;
    stubVector[ZIS_STUB_CMCPFPSK] = (void*)cmCopyFromPrimaryWithCallerKey;
    stubVector[ZIS_STUB_CMCPTHSK] = (void*)cmCopyToHomeWithCallerKey;
    stubVector[ZIS_STUB_CMCPFHSK] = (void*)cmCopyFromHomeWithCallerKey;
    stubVector[ZIS_STUB_CMCPYSKA] = (void*)cmCopyWithSourceKeyAndALET;
    stubVector[ZIS_STUB_CMGAACEE] = (void*)cmGetCallerAddressSpaceACEE;
    stubVector[ZIS_STUB_CMGTACEE] = (void*)cmGetCallerTaskACEE;
    stubVector[ZIS_STUB_CMALLOC ] = (void*)cmAlloc;
    stubVector[ZIS_STUB_CMFREE  ] = (void*)cmFree;
    stubVector[ZIS_STUB_CMALLOC2] = (void*)cmAlloc2;
    stubVector[ZIS_STUB_CMFREE2 ] = (void*)cmFree2;
    stubVector[ZIS_STUB_CMUMKMAP] = (void*)makeCrossMemoryMap;
    stubVector[ZIS_STUB_CMURMMAP] = (void*)removeCrossMemoryMap;
    stubVector[ZIS_STUB_CMUMAPP ] = (void*)crossMemoryMapPut;
    stubVector[ZIS_STUB_CMUMAPGH] = (void*)crossMemoryMapGetHandle;
    stubVector[ZIS_STUB_CMUMAPGT] = (void*)crossMemoryMapGet;
    stubVector[ZIS_STUB_CMUMAPIT] = (void*)crossMemoryMapIterate;
    stubVector[ZIS_STUB_FBMGRCRT] = (void*)fbMgrCreate;
    stubVector[ZIS_STUB_FBMGRALC] = (void*)fbMgrAlloc;
    stubVector[ZIS_STUB_FBMGRFRE] = (void*)fbMgrFree;
    stubVector[ZIS_STUB_FBMGRDST] = (void*)fbMgrDestroy;
    stubVector[ZIS_STUB_HTCREATE] = (void*)htCreate;
    stubVector[ZIS_STUB_HTALTER ] = (void*)htAlter;
    stubVector[ZIS_STUB_HTGET   ] = (void*)htGet;
    stubVector[ZIS_STUB_HTINTGET] = (void*)htIntGet;
    stubVector[ZIS_STUB_HTPUT   ] = (void*)htPut;
    stubVector[ZIS_STUB_HTINTPUT] = (void*)htIntPut;
    stubVector[ZIS_STUB_HTUINTPT] = (void*)htUIntPut;
    stubVector[ZIS_STUB_HTUINTGT] = (void*)htUIntGet;
    stubVector[ZIS_STUB_HTREMOVE] = (void*)htRemove;
    stubVector[ZIS_STUB_HTMAP   ] = (void*)htMap;
    stubVector[ZIS_STUB_HTMAP2  ] = (void*)htMap2;
    stubVector[ZIS_STUB_HTPRUNE ] = (void*)htPrune;
    stubVector[ZIS_STUB_HTDSTROY] = (void*)htDestroy;
    stubVector[ZIS_STUB_HTCOUNT ] = (void*)htCount;
    stubVector[ZIS_STUB_STRNGHSH] = (void*)stringHash;
    stubVector[ZIS_STUB_STRNGCMP] = (void*)stringCompare;
    stubVector[ZIS_STUB_MKLRUCHE] = (void*)makeLRUCache;
    stubVector[ZIS_STUB_DSLRUCHE] = (void*)destroyLRUCache;
    stubVector[ZIS_STUB_LRUGET  ] = (void*)lruGet;
    stubVector[ZIS_STUB_LRUSTORE] = (void*)lruStore;
    stubVector[ZIS_STUB_LNHTCRTE] = (void*)lhtCreate;
    stubVector[ZIS_STUB_LNHTALTR] = (void*)lhtAlter;
    stubVector[ZIS_STUB_LNHDSTRY] = (void*)lhtDestroy;
    stubVector[ZIS_STUB_LNHTGET ] = (void*)lhtGet;
    stubVector[ZIS_STUB_LNHTPUT ] = (void*)lhtPut;
    stubVector[ZIS_STUB_LNHTREMV] = (void*)lhtRemove;
    stubVector[ZIS_STUB_LNHTMAP ] = (void*)lhtMap;
    stubVector[ZIS_STUB_MAKELCFQ] = (void*)makeQueue;
    stubVector[ZIS_STUB_DSTRLCFQ] = (void*)destroyQueue;
    stubVector[ZIS_STUB_QENQUEUE] = (void*)qEnqueue;
    stubVector[ZIS_STUB_QDEQUEUE] = (void*)qDequeue;
    stubVector[ZIS_STUB_QINSERT ] = (void*)qInsert;
    stubVector[ZIS_STUB_QREMOVE ] = (void*)qRemove;
    stubVector[ZIS_STUB_ALSTMAKE] = (void*)makeArrayList;
    stubVector[ZIS_STUB_ALSTFREE] = (void*)arrayListFree;
    stubVector[ZIS_STUB_ALSTADD ] = (void*)arrayListAdd;
    stubVector[ZIS_STUB_ALSTELMT] = (void*)arrayListElement;
    stubVector[ZIS_STUB_ALINEMAR] = (void*)initEmbeddedArrayList;
    stubVector[ZIS_STUB_ALSTSORT] = (void*)arrayListSort;
    stubVector[ZIS_STUB_ALSHLCPY] = (void*)arrayListShallowCopy;
    stubVector[ZIS_STUB_CPL64CRE] = (void*)iarcp64Create;
    stubVector[ZIS_STUB_CPL64GET] = (void*)iarcp64Get;
    stubVector[ZIS_STUB_CPL64FRE] = (void*)iarcp64Free;
    stubVector[ZIS_STUB_CPL64DEL] = (void*)iarcp64Delete;
    stubVector[ZIS_STUB_CMGETGA ] = (void*)cmsGetGlobalArea;
    stubVector[ZIS_STUB_CMTSAUTH] = (void*)cmsTestAuth;
    stubVector[ZIS_STUB_CMCMSRCS] = (void*)cmsCallService;
    stubVector[ZIS_STUB_CMCALLS2] = (void*)cmsCallService2;
    stubVector[ZIS_STUB_CMCALLS3] = (void*)cmsCallService3;
    stubVector[ZIS_STUB_CMCMSPRF] = (void*)cmsPrintf;
    stubVector[ZIS_STUB_CMCMSVPF] = (void*)vcmsPrintf;
    stubVector[ZIS_STUB_CMHEXDMP] = (void*)cmsHexDump;
    stubVector[ZIS_STUB_CMGETPRM] = (void*)cmsGetConfigParm;
    stubVector[ZIS_STUB_CMGETPRU] = (void*)cmsGetConfigParmUnchecked;
    stubVector[ZIS_STUB_CMGETLOG] = (void*)cmsGetPCLogLevel;
    stubVector[ZIS_STUB_CMGETSTS] = (void*)cmsGetStatus;
    stubVector[ZIS_STUB_CMMKSNAM] = (void*)cmsMakeServerName;
    stubVector[ZIS_STUB_DYNASTXU] = (void*)createSimpleTextUnit;
    stubVector[ZIS_STUB_DYNASTX2] = (void*)createSimpleTextUnit2;
    stubVector[ZIS_STUB_DYNACTXU] = (void*)createCharTextUnit;
    stubVector[ZIS_STUB_DYNACMTU] = (void*)createCompoundTextUnit;
    stubVector[ZIS_STUB_DYNAITXU] = (void*)createIntTextUnit;
    stubVector[ZIS_STUB_DYNAI1TU] = (void*)createInt8TextUnit;
    stubVector[ZIS_STUB_DYNAI2TU] = (void*)createInt16TextUnit;
    stubVector[ZIS_STUB_DYNAFTXU] = (void*)freeTextUnit;
    stubVector[ZIS_STUB_DYNAAIRD] = (void*)AllocIntReader;
    stubVector[ZIS_STUB_DYNASLIB] = (void*)dynallocSharedLibrary;
    stubVector[ZIS_STUB_DYNAUSSD] = (void*)dynallocUSSDirectory;
    stubVector[ZIS_STUB_DYNAUSSO] = (void*)dynallocUSSOutput;
    stubVector[ZIS_STUB_DYNASAPI] = (void*)AllocForSAPI;
    stubVector[ZIS_STUB_DYNADOUT] = (void*)AllocForDynamicOutput;
    stubVector[ZIS_STUB_DYNADDDN] = (void*)DeallocDDName;
    stubVector[ZIS_STUB_DYNAUALC] = (void*)dynallocDataset;
    stubVector[ZIS_STUB_DYNAUALM] = (void*)dynallocDatasetMember;
    stubVector[ZIS_STUB_DYNADALC] = (void*)unallocDataset;
    stubVector[ZIS_STUB_DYNALAD2] = (void*)dynallocAllocDataset;
    stubVector[ZIS_STUB_DYNALUD2] = (void*)dynallocUnallocDatasetByDDName;
    stubVector[ZIS_STUB_RSIDCCCM] = (void*)idcamsCreateCommand;
    stubVector[ZIS_STUB_RSIDCALN] = (void*)idcamsAddLineToCommand;
    stubVector[ZIS_STUB_RSIDCEXE] = (void*)idcamsExecuteCommand;
    stubVector[ZIS_STUB_RSIDCDCM] = (void*)idcamsDeleteCommand;
    stubVector[ZIS_STUB_RSIDCPCO] = (void*)idcamsPrintCommandOutput;
    stubVector[ZIS_STUB_RSIDCDCO] = (void*)idcamsDeleteCommandOutput;
    stubVector[ZIS_STUB_ENQTRYX ] = (void*)isgenqTryExclusiveLock;
    stubVector[ZIS_STUB_ENQGETX ] = (void*)isgenqGetExclusiveLock;
    stubVector[ZIS_STUB_ENQTRYS ] = (void*)isgenqTrySharedLock;
    stubVector[ZIS_STUB_ENQGETS ] = (void*)isgenqGetSharedLock;
    stubVector[ZIS_STUB_ENQTSTX ] = (void*)isgenqTestExclusiveLock;
    stubVector[ZIS_STUB_ENQTSTS ] = (void*)isgenqTestSharedLock;
    stubVector[ZIS_STUB_ENQTEST ] = (void*)isgenqTestLock;
    stubVector[ZIS_STUB_ENQREL  ] = (void*)isgenqReleaseLock;
    stubVector[ZIS_STUB_LEGETCAA] = (void*)getCAA;
    stubVector[ZIS_STUB_LESHWRTL] = (void*)showRTL;
    stubVector[ZIS_STUB_LEMKRLEA] = (void*)makeRLEAnchor;
    stubVector[ZIS_STUB_LEDLRLEA] = (void*)deleteRLEAnchor;
    stubVector[ZIS_STUB_LEMKRLET] = (void*)makeRLETask;
    stubVector[ZIS_STUB_LEDLRLET] = (void*)deleteRLETask;
    stubVector[ZIS_STUB_LEINRLEE] = (void*)initRLEEnvironment;
    stubVector[ZIS_STUB_LETMRLEE] = (void*)termRLEEnvironment;
    stubVector[ZIS_STUB_LEMKFCAA] = (void*)makeFakeCAA;
    stubVector[ZIS_STUB_LEARTCAA] = (void*)abortIfUnsupportedCAA;
    stubVector[ZIS_STUB_MKLOGCTX] = (void*)makeLoggingContext;
    stubVector[ZIS_STUB_MKLLGCTX] = (void*)makeLocalLoggingContext;
    stubVector[ZIS_STUB_RMLOGCTX] = (void*)removeLoggingContext;
    stubVector[ZIS_STUB_RMLLGCTX] = (void*)removeLocalLoggingContext;
    stubVector[ZIS_STUB_GTLOGCTX] = (void*)getLoggingContext;
    stubVector[ZIS_STUB_STLOGCTX] = (void*)setLoggingContext;
    stubVector[ZIS_STUB_ZOWELOG ] = (void*)zowelog;
    stubVector[ZIS_STUB_ZOWEDUMP] = (void*)zowedump;
    stubVector[ZIS_STUB_LGCFGDST] = (void*)logConfigureDestination;
    stubVector[ZIS_STUB_LGCFGDS2] = (void*)logConfigureDestination2;
    stubVector[ZIS_STUB_LGCFGSTD] = (void*)logConfigureStandardDestinations;
    stubVector[ZIS_STUB_LGCFGCMP] = (void*)logConfigureComponent;
    stubVector[ZIS_STUB_LGSETLVL] = (void*)logSetLevel;
    stubVector[ZIS_STUB_LGGETLVL] = (void*)logGetLevel;
    stubVector[ZIS_STUB_LGSHTRCE] = (void*)logShouldTraceInternal;
    stubVector[ZIS_STUB_LGGLOGCX] = (void*)logGetExternalContext;
    stubVector[ZIS_STUB_LGSLOGCX] = (void*)logSetExternalContext;
    stubVector[ZIS_STUB_LGPRSOUT] = (void*)printStdout;
    stubVector[ZIS_STUB_LGPRSERR] = (void*)printStderr;
    stubVector[ZIS_STUB_LPAADD  ] = (void*)lpaAdd;
    stubVector[ZIS_STUB_LPADEL  ] = (void*)lpaDelete;
    stubVector[ZIS_STUB_GTNMTKVL] = (void*)getNameTokenValue;
    stubVector[ZIS_STUB_CRNMTKPR] = (void*)createNameTokenPair;
    stubVector[ZIS_STUB_DLNMTKPR] = (void*)deleteNameTokenPair;
    stubVector[ZIS_STUB_GTSYSOUT] = (void*)getSYSOUTStruct;
    stubVector[ZIS_STUB_WTOPRNF ] = (void*)wtoPrintf;
    stubVector[ZIS_STUB_AWTOPRNF] = (void*)authWTOPrintf;
    stubVector[ZIS_STUB_SENDWTO ] = (void*)sendWTO;
    stubVector[ZIS_STUB_QSAMPRNF] = (void*)qsamPrintf;
    stubVector[ZIS_STUB_PRINTF  ] = (void*)printf;
    stubVector[ZIS_STUB_FFLUSH  ] = (void*)fflush;
    stubVector[ZIS_STUB_SETJMP  ] = (void*)setjmp;
    stubVector[ZIS_STUB_LONGJMP ] = (void*)longjmp;
    stubVector[ZIS_STUB_NTPCREF ] = (void*)nameTokenCreate;
    stubVector[ZIS_STUB_NTPCRTPF] = (void*)nameTokenCreatePersistent;
    stubVector[ZIS_STUB_NTPDELF ] = (void*)nameTokenDelete;
    stubVector[ZIS_STUB_NTPRETF ] = (void*)nameTokenRetrieve;
    stubVector[ZIS_STUB_PEALLOC ] = (void*)peAlloc;
    stubVector[ZIS_STUB_PEDALLOC] = (void*)peDealloc;
    stubVector[ZIS_STUB_PEPAUSE ] = (void*)pePause;
    stubVector[ZIS_STUB_PERELEAS] = (void*)peRelease;
    stubVector[ZIS_STUB_PERTVNFO] = (void*)peRetrieveInfo;
    stubVector[ZIS_STUB_PERTVNF2] = (void*)peRetrieveInfo2;
    stubVector[ZIS_STUB_PETEST  ] = (void*)peTest;
    stubVector[ZIS_STUB_PETRNSFR] = (void*)peTransfer;
    stubVector[ZIS_STUB_PCAXSET ] = (void*)pcSetAllAddressSpaceAuthority;
    stubVector[ZIS_STUB_PCLXRES ] = (void*)pcReserveLinkageIndex;
    stubVector[ZIS_STUB_PCLXFRE ] = (void*)pcFreeLinkageIndex;
    stubVector[ZIS_STUB_PCETCRED] = (void*)pcMakeEntryTableDescriptor;
    stubVector[ZIS_STUB_PCETADD ] = (void*)pcAddToEntryTableDescriptor;
    stubVector[ZIS_STUB_PCETREMD] = (void*)pcRemoveEntryTableDescriptor;
    stubVector[ZIS_STUB_PCETCRE ] = (void*)pcCreateEntryTable;
    stubVector[ZIS_STUB_PCETDES ] = (void*)pcDestroyEntryTable;
    stubVector[ZIS_STUB_PCETCON ] = (void*)pcConnectEntryTable;
    stubVector[ZIS_STUB_PCETDIS ] = (void*)pcDisconnectEntryTable;
    stubVector[ZIS_STUB_PCCALLR ] = (void*)pcCallRoutine;
    stubVector[ZIS_STUB_MALLOC24] = (void*)malloc24;
    stubVector[ZIS_STUB_OPENSAM ] = (void*)openSAM;
    stubVector[ZIS_STUB_GTSAMLN ] = (void*)getSAMLength;
    stubVector[ZIS_STUB_GTSAMBS ] = (void*)getSAMBlksize;
    stubVector[ZIS_STUB_GTSAMLR ] = (void*)getSAMLrecl;
    stubVector[ZIS_STUB_GTSAMCC ] = (void*)getSAMCC;
    stubVector[ZIS_STUB_GTSAMRF ] = (void*)getSAMRecfm;
    stubVector[ZIS_STUB_PUTLINE ] = (void*)putline;
    stubVector[ZIS_STUB_GETLINE ] = (void*)getline;
    stubVector[ZIS_STUB_GTEODBUF] = (void*)getEODADBuffer;
    stubVector[ZIS_STUB_FREODBUF] = (void*)freeEODADBuffer;
    stubVector[ZIS_STUB_GETLINE2] = (void*)getline2;
    stubVector[ZIS_STUB_MKQSMBUF] = (void*)makeQSAMBuffer;
    stubVector[ZIS_STUB_FRQSMBUF] = (void*)freeQSAMBuffer;
    stubVector[ZIS_STUB_PUTLNEV ] = (void*)putlineV;
    stubVector[ZIS_STUB_GETLNEV ] = (void*)getlineV;
    stubVector[ZIS_STUB_CLOSESAM] = (void*)closeSAM;
    stubVector[ZIS_STUB_OPENEXCP] = (void*)openEXCP;
    stubVector[ZIS_STUB_CLOSEXCP] = (void*)closeEXCP;
    stubVector[ZIS_STUB_HASVRLEN] = (void*)hasVaryingRecordLength;
    stubVector[ZIS_STUB_BPAMDELM] = (void*)bpamDeleteMember;
    stubVector[ZIS_STUB_BPAMFIND] = (void*)bpamFind;
    stubVector[ZIS_STUB_BPAMREAD] = (void*)bpamRead;
    stubVector[ZIS_STUB_BPAMRD2 ] = (void*)bpamRead2;
    stubVector[ZIS_STUB_RADMXUP ] = (void*)radminExtractUserProfiles;
    stubVector[ZIS_STUB_RADMXBUP] = (void*)radminExtractBasicUserProfileInfo;
    stubVector[ZIS_STUB_RADMXBRP] = (void*)radminExtractBasicGenresProfileInfo;
    stubVector[ZIS_STUB_RADMXBGP] = (void*)radminExtractBasicGroupProfileInfo;
    stubVector[ZIS_STUB_RADMXPAL] = (void*)radminExtractGenresAccessList;
    stubVector[ZIS_STUB_RADMXGAL] = (void*)radminExtractGroupAccessList;
    stubVector[ZIS_STUB_RADMPREA] = (void*)radminPerformResAction;
    stubVector[ZIS_STUB_RADMPGRA] = (void*)radminPerformGroupAction;
    stubVector[ZIS_STUB_RADMPCNA] = (void*)radminPerformConnectionAction;
    stubVector[ZIS_STUB_RADMRCMD] = (void*)radminRunRACFCommand;
    stubVector[ZIS_STUB_RCVRESRR] = (void*)recoveryEstablishRouter;
    stubVector[ZIS_STUB_RCVRRSRR] = (void*)recoveryRemoveRouter;
    stubVector[ZIS_STUB_RCVRTRES] = (void*)recoveryIsRouterEstablished;
    stubVector[ZIS_STUB_RCVRPSFR] = (void*)recoveryPush;
    stubVector[ZIS_STUB_RCVRPPFR] = (void*)recoveryPop;
    stubVector[ZIS_STUB_RCVRSDTL] = (void*)recoverySetDumpTitle;
    stubVector[ZIS_STUB_RCVRSFLV] = (void*)recoverySetFlagValue;
    stubVector[ZIS_STUB_RCVRECST] = (void*)recoveryEnableCurrentState;
    stubVector[ZIS_STUB_RCVRDCST] = (void*)recoveryDisableCurrentState;
    stubVector[ZIS_STUB_RCVRURSI] = (void*)recoveryUpdateRouterServiceInfo;
    stubVector[ZIS_STUB_RCVRUSSI] = (void*)recoveryUpdateStateServiceInfo;
    stubVector[ZIS_STUB_RCVRGACD] = (void*)recoveryGetABENDCode;
    stubVector[ZIS_STUB_SCHZOSWT] = (void*)zosWait;
    stubVector[ZIS_STUB_SCHZOSWL] = (void*)zosWaitList;
    stubVector[ZIS_STUB_SCHZOSPT] = (void*)zosPost;
    stubVector[ZIS_STUB_SCHSRLET] = (void*)startRLETask;
    stubVector[ZIS_STUB_SHR64TKN] = (void*)shrmem64GetAddressSpaceToken;
    stubVector[ZIS_STUB_SHR64ALC] = (void*)shrmem64Alloc;
    stubVector[ZIS_STUB_SHR64AL2] = (void*)shrmem64Alloc2;
    stubVector[ZIS_STUB_SHR64CAL] = (void*)shrmem64CommonAlloc;
    stubVector[ZIS_STUB_SHR64CA2] = (void*)shrmem64CommonAlloc2;
    stubVector[ZIS_STUB_SHR64REL] = (void*)shrmem64Release;
    stubVector[ZIS_STUB_SHR64REA] = (void*)shrmem64ReleaseAll;
    stubVector[ZIS_STUB_SHR64GAC] = (void*)shrmem64GetAccess;
    stubVector[ZIS_STUB_SHR64GA2] = (void*)shrmem64GetAccess2;
    stubVector[ZIS_STUB_SHR64RAC] = (void*)shrmem64RemoveAccess;
    stubVector[ZIS_STUB_SHR64RA2] = (void*)shrmem64RemoveAccess2;
    stubVector[ZIS_STUB_GETSTCK ] = (void*)getSTCK;
    stubVector[ZIS_STUB_GETSTCKU] = (void*)getSTCKU;
    stubVector[ZIS_STUB_CONVTODL] = (void*)convertTODToLocal;
    stubVector[ZIS_STUB_TZDIFFOR] = (void*)timeZoneDifferenceFor;
    stubVector[ZIS_STUB_STCKCONV] = (void*)stckToTimestamp;
    stubVector[ZIS_STUB_CONVTOD ] = (void*)timestampToSTCK;
    stubVector[ZIS_STUB_MIDNIGHT] = (void*)timeFromMidnight;
    stubVector[ZIS_STUB_STCKYYMD] = (void*)stckFromYYYYMMDD;
    stubVector[ZIS_STUB_ELPSTIME] = (void*)elapsedTime;
    stubVector[ZIS_STUB_STCKUNIX] = (void*)stckToUnix;
    stubVector[ZIS_STUB_STCK2USM] = (void*)stckToUnixSecondsAndMicros;
    stubVector[ZIS_STUB_CONVUNIX] = (void*)unixToTimestamp;
    stubVector[ZIS_STUB_GTDAYMNT] = (void*)getDayAndMonth;
    stubVector[ZIS_STUB_SNPRNTLT] = (void*)snprintLocalTime;
    stubVector[ZIS_STUB_STRCPSAF] = (void*)strcopy_safe;
    stubVector[ZIS_STUB_INDEXOF ] = (void*)indexOf;
    stubVector[ZIS_STUB_IDXSTR  ] = (void*)indexOfString;
    stubVector[ZIS_STUB_LIDXSTR ] = (void*)lastIndexOfString;
    stubVector[ZIS_STUB_LINDEXOF] = (void*)lastIndexOf;
    stubVector[ZIS_STUB_IDXSTRNS] = (void*)indexOfStringInsensitive;
    stubVector[ZIS_STUB_ISZEROS ] = (void*)isZeros;
    stubVector[ZIS_STUB_ISBLANKS] = (void*)isBlanks;
    stubVector[ZIS_STUB_HASTEXT ] = (void*)hasText;
    stubVector[ZIS_STUB_PARSEINT] = (void*)parseInt;
    stubVector[ZIS_STUB_PSINTINT] = (void*)parseInitialInt;
    stubVector[ZIS_STUB_NULLTERM] = (void*)nullTerminate;
    stubVector[ZIS_STUB_ISCHARAN] = (void*)isCharAN;
    stubVector[ZIS_STUB_TKGTDCML] = (void*)tknGetDecimal;
    stubVector[ZIS_STUB_TKGTQOTD] = (void*)tknGetQuoted;
    stubVector[ZIS_STUB_TKGTANUM] = (void*)tknGetAlphanumeric;
    stubVector[ZIS_STUB_TKGTSTND] = (void*)tknGetStandard;
    stubVector[ZIS_STUB_TKGTNWSP] = (void*)tknGetNonWhitespace;
    stubVector[ZIS_STUB_TKGTTERM] = (void*)tknGetTerminating;
    stubVector[ZIS_STUB_TKTXEQLS] = (void*)tknTextEquals;
    stubVector[ZIS_STUB_FREETKN ] = (void*)freeToken;
    stubVector[ZIS_STUB_TKNTEXT ] = (void*)tknText;
    stubVector[ZIS_STUB_TKNINT  ] = (void*)tknInt;
    stubVector[ZIS_STUB_TKNLNGTH] = (void*)tknLength;
    stubVector[ZIS_STUB_DMPBUFFR] = (void*)dumpbuffer;
    stubVector[ZIS_STUB_DMPBUFFA] = (void*)dumpbufferA;
    stubVector[ZIS_STUB_HEXFILL ] = (void*)hexFill;
    stubVector[ZIS_STUB_SMPHXFIL] = (void*)simpleHexFill;
    stubVector[ZIS_STUB_SMPHXPRT] = (void*)simpleHexPrint;
    stubVector[ZIS_STUB_SMPHXPRL] = (void*)simpleHexPrintLower;
    stubVector[ZIS_STUB_HEXDUMP ] = (void*)hexdump;
    stubVector[ZIS_STUB_DMPBFFR2] = (void*)dumpbuffer2;
    stubVector[ZIS_STUB_DMPBFFRS] = (void*)dumpBufferToStream;
    stubVector[ZIS_STUB_CMPIGNCS] = (void*)compareIgnoringCase;
    stubVector[ZIS_STUB_STRUPCAS] = (void*)strupcase;
    stubVector[ZIS_STUB_MAKESLH ] = (void*)makeShortLivedHeap;
    stubVector[ZIS_STUB_MAKSLH64] = (void*)makeShortLivedHeap64;
    stubVector[ZIS_STUB_SLHALLOC] = (void*)SLHAlloc;
    stubVector[ZIS_STUB_SLHFREE ] = (void*)SLHFree;
    stubVector[ZIS_STUB_NYMALLOC] = (void*)noisyMalloc;
    stubVector[ZIS_STUB_DECODB32] = (void*)base32Encode;
    stubVector[ZIS_STUB_ENCODB32] = (void*)base32Decode;
    stubVector[ZIS_STUB_DECODB64] = (void*)decodeBase64;
    stubVector[ZIS_STUB_DECDB64U] = (void*)decodeBase64Unterminated;
    stubVector[ZIS_STUB_ENCODB64] = (void*)encodeBase64;
    stubVector[ZIS_STUB_ENCDB64N] = (void*)encodeBase64NoAlloc;
    stubVector[ZIS_STUB_B642BURL] = (void*)base64ToBase64url;
    stubVector[ZIS_STUB_B64URLTB] = (void*)base64urlToBase64;
    stubVector[ZIS_STUB_CLNURLPV] = (void*)cleanURLParamValue;
    stubVector[ZIS_STUB_PCTENCOD] = (void*)percentEncode;
    stubVector[ZIS_STUB_DSTUNASC] = (void*)destructivelyUnasciify;
    stubVector[ZIS_STUB_MAKESLST] = (void*)makeStringList;
    stubVector[ZIS_STUB_SLSTLEN ] = (void*)stringListLength;
    stubVector[ZIS_STUB_SLSTPRNT] = (void*)stringListPrint;
    stubVector[ZIS_STUB_SLSTCTNS] = (void*)stringListContains;
    stubVector[ZIS_STUB_SLSTLAST] = (void*)stringListLast;
    stubVector[ZIS_STUB_ADSLSTUQ] = (void*)addToStringListUnique;
    stubVector[ZIS_STUB_ADSLST  ] = (void*)addToStringList;
    stubVector[ZIS_STUB_SLSTELT1] = (void*)firstStringListElt;
    stubVector[ZIS_STUB_STRCNCAT] = (void*)stringConcatenate;
    stubVector[ZIS_STUB_MKBFCHST] = (void*)makeBufferCharStream;
    stubVector[ZIS_STUB_CSTRPOSN] = (void*)charStreamPosition;
    stubVector[ZIS_STUB_CSTRGET ] = (void*)charStreamGet;
    stubVector[ZIS_STUB_CSTREOF ] = (void*)charStreamEOF;
    stubVector[ZIS_STUB_CSTRCLOS] = (void*)charStreamClose;
    stubVector[ZIS_STUB_CSTRFREE] = (void*)charStreamFree;
    stubVector[ZIS_STUB_PADWSPCS] = (void*)padWithSpaces;
    stubVector[ZIS_STUB_RPLTRMNL] = (void*)replaceTerminateNulls;
    stubVector[ZIS_STUB_CNVINTST] = (void*)convertIntToString;
    stubVector[ZIS_STUB_HEXTODEC] = (void*)hexToDec;
    stubVector[ZIS_STUB_DECTOHEX] = (void*)decToHex;
    stubVector[ZIS_STUB_COMPSEQS] = (void*)compareSequences;
    stubVector[ZIS_STUB_DEC2OCT ] = (void*)decimalToOctal;
    stubVector[ZIS_STUB_UNX2ISO ] = (void*)convertUnixToISO;
    stubVector[ZIS_STUB_MATCHWLD] = (void*)matchWithWildcards;
    stubVector[ZIS_STUB_STRISDIG] = (void*)stringIsDigit;
    stubVector[ZIS_STUB_TRMRIGHT] = (void*)trimRight;
    stubVector[ZIS_STUB_ISPASPHR] = (void*)isPassPhrase;
    stubVector[ZIS_STUB_MAKEACB ] = (void*)makeACB;
    stubVector[ZIS_STUB_VOPCLACB] = (void*)opencloseACB;
    stubVector[ZIS_STUB_OPENACB ] = (void*)openACB;
    stubVector[ZIS_STUB_CLOSEACB] = (void*)closeACB;
    stubVector[ZIS_STUB_MODRPL  ] = (void*)modRPL;
    stubVector[ZIS_STUB_VSPOINT ] = (void*)point;
    stubVector[ZIS_STUB_VPUTREC ] = (void*)putRecord;
    stubVector[ZIS_STUB_VGETREC ] = (void*)getRecord;
    stubVector[ZIS_STUB_VMKDBUFF] = (void*)makeDataBuffer;
    stubVector[ZIS_STUB_VFRDBUFF] = (void*)freeDataBuffer;
    stubVector[ZIS_STUB_VPNBYRBA] = (void*)pointByRBA;
    stubVector[ZIS_STUB_VPNBYKEY] = (void*)pointByKey;
    stubVector[ZIS_STUB_VPNBYREC] = (void*)pointByRecord;
    stubVector[ZIS_STUB_VPNBYCI ] = (void*)pointByCI;
    stubVector[ZIS_STUB_VALLOCDS] = (void*)allocateDataset;
    stubVector[ZIS_STUB_VDEFAIX ] = (void*)defineAIX;
    stubVector[ZIS_STUB_DELCLUST] = (void*)deleteCluster;
    stubVector[ZIS_STUB_E2A     ] = (void*)e2a;
    stubVector[ZIS_STUB_A2E     ] = (void*)a2e;
    stubVector[ZIS_STUB_EXTRPSW ] = (void*)extractPSW;
    stubVector[ZIS_STUB_SUPRMODE] = (void*)supervisorMode;
    stubVector[ZIS_STUB_SETKEY  ] = (void*)setKey;
    stubVector[ZIS_STUB_DDEXISTS] = (void*)ddnameExists;
    stubVector[ZIS_STUB_ATOMINCR] = (void*)atomicIncrement;
    stubVector[ZIS_STUB_GTCRACEE] = (void*)getCurrentACEE;
    stubVector[ZIS_STUB_GTFCHTCB] = (void*)getFirstChildTCB;
    stubVector[ZIS_STUB_GTPRTTCB] = (void*)getParentTCB;
    stubVector[ZIS_STUB_GTNXSTCB] = (void*)getNextSiblingTCB;
    stubVector[ZIS_STUB_GETCVT  ] = (void*)getCVT;
    stubVector[ZIS_STUB_GETATCVT] = (void*)getATCVT;
    stubVector[ZIS_STUB_GETCSTBL] = (void*)getIEACSTBL;
    stubVector[ZIS_STUB_GETCVTPR] = (void*)getCVTPrefix;
    stubVector[ZIS_STUB_GETECVT ] = (void*)getECVT;
    stubVector[ZIS_STUB_GETTCB  ] = (void*)getTCB;
    stubVector[ZIS_STUB_GETSTCB ] = (void*)getSTCB;
    stubVector[ZIS_STUB_GETOTCB ] = (void*)getOTCB;
    stubVector[ZIS_STUB_GETASCB ] = (void*)getASCB;
    stubVector[ZIS_STUB_GETASXB ] = (void*)getASXB;
    stubVector[ZIS_STUB_GETASSB ] = (void*)getASSB;
    stubVector[ZIS_STUB_GETJSAB ] = (void*)getJSAB;
    stubVector[ZIS_STUB_GTSPLXNM] = (void*)getSysplexName;
    stubVector[ZIS_STUB_GTSYSTNM] = (void*)getSystemName;
    stubVector[ZIS_STUB_GETDSAB ] = (void*)getDSAB;
    stubVector[ZIS_STUB_DSABOMVS] = (void*)dsabIsOMVS;
    stubVector[ZIS_STUB_LOCATE  ] = (void*)locate;
    stubVector[ZIS_STUB_GETR13  ] = (void*)getR13;
    stubVector[ZIS_STUB_GETR12  ] = (void*)getR12;
    stubVector[ZIS_STUB_GETASCBJ] = (void*)getASCBJobname;
    stubVector[ZIS_STUB_LOADBYNA] = (void*)loadByName;
    stubVector[ZIS_STUB_LOADBNML] = (void*)loadByNameLocally;
    stubVector[ZIS_STUB_ZOSCLCKD] = (void*)isCallerLocked;
    stubVector[ZIS_STUB_ZOSCSRB ] = (void*)isCallerSRB;
    stubVector[ZIS_STUB_ZOSCXMEM] = (void*)isCallerCrossMemory;
    stubVector[ZIS_STUB_GADSACEE] = (void*)getAddressSpaceAcee;
    stubVector[ZIS_STUB_GTSKACEE] = (void*)getTaskAcee;
    stubVector[ZIS_STUB_STSKACEE] = (void*)setTaskAcee;
    stubVector[ZIS_STUB_SAFVRIFY] = (void*)safVerify;
    stubVector[ZIS_STUB_SAFVRFY2] = (void*)safVerify2;
    stubVector[ZIS_STUB_SAFVRFY3] = (void*)safVerify3;
    stubVector[ZIS_STUB_SAFVRFY4] = (void*)safVerify4;
    stubVector[ZIS_STUB_SAFVRFY5] = (void*)safVerify5;
    stubVector[ZIS_STUB_SAFVRFY6] = (void*)safVerify6;
    stubVector[ZIS_STUB_SAFVRFY7] = (void*)safVerify7;
    stubVector[ZIS_STUB_SAFAUTH ] = (void*)safAuth;
    stubVector[ZIS_STUB_SAFAUTHS] = (void*)safAuthStatus;
    stubVector[ZIS_STUB_SAFSTAT ] = (void*)safStat;
    stubVector[ZIS_STUB_GETSAFPL] = (void*)getSafProfileMaxLen;
    stubVector[ZIS_STUB_ZVTINIT ] = (void*)zvtInit;
    stubVector[ZIS_STUB_ZVTGET  ] = (void*)zvtGet;
    stubVector[ZIS_STUB_ZVTAENTR] = (void*)zvtAllocEntry;
    stubVector[ZIS_STUB_ZVTFENTR] = (void*)zvtFreeEntry;
    stubVector[ZIS_STUB_ZVTGXMLR] = (void*)zvtGetCMSLookupRoutineAnchor;
    stubVector[ZIS_STUB_ZVTSXMLR] = (void*)zvtSetCMSLookupRoutineAnchor;
/*
  This program and the accompanying materials are
  made available under the terms of the Eclipse Public License v2.0 which accompanies
  this distribution, and is available at https://www.eclipse.org/legal/epl-v20.html

  SPDX-License-Identifier: EPL-2.0

  Copyright Contributors to the Zowe Project.
*/
