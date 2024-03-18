/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  ERRLOG.H				    *
 *								    *
 *  This file contains information about the NetErrorLog APIs.	    *
 *								    *
 *	Function prototypes.					    *
 *								    *
 *	Data structure templates.				    *
 *								    *
 *	Definition of special values.				    *
 *								    *
 *								    *
 *  NOTE:  You must include NETCONS.H before this file, since this  *
 *	   file	depends on values defined in NETCONS.H.		    *
 *								    *
 ********************************************************************/


/**************************************************************** 
 *								*
 *	  	Function prototypes 				*
 *								*
 ****************************************************************/

extern API_FUNCTION
  NetErrorLogOpen ( const char far *, unsigned far *, char far * );

extern API_FUNCTION
  NetErrorLogClear ( const char far *, const char far *, char far * );

extern API_FUNCTION
  NetErrorLogWrite ( char far *, unsigned short, const char far *, 
					const char far *, 
  					unsigned short, const char far *, 
					unsigned short, char far * );


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/


struct error_log {
	unsigned short	el_len;
	unsigned short  el_reserved;
	unsigned long	el_time;
	unsigned short	el_error;
        char            el_name[SNLEN+1];
	unsigned short  el_data_offset;
	unsigned short  el_nstrings;
}; /* error_log */


/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/


/***	ERRLOG_BASE is the base of error log codes,
 *	chosen to avoid conflict with OS, redirector,
 *	and netapi codes.
 */

#define ERRLOG_BASE	2800		/* NELOG errs start here */

/*
 *	Generic (could be used by more than one service)
 * 	 error log messages from 0 to 25
 */

#define NELOG_Internal_Error		(ERRLOG_BASE + 0)
	/*
	 * Lanman Internal error has occured.
	 */


#define NELOG_Resource_Shortage		(ERRLOG_BASE + 1)
	/*
	 * Ran out of resource controlled by startup
	 *  parameter %1
	 */

#define NELOG_Unable_To_Lock_Segment	(ERRLOG_BASE + 2)
	/*
	 * Service failed to obtain long-term lock on segment for NCBs.
	 *  (data is error code)
	 */

#define NELOG_Unable_To_Unlock_Segment	(ERRLOG_BASE + 3)
	/*
	 * Service failed to release long-term lock on segment for NCBs.
	 *  (data is error code)
	 */

#define NELOG_Uninstall_Service		(ERRLOG_BASE + 4)
	/*
	 * Error uninstalling service %1
	 *  (error code from NetServiceControl is the data)
	 */

#define NELOG_Status_Update		(ERRLOG_BASE + 5)
	/*
	 * There was an error updating the service status. The error code
	 * is %1.
	 */

#define NELOG_Init_Exec_Fail		(ERRLOG_BASE + 6)
	/*
	 * Startup failed because of OS\2 exec failure on path %1;
	 *  OS\2 error code in raw data
	 */

#define NELOG_Ncb_Error			(ERRLOG_BASE + 7)
	/*
	 * Received unexpected NCB error %1; NCB in raw data
	 */

#define NELOG_Net_Not_Started		(ERRLOG_BASE + 8)
	/*
 	 * Network not started
	 */

#define NELOG_Ioctl_Error		(ERRLOG_BASE + 9)
	/*
 	 * DosDevIoctl to rdr fails
	 *	data is:  DWORD  approx CS:IP of call to ioctl
	 *		  WORD   error code
	 *		  WORD   ioctl number
	 */

#define NELOG_System_Semaphore		(ERRLOG_BASE + 10)
	/*
	 *  Unable to create or open system semaphore %1
	 *  (data is error code)
	 */

#define NELOG_Init_OpenCreate_Err	(ERRLOG_BASE + 11)
	/*
	 * Startup failed because of an open/create error on the
	 *  file %1; OS/2 error code in raw data.
	 */

#define NELOG_NetBios			(ERRLOG_BASE + 12)
	/*
	 *  Unexpected NetBios error
	 *  (data is error code)
	 */

#define NELOG_SMB_Illegal		(ERRLOG_BASE + 13)
	/*
	 *  Illegal SMB
	 *  (data is SMB)
	 */

#define NELOG_Service_Fail		(ERRLOG_BASE + 14)
	/*
	 * Startup failed because requested service %1 could not be
	 *  installed
	 */

#define NELOG_Entries_Lost		(ERRLOG_BASE + 15)
	/*
 	 * Some error log entries have been lost due to buffer overflow.
	 */


