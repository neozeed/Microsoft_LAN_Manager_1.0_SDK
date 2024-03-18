/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  NETBIOS.H				    *
 *								    *
 *  This file contains information about the NetBios APIs.	    *
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
 ********************************************************************
 *								    *
 *  NOTICE:  The redirector uses this include file.  If you change  *
 *           it, you need to make sure that the redir still builds. *
 *								    *
 ********************************************************************/

/**************************************************************** 
 *								*
 *	  	Function prototypes 				*
 *								*
 ****************************************************************/

/*NOINC*/
extern API_FUNCTION 
  NetBiosEnum( char far *, short, char far *, unsigned short, 
			unsigned short far *, unsigned short far *);

extern API_FUNCTION 
  NetBiosGetInfo( char far *, char far *, short, char far *, 
			unsigned short, unsigned short far * );

extern API_FUNCTION 
  NetBiosOpen( char far *, char far *, unsigned short, unsigned short far * );

extern API_FUNCTION 
  NetBiosClose( unsigned short, unsigned short );

extern API_FUNCTION 
  NetBiosSubmit( unsigned short, unsigned short, struct ncb far *);
/*INC*/


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/


struct netbios_info_0 {
    char  	   nb0_net_name[NETBIOS_NAME_LEN+1];
};	/* netbios_info_0 */

struct netbios_info_1 {
    char    	   nb1_net_name[NETBIOS_NAME_LEN+1];   
    char           nb1_driver_name[DEVLEN+1];/* OS/2 device driver name        */
    unsigned char  nb1_lana_num;             /* Lan adapter number of this net */
    char	   nb1_pad_1;
    unsigned short nb1_driver_type;
    unsigned short nb1_net_status;           
    unsigned long  nb1_net_bandwidth;        /* Network bandwidth, bits/s      */
    unsigned short nb1_max_sess;             /* Max number of sessions         */
    unsigned short nb1_max_ncbs;             /* Max number of outstanding NCBs */
    unsigned short nb1_max_names;            /* Max number of names            */
};	/* netbios_info_1 */


/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/


/*
 *	Driver types (nb1_driver_type).
 */

#define	NB_TYPE_NCB	1
#define	NB_TYPE_MCB	2

/*
 *	Bits defined in nb1_net_status.
 */

#define NB_LAN_MANAGED	0x0001		/* Lan is managed by redirector */
#define NB_LAN_LOOPBACK	0x0002		/* Lan is a loopback driver */

/*
 *	Open modes for NetBiosOpen.
 */

#define	NB_REGULAR	1 
#define	NB_PRIVILEGED	2
#define	NB_EXCLUSIVE	3 



