/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: X86_SimWPILib_Main.cpp
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Main module to create routines to simulate environment
*****************************************************************************/
/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

/****************************************************************************
**************** DETAILED EXPLANATION OF SIMULATION DESIGN ******************
*****************************************************************************
* Source Code Environment:
*	The code that is used with WindRiver must be placed in a specific places
*	because the project files use absolute references. We have chosen to use
*	the drive letter "W:" to allow anyone to use the code.
*
* 	Create a directory tree on the media that you want to use. For instance,
* 		C:\FIRST\Code\Sandbox1
* 	In a Command Box, use the following command to get the driver letter:
*		subst W: C:\FIRST\Code\Sandbox1
*   Then create the directory "workspace" on the "W:" driver. Populate it
*   with the directories needed (usually by downloading from source control).
* 	You should then see the following dirctory tree:
* 		W:\workspace\WPILib10
*		W:\workspace\X86_WPILib10
*
* 	Note that we use the tree with "10" appended for "2010".
* 
* 	You will need the Wind River Workbench now, and you should import the
*   projects from you source pool for all of "workspace".
* 
* Build Environment:
* 	You will need to install a native G++ compiler onto your system. We use
* 	the same GNU compiler, to maximize compatibility with the simulator and
* 	also prevent anyone from having to download or purchase Microsoft Visual
* 	Studio from Microsoft. The simulator should have complete compatibility
* 	both from a compiler and from an execution point of view.
* 
* 	If you have installed everything necessary for FIRST, you only have to
* 	install MinGW for Windows. (Find the latest version on the web. As of 
* 	this writing, I happened to be using V3.17, but any version later than
* 	that should also work.)
* 
* Basic Design/Philosophy:
* 	The idea of this simulator is to allow the existing WPILib to work and
* 	be used without being changed at all. Future variations of WPILib may
* 	work without change, but most likely will need addition calls and
* 	simulation.
* 
* 	Only the calls underneath WPILib are pulled out for simulation. These
* 	calls and constants are put in only AS NEEDED, and their definitions are
* 	generally found in the header files that are in VxWorks. 
* 
* 	At the simulator layer, each routine used in VxWorks and the register
* 	set of the hardware, must be simulated. As more hardware is used by a
* 	particular robot, addition simulation files can be added for each piece
* 	of hardware that is needed.
* 
* 	The simulator will run in one process on Windows, but will use Windows
* 	threads to simulate the various tasks. Hopefully the debug environment
* 	will be excellent using Wind River, but only time will tell.
* 
* Files of Note:
* 	Most of the files that are created in this project (that are only for
* 	this project and NOT shared) are header files. They exist because the
* 	code somewhere in WPILib uses these files. As of this writing, the
* 	following header files had to be created:
* 		dbgLib.h, errnoLib.h, fioLib.h, HostLib.h, inetLib.h,
* 		moduleLib.h, semLib.h, sigLib.h, sockLib.h, stdioLib.h
* 		strLib.h, sysLib.h, sysSymTbl.h, taskLib.h, unldLib.h,
* 		usrLib.h, VxWorks.h
* 
* 	Only the external routine definition, typedefs and constants that are
* 	needed are included in these tiny stub files.
* 
* Project Notes:
* 	Because the native GNU G++ compiler automatically defines certain macros
* 	by default, you must add the following "DEFINES" to the build to undefine
* 	these macros:
* 		-U__DEPRECATED -U__STRICT_ANSI__
* 
* 	If these are not added under the build macros, you will get many, errors
* 	when you try to use the native header files provided with MinGW.
* 
* 	To add files NOT in the same directory tree as the project, you must
* 	use the notion of a "shortcut" to another directory. This is how the
* 	entire WPILib10 directory tree is included in this project. (It means
* 	the original files are never touched.) You should use this technique
* 	to add more "X86_" projects for your specific robot code.
* 
*****************************************************************************/


