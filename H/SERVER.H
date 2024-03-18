/********************************************************************/
/**                   Microsoft OS/2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  SERVER.H				    *
 *								    *
 *  This file contains information about the NetServer APIs.	    *
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
  NetServerEnum( char far *, short, char far *, unsigned short, 
			unsigned short far *, unsigned short far *);


extern API_FUNCTION
  NetServerAdminCommand ( char far *, char far *, short far *, char far *,
			unsigned short, unsigned short far *, 
			unsigned short far * );

extern API_FUNCTION
  NetServerGetInfo ( char far *, short, char far *, unsigned short,
			unsigned short far * );

extern API_FUNCTION
  NetServerSetInfo ( char far *, short, char far *, unsigned short, short );


extern API_FUNCTION
  NetServerDiskEnum  ( char far *, short, char far *, unsigned short,
			unsigned short far *, unsigned short far *);


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/

struct server_info_0 {
    char	    sv0_name[CNLEN + 1]; 	/* Server name		    */
};	 /* server_info_0 */


struct server_info_1 {
    char	    sv1_name[CNLEN + 1];
    unsigned char   sv1_version_major;		/* Major version # of net   */
    unsigned char   sv1_version_minor;		/* Minor version # of net   */
    unsigned long   sv1_type;	     		/* Server type 		    */
    char far *	    sv1_comment; 		/* Exported server comment  */
};	 /* server_info_1 */


struct server_info_2 {
    char            sv2_name[CNLEN + 1];
    unsigned char   sv2_version_major;
    unsigned char   sv2_version_minor;
    unsigned long   sv2_type;	     
    char far *	    sv2_comment;		    
    unsigned long   sv2_ulist_mtime; /* User list, last modification time    */
    unsigned long   sv2_glist_mtime; /* Group list, last modification time   */
    unsigned long   sv2_alist_mtime; /* Access list, last modification time  */
    unsigned short  sv2_users;       /* max number of users allowed          */
    unsigned short  sv2_disc;	    /* auto-disconnect timeout(in seconds)  */
    char far *	    sv2_alerts;	    /* alert names (semicolon separated)    */
    unsigned short  sv2_security;    /* SV_USERSECURITY or SV_SHARESECURITY  */
    unsigned short  sv2_auditing;    /* 0 = no auditing; nonzero = auditing  */

    unsigned short  sv2_numadmin;    /* max number of administrators allowed */
    unsigned short  sv2_lanmask;     /* bit mask representing the srv'd nets */
    unsigned short  sv2_hidden;      /* 0 = visible; nonzero = hidden        */
    unsigned short  sv2_announce;    /* visible server announce rate (sec)   */
    unsigned short  sv2_anndelta;    /* announce randomize interval (sec)    */
                                    /* name of guest account                */
                                    /* NOTE: Destroys word alignment      */
    char            sv2_guestacct[UNLEN + 1];
    unsigned char   sv2_pad1;	    /* Word alignment pad byte		    */
    char far *      sv2_userpath;    /* asciz path to user directories       */
    unsigned short  sv2_chdevs;      /* max # shared character devices       */
    unsigned short  sv2_chdevq;      /* max # character device queues        */
    unsigned short  sv2_chdevjobs;   /* max # character device jobs          */
    unsigned short  sv2_connections; /* max # of connections		    */
    unsigned short  sv2_shares;	    /* max # of shares			    */
    unsigned short  sv2_openfiles;   /* max # of open files		    */
    unsigned short  sv2_sessopens;   /* max # of open files per session	    */
    unsigned short  sv2_sessvcs;     /* max # of virtual circuits per client */
    unsigned short  sv2_sessreqs;    /* max # of simul. reqs. from a client  */
    unsigned short  sv2_opensearch;  /* max # of open searches		    */
    unsigned short  sv2_activelocks; /* max # of active file locks           */
    unsigned short  sv2_numreqbuf;   /* number of server (standard) buffers  */
    unsigned short  sv2_sizreqbuf;   /* size of svr (standard) bufs (bytes)  */
    unsigned short  sv2_numbigbuf;   /* number of big (64K) buffers          */
    unsigned short  sv2_numfiletasks;/* number of file worker processes      */
    unsigned short  sv2_alertsched;  /* alert counting interval (minutes)    */
    unsigned short  sv2_erroralert;  /* error log alerting threshold         */
    unsigned short  sv2_logonalert;  /* logon violation alerting threshold   */
    unsigned short  sv2_accessalert; /* access violation alerting threshold  */
    unsigned short  sv2_diskalert;   /* low disk space alert threshold (KB)  */
    unsigned short  sv2_netioalert;  /* net i/o error ratio alert threshold  */
                                    /*  (tenths of a percent)               */
    unsigned short  sv2_maxauditsz;  /* Maximum audit file size in KB        */
    char far *	    sv2_srvheuristics; /* performance related server switches*/
};	/* server_info_2 */



/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/

/*
 *	Bit-mapped values for sv1_type and sv2_type fields.
 */

#define SV_TYPE_WORKSTATION	0x1
#define SV_TYPE_SERVER		0x2

/*
 *	Special value for sv2_disc that specifies infinite disconnect
 *	time.
 */

#define SV_NODISC		0xFFFF	/* No autodisconnect timeout enforced */

/*
 *	Values of sv2_security field.
 */

#define SV_USERSECURITY		1
#define SV_SHARESECURITY	0

/*
 *	Values for parmnum parameter to NetServerSetInfo.
 */

#define SV_COMMENT_PARMNUM	5
#define SV_DISC_PARMNUM 	10
#define SV_ALERTS_PARMNUM	11
#define SV_HIDDEN_PARMNUM	16
#define SV_ANNOUNCE_PARMNUM	17
#define SV_ANNDELTA_PARMNUM	18
#define SV_ALERTSCHED_PARMNUM	37
#define SV_ERRORALERT_PARMNUM	38
#define SV_LOGONALERT_PARMNUM	39
#define SV_ACCESSALERT_PARMNUM	40
#define SV_DISKALERT_PARMNUM	41
#define SV_NETIOALERT_PARMNUM	42
#define SV_MAXAUDITSZ_PARMNUM	43


#define SVI1_NUM_ELEMENTS	5
#define SVI2_NUM_ELEMENTS	44

/*
 *	Maxmimum length for command string to NetServerAdminCommand.
 */

#define	SV_MAX_CMD_LEN		80


