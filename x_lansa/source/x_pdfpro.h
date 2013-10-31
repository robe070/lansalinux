/* ================================================================= */
/* === LANSA FOR WINDOWS PLATFORM DEPENDENT FUNCTION PROTOTYPES ==== */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_PDFPRO.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : Platform dependent function prototypes      */
/*                                                                   */
/* ================================================================= */

#ifndef X_PDFPRO
#define X_PDFPRO

/* Used by BIF146 */
#define X_CONN_TYPE_LEN     15

#include "utilship.h"

#ifdef X_OPERATING_SYSTEM_UNIX

typedef  int                X_HFILE;
typedef  X_HFILE           *X_PHFILE;

#endif

#ifdef X_OPERATING_SYSTEM_WIN

typedef  int                X_HFILE;
typedef  X_HFILE           *X_PHFILE;

#endif

#define  X_PDF_MATH_ADD        'A'
#define  X_PDF_MATH_SUBTRACT   'S'
#define  X_PDF_MATH_MULTIPLY   'M'
#define  X_PDF_MATH_DIVIDE     'D'

#define  X_PDF_EXPORT_OBJECT_SILENT_MODE  0x00000001
#define  X_PDF_EXPORT_SYSTEM_DATA_ONLY    0x00000002
#define  X_PDF_EXPORT_PARTITION_DATA_ONLY 0x00000004

struct LANG_MAP
{
   X_VCHAR  vchLang[ X_LANGCODELEN + 1 ];
#if defined(X_OPERATING_SYSTEM_ISERIES)
   X_VCHAR  vchCCSID[ X_CCSIDLEN + 1 ];
#elif defined(X_OPERATING_SYSTEM_WIN)
   X_VCHAR  vchCCSID[ X_CCSIDLEN + 1 ];
#elif defined(X_OPERATING_SYSTEM_UNIX)
   X_VCHAR  vchCCSID[ X_CCSIDLEN_UNIX + 1 ];
#endif
   X_SHORT  sSource;
};

