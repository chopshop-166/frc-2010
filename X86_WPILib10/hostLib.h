/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: hostLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_HOSTLIB_H
#define _X86_HOSTLIB_H



/* function declarations */

//extern STATUS 	hostAdd (char *hostName, char *hostAddr);
//extern STATUS 	hostDelete (char *name, char *addr);
//extern STATUS 	hostGetByAddr (int addr, char *name);
extern int 	hostGetByName (char *name);
//extern int      getnameinfo (const struct sockaddr *sa, socklen_t salen, char *host,
//                             size_t hostlen, char *serv, size_t servlen, int flags);
//extern struct hostent * hostentAlloc (void);
//extern void hostentFree (struct hostent *);
//extern struct hostent * gethostbyaddr (const char *addr, int len, int type);
//extern struct hostent * gethostbyname (const char *name);
//extern struct servent *getservbyname (const char *name, const char *proto);
//extern struct servent *getservbyport (int port, const char *proto);
//extern int      getaddrinfo (const char *hostname, const char *servname,
//                             const struct addrinfo *hints, struct addrinfo **result);
//extern void     freeaddrinfo (struct addrinfo *ai);
///extern void freehostent (struct hostent *);
//extern int 	gethostname (char *name, int nameLen);
//extern int 	sethostname (char *name, int nameLen);
//extern char    *gai_strerror (int ecode);
//extern struct	 hostent *_dns_ghbyaddr(const void *addr, int addrlen, int af, int *errp);
#endif //_X86_HOSTLIB_H

