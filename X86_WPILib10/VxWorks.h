/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: VxWorks.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_VXWORKS_H
#define _X86_VXWORKS_H

typedef unsigned long long UINT64;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;

typedef unsigned int UINT;
typedef unsigned long INSTR;

typedef long long INT64;
typedef int INT32;
typedef short INT16;
typedef char INT8;

typedef bool BOOL;

typedef INT32 STATUS;
typedef void * SEM_ID;

typedef void *(*FUNCPTR)();

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE true
#endif

#ifndef SVN_REV
#define SVN_REV "Unknown"
#endif

#define ERROR           (-1)
#define OK				(0)


#endif //_X86_VXWORKS_H


