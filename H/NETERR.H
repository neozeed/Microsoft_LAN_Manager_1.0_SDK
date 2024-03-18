/********************************************************************/
/**                   Microsoft OS|2 LAN Manager                   **/
/**               Copyright(c) Microsoft Corp., 1987               **/
/********************************************************************/

/***	neterr.h - network error definitions
 *
 */

#define NERR_Success		0	/* Success */

/* 
 *	Redirector related
 *		Err codes from 50 to 79, 88, and 230 to 249
 */

#define ERROR_NOT_SUPPORTED	50	/* This request is not supported by the network.  */
#define ERROR_REM_NOT_LIST	51	/* This remote computer is not listening. */
#define ERROR_DUP_NAME		52	/* A duplicate name exists on the network. */
#define ERROR_BAD_NETPATH	53	/* The network path cannot be located. */
#define ERROR_NETWORK_BUSY	54	/* The network is busy. */
#define ERROR_DEV_NOT_EXIST	55	/* This device does not exist on the network. */
#define ERROR_TOO_MANY_CMDS	56	/* The net BIOS command limit has been exceeded. */
#define ERROR_ADAP_HDW_ERR	57	/* A network adapter hardware error has occurred. */
#define ERROR_BAD_NET_RESP	58	/* The network has responded incorrectly. */
#define ERROR_UNEXP_NET_ERR	59	/* An unexpected network error has occurred. */
#define ERROR_BAD_REM_ADAP	60	/* The remote adapter being used is incompatible. */
#define ERROR_PRINTQ_FULL	61	/* The print queue is full. */
#define ERROR_NO_SPOOL_SPACE	62	/* There's not enough memory available for the requested print file. */
#define ERROR_PRINT_CANCELLED	63	/* The requested print file has been cancelled. */
#define ERROR_NETNAME_DELETED	64	/* The network name was deleted. */
#define	ERROR_NETWORK_ACCESS_DENIED 65	/* Network access is denied. */
#define ERROR_BAD_DEV_TYPE	66	/* This network device type is incorrect. */
#define ERROR_BAD_NET_NAME	67	/* This network name cannot be found. */
#define ERROR_TOO_MANY_NAMES	68	/* The network name limit has been exceeded. */
#define ERROR_TOO_MANY_SESS	69	/* The net BIOS session limit has been exceeded. */
#define ERROR_SHARING_PAUSED	70	/* File sharing has been temporarily paused. */
#define ERROR_REQ_NOT_ACCEP	71	/* This request is not accepted by the network. */
#define ERROR_REDIR_PAUSED	72	/* Print or disk redirection is temporarily paused. */

#define ERROR_NET_WRITE_FAULT	88	/* A network data fault has occurred. */

#define	ERROR_BAD_PIPE		230	/* This is a non-existent pipe or an invalid operation. */
#define	ERROR_PIPE_BUSY		231	/* The specified pipe is busy. */
#define	ERROR_NO_DATA		232	/* There's no data on a non-blocking read. */
#define	ERROR_PIPE_NOT_CONNECTED 233	/* The pipe was disconnected by the server. */
#define	ERROR_MORE_DATA		234	/* Additional data is available. */

#define	ERROR_VC_DISCONNECTED	240	/* The session was canceled. */


/***	NERR_BASE is the base of error codes from network utilities,
 *	chosen to avoid conflict with OS and redirector error codes.
 *	2100 is a value that has been assigned to us by the OS folks.
 */
#define	NERR_BASE	2100

