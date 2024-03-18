/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  SERVICE.H 				    *
 *								    *
 *  This file contains information about the NetService APIs.	    *
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
  NetServiceEnum ( const char far *, short, char far *, unsigned short, 
			unsigned short far *, unsigned short far * );

extern API_FUNCTION
  NetServiceGetInfo ( const char far *, const char far *, short, char far *, 
			unsigned short, unsigned short far * );

extern API_FUNCTION
  NetServiceInstall ( const char far *, const char far *, const char far *, 
			char far *, unsigned short );

extern API_FUNCTION
  NetServiceControl ( const char far *, const char far *, unsigned char, 
			unsigned char, char far *, unsigned short );

extern API_FUNCTION
  NetServiceStatus( const char far *, unsigned short );


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/


struct service_info_0 {
    char 	    svci0_name[SNLEN+1];
};	/* service_info_0 */

struct service_info_1 {
    char 	    svci1_name[SNLEN+1];  /* service name 			*/
    unsigned short  svci1_status;	       /* See "status values" above 	*/
    unsigned long   svci1_code;	       /* install code of service	*/
    unsigned short  svci1_pid;	       /* pid of service program	*/
};	/* service_info_1 */

struct service_info_2 {
    char 	    svci2_name[SNLEN+1];  /* service name 			*/
    unsigned short  svci2_status;	       /* See "status values" above 	*/
    unsigned long   svci2_code;	       /* install code of service	*/
    unsigned short  svci2_pid;	       /* pid of service program	*/
    char	    svci2_text[STXTLEN+1];   /* text area for use by services */
};	/* service_info_2 */

struct service_status {
    unsigned short  svcs_status;	       /* See "status values" above 	*/
    unsigned long   svcs_code;	       /* install code of service	*/
    unsigned short  svcs_pid;	       /* pid of service program	*/
    char	    svcs_text[STXTLEN+1];   /* text area for use by services */
};	/* service_status */



/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/

/*
 *	SERVICE_RCV_SIG_FLAG is the value passed to DosSetSigHandler when 
 *	installing the handler within a service, to recieve control
 *	signals.
 */

#define SERVICE_RCV_SIG_FLAG 5

/* 
 *	Bitmask and bit values for svci1_status, svci2_status, and
 *	svcs_status fields.  For each "sub-field", there is a mask
 *	defined, and a number of constants representing the value
 *	obtained by doing (status & mask).
 */

/* Bits 0,1 -- general status */

#define SERVICE_INSTALL_STATE  		0x03
#define	SERVICE_UNINSTALLED 		0x00
#define	SERVICE_INSTALL_PENDING		0x01
#define	SERVICE_UNINSTALL_PENDING	0x02
#define	SERVICE_INSTALLED		0x03

/* Bits 2,3 -- paused/active status */

#define SERVICE_PAUSE_STATE  		0x0C
#define SERVICE_ACTIVE			0x00
#define	SERVICE_CONTINUE_PENDING	0x04
#define SERVICE_PAUSE_PENDING		0x08
#define SERVICE_PAUSED			0x0C

/* Bit 4 -- uninstallable indication */

#define SERVICE_NOT_UNINSTALLABLE	0x00
#define SERVICE_UNINSTALLABLE		0x10

/* Bit 5 -- pausable indication */

#define SERVICE_NOT_PAUSABLE		0x00
#define SERVICE_PAUSABLE		0x20

/* Workstation service only:  
 * Bits 8,9,10 -- redirection paused/active */

#define SERVICE_REDIR_PAUSED		0x700
#define SERVICE_REDIR_DISK_PAUSED	0x100
#define SERVICE_REDIR_PRINT_PAUSED	0x200
#define SERVICE_REDIR_COMM_PAUSED	0x400

/* 
 *	Standard Lan Manager service names.
 */

#define SERVICE_WORKSTATION	"WORKSTATION"
#define SERVICE_SERVER		"SERVER"
#define SERVICE_MESSENGER	"MESSENGER"
#define SERVICE_NETRUN	 	"NETRUN"
#define SERVICE_SPOOLER		"SPOOLER"
#define SERVICE_ALERTER 	"ALERTER"
#define SERVICE_NETLOGON 	"NETLOGON"
#define SERVICE_NETPOPUP	"NETPOPUP"

/*
 *	NetServiceControl opcodes.
 */

#define SERVICE_CTRL_INTERROGATE	0
#define SERVICE_CTRL_PAUSE		1
#define SERVICE_CTRL_CONTINUE		2
#define SERVICE_CTRL_UNINSTALL		3

/*
 *	Workstation service only:  Bits used in the "arg" parameter
 *	to NetServiceControl in conjunction with the opcode
 *	SERVICE_CTRL_PAUSE or SERVICE_CTRL_CONTINUE, to pause or
 *	continue redirection.
 */

#define SERVICE_CTRL_REDIR_DISK		0x1
#define SERVICE_CTRL_REDIR_PRINT	0x2
#define SERVICE_CTRL_REDIR_COMM		0x4


/*
 *	Values for svci1_code, svci2_code, and svcs_code when
 *	status of the service is SERVICE_INSTALL_PENDING
 *	A service can optionally provide a hint to the installer
 *	that the install is proceeding and how long to wait
 *	(in 0.1 second increments) before querying status again.
 */

#define SERVICE_IP_NO_HINT		0x0
#define SERVICE_IP_QUERY_HINT		0x10000

	/* Mask for install proceeding checkpoint number */
