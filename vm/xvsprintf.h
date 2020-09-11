#ifndef XVSPRINTF_H
#define XVSPRINTF_H

#include <stdarg.h>

#ifdef __cplusplus
extern  "C"
{
#endif

#ifdef __linux__
#define xvsnprintf(buf, size, fmt, args) vsnprintf(buf, size, fmt, args)
#define xsnprintf snprintf
#else
int xvsnprintf(char *buf, size_t size, const char *fmt, va_list args);
int xsnprintf(char * buf, size_t size, const char *fmt, ...);
#endif

int xvsscanf(const char * buf, const char * fmt, va_list args);
int xsscanf(const char * buf, const char * fmt, ...);

static int xvscprintf(const char *fmt, va_list args)
{
	char buf[256];
	return xvsnprintf(buf, sizeof(buf), fmt, args);
}

static int xvasprintf(char **strp, const char *fmt, va_list args) 
{
	int len = xvscprintf(fmt, args);
	if (len < 0) {
		return -1;
	}
	size_t size = (size_t)len + 1;
	char *str = malloc(size);
	if (!str) {
		return -1;
	}
	int r = xvsnprintf(str, len + 1, fmt, args);
	if (r == -1) {
		free(str);
		return -1;
	}
	*strp = str;
	return r;
}

#ifdef __cplusplus
}
#endif

#endif