/*
 *	Server specific error log messages from 20 to 40
 */

#define NELOG_Init_Seg_Overflow		(ERRLOG_BASE + 20)
	/*
	 * Startup parameters controlling resource usage other
	 *  than net buffers are sized such that too much memory
	 *  is needed. Suggest lowering one or more of these
	 *  values.
	 */

#define NELOG_Srv_Shutdown_Shortages	(ERRLOG_BASE + 22)
	/* Server encountered resource shortages controlled by
	 *  the following parameters (parameter:# shortages):
	 *  %1
	 */

#define NELOG_Srv_Shutdown_Stats	(ERRLOG_BASE + 23)
	/* Server resource usage statistics follow in raw data.
	 *  See your admin guide for description.
	 */

#define NELOG_Srv_No_Mem_Grow		(ERRLOG_BASE + 24)
	/* Server cannot increase the size of a memory segment.
	 */

#define NELOG_Access_File_Bad		(ERRLOG_BASE + 25)
	/*
	 * Startup failed because account file: %1 is either incorrect
	 * or not present
	 */

#define NELOG_Srvnet_Not_Found		(ERRLOG_BASE + 26)
	/*
	 * Startup failed because Srvnet: %1 was not found
	 */

#define NELOG_Srvnet_Not_Started	(ERRLOG_BASE + 27)
	/*
	 * Startup failed because Srvnet: %1 was not started
	 */

#define NELOG_Init_Chardev_Err		(ERRLOG_BASE + 28)
	/*
	 * Either all three chdev parameters must be zero or
	 *  all three must be nonzero
	 */

#define NELOG_Remote_API		(ERRLOG_BASE + 29)
	/* A remote API request was aborted due to the following
	 * invalid descriptor string: %1
	 */

/*
 *	Message service and POPUP specific error log messages from 40 to 55
 */

#define NELOG_Msg_Shutdown		(ERRLOG_BASE + 40)
	/*
	 * The service has shut down due to repeated consecutive
	 * occurences of an NCB error. NCB follows in raw data.
	 */
	 
#define NELOG_Msg_Sem_Shutdown		(ERRLOG_BASE + 41)
	/*
	 * The message server has shut down due to a lock on the
	 * message server shared data segment.
	 */

#define	NELOG_Msg_Log_Err		(ERRLOG_BASE + 50)
	/*
	 * A file system error occured while opening or writing to the 
	 * system message log file, %1. 
	 * Message logging has been switched off due to the error.
	 * File system error follows in raw data.
	 */


#define NELOG_VIO_POPUP_ERR		(ERRLOG_BASE + 51)
	/*
	 * Unable to display message POPUP due to OS/2 VIO call error
	 */


#define	NELOG_Msg_Unexpected_SMB_Type	(ERRLOG_BASE + 52)
	/*
	 * A SMB arrived with an unexpected command type for the message server
	 * SMB follows in raw data.
	 */

	
/*
 *	Workstation specific error log messages from 60 to 75
 */


#define NELOG_Wksta_Infoseg		(ERRLOG_BASE + 60)
	/*
	 *  Infoseg is bigger than 64k bytes
	 *  (data is DWORD size of infoseg)
	 */

#define NELOG_Wksta_Compname		(ERRLOG_BASE + 61)
	/*
	 *  Unable to get name-number of computer name
	 */

#define NELOG_Wksta_Groupname		(ERRLOG_BASE + 62)
	/*
	 *  Unable to add or get name-number of special LANMAN
	 *  group name.
	 */

#define NELOG_Wksta_BiosThreadFailure	(ERRLOG_BASE + 63)
	/*
	 *  Error spawning or initializing Async NetBios Thread
	 *	(Data is error code)
	 */

#define NELOG_Wksta_IniSeg		(ERRLOG_BASE + 64)
	/*
	 * Error opening init shared segment
	 *	(Data is error code)
	 */


#define NELOG_Wksta_HostTab_Full	(ERRLOG_BASE + 65)
	/*
	 * Host table is full
	 */


#define NELOG_Wksta_Unk_Transaction	(ERRLOG_BASE + 66)
	/*
	 *  Unknown transaction SMB received via datagram
	 *  (data is SMB)
	 */

