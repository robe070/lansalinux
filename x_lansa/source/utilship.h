/* ================================================================== */
/* ================ VISUAL LANSA UTILITY DEFINITIONS ================ */
/* ================================================================== */
/*                                                                    */
/* Source File         : utilship.h                                   */
/* OS/Dependencies     : Yes                                          */
/* End User Modifiable : Not Recommended                              */
/* Description         : Expose utility APIs in generated code.       */
/*                                                                    */
/* ================================================================== */

#ifndef __INCL_UTILSHIP_H__
#define __INCL_UTILSHIP_H__

#ifdef __cplusplus
extern "C" {
#endif

/* for utilconv.h and utilconv2.h */

#define UTC_X60CHR_LEN              20
#define UTC_X60PLN_LEN              4
#define UTC_X60_CCSID_LEN           5
#define UTC_X60_ISOCHARSET_LEN      5

#define UTC_CCSIDLEN                5
#define UTC_CCSIDLEN2               32    /* For use in parsing ccsid.txt entries on Unix */

/*********************************************************************
* When this structure is used in an array, the first element should be
* the default language and the last element should have a blank in the
* 1st byte of szLanguage.
**********************************************************************
* N.B. A copy of this structure is in the RPG program DC@P6455. If this
* is changed, so must the RPG program.********************************
*********************************************************************/

typedef struct _UTC_LANGUAGE
{
   char              szLanguage[UTC_X60PLN_LEN + 1];      /* Language */
   char              chDBCS;                              /* DBCS flag (Y/N) for the language */
   char              chRLT;                               /* Right to left language (Y/N) */
   char              sziSeriesCCSID[UTC_CCSIDLEN + 1];
#if !defined(X_OPERATING_SYSTEM_ISERIES)
   char              szWindowsCCSID[UTC_CCSIDLEN2 + 1];
#else
   char              szWindowsCCSID[UTC_CCSIDLEN + 1];
#endif
   char              szWindowsCodepageEquivalentOnThisOS[UTC_CCSIDLEN + 1]; /* E.g. 943 on iSeries when language is JPN (Win 932) */
   char              szIsoCharset[UTC_X60_ISOCHARSET_LEN + 1];
} UTC_LANGUAGE;

enum UTC_Encoding
{
   UTC_NATIVE,
   UTC_UTF8,
   UTC_UseCodePage,
   UTC_UTF16,
   UTC_UCS2
};

typedef void* (*LALLOCATOR)(
   void* pAnchor,
   size_t uiBytes);

/* *IMPORTANT* pszInbuff may be modified because of trimming, */
/*             some code relies on that to work.              */
extern size_t
UTC_UnicodeToNative(
   void* pAnchor,
   enum UTC_Encoding encoding,
   char* pszInbuff,
   int   iInbuffSize,
   short  fRemoveTrailingBlanks,
   char** ppszOutbuff,
   size_t* puiOutbuffSize,
   short * pfTruncated,
   LALLOCATOR pfnAllocator);

#ifdef X_OPERATING_SYSTEM_ISERIES

/* *IMPORTANT* pszInbuff may be modified because of trimming, */
/*             some code relies on that to work.              */
extern size_t
UTC_NativeToUnicode(
   void* pAnchor,
   enum UTC_Encoding encoding,
   char* pszInbuff,
   int   iInbuffSize,
   short  fRemoveTrailingBlanks,
   char** ppszOutbuff,
   size_t* puiOutbuffSize,
   short * pfTruncated,
   LALLOCATOR pfnAllocator);

extern size_t
UTC_WideCharToUTF8(
   void* pAnchor,
   const char* pwcsInbuff,
   size_t uiInbuffSize,
   char** ppszOutbuff,
   size_t* puiOutbuffSize,
   short * pfError,
   LALLOCATOR pfnAllocator);

extern size_t
UTC_UTF8ToWideChar(
   void* pAnchor,
   const char* pszInbuff,
   size_t uiInbuffSize,
   char** ppwcsOutbuff,
   size_t* puiOutbuffSize,
   short * pfError,
   LALLOCATOR pfnAllocator);

#endif /* def X_O_S_ISERIES */

/* for utilopenssl.h */

struct X_IDS;
struct X_PRO;
struct X_FUN;

typedef int (*UTSSL_ERROR_CALLBACK)( struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     const char * );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !def __INCL_UTILSHIP_H__ */
