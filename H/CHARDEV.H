/********************************************************************/
/**                   Microsoft OS/2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  CHARDEV.H				    *
 *								    *
 *  This file contains information about the NetCharDev and 	    *
 *  NetCharDevQ APIs.						    *
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
NetCharDevEnum( char far *, short, char far *, unsigned short,
    unsigned short far *, unsigned short far *);

extern API_FUNCTION
NetCharDevGetInfo(char far *, char far *, short, char far *, 
    unsigned short, unsigned short far *);

extern API_FUNCTION
NetCharDevControl(char far *, char far *, short);

extern API_FUNCTION 
NetCharDevQEnum(char far *, char far *, short, char far *, unsigned short,
    unsigned short far *, unsigned short far *);

extern API_FUNCTION
NetCharDevQGetInfo(char far *, char far *, char far *, short, char far *,
    unsigned short, unsigned short far *);

extern API_FUNCTION
NetCharDevQSetInfo(char far *, char far *, short, char far *, unsigned short,
    short);

extern API_FUNCTION
NetCharDevQPurge (char far *, char far *);

extern API_FUNCTION
NetCharDevQPurgeSelf (char far *, char far *, char far *);



/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/


struct chardev_info_0
{
    char	   ch0_dev[DEVLEN+1];  /*	   device name		  */
};

struct chardev_info_1
{
    char	   ch1_dev[DEVLEN+1]; /* device name			    */
    char	   ch1_pad1;	      /* pad to an word boundary	    */
    unsigned short ch1_status;        /* status                             */
				      /*   bit 0 reserved		    */
                                      /*   bit 1 on = opened                */
				      /*   bit 1 off = idle		    */
				      /*   bit 2 on = error		    */
				      /*   bit 2 off = no error 	    */
    char	   ch1_username[UNLEN+1]; /* name of device's current user  */
    char	   ch1_pad2;	      /* pad to an word boundary	    */
    unsigned long  ch1_time;          /* time current user attached         */
};


struct chardevQ_info_0
{
    char	   cq0_dev[NNLEN+1];   /* queue name (network name)	    */
};

struct chardevQ_info_1
{
    char	   cq1_dev[NNLEN+1];   /* queue name (network name)	    */
    char	   cq1_pad;	       /* pad to a word boundary 	    */
    unsigned short cq1_priority;       /* priority (1 - 9)		    */
    char far *     cq1_devs;           /* names of devices assigned to queue */
    unsigned short cq1_numusers;       /* # of users waiting in queue        */
    unsigned short cq1_numahead;       /* # of users in queue ahead of this  */
                                       /*     user. -1 is returned if the    */
                                       /*     user is not in the queue.      */
};



/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/

/*
 *	Bits for chardev_info_1 field ch1_status.
 */

#define CHARDEV_STAT_OPENED		0x02
#define CHARDEV_STAT_ERROR		0x04

/*
 *	Opcodes for NetCharDevControl
 */

#define CHARDEV_CLOSE			0

/*
 *	Values for parmnum parameter to NetCharDevQSetInfo.
 */

#define CHARDEVQ_PRIORITY_PARMNUM	2
#define CHARDEVQ_DEVICES_PARMNUM	3


/*
 *	Minimum, maximum, and reccommended default for priority.
 */

#define CHARDEVQ_MAX_PRIORITY		1
#define CHARDEVQ_MIN_PRIORITY		9
#define CHARDEVQ_DEF_PRIORITY		5


