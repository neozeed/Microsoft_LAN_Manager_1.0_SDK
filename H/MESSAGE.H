/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  MESSAGE.H				    *
 *								    *
 *  This file contains information about the NetMessage APIs.	    *
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
  NetMessageBufferSend( char far *,char far *, char far *, unsigned short);

extern API_FUNCTION
  NetMessageFileSend( char far *, char far *, char far *);

extern API_FUNCTION 	
  NetMessageLogFileGet( char far *, char far *, unsigned short, short far *);

extern API_FUNCTION 
  NetMessageLogFileSet( char far *, char far *, short);

extern API_FUNCTION
  NetMessageNameAdd( char far *, char far *, short);

extern API_FUNCTION 	
  NetMessageNameDel( char far *, char far *, short);

extern API_FUNCTION 	
  NetMessageNameFwd( char far *, char far *, char far *, short);

extern API_FUNCTION 	
  NetMessageNameGetInfo( char far *, char far *, short, char far *, unsigned short, unsigned short far *);
  
extern API_FUNCTION 	
  NetMessageNameUnFwd( char far *, char far *);

extern API_FUNCTION 	
  NetMessageNameEnum( char far *, short, char far *, unsigned short, unsigned short far *, unsigned short far *);
 

/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/

struct msg_info_0 {
    char		msgi0_name[CNLEN + 1];
};

struct msg_info_1 {
    char		msgi1_name[CNLEN + 1];
    unsigned char	msgi1_forward_flag;
    unsigned char	msgi1_pad1;
    char		msgi1_forward[CNLEN + 1];
};


/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/

/*
 *	Values for msgi1_forward_flag.
 */

#define MSGNAME_NOT_FORWARDED	0	/* Name not forwarded */
#define MSGNAME_FORWARDED_TO	0x04	/* Name forward to remote station */
#define MSGNAME_FORWARDED_FROM  0x10	/* Name forwarded from remote station */