/* UNUSED BASE+0 */
/* UNUSED BASE+1 */
#define NERR_NetNotStarted	(NERR_BASE+2)	/* The Workstation driver NETWKSTA.SYS is not installed. */
#define NERR_UnknownServer	(NERR_BASE+3)	/* This server cannot be located. */
#define NERR_ShareMem		(NERR_BASE+4)	/* An internal error occurred.  The network cannot access a shared memory segment. */
/* UNUSED BASE+5 */
#define NERR_RemoteOnly		(NERR_BASE+6)	/* API is not supported on local machines. */
#define NERR_DevNotRedirected	(NERR_BASE+7)	/* This device is not redirected. */
/* UNUSED BASE+8 */
#define NERR_NoSuchUNCRedir	(NERR_BASE+9)	/* This UNC net name does not exist. */
#define NERR_AlertExists	(NERR_BASE+10)	/* This alert has already been started. */
#define NERR_TooManyAlerts	(NERR_BASE+11)	/* The alert table is full. */
#define NERR_NoSuchAlert	(NERR_BASE+12)	/* This alert has not been started. */
#define NERR_BadRecipient	(NERR_BASE+13)	/* The alert recipient is invalid.*/
#define NERR_ServerNotStarted	(NERR_BASE+14)	/* The server has not been started. */
#define NERR_ItemNotFound	(NERR_BASE+15)	/* Requested item does not exist */
#define NERR_UnknownDevDir	(NERR_BASE+16)	/* This device or directory does not exist. */
#define NERR_RedirectedPath	(NERR_BASE+17)	/* Redirected devices cannot be shared. */
#define NERR_DuplicateShare	(NERR_BASE+18)	/* This net name has already been shared */
#define NERR_NoRoom		(NERR_BASE+19)	/* The server is currently out of the requested resource. */
#define NERR_ErrlogCorrupt	(NERR_BASE+20)	/* The error log file has been corrupted. */
#define NERR_TooManyItems	(NERR_BASE+21)	/* Requested add of item exceeds maximum allowed */
/* UNUSED BASE+22 */
#define NERR_BufTooSmall	(NERR_BASE+23)	/* The API return buffer is too small. */
/* UNUSED BASE+24 */
/* UNUSED BASE+25 */
/* UNUSED BASE+26 */
#define NERR_RemoteErr		(NERR_BASE+27)	/* A remote API error has occurred.  */
/* UNUSED BASE+28 */
/* UNUSED BASE+29 */
/* UNUSED BASE+30 */
#define NERR_LanmanIniError	(NERR_BASE+31)	/* An error occurred when opening or reading LANMAN.INI. */
/* UNUSED BASE+32 */
/* UNUSED BASE+33 */
#define NERR_OS2IoctlError	(NERR_BASE+34)	/* An internal error occurred when calling the Workstation driver. */
/* UNUSED BASE+35 */
#define	NERR_NetworkError	(NERR_BASE+36)	/* A generic network error has occurred. */
/* UNUSED BASE+37 */
#define NERR_WkstaNotStarted	(NERR_BASE+38)	/* The Workstation has not been started. */
#define NERR_BrowserNotStarted	(NERR_BASE+39)	/* The requested server information is not available. */
#define NERR_InternalError	(NERR_BASE+40)	/* An internal LAN Manager error has occurred.*/
#define NERR_BadTransactConfig	(NERR_BASE+41)	/* The server is not configured for transactions. */
#define NERR_InvalidAPI		(NERR_BASE+42)	/* The requested API is not supported on the remote server. */
#define NERR_BadEventName	(NERR_BASE+43)	/* The event name is poorly formed. */

/* 
 *	Config API related
 *		Err codes from BASE+45 to BASE+49
 */

#define NERR_CfgCompNotFound	(NERR_BASE+46)	/* The program could not find the specified component in LANMAN.INI. */
#define NERR_CfgParamNotFound	(NERR_BASE+47)	/* The program could not find the specified parameter in LANMAN.INI. */
#define NERR_LineTooLong	(NERR_BASE+49)	/* A line in LANMAN.INI is too long. */

/* 
 *	Spooler API related
 *		Err codes from BASE+50 to BASE+79
 */

#define NERR_QNotFound		(NERR_BASE+50)	/* This print queue does not exist. */
#define NERR_JobNotFound	(NERR_BASE+51)	/* This print job does not exist. */
#define NERR_DestNotFound	(NERR_BASE+52)	/* This print destination cannot be found. */
#define NERR_QExists		(NERR_BASE+54)	/* This print queue already exists. */
#define NERR_QNoRoom		(NERR_BASE+55)	/* No more print queues can be added. */
#define NERR_JobNoRoom		(NERR_BASE+56)	/* No more print jobs can be added.  */
#define NERR_DestNoRoom 	(NERR_BASE+57)	/* No more print destinations can be added. */
#define NERR_DestIdle		(NERR_BASE+58)	/* This print destination is idle and cannot accept control operations. */
#define NERR_DestInvalidOp	(NERR_BASE+59)	/* This print destination request contains an invalid control function. */
#define NERR_ProcNoRespond	(NERR_BASE+60)	/* The print processor is not responding. */
#define NERR_SpoolerNotLoaded	(NERR_BASE+61)	/* The spooler has not been started. */
#define NERR_QInvalidState	(NERR_BASE+63)	/* This operation cannot be performed on the print queue in its current state. */
#define NERR_JobInvalidState	(NERR_BASE+64)	/* This operation cannot be performed on the print job in its current state. */
#define	NERR_SpoolNoMemory	(NERR_BASE+65)	/* A spooler memory allocation failure has occurred. */

