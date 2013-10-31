/* ================================================================= */
/* ========== LANSA FOR WINDOWS GLOBAL DEFINITIONS ================= */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_BLDCFG.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : LANSA compiler macros                       */
/* This file derives LANSA macros from implicit compiler macros      */
/* Use x_platform.h for using these macros to derive other LANSA     */
/* macros.                                                           */
/*                                                                   */
/* Changes to this file must be reflected in the documentation here: */
/* http://rhea/lpcwiki/StandardMacros                                */
/* ================================================================= */

#ifndef __INCL_X_BLDCFG_H__
#define __INCL_X_BLDCFG_H__

// ****************************************************************************
// Determine lengths of int, long and pointer
// Use of these should be rare. Specific integer lengths should be used instead.
// e.g. int16,
// ****************************************************************************

// long long is always 64-bit. int, long and pointer are presumed to be 32-bit unless otherwise detected below

#if defined(__LP64__)
// LP64 machine, Linux (64-bit)
// long and pointer 64-bit
#define X_LP64
#define X_P64           // 64-bit pointer
#define X_L64           // 64-bit long

#elif defined(__OS400__) && !defined(__LLP64_IFC__)
// IBM i
// pointer 128-bit
#define X_LL64P128      // By convention long long is specified, but it's redundant as it's always 64-bit
#define X_P128          // 128-bit pointer

#elif defined(_M_X64) || defined(_M_AMD64) \
      || defined(amd64) || defined(__amd64) || defined(__amd64__) \
      || defined(x86_64) || defined(__x86_64) || defined(__x86_64__) \
      || defined(__LLP64_IFC__)
// LLP64 machine. Windows (64-bit), IBM i with __LLP64_IFC__ defined
// pointer 64-bit
#define X_LLP64         // By convention long long is specified, but it's redundant as it's always 64-bit
#define X_P64           // 64-bit pointer

#if defined(__OS400__)
#error Unexplored option of using __LLP64_IFC__ on IBM i
#endif

#else
// 32-bit machine, Windows or Linux
// int, long and pointer all 32-bit
#define X_LP32

#ifdef _WIN64
#error Internal compiler macro inconsistency. Compiling for 64-bit but setting 32-bit options
#endif

#endif

// ****************************************************************************
// Main OS being used
// ****************************************************************************

#if defined(_WIN32)

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502   // Windows XP SP2
#endif

#ifndef WINVER
#define WINVER 0x0502         // Windows XP SP2
#endif

#ifndef X_OPERATING_SYSTEM_WIN
#define X_OPERATING_SYSTEM_WIN
#endif

#ifndef X_OPERATING_SYSTEM_WIN32
#define X_OPERATING_SYSTEM_WIN32
#endif

// For backward compatibility with x_defxxx.h files which use X_OPERATING_SYSTEM_WIN95
// Do not use for any other purpose
#ifndef X_OPERATING_SYSTEM_WIN95
#define X_OPERATING_SYSTEM_WIN95
#endif

#if defined(_MSC_VER)
#ifndef X_MSVC
#define X_MSVC
#endif
#endif

#elif defined(__OS400__)

#ifndef X_OPERATING_SYSTEM_UNIX
#define X_OPERATING_SYSTEM_UNIX
#endif
#ifndef X_OPERATING_SYSTEM_ISERIES
#define X_OPERATING_SYSTEM_ISERIES
#endif

#elif defined(unix) || defined(__unix) || defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))

#ifndef X_OPERATING_SYSTEM_UNIX
#define X_OPERATING_SYSTEM_UNIX
#endif

#if defined(__APPLE__) && defined(__MACH__)

#ifndef X_OPERATING_SYSTEM_IOS
#define X_OPERATING_SYSTEM_IOS
#endif

#elif defined(__ANDROID__)

#ifndef X_OPERATING_SYSTEM_ANDROID
#define X_OPERATING_SYSTEM_ANDROID
#endif

#elif defined(__JAVASCRIPT__)

#ifndef X_OPERATING_SYSTEM_JAVASCRIPT
#define X_OPERATING_SYSTEM_JAVASCRIPT
#endif

#else

#ifndef X_OPERATING_SYSTEM_LNX
#define X_OPERATING_SYSTEM_LNX
#endif

#endif

#endif

// ****************************************************************************
// CPU bitness
// ****************************************************************************

#if defined(_M_IX86) || defined(_X86_) \
      || defined(i386) || defined(__i386) || defined(__i386__) \
      || defined(_M_ARM_FP)
#ifndef X_OPERATING_SYSTEM_32BIT
#define X_OPERATING_SYSTEM_32BIT
#endif
#ifndef X_CPU_32BIT
#define X_CPU_32BIT
#endif
#ifndef X_SIZE_T_32BIT
#define X_SIZE_T_32BIT
#endif
#endif

#if defined(_M_X64) || defined(_M_AMD64) || defined(_M_IA64) \
      || defined(amd64) || defined(__amd64) || defined(__amd64__) \
      || defined(x86_64) || defined(__x86_64) || defined(__x86_64__) \
      || defined(__OS400__) || defined(__LP64__)
#ifndef X_OPERATING_SYSTEM_64BIT
#define X_OPERATING_SYSTEM_64BIT
#endif
#ifndef X_CPU_64BIT
#define X_CPU_64BIT
#endif
#ifdef __OS400__
#ifndef X_SIZE_T_32BIT
#define X_SIZE_T_32BIT
#endif
#else
#ifndef X_SIZE_T_64BIT
#define X_SIZE_T_64BIT
#endif
#endif
#endif

