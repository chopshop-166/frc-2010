/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: semLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_SEMLIB_H
#define _X86_SEMLIB_H

#include "VxWorks.h"

#define WAIT_FOREVER    (-1)

#define SEM_Q_FIFO		 0x00	/* first in first out queue */
#define SEM_Q_PRIORITY		 0x01	/* priority sorted queue */
#define SEM_DELETE_SAFE		 0x04	/* owner delete safe (mutex opt.) */
#define SEM_INVERSION_SAFE	 0x08	/* no priority inversion (mutex opt.) */
#define SEM_EVENTSEND_ERR_NOTIFY 0x10	/* notify when eventRsrcSend fails */
#define SEM_INTERRUPTIBLE        0x20   /* interruptible on RTP signal */


/* binary semaphore initial state */

typedef bool SEM_B_STATE;
#ifndef SEM_EMPTY
#define SEM_EMPTY 0
#define SEM_FULL 1
#endif

extern SEM_ID 	  semMCreate 	(int options);
extern SEM_ID 	  semBCreate 	(int options, SEM_B_STATE initialState);
extern SEM_ID 	  semCCreate 	(int options, int initialCount);
extern STATUS 	  semDelete 	(SEM_ID semId);
extern STATUS 	  semFlush 	(SEM_ID semId);
extern STATUS 	  semGive 	(SEM_ID semId);
extern STATUS 	  semTake 	(SEM_ID semId, int timeout);
//extern SEM_ID	  semOpen	(const char * name, SEM_TYPE type, 
//				 int initState, int options, int mode,
// 				 void * context);
//extern STATUS	  semInfoGet	(SEM_ID semId, SEM_INFO *pInfo);
extern STATUS 	  semClose	(SEM_ID semId);
extern STATUS 	  semUnlink	(const char * name);

extern int     sysClkRateGet ();

#define CLOCK_REALTIME			0x0 /* system wide realtime clock */

 
 
#if !defined(_DEFINED_timer_t) && !defined(_TIMER_T)
#define _DEFINED_timer_t
#define _TIMER_T
struct __timer;
typedef struct __timer *timer_t;
#endif /* !defined(_DEFINED_timer_t) */
 
//#ifndef _TIME_T
//#define _TIME_T
//typedef unsigned long time_t;
//#endif  /* _TIME_T */
//typedef long int time_t;
typedef unsigned long clockid_t;

 
 
#ifndef _DEFINED_struct_timespec
#define _DEFINED_struct_timespec
struct timespec
    {
    long tv_sec; //time_t tv_sec;
    long tv_nsec;
    };
#endif /* _DEFINED_struct_timespec */
extern int 	timer_gettime (timer_t timerid, struct itimerspec *value);
extern int  clock_gettime (clockid_t clock_id, struct timespec *tp);

extern int      nanosleep (const struct timespec *rqtp, struct timespec *rmtp);



#endif //_X86_SEMLIB_H