//
//	Includes that will be needed for the simulation code
//
#include "VxWorks.h"
#include <stdio.h>
#include "WPILib.h"

#include "errnoLib.h"
#include "inetLib.h"
#include "moduleLib.h"
#include "sockLib.h"
#include "semLib.h"
#include "sysSymTbl.h"
#include "taskLib.h"

//
//	Below here, code that actually emulates the VxWorks routines will
//	be created. It probably will make sense to add files for emulation
//	of various pieces of hardware so they can be included if wanted.
//


int    accept (int s, struct sockaddr *addr, int *addrlen) {return 0;};
int  clock_gettime (clockid_t clock_id, struct timespec *tp) {return 0;};
STATUS close (int) {return 0;};
STATUS         connect (int s, struct sockaddr *name, int namelen) {return 0;};
//cplusDemangle'
int      errnoGet (void) {return 0;};
//FRC_NetworkCommunication_observeUserProgramStarting'
//getCommonControlData'
//getDynamicControlData'
//imaqGetLastError'
unsigned long   inet_addr (char *){return 0;};
//LedInput'
//LedOutput'
STATUS         listen (int s, int backlog){return 0;};
MODULE_ID    moduleFindByName (char * moduleName){return 0;};
//moduleNameFindBySymbolName'
int      nanosleep (const struct timespec *rqtp, struct timespec *rmtp){return 0;};
//overrideIOConfig'
//pcre_compile'
//pcre_exec'
void    printErrno (int errNo) {};
//Priv_ReadJPEGString_C'
//Priv_SetWriteFileAllowed'
int    recv (int s, char *buf, int bufLen, int flags){return 0;};
SEM_ID     semBCreate    (int options, SEM_B_STATE initialState){return 0;};
STATUS     semDelete     (SEM_ID semId){return 0;};
STATUS     semFlush      (SEM_ID semId){return 0;};
STATUS     semGive       (SEM_ID semId){return 0;};
SEM_ID     semMCreate    (int options){return 0;};
STATUS     semTake       (SEM_ID semId, int timeout){return 0;};
int    send (int s, const char *buf, int bufLen, int flags){return 0;};
//setErrorData'
//setStatusData'
int    socket (int domain, int type, int protocol);
 STATUS	symFindByValue(SYMTAB_ID symTblId, UINT value, char * name, 
			       int * pValue, SYM_TYPE * pType){return 0;};
int     sysClkRateGet (){return 0;};
SYMTAB_ID    sysSymTbl;
STATUS	taskDelete 	(int tid){return 0;};
int	taskIdSelf 	(void){return 0;};
STATUS	taskIdVerify 	(int tid){return 0;};
BOOL	taskIsReady 	(int tid){return 0;};
BOOL	taskIsSuspended (int tid){return 0;};
STATUS taskKill(int,int){return 0;};
STATUS   taskLock        (void){return 0;};
int	taskNameToId 	(char * name){return 0;};
STATUS	taskPriorityGet (int tid, int * pPriority){return 0;};
STATUS	taskPrioritySet (int tid, int newPriority){return 0;};
STATUS   taskRegsGet     (int tid, REG_SET * pRegs){return 0;};
STATUS	taskRestart 	(int tid){return 0;};
STATUS	taskResume 	(int tid){return 0;};
int	taskSpawn 	(char * name, int priority, int options, 
			   	 int stackSize, FUNCPTR entryPt, int arg1,  
			   	 int arg2, int arg3, int arg4, int arg5, 
			   	 int arg6, int arg7, int arg8, int arg9, 
				 int arg10){return 0;};
STATUS	taskSuspend 	(int tid){return 0;};
STATUS   taskUnlock      (void){return 0;};
STATUS taskDelay(int){return 0;};
STATUS	taskUnsafe	(void){return 0;};
//trcStack'
STATUS unldByModuleId(MODULE_ID moduleId, int options){return 0;};
//UserSwitchInput'
int    write (int, char *, size_t){return 0;};