#ifdef __cplusplus
extern "C"
{
#endif

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_PDF_ANCHOR_BLOCK
{
   struct X_IDS   *pX_Ids;
   struct X_PRO   *pX_Pro;
   struct X_FUN   *pX_Fun;

} X_PDF_ANCHOR_BLOCK,
  *PX_PDF_ANCHOR_BLOCK,
  **PPX_PDF_ANCHOR_BLOCK;

#define X_PDF_SET_ANCHOR \
   Anchor.pX_Ids = pX_Ids; \
   Anchor.pX_Pro = pX_Pro; \
   Anchor.pX_Fun = pX_Fun;

#define X_PDF_CRACK_ANCHOR \
   struct X_IDS * pX_Ids = pAnchor->pX_Ids; \
   struct X_PRO * pX_Pro = pAnchor->pX_Pro; \
   struct X_FUN * pX_Fun = pAnchor->pX_Fun;

/* ================================================================= */
/*                      X_COM_ANCHOR                                 */
/* ================================================================= */
/* For use in handling generic comms interface between x_com helper  */
/* functions.                                                        */
/* Not used as a record to send to server.                           */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef struct _X_COM_ANCHOR
{
   struct      X_CONNECT_COMPUTER *pConnect;
   X_CHAR      chRecordType;
   X_LONG      lRecordLength;
   X_PVCHAR    pRecord;
   X_VCHAR     vchAppName[X_APPL_NAME_LEN + 1];
}    X_COM_ANCHOR,
 *  PX_COM_ANCHOR,
 **PPX_COM_ANCHOR;


/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_PDF_MSIVERSION_DETAIL
{
   X_VCHAR              vchUpgradeCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchProductCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchPackageCode[ X_MSI_GUID_LEN + 1];      // This is the PatchCode for Patches
   X_VCHAR              vchVersion[ X_MSI_VERSION_LEN + 1];
   X_VCHAR              vchLanguage[ X_MSI_LOCALE_LEN + 1];     // This is not set specifically for a Patch, its the MSIs value
   X_INT32              dwContext;                                // See MSIINSTALLCONTEXT for possible values

} X_PDF_MSIVERSION_DETAIL,
  *PX_PDF_MSIVERSION_DETAIL,
  **PPX_PDF_MSIVERSION_DETAIL;

typedef struct _X_PDF_MSIVERSION_PROPERTY
{
   const X_UTF16_VCHAR        * pwchPropertyIdentifier;
   const X_UTF16_VCHAR        * pwchPropertyValue;
   X_PVCHAR                     pvchStatus;
   X_BOOL                       fPatchIdentifier;
} X_PDF_MSIVERSION_PROPERTY,
  *PX_PDF_MSIVERSION_PROPERTY,
  **PPX_PDF_MSIVERSION_PROPERTY;

/* -------------------------------------------------------------- */
/* Call back used by X_PDF routines to enumerate patch details    */
/* -------------------------------------------------------------- */

typedef X_INT
   FN_MSIVERSIONDETAILS_CALLBACK       (
      PX_PDF_ANCHOR_BLOCK                 pPDFAnchor,
      PX_COM_ANCHOR                       pComAnchor, 
      PX_PDF_MSIVERSION_DETAIL            pPatchDetail );

typedef FN_MSIVERSIONDETAILS_CALLBACK
   *PFN_MSIVERSIONDETAILS_CALLBACK;

typedef FN_MSIVERSIONDETAILS_CALLBACK
   **PPFN_MSIVERSIONDETAILS_CALLBACK;

// -----------------------------------------------------------------

typedef X_INT
   FN_MSIPROPERTY_CALLBACK       (
      PX_PDF_ANCHOR_BLOCK                 pPDFAnchor, 
      X_PVOID                             pCallbackAnchor,
      PX_PDF_MSIVERSION_PROPERTY          pMSIProperty );

typedef FN_MSIPROPERTY_CALLBACK
   *PFN_MSIPROPERTY_CALLBACK;

typedef FN_MSIPROPERTY_CALLBACK
   **PPFN_MSIPROPERTY_CALLBACK;

// -----------------------------------------------------------------

/* ================================================================= */
/*  X_OIDPDF.C functions                                             */
/* ================================================================= */

X_LONG_FUNCTION X_PDF_Get_Build_Number( void );

/* ================================================================= */
/*  X_PDF1.C functions                                               */
/* ================================================================= */

X_VOID_FUNCTION  X_PDF_Math(struct X_IDS *,
                           struct X_PRO *,
                           struct X_FUN *,
                           X_CHAR,
                           struct X_FLD[],
                           X_SHORT,
                           struct X_FLD[],
                           X_SHORT,
                           struct X_FLD[],
                           X_SHORT);

X_YES_NO_FUNCTION X_PDF_Valid_Printer (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PVCHAR);

X_VOID_FUNCTION  X_PDF_Wait(struct X_IDS *,
                            struct X_PRO *,
                            struct X_FUN *,
                            X_ULONG);

X_VOID_FUNCTION X_Leak_Report( X_BOOL fResetTracking, X_PCCHAR pszFileName);

#ifdef X_OPERATING_SYSTEM_WIN
X_LONG X_FUNTYPE X_Leak_RegOpenKeyExEncoded(struct X_IDS *pX_Ids,
                          HKEY          hKey,
                          char        * lpSubKey,
                          DWORD         ulOptions,
                          REGSAM        samDesired,
                          PHKEY         phkResult,
                          const char *  pvchCFile,
                          unsigned long ulCLine);
#endif

/* ================================================================= */
/*  X_PDF2.C functions                                               */
/* ================================================================= */

X_VOID_FUNCTION X_PDF_Get_Date(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_SHORT,
                               X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_Julian_Date(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      X_SHORT,
                                      X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_Time(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_SHORT,
                               X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_Time2(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_BOOL);

X_VOID_FUNCTION X_PDF_Get_Time_Stamp(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_SHORT,
                                     X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_Job_Name(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   X_SHORT,
                                   X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_User_Name(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    X_SHORT,
                                    X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_Job_Nbr(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_SHORT,
                                  X_PFCHAR);

X_VOID_FUNCTION X_PDF_Get_Job_CPU_Seconds( struct X_IDS*,
                                           struct X_PRO*,
                                           struct X_FUN*,
                                           X_SHORT,
                                           X_PFCHAR,
                                           X_DOUBLE* );

X_VOID_FUNCTION X_PDF_Get_Job_100_Nano_Secs( struct X_IDS  *  pX_Ids,
                                           struct X_PRO  *  pX_Pro,
                                           struct X_FUN  *  pX_Fun,
                                           X_SHORT          sLfch100NanoSeconds,
                                           X_PFCHAR         pfch100NanoSeconds,
                                           X_DOUBLE      *  pd100NanoSeconds );

X_VOID_FUNCTION X_PDF_Get_RRNO(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_FLD *,
                               X_SHORT,
                               X_PVCHAR);

X_VOID_FUNCTION X_PDF_Get_RRNO_2(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_FLD *,
                                 X_SHORT,
                                 X_PVCHAR,
                                 X_CHAR);

X_VOID_FUNCTION X_PDF_Get_RRNO_3(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_FLD *,
                                 X_SHORT,
                                 X_PVCHAR,
                                 X_CHAR,
                                 struct X_DBM *);

X_VOID_FUNCTION X_PDF_DestroyDataAreasHandles (struct X_IDS * pX_Ids);

X_BOOL_FUNCTION X_PDF_AccessEmulatedDataArea( struct    X_IDS * pX_Ids,
                                              struct    X_PRO * pX_Pro,
                                              struct    X_FUN * pX_Fun,
                                              X_BOOL            fReadDataArea,
                                              X_BOOL            fLeaveOpenandLocked,
                                              X_PVCHAR          pvchDataAreaName,
                                              X_ULONG           ulDataAreaLength,
                                              X_PVCHAR          pvchDataAreaValue,
                                              X_PULONG          pulDataAreaLengthRead );

X_BOOL_FUNCTION X_PDF_OpenExclusiveFile( struct    X_IDS * pX_Ids,
                                         struct    X_PRO * pX_Pro,
                                         struct    X_FUN * pX_Fun,
                                         X_HFILE         * phFile,
                                         X_PCCHAR          pvchPath,
                                         X_PCCHAR          pvchFileName,
                                         X_PCCHAR          pvchFileSuffix );

X_BOOL_FUNCTION X_PDF_CloseExclusiveFile ( struct   X_IDS * pX_Ids,
                                           struct   X_PRO * pX_Pro,
                                           struct   X_FUN * pX_Fun,
                                           X_HFILE        * phFile  );

X_BOOL_FUNCTION X_PDF_ReWriteExclusiveFile( struct   X_IDS * pX_Ids,
                                            struct   X_PRO * pX_Pro,
                                            struct   X_FUN * pX_Fun,
                                            X_HFILE          hFile,
                                            X_ULONG          ulDataLength,
                                            X_PVCHAR         pvchData  );

X_BOOL_FUNCTION X_PDF_ReadExclusiveFile( struct   X_IDS * pX_Ids,
                                         struct   X_PRO * pX_Pro,
                                         struct   X_FUN * pX_Fun,
                                         X_HFILE          hFile,
                                         X_ULONG          ulDataLength,
                                         X_PVCHAR         pvchData,
                                         X_PULONG         pulBytesRead );

X_VOID_FUNCTION X_PDF_Get_File_Time_Size(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PVCHAR pvchPath,
                                         X_PUSHORT pusTime,
                                         X_PUSHORT pusDate,
                                         X_PLONG  plBytes);

X_VOID_FUNCTION X_PDF_Get_Timezone(struct X_IDS *pX_Ids,
                                   struct X_PRO *pX_Pro,
                                   struct X_FUN *pX_Fun,
                                   X_PVCHAR pvchZone);

X_ULONG_FUNCTION X_PDF_Get_Process_ID(struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun);

X_BOOL_FUNCTION X_PDF_Get_OS_Username(struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun,
                                      X_PVCHAR      pvchBuff);

X_BOOL_FUNCTION X_PDF_Set_File_DateTime( struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PVCHAR pvchPath,
                                         X_USHORT usDate,
                                         X_USHORT usTime );

X_BOOL_FUNCTION X_PDF_Set_File_DateTimeEx( struct X_IDS * pX_Ids,
                                           struct X_PRO * pX_Pro,
                                           struct X_FUN * pX_Fun,
                                           X_PVCHAR pvchPath,
                                           X_INT iYear,
                                           X_INT iMonth,
                                           X_INT iDay,
                                           X_INT iHour,
                                           X_INT iMinute,
                                           X_INT iSecond,
                                           X_INT iMillisecond );

X_BOOL_FUNCTION X_PDF_MakePath( struct X_IDS *  pX_Ids,
                                struct X_PRO *  pX_Pro,
                                struct X_FUN *  pX_Fun,
                                X_PVCHAR        pvchPath );

#ifdef X_OPERATING_SYSTEM_ISERIES
X_INT_FUNCTION X_PDF_GetSBCSJobCCSID( struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun );

X_BOOL_FUNCTION X_PDF_GetWinNTCCSID( struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     X_PVCHAR      pvchCodepage,
                                     X_PVCHAR      pvchCCSID );
#endif

X_BOOL_FUNCTION X_PDF_GetJobCodepage( struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun,
                                      X_PVCHAR      pvchCodepage,
                                      X_USHORT      usLen );

X_VOID_FUNCTION X_PDF_SetThreadName( X_LONG dwThreadID, X_PCCHAR szThreadName );

/* ================================================================= */
/*  X_PDF3.C functions                                               */
/* ================================================================= */

X_VOID_FUNCTION X_PDF_System_Command(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_SHORT,
                                     X_PVCHAR,
                                     X_PLONG);

X_VOID_FUNCTION X_PDF_DumpAllocMemList( struct X_IDS *,
                                        X_PVCHAR,
                                        X_BOOL,
                                        X_BOOL );


/* Memory allocation routines using default LANSA Heap      */
/* These DO NOT use the default Process Heap (Windows only) */

X_PVOID_FUNCTION XX_PDF_Allocate_Memory( struct X_IDS      * pX_Ids,
                                         struct X_PRO      * pX_Pro,
                                         struct X_FUN      * pX_Fun,
                                         X_SIZE              lBytes,
                                         X_PCCHAR            pszFile,
                                         X_SHORT             sLine );

X_PVOID_FUNCTION XX_PDF_ReAllocate_Memory( struct X_IDS    * pX_Ids,
                                           struct X_PRO    * pX_Pro,
                                           struct X_FUN    * pX_Fun,
                                           X_PVOID           pMemory,
                                           X_SIZE            lBytes,
                                           X_PCCHAR          pszFile,
                                           X_SHORT           sLine );

X_VOID_FUNCTION X_PDF_RetrieveComputerName(  struct X_IDS   * pX_Ids,
                                             struct X_PRO   * pX_Pro,
                                             struct X_FUN   * pX_Fun,
                                             X_PVCHAR       pszComputerName);

X_VOID_FUNCTION XX_PDF_Free_Memory( struct X_IDS      * pX_Ids,
                                    struct X_PRO      * pX_Pro,
                                    struct X_FUN      * pX_Fun,
                                    X_PVOID             pMemory,
                                    X_PCCHAR            pszFile,
                                    X_SHORT             sLine );

X_PVOID_FUNCTION XX_PDF_Allocate_Array( struct X_IDS      * pX_Ids,
                                        struct X_PRO      * pX_Pro,
                                        struct X_FUN      * pX_Fun,
                                        X_PVOID             pvCurrentAllocation,
                                        X_SIZE              lItemLength,
                                        X_SIZE              lCurrentItems,
                                        X_SIZE              lAllocateNewBlocks,
                                        X_PCCHAR            pszFile,
                                        X_SHORT             sLine );

X_VOID_FUNCTION XX_PDF_Free_Array( struct X_IDS      * pX_Ids,
                                   struct X_PRO      * pX_Pro,
                                   struct X_FUN      * pX_Fun,
                                   X_PVOID           * ppvCurrentAllocation,
                                   X_PCCHAR            pszFile,
                                   X_SHORT             sLine );

/* New private Heap-based allocation routines. */

X_PVOID_FUNCTION XX_PDF_Allocate_Memory_Heap( struct X_IDS      * pX_Ids,
                                              struct X_PRO      * pX_Pro,
                                              struct X_FUN      * pX_Fun,
                                              X_SIZE              lBytes,
                                              X_PCCHAR            pszFile,
                                              X_SHORT             sLine,
                                              X_PHEAP             pHeap);

#ifdef X_OPERATING_SYSTEM_WIN
X_VOID_FUNCTION XX_PDF_Check_Memory_Heap( struct X_IDS    * pX_Ids,
                                          struct X_PRO    * pX_Pro,
                                          struct X_FUN    * pX_Fun,
                                          X_PVOID           pMemory,
                                          X_PCCHAR          pszFile,
                                          X_SHORT           sLine,
                                          X_PHEAP           pHeap);
#endif

X_PVOID_FUNCTION XX_PDF_ReAllocate_Memory_Heap( struct X_IDS    * pX_Ids,
                                                struct X_PRO    * pX_Pro,
                                                struct X_FUN    * pX_Fun,
                                                X_PVOID           pMemory,
                                                X_SIZE            lBytes,
                                                X_PCCHAR          pszFile,
                                                X_SHORT           sLine,
                                                X_PHEAP           pHeap);
X_VOID_FUNCTION XX_PDF_Free_Memory_Heap( struct X_IDS      * pX_Ids,
                                         struct X_PRO      * pX_Pro,
                                         struct X_FUN      * pX_Fun,
                                         X_PVOID             pMemory,
                                         X_PCCHAR            pszFile,
                                         X_SHORT             sLine,
                                         X_PHEAP             pHeap);

X_PVOID_FUNCTION XX_PDF_Allocate_Array_Heap( struct X_IDS      * pX_Ids,
                                             struct X_PRO      * pX_Pro,
                                             struct X_FUN      * pX_Fun,
                                             X_PVOID             pvCurrentAllocation,
                                             X_SIZE              lItemLength,
                                             X_SIZE              lCurrentItems,
                                             X_SIZE              lAllocateNewBlocks,
                                             X_PCCHAR            pszFile,
                                             X_SHORT             sLine,
                                             X_PHEAP             pHeap);

X_VOID_FUNCTION XX_PDF_Free_Array_Heap( struct X_IDS      * pX_Ids,
                                        struct X_PRO      * pX_Pro,
                                        struct X_FUN      * pX_Fun,
                                        X_PVOID           * ppvCurrentAllocation,
                                        X_PCCHAR            pszFile,
                                        X_SHORT             sLine,
                                        X_PHEAP             pHeap);

/* Memory debug macros that redefine normal access */

#define X_PDF_Allocate_Memory(_pX_Ids, _pX_Pro, _pX_Fun, _lBytes) \
   XX_PDF_Allocate_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _lBytes, \
      __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE)

#define X_PDF_Allocate_Memory_Default_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _lBytes) \
   XX_PDF_Allocate_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _lBytes, \
      __FILE__, ((X_SHORT)__LINE__), pX_NULL)

#define X_PDF_Allocate_Memory_NOCHECK(_PTR, _CASTAS, _pX_Ids, _pX_Pro, _pX_Fun, _lBytes) \
   { \
      X_BOOL fSaveCheckMemory  = _pX_Ids->fCheckMemory; \
      X_BOOL fSaveReportMemory = _pX_Ids->fReportMemory; \
      X_CHAR chValidateHeap    = _pX_Ids->chValidateHeap; \
      _pX_Ids->fCheckMemory  = FALSE; \
      _pX_Ids->fReportMemory = FALSE; \
      _pX_Ids->chValidateHeap = NO; \
      _PTR = _CASTAS XX_PDF_Allocate_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _lBytes, \
                        __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE); \
      _pX_Ids->fCheckMemory  = fSaveCheckMemory; \
      _pX_Ids->fReportMemory = fSaveReportMemory; \
      _pX_Ids->chValidateHeap = chValidateHeap; \
   }

#ifndef X_OPERATING_SYSTEM_WIN
#define X_PDF_Check_Memory_Default_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory)
#else
#define X_PDF_Check_Memory_Default_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory) \
   if ( pX_Ids->chValidateHeap == X_HEAP_GUARD ) \
      XX_PDF_Check_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, \
      __FILE__, ((X_SHORT)__LINE__), pX_NULL)
#endif
#define X_PDF_ReAllocate_Memory(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, _lBytes) \
   XX_PDF_ReAllocate_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, _lBytes, \
      __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE)

#define X_PDF_ReAllocate_Memory_Default_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, _lBytes) \
   XX_PDF_ReAllocate_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, _lBytes, \
      __FILE__, ((X_SHORT)__LINE__), pX_NULL)

#define X_PDF_Free_Memory(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory) \
   XX_PDF_Free_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, \
      __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE)

