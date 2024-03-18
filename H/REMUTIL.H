/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  USE.H					    *
 *								    *
 *  This file contains information about the NetUse APIs.	    *
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


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/

struct copy_info {
	unsigned short	ci_num_copied;
	char 		ci_err_buf[1];
};	/* copy_info */


struct move_info {
	unsigned short	mi_num_moved;
	char 		mi_err_buf[1];
};	/* move_info */

struct time_of_day_info {
    unsigned long   tod_elapsedt;   /* time from 1-1-1970 in seconds */
    unsigned long   tod_msecs;	    /* milliseconds */
    unsigned char   tod_hours;	    /* hours */
    unsigned char   tod_mins;	    /* minutes */
    unsigned char   tod_secs;	    /* seconds */
    unsigned char   tod_hunds;	    /* hundredths */
    unsigned short  tod_timezone;   /* time zone in minutes from GMT */
    unsigned short  tod_tinterval;  /* timer interval (units = 0.0001 sec */
    unsigned char   tod_day;	    /* day */
    unsigned char   tod_month;	    /* month */
    unsigned short  tod_year;	    /* year */
    unsigned char   tod_weekday;    /* day of week */
};	/* time_of_day_info */




/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/


#define MUST_BE_FILE	0x1
#define MUST_BE_DIR	0x2
#define ASCII_DEST	0x4
#define ASCII_SOURCE	0x8
#define VERIFY		0x10

/* Exec */

/***
 * flags bit map:
 *
 *  bit 0:  	0 - use msg mode pipe for std in
 *		1 - use char mode pipe for std in
 *  bit 1:  	0 - CWait for process tree before returning ExitCode to Ghost
 *		1 - CWait for exec'ed process before returning ExitCode to Ghost
 *  bit 2:  	0 - Map SIGINTR and SIGBREAK to SIGKILL when remoting signals
 *		1 - Send signals as received
 */

#define REM_PIPE_MODE 1
#define REM_WAIT_MODE 2
#define REM_SIGL_MODE 4

/* Time of Day */


extern API_FUNCTION
 NetRemoteCopy( char far *, char far *, char far *, char far *, 
		unsigned short, unsigned short, char far *, unsigned short);


extern API_FUNCTION
 NetRemoteMove( char far *, char far *, char far *, char far *, 
		unsigned short, unsigned short, char far *, unsigned short);


extern API_FUNCTION
 NetRemoteExec( char far *, char far *, unsigned, unsigned, char far *, 
		char far *, struct ResultCodes far *, char far *, 
		char far *, unsigned short);

extern API_FUNCTION
 NetRemoteTOD ( char far *, char far *, unsigned short );

