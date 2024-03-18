/********************************************************************
 **                   Microsoft OS/2 LAN Manager                   **
 **            Copyright(c) Microsoft Corp., 1987, 1988            **
 ********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  MAILSLOT.H				    *
 *								    *
 *  This file contains information about the Mailslot APIs.	    *
 *								    *
 *	Function prototypes.					    *
 *								    *
 ********************************************************************/


/**************************************************************** 
 *								*
 *	  	Function prototypes 				*
 *								*
 ****************************************************************/


extern API_FUNCTION
    DosMakeMailslot( const char far *, unsigned short, unsigned short, 
		unsigned far * );

extern API_FUNCTION
    DosDeleteMailslot( unsigned );

extern API_FUNCTION
    DosMailslotInfo( unsigned, unsigned short far *, unsigned short far *, 
		unsigned short far *, unsigned short far *, 
		unsigned short far * );

extern API_FUNCTION
    DosReadMailslot( unsigned, char far *, unsigned short far *, 
		unsigned short far *, unsigned short far *, long );

extern API_FUNCTION
    DosPeekMailslot( unsigned, char far *, unsigned short far *, 
		unsigned short far *, unsigned short far * );

extern API_FUNCTION
    DosWriteMailslot( const char far *, const char far *, unsigned short, 
		unsigned short, unsigned short, long);
