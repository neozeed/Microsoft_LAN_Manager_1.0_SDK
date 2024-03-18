/********************************************************************/
/**                   Microsoft OS/2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/

/********************************************************************
 *
 *  About this file ...  ALERTMSG.H
 *
 *  This file contains the number and text of alert messages.
 *
 *  Since it is included by ALERT.H, it is not usually necessary
 *  to include this file directly.  As a precaution against 
 *  including this file twice -- for example, by including it
 *  explicitly and also including ALERT.H -- the contents are
 *  inside an #ifdef that insures that the contents are only
 *  included once.
 *
 ********************************************************************/


#ifndef _ALERTMSG_H_

#define _ALERTMSG_H_


/*
 * 	ALERT_BASE is the base of alert log codes.
 */

#define ALERT_BASE	2450


#define ALERT_Disk_Full		(ALERT_BASE + 0)
	/*
	 *  Drive %1 is nearly full. %2 bytes available.
	 *  Recommend you warn users and delete unneeded files 
	 */


#define	ALERT_ErrorLog		(ALERT_BASE + 1)
	/*
	 *  %1 errors have been logged in the last %2 minutes.
	 *  Recommend you view the server's error log.
	 */


#define ALERT_NetIO		(ALERT_BASE + 2)
	/*
	 *  %1 network errors have occurred in the last %2 minutes
	 *  on network %3.  Recommend you view the server's error log.
	 *  The server and/or network hardware may need service.
	 */


#define ALERT_Logon		(ALERT_BASE + 3)
	/*
	 *  %1 bad password attempts in the last %2 minutes.
	 *  Recommend you view the server's audit trail.
	 */


#define ALERT_Access		(ALERT_BASE + 4)
	/*
	 *  %1 access denied errors in the last %2 minutes.
	 *  Recommend you view the server's audit trail.
	 */


#define ALERT_AutoDisc		(ALERT_BASE + 5)
	/*
	 * Your session to this server has been automatically disconnected
	 * due to inactivity.
	 */


#define	ALERT_ErrorLogFull	(ALERT_BASE + 6)
	/*
	 *  The error log is full.  No errors will be logged until
	 *  the file is cleared or the limit is raised.
	 */


#define	ALERT_ErrorLogFull_W	(ALERT_BASE + 7)
	/*
	 *  The error log is 80% full.  
	 */


#define	ALERT_AuditLogFull	(ALERT_BASE + 8)
	/*
	 *  The audit log is full.  No audits will be logged until
	 *  the file is cleared or the limit is raised.
	 */


#define	ALERT_AuditLogFull_W	(ALERT_BASE + 9)
	/*
	 *  The audit log is 80% full.  
	 */

#define ALERT_CloseBehindError	(ALERT_BASE + 10)
	/*
	 *  An error occurred closeing file %1. 
	 *  Recommend you check the file for integrity.
	 */

#define ALERT_AdminClose	(ALERT_BASE + 11)
	/*
	 * The administrator has closed %1.
	 */

#endif

