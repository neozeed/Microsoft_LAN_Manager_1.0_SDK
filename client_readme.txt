
           Release Notes for Microsoft LAN Manager
                        SDK - 5/5/88



PRESENTATION MANAGER AND LAN MANAGER

	This version of Lan Manager is supported on OS/2 1.1 SDK kernel, it 
will also run on the last OS/2 1.0 SDK release (SDK 1.02) and on released 
OS/2 1.0 product (such as IBM OS/2 1.0, Compaq OS/2 1.0, etc.).  Presentation 
Manager and Lan Manager interaction has not been fully tested.  

	NOTE: It is recommended that if you are going to be using Lan Manager 
in a production or development environment you run OS/2 without the 
Presentation Manager shell. 

	Follow these steps to remove the Presentation Manager Shell. Your
system will then be setup to run the standard command line shell cmd.exe
(the normal OS/2 1.0 shell):

	1) Edit your config.sys

	2) In the standard config.sys as installed by the OS/2 installer
	   there are the following two lines:

rem protshell=c:\os2\pbin\shell.exe c:\os2\pbin\cmd.exe /k c:\os2init.cmd
protshell=c:\os2\pmshell.exe c:\os2\pbin\cmd.exe /k c:\os2init.cmd

	   Change the lines to the following:

protshell=c:\os2\pbin\shell.exe c:\os2\pbin\cmd.exe /k c:\os2init.cmd
rem protshell=c:\os2\pmshell.exe c:\os2\pbin\cmd.exe /k c:\os2init.cmd


NOTE: If you run Lan Manager in the Presentation Manager shell, be sure to 
install the Lan Manager Screen (full screen interface) as a Nonpresentation 
Manager application (don't install it as a VIO or Presentation Manager aware 
application).  This will result in the full screen interface running in
a separate screen group.  Future versions of the Lan Manager Screen will
be able to be installed as a VIO application and run in a window in the
Presentation Manager desktop.


AFTER INSTALLING OS/2

	If you already have OS/2 operating on your system or have just
installed it on a new system, be sure to do the following:

	1) Remove the line:
		run=<path>spool.exe
	   to disable the OS/2 spooler.  Lan Manager has its own spooler.

	   NOTE: OS/2 1.0 will include the above line in your config.sys,
	   the OS/2 1.1 installer will not.
	   

	2) Be sure that your config.sys line for the memory manager is as 
	   follows:
		MEMMAN=SWAP,MOVE (i.e. don't have swapping or moving disabled)


EXISTING MSDOS NETWORKING USERS

	If you are upgrading all of your systems to run OS/2, you should
install OS/2 on your machines, reboot and then install Lan Manager.  This 
release of Lan Manager contains OS/2 Netbios drivers for the following 
network cards:
	3com Tokenlink Plus
	3com Etherlink Plus
	Ungermann-Bass Personal-NIU UB128 (8-bit card)
	Ungermann-Bass NIU-PC UB256 (16-bit card)
	Standard Microsystems Corp (SMC) Arcnet
	IBM PC Network Adapter (Sytek broadband)
	Corvus Omninet IV

You must have one of the above cards to be able to run Lan Manager and
OS/2 at this time.  In addition, there is a loopback driver included that
will allow you to run Lan Manager on a standalone system without networking 
hardware installed.

	If you are going to configure your network to contain a mix of MSDOS 
and OS/2 systems you need to do the following:

	1) Be sure you have one of the above networking cards installed
	   in the OS/2 systems. You must have the same hardware installed
	   in your DOS machines (NOTE: If you have a 3com based network
	   installed, the DOS machine may have any variety of 3com cards 
	   described in section 3, the OS/2 machines must have the 3com 
	   Etherlink + for ethernet networks or 3com tokenlink + for 
	   Tokenring networks).

	2) If you are running the IBM PC Lan Program on your DOS machines
	   (using the PC Network adapter listed above), you can immediately 
	   begin using OS/2 and Lan Manager to communicate between the DOS 
	   and OS/2 machines.  No additional hardware or software is required.

	3) If you are running 3com's 3plus network on your DOS systems, 
	   these systems should also be able to communicate to the Lan Manager 
	   OS/2 systems. All 3Com adaptor cards (Etherlink, Etherlink II, 
	   Etherlink/MC, Etherlink Plus, Tokenlink, Tokenlink Plus, and 
	   IBM Token Ring (1,2 and A)) are supported as a DOS client talking 
	   to an Lan Manager Server.  If you are having problems or need
	   to the get the DOS drivers to install on your DOS machines contact 
	   3Com at:

    		1-800 NET-3COM ext 505.

    	   Diskettes and installation procedures will be sent from 3com to
	   you.  Lan Manager problems in general should be routed through
	   Microsoft DIAL.

	4) If you are running Ungermann/Bass Net One on your DOS machines,
	   installing Lan Manager should be the only steps required to allow
	   the DOS machines to communicate to the OS/2 Lan Manager systems.

	   Included on the DOS Lanman Distribution disk is a version of UB
	   Net One DOS networking software (in the sub-directory UBNET).  If 
	   there are problems, contact Ungermann/Bass product support or use 
	   Microsoft Dial.  Contact Ungermann/Bass at:

			408-496-0111
	
	   Note: The UB NIU-PC (16 bit), Personal-NIU (8-bit), NIC-PC, and
	   NIC-PS/2 cards interoperate under the NET-BNS-PC Ungermann/Bass 
	   software package.
	   

	5) If you have one of the above cards (3com or Ungermann/Bass) and 
	   are not running the card manufacturers DOS (MSNET based) networking 
	   product (3com 3plus or UB Net One) but are running another 
	   networking product (such as Novell Netware), please contact the 
	   appropriate hardware vendor listed above in points #3 or #4.
	   They will supply you with the appropriate DOS netbios drivers 
	   to operate with OS/2 and Lan Manager.  In addition, you should 
	   install the DOS Lan Manager product on your DOS machines as 
	   described in the release notes (read.me file) on the DOS Lan 
	   Manager Disk.

	6) If you are using SMC Arcnet or Corvus Omninet IV networking cards,
	   there are Netbios drivers supplied on the Lan Manager Drivers 
	   disk (called \LANMAN\DRIVERS\SMCARC.SYS for the SMC cards and
	   \LANMAN\DRIVERS\OMNINET4.SYS for the Corvus cards.  The drivers 
	   must installed on your DOS machines.  These drivers are 
	   automatically installed on the OS/2 machines by the Lan Manager 
	   installer.  If there are problems, please contact Microsoft DIAL.

	7) Feel free to contact Microsoft using DIAL with any other
	   question you may have concerning Lan Manager.


