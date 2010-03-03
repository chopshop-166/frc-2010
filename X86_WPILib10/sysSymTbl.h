/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: sysSymTbl.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_SYSSYMTBL_H
#define _X86_SYSSYMTBL_H

#include "strLib.h"
typedef unsigned char SYM_TYPE;
#define MAX_SYS_SYM_LEN 256	/* system symbols will not exceed this limit */

/* Type definitions */

typedef struct symtab * SYMTAB_ID;
extern SYMTAB_ID 	sysSymTbl;	/* system symbol table */
extern STATUS	symByValueFind (SYMTAB_ID symTblId, UINT value, char ** pName, 
				int * pValue, SYM_TYPE * pType);
extern STATUS	symFindByValue(SYMTAB_ID symTblId, UINT value, char * name, 
			       int * pValue, SYM_TYPE * pType);

//typedef struct {char data[32];} REG_SET;

#endif //_X86_SYSSYMTBL_H