#define X_PDF_Free_Memory_Default_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory) \
   XX_PDF_Free_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, \
      __FILE__, ((X_SHORT)__LINE__), pX_NULL)

#define X_PDF_Free_Memory_NOCHECK(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory) \
{ \
   X_BOOL fSaveCheckMemory  = _pX_Ids->fCheckMemory; \
   X_BOOL fSaveReportMemory = _pX_Ids->fReportMemory; \
   X_CHAR chValidateHeap    = _pX_Ids->chValidateHeap; \
   _pX_Ids->fCheckMemory  = FALSE; \
   _pX_Ids->fReportMemory = FALSE; \
   _pX_Ids->chValidateHeap = NO; \
   XX_PDF_Free_Memory_Heap(_pX_Ids, _pX_Pro, _pX_Fun, _pMemory, \
      __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE); \
   _pX_Ids->fCheckMemory  = fSaveCheckMemory; \
   _pX_Ids->fReportMemory = fSaveReportMemory; \
   _pX_Ids->chValidateHeap = chValidateHeap; \
}

#define X_PDF_Allocate_Array(_A, _B, _C, _D, _E, _F, _G) \
   XX_PDF_Allocate_Array_Heap(_A, _B, _C, _D, _E, _F, _G, \
      __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE)

#define X_PDF_Free_Array(_A, _B, _C, _D) \
   XX_PDF_Free_Array_Heap(_A, _B, _C, _D, \
      __FILE__, ((X_SHORT)__LINE__), X_PMODULE_HEAP_IN_USE)

#ifdef X_OPERATING_SYSTEM_ISERIES
X_VOID_FUNCTION X_PDF_Exec_OS400(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 X_SHORT,
                                 X_PFCHAR,
                                 X_PSHORT);
#endif

/* ================================================================= */
/*  X_PDF4.C functions                                               */
/* ================================================================= */

X_BOOL_FUNCTION X_PDF_Execute_Process
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_SHORT,
                               struct X_PARM *);

X_BOOL_FUNCTION X_PDF_Execute_Function
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_SHORT,
                               struct X_PARM []);

X_VOID_FUNCTION X_PDF_Load_Component ( struct X_IDS   * pX_Ids,
                                       struct X_PRO   * pX_Pro,
                                       struct X_FUN   * pX_Fun,
                                       X_PVCHAR         pvchComponentClass,
                                       X_MODULEHANDLE * phmodDLL,
                                       X_PVOID        * ppfnRDMLXFunction,
                                       X_CHAR           chDLLType );


X_VOID_FUNCTION X_PDF_Unload_Component ( struct X_IDS   * pX_Ids,
                                         struct X_PRO   * pX_Pro,
                                         struct X_FUN   * pX_Fun,
                                         X_PVCHAR         pvchComponentClass,
                                         X_MODULEHANDLE * phmodDLL);

X_VOID_FUNCTION X_PDF_Execute_User_Function
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_SHORT,
                               struct X_PARM []);

X_VOID_FUNCTION X_PDF_Execute_IO_Module
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_DBM *,
                               X_PCCHAR);

X_VOID_FUNCTION X_PDF_Get_OS2_Names
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_CHAR,
                               X_PCCHAR,
                               X_SHORT,
                               X_SHORT,
                               X_PVCHAR,
                               X_PVCHAR);

X_VOID_FUNCTION X_PDF_Trunc_Process_Name( struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          X_PCCHAR,
                                          X_PVCHAR    );

X_VOID_FUNCTION X_PDF_Put_Temp_File
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_LONG,
                               X_PFCHAR,
                               X_SHORT,
                               X_PVCHAR);

X_VOID_FUNCTION X_PDF_Put_Temp_File_Suffix
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_LONG,
                               X_PFCHAR,
                               X_SHORT,
                               X_PVCHAR,
                               X_PVCHAR);

X_VOID_FUNCTION X_PDF_Get_Temp_File
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_CHAR,
                               X_LONG,
                               X_PFCHAR,
                               X_PLONG);

X_BOOL_FUNCTION X_PDF_RSA_Seal_Envelope
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_LONG,
                               X_PFCHAR,
                               X_SHORT,
                               X_PVCHAR,
                               X_PVCHAR,
                               void *,        // Use void to avoid dragging in OpenSSL
                               X_PVCHAR );

X_BOOL_FUNCTION X_PDF_RSA_Open_Envelope
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_CHAR,
                               X_LONG,
                               X_PFCHAR,
                               X_PLONG,
                               void *,
                               X_PVCHAR );  // Use void to avoid dragging in OpenSSL

X_INT_FUNCTION X_PDF_TempFileName(  struct X_IDS *,
                                    char * ,
                                    const char * ,
                                    const char * ,
                                    const char * );

X_VOID_FUNCTION X_PDF_Get_Unique_Filename(struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          X_PVCHAR,
                                          size_t,
                                          X_PCCHAR);

X_VOID_FUNCTION X_PDF_Open_File( struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 X_PHFILE,
                                 X_PCCHAR );

X_INT_FUNCTION X_PDF_open( struct X_IDS *pX_Ids,
                           struct X_PRO *pX_Pro,
                           struct X_FUN *pX_Fun,
                           X_PCCHAR pszFileName,
                           X_FILE_KIND    kind,
                           int oflag,
                           int pmode );

X_INT_FUNCTION X_PDF_open_Lock( struct X_IDS *  pX_Ids,
                                struct X_PRO *  pX_Pro,
                                struct X_FUN *  pX_Fun,
                                X_PCCHAR        pszFileName,
                                X_FILE_KIND     kind,
                                int             oflag,
                                int             pmode,
                                X_BOOL          fLock );

X_INT_FUNCTION X_PDF_close( X_INT    iFile );

X_INT_FUNCTION X_PDF_fgets( struct X_IDS   *pX_Ids,
                            struct X_PRO   *pX_Pro,
                            struct X_FUN   *pX_Fun,
                            X_PVCHAR       pvchBuffer,
                            X_INT          iBufferLength,
                            X_INT          iFile );

X_FILEBUFFERING_FUNCTION X_PDF_open_Buffering( struct X_IDS   *pX_Ids,
                                               struct X_PRO   *pX_Pro,
                                               struct X_FUN   *pX_Fun,
                                               X_PCCHAR       pszFileName,
                                               X_INT          iBufFactor,
                                               X_FILE_KIND    kind,
                                               int            oflag,
                                               int            pmode );

