/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  NETSTATS.H				    *
 *								    *
 *  This file contains information about the NetStatistics APIs.    *
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
  NetStatisticsClear ( char far * );

extern API_FUNCTION
  NetStatisticsGet ( char far *, char far *, unsigned short,
			unsigned short far *, unsigned short far *);

/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/






struct statistics_info_0 {
    unsigned long   st0_start;        /* time statistics collection started   */
    unsigned long   st0_wknumNCBs;    /* # workstation NCBs issued            */
    unsigned long   st0_wkfiNCBs;     /* # workstation NCBs failed issue      */
    unsigned long   st0_wkfcNCBs;     /* # workstation NCBs failed completion */
    unsigned long   st0_wksesstart;   /* # workstation sessions started       */
    unsigned long   st0_wksessfail;   /* # workstation session failures       */
    unsigned long   st0_wkuses;       /* # workstation uses                   */
    unsigned long   st0_wkusefail;    /* # workstation use failures           */
    unsigned long   st0_wkautorec;    /* # workstation auto-reconnects        */
    unsigned long   st0_reserved1;    /* reserved for future use              */
    unsigned long   st0_reserved2;    /* reserved for future use              */
    unsigned long   st0_reserved3;    /* reserved for future use              */
    unsigned long   st0_reserved4;    /* reserved for future use              */
    unsigned long   st0_reserved5;    /* reserved for future use              */
    unsigned long   st0_reserved6;    /* reserved for future use              */
    unsigned long   st0_reserved7;    /* reserved for future use              */
    unsigned long   st0_reserved8;    /* reserved for future use              */
    unsigned long   st0_svfopens;     /* # of server file opens               */
    unsigned long   st0_svdevopens;   /* # of server device opens             */
    unsigned long   st0_svjobsqueued; /* # of server print jobs spooled       */
    unsigned long   st0_svsopens;     /* # of server session starts           */
    unsigned long   st0_svstimedout;  /* # of server session auto-disconnects */
    unsigned long   st0_svserrorout;  /* # of server sessions errored out     */
    unsigned long   st0_svpwerrors;   /* # of server password violations      */
    unsigned long   st0_svpermerrors; /* # of server access permission errors */
    unsigned long   st0_svsyserrors;  /* # of server system errors            */
    unsigned long   st0_svbytessent;  /* # of server bytes sent to net        */
    unsigned long   st0_svbytesrcvd;  /* # of server bytes received from net  */
    unsigned long   st0_svavresponse; /* average server response time in msec */
};  /* statistics_info */




