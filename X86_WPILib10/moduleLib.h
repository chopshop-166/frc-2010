/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: moduleLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_MODULELIB_H
#define _X86_MODULELIB_H



/*
 * Description:
 */
typedef struct module
    {
//    HANDLE	handle;		    /* handle management */

//    DL_NODE	moduleNode;	    /* double-linked list node information */

    /*
     * nameWithPath is now the preferred field to use for name and 
     * path. The separate name and path fields are kept for backward
     * compatibility, but they may not hold valid information, since
     * they are of limited size. 
     */

    char *	nameWithPath;	    /* module name and path */
//    char	name [NAME_MAX];    /* module name */
    char	path [PATH_MAX];    /* module path */
    int		flags;		    /* symFlags as passed to the loader */
//    DL_LIST	sectionList;	    /* list of section */
//    DL_LIST	segmentList;	    /* list of segments */
    int         format;		    /* object module format. Only ELF now */
    UINT16	group;		    /* group number */
//    VOIDFUNCPTR * ctors;	    /* list of static constructor callsets */
//    VOIDFUNCPTR * dtors;	    /* list of static destructor callsets */
//    UINT	commTotalSize;	    /* memory used by common symbols */
//    BOOL	swapNeeded;	    /* TRUE if the headers need byte swap */
    int		undefSymCount;	    /* number of undefined symbols */
    void *	user1;		    /* reserved for use by end-user */
    void *	reserved1;	    /* reserved for use by WRS */
    void *	reserved2;	    /* reserved for use by WRS */
    void *	reserved3;	    /* reserved for use by WRS */
    void *	reserved4;	    /* reserved for use by WRS */
    } MODULE;

typedef struct module * MODULE_ID;  /* module ID */

extern MODULE_ID    moduleFindByName (char * moduleName);

#undef factory
#define factory WHAT_IS_HAPPENING_HERE

extern UINT16 *WHAT_IS_HAPPENING_HERE();


#endif //_X86_MODULELIB_H





