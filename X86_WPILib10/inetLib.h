/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: inetLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_INETLIB_H
#define _X86_INETLIB_H


/*
 * Description:
 */
typedef unsigned char u_char;
typedef unsigned short int u_short;
typedef unsigned long int u_long;
typedef unsigned long int u_int32_t;

/*
 * Internet address (a structure for historical reasons)
 */

typedef u_int32_t       in_addr_t;

struct in_addr {
	in_addr_t s_addr;
};


/*
 * Socket address, internet style.
 */
struct sockaddr_in {
	u_char	sin_len;
	u_char	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};

#define htons(x)        (x)
#define htonl(x)        (x)


extern    unsigned long   inet_addr (char *);
#define INADDR_ANY                      (u_int32_t)0x00000000



#endif //_X86_INETLIB_H



