/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  CONFIG.H				    *
 *								    *
 *  This file contains information about the NetConfig APIs.	    *
 *								    *
 ********************************************************************/


/**************************************************************** 
 *								*
 *	  	Function prototypes 				*
 *								*
 ****************************************************************/


extern API_FUNCTION
  NetConfigGet ( const char far *, const char far *, char far *, 
			unsigned short, 
			unsigned short far *);

extern API_FUNCTION
  NetConfigGetAll ( const char far *, char far *, unsigned short, 
			unsigned short far *, unsigned short far * );