/* 
 *	Service API related
 *		Err codes from BASE+80 to BASE+99
 */

#define NERR_ServiceTableLocked	(NERR_BASE+80)	/* There is a timeout on the service table semaphore. */
#define NERR_ServiceTableFull	(NERR_BASE+81)	/* The service table is full. */
#define NERR_ServiceInstalled	(NERR_BASE+82)	/* The requested service has already been started. */
#define NERR_ServiceEntryLocked	(NERR_BASE+83)	/* There is a service entry semaphore timeout. */
#define NERR_ServiceNotInstalled (NERR_BASE+84) /* The service has not been started. */
#define NERR_BadServiceName	(NERR_BASE+85)	/* The service name is invalid. */
#define NERR_ServiceCtlTimeout	(NERR_BASE+86)	/* The service is not responding to the control function. */
#define NERR_ServiceCtlBusy	(NERR_BASE+87)	/* The service control is busy. */
#define NERR_BadServiceProgName	(NERR_BASE+88)	/* LANMAN.INI contains an invalid service program name. */
#define NERR_ServiceNotCtrl	(NERR_BASE+89)	/* The service cannot be controlled in its present state. */
#define NERR_ServiceKillProc	(NERR_BASE+90)	/* The service did not respond to normal service control funtions and was terminated with the DosKillProc function. */ 
#define NERR_ServiceCtlNotValid	(NERR_BASE+91)	/* The requested pause or stop is not valid for this service. */

/* 
 *	Wksta and Logon API related
 *		Err codes from BASE+100 to BASE+119
 */

#define NERR_AlreadyLoggedOn	(NERR_BASE+100)	/* This Workstation is already logged on. */
#define NERR_NotLoggedOn	(NERR_BASE+101)	/* This Workstation has not been logged on yet. */
#define NERR_BadUsername	(NERR_BASE+102)	/* The username parameter is invalid.  */
#define NERR_BadPassword	(NERR_BASE+103)	/* The password parameter is invalid. */
#define NERR_UnableToAddName_W	(NERR_BASE+104)	/* @W The logon processor did not add the messagename. */
#define NERR_UnableToAddName_F	(NERR_BASE+105)	/* The logon processor did not add the messagename. */
#define NERR_UnableToDelName_W	(NERR_BASE+106)	/* @W The logoff processor did not delete the messagename. */
#define NERR_UnableToDelName_F	(NERR_BASE+107)	/* The logoff processor did not delete the messagename. */
/* UNUSED BASE+108 */
/* UNUSED BASE+109 */
#define NERR_LogonServerConflict (NERR_BASE+110)/* A centralized logon server conflict has occurred. */
#define NERR_LogonNoUserPath	(NERR_BASE+111) /* The server is configured without a user path. */
#define NERR_LogonScriptError	(NERR_BASE+112) /* An error occurred while either loading or executing the logon script. */
#define NERR_CentralLogonFailed (NERR_BASE+113) /* The net is unable to use the resources provided for centralized logon. */
#define NERR_StandaloneLogon    (NERR_BASE+114) /* The logon server was not specified.  Standalone logon will occur. */
#define NERR_LogonServerNotFound (NERR_BASE+115) /* The logon server cannot be found.  */


/* 
 *	ACF API related (access, user, group)
 *		Err codes from BASE+120 to BASE+149
 */