#define NELOG_Wksta_Bad_Mailslot_SMB	(ERRLOG_BASE + 67)
	/*
	 *  Bad mailslot SMB received  (opcode not write, or
	 *   delivery mode not legal, or priority out of range)
	 *  (data is SMB)
	 */



/*
 *	Alerter service specific error log messages from 70 to 79
 */


#define NELOG_Build_Name		(ERRLOG_BASE + 70)
	/*
	 * There was an error in building the list of names to alert. The
	 * error code is %1.
	 */

#define NELOG_Alrt_Err			(ERRLOG_BASE + 75)
	/*
	 * There was an error in registering the alerter to recieve 
	 * alerts. The error code is %1.
	 */


#define NELOG_Name_Expansion		(ERRLOG_BASE + 76)
	/*
	 * There was an error expanding %1 as a group name. Try
	 * splitting the group into two or more smaller groups.
	 */


#define NELOG_Format_Err		(ERRLOG_BASE + 77)
	/*
	 * There was an error formatting the alert message. The error
	 * code is %1.
	 */

#define NELOG_Message_Send		(ERRLOG_BASE + 78)
	/*
	 * There was an error sending %2 the alert message -
	 *    ( %3 )
	 *  The error code is %1.
	 */


#define NELOG_Mail_Slt_Err		(ERRLOG_BASE + 79)
	/*
	 * There was an error in creating or reading the alerter mailslot.
	 * The error code is %1.
	 */



#define NELOG_AT_cannot_read		(ERRLOG_BASE + 80)
	/*
	 * The server could not read the AT schedule file
	 */

#define NELOG_AT_sched_err		(ERRLOG_BASE + 81)
	/*
	 * The server found an invalid AT schedule record
	 */

#define NELOG_AT_schedule_file_created	(ERRLOG_BASE + 82)
	/*
	 * The server could not find an AT schedule file so it created one
	 */

#define NELOG_Srvnet_NB_Open		(ERRLOG_BASE + 83)
	/*
	 * The server could not NetBiosOpen network %1
	 */

#define NELOG_AT_Exec_Err		(ERRLOG_BASE + 84)
	/*
	 * The AT processor could not exec %1
	 */

/*
 *	Netwksta.sys specific error log messages from 100 to 109
 */

#define NELOG_NetWkSta_Internal_Error	(ERRLOG_BASE + 90)
	/*
	 * A NetWksta internal error has occurred:
	 *   %1
	 */

#define NELOG_NetWkSta_No_Resource	(ERRLOG_BASE + 91)
	/*
	 * Out of redirector resource: %1
	 */

#define NELOG_NetWkSta_SMB_Err		(ERRLOG_BASE + 92)
	/*
	 * SMB error on connection to %1
	 * (data is SMB header).
	 */

#define NELOG_NetWkSta_VC_Err		(ERRLOG_BASE + 93)
	/*
	 * VC error on session to %1
	 * (data is NCB command and retcode).
	 */

#define NELOG_NetWkSta_Stuck_VC_Err	(ERRLOG_BASE + 94)
	/*
	 * Hanging up stuck session to %1 
	 */

#define NELOG_NetWkSta_NCB_Err		(ERRLOG_BASE + 95)
	/*
	 * NCB error (%1).
	 * (data is NCB).
	 */

#define NELOG_NetWkSta_Write_Behind_Err	(ERRLOG_BASE + 96)
	/*
	 * Write to %1 failed.
	 */

#define NELOG_NetWkSta_Reset_Err	(ERRLOG_BASE + 97)
	/*
	 * Reset of driver (%1) failed to complete NCB.
	 * (data is uncompleted NCB).
	 */

/*
 *	Spooler specific error log messages from 100 to 109
 */

#define NELOG_Spooler_Exec_Failed		(ERRLOG_BASE + 100)
	/*
	 * The exec of SPOOLER.EXE failed.
	 */

#define NELOG_Cannot_Make_Spooldir		(ERRLOG_BASE + 101)
	/*
	 * Spooler initialization cannot make the spool directory.
	 */

#define NELOG_Spooler_Handshake_Failed		(ERRLOG_BASE + 102)
	/*
	 * Spooler did not handshake with initialization process.
	 */
#define NELOG_Q_Config_Error			(ERRLOG_BASE + 103)
	/*
	 * Print queue %1 configuration error. The %2 file cannot be found.
	 */
#define NELOG_PrintDest_Error			(ERRLOG_BASE + 104)
	/*
	 * Print destination %1  cannot be opened.
	 */

