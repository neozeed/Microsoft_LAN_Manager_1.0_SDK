/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  WKSTA.H				    *
 *								    *
 *  This file contains information about the NetWksta APIs.	    *
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
  NetWkstaLogon ( char far *, char far *, char far *, unsigned long far *,
		  char far *, unsigned short );

extern API_FUNCTION
  NetWkstaReLogon ( char far *, char far *, char far *, char far *, 
		unsigned short );

extern API_FUNCTION
  NetWkstaLogoff ( char far *, char far *, unsigned long );

extern API_FUNCTION
  NetWkstaGetInfo ( char far *, short, char far *, unsigned short,
			 unsigned short far * );

extern API_FUNCTION
  NetWkstaSetInfo ( char far *, short, char far *, unsigned short, short );

extern API_FUNCTION 
 NetWkstaAnnounce ( unsigned short, char far *, unsigned short );

#define SETUID_NOFORCE 0
#define SETUID_FORCE 1

extern API_FUNCTION
  NetWkstaSetUID ( char far *, char far *, char far *, char far *, 
			unsigned short );


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/

struct wksta_info_0 {
    unsigned short  wki0_reserved_1;
    unsigned long   wki0_reserved_2;
    char far *	    wki0_root;
    char far *	    wki0_computername;
    char far *	    wki0_username;
    char far *      wki0_langroup;
    unsigned char   wki0_ver_major;
    unsigned char   wki0_ver_minor;
    unsigned long   wki0_reserved_3;
    unsigned short  wki0_charwait;
    unsigned long   wki0_chartime;
    unsigned short  wki0_charcount;
    unsigned short  wki0_reserved_4;
    unsigned short  wki0_reserved_5;
    unsigned short  wki0_keepconn;
    unsigned short  wki0_keepsearch;
    unsigned short  wki0_maxthreads;
    unsigned short  wki0_maxcmds;
    unsigned short  wki0_maxpipes;
    unsigned short  wki0_numworkbuf;
    unsigned short  wki0_sizworkbuf;
    unsigned short  wki0_maxwrkcache;
    unsigned short  wki0_sesstimeout;
    unsigned short  wki0_sizerror;
    unsigned short  wki0_numalerts;
    unsigned short  wki0_numservices;
    unsigned short  wki0_errlogsz;
    unsigned short  wki0_printbuftime;
    unsigned short  wki0_numcharbuf;
    unsigned short  wki0_sizcharbuf;
    char far *	    wki0_logon_server;	
    char far *	    wki0_wrkheuristics;
    unsigned short  wki0_mailslots;
};	/* wksta_info_0 */


/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/


/*
 * 	Constants for use as NetWkstaSetInfo parmnum parameter 
 */

#define WKSTA_CHARWAIT_PARMNUM	   	10
#define WKSTA_CHARTIME_PARMNUM	   	11	
#define WKSTA_CHARCOUNT_PARMNUM    	12   
#define WKSTA_ERRLOGSZ_PARMNUM     	27
#define WKSTA_PRINTBUFTIME_PARMNUM 	28
#define WKSTA_WRKHEURISTICS_PARMNUM 	32

/*
 * 	Definitions for NetWkstaSetUID's ucond parameter 
 */

#define WKSTA_NOFORCE         0
#define WKSTA_FORCE           1
#define WKSTA_LOTS_OF_FORCE   2
#define WKSTA_MAX_FORCE       3



