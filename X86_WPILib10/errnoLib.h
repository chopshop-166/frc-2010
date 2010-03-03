/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: errnoLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_ERRNOLIB_H
#define _X86_ERRNOLIB_H

extern int      errnoGet (void);
extern void    printErrno (int errNo);

/* Error Status codes */
#define M_objLib             					0x003D0000 // (61 << 16)	
#define S_objLib_OBJ_ID_ERROR                   0x003D0001 //(M_objLib _WRS_BIT_OR 1)
#define S_objLib_OBJ_UNAVAILABLE                0x003D0002 //(M_objLib _WRS_BIT_OR 2)
#define S_objLib_OBJ_DELETED                    0x003D0004 //(M_objLib _WRS_BIT_OR 3)
#define S_objLib_OBJ_TIMEOUT                    0x003D0008 //(M_objLib _WRS_BIT_OR 4)
#define S_objLib_OBJ_NO_METHOD                  0x003D0010 //(M_objLib _WRS_BIT_OR 5)
#define S_objLib_OBJ_NO_ACCESS_RIGHTS           0x003D0020 //(M_objLib _WRS_BIT_OR 6)
#define S_objLib_OBJ_NAME_TRUNCATED             0x003D0040 //(M_objLib _WRS_BIT_OR 7)
#define S_objLib_OBJ_NAME_CLASH                 0x003D0080 //(M_objLib _WRS_BIT_OR 8)
#define S_objLib_OBJ_NOT_NAMED                  0x003D0100 //(M_objLib _WRS_BIT_OR 9)
#define S_objLib_OBJ_ILLEGAL_CLASS_TYPE         0x003D0200 //(M_objLib _WRS_BIT_OR 10)
#define S_objLib_OBJ_OPERATION_UNSUPPORTED      0x003D0400 //(M_objLib _WRS_BIT_OR 11)
#define S_objLib_OBJ_INVALID_OWNER              0x003D0800 //(M_objLib _WRS_BIT_OR 12)
#define S_objLib_OBJ_RENAME_NOT_ALLOWED         0x003D1000 //(M_objLib _WRS_BIT_OR 13)
#define S_objLib_OBJ_DESTROY_ERROR              0x003D2000 //(M_objLib _WRS_BIT_OR 14)
#define S_objLib_OBJ_HANDLE_TBL_FULL            0x003D4000 //(M_objLib _WRS_BIT_OR 15)
#define S_objLib_OBJ_NOT_FOUND                  0x003D8000 //(M_objLib _WRS_BIT_OR 16)
#define S_objLib_OBJ_INVALID_ARGUMENT           0x003D0000 //(M_objLib _WRS_BIT_OR 17)
#define S_objLib_OBJ_LIB_NOT_INITIALIZED        0x003F0000 //(M_objLib _WRS_BIT_OR 18)

#define M_taskLib            					0x00030000 //(3 << 16)
#define S_taskLib_NAME_NOT_FOUND				0x00030101 //(M_taskLib | 101)
#define S_taskLib_TASK_HOOK_TABLE_FULL			0x00030102 //(M_taskLib | 102)
#define S_taskLib_TASK_HOOK_NOT_FOUND			0x00030103 //(M_taskLib | 103)
#define S_taskLib_TASK_SWAP_HOOK_REFERENCED		0x00030104 //(M_taskLib | 104)
#define S_taskLib_TASK_SWAP_HOOK_SET			0x00030105 //(M_taskLib | 105)
#define S_taskLib_TASK_SWAP_HOOK_CLEAR			0x00030106 //(M_taskLib | 106)
#define S_taskLib_TASK_VAR_NOT_FOUND			0x00030107 //(M_taskLib | 107)
#define S_taskLib_TASK_UNDELAYED				0x00030108 //(M_taskLib | 108)
#define S_taskLib_ILLEGAL_PRIORITY				0x00030109 //(M_taskLib | 109)
#define S_taskLib_ILLEGAL_OPTIONS				0x00030110 //(M_taskLib | 110)
#define S_taskLib_NO_TCB						0x00030111 //(M_taskLib | 111)
#define S_taskLib_ILLEGAL_OPERATION				0x00030112 //(M_taskLib | 112)

#define M_memLib             					0x00110000 //(17 << 16)
#define S_memLib_NOT_ENOUGH_MEMORY             	0x00110001 //(M_memLib | 1)

#endif //_X86_ERRNOLIB_H
