#ifndef XPLATFORM_H
#define XPLATFORM_H

#ifdef _WIN32
#if defined(NTDDI_VERSION) && WINNT == 1
#include <fltKernel.h>
#include <ntddk.h>
#include <wdm.h>
#else
#include <Windows.h>
#endif
#else
#ifdef __KERNEL__
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/limits.h>
#include <linux/version.h>
#else
#include <unistd.h>  
#endif
#endif

#ifndef likely
#define likely(x)	(x)
#endif

#ifndef unlikely
#define unlikely(x)	(x)
#endif

#ifndef PAGE_SIZE
#define PAGE_SIZE	0x1000
#endif

#endif
