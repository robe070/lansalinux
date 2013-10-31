/*     %NATIVE PVCS                                                 */
/*     %AS   DCXXUPDMBR SRCMBR(X_ENDPCK.H)                          */
/* =============================== */
/* Put packing back to the default */
/* =============================== */

#if defined( X_OPERATING_SYSTEM_UNIX )

#if defined( X_OPERATING_SYSTEM_AIX ) || defined( X_OPERATING_SYSTEM_PASE )

#pragma options align=reset
#ifdef _Packed
#undef _Packed
#endif

#elif defined( X_OPERATING_SYSTEM_LNX ) \
      || defined( X_OPERATING_SYSTEM_SOL ) \
      || defined(X_OPERATING_SYSTEM_ANDROID) \
      || defined(X_OPERATING_SYSTEM_JAVASCRIPT) \
      || defined(X_OPERATING_SYSTEM_IOS)

#pragma pack()
#ifdef _Packed
#undef _Packed
#endif

#elif defined( X_OPERATING_SYSTEM_ISERIES )

/* #pragma pack() is supported as of V5R1M0                             */
/* Packed Structs no longer need to be typedef X_PACKED  struct ....    */

#ifdef X_LANSAX_BUILD
/* VISUAL LANSA ONLY */
#pragma pack()
#endif

#else
#include "warnpend.h"
#endif

#elif defined( X_OPERATING_SYSTEM_ISERIES )

/* CLASSIC LANSA - Nothing to worry! */

#else /* i.e. Windows */

#pragma pack(pop)

#endif