X_INT_FUNCTION X_PDF_fgets_Buffering( struct X_IDS      *pX_Ids,
                                      struct X_PRO      *pX_Pro,
                                      struct X_FUN      *pX_Fun,
                                      X_PVCHAR          pvchBuffer,
                                      X_INT             iBufferLength,
                                      X_FILEBUFFERING   *pX_File);

X_INT_FUNCTION X_PDF_close_Buffering( struct X_IDS      *pX_Ids,
                                      struct X_PRO      *pX_Pro,
                                      struct X_FUN      *pX_Fun,
                                      X_FILEBUFFERING   *pX_File );

X_INT_FUNCTION X_PDF_fputs( struct X_IDS   *pX_Ids,
                            struct X_PRO   *pX_Pro,
                            struct X_FUN   *pX_Fun,
                            X_PVCHAR       pvchBuffer,
                            X_INT          iFile );

X_VOID_FUNCTION X_PDF_Write_File( struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_HFILE, X_PVCHAR );

X_VOID_FUNCTION X_PDF_Close_File( struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          X_HFILE );

X_PFILE_HANDLE_FUNCTION X_PDF_OpenFlatFile( struct X_IDS    *pX_Ids,
                                            X_PCCHAR        pszFileName,
                                            X_FILE_USAGE    iUsage,
                                            X_PFILE_OPTIONS pOptions );

X_BOOL_FUNCTION X_PDF_CloseFlatFile( struct X_IDS     *pX_Ids,
                                     X_PFILE_HANDLE   pFile );

X_BOOL_FUNCTION X_PDF_PositionFlatFile( struct X_IDS        *pX_Ids,
                                        X_PFILE_HANDLE      pFile,
                                        X_LONG              lOffset,
                                        X_FILE_POS_ORIGIN   iOrigin );

X_BOOL_FUNCTION X_PDF_GetFlatFilePosition( struct X_IDS     *pX_Ids,
                                           X_PFILE_HANDLE   pFile,
                                           X_PULONG         pulPosition );

X_BOOL_FUNCTION X_PDF_ReadFlatFile( struct X_IDS     *pX_Ids,
                                    X_PVOID          pBuffer,
                                    X_ULONG          ulSize,
                                    X_ULONG          ulCount,
                                    X_PULONG         pulRetCount,
                                    X_PBOOL          pfEOF,
                                    X_PFILE_HANDLE   pFile );

X_BOOL_FUNCTION X_PDF_WriteFlatFile( struct X_IDS     *pX_Ids,
                                     X_PVOID          pBuffer,
                                     X_ULONG          ulSize,
                                     X_ULONG          ulCount,
                                     X_PFILE_HANDLE   pFile );

X_BOOL_FUNCTION X_PDF_FlushFlatFile( struct X_IDS     *pX_Ids,
                                     X_PFILE_HANDLE   pFile );

X_BOOL_FUNCTION X_PDF_GetFlatFileSize( struct X_IDS     *pX_Ids,
                                       X_PFILE_HANDLE   pFile,
                                       X_PULONG         pulFileSize );

X_BOOL_FUNCTION X_PDF_DeleteFlatFile( struct X_IDS   *pX_Ids,
                                      X_PCCHAR       pszFileName );

X_LONG_FUNCTION X_PDF_GetFlatFileError( struct X_IDS   *pX_Ids );

X_VOID_FUNCTION X_PDF_ResetFlatFileError( struct X_IDS   *pX_Ids );

X_PCHAR_FUNCTION X_PDF_GetFlatFileErrorMsg( struct X_IDS   *pX_Ids );

X_LONG_FUNCTION X_PDF_GetOpenFlatFileCount( struct X_IDS   *pX_Ids );

X_ULONG_FUNCTION X_PDF_MakeFileList( struct X_IDS     *pX_Ids,
   struct X_PRO     *pX_Pro,
   struct X_FUN     *pX_Fun,
   X_PVCHAR         pvchPath,
   X_PVCHAR         pvchName,
   X_PVCHAR         pvchSuffix,
   X_FILE_LIST    **ppList,
   X_PULONG         pulAllocUnits);

X_VOID_FUNCTION X_PDF_Load_ASV_DLL( struct X_IDS * pX_Ids );
X_VOID_FUNCTION X_PDF_UnLoad_ASV_DLL( struct X_IDS * pX_Ids );

X_VOID_FUNCTION X_PDF_Load_DBMS_DLL (struct X_IDS *, struct X_CONNECT_DATABASE *);
X_VOID_FUNCTION X_PDF_UnLoad_DBMS_DLL (struct X_IDS *pX_Ids, enum DBMSCategoryIds sDBMSCategory );
X_VOID_FUNCTION X_PDF_UnLoad_All_DBMS_DLL (struct X_IDS * );

