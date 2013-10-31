/* ================================================================= */
/* ========== LANSA FOR WINDOWS GLOBAL DEFINITIONS ================= */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_PLATFORM.H                                */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : LANSA Platform Defintions                   */
/*                                                                   */
/* ================================================================= */

#ifndef __INCL_X_PLATFORM_H__
#define __INCL_X_PLATFORM_H__

#include "x_bldcfg.h"

#ifndef X_VAR_SUPPORT
#define X_VAR_SUPPORT
#endif

/* Allow MessageBox in user defined builtins. */
#ifdef U_BIF_FUNCTION
#ifndef X_ALLOW_MESSAGE_BOX
#define X_ALLOW_MESSAGE_BOX
#endif
#endif

/* ==================================================================== */
/* Full leakage testing variable - DO NOT DEFINE IN PRODUCTION SOFTWARE */
/* ==================================================================== */

#ifdef X_LANSAX_BUILD  /* Generators do not support leak checking */
   #ifdef NO_LEAK_CHECK
      #undef X_LEAK_CHECKING_CODE
   #endif
#else
   #ifdef X_LEAK_CHECKING_CODE
      #undef X_LEAK_CHECKING_CODE
   #endif
#endif

/* ================================================================= */
/* Shortened versions of Operating System defines were introduced    */
/* to reduce the compile command line length to less than 240.  This */
/* is especially relevant in the Win32 environment when compiling    */
/* with X_DEBUG.                                                     */
/* This code defines the original OS Defines from the shortened      */
/* versions.                                                         */
/* Similarly for X_DATABASE_ODBC & X_DATABASE_WSQL                   */
/* ================================================================= */

// X_OPERATING_SYSTEM_W95 is required for backward compatibility with x_defxxx.h files

#if defined( X_W32 ) && !defined( X_OPERATING_SYSTEM_WIN32 )
#define X_OPERATING_SYSTEM_WIN32
#if !defined( X_OPERATING_SYSTEM_WIN )
#define X_OPERATING_SYSTEM_WIN
#endif
#endif

#if defined( X_W32 ) && !defined( X_OPERATING_SYSTEM_WIN95 )
#define X_OPERATING_SYSTEM_WIN95
#if !defined( X_OPERATING_SYSTEM_WIN )
#define X_OPERATING_SYSTEM_WIN
#endif
#endif

#if defined( X_W64 ) && !defined( X_OS_64BIT )
#define X_OS_64BIT
#if !defined( X_OPERATING_SYSTEM_WIN )
#define X_OPERATING_SYSTEM_WIN
#endif
#endif

#if defined( X_W64 ) && !defined( X_OPERATING_SYSTEM_WIN95 )
#define X_OPERATING_SYSTEM_WIN95
#if !defined( X_OPERATING_SYSTEM_WIN )
#define X_OPERATING_SYSTEM_WIN
#endif
#endif

#if defined( X_ODBC ) && !defined( X_DATABASE_ODBC )
#define X_DATABASE_ODBC
#endif

#if defined( X_WSQL ) && !defined( X_DATABASE_WSQL )
#define X_DATABASE_WSQL
#endif

#if ( defined( X_LX ) || defined( X_OPERATING_SYSTEM_IOS ) || defined( X_OPERATING_SYSTEM_ANDROID ) || defined( X_OPERATING_SYSTEM_JAVASCRIPT ) ) && !defined( X_LANSAX_BUILD )
#define X_LANSAX_BUILD
#endif

#if ( defined( X_32 ) || defined( X_OPERATING_SYSTEM_IOS ) || defined( X_OPERATING_SYSTEM_ANDROID ) || defined( X_OPERATING_SYSTEM_JAVASCRIPT ) ) && !defined( X_SPLIT_NO )
#define X_SPLIT_NO
#endif

#if defined(X_OPERATING_SYSTEM_WIN)

#define X_DEBUG_MESSAGE_BOX(_TEXT) \
{ \
   MessageBox( NULL,  \
               _TEXT, \
               "X_DEBUG_MESSAGE_BOX", \
               (MB_OK | MB_ICONSTOP | MB_TASKMODAL | MB_SETFOREGROUND \
               | MB_SETFOREGROUND | MB_SERVICE_NOTIFICATION) ); \
}

#if !defined WIN32
#define WIN32
#endif

/* Set the default compiler to Microsoft Visual C on WIN32 */
#if !defined( X_WATCOM ) && !defined( X_MSVC ) && !defined( MSVC )
#define X_MSVC
#endif

#endif

/* Note that other platforms may use MSVC compiler like the now   */
/* defunct Compaq Alpha                                           */
#if defined( MSVC ) && !defined( X_MSVC )
#define X_MSVC
#endif

#if defined( X_MSVC ) && !defined( MSVC )
#define MSVC
#endif

#if defined( X_MSVC ) && defined( X_WATCOM )
#error Both the Watcom and Microsoft Visual C Compilers have been defined.
#endif

/* Defining this causes some warnings to be suppressed as defined by each C */
/* file  -  undefine it to see all warnings                                 */
#if defined( X_OPERATING_SYSTEM_WIN) && defined( X_MSVC )
#define X_WARNINGS
#endif

/* Enable heap list tracking. Requires x_pdflst.cpp to be linked in for Windows */
/* or x_pdflst.c on UNIX/iSeries - and also requires $(DLLMAIN) in link line    */
#if !defined(X_OPERATING_SYSTEM_ISERIES)
#define X_HEAPLIST
#endif

/* ================================================================= */
/*  Decide whether collection names supported in database            */
/* ================================================================= */

#if defined( X_DATABASE_DB2 ) || defined( X_DATABASE_WSQL )
#define X_COLLECTIONS_SUPPORTED
#endif

/* ================================================================= */
/*  Watcom SQL is an ODBC database.                                  */
/* ================================================================= */

#if defined( X_DATABASE_WSQL ) && !defined( X_DATABASE_ODBC )
#define X_DATABASE_ODBC
#endif

#if !defined(X_OPERATING_SYSTEM_ISERIES)
#define X_JOB_QUEUE_EMULATION
#endif

#if defined( X_OPEN_SSL ) && !defined(XSLEDITOR)
// Stop wincrypt.h being used as the definition of OCSP_RESPONSE in ossl_typ.h
// conflicts with the OpenSSL file ossl_typ.h file
// Error	1	error C2059: syntax error : 'type'	c:\dev\trunk\work\x_win95\x_lansa\src\openssl\ossl_typ.h	178
// It must be included before windows.h which this file achieves through x_glodef.h
#define __WINCRYPT_H__
#endif

#endif /* __INCL_X_PLATFORM_H__ */
