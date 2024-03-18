/********************************************************************/
/**                   Microsoft OS|2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  NETCONS.H				    *
 *								    *
 *  This file contains constants used throughout the Lan Manager    *
 *  API header files.  It should be included in any source file     *
 *  that is going to include other Lan Manager API header files or  *
 *  call a Lan Manager API.					    *
 *								    *
 ********************************************************************/

/*
 *	NOTE:  Lengths of ASCIZ strings are given as the maximum
 *	strlen() value.  This does not include space for the 
 *	terminating 0-byte.  When allocating space for such an item,
 *	use the form:
 *
 *		char username[UNLEN+1];
 */



#define CNLEN		15		    /* Computer name length     */
#define UNCLEN		(CNLEN+2)	    /* UNC computer name length */
#define NNLEN		12		    /* 8.3 Net name length      */
#define RMLEN		(UNCLEN+1+NNLEN)    /* Maximum remote name len  */

#define SNLEN		15		    /* Service name length      */
#define STXTLEN		63		    /* Service text length      */

#define PATHLEN        128                  /* Maximum path name len    */
#define DEVLEN		 8 		    /* Device name length	*/

#define EVLEN		16		    /* event name length        */
#define JOBSTLEN	32		    /* status len in print job  */
#define	AFLEN		64		    /* Maximum length of alert  */
					    /* names field 		*/
#define UNLEN		20	   	    /* Maximum user name length	*/
#define GNLEN 		UNLEN		    /* Group name */
#define PWLEN		14		    /* Maximum password length  */
#define	SHPWLEN		 8		    /* Share password length    */


#define MAXCOMMENTSZ	49		    /* server & share comment length */

#define QNLEN		NNLEN		    /* Queue name maximum length     */
#define PDLEN		 8		    /* Print destination length      */
#define DTLEN		 8	            /* Spool file data type          */
					    /* e.g. IBMQSTD,IBMQESC,IBMQRAW  */
#define ALERTSZ		128		    /* size of alert string in server */
#define MAXDEVENTRIES	(sizeof (int)*8)    /* Max no of device entries */
					    /* We use int bitmap to represent */

#define NETBIOS_NAME_LEN	16	    /* NetBios net name */



/*
 *	Constants used with encryption
 */

#define	CRYPT_KEY_LEN	7
#define	CRYPT_TXT_LEN	8
#define ENCRYPTED_PWLEN	16
#define SESSION_PWLEN	24
#define SESSION_CRYPT_KLEN 21

/*
 *	Message File Name
 */

#define MESSAGE_FILE		"NETPROG\\NET.MSG"
#define MESSAGE_FILENAME	"NET.MSG"

#ifndef NULL
#define  NULL    0
#endif

/*NOINC*/
#define API_RET_TYPE unsigned
#define API_FUNCTION API_RET_TYPE far pascal
/*INC*/
