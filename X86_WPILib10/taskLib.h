/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: taskLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_TASKLIB_H
#define _X86_TASKLIB_H


#include "VxWorks.h"
#include <strings.h>

#define VX_FP_TASK 22

extern int	taskSpawn 	(char * name, int priority, int options, 
			   	 int stackSize, FUNCPTR entryPt, int arg1,  
			   	 int arg2, int arg3, int arg4, int arg5, 
			   	 int arg6, int arg7, int arg8, int arg9, 
				 int arg10);
//extern int	taskCreate 	(char * name, int priority, int options,
//			         int stackSize, FUNCPTR entryPt, int arg1,  
//			   	 int arg2, int arg3, int arg4, int arg5, 
//			   	 int arg6, int arg7, int arg8, int arg9, 
//				 int arg10);
//extern STATUS	taskActivate 	(int tid);
extern STATUS	taskDelete 	(int tid);
//extern STATUS	taskDeleteForce (int tid);
extern STATUS	taskSuspend 	(int tid);
extern STATUS	taskResume 	(int tid);
extern STATUS	taskRestart 	(int tid);
extern STATUS	taskPrioritySet (int tid, int newPriority);
extern STATUS	taskPriorityGet (int tid, int * pPriority);
//extern char *	taskName 	(int tid);
extern int	taskNameToId 	(char * name);
extern STATUS	taskIdVerify 	(int tid);
extern int	taskIdSelf 	(void);
//extern int	taskIdDefault 	(int tid);
extern BOOL	taskIsReady 	(int tid);
extern BOOL	taskIsSuspended (int tid);
//extern BOOL	taskIsPended	(int tid);
//extern STATUS	taskInfoGet 	(int tid, TASK_DESC * pTaskDesc);
//extern STATUS	taskOptionsGet 	(int tid, int * pOptions);
extern STATUS	taskDelay 	(int ticks);
//extern int	taskOpen 	(const char * name, int priority, int options, 
//			   	 int mode, char * pStackBase, int stackSize, 
//				 void * context, FUNCPTR entryPt, int arg1, 
//				 int arg2, int arg3, int arg4, int arg5, 
//				 int arg6, int arg7, int arg8, int arg9, 
//				 int arg10);
//extern STATUS 	taskClose	(int  tid);
//extern STATUS 	taskUnlink	(const char * name);
extern STATUS	taskSafe	(void);
extern STATUS	taskUnsafe	(void);

extern STATUS taskKill(int,int);

typedef struct {char data[32];} REG_SET;

//extern int      taskIdListGet   (int idList [ ], int maxTasks);
//extern STATUS   taskStatusString (int tid, char * pString);
//extern STATUS   taskOptionsString (int tid, char * pString);
extern STATUS   taskRegsGet     (int tid, REG_SET * pRegs);
//extern STATUS   taskRegsSet     (int tid, REG_SET * pRegs);
//extern void     taskRegsShow    (int tid);
//extern void *   taskStackAllot  (int tid, unsigned nBytes);
//extern void     taskShowInit    (void);
//extern STATUS   taskShow        (int tid, int level);
extern STATUS   taskLock        (void);
extern STATUS   taskUnlock      (void);

#endif //_X86_TASKLIB_H


