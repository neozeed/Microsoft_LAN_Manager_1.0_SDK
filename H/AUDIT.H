/********************************************************************/
/**                   Microsoft OS/2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/



/********************************************************************
 *								    *
 *  About this file ...  AUDIT.H				    *
 *								    *
 *  This file contains information about the NetAudit APIs.	    *
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
  NetAuditWrite ( unsigned short, const char far *, unsigned short, 
			char far *, char far * );

extern API_FUNCTION 
  NetAuditOpen ( const char far *, unsigned far *, char far *);

extern API_FUNCTION
  NetAuditClear ( const char far *, const char far *, char far *);


/**************************************************************** 
 *								*
 *	  	Data structure templates			*
 *								*
 ****************************************************************/

/*
 *	General audit_entry information.  For each type of entry,
 *	there may be additional information.  This is found at an
 *	offset of "ae_data_offset" from the start of the audit_entry
 *	structure.
 *
 *	Note that at the very end of each record is a word (unsigned
 *	short) which is the length of the record, the same value as
 *	found in ae_len.  This length includes the whole record, including
 *	the trailing length word.  This allows scanning backward.
 */

struct audit_entry {
	unsigned short      ae_len;         /* length of record */
 	unsigned short	    ae_reserved;
        unsigned long       ae_time;        /* time of entry    */
        unsigned short      ae_type;        /* type of entry    */
        unsigned short      ae_data_offset; /* offset to ae_data */
    };

/*
 *	The following structures represent the layout of the data area
 *	of specific audit entry types.  This is the information found
 *	at an offset of "ae_data_offset" from the start of the record.
 *	This will usually be immediately following the audit_entry,
 *	structure, but DO NOT ASSUME THIS, use the ae_data_offset value.
 *
 *	Some of these fields are offsets of the start of a text string.
 *	The offset is from the start of the data area (i.e. the position
 *	identified by ae_data_offset), NOT from the start of the whole
 *	entry.  This data will appear as ASCIZ strings, usually in the
 *	area following the defined structure.
 */

					/* Server status record */
struct ae_srvstatus {
    unsigned short    ae_ss_status;	/* AE_SRVSTART, AE_SRVPAUSED, */
					/*  AE_SRVCONT, AE_SRVSTOP    */
};

struct ae_sesslogon {
    unsigned short    ae_so_compname;	/* ptr to computername of client    */
    unsigned short    ae_so_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_so_privilege;	/* AE_GUEST, AE_USER, AE_ADMIN	    */
};
	
struct ae_sesslogoff {
    unsigned short    ae_sf_compname;	/* ptr to computername of client    */
    unsigned short    ae_sf_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_sf_reason;	/* AE_NORMAL, AE_ERROR, AE_AUTODIS, */
					/*  AE_ADMINDIS			    */
};

struct ae_sesspwerr {
    unsigned short    ae_sp_compname;	/* ptr to computername of client  */
    unsigned short    ae_sp_username;	/* ptr to username submitted by   */
					/*  client (NULL if same as 	  */
					/*  computername)		  */
};
	
struct ae_connstart {
    unsigned short    ae_ct_compname;	/* ptr to computername of client    */
    unsigned short    ae_ct_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_ct_netname;	/* ptr to netname of share	    */
    unsigned short    ae_ct_connid;	/* Unique connection id		    */
};

struct ae_connstop {
    unsigned short    ae_cp_compname;	/* ptr to computername of client    */
    unsigned short    ae_cp_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_cp_netname;	/* ptr to netname of share	    */
    unsigned short    ae_cp_connid;	/* Unique connection id		    */
    unsigned short    ae_cp_reason;	/* AE_NORMAL/AE_SESSDIS/AE_UNSHARE  */
};

struct ae_connrej {
    unsigned short    ae_cr_compname;	/* ptr to computername of client    */
    unsigned short    ae_cr_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_cr_netname;	/* ptr to netname of share	    */
    unsigned short    ae_cr_reason;	/* AE_USERLIMIT, AE_BADPW	    */
};

struct ae_resaccess {
    unsigned short    ae_ra_compname;	/* ptr to computername of client    */
    unsigned short    ae_ra_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_ra_resname;	/* ptr to resource name		    */
    unsigned short    ae_ra_operation;	/* Bitmask uses bits defined in     */
					/*  access.h			    */
    unsigned short    ae_ra_returncode;	/* return code from operation	    */
    unsigned short    ae_ra_restype;	/* type of resource record	    */
    unsigned short    ae_ra_fileid;	/* unique server id of file	    */
};

struct ae_resaccessrej {
    unsigned short    ae_rr_compname;	/* ptr to computername of client    */
    unsigned short    ae_rr_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_rr_resname;	/* ptr to resource name		    */
    unsigned short    ae_rr_operation;	/* Bitmask uses bits defined in     */
					/*  access.h			    */
};

struct ae_closefile {
    unsigned short    ae_cf_compname;	/* ptr to computername of client    */
    unsigned short    ae_cf_username;	/* ptr to username of client (NULL  */
					/*  if same as computername)	    */
    unsigned short    ae_cf_resname;	/* ptr to resource name		    */
    unsigned short    ae_cf_fileid;	/* unique id of file		    */
    unsigned long     ae_cf_duration;	/* length of use of file	    */
    unsigned short    ae_cf_reason;	/* How the file was closed	    */
					/* 0 = Normal Client Close	    */
					/* 1 = Session Disconnected	    */
					/* 2 = Administrative Close	    */
};


/**************************************************************** 
 *								*
 *	  	Special values and constants			*
 *								*
 ****************************************************************/


/*
 * 	Audit entry types (field ae_type in audit_entry).
 */

#define AE_SRVSTATUS	0
#define AE_SESSLOGON	1
#define AE_SESSLOGOFF	2
#define AE_SESSPWERR	3
#define AE_CONNSTART	4
#define AE_CONNSTOP	5
#define AE_CONNREJ	6
#define AE_RESACCESS	7
#define AE_RESACCESSREJ	8
#define	AE_CLOSEFILE	9

/* 
 *	Values for ae_ss_status field of ae_srvstatus.
 */

#define AE_SRVSTART	0
#define AE_SRVPAUSED	1
#define AE_SRVCONT	2
#define AE_SRVSTOP	3

/*
 * 	Values for ae_so_privilege field of ae_sesslogon.
 */

#define AE_GUEST	0		
#define AE_USER		1
#define AE_ADMIN	2

/* 
 *	Values for various ae_XX_reason fields.
 */

#define AE_NORMAL	0		
#define AE_USERLIMIT	0
#define AE_ERROR	1
#define AE_SESSDIS	1
#define AE_BADPW	1
#define AE_AUTODIS	2
#define AE_UNSHARE	2
#define AE_ADMINPRIVREQD 2
#define AE_ADMINDIS	3
#define AE_NOACCESSPERM 3

#define	AE_NORMAL_CLOSE	0
#define	AE_SES_CLOSE	1
#define	AE_ADMIN_CLOSE	2



