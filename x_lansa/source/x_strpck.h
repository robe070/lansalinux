/*     %NATIVE PVCS                                                 */
/*     %AS   DCXXUPDMBR SRCMBR(X_STRPCK.H)                          */
/* =========================================== */
/* Start constant packing across all platforms */
/* =========================================== */
/* LANSA/X compiled with MSVC defaults to 1 byte Pack.*/
/* This is a compiler option /Zp1                     */
/* Watcom also does this, but it is working so I aint */
/* going to break it! Rob G.                          */
/* Redefine of _Packed for MSVC is now only needed    */
/* the Web code. X_PACKED is not defined in the       */
/* iSeries code. Steve T                              */

#if defined( X_OPERATING_SYSTEM_UNIX )

#if defined( X_OPERATING_SYSTEM_AIX ) || defined( X_OPERATING_SYSTEM_PASE )

#pragma options align=packed
#ifndef _Packed
#define _Packed
#endif

#elif defined( X_OPERATING_SYSTEM_LNX ) \
      || defined( X_OPERATING_SYSTEM_SOL ) \
      || defined(X_OPERATING_SYSTEM_ANDROID) \
      || defined(X_OPERATING_SYSTEM_JAVASCRIPT) \
      || defined(X_OPERATING_SYSTEM_IOS)

#pragma pack(1)
#ifndef _Packed
#define _Packed
#endif

#elif defined( X_OPERATING_SYSTEM_ISERIES )

/* #pragma pack(1) is supported as of V5R1M0                           */
/* Packed Structs no longer need to be typedef X_PACKED  struct ....   */

#ifdef X_LANSAX_BUILD
/* VISUAL LANSA ONLY */
#pragma pack(1)
#endif

#else
#include "warnpend.h"
#endif

#elif defined( X_OPERATING_SYSTEM_ISERIES )

/* CLASSIC LANSA - Nothing to worry! */

#else /* i.e. Windows etc */

#pragma pack(push, 1)

#endif

#if defined(_MSC_VER) || defined(MSVC)
/* Get rid of the _Packed keyword */
#undef _Packed
#define _Packed
#endif
