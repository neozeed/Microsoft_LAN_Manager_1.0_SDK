/********************************************************************/
/**                   Microsoft OS/2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/


/********************************************************************
 *
 *  About this file ...  ALERT.H
 *
 *  This file contains information about the NetUse APIs.
 *
 *	Function prototypes.
 *
 *	Data structure templates.
 *
 *	Definition of special values.
 *
 *
 *  NOTE:  You must include NETCONS.H before this file, since this
 *	   file	depends on values defined in NETCONS.H.
 *
 *  NOTE:  ALERT.H includes ALERTMSG.H, which defined the alert message
 *	   numbers.
 *
 ********************************************************************/


#include "alertmsg.h"



/**************************************************************** 
 *								*
 *	  	Function prototypes 				*
 *								*
 ****************************************************************/

extern API_FUNCTION
  NetAlertStart ( const char far *, const char far *, unsigned short );

extern API_FUNCTION
  NetAlertStop ( const char far *, const char far * );

extern API_FUNCTION
  NetAlertRaise ( const char far *, const char far *, unsigned short, unsigned long );



/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/


/***   Standard alert structure
 */

struct std_alert
{
        long    alrt_timestamp;          
        char    alrt_eventname[EVLEN+1]; 
        char    alrt_servicename[SNLEN+1];
};

/*
 *	The following macro gives a pointer to the other_info data.
 *	It takes a "struct std_alert *" and returns a "char *".
 */

#define ALERT_OTHER_INFO(x)    ((char *)(x)     + sizeof(struct std_alert))
#define ALERT_OTHER_INFO_F(x)  ((char far *)(x) + sizeof(struct std_alert))

/*
 *	The following macro gives a pointer to the val-len data.
 *	It takes a pointer to one of the other-info structs and
 *	returns a "char *".
 */

#define ALERT_VAR_DATA(p)      ((char *)(p)     + sizeof(*p))
#define ALERT_VAR_DATA_F(p)    ((char far *)(p) + sizeof(*p))


/***   Print alert other-info structure
 */

struct print_other_info { 
        short   alrtpr_jobid;       /* Job id for job */
        short   alrtpr_status;      /* Status word from job info struct */
				    /* bit 15 == 1 means job deleted */
        long    alrtpr_submitted;   /* When submitted */
        long    alrtpr_size;        /* Bytes in job */
};

/*	Followed by (consecutive ASCIZ strings) ...
 *
 *		computername
 *		username
 *		queuename
 *		destination
 *		status string
 */

/***   Error log alert other-info structure
 */

struct errlog_other_info {
	short	alrter_errcode;
	long	alrter_offset;
};

/***   Admin alert other-info structure
 */

struct admin_other_info {
	short	alrtad_errcode;		/* code for message in net error message file */
	short	alrtad_numstrings;	/* the number of merge strings 0-9 */
};

/*	Followed by merge strings (consecutive ASCIZ strings, count
 *	is in alrtad_numstrings field).
 */


/***   User alert other-info structure
 */

struct user_other_info {
	short	alrtus_errcode;	/* code for message in net error message file */
	short	alrtus_numstrings;	 /* the number of merge strings 0-9 */
};

/*	Followed by merge strings (consecutive ASCIZ strings, count
 *	is in alrtus_numstrings field).
 *
 *	Further followed by (consecutive ASCIZ strings) ...
 *
 *		username
 *		computername
 */


/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/

/*
 *	Names of standard Microsoft-defined alert events.
 */

#define ALERT_PRINT_EVENT	"PRINTING"   
#define ALERT_MESSAGE_EVENT	"MESSAGE"
#define ALERT_ERRORLOG_EVENT	"ERRORLOG"
#define ALERT_ADMIN_EVENT	"ADMIN"
#define ALERT_USER_EVENT	"USER"

/*
 * 	Three suggested timeouts (in milliseconds) for NetAlertRaise.
 */

#define ALERT_SHORT_WAIT	100L
#define ALERT_MED_WAIT		1000L
#define ALERT_LONG_WAIT		10000L