#define SERVICE_IP_CHKPT_NUM		0x0FF

	/* Mask for wait time hint before querying again */
#define SERVICE_IP_WAIT_TIME		0x0FF00

	/* Shift count for building wait time _code values */
#define SERVICE_IP_WAITTIME_SHIFT	8



/*NOINC*/
#define SERVICE_IP_CODE(tt,nn) \
  ((long)SERVICE_IP_QUERY_HINT|(long)(nn|(tt<<SERVICE_IP_WAITTIME_SHIFT)))

#define SERVICE_UIC_CODE(cc,mm) \
  ((long)(((long)cc<<16)|(long)(unsigned)mm))
/*INC*/

/***	SERVICE_BASE is the base of service error codes,
 *	chosen to avoid conflict with OS, redirector,
 *	netapi, and errlog codes.  
 */

#define SERVICE_BASE	2950


/*  Uninstall codes, to be used in high byte of 'code' on final NetStatus,
 *  which sets the status to UNINSTALLED 
 */

/*NOINC*/
#define SERVICE_UIC_NORMAL	0
#define SERVICE_UIC_BADPARMVAL	(SERVICE_BASE + 1) \
        /* LANMAN.INI or the command line has an illegal value for %1. */
#define SERVICE_UIC_MISSPARM	(SERVICE_BASE + 2) \
        /* The required parameter "%1" was not provided on the command line or in LANMAN.INI. */
#define SERVICE_UIC_UNKPARM	(SERVICE_BASE + 3) \
        /* The unknown parameter "%1" was provided on the command line or in LANMAN.INI. */
#define SERVICE_UIC_RESOURCE	(SERVICE_BASE + 4) /* A request for a resource "%1" could not be satisfied. */
#define SERVICE_UIC_CONFIG	(SERVICE_BASE + 5) /* A problem exists with the system configuration %1. */
#define SERVICE_UIC_SYSTEM	(SERVICE_BASE + 6) /* A system error has occured. */
#define SERVICE_UIC_INTERNAL	(SERVICE_BASE + 7) /* An internal consistency error has occured. */
#define SERVICE_UIC_AMBIGPARM	(SERVICE_BASE + 8) \
        /* LANMAN.INI or the command line has an ambiguous parameter "%1". */
#define SERVICE_UIC_DUPPARM	(SERVICE_BASE + 9) \
        /* LANMAN.INI or the command line has a duplicate parameter "%1". */
#define SERVICE_UIC_KILL	(SERVICE_BASE + 10) \
        /* The service did not respond to control and was terminated with the DosKillProc function.*/
#define SERVICE_UIC_EXEC	(SERVICE_BASE + 11) \
	/* There was an error executing the service. */
#define SERVICE_UIC_SUBSERV	(SERVICE_BASE + 12) \
	/* Sub-service %1 failed to install. */
/*INC*/

/***
 *	The modifiers
 */

/*  General: */
#define SERVICE_UIC_M_NULL	0

/*  BADPARMVAL:  A text string in service_info_2.text */
/*  MISSPARM:  ditto */
/*  UNKPARM:  ditto */
/*  AMBIGPARM:  ditto */
/*  DUPPARM:  ditto */
/*  SUBSERV:  ditto */

/*NOINC*/
/*  RESOURCE: */
#define SERVICE_UIC_M_MEMORY	(SERVICE_BASE + 20) /* @I
	*, memory%0 */
#define SERVICE_UIC_M_DISK	(SERVICE_BASE + 21) /* @I 
	*, disk space%0 */
#define SERVICE_UIC_M_THREADS	(SERVICE_BASE + 22) /* @I 
	*, threads%0 */
#define SERVICE_UIC_M_PROCESSES	(SERVICE_BASE + 23) /* @I 
	*, processes%0 */

/*  CONFIG: */
#define SERVICE_UIC_M_SECURITY	(SERVICE_BASE + 24) /* @I 
	*:  Security Failure%0 */
#define SERVICE_UIC_M_LANROOT	(SERVICE_BASE + 25) /* @I 
	*:  Bad or Missing Lan Root%0 */
#define SERVICE_UIC_M_REDIR	(SERVICE_BASE + 26) /* @I 
	*:  Network not installed%0 */
#define SERVICE_UIC_M_SERVER	(SERVICE_BASE + 27) /* @I 
	*:  Server not started%0 */
#define SERVICE_UIC_M_SUBSERV	(SERVICE_BASE + 28) /* @I 
	*:  A sub-service failed to install%0 */
#define SERVICE_UIC_M_FILES	(SERVICE_BASE + 29) /* @I 
	*:  The LANMAN has incompatible files%0 */
#define SERVICE_UIC_M_LOGS	(SERVICE_BASE + 30) /* @I
	*:  The LANMAN\LOGS directory is invalid%0 */
#define SERVICE_UIC_M_LANGROUP	(SERVICE_BASE + 31) /* @I
	*:  The LANGROUP specified could not be used%0 */
#define SERVICE_UIC_M_MSGNAME	(SERVICE_BASE + 32) /* @I
	*:  The COMPUTERNAME specified is in use as a messaging name on another machine%0 */
/*INC*/


/* SYSTEM:  A DOS or NET error number */
/* INTERNAL:  None */
/* KILL:  None */
/* EXEC:  None */

/***
 *	End modifiers
 */

