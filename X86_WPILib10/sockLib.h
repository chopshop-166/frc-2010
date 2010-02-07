/*****************************************************************************
*  Project   		: X86_WPILib10 - 2010 Chopshop Robot Hardware Simulator
*  File Name  		: sockLib.h
*  Creator			: Chris Franklin (mentor)     
*  Owner		   	: Software Group (FIRST Chopshop Team 166)
*  Creation Date	: February 6, 2010
*  Revision History	: From Explorer w/TortoiseSVN, Use "Show log" menu item
*  File Description	: Stub header included with existing WPILib code
*****************************************************************************/

/*--------------------------------------------------------------------------*/
/*  Copyright (c) MHS Chopshop Team 166, 2010.  All Rights Reserved.        */
/*--------------------------------------------------------------------------*/

#ifndef _X86_SOCKLIB_H
#define _X86_SOCKLIB_H


#include "VxWorks.h"
#include <strLib.h>

#define AF_INET         2               /* internetwork: UDP, TCP, etc. */

#define SOL_SOCKET      0xffff          /* options for socket level */

/*
 * Types
 */
#define	SOCK_STREAM	1		/* stream socket */
#define	SOCK_DGRAM	2		/* datagram socket */
#define	SOCK_RAW	3		/* raw-protocol interface */
#define	SOCK_RDM	4		/* reliably-delivered message */
#define	SOCK_SEQPACKET	5		/* sequenced packet stream */

/*
 * Option flags per-socket.
 */
#define	SO_DEBUG	0x0001		/* turn on debugging info recording */
#define	SO_ACCEPTCONN	0x0002		/* socket has had listen() */
#define	SO_REUSEADDR	0x0004		/* allow local address reuse */
#define	SO_KEEPALIVE	0x0008		/* keep connections alive */
#define	SO_DONTROUTE	0x0010		/* just use interface addresses */
#define	SO_BROADCAST	0x0020		/* permit sending of broadcast msgs */
#define	SO_USELOOPBACK	0x0040		/* bypass hardware when possible */
#define	SO_LINGER	0x0080		/* linger on close if data present */
#define	SO_OOBINLINE	0x0100		/* leave received OOB data in line */
#define	SO_REUSEPORT	0x0200		/* allow local address & port reuse */
#define	SO_TIMESTAMP	0x0400		/* timestamp received dgram traffic */

#define SO_LINGERRESET  0x2000		/* when linger fails, reset conn. */
#define SO_VSLOCK       0x4000          /* restrict calls to creation stack */
#define SO_VLAN         0x8000      /* get/set VLAN ID and user priority */
#define SO_PRIVBUF      0x0             /* COMP-only: socket uses private pool*/

extern STATUS 	bind (int s, struct sockaddr *name, int namelen);
extern STATUS 	connect (int s, struct sockaddr *name, int namelen);
//extern STATUS 	connectWithTimeout (int sock, struct sockaddr *adrs,
//				    int adrsLen, struct timeval *timeVal);
//extern STATUS 	getpeername (int s, struct sockaddr *name, int *namelen);
//extern STATUS 	getsockname (int s, struct sockaddr *name, int *namelen);
//extern STATUS 	getsockopt (int s, int level, int optname, char *optval,
//			    int *optlen);
extern STATUS 	listen (int s, int backlog);
extern STATUS 	setsockopt (int s, int level, int optname, char *optval,
			    int optlen);
//extern STATUS 	shutdown (int s, int how);
extern int 	accept (int s, struct sockaddr *addr, int *addrlen);
extern int 	recv (int s, char *buf, int bufLen, int flags);
//extern int 	recvfrom (int s, char *buf, int bufLen, int flags,
//			  struct sockaddr *from, int *pFromLen);
//extern int 	recvmsg (int sd, struct msghdr *mp, int flags);
extern int 	send (int s, const char *buf, int bufLen, int flags);
//extern int 	sendmsg (int sd, struct msghdr *mp, int flags);
//extern int 	sendto (int s, caddr_t buf, int bufLen, int flags,
//			struct sockaddr *to, int tolen);
extern int 	socket (int domain, int type, int protocol);

/* APIs unique to Kernel */
//extern int	open (const char *, int, int);
//extern int	creat (const char *, int);
extern int	read (int, char *, size_t);
extern int	write (int, char *, size_t);
//extern int 	ioctl (int fd, int function, int arg);
extern STATUS	close (int);
//extern STATUS	remove (const char *);
//extern BOOL	isatty (int fd);


#endif //_X86_SOCKLIB_H