#define NERR_GroupNotFound	(NERR_BASE+120)	/* The groupname cannot be found. */
#define NERR_UserNotFound	(NERR_BASE+121)	/* The username cannot be found. */
#define NERR_ResourceNotFound	(NERR_BASE+122)	/* The resource name cannot be found.  */
#define NERR_GroupExists	(NERR_BASE+123)	/* The group already exists. */
#define NERR_UserExists		(NERR_BASE+124)	/* The user account already exists. */
#define NERR_ResourceExists	(NERR_BASE+125)	/* The resource permission list already exists. */
/* UNUSED BASE+126 */
#define NERR_ACFNotLoaded	(NERR_BASE+127)	/* The user-level security is not running. */
#define NERR_ACFNoRoom		(NERR_BASE+128)	/* There are too many names in the access control file. */
#define NERR_ACFFileIOFail	(NERR_BASE+129)	/* A disk I/O failure has occurred.*/
#define NERR_ACFTooManyLists	(NERR_BASE+130)	/* Too many entries in the access control list. */
/* UNUSED BASE+131 */
#define NERR_ACFNoParent	(NERR_BASE+132)	/* The parent directory cannot be located. */
/* UNUSED BASE+133 */
#define NERR_SpeGroupOp		(NERR_BASE+134) /* This operation is not allowed on this special group. */
/* UNUSED BASE+135 */
#define NERR_UserInGroup	(NERR_BASE+136) /* The user already belongs to this group. */
#define NERR_UserNotInGroup	(NERR_BASE+137) /* The user does not belong to this group. */

/* 
 *	Use API related 
 *		Err codes from BASE+150 to BASE+169
 */

#define NERR_UseNotFound	(NERR_BASE+150)	/* This redirection cannot be found. */
#define NERR_BadAsgType		(NERR_BASE+151)	/* This asg_type is invalid. */
#define NERR_DeviceIsShared	(NERR_BASE+152) /* This device is already being shared. */

/* 
 *	Message server related 
 *		Error codes BASE+170 to BASE+209
 */

#define	NERR_NoComputerName	(NERR_BASE+170)	/* A computername has not been configured.  */
#define	NERR_MsgAlreadyStarted	(NERR_BASE+171)	/* This message server has already been started. */
#define NERR_MsgInitFailed	(NERR_BASE+172)	/* The message server initialization request has failed. */
#define	NERR_NameNotFound	(NERR_BASE+173)	/* This name cannot be located on the network. */
#define	NERR_AlreadyForwarded	(NERR_BASE+174)	/* This name has already been forwarded. */
#define NERR_AddForwarded	(NERR_BASE+175)	/* This name has been added but is still forwarded. */
#define NERR_AlreadyExists	(NERR_BASE+176)	/* This name already exists locally. */
#define	NERR_TooManyNames	(NERR_BASE+177)	/* The maximum number of added names has been exceeded. */
#define NERR_DelComputerName	(NERR_BASE+178)	/* The computername cannot be deleted.*/
#define	NERR_LocalForward	(NERR_BASE+179)	/* Messages cannot be forwarded back to the same Workstation. */
#define	NERR_NoLogFile		(NERR_BASE+180)	/* The log file or device has not been specified. */
#define NERR_PausedRemote	(NERR_BASE+181)	/* The message has been sent but the reception is currently paused. */
#define	NERR_BadReceive		(NERR_BASE+182)	/* The message was sent but not received. */
#define	NERR_NameInUse		(NERR_BASE+183)	/* This name is currently in use. Try again later. */
#define	NERR_MsgNotStarted	(NERR_BASE+184)	/* The messenger has not been started. */
#define	NERR_NotLocalName	(NERR_BASE+185)	/* This name is not on the local computer. */
#define	NERR_NoForwardName	(NERR_BASE+186)	/* The forwarded name cannot be found on the network. */
#define	NERR_RemoteFull		(NERR_BASE+187)	/* The name table on the remote station is full. */
#define NERR_NameNotForwarded	(NERR_BASE+188)	/* This name is not currently forwarded. */
#define NERR_TruncatedBroadcast	(NERR_BASE+189)	/* The broadcast was truncated. */
#define NERR_FileError		(NERR_BASE+190)	/* An error occurred when reading the message file. */
#define	NERR_InvalidLogName	(NERR_BASE+191)	/* The log name contains invalid characters. */
#define	NERR_InvalidDevice	(NERR_BASE+194)	/* This is an invalid device. */
#define	NERR_WriteFault		(NERR_BASE+195)	/* A  write fault has occurred. */
/* UNUSED BASE+196 */
#define	NERR_DuplicateName	(NERR_BASE+197)	/* A duplicate name exists on the network. */
#define	NERR_DeleteLater	(NERR_BASE+198)	/* This name will be deleted later. */


