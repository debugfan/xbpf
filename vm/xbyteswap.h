#ifndef XBYTESWAP_H
#define XBYTESWAP_H

#ifdef _WIN32
#include <stdlib.h>
#else
#ifndef __KERNEL__
#include <byteswap.h>
#define HAVE_BYTESWAP
#endif
#endif

#ifdef _WIN32
#define xbswap_16(x)	_byteswap_ushort (x)
#define xbswap_32(x)	_byteswap_ulong (x)
#define xbswap_64(x)	_byteswap_uint64 (x)
#else
#ifdef __KERNEL__
#define xbswap_16(x)	__builtin_bswap16 (x)
#define xbswap_32(x)	__builtin_bswap32 (x)
#define xbswap_64(x)	__builtin_bswap64 (x)
#else
#define xbswap_16(x)	bswap_16 (x)
#define xbswap_32(x)	bswap_32 (x)
#define xbswap_64(x)	bswap_64 (x)
#endif
#endif

#ifndef HAVE_BYTESWAP
#define __bswap_16(x) xbswap_16(x)
#define __bswap_32(x) xbswap_32(x)
#define __bswap_64(x) xbswap_64(x)

#define bswap_16(x) xbswap_16(x)
#define bswap_32(x) xbswap_32(x)
#define bswap_64(x) xbswap_64(x)
#endif

#endif
