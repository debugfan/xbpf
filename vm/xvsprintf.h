#ifndef XVSPRINTF_H
#define XVSPRINTF_H

#include <stdarg.h>

#ifdef __cplusplus
extern  "C"
{
#endif

int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);

#ifdef __cplusplus
}
#endif

#endif