/* 
 * 	Server API related 
 *		Error codes BASE+210 to BASE+229
 */
 
#define NERR_NetNameNotFound	(NERR_BASE+210)	/* This shared resource does not exist.*/
#define	NERR_DeviceNotShared	(NERR_BASE+211)	/* This device is not shared. */
#define NERR_ClientNameNotFound	(NERR_BASE+212)	/* A session does not exist with that computername. */
#define NERR_FileIdNotFound	(NERR_BASE+214)	/* This is an invalid file ID number. */
#define NERR_ExecFailure	(NERR_BASE+215)	/* A failure occurred when executing a remote administration command. */
#define NERR_TmpFile		(NERR_BASE+216) /* A failure occurred when opening a remote temporary file. */
#define NERR_TooMuchData	(NERR_BASE+217) /* The data returned from a remote administration command has been truncated to 64K bytes. */
#define NERR_DeviceShareConflict (NERR_BASE+218) /* This device cannot be shared as both a spooled and a non-spooled device. */
#define NERR_BrowserTableIncomplete (NERR_BASE+219)  /* The server table was initialized incorrectly.*/

/* 
 * 	CharDev API related 
 *		Error codes BASE+230 to BASE+249
 */
 
/* UNUSED BASE+230 */
#define NERR_DevInvalidOpCode	(NERR_BASE+231)	/* The operation is invalid for this device. */
#define NERR_DevNotFound	(NERR_BASE+232)	/* This device cannot be shared. */
#define NERR_DevNotOpen		(NERR_BASE+233)	/* This device was not open. */
#define NERR_BadQueueDevString	(NERR_BASE+234)	/* This device name string is invalid. */
#define NERR_BadQueuePriority	(NERR_BASE+235)	/* The queue priority is invalid. */
#define NERR_NoCommDevs		(NERR_BASE+237)	/* There are no shared communication devices. */
#define NERR_QueueNotFound	(NERR_BASE+238)	/* A queue does not exist for this request. */
#define NERR_BadDevString	(NERR_BASE+240) /* This list of devices is invalid. */
#define NERR_BadDev		(NERR_BASE+241) /* The requested device is invalid. */
#define NERR_InUseBySpooler	(NERR_BASE+242) /* This device is already in use by the spooler. */
#define NERR_CommDevInUse	(NERR_BASE+243) /* This device is already in use as a communications device. */

/* 
 *	NetICanonicalize and NetIType and NetIMakeLMFileName
 *	NetIListCanon and NetINameCheck
 *		Error codes BASE+250 - BASE+269
 */
 
#define NERR_InvalidComputer   (NERR_BASE+251) /* This computername is invalid. */
/* UNUSED BASE+252 */
/* UNUSED BASE+253 */
#define NERR_MaxLenExceeded    (NERR_BASE+254) /* The string and prefix specified are too long. */
/* UNUSED BASE+255 */
#define NERR_BadComponent      (NERR_BASE+256) /* This path component is invalid. */
#define NERR_CantType	       (NERR_BASE+257) /* Cannot determine type of input.(?) */
/* UNUSED BASE+258 */
/* UNUSED BASE+259 */
#define NERR_TooManyEntries    (NERR_BASE+262) /* The buffer for types is not big enough. */

/* 
 *	NetProfile
 *		Error codes BASE+270 - BASE+276
 */
 
#define NERR_ProfileFileTooBig	(NERR_BASE+270) /* Profile files cannot exceed 64K bytes. */
#define NERR_ProfileOffset	(NERR_BASE+271) /* The start offset is out of range. */
#define NERR_ProfileCleanup	(NERR_BASE+272) /* Cannot delete current users or shares. */
#define NERR_ProfileUnknownCmd	(NERR_BASE+273) /* Unable to parse command line in file.*/
#define NERR_ProfileLoadErr	(NERR_BASE+274) /* An error occurred executing a network profile command. */


/* 
 * 	NetAudit and NetErrorLog
 *		Error codes BASE+277 - BASE+279
 */