X_VOID_FUNCTION X_PDF_Load_COMP_DLL (struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_UnLoad_COMP_DLL (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Load_LSV_DLL (struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_UnLoad_LSV_DLL (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Load_SSV_DLL (struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_UnLoad_SSV_DLL (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Load_UIM_DLL (struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_UnLoad_UIM_DLL (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Switch_To_Web_UIM_DLL(
   struct X_IDS *pX_Ids,
   struct X_WEB_INFO *pUseThisWebInfo,
   X_MODULEHANDLE *phOldUIMDLL,
   PFNUIMVOIDFUNCTION *ppfnOldManager );

X_VOID_FUNCTION X_PDF_Restore_Original_UIM_DLL(
   struct X_IDS *pX_Ids,
   X_CHAR chOrginalExecState,
   X_MODULEHANDLE hOldUIMDLL,
   PFNUIMVOIDFUNCTION pfnOldManager );

X_VOID_FUNCTION X_PDF_Execute_User_BIF (struct X_IDS * pX_Ids,
                                        struct X_PRO * pX_Pro,
                                        struct X_FUN * pX_Fun,
                                        struct X_BIF * pX_Bif,
                                        X_CHAR         chStayActive,
                                        struct X_FLD   X_Fld[],
                                        struct X_LIST  X_List[],
                                        X_SHORT        sInCount,
                                        X_SHORT        sInVec[],
                                        X_SHORT        sRetCount,
                                        X_SHORT        sRetVec[]);

X_VOID_FUNCTION X_PDF_Free_User_BIFs (struct X_IDS * pX_Ids);

X_APIRET X_FUNTYPE X_DosLoadModule (struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_CHAR,
                                    X_PCCHAR,
                                    X_PCCHAR,
                                    X_MODULEHANDLE *);

X_APIRET X_FUNTYPE X_DosLoadModule_2 (struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_CHAR,
                                    X_PCCHAR,
                                    X_PCCHAR,
                                    X_MODULEHANDLE *,
                                    X_BOOL );

X_APIRET X_FUNTYPE X_DosQueryProcAddr (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_MODULEHANDLE,
                                       X_PCCHAR,
                                       X_PFN * );

X_APIRET X_FUNTYPE X_DosFreeModule (struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_MODULEHANDLE,
                                    X_YES_NO);

X_APIRET X_FUNTYPE X_DosFreeModuleACTGRP (struct X_IDS   *pX_Ids,
                                    struct X_PRO   *pX_Pro,
                                    struct X_FUN   *pX_Fun,
                                    X_MODULEHANDLE hmodDLL );

X_VOID_FUNCTION X_PDF_Get_Jobq_Path (struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     X_PVCHAR      pvchJobq,
                                     X_PVCHAR      pvchPath,
                                     X_CHAR        chSearchType);
#ifdef X_OPEN_SSL

X_BOOL_FUNCTION X_PDF_InitialiseOpenSSL( struct X_IDS *pX_Ids );
X_BOOL_FUNCTION X_PDF_UninitialiseOpenSSL( struct X_IDS *pX_Ids );
X_BOOL_FUNCTION X_PDF_RSA_Read_Public_Key( struct X_IDS *pX_Ids,
                                           void **rsa,
                                           X_PVCHAR pvchFilePath,
                                           UTSSL_ERROR_CALLBACK pfnErrorCallback );

#endif

X_VOID_FUNCTION X_PDF_ShutDown_Processes (struct X_IDS *pX_Ids);

X_VOID_FUNCTION X_PDF_ShutDown_Functions (struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro);

X_VOID_FUNCTION X_PDF_ShutDown_Components(struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro);

X_VOID_FUNCTION X_MakeStandardBeep(struct X_IDS *pX_Ids);

X_PFN X_FUNTYPE  X_PDF_Query_Proc_Address(struct X_IDS    *,
                                          struct X_PRO    *,
                                          struct X_FUN    *,
                                          X_MODULEHANDLE   ,
                                          X_PVCHAR         );

X_APIRET X_FUNTYPE X_PDF_Load_Partition_Module(struct X_IDS *,
                                            struct X_PRO    *,
                                            struct X_FUN    *,
                                            X_PVCHAR         ,
                                            X_MODULEHANDLE  *);

X_APIRET X_FUNTYPE X_PDF_Load_Package_Module(struct X_IDS   *,
                                            struct X_PRO    *,
                                            struct X_FUN    *,
                                            X_PVCHAR         ,
                                            X_PVCHAR         ,
                                            X_PVCHAR         ,
                                            X_MODULEHANDLE  *);

X_VOID_FUNCTION X_PDF_Unload_Module(  struct X_IDS    *,
                                      struct X_PRO    *,
                                      struct X_FUN    *,
                                      X_MODULEHANDLE   );

X_BOOL_FUNCTION X_PDF_GetFirstPkgStatus( struct X_IDS *pX_Ids,
                                         X_PVCHAR      pvchPkgsPath,
                                         X_PVCHAR      pvchAppl,
                                         struct X_PKG_STATUS *pPkgSts,
                                         X_CHAR        chFilterType,
                                         X_PVCHAR      pvchFilter,
                                         X_PVCHAR      pvchAdditionalInfo,
                                         X_SHORT       sAdditionalInfo );

X_LONG_FUNCTION X_PDF_CreateLockFile(struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     X_PVCHAR pvchPath,
                                     X_PVCHAR pvchFile);

X_BOOL_FUNCTION X_PDF_LockFileExists(struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     X_PVCHAR pvchPath,
                                     X_PVCHAR pvchFile);

X_VOID_FUNCTION X_PDF_RemoveLockFile(struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     X_PVCHAR pvchPath,
                                     X_PVCHAR pvchFile,
                                     X_LONG lHandle);

#if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_WIN)
X_VOID_FUNCTION X_PDF_GetFirstFileName(struct X_IDS  *pX_Ids,
                                       X_PCCHAR      pvchPath,
                                       X_PCCHAR      pvchPattern,
                                       X_CHAR        chType,
                                       X_PVCHAR      pvchFileName);

X_VOID_FUNCTION X_PDF_GetFirstFileNameR(struct X_IDS  *pX_Ids,
                                        X_PVOID       pHandle,
                                        X_PCCHAR      pvchPath,
                                        X_PCCHAR      pvchPattern,
                                        X_CHAR        chType,
                                        X_PVCHAR      pvchFileName);

X_VOID_FUNCTION X_PDF_GetNextFileName(struct X_IDS  *pX_Ids,
                                      X_PCCHAR      pvchPath,
                                      X_PCCHAR      pvchPattern,
                                      X_CHAR        chType,
                                      X_PVCHAR      pvchFileName);

X_VOID_FUNCTION X_PDF_GetNextFileNameR(struct X_IDS  *pX_Ids,
                                       X_PVOID       pHandle,
                                       X_PCCHAR      pvchPath,
                                       X_PCCHAR      pvchPattern,
                                       X_CHAR        chType,
                                       X_PVCHAR      pvchFileName);

X_VOID_FUNCTION X_PDF_CloseFileList(void);
X_VOID_FUNCTION X_PDF_CloseFileListR(X_PVOID pHandle);
#endif

X_VOID_FUNCTION X_PDF_Load_Zip_DLL (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_SetGlobalDLLPath( struct X_IDS *pX_Ids,
                                        X_PVCHAR      pvchFullDLLPath );

X_VOID_FUNCTION X_PDF_ReplaceSpecialChars( struct X_IDS *pX_Ids,
                                           X_PVCHAR      pvchName );

X_BOOL_FUNCTION X_PDF_CopyFile( struct X_IDS *  pX_Ids,
                                struct X_PRO *  pX_Pro,
                                struct X_FUN *  pX_Fun,
                                X_PVCHAR        pvchExisting,
                                X_PVCHAR        pvchNew );

#ifdef X_OPERATING_SYSTEM_ISERIES
X_BOOL_FUNCTION X_PDF_CopyFileSetCCSID( struct X_IDS *  pX_Ids,
                                        struct X_PRO *  pX_Pro,
                                        struct X_FUN *  pX_Fun,
                                        X_PVCHAR        pvchExisting,
                                        X_PVCHAR        pvchNew,
                                        X_PVCHAR        pvchTargetCCSID );
#endif
 

X_BOOL_FUNCTION X_PDF_CopyDirectory( struct X_IDS *  pX_Ids,
                                     struct X_PRO *  pX_Pro,
                                     struct X_FUN *  pX_Fun,
                                     X_PVCHAR        pvchSourceDir,
                                     X_PVCHAR        pvchTargetDir );


X_BOOL_FUNCTION X_PDF_fCheckDirectory(struct X_IDS    * pX_Ids,
                                       X_PVCHAR pvchDirectory);
X_BOOL_FUNCTION X_PDF_DeleteDirectory(   struct X_IDS *pX_Ids,X_PVCHAR pvchRootPath, X_BOOL fFatalError);

X_BOOL_FUNCTION X_PDF_IsValidMapping( struct X_IDS          *  pX_Ids,
                                      struct X_PRO          *  pX_Pro,
                                      struct X_FUN          *  pX_Fun,
                                      X_DATA_FILE_HEADER_EX *  pHeader,
                                      X_DATA_FILE_COLUMN_EX *  pColumnFrom,
                                      X_DATA_FILE_COLUMN_EX *  pColumnTo );

X_BOOL_FUNCTION X_PDF_ConvertMappedData( struct X_IDS          *  pX_Ids,
                                         struct X_PRO          *  pX_Pro,
                                         struct X_FUN          *  pX_Fun,
                                         X_DATA_FILE_HEADER_EX *  pHeader,
                                         X_DATA_MAPPING        *  pMapping,
                                         X_SHORT                  sMappings );

X_BOOL_FUNCTION X_PDF_IsMappingPossible( struct X_IDS          *  pX_Ids,
                                         struct X_PRO          *  pX_Pro,
                                         struct X_FUN          *  pX_Fun,
                                         X_DATA_FILE_HEADER_EX *  pHeader );

X_BOOL_FUNCTION X_PDF_IsMappingPossibleEx( struct X_IDS           *  pX_Ids,
                                           struct X_PRO           *  pX_Pro,
                                           struct X_FUN           *  pX_Fun,
                                           X_DATA_FILE_HEADER_EX  *  pHeader,
                                           X_PFNGETIDPTR             pfnfCallerId,
                                           X_PVOID                   pParam,
                                           X_DATA_OAM_HEADER      ** ppOamHeader );

X_LONG_FUNCTION X_PDF_Deallocate_OamHeader( struct X_IDS       *  pX_Ids,
                                            struct X_PRO       *  pX_Pro,
                                            struct X_FUN       *  pX_Fun,
                                            X_DATA_OAM_HEADER  ** ppOamHeader );

X_BOOL_FUNCTION X_PDF_ConvertMappedData_2( struct X_IDS           *  pX_Ids,
                                           struct X_PRO           *  pX_Pro,
                                           struct X_FUN           *  pX_Fun,
                                           X_DATA_FILE_HEADER_EX  *  pHeader,
                                           X_DATA_MAPPING         *  pMapping,
                                           X_DATA_X_VAR           *  pVarData,
                                           X_SHORT                   sColumns,
                                           X_DATA_OAM_HEADER      *  pOamHeader );

X_BOOL_FUNCTION X_PDF_PromptYesNo( struct X_IDS *pX_Ids,
                                   X_PCCHAR pvchTitle,
                                   X_PCCHAR pvchMessage);

X_CHAR_FUNCTION X_PDF_PromptYesNoCancel( struct X_IDS *pX_Ids,
                                         X_PCCHAR pvchTitle,
                                         X_PCCHAR pvchMessage);

X_INT_FUNCTION X_PDF_Prompt(struct X_IDS * pX_Ids,
                            struct X_PRO * pX_Pro,
                            struct X_FUN * pX_Fun,
                            X_PCCHAR pvchTitle,
                            X_PCCHAR pvchMessage,
                            X_UINT   uType);

X_PVOID_FUNCTION X_PDF_Allocate_Mapping( struct X_IDS          *  pX_Ids,
                                         struct X_PRO          *  pX_Pro,
                                         struct X_FUN          *  pX_Fun,
                                         X_DATA_FILE_HEADER_EX *  pHeader );

X_LONG_FUNCTION X_PDF_Deallocate_Mapping( struct X_IDS      *  pX_Ids,
                                          struct X_PRO      *  pX_Pro,
                                          struct X_FUN      *  pX_Fun,
                                          X_DATA_MAPPING_EX ** ppMapping );

X_BOOL_FUNCTION X_PDF_Remove_Directory_Tree( struct X_IDS * pX_Ids,
                                             struct X_PRO * pX_Pro,
                                             struct X_FUN * pX_Fun,
                                             X_PCCHAR       pvchDirectory,
                                             X_BOOL         fFatal,
                                             X_BOOL         fForce );

X_BOOL_FUNCTION X_PDF_Remove_Directory( struct X_IDS * pX_Ids,
                                        struct X_PRO * pX_Pro,
                                        struct X_FUN * pX_Fun,
                                        X_PCCHAR       pvchDirectory,
                                        X_BOOL         fFatal,
                                        PFNGENLPURP    pfnMessageCallback );

X_BOOL_FUNCTION X_PDF_Clear_Directory( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PCCHAR       pvchDirectory,
                                       X_BOOL         fRemoveSubDirs,
                                       X_BOOL         fFatal,
                                       PFNGENLPURP    pfnMessageCallback,
                                       X_BOOL         fForce );

X_BOOL_FUNCTION X_PDF_IsRegularFile( struct X_IDS * pX_Ids,
                                     struct X_PRO * pX_Pro,
                                     struct X_FUN * pX_Fun,
                                     X_PVCHAR       pvchFilePath );


X_BOOL_FUNCTION X_PDF_IsDirectory( struct X_IDS * pX_Ids,
                                   struct X_PRO * pX_Pro,
                                   struct X_FUN * pX_Fun,
                                   X_PVCHAR       pvchFilePath );

X_BOOL_FUNCTION X_PDF_ConvertMappedData_3( struct X_IDS           *  pX_Ids,
                                           struct X_PRO           *  pX_Pro,
                                           struct X_FUN           *  pX_Fun,
                                           X_DATA_FILE_HEADER_EX  *  pHeader,
                                           X_DATA_MAPPING         *  pMapping,
                                           X_DATA_X_VAR           *  pVarData,
                                           X_SHORT                   sColumns,
                                           X_DATA_OAM_HEADER      *  pOamHeader,
                                           X_PVCHAR                  pvchLOBPath,
                                           X_PPVOID                  pvLOBTree,
                                           X_TYPE_FLAG               chOption );

X_BOOL_FUNCTION X_PDF_CleanupLOBFilesTree( struct X_IDS *  pX_Ids,
                                           struct X_PRO *  pX_Pro,
                                           struct X_FUN *  pX_Fun,
                                           X_PPVOID        ppvLOBTree,
                                           X_BOOL          fDeleteFiles,
                                           X_TYPE_FLAG     chOption );

X_SHORT_FUNCTION X_PDF_Execute_IO_Module_2( struct X_IDS *pX_Ids,
                                            struct X_PRO *pX_Pro,
                                            struct X_FUN *pX_Fun,
                                            struct X_DBM *pX_DBM,
                                            X_PCCHAR      pfchTable,
                                            X_BOOL        fReportFatal,
                                            X_PVCHAR      pvchMsgBuff,
                                            X_SHORT       sMsgBuffSize );
/* Originally in x_pdf10.c */
X_BOOL_FUNCTION X_PDF_ChangeFileAttrib( struct X_IDS *  pX_Ids,
                                        struct X_PRO *  pX_Pro,
                                        struct X_FUN *  pX_Fun,
                                        X_PCCHAR        pvchFileName,
                                        X_TYPE_FLAG     chAttrib );

#ifdef X_OPERATING_SYSTEM_UNIX
X_BOOL X_PDF_SetUnixFilePermission ( struct X_IDS         * pX_Ids,
                                     struct X_PRO         * pX_Pro,
                                     struct X_FUN         * pX_Fun,
                                     X_PCCHAR               pvchFileName,
                                     X_ULONG                ulPermission );
#endif

X_LONG_FUNCTION X_PDF_Partition_Folder_Order( struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              X_CHAR           chSearch,
                                              X_PVOID          pParam1,
                                              X_PVOID          pParam2,
                                              PFNCALBACK       pfnCallback );

X_LONG_FUNCTION X_PDF_Add_Define_Override( struct X_IDS  *  pX_Ids,
                                           struct X_PRO  *  pX_Pro,
                                           struct X_FUN  *  pX_Fun,
                                           const X_PVCHAR   pvchLibrary,
                                           const X_PVCHAR   pvchFile,
                                           const X_PVCHAR   pvchOverrideOwner,
                                           const X_PVCHAR   pvchOverrideTable,
                                           const X_CHAR     chUpdateType );

X_LONG_FUNCTION X_PDF_Delete_Define_Override( struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              X_BOOL           fDeleteAll,
                                              const X_PVCHAR   pvchLibrary,
                                              const X_PVCHAR   pvchFile );

X_LONG_FUNCTION X_PDF_Get_Define_Override( struct X_IDS  *  pX_Ids,
                                           struct X_PRO  *  pX_Pro,
                                           struct X_FUN  *  pX_Fun,
                                           const X_PVCHAR   pvchLibrary,
                                           const X_PVCHAR   pvchFile,
                                           const X_PVCHAR   pvchAlternate,
                                           X_PVCHAR         pvchOverrideOwner,
                                           X_PVCHAR         pvchOverrideTable,
                                           X_PVCHAR         pvchUpdateType );

X_BOOL_FUNCTION X_PDF_CreatePromptFile( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        X_ULONG          ulFlags,
                                        X_FUNC_ARG    *  pFA );

X_BOOL_FUNCTION X_PDF_CreateComposerServer( struct X_IDS * pX_Ids,
                                            struct X_PRO * pX_Pro,
                                            struct X_FUN * pX_Fun,
                                            struct X_COMPOSER_CONNECT ** ppCompServer );

X_BOOL_FUNCTION X_PDF_LoadComposerServer( struct X_IDS      *  pX_Ids,
                                          struct X_PRO      *  pX_Pro,
                                          struct X_FUN      *  pX_Fun,
                                          X_PVCHAR             pvchSystemPath,
                                          X_MODULEHANDLE    *  pModDLL,
                                          X_COMPOSER_SERVER *  ppfn );

#if defined (X_OPERATING_SYSTEM_ISERIES)

X_VOID_FUNCTION X_PDF_CloseSharedFiles( struct X_IDS   * pX_Ids,
                                        struct X_PRO   * pX_Pro,
                                        struct X_FUN   * pX_Fun );

X_VOID_FUNCTION X_PDF_Rinzstat( struct X_IDS   * pX_Ids,
                                struct X_PRO   * pX_Pro,
                                struct X_FUN   * pX_Fun );
#endif

/* ================================================================= */
/*  X_PDF5.C functions                                               */
/* ================================================================= */

/* X_MAIN_FUNCTION X_PDF_Run (int, char **);                         */

/* ================================================================= */
/*  X_PDF6.C functions                                               */
/* ================================================================= */


X_VOID_FUNCTION X_PDF_Submit_Process(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_PVCHAR,
                                     X_PVCHAR,
                                     X_PVCHAR,
                                     struct X_FLD[],
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT,
                                     X_SHORT[]);

#ifdef X_OPERATING_SYSTEM_ISERIES
X_VOID X_PDF_Call_3GL_Program (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_SHORT,
                               X_SHORT[],
                               X_SHORT,
                               struct X_PARM [],
                               X_CHAR,
                               X_CHAR,
                               X_PSHORT);

X_VOID_FUNCTION X_PDF_Call_3GL_Program_2(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PVCHAR      pvchProgram,
                                         X_SHORT       sCountParms,
                                         X_SHORT       sParms[],
                                         X_SHORT       scX_Parm,
                                         struct        X_PARM aX_Parm[],
                                         X_CHAR        chNum_Len,
                                         X_CHAR        chPgm_Exch,
                                         X_PSHORT      psRetCode,
                                         X_SHORT       sParmBlocks,
                                         X_PARM_BLOCK_HDR *pParmBlockHdr,
                                         X_PARM_BLOCK *pParmBlock);

X_VOID_FUNCTION X_PDF_Submit_3GL_Program(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PVCHAR      pvchProgram,
                                         struct X_FLD  X_Fld[],
                                         X_SHORT       sVecJobName,
                                         X_SHORT       sVecJobDesc,
                                         X_SHORT       sVecJobDescLib,
                                         X_SHORT       sVecJobQueue,
                                         X_SHORT       sVecJobQueueLib,
                                         X_SHORT       sVecOutputQueue,
                                         X_SHORT       sVecOutputQueueLib,
                                         X_SHORT       sCountParms,
                                         X_SHORT       sParms[]);
X_VOID_FUNCTION X_PDF_Call_3GL_Program_Ex(struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro,
                                          struct X_FUN *pX_Fun,
                                          X_PVCHAR      pvchProgram,
                                          X_SHORT       iTotalParms,
                                          X_PVOID       pParms[],
                                          X_PSHORT      psRetCode);
#endif

/* ================================================================= */
/*  X_PDF7.C functions                                               */
/* ================================================================= */


X_VOID_FUNCTION X_PDF_Upper_Case
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_LONG,
                               X_PFCHAR);

X_VOID_FUNCTION X_PDF_Lower_Case
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_LONG,
                               X_PFCHAR);

X_VOID_FUNCTION X_PDF_MemCopy_Upper_Case( struct X_IDS   *  pX_Ids,
                                          struct X_PRO   *  pX_Pro,
                                          struct X_FUN   *  pX_Fun,
                                          X_PVCHAR          pvchDes,
                                          X_LONG            lSize,
                                          X_PVCHAR          pvchSrc,
                                          X_LONG            lBytes );

X_VOID_FUNCTION X_PDF_GetCPU
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PFCHAR);

X_CHAR_FUNCTION X_PDF_Licence_Operation
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_CHAR,
                               X_PFCHAR);

X_CHAR_FUNCTION X_PDF_Licence_Operation_Ex
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_CHAR,
                               X_PFCHAR,
                               X_BOOL);

X_CHAR_FUNCTION X_PDF_Licence_Operation_Details( struct X_IDS  *  pX_Ids,
                                                 struct X_PRO  *  pX_Pro,
                                                 struct X_FUN  *  pX_Fun,
                                                 X_CHAR           chOperation,
                                                 X_PFCHAR         pfchFeature,
                                                 X_BOOL           fLogLicenceNotFound,
                                                 X_SHORT          scX_Parm,
                                                 struct X_PARM    aX_Parm[] );

X_CHAR_FUNCTION X_PDF_Extern_Licence_Operation (
                                          X_PFCHAR,
                                          X_PFCHAR);

X_SHORT_FUNCTION X_PDF_Get_Version( X_VOID );

X_BOOL_FUNCTION X_PDF_SetLANSAPCPath( struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN * );

X_BOOL_FUNCTION X_PDF_SetLANSAXDLLPath( struct X_IDS * );

X_VOID_FUNCTION X_PDF_Decrease_Code( struct X_IDS *pX_Ids,
                                     X_UCHAR *pfuchInput,
                                     X_UCHAR *pfuchOutput,
                                     X_PVCHAR pvchReturnCode );

/* ================================================================= */
/*  X_PDF8.C functions                                               */
/* ================================================================= */

X_LONG_FUNCTION X_PDF_Allocate_Comms_Session( struct X_IDS *pX_Ids,
                                              struct X_PRO *pX_Pro,
                                              struct X_FUN *pX_Fun,
                                              struct X_CONNECT_COMPUTER *pComputer,
                                              X_PVCHAR pvchPassword,
                                              X_PVCHAR pvchUserProfile,
                                              X_BOOL   fAllowUpperCasing );

X_BOOL_FUNCTION X_PDF_Deallocate_Comms_Session(struct X_IDS *pX_Ids,
                                                struct X_PRO *pX_Pro,
                                                struct X_FUN *pX_Fun,
                                                struct X_CONNECT_COMPUTER *pX_Connect,
                                                X_YES_NO chIssueErrorMessage);

X_BOOL_FUNCTION X_PDF_Send_Comms_Data(struct X_IDS *pX_Ids,
                                       struct X_PRO *pX_Pro,
                                       struct X_FUN *pX_Fun,
                                       struct X_CONNECT_COMPUTER *pX_Connect,
                                       X_PVCHAR  pvchData,
                                       X_LONG    lLen);

X_BOOL_FUNCTION X_PDF_Flush_Comms_Data(struct X_IDS *pX_Ids,
                                       struct X_PRO *pX_Pro,
                                       struct X_FUN *pX_Fun,
                                       struct X_CONNECT_COMPUTER *pX_Connect);

X_BOOL_FUNCTION X_PDF_Turn_Comms_Line(struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun,
                                      struct X_CONNECT_COMPUTER *pX_Connect);

X_BOOL_FUNCTION X_PDF_Receive_Comms_Data(struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro,
                                          struct X_FUN *pX_Fun,
                                          struct X_CONNECT_COMPUTER *pX_Connect,
                                          X_PVCHAR  pvchData,
                                          X_PLONG  plLen);

X_LONG_FUNCTION X_PDF_Determine_Client_Type(struct X_IDS *pX_Ids,
                                            struct X_PRO *pX_Pro,
                                            struct X_FUN *pX_Fun,
                                            struct X_CONNECT_COMPUTER *pComputer);

X_VOID_FUNCTION X_PDF_Get_Connection_Type (struct X_IDS *pX_Ids,
                                           struct X_PRO *pX_Pro,
                                           struct X_FUN *pX_Fun,
                                           struct X_CONNECT_COMPUTER *pComputer,
                                           X_PVCHAR      pvchType);

/* ================================================================= */
/*  X_PDF9.C functions                                               */
/* ================================================================= */

X_ULONG_FUNCTION X_PDF_Ebcdic_Length_2 (struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      X_PCCHAR       pvchASCII,
                                      X_PULONG       pulTotalDBCS);

X_SHORT_FUNCTION X_PDF_Ebcdic_Length (struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      X_PCCHAR       pvchASCII,
                                      X_PSHORT       psTotalDBCS);

X_VOID_FUNCTION X_PDF_Prepare_DBCS_Environment (struct X_IDS * pX_Ids);

X_BOOL_FUNCTION X_PDF_Is_DBCS_First_Char (struct X_IDS * pX_Ids,
                                          X_PCCHAR pchTestChar);

X_ULONG_FUNCTION X_PDF_Analyse_DBCS_String_Ex (struct X_IDS * pX_Ids,
                                               X_PCCHAR       pvchASCII,
                                               X_PULONG       pnTotalDBCS,
                                               X_PULONG       pnTotalNonDBCS);

X_SHORT_FUNCTION X_PDF_Analyse_DBCS_String (struct X_IDS * pX_Ids,
                                            X_PCCHAR       pvchASCII,
                                            X_PSHORT       psTotalDBCS,
                                            X_PSHORT       psTotalNonDBCS);

X_VOID_FUNCTION X_PDF_Load_IME_Settings (struct X_IDS * pX_Ids);

/* ================================================================= */
/*  X_PDF10.C functions                                              */
/* ================================================================= */


X_CHAR_FUNCTION X_PDF_ExportObjects(struct X_IDS   *  pX_Ids,
                                    struct X_PRO   *  pX_Pro,
                                    struct X_FUN   *  pX_Fun,
                                    X_PVCHAR          pvchProcess,
                                    struct X_LIST  *  pX_List,
                                    X_BOOL            fAppend,
                                    X_BOOL            fSys,
                                    X_BOOL            fDev,
                                    X_PVCHAR          pvchPath,
                                    X_BOOL            fResetBuildStatus,
                                    struct X_LIST  *  pLibDirectives );

X_CHAR_FUNCTION X_PDF_ExportObjectsEx( struct X_IDS   *  pX_Ids,
                                       struct X_PRO   *  pX_Pro,
                                       struct X_FUN   *  pX_Fun,
                                       X_PVCHAR          pvchProcess,
                                       struct X_LIST  *  pX_List,
                                       X_BOOL            fAppend,
                                       X_BOOL            fSys,
                                       X_BOOL            fDev,
                                       X_PVCHAR          pvchPath,
                                       X_BOOL            fResetBuildStatus,
                                       struct X_LIST  *  pLibDirectives,
                                       X_ULONG           ulFlags );

X_BOOL_FUNCTION X_PDF_ImportObjects(struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_PVCHAR pvchProcess,
                                    X_PLONG  plNumErrors,
                                    X_PLONG  plNumWarnings,
                                    X_PVCHAR pvchUseImportDirective);

X_BOOL_FUNCTION X_PDF_ImportObjectsEx( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PVCHAR pvchProcess,
                                       X_PLONG  plNumErrors,
                                       X_PLONG  plNumWarnings,
                                       X_PVCHAR pvchUseImportDirective,
                                       X_BOOL   fDeliverTo,
                                       PX_IN_MEMORY_IMPORT  pConsumer );

X_BOOL_FUNCTION X_PDF_ImportObjectEx2( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PVCHAR pvchProcess,
                                       X_PLONG  plTotalFatals,
                                       X_PLONG  plTotalWarnings,
                                       X_PVCHAR pvchUseImportDirective,
                                       X_BOOL   fDeliverTo,
                                       PX_IN_MEMORY_IMPORT pConsumer,
                                       X_IMPORT_OPTION   * pOption );

X_VOID_FUNCTION X_PDF_Load_W3XSVPGM_DLL(struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_Unload_W3XSVPGM_DLL(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Load_W3XSVPGX_DLL(struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_Unload_W3XSVPGX_DLL(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Load_X_WSI_DLL(struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_Unload_X_WSI_DLL(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_Load_X_DBG_DLL(struct X_IDS * pX_Ids);
X_VOID_FUNCTION X_PDF_Unload_X_DBG_DLL(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_PDF_GetLanguageMappings( struct X_IDS *    pX_Ids,
                                           struct X_PRO *    pX_Pro,
                                           struct X_FUN *    pX_Fun,
                                           struct LANG_MAP * langMap,
                                           X_SHORT *         sLangCount,
                                           X_BOOL            fClient );

UTC_LANGUAGE * X_PDF_InitializeUtcLanguageMap( struct X_IDS *    pX_Ids,
                                                struct X_PRO *    pX_Pro,
                                                struct X_FUN *    pX_Fun );

X_BOOL_FUNCTION X_PDF_Import_Library( struct X_IDS *  pX_Ids,
                                      struct X_PRO *  pX_Pro,
                                      struct X_FUN *  pX_Fun,
                                      X_FUNC_ARG   *  pFuncArg,
                                      X_BOOL          fGetLibrary,
                                      PFNCALBACK      pfnCallback );

X_VOID_FUNCTION X_PDF_Free_LImport_Memory( struct X_IDS  *  pX_Ids,
                                           struct X_PRO  *  pX_Pro,
                                           struct X_FUN  *  pX_Fun );

X_BOOL_FUNCTION X_PDF_IsDevInstallEnv( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun );

#ifdef X_OPERATING_SYSTEM_WIN
X_BOOL_FUNCTION X_PDF_WINDTMCreateProcess(
   X_BOOL fUseWDH,                              /* use WDH or IDH */
   struct X_IDS *pX_Ids,                        /* ids structure */
   X_PCCHAR lpExeName,                          /* name of executable module without parameter */
   X_PCCHAR lpApplicationName,                  /* name of executable module */
   X_PCHAR lpCommandLine,                       /* command line string */
   LPSECURITY_ATTRIBUTES lpProcessAttributes,   /* SD */
   LPSECURITY_ATTRIBUTES lpThreadAttributes,    /* SD */
   X_BOOL bInheritHandles,                      /* handle inheritance option */
   X_DWORD dwCreationFlags,                     /* creation flags */
   X_PVOID lpEnvironment,                       /* new environment block */
   X_PCCHAR lpCurrentDirectory,                 /* current directory name */
   LPSTARTUPINFO lpStartupInfo,                 /* startup information */
   LPPROCESS_INFORMATION lpProcessInformation   /* process information */
   );
X_ULONG_FUNCTION X_PDF_WINDTMUnregister(void);
X_BOOL_FUNCTION X_PDF_WINDTMUseWDH(struct X_IDS * pX_Ids,
                                   X_PCCHAR pszParameters);
#endif

X_BOOL_FUNCTION 
   X_PDF_GetAlternateName( 
      struct X_IDS                              *  pX_Ids,
      struct X_PRO                              *  pX_Pro,
      struct X_FUN                              *  pX_Fun,
      X_PVCHAR                                     pvchObjIn,
      X_PVCHAR                                     pvchExtIn,
      X_PVCHAR                                     pvchExt2In,
      X_PVCHAR                                     pvchTypeIn,
      X_PVCHAR                                     pvchAltNameIn,
      X_PVCHAR                                     pvchObjOut,
      X_PVCHAR                                     pvchExtOut,
      X_PVCHAR                                     pvchExt2Out,
      X_PVCHAR                                     pvchTypeOut,
      X_PVCHAR                                     pvchAltNameOut );


/* ================================================================= */
/*  X_PDF11.CPP functions                                            */
/* ================================================================= */

X_LONG_FUNCTION X_PDF_PublishWebRoutineXslData(struct X_IDS *pX_Ids,
                                               struct X_PRO *pX_Pro,
                                               struct X_FUN *pX_Fun,
                                               X_PVCHAR      pvchWam,
                                               X_PVCHAR      pvchRoutine,
                                               X_PVCHAR      pvchEntity,
                                               X_PVCHAR      pvchApp,
                                               X_LONG        lSet,
                                               X_PVCHAR      pvchLangCode,
                                               PFNGENLPURP   pfnMessageCallback,
                                               X_PLONG       plTotalFatals,
                                               X_PLONG       plTotalWarnings);

X_LONG_FUNCTION X_PDF_PublishWebletXslData(struct X_IDS  *pX_Ids,
                                           struct X_PRO  *pX_Pro,
                                           struct X_FUN  *pX_Fun,
                                           X_PVCHAR       pvchWeblet,
                                           X_PVCHAR       pvchEntity,
                                           X_PVCHAR       pvchApp,
                                           X_LONG         lSet,
                                           X_PVCHAR       pvchLangCode,
                                           PFNGENLPURP    pfnMessageCallback,
                                           X_PLONG        plTotalFatals,
                                           X_PLONG        plTotalWarnings);

X_LONG_FUNCTION X_PDF_PublishTechServiceXslData(struct X_IDS  *pX_Ids,
                                                struct X_PRO  *pX_Pro,
                                                struct X_FUN  *pX_Fun,
                                                X_PVCHAR       pvchEntity,
                                                X_PVCHAR       pvchApp,
                                                X_PVCHAR       pvchDoc,
                                                X_LONG         lSet,
                                                PFNGENLPURP    pfnMessageCallback,
                                                X_PLONG        plTotalFatals,
                                                X_PLONG        plTotalWarnings);

X_LONG_FUNCTION X_PDF_RemovePublishedWebRoutineXslDoc(struct X_IDS   *pX_Ids,
                                                      struct X_PRO   *pX_Pro,
                                                      struct X_FUN   *pX_Fun,
                                                      X_PVCHAR        pvchWam,
                                                      X_PVCHAR        pvchRoutine,
                                                      X_PVCHAR        pvchEntity,
                                                      X_PVCHAR        pvchApp,
                                                      X_LONG          lSet,
                                                      X_PVCHAR        pvchLangCode,
                                                      PFNGENLPURP     pfnMessageCallback,
                                                      X_PLONG         plTotalFatals,
                                                      X_PLONG         plTotalWarnings);

X_LONG_FUNCTION X_PDF_RemovePublishedWebletXslDoc(struct X_IDS *pX_Ids,
                                                  struct X_PRO *pX_Pro,
                                                  struct X_FUN *pX_Fun,
                                                  X_PVCHAR      pvchWeblet,
                                                  X_PVCHAR      pvchEntity,
                                                  X_PVCHAR      pvchApp,
                                                  X_LONG        lSet,
                                                  X_PVCHAR      pvchLangCode,
                                                  PFNGENLPURP   pfnMessageCallback,
                                                  X_PLONG       plTotalFatals,
                                                  X_PLONG       plTotalWarnings);

X_LONG_FUNCTION X_PDF_RemovePublishedTechServiceXslDoc(struct X_IDS *pX_Ids,
                                                       struct X_PRO *pX_Pro,
                                                       struct X_FUN *pX_Fun,
                                                       X_PVCHAR      pvchEntity,
                                                       X_PVCHAR      pvchApp,
                                                       X_PVCHAR      pvchDoc,
                                                       X_LONG        lSet,
                                                       PFNGENLPURP   pfnMessageCallback,
                                                       X_PLONG       plTotalFatals,
                                                       X_PLONG       plTotalWarnings);

X_LONG_FUNCTION X_PDF_SaveTechServiceXslData(struct X_IDS *pX_Ids,
                                             struct X_PRO *pX_Pro,
                                             struct X_FUN *pX_Fun,
                                             X_PVCHAR      pvchEntity,
                                             X_PVCHAR      pvchApp,
                                             X_PVCHAR      pvchDoc,
                                             X_LONG        lSet,
                                             PFNGENLPURP   pfnMessageCallback,
                                             X_PLONG       plTotalFatals,
                                             X_PLONG       plTotalWarnings);

X_LONG_FUNCTION X_PDF_ClearWebCache(struct X_IDS *pX_Ids,
                                    struct X_PRO *pX_Pro,
                                    struct X_FUN *pX_Fun,
                                    PFNGENLPURP   pfnMessageCallback,
                                    X_PLONG       plTotalFatals,
                                    X_PLONG       plTotalWarnings);

X_LONG_FUNCTION X_PDF_InitializeXmlLibrary(struct X_IDS *pX_Ids,
                                           struct X_PRO *pX_Pro,
                                           struct X_FUN *pX_Fun,
                                           PFNGENLPURP   pfnMessageCallback,
                                           X_PLONG       plTotalFatals,
                                           X_PLONG       plTotalWarnings);

X_LONG_FUNCTION X_PDF_TerminateXmlLibrary(struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro,
                                          struct X_FUN *pX_Fun,
                                          PFNGENLPURP   pfnMessageCallback,
                                          X_PLONG       plTotalFatals,
                                          X_PLONG       plTotalWarnings);


/* ================================================================= */
/*  X_PDF12.CPP functions                                            */
/* ================================================================= */
X_INT EnumMSIGuids(  struct X_IDS * pX_Ids,
                     struct X_PRO * pX_Pro,
                     struct X_FUN * pX_Fun );

X_INT EnumUpgradeCodePatches  ( 
   PX_PDF_ANCHOR_BLOCK,
   PX_COM_ANCHOR,
   PFN_MSIVERSIONDETAILS_CALLBACK pfnPatchVersionCallBack );

X_INT X_PDF_EnumMSIGuidProperties(  
   PX_PDF_ANCHOR_BLOCK           pAnchor,
   X_UTF16_VCHAR              *  pwchGUID, 
   PFN_MSIPROPERTY_CALLBACK      pfnMSIPropertyCallBack,
   X_PVOID                       pCallbackAnchor,
   X_BOOL                        fEnumeratePatches );

/* ================================================================= */
/*  X_PDFLST.CPP functions                                           */
/* ================================================================= */

X_VOID_FUNCTION X_PDF_HeapListLog(   struct X_IDS *pX_Ids );
X_VOID_FUNCTION X_PDF_HeapListTrace( struct X_IDS *pX_Ids );
X_VOID_FUNCTION X_PDF_HeapListInsert( X_PHEAP pHeap );
X_VOID_FUNCTION X_PDF_HeapListRemove( X_PHEAP pHeap );
X_BOOL_FUNCTION X_PDF_HeapListValidate(   struct X_IDS *pX_Ids, X_PCCHAR pszFile, X_SHORT sLine );

/* ================================================================= */
/*  X_CPU.C functions                                                */
/* ================================================================= */

short getOSVerString (  char* value, int *numProc, int *numBits );

#ifdef __cplusplus

}
#endif

#endif
