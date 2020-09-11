#ifndef _XCTYPE_H
#define _XCTYPE_H

#include "xplatform.h"
#ifdef __KERNEL__
#include <linux/ctype.h>
#else
#include <ctype.h>
#endif

/*
 * NOTE! This ctype does not handle EOF like the standard C
 * library is required to.
 */

#define _U	0x01	/* upper */
#define _L	0x02	/* lower */
#define _D	0x04	/* digit */
#define _C	0x08	/* cntrl */
#define _P	0x10	/* punct */
#define _S	0x20	/* white space (space/lf/tab) */
#define _X	0x40	/* hex digit */
#define _SP	0x80	/* hard space (0x20) */

static unsigned char _xctype[] = {
	_C,_C,_C,_C,_C,_C,_C,_C,			/* 0-7 */
	_C,_C | _S,_C | _S,_C | _S,_C | _S,_C | _S,_C,_C,		/* 8-15 */
	_C,_C,_C,_C,_C,_C,_C,_C,			/* 16-23 */
	_C,_C,_C,_C,_C,_C,_C,_C,			/* 24-31 */
	_S | _SP,_P,_P,_P,_P,_P,_P,_P,			/* 32-39 */
	_P,_P,_P,_P,_P,_P,_P,_P,			/* 40-47 */
	_D,_D,_D,_D,_D,_D,_D,_D,			/* 48-55 */
	_D,_D,_P,_P,_P,_P,_P,_P,			/* 56-63 */
	_P,_U | _X,_U | _X,_U | _X,_U | _X,_U | _X,_U | _X,_U,	/* 64-71 */
	_U,_U,_U,_U,_U,_U,_U,_U,			/* 72-79 */
	_U,_U,_U,_U,_U,_U,_U,_U,			/* 80-87 */
	_U,_U,_U,_P,_P,_P,_P,_P,			/* 88-95 */
	_P,_L | _X,_L | _X,_L | _X,_L | _X,_L | _X,_L | _X,_L,	/* 96-103 */
	_L,_L,_L,_L,_L,_L,_L,_L,			/* 104-111 */
	_L,_L,_L,_L,_L,_L,_L,_L,			/* 112-119 */
	_L,_L,_L,_P,_P,_P,_P,_C,			/* 120-127 */
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,		/* 128-143 */
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,		/* 144-159 */
	_S | _SP,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,   /* 160-175 */
	_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,       /* 176-191 */
	_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,_U,       /* 192-207 */
	_U,_U,_U,_U,_U,_U,_U,_P,_U,_U,_U,_U,_U,_U,_U,_L,       /* 208-223 */
	_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,_L,       /* 224-239 */
	_L,_L,_L,_L,_L,_L,_L,_P,_L,_L,_L,_L,_L,_L,_L,_L };      /* 240-255 */

#define __xismask(x) (_xctype[(int)(unsigned char)(x)])

#define xisalnum(c)	((__xismask(c)&(_U|_L|_D)) != 0)
#define xisalpha(c)	((__xismask(c)&(_U|_L)) != 0)
#define xiscntrl(c)	((__xismask(c)&(_C)) != 0)
#define xisdigit(c)	((__xismask(c)&(_D)) != 0)
#define xisgraph(c)	((__xismask(c)&(_P|_U|_L|_D)) != 0)
#define xislower(c)	((__xismask(c)&(_L)) != 0)
#define xisprint(c)	((__xismask(c)&(_P|_U|_L|_D|_SP)) != 0)
#define xispunct(c)	((__xismask(c)&(_P)) != 0)
#define xisspace(c)	((__xismask(c)&(_S)) != 0)
#define xisupper(c)	((__xismask(c)&(_U)) != 0)
#define xisxdigit(c)	((__xismask(c)&(_D|_X)) != 0)

#define xisascii(c) (((unsigned char)(c))<=0x7f)
#define xtoascii(c) (((unsigned char)(c))&0x7f)

static inline unsigned char __xtolower(unsigned char c)
{
	if (isupper(c))
		c += 'a' - 'A';
	return c;
}

static inline unsigned char __xtoupper(unsigned char c)
{
	if (islower(c))
		c -= 'a'-'A';
	return c;
}

#define xtolower(c) __xtolower(c)
#define xtoupper(c) __xtoupper(c)

#ifdef _NTDDK_
#define isalpha(x)	xisalpha(x)
#define isalnum(x)	xisalnum(x)
#endif

#endif