#define NERR_LogOverflow	   (NERR_BASE+277)	/* This log file exceeds the maximum defined size. */
 
/* 
 *	NetRemote
 *		Error codes BASE+280 - BASE+299
 */
#define NERR_SourceIsDir   (NERR_BASE+280) /* The source path cannot be a directory. */
#define NERR_BadSource     (NERR_BASE+281) /* The source path is illegal. */
#define NERR_BadDest       (NERR_BASE+282) /* The destination path is illegal. */
#define NERR_DifferentServers   (NERR_BASE+283) /* The source and destination paths are on different servers. */
#define NERR_CurEnvNotRemote (NERR_BASE+284) /* The current drive is not redirected. */

#define NERR_RunSrvPaused 	(NERR_BASE+285) /* The Run Service is paused. */
#define NERR_CreatingThread 	(NERR_BASE+286) /* An error occurred when creating a thread. */
#define NERR_ErrorMakingPipe 	(NERR_BASE+287) /* An error occurred when making a pipe. */
/* UNUSED BASE+288 */
#define NERR_ErrCommRunSrv 	(NERR_BASE+289) /* An error occurred when communicating with a run server. */
#define NERR_ErrConnRunSrv 	(NERR_BASE+290) /* An error occurred when connecting to a run server. */
#define NERR_ErrorExecingGhost 	(NERR_BASE+291) /* An error occurred when executinng a ghost. */
#define NERR_ShareNotFound 	(NERR_BASE+292) /* This shared resource does not exist.*/
#define NERR_ErrKillingChild 	(NERR_BASE+293) /* An error occurred when killing a child. */
#define NERR_PgmNotFound 	(NERR_BASE+294) /* This program cannot be located. */


/* 
 *  NetWksta.sys (redir) returned error codes.  Includes installation
 *  messages.
 *
 *          NERR_BASE + (300-329)
 */

#define NERR_InvalidLana        (NERR_BASE+300) /* The LAN adapter number is invalid.  */
#define NERR_OpenFiles          (NERR_BASE+301) /* There are open files on the connection.    */
#define NERR_ActiveConns        (NERR_BASE+302) /* Active connections still exist. */
#define NERR_BadPasswordCore    (NERR_BASE+303) /* This netname or password is invalid. */
#define NERR_DevInUse           (NERR_BASE+304) /* The device is being accessed by an active process. */

#define NERR_MPXCntMsg		(NERR_BASE+305) /* @I %5Number of MPXThreads%5  %1%6%5Number of NCB_Queues%5  %2%6%5Number of named pipes%5  %3%6%5Total memory used%5  %4%6 */

#define NERR_MemAllocMsg        (NERR_BASE+306) /* There is not enough memory available to install the Workstation software. */
#define NERR_IniFilRdErr        (NERR_BASE+307) /* An error occurred when reading the 'NETWORKS' entry in LANMAN.INI. */
#define NERR_MultNetsMsg        (NERR_BASE+308) /* @W There are too many 'NETWORKS' entries. */
#define NERR_BadNetEntHdr       (NERR_BASE+309) /* @W The 'NETWORKS' entry in LANMAN.INI: %1 has a syntax error and will be ignored. */
#define NERR_BadBiosMsg         (NERR_BASE+310) /* @W An error occurred when opening network device driver %1 = %2. */
#define NERR_BadLinkMsg         (NERR_BASE+311) /* @W Device driver %1 sent a bad BiosLinkage response.*/
#define NERR_BadArgMsg          (NERR_BASE+312) /* This is an invalid argument: %1. */
#define NERR_BadVerMsg          (NERR_BASE+313) /* This version of OS/2 is incorrect. */
#define NERR_RdrInstMsg         (NERR_BASE+314) /* The redirector is already installed. */
#define NERR_LocalDrive		(NERR_BASE+315) /* The drive letter is in use locally. */

#define NERR_Version            (NERR_BASE+316) /* @I Installing NETWKSTA.SYS Version %1.%2.%3 %4 (?)  */


#define MAX_NERR		(NERR_BASE+349) /* This is the last error in NERR range. */

/* 
 * end of list
 *
 *    WARNING:  DO not exceed MAX_NERR, values above this are used by
 *		other error code ranges (errlog.h, service.h, app[err.h).
 */
