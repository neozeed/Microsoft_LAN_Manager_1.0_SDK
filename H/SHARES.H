/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  SHARES.H				    *
 *								    *
 *  This file contains information about the NetShare, NetSession,  *
 *  Net File, and NetConnection APIs.  For each API class there is  *
 *  a section on:						    *
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
 *	  	Function prototypes - SHARE			*
 *								*
 ****************************************************************/


extern API_FUNCTION
  NetShareEnum(char far *, short, char far *, unsigned short,
	       unsigned short far *, unsigned short far *);

extern API_FUNCTION
  NetShareGetInfo(char far *, char far *, short, char far *,
		  unsigned short, unsigned short far *);

extern API_FUNCTION
  NetShareSetInfo(char far *, char far *, short, char far *, 
		  unsigned short, short);

extern API_FUNCTION
  NetShareAdd(char far *, short , char far *, unsigned short);

extern API_FUNCTION
  NetShareDel(char far *, char far *, unsigned short);

extern API_FUNCTION
  NetShareCheck(char far *, char far *, unsigned short far *);



/**************************************************************** 
 *								*
 *	  	Data structure templates - SHARE		*
 *								*
 ****************************************************************/

struct share_info_0 {
    char		shi0_netname[NNLEN+1];
};  /* share_info_0 */

struct share_info_1 {
    char		shi1_netname[NNLEN+1];
    char		shi1_pad1;
    unsigned short	shi1_type;
    char far *		shi1_remark;
};  /* share_info_1 */

struct share_info_2 {
    char		shi2_netname[NNLEN+1];
    char		shi2_pad1;
    unsigned short	shi2_type;
    char far *		shi2_remark;
    unsigned short	shi2_permissions;
    unsigned short	shi2_max_uses;
    unsigned short	shi2_current_uses;
    char far *		shi2_path;
    char 		shi2_passwd[SHPWLEN+1];
    char		shi2_pad2;
};  /* share_info_2 */


/**************************************************************** 
 *								*
 *	  	Special values and constants - SHARE		*
 *								*
 ****************************************************************/


/*
 *	Values for parmnum parameter to NetShareSetInfo.
 */

#define	SHI_REMARK_PARMNUM		4
#define	SHI_PERMISSIONS_PARMNUM		5
#define	SHI_MAX_USES_PARMNUM		6
#define	SHI_PASSWD_PARMNUM		9

#define	SHI1_NUM_ELEMENTS		4
#define	SHI2_NUM_ELEMENTS		10


/*
 *	Share types (shi1_type and shi2_type fields).
 */

#define STYPE_DISKTREE 			0
#define STYPE_PRINTQ   			1
#define STYPE_DEVICE   			2
#define STYPE_IPC      			3


/**************************************************************** 
 *								*
 *	  	Function prototypes - SESSION			*
 *								*
 ****************************************************************/

extern API_FUNCTION 
  NetSessionEnum( char far *, short, char far *, unsigned short, 
		  unsigned short far *, unsigned short far *);

extern API_FUNCTION 
  NetSessionGetInfo( char far *, char far *, short, char far *,
		     unsigned short, unsigned short far *);

extern API_FUNCTION 
  NetSessionDel( char far *, char far *, short);


/**************************************************************** 
 *								*
 *		Data structure templates - SESSION		*
 *								*
 ****************************************************************/


struct session_info_0 {
    char far *		sesi0_cname;
};  /* session_info_0 */

struct session_info_1 {
    char far *		sesi1_cname;
    char far *		sesi1_username;
    unsigned short	sesi1_num_conns;
    unsigned short	sesi1_num_opens;
    unsigned short	sesi1_num_users;
    unsigned long	sesi1_time;
    unsigned long	sesi1_idle_time;
    unsigned long	sesi1_user_flags;
};  /* session_info_1 */


/**************************************************************** 
 *								*
 *	  	Special values and constants - SESSION		*
 *								*
 ****************************************************************/

/*
 *	Bits defined in sesi1_user_flags.
 */

#define SESS_GUEST		1	/* session is logged on as a guest */
#define SESS_NOENCRYPTION	2	/* session is using encryption     */


/**************************************************************** 
 *								*
 *	  	Function prototypes - CONNECTION		*
 *								*
 ****************************************************************/

extern API_FUNCTION 
  NetConnectionEnum( char far *, char far *, short, char far *, unsigned short,
		     unsigned short far *, unsigned short far *);


/**************************************************************** 
 *								*
 *	  	Data structure templates - CONNECTION		*
 *								*
 ****************************************************************/

struct connection_info_0 {
    unsigned short	coni0_id;
};  /* connection_info_0 */

struct connection_info_1 {
    unsigned short	coni1_id;
    unsigned short	coni1_type;
    unsigned short	coni1_num_opens;
    unsigned short	coni1_num_users;
    unsigned long	coni1_time;
    char far *		coni1_username;
    char far *		coni1_netname;
};  /* connection_info_1 */



/**************************************************************** 
 *								*
 *	  	Function prototypes - CONNECTION		*
 *								*
 ****************************************************************/

extern API_FUNCTION
    NetFileEnum( char far *, char far *, short, char far *, unsigned short,
		 unsigned short far *, unsigned short far * );

extern API_FUNCTION
    NetFileGetInfo( char far *, unsigned short, short, char far *,
		    unsigned short, unsigned short far * );

extern API_FUNCTION 
    NetFileClose( char far *, unsigned short);
    

/**************************************************************** 
 *								*
 *	  	Data structure templates - FILE			*
 *								*
 ****************************************************************/

struct file_info_0 {
    unsigned short	fi0_id;
};  /* file_info_0 */

struct file_info_1 {
    unsigned short	fi1_id;
    unsigned short	fi1_permissions;
    unsigned short	fi1_num_locks;
    char far *		fi1_pathname;
    char far *		fi1_username;
};  /* file_info_1 */


/**************************************************************** 
 *								*
 *		Special values and constants - FILE		*
 *								*
 ****************************************************************/

				/* bit values for permissions */
#define	FILE_READ	0x1	/* user has read access */
#define	FILE_WRITE	0x2	/* user has write access */
#define	FILE_CREATE	0x4	/* user has create access */
