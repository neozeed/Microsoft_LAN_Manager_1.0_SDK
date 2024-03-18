/********************************************************************/
/**                   Microsoft OS/2 LAN Manager                   **/
/**            Copyright(c) Microsoft Corp., 1987, 1988            **/
/********************************************************************/

/********************************************************************
 *								    *
 *  About this file ...  ACCESS.H				    *
 *								    *
 *  This file contains information about the NetUser, NetGroup, and *
 *  NetAccess APIs.  There is a section for each set of APIs.  Each *
 *  section contains:						    *
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
 *	  	Function prototypes - USER			*
 *								*
 ****************************************************************/


extern API_FUNCTION 
  NetUserEnum( char far *, short, char far *, unsigned short,
		 unsigned short far *, unsigned short far *);

extern API_FUNCTION 
  NetUserAdd(char far *, short, char far *, unsigned short);

extern API_FUNCTION 
  NetUserDel( char far *, char far *);

extern API_FUNCTION 
  NetUserGetInfo( char far *, char far *, short, char far *, unsigned short,
	unsigned short far *);

extern API_FUNCTION 
  NetUserSetInfo( char far *, char far *,short, char far *, unsigned short,
		  short);

extern API_FUNCTION 
  NetUserPasswordSet( char far *, char far *, char far *, char far *);

extern API_FUNCTION
  NetUserValidate(char far *, char far *, char far *, unsigned short far *);

extern API_FUNCTION 
  NetUserGetGroups( char far *, char far *, short, char far *, 
		 unsigned short , unsigned short far *, unsigned short far *);


/**************************************************************** 
 *								*
 *	  	Data structure templates - USER			*
 *								*
 ****************************************************************/


struct user_info_0 {
    char usri0_name[UNLEN+1];
};

struct user_info_1 {
    char usri1_name[UNLEN+1];
    char usri1_pad_1;
    char usri1_password[ENCRYPTED_PWLEN];	/* See note below */
    long usri1_password_age;
    unsigned short usri1_priv;			/* See values below */
    char far *usri1_home_dir;
    char far *usri1_comment;
    unsigned short usri1_flags;			/* See values below */
    char far *usri1_script_path;
};

/*
 *	NOTE:  The maximum length of a user password is PWLEN.  The
 *	field usri1_password contains extra room for transporting
 *	the encrypted form of the password over the network.  When
 *	setting the user's password, check length vs. PWLEN, not
 *	the size of this field.  PWLEN is defined in NETCONS.H.
 */


/**************************************************************** 
 *								*
 *	  	Special values and constants - USER		*
 *								*
 ****************************************************************/


/*  
 *	Bit masks for field usri1_flags of user_info_1.
 */

#define	UF_SCRIPT		1
#define UF_ACCOUNTDISABLE	2

/*
 *	Values for parmnum for NetUseSetInfo.
 */

#define U1_ALL			0
#define U1_NAME			1
#define U1_PAD			2
#define U1_PASSWD		3
#define U1_PASSWDAGE		4
#define U1_PRIV			5
#define U1_DIR			6
#define U1_COMMENT		7
#define U1_USER_FLAGS		8
#define U1_SCRIPT_PATH		9

/*
 *	Privledge levels (user_info_1 field usri1_priv).
 */
#define USER_PRIV_GUEST		0
#define USER_PRIV_USER		1
#define USER_PRIV_ADMIN		2


/**************************************************************** 
 *								*
 *	  	Function prototypes - GROUP			*
 *								*
 ****************************************************************/


extern API_FUNCTION 
  NetGroupEnum( char far *, short, char far *, unsigned short,
		 unsigned short far *, unsigned short far *);

extern API_FUNCTION 
  NetGroupAdd( char far *, short,char far *, unsigned short);

extern API_FUNCTION 
  NetGroupDel( char far *, char far *);

extern API_FUNCTION 
  NetGroupAddUser( char far *, char far *, char far *);

extern API_FUNCTION 
  NetGroupDelUser( char far *, char far *, char far *);

extern API_FUNCTION 
  NetGroupGetUsers( char far *, char far *,short, char far *, 
		 unsigned short, unsigned short far *, unsigned short far *);



/**************************************************************** 
 *								*
 *	  	Data structure templates - GROUP		*
 *								*
 ****************************************************************/


struct group_info_0 {
    char grpi0_name[GNLEN+1];
};


struct group_users_info_0 {
    char grui0_name[UNLEN+1];
};


/**************************************************************** 
 *								*
 *	  	Special values and constants - GROUP		*
 *								*
 ****************************************************************/

/*
 * 	Predefined group names
 */

#define USERSGROUP		"USERS"
#define GUESTGROUP		"GUESTS"



/**************************************************************** 
 *								*
 *	  	Function prototypes - ACCESS			*
 *								*
 ****************************************************************/


extern API_FUNCTION
  NetAccessEnum ( char far *,char far *, short,short, char far *,
	unsigned short, unsigned short far *, unsigned short far * );

extern API_FUNCTION
  NetAccessGetInfo ( char far *, char far *, short, char far *, unsigned short,
			 unsigned short far * );


extern API_FUNCTION
  NetAccessSetInfo ( char far *, char far *,short,char far *,unsigned short,
		short );

extern API_FUNCTION
  NetAccessAdd ( char far *, short, char far *, unsigned short);

extern API_FUNCTION
  NetAccessDel ( char far *, char far * );

extern API_FUNCTION
  NetAccessCheck(char far *, char far *, char far *, unsigned short,
		unsigned short far *);


/**************************************************************** 
 *								*
 *	  	Data structure templates - ACCESS		*
 *								*
 ****************************************************************/

struct access_list {
    char   acl_ugname[UNLEN+1];
    char   acl_ugname_pad_1;
    short  acl_access;
};

struct access_info_0 {
    char far * acc0_resource_name;
};

struct access_info_1 {
    char  far * acc1_resource_name;
    short acc1_attr; 		  	/* See values below */
    short acc1_count;
};

/**************************************************************** 
 *								*
 *	  	Special values and constants - ACCESS		*
 *								*
 ****************************************************************/

/*
 *	Maximum number of permission entries for each resource.
 */

#define MAXPERMENTRIES  64


/*
 *	Bit values for the access permissions.  ACCESS_ALL is a handy
 *	way to specify maximum permissions.  These are used in
 *	acl_access field of access_list structures.
 */

#define ACCESS_ALL     (ACCESS_READ|ACCESS_WRITE|ACCESS_CREATE|ACCESS_EXEC|ACCESS_DELETE|ACCESS_ATRIB|ACCESS_PERM)

#define ACCESS_READ   0x1
#define ACCESS_WRITE  0x2
#define ACCESS_CREATE 0x4
#define ACCESS_EXEC   0x8
#define ACCESS_DELETE 0x10
#define ACCESS_ATRIB  0x20
#define ACCESS_PERM   0x40
#define ACCESS_FINDFIRST 0x80

#define ACCESS_GROUP  0x8000

/*
 *	Bit values for access_info_1 acf1_attr field.  Only one
 *	bit is currently defined.
 */

#define ACCESS_AUDIT	0x1

/*
 *	Parmnum value for NetAccessSetInfo.
 */

#define ACCESS_ATTR_PARMNUM 	2


/*
 *	ACCESS_LETTERS defines a letter for each bit position in
 *	the acl_access field of struct access_list.  Note that some
 *	bits have a corresponding letter of ' ' (space).
 */

#define ACCESS_LETTERS "RWCXDAP         " 
