/* ================================================================= */
/* ============== VISUAL LANSA UTILITY DEFINITIONS ================= */
/* ================================================================= */
/*                                                                   */
/* Source File         : x_cutil.h                                   */
/* OS/Dependencies     : Yes                                         */
/* End User Modifiable : Not Recommended                             */
/* Description         : Utility definitions                         */
/*                                                                   */
/*                       ---------- IMPORTANT NOTE ------------      */
/*                       Don't include LANSA defined headers in      */
/*                       this file. It is used in modules that       */
/*                       don't include all LANSA source direct-      */
/*                       ories.                                      */
/*                       --------------------------------------      */
/*                                                                   */
/* ================================================================= */

#ifndef __INCL_X_CUTIL_H__
#define __INCL_X_CUTIL_H__

#include <string.h>

// #include "utilutf16.h"

/* ================================================================= */
/*  Operating system dependent defines and redefines                 */
/* ================================================================= */

/* CCS 128095 : Better performing memcpy when copying bytes on iSeries. NOT TO BE USED when data contains pointers - use memcpy!!! */
#if defined(X_OPERATING_SYSTEM_ISERIES) && !defined(X_OPERATING_SYSTEM_PASE)

#include <mih/cpybytes.h>

#define X_CPYBYTES( _T, _S, _L ) _CPYBYTES( (_T), (_S), (_L) )
#define X_CPYBYTES_STR( _T, _S, _L ) X_CPYBYTES( _T, _S, _L )

// Length specified in UTF-16 units, not bytes
#define X_WCPYBYTES( _T, _S, _L ) _CPYBYTES( (_T), (_S), sizeof(X_UTF16_VCHAR) * (_L) )

#else

#ifdef X_OPERATING_TARGET_CSHARP

#define X_CPYBYTES( _T, _S, _L ) X_DEFS.X_COPYBYTES( _T, _S, _L )
#define X_CPYBYTES_STR( _T, _S, _L ) X_DEFS.X_COPYBYTES_STR( _T, _S, _L )

// Length specified in UTF-16 units, not bytes
#define X_WCPYBYTES( _T, _S, _L ) X_DEFS.X_COPYBYTES( _T, _S, sizeof(X_UTF16_VCHAR) * (_L) )

#else

#define X_CPYBYTES( _T, _S, _L ) memcpy( (_T), (_S), (_L) )
#define X_CPYBYTES_STR( _T, _S, _L ) X_CPYBYTES( _T, _S, _L )

// Don't use wmemcpy as on Linux its defined as 32 bit not 16 bit.
// Length specified in UTF-16 units, not bytes
#define X_WCPYBYTES( _T, _S, _L ) memcpy( (_T), (_S), sizeof(X_UTF16_VCHAR) * (_L) )

#endif /* X_OPERATING_TARGET_CSHARP */

#endif

#if defined(X_OPERATING_SYSTEM_WIN)
   #define X_PATH_SEPARATOR         '\\'
   #define X_PATH_SEPARATOR_2       '/'
   #define X_IS_PATH_SEPARATOR(c)   (((c) == X_PATH_SEPARATOR) || ((c) == X_PATH_SEPARATOR_2))
   #define X_OLD_ROOT_NAME_LEN      65
   #define X_NEW_ROOT_NAME_LEN      260

#elif defined(X_OPERATING_SYSTEM_UNIX)
   #define X_PATH_SEPARATOR         '/'
   #define X_PATH_SEPARATOR_2       '\\'
   #define X_IS_PATH_SEPARATOR(c)   ((c) == X_PATH_SEPARATOR)
   #define X_OLD_ROOT_NAME_LEN      256    /* Max length of ROOT */
   #define X_NEW_ROOT_NAME_LEN      X_OLD_ROOT_NAME_LEN

#endif

#define X_NEW_FILE_PATH_LENGTH X_NEW_ROOT_NAME_LEN
#define X_OLD_FILE_PATH_LENGTH X_OLD_ROOT_NAME_LEN  /* Deprecated ... use X_NEW_FILE_PATH_LENGTH */

/* X_ISALNUM() is used in place of the C isalnum() function to handle some code pages including
   characters that are not valid for C names such as the translated '@' character for FRA. */

#define X_ISALNUM(_C) \
   ((int)(strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890",(int)(_C)) != NULL))

#ifdef __cplusplus
#undef min
#undef max
extern "C++" {
#if defined(_MSC_VER) && _MSC_VER < 1300
#include <xutility>
#define min std::_cpp_min
#define max std::_cpp_max
#else
#include <algorithm>
using std::min;
using std::max;
#endif
} // extern "C++"
#ifdef LP__HPP
// Components code still relies on min() and max() being macros
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#else
#define min min
#define max max
#endif
#else
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif
#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif
#endif

#endif /* __INCL_X_CUTIL_H__ */