HARDWARE HINTS

	Please see the file HARDWARE.TXT on the Workstation Distribution
Disk #1 for hints in installing the above networking cards.  If there are
additional questions, consult the manufacturers documentation or call
the Product Support divisions of the hardware manufacturer.


APPLICATION DEVELOPERS

	Included in the Lan Manager tree is a directory called:

		\LANMAN\NETSRC

which will be installed on your machine by the Lan Manager installer.
There are two sub-directories (H and LIB) that include C header files
and libraries you can use to develop applications to the Lan Manager API.
The API is described in the Microsoft Lan Manager API document (included 
in hardcopy form in the SDK package and also machine readable form on the 
Lan Manager Workstation Distribution Disk #1 as the file summary.api).
The Lan Manager API follow the conventions of the OS/2 API; therefore,
if you are familiar with the OS/2 API, programming to the Lan Manager API
will be straight forward.


SERVER PERFORMANCE 

	Although good, performance of the Lan Manager Server is not 
representative of the performance of the final released product due to 
this version of the server not having a disk cache.

	Setting a large value for DISKCACHE= in your config.sys will not
significantly improve the performance of the server.  The disk cache
logic included in this release is the standard OS/2 version, which is
optimized for single-user workstation applications but has little
benefit for the network server.  An optimized server disk cache will be
provided in a future release. 



RELEASE NOTES

Note: Running the server requires a minimum of 3mb of memory for good
      operation (this allows for a full 640K compatibility box); the current
      version of the install program will allow you to install the server
      software on a 2mb system however.  Running the workstation only 
      requires 2mb.

1. There are several documents supplied with this release on the OS/2
   workstation diskette #1:

        READ.ME         This file
        SUMMARY.API     This is documentation for the LAN
                        Manager API. This is the most
                        up to date information, and is to
                        be used where discrepancies exist
                        with the programmer's guides.
        SPECUPDT.TXT    This is an update to the LAN Manager
                        specification. It contains all new
                        features added since the document
                        dated Oct. 14.
        HARDWARE.TXT    Some notes on getting LAN Manager to
                        run with some common hardware.
        NETDRIVE.TXT    Specifications for writing a
                        NETBIOS driver for LAN Manager.


    NOTE: Included on the DOS 3 Lanman distribution disk #1 is a file:
          READ.ME that describes the new features of the DOS workstation
          software and installation instructions for installing it.

2.  Please use the NETSETUP program to install. Put either the 
    Workstation Distribution Disk #1 or Server Distribution Disk #1
    in A: and enter: A:NETSETUP.  If you are installing Lan Manager
    for the first time, you can just use the defaults provided
    by the installer (defaults are provided for buffer sizes, etc.).  
    BE  SURE TO SELECT THE CORRECT NETWORK CARD YOU HAVE INSTALLED IN YOUR 
    SYSTEM WHEN PROMPTED BY THE INSTALLER. By default the installer will
    select the loopback driver.  Also, be sure to enter a unique 
    computername/username when asked for it by the installer.

3.  If you have previously used a release of the LAN Manager it is
    necessary to clean up your CONFIG.SYS file before installing the new
    version of Lan Manager.  To do this use the installer (NETSETUP),
    by selecting the main menu item for uninstalling Lan Manager.

4.  If NETAPI.DLL is accessible from the LIBPATH, when running the
    NETSETUP installation program, many problems can occur. Please make
    sure that there are no old copies of NETAPI.DLL accessible before
    running the installation. This problem only occurs if you have a
    previous release of LAN Manager installed on your machine.

5.  If you use NETSETUP to install one of the UB drivers, the line
    which is inserted in CONFIG.SYS will contain hard-coded references to
    C:\LANMAN.  The user will not notice any problems if the LANMAN tree is
    put in C:\, but if the user puts it anywhere else he/she will have to
    modify the DEVICE line for UBXNS.SYS in CONFIG.SYS to fix these
    references.

6.  Occasionally there are some difficulties in getting OS/2 and some
    network cards configured correctly because of the interrupt structure.
    In particular, the SYTEK card at present only works on IRQ3, even
    though the hardware itself supports 2 or 3.
    Please see the file HARDWARE.TXT for hardware installation hints.

7.  Although this release of LAN Manager is functionally complete,
    there are some known bugs that have yet to be fixed. Here is a list of
    known problems that are considered "severe":

    a) If there are more than 1000 entries in a list box under
       the Lan Manager Screen, scrolling the list box will GP
       fault the Screen.

    b) If you use the NET, NET ADMIN,  NET START WORKSTATION commands to
       start the workstation and your computer name is a duplicate
       name of a computer already on the network, you will see
       the following error:

                OS/2 ERROR 52: There is a duplicate filename on the network

       Filename should read computername.

       NOTE: The LANGROUP parameter in your lanman.ini cannot be the same
       as a computername or username on the net work.

    c) Starting the server with the following command:

		Net Start Server /maxusers:100

       will hang the server at startup time. The limit should be less than
       80.