// Default CPU size is 32-bit
#if !defined(X_CPU_32BIT) && !defined(X_CPU_64BIT)
#define X_CPU_32BIT
#endif

// Default sizeof size_t is 32-bit
#if !defined(X_SIZE_T_32BIT) && !defined(X_SIZE_T_64BIT)
#define X_SIZE_T_32BIT
#endif

// ****************************************************************************
// CPU Specifics
// ****************************************************************************
#if defined(_M_IX86) || defined(_X86_) \
      || defined(i386) || defined(__i386) || defined(__i386__)
#ifndef X_CPU_INTEL
#define X_CPU_INTEL
#endif
#ifndef X_CPU_X86
#define X_CPU_X86
#endif
#ifndef X_LITTLE_ENDIAN
#define X_LITTLE_ENDIAN
#endif
#endif

// Notice that even though AMD may be defined, it's synonymous with x64
// and so it's been defined as an Intel platform
#if defined(_M_X64) || defined(_M_AMD64) \
      || defined(amd64) || defined(__amd64) || defined(__amd64__) \
      || defined(x86_64) || defined(__x86_64) || defined(__x86_64__)
#ifndef X_CPU_INTEL
#define X_CPU_INTEL
#endif
#ifndef X_CPU_X64
#define X_CPU_X64
#endif
#ifndef X_LITTLE_ENDIAN
#define X_LITTLE_ENDIAN
#endif
#endif

#if defined(__OS400__)
#ifndef X_BIG_ENDIAN
#define X_BIG_ENDIAN
#endif
#endif

#if defined(_M_ARM_FP)
#ifndef X_CPU_ARM
#define X_CPU_ARM
#endif
#ifndef X_CPU_ARM32
#define X_CPU_ARM32
#endif
#ifndef X_LITTLE_ENDIAN
#define X_LITTLE_ENDIAN
#pragma message( "Check endianness of ARM processor" )
#endif
#endif

// ****************************************************************************
// OS Aliases
// ****************************************************************************

#if defined(X_OPERATING_SYSTEM_WIN)
#ifndef X_OS_WIN
#define X_OS_WIN
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WIN32)
#ifndef X_OS_WIN32
#define X_OS_WIN32
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WINRT)
#ifndef X_OS_WINRT
#define X_OS_WINRT
#endif
#endif

#if defined(X_OPERATING_SYSTEM_32BIT)
#ifndef X_OS_32BIT
#define X_OS_32BIT
#endif
#endif

#if defined(X_OPERATING_SYSTEM_64BIT)
#ifndef X_OS_64BIT
#define X_OS_64BIT
#endif
#endif

#if defined(X_OPERATING_SYSTEM_ISERIES)
#ifndef X_OS_ISERIES
#define X_OS_ISERIES
#endif
#endif

#if defined(X_OPERATING_SYSTEM_UNIX)
#ifndef X_OS_UNIX
#define X_OS_UNIX
#endif
#endif

#if defined(X_OPERATING_SYSTEM_LNX)
#ifndef X_OS_LNX
#define X_OS_LNX
#endif
#endif

#if defined(X_OPERATING_SYSTEM_IOS)
#ifndef X_OS_IOS
#define X_OS_IOS
#endif
#endif

#if defined(X_OPERATING_SYSTEM_ANDROID)
#ifndef X_OS_ANDROID
#define X_OS_ANDROID
#endif
#endif

#if defined(X_OPERATING_SYSTEM_JAVASCRIPT)
#ifndef X_OS_JAVASCRIPT
#define X_OS_JAVASCRIPT
#endif
#endif

// ****************************************************************************
// Handy macros
// ****************************************************************************

#if defined(X_OPERATING_SYSTEM_WIN32) && defined(X_CPU_X86) && defined(X_OS_32BIT) && defined(X_LITTLE_ENDIAN)
#ifndef X_WIN32_X86
#define X_WIN32_X86
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WIN32) && defined(X_CPU_X64) && defined(X_OS_64BIT) && defined(X_LITTLE_ENDIAN)
#ifndef X_WIN32_X64
#define X_WIN32_X64
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WINRT) && defined(X_CPU_X86) && defined(X_OS_32BIT) && defined(X_LITTLE_ENDIAN)
#ifndef X_WINRT_X86
#define X_WINRT_X86
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WINRT) && defined(X_CPU_X64) && defined(X_OS_64BIT)
#ifndef X_WINRT_X64
#define X_WINRT_X64
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WINRT) && defined(X_CPU_ARM32)
#ifndef X_WINRT_ARM32
#define X_WINRT_ARM32
#endif
#endif

#if defined(X_OPERATING_SYSTEM_WINRT )&& defined(X_CPU_ARM64)
#ifndef X_WINRT_ARM64
#define X_WINRT_ARM64
#endif
#endif

// ****************************************************************************
// Miscellaneous
// ****************************************************************************

// On OS/400, when an API specifies that a 32-bit integer is required, using
// long is not acceptable even though it too is 32 bits. e.g. the CEEDAYS API
// in x_fun3.c.
// Its not dependent on machine architecture or 32 v. 64 bit or anything else.
// Just a quirk of these APIs.
#if defined(__OS400__)
#ifndef X_USE_INT_NOT_LONG
#define X_USE_INT_NOT_LONG
#endif
#endif

#endif /* __INCL_X_BLDCFG_H__ */
