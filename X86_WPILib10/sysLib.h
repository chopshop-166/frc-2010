/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: sysLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_SYSLIB_H
#define _X86_SYSLIB_H

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
extern int       clock_gettime (clockid_t clock_id, struct timespec *tp);



#endif //_X86_SYSLIB_H