8.  This release has been tested with OS/2 versions 1.0 and 1.1.
    It has not been well tested running with Presentation Manager.

9.  This version implements a performance enhancement called
    "opportunistic locking". When enabled, this allows single instances of
    file opens to be done as if the open had been in DENY ALL mode. This
    allows the workstation and server to do much more ambitious read ahead
    and write behind optimizations. If a second open occurs, the server
    will signal the workstation to flush its buffers and stop using that
    mode.

    NOTE: If you are using the server as a workstation also, you should
    install the loopback as net2 and perform all local access via a
    redirected drive back to the servers shares.  Alternatively, the 
    locking can be disabled by setting the lanman.ini file parameter:

	From:
  		srvheuristics = 1111110111111
	To:
  		srvheuristics = 0111110111111

    This must be disabled if you are going to access files using local
    drives on the server (i.e. C:), as the server will not know the local 
    drives are being accessed by the local user and data may be lost if 
    the user is accessing the same file as a remote workstation.

10. The FASTOPEN.SYS driver will not work with OS/2 1.0 because of
    problems in the OS. These have been fixed in 1.1. The LAN Manager
    installer will not include the

         device=c:\lanman\drivers\fastopen.sys 32

    line in the CONFIG.SYS file. If you are running with OS/2 1.1, and want
    the performance advantage of the directory path cache driver, then the
    appropriate line can be added to your CONFIG.SYS.

11. If you are configuring a user-level-security server, after running
    the installer you must run a program that creates the user data base
    (MAKEACC). The syntax for running MAKEACC is:

             MAKEACC <number of users> <Lan Manager root>

    Number of users is can be any number >= 10 and <=1024. Example: 

	MAKEACC 100 C:\LANMAN 

    will create an user accounts file that will hold a maximum of 100 users.  
    MAKEACC will also prompt you for the password of the ADMIN user for the 
    server.  It will create the account with the username of ADMIN and the 
    password you supply (passwords are limited to 14 characters).

    In addition, there is another command that allows your to grow the
    accounts database.  The command is called GROWACC and the syntax is:

	GROWACC <new number of users>

    Number of users is can be any number >= 10 and <=1024. Example: 

	GROWACC 200

    GROWACC must be ran with the netwksta.sys driver loaded.

    NOTE: For performance reasons: Number of users should be a prime number
	  multiplied by 2.  This will speed up the hashing used to store
	  the usernames in the database.

12. There are a number of memory management bugs in OS/2 1.0 involving
    long term locks (which are needed by the server). We have tried to work
    around them in the LAN Manager, but some software/hardware
    combinations may fail to install the server with the message, "Out of
    resource, memory". If you should encounter this problem this you can:

        - add more memory
        - shrink 3X box size
        - disable 3X box
        - turn off swapping and motion
        - move onto OS/2 1.1


13. The documentation supplied with the Lan Manager SDK package is a little
    out of date with the product.  Please consult the file SPECUPDT.TXT
    on the Lan Manager Workstation Distribution Disk #1 for differences
    of where the product differs from the documentation.  The next SDK
    release of Lan Manager will include updated documentation.

14. Setting "numbigbuf=0" in your lanman.ini file will disable the ability 
    to execute remote apis against the server.

