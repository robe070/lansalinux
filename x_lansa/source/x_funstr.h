/* ================================================================= */
/* ========= LANSA FOR WINDOWS GLOBAL STRUCTURES =================== */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_FUNSTR.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : Standard X_ structures                      */
/*                                                                   */
/*===================================================================*/
/* $Archive:: /VL/Trunk/work/x_win95/x_lansa/source/x_funstr.h     $ */
/*===================================================================*/

#ifndef __INCL_X_FUNSTR_H__
#define __INCL_X_FUNSTR_H__

#ifndef __stdio_h
   #include <stdio.h>
#endif

#include "x_ctypes.h"
#include "x_ftypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef X_OPERATING_TARGET_CSHARP

   /* NB Define of X_PACKED is required before inclusion of x_xqlxxx.h */
   #if defined X_OPERATING_SYSTEM_ISERIES
   #define X_PACKED _Packed
   #else
   #define X_PACKED
   #endif

#endif // X_OPERATING_TARGET_CSHARP

// The following #defines are required by x_xqlxxx.h

#define X_DESCRIPTION_LEN      40      /* Length of description as MBCS in RAM */
#define X_DESCRIPTION_COL_LEN 120      /* Length of description as UTF-8 on disk - column length*/

#define X_LABEL_LEN            15      /* Length of label as MBCS in RAM */
#define X_LABEL_COL_LEN        45      /* Length of label as UTF-8 on disk  - column length */

#define X_COLUMN_HEADING_LEN   20      /* Length of column heading as MBCS in RAM */
#define X_COLUMN_HEADING_COL_LEN 60    /* Length of column heading as UTF-8 on disk  - column length */

#include "x_xqlxxx.h"

/* Increment this value for each release of LANSA and also            */
/* X_FUN_GENERATION_LEVEL in FUN00001.S                               */
#define X_INTERNAL_GENERATION_LEVEL 1

#ifdef X_GENERATED_CODE

   #ifndef X_FUN_GENERATION_LEVEL
      #error Generated code is incompatible with the execution environment. Please re-build it.
   #else
      #if X_FUN_GENERATION_LEVEL != X_INTERNAL_GENERATION_LEVEL
         #error Generated code is incompatible with the execution environment. Please re-build it.
      #endif
   #endif

   #endif

#define VARCHARCOPY(_A, _B) \
{ \
   strncpy(_A,_B,sizeof(_A));  \
   _A[sizeof(_A) - 1] = LOVAL; \
}


#define X_MESSAGE_BOX_TEXT_LEN (1024 * 4 * 2)   // * 2 is to support widechar characters
#define X_EDIT_SOURCE_LEN       3
#define X_C_FUNCTION_NAME_LEN  30
#define X_DATE_LEN              6
#define X_DATE_FORMAT_LEN       3
#define X_DBID_LEN              8
#define X_DSN_NAME_LEN         32
#define X_DDLIST_TEXT_LEN      60      /* Max len of Text in Drop Down list */

#define X_DISPLAY_DATE_LEN      8
#define X_DISPLAY_TIME_LEN      8
#define X_ERROR_TEXT_LEN     1048      /* Max length of error text   */
#define X_EXCHANGE_LIST_LEN  2000
#define X_FILE_NAME_LEN        12      /* 8.3 file name length       */
#define X_FUNCTION_NAME_LEN     7
#define X_LANGUAGE_CODE_LEN     4
#define X_LANGUAGE_SPARE_LEN  100
#define X_LDA_LEN            1024
#define X_DATA_AREA_LEN      2000
#define X_LONG_DATE_LEN         8
#define X_MAX_ACTION_BARS_PER_LINE 6
#define X_MAX_DESC_LEN         40      /* Max len of Field Description */
#define X_SQL_STATEMENT_LEN    8096
#define X_INVALID_CURSOR       -9999   /* Invalid cursorid used by Component routine termination */
#define X_SUP_GROUP_PROFILES_LEN   150
#define X_LANGUAGE_CHAR_SET_LEN     20
#define X_SHORT_CHAR_LEVEL_MULTIPLIER  32
#define X_MSI_GUID_LEN                 38  // Refer to MsiEnumProductsEx() documentation for szInstalledProductCode 
#define X_MSI_VERSION_LEN              23  // 99999.99999.99999.99999
#define X_MSI_CULTURE_LEN        7         // e.g. en-us or ja-jp, but allow for some 3 char language & country
#define X_MSI_LOCALE_LEN         5         // e.g. 1033 for English
#define X_SETUP_BATCH_FILE_NAME    "setup.bat"

/* The following are the maximum lengths of the values of the named type */

#define X_MAX_DICTIONARY_FIELD_LEN  256
#define X_MAX_ALPHA_FIELD_LEN       256
#define X_MAX_SYSVAR_FIELD_LEN      256
#define X_MAX_SHORT_CHAR_FIELD_LEN  512
#define X_MAX_CHAR_FIELD_LEN        65535
#define X_MAX_BINARY_FIELD_LEN      32767
#define X_MAX_UPID_FIELD_LEN        256     /* No where near this length, but I don't want to have to test all the ramifications of making it exact :-). There is an enhancement to increase the length of RRN and UPID. It should be done then. */
#define X_MAX_NUMBER_AS_STRING_LEN  ( X_MAX_NUMERIC_DIGITS + X_MAX_NUMERIC_DECIMALS ) + 3 + X_MAX_NUMERIC_DIGITS/3 + 1   /* Allow for generic decimal, minus sign, decimal point, currency, thousand separators */
#define X_DEFAULT_VALUE_LEN         20      /* TN: Actually it is the length of X03DFT */
#define X_MAX_DEFAULT_VALUE_LEN     MAX(X_MAX_SYSVAR_FIELD_LEN,X_DEFAULT_VALUE_LEN)
#define X_MAX_WIN_REGISTRY_VALUE_LEN   16300  /* TN: Windows 95/98/Me */
#define MAX_NON_VAR_AS_STRING MAX( sizeof(X_FLDDATA), X_MAX_NUMBER_AS_STRING_LEN)
#define X_MIN_DICTIONARY_FIELD_LEN  1

#define X_BIF157_COMMAND_BLOCK_LEN  256

/* Maximum length for Built-In 157 command string */
#define BIF157_MAX_COMMAND_LEN      ( X_BIF157_COMMAND_BLOCK_LEN * 3 )

#define X_MAX_COMPONENT_FIELD_LEN   X_MAX_DICTIONARY_FIELD_LEN
#define X_MIN_COMPONENT_FIELD_LEN   X_MIN_DICTIONARY_FIELD_LEN

#define X_MAX_PARAMETER_VALUE_LEN   256

#define X_MAX_PROCESS_PARMS         10

#define X_MESSAGE_ID_LEN            7
#define X_MESSAGE_FORMAT_NORMAL     'N'
#define X_MESSAGE_FORMAT_EXTENDED   'E'
#define X_MESSAGE_FORMAT_FIXED      'F'
#define X_MESSAGE_EXTENDED_TEXT     "*STCMSG"
#define X_MAX_FIRST_LEVEL_TEXT      132
#define X_MAX_SECOND_LEVEL_TEXT     2000
#define X_MESSAGE_DATA_LEN          512

#define X_MIN_DOT_LEN            6     /* Min no. dots at end Field Desc */
#define X_OBJECT_NAME_LEN        10
#define X_CLASS_NAME_LEN         10
#define X_TABLE_NAME_LEN         10
#define X_COLLECTION_NAME_LEN    10
#define X_MEMBER_NAME_LEN        10
#define X_ALTERNATE_NAME_LEN     256
#define X_PJF_KEY_NAME_LEN       256

#define X_COLUMN_NAME_LEN        256

#define X_COMPONENT_NAME_LEN     20
#define X_HELP_CONTEXT_LEN       65

#define X_WEB_SERVICE_NAME_LEN         40
#define X_WEB_APPMOD_NAME_LEN          10
#define X_WEB_ROUTINE_NAME_LEN         20
#define X_WEB_ML_NAME_LEN              40
#define X_WEB_SESSION_GROUP_NAME_LEN   10
#define X_WEB_SERVER_TYPE_LEN          16

#define X_DEBUGGING_HOST_NAME_LEN      64

#define X_SERVER_NAME_LEN        20

#define X_BIF_NAME_LEN           20
#define X_BIF_MAXIMUM_ARGS       20
#define X_BIF_MAXIMUM_RETS       20

#define X_SYSVAR_NAME_LEN        20
#define X_MULVAR_NAME_LEN        20
#define X_PARAMETER_NAME_LEN     5     /* Parameter Length passed to */
                                       /* X_RUN.                     */
#define X_PARTITION_NAME_LEN     3
#define X_TASK_ID_LEN            8
#define X_TIME_LEN               6

#define X_CIPHER_NAME_LEN        16          // Longest currently used is 11. e.g. aes-256-cbc. Look in OpenSSL documentation.
#define X_DEFAULT_CIPHER_NAME    "aes-256-cbc"
#define X_PUBLIC_KEY_FILE_SUFFIX "der"

#define X_ISERIES_USER_NAME_LEN      10      // User ids that have a relationship to iSeries User ID. e.g. Authority Checking
#define X_CURRENT_USER_NAME_LEN     256      // User ids that are restricted to 256 - mostly comms and DB
#define X_CURRENT_PASSWORD_LEN      256      // Passwords that are restricted to 256 - mostly comms and DB

#define X_MAX_USER_NAME_LEN         256      // User ids that can expand quite easily. This is an arbitrary limit
#define X_MAX_PASSWORD_LEN          256      // Passwords that can expand quite easily. This is an arbitrary limit

#define X_SYSTEM_NAME_LEN           20

#define X_MAX_SIZE_LOB_FILE_NAME    256
#define X_MAX_SIZE_ALPHA_LEN        256

/* Packed and signed are variable size, so do not use a max length to copy the value */
/* #define X_MAX_SIZE_PACKED_LEN       20 */
/* #define X_MAX_SIZE_SIGNED_LEN       38 */

#define X_MAX_SIZE_DATE_LEN            (10 + 1)
#define X_MAX_SIZE_TIME_LEN            (8 + 1)
#define X_MAX_SIZE_DATETIME_LEN        (29 + 1)
#define X_MAX_SIZE_DATETIME_STRING_LEN (35 + 1)    /* Big enough for Datetime strings in           */
                                                   /* format: YYYY-MM-DDTHH:SS:MM[.fffffffff]+HHMM */
#define X_DEFAULT_DATE "1900-01-01"
#define X_DEFAULT_TIME "00:00:00"

#define X_MAX_SIZE_GREGORIAN_LEN       (14 + 1)
#define X_MAX_SIZE_DURATION_LEN        (59 + 1)

#define X_VARIABLE_NAME_LEN    20
#define X_VAR_NAME_COMPARE_LEN 10
#define X_JOBNAME_LEN          10
#define X_JOBNUM_LEN            6
#define X_SYSTEM_CMD_LEN      300      /* Max len of system command */
#define X_PRTR_PORT_NAME_LEN   20
#define X_PRINTER_NAME_LEN     64
#define X_MAXIMUM_USER_KEYS     5
#define X_REFRESH_FLAGS_LENGTH  9

#define X_OBJECT_SHORT_NAME_LEN  20

/* Source is generated on Windows and is generally 8 long */
#define X_GENERATED_SOURCE_NAME_LEN  8

/* File has been enhanced to use 10 chars for source and DLL */
#define X_FILE_DLL_NAME_LEN               10
#define X_FILE_GENERATED_SOURCE_NAME_LEN  10

/* On the other hand all iSeries DLL names allow 10 characters, which is   */
/* different to the source name length, currently.                         */
#ifdef X_OPERATING_SYSTEM_ISERIES
#define X_DLL_NAME_LEN  10
#else
#define X_DLL_NAME_LEN  8
#endif

/* TN: Special macro for C call RPG cases  */
#define X_MAX_RPG3_ARRAY_LEN  9999
/* /TN */
#define X_WEBLET_NAME_LEN     20

#define X_FIRST_DBCS_BLANK    0x81
#define X_SECOND_DBCS_BLANK   0x40

#define X_BUILD_NUMBER_LEN    20

#define X_TIMEZONE_MAX_LEN 5 /* e.g. +HHMM or Z */

#define X_HEAP_DEFAULT           'X' /* Use default as set in code   */
#define X_HEAP_GUARD             'G' /* Guard bytes and validate ptr */
#define X_HEAP_VALIDATEPTR       'P' /* Validate ptr only            */
#define X_HEAP_VALIDATEHEAP      'H' /* 'P' + validate whole of heap */
#define X_HEAP_VALIDATEALL       'A' /* 'H' + validate all heaps     */
#define X_HEAP_VALIDATEHEAPTRACE 'T' /* 'H' + trace validations      */
#define X_HEAP_VALIDATEALLTRACE  'Z' /* 'A' + trace validations      */

/* Let compile environment resolve the length of a C string when     */
/* that string contains DBCS characters. Shift codes are added on    */
/* EBCDIC system and they are not there on ASCII systems             */
#if defined(X_OPERATING_SYSTEM_ISERIES)
   #define X_RESOLVE_VARCHAR_LENGTH( _L1, _L2 ) _L2
#else
   #define X_RESOLVE_VARCHAR_LENGTH( _L1, _L2 ) _L1
#endif

/* Define common string to enable code generation to use memcmp for trailing blank checks */
#define X_ALPHA_BLANK_STRING  \
"          " "          " "          " "          " "          " \
"          " "          " "          " "          " "          " \
"          " "          " "          " "          " "          " \
"          " "          " "          " "          " "          " \
"          " "          " "          " "          " "          " \
"      "

/* -------------------------------------------------------------- */
/*  Upgrade/Install details                                       */
/* -------------------------------------------------------------- */
#define X_INSTALL_OPTION_LEN      3
#define X_APPL_NAME_LEN           8
#define X_PKG_NAME_LEN            8
#define X_UPGD_LOCK_FILE_NAME "_upgrade.lck"
#ifdef X_OPERATING_SYSTEM_UNIX
#define X_UPGD_LOCK_FILE_PATH "%s%sx_%s/bin/"
#else  /* OPERATING_SYSTEM_UNIX */
#define X_UPGD_LOCK_FILE_PATH "%s%sX_%s\\EXECUTE\\"
#endif

struct X_PKG_STATUS
{
   X_VCHAR  vchName[X_PKG_NAME_LEN + 1];
   X_CHAR   chStatus;
};

#ifdef X_OPERATING_SYSTEM_UNIX
#define X_DLL_PREFIX "lib"
#define X_EXE_SUFFIX ""
#define X_ALL_FILES "*"
#define X_EXECUTE_DIR "bin"
#define X_DLL_SUFFIX ".so"
#define X_EXE_SUFFIX ""
#else
#define X_EXECUTE_DIR "execute"
#define X_DLL_PREFIX ""
#define X_DLL_SUFFIX ".dll"
#define X_EXE_SUFFIX ".exe"
#define X_ALL_FILES "*.*"
#endif

#define X_THIS_DIRECTORY "."
#define X_PARENT_DIRECTORY ".."

#define X_CTD_SUFFIX ".ctd"
#define X_CTX_SUFFIX ".ctx"

#define X_PKG_EPCZIP_SPEC "epc*.zip"
#define X_PKG_EPCDIR_SPEC "epc*"

#define X_PKG_CAB1_SPEC "cab1*.*"

#define X_PARTIAL_PKG_STATUS      'P'
#define X_INSTALLABLE_PKG_STATUS  ' '
#define X_INSTALLED_PKG_STATUS    'Y'
#define X_SETUP_NEEDED_PKG_STATUS 'S'
#define X_IGNORE_PKG_STATUS       'I' /* Ignore if optional */
#define X_UPDATE_X_PKG_STATUS     'X'

#define X_MANDATORY_PKG 'M'
#define X_OPTIONAL_PKG  'O'

#define X_DUMMY_MSI_PACKAGE    "Download"
#define X_JIT_CLIENT_DOWNLOAD  "x_apps_client"

#define X_TO_SERVER_TABLE      "ANSEBC1140"
#define X_TO_CLIENT_TABLE      "EBC1140ANS"

#define X_SSV_GET_ROOT_DIR     "*ROOTDR"
#define X_SSV_ROOT_DIR_FLD     "ROOTDR              "
#define X_SSV_ROOT_DIR_FLD_LEN 256
#define X_SSV_GETBUILDNO       "*BLDNO"
#define X_SSV_BUILDNO_FLD      "BUILDNO             "
#define X_SSV_BUILDNO_FIELD_LEN  6
#define X_SSV_BUILDNO_BYTE_LEN   4
#define X_SSV_EPCCHECK         "*EPCCK"
#define X_SSV_EPC_LIST         "EPC_LST"
#define X_SSV_VERSION_FUNC     "*SSVVN"
#define X_SSV_LANGMAP          "*LANGMP"
#define X_SSV_LANGMAP_LIST     "LMAP_LST"
#define X_SSV_OBJECTNAMEMAP    "*NAMMAP"
#define X_SSV_OBJECTNAMEMAP_LIST "ONMAP_LST"
#define X_SSV_VERSION_FLD      "$VERSION            "
#define X_SSV_VERSION_BYTE_LEN 3
#define X_SSV_V1               1 /* Supports DLL Upgrade */
#define X_SSV_V2               2 /* Supports Package Upgrade */
#define X_UPGD_ALL             'A'
#define X_UPGD_REFRESH         'R'
#define X_UPGD_MISSING         'M' /* Missing DLLs only */
#define X_UPGD_TYPE_DLL        'D'
#define X_UPGD_TYPE_PACKAGE    'P'
#define X_UPGD_TYPE_NETWORKCLIENT     'C' // Implied MSI Upgrade for Network Client. Not usually passed on the command line. Typically derived from registry key not existing.

#define X_ASKC_REOPEN          'R'
/* If Ignore status set on a package, pretend pkg not known to client */
#define X_UPGD_FORCE_SKIP_IGNORE 'F'
/* Max line length in applpkg.txt is 256, allow for statuses and \r\n */
#define X_PARTIAL_OBJ_LENGTH (256 - X_PKG_NAME_LEN - 4)

#define APPLPKG_NEWNAME       "applpkg.txt"
#define APPLPKG_OLDNAME       "applpkg.dat"

#define FIRST_UPGD_SPPT_BUILD 1598 /* First build after 8.03 stripe, sppts upgrade/minim */

#define X_NAME_LEADING_REPLACE      'X'
#define X_NAME_NON_LEADING_REPLACE  '_'
#define X_NAME_NODENAMEKEY          "LX_NodeName"
#define X_FORMAT_JOBNUM             "%*.*ld"
#define X_DEFAULT_SERVER_NAME       "*NOMASTER"

#define X_PROCESS_NAME        'P'
#define X_COMPONENT_NAME      'C'
#define X_FUNCTION_NAME       'F'
#define X_SQLTABLE_NAME       'T'
#define X_JOBQUEUE_NAME       'J'
#define X_DATAQUEUE_NAME      'D'

#define X_PNL_DISPLAY         'D'
#define X_PNL_REQUEST         'R'
#define X_PNL_POPUP           'P'

#define X_FKEY_TOTAL           30
#define X_FKEY_NAME_LEN        10
#define X_FKEY_AID_LEN          2

#define X_MAX_COLUMN         1000

#define X_ALLOW_DROP_DOWNS      9
#define X_ALLOW_ID_STRINGS      3
#define X_ABOPT_PDOPT_LEN       3

/* Bit flags for Byte 20 of X_FLD.fchName or X_FLD2.chFieldInfo */
/* Refer to \\nt1\docs\desspec\VLFieldTypeAppCodeDS.doc      */
#define LL2FIELD     0x80 /* 10000000 in Binary                                  */
#define LL2NULLABLE  0x82 /* 10000010 in Binary                                  */
#define LL2FIXEDCHAR 0x84 /* 10000100 in Binary: If Char, blanks insignificant   */
#define LL2UNSINT    0x84 /* 10000100 in Binary: If Integer, unsigned            */
#define LL2SUTCDT    0x84 /* 10000100 in Binary: If Datetime, store in UTC       */
#define LL2DUTCDT    0x88 /* 10001000 in Binary: If Datetime, display in UTC     */

#define X_CLEAR_ALPHA            ' '
#define X_CLEAR_ALPHA_LOVAL      0x01
#define X_CLEAR_ALPHA_HIVAL      0xFF
#define X_CLEAR_PACK             0x00
#define X_CLEAR_SIGN             '0'
#define X_PACK_TERMINATOR        0x0F

#define X_EDIT_ERR_NO_ERROR       0
#define X_EDIT_ERR_DATA_NUMERIC  -1
#define X_EDIT_ERR_DATA_ALPHA    -2
#define X_EDIT_ERR_DECIMAL_POS   -3
#define X_EDIT_ERR_LEN_NUMERIC   -4
#define X_EDIT_ERR_LEN_ALPHA     -5
#define X_EDIT_ERR_LEN_DBCS      -6
#define X_EDIT_ERR_FORMAT_DATETIME  -7
#define X_EDIT_ERR_ATTRIB_VALIDATION -10

#define X_LOCK_STR_PERMANENT     "PERM"
#define X_LOCK_STR_FUNCTION      "FUNC"
#define X_LOCK_STR_JOB           "JOB"
#define X_LOCK_STR_ANY           "ANY"
#define X_LOCK_PERMANENT         'P'
#define X_LOCK_FUNCTION          'F'
#define X_LOCK_JOB               'J'
#define X_LOCK_ANY               'A'
#define X_LOCK_ID_ALL            "ALL"

#define X_LOCK_RET_OK            "OK"
#define X_LOCK_RET_ERROR         "ER"
#define X_LOCK_RET_IGNORE        "IG"

#define X_SAV_LIST_OK            "OK"
#define X_SAV_LIST_FULL          "OV"
#define X_SAV_LIST_NOTFOUND      "NR"

#define X_STRIP_BLANKS_LEADING   0x0001
#define X_STRIP_BLANKS_TRAILING  0x0002
#define X_STRIP_BLANKS_BOTH      0x0003

#define X_DBM_RETURN_CODE_LEN    2
#define X_DBM_TRIGGER_OPER_LEN   6

#define X_DLL_QUALIFIED_NAME_LENGTH      256
#define X_DLL_ENTRY_POINT_NAME_LENGTH     32
#define X_DLL_MAXIMUM_ENTRY_POINTS         4

#define X_DEFAULT_HEAVY_SYNC_TRIGGER     100
#define X_SHUTDOWN_UNLOADABLE            'U'
#define X_FORCE_UNLOAD                   'F'
#define X_ALWAYS_SKIP_UNLOAD             'Z'

#define X_INTERACTIVE_DESKTOP            'I'

#define X_EVENTLOG_ICON_DEFAULT           120   /* UID_ICON_DEFAULT  */
#define X_EVENTLOG_ICON_ERROR             121   /* UID_ICON_ERROR    */
#define X_EVENTLOG_ICON_EXCLAIM           122   /* UID_ICON_EXCLAIM  */
#define X_EVENTLOG_ICON_QUESTION          123   /* UID_ICON_QUESTION */
#define X_EVENTLOG_ICON_IMPORT01          124   /* UID_ICON_IMPORT01 */
#define X_EVENTLOG_ICON_IMPORT02          125   /* UID_ICON_IMPORT02 */
#define X_EVENTLOG_ICON_IMPORT03          126   /* UID_ICON_IMPORT03 */
#define X_EVENTLOG_ICON_IMPORT04          127   /* UID_ICON_IMPORT04 */
#define X_EVENTLOG_ICON_IMPORT05          128   /* UID_ICON_IMPORT05 */
#define X_EVENTLOG_ICON_IMPORT06          129   /* UID_ICON_IMPORT06 */
#define X_EVENTLOG_ICON_OK                130   /* UID_ICON_OK       */
#define X_EVENTLOG_ICON_EXPORT01          131   /* UID_ICON_EXPORT01 */
#define X_EVENTLOG_ICON_EXPORT02          132   /* UID_ICON_EXPORT02 */
#define X_EVENTLOG_ICON_EXPORT03          133   /* UID_ICON_EXPORT03 */
#define X_EVENTLOG_ICON_EXPORT04          134   /* UID_ICON_EXPORT04 */
#define X_EVENTLOG_ICON_EXPORT05          135   /* UID_ICON_EXPORT05 */
#define X_EVENTLOG_ICON_EXPORT06          136   /* UID_ICON_EXPORT06 */
#define X_EVENTLOG_ICON_PCTOPC01          137   /* UID_ICON_PCTOPC01 */
#define X_EVENTLOG_ICON_PCTOPC02          138   /* UID_ICON_PCTOPC02 */
#define X_EVENTLOG_ICON_PCTOPC03          139   /* UID_ICON_PCTOPC03 */
#define X_EVENTLOG_ICON_PCTOPC04          140   /* UID_ICON_PCTOPC04 */
#define X_EVENTLOG_ICON_PCTOPC05          141   /* UID_ICON_PCTOPC05 */
#define X_EVENTLOG_ICON_PCTOPC06          142   /* UID_ICON_PCTOPC06 */
#define X_EVENTLOG_ICON_CAN_IGNORE        143   /* Convert to X_EVENTLOG_ICON_DEFAULT */

/* Moved from x_lsvdef.h -- useful for I/O calls */
#define X_FILE_LIB_DFT                          "*LIBL     "
#define X_FILE_MBR_DFT                          "*FIRST    "

/* ================================================================= */
/*                     FORWARD DECLARATIONS                          */
/* ================================================================= */

struct  X_IDS;
struct  X_PRO;
struct  X_FUN;
struct  X_FLD;
struct  X_FKEY;
struct  FUNCTION_STATIC_GLOBAL_1;
struct  FUNCTION_STATIC_GLOBAL_2;
struct  X_FLD2;
struct  X_COMP_DISPATCH_INTERFACE;

/* All paramaters to functions use X_LIST_VOID unless handling a */
/* specific list version. Thus they must be cast before using.   */
typedef void X_LIST_VOID, * PX_LIST_VOID, ** PPX_LIST_VOID;

/* A long is used rather than unsigned long as there are work fields that */
/* must allow negative values for error states.                           */
typedef X_LONG X_LIST_COUNT;

/* ================================================================= */
/*  X_ZIP_DLL_TRACKING : Interface to Info-ZIP's zip & unzip libs    */
/* ================================================================= */
/* Name                     Description                              */
/* ----                     -----------                              */
/* hmodZipDLL               Pointer to zip library (zip32.dll)       */
/* hmodUnZipDLL             Pointer to zip library (unzip32.dll)     */
/* pfnZpArchive                                                      */
/* pfnZpGetOptions                                                   */
/* pfnZpInit                                                         */
/* pfnZpSetOptions                                                   */
/* pfnZpVersion                                                      */
/* pfnUzpVersion                                                     */
/* pfnUzpVersion2                                                    */
/* pfnWiz_SingleEntryUnzip                                           */
/* pfnWiz_Validate                                                   */
/* lpUserFuncs              Pointer to std USERFUNCTIONS for unzip   */
/*                                                                   */

struct X_ZIP_DLL_TRACKING 
{
   X_MODULEHANDLE hmodZipDLL;
   X_MODULEHANDLE hmodUnzipDLL;
   X_PFN          pfnZpInit;
   X_PFN          pfnZpGetOptions;
   X_PFN          pfnZpSetOptions;
   X_PFN          pfnZpArchive;
   X_PFN          pfnWiz_SingleEntryUnzip;
   X_PFN          pfnWiz_Validate;
   X_PVOID        lpUserFuncs;
};

/* ================================================================= */
/*  X_FILE_HANDLE: Platform independent file handle                  */
/* ================================================================= */
/*                                                                   */
/* Warning!: This structure is created by X_PDF_OpenFlatFile()       */
/* -------   and must not be modified outside the Flat File APIs     */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* fp              Pointer to file                                   */
/* fText           TRUE if text mode, false otherwise                */
/* fAppend         TRUE if append mode, false otherwise              */
/* fUpdate         TRUE if file is open in update mode, false other- */
/*                   wise                                            */
/* sLastOperation  Last operation performed on this file             */
/*                                                                   */

typedef struct _X_FILE_HANDLE
{
   X_PVOID   fp;
   X_BOOL    fTextMode;
   X_BOOL    fAppend;
   X_BOOL    fUpdate;
   X_SHORT   sLastOperation;
}  X_FILE_HANDLE,
  *X_PFILE_HANDLE;

/* ================================================================= */
/*  X_FILE_OPTIONS: Flat File APIs open options                      */
/* ================================================================= */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* fNoBuffering    TRUE to disable buffering, false otherwise        */
/* fRandomAccess   TRUE to optimise random access to the file, false */
/*                   otherwise                                       */
/* fSequential     TRUE if file is open in update mode, false other- */
/*                   wise                                            */
/* lBufferSize     Size of the buffer, if other than the runtime     */
/*                   default. If entered buffering is enabled        */
/*                   regardless of the value of fNoBuffering         */
/*                                                                   */

typedef struct _X_FILE_OPTIONS
{
   X_BOOL   fNoBuffering;
   X_BOOL   fRandomAccess;
   X_BOOL   fSequential;
   X_LONG   lBufferSize;
}  X_FILE_OPTIONS,
  *X_PFILE_OPTIONS;

/* ================================================================= */
/*  X_FILE_USAGE: Valid Flat File Access file open modes (usage)     */
/* ================================================================= */

typedef enum
{
   X_OPEN_READ_BIN,
   X_OPEN_READWRITE_BIN,
   X_OPEN_OVERWRITE_BIN,
   X_OPEN_OVERWRITEREAD_BIN,
   X_OPEN_APPEND_BIN,
   X_OPEN_APPENDREAD_BIN,
   X_OPEN_OVERWRITE_BIN_EXCL /* Currently does NOT lock on UNIX/iSeries */

   /* NOTE: Add new values at the end only */

} X_FILE_USAGE;


typedef struct _X_FILE_LIST
{
   X_VCHAR  vchName[X_CIPHER_NAME_LEN + 1];
   X_VCHAR  vchSuffix[4];
   X_USHORT usDay;
   X_USHORT usMonth;
   X_USHORT usYear;
   X_USHORT usHour;
   X_USHORT usMinute;
   X_USHORT usSecond;
} X_FILE_LIST;

/* ================================================================= */
/*  X_FILE_POS_ORIGIN: Valid Flat File Access file positioning       */
/*                     reference (offset origin)                     */
/* ================================================================= */

typedef enum
{
   X_SEEK_SET,
   X_SEEK_CUR,
   X_SEEK_END
} X_FILE_POS_ORIGIN;

/* ================================================================= */
/*  X_LIST_DATA : List page pointer                                  */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pData           Pointer to a list "page" of data                  */

struct X_LIST_DATA
{
   X_DEFS_LIST_DATA_PTR pData;
};

/* ================================================================= */
/*  X_TEXT_FILE_EXT_LIST: Holds a list of file extensions that we    */
/*                        consider to be text files.                 */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pchExt          Pointer to an extension                           */
/* pNext           Pointer to the next X_TEXT_FILE_EXT_LIST item     */
struct X_TEXT_FILE_EXT_LIST
{
   X_PCHAR                       pchExt;
   struct X_TEXT_FILE_EXT_LIST  *pNext;
};


/* ================================================================= */
/*  X_TRIGGER : Trigger function parameters                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Oper            Database operation about to be performed          */
/* Retc            Return code from trigger function                 */
/* RecLen          Database record length or field length            */
/* Current         Current database record image or field value      */
/* Previous        Previous database record image or field value     */

struct X_TRIGGER
{
   X_VCHAR  vchOper[X_DBM_TRIGGER_OPER_LEN+1];
   X_VCHAR  vchRetc[X_DBM_RETURN_CODE_LEN+1];
   X_SHORT  sRecLen;
   X_PVOID  pCurrent;
   X_PVOID  pPrevious;
};


/* ================================================================= */
/*  X_PARM   : LANSA/X Standardized Parameter Exchange Structure     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Type            Type of parameter                                 */
/* Name            Optional Name of parameter                        */
/* NumberOf        Optional Number of parameter                      */
/* Value           Pointer to value of parameter                     */

#define X_PARM_WORKING_LIST            20
#define X_PARM_DATA_STRUCTURE          30
#define X_PARM_PROCESS_PARM            40
#define X_PARM_SINGLE_VECTOR           50
#define X_PARM_LIST_OF_VECTOR          60
#define X_PARM_SYSVAR_STRUCTURE        70
#define X_PARM_VALIDATE_STRUCTURE      80
#define X_PARM_TRIGGER_STRUCTURE       90

#define X_PARM_BIF_VECTOR_ARGUMENT     100
#define X_PARM_BIF_VECTOR_RETURN_VALUE 110

#define X_PARM_BIF_LIST_ARGUMENT       120
#define X_PARM_BIF_LIST_RETURN_VALUE   140

#define X_PARM_BIF_CALLER_PX_FUN       150
#define X_PARM_BIF_CALLER_PX_BIF       160

#define X_PARM_BIF_DEFAULT_ARG_INFO    170   /* Information about BIF argument defaults      */
#define X_PARM_BIF_DEFAULT_RET_INFO    180   /* Information about BIF return values defaults */

#define X_PARM_UPID_OFFSET             190

struct X_PARM
  {
     X_SHORT         sType;
     X_VCHAR         vchName[X_OBJECT_NAME_LEN+1];
     X_SHORT         sNumberOf;
     X_PVOID         pValue;
  } ;

struct X_UPID_OFFSET
{
   X_ULONG  ulOffset;
   X_INT    iLength;
};

/* Allowable values for chType */

#define X_BIFPARM_NUMERIC  'N'
#define X_BIFPARM_ALPHA    'A'
#define X_BIFPARM_LIST     'L'
#define X_BIFPARM_EITHER   'X'

typedef struct _X_BIFPARM
  {
     X_SHORT    sSequence;
     X_BOOL     fRequired;
     X_CHAR     chType;
     X_SHORT    sStorageVector;
     X_USHORT   usMinLength;
     X_USHORT   usMaxLength;
     X_USHORT   usMinDecimals;
     X_USHORT   usMaxDecimals;
     X_SHORT    sDefaultValueVector;
  }      X_BIFPARM,
     *  PX_BIFPARM,
    ** PPX_BIFPARM;

typedef struct _X_RDML_BIF_DEFAULT
  {
     X_CHAR   chType;             /* Argument or return values Type */
     X_SHORT  sPassLength;        /* Pass length from LX_F48        */
     X_SHORT  sPassDecimals;      /* Pass decimals from LX_F48      */
     X_VCHAR  vchDefault[10 + 1]; /* Default value from LX_F48      */
  }   X_RDML_BIF_DEFAULT,
    * PX_RDML_BIF_DEFAULT ;

/* ================================================================= */
/*  X_MSGT  : LANSA/X Message Tracking Block  (STANDARD FOMAT)       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* MsgFormat       Storage Format of this message                    */
/* MsgId           Message Id                                        */
/* MsgF            Message File Name                                 */
/* NextMsg         Pointer to next Message (pX_NULL = no more)       */
/* MsgDtaLen       Message Data (ie: substitution variables) Length  */
/* MsgDta          Message Data (aggregated with no EOS delimiters)  */

#ifndef X_OPERATING_TARGET_CSHARP

struct X_MSGT
  {
     X_CHAR          chMsgFormat;
     X_VCHAR         vchMsgid[X_MESSAGE_ID_LEN+1];
     X_VCHAR         vchMsgF[X_OBJECT_NAME_LEN+1];
     struct X_MSGT * pNextMsg;
     X_LONG          lMsgDtaLen;
     X_FCHAR         fchMsgDta[X_MESSAGE_DATA_LEN];
  } ;

#endif // X_OPERATING_TARGET_CSHARP

/* ================================================================= */
/*  X_MSGT_EXT : LANSA/X Message Tracking Block (EXTENDED FORMAT)    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* MsgFormat       Storage Format of this message                    */
/* MsgId           Message Id                                        */
/* MsgF            Message File Name                                 */
/* NextMsg         Pointer to next Message (pX_NULL = no more)       */
/* MsgTxtLen       Length of Message Text                            */
/* MsgTxt          Message Text                                      */
/* SecTxtLen       Length of Second Level Text                       */
/* SecTxt          Second Level Text                                 */

#ifndef X_OPERATING_TARGET_CSHARP

struct X_MSGT_EXT
  {
     X_CHAR          chMsgFormat;
     X_VCHAR         vchMsgid[X_MESSAGE_ID_LEN + 1];
     X_VCHAR         vchMsgF[X_OBJECT_NAME_LEN + 1];
     struct X_MSGT * pNextMsg;
     X_LONG          lMsgTxtLen;
     X_FCHAR         fchMsgTxt[X_MAX_FIRST_LEVEL_TEXT];
     X_LONG          lSecTxtLen;
     X_FCHAR         vchSecTxt[X_MAX_SECOND_LEVEL_TEXT];
  } ;

#endif // X_OPERATING_TARGET_CSHARP

/* ================================================================= */
/*  X_Invoc : LANSA/X Process/Function Invocation Tracking           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Type            Type of Entry ('P' = Process, 'F' = Function      */
/* Process         Process Name                                      */
/* Function        Function Name                                     */
/* ShutDown        Shutdown this object after invocation             */
/* FirstMsg        First Message                                     */
/* LastMsg         Last Message                                      */
/* CurrMsg         Current Message for X_Next_Message                */

#define X_MAX_INVOCATION_DEPTH          250
#define X_MAX_INVOCATION_DEPTH_FIXED    50
#define X_MAX_PROCESS_INVOCATION_DEPTH  9

struct X_INVOC
  {
     X_CHAR          chType;
     X_VCHAR         vchProcess[X_OBJECT_NAME_LEN+1];
     X_VCHAR         vchFunction[X_FUNCTION_NAME_LEN + 1];
     X_YES_NO        chShutDown;
     X_SHORT         sProMenuEntry;
     struct X_MSGT * pFirstMsg;
     struct X_MSGT * pLastMsg;
     struct X_MSGT * pCurrMsg;
  } ;

/* ================================================================= */
/*  X_Invoc_Tracking : LANSA/X Process/Function Invocation Tracking  */
/*  NO REFERENCES TO ELEMENTS OF THIS STRUCTURE ARE ALLOWED IN       */
/*  GENERATED RDML CODE .... ONLY IN EXTERNAL COMPILED COMPONENTS    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sTotalDRPExec   Total DISPLAY/REQUEST/POP_UPs executed            */

struct X_INVOC_TRACKING
  {
     X_SHORT          sTotalDRPExec;
     struct X_MSGT  * pNextBIF021Msg;
     struct X_FUN   * pX_Fun;
  } ;


/* ================================================================= */
/*  X_Exchl : LANSA/X Exchange List                                  */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sEntryTot       Number of entries in exchange list                */
/* sNextPos        Position of next spare item                       */
/* fchData         Buffer holding exchange list data                 */

struct X_EXCHL
  {
     X_SHORT         sEntryTot;
     X_SHORT         sNextPos;
     X_FCHAR         fchData[X_EXCHANGE_LIST_LEN];
  } ;

#define X_LL2EXCHL X_VOID
/* ================================================================= */
/*  X_EXCHL2 : LANSA/X Exchange List 2 - To hold LL2 Exchange List   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/*                                                                   */
/* pLL2Exch       pointer to a LL2 exchange list                     */
/*                                                                   */
/* ================================================================= */
typedef struct _X_EXCHL2
   {
      X_LL2EXCHL *   pLL2Exch;      /* pointer to a LL2 exchange list*/
      X_UINT16       usLL1Fields;   /* number of LL1 fields in the exchange list*/
      X_UINT16       usLL2Fields;   /* number of LL2 fields in the exchange list*/
   } X_EXCHL2, *PX_EXCHL2;

#include "x_strpck.h" /* 111573 Force single-byte alignment */

typedef X_PACKED struct _X_SAVE_EXCHANGE_LIST_HEADER
   {
      X_INT32  lVersion   ;      /* TN: -1 for 10.7*/
      X_UINT16 usLL1Fields;      /* Count of number of LL1 fields in the exchange list. */
      X_UINT16 usLL2Fields;      /* Count of number of LL2 fields in the exchange list. */
   }   X_SAVE_EXCHANGE_LIST_HEADER, *PX_SAVE_EXCHANGE_LIST_HEADER;

typedef X_PACKED struct _X_SAVE_EXCHANGE_LIST_FIELD
   {
      X_FCHAR fchName[X_OBJECT_NAME_LEN];       /* TN: The field name */
      X_CHAR chFieldInfo;        /* TN: originally from X_FLD*/
      X_CHAR chType;             /* chType or chSubType (originally from X_FLD, chSubType used if type was a component) */
      X_INT32 lFieldState;       /* bFieldState (from X_FLD_XXXX). Set to 0 for LL1 fields. */
      X_UINT32 ulCurrLen;        /* The number of bytes of data following. */
                                 /* If the field state indicates that the field is SQL NULL then ulCurrLen will be 0.*/
                                 /* */
                                 /* For fields of type Char & Binary (i.e. stored as X_VAR), */
                                 /* this is the result of calling X_VAR_VarChar_GetCurSize() +1 */
                                 /* or X_VAR_VarBinary_GetCurSize(). */

                                 /* It is assumed this size includes the null terminator for fields of type Char.*/
                                 /* For field of type BLOB & CLOB, if chLOBContents is 0x01, */
                                 /* this is the length of the data (contents) being saved; */
                                 /* otherwise it is the strlen of the filename + 1. */
                                 /* For fields of other types, it is the strlen of the data*/
      X_VCHAR  vchValue[1];
   }  X_SAVE_EXCHANGE_LIST_FIELD, *PX_SAVE_EXCHANGE_LIST_FIELD, **PPX_SAVE_EXCHANGE_LIST_FIELD;

typedef struct _X_EXCHANGE_LIST_FIELD_INFO
   {
      X_CHAR chFieldInfo;        /* TN: originally from X_FLD*/
      X_CHAR chType;             /* chType or chSubType (originally from X_FLD, chSubType used if type was a component) */
      X_INT32 lFieldState;       /* bFieldState (from X_FLD_XXXX). Set to 0 for LL1 fields. */
      X_UINT32 ulCurrLen;
   }  X_EXCHANGE_LIST_FIELD_INFO , *PX_EXCHANGE_LIST_FIELD_INFO  ;

/* ================================================================= */
/*  X_Exchlist_Header : LANSA/X Exchange List Header                 */
/* ================================================================= */



typedef X_PACKED struct X_EXCHANGE_LIST_HEADER
  {
     X_FCHAR  fchName[X_OBJECT_NAME_LEN];
     X_CHAR   chType;
     X_INT16  sLen_Damn;
     X_INT16  sDec_Damn;
     X_VCHAR  vchValue[1];
  }  X_EXCHANGE_LIST_HEADER;

#if defined(X_OPERATING_SYSTEM_SOL)

#define GET_EXCHANGE_LIST_ITEM_LEN(__e__, __l__) { \
   X_SHORT __s__; \
   memcpy(&__s__, &((__e__)->sLen_Damn), sizeof(X_SHORT)); \
   (__l__) = __s__; \
}

#define SET_EXCHANGE_LIST_ITEM_LEN(__e__, __l__) { \
   X_SHORT __s__ = (X_SHORT)(__l__); \
   memcpy(&((__e__)->sLen_Damn), &__s__, sizeof(X_SHORT)); \
}

#define GET_EXCHANGE_LIST_ITEM_DEC(__e__, __d__) { \
   X_SHORT __s__; \
   memcpy(&__s__, &((__e__)->sDec_Damn), sizeof(X_SHORT)); \
   (__d__) = __s__; \
}

#define SET_EXCHANGE_LIST_ITEM_DEC(__e__, __d__) { \
   X_SHORT __s__ = (X_SHORT)(__d__); \
   memcpy(&((__e__)->sDec_Damn), &__s__, sizeof(X_SHORT)); \
}

#else

#define GET_EXCHANGE_LIST_ITEM_LEN(__e__, __l__) { \
   (__l__) = (__e__)->sLen_Damn; \
}

#define SET_EXCHANGE_LIST_ITEM_LEN(__e__, __l__) { \
   (__e__)->sLen_Damn = (X_SHORT)(__l__); \
}

#define GET_EXCHANGE_LIST_ITEM_DEC(__e__, __d__) { \
   (__d__) = (__e__)->sDec_Damn; \
}

#define SET_EXCHANGE_LIST_ITEM_DEC(__e__, __d__) { \
   (__e__)->sDec_Damn = (__d__); \
}

#endif

#include "x_endpck.h"

/* ================================================================= */
/*  X_EXTENDED_EXCHL : LANSA/X Exchange List (Extended)              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sEntryTot       Current number of items on list                   */
/* sNextPos        Position for next item within 'pvchData'          */
/* sDataSize       Size of buffer at 'pvchData'                      */
/* pvchData        Buffer holding 'sEntryTot' X_EXCHANGE_LIST_HEADERs*/

struct X_EXTENDED_EXCHL
  {
     X_SHORT         sEntryTot;
     X_SHORT         sNextPos;
     X_SHORT         sDataSize;
     X_PVCHAR        pvchData;
  } ;

/* ================================================================= */
/*  X_WEB_INFO : LANSA/X WEB-JOB Information                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sVersion        Version number of this struct (not currently used)*/
/* fchJobNumber    Web Job Identifier                                */
/* chPersistFrame  'Y' if frame has been sent                        */
/* chHomeKey       'Y' if Home key is present                        */
/* chHeaderStyle   'Y' if page uses header                           */
/* chFramesetStyle 'Y' if page uses frames                           */
/* chMultiLingual  'Y' if multilingual                               */
/* chKeyAlignRight 'Y' if keys are right-aligned                     */
/* sButtonsInHeader Holds number of buttons if header style          */
/* sEnabledButtons Holds number of enabled buttons                   */
/* chUseIFS        'Y' if to use IFS files else 'N'                  */
/* chRunType       'B' if using browser, 'N' if 'Green Screen'       */
/* fchIFSFileName   IFS File name                                    */
/* fchIFSFileSuffix IFS File name suffix                             */
/* fchIFSCodePage   IFS Code Page                                    */
/* fchIFSFileExtension        IFS Filename extension                 */
/* chDebugWebEvent  'Y' to debug web-events else 'N'                 */
/* fchParentProcess Identifies parent process                        */
/* fchSetNumber     Set number of HTML pages                         */
/* chRemote         'L' if local system else 'R'                     */
/* fchWebTraceId    Trace ID used in P1400                           */

#define X_WEB_JOB_ID_LENGTH      (6+1)

struct X_WEB_INFO
  {
     X_SHORT                  sVersion;
     X_FCHAR                  fchJobNumber[X_WEB_JOB_ID_LENGTH];
     X_CHAR                   chPersistFrame;
     X_CHAR                   chHomeKey;
     X_CHAR                   chHeaderStyle;
     X_CHAR                   chFramesetStyle;
     X_CHAR                   chMultiLingual;
     X_CHAR                   chKeyAlignRight;
     X_CHAR                   sButtonsInHeader;
     X_CHAR                   sEnabledButtons;
     X_CHAR                   chRunType;
     X_CHAR                   chUseIFS;
     X_FCHAR                  fchIFSFileName[20 + 1];
     X_FCHAR                  fchIFSFileSuffix[10 + 1];
     X_FCHAR                  fchIFSPath[256 + 1];
     X_FCHAR                  fchIFSCodePage[5 + 1];
     X_FCHAR                  fchIFSFileExtension[8 + 1];
     X_CHAR                   chDebugWebEvent;
     X_FCHAR                  fchParentProcess[10 + 1];
     X_FCHAR                  fchSetNumber[2 + 1];
     X_CHAR                   chRemote;
     X_FCHAR                  fchWebTraceId[15 + 1];

  } ;

/* ================================================================= */
/*  X_DBCS_BYTE_2 : DBCS Conversion Tables                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* psBytes2        Pointer to Byte 2 Data                           */

struct X_DBCS_BYTE_2
  {
     X_PUSHORT     psBytes2;
  } ;

/* ================================================================= */
/*  X_LANGUAGE : Language type definitions                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* LangCode         Language Code                                    */
/* LangType         Language Type                                    */
/* pNextLanguage    Next Language in the Language chain              */

struct X_LANGUAGE
  {
     X_VCHAR            vchLangCode[X_LANGUAGE_CODE_LEN + 1];
     X_TYPE_FLAG        chLangType;
     struct X_LANGUAGE *pNextLanguage;
     X_BOOL             fDevelopmentLanguage;
     X_VCHAR            vchX60SP1[X_LANGUAGE_SPARE_LEN + 1];
     X_BOOL             fDefaultLanguage;
     X_VCHAR            vchCharSet[X_LANGUAGE_CHAR_SET_LEN + 1];
  } ;

/* ================================================================= */
/*  X_CONNECT_COMPUTER : Remotely connected Computer                 */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Version Number of this structure                  */
/* SSN             Server Symbolic Name                              */
/* Connected       Currently Connected Flag                          */
/* AllocConfirmed  Allocate Confirmation Pending                     */
/* FatalError      Fatal error has occured during processing         */
/* LUName          Logical Unit Name                                 */
/* TPName          Name of Transaction Processing Program            */
/* CID             Communication Session Identifier                  */
/* ClientPriority  Execution Prority on Server                       */
/* DBCSCapable     DBCS Capable System Flag                          */
/* StartUpMessage  Start up message displayed during connection      */
/* ClienttoServerTableN Client to Server Conversion Table Name       */
/* ServertoClientTableN Server to Client Conversion Table Name       */
/* ClienttoServerCTable Client to Server Conversion Table            */
/* ServertoClientCTable Server to Client Conversion Table            */
/* CommitControl   Uses Commitment Control                           */
/* CommitControl   Uses Commitment Control                           */
/* InBufferNextPos Next Position to process in the input buffer      */
/* pInBuffer       Pointer to Input Buffer                           */
/* BytesOutBuffer  Bytes Currently in the input buffer               */
/* pOutBuffer      Pointer to OutputBuffer                           */
/* DBCS_CtoS       DBCS Client to Server Conversion Tables           */
/* DBCS_StoC       DBCS Server to Client Conversion Tables           */
/* LockObjects     Object Locks should be sent to this server        */
/* ConversationId  Conversation Id (EHNAPPC style communications)    */
/* InSendState     Connection is in a send state                     */
/* ConnectionType  Type of connnection to this computer              */
/* pvchTempArea    Dedicated buffer area                             */
/* pvTableUsage    Track tables open on this connection              */
/* RouteAuthorityChecks Route Authority checks to this server        */
/* RouteRepository Routes info requests to server if not found local */
/* fPSRR           True indicates internally created OS/400 server   */
/*                 for SuperServer without Sysexport via RPG server  */
/* fUseKerberos    True indicates Kerberos authentication            */
/* SavedUser       OS/400 only: User to use for PSRR server.         */
/* SavedPswd       OS/400 only: Password to use for PSRR server.     */
/* pDBMSInfo       Server DBMSInfo array for each DBMS type          */
/* scDBMSInfo      Count of number of elements in array              */
/* lReturnCode     Last return code, currently only implemented for X_Open_Communications */
/* ulTempAreaSize  # bytes allocated in pvchTempArea                 */
/* lOtherEndBuildNumber 0 if other end's build # is unknown          */
/* chClientType    0x00 by default meaning normal SuperServer        */

#define X_CONNECT_COMPUTER_V1           -2
#define X_CONNECT_COMPUTER_V2           -3
#define X_CONNECT_COMPUTER_V3           -4
#define X_CONNECT_COMPUTER_V4           -5
#define X_CONNECT_COMPUTER_V5           -6
#define X_CONNECT_COMPUTER_V6           -7
#define X_CONNECT_COMPUTER_V7           -8
#define X_CONNECT_COMPUTER_V8           -9
#define X_CONNECT_COMPUTER_V9           -10
#define X_CONNECT_COMPUTER_CURRENT      X_CONNECT_COMPUTER_V9  // Change this when a new version is added

#define X_CONNECT_SSN_LENGTH            10

#define X_CONNECT_INPUT_BUFFER_SIZE   85000
#define X_CONNECT_OUTPUT_BUFFER_SIZE  85000

#define X_CONNECT_CPIC_LUNAME_LENGTH    20
#define X_CONNECT_CPIC_TPNAME_LENGTH    10
#define X_CONNECT_CPIC_CID_LENGTH        8

#define X_CONNECT_TYPE_CLIENT_TO_OS400       '\x00'
#define X_CONNECT_TYPE_CLIENT_TO_OTHER       '\x10'
#define X_CONNECT_TYPE_SERVER_FOR_LSERVER    '\x20'
#define X_CONNECT_TYPE_SERVER_FOR_XSERVER    '\x30'
#define X_CONNECT_TYPE_CLIENT_TO_VL400       '\x40'
#define X_CONNECT_TYPE_CLIENT_TO_UNKNOWN     '\x50'

#define X_CONNECT_CLIENT_TYPE_STANDARD    '\x00'

struct X_CONNECT_COMPUTER
  {
     X_SHORT              sVersion;
     X_VCHAR              vchSSN[X_CONNECT_SSN_LENGTH + 1];
     X_YES_NO             chConnected;
     X_YES_NO             chAllocConfirmed;
     X_YES_NO             chFatalError;
     X_VCHAR              vchLUName[X_CONNECT_CPIC_LUNAME_LENGTH + 1];
     X_VCHAR              vchTPName[X_CONNECT_CPIC_TPNAME_LENGTH + 1];
     X_FCHAR              fchCID[X_CONNECT_CPIC_CID_LENGTH];
     X_FCHAR              fchClientPriority[2];
     X_YES_NO             chDBCSCapable;
     X_YES_NO             chStartUpMessage;
     X_FCHAR              fchClienttoServerTableN[X_OBJECT_NAME_LEN];
     X_FCHAR              fchServertoClientTableN[X_OBJECT_NAME_LEN];
     X_FCHAR              fchClienttoServerCTable[256];
     X_FCHAR              fchServertoClientCTable[256];
     X_YES_NO             chCommitControl;
     struct X_CONNECT_COMPUTER * pNextConnectComputer;
     X_LONG               lInBufferNextPos;
     X_LONG               lBytesInBuffer;
     X_VCHAR              vchInBuffer[X_CONNECT_INPUT_BUFFER_SIZE];
     X_LONG               lBytesOutBuffer;
     X_VCHAR              vchOutBuffer[X_CONNECT_OUTPUT_BUFFER_SIZE];
     struct X_DBCS_BYTE_2 DBCS_CtoS[256];
     struct X_DBCS_BYTE_2 DBCS_StoC[256];
     X_YES_NO             chLockObjects;
     X_ULONG              ulConversationId;
     X_BOOL               fInSendState;
     X_CHAR               chConnectionType;
     X_VCHAR              vchXRUNExceptArgs[256 + 1];
     X_VCHAR              vchServerExceptArgs[256 + 1];
     X_PVOID              pvNetObjectCluster;
     X_PVCHAR             pvchTempArea;
     X_PVOID              pvQueues;
     X_PVOID              pvTableUsage;
     X_YES_NO             chRouteAuthorityChecks;
     X_YES_NO             chRouteRepository;
     X_YES_NO             chSystemAuthoritiesSent;
     X_BOOL               fPSRR;
     X_BOOL               fUseKerberos;
     X_PVCHAR             pvchSavedUser;
     X_PVCHAR             pvchSavedPswd;
     struct X_CTD_DBMS_INFO ** apDBMSInfo;
     X_SHORT              scDBMSInfo;
     X_LONG               lReturnCode;
     X_ULONG              ulTempAreaSize;
     X_BOOL               fByPassServerError;
     X_LONG               lDownloadBuildNumber; /* For Server. Only altered by Client calling DownLoadBuild, which it should only do if a 12.0 client. */
     X_LONG               lOtherEndBuildNumber;
     X_CHAR               chClientSSVType;      /* Only used on Server. */
  };

/* ================================================================= */
/*  X_COMPOSER_CONNECT : External connected database                 */
/* ================================================================= */
/* Name                 Description                                  */
/* ----                 -----------                                  */
/* vchSSN               Server Symbolic Name                         */
/* vchPartition         Server Partition Id                          */
/* vchSystemPath        Server System Path                           */
/* vchUserId            Server User Id                               */
/* vchPassword          Server Password                              */
/* vchDatabase          Server Database                              */
/* vchDatabaseType      Server Database Type                         */
/* vchDatabaseUserId    Server Database User Id                      */
/* vchDatabasePassword  Server Database Password                     */
/* vchOverrides         Server Parameter overrides                   */
/* chServerLog          Server Log                                   */
/* chFatalError         Connection Status                            */

struct X_COMPOSER_CONNECT
{
   X_VCHAR                       vchSSN[X_CONNECT_SSN_LENGTH + 1];
   X_VCHAR                       vchPartition[X_PARTITION_NAME_LEN + 1];
   X_VCHAR                       vchSystemPath[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                       vchUserId[X_MAX_USER_NAME_LEN + 1];
   X_VCHAR                       vchPassword[X_MAX_PASSWORD_LEN + 1];
   X_VCHAR                       vchDatabase[X_DSN_NAME_LEN + 1];
   X_VCHAR                       vchDatabaseType[X_CTD_VALUE_LENGTH + 1];
   X_VCHAR                       vchDatabaseUserId[X_CURRENT_USER_NAME_LEN + 1];
   X_VCHAR                       vchDatabasePassword[X_CURRENT_PASSWORD_LEN + 1];
   X_VCHAR                       vchOverrides[X_MAX_PARAMETER_VALUE_LEN + 1];
   X_YES_NO                      chServerLog;
   X_YES_NO                      chFatalError;
   struct X_COMPOSER_CONNECT *   pNextComposerConnect;
};

/* ================================================================= */
/*  X_CONNECT_DATABASE : External connected database                 */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Version Number of this structure                  */
/* SSN             Server Symbolic Name                              */
/* DatabaseId      DSN or ORACLE_SID                                 */
/* Parameters      Connection override parameters e.g. UID=xxx;PWD=x */
/* RRNPath         Alternative RRN Path                              */
/* DatabaseType    Valid types are those in x_dbmenv.dat             */
/* Connected       Currently Connected Flag                          */
/* FatalError      Fatal error has occured during processing         */
/* Encrypted       Y if Parameters and Spare are encrypted           */
/* ODBA            If not blank, overrides the ODBA= parameter       */
/* ODBI            If not blank, overrides the ODBI= parameter       */
/* pConnectionInfo If Windows, a Tree of X_ODBC_CONNECTIONs          */
/* pDBMSInfo       Pointer to info about the database type           */
/* Next            Next database in the list                         */
/* pfnUserIO       Function ptr for normal user IO                   */
/* pfnUserIONative Function ptr for native IO, currently only iSeries*/
/* pfnInternalIO;  Same as pfnUserIO, but Internal IO                */
/* pfnInternalIONative; Same as pfnUserIONative, but internal IO.    */
/* ActiveTransaction True if Commit/Rollback pending                 */
/* NativeOpenCommitError True if SQL conn and no Commit Defn existed */

#define X_LOCAL_DB_SSN             "*LOCALDB"
#define X_REMOTE_DB_SSN_PREFIX     "*REMOTE"
#define X_REMOTE_DB_SSN_PREFIX_LEN 7

#define X_CONNECT_DB_V1           -1
#define X_CONNECT_DB_V2           -2
#define X_CONNECT_DB_V3           -3
#define X_CONNECT_DB_V4           -4
#define X_CONNECT_DB_V5           -5
#define X_CONNECT_DB_V2_OR_LATER     (pX_DBM->pDatabase->sVersion <= X_CONNECT_DB_V2)
#define X_CONNECT_DB_NOT_V2_OR_LATER (pX_DBM->pDatabase->sVersion >  X_CONNECT_DB_V2)
#define X_CONNECT_DB_V3_OR_LATER     (pX_DBM->pDatabase->sVersion <= X_CONNECT_DB_V3)
#define X_CONNECT_DB_NOT_V3_OR_LATER (pX_DBM->pDatabase->sVersion >  X_CONNECT_DB_V3)
#define X_CONNECT_DB_V4_OR_LATER     (pX_DBM->pDatabase->sVersion <= X_CONNECT_DB_V4)
#define X_CONNECT_DB_NOT_V4_OR_LATER (pX_DBM->pDatabase->sVersion >  X_CONNECT_DB_V4)
#define X_CONNECT_DB_V5_OR_LATER     (pX_DBM->pDatabase->sVersion <= X_CONNECT_DB_V5)
#define X_CONNECT_DB_NOT_V5_OR_LATER (pX_DBM->pDatabase->sVersion >  X_CONNECT_DB_V5)


struct X_CONNECT_DATABASE
{
   X_SHORT                       sVersion;
   X_VCHAR                       vchSSN[X_CONNECT_SSN_LENGTH + 1];
   X_VCHAR                       vchDatabaseId[X_DSN_NAME_LEN + 1];
   X_VCHAR                       vch_DEPRECATE_Parameters[500 + 1];
   X_VCHAR                       vchRRNPath[256 + 1];
   X_VCHAR                       vchDatabaseType[X_CTD_VALUE_LENGTH + 1];
   X_YES_NO                      chConnected;
   X_YES_NO                      chFatalError;
   X_CHAR                        chEncrypted;
   X_CHAR                        chODBA;
   X_CHAR                        chODBI;
   X_PVOID                       pConnectionInfo;
   struct X_CTD_DBMS_INFO     *  pDBMSInfo;
   struct X_CONNECT_DATABASE  *  pNext;
   X_PVOID                       pfnUserIO;
   X_PVOID                       pfnUserIONative;
   X_BOOL                        fActiveTransaction;
   X_VCHAR                       vchParameters[X_CTD_CONNECT_PARMS_LENGTH + 1];
   X_BOOL                        fNativeOpenCommitError;
};

/* ================================================================= */
/*  X_CONNECT_FILE : Remotely connected File                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Version Number of this structure                  */
/* FileName        Name of this connected file                       */
/* ConnectComputer Pointer to connected computer for this file       */
/* NextConnect     Pointer to next connected file                    */
/* BlockSize       Number of records in a block for a SELECT request */
/* SelectLimit     Maximum number of records returned for a SELECT   */
/* ConnectDatabase (when ConnectComputer is NULL)                    */

#define X_CONNECT_FILE_V1           -1
#define X_CONNECT_FILE_V2           -2

struct X_CONNECT_FILE
  {
     X_INT16                   sVersion;
     X_VCHAR                   vchFileName[X_OBJECT_NAME_LEN + 1];
     struct X_CONNECT_COMPUTER *pConnectComputer;
     struct X_CONNECT_FILE     *pNextConnectFile;
     X_INT32                   lBlockSize;
     X_INT32                   lSelectLimit;
     struct X_CONNECT_DATABASE *pConnectDatabase;
  };

/* ================================================================= */
/*  X_CONNNECT_AUTO : Automatic connected computer details           */
/*                    collected from the X_RUN command               */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Version Number of this structure                  */
/* SSN             Server Symbolic Name                              */
/* LUName          Logical Unit Name                                 */
/* ClientPriority  Execution Prority on Server                       */
/* DBCSCapable     DBCS Capable System Flag                          */
/* StartUpMessage  Start up message displayed during connection      */
/* ClienttoServerTableN Client to Server Conversion Table Name       */
/* ServertoClientTableN Server to Client Conversion Table Name       */
/* CommitControl   Uses Commitment Control                           */
/* LockObjects     Divert Object Locks                               */
/* Password        Password                                          */
/* ConnectionType  Type of connnection to this computer              */
/* RouteAuthorityChecks Route Authroity requests to this server      */
/* RouteRepository Routes info requests to server if not found local */


#define X_CONNECT_AUTO_V1           -1
#define X_CONNECT_AUTO_V2           -2
#define X_CONNECT_AUTO_V3           -3
#define X_CONNECT_AUTO_V4           -4
#define X_CONNECT_AUTO_V5           -5
#define X_CONNECT_AUTO_V6           -6
#define X_CONNECT_AUTO_V7           -7

struct X_CONNECT_AUTO
  {
     X_SHORT       sVersion;
     X_VCHAR       vchSSN[X_CONNECT_SSN_LENGTH + 1];
     X_VCHAR       vchLUName[X_CONNECT_CPIC_LUNAME_LENGTH + 1];
     X_VCHAR       vchClientPriority[2 + 1];
     X_YES_NO      chDBCSCapable;
     X_YES_NO      chStartUpMessage;
     X_FCHAR       vchClienttoServerTableN[X_OBJECT_NAME_LEN + 1];
     X_FCHAR       vchServertoClientTableN[X_OBJECT_NAME_LEN + 1];
     X_YES_NO      chCommitControl;
     X_YES_NO      chLockObjects;
     X_VCHAR       vchXRUNPassword[X_CURRENT_PASSWORD_LEN + 1];    /* May be in lower case */
     X_CHAR        chConnectionType;
     X_YES_NO      chRouteAuthorityChecks;
     X_VCHAR       vchClienttoServerQueueN[X_OBJECT_NAME_LEN + 1];
     X_VCHAR       vchServertoClientQueueN[X_OBJECT_NAME_LEN + 1];
     X_VCHAR       vchWorkstationName[X_OBJECT_NAME_LEN + 1];
     X_VCHAR       vchXRUNUser[X_CURRENT_USER_NAME_LEN + 1];  /* May be in lower case */
     X_YES_NO      chRouteRepository;
     X_BOOL        fUseKerberos;
  };

/* ================================================================= */
/*  X_UBIF_TRACKING : Track user defined builtin functions           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sUID            Unique identifier from LX_F47                     */
/* pfEntryPoint    Pointer to entry point address                    */
/* pNextUBIF       Pointer to next U_BIF_TRACKING structure in chain */
/* hModule         OS/2 only "handle" to DLL                         */

struct X_UBIF_TRACKING
  {
     X_SHORT                  sUID;
     X_PVOID                  pfEntryPoint;
     struct X_UBIF_TRACKING * pNextUBIF;
     X_MODULEHANDLE            hModule;
  } ;

/* ============================================== */
/* Database connection types and update channels  */
/*                                                */
/* struct X_ODBC_CONNECTION moved into x_dbm1.c   */
/* ============================================== */

#define X_ODBC_READ_CONNECTION              'R'
#define X_ODBC_UPDATE_CONNECTION            'U'
#define X_ODBC_UPDATE_CONNECTION_MIXED_MODE 'M'
#define X_ODBC_READ_UNCOMMITTED_CONNECTION  'D'

#define X_ODBC_DEFAULT_UPDATE_CONNECTION     X_ODBC_UPDATE_CONNECTION

#define X_COMMIT_ROLLBACK_UPDATE_CHANNEL_1         '1'
#define X_COMMIT_ROLLBACK_ALL_UPDATE_CHANNELS      'A'
#define X_COMMIT_ROLLBACK_UPDATE_DEFAULT           X_COMMIT_ROLLBACK_ALL_UPDATE_CHANNELS

#define ODBI_OPTION \
   (pDatabase->chODBI == BLANK ? pX_Ids->chODBCIOption : pDatabase->chODBI)

/* ================== */
/* LOB handling stuff */
/* ================== */

#define X_LOB_DISK_FILE_LEN 12 /* 8 + . + 3 */
#define X_LOB_SECURE 'S'
#define X_LOB_CACHED 'C'

/* This is used for temporary LOB files when not associated with a PF/LF */
/* USEPID should be FALSE when file must outlast caller's session */
#define X_SET_LOB_TEMP_PATH(_BUFF,_USEPID) \
   if (pX_Ids->fWebRoutineExecution && pX_Ids->pszWamLobTempDir != NULL) \
   { \
      strcpy(_BUFF, pX_Ids->pszWamLobTempDir); \
      pX_Ids->fWamLobTempDirUsed = TRUE; \
   } \
   else if ( _USEPID ) \
   { \
      sprintf(_BUFF,"%slobuser%c%s%c%s%c", \
              pX_Ids->vchLOBRoot, \
              X_PATH_SEPARATOR, \
              pX_Ids->pX_IdsOS->vchOSUser, \
              X_PATH_SEPARATOR, \
              pX_Ids->pX_IdsOS->vchPID, \
              X_PATH_SEPARATOR); \
   } \
   else \
   { \
      sprintf(_BUFF,"%slobuser%c%s%c", \
              pX_Ids->vchLOBRoot, \
              X_PATH_SEPARATOR, \
              pX_Ids->pX_IdsOS->vchOSUser, \
              X_PATH_SEPARATOR); \
  }

/* This assumes _FILE / _FIELD are appropriate for iSeries vs VL (real names vs converted names) */
#define X_SET_LOB_PATH(_BUFF,_TYPE,_FILE,_FIELD) \
   if ( _TYPE == X_LOB_SECURE ) \
   { \
      if (pX_Ids->fWebRoutineExecution && pX_Ids->pszWamLobTempDir != NULL) \
      { \
         sprintf(_BUFF,"%s%s%c%s%c", \
                 pX_Ids->pszWamLobTempDir, \
                 _FILE, \
                 X_PATH_SEPARATOR, \
                 _FIELD, \
                 X_PATH_SEPARATOR); \
         pX_Ids->fWamLobTempDirUsed = TRUE; \
      } \
      else \
      { \
         sprintf(_BUFF,"%slobuser%c%s%c%s%c%s%c%s%c", \
                 pX_Ids->vchLOBRoot, \
                 X_PATH_SEPARATOR, \
                 pX_Ids->pX_IdsOS->vchOSUser, \
                 X_PATH_SEPARATOR, \
                 pX_Ids->pX_IdsOS->vchPID, \
                 X_PATH_SEPARATOR, \
                 _FILE, \
                 X_PATH_SEPARATOR, \
                 _FIELD, \
                 X_PATH_SEPARATOR); \
      } \
   } \
   else \
   { \
      sprintf(_BUFF, \
              "Cached LOBs are not currently supported. Delete any BLOB or CLOB fields on the file %s, and re-add to the file.", \
              _FILE); \
   }

/* Process ID & OS User name */
#if defined(X_OPERATING_SYSTEM_WIN)
   #define X_OS_USERNAME_LEN 256
   #define X_OS_PID_LEN sizeof(DWORD) /* What GetCurrentProcessID() returns */
   #define X_OS_CODEPAGE_LEN  6
#elif defined(X_OPERATING_SYSTEM_ISERIES)
   #define X_OS_USERNAME_LEN X_ISERIES_USER_NAME_LEN
   #define X_OS_PID_LEN 6 /* Job number */
   #define X_OS_CODEPAGE_LEN  5
#else /* UNIX */
   #define X_OS_USERNAME_LEN 31 /* Based on UT_NAMESIZE - byte for null terminator (see x_uimerr.c) */
   #define X_OS_PID_LEN sizeof(pid_t)
   #define X_OS_CODEPAGE_LEN  6
#endif

/* ------------------------------------------------- */
/* File attribute setting - X_PDF_ChangeFileAttrib() */
/* ------------------------------------------------- */
#define X_FILE_ATTRIB_READ_ONLY        'A'
#define X_FILE_ATTRIB_READ_WRITE_USER  'B'
#define X_FILE_ATTRIB_READ_WRITE_ALL   'C'

/* ================================================================= */
/*  X_IdsOS : LANSA/X OS dependent variable for IDS                  */
/* ================================================================= */
/* habX_UIM           Anchor block allocated by the X_UIM            */
/* hmqX_UIM           Handle to message queue allocated by the X_UIM */
/* hwndX_UIM          Handle to window frame allocated by the X_UIM  */
/* hmodLastProcess    Module handle of last process loaded           */
/* hODBChenv1         ODBC environment handle                        */
/* hmodLastFunction   Module handle of last function loaded          */
/* hmodLastComponent  Module handle of last component loaded         */
/* ulPID              Process ID of this job                         */
/* vchOSUser          Operating system username executing this job   */
/* vchCodePage        Codepage of current Job. X_PDF_GetJobCodepage()*/
/* iSingleByteCCSID   If sJobCCSID is Mixed, this is set to the      */
/*                    CCSID to use for single byte encoding.         */

#ifndef X_OPERATING_TARGET_CSHARP

#define X_IDSOS_VERSION -1

struct X_IDSOS
   {
      X_SHORT sVersion;
      X_MODULEHANDLE             hmodLastProcess;

#if defined(X_OPERATING_SYSTEM_WIN)
      X_WINDOWHANDLE             hwndX_UIM;
#endif

#if defined(X_OPERATING_SYSTEM_OS2) || defined(X_OPERATING_SYSTEM_WIN)
      // FIXME: These can be removed if the structure size can be changed
      unsigned long              __habX_UIM;
      unsigned long              __hmqX_UIM;
#endif

#if defined(X_OPERATING_SYSTEM_WIN)
      X_WIN_HINSTANCE            hInstance;
#endif

      X_MODULEHANDLE             hmodLastFunction;
      X_MODULEHANDLE             hmodLastComponent;

      X_VCHAR                    vchPID[X_OS_PID_LEN + 1];
      X_VCHAR                    vchOSUser[X_OS_USERNAME_LEN + 1];
      X_VCHAR                    vchCodePage[X_OS_CODEPAGE_LEN + 1];
#if defined(X_OPERATING_SYSTEM_ISERIES)
      X_INT                      iSingleByteCCSID;
#endif

#if defined(X_OPERATING_SYSTEM_WIN)
      HANDLE                     hmtxSQL;       /* Development Environment DB Layer sync mutex */
#endif
   };

#endif // X_OPERATING_TARGET_CSHARP

/* ================================================================= */
/*  X_TXTMSG : Text message tracking area                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* EntryCounter    Roitine entry counter / recursion tracker         */
/* TextTotal       Total text strings                                */
/* apvchText       Array of pointers to text strings                 */

struct X_TXTMSG
  {
     X_SHORT                  sEntryCounter;
     X_SHORT                  sTextTotal;
     X_PVCHAR                 apvchText[X_TEXT_MAXIMUM_STRINGS];
  };

/* ================================================================= */
/*  X_EXCHANGE_STRUCT_LIST : Track exchanged data structures         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Name of Data Structure                            */
/* Length          Length of Data Structure                          */
/* DataStruct      Pointer to where Data Structure currently stored  */

#define X_MAX_EXCHANGE_STRUCT         20
#define X_MAX_EXCHANGE_STRUCT_LEN   9999

struct X_EXCHANGE_STRUCT_LIST
  {
     X_VCHAR     vchName[X_OBJECT_NAME_LEN];
     X_SHORT     sLength;
     X_PCHAR     pDataStruct;
  };

/* ================================================================= */
/*  FNIOMODULE : Function to run an I/O Module                       */
/* ================================================================= */

typedef X_VOID_FUNCTION FNIOMODULE (X_PVOID,
                                       X_PVOID,
                                       X_PVOID,
                                       X_PVOID);
typedef FNIOMODULE *PFNIOMODULE;

/* ================================================================= */
/*  FNGENLPURP : General purpose function interface                  */
/* ================================================================= */

typedef X_VOID_FUNCTION FNGENLPURP (X_PVOID,
                                    X_PVOID,
                                    X_PVOID,
                                    X_PVOID,
                                    X_PVOID,
                                    X_PVOID,
                                    X_PVOID);
typedef FNGENLPURP *PFNGENLPURP;

typedef X_LONG_FUNCTION FNCALBACK( X_PVOID,
                                   X_PVOID,
                                   X_PVOID,
                                   X_PVOID,
                                   X_PVOID,
                                   X_PVOID,
                                   X_PVOID );

typedef FNCALBACK *PFNCALBACK;

#ifdef X_OPERATING_SYSTEM_WIN
typedef long FAR PASCAL X_COMPOSER_SERVER_ENTRYPOINT( long, LPCTSTR, long, LPCTSTR, LPCTSTR, LPCTSTR, LPCTSTR,
                                                      LPTSTR, LPTSTR, long, LPTSTR, LPTSTR, LPTSTR, LPTSTR, LPTSTR, LPTSTR, LPTSTR );
#else
/* Just a dummy */
typedef long X_COMPOSER_SERVER_ENTRYPOINT( long );
#endif

typedef X_COMPOSER_SERVER_ENTRYPOINT *X_COMPOSER_SERVER;


typedef struct _X_Func_Arg_
{
   X_PVOID  pParam1;
   X_PVOID  pParam2;
   X_PVOID  pParam3;
   X_PVOID  pParam4;
   X_PVOID  pParam5;
   X_PVOID  pParam6;
   X_PVOID  pParam7;
} X_FUNC_ARG;

/* ================================================================= */
/*  X_OBJ_AUTHS_LIST : List of object authorities                    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Object          Object name                                       */
/* Extension       Object Extension name                             */
/* Type            Type of object                                    */
/* Auths           Object authorities                                */

#define MAX_AUTHS          100

struct X_OBJ_AUTHS_LIST
{
   X_VCHAR  vchObject[X_OBJECT_NAME_LEN+1];
   X_VCHAR  vchExtension[X_OBJECT_NAME_LEN+1];
   X_VCHAR  vchType[X_OBJECT_TYPE_LEN+1];
   X_VCHAR  avchAuths[X_OBJECT_AUTH_LIST_LEN+1];
};


/* ================================================================= */
/*  X_PROCESS_ALIAS : Process alias name details                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* MaskLen         Length of masking characters                      */
/* Mask            Mask value                                        */
/* SPos            Array of start positions for new names            */
/* SLen            Array of lengths for new names                    */

#define X_PROCESS_ALIAS_MAX       101
#define X_PROCESS_ALIAS_SUBSTR      3
#define X_PROCESS_ALIAS_MASK       10

#if defined(X_OPERATING_SYSTEM_UNIX)
   #define X_PROCESS_ALIAS_FILE_NAME "/x_lansa/x_palias.dat"
#else
   #define X_PROCESS_ALIAS_FILE_NAME "\\X_LANSA\\X_PALIAS.DAT"
#endif

struct X_PROCESS_ALIAS
{
   X_SHORT sMaskLen;
   X_VCHAR vchMask[X_PROCESS_ALIAS_MASK  + 1];
   X_SHORT asSPos[X_PROCESS_ALIAS_SUBSTR];
   X_SHORT asSLen[X_PROCESS_ALIAS_SUBSTR];
};

/* ================================================================= */
/*  X_HSKC_ELIGIBLE : High Speed key checking eligible file name     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* PhysicalFile    Name of actual physical file/table being accessed */

#define X_HSKC_MAX_VALUES      256
#define X_HSKC_MAX_KEY_LENGTH  2048

#define X_HSKC_FILE_NAME       "x_hskc.dat"

struct X_HSKC_ELIGIBLE
{
   X_FCHAR  fchPhysicalFile[X_OBJECT_NAME_LEN];
};

/* ================================================================= */
/*  X_HSKC_HEADER : High Speed key checking header                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* AccessFile      Name of file/table being accessed                 */
/* PhysicalFile    Name of actual physical file/table being accessed */
/* LengthofKey     Length of key being used to lookup the table      */
/* NumberofValues  Number of values that currently exist             */
/* InUse           Structure entry is in use                         */
/* pKeyValues      Pointer to array of key values                    */


struct X_HSKC_HEADER
{
   X_FCHAR  fchAccessFile[X_OBJECT_NAME_LEN];
   X_FCHAR  fchPhysicalFile[X_OBJECT_NAME_LEN];
   X_USHORT usLengthofKey;
   X_USHORT usNumberofValues;
   X_BOOL   fInUse;
   X_PVOID  pKeyValues;
};

/* ================================================================= */
/*  X_HSKC_VALUE : High Speed key checking key value                 */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* LengthofKey     Length of key being used to lookup the table      */
/* vchKeyValue     Value of key                                      */

struct X_HSKC_VALUE
{
   X_USHORT usLengthofKey;
   X_VCHAR vchKeyValue[X_HSKC_MAX_KEY_LENGTH];
};

/* ================================================================= */
/*  X_SET_RECORD and X_SET_HEAD : Used for internal file tracking.   */
/*                                Refer to X_XQL8.C for more info.   */
/* ================================================================= */

struct X_SET_RECORD
{
   X_PVCHAR pvchKeyandData;
};

struct X_SET_HEAD
{
  X_ULONG                ulSetTotal;
  X_ULONG                ulSetCurrent;
  X_ULONG                ulSetKeyLength;
  X_ULONG                ulSetDataLength;
  struct  X_SET_RECORD * pSetRecord;
};

/* Moved definition of FNSETSELECTOR and PFSETSELECTOR to x_xqlstr.h */

/* ================================================================= */
/*  X_LANSA_PC : Details of connected LANSA/PC session               */
/* ================================================================= */

#define X_LANSA_PC_V1   -1

struct xdef_file_list_index;
struct _xdef_pcxinterface;
#if defined(X_OPERATING_SYSTEM_UNIX) && defined(__cplusplus)
typedef int (*X_LANSA_PC_FUNCTION) ( struct _xdef_pcxinterface *, unsigned short, void * );
#else
typedef int (*X_LANSA_PC_FUNCTION) ( struct _xdef_pcxinterface *, unsigned short, void *(*)[] );
#endif

struct X_LANSA_PC
{
   X_SHORT  sVersion;

   X_MODULEHANDLE hModule;

   struct _xdef_pcxinterface * pPCXI;
   struct xdef_file_list_index * pGetFileListIndex;

   X_LANSA_PC_FUNCTION LIIX_iCIDT;
   X_LANSA_PC_FUNCTION LIIX_iClearList;
   X_LANSA_PC_FUNCTION LIIX_iClearMessages;
   X_LANSA_PC_FUNCTION LIIX_iClearTemplateAnswers;
   X_LANSA_PC_FUNCTION LIIX_iClearTemplateInfo;
   X_LANSA_PC_FUNCTION LIIX_iCompileObject;
   X_LANSA_PC_FUNCTION LIIX_iDeleteField;
   X_LANSA_PC_FUNCTION LIIX_iDeleteFile;
   X_LANSA_PC_FUNCTION LIIX_iDeleteFunction;
   X_LANSA_PC_FUNCTION LIIX_iDeleteProcess;
   X_LANSA_PC_FUNCTION LIIX_iEndInterface;
   X_LANSA_PC_FUNCTION LIIX_iExecuteTemplate;
   X_LANSA_PC_FUNCTION LIIX_iFFC;
   X_LANSA_PC_FUNCTION LIIX_iFreePCXMemory;
   X_LANSA_PC_FUNCTION LIIX_iFreeRDML;
   X_LANSA_PC_FUNCTION LIIX_iGetFiles;
   X_LANSA_PC_FUNCTION LIIX_iGetNextRulePtr;
   X_LANSA_PC_FUNCTION LIIX_iGetRDML;
   X_LANSA_PC_FUNCTION LIIX_iIJDT;
   X_LANSA_PC_FUNCTION LIIX_iParseRDML;
   X_LANSA_PC_FUNCTION LIIX_iPCXDongleCheck;
   X_LANSA_PC_FUNCTION LIIX_iPutRDML;
   X_LANSA_PC_FUNCTION LIIX_iSetCANS;
   X_LANSA_PC_FUNCTION LIIX_iSetFiles;
   X_LANSA_PC_FUNCTION LIIX_iSetIDX;
   X_LANSA_PC_FUNCTION LIIX_iSetNANS;
   X_LANSA_PC_FUNCTION LIIX_iStartInterface;
   X_LANSA_PC_FUNCTION LIIX_iStoreInList;
   X_LANSA_PC_FUNCTION LIIX_iValidateName;
   X_LANSA_PC_FUNCTION LIIX_iExecuteLIIOFunc;
   X_LANSA_PC_FUNCTION LIIX_iExecuteLansaPCFunc;
   X_LANSA_PC_FUNCTION LIIX_iValidate_Logon;
};

/* ================================================================= */
/*  X_EDIT_PROCESS : Details of process being edited                 */
/* ================================================================= */

struct X_EDIT_PROCESS
{
   X_SHORT  sVersion;
   X_BOOL   fInProgress;
   X_BOOL   fEditingProcess;
   X_VCHAR  vchProc[X_OBJECT_NAME_LEN + 1];
   X_VCHAR  vchProcDesc[X_DESCRIPTION_LEN + 1];
   X_BOOL   fEditingFunction;
   X_VCHAR  vchFunc[X_FUNCTION_NAME_LEN + 1];
   X_VCHAR  vchFuncDesc[X_DESCRIPTION_LEN + 1];

   X_CHAR   chProcessType;       /* X20MUS */
   X_CHAR   chAuditStamp;
   X_BOOL   fNewlyCreatedFunction;
};

/* ================================================================= */
/*  X_EDIT_FILE : Details of file being edited                       */
/* ================================================================= */

struct X_EDIT_FILE
{
   X_SHORT  sVersion;
   X_VCHAR  vchFile[X_OBJECT_NAME_LEN+1];/* Current file being editted      */
                                         /* Current file's library          */
   X_VCHAR  vchLibrary[X_OBJECT_NAME_LEN+1];
                                         /* Current editing source          */
   X_VCHAR  vchEditingSource[X_EDIT_SOURCE_LEN + 1];
   X_BOOL   fEditingFile;                /* Edit file state                 */
   X_BOOL   fNewFile;                    /* New file being editted          */
   X_BOOL   fEditFields;                 /* Edit field state                */
   X_BOOL   fEditLogicalViews;           /* Edit logical views state        */
   X_BOOL   fEditAccessRoutes;           /* Edit access routes state        */
   X_VCHAR  vchInitialAccess[40 + 1];    /* Initial public access           */
   LX_F27_RECD *pX27;                    /* File's definition               */
   X_USHORT uscX64;                      /* Num of multilingual records     */
   LX_F64_RECD *pX64;                    /* Multilingual records            */
   X_USHORT uscFFD;                      /* Num of real fields in file      */
   LX_F14_RECD *pFFD;                    /* Real fields in file             */
   X_USHORT uscVFD;                      /* Num of virt fields in file      */
   LX_F14_RECD *pVFD;                    /* Virtual fields in file          */
   X_USHORT uscPAK;                      /* Num of primary keys in file     */
   LX_F24_RECD *pPAK;                    /* File's primary keys             */
   X_USHORT uscX15;                      /* Num of views                    */
   LX_F15_RECD *pX15;                    /* File's views                    */
   X_USHORT uscX43;                      /* Num of view keys                */
   LX_F43_RECD *pX43;                    /* File's view keys                */
   X_USHORT uscX65;                      /* Num of view ML details          */
   LX_F65_RECD *pX65;                    /* View ML details                 */
   X_USHORT uscX36;                      /* Num of select/omit criteria     */
   LX_F36_RECD *pX36;                    /* Select/omit criteria            */
   X_USHORT uscX30;                      /* Num of other table key defs     */
   LX_F30_RECD *pX30;                    /* Other table key defs            */
   X_USHORT uscX18;                      /* Num of access route defs        */
   LX_F18_RECD *pX18;                    /* Access route defs               */
   X_USHORT uscX42;                      /* Num of access route keys        */
   LX_F42_RECD *pX42;                    /* Access route keys               */
   X_USHORT uscX05;                      /* Num of rule directories         */
   LX_F05_RECD *pX05;                    /* Rule directories                */
   X_USHORT uscX06;                      /* Num of value rules              */
   LX_F06_RECD *pX06;                    /* Value rules                     */
   X_USHORT uscX07;                      /* Num of list value rules         */
   LX_F07_RECD *pX07;                    /* List value rules                */
   X_USHORT uscX08;                      /* Num of code file lookups        */
   LX_F08_RECD *pX08;                    /* Code file lookups               */
   X_USHORT uscX09;                      /* Num of simple logic rules       */
   LX_F09_RECD *pX09;                    /* Simple logic rules              */
   X_USHORT uscX10;                      /* Num of complex logic rules      */
   LX_F10_RECD *pX10;                    /* Complex logic rules             */
   X_USHORT uscX11;                      /* Num of date range rules         */
   LX_F11_RECD *pX11;                    /* Date range rules                */
   X_USHORT uscX88;                      /* Number of triggers              */
   LX_F88_RECD *pX88;                    /* Triggers                        */
};

/* ================================================================= */
/*  X_JOB_QUEUE : Job Queue Details                                  */
/* ================================================================= */

#define X_JOB_QUEUE_FILE_NAME "x_jobq.dat"

struct X_JOB_QUEUE
{
   X_CHAR  chType;
   X_VCHAR vchName[X_OBJECT_NAME_LEN + 1];
   X_VCHAR vchPath[X_NEW_FILE_PATH_LENGTH + 1];
};

/* ================================================================= */
/*  X_SUBMITTED_JOB: Submitted Job details                           */
/* ================================================================= */

struct X_SUBMITTED_JOB
{
   X_VCHAR vchName[X_OBJECT_NAME_LEN + 1];
   X_VCHAR vchByJobName[10 + 1];
   X_VCHAR vchByJobNumber[6 + 1];
   X_VCHAR vchOnDate[X_DATE_LEN + 1];
   X_VCHAR vchAtTime[6 + 1];
   X_VCHAR vchByCURRENTUser[X_ISERIES_USER_NAME_LEN + 1];
   X_VCHAR vchSubmittingJobOrder[20 + 1];
   X_VCHAR vchProgram[X_NEW_FILE_PATH_LENGTH + X_FILE_NAME_LEN + 1];
   X_VCHAR vchParameters[5000];
};

/* ================================================================= */
/*  FNEXPANDFR : Function to free allocated resources                */
/* ================================================================= */

typedef X_VOID_FUNCTION FNEXPANDFR (struct X_IDS *);
typedef FNEXPANDFR *PFNEXPANDFR;

/* ================================================================= */
/*  Types of chOAMRequest                                            */
/* ================================================================= */

#define X_VARIANT_OPERATION    '\x00'
#define X_INVARIANT_OPERATION  '\xF0'
#define X_LOCK_OPERATION       '\x08'

#define X_SELECT_OPERATION     '\x01'
#define X_INSERT_OPERATION     '\x02'
#define X_UPDATE_OPERATION     '\x03'
#define X_DELETE_OPERATION     '\x04'
#define X_ALLOC_OPERATION      '\x05'
#define X_REREAD_OPERATION     '\x06'
#define X_LOB_SELECT_OPERATION '\x07'
#define X_OPERATION_MASK       '\x07' /* The operation types share bits so ALL must be masked off before testing! */

#define X_VARIANT_SELECT        (X_VARIANT_OPERATION   | X_SELECT_OPERATION) 
#define X_VARIANT_INSERT        (X_VARIANT_OPERATION   | X_INSERT_OPERATION)
#define X_VARIANT_UPDATE        (X_VARIANT_OPERATION   | X_UPDATE_OPERATION)
#define X_VARIANT_DELETE        (X_VARIANT_OPERATION   | X_DELETE_OPERATION)
#define X_VARIANT_ALLOC_SQLDA   (X_VARIANT_OPERATION   | X_ALLOC_OPERATION)
#define X_VARIANT_REREAD        (X_VARIANT_OPERATION   | X_REREAD_OPERATION)
#define X_VARIANT_LOB_SELECT    (X_VARIANT_OPERATION   | X_LOB_SELECT_OPERATION)

#define X_INVARIANT_SELECT      (X_INVARIANT_OPERATION | '\x01') /* <- No longer generated, only in old object */
#define X_INVARIANT_INSERT      (X_INVARIANT_OPERATION | '\x02')
#define X_INVARIANT_UPDATE      (X_INVARIANT_OPERATION | '\x03')
#define X_INVARIANT_DELETE      (X_INVARIANT_OPERATION | '\x04')
#define X_INVARIANT_ALLOC_SQLDA (X_INVARIANT_OPERATION | '\x05')
#define X_INVARIANT_REREAD      (X_INVARIANT_OPERATION | X_REREAD_OPERATION)
#define X_INVARIANT_LOB_SELECT  (X_INVARIANT_OPERATION | X_LOB_SELECT_OPERATION)

/* ================================================================= */
/*  X_FUNRTR : Function routing table entry                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* vchFromFunction The "from" function name                          */
/* vchToFunction   The "to" function name                            */

#define X_FUNRTR_FILE_NAME  "x_funrtr.dat"

struct X_FUNRTR
{
   X_VCHAR   vchFromFunction[X_FUNCTION_NAME_LEN];
   X_VCHAR   vchToFunction[X_FUNCTION_NAME_LEN];
};


/* ================================================================= */
/*  X_REMOVE_FILE : Chain of files to be removed                     */
/* ================================================================= */

struct X_REMOVE_FILE
{
   struct    X_REMOVE_FILE * pNextRemFile;
   X_BOOL    fIssueErrorMessage;
   X_VCHAR   vchFileName[X_NEW_FILE_PATH_LENGTH + 1];
};


/* ================================================================= */
/*  X_IDS_COMPONENT : Information when running with components       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pX_ComponentPro Pointer to Process controlling components         */
/* pX_CmoponentFun Pointer to Function controlling components        */

struct X_IDS_COMPONENT
{
   X_DEFS_COMPONENT_MANAGER_FUNCTION   pfnComponentManager;
   X_MODULEHANDLE                      hComponentManagerDLL;
   struct X_PRO                      * pX_ProComponent;
   struct X_FUN                      * pX_FunComponent;
   X_BOOL                              fInitialised;
};


/* ================================================================= */
/*  X_XENV_VARIABLE : Stores XENV= values from the command line      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pX_ComponentPro Pointer to Process controlling components         */
/* pX_CmoponentFun Pointer to Function controlling components        */

#define X_ENV_VARIABLE_MAX_NAME_LEN  64
#define X_ENV_VARIABLE_MAX_VALUE_LEN 256

struct X_XENV_VARIABLE
{
   struct X_XENV_VARIABLE * pNextXENVVariable;
   X_VCHAR                  vchVariableName[X_ENV_VARIABLE_MAX_NAME_LEN + 1];
   X_VCHAR                  vchVariableValue[X_ENV_VARIABLE_MAX_VALUE_LEN + 1];
};

/* ================================================================= */
/*  X_BITFLAG : Declares a set of bit flags for use in validating    */
/*              X_RUN environment variables.                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* X_PVCHAR    A valid variable name for this environment variable   */
/* ctOptions   The corresponding bit to set in the internal flag.    */
/* fCompositeFlag Generally FALSE. If an entry is a composite of     */
/*                other flags, set it to TRUE. This is used by trace */
/*                to not trace its value - because its traced as each*/
/*                individual flag anyway.                            */

typedef struct _BITFLAG
{
   X_PVCHAR             vchVariableName;
   X_INT                ctOptions;
   X_BOOL               fCompositeFlag;
}     X_BITFLAG,
  *  PX_BITFLAG,
 ** PPX_BITFLAG;

/* ---------------------------------- */
/* Standard VOID function definitions */
/* ---------------------------------- */

typedef X_VOID_FUNCTION FNSTDVOIDFUNCTION (struct X_IDS *);
typedef FNSTDVOIDFUNCTION *  PFNSTDVOIDFUNCTION;
typedef FNSTDVOIDFUNCTION ** PPFNSTDVOIDFUNCTION;

typedef X_VOID_FUNCTION FNUIMVOIDFUNCTION (X_SHORT,struct X_IDS *,struct X_PRO *,
                                           struct X_FUN *, ...);
typedef FNUIMVOIDFUNCTION *  PFNUIMVOIDFUNCTION;
typedef FNUIMVOIDFUNCTION ** PPFNUIMVOIDFUNCTION;


/* ----------------------- */
/* X_RUN Argument Tracking */
/* ----------------------- */

typedef struct _X_RUN_ARGUMENT
{

   struct _X_RUN_ARGUMENT * pNext;
   X_BOOL    fIsSupercededLater;
   X_VCHAR   vchName[X_PARAMETER_NAME_LEN + 1];
   X_PVCHAR  pvchValue;

}      X_RUN_ARGUMENT,
   *  PX_RUN_ARGUMENT,
  ** PPX_RUN_ARGUMENT;

/* ----------------------- */
/* X_RUN Argument Tracking */
/* ----------------------- */

typedef struct _X_ISAM_FILE
{
   X_PFILE_HANDLE   pfFile;
   X_ULONG   ulPairingIdentifier;
   X_DOUBLE  dAgeIdentifier;
   X_FILE_USAGE   iUsage;
   X_VCHAR   vchFileName[X_NEW_FILE_PATH_LENGTH + X_FILE_NAME_LEN + 1];
}      X_ISAM_FILE,
   *  PX_ISAM_FILE,
  ** PPX_ISAM_FILE;

/* ---------------------------------------------------- */
/* Caching of repository data retrieved from the server */
/* ---------------------------------------------------- */
typedef struct _X_XQL_CACHE
{
   X_PVOID pLX_MSGTree;
   X_PVOID pLX_F03Tree;
   X_PVOID pLX_F40Tree;
   X_PVOID pLX_F61Tree;
   X_PVOID pLX_F62Tree;
   X_PVOID pLX_F66Tree;
   X_PVOID pLX_F67Tree;
}      X_XQL_CACHE,
  *   PX_XQL_CACHE,
  ** PPX_XQL_CACHE;

/* ----------------------------------------------------- */
/* Client User parameter details.                        */
/* ----------------------------------------------------- */

typedef struct _X_CLIENT_PARAMS
{
   X_PVCHAR pvchClientType;
   X_PVCHAR pvchLUName;

}     X_CLIENT_PARAMS,
   *  PX_CLIENT_PARAMS,
   ** PPX_CLIENT_PARAMS;

/* ================================================================= */
/*  X_IDS_RPG : DC@IDS structure for LANSA for iSeries RPG runtime.  */
/*                                                                   */
/*  Required to pass to LANSA for iSeries RPG runtime programs.      */
/*  Note that these are all fixed length and also contain signed     */
/*  and packed data. Refer to DC@ISPEC.                              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* DC@PGL          LANSA program library                             */
/* DC@DTL          LANSA data library                                */
/* DC@MDL          LANSA module library (partition objects)          */
/* DC@OWN          LANSA system owner profile                        */
/* DC@PRO          Name of product (LANSA)                           */
/* DC@LVL          Release level of the product S(3,1)               */
/* DC@ORG          Name of company / organisation                    */
/* DC@SEC          System security officer                           */
/* DC@LIC          CPU licence number                                */
/* DC@CEX          Exit command key (@E overlay) S(2,0)              */
/* DC@CMN          Menu command key (@U overlay) S(2,0)              */
/* DC@CDM          Messages command key (@M overlay) S(2,0)          */
/* DC@CAD          Add command key (@A overlay) S(2,0)               */
/* DC@CCH          Change command key (@C overlay) S(2,0)            */
/* DC@CDL          Delete command key (@D overlay) S(2,0)            */
/* DC@SUI          Unique system prefix / identifier                 */
/* DC@SIZ          Standard file size                                */
/* DC@LCK          System file level check standard                  */
/* DC@CSL          Produce source listings default (Y or N)          */
/* DC@COP          Optimise program compiles       (Y or N)          */
/* DC@CID          Ignore decimal data errors      (Y or N)          */
/* DC@DPW          Default printer width (80 - 198) S(3,0)           */
/* DC@DSW          Default screen width  (80 - 132) S(3,0)           */
/* DC@DSL          Default screen length (16 - 24)  S(3,0)           */
/* DC@DIA          Default input attribute list (alpha)              */
/* DC@DIN          Default input attribute list (numeric)            */
/* DC@DOA          Default output attribute list (alpha)             */
/* DC@DON          Default output attribute list (numeric)           */
/* DC@$JD          Last job description used                         */
/* DC@$JQ          Last job queue used                               */
/* DC@$OQ          Last output queue used                            */
/* DC@DFN          Default library name for new file defn            */
/* DC@DCC          Default commitment control for new file defn      */
/* DC@DAC          Default AUTOCOMMIT control for new file defn      */
/* DC@DFE          Default FCC program editor                        */
/* DC@OSV          Operating system version no.                      */
/* DC@EOA          Export LANSA object authority default             */
/* DC@ASP          Partitions are configured in differing ASPs       */
/* DC@TCO          Turbo compiler option is enabled ("T"=Yes)        */
/* DC@LDC          LANSA/DOCUMENT is enabled                         */
/* DC@EDB          Enable debug default (Y/N)                        */
/* DC@EAE          Enable alternate editors for help and RDML        */
/* DC@DIP          Dictionary interface program                      */
/* DC@DPL          Default printer form length                       */
/* DC@DPO          Default printer overflow line number              */
/* DC@IHI          Default IDENT_ATR parm to high intensity          */
/* DC@IRI          Default IDENT_ATR parm to reverse image           */
/* DC@IUL          Default IDENT_ATR parm to underline               */
/* DC@STH          Default STD_HEAD parameter value                  */
/* DC@URL          Use running process locks                         */
/* DC@LPC          Last PC installed on this system                  */
/* DC@HOL          Name of HANDSON pgm library (if installed)        */
/* DC@LLG          Display LANSA logo screen on entry                */
/* DC@EFH          Enable field level HELP support                   */
/* DC@C3X          System/38 or System/3X computer                   */
/* DC@CEE          Execution environment if System/3X                */
/* DC@W            List of 132 wide screens (20 x char 1)            */
/* DC@CPR          Default for compiling a process                   */
/* DC@EAK          Enable atttention key in system                   */
/* DC@LFC          Field label fill character                        */
/* DC@CUC          Field column heading underline character          */
/* DC@C            List of valid colour screen codes (10 x char 1)   */
/* DC@FLS          Function level security is enabled                */
/* DC@AGH          Automatically generate field level help           */
/* DC@PKE          Prompt key is enabled by default                  */
/* DC@CPM          Prompt key function key (non SAA only)            */
/* DC@RCL          Execute RCLRSC on exit from LANSA                 */
/* DC@RPL          Execute RPLLIBL on exit from LANSA                */
/* DC@IOM          Release 2.5 I/O modules required                  */
/* DC@TRP          SUPERSEDED BY XC@TGT                              */
/* DC@HCH          Horizontal print character for reports            */
/* DC@VCH          Vertical print character for reports              */
/* DC@ESM          External Security Matching (files)                */
/* DC@EXL          3GL Program access to exchange list required      */
/* DC@CYY          YY Compare value                                  */
/* DC@CLE          Century if LE DC@CYY                              */
/* DC@CGT          Century if GT DC@CYY                              */
/* DC@DPC          Decimal format ('.' or ',')                       */
/* DC@SMG          Suppress 'Interpretive mode' message.             */
/* DC@SPS          Disable process/function security checking        */
/* DC@SFS          Disable file security checking                    */
/* DC@UPK          Execute user defined prompt key message program   */
/* DC@EXA          EXCHANGE all fields on a prompt request           */
/* DC@BAT          Battery Licence MAY Apply Flag                    */
/* DC@CPF          Release level of CPF S(3,1)                       */
/* DC@DAT          Date in system format S(6,0)                      */
/* DC@SDF          System date format                                */
/* DC@DMY          Date in DDMMYY format S(6,0)                      */
/* DC@YMD          Date in YYMMDD format S(6,0)                      */
/* DC@MDY          Date in MMDDYY format S(6,0)                      */
/* DC@JUL          Date in julian format S(5,0)                      */
/* DC@JTP          Current job type (B or I)                         */
/* DC@JOB          Current job name                                  */
/* DC@JNB          Current job number                                */
/* DC@USR          Current job user                                  */
/* DC@OQN          Current output queue name                         */
/* DC@OQL          Current output queue library                      */
/* DC@MQN          Current message queue name                        */
/* DC@MQL          Current message queue library                     */
/* DC@LBL          Current library list (first 23)                   */
/* DC@LB2          Current library list (last 2)                     */
/* DC@GRU          Current job group user profile                    */
/* DC@GRO          Group owner (*USRPRF *GRPPRF)                     */
/* DC@GRA          Group authority (*ALL *NORMAL *NONE)              */
/* DC@LDM          LANSA "system" debug mode is on                   */
/* DC@SYT          Reserved for internal use                         */
/* DC@P#I          Current partition identifier                      */
/* DC@P#D          Current partition description                     */
/* DC@P#S          Displayable product/partition                     */
/* DC@DEX          Displayable exit key description                  */
/* DC@LEX          Length of exit key description P(1,0)             */
/* DC@TEX          Exit key is EXIT or SYSTEM function               */
/* DC@OQI          Next file OPNID parameter to be used S(9,0)       */
/* DC@CAL          CHECK_AUTH_DYNLIBL IN EFFECT Y/N                  */
/* SA@SAA          Current partition uses SAA/CUA standards          */
/* DC@WMB          Compiler Working Member Name                      */
/* DC@SMB          Compiler Working Source Name                      */
/* ML@IGM          Current machine is IGC capable (1/0)              */
/* ML@IGD          Current device is IGC capable (1/0)               */
/* DC@SCS          System Currency Symbol                            */
/* DC@TKI          Current Task Identifier                           */
/* DC@PCT          PC Type N=NPT, W=Windows, P=PM - GUI,             */
/*                         B=Browser - WEB, X=XML                    */
/* DC@ILS          Ignore LANSA security checks (Y/N)                */
/*                 (External export/import)                          */
/* DC@SDS          System Date Separator                             */
/* DC@STS          System Time Separator                             */
/* DC@VLR          Visual LANSA runtime (Y/N)                        */
/* DC@RTR          Function Routing in Effect (Y/N)                  */
/* DC@DT8          8 digit Date in system format S(8,0)              */
/* DC@CEN          Century of system date S(2,0)                     */

struct X_IDS_RPG
{
   X_FCHAR         fchDC_PGL[10];
   X_FCHAR         fchDC_DTL[10];
   X_FCHAR         fchDC_MDL[10];
   X_FCHAR         fchDC_OWN[10];
   X_FCHAR         fchDC_PRO[5];
   X_FCHAR         fchDC_LVL[3];
   X_FCHAR         fchDC_ORG[30];
   X_FCHAR         fchDC_SEC[10];
   X_FCHAR         fchDC_LIC[10];
   X_FCHAR         fchDC_CEX[2];
   X_FCHAR         fchDC_CMN[2];
   X_FCHAR         fchDC_CDM[2];
   X_FCHAR         fchDC_CAD[2];
   X_FCHAR         fchDC_CCH[2];
   X_FCHAR         fchDC_CDL[2];
   X_CHAR          chDC_SUI;
   X_FCHAR         fchDC_SIZ[30];
   X_FCHAR         fchDC_LCK[4];
   X_CHAR          chDC_CSL;
   X_CHAR          chDC_COP;
   X_CHAR          chDC_CID;
   X_FCHAR         fchDC_DPW[3];
   X_FCHAR         fchDC_DSW[3];
   X_FCHAR         fchDC_DSL[3];
   X_FCHAR         fchDC_DIA[40];
   X_FCHAR         fchDC_DIN[40];
   X_FCHAR         fchDC_DOA[40];
   X_FCHAR         fchDC_DON[40];
   X_FCHAR         fchDC__JD[21];
   X_FCHAR         fchDC__JQ[21];
   X_FCHAR         fchDC__OQ[21];
   X_FCHAR         fchDC_DFN[10];
   X_CHAR          chDC_DCC;
   X_CHAR          chDC_DAC;
   X_CHAR          chDC_DFE;
   X_CHAR          chDC_OSV;
   X_FCHAR         fchDC_EOA[2];
   X_CHAR          chDC_ASP;
   X_CHAR          chDC_TCO;
   X_CHAR          chDC_LDC;
   X_CHAR          chDC_EDB;
   X_CHAR          chDC_EAE;
   X_FCHAR         fchDC_DIP[10];
   X_FCHAR         fchDC_DPL[3];
   X_FCHAR         fchDC_DPO[3];
   X_CHAR          chDC_IHI;
   X_CHAR          chDC_IRI;
   X_CHAR          chDC_IUL;
   X_CHAR          chDC_STH;
   X_CHAR          chDC_URL;
   X_FCHAR         fchDC_LPC[2];
   X_FCHAR         fchDC_HOL[10];
   X_CHAR          chDC_LLG;
   X_CHAR          chDC_EFH;
   X_FCHAR         fchDC_C3X[2];
   X_FCHAR         fchDC_CEE[2];
   X_FCHAR         fchDC_W[20];
   X_CHAR          chDC_CPR;
   X_CHAR          chDC_EAK;
   X_CHAR          chDC_LFC;
   X_CHAR          chDC_CUC;
   X_FCHAR         fchDC_C[10];
   X_CHAR          chDC_FLS;
   X_CHAR          chDC_AGH;
   X_CHAR          chDC_PKE;
   X_FCHAR         fchDC_CPM[2];
   X_CHAR          chDC_RCL;
   X_CHAR          chDC_RPL;
   X_CHAR          chDC_IOM;
   X_CHAR          chDC_TRP;
   X_CHAR          chDC_HCH;
   X_CHAR          chDC_VCH;
   X_CHAR          chDC_ESM;
   X_CHAR          chDC_EXL;
   X_FCHAR         fchDC_CYY[2];
   X_FCHAR         fchDC_CLE[2];
   X_FCHAR         fchDC_CGT[2];
   X_CHAR          chDC_DPC;
   X_CHAR          chDC_SMG;
   X_CHAR          chDC_SPS;
   X_CHAR          chDC_SFS;
   X_CHAR          chDC_UPK;
   X_CHAR          chDC_EXA;
   X_CHAR          chDC_BAT;
   X_FCHAR         fchDC_CPF[3];
   X_FCHAR         fchDC_DAT[6];
   X_FCHAR         fchDC_SDF[3];
   X_FCHAR         fchDC_DMY[6];
   X_FCHAR         fchDC_YMD[6];
   X_FCHAR         fchDC_MDY[6];
   X_FCHAR         fchDC_JUL[5];
   X_CHAR          chDC_JTP;
   X_FCHAR         fchDC_JOB[10];
   X_FCHAR         fchDC_JNB[6];
   X_FCHAR         fchDC_USR[10];
   X_FCHAR         fchDC_OQN[10];
   X_FCHAR         fchDC_OQL[10];
   X_FCHAR         fchDC_MQN[10];
   X_FCHAR         fchDC_MQL[10];
   X_FCHAR         fchDC_LBL[253];
   X_FCHAR         fchDC_LB2[22];
   X_FCHAR         fchDC_GRU[10];
   X_FCHAR         fchDC_GRO[10];
   X_FCHAR         fchDC_GRA[10];
   X_CHAR          chDC_LDM;
   X_CHAR          chDC_SYT;
   X_FCHAR         fchDC_P_I[3];
   X_FCHAR         fchDC_P_D[40];
   X_FCHAR         fchDC_P_S[9];
   X_FCHAR         fchDC_DEX[6];
   X_CHAR          chDC_LEX;
   X_CHAR          chDC_TEX;
   X_FCHAR         fchDC_OQI[9];
   X_CHAR          chDC_CAL;
   X_CHAR          chSA_SAA;
   X_FCHAR         fchDC_WMB[10];
   X_FCHAR         fchDC_SMB[7];
   X_CHAR          chML_IGM;
   X_CHAR          chML_IGD;
   X_CHAR          chDC_SCS;
   X_FCHAR         fchDC_TKI[8];
   X_CHAR          chDC_PCT;
   X_CHAR          chDC_ILS;
   X_CHAR          chDC_SDS;
   X_CHAR          chDC_STS;
   X_CHAR          chDC_VLR;
   X_CHAR          chDC_RTR;
   X_FCHAR         fchDC_DT8[8];
   X_FCHAR         fchDC_CEN[2];
};

/* ================================================================= */
/*  X_EDS_RPG : DC@EDS structure for LANSA for iSeries RPG runtime.  */
/*                                                                   */
/*  Required to pass to LANSA for iSeries RPG runtime programs.      */
/*  Note that these are all fixed length and also contain signed     */
/*  and packed data. Refer to DC@ISPEC.                              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* DC@IDN          Identifies LDA as being set up by LANSA           */
/* DC@NXT          Next task to be performed                         */
/* DC@PGM          Next program to be called                         */
/* DC@PLT          Parameter list type for call                      */
/* DC@PF1          Program function flag/byte 1                      */
/* DC@PF2          Program function flag/byte 2                      */
/* DC@HLM          Higher level message collector                    */
/* DC@OCH          Object change allowed flag                        */
/* DC@ODM          Object definition mode                            */
/* DC@OAM          Object amendment flag (full amendment)            */
/* DC@RET          Program suite return code                         */
/* DC@MID          Program suite message                             */
/* DC@MVR          Program suite message substitution variable       */
/* ML@RLN          Repeated language for batch jobs                  */
/* DC@CPI          Current process access key                        */
/* DC@CFI          Current function access key                       */
/* DC@OAP          Object amendment flag (partial amendment)         */
/* DC@NUP          Number of user parameters passed S(3,0)           */
/* DC@FUM          Current function action (C/R)                     */
/* DC@RTP          Request to terminate program                      */
/* DC@WRN          WITH_RRN value P(15,0)                            */
/* DC@RRN          RETURN_RRN value P(15,0)                          */
/* DC@DBG          DEBUG mode on for current function                */
/* DC@DBP          DEBUG program name                                */
/* DC@DCI          Direct call indicator                             */
/* DC@CWF          Compiler work files in use flag                   */
/* Positions 230 --> 231 are currently spare - fchSpare1             */
/* DC@ACC          Auto commitment control requested flag            */
/* DC@E#I          Submitting partition identifier                   */
/* DC@WIU          Wide screen currently in use flag                 */
/* DC@DFS          Source of date & date format (S or J)             */

/* Overlay area for LANSA for iSeries development and production     */
/* tasks.                                                            */
/* Positions 238 --> 255 are available as fchEDS1a                   */

/* IOM-call overlays                                                 */

/* IOM@UF          File to be actually used                          */
/* IOM@UM          Member to be actually used                        */
/* IOM@BF          Base physical file to actually use                */
/* IOM@BM          Base logical file to actually use                 */
/* IOM@QS          QRYSLT values for OPNQRYF                         */
/* IOM@KF          KEYFLD values for OPNQRYF                         */
/* IOM@AC          ALWCPYDTA value for OPNQRYF                       */
/* IOM@OP          OPTIMIZE value for OPNQRYF                        */
/* IOM@S1          SEQONLY value 1 for OPNQRYF                       */
/* IOM@S2          SEQONLY value 2 for OPNQRYF                       */
/* IOM@CM          COMMIT value for OPNQRYF                          */
/* IOM@TY          TYPE value for OPNQRYF                            */
/* IOM@FC          CLOSE operation must close the file               */
/* IOM@LO          I/O Logical Operation                             */
/* IOM@MX          *MAXREC for LCOE SELECT / LANSA/X                 */
/* IOM@SF          Send field names for LCOE SELECT first            */
/*                 time only.                                        */
/* IOM@LI          Length of I/O area (LANSA/X only)                 */
/* IOM@BL          Blocking factor for server and X full reads       */
/* IOM@IT          Immediate Transmission Request                    */
/* IOM@GI          Communications session identifier                 */
/* IOM@DG          Communications debug is enabled                   */
/* IOM@ST          ODBC Statement id (binary)                        */
/* IOM@MF          SuperServer mapping flags                         */
/* IOM@MS          SuperServer mapping status                        */

/* Positions 893 --> 900 are available as fchEDS1b                   */

/* Permanent fields beyond the overlay area ......                   */

/* DC@CPN          Current process name                              */
/* DC@LFN          Last function name                                */
/* DC@CFN          Current function name                             */
/* DC@NFN          Next function name                                */
/* DC@DCF          Direct call function name                         */
/* DC@WIS          Wide screen indicator ('Y' 'N')                   */
/* DC@D$P          Process to be de-bugged                           */
/* DC@D$F          Function to be de-bugged                          */
/* DC@D$E          Debug currently enabled for a function            */
/* DC@CFS          Current function DC@F29/30 set number             */
/* DC@JCC          Optional job completion code (Y or N)             */
/* DC@SXT          Suspended next task to be performed               */
/* DC@SGM          Suspended next program to be called               */
/* DC@L$P          Locked process name                               */
/* DC@L$F          Locked function name                              */
/* DC@MSG          Work with Developer Messages (Y/N)                */
/* DC@DEV          Development User (Y/N)                            */

/* SAA/CUA details from partition definition F46IDS                  */
/* Bytes 1001 (SA@PMS) --> 1516 (SA@AAR)                             */
/* are available as variable fchEDS2                                 */

/* Task control flags                                                */

/* DC@TCA          Task control is active (Y/N)                      */
/* DC@TNW          User must have task no. (Y/N)                     */
/* DC@TNP          Prompt/confirm task no. (Y/N)                     */
/* DC@TCN          Allow user to change tasks (Y/N)                  */

/* Bytes 1521 (SA@WBS) --> 1547 (DC@EDL)                             */
/* are available as variable fchEDS3                                 */

/* ML@1LO          One language only Enabled under Multiling         */
/* DC@IUE          Import user exit program (ex DC@A07).             */
/* DC@ILK          Job has issued locks via LOCK_OBJECT BIF          */

/* Bytes 1560 (DC@DTS) --> 1571 (1 byte after DC@UIL)                */
/* are available as variable fchEDS4                                 */

/* DC@CTY          Client Type (L=LCOE/Server, X=LANSA/X)            */

/* DC@LIO          Last file I/O status code (*DBMS_RECORD_LOCKED)   */

/* W3@FRM          LANSA for the Web - frame sent ?                  */
/* W3@HOM          LANSA for the Web - home page ?                   */
/* W3@WEB          LANSA for the Web                                 */

/* Batch debug device & message queue.                               */

/* BD@DBG          Batch debugging turned on (Y/N)                   */
/* BD@DEV          Device to be used for debugging                   */
/* BD@MSG          Message queue for debug questions                 */

/* W3@WEE          WEB - use extended exchange                       */

/* DC@CRF          Function is being created                         */

/* XL@PEN         XML - Primary Extension Name                       */
/* XL@SEN         XML - Secondary Extension Name                     */

/* DC@IMP         Task Tracking for Import                           */
/* DC@PIL         Partition level '1'= LL2 (RDMLX)                   */
/* DC@NOL         New object level.Y= LL2 (RDMLX)                    */
/* DC@MIC         Y= migrate to LL2 (RDMLX) without confirm          */

/* Bytes 1655 --> 1679 are currently spare - fchSpare2               */

/* Multilingual flags from F46IDS & F60IDS                           */

/* ML@LDC          Multilingual - IGCCNV key desc. length S(2,0)     */
/* ML@CNV          Multilingual - IGCCNV required (Y/N)              */
/* ML@KCV          Multilingual - IGCCNV function key                */
/* ML@DCV          Multilingual - IGCCNV key description             */
/* ML@LCV          Multilingual - IGCCNV line number                 */
/* ML@DEV          Multilingual development language (Y/N)           */
/* ML@MSG          Multilingual message files                        */
/* DC@MLP          Multilingual partition indicator (Y/N)            */
/* ML@CLN          Current language code                             */
/* ML@CLD          Current language description                      */
/* ML@LRL          Current language is left-to-right                 */
/* ML@IGL          Current language is IGC / DBCS                    */
/* ML@RLL          Current language is right-to-left                 */
/* ML@DLN          Default development language                      */
/* ML@LRT          Total left-to-right languages in partition (P 3,0)*/
/* ML@IGT          Total IGC / DBCS languages in partition P(3,0)    */
/* ML@RLT          Total right-to-left languages in partition P(3,0) */

/* Bytes 1836 (2 bytes before P#@PHM) --> 2271 (SA@WRK)              */
/* are available as variable fchEDS5                                 */

/* DC@ANL          Number of entries in the list (advanced) P(7,0)   */
/* DC@PCN          Initiating PC Name                                */
/* DC@LCF          Limit Capabilities Flag (from USRPRF)             */

/* Bytes 2287 --> 2300 are currently spare - fchSpare3               */

/* CP@CID          CPIC Communication Control information            */
/* DC@ROT          Root Directory from VL runtime                    */

/* Bytes 2339 --> 2500 are currently spare - fchSpare4               */

struct X_EDS_RPG
{
   X_FCHAR         fchDC_IDN[6];
   X_FCHAR         fchDC_NXT[5];
   X_FCHAR         fchDC_PGM[10];
   X_CHAR          chDC_PLT;
   X_CHAR          chDC_PF1;
   X_CHAR          chDC_PF2;
   X_FCHAR         fchDC_HLM[10];
   X_CHAR          chDC_OCH;
   X_CHAR          chDC_ODM;
   X_CHAR          chDC_OAM;
   X_CHAR          chDC_RET;
   X_FCHAR         fchDC_MID[7];
   X_FCHAR         fchDC_MVR[132];
   X_FCHAR         fchDC_CPI[10];
   X_FCHAR         fchDC_CFI[7];
   X_CHAR          chDC_OAP;
   X_FCHAR         fchDC_NUP[3];
   X_CHAR          chDC_FUM;
   X_CHAR          chDC_RTP;
   X_FCHAR         fchDC_WRN[8];
   X_FCHAR         fchDC_RRN[8];
   X_CHAR          chDC_DBG;
   X_FCHAR         fchDC_DBP[10];
   X_CHAR          chDC_DCI;
   X_CHAR          chDC_CWF;
   X_FCHAR         fchSpare1[2];
   X_CHAR          chDC_ACC;
   X_FCHAR         fchDC_E_I[3];
   X_CHAR          chDC_WIU;
   X_CHAR          chDC_DFS;
   X_FCHAR         fchEDS1a[18];
   X_FCHAR         fchIOM_UF[10];
   X_FCHAR         fchIOM_UM[10];
   X_FCHAR         fchIOM_BF[10];
   X_FCHAR         fchIOM_BM[10];
   X_FCHAR         fchIOM_QS[256];
   X_FCHAR         fchIOM_KF[256];
   X_FCHAR         fchIOM_AC[4];
   X_FCHAR         fchIOM_OP[8];
   X_FCHAR         fchIOM_S1[4];
   X_FCHAR         fchIOM_S2[4];
   X_FCHAR         fchIOM_CM[4];
   X_FCHAR         fchIOM_TY[8];
   X_CHAR          chIOM_FC;
   X_CHAR          chIOM_LO;
   X_FCHAR         fchIOM_MX[15];
   X_CHAR          chIOM_SF;
   X_FCHAR         fchIOM_LI[8];
   X_FCHAR         fchIOM_BL[4];
   X_CHAR          chIOM_IT;
   X_FCHAR         fchIOM_GI[2];
   X_CHAR          chIOM_DG;
   X_CHAR          chIOM_ST;
   X_FCHAR         fchIOM_MF[15];
   X_FCHAR         fchIOM_MS[3];
   X_FCHAR         fchEDS1b[8];
   X_FCHAR         fchDC_CPN[10];
   X_FCHAR         fchDC_LFN[7];
   X_FCHAR         fchDC_CFN[7];
   X_FCHAR         fchDC_NFN[7];
   X_FCHAR         fchDC_DCF[10];
   X_CHAR          chDC_WIS;
   X_FCHAR         fchDC_D_P[10];
   X_FCHAR         fchDC_D_F[7];
   X_CHAR          chDC_D_E;
   X_FCHAR         fchDC_CFS[2];
   X_CHAR          chDC_JCC;
   X_FCHAR         fchDC_SXT[5];
   X_FCHAR         fchDC_SGM[10];
   X_FCHAR         fchDC_L_P[10];
   X_FCHAR         fchDC_L_F[10];
   X_CHAR          chDC_MSG;
   X_CHAR          chDC_DEV;
   X_FCHAR         fchEDS2[516];
   X_CHAR          chDC_TCA;
   X_CHAR          chDC_TNW;
   X_CHAR          chDC_TNP;
   X_CHAR          chDC_TCN;
   X_FCHAR         fchEDS3[27];
   X_CHAR          chML_1LO;
   X_FCHAR         fchDC_IUE[10];
   X_CHAR          chDC_ILK;
   X_FCHAR         fchEDS4[12];
   X_CHAR          chDC_CTY;
   X_FCHAR         fchDC_LIO[5];
   X_CHAR          chW3_FRM;
   X_CHAR          chW3_HOM;
   X_FCHAR         fchW3_WEB[40];
   X_CHAR          chBD_DBG;
   X_FCHAR         fchBD_DEV[10];
   X_FCHAR         fchBD_MSG[10];
   X_CHAR          chW3_WEE;
   X_CHAR          chDC_CRF;
   X_FCHAR         fchXL_PEN[3];
   X_FCHAR         fchXL_SEN[5];
   X_CHAR          chDC_IMP;
   X_CHAR          chDC_PIL;
   X_CHAR          chDC_NOL;
   X_CHAR          chDC_MIC;
   X_CHAR          chDC_SCH;
   X_CHAR          chDC_LDZ;
   X_CHAR          chDC_LUA;
   X_FCHAR         fchSpare2[22];
   X_FCHAR         fchML_LDC[2];
   X_CHAR          chML_CNV;
   X_FCHAR         fchML_KCV[2];
   X_FCHAR         fchML_DCV[10];
   X_FCHAR         fchML_LCV[2];
   X_CHAR          chML_DEV;
   X_FCHAR         fchML_MSG[100];
   X_CHAR          chDC_MLP;
   X_FCHAR         fchML_CLN[4];
   X_FCHAR         fchML_CLD[20];
   X_CHAR          chML_LRL;
   X_CHAR          chML_IGL;
   X_CHAR          chML_RLL;
   X_FCHAR         fchML_DLN[4];
   X_FCHAR         fchML_LRT[2];
   X_FCHAR         fchML_IGT[2];
   X_FCHAR         fchML_RLT[2];
   X_FCHAR         fchEDS5[436];
   X_FCHAR         fchDC_ANL[4];
   X_FCHAR         fchDC_PCN[10];
   X_CHAR          chDC_LCF;
   X_FCHAR         fchSpare3[14];
   X_FCHAR         fchCP_CID[8];
   X_FCHAR         fchDC_ROT[30];
   X_FCHAR         fchSpare4[162];
};

/* ================================================================= */
/*  X_PRIDS_RPG : PR@IDS structure for LANSA for iSeries RPG runtime.*/
/*                                                                   */
/*  Required to pass to LANSA for iSeries RPG runtime programs.      */
/*  Refer to PR@ISPEC for individual fields.                         */
/* ================================================================= */

struct X_PRIDS_RPG
{
   char               vchPRIDS[5000];
};

/* ================================================================= */
/*  WARNING - WARNING - WARNING - WARNING - WARNING - WARNING        */
/* ================================================================= */
/*                                                                   */
/* You must not perform any action that causes the element layout    */
/* in X_IDS to change from one version of LANSA/X to another. The    */
/* X_IDS structure can be lengthened by adding new elements to the   */
/* end of it at any time, but changes to the elemental layout would  */
/* force LANSA/X users to have to (re)generate and (re)compile every */
/* single process, function and OAM that they have. This is clearly  */
/* not acceptable, so changes to the elemental layout cannot be      */
/* made in any way, shape or form. When changing any structure       */
/* please consider upward compatibility issues. If the structure     */
/* (or any of its elements) are referenced in generated code then    */
/* it is unlikely that you can change the structure layout.          */
/*                                                                   */
/* ================================================================= */
/*  WARNING - WARNING - WARNING - WARNING - WARNING - WARNING        */
/* ================================================================= */



/* ================================================================= */
/*  X_Ids : LANSA/X Global System Definition                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* StructSize      Size of this structure                            */
/* Mode            Mode of this "job" (I=Interactive, B=batch        */
/* ShutDown        Shutdown the object just called                   */
/* DebugOn         Debugging Mode is currently On                    */
/* SysOwner        Name of LANSA System Owner Profile                */
/* FatalError      Low level function call experienced fatal error   */
/* Partition       Current Partition Identifier                      */
/* LangCode        Current Language Code                             */
/* LangType        Current Language Type                             */
/* Developer       User is a developer                               */
/* AutoHelp        Automatic field level help generation enabled     */
/* TempDir         Fully qualified directory for temporary files     */
/* RRNODir         Fully qualified directory for RRNO files          */
/* Exch            Exchange List Area                                */
/* LDA             Local Data Area Emulation Block                   */
/* pX_UIM          Pointer to current X_UIM structure in use         */
/* ModuleLib       Module Library associated with current partition  */
/* Next            Next Function to call after an inter process call */
/* ActiveProcDesc  Currently active process description              */
/* DBId            Database Identifier (User Defined Tables)         */
/* Product         Product Name                                      */
/* Company         Company/Organisation Name                         */
/* OSVersion       Operating system version (3,1)                    */
/* Date            Current date in installation format               */
/* DMYDate         Current date in Day/Month/Year format             */
/* YMDDate         Current date in Year/Month/Day format             */
/* MDYDate         Current date in Month/Day/Year format             */
/* JulianDate      Current date in Julian format                     */
/* JobName         Current job name                                  */
/* JobNumber       Current job number                                */
/* ProdRel         LANSA Product release no. (3,1)                   */
/* PgmLib          LANSA Program Library                             */
/* DtaLib          LANSA Data Library                                */
/* PartDtaLib      Partition Data Library                            */
/* CenturyCmp      Century compare date                              */
/* CenturyGT       Century compare date for greater than             */
/* CenturyLE       Century compare date for less than or equal to    */
/* LangDesc        Current Language Description                      */
/* DecimalPoint    Decimal Point character (QDECFMT)                 */
/* ThousandSep     Thousands separator character                     */
/* DateSeparator   Date separator character (QDATSEP)                */
/* CurrencySymbol  Currency symbol character (QCURSYM)               */
/* PartDesc        Current Partition Description                     */
/* TimeSeparator   Time separator character                          */
/* vchDisplayDate  Displayable Data                                  */
/* chSpare_1       Spare bytes (from old chDrive field)              */
/* chFileSecurityDisabled                                            */
/* chProcessSecurityDisabled                                         */
/* chFunctionSecurityDisabled                                        */
/* vchPartSecOfficer                                                 */
/* SysDateFmt      System Date Format (installation format)          */
/* sButton2DblClkFKey Function Key to simulate when Button 2 Dbl Clk */
/* sButton3DblClkFKey Function Key to simulate when Button 3 Dbl Clk */
/* pConnectComputer   Pointer to X_CONNECT_COMPUTER chain            */
/* pConnectFile       Pointer to X_CONNECT_FILE chain                */
/* chJobLock          Indicates a lock exists for this job           */
/* GroupUser          Group User Name                                */
/* PrinterPort        Name of printer port e.g. LPT2:                */
/* SpecialSecOfficer  Name of Special Security Officer               */
/* EventLogOpen       UIM Event Log is currently open                */
/* HashSign           Hash sign ('#') character                      */
/* AtSign             At sign ('@') character                        */
/* StandardMessageFile Standard Message File Name                    */
/* pX_InvocTrack      Pointer to invocation tracking structures      */
/* DollarSign         Dollar sign ('$') character                    */
/* XRoot              Lansa/X Root Directory for all versions        */
/* PartitionLower     Partition name in lower case characters        */
/* DBCSEnvironment    This process is running in a DBCS environment  */
/* EDLCParameter      Setting of the EDLC= parameter option          */
/* 3GLDebugOn         Set to display 3GL debug messages              */
/* pX_Lang            Pointer to language list                       */
/* Invoke[*]          Invocation stack of processes/functions        */
/* MBNCOption         MBNC= Option from the X_RUN command            */
/* InternalDBMSSource Internal I/O Data base Source                  */
/* InternalIO         Internal I/O handling function                 */
/* UserDBMSSource     User I/O Data Base Source                      */
/* UserIO             User I/O handling function                     */
/* DBIdInternal       Database Identifier (Internal Tables)          */
/* ConnectAutoStatus  Automatic connection status                    */
/* pConnectAuto       Optional pointer to X_CONNECT_AUTO details     */
/* pX_IdsOS           Operating System dependant variables           */
/* DBMInstance        Instance pointer for DBM structure             */
/* DBIInstance        Instance pointer for DBI structure             */
/* XQLInstance        Instance pointer for XQL structure             */
/* pX_TxtMsg          Pointer to associated X_TXTMSG details         */
/* scX_ExchDS         Counter of exchange data structures            */
/* pX_ExchDS          Pointer to Array of exchange data structures   */
/* sTrackMax          Current number being tracked - Now redundant   */
/* pTrackOAM          OAM tracking list - Now redundant              */
/* pObjAuthsList      Object authorities list                        */
/* sAuthCount         Current count of authorities stored in list    */
/* sCurrentAuth       Current authorities list index                 */
/* pStaticMIOC        Static communications area                     */
/* pChainMIOList      Pointer to chain of MIOC areas                 */
/* sNumVisibleScrollItems  No. of Items up to which to visibly scroll*/
/*                         a Browse List. Make Invisible after this. */
/* chUseIconMenuAbar  indicates if UIM should use icon menu and abar */
/*                    style, or the older menu/abar style            */
/* pProcessAlias      Pointer to array of process renames/alias      */
/* chDefaultMsgDisplayed Error msg is already the default.           */
/* HSKCEnabled        HSKC option is enabled                         */
/* cHSKCHeader        Count of HSKC header structures in existence   */
/* pHSKCHeader        Pointer to first HSKC header structure         */
/* cHSKCEligible      Count of HSKC eligible structures in existence */
/* pHSKCEligible      Pointer to first HSKC elibible                 */
/* LX_F04_ISAM_Set    Current LX_F04 ISAM Set (if any)               */
/* LX_F05_ISAM_Set    Current LX_F05 ISAM Set (if any)               */
/* LX_F06_ISAM_Set    Current LX_F06 ISAM Set (if any)               */
/* LX_F07_ISAM_Set    Current LX_F07 ISAM Set (if any)               */
/* LX_F64_ISAM_Set    Current LX_F64 ISAM Set (if any)               */
/* LX_F65_ISAM_Set    Current LX_F65 ISAM Set (if any)               */
/* LX_F67_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F44_ISAM_Set    Current LX_F44 ISAM Set (if any)               */
/* pLANSAPC           Pointer to LANSA/PC connection structure       */
/* pEditProc          Pointer to details of process being edited     */
/* QNAM               QNAM value specified on X_RUN command          */
/* QCHK               QCHK value specified on X_RUN command          */
/* QHLD               QHLD value specified on X_RUN command          */
/* fJobqLoadAttempted Jobq queue load attempt has been made          */
/* uscJobq            Number of job queue details available          */
/* pJobq              Pointer to first job queue structure           */
/* JobqPriority       Submit job queue priority to be used           */
/* UnderJobqEmulate   This job is running under job queue emulation  */
/* LastSbmTime        Time of last SUBMIT command                    */
/* NextSbmSuffix      Next suffix to be used in a SUBMIT command     */
/* CDLLName           CDLL= option from the X_RUN command            */
/* ODBCAOption        ODBC Option A to have dual ODBC connections    */
/* CMTHOption         CMTH= option from the X_RUN command            */
/* CRMUSupported      CRMU= option from the X_RUN command            */
/* pDBMSTypes         Pointer to DBMS types and details              */
/* pUserDBMSInfo      Pointer to User DBMS information               */
/* pInternalDBMSInfo  Pointer to Internal DBMS information           */
/* PBFPColour         Panel Body - Field Prompt Colour               */
/* PBCMColour         Panel Body - Column Heading Colour             */
/* apExpand           Pointers for future expansion                  */
/* apfExpandFreeRes   Resource Freeing function                      */
/*                    Allocation must be noted below                 */
/* OAMRqsType         OAM Request Type                               */
/* HeavyTransaction   Heavy Transaction Mode has been turned on      */
/* pTrackStmt         Pointer to chain of SQL statements to track    */
/* HeavySyncCount     Heavy Sync Point Counter                       */
/* HeavySyncTrigger   Heavy Sync Point commit trigger level          */
/* PPTHDir            Fully qualified directory for printer files    */
/* IMEforKeyboardJ    DBCS IME control value for keyboard shift J-on */
/* IMEforKeyboardJOff DBCS IME control value for keyboard shift J-off*/
/* IMEforKeyboardJAct DBCS IME control value for keyboard shift J    */
/* IMEforKeyboardE    DBCS IME control value for keyboard shift E-on */
/* IMEforKeyboardEOff DBCS IME control value for keyboard shift E-off*/
/* IMEforKeyboardEAct DBCS IME control value for keyboard shift E    */
/* IMEforKeyboardO    DBCS IME control value for keyboard shift O-on */
/* IMEforKeyboardOOff DBCS IME control value for keyboard shift O-off*/
/* IMEforKeyboardOAct DBCS IME control value for keyboard shift O    */
/* IMEforKeyboardW    DBCS IME control value for keyboard shift W-on */
/* IMEforKeyboardWOff DBCS IME control value for keyboard shift W-off*/
/* IMEforKeyboardWAct DBCS IME control value for keyboard shift W    */
/* IMEforKeyboardG    DBCS IME control value for keyboard shift G-on */
/* IMEforKeyboardGOff DBCS IME control value for keyboard shift G-off*/
/* IMEforKeyboardGAct DBCS IME control value for keyboard shift G    */
/* IMEforAlphanumeric DBCS IME control value for other alphanum - on */
/* IMEforAlphanumericOff   IME control value for other alphanum - off*/
/* IMEforAlphanumericAct   IME control value for other alphanum      */
/* IMEforNumeric      DBCS IME control value for numerics - on       */
/* IMEforNumericOff   DBCS IME control value for numerics - off      */
/* IMEforNumericAct   DBCS IME control value for numerics            */
/* IMEDLLName         DBCS IME DLL name                              */
/* EStyleforKeyboardJ DBCS window creation style : keyboard shift J  */
/* EStyleforKeyboardE DBCS window creation style : keyboard shift E  */
/* EStyleforKeyboardO DBCS window creation style : keyboard shift O  */
/* EStyleforKeyboardW DBCS window creation style : keyboard shift W  */
/* EStyleforKeyboardG DBCS window creation style : keyboard shift G  */
/* EStyleforAlphanumeric DBCS creation style : alphanumeric          */
/* EStyleforNumeric      DBCS creation style : alphanumeric          */
/* ExchangeAllFields     DBCS creation style : alphanumeric          */
/* SystemShutDownMode System is in shudown mode                      */
/* GenAtSign          '@' sign character used at generation time     */
/* XVecAssignOption   Extended X_Vec_Assign Option                   */
/* InternalTracing    Internal Tracing is turned on                  */
/* MaxTraceEntries    Maximum Trace Entries                          */
/* CurTraceEntries    Current Trace Entries                          */
/* TracingIndent      Current Trace Level Indenting                  */
/* TracingLevel       Tracing Level                                  */
/* TracingCategories  Tracing Categories                             */
/* TracingFile        Tracing File                                   */
/* cX_FunRtr          Count of functions in function routing table   */
/* pX_FunRtr          Pointer to first entry in routing table        */
/* sPCOSVersion       Operating System Version.  e.g. Win95, WinNT   */
/* vchEXPO            EXPO= parameter value                          */
/* pfEXPO             File associated with EXPO parameter            */
/* vchEXPM            EXPM= parameter value                          */
/* pfEXPM             File associated with EXPM parameter            */
/* vchEXPR            EXPR= parameter value                          */
/* LIMPORT            X_RUN is executing from LANSA/PC LIMPORT       */
/* REFRESH            X_RUN is executing from LANSA/PC LIMPORT       */
/*                    in refresh mode                                */
/* PLUGIN             X_RUN is executing from LANSA/PC LIMPORT       */
/*                    in plug in mode                                */
/* pRemFileStartofChain Start of remove file chain                   */
/* pRemFileEndofChain   End of remove file chain                     */
/* vchConnectPartition  Partition to Connect To                      */
/* ODBCIOption        ODBC Isolation Level Option (ODBI=)            */
/* ODBCUncommittedRead  ODBC Uncommitted Read connection required    */
/* pX_IdsComponent      Pointer X_IDS_COMPONENT information          */
/* ExecutionState       Execution State                              */
/* vchFORM              Mapping of FORM= parameter                   */
/* pfnX_LServerServices Pointer to X_LServer_Services in X_LSV.DLL   */
/* hX_LSVDLL            X_LSV.DLL handle (if loaded)                 */
/* pfnX_SServerServices Pointer to X_SServer_Services in X_SSV.DLL   */
/* hX_SSVDLL            X_SSV.DLL handle (if loaded)                 */
/* pfnX_UIM_Manager     Pointer to X_UIM_Manager in X_UIM or X_USV   */
/* hX_UIMDLL            X_UIM.DLL or X_USV.DLL handle (if loaded)    */
/* TracingFileName      Name of the file being used to trace into    */
/* Dat8                 Current date in installation format 8 digits */
/* Century              Century of current date                      */
/* vchInitialExecutable Initial Executable - Process, Form, etc.     */
/* fFirstUserProcess    First User Process                           */
/* fINITFunctionExecuted Initial Function has been executed          */
/* fTERMFunctionExecuted Termination Function has been executed      */
/* vchINITFunction       Initial Function from INIT=                 */
/* vchTERMFunction       Termination function from TERM=             */
/* ulRDMLLevelUIMCallCount Calls to UIM Manager from RDML proc/func  */
/* fForceAllXQFileUsage  Force use of .XQ* files regardless of DBII= */
/* LX_F14_ISAM_Set       Current LX_F14 ISAM Set (if any)            */
/* LX_F15_ISAM_Set       Current LX_F15 ISAM Set (if any)            */
/* LX_F54_ISAM_Set       Current LX_F54 ISAM Set (if any)            */
/* ulTotalISAM           Total ISAM Files Open                       */
/* pISAM                 Pointer to ISAM File details                */
/* ulFXQMParameter       FXQM parameter from X_RUN command           */
/* vchFileCheckRetCode   Last return code from X_Code_File_Check     */
/* ulOSLevelLanguage     Operating system level language code        */
/* fBypassQuestions      Bypass user interraction questions          */
/* sEventLogIcon         The Event Log Window bitmap ID.             */
/* User                  User Name                                   */
/* GroupAuth             Group Authority                             */
/* vchPassWd             Password for DBMS authentication            */
/* chNoFatal             Bypass fatal error.                         */
/* lLastErrorCode        The last error code.                        */
/* chDELI                DELI parameter ('Y'/'N'). Not used          */
/* vchPKGD               Package directory.                          */
/* chRunInstall          Does Package Installer need to be run? (Y/N)*/
/* pActiveCompRtnX_Fun   Active component routine pX_Fun             */
/* chUPSI                Upgrade Single Install (Y/N/P) (P = prompt) */
/* chDASO                Data Area Storage Option                    */
/* vchIPKG               Installed package (for network clients only)*/
/* chUPGD                Upgrade? (Y/N/A/R) (A = All) (R = Refresh)  */
/* chUPCF                Continue if Upgrade Connect Failure (Y/N/P) */
/* chUPDF                Continue if Upgrade Download Failure (Y/N/P)*/
/* chConnectASXXStatus   Like chConnectAutoStatus, but for App Server*/
/* pConnectASXX          Like pConnect, but for Application Server   */
/* chASKC                Keep AS Connection? (Y/N/R) (R = Reopen)    */
/* chUPTP                Upgrade Type (D/P) (D = DLL, P = Package)   */
/* pulNormalIOCounter    Pointer to Normal I/O counter (if any)      */
/* pulSServerIOCounter   Pointer to S-Server I/O counter (if any)    */
/* chRunTimeHelpStyle    'O' = old windowing style                   */
/*                       'S' = standard tri-pane style (WIN32 default)*/
/* vchRunTimeHelpFile    Windows Help file to be used                */
/* chMULT                Upgrade all apps from the host? (Y/N)       */
/* chUPMP                Upgrade mandatory packages (Y/P) (P = prompt)*/
/* chUPOP                Upgrade optional packages (Y/N/P)           */
/* chUPFP                Download full package? (Y/N)                */
/* chImportSecurity      LIMPORT Security setting (D/R/A)            */
/*                       'D' = Delete all records for an object      */
/*                       'R' = Replace individual records on import  */
/*                       'A' = Append new records, ignore duplicates */
/* fHaveLoadedTextFileList Set to TRUE when the list of file-        */
/*                         extensions that we consider to be 'text'  */
/*                         has been loaded.                          */
/* pTextFiles             A list of the aforementioned extensions    */
/* LX_MSG_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F03_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F08_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F09_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F10_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F11_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F26_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F27_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F40_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F61_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F62_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/* LX_F66_ISAM_Set    Current LX_F67 ISAM Set (if any)               */
/*                                                                   */
/* ----------------------------------------------------------------- */
/* Allocation of new/upgraded pointers assigned for future expands   */
/* ----------------------------------------------------------------- */
/*                                                                   */
/*  Pointer           Assigned To / Used For                         */
/*  -------           ----------------------                         */
/* apExpand[0]        Graphic Server Tracking                        */
/* apExpand[1]        Extended Drop Down Attribute Tracking          */
/* apExpand[2]        DLL and Entry Point Tracking (Start of chain)  */
/* apExpand[3]        DLL and Entry Point Tracking (End of chain)    */
/* apExpand[4]        RB Tree to track LOB cursors, etc. (OAMs)      */
/* apExpand[5]        Communication DLL procedure addresses (X_PDF8) */
/* apExpand[6]        Rename tracking tree (Only when *SSERVER)      */
/* apExpand[7]        Unassigned                                     */
/* apExpand[8]        Unassigned                                     */
/* apExpand[9]        Unassigned                                     */
/* apExpand[10]       Space Management Anchor Block                  */
/* apExpand[11]       DBF file production (X_FUN11.C)                */
/* apExpand[12]       Assigned to flat file data area emulation      */
/* apExpand[13]       Unassigned                                     */
/* apExpand[14]       Assigned to extended printing                  */
/* apExpand[15]       Assigned to extended printing                  */
/* apExpand[16]       Assigned to extended printing                  */
/* apExpand[17]       Assigned to MAIL_ BIFS for local memory        */
/* apExpand[18]       Assigned by agreement to OV_INDEXED_SPACE      */
/* apExpand[19]       Assigned by agreement to OV_xxxx's using DDE   */
/* chFieldExit        YES if need to treat NumPad Enter as a Tab     */
/* fQuietModeExecution Execute batch jobs without errors or event logs */
/* fCrossPartitionMode Execution is in cross partition mode            */
/* pWebInfo           Holds global info for Web Jobs only            */
/* pZipInfo           Zip & Unzip DLL and Entry Point Tracking       */
/* chSysexportLX_MSG  Y if auto-sysexport LX_MSG on LIMPORT, et al   */
/* pXQLCache          Holds cached repository data from Server       */
/* pConnectDatabase   Pointer to X_CONNECT_DATABASE chain            */
/* fODBCTimestamp     True if X_Quote_String needs to handle date/time */
/* vchDevLangCode     Development Language Code for LANSA in LANSA apps */
/* pchIOMUsedGrpFlds  Array of Y/N matching pX_DBM->scGrpFlds vecs   */
/*                    Indicates (for last IOM call) which fields are */
/*                    actually on the file. Is always set to pX_NULL */
/*                    at start of X_PDF_Execute_IO_Module()          */
/* fUseNativeIO       TRUE to use Native IO, else FALSE.             */
/* vchLOBRoot         LPTH= value. Must be short enough to fit the   */
/*                    various subdirectories and LOB filename <= 256 */
/* vchWebSessionId    Deprecated - first byte must be 0 so OAMs with */
/*                    LOBs built before 12 + 859 work correctly      */
/* pX_Ids_RPG         Ptr to iSeries RPG runtime DC@IDS structure    */
/* pX_Eds_RPG         Ptr to iSeries RPG runtime DC@EDS structure    */
/* pX_PrIds_RPG       Ptr to iSeries RPG runtime PR@IDS structure    */
/* pSaveLibl          Ptr to iSeries saved libraries (up to 250)     */
/* pSaveLDA           Ptr to iSeries saved *LDA                      */
/* chDateSource       Date Source for iSeries (S=*SYSTEM, J=*JOB)    */
/* AuditUser          Current Audit User (for DB audit stamping)     */
/* fchF60MSGDft       Default language user message file names used  */
/*                    for overriding message files on iSeries.       */
/* vchInvocStackName  iSeries invocation stack entry name for escape */
/*                    message routing from DC@P0006.                 */

#define X_LOB_CURSOR_TREE_ANCHOR            4
#define X_SPACE_MANAGER_ANCHOR             10
#define X_XDB_FILE_ANCHOR                  11
#define X_DATA_AREA_TRACKING_ANCHOR        12
#define X_WINDOWS_PRINTING_ANCHOR          14
#define X_EXPAND_EXTENDED_PRINTER          15
#define X_EXPAND_EXTENDED_PRINTER_FONT     16
#define X_EXPAND_MAIL_BIFS                 17


#define X_EXTENDED_PRINT_DEFAULT         'D'
#define X_EXTENDED_PRINT_FIRST_TIME      'F'
#define X_EXTENDED_PRINT_EVERY_TIME      'E'
#define X_EXTENDED_PRINT_AUTOMATIC       'A'
#define X_EXTENDED_PRINT_DEFAULT_FONT    "Courier New"

#define X_USE_DBM_SCKEYFLDS             -999

#define X_VEC_ASSIGN_ROUND_UP  'R'
#define X_VEC_ASSIGN_TRUNCATE  'T'
#define X_VEC_ASSIGN_DEFAULT   ' '

#define X_EXPAND_POINTERS  20

#define X_NO_DATA_BASE              'N'
#define X_REMOTE_SERVER_DATA_BASE   'A'
#define X_LOCAL_CLIENT_DATA_BASE    'D'

#define X_CONNECT_AUTO_NOT_IN_USE  'N'
#define X_CONNECT_AUTO_PENDING     'P'
#define X_CONNECT_AUTO_ACTIVE      'A'
#define X_CONNECT_AUTO_FAILED      'F'

#define X_LANGUAGE_LRTB   'L'
#define X_LANGUAGE_DBCS   'D'
#define X_LANGUAGE_RLTB   'R'

#define X_LANGUAGE_IS_LRTB      (pX_Ids->chLangType == X_LANGUAGE_LRTB)
#define X_LANGUAGE_IS_DBCS      (pX_Ids->chLangType == X_LANGUAGE_DBCS)
#define X_LANGUAGE_IS_RLTB      (pX_Ids->chLangType == X_LANGUAGE_RLTB)

#define X_JOB_MODE_INTER        ( 'I')
#define X_JOB_MODE_BATCH        ( 'B')

#define X_JOB_MODE_IS_INTER     (pX_Ids->chMode == 'I')
#define X_JOB_MODE_IS_BATCH     (pX_Ids->chMode == 'B')

#define X_EXECUTION_LEVEL_ALL       'A'
#define X_EXECUTION_LEVEL_PARTITION 'P'
#define X_EXECUTION_LEVEL_SYSTEM    'S'

#define X_NATIONAL_LANGUAGE_ONLY "NAT"

#define X_CMTH_CPIC      'C'  /* CPIC Communications                       */
#define X_CMTH_CA400     'E'  /* Client/Access 400 Communications          */
#define X_CMTH_TCPIP     'T'  /* TCP/IP (actually the same as X_CMTH_CPIC) */

#if defined(X_OPERATING_SYSTEM_WIN)
#define X_CDLL_DEFAULT  "LCOMGR32"
#define X_CMTH_DEFAULT  X_CMTH_CPIC
#else
#define X_CDLL_DEFAULT  "CPIC"
#define X_CMTH_DEFAULT  X_CMTH_CPIC
#endif

#define X_ODBC_ISOLATION_LEVEL_DEFAULT  '0'
#define X_ODBC_ISOLATION_LEVEL_READ_UNCOMMITTED  '1'
#define X_ODBC_UNCOMMITTED_READ_DEFAULT FALSE
#define X_ODBC_IGNORE_GENERAL_WARNING  "IG"
#define X_ODBC_IGNORE_ALL_WARNING      "IA"

/* --------------------------------------------------------------*/
/* N.B. The UIM Client is loaded when Exec State <= CLIENT_BATCH */
/* otherwise the UIM Server is loaded.                           */
/* --------------------------------------------------------------*/
#define X_EXECUTION_STATE_CLIENT_INTER         '\x01'
#define X_EXECUTION_STATE_CLIENT_COMPONENTS    '\x02'
#define X_EXECUTION_STATE_CLIENT_BATCH         '\x03'
#define X_EXECUTION_STATE_SERVER_SSERVER       '\x04' /* LANSA/X S/Server                    */
#define X_EXECUTION_STATE_SERVER_LSERVER       '\x05' /* LANSA/Server                        */
#define X_EXECUTION_STATE_SERVER_BATCH_CHILD   '\x06' /* Direct or indirect Child of server  */
#define X_EXECUTION_STATE_SERVER_WEB_JOB       '\x07' /* LANSA/X Web Server                  */
#define X_EXECUTION_STATE_SERVER_ASERVER       '\x08' /* LANSA/X Async/Server                */
/* Read further notes at RESET_EXECUTION_STATE of X_PDF5.C */
/* #define X_EXECUTION_STATE_SERVER_XML_JOB       '\x08' */ /* LANSA/X XML Server                  */


#define FXQMParameterDEFAULT   60L

#define X_OS_LANGUAGE_FRA      10L
#define X_OS_LANGUAGE_JPN      20L
#define X_OS_LANGUAGE_ENG      30L
#define X_OS_LANGUAGE_ENG      30L
#define X_OS_LANGUAGE_KOR      40L
#define X_OS_LANGUAGE_TCHI     50L
#define X_OS_LANGUAGE_SCHI     60L
#define X_OS_LANGUAGE_OTHER  9000L

#define X_DASO_PARM_DBMS        'D'
#define X_DASO_PARM_FLAT_FILE   'F'
#define X_DASO_PARM_DEFAULT     X_DASO_PARM_DBMS

/*  Moved before ids definition for use there  */
#define X_ENVIRON_MAXIMUM_LANGUAGES   20
#define X_ISERIES_MESSAGE_FILE_LEN 10

#if defined(X_OPERATING_SYSTEM_ISERIES)
#define X_ISERIES_SAVE_LIBL_LEN (250 * 11)
#define X_ISERIES_SAVE_LDA_LEN   512
#endif

#define X_DBCL_1                 '1'
#define X_DBCL_2                 '2'
#if defined(X_OPERATING_SYSTEM_UNIX) && !defined(X_OPERATING_SYSTEM_ISERIES)
#define X_DBCL_DEFAULT           X_DBCL_1
#else
#define X_DBCL_DEFAULT           X_DBCL_2
#endif

/* Used in prototypes that require a generic enumeration type */
/* but handle various sets of enumerations c.f. X_Bit_Flag_Apply_Setting */
typedef enum
{
   X_DUMMY_FLAG = 0
} X_ENUM;

typedef enum _CONNECT_TYPE
{
   CT_DISPLAY_AUTHENTICATION_PROMPT    = 0x00000001,
   CT_not_used2                        = 0x00000002,
   CT_USE_CONNECTION_STRING            = 0x00000004,
   CT_SAVE_CONNECT_STRING              = 0x00000008,
   CT_not_used3                        = 0x00000010,
   CT_INTEGRATED_LOGON                 = 0x00000020,
   CT_DSN_ONLY_LOGON                   = 0x00000040,
   CT_DEFAULT_USER_LOGON               = 0x00000080,
   CT_OLD_STYLE_LOGON_SQLCONNECT       = 0x00000100,
   CT_OLD_STYLE_LOGON_SQLDRIVERCONNECT = 0x00000200,
   CT_AUTHENTICATION_ERROR_IS_FATAL    = 0x00000400,
   CT_INDIVIDUAL_CONNECTION            = 0x00000800,
   CT_DRIVER_PROMPT                    = 0x00001000,

   CT_ALL_FLAGS_ON                     = 0xFFFFFFFF
} X_DB_CONNECT_TYPE;

#define X_DBCF_DEFAULT  CT_INTEGRATED_LOGON

struct X_IDS
{
   X_LONG          sStructSize;
   X_TYPE_FLAG     chMode;
   X_YES_NO        chShutDown;
   X_YES_NO        chDebugOn;
   X_VCHAR         vchSysOwner[X_ISERIES_USER_NAME_LEN + 1];
   X_YES_NO        chFatalError;
   X_VCHAR         vchPartition[X_PARTITION_NAME_LEN + 1];
   X_VCHAR         vchLangCode[X_LANGUAGE_CODE_LEN + 1];
   X_TYPE_FLAG     chLangType;
   X_YES_NO        chDeveloper;
   X_YES_NO        chAutoHelp;
   X_SHORT         sCurrInvoc;
   struct X_INVOC  OldInvoc[9]; /* Do not remove */
   X_VCHAR         vchSpare1[65 - X_MSI_GUID_LEN - 1 ];
   X_VCHAR         vchUpgradeCode[X_MSI_GUID_LEN + 1];      // This GUID links all MSI and MSP created for an APPL in the Deployment Tool
   X_BYTE          ucCmdLineWindowShowCmd;                  // iCmdShow parameter from WinMain
   X_VCHAR         vchSpare2[65 + 1];
   struct X_EXCHL  Exch;
   X_FCHAR         fchLDA[X_LDA_LEN];
   struct X_UIM  * pX_UIM;
   X_VCHAR         vchModuleLib[X_OBJECT_NAME_LEN+1];
   X_VCHAR         vchNext[X_FUNCTION_NAME_LEN+1];
   X_VCHAR         vchActiveProcDesc[X_DESCRIPTION_LEN+1];
   X_YES_NO        chDBFatalError;     /* YES if X_SQL_Error has been called */
   X_CHAR          chExecutionLevel;
   X_VCHAR         __to_be_recycled_vchDBId[7];
   X_VCHAR         __to_be_recycled_vchDEPRECATEDUser[8 + 1];
   X_VCHAR         vchGroupAuth[10 + 1];
   X_VCHAR         vchProduct[5 + 1];
   X_VCHAR         vchCompany[30 + 1];
   X_SHORT         sOSVersion;
   X_VCHAR         vchDate[X_DATE_LEN + 1];
   X_VCHAR         vchDMYDate[X_DATE_LEN + 1];
   X_VCHAR         vchYMDDate[X_DATE_LEN + 1];
   X_VCHAR         vchMDYDate[X_DATE_LEN + 1];
   X_VCHAR         vchJulianDate[5 + 1];
   X_VCHAR         vchJobName[10 + 1];
   X_VCHAR         vchJobNumber[6 + 1];
   X_SHORT         sProdRel;
   X_VCHAR         vchPgmLib[10 + 1];
   X_VCHAR         vchDtaLib[10 + 1];
   X_VCHAR         vchPartDtaLib[10 + 1];
   X_VCHAR         vchCenturyCmp[2 + 1];
   X_VCHAR         vchCenturyGT[2 + 1];
   X_VCHAR         vchCenturyLE[2 + 1];
   X_VCHAR         vchLangDesc[40 + 1];
   X_CHAR          chDecimalPoint;
   X_CHAR          chThousandSep;
   X_CHAR          chDateSeparator;
   X_CHAR          chCurrencySymbol;
   X_VCHAR         vchPartDesc[X_DESCRIPTION_LEN+1];
   X_CHAR          chTimeSeparator;
   X_VCHAR         vchDisplayDate[X_DISPLAY_DATE_LEN + 1];
   X_CHAR          chLicenseSSV;
   X_YES_NO        chFileSecurityDisabled;
   X_YES_NO        chProcessSecurityDisabled;
   X_YES_NO        chFunctionSecurityDisabled;
   X_VCHAR         vchPartSecOfficer[X_ISERIES_USER_NAME_LEN + 1];
   X_VCHAR         vchSysDateFmt[X_DATE_FORMAT_LEN + 1];
   X_SHORT         sButton2DblClkFKey;
   X_SHORT         sButton3DblClkFKey;
   struct X_CONNECT_COMPUTER * pConnectComputer;
   struct X_CONNECT_FILE     * pConnectFile;
   X_CHAR          chJobLock;
   X_VCHAR         __to_be_recycled_vchDEPRECATEDGroupUser[8 + 1];
   X_VCHAR         vchPrinterPort[X_PRTR_PORT_NAME_LEN + 1];
   X_VCHAR         vchSpecialSecOfficer[X_ISERIES_USER_NAME_LEN + 1];
   X_YES_NO        chEventLogOpen;
   X_CHAR          chHashSign;
   X_CHAR          chAtSign;
   X_VCHAR         vchStandardMessageFile[X_OBJECT_NAME_LEN+1];
   X_DEFS_INVOCATION_TRACKING_PTR pX_InvocTrack;
   X_CHAR          chDollarSign;
   X_VCHAR         vchSpare3[20 + 1];
   X_VCHAR         vchPartitionLower[X_PARTITION_NAME_LEN + 1];
   X_YES_NO        chDBCSEnvironment;
   X_YES_NO        chEDLCParameter;
   X_YES_NO        ch3GLDebugOn;
   struct X_LANGUAGE *pX_Lang;
   struct X_INVOC  InvocFixed[X_MAX_INVOCATION_DEPTH_FIXED];
   X_BOOL          bMBNCOption;
   X_FCHAR         fchTaskId[X_TASK_ID_LEN];
   X_PVCHAR        pvchHelpBoldFont;
   X_CHAR          chInternalDBMSSource;
   X_PVOID         pfInternalIO;
   X_CHAR          chUserDBMSSource;
   X_PVOID         pfUserIO;
   X_VCHAR         __to_be_recycled_vchDBIdInternal[X_DBID_LEN + 1];
   X_CHAR          chConnectAutoStatus;
   struct X_CONNECT_AUTO         * pConnectAuto;
   struct X_UBIF_TRACKING        * pFirstUBIF;
   struct X_UBIF_TRACKING        * pLastUBIF;
   struct X_IDSOS                * pX_IdsOS;
   X_PVOID                         pDBMInstance;
   X_PVOID                         pDBIInstance;
   X_PVOID                         pXQLInstance;
   struct X_TXTMSG               * pX_TxtMsg;
   X_SHORT                         scX_ExchDS;
   struct X_EXCHANGE_STRUCT_LIST * pX_ExchDS;
   X_SHORT                         sTrackMax;  /* Now redundant */
   X_PVOID                         pTrackOAM;  /* Now redundant */
   X_MODULEHANDLE                  hUserIODLL;
   X_MODULEHANDLE                  hIntnIODLL;
   X_PVOID                         pfnUserIODLL;
   X_PVOID                         pfnIntnIODLL;
   struct X_OBJ_AUTHS_LIST       * pObjAuthsList;
   X_SHORT                         sAuthCount;
   X_SHORT                         sCurrentAuth;
   X_PVOID                         pStaticMIOC;
   X_PVOID                         pChainMIOList;
   X_SHORT                         sNumVisibleScrollItems;
   X_YES_NO                        chUseIconMenuAbar;
   struct X_PROCESS_ALIAS        * pProcessAlias;
   X_CHAR                          chNonDisplayChar;
   X_BOOL                          fDefaultMsgDisplayed;
   X_BOOL                          fHSKCEnabled;
   X_USHORT                        uscHSKCHeader;
   struct X_HSKC_HEADER          * pHSKCHeader;
   X_VCHAR                         vchOldTempDir[X_OLD_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchOldRRNODir[X_OLD_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchOldXRoot[X_OLD_ROOT_NAME_LEN + 1];
   X_USHORT                        uscHSKCEligible;
   struct X_HSKC_ELIGIBLE        * pHSKCEligible;
   struct X_SET_HEAD               LX_F04_ISAM_Set;
   struct X_SET_HEAD               LX_F05_ISAM_Set;
   struct X_SET_HEAD               LX_F06_ISAM_Set;
   struct X_SET_HEAD               LX_F07_ISAM_Set;
   struct X_SET_HEAD               LX_F64_ISAM_Set;
   struct X_SET_HEAD               LX_F65_ISAM_Set;
   struct X_SET_HEAD               LX_F67_ISAM_Set;
   struct X_SET_HEAD               LX_F44_ISAM_Set;
   struct X_LANSA_PC             * pLansaPC;
   struct X_EDIT_PROCESS         * pEditProc;
   struct X_EDIT_FILE            * pEditFile;
   X_VCHAR                         vchQNAM[X_OBJECT_NAME_LEN + 1];
   X_USHORT                        usQCHK;
   X_USHORT                        usQHLD;
   X_BOOL                          fJobqLoadAttempted;
   X_USHORT                        uscJobq;
   struct X_JOB_QUEUE            * pJobq;
   X_USHORT                        usJobqPriority;
   X_BOOL                          fUnderJobqEmulate;
   X_VCHAR                         vchLastSbmTime[6 + 1];
   X_USHORT                        usNextSbmSuffix;
   X_VCHAR                         vchOldCDLLName[X_OLD_FILE_PATH_LENGTH + 1];
   X_CHAR                          chODBCAOption; /* No Longer Used - x_ctddbms.c determines if multiple connections are required */
   X_CHAR                          chCMTHOption;
   X_BOOL                          fCRMUSupported;
   struct X_CTD_DATABASE_TYPE    * pDBMSTypes;
   struct X_CTD_DBMS_INFO        * pUserDBMSInfo;
   struct X_CTD_DBMS_INFO        * pInternalDBMSInfo;
   X_CHAR                          chPBFPColour;
   X_CHAR                          chPBCMColour;
   X_PVOID                         apExpand[X_EXPAND_POINTERS];
   PFNEXPANDFR                     apfExpandFreeRes[X_EXPAND_POINTERS];
   X_CHAR                          chOAMRqsType;
   X_BOOL                          fHeavyTransaction;
   X_PVOID                         pTrackStmt; /* Now defined in x_dbm1.c */
   X_ULONG                         ulHeavySyncCount;
   X_ULONG                         ulHeavySyncTrigger;
   X_VCHAR                         vchOldPPTHDir[X_OLD_FILE_PATH_LENGTH + 1];
   X_VCHAR                         __to_be_recycled_vchDEPRECATEDPassWd[8 + 1];
   X_LONG                          lIMEforKeyboardJ;
   X_LONG                          lIMEforKeyboardJOff;
   X_CHAR                          chIMEforKeyboardJAct;
   X_LONG                          lIMEforKeyboardE;
   X_LONG                          lIMEforKeyboardEOff;
   X_CHAR                          chIMEforKeyboardEAct;
   X_LONG                          lIMEforKeyboardO;
   X_LONG                          lIMEforKeyboardOOff;
   X_CHAR                          chIMEforKeyboardOAct;
   X_LONG                          lIMEforKeyboardW;
   X_LONG                          lIMEforKeyboardWOff;
   X_CHAR                          chIMEforKeyboardWAct;
   X_LONG                          lIMEforKeyboardG;
   X_LONG                          lIMEforKeyboardGOff;
   X_CHAR                          chIMEforKeyboardGAct;
   X_LONG                          lIMEforAlphanumeric;
   X_LONG                          lIMEforAlphanumericOff;
   X_CHAR                          chIMEforAlphanumericAct;
   X_LONG                          lIMEforNumeric;
   X_LONG                          lIMEforNumericOff;
   X_CHAR                          chIMEforNumericAct;
   X_VCHAR                         vchIMEDLLName[X_FILE_NAME_LEN + 1];
   X_LONG                          lEStyleforKeyboardJ;
   X_LONG                          lEStyleforKeyboardE;
   X_LONG                          lEStyleforKeyboardO;
   X_LONG                          lEStyleforKeyboardW;
   X_LONG                          lEStyleforKeyboardG;
   X_LONG                          lEStyleforAlphanumeric;
   X_LONG                          lEStyleforNumeric;
   X_BOOL                          fExchangeAllFields;
   X_BOOL                          fSystemShutDownMode;
   X_CHAR                          chGenAtSign;
   X_CHAR                          chXVecAssignOption;
   X_BOOL                          fInternalTracing;
   X_ULONG                         ulMaxTraceEntries;
   X_ULONG                         ulCurTraceEntries;
   X_LONG                          lTracingIndent;
   X_ULONG                         ulTracingLevel;
   X_VCHAR                         vchTracingCategories[(20 * TRACE_CATEGORY_LENGTH) + 1];
   FILE                          * pTracingFile;
   X_ULONG                         ulcX_FunRtr;
   struct X_FUNRTR               * pX_FunRtr;
   X_SHORT                         sPCOSVersion;
   X_VCHAR                         vchOldEXPO[X_OLD_FILE_PATH_LENGTH + 1];
   FILE                          * pfEXPO;
   X_VCHAR                         vchOldEXPM[X_OLD_FILE_PATH_LENGTH + 1];
   FILE                          * pfEXPM;
   X_VCHAR                         vchSpare4[X_OLD_FILE_PATH_LENGTH + 1];
   X_BOOL                          fLIMPORT;
   X_VCHAR                         __to_be_recycled_vchDEPRECATEDDBUser[8 + 1];
   X_BOOL                          fREFRESH;
   X_BOOL                          fPLUGIN;
   struct X_REMOVE_FILE          * pRemFileStartofChain;
   struct X_REMOVE_FILE          * pRemFileEndofChain;
   X_VCHAR                         vchConnectPartition[X_PARTITION_NAME_LEN + 1];
   X_BOOL                          fX_DBM_PrepareParams;
   X_CHAR                          chODBCIOption;
   X_BOOL                          fODBCUncommittedRead;
   struct X_IDS_COMPONENT        * pX_IdsComponent;
   X_CHAR                          chExecutionState;
   X_VCHAR                         vchFORM[X_CLASS_NAME_LEN + 1];
   PFNSTDVOIDFUNCTION              pfnX_LServerServices;
   X_MODULEHANDLE                  hX_LSVDLL;
   PFNSTDVOIDFUNCTION              pfnX_SServerServices;
   X_MODULEHANDLE                  hX_SSVDLL;
   PFNUIMVOIDFUNCTION              pfnX_UIM_Manager;
   X_MODULEHANDLE                  hX_UIMDLL;
   X_VCHAR                         vchOldTracingFileName[X_OLD_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchDat8[X_LONG_DATE_LEN + 1];
   X_VCHAR                         vchCentury[2 + 1];
   X_VCHAR                         vchInitialExecutable[X_OBJECT_NAME_LEN + 1];
   struct X_XENV_VARIABLE *        pXENVChain;
   X_BOOL                          fFirstUserProcess;
   X_BOOL                          fINITFunctionExecuted;
   X_BOOL                          fTERMFunctionExecuted;
   X_VCHAR                         vchINITFunction[X_FUNCTION_NAME_LEN + 1];
   X_VCHAR                         vchTERMFunction[X_FUNCTION_NAME_LEN + 1];
   X_CHAR                          chActiveIOMUpdateConnection;
   X_CHAR                          chCommitRollbackChannel;
   X_BOOL                          fWindowsPrinting;
   X_CHAR                          chWPPD_Parameter;
   X_CHAR                          chWPFD_Parameter;
   X_VCHAR                         chWPDF_Parameter[32 + 1];
   X_LONG                          lWPDS_Parameter;
   X_BOOL                          fWPFO_Parameter;
   X_SHORT                         scRemoteOAMMaxKeyFlds;
   X_BOOL                          fWPAS_Parameter;
   X_ULONG                         ulRDMLLevelUIMCallCount;
   X_SHORT                         sLock;
   PX_RUN_ARGUMENT                 pX_RUNArgChain;
   X_BOOL                          fBuildCheck;
   X_BOOL                          fForceAllXQFileUsage;
   struct X_SET_HEAD               LX_F14_ISAM_Set;
   struct X_SET_HEAD               LX_F15_ISAM_Set;
   struct X_SET_HEAD               LX_F54_ISAM_Set;
   X_ULONG                         ulTotalISAM;
   X_BOOL                          fpISAMNeedsSorting;
   PX_ISAM_FILE                    pISAM;
   X_ULONG                         ulFXQMParameter;
   X_VCHAR                         vchFileCheckRetCode[X_DBM_RETURN_CODE_LEN + 1];
   X_ULONG                         ulOSLevelLanguage;
   X_CHAR                          chLANSAPCHashSign;
   X_CHAR                          chLANSAPCAtSign;
   X_CHAR                          chLANSAPCDollarSign;
   X_BOOL                          fBypassQuestions;
   struct X_SET_HEAD               DC_F03_ISAM_Set;
   struct X_SET_HEAD               DC_F12_ISAM_Set;
   struct X_SET_HEAD               DC_F14_ISAM_Set;
   struct X_SET_HEAD               DC_F15_ISAM_Set;
   struct X_SET_HEAD               DC_F18_ISAM_Set;
   struct X_SET_HEAD               DC_F27_ISAM_Set;
   X_BOOL                          fSystemDefinitionisReal;
   X_BOOL                          fPartitionDefinitionisReal;
   X_BOOL                          fLanguageDefinitionisReal;
   X_ULONG                         ulMessageBoxTextLen;
   X_PVOID                         pwcsMessageBoxText;
   X_SHORT                         sEventLogIcon;
   X_VCHAR                         vchAppl[X_OBJECT_NAME_LEN + 1];
                 /* Above should have been X_APPL_NAME_LEN, but too late now */
   X_VCHAR                         vchInst[X_INSTALL_OPTION_LEN + 1];

   X_VCHAR                         vchCURRENTUser[X_ISERIES_USER_NAME_LEN + 1];
   X_VCHAR                         vchCURRENTGroupUser[X_ISERIES_USER_NAME_LEN + 1];
   X_VCHAR                         __to_be_recycled_vchCURRENTPassWd[10 + 1];
   X_VCHAR                         __to_be_recycled_vchCURRENTDBUser[10 + 1];

   X_VCHAR                         vchOldLANSAPC_LX_DataDirectory[X_OLD_FILE_PATH_LENGTH + 1];

   X_VCHAR                         vchInvokeBIF[X_BIF_NAME_LEN + 1];
   X_PVCHAR                        apvchInvokeBIFArgs[X_BIF_MAXIMUM_ARGS];
   X_LONG                          lNumberofBIFRetstoUse;
   X_VCHAR                         vchOldBIFReturnFile[X_OLD_FILE_PATH_LENGTH + 1];

   X_VCHAR                         vchLANSAPCMessageFile[X_OBJECT_NAME_LEN+1];
   X_CHAR                          chNoFatal;
   X_LONG                          lLastErrorCode;
   X_CHAR                          chDELI;                        // Unused
   X_ULONG                         ulLoadModuleProcessOrder;
   X_VCHAR                         vchPKGD[X_NEW_FILE_PATH_LENGTH + 1];
   X_CHAR                          chRunInstall;

   struct X_FUN                  * pActiveCompRtnX_Fun;
   X_CHAR                          chUPSI;
   X_CHAR                          chDASO;
   X_VCHAR                         vchIPKG[X_PKG_NAME_LEN + 1];
   X_CHAR                          chUPGD;
   X_CHAR                          chUPCF;
   X_CHAR                          chUPDF;
   X_CHAR                          chConnectASXXStatus;
   struct X_CONNECT_AUTO         * pConnectASXX;
   X_CHAR                          chASKC;

   X_DOUBLE                        dNextSubmitJobOrder;
   X_CHAR                          chUPTP;

   X_VCHAR                         vchDPTHParameter[X_NEW_FILE_PATH_LENGTH + 1];

   X_PULONG                        pulNormalIOCounter;
   X_PULONG                        pulSServerIOCounter;
   X_VCHAR                         vchEXPR[X_NEW_FILE_PATH_LENGTH + 1];
   X_BOOL                          fX_UIMDebuggerActive;
   X_CHAR                          chRunTimeHelpStyle;
   X_VCHAR                         vchRunTimeHelpFile[X_NEW_FILE_PATH_LENGTH + 1];

   X_CHAR                          chMULT;
   X_CHAR                          chUPMP;
   X_CHAR                          chUPOP;
   X_CHAR                          chUPFP;

   X_CHAR                          chImportSecurity;

   X_BOOL                          fHaveLoadedTextFileList;
   struct X_TEXT_FILE_EXT_LIST     *pTextFiles;

   X_VCHAR                         vchTempDir[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchRRNODir[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchXRoot[X_NEW_ROOT_NAME_LEN + 1];
   X_BOOL                          fUseSharedRoot;
   X_VCHAR                         vchSharedRoot[X_NEW_ROOT_NAME_LEN + 1];
   X_VCHAR                         vchCDLLName[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchPPTHDir[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchEXPO[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchEXPM[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchTracingFileName[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchLANSAPC_LX_DataDirectory[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchBIFReturnFile[X_NEW_FILE_PATH_LENGTH + 1];

#if (defined X_OPERATING_SYSTEM_WIN)
   X_WINDOWHANDLE                  hwndLPC;
#endif

   X_CHAR                          chFieldExit;
   X_BOOL                          fQuietModeExecution;
   X_BOOL                          fCrossPartitionMode;

   X_CHAR                          chKeepEventLogOpen;
   X_BOOL                          fCheckMemory;
   X_BOOL                          fReportMemory;

   X_BOOL                          fInheritPSxxParams;
   X_LONG                          lRRNNumbertoAllocate;
   X_BOOL                          fRRNUseWindowsBuffering;
   X_VCHAR                         vchPSEAParameter[X_NEW_FILE_PATH_LENGTH + 1];

   struct X_WEB_INFO               *pWebInfo;
   struct X_EXTENDED_EXCHL         *pExtendedExchange;

   struct X_ZIP_DLL_TRACKING       *pZipInfo;
   X_BOOL                          fStripTrailingDBCSBlanks;
   X_CHAR                          chSysexportLX_MSG;
   struct X_SET_HEAD               LX_MSG_ISAM_Set;
   struct X_SET_HEAD               LX_F03_ISAM_Set;
   struct X_SET_HEAD               LX_F08_ISAM_Set;
   struct X_SET_HEAD               LX_F09_ISAM_Set;
   struct X_SET_HEAD               LX_F10_ISAM_Set;
   struct X_SET_HEAD               LX_F11_ISAM_Set;
   struct X_SET_HEAD               LX_F26_ISAM_Set;
   struct X_SET_HEAD               LX_F27_ISAM_Set;
   struct X_SET_HEAD               LX_F40_ISAM_Set;
   struct X_SET_HEAD               LX_F61_ISAM_Set;
   struct X_SET_HEAD               LX_F62_ISAM_Set;
   struct X_SET_HEAD               LX_F66_ISAM_Set;
   PX_XQL_CACHE                    pXQLCache;

   struct X_CONNECT_DATABASE     * pConnectDatabase;

   X_BOOL                          fODBCTimestamp;
   X_VCHAR                         vchDevLangCode[X_LANGUAGE_CODE_LEN + 1];
   X_CHAR                          chLangLocale;
   X_SHORT                         sStayAliveTimeout;
   X_VCHAR                         vchFinalDir[X_NEW_FILE_PATH_LENGTH + 1];
   X_BOOL                          fKeepExport;
   X_CHAR                          chValidateHeap;
   X_VCHAR                         vchLANSARoot[X_NEW_FILE_PATH_LENGTH + 1];
   X_PYES_NO                       pchIOMUsedGrpFlds;
   X_BOOL                          fUseNativeIO;

   X_BOOL                          fWebRoutineExecution;
   X_VCHAR                         vchWebService[X_WEB_SERVICE_NAME_LEN + 1];
   X_BOOL                          fWebLicenseError;
   X_CHAR                          chLeadingZeroSuppressionLevel;
   X_YES_NO                        chWebServerXslt;
   X_YES_NO                        chWebRoutineRequestXsl;
   X_VCHAR                         vchWebRoutine[X_WEB_ROUTINE_NAME_LEN + 1];
   X_VCHAR                         vchWebMarkupLanguage[X_WEB_ML_NAME_LEN + 1];
   X_PCVOID                        pWebVariables;

   X_BOOL                          fDEPRECATED_WDTM_UseWDH; /* Flag needed to be changed to multi-value, not boolean */

   X_MODULEHANDLE                  hW3XSVPGM_DLL;
   PX_EXCHL2                       pExch2;                      /* To keep a pointer to a LL2 Exchange List */

   X_MODULEHANDLE                  hW3XSVPGX_DLL;
   X_PFN                           pfn_W4000_CreateWamExecContext;
   X_PFN                           pfn_W4000_DestroyWamExecContext;
   X_PFN                           pfn_W4000_WamExecContextServices;
   X_PFN                           pfn_W4000_WebRoutineRuntime;
   X_PVOID                         pWamExecContext;

   X_VCHAR                         vchWebAppModule[X_WEB_APPMOD_NAME_LEN + 1];
   PX_CLIENT_PARAMS                pClientParams;

   X_BOOL                          fForceShowFatalErrors; /* Show errors even if QUET=Y */
   X_VCHAR                         vchUserParam[X_MAX_ALPHA_FIELD_LEN + 1];

   X_BOOL                          fShowLog; /* Show the event log - categorically doesn't show it. */
   X_BOOL                          fShowLogIgnoreMessages;

   X_DEFS_INVOCATION_FRAMES        pInvocationFrames;
   X_PVOID                         pInvocationFactorBlock;
   X_LONG                          lTotalInvocationFrames;
   X_LONG                          lNextInvocationFrame;
   X_VCHAR                         vchDevLang[X_LANGUAGE_CODE_LEN + 1];
   X_CHAR                          chLimportLanguages;
   X_PVCHAR                        apvchImportLanguages[X_ENVIRON_MAXIMUM_LANGUAGES];

   X_BOOL                          fRDMLXPartition;

   X_PFN                           __to_be_recycled_1__;
   X_PFN                           __to_be_recycled_2__;
   X_PFN                           __to_be_recycled_3__;

   X_VCHAR                         vchLOBRoot[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR                         vchDeprecatedWebSessionID[33];

   X_MODULEHANDLE                  hX_DBG_DLL;
   X_PFN                           pfn_X_DBG_ProcessUIMRequest;

   X_BOOL                          fApplyLANSASecurityChecks; /* For use by import/export */
   X_VCHAR                         vchSupGroupProfiles[X_SUP_GROUP_PROFILES_LEN + 1];

   struct X_IDS_RPG              * pX_Ids_RPG;
   struct X_EDS_RPG              * pX_Eds_RPG;
   struct X_PRIDS_RPG            * pX_PrIds_RPG;
   X_PFCHAR                        pSaveLibl;
   X_PFCHAR                        pSaveLDA;
   X_CHAR                          chDateSource;
   X_BOOL                          fHostMonitorJob;

   X_VCHAR                         vchWebServerType[X_WEB_SERVER_TYPE_LEN + 1];

   X_BOOL                          fWamStaticPage;
   X_BOOL                          fWamStaticPageLXML;
   X_VCHAR                         vchWamStaticPageFileName[X_NEW_FILE_PATH_LENGTH + 1];

   X_INT                           iLockTimeout;  /* Changed from X_BOOL. Equals X_INT on all platforms (int) */
   X_VCHAR                         vchPackageInstallMem[21]; /* The memory is used by the Package Installer */
   X_BOOL                          fDebuggingError;
   X_INT                           iMaxSavedStatements; /* Changed from X_BOOL. Equals X_INT on all platforms (int) */
   X_BOOL                          fObscureCommandLine;
   X_BOOL                          fEnableHandleMessageForWeb;
   X_COMP_RETURN_CODE              lWamExecuteReturnCode;
   X_CHAR                          chChangeWorkingDirectory;
   X_CHAR                          chRenderMode;

   X_VCHAR                         vchSubmitCommandProgramName[X_NEW_FILE_PATH_LENGTH + 1];

   X_CHAR                          vchDebuggingHost[X_DEBUGGING_HOST_NAME_LEN + 1];
   X_VCHAR                         vchDBId[X_DSN_NAME_LEN + 1];
   X_VCHAR                         vchDBIdInternal[X_DSN_NAME_LEN + 1];
   X_VCHAR                         __to_be_recycled_5__[126];
   X_VCHAR                         vchCURRENTDBUser[X_CURRENT_USER_NAME_LEN + 1];

   X_BOOL                          fVLIseriesInstalled;

   X_VCHAR                         vchCURRENTUserExactCase[X_ISERIES_USER_NAME_LEN + 1];

   X_PFN                           pfn_W4000_GetWamExecContextDetails;
   X_PFN                           pfn_W4000_WamExecContextError;

   X_VCHAR                         vchCipherName[X_CIPHER_NAME_LEN + 1];

   X_VCHAR                         __to_be_recycled_7__[16];

   X_VCHAR                         __to_be_recycled_vchAuditUser[X_ISERIES_USER_NAME_LEN + 1];

   X_PVOID                         rfpW06V1;
   X_PVOID                         rfpW07V1;
   X_PVOID                         rfpW07V2;
   X_PVOID                         rfpW07V3;

   X_BOOL                          fIssueBIFDiagnosticMsgsDEPRECATED; /* No longer used */
   X_FCHAR                         fchF60MSGDft[X_ISERIES_MESSAGE_FILE_LEN * 10];

   X_USHORT                        iPerfLogLevel;

   X_CHAR                          chWDTM_UseNonInteractiveDesktop;

   X_VCHAR                         vchPrinterName[ X_PRINTER_NAME_LEN + 1 ];
   X_VCHAR                         vchPrinterSetupFile[ X_NEW_FILE_PATH_LENGTH + 1 ];

   X_SHORT                         chDBConnectionLevel;
   X_BOOL                          fTryTrustedConnection;
   X_DB_CONNECT_TYPE               bDBConnectionFlags;
   X_VCHAR                         vchInvocStackName[X_OBJECT_NAME_LEN + 1];

   X_VCHAR                         vchSSNCurrent[X_CONNECT_SSN_LENGTH + 1];

   X_CHAR                          chEnableShortCharLevel;

   X_MODULEHANDLE                  __to_be_recycled_6__;

   X_CHAR                          chDevToolIdentifier;

   struct X_CTD_DBMS_INFO        * pLastErrorDBMSInfo;

   X_VCHAR                         vchCURRENTPassWd[X_CURRENT_PASSWORD_LEN + 1];

   X_VCHAR                         vchLogDir[X_NEW_FILE_PATH_LENGTH + 1];

   X_BOOL                          fQENC;

   X_BOOL                          fEnableSavepoints;

   X_BOOL                          fEnableMARS;

   X_ULONG                         ulODBCCursorType;

   X_ULONG                         ulODBCCursorConcurrency;

   X_SHORT                         sMaxInvoc;
   struct X_INVOC                * pInvoc;

   X_VCHAR                         vchServerName[X_SYSTEM_NAME_LEN + 1];
   X_BOOL                          fDefinitionIsReal;

   X_PCCHAR                        pszWamLobTempDir;
   X_BOOL                          fWamLobTempDirUsed;

   struct X_COMPOSER_CONNECT     * pComposerConnect;
   struct _X_OVERRIDE_LIBRARY    * pOverrideLibrary;
   X_VCHAR                         vchAuditUser[X_MAX_USER_NAME_LEN + 1];
   X_BOOL                          fLongUserAudit;

   struct X_COMP_DISPATCH_INTERFACE * pComponentDispatchInterface;

   X_CHAR                          chRender;

   X_MODULEHANDLE                  hX_WSI_DLL;
   X_PFN                           pfn_WSI_CreateContext;
   X_PFN                           pfn_WSI_DestroyContext;
   X_PCHAR                         pszWsiContextArgs;
   X_ULONG                         nWsiContextArgsLen;
   X_PVOID                         pWsiContext;
   X_BOOL                          fSetupDatabase;
   PFNSTDVOIDFUNCTION              pfnX_AServerServices;
   X_MODULEHANDLE                  hX_ASVDLL;
   X_PVOID                         pvBotpContext;

   X_ULONG                         ulDevFlag;

   X_PVOID                         pLoadedDBMSDLLRoot;

   X_BOOL                          fWebConnect;
   X_BOOL                          fCloudLicensed;

   /*
    *  PLEASE CONSIDER REUSING THE SPACE OF ALL THOSE
    *  __to_be_recycled_??__ FIELDS BEFORE ADDING NEW ONES.
    */

   /*
    *  SERIOUS NOTE:
    *  DO NOT DO ANY CONDITIONAL COMPILE FOR THE X_IDS
    *  STRUCTURE UNLESS YOU HAVE SUPER EXTRAORDINARY
    *  STRONG REASON. IT SHOULD BE OF THE SAME SIZE FOR
    *  ALL PLATFORMS. (WELL, WIN32 IS A LITTLE BIT
    *  DIFFERENT BECAUSE OF THE ABOVE "MISTAKE" OR THE
    *  ONLY EXAMPLE OF SUPER EXTRAORDINARY STRONG REASON)
    *  SO ALSO MAKE SURE NEW MEMBER VARIABLES ARE OF THE
    *  SAME SIZE FOR ALL PLATFORMS. (OR INCLUDE THEM IN
    *  X_IDSOS)
    *
    *  NOTE FOR THE SERIOUS NOTE ABOVE:
    *  PLEASE KEEP THIS COMMENT BLOCK AT THE END OF
    *  THIS X_IDS DEFINITION.
    */
};

#define X_DEVFLAG_CURRENT_LEVEL_ONLY                     0x00000001
#define X_DEVFLAG_IMPORT_CHANGE_FILE_LIB_TO_PARTDTALIB   0x00000002
#define X_DEVFLAG_IMPORT_IGNORE_FILE_LIB_OVERRIDE        0x00000004
#define X_DEVFLAG_IMPORT_APPLY_PACKAGE_SETTING           0x00000008
#define X_DEVFLAG_IMPORT_ALLOW_NAME_CHANGES              0x00000010
#define X_DEVFLAG_IMPORT_VERIFY                          0x00000020
#define X_DEVFLAG_IMPORT_ALLOW_TYPE_CHANGES              0x00000040

/* ================================================================= */
/*  X_ABar : LANSA/X Action Bar Definition Table                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ABOpt           Action Bar Option Code                            */
/* ABDesc          Pointer to Action Bar Description                 */
/* PDTotal         Total Pull Down Options                           */
/* PDEnabled       Array of Pull Down Enablement Y/N flags           */
/* PDAuth          Array of authorisation flags for current user     */
/* PDOpt           Array of Pull Down Option Pointers                */
/* PDDesc          Array of Pull Down Option Descriptions            */
/* PDAID           Array of Pull AID Bytes                           */
/* PDLink          Array of link numbers to X_PROFUNC structures     */
/* PDToolBarIconId Array of Tool Bar Icon Identifiers                */

struct X_ABAR
  {
     X_VCHAR       vchABOpt[X_ABOPT_PDOPT_LEN+1];
     X_PVCHAR      pvchABDesc;
     X_SHORT       sPDTotal;
     X_YES_NO      chPDEnabled[X_ALLOW_DROP_DOWNS];
     X_YES_NO      chPDAuth[X_ALLOW_DROP_DOWNS];
     X_PVCHAR      pvchPDOpt[X_ALLOW_DROP_DOWNS];
     X_PVCHAR      pvchPDDesc[X_ALLOW_DROP_DOWNS];
     X_PVCHAR      pvchPDAID[X_ALLOW_DROP_DOWNS];
     X_SHORT       sPDLink[X_ALLOW_DROP_DOWNS];
     X_ULONG       aulPDToolBarIconId[X_ALLOW_DROP_DOWNS];
  } ;

/* ================================================================= */
/*  X_FKey : LANSA/X Function Key Definition and Enablement          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Enable          Enabled on next panel                             */
/*                 'Y' = Enable as a function key and button         */
/*                 'F' = Enable as a function key only               */
/*                 other = do not enable or show this key            */
/* Name            Name of Function Key to show in a button          */
/* AID             AID byte(2) to return if key/button is used       */

#define X_UIM_FKEY_TOTAL 28

#define X_UIM_CANCEL_IDX          0
#define X_UIM_OKAY_IDX            1
#define X_UIM_HELP_IDX            2
#define X_UIM_PROMPT_IDX          3
#define X_UIM_REFRESH_IDX         4
#define X_UIM_MESSAGES_IDX        5
#define X_UIM_BCK_IDX             6
#define X_UIM_COMMAND_IDX         7
#define X_UIM_KEYS_IDX            8
#define X_UIM_EXIT_HI_IDX         9
#define X_UIM_EXIT_LO_IDX        10
#define X_UIM_HOME_IDX           11
#define X_UIM_FWD_IDX            12
#define X_UIM_CONTENT_IDX        13
#define X_UIM_EX_HELP_IDX        14
#define X_UIM_INDEX_IDX          15
#define X_UIM_KEYS_HELP_IDX      16
#define X_UIM_LEFT_IDX           17
#define X_UIM_RETRIEVE_IDX       18
#define X_UIM_RIGHT_IDX          19
#define X_UIM_SWITCH_BCK_IDX     20
#define X_UIM_SWITCH_FWD_IDX     21
#define X_UIM_ACTIONS_IDX        22
#define X_UIM_CREATE_IDX         23
#define X_UIM_CHANGE_IDX         24
#define X_UIM_DELETE_IDX         25
#define X_UIM_ROLLUP_IDX         26
#define X_UIM_ROLLDOWN_IDX       27


#define X_UIM_CANCEL_ENABLE         (X_FKey[X_UIM_CANCEL_IDX      ].chEnable)
#define X_UIM_OKAY_ENABLE           (X_FKey[X_UIM_OKAY_IDX        ].chEnable)
#define X_UIM_HELP_ENABLE           (X_FKey[X_UIM_HELP_IDX        ].chEnable)
#define X_UIM_PROMPT_ENABLE         (X_FKey[X_UIM_PROMPT_IDX      ].chEnable)
#define X_UIM_REFRESH_ENABLE        (X_FKey[X_UIM_REFRESH_IDX     ].chEnable)
#define X_UIM_MESSAGES_ENABLE       (X_FKey[X_UIM_MESSAGES_IDX    ].chEnable)
#define X_UIM_BCK_ENABLE            (X_FKey[X_UIM_BCK_IDX         ].chEnable)
#define X_UIM_COMMAND_ENABLE        (X_FKey[X_UIM_COMMAND_IDX     ].chEnable)
#define X_UIM_KEYS_ENABLE           (X_FKey[X_UIM_KEYS_IDX        ].chEnable)
#define X_UIM_EXIT_HI_ENABLE        (X_FKey[X_UIM_EXIT_HI_IDX     ].chEnable)
#define X_UIM_EXIT_LO_ENABLE        (X_FKey[X_UIM_EXIT_LO_IDX     ].chEnable)
#define X_UIM_HOME_ENABLE           (X_FKey[X_UIM_HOME_IDX        ].chEnable)
#define X_UIM_FWD_ENABLE            (X_FKey[X_UIM_FWD_IDX         ].chEnable)
#define X_UIM_CONTENT_ENABLE        (X_FKey[X_UIM_CONTENT_IDX     ].chEnable)
#define X_UIM_EX_HELP_ENABLE        (X_FKey[X_UIM_EX_HELP_IDX     ].chEnable)
#define X_UIM_INDEX_ENABLE          (X_FKey[X_UIM_INDEX_IDX       ].chEnable)
#define X_UIM_KEYS_HELP_ENABLE      (X_FKey[X_UIM_KEYS_HELP_IDX   ].chEnable)
#define X_UIM_LEFT_ENABLE           (X_FKey[X_UIM_LEFT_IDX        ].chEnable)
#define X_UIM_RETRIEVE_ENABLE       (X_FKey[X_UIM_RETRIEVE_IDX    ].chEnable)
#define X_UIM_RIGHT_ENABLE          (X_FKey[X_UIM_RIGHT_IDX       ].chEnable)
#define X_UIM_SWITCH_BCK_ENABLE     (X_FKey[X_UIM_SWITCH_BCK_IDX  ].chEnable)
#define X_UIM_SWITCH_FWD_ENABLE     (X_FKey[X_UIM_SWITCH_FWD_IDX  ].chEnable)
#define X_UIM_ACTIONS_ENABLE        (X_FKey[X_UIM_ACTIONS_IDX     ].chEnable)
#define X_UIM_CREATE_ENABLE         (X_FKey[X_UIM_CREATE_IDX      ].chEnable)
#define X_UIM_CHANGE_ENABLE         (X_FKey[X_UIM_CHANGE_IDX      ].chEnable)
#define X_UIM_DELETE_ENABLE         (X_FKey[X_UIM_DELETE_IDX      ].chEnable)
#define X_UIM_ROLLUP_ENABLE         (X_FKey[X_UIM_ROLLUP_IDX      ].chEnable)
#define X_UIM_ROLLDOWN_ENABLE       (X_FKey[X_UIM_ROLLDOWN_IDX    ].chEnable)

#define X_UIM_CANCEL_NAME            (X_FKey[X_UIM_CANCEL_IDX     ].vchName)
#define X_UIM_OKAY_NAME              (X_FKey[X_UIM_OKAY_IDX       ].vchName)
#define X_UIM_HELP_NAME              (X_FKey[X_UIM_HELP_IDX       ].vchName)
#define X_UIM_PROMPT_NAME            (X_FKey[X_UIM_PROMPT_IDX     ].vchName)
#define X_UIM_REFRESH_NAME           (X_FKey[X_UIM_REFRESH_IDX    ].vchName)
#define X_UIM_MESSAGES_NAME          (X_FKey[X_UIM_MESSAGES_IDX   ].vchName)
#define X_UIM_BCK_NAME               (X_FKey[X_UIM_BCK_IDX        ].vchName)
#define X_UIM_COMMAND_NAME           (X_FKey[X_UIM_COMMAND_IDX    ].vchName)
#define X_UIM_KEYS_NAME              (X_FKey[X_UIM_KEYS_IDX       ].vchName)
#define X_UIM_EXIT_HI_NAME           (X_FKey[X_UIM_EXIT_HI_IDX    ].vchName)
#define X_UIM_EXIT_LO_NAME           (X_FKey[X_UIM_EXIT_LO_IDX    ].vchName)
#define X_UIM_HOME_NAME              (X_FKey[X_UIM_HOME_IDX       ].vchName)
#define X_UIM_FWD_NAME               (X_FKey[X_UIM_FWD_IDX        ].vchName)
#define X_UIM_CONTENT_NAME           (X_FKey[X_UIM_CONTENT_IDX    ].vchName)
#define X_UIM_EX_HELP_NAME           (X_FKey[X_UIM_EX_HELP_IDX    ].vchName)
#define X_UIM_INDEX_NAME             (X_FKey[X_UIM_INDEX_IDX      ].vchName)
#define X_UIM_KEYS_HELP_NAME         (X_FKey[X_UIM_KEYS_HELP_IDX  ].vchName)
#define X_UIM_LEFT_NAME              (X_FKey[X_UIM_LEFT_IDX       ].vchName)
#define X_UIM_RETRIEVE_NAME          (X_FKey[X_UIM_RETRIEVE_IDX   ].vchName)
#define X_UIM_RIGHT_NAME             (X_FKey[X_UIM_RIGHT_IDX      ].vchName)
#define X_UIM_SWITCH_BCK_NAME        (X_FKey[X_UIM_SWITCH_BCK_IDX ].vchName)
#define X_UIM_SWITCH_FWD_NAME        (X_FKey[X_UIM_SWITCH_FWD_IDX ].vchName)
#define X_UIM_ACTIONS_NAME           (X_FKey[X_UIM_ACTIONS_IDX    ].vchName)
#define X_UIM_CREATE_NAME            (X_FKey[X_UIM_CREATE_IDX     ].vchName)
#define X_UIM_CHANGE_NAME            (X_FKey[X_UIM_CHANGE_IDX     ].vchName)
#define X_UIM_DELETE_NAME            (X_FKey[X_UIM_DELETE_IDX     ].vchName)
#define X_UIM_ROLLUP_NAME            (X_FKey[X_UIM_ROLLUP_IDX     ].vchName)
#define X_UIM_ROLLDOWN_NAME          (X_FKey[X_UIM_ROLLDOWN_IDX   ].vchName)

#define X_UIM_CANCEL_AID            (X_FKey[X_UIM_CANCEL_IDX      ].vchAID)
#define X_UIM_OKAY_AID              (X_FKey[X_UIM_OKAY_IDX        ].vchAID)
#define X_UIM_HELP_AID              (X_FKey[X_UIM_HELP_IDX        ].vchAID)
#define X_UIM_PROMPT_AID            (X_FKey[X_UIM_PROMPT_IDX      ].vchAID)
#define X_UIM_REFRESH_AID           (X_FKey[X_UIM_REFRESH_IDX     ].vchAID)
#define X_UIM_MESSAGES_AID          (X_FKey[X_UIM_MESSAGES_IDX    ].vchAID)
#define X_UIM_BCK_AID               (X_FKey[X_UIM_BCK_IDX         ].vchAID)
#define X_UIM_COMMAND_AID           (X_FKey[X_UIM_COMMAND_IDX     ].vchAID)
#define X_UIM_KEYS_AID              (X_FKey[X_UIM_KEYS_IDX        ].vchAID)
#define X_UIM_EXIT_HI_AID           (X_FKey[X_UIM_EXIT_HI_IDX     ].vchAID)
#define X_UIM_EXIT_LO_AID           (X_FKey[X_UIM_EXIT_LO_IDX     ].vchAID)
#define X_UIM_HOME_AID              (X_FKey[X_UIM_HOME_IDX        ].vchAID)
#define X_UIM_FWD_AID               (X_FKey[X_UIM_FWD_IDX         ].vchAID)
#define X_UIM_CONTENT_AID           (X_FKey[X_UIM_CONTENT_IDX     ].vchAID)
#define X_UIM_EX_HELP_AID           (X_FKey[X_UIM_EX_HELP_IDX     ].vchAID)
#define X_UIM_INDEX_AID             (X_FKey[X_UIM_INDEX_IDX       ].vchAID)
#define X_UIM_KEYS_HELP_AID         (X_FKey[X_UIM_KEYS_HELP_IDX   ].vchAID)
#define X_UIM_LEFT_AID              (X_FKey[X_UIM_LEFT_IDX        ].vchAID)
#define X_UIM_RETRIEVE_AID          (X_FKey[X_UIM_RETRIEVE_IDX    ].vchAID)
#define X_UIM_RIGHT_AID             (X_FKey[X_UIM_RIGHT_IDX       ].vchAID)
#define X_UIM_SWITCH_BCK_AID        (X_FKey[X_UIM_SWITCH_BCK_IDX  ].vchAID)
#define X_UIM_SWITCH_FWD_AID        (X_FKey[X_UIM_SWITCH_FWD_IDX  ].vchAID)
#define X_UIM_ACTIONS_AID           (X_FKey[X_UIM_ACTIONS_IDX     ].vchAID)
#define X_UIM_CREATE_AID            (X_FKey[X_UIM_CREATE_IDX      ].vchAID)
#define X_UIM_CHANGE_AID            (X_FKey[X_UIM_CHANGE_IDX      ].vchAID)
#define X_UIM_DELETE_AID            (X_FKey[X_UIM_DELETE_IDX      ].vchAID)
#define X_UIM_ROLLUP_AID            (X_FKey[X_UIM_ROLLUP_IDX      ].vchAID)
#define X_UIM_ROLLDOWN_AID          (X_FKey[X_UIM_ROLLDOWN_IDX    ].vchAID)

struct X_FKEY
  {
     X_TYPE_FLAG chEnable;
     X_VCHAR     vchName[X_FKEY_NAME_LEN + 1];
     X_VCHAR     vchAID[X_FKEY_AID_LEN + 1];
  };

/* ================================================================= */
/*  X_PROFUNC : LANSA/X Process executable function definitions      */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* Type              Type of function Entry                          */
/* Authorised        Authority to use this function                  */
/* Process           Process Name                                    */
/* Function          Function Name                                   */
/* Desc              Description                                     */
/* Next              Default Next Function                           */
/* NextFunc          Allowable Next Functions List                   */
/* CommandLen        Command Length                                  */
/* Command           Command String                                  */
/* OnMenu            Show on Menu                                    */
/* Expand1           For future Expansion                            */
/* Expand2           For future Expansion                            */
/* Expand3           For future Expansion                            */

#define X_PROCESS_TYPE_MNU 'M'
#define X_PROCESS_TYPE_FUN 'F'
#define X_PROCESS_TYPE_CMD 'C'
#define X_PROCESS_TYPE_HLP 'H'
#define X_PROCESS_TYPE_EXT 'E'

#define X_PROCESS_EXIT    "EXIT"
#define X_PROCESS_MENU    "MENU"
#define X_PROCESS_RETURN  "RETRN"
#define X_PROCESS_ERROR   "ERROR"
#define X_PROCESS_EOJ     "EOJ"
#define X_PROCESS_SELECT  "SELECT"
#define X_PROCESS_HELP    "HELP"
#define X_PROCESS_ALL     "*ALL"
#define X_PROCESS_ANY     "*ANY"

struct X_PROFUNC
{
   X_TYPE_FLAG  chType;
   X_YES_NO     chAuthorised;
   X_VCHAR      vchProcess[X_OBJECT_NAME_LEN+1];
   X_VCHAR      vchFunction[X_FUNCTION_NAME_LEN+1];
   X_PVCHAR     pvchDesc;
   X_VCHAR      vchNext[X_FUNCTION_NAME_LEN+1];
   X_PVCHAR     pvchNextFunc[X_ALLOW_NEXT_FUNCTIONS];
   X_SHORT      sCommandLen;
   X_PVCHAR     pvchCommand;
   X_YES_NO     chOnMenu;
   X_PVCHAR     pvchExpand1;
   X_SHORT      sExpand2;
   X_PVOID      pExpand3;
} ;


/* ================================================================= */
/*  X_Pro : LANSA/X Currently Executing Process Definition           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Version number of this structure                  */
/* Name            Name of this process                              */
/* Desc            Description of this Process                       */
/* SingleMode      Process in running in single function only mode   */
/* CurrFunc        Current Function Name                             */
/* NextFunc        Next Function Number                              */
/* nX_ProFunc      Number of current function in X_PROFUNC array     */
/* KillProc        Kill executing process flag                       */
/* CurrProc        Current Process Name (executing from menu/bar)    */
/* NextProc        Next Process Name (executing from menu/bar)       */
/* LastFunc        Last Function Number                              */
/* scX_ABar        Count of X_ABAR structures                        */
/* pX_ABar         Ptr to an array of X_ABAR structures              */
/* pX_FKey         Ptr to an array of X_FKEY structures              */
/* scX_ProFunc     Count of X_PROFUNC structures                     */
/* pX_ProFunc      Ptr to an array of X_PROFUNC structures           */
/* HeavyorLight    Heavy or Light usage process                      */

#if defined(X_OPERATING_SYSTEM_WIN)
/* hmodProcess     Module handle of this process                     */
#endif


#define X_PRO_V1           -1
#define X_PRO_V2           -2
#define X_PRO_V3           -3
#define X_PRO_V4           -4

#define X_PRO_V1_OR_LATER   (pX_Pro->sVersion <= X_PRO_V1)
#define X_PRO_V2_OR_LATER   (pX_Pro->sVersion <= X_PRO_V2)
#define X_PRO_V3_OR_LATER   (pX_Pro->sVersion <= X_PRO_V3)
#define X_PRO_V4_OR_LATER   (pX_Pro->sVersion <= X_PRO_V4)

#define X_PROCESS_USAGE_HEAVY 'H'
#define X_PROCESS_USAGE_LIGHT 'L'

struct X_PRO
  {
      X_SHORT                  sVersion;
      X_VCHAR                  vchName[X_OBJECT_NAME_LEN+1];
      X_VCHAR                  vchDesc[X_DESCRIPTION_LEN+1];
      X_YES_NO                 chSingleMode;
      X_VCHAR                  vchCurrFunc[X_FUNCTION_NAME_LEN+1];
      X_VCHAR                  vchNextFunc[X_FUNCTION_NAME_LEN+1];
      X_SHORT                  snX_ProFunc;
      X_YES_NO                 chKillProc;
      X_VCHAR                  vchCurrProc[X_OBJECT_NAME_LEN+1];
      X_VCHAR                  vchNextProc[X_OBJECT_NAME_LEN+1];
      X_VCHAR                  vchLastFunc[X_FUNCTION_NAME_LEN+1];
      X_SHORT                  scX_ABar;
      struct X_ABAR           *pX_ABar;
      struct X_FKEY           *pX_FKey;
      X_SHORT                  scX_ProFunc;
      struct X_PROFUNC        *pX_ProFunc;
#if defined(X_OPERATING_SYSTEM_WIN)
      X_MODULEHANDLE           hmodProcess;
#endif
      X_CHAR                   chHeavyorLight; /* V3 onwards only */
  } ;

/* ================================================================= */
/*  X_Menu : LANSA/X Menu Definition Table                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* LinkNo         Link to X_PROCFUN array entry                      */
/* Desc           Pointer to Description                             */
/* chPreselect    Pre-select this menu entry                         */

struct X_MENU
  {
     X_SHORT       sLinkNo;
     X_PVCHAR      pvchDesc;
     X_YES_NO      chPreselect;
  };

/* ================================================================= */
/*  X_FKeyLang : LANSA/X Function keys for a language                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* aFKey           Array of Function keys                            */

struct X_FKEY_LANG
  {
      struct X_FKEY aFKey[X_FKEY_TOTAL];
  } ;

typedef struct X_FKEY_LANG *X_PFKEY_LANG;

/* ================================================================= */
/*  X_DEBUG_ARRAY : Tracking of array details for array elements     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Array Name                                        */
/* MaxIndex        Maximum allowable Index Value (lowest is 1)       */

#define X_ARRAY_NAME_MAX_LEN  3

struct X_DEBUG_ARRAY
  {
      X_FCHAR      fchName[X_ARRAY_NAME_MAX_LEN];
      X_SHORT      sMaxIndex;
  };


/* ================================================================= */
/*  X_Fld : LANSA/X Field Definition "Vector"                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Field Name                                        */
/*                                                                   */
/* chFieldInfo     Additional field info (bit mask)                  */
/*                 For LL1 fields, should be one of the following:   */
/*                 0x00, ASCII space, EBCDIC space                   */
/* Bit 1, i.e. 1000000X Future use.                                  */
/* Bit 2, i.e. 100000X0 SQL Nulls are supported for this field.      */
/* Bit 3, i.e. 10000X00 Type-specific flag 1                         */
/*                      Integer: Unsigned (SUNS attribute)           */
/*                      Datetime: Store in UTC (SUTC attribute)      */
/* Bit 4, i.e. 1000X000 Type-specific flag 2                         */
/*                      Datetime: Display in UTC (DUTC attribute)    */
/* Bit 5, i.e. 100X0000 Future use.                                  */
/* Bit 6, i.e. 10X00000 Future use. To avoid confusion with ASCII    */
/*                      space, always check this bit with bit 8 ON.  */
/* Bit 7, i.e. 1X000000 Future use. To avoid confusion with EBCDIC   */
/*                      space, always check this bit with bit 8 ON.  */
/* Bit 8, i.e. X0000000 LL2 or higher field. Must always be ON for   */
/*                      any other bit to be considered ON. This will */
/*                      avoid space/blank/0x00 being interpreted     */
/*                      incorrectly, as neither ASCII space nor      */
/*                      EBCDIC space have this bit ON.               */
/*                                                                   */
/* Type            Type                                              */
/*                 Refer to X_TYPE_XXXX macros for possible values   */
/*                                                                   */
/* SubType         Subtype                                           */
/*                 Refer to X_SUBTYPE_XXXX macros for possible values*/
/*                                                                   */
/* DBCS            Vector field may contain DBCS/multibyte data      */
/*                 'N' -- no DBCS allowed,                           */
/*                 'Y' Keyboards Shift O, E, or J                    */
/*                 'G' -- DBCS Only (Shift G)                        */
/*                 'U' -- Unicode (Shift U)                          */
/*                                                                   */
/* Len             Length (from LANSA dictionary, NOT bytes)         */
/*                 Note: calculated for Float & Integer              */
/*                                                                   */
/* ByteLen         Calculated Byte Length                            */
/*                 Note: Data dictionary length for Float and Integer*/
/*                                                                   */
/* Dec             Decimal Positions (0 for all types except packed, */
/*                 signed, and double)                               */
/*                                                                   */
/* pField          If LL2 field, points to extended field info.      */
/*                 (cast as PX_FLDEXT)                               */
/*                 This should always be initialized to pX_NULL if   */
/*                 it hasn't been allocated yet!                     */
/*                 If LL1 field, you should use X_FLD not X_FLD2     */
/*                 (cast as X_PDICTIONARY_FIELD)                     */
/*                                                                   */
/*                 What about SubType 'R' ???                        */
/*                                                                   */
/* IndexVOV        Index Value or Vector Number                      */
/*                 For SubType 'R' ???                               */
/*                 For SubType 'I' this is the current value of the  */
/*                 field available in high speed 'short' format. All */
/*                 operations that change a field of SubType 'I'     */
/*                 must update this value.                           */
/*                 For all other SubTypes this value is 0.           */
/*                                                                   */
/* ValError        Vector field has a validation error               */
/*                                                                   */

/* LL1 field info : cast X_FLD * as X_FLD2 * to use these macros !!! */
/* System Variables cannot be LL2 at the moment and the 20th char of */
/* pre-10.2 fields is in chFieldInfo, so they are eliminated before  */
/* checking for LL2 support. Also a sysvar without a v as first char */
/* may be an LL2 field in the future, though not now.                */
/*                                                                   */
/* All X_FLD variables can be tested directly, except for pField,    */
/* which is invalid for an evaluation variable.                      */

#ifdef X_OPERATING_TARGET_CSHARP

#define X_VECTOR_FIELD_IS_LL2(X_Fld2, f)         (((X_VECTOR_FIELD_IS_SYSVAR(X_Fld2, f)         &&   X_Fld2[f].fchName2[0] != 'v') || \
                                                   !X_VECTOR_FIELD_IS_SYSVAR(X_Fld2, f))        &&  ((((int)X_Fld2[f].chFieldInfo) & LL2FIELD)!=0) )
#define X_VECTOR_FIELD_IS_NULLABLE(X_Fld2, f)      (X_VECTOR_FIELD_IS_LL2(X_Fld2, f)            && ((((int)X_Fld2[f].chFieldInfo) & LL2NULLABLE)  == LL2NULLABLE) )
#define X_VECTOR_FIELD_IS_UNSIGNED(X_Fld2, f)      (X_VECTOR_STORED_AS_INTEGER(X_Fld2, f)       && ((((int)X_Fld2[f].chFieldInfo) & LL2UNSINT)    == LL2UNSINT))
#define X_VECTOR_FIELD_IS_STORED_UTC(X_Fld2, f)    (X_VECTOR_STORED_AS_DATETIME_ONLY(X_Fld2, f) && ((((int)X_Fld2[f].chFieldInfo) & LL2SUTCDT)    == LL2SUTCDT))
#define X_VECTOR_FIELD_IS_DISPLAYED_UTC(X_Fld2, f) (X_VECTOR_STORED_AS_DATETIME_ONLY(X_Fld2, f) && ((((int)X_Fld2[f].chFieldInfo) & LL2DUTCDT)    == LL2DUTCDT))

#define X_VECTOR_FIELD_IS_FIXED_CHAR(X_Fld2, f)       ( ( X_VECTOR_STORED_AS_CHAR( X_Fld2, f ) )       && ( ( ((int)X_Fld2[f].chFieldInfo) & LL2FIXEDCHAR ) == LL2FIXEDCHAR ) )
#define X_VECTOR_FIELD_IS_FIXED_SHORT_CHAR(X_Fld2, f) ( ( X_VECTOR_STORED_AS_SHORT_CHAR( X_Fld2, f ) ) && ( ( ((int)X_Fld2[f].chFieldInfo) & LL2FIXEDCHAR ) == LL2FIXEDCHAR ) )

#else

#define X_VECTOR_FIELD_IS_LL2(X_Fld2, f)         (((X_VECTOR_FIELD_IS_SYSVAR(X_Fld2, f)         &&   X_Fld2[f].fchName2[0] != 'v') || \
                                                   !X_VECTOR_FIELD_IS_SYSVAR(X_Fld2, f))        &&  (X_Fld2[f].chFieldInfo & LL2FIELD) )
#define X_VECTOR_FIELD_IS_NULLABLE(X_Fld2, f)      (X_VECTOR_FIELD_IS_LL2(X_Fld2, f)            && ((X_Fld2[f].chFieldInfo & LL2NULLABLE)  == LL2NULLABLE) )
#define X_VECTOR_FIELD_IS_UNSIGNED(X_Fld2, f)      (X_VECTOR_STORED_AS_INTEGER(X_Fld2, f)       && ((X_Fld2[f].chFieldInfo & LL2UNSINT)    == LL2UNSINT))
#define X_VECTOR_FIELD_IS_STORED_UTC(X_Fld2, f)    (X_VECTOR_STORED_AS_DATETIME_ONLY(X_Fld2, f) && ((X_Fld2[f].chFieldInfo & LL2SUTCDT)    == LL2SUTCDT))
#define X_VECTOR_FIELD_IS_DISPLAYED_UTC(X_Fld2, f) (X_VECTOR_STORED_AS_DATETIME_ONLY(X_Fld2, f) && ((X_Fld2[f].chFieldInfo & LL2DUTCDT)    == LL2DUTCDT))

#define X_VECTOR_FIELD_IS_FIXED_CHAR(X_Fld2, f)       ( ( X_VECTOR_STORED_AS_CHAR( X_Fld2, f ) )       && ( ( X_Fld2[f].chFieldInfo & LL2FIXEDCHAR ) == LL2FIXEDCHAR ) )
#define X_VECTOR_FIELD_IS_FIXED_SHORT_CHAR(X_Fld2, f) ( ( X_VECTOR_STORED_AS_SHORT_CHAR( X_Fld2, f ) ) && ( ( X_Fld2[f].chFieldInfo & LL2FIXEDCHAR ) == LL2FIXEDCHAR ) )

#endif // X_OPERATING_TARGET_CSHARP

/* Test field states. Require vector to be resolved before using. */
/* If you don't resolve first, and its an evaluation variable,    */
/* a fatal error will occur!                                      */

#define X_VECTOR_FIELD_IS_SQL_NULL(_X_Fld, _f, _pField)                                                           \
   ( !X_VECTOR_FIELD_IS_EVALUATION( _X_Fld, _f)                                                                   \
      ? ( X_VECTOR_FIELD_IS_LL2(_X_Fld, _f) && ( ((X_FLD_INFO*)( _pField ))->bFieldState & FsIsSqlNull ) )        \
      : X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, "X_VECTOR_FIELD_IS_SQL_NULL", X_TEXT(976) ) )

#define X_VECTOR_FIELD_HAS_OVERFLOWED(_X_Fld, _f, _pField)                                                        \
  ( !X_VECTOR_FIELD_IS_EVALUATION( _X_Fld, _f)                                                                    \
     ? ( X_VECTOR_FIELD_IS_LL2(_X_Fld, _f) && ( ((X_FLD_INFO*)( _pField ))->bFieldState & FsHasOverflowed ) )     \
     : X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, "X_VECTOR_FIELD_HAS_OVERFLOWED", X_TEXT(976) ) )

#define X_VECTOR_FIELD_HAS_UNDERFLOWED(_X_Fld, _f, _pField)                                                       \
   ( !X_VECTOR_FIELD_IS_EVALUATION( _X_Fld, _f)                                                                   \
      ? ( X_VECTOR_FIELD_IS_LL2(_X_Fld, _f) && ( ((X_FLD_INFO*)( _pField ))->bFieldState & FsHasUnderflowed ) )   \
      : X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, "X_VECTOR_FIELD_HAS_UNDERFLOWED", X_TEXT(976) ) )

#define X_VECTOR_FIELD_HAS_CHANGED(_X_Fld, _f, _pField)                                                           \
   ( !X_VECTOR_FIELD_IS_EVALUATION( _X_Fld, _f)                                                                   \
      ? ( X_VECTOR_FIELD_IS_LL2(_X_Fld, _f) && ( ((X_FLD_INFO*)( _pField ))->bFieldState & FsHasChanged ) )       \
      : X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, "X_VECTOR_FIELD_HAS_CHANGED", X_TEXT(976) ) )


/* Test field states with just the resolved X_FLD_xxxx structure pointer provided */

#define X_FLD_INFO_IS_SQL_NULL(_X_FldInfo)         (((PX_FLD_INFO)_X_FldInfo)->bFieldState & FsIsSqlNull)

#define X_FLD_INFO_HAS_OVERFLOWED(_X_FldInfo)      (((PX_FLD_INFO)_X_FldInfo)->bFieldState & FsHasOverflowed)

#define X_FLD_INFO_HAS_UNDERFLOWED(_X_FldInfo)     (((PX_FLD_INFO)_X_FldInfo)->bFieldState & FsHasUnderflowed)

#define X_FLD_INFO_HAS_CHANGED(_X_FldInfo)         (((PX_FLD_INFO)_X_FldInfo)->bFieldState & FsHasChanged)

#define X_FLD_CHAR_HAS_WIDECHAR(_X_FldChar)        (((PX_FLD_CHAR)_X_FldChar)->bFieldState & FsHasWideCharData)

/* Set field states with just the resolved X_FLD_xxxx structure pointer provided */

#define X_SET_FLD_INFO_IS_SQL_NULL(_X_FldInfo)     ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState | FsIsSqlNull)

#define X_SET_FLD_INFO_HAS_OVERFLOWED(_X_FldInfo)  ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState | FsHasOverflowed)

#define X_SET_FLD_INFO_HAS_UNDERFLOWED(_X_FldInfo) ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState | FsHasUnderflowed)

#define X_SET_FLD_INFO_HAS_CHANGED(_X_FldInfo)     ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState | FsHasChanged)

#define X_SET_FLD_CHAR_HAS_WIDECHAR(_X_FldChar)    ((PX_FLD_CHAR)_X_FldChar)->bFieldState = (XFIELDSTATE)(((PX_FLD_CHAR)_X_FldChar)->bFieldState | FsHasWideCharData)

/* Clear field states with just the resolved X_FLD_xxxx structure pointer provided */

#define X_CLEAR_FLD_INFO_IS_SQL_NULL(_X_FldInfo)     ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState & ~FsIsSqlNull)

#define X_CLEAR_FLD_INFO_HAS_OVERFLOWED(_X_FldInfo)  ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState & ~FsHasOverflowed)

#define X_CLEAR_FLD_INFO_HAS_UNDERFLOWED(_X_FldInfo) ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState & ~FsHasUnderflowed)

#define X_CLEAR_FLD_INFO_HAS_CHANGED(_X_FldInfo)     ((PX_FLD_INFO)_X_FldInfo)->bFieldState = (XFIELDSTATE)(((PX_FLD_INFO)_X_FldInfo)->bFieldState & ~FsHasChanged)

#define X_CLEAR_FLD_CHAR_HAS_WIDECHAR(_X_FldChar)    ((PX_FLD_CHAR)_X_FldChar)->bFieldState = (XFIELDSTATE)(((PX_FLD_CHAR)_X_FldChar)->bFieldState & ~FsHasWideCharData)

/* Major Types of fields */

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* N.B. Do not use the following X_VECTOR_FIELD_IS... macros directly*/
/* Use the X_VECTOR_STORED_AS_... macros instead                     */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

#define X_VECTOR_FIELD_IS_ALPHA(X_Fld, f)          (X_Fld[f].chType == X_TYPE_ALPHA)
#define X_VECTOR_FIELD_IS_PACKED(X_Fld, f)         (X_Fld[f].chType == X_TYPE_PACKED)
#define X_VECTOR_FIELD_IS_SIGNED(X_Fld, f)         (X_Fld[f].chType == X_TYPE_SIGNED)
#define X_VECTOR_FIELD_IS_LONG(X_Fld, f)           (X_Fld[f].chType == X_TYPE_LONG)
#define X_VECTOR_FIELD_IS_DOUBLE(X_Fld, f)         (X_Fld[f].chType == X_TYPE_DOUBLE)
#define X_VECTOR_FIELD_IS_COMPONENT(X_Fld, f)      (X_Fld[f].chType == X_TYPE_COMPONENT)
#define X_VECTOR_FIELD_IS_CHAR(X_Fld, f)           (X_Fld[f].chType == X_TYPE_CHAR)
#define X_VECTOR_FIELD_IS_NCHAR(X_Fld, f)          ((X_Fld[f].chType == X_TYPE_CHAR) && (((PX_FLD_INFO)(X_Fld[f].pField))->i8Version < X_FLDDATA_V1))
#define X_VECTOR_FIELD_IS_WIDECHAR(X_Fld, f)       (X_VECTOR_FIELD_IS_NCHAR(X_Fld, f ) && X_FLD_CHAR_HAS_WIDECHAR( X_Fld[f].pField  ) )
#define X_VECTOR_FIELD_IS_SHORT_CHAR(X_Fld, f)     (X_Fld[f].chType == X_TYPE_SHORT_CHAR)
#define X_VECTOR_FIELD_IS_BINARY(X_Fld, f)         (X_Fld[f].chType == X_TYPE_BINARY)
#define X_VECTOR_FIELD_IS_BOOLEAN(X_Fld, f)        (X_Fld[f].chType == X_TYPE_BOOLEAN)
#define X_VECTOR_FIELD_IS_DATE(X_Fld, f)           (X_Fld[f].chType == X_TYPE_DATE)
#define X_VECTOR_FIELD_IS_TIME(X_Fld, f)           (X_Fld[f].chType == X_TYPE_TIME)
#define X_VECTOR_FIELD_IS_DATETIME(X_Fld, f)       (X_Fld[f].chType == X_TYPE_DATETIME)
#define X_VECTOR_FIELD_IS_INTEGER(X_Fld, f)        (X_Fld[f].chType == X_TYPE_INTEGER)
#define X_VECTOR_FIELD_IS_FLOAT(X_Fld, f)          (X_Fld[f].chType == X_TYPE_FLOAT)
#define X_VECTOR_FIELD_IS_CLOB(X_Fld, f)           (X_Fld[f].chType == X_TYPE_CLOB)
#define X_VECTOR_FIELD_IS_BLOB(X_Fld, f)           (X_Fld[f].chType == X_TYPE_BLOB)
#define X_VECTOR_FIELD_IS_NCLOB(X_Fld, f)          (X_Fld[f].chType == X_TYPE_NCLOB)
#define X_VECTOR_FIELD_IS_DECIMAL(X_Fld, f)        (X_Fld[f].chType == X_TYPE_DECIMAL)
/* TN: This macro check if the vector is an evaluated instance of a EVALUATION vector */
/* it is based on two condition 1. Vector is a Component  2.  X_Fld[f].chValError == '?' */
/* if we know that the vector is a component use X_COMPONENT_FIELD_IS_EVALUATED */
#define X_VECTOR_FIELD_IS_EVALUATED(X_Fld, f)      ((X_Fld[f].chType == X_TYPE_COMPONENT) \
                                                      && ( X_Fld[f].chValError == '?'))
/* Valid sub types for fields                                        */
/* Ok to use the following macros, provided chType is tested first   */
/* See X_VECTOR_STORED_AS_... macros for common combinations         */

#define X_VECTOR_FIELD_IS_SIMPLE(X_Fld, f)         (X_Fld[f].chSubType == X_SUBTYPE_SIMPLE_FIELD)
#define X_VECTOR_FIELD_IS_INDEX(X_Fld, f)          (X_Fld[f].chSubType == X_SUBTYPE_INDEX)
#define X_VECTOR_FIELD_IS_LITERAL(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_LITERAL)
#define X_VECTOR_FIELD_IS_ARRAY(X_Fld, f)          (X_Fld[f].chSubType == X_SUBTYPE_ARRAY)
#define X_VECTOR_FIELD_IS_SYSVAR(X_Fld, f)         (X_Fld[f].chSubType == X_SUBTYPE_SYSTEM_VARIABLE)
#define X_VECTOR_FIELD_IS_UPARM(X_Fld, f)          (X_Fld[f].chSubType == X_SUBTYPE_USER_PARAMETER)
#define X_VECTOR_FIELD_IS_EVALUATION(X_Fld, f)     (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_EVALUATION)

#define X_COMPONENT_FIELD_IS_ALPHA(X_Fld, f)       (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_ALPHA)
#define X_COMPONENT_FIELD_IS_PACKED(X_Fld, f)      (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_PACKED)
#define X_COMPONENT_FIELD_IS_SIGNED(X_Fld, f)      (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_SIGNED)
#define X_COMPONENT_FIELD_IS_LONG(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_LONG)
#define X_COMPONENT_FIELD_IS_DOUBLE(X_Fld, f)      (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_DOUBLE)
#define X_COMPONENT_FIELD_IS_CHAR(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_CHAR)
#define X_COMPONENT_FIELD_IS_NCHAR(X_Fld, f)       (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_CHAR && (((PX_FLD_INFO)(X_Fld[f].pField))->i8Version < X_FLDDATA_V1) ) 
#define X_COMPONENT_FIELD_IS_WIDECHAR(X_Fld, f)    (X_COMPONENT_FIELD_IS_NCHAR(X_Fld, f ) && X_FLD_CHAR_HAS_WIDECHAR( X_Fld[f].pField  ) )
#define X_COMPONENT_FIELD_IS_SHORT_CHAR(X_Fld, f)  (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_SHORT_CHAR)
#define X_COMPONENT_FIELD_IS_BINARY(X_Fld, f)      (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_BINARY)
#define X_COMPONENT_FIELD_IS_BOOLEAN(X_Fld, f)     (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_BOOLEAN)
#define X_COMPONENT_FIELD_IS_DATE(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_DATE)
#define X_COMPONENT_FIELD_IS_TIME(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_TIME)
#define X_COMPONENT_FIELD_IS_DATETIME(X_Fld, f)    (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_DATETIME)
#define X_COMPONENT_FIELD_IS_INTEGER(X_Fld, f)     (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_INTEGER)
#define X_COMPONENT_FIELD_IS_FLOAT(X_Fld, f)       (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_FLOAT)
#define X_COMPONENT_FIELD_IS_CLOB(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_CLOB)
#define X_COMPONENT_FIELD_IS_BLOB(X_Fld, f)        (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_BLOB)
#define X_COMPONENT_FIELD_IS_NCLOB(X_Fld, f)       (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_NCLOB)
#define X_COMPONENT_FIELD_IS_DECIMAL(X_Fld, f)     (X_Fld[f].chSubType == X_SUBTYPE_COMPONENT_DECIMAL)
#define X_COMPONENT_FIELD_IS_EVALUATED(X_Fld, f)   ( X_Fld[f].chValError == '?')

/* -------------------------------------------------------------- */
/* Valid way to test for groups of vector types                   */
/* The X_VECTOR_STORED_AS_... macros are the safest ones to use   */
/* They fully allow for evaluation variables.                     */
/* -------------------------------------------------------------- */

#ifdef X_OPERATING_TARGET_CSHARP

#define X_VECTOR_STORED_AS_INTEGER(_X,_V) (  (X_VECTOR_FIELD_IS_INTEGER(_X,_V)) || (X_COMPONENT_FIELD_IS_INTEGER(_X,_V)) ||\
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_INTEGER, END_OF_STRING )                                         \
                                             :  false ) )

#define X_VECTOR_STORED_AS_DATE(_X,_V)    (  (X_VECTOR_FIELD_IS_DATE(_X,_V)) || (X_COMPONENT_FIELD_IS_DATE(_X,_V)) ||      \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_DATE, END_OF_STRING )                                            \
                                             :  false ) )

#define X_VECTOR_STORED_AS_TIME(_X,_V)    (  (X_VECTOR_FIELD_IS_TIME(_X,_V)) || (X_COMPONENT_FIELD_IS_TIME(_X,_V)) ||      \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_TIME, END_OF_STRING )                                            \
                                             :  false ) )

#define X_VECTOR_STORED_AS_DATETIME_ONLY(_X,_V) ( (X_VECTOR_FIELD_IS_DATETIME(_X,_V)) || (X_COMPONENT_FIELD_IS_DATETIME(_X,_V)) || \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                         \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,         \
                                                   X_TYPE_DATETIME, END_OF_STRING )                                           \
                                             :  false ) )

#define X_VECTOR_STORED_AS_FLOAT(_X,_V) ( (X_VECTOR_FIELD_IS_FLOAT(_X,_V)) || (X_COMPONENT_FIELD_IS_FLOAT(_X,_V)) ||    \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_FLOAT, END_OF_STRING )                                           \
                                          :  false ) )

/* Only tests for Alpha! For other character types use X_VECTOR_STORED_AS_STRING or X_VECTOR_STORED_AS_CHARS */
#define X_VECTOR_STORED_AS_ALPHA(_X,_V) ( (X_VECTOR_FIELD_IS_ALPHA(_X,_V)) || (X_COMPONENT_FIELD_IS_ALPHA(_X,_V)) ||    \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_ALPHA, END_OF_STRING )                                           \
                                          :  false ) )

#define X_VECTOR_STORED_AS_PACKED(_X,_V) ((X_VECTOR_FIELD_IS_PACKED(_X,_V)) || (X_COMPONENT_FIELD_IS_PACKED(_X,_V)) ||  \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_PACKED, END_OF_STRING )                                          \
                                          :  false ) )

#define X_VECTOR_STORED_AS_SIGNED(_X,_V) ((X_VECTOR_FIELD_IS_SIGNED(_X,_V)) || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V)) ||  \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_SIGNED, END_OF_STRING )                                          \
                                          :  false ) )

/* Remember, CLOB and BLOB store filenames!  */
#define X_VECTOR_STORED_AS_LOB(_X,_V) (   (X_VECTOR_FIELD_IS_CLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_CLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_BLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_BLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_NCLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_NCLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                   \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,   \
                                                X_TYPE_BLOB, X_TYPE_CLOB, X_TYPE_NCLOB, END_OF_STRING )                            \
                                          :  false ) )

#define X_VECTOR_STORED_AS_NCLOB(_X,_V) ( (X_VECTOR_FIELD_IS_NCLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_NCLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                   \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,   \
                                                X_TYPE_NCLOB, END_OF_STRING )                            \
                                          :  false ) )

#define X_VECTOR_STORED_AS_CHAR(_X,_V) ( (X_VECTOR_FIELD_IS_CHAR(_X,_V)) || (X_COMPONENT_FIELD_IS_CHAR(_X,_V) ) ||      \
                                         (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                       \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_CHAR, END_OF_STRING )                                            \
                                          :  false ) )

#define X_VECTOR_STORED_AS_WIDECHAR(_X,_V) ( (X_VECTOR_FIELD_IS_WIDECHAR(_X,_V)) || (X_COMPONENT_FIELD_IS_WIDECHAR(_X,_V) ) ||      \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                               \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,     \
                                                   X_TYPE_NCHAR, END_OF_STRING )                                                    \
                                           :  false ) )

#define X_VECTOR_STORED_AS_SHORT_CHAR(_X,_V) ( (X_VECTOR_FIELD_IS_SHORT_CHAR(_X,_V)) || (X_COMPONENT_FIELD_IS_SHORT_CHAR(_X,_V) ) \
                                               || (X_VECTOR_FIELD_IS_EVALUATION( _X, _V)                                          \
                                                  ? X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,         \
                                                       X_TYPE_SHORT_CHAR, END_OF_STRING )                                         \
                                                  :  false ) )

/* If a flag is added to X_Fld2.chFieldInfo to show the SBIN attribute for LL2 Alpha, this should also added below */
#define X_VECTOR_STORED_AS_BINARY(_X,_V) ((X_VECTOR_FIELD_IS_BINARY(_X,_V)) || (X_COMPONENT_FIELD_IS_BINARY(_X,_V)) ||  \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_BINARY, END_OF_STRING )                                          \
                                          :  false ) )

#define X_VECTOR_STORED_AS_DECIMAL(_X,_V) (  (X_VECTOR_FIELD_IS_DECIMAL(_X,_V)) || (X_COMPONENT_FIELD_IS_DECIMAL(_X,_V)) ||\
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_DECIMAL, END_OF_STRING )                                         \
                                                :  false ) )


#define X_VECTOR_STORED_AS_X_FCHAR(_X,_V) (  (X_VECTOR_FIELD_IS_SIGNED(_X,_V))  || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V)) || \
                                             (X_VECTOR_FIELD_IS_PACKED(_X,_V))  || (X_COMPONENT_FIELD_IS_PACKED(_X,_V)) || \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_SIGNED, X_TYPE_PACKED, END_OF_STRING )                           \
                                             :  false ) )


#define X_VECTOR_STORED_AS_DATETIME(_X,_V) ( (X_VECTOR_FIELD_IS_DATE(_X,_V))     || (X_COMPONENT_FIELD_IS_DATE(_X,_V))    ||  \
                                             (X_VECTOR_FIELD_IS_TIME(_X,_V))     || (X_COMPONENT_FIELD_IS_TIME(_X,_V))    ||  \
                                             (X_VECTOR_FIELD_IS_DATETIME(_X,_V)) || (X_COMPONENT_FIELD_IS_DATETIME(_X,_V))||  \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                         \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,         \
                                                   X_TYPE_DATE, X_TYPE_TIME, X_TYPE_DATETIME, END_OF_STRING )                 \
                                             :  false ) )

#define X_VECTOR_STORED_AS_NATIVE(_X,_V) ((X_VECTOR_FIELD_IS_ALPHA(_X,_V))   || (X_COMPONENT_FIELD_IS_ALPHA(_X,_V))  || \
                                          (X_VECTOR_FIELD_IS_SIGNED(_X,_V))  || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V)) || \
                                          (X_VECTOR_FIELD_IS_PACKED(_X,_V))  || (X_COMPONENT_FIELD_IS_PACKED(_X,_V)) || \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_ALPHA, X_TYPE_SIGNED, X_TYPE_PACKED, END_OF_STRING )             \
                                          :  false ) )

/* Note X_VECTOR_STORED_AS_NUMERIC used to be !( X_VECTOR_STORED_AS_ALPHA(_X,_V)). */
/* It has now been changed to include all the numeric types by name.               */

#define X_VECTOR_STORED_AS_NUMERIC(_X,_V) ( (X_VECTOR_FIELD_IS_SIGNED(_X,_V))  || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V))  || \
                                            (X_VECTOR_FIELD_IS_PACKED(_X,_V))  || (X_COMPONENT_FIELD_IS_PACKED(_X,_V))  || \
                                            (X_VECTOR_FIELD_IS_LONG(_X,_V))    || (X_COMPONENT_FIELD_IS_LONG(_X,_V))    || \
                                            (X_VECTOR_FIELD_IS_DOUBLE(_X,_V))  || (X_COMPONENT_FIELD_IS_DOUBLE(_X,_V))  || \
                                            (X_VECTOR_FIELD_IS_INTEGER(_X,_V)) || (X_COMPONENT_FIELD_IS_INTEGER(_X,_V)) || \
                                            (X_VECTOR_FIELD_IS_BOOLEAN(_X,_V)) || (X_COMPONENT_FIELD_IS_BOOLEAN(_X,_V)) || \
                                            (X_VECTOR_FIELD_IS_FLOAT(_X,_V))   || (X_COMPONENT_FIELD_IS_FLOAT(_X,_V))   || \
                                            (X_VECTOR_FIELD_IS_DECIMAL(_X,_V)) || (X_COMPONENT_FIELD_IS_DECIMAL(_X,_V)) || \
                                            (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                       \
                                                X_VAR_DLL.X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_SIGNED, X_TYPE_PACKED, X_TYPE_LONG, X_TYPE_DOUBLE,               \
                                                   X_TYPE_INTEGER, X_TYPE_BOOLEAN, X_TYPE_FLOAT, X_TYPE_DECIMAL,           \
                                                   END_OF_STRING )                                                         \
                                              : false ) )

#else

#define X_VECTOR_STORED_AS_INTEGER(_X,_V) (  (X_VECTOR_FIELD_IS_INTEGER(_X,_V)) || (X_COMPONENT_FIELD_IS_INTEGER(_X,_V)) ||\
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_INTEGER, END_OF_STRING )                                         \
                                             :  FALSE ) )

#define X_VECTOR_STORED_AS_DATE(_X,_V)    (  (X_VECTOR_FIELD_IS_DATE(_X,_V)) || (X_COMPONENT_FIELD_IS_DATE(_X,_V)) ||      \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_DATE, END_OF_STRING )                                            \
                                             :  FALSE ) )

#define X_VECTOR_STORED_AS_TIME(_X,_V)    (  (X_VECTOR_FIELD_IS_TIME(_X,_V)) || (X_COMPONENT_FIELD_IS_TIME(_X,_V)) ||      \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_TIME, END_OF_STRING )                                            \
                                             :  FALSE ) )

#define X_VECTOR_STORED_AS_DATETIME_ONLY(_X,_V) ( (X_VECTOR_FIELD_IS_DATETIME(_X,_V)) || (X_COMPONENT_FIELD_IS_DATETIME(_X,_V)) || \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                         \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,         \
                                                   X_TYPE_DATETIME, END_OF_STRING )                                           \
                                             :  FALSE ) )

#define X_VECTOR_STORED_AS_FLOAT(_X,_V) ( (X_VECTOR_FIELD_IS_FLOAT(_X,_V)) || (X_COMPONENT_FIELD_IS_FLOAT(_X,_V)) ||    \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_FLOAT, END_OF_STRING )                                           \
                                          :  FALSE ) )

/* Only tests for Alpha! For other character types use X_VECTOR_STORED_AS_STRING or X_VECTOR_STORED_AS_CHARS */
#define X_VECTOR_STORED_AS_ALPHA(_X,_V) ( (X_VECTOR_FIELD_IS_ALPHA(_X,_V)) || (X_COMPONENT_FIELD_IS_ALPHA(_X,_V)) ||    \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_ALPHA, END_OF_STRING )                                           \
                                          :  FALSE ) )

#define X_VECTOR_STORED_AS_PACKED(_X,_V) ((X_VECTOR_FIELD_IS_PACKED(_X,_V)) || (X_COMPONENT_FIELD_IS_PACKED(_X,_V)) ||  \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_PACKED, END_OF_STRING )                                          \
                                          :  FALSE ) )

#define X_VECTOR_STORED_AS_SIGNED(_X,_V) ((X_VECTOR_FIELD_IS_SIGNED(_X,_V)) || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V)) ||  \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_SIGNED, END_OF_STRING )                                          \
                                          :  FALSE ) )

/* Remember, CLOB and BLOB store filenames!  */
#define X_VECTOR_STORED_AS_LOB(_X,_V) (   (X_VECTOR_FIELD_IS_CLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_CLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_BLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_BLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_NCLOB(_X,_V)) || (X_COMPONENT_FIELD_IS_NCLOB(_X,_V))   || \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                   \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,   \
                                                X_TYPE_BLOB, X_TYPE_CLOB, X_TYPE_NCLOB, END_OF_STRING )                            \
                                          :  FALSE ) )

/* NOTE: To exclude NCHAR Fields, use X_VECTOR_STORED_AS_NATIVE_CHAR instead */
#define X_VECTOR_STORED_AS_CHAR(_X,_V) ( (X_VECTOR_FIELD_IS_CHAR(_X,_V)) || (X_COMPONENT_FIELD_IS_CHAR(_X,_V) ) ||      \
                                         (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                       \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_CHAR, END_OF_STRING )                                            \
                                          :  FALSE ) )

#define X_VECTOR_STORED_AS_WIDECHAR(_X,_V) ( (X_VECTOR_FIELD_IS_WIDECHAR(_X,_V)) || (X_COMPONENT_FIELD_IS_WIDECHAR(_X,_V) ) ||    \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                             \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,             \
                                                   X_TYPE_NCHAR, END_OF_STRING )                                                  \
                                          :  FALSE ) )

#define X_VECTOR_STORED_AS_NATIVE_CHAR(_X,_V) ( X_VECTOR_STORED_AS_CHAR(_X,_V) && ( X_VECTOR_STORED_AS_WIDECHAR(_X,_V) == FALSE ) )

#define X_VECTOR_STORED_AS_SHORT_CHAR(_X,_V) ( (X_VECTOR_FIELD_IS_SHORT_CHAR(_X,_V)) || (X_COMPONENT_FIELD_IS_SHORT_CHAR(_X,_V) ) \
                                               || (X_VECTOR_FIELD_IS_EVALUATION( _X, _V)                                          \
                                                  ? X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,         \
                                                       X_TYPE_SHORT_CHAR, END_OF_STRING )                                         \
                                                  :  FALSE ) )

/* If a flag is added to X_Fld2.chFieldInfo to show the SBIN attribute for LL2 Alpha, this should also added below */
#define X_VECTOR_STORED_AS_BINARY(_X,_V) ((X_VECTOR_FIELD_IS_BINARY(_X,_V)) || (X_COMPONENT_FIELD_IS_BINARY(_X,_V)) ||  \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_BINARY, END_OF_STRING )                                          \
                                          :  FALSE ) )

#define X_VECTOR_STORED_AS_DECIMAL(_X,_V) (  (X_VECTOR_FIELD_IS_DECIMAL(_X,_V)) || (X_COMPONENT_FIELD_IS_DECIMAL(_X,_V)) ||\
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_DECIMAL, END_OF_STRING )                                         \
                                                :  FALSE ) )


#define X_VECTOR_STORED_AS_X_FCHAR(_X,_V) (  (X_VECTOR_FIELD_IS_SIGNED(_X,_V))  || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V)) || \
                                             (X_VECTOR_FIELD_IS_PACKED(_X,_V))  || (X_COMPONENT_FIELD_IS_PACKED(_X,_V)) || \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_SIGNED, X_TYPE_PACKED, END_OF_STRING )                           \
                                             :  FALSE ) )


#define X_VECTOR_STORED_AS_DATETIME(_X,_V) ( (X_VECTOR_FIELD_IS_DATE(_X,_V))     || (X_COMPONENT_FIELD_IS_DATE(_X,_V))    ||  \
                                             (X_VECTOR_FIELD_IS_TIME(_X,_V))     || (X_COMPONENT_FIELD_IS_TIME(_X,_V))    ||  \
                                             (X_VECTOR_FIELD_IS_DATETIME(_X,_V)) || (X_COMPONENT_FIELD_IS_DATETIME(_X,_V))||  \
                                             (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                         \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,         \
                                                   X_TYPE_DATE, X_TYPE_TIME, X_TYPE_DATETIME, END_OF_STRING )                 \
                                             :  FALSE ) )

#define X_VECTOR_STORED_AS_NATIVE(_X,_V) ((X_VECTOR_FIELD_IS_ALPHA(_X,_V))   || (X_COMPONENT_FIELD_IS_ALPHA(_X,_V))  || \
                                          (X_VECTOR_FIELD_IS_SIGNED(_X,_V))  || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V)) || \
                                          (X_VECTOR_FIELD_IS_PACKED(_X,_V))  || (X_COMPONENT_FIELD_IS_PACKED(_X,_V)) || \
                                          (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                      \
                                             X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                X_TYPE_ALPHA, X_TYPE_SIGNED, X_TYPE_PACKED, END_OF_STRING )             \
                                          :  FALSE ) )

/* Note X_VECTOR_STORED_AS_NUMERIC used to be !( X_VECTOR_STORED_AS_ALPHA(_X,_V)). */
/* It has now been changed to include all the numeric types by name.               */

#define X_VECTOR_STORED_AS_NUMERIC(_X,_V) ( (X_VECTOR_FIELD_IS_SIGNED(_X,_V))  || (X_COMPONENT_FIELD_IS_SIGNED(_X,_V))  || \
                                            (X_VECTOR_FIELD_IS_PACKED(_X,_V))  || (X_COMPONENT_FIELD_IS_PACKED(_X,_V))  || \
                                            (X_VECTOR_FIELD_IS_LONG(_X,_V))    || (X_COMPONENT_FIELD_IS_LONG(_X,_V))    || \
                                            (X_VECTOR_FIELD_IS_DOUBLE(_X,_V))  || (X_COMPONENT_FIELD_IS_DOUBLE(_X,_V))  || \
                                            (X_VECTOR_FIELD_IS_INTEGER(_X,_V)) || (X_COMPONENT_FIELD_IS_INTEGER(_X,_V)) || \
                                            (X_VECTOR_FIELD_IS_BOOLEAN(_X,_V)) || (X_COMPONENT_FIELD_IS_BOOLEAN(_X,_V)) || \
                                            (X_VECTOR_FIELD_IS_FLOAT(_X,_V))   || (X_COMPONENT_FIELD_IS_FLOAT(_X,_V))   || \
                                            (X_VECTOR_FIELD_IS_DECIMAL(_X,_V)) || (X_COMPONENT_FIELD_IS_DECIMAL(_X,_V)) || \
                                            (X_VECTOR_FIELD_IS_EVALUATION( _X, _V) ?                                       \
                                                X_VAR_IsEvaluationVariableOfFieldType(pX_Ids, pX_Pro, pX_Fun, _X, _V,      \
                                                   X_TYPE_SIGNED, X_TYPE_PACKED, X_TYPE_LONG, X_TYPE_DOUBLE,               \
                                                   X_TYPE_INTEGER, X_TYPE_BOOLEAN, X_TYPE_FLOAT, X_TYPE_DECIMAL,           \
                                                   END_OF_STRING )                                                         \
                                              : FALSE ) )

#endif // X_OPERATING_TARGET_CSHARP

/* Date/Time not included here, as they have special formatting */
#define X_VECTOR_STORED_AS_STRING(_X,_V) ( ( X_VECTOR_STORED_AS_SHORT_CHAR(_X,_V) ) || ( X_VECTOR_STORED_AS_CHAR(_X,_V) ) || ( X_VECTOR_STORED_AS_LOB(_X,_V) ) )

/* X_VECTOR_STORED_AS_BYTES: The data is stored in X_VARDAT.pvData */
#define X_VECTOR_STORED_AS_BYTES(_X,_V) ((X_VECTOR_STORED_AS_STRING(_X,_V)) || (X_VECTOR_STORED_AS_BINARY(_X,_V)) || \
                                         (X_VECTOR_STORED_AS_ALPHA(_X,_V)))

#define X_VECTOR_STORED_AS_X_VAR(_X,_V) ((X_VECTOR_STORED_AS_CHAR(_X,_V))   || \
                                         (X_VECTOR_STORED_AS_BINARY(_X,_V)) || \
                                         (X_VECTOR_STORED_AS_DECIMAL(_X,_V)) )

#define X_VECTOR_STORED_AS_ALPHAORLOB(_X,_V) ( (X_VECTOR_STORED_AS_ALPHA(_X,_V)) || (X_VECTOR_STORED_AS_LOB(_X,_V)) )

#define X_VECTOR_STORED_AS_BOOLEAN(_X,_V) ( (X_VECTOR_FIELD_IS_BOOLEAN(_X,_V)) || (X_COMPONENT_FIELD_IS_BOOLEAN(_X,_V)) )

#define X_VECTOR_USABLE_AS_GENERIC_KEY(_X,_V) ( ( X_VECTOR_STORED_AS_ALPHA(_X,_V) )       || \
                                                ( X_VECTOR_STORED_AS_CHAR(_X,_V) )        || \
                                                ( X_VECTOR_STORED_AS_SHORT_CHAR(_X,_V) )  || \
                                                ( X_VECTOR_STORED_AS_INTEGER(_X,_V) )     || \
                                                ( X_VECTOR_STORED_AS_PACKED(_X,_V) )      || \
                                                ( X_VECTOR_STORED_AS_SIGNED(_X,_V) ) )

/* Macro to resolve address of X_FLD element */
#define X_VECTOR_RESOLVE_FIELD_ADDRESS(A, B, C, D, E) \
   ( ( X_VECTOR_FIELD_IS_EVALUATION( (D), (E) ) ) \
  	   ? X_VAR_ResolveEvaluationVariable( A, B, C, D, E ) \
      : &( (D)[(E)] ) )


/* Standard manipulation macros */

/* Support old vectors that conatin Y or N for chDBCS. Y is presumed to be 'O' */
/* and 'N' is presumed to be SBCS - BLANK. All other values are presumed to be */
/* keyboard shift so its just used as it is.                                   */
/* keyboard shift is validated against JEOGU in order to just use the          */
/* DBCS keyboard shifts                                                        */
/* This might need to change when G and U are actually implemented as they may */
/* not be validated as DBCS strings.                                           */

/* If statements using X_VECTOR_GETKEYBOARDSHIFT && X_GETKEYBOARDSHIFT have been changed so the  */
/* check to see if the system supports DBCS is done before the keyboard shift test. The majority */
/* of systems will not have DBCS support and this check is very quick. So the macro will only be */
/* evaluated on a DBCS system. In the majority of uses of both X_VECTOR_GETKEYBOARDSHIFT and     */
/* especially X_GETKEYBOARDSHIFT, the field or vector will not be DBCS capable and hence we test */
/* for NO first.                                                                                 */
#define X_VECTOR_GETKEYBOARDSHIFT( _X, _V ) \
   ( (X_CHAR)(_X[_V].chDBCS == NO ? BLANK \
                                   : _X[_V].chDBCS == YES ? 'O' \
                                                         : ( strchr( "JEOGU", _X[_V].chDBCS) ? _X[_V].chDBCS \
                                                                                             : BLANK ) ) )

#define X_GETKEYBOARDSHIFT( _KSH ) \
   ( (X_CHAR)(_KSH == NO ? BLANK \
                         : _KSH == YES ? 'O' \
                                       : ( strchr( "JEOGU", _KSH) ? _KSH \
                                                                  : BLANK ) ) )

#define X_VECTOR_GET_KEYBOARDSHIFT_PADDING( _X, _V ) X_VECTOR_GETKEYBOARDSHIFT( _X, _V )
   
#define X_GET_KEYBOARDSHIFT_PADDING( _KSH ) X_GETKEYBOARDSHIFT( _KSH )

#define X_VECTOR_IS_DBCS_CAPABLE( _X, _V ) \
   ( X_VECTOR_GETKEYBOARDSHIFT( _X, _V ) != BLANK )

#define X_IS_DBCS_CAPABLE( _KSH ) \
   ( X_GETKEYBOARDSHIFT( _KSH ) != BLANK )

#define X_KEYBOARDSHIFT_TO_YESNO( _KSH ) \
   ( (X_CHAR)( strchr( "JEOGUY", _KSH) ? YES : NO ) )

#define X_REFRESH_FIELD(A, B, C, D, E) \
   if ( ( X_VECTOR_FIELD_IS_COMPONENT( D, E ) ) && ( !X_VECTOR_FIELD_IS_EVALUATION( D, E ) ) ) X_Refresh_Field_Value( (A), (B), (C), &( (D)[(E)] ) )

#define X_REFRESH_COMPONENT(A, B, C, D, E)\
   if ( ( X_VECTOR_FIELD_IS_COMPONENT( D, E ) ) && ( !X_VECTOR_FIELD_IS_EVALUATION( D, E ) ) ) X_Refresh_Component_Value( (A), (B), (C), &( (D)[(E)] ) )

#define X_GET_INDEX(A, B, C, D, E) \
   ( (X_VECTOR_FIELD_IS_ARRAY((D), (E))) ? X_Vec_Apply_Index ((A), (B), (C), (D), (E)) : X_VECTOR_RESOLVE_FIELD_ADDRESS(A,B,C,D,E)->pField )


#define X_GET_INDEX_WITH_REFRESH(A, B, C, D, E) \
    ( (X_VECTOR_FIELD_IS_ARRAY((D), (E))) ? X_Vec_Apply_Index ((A), (B), (C), (D), (E)) :  X_VECTOR_RESOLVE_FIELD_ADDRESS(A,B,C,D,E)->pField  ); \
    X_REFRESH_FIELD(A, B, C, D, E)


#define X_SET_INDEX(A, B, C, D, E) \
  if (X_VECTOR_FIELD_IS_INDEX ((D), (E))) X_Vec_Set_Index ((A), (B), (C), (D), (E));


#define X_SET_INDEX_WITH_REFRESH(A, B, C, D, E) \
  if (X_VECTOR_FIELD_IS_INDEX ((D), (E))) X_Vec_Set_Index ((A), (B), (C), (D), (E)); \
  X_REFRESH_COMPONENT(A, B, C, D, E);


#define SIGNAL_COMPONENT_INVALID_USE(_MOD, _IDS, _PRO, _FUN, _FLD, _VEC) \
{ \
   X_VCHAR vchSubsVar[X_VARIABLE_NAME_LEN + 1]; \
   strncpy(vchSubsVar,_FLD[_VEC].fchName2,sizeof(vchSubsVar)); \
   vchSubsVar[sizeof(vchSubsVar) - 1] = LOVAL; \
   X_Fatal_Error(pX_Ids,pX_Pro,pX_Fun,_MOD,X_TEXT(576),vchSubsVar); \
}


#define PERFORM_COMPONENT_OPERATION(_MOD, _IDS, _PRO, _FUN, _REQ, _FLD, _VEC, _PTRRESVAL) \
{ \
   X_COMP_RETURN_CODE ulReturnCode; \
   if ( (_IDS)->pX_IdsComponent->pfnComponentManager ) \
   { \
      X_COMP_SERVICES_POINT_REQUEST CompRequest; \
      PFN_COMP_SERVICES_POINT pfnServicesPoint = (PFN_COMP_SERVICES_POINT) (_IDS)->pX_IdsComponent->pfnComponentManager; \
      X_PVOID apvArgs[2]; \
      CompRequest.lRequest = (X_LONG) _REQ; \
      CompRequest.pX_Ids = (X_PVOID) (_IDS); \
      CompRequest.pfnLANSAServices = (X_PVOID) X_LANSAX_Services; \
      if (_FUN) CompRequest.ulRDMLXLineNumber = ((X_ULONG) _FUN->sSequence); \
      else      CompRequest.ulRDMLXLineNumber = ((X_ULONG) 0); \
      apvArgs[0] = (X_PVOID) ((X_ULONG) _FLD[_VEC].pField); \
      apvArgs[1] = (X_PVOID) (_PTRRESVAL); \
      ulReturnCode = (X_COMP_RETURN_CODE) pfnServicesPoint (&(CompRequest),apvArgs,0,pX_NULL); \
   } \
   else \
   { \
      X_Fatal_Error(_IDS,_PRO,_FUN,_MOD,"Invalid attempt to reference the Component Manager"); \
      ulReturnCode = X_COMP_RETURN_ERROR; \
   } \
   if (ulReturnCode != X_COMP_RETURN_OK) \
   { \
      X_VCHAR vchReturnCode[20]; \
      sprintf(vchReturnCode,"%ld",((X_LONG) ulReturnCode)); \
      X_Fatal_Error(_IDS,_PRO,_FUN,_MOD,"Invocation of the Component Manager failed with error %s",vchReturnCode); \
   } \
}

struct X_FLD
  {
     X_FCHAR             fchName2[X_VARIABLE_NAME_LEN];
     X_CHAR              chFieldInfo;
     X_TYPE_FLAG         chType;
     X_TYPE_FLAG         chSubType;
     X_YES_NO            chDBCS;
     X_SHORT             sLen;
     X_SHORT             sByteLen;
     X_SHORT             sDec;
     X_PDICTIONARY_FIELD pField;
     X_SHORT             sIndexVOV;
     X_YES_NO            chValError;
  } 
#if defined(X_OPERATING_SYSTEM_IOS)
     __attribute__((packed)) // [Danny 26/06/2013] This needs more investigation, we needed it for the IOS POC
#endif
;

typedef enum
{
   FsIsSqlNull       = 0x00000001,
   FsHasOverflowed   = 0x00000002,
   FsHasUnderflowed  = 0x00000004,
   FsHasChanged      = 0x00000008,
   FsHasCharLength   = 0x00000010,
   FsHasWideCharData = 0x00000020,
   FsHasNativeUTF8   = 0x00000040,
   FsIsMax     = 0x10000000      /* Causes Watcom to use an int to store the enumeration */
                                 /* Can change the identifier name to anything useful if */
                                 /* the value needs to be used. Enumeration must just have */
                                 /* a value that requires an int to store it. See          */
                                 /* 32-bit:  Size of Enumerated Types in the Watcom doco   */

} XFIELDSTATE;

#define X_FLDDATA_V1           -1
#define X_FLDDATA_V2           -2

/* Cast to any FLDDATA strcuture as the version is stored in the same place for each */
#define X_FLDDATA_V1_OR_LATER( _pField )   (((PX_FLD_INT8)_pField)->i8Version <= X_FLDDATA_V1)
#define X_FLDDATA_V2_OR_LATER( _pField )   (((PX_FLD_INT8)_pField)->i8Version <= X_FLDDATA_V2)

/* _FLD_INFO. Contains just the information part of _FLD_XXXX, that is */
/* everything except the value                                          */
/* Important X_GET_FIELD_VALUE_MAX_SIZE macro use this to calculate the max value size             */
/* So in the future if some thing will be changed in _FLD_XXXX, same change should be applied here */
typedef struct _FLD_INFO
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
} X_FLD_INFO,
  *PX_FLD_INFO;


/* _FLD_INT8. Structure for signed 1 byte Integer */

typedef struct _FLD_INT8
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_INT8         iInt8;            /* For signed 1 byte Integer */
}  X_FLD_INT8,
   *PX_FLD_INT8;


/* _FLD_UINT8. Structure for unsigned 1 byte Integer */

typedef struct _FLD_UINT8
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_UINT8        uiInt8;          /* For unsigned 1 byte Integer */
}  X_FLD_UINT8,
   *PX_FLD_UINT8;

/* _FLD_INT16. Structure for signed 2 bytes Integer */

typedef struct _FLD_INT16
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_INT16        iInt16;          /* For signed 2 bytes Integer */
}  X_FLD_INT16,
   *PX_FLD_INT16;

/* _FLD_INT32. Structure for signed 4 bytes Integer */

typedef struct _FLD_INT32
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_INT32        iInt32;          /* For signed 4 bytes Integer */
}  X_FLD_INT32,
   *PX_FLD_INT32;

/* _FLD_INT64. Structure for signed 8 bytes Integer */

typedef struct _FLD_INT64
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 64 bit mask */
   X_INT64        iInt64;          /* For signed 8 bytes Integer */
}  X_FLD_INT64,
   *PX_FLD_INT64;

/* _FLD_BOOL. Structure for Boolean */

typedef struct _FLD_BOOL
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_BOOL         fBool ;          /* For Boolean */
}  X_FLD_BOOL,
   *PX_FLD_BOOL;

/* _FLD_FLT32. Structure for Float 32  */

typedef struct _FLD_FLT32
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_FLT32        dFloat32;        /* For 4 bytes Float */
}  X_FLD_FLT32,
   *PX_FLD_FLT32;

/* _FLD_FLT64. Structure for Float 64  */

typedef struct _FLD_FLT64
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_FLT64        dFloat64;        /* For 8 bytes Float */
}  X_FLD_FLT64,
   *PX_FLD_FLT64;

/* _FLD_CLOB. Structure for CLOB  */

typedef struct _FLD_CLOB
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_VCHAR        vchFileName[ X_MAX_SIZE_LOB_FILE_NAME + 1 ];
}  X_FLD_CLOB,
   *PX_FLD_CLOB;

/* _FLD_BLOB. Structure for BLOB  */

typedef struct _FLD_BLOB
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_VCHAR        vchFileName[X_MAX_SIZE_LOB_FILE_NAME + 1];
}  X_FLD_BLOB,
   *PX_FLD_BLOB;

/* _FLD_NCLOB. Structure for NCLOB  */

typedef struct _FLD_NCLOB
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_VCHAR        vchFileName[X_MAX_SIZE_LOB_FILE_NAME + 1];
}  X_FLD_NCLOB,
   *PX_FLD_NCLOB;

/* _FLD_DATE. Structure for DATE  */

typedef struct _FLD_DATE
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_VCHAR        vchDate[X_MAX_SIZE_DATE_LEN]; /* For Date YYYY-MM-DD*/
}  X_FLD_DATE,
   *PX_FLD_DATE;

/* _FLD_TIME. Structure for TIME  */

typedef struct _FLD_TIME
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_VCHAR        vchTime[X_MAX_SIZE_TIME_LEN];   /* For Time HH:MM:SS*/
}  X_FLD_TIME,
   *PX_FLD_TIME;

/* _FLD_DATETIME. Structure for DATETIME  */

typedef struct _FLD_DATETIME
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_VCHAR        vchDateTime[X_MAX_SIZE_DATETIME_LEN];  /* For Time YYYY-MM-DD HH:MM:SS.FFFFFFFFF : 9 digits after fraction point */
}  X_FLD_DATETIME,
   *PX_FLD_DATETIME;

/* _FLD_CHAR/_FLD_NCHAR/_FLD_SHORT_CHAR. Structure for CHAR and VARCHAR  */

typedef struct _FLD_CHAR
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_ULONG        ulMaxSize;        /* Max size this field can be */
   X_PVOID        pvData;           /* point to  X_VAR data */
}  X_FLD_CHAR,
   *PX_FLD_CHAR;

typedef struct _FLD_NCHAR
{
   X_INT8         i8Version;        /* For future enhancement; always -2 at present (V2) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_ULONG        ulMaxSize;        /* Max byte size this field can be */
   X_PVOID        pvData;           /* point to  X_VAR data */
   X_ULONG        ulMaxChars;       /* Max character size this field can be */
}  X_FLD_NCHAR,
   *PX_FLD_NCHAR;

typedef struct _FLD_SHORT_CHAR
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_SHORT        sLength;          /* Current length of vchData excluding terminating zero */
   X_VCHAR        vchData[1];       /* First byte of zero terminated string */
}  X_FLD_SHORT_CHAR,
   *PX_FLD_SHORT_CHAR;

typedef struct _FLD_BINARY
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_ULONG        ulMaxSize;        /* Max size this field can be */
   X_PVOID        pvData;           /* point to  X_VAR data */
}  X_FLD_BINARY,
   *PX_FLD_BINARY;

typedef struct _FLD_PACKED
{
   X_INT8                     i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE                bFieldState;      /* 32 bit mask */
   X_DEFS_FLD_PACKED_DATA_PTR fchData[1];       /* Up to X_MAX_SIZE_PACKED_LEN */
}  X_FLD_PACKED,
   *PX_FLD_PACKED;

typedef struct _FLD_SIGNED
{
   X_INT8                     i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE                bFieldState;      /* 32 bit mask */
   X_DEFS_FLD_SIGNED_DATA_PTR fchData[1];       /* Up to X_MAX_SIZE_SIGNED_LEN */
}  X_FLD_SIGNED,
   *PX_FLD_SIGNED;

typedef struct _FLD_DECIMAL
{
   X_INT8         i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE    bFieldState;      /* 32 bit mask */
   X_PVOID        pvData;           /* point to  X_VAR data */
}  X_FLD_DECIMAL,
   *PX_FLD_DECIMAL;

typedef struct _FLD_EVALUATION
{
   X_INT8                           i8Version;        /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE                      bFieldState;      /* 32 bit mask */
   X_LONG                           lSize;            /* Size of following Evaluation table */
   X_DEFS_FLD_EVALUATION_TABLE_PTR  ppvTable;         /* Pointer to table of Evaluation definitions */
}  X_FLD_EVALUATION,
   *PX_FLD_EVALUATION;

typedef struct _FLD_RECORD
{
   X_INT8                              i8Version;     /* For future enhancement; always -1 at present (V1) */
   XFIELDSTATE                         bFieldState;   /* 32 bit mask */
   struct X_DRD                     *  pDescription;  /* Pointer to static description of data record */
   X_VOID                           *  pDataRecord;   /* Pointer to instance of data record */
   X_VOID                           *  pHandler;      /* Pointer to handler of record service requests */
}  
   X_FLD_RECORD,
   *PX_FLD_RECORD;


/* All the possible strcutures that pField can point to */
/* The maximum length of pField is calculated from this */
typedef union _FLDDATA
{
   X_FLD_INT8        Int8;
   X_FLD_UINT8       Uint8;
   X_FLD_INT16       Int16;
   X_FLD_INT32       Int32;
   X_FLD_INT64       Int64;
   X_FLD_BOOL        Bool;
   X_FLD_FLT32       Flt32;
   X_FLD_FLT64       Flt64;
   X_FLD_CLOB        Clob;
   X_FLD_BLOB        Blob;
   X_FLD_NCLOB       Nclob;
   X_FLD_DATE        Date;
   X_FLD_TIME        Time;
   X_FLD_DATETIME    Datetime;
   X_FLD_CHAR        Char;
   X_FLD_NCHAR       Nchar;
   X_FLD_BINARY      Binary;
   X_FLD_DECIMAL     Decimal;
   X_FLD_EVALUATION  Evaluation;
   X_CHAR            Alpha1[256];
   X_UCHAR           Packed1[16];
   X_UCHAR           Signed1[30];
   X_UCHAR           Packed2[ ( sizeof(X_FLD_PACKED) - 1 ) + ( ( X_MAX_NUMERIC_DIGITS / 2 ) + 1 ) ];
   X_UCHAR           Signed2[ ( sizeof(X_FLD_SIGNED) - 1 ) + X_MAX_NUMERIC_DIGITS ];
   X_UCHAR           ShortChar[ sizeof(X_FLD_SHORT_CHAR) + X_MAX_SHORT_CHAR_FIELD_LEN ];
}
    X_FLDDATA,
   *PX_FLDDATA;

/* ****************************** */
/* OBSOLETE STRUCTURE. DO NOT USE */
/* ****************************** */
struct X_FLD2
  {
     X_FCHAR             fchName[X_VARIABLE_NAME_LEN];
     X_CHAR              chFieldInfo;
     X_TYPE_FLAG         chType;
     X_TYPE_FLAG         chSubType;
     X_CHAR              chDBCS;
     X_SHORT             sLen;
     X_SHORT             sByteLen;
     X_SHORT             sDec;
     X_PVOID             pFieldExt;
     X_SHORT             sIndexVOV;
     X_YES_NO            chValError;
  } ;

/* ------------------------------------ */
/* A structure to save LL2 field value  */
/* ------------------------------------ */

typedef struct _X_SAVE_FIELD_VALUE
{
   X_LONG    lFieldState;  /* bFieldState from X_FLD_XXX).        */
   X_ULONG   ulCurLen;     /* Number of bytes of data following   */

}     X_SAVE_FIELD_VALUE,
 *   PX_SAVE_FIELD_VALUE;

/* --------------------------------- */
/* A structure to save field values  */
/* --------------------------------- */

typedef struct _X_SAVE_FIELD_AREA
{
   X_ULONG              ulSize; /* Size of the area */
   char                 Data[1];
}     X_SAVE_FIELD_AREA,
 *   PX_SAVE_FIELD_AREA;

/* ================================================================= */
/*  X_VECTOR_COMPONENT_EXCHANGE : Tracks component/vector exchanges  */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ExchangeFormat  Exchange format (refer to LIIODEF.H)              */
/* FieldVector     X_FLD vector of field to be exchanged             */


typedef struct _X_VECTOR_COMPONENT_EXCHANGE
  {
     X_USHORT usExchangeFormat;
     X_SHORT  sFieldVector;
  }
         X_VECTOR_COMPONENT_EXCHANGE,
    *   PX_VECTOR_COMPONENT_EXCHANGE,
    ** PPX_VECTOR_COMPONENT_EXCHANGE;

/* ================================================================= */
/*  X_Rename_Stack : Tracks renames in executing functions           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* OrgName         OriginalName                                      */
/* Vector          Vector of field                                   */

struct X_RENAME_STACK
  {
     X_FCHAR             fchOrgName[X_VARIABLE_NAME_LEN];
     X_SHORT             sVector;
  } ;

/* ================================================================= */
/*  X_VALIDATE : LANSA/X Validation Function Structure               */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Name of field to be validated                     */
/* Len             Length of field to be validated                   */
/* Dec             Decimals in field to be validated                 */
/* RetCode         Return code from validation                       */
/* Value           Value of field to be validated in string format   */
/* Type            Field type - only used on iSeries for RPG calls   */

struct X_VALIDATE
  {
     X_VCHAR         vchName[X_OBJECT_NAME_LEN + 1];
     X_SHORT         sLen;
     X_SHORT         sDec;
     X_CHAR          chRetCode;
     X_VCHAR         vchValue[X_MAX_ALPHA_FIELD_LEN + 1];
     X_TYPE_FLAG     chType;
  } ;

/* ================================================================= */
/*  X_SYSVAR   : LANSA/X system variable evaluation structure        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* VarName         Name of system variable to be evaluated           */
/* pX_Fld          Pointer to X_FLD structure of result field        */
/* vResult         Vector Number of result field                     */

struct X_SYSVAR
  {
     X_VCHAR         vchName[X_SYSVAR_NAME_LEN + 1];
     struct X_FLD    *pX_Fld;
     X_SHORT         svResult;
  } ;

/* ================================================================= */
/*  X_Procp : LANSA/X Process Parameter Values inter/batch exchange  */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Number          Parameter Number                                  */
/* Type            Parameter Type                                    */
/* Len             Parameter Length                                  */
/* Dec             Decimal Positions                                 */
/* Value           Parameter Value                                   */

struct X_PROCP
  {
     X_SHORT         sNumber;
     struct X_FLD    X_Fld;
     X_FCHAR         fchValue[X_MAX_ALPHA_FIELD_LEN];
  } ;


/* ================================================================= */
/*  X_Panel_Ctl : Panel Display Control                              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Type            Display, Request or Pop_up                        */
/* StdHead         Show Standard Headings (YES/NO)                   */
/* StdDate         Show Standard Date (YES/NO)                       */
/* StdTime         Show Standard Time (YES/NO)                       */
/* pPanelId        Pointer to Panel Identification (may be null)     */
/* pPanelTitle     Pointer to Panel Title (may be null)              */
/* Row_Offset      Row Offset                                        */
/* Col_Offset      Column Offset                                     */
/* sDescPadLen     Pad all descriptions to this length with dots.    */
/* sExitHi         Exit Hi enablement condition number               */
/* sExitLow        Exit Low enablement Number                        */
/* sCancel         Cancel enablement Number                          */
/* sAdd            Add    enablement Number                          */
/* sChange         Change enablement Number                          */
/* sDelete         Delete enablement Number                          */
/* sPrompt         Prompt enablement Number                          */
/* UKey            User Keys array of structures                     */
/* IO_KEY          Vector number of IO_KEY field (negative if none)  */
/* PopUpRow        Pop-up window row location                        */
/* PopUpCol        Pop-up window column location                     */
/* PopUpWidth      Pop-up window width                               */
/* PopUpLength     Pop-up window Length                              */
/* CursorRow       Cursor Row                                        */
/* CursorCol       Cursor Column                                     */
/* RUpMeth         Roll Up Method                                    */
/* RDnMeth         Roll Down Method                                  */
/* TopEntry        TopEntry to display/selected                      */
/* RowVector       Vector of cursor Row field (if sepecified)        */
/* ColVector       Vector of cursor Column field (if specified)      */

#define X_PNL_IS_DISPLAY     pX_Panel_Ctl->chType == 'D'
#define X_PNL_IS_REQUEST     pX_Panel_Ctl->chType == 'R'
#define X_PNL_IS_POP_UP      pX_Panel_Ctl->chType == 'P'

#define X_ROLL_BY_FUNCTION   'R'
#define X_ROLL_BY_UIM        'U'

struct X_PANEL_USER_KEY
   {
      X_SHORT        sCond;
      X_VCHAR        vchAID[X_FKEY_AID_LEN + 1];
      X_PVCHAR       pvchDesc;
   };

struct X_PANEL_CTL
   {
      X_TYPE_FLAG    chType;
      X_YES_NO       chStdHead;
      X_YES_NO       chStdDate;
      X_YES_NO       chStdTime;
      X_PVCHAR       pvchPanelId;
      X_PVCHAR       pvchPanelTitle;
      X_SHORT        sRowOffset;
      X_SHORT        sColOffset;
      X_SHORT        sDescPadLen;
      X_SHORT        sExitHi;
      X_SHORT        sExitLow;
      X_SHORT        sCancel;
      X_SHORT        sAdd;
      X_SHORT        sChange;
      X_SHORT        sDelete;
      X_SHORT        sPrompt;
      struct  X_PANEL_USER_KEY UKey[X_MAXIMUM_USER_KEYS];
      X_SHORT        sIO_KEY;
      X_SHORT        sPopUpRow;
      X_SHORT        sPopUpCol;
      X_SHORT        sPopUpWidth;
      X_SHORT        sPopUpLength;
      X_SHORT        sCursorRow;
      X_SHORT        sCursorCol;
      X_CHAR         chRUpMeth;
      X_CHAR         chRDnMeth;
      X_SHORT        sTopEntry;
      X_SHORT        sRowVector;
      X_SHORT        sColVector;
   };

/* ================================================================= */
/*  X_Panel_Txt : Panel Text Details                                 */
/* ================================================================= */
/*                                                                   */
/* Narrative : This structure is normally statically defined in RDML */
/* ---------   functions to define the text details that are to      */
/* appear on a screen panel. For example, an RDML DISPLAY command at */
/* sequence number 123 that presented a panel with 2 pieces of       */
/* text on it would cause the generation of declarative code like    */
/* this :                                                            */
/*                                                                   */
/*    X_TEXT_GROUP_0123 2                                            */
/*    static X_PANEL_TXT                                             */
/*           X_Panel_Txt_0123[] = {<static initialisation values>};  */
/*                                                                   */
/* Subsequent calls to UIM panel manager routines pass the address   */
/* of the first element of this structure and the count value of     */
/* X_TOTAL_TEXT_nnnn to instruct it as to textual details that are   */
/* to be presented on the screen panel.                              */
/*                                                                   */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Row             Line at which field appears in panel              */
/* Col             Position at which field appears in panel          */
/* Text            Pointer to X_VCHAR text string                    */
/* Attrib          Display Attributes                                */
/* Colour          Colour Attribute                                  */

#define X_TEXT_TOTAL_ATTRIB 5

#define X_TEXT_ATTRIB_RI_INDEX 0
#define X_TEXT_ATTRIB_UL_INDEX 1
#define X_TEXT_ATTRIB_BL_INDEX 2
#define X_TEXT_ATTRIB_CS_INDEX 3
#define X_TEXT_ATTRIB_HI_INDEX 4

#define X_TEXT_ATTRIB_RI  pX_PanelTxt->chAttrib[0] == 'Y'
#define X_TEXT_ATTRIB_UL  pX_PanelTxt->chAttrib[1] == 'Y'
#define X_TEXT_ATTRIB_BL  pX_PanelTxt->chAttrib[2] == 'Y'
#define X_TEXT_ATTRIB_CS  pX_PanelTxt->chAttrib[3] == 'Y'
#define X_TEXT_ATTRIB_HI  pX_PanelTxt->chAttrib[4] == 'Y'

#define X_COLOUR_GRN  'G'
#define X_COLOUR_WHT  'W'
#define X_COLOUR_RED  'R'
#define X_COLOUR_TRQ  'T'
#define X_COLOUR_YLW  'Y'
#define X_COLOUR_PNK  'P'
#define X_COLOUR_BLU  'B'

#define X_TEXT_COLOUR_GRN  pX_PanelTxt->chColour == X_COLOUR_GRN
#define X_TEXT_COLOUR_WHT  pX_PanelTxt->chColour == X_COLOUR_WHT
#define X_TEXT_COLOUR_RED  pX_PanelTxt->chColour == X_COLOUR_RED
#define X_TEXT_COLOUR_TRQ  pX_PanelTxt->chColour == X_COLOUR_TRQ
#define X_TEXT_COLOUR_YLW  pX_PanelTxt->chColour == X_COLOUR_YLW
#define X_TEXT_COLOUR_PNK  pX_PanelTxt->chColour == X_COLOUR_PNK
#define X_TEXT_COLOUR_BLU  pX_PanelTxt->chColour == X_COLOUR_BLU

struct X_PANEL_TXT
  {
     X_SHORT     sRow;
     X_SHORT     sCol;
     X_PVCHAR    pvchText;
     X_CHAR      chAttrib[X_TEXT_TOTAL_ATTRIB];
     X_CHAR      chColour;
  };

/* ================================================================= */
/*  X_Panel_Fld : Panel Field Definition                             */
/* ================================================================= */
/*                                                                   */
/* Narrative : This structure is normally statically defined in RDML */
/* ---------   functions to define the detail of fields to appear    */
/* appear on a screen panel in the header area or the browse list    */
/* area. For example an RDML DISPLAY command that displayed 2 fields */
/* in the header area of a panel would cause code like this to be    */
/* generated (assuming the command is at sequence number 45).        */
/*                                                                   */
/*    X_PANEL_GROUP_0045 2                                           */
/*    static X_PANEL_FLD                                             */
/*           X_Panel_Fld_0045[] = {<initialisation values>};         */
/*                                                                   */
/* Subsequent calls to UIM panel manager routines pass the address   */
/* of the first element of this structure and the count value of     */
/* X_TOTAL_TEXT_nnnn to instruct it as to textual details that are   */
/* to be presented on the screen panel.                              */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Vector          Vector number in X_Fld of this Field              */
/* Usage           Usage on Panel                                    */
/* ModeCond        Mode Condition Number                             */
/* ShowCond        Show Condition Number                             */
/* ErrorCond       Error Condition Number                            */
/* Row             Line at which field appears in panel              */
/* Col             Position at which field appears in panel          */
/* InputColour     Input Colour                                      */
/* OutputColour    Output Colour                                     */
/* IdMethod        Identification Method                             */
/* IdCond          Identification Condition                          */
/* IdString[ ]     Identification Strings                            */
/* IdStringRow[ ]  Identification Strings                            */
/* IdStringCol[ ]  Identification Strings                            */
/* EditCode        Edit Code                                         */
/* EditWord        Edit Word                                         */
/* KeyBoardShift   Key Board Shift                                   */
/* DisplayLength   Displayable Length in characters                  */


#define X_PNL_INPUT_FLD    pX_PanelFld->chUsage == X_PNL_INPUT_FLD_ID
#define X_PNL_OUTPUT_FLD   pX_PanelFld->chUsage == X_PNL_OUTPUT_FLD_ID
#define X_PNL_MODAL_FLD    pX_PanelFld->chUsage == X_PNL_MODAL_FLD_ID
#define X_PNL_HIDDEN_FLD   pX_PanelFld->chUsage == X_PNL_HIDDEN_FLD_ID

#define X_PNL_INPUT_FLD_ID    'I'
#define X_PNL_OUTPUT_FLD_ID   'O'
#define X_PNL_MODAL_FLD_ID    'B'
#define X_PNL_HIDDEN_FLD_ID   'H'

#define X_PNL_INPUT_GRN   pX_PanelFld->chInputColour == 'G'
#define X_PNL_INPUT_WHT   pX_PanelFld->chInputColour == 'W'
#define X_PNL_INPUT_RED   pX_PanelFld->chInputColour == 'R'
#define X_PNL_INPUT_TRQ   pX_PanelFld->chInputColour == 'T'
#define X_PNL_INPUT_YLW   pX_PanelFld->chInputColour == 'Y'
#define X_PNL_INPUT_PNK   pX_PanelFld->chInputColour == 'P'
#define X_PNL_INPUT_BLU   pX_PanelFld->chInputColour == 'B'

#define X_PNL_OUTPUT_GRN   pX_PanelFld->chOutputColour == 'G'
#define X_PNL_OUTPUT_WHT   pX_PanelFld->chOutputColour == 'W'
#define X_PNL_OUTPUT_RED   pX_PanelFld->chOutputColour == 'R'
#define X_PNL_OUTPUT_TRQ   pX_PanelFld->chOutputColour == 'T'
#define X_PNL_OUTPUT_YLW   pX_PanelFld->chOutputColour == 'Y'
#define X_PNL_OUTPUT_PNK   pX_PanelFld->chOutputColour == 'P'
#define X_PNL_OUTPUT_BLU   pX_PanelFld->chOutputColour == 'B'

#define X_PNL_IDM_COLHDG   pX_PanelFld->chIdMethod == 'C'
#define X_PNL_IDM_LABEL    pX_PanelFld->chIdMethod == 'L'
#define X_PNL_IDM_DESC     pX_PanelFld->chIdMethod == 'D'
#define X_PNL_IDM_NONE     pX_PanelFld->chIdMethod == 'N'

#define X_INPUT_ATR_TOTAL 16
#define X_PNL_LC_IDX    0
#define X_PNL_AB_IDX    1
#define X_PNL_ME_IDX    2
#define X_PNL_MF_IDX    3
#define X_PNL_M10_IDX   4
#define X_PNL_M11_IDX   5
#define X_PNL_VN_IDX    6
#define X_PNL_FE_IDX    7
#define X_PNL_RB_IDX    8
#define X_PNL_RZ_IDX    9
#define X_PNL_RL_IDX    10
#define X_PNL_BL_IDX    11
#define X_PNL_CS_IDX    12
#define X_PNL_HI_IDX    13
#define X_PNL_ND_IDX    14
#define X_PNL_RA_IDX    15

#define X_PNL_INPUT_LC     pX_PanelFld->chInputAttrib[X_PNL_LC_IDX  ] == 'Y'
#define X_PNL_INPUT_AB     pX_PanelFld->chInputAttrib[X_PNL_AB_IDX  ] == 'Y'
#define X_PNL_INPUT_ME     pX_PanelFld->chInputAttrib[X_PNL_ME_IDX  ] == 'Y'
#define X_PNL_INPUT_MF     pX_PanelFld->chInputAttrib[X_PNL_MF_IDX  ] == 'Y'
#define X_PNL_INPUT_M10    pX_PanelFld->chInputAttrib[X_PNL_M10_IDX ] == 'Y'
#define X_PNL_INPUT_M11    pX_PanelFld->chInputAttrib[X_PNL_M11_IDX ] == 'Y'
#define X_PNL_INPUT_VN     pX_PanelFld->chInputAttrib[X_PNL_VN_IDX  ] == 'Y'
#define X_PNL_INPUT_FE     pX_PanelFld->chInputAttrib[X_PNL_FE_IDX  ] == 'Y'
#define X_PNL_INPUT_RB     pX_PanelFld->chInputAttrib[X_PNL_RB_IDX  ] == 'Y'
#define X_PNL_INPUT_RZ     pX_PanelFld->chInputAttrib[X_PNL_RZ_IDX  ] == 'Y'
#define X_PNL_INPUT_RL     pX_PanelFld->chInputAttrib[X_PNL_RL_IDX  ] == 'Y'
#define X_PNL_INPUT_BL     pX_PanelFld->chInputAttrib[X_PNL_BL_IDX  ] == 'Y'
#define X_PNL_INPUT_CS     pX_PanelFld->chInputAttrib[X_PNL_CS_IDX  ] == 'Y'
#define X_PNL_INPUT_HI     pX_PanelFld->chInputAttrib[X_PNL_HI_IDX  ] == 'Y'
#define X_PNL_INPUT_ND     pX_PanelFld->chInputAttrib[X_PNL_ND_IDX  ] == 'Y'
#define X_PNL_INPUT_RA     pX_PanelFld->chInputAttrib[X_PNL_RA_IDX  ] == 'Y'

#define X_OUTPUT_ATR_TOTAL 16
#define X_PNL_OUTPUT_LC    pX_PanelFld->chOutputAttrib[X_PNL_LC_IDX  ] == 'Y'
#define X_PNL_OUTPUT_AB    pX_PanelFld->chOutputAttrib[X_PNL_AB_IDX  ] == 'Y'
#define X_PNL_OUTPUT_ME    pX_PanelFld->chOutputAttrib[X_PNL_ME_IDX  ] == 'Y'
#define X_PNL_OUTPUT_MF    pX_PanelFld->chOutputAttrib[X_PNL_MF_IDX  ] == 'Y'
#define X_PNL_OUTPUT_M10   pX_PanelFld->chOutputAttrib[X_PNL_M10_IDX ] == 'Y'
#define X_PNL_OUTPUT_M11   pX_PanelFld->chOutputAttrib[X_PNL_M11_IDX ] == 'Y'
#define X_PNL_OUTPUT_VN    pX_PanelFld->chOutputAttrib[X_PNL_VN_IDX  ] == 'Y'
#define X_PNL_OUTPUT_FE    pX_PanelFld->chOutputAttrib[X_PNL_FE_IDX  ] == 'Y'
#define X_PNL_OUTPUT_RB    pX_PanelFld->chOutputAttrib[X_PNL_RB_IDX  ] == 'Y'
#define X_PNL_OUTPUT_RZ    pX_PanelFld->chOutputAttrib[X_PNL_RZ_IDX  ] == 'Y'
#define X_PNL_OUTPUT_RL    pX_PanelFld->chOutputAttrib[X_PNL_RL_IDX  ] == 'Y'
#define X_PNL_OUTPUT_BL    pX_PanelFld->chOutputAttrib[X_PNL_BL_IDX  ] == 'Y'
#define X_PNL_OUTPUT_CS    pX_PanelFld->chOutputAttrib[X_PNL_CS_IDX  ] == 'Y'
#define X_PNL_OUTPUT_HI    pX_PanelFld->chOutputAttrib[X_PNL_HI_IDX  ] == 'Y'
#define X_PNL_OUTPUT_ND    pX_PanelFld->chOutputAttrib[X_PNL_ND_IDX  ] == 'Y'
#define X_PNL_OUTPUT_RA    pX_PanelFld->chOutputAttrib[X_PNL_RA_IDX  ] == 'Y'

struct X_PANEL_FLD
  {
     X_SHORT     sVector;
     X_TYPE_FLAG chUsage;
     X_SHORT     sModeCond;
     X_SHORT     sShowCond;
     X_SHORT     sRow;
     X_SHORT     sCol;
     X_TYPE_FLAG chInputColour;
     X_TYPE_FLAG chOutputColour;
     X_TYPE_FLAG chIdMethod;
     X_SHORT     sIdCond;
     X_PVCHAR    pvchIdString[X_ALLOW_ID_STRINGS];
     X_SHORT     sIdStringRow[X_ALLOW_ID_STRINGS];
     X_SHORT     sIdStringCol[X_ALLOW_ID_STRINGS];
     X_TYPE_FLAG chEditCode;
     X_PVCHAR    pvchEditWord;
     X_TYPE_FLAG chKeyboardShift;
     X_FCHAR     chInputAttrib[X_INPUT_ATR_TOTAL];
     X_FCHAR     chOutputAttrib[X_OUTPUT_ATR_TOTAL];
     X_SHORT     sDisplayLength;
  } ;

/* ================================================================= */
/*  X_PANEL_FLD_EXT : LANSA/X Panel Field Extensions for WIMP Constructs  */
/* ================================================================= */
/* An extension to X_PANEL_FLD to hold extensions to this structure  */
/* Currently contains information on the type of WIMP construct.     */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sVector        Vector number in X_Fld of this Field               */
/* chWIMPType     Type of WIMP construct                             */
/* vchId          WIMP identification i.e. Push Button AID, Radio    */
/*                Button Group Box, Drop Down List contents list no. */

/* chWIMPType values */

#define X_PNL_EXT_ENTRY_FIELD    'E'   /* Not stored in this structure  */
                                       /* but is used by code           */
#define X_PNL_EXT_PUSH_BUTTON    'P'
#define X_PNL_EXT_RADIO_BUTTON   'R'
#define X_PNL_EXT_CHECK_BOX      'C'
#define X_PNL_EXT_DROP_DOWN_LIST 'D'

#define X_PNL_PUSH_BUTTON_01_AID  "B1"
#define X_PNL_PUSH_BUTTON_02_AID  "B2"
#define X_PNL_PUSH_BUTTON_03_AID  "B3"
#define X_PNL_PUSH_BUTTON_04_AID  "B4"
#define X_PNL_PUSH_BUTTON_05_AID  "B5"
#define X_PNL_PUSH_BUTTON_06_AID  "B6"
#define X_PNL_PUSH_BUTTON_07_AID  "B7"
#define X_PNL_PUSH_BUTTON_08_AID  "B8"
#define X_PNL_PUSH_BUTTON_09_AID  "B9"
#define X_PNL_PUSH_BUTTON_10_AID  "BA"
#define X_PNL_PUSH_BUTTON_11_AID  "BB"
#define X_PNL_PUSH_BUTTON_12_AID  "BC"
#define X_PNL_PUSH_BUTTON_13_AID  "BD"
#define X_PNL_PUSH_BUTTON_14_AID  "BE"
#define X_PNL_PUSH_BUTTON_15_AID  "BF"
#define X_PNL_PUSH_BUTTON_16_AID  "BG"
#define X_PNL_PUSH_BUTTON_17_AID  "BH"
#define X_PNL_PUSH_BUTTON_18_AID  "BI"
#define X_PNL_PUSH_BUTTON_19_AID  "BJ"
#define X_PNL_PUSH_BUTTON_20_AID  "BK"

#define X_FLD_EXT_ID_LEN         2

struct X_PANEL_FLD_EXT
   {
      X_SHORT     sVector;
      X_CHAR      chWIMPType;
      X_VCHAR     vchId[X_FLD_EXT_ID_LEN + 1];

      X_PVOID     pSpare1;
      X_PVOID     pSpare2;
   } ;

/* ================================================================= */
/* Drop down extended value tracking                                 */
/* ================================================================= */

#define X_DD_STYLE_NEDD      1    /* Non-editable drop down                     */
#define X_DD_STYLE_EDDD      2    /* Editable drop down                         */
#define X_DD_STYLE_EDDDWL    3    /* Editable drop down (with a fixed list)     */
#define X_DD_STYLE_NEDDWL    4    /* Non-editable drop down (with a fixed list) */

#define X_DD_DEFAULT_STYLE   X_DD_STYLE_NEDD
#define X_DD_DEFAULT_LENGTH  -1

struct X_DD_DETAILS
   {
      X_VCHAR     vchId[X_FLD_EXT_ID_LEN + 1];
      X_SHORT     sStyle;
      X_SHORT     sLength;
   } ;

struct X_DD_ATTRIBUTES
   {
      X_ULONG               ulTotalDD;
      struct X_DD_DETAILS   DD[1];
   };


/* ================================================================= */
/*  FNCONDEVALU : Function to evaluate a condition                   */
/* ================================================================= */

typedef X_YES_NO_FUNCTION FNCONDEVALU (X_VOID);

typedef FNCONDEVALU *PFNCONDEVALU;

typedef X_YES_NO_FUNCTION FNCONDEVALU_V5 (FUNCTION_STD_ARGS);

typedef FNCONDEVALU_V5 *PFNCONDEVALU_V5;

/* ================================================================= */
/*  X_COND_EVALUTE : Conditions to evaluate for a screen panel       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* CondNumber      Condition Number                                  */
/* CondEvaluate    Pointer to function that evaluates the condition  */

struct X_COND_EVALUATE
  {
     X_SHORT                   sCondNumber;
     union {
              PFNCONDEVALU     pfCondEvaluate;
              PFNCONDEVALU_V5  pfCondEvaluate_V5;
           }                   Version;
  };

/* ================================================================= */
/*  X_EXTRA_USER_KEY : Extra user defined function key details       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Key Name                                          */
/* AID             Associated AID byte                               */

#define X_EXTRA_USER_KEY_MAX          24

struct X_EXTRA_USER_KEY
  {
     X_VCHAR     vchName[X_FKEY_NAME_LEN + 1];
     X_VCHAR     vchAID[X_FKEY_AID_LEN + 1];
  };

/* ================================================================= */
/*  X_COMPONENT_ROUTINE_INO : Component Routine control block        */
/* ================================================================= */

/* sVersionNumber values */

#define X_COMPONENT_INFO_V1                     1

#define X_COMPONENT_INFO_VERSION_MASK           0x000F

#define X_COMPONENT_INFO_ROUTE_MESSAGES_IN      0x0100
#define X_COMPONENT_INFO_ROUTE_MESSAGES_OUT     0x0200

/* chRoutineType values (must NEVER be specified as 'P' or 'F') */

#define X_COMPONENT_EVT_ROUTINE                 'E'
#define X_COMPONENT_MTH_ROUTINE                 'M'
#define X_COMPONENT_PTY_ROUTINE                 'R'
#define X_COMPONENT_WEB_ROUTINE                 'W'

/* Component routine information block */

typedef struct _X_COMPONENT_ROUTINE_INFO
{
   X_SHORT    sVersionAndState;
   X_CHAR     chRoutineType;

}      X_COMPONENT_ROUTINE_INFO,
  *   PX_COMPONENT_ROUTINE_INFO,
  ** PPX_COMPONENT_ROUTINE_INFO;

/* ================================================================= */
/*  X_FUN_ALTNAME_STRING_OFFSET_ENTRY : AltName String+Offset Entry  */
/* ================================================================= */

typedef struct _X_FUN_ALTNAME_STRING_OFFSET_ENTRY
{
   X_VCHAR                             *  pvchStringOfStrings;
   X_DEFS_FLD_SHORT_PTR                   psOffsetTable;
}
      X_FUN_ALTNAME_STRING_OFFSET_ENTRY,
  *   PX_FUN_ALTNAME_STRING_OFFSET_ENTRY,
  ** PPX_FUN_ALTNAME_STRING_OFFSET_ENTRY;

typedef struct _X_FUN_ALTNAME_TABLE
{
   X_FUN_ALTNAME_STRING_OFFSET_ENTRY   ** paStringOffsetEntries;     /* Vers V18 or later */
   X_DEFS_FLD_SHORT_PTR                   psFieldIndexes;            /* Vers V18 or later */
   X_DEFS_FLD_SHORT_PTR                   psListIndexes;             /* Vers V18 or later */
}
      X_FUN_ALTNAME_TABLE,
  *   PX_FUN_ALTNAME_TABLE,
  ** PPX_FUN_ALTNAME_TABLE;

/* Macro to resolve AltName of X_FLD Vector */
#define _X_FUN_GET_FIELD_VECTOR_ALTNAME( _pX_Fun, _V, _P ) \
   if ( _X_FUN_V19_OR_LATER( _pX_Fun ) \
         && ( _pX_Fun->pAltNameTable != pX_NULL ) && ( _pX_Fun->pAltNameTable->psFieldIndexes != pX_NULL ) ) \
   { \
      X_SHORT const \
         sIndex = _pX_Fun->pAltNameTable->psFieldIndexes[ (_V) ]; \
      const X_FUN_ALTNAME_STRING_OFFSET_ENTRY \
         * const pEntry = _pX_Fun->pAltNameTable->paStringOffsetEntries[ ( sIndex >> 8 ) ]; \
      (_P) = pEntry->pvchStringOfStrings + pEntry->psOffsetTable[ sIndex & 0xff ]; \
   } \
   else \
   { \
      (_P) = ""; \
   }

/* Macro to resolve AltName of X_LIST Vector */
#define _X_FUN_GET_LIST_VECTOR_ALTNAME( _pX_Fun, _V, _P ) \
   if ( _X_FUN_V19_OR_LATER( _pX_Fun ) \
         && ( _pX_Fun->pAltNameTable != pX_NULL ) && ( _pX_Fun->pAltNameTable->psListIndexes != pX_NULL ) ) \
   { \
      X_SHORT const \
         sIndex = _pX_Fun->pAltNameTable->psListIndexes[ (_V) ]; \
      const X_FUN_ALTNAME_STRING_OFFSET_ENTRY \
         * const pEntry = _pX_Fun->pAltNameTable->paStringOffsetEntries[ ( sIndex >> 8 ) ]; \
      (_P) = pEntry->pvchStringOfStrings + pEntry->psOffsetTable[ sIndex & 0xff ]; \
   } \
   else \
   { \
      (_P) = ""; \
   }

/* Macro to resolve AltName of X_FLD Vector */
#define X_FUN_GET_FIELD_VECTOR_ALTNAME( _V, _P ) \
   _X_FUN_GET_FIELD_VECTOR_ALTNAME( pX_Fun, _V, _P )

/* Macro to resolve AltName of X_LIST Vector */
#define X_FUN_GET_LIST_VECTOR_ALTNAME( _V, _P ) \
   _X_FUN_GET_LIST_VECTOR_ALTNAME( pX_Fun, _V, _P )

/* ================================================================== */
/*  X_Fun :  LANSA/X Currently Executing Function Definition          */
/* ================================================================== */
/* Name             Description                                       */
/* ----             -----------                                       */
/* X_FunVersion     Version number of this structure                  */
/* OwnProcess       Owning Process Name (may NOT be executing process */
/* Name             Function Name                                     */
/* Desc             Description of Function                           */
/* Command          Current Command Name                              */
/* Sequence         Current Command Sequence Number                   */
/* ShutDown         Shut function down at completion                  */
/* Error            Fatal Error in Function                           */
/* RouteMsgs        Re-Route Messages to the caller                   */
/* chMode           Function Mode                                     */
/* chChangeUsed     Change key/mode has been used                     */
/* chDeleteUsed     Delete key/mode has been used                     */
/* LastAID          AID of last panel interaction                     */
/* Ukey[].vchAID    AIDs of last set of enabled user keys             */
/* chDebug          Indicates if function is in debug mode            */
/* scX_Array        Count of debug array details available            */
/* pX_Array         Pointer to first X_DEBUG_ARRAY structure          */
/* chFunctionLock   Indicates if function has any lock                */
/* vCursorFieldName Vector of field containing cursor field name      */
/* cX_PanelFldExt   Count of X_PANEL_FLD_EXT structures addresssed    */
/* pX_PanelFldExt   Pointer to first X_PANEL_FLD_EXT structure        */
/* scX_Fld          Count of fields in associated X_Fld array         */
/* pX_Fld           Pointer to first X_FLD structure                  */
/* scX_CondEvaluate Count of fields in associated X_Fld array         */
/* pX_CondEvaluate  Pointer to first X_FLD structure                  */
/* svIO_MDE         Vector number of the IO$MDE field                 */
/* pFunctionGlobal1 Pointer to this functions unique global memory 1  */
/* pFunctionGlobal2 Pointer to this functions unique global memory 2  */
/* fComponentRoutineBusy Indicates an active component routine        */
/* fIsComponent     Indicates this is an active component             */
/* pvModuleFrame    Module Frame Pointer as a pointer to void         */
/* BifArgCount      Bif Argument Count                                */
/* BifRetCount      Bif Return Count                                  */
/* BifShutDown      Bif shut down indicator                           */
/* FunctionInstanceId Unique Function INstance Identifier             */
/* sWebPageNumber   Number of next web page to display                */
/* fWebEvent        TRUE if this is a '*WEBEVENT' function            */
/* sWebTextOffset   Offset set in generated code for web text         */
/* fAddPanelTitleAsWebText  TRUE if panel title is added to web text  */
/* fWebPanelHasDescription  TRUE if panel fields has non-blank DESC   */

#define X_FUNCTION_MODE_IS_DISPLAY  (pX_Fun->chMode == 'D')
#define X_FUNCTION_MODE_DISPLAY     'D'
#define X_FUNCTION_MODE_IS_ADD      (pX_Fun->chMode == 'A')
#define X_FUNCTION_MODE_ADD         'A'
#define X_FUNCTION_MODE_IS_CHANGE   (pX_Fun->chMode == 'C')
#define X_FUNCTION_MODE_CHANGE      'C'
#define X_FUNCTION_MODE_IS_DELETE   (pX_Fun->chMode == 'L')
#define X_FUNCTION_MODE_DELETE      'L'
#define X_FUNCTION_MODE_IS_UNKNOWN  (pX_Fun->chMode == 'U')
#define X_FUNCTION_MODE_UNKNOWN     'U'
#define X_FUNCTION_MODE_IS_SAME     (pX_Fun->chMode == 'S')
#define X_FUNCTION_MODE_SAME        'S'

#define X_FUN_V2            (-2)
#define X_FUN_V3            (-3)
#define X_FUN_V4            (-4)
#define X_FUN_V5            (-5)
#define X_FUN_V6            (-6)
#define X_FUN_V7            (-7)
#define X_FUN_V8            (-8)
#define X_FUN_V9            (-9)
#define X_FUN_V10           (-10)
#define X_FUN_V11           (-11)
#define X_FUN_V12           (-12)
#define X_FUN_V13           (-13)
#define X_FUN_V14           (-14)
#define X_FUN_V15           (-15)
#define X_FUN_V16           (-16)
#define X_FUN_V17           (-17)
#define X_FUN_V18           (-18)
#define X_FUN_V19           (-19)
#define X_FUN_V20           (-20)

#define X_FUN_V2_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V2)
#define X_FUN_V3_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V3)
#define X_FUN_V4_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V4)
#define X_FUN_V5_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V5)
#define X_FUN_V6_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V6)
#define X_FUN_V7_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V7)
#define X_FUN_V8_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V8)
#define X_FUN_V9_OR_LATER   (pX_Fun->sX_FunVersion <= X_FUN_V9)
#define X_FUN_V10_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V10)
#define X_FUN_V11_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V11)
#define X_FUN_V12_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V12)
#define X_FUN_V13_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V13)
#define X_FUN_V14_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V14)
#define X_FUN_V15_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V15)
#define X_FUN_V16_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V16)
#define X_FUN_V17_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V17)
#define X_FUN_V18_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V18)
#define X_FUN_V19_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V19)
#define X_FUN_V20_OR_LATER  (pX_Fun->sX_FunVersion <= X_FUN_V20)

#define _X_FUN_V19_OR_LATER( _pX_Fun ) \
   (_pX_Fun->sX_FunVersion <= X_FUN_V19)

#ifdef X_OPERATING_TARGET_CSHARP

#define X_IS_STRICT_SQL_NULL_ASSIGN(_PFUN)      ( (_PFUN->sX_FunVersion <= X_FUN_V14) && ( (_PFUN->bFunctionState & FuncIsStrictSqlNullAssign) !=0 ) )

#else

#define X_IS_STRICT_SQL_NULL_ASSIGN(_PFUN)      ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (_PFUN->bFunctionState & FuncIsStrictSqlNullAssign) )

#endif // X_OPERATING_TARGET_CSHARP

/* The following macro names reflect the same names used as conditional generation directives   */
/* e.g. %%IF_RDMLX_IS_NOT_USED_IN_FUNCTION. see dc_p3109.c                                      */

#ifdef X_OPERATING_TARGET_CSHARP

#define X_IS_LANGUAGE_LEVEL_TWO(_PFUN)          ( (_PFUN->sX_FunVersion <= X_FUN_V14) && ( ( (int)_PFUN->bFunctionState & (int)XFUNCTIONSTATE.FuncIsLanguageLevelTwo ) != 0 ) )

#define X_IS_COMPONENT(_PFUN)                   ( (_PFUN->sX_FunVersion <= X_FUN_V6) &&  (_PFUN->fIsComponent) )

#define X_IS_FUNCTION(_PFUN)                    ( !( X_IS_COMPONENT(_PFUN) ) )
#define X_IS_LL1_FUNCTION(_PFUN)                ( X_IS_FUNCTION(_PFUN) && !( X_RDML2_IS_USED(_PFUN) || X_RDMLX_IS_USED(_PFUN) ) )
#define X_IS_LL2_FUNCTION(_PFUN)                ( X_IS_FUNCTION(_PFUN) &&  ( X_RDML2_IS_USED(_PFUN) || X_RDMLX_IS_USED(_PFUN) ) )

#define X_RDMLX_IS_USED_IN_COMPONENT(_PFUN)     ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (_PFUN->fIsComponent)    \
                                                  && (((int)_PFUN->bFunctionState & (int)FuncIsRdmlxUsed)!=0) )
#define X_RDMLX_IS_USED_IN_FUNCTION(_PFUN)      ( (_PFUN->sX_FunVersion <= X_FUN_V14) && !(_PFUN->fIsComponent)   \
                                                  && (((int)_PFUN->bFunctionState & (int)FuncIsRdmlxUsed)!=0) )
#define X_RDMLX_IS_NOT_USED_IN_FUNCTION(_PFUN)  ( !( X_RDMLX_IS_USED_IN_FUNCTION(_PFUN) ) )
#define X_RDMLX_IS_USED(_PFUN)                  ( (_PFUN->sX_FunVersion <= X_FUN_V14) && ( (_PFUN->fIsComponent)  \
                                                  || (_PFUN->bFunctionState & FuncIsRdmlxUsed) ) )
#define X_RDML2_IS_USED(_PFUN)                  ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (((int)_PFUN->bFunctionState & (int)FuncIsFullRdmlxUsed)!=0) )
#define X_RDML2_IS_NOT_USED(_PFUN)              ( !( X_RDML2_IS_USED(_PFUN) ) )

#else

#define X_IS_LANGUAGE_LEVEL_TWO(_PFUN)          ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (_PFUN->bFunctionState & FuncIsLanguageLevelTwo) )
#define X_IS_COMPONENT(_PFUN)                   ( (_PFUN->sX_FunVersion <= X_FUN_V6) &&  (_PFUN->fIsComponent) )

#define X_IS_FUNCTION(_PFUN)                    ( !( X_IS_COMPONENT(_PFUN) ) )
#define X_IS_LL1_FUNCTION(_PFUN)                ( X_IS_FUNCTION(_PFUN) && !( X_RDML2_IS_USED(_PFUN) || X_RDMLX_IS_USED(_PFUN) ) )
#define X_IS_LL2_FUNCTION(_PFUN)                ( X_IS_FUNCTION(_PFUN) &&  ( X_RDML2_IS_USED(_PFUN) || X_RDMLX_IS_USED(_PFUN) ) )

#define X_RDMLX_IS_USED_IN_COMPONENT(_PFUN)     ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (_PFUN->fIsComponent)    \
                                                  && (_PFUN->bFunctionState & FuncIsRdmlxUsed) )
#define X_RDMLX_IS_USED_IN_FUNCTION(_PFUN)      ( (_PFUN->sX_FunVersion <= X_FUN_V14) && !(_PFUN->fIsComponent)   \
                                                  && (_PFUN->bFunctionState & FuncIsRdmlxUsed) )
#define X_RDMLX_IS_NOT_USED_IN_FUNCTION(_PFUN)  ( !( X_RDMLX_IS_USED_IN_FUNCTION(_PFUN) ) )
#define X_RDMLX_IS_USED(_PFUN)                  ( (_PFUN->sX_FunVersion <= X_FUN_V14) && ( (_PFUN->fIsComponent)  \
                                                  || (_PFUN->bFunctionState & FuncIsRdmlxUsed) ) )
#define X_RDML2_IS_USED(_PFUN)                  ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (_PFUN->bFunctionState & FuncIsFullRdmlxUsed) )
#define X_RDML2_IS_NOT_USED(_PFUN)              ( !( X_RDML2_IS_USED(_PFUN) ) )

#endif // X_OPERATING_TARGET_CSHARP

#define X_FUN_FUNCTION_INSTANCE_ID(_PFUN) \
   ( (_PFUN->sX_FunVersion <= X_FUN_V20) \
      ? (intptr_t)_PFUN->pvFunctionInstanceId \
      : (intptr_t)_PFUN->ulFunctionInstanceId )

#define X_SIZE_IS_IN_GLOBALS(_PFUN)             ( (_PFUN->sX_FunVersion <= X_FUN_V14) && (_PFUN->bFunctionState & FuncIsSizingInfoInGlobals) )

#if defined(X_OPERATING_SYSTEM_WIN)

   #define X_REMEMBER_HKEY                   HKEY_CURRENT_USER
   #define X_REMEMBER_SUBKEY_MAX_LENGTH      256
   #define X_REMEMBER_SUBKEY_USER_FUNCTION   "Software\\L4WApplication\\RememberedValue\\ForUser\\%s\\%s"
   #define X_REMEMBER_SUBKEY_FUNCTION        "Software\\L4WApplication\\RememberedValue\\ForFunction\\%s"
   #define X_REMEMBER_SUBKEY_SYSTEM          "Software\\L4WApplication\\RememberedValue\\ForSystem"
   #define X_REMEMBER_SUBKEY_USER_SYSTEM     "Software\\L4WApplication\\RememberedValue\\ForUserInSystem\\%s"

#endif

/* CCS 122467 - Ensure generate component C code compiles on non-Windows ISeries. */
#define X_REMEMBER_FORMAT_USER_FUNCTION  10
#define X_REMEMBER_FORMAT_FUNCTION       20
#define X_REMEMBER_FORMAT_SYSTEM         30
#define X_REMEMBER_FORMAT_USER_SYSTEM    40

typedef enum
{
   FuncIsFullRdmlxUsed        = 0x00000001,
   FuncIsLL2                  = 0x00000001,     /* TODO: Delete when all references removed. */
   FuncIsStrictSqlNullAssign  = 0x00000002,
   FuncIsRdmlxUsed            = 0x00000004,
   FuncIsLanguageLevelTwo     = 0x00000008,
   FuncIsSizingInfoInGlobals  = 0x00000010,
   FuncIsStaticTextUtf8       = 0x00000020,
   FuncIsMax                  = 0x10000000      /* Causes Watcom to use an int to store the enumeration */
                                                /* Can change the identifier name to anything useful if */
                                                /* the value needs to be used. Enumeration must just have */
                                                /* a value that requires an int to store it. See          */
                                                /* 32-bit:  Size of Enumerated Types in the Watcom doco   */

} XFUNCTIONSTATE;

struct X_FUN_UKEY
  {
     X_VCHAR   vchAID[X_FKEY_AID_LEN + 1];
  } ;

#include "x_strpck.h"
/* This struct is configured for communications */
typedef struct _X_FUN_RENAMES
{
   X_FCHAR fchFile[X_TABLE_NAME_LEN + 1]; /* Same as vchPhysical, null-term */
   X_SHORT sTargetVector;
   X_SHORT sSourceVector;
}      X_FUN_RENAMES,
   *   PX_FUN_RENAMES;
#include "x_endpck.h"

struct X_FUN
  {
     X_SHORT    sX_FunVersion;
     X_VCHAR    vchOwnProcess[X_OBJECT_NAME_LEN+1];
     X_VCHAR    vchName[X_FUNCTION_NAME_LEN+1];
     X_VCHAR    vchDesc[X_DESCRIPTION_LEN+1];
     X_VCHAR    vchCommand[X_OBJECT_NAME_LEN+1];
     X_SHORT    sSequence;
     X_CHAR     chShutDown;
     X_CHAR     chError;
     X_CHAR     chRouteMsgs;
     X_CHAR     chMode;
     X_YES_NO   chChangeUsed;
     X_CHAR     chDeleteUsed;
     X_VCHAR    vchLastAID[X_FKEY_AID_LEN + 1];
     struct     X_FUN_UKEY UKey[X_MAXIMUM_USER_KEYS];
     X_CHAR     chDebug;
     X_SHORT    scX_Array;
     struct     X_DEBUG_ARRAY *pX_Array;

     X_CHAR     chFunctionLock;
     X_SHORT    sVCursorFieldName;                      /* Vers V2 or later */
     X_SHORT    scX_PanelFldExt;                        /* Vers V2 or later */
     struct     X_PANEL_FLD_EXT  *pX_PanelFldExt;       /* Vers V2 or later */

     X_SHORT    scX_Fld;                                /* Vers V3 or later */
     X_DEFS_FLD_TABLE pX_Fld;                           /* Vers V3 or later */

     X_SHORT    scX_CondEvaluate;                       /* Vers V4 or later */
     struct     X_COND_EVALUATE  *pX_CondEvaluate;      /* Vers V4 or later */
     X_SHORT    svIO_MDE;                               /* Vers V4 or later */
     X_SHORT    scX_ExtraUserKey;                       /* Vers V4 or later */
     struct     X_EXTRA_USER_KEY *pX_ExtraUserKey;      /* Vers V4 or later */

     struct FUNCTION_STATIC_GLOBAL_1 *pFunctionGlobal1; /* Vers V5 or later */
     struct FUNCTION_STATIC_GLOBAL_2 *pFunctionGlobal2; /* Vers V5 or later */

     X_BOOL      fComponentRoutineBusy;                  /* Vers V6 or later */
     X_BOOL      fIsComponent;                           /* Vers V6 or later */
     X_PVOID     pvModuleFrame;                          /* Vers V6 or later */

     X_SHORT     scX_List;                               /* Vers V6 or later */
     X_DEFS_LIST_VOID_TABLE pX_List;                     /* Vers V6 or later */

     X_SHORT     sBifArgCount;                           /* Vers V7 or later */
     X_SHORT     sBifRetCount;                           /* Vers V7 or later */
     X_BOOL      fBifShutDown;                           /* Vers V7 or later */

     X_ULONG     ulFunctionInstanceId;                   /* Vers V8 or later */
     X_ULONG     ulRememberCount;                        /* Vers V8 or later */
     X_DEFS_FLD_SHORT_PTR psRememberVectors;             /* Vers V8 or later */
     X_DEFS_FLD_SHORT_PTR psRememberFormats;             /* Vers V8 or later */

     X_DEFS_FLD_SHORT_PTR psSortedX_FldVectors;          /* Vers V9 or later */

     X_SHORT     sWebPageNumber;                         /* Vers V10 or later */
     X_BOOL      fWebEvent;                              /* Vers V10 or later */

     X_SHORT     sWebTextOffset;                         /* Vers V11 or later */
     X_BOOL      fAddPanelTitleAsWebText;                /* Vers V11 or later */

     X_BOOL      fWebPanelHasDescription;                /* Vers V12 or later */

     X_PPVCHAR   pWebTextTags;                           /* Vers V13 or later */
     X_LONG      lWebTextTagsLimit;                      /* Vers V13 or later */

     XFUNCTIONSTATE    bFunctionState; /* 32 bit mask */ /* Vers V14 or later */

     X_DEFS_FLD_SHORT_PTR           psArrayVectorBounds; /* Vers V15 or later */
     
     X_SHORT                        scRenames;           /* Vers V16 or later */
     PX_FUN_RENAMES                 pRenames;            /* Vers V16 or later */

     PX_FUN_ALTNAME_TABLE           pAltNameTable;       /* Vers V19 or later */

     void *      pvFunctionInstanceId;                   /* Vers V20 or later */
  }
#if defined(X_OPERATING_SYSTEM_IOS)
     __attribute__((packed)) // [Danny 26/06/2013] This needs more investigation, we needed it for the IOS POC
#endif
;

/* ================================================================= */
/*  X_Bif : LANSA/X Built in Function Definition                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* sUID            Unique identifier                                 */
/* chReturnCode    Return code                                       */
/* ShutDown        Shutdown flag                                     */

struct X_BIF
  {
     X_SHORT         sUID;
     X_YES_NO        chReturnCode;
     X_YES_NO        chShutDown;
  } ;

/* ================================================================= */
/*  X_Cond : Condition State                                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* chTrue          Condition is true or not.                         */

struct X_COND
   {
      X_YES_NO    chTrue;
   };

/* ================================================================= */
/*  X_Error : Error Definition Block                                 */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* State           Error State of associated field                   */

struct X_ERROR
  {
     X_CHAR        chState;
  };

/* ================================================================= */
/*  X_LMap  : List definition Map                                    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* vFld            Vector of field in the X_FLD area                 */
/* vFldPanel       Vector of field in the X_PANEL_FLD area           */

struct X_LMAP
  {
     X_SHORT       svX_Fld;
     X_SHORT       svX_Panel_Fld;
  };



/* ================================================================= */
/*  X_LIST_OPERATION_TABLE : Runtime binding for WL operations       */
/* ================================================================= */

#if defined(X_OPERATING_SYSTEM_UNIX)

   typedef X_VOID_FUNCTION X_Add_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_YES_NO, X_YES_NO, X_CHAR, X_YES_NO );
   typedef X_VOID_FUNCTION X_Dlt_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_LIST_COUNT, PX_LIST_VOID, X_SHORT, X_PLONG );
   typedef X_VOID_FUNCTION X_Upd_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_CHAR, X_YES_NO );
   typedef X_VOID_FUNCTION X_Inz_Entries_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_YES_NO, X_YES_NO, X_SHORT, X_CHAR );
   typedef X_VOID_FUNCTION X_Store_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, X_SHORT, PX_LIST_VOID, X_LIST_COUNT, X_LIST_COUNT, X_LONG );
   typedef X_VOID_FUNCTION X_Drop_Entries_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_SHORT, PX_LIST_VOID, X_YES_NO );
   typedef X_CHAR_FUNCTION X_Get_Entry_Ext_Fcn(  struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_LIST_COUNT, X_YES_NO, X_YES_NO*, X_BOOL );
   typedef X_VOID_FUNCTION X_Assemble_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_SHORT, PX_LIST_VOID, X_YES_NO, X_CHAR, X_BOOL );
   typedef X_CHAR_FUNCTION X_Retrieve_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, X_SHORT, PX_LIST_VOID, X_LIST_COUNT );
   typedef X_VOID_FUNCTION X_Add_Entry_After_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_YES_NO, X_YES_NO, X_CHAR, X_YES_NO, X_LONG, X_PLONG );
   typedef X_VOID_FUNCTION X_Shuffle_Entries_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, PX_LIST_VOID, X_LIST_COUNT, X_LIST_COUNT, X_SHORT );
   typedef X_CHAR_FUNCTION X_DisAssemble_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_SHORT, PX_LIST_VOID, X_YES_NO*, X_YES_NO*, X_YES_NO );

#else

   typedef X_VOID_FUNCTION __cdecl X_Add_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_YES_NO, X_YES_NO, X_CHAR, X_YES_NO );
   typedef X_VOID_FUNCTION __cdecl X_Dlt_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_LIST_COUNT, PX_LIST_VOID, X_SHORT, X_PLONG );
   typedef X_VOID_FUNCTION __cdecl X_Upd_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_CHAR, X_YES_NO );
   typedef X_VOID_FUNCTION __cdecl X_Inz_Entries_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_YES_NO, X_YES_NO, X_SHORT, X_CHAR );
   typedef X_VOID_FUNCTION __cdecl X_Store_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, X_SHORT, PX_LIST_VOID, X_LIST_COUNT, X_LIST_COUNT, X_LONG );
   typedef X_VOID_FUNCTION __cdecl X_Drop_Entries_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_SHORT, PX_LIST_VOID, X_YES_NO );
   typedef X_CHAR_FUNCTION __cdecl X_Get_Entry_Ext_Fcn(  struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_LIST_COUNT, X_YES_NO, X_YES_NO*, X_BOOL );
   typedef X_VOID_FUNCTION __cdecl X_Assemble_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_SHORT, PX_LIST_VOID, X_YES_NO, X_CHAR, X_BOOL );
   typedef X_CHAR_FUNCTION __cdecl X_Retrieve_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, X_SHORT, PX_LIST_VOID, X_LIST_COUNT );
   typedef X_VOID_FUNCTION __cdecl X_Add_Entry_After_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], struct X_COND*, X_SHORT, PX_LIST_VOID, X_YES_NO, X_YES_NO, X_CHAR, X_YES_NO, X_LONG, X_PLONG );
   typedef X_VOID_FUNCTION __cdecl X_Shuffle_Entries_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, PX_LIST_VOID, X_LIST_COUNT, X_LIST_COUNT, X_SHORT );
   typedef X_CHAR_FUNCTION __cdecl X_DisAssemble_Entry_Fcn( struct X_IDS*, struct X_PRO*, struct X_FUN*, struct X_FLD[], X_SHORT, PX_LIST_VOID, X_YES_NO*, X_YES_NO*, X_YES_NO );

#endif

typedef struct _X_LIST_OPERATION_TABLE
{
   X_LIST_COUNT                                    lcPageTableCount;          /* X_FUN_V14_OR_LATER */
   X_LIST_COUNT                                    lcPageTableIncrement;      /* X_FUN_V14_OR_LATER */
   X_LIST_COUNT                                    lcEntriesPerPage;          /* X_FUN_V14_OR_LATER */
   X_LIST_COUNT                                    lcListMaxEntries;          /* X_FUN_V14_OR_LATER */
   X_ULONG                                         ulListDataPageSize;        /* X_FUN_V14_OR_LATER */
   struct X_PANEL_FLD                           *  pX_Panel_Fld;              /* X_FUN_V14_OR_LATER */
   X_Add_Entry_Fcn                              *  pfnAddEntry;               /* X_FUN_V14_OR_LATER */
   X_Dlt_Entry_Fcn                              *  pfnDltEntry;               /* X_FUN_V14_OR_LATER */
   X_Upd_Entry_Fcn                              *  pfnUpdEntry;               /* X_FUN_V14_OR_LATER */
   X_Inz_Entries_Fcn                            *  pfnInzEntries;             /* X_FUN_V14_OR_LATER */
   X_Store_Entry_Fcn                            *  pfnStoreEntry;             /* X_FUN_V14_OR_LATER */
   X_Drop_Entries_Fcn                           *  pfnDropEntries;            /* X_FUN_V14_OR_LATER */
   X_Get_Entry_Ext_Fcn                          *  pfnGetEntryExt;            /* X_FUN_V14_OR_LATER */
   X_Assemble_Entry_Fcn                         *  pfnAssembleEntry;          /* X_FUN_V14_OR_LATER */
   X_Retrieve_Entry_Fcn                         *  pfnRetrieveEntry;          /* X_FUN_V14_OR_LATER */
   X_Add_Entry_After_Fcn                        *  pfnAddEntryAfter;          /* X_FUN_V14_OR_LATER */
   X_Shuffle_Entries_Fcn                        *  pfnShuffleEntries;         /* X_FUN_V14_OR_LATER */
   X_DisAssemble_Entry_Fcn                      *  pfnDisAssembleEntry;       /* X_FUN_V14_OR_LATER */
}
   X_LIST_OPERATION_TABLE,
   *PX_LIST_OPERATION_TABLE,
   **PPX_LIST_OPERATION_TABLE;


/* ================================================================= */
/*  X_List : LANSA/X List Definition "Vector"                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            List Name                                         */
/* Type            Type (W=Working,B=Browse)                         */
/* EntryLength     Byte Length of complete a complete list entry     */
/* MaxEntrys       Maximum Allowable Entries                         */
/* CurrentEntrys   Current Number of Entries                         */
/* CurrentEntry    Current Entry Number                              */
/* sFld            Total Fields in Vector array of structures        */
/* pX_Fld          Pointer to Vector List array of structures        */
/* sCond           Total Conditions in array of structures           */
/* pX_Cond         Pointer to conditions                             */
/* pX_LMap         Pointer to list map                               */
/* PageSize        Page size for display                             */
/* Received        Received List                                     */
/* ChangeF         Change Fields are used in this list               */
/* vCounter        Vector Number of Count parameter                  */
/* vPageSize       Vector Number of Page Size parameter              */
/* vTopEntry       Vector Number of Top Entry parameter              */
/*                 NOTE : For componentized lists this value         */
/*                 ----   is reused for the list dispatch identifier */
/* vSelEntry       Vector Number of Selected Entry parameter         */
/* vScrollTxt      Vector Number of Scroll Text parameter            */
/* vSelectField    Vector Number of *SELECT field in this list       */
/* CurrentEntry    Pointer to current entry storage area             */
/* EntryStorage    Pointer to storage area for all entries           */
/* pX_Panel_Fld    Pointer to X_PANEL_FLD area                       */
/* Screening       Screening of selected entries required            */
/* OSelected       Include only selected entries                     */
/* OAltered        Include only altered entries                      */
/* ONotNull        Include only not-null entries                     */
/* ODisplay        Include only display mode entries                 */
/* OAdd            Include only add mode entries                     */
/* OChange         Include only change mode entries                  */
/* ODelete         Include only delete mode entries                  */


/* Allowable Values for chType */

#define X_BROWSE_LIST       'B'
#define X_WORKING_LIST      'W'
#define X_COMPONENT_LIST    'C'

/* Allowable values for chReceived */

#define X_NOT_RECEIVED      NO
#define X_RECEIVED_NORMAL   YES
#define X_RECEIVED_BIF_ARG  'A'
#define X_RETURNED_BIF_VAL  'R'


#define X_COMPONENT_LIST_NA -1L

/* *********************************************************************** */
/* LL1 Generated code still uses X_LIST so generated code has no changes   */
/* Thus it should windiff without differences.                             */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* NEVER use this structure anywhere but LL1 generated code!               */
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* *********************************************************************** */

/* Comment out the #if(0) for old 10.0 structure support */
#if(0)
/* Temporarily make it work the old way */
#ifndef X_ALLOW_10_0_STRUCTURES
#define X_ALLOW_10_0_STRUCTURES
#endif
#endif

#ifdef X_ALLOW_10_0_STRUCTURES

/* ------------------------------------------------------------------------- */
/* Note that this structure is not defined in the runtime, yet it is allowed */
/* to be used as a pointer in function declarations and prototypes. This is  */
/* a Messysoft feature that can be switched to ANSI standard, but Windows'   */
/* header files then fail to compile! ... /Za switch.                        */
/* Given that the first reference to the parameter in the body that requires */
/* a type will give a zero length error or similar. Its not a problem, just  */
/* confusing as to why it compiles at all - until you read this!             */
/* ------------------------------------------------------------------------- */
struct X_LIST
  {
     X_VCHAR         vchName[X_OBJECT_NAME_LEN+1];
     X_TYPE_FLAG     chType;
     X_SHORT         sEntryLength;
     X_SHORT         sMaxEntrys;
     X_SHORT         sCurrentEntrys;
     X_SHORT         sCurrentEntry;
     X_SHORT         sFld;
     struct X_FLD   *pX_Fld;
     X_SHORT         sCond;
     struct X_COND  *pX_Cond;
     struct X_LMAP  *pX_LMap;
     X_SHORT         sPageSize;
     X_YES_NO        chReceived;
     X_YES_NO        chChangeF;
     X_SHORT         svCounter;
     X_SHORT         svPageSize;
     X_SHORT         svTopEntry;
     X_SHORT         svSelEntry;
     X_SHORT         svScrollTxt;
     X_SHORT         svSelectField;
     X_PVOID         pCurrentEntry;
     X_PVOID         pEntryStorage;
     union
     {
        struct X_PANEL_FLD       *pX_Panel_Fld;
        X_LIST_OPERATION_TABLE   *pOperationTable;
     };
     X_YES_NO        chScreening;
     X_YES_NO        chOSelected;
     X_YES_NO        chOAltered;
     X_YES_NO        chONotNull;
     X_YES_NO        chODisplay;
     X_YES_NO        chOAdd;
     X_YES_NO        chOChange;
     X_YES_NO        chODelete;
  };

#else

/* Dummy structure so that UNIX compiles OK but elements are not accessed through */
/* X_LIST variables without a cast to X_LIST_1 or X_LIST_2                        */
struct X_LIST
  {
     X_SHORT         sDummy;
  };

#endif

/* This is the same memory structure as X_LIST, but it uses different names */
/* for 6 of the elements - all with '1' on the end.                         */
typedef struct _LIST_1
  {
     X_VCHAR         vchName[X_OBJECT_NAME_LEN+1];
     X_TYPE_FLAG     chType;

     X_SHORT         sEntryLength1;    /* -1 for V2 lists and later*/
     X_SHORT         sMaxEntrys1;
     X_SHORT         sCountEntrys1;    /* was sCurrentEntrys */
     X_SHORT         sCurrentEntry1;

     X_SHORT         sFld;
     struct X_FLD   *pX_Fld;
     X_SHORT         sCond;
     struct X_COND  *pX_Cond;
     struct X_LMAP  *pX_LMap;
     X_SHORT         sPageSize;
     X_YES_NO        chReceived;
     X_YES_NO        chChangeF;
     X_SHORT         svCounter;
     X_SHORT         svPageSize;
     X_SHORT         svTopEntry;
     X_SHORT         svSelEntry;
     X_SHORT         svScrollTxt;
     X_SHORT         svSelectField;

     X_PVOID         pCurrentEntry1;
     X_PVOID         pEntryStorage1;
     union
     {
        struct X_PANEL_FLD       *pX_Panel_Fld;
        X_LIST_OPERATION_TABLE   *pOperationTable;
     };
     X_YES_NO        chScreening;
     X_YES_NO        chOSelected;
     X_YES_NO        chOAltered;
     X_YES_NO        chONotNull;
     X_YES_NO        chODisplay;
     X_YES_NO        chOAdd;
     X_YES_NO        chOChange;
     X_YES_NO        chODelete;
} X_LIST_1, * PX_LIST_1, ** PPX_LIST_1;

/* Note that all access to pX_List is cast until the structure type is known, even X_LIST_1 */
/* When it is known that it is of a specific structure (rare) it is NOT cast, so that at least compile errors can be located.  */

#define X_LIST_V2            (-2)
#define X_LIST_V2_OR_LATER( _plist )   (((struct X_LIST_1) _plist)->sEntryLength1 == -1 && ((struct X_LIST_2) _plist)->sX_ListVersion <= X_LIST_V2)

#define X_DECLARE_WORK_LISTS \
   PX_LIST_1     pList_1 = (PX_LIST_1)pX_NULL; \
   PX_LIST_2     pList_2 = (PX_LIST_2)pX_NULL;

/* Used to replace &(X_List[sListNo]) in struct  X_LIST * pList = &(X_List[sListNo]);*/
/* The returned pointer can be used as either an X_LIST_1 or an X_LIST_2, provided   */
/* access to X_LIST_2 elements use the above macros.                                 */

#define X_CAST_LIST_FROM_NO( _X_List, _sListNo, _pX_Fun ) \
   if ( X_RDML2_IS_USED( _pX_Fun ) ) \
   { \
      pList_1 = (PX_LIST_1)&(((PX_LIST_2)_X_List)[_sListNo]); \
      pList_2 =            &(((PX_LIST_2)_X_List)[_sListNo]); \
   } \
   else \
   { \
      pList_1 =            &(((PX_LIST_1)_X_List)[_sListNo]); \
      pList_2 = (PX_LIST_2)&(((PX_LIST_1)_X_List)[_sListNo]); \
   }

/* Similar to X_CAST_LIST_FROM_NO. Steps through the array using  */
/* appropriate type and then sets the other pointer to the same   */
/* value.                                                         */
#define X_INC_LIST_PTR( _pX_Fun ) \
   if ( X_RDML2_IS_USED( _pX_Fun ) ) \
   { \
      pList_2++; \
      pList_1 = (PX_LIST_1)pList_2; \
   } \
   else \
   { \
      pList_1++; \
      pList_2 = (PX_LIST_2)pList_1; \
   }

#define X_CAST_LIST( _X_List ) \
   pList_2 = (PX_LIST_2)_X_List; \
   pList_1 = (PX_LIST_1)_X_List;

/* This macro is not valid in an LL1 object.
   This code in fun00001.s ensures that use of the
   macro will fail to compile:
%%IF_LANGUAGE_LEVEL_TWO
%%ELSE
#if !defined(X_ALLOW_10_0_STRUCTURES)
#define X_ALLOW_10_0_STRUCTURES
#undef PX_LIST_1
#undef PX_LIST_2
#undef X_LIST_1
#undef X_LIST_2
#endif
%%ENDIF
*/
/* So, only use it in generated code. */
/* This macro relies on the list of lists being LL2 in an LL2 'Function' */
/* The list is located using LL2 array offsets, then finally cast to the */
/* actual list type before accessing the element. LL1 lists need the     */
/* extra cast to LL1 before accessing the element.                       */
/* c.f. X_CAST_LIST_FROM_NO above => the logic below is when the 'if' is */
/* TRUE.                                                                 */
#define X_LIST_ELEMENT_FROM_NO( _X_List, _sListNo, _element ) \
   ( ((PX_LIST_2)(_X_List))[_sListNo].sEntryLength1 == -1 \
      ? \
                    (&(((PX_LIST_2)(_X_List))[_sListNo]))->_element \
      : \
         ((PX_LIST_1)&(((PX_LIST_2)(_X_List))[_sListNo]))->_element \
   )

/* -------------------------------------------------------------------------*/
/* A note about the macros that use the "?...:" syntax and level 4 warnings */
/* MSVC thinks the result of the entire macro is an integer, no matter what */
/* the  variable's type is. The only solution is to cast the entire result, */
/* but that requires the two results to be the same, which they generally   */
/* are not, and where they are the same type, its a common macro used by    */
/* various variables and I'm not about to write an extra 30 macros to       */
/* appease Messysoft's interesting compiler!                                */
/* Upshot is that level 4 warnings have to be ignored.                      */
/* -------------------------------------------------------------------------*/
#define X_LIST_SIZE_OF_STRUC( _pX_Fun ) \
   ( X_RDML2_IS_USED( _pX_Fun ) \
      ? sizeof(X_LIST_2) \
      : sizeof(X_LIST_1) )

/* Return either pointer as they both reference the same memory address */
/* Required as use of this macro is often to test the pointer for null  */
/* hence the original code that tested pList_2->sEntryLength1 == -1   */
/* first was invalid.                                                   */
#define X_LIST_PTR \
   ( (PX_LIST_VOID)pList_2 )

#define X_LIST_PTR_ADDRESS \
   ( pList_2->sEntryLength1 == -1 \
      ? &((PX_LIST_VOID)pList_2)  \
      : &((PX_LIST_VOID)pList_1) )

#define X_LIST_TYPE() \
   ( pList_2->chType )

#define X_LIST_IS_LL2 \
   ( pList_2->sEntryLength1 == -1 )

#define X_LIST_COMMON_ELEMENT( _element ) \
   ( pList_2->sEntryLength1 == -1 \
      ? pList_2->_element \
      : pList_1->_element )

#define X_LIST_COMMON_ELEMENT_ADDRESS( _element ) \
   ( pList_2->sEntryLength1 == -1 \
      ? &(pList_2->_element) \
      : &(pList_1->_element) )

#define X_LIST_COMMON_ELEMENT_SIZEOF( _element ) \
   ( pList_2->sEntryLength1 == -1 \
      ? sizeof(pList_2->_element) \
      : sizeof(pList_1->_element) )

/* Entry Storage */
#define X_LIST_LIST_DATA \
   ( X_LIST_IS_LL2                  \
      ? ((struct X_LIST_DATA *)pList_2->pEntryStorage1) \
      : ((struct X_LIST_DATA *)pList_1->pEntryStorage1) )

/* ************************************************************************ */
/* Memory size of the pages of memory addressed by ListData.pEntryStorage1. */
/* ------------------------------------------------------------------------ */
/* For LL1 Working Lists:                                                   */
/*    - pList_1->sPageSize = number of entries in one page.                 */
/*    - SizeOfListDataPage is Page Size * Entry Length                      */
/* ------------------------------------------------------------------------ */
/* For LL2 Working Lists:                                                   */
/*    - pList_2->sPageSize = fixed number allocated at generate time (500)  */
/*    - SizeOfListDataPage is number of entries that fit in a max of 32K,   */
/*      unless one entry does not fit in 32 K, then it is one entry worth   */
/*    - Management of page table and SizeOfListDataPage is the same for all */
/*      LL2 Working Lists.                                                  */
/*    - SORT_LIST commands now supports multi-page sorting                  */
/* ************************************************************************ */

#define X_LIST_SIZE_OF_LIST_DATA_PAGE                                                                    \
   ( ( ( X_LIST_IS_LL2 ) && ( X_LIST_COMMON_ELEMENT(chType) == X_WORKING_LIST ) )                        \
      ? ( ( ( X_LIST_ENTRY_LENGTH * X_LIST_COMMON_ELEMENT(sPageSize) ) <= X_MAX_LIST_PAGE_MEMORY_SIZE )  \
          ? ( X_LIST_ENTRY_LENGTH * X_LIST_COMMON_ELEMENT(sPageSize) )                                   \
          : ( ( X_LIST_ENTRY_LENGTH > X_MAX_LIST_PAGE_MEMORY_SIZE )                                      \
              ? X_LIST_ENTRY_LENGTH                                                                      \
              : ( ( X_MAX_LIST_PAGE_MEMORY_SIZE / X_LIST_ENTRY_LENGTH ) * X_LIST_ENTRY_LENGTH ) ) )      \
      : ( X_LIST_COMMON_ELEMENT(sPageSize) * X_LIST_ENTRY_LENGTH ) )

/* ----------------------------------------------------------------- */
/* How many page pointers to incrementally add to Page Pointer array */
/* Only LL2 lists support partial page pointer allocation            */
/* Size is calculated to be driven by sPageSize. This defines the    */
/* number of entries that the page pointer list needs to support.    */
/* But, this may be specified as quite a small number so the minimum */
/* number of page pointers allocated is 256 (this is 1K on Windows)  */
/* On the other hand, there is no point allocating more than the     */
/* maximum number of entries in the list.                            */
/* Note that if entrys per page is 1 then use Max Entrys as adding 1 */
/* to *MAX gives a -ve number. This is close enough for these        */
/* purposes.                                                         */
/* ----------------------------------------------------------------- */

#define X_LIST_LIST_DATA_INCREMENT                                                                    \
      ( MIN( ( MAX( ( ( X_LIST_COMMON_ELEMENT(sPageSize) / X_LIST_ENTRYS_PER_PAGE ) + 1 ), 256 ) ),   \
             ( X_LIST_ENTRYS_PER_PAGE == 1 ? X_LIST_MAX_ENTRYS : ( ( X_LIST_MAX_ENTRYS / X_LIST_ENTRYS_PER_PAGE ) + 1 ) ) ) )

/* Number of entries stored in each memory page */
#define X_LIST_ENTRYS_PER_PAGE                                 \
   ( X_LIST_IS_LL2                                             \
      ? (X_LIST_SIZE_OF_LIST_DATA_PAGE / X_LIST_ENTRY_LENGTH ) \
      : pList_1->sPageSize )

/* Get the List Page number from the entry number. */
/* Number starts from 1.                           */
#define X_LIST_LIST_PAGE_FROM_ENTRY( _entry ) \
   ( ( (_entry - 1) / X_LIST_ENTRYS_PER_PAGE ) + 1 )

/* Entry Length */
#define X_LIST_ENTRY_LENGTH \
   ( pList_2->sEntryLength1 == -1 \
      ? pList_2->lcEntryLength \
      : pList_1->sEntryLength1 )

#define X_LIST_ENTRY_LENGTH_ADDRESS \
   ( pList_2->sEntryLength1 == -1 \
      ? (void *)&(pList_2->lcEntryLength) \
      : (void *)&(pList_1->sEntryLength1) )

#define X_LIST_ENTRY_LENGTH_SIZEOF \
   ( pList_2->sEntryLength1 == -1 \
      ? sizeof(pList_2->lcEntryLength) \
      : sizeof(pList_1->sEntryLength1) )

/* Max Entrys */
#define X_LIST_MAX_ENTRYS \
   ( pList_2->sEntryLength1 == -1 \
      ? pList_2->lcMaxEntrys \
      : pList_1->sMaxEntrys1 )

#define X_LIST_MAX_ENTRYS_ADDRESS \
   ( pList_2->sEntryLength1 == -1 \
      ? (void *)&(pList_2->lcMaxEntrys) \
      : (void *)&(pList_1->sMaxEntrys1) )

#define X_LIST_MAX_ENTRYS_SIZEOF \
   ( pList_2->sEntryLength1 == -1 \
      ? sizeof(pList_2->lcMaxEntrys) \
      : sizeof(pList_1->sMaxEntrys1) )

/* CountEntrys */
#define X_LIST_COUNT_ENTRYS \
   ( pList_2->sEntryLength1 == -1 \
      ? pList_2->lcCountEntrys \
      : pList_1->sCountEntrys1 )

#define X_LIST_COUNT_ENTRYS_ADDRESS \
   ( pList_2->sEntryLength1 == -1 \
      ? (void *)&(pList_2->lcCountEntrys) \
      : (void *)&(pList_1->sCountEntrys1) )

#define X_LIST_COUNT_ENTRYS_SIZEOF \
   ( pList_2->sEntryLength1 == -1 \
      ? sizeof(pList_2->lcCountEntrys) \
      : sizeof(pList_1->sCountEntrys1) )

/* CurrentEntry */
#define X_LIST_CURRENT_ENTRY \
   ( pList_2->sEntryLength1 == -1 \
      ? pList_2->lcCurrentEntry \
      : pList_1->sCurrentEntry1 )

#define X_LIST_CURRENT_ENTRY_ADDRESS \
   ( pList_2->sEntryLength1 == -1 \
      ? (void *)&(pList_2->lcCurrentEntry) \
      : (void *)&(pList_1->sCurrentEntry1) )

#define X_LIST_CURRENT_ENTRY_SIZEOF \
   ( pList_2->sEntryLength1 == -1 \
      ? sizeof(pList_2->lcCurrentEntry) \
      : sizeof(pList_1->sCurrentEntry1) )

#define X_SET_LIST_COMMON_ELEMENT( _element, _var ) \
   if ( pList_2->sEntryLength1 == -1 ) \
   { \
      pList_2->_element = _var; \
   } \
   else \
   { \
      pList_1->_element = _var; \
   }

#define X_SET_LIST_ENTRY_LENGTH( _var ) \
   if ( pList_2->sEntryLength1 == -1 ) \
   { \
      pList_2->lcEntryLength = _var; \
   } \
   else \
   { \
      pList_1->sEntryLength1 = (X_SHORT)_var; \
   }

#define X_SET_LIST_MAX_ENTRYS( _var ) \
   if ( pList_2->sEntryLength1 == -1 ) \
   { \
      pList_2->lcMaxEntrys = _var; \
   } \
   else \
   { \
      pList_1->sMaxEntrys1 = (X_SHORT)_var; \
   }

#define X_SET_LIST_COUNT_ENTRYS( _var ) \
   if ( pList_2->sEntryLength1 == -1 ) \
   { \
      pList_2->lcCountEntrys = _var; \
   } \
   else \
   { \
      pList_1->sCountEntrys1 = (X_SHORT)_var; \
   }

#define X_SET_LIST_CURRENT_ENTRY( _var ) \
   if ( pList_2->sEntryLength1 == -1 ) \
   { \
      pList_2->lcCurrentEntry = _var; \
   } \
   else \
   { \
      pList_1->sCurrentEntry1 = (X_SHORT)_var; \
   }

/* ----------------- */
/* Named list macros */
/* ----------------- */
#define X_DECLARE_NAMED_WORK_LISTS( _name ) \
   PX_LIST_1     _name##_1 = pX_NULL; \
   PX_LIST_2     _name##_2 = pX_NULL;

#define X_CAST_NAMED_LIST_FROM_NO( _name, _X_List, _sListNo, _pX_Fun ) \
   if ( X_RDML2_IS_USED( _pX_Fun ) ) \
   { \
      _name##_1 = (PX_LIST_1)&(((PX_LIST_2)_X_List)[_sListNo]); \
      _name##_2 = &(((PX_LIST_2)_X_List)[_sListNo]); \
   } \
   else \
   { \
      _name##_1 = &(((PX_LIST_1)_X_List)[_sListNo]); \
      _name##_2 = (PX_LIST_2)&(((PX_LIST_1)_X_List)[_sListNo]); \
   }

#define X_INC_NAMED_LIST_PTR( _name, _pX_Fun ) \
   if ( X_RDML2_IS_USED( _pX_Fun ) ) \
   { \
      _name##_2++; \
      _name##_1 = (PX_LIST_1)_name##_2; \
   } \
   else \
   { \
      _name##_1++; \
      _name##_2 = (PX_LIST_2)_name##_1; \
   }

/* This can only be applied to lists that are guaranteed to only contain LL1 lists */
/* To my knowledge, that only occurs when initialising the list of lists from a    */
/* list of LL1 lists and a list of LL2 lists. The _X_List must be declared as an   */
/* LL1 list.                                                                       */
/* There is a compile warning if this is not the case, but a runtime error has     */
/* been put in to make sure that its trapped somewhere.                            */

#define X_CAST_NAMED_LL1_LIST_FROM_NO( _name, _X_List, _sListNo ) \
   if ( pX_Fun->sX_FunVersion >= X_FUN_V13 || (X_FUN_V14_OR_LATER && _X_List->sEntryLength1 != -1)) \
   { \
      _name##_1 = &(_X_List[_sListNo]); \
      _name##_2 = (PX_LIST_2)&(_X_List[_sListNo]); \
   } \
   else \
   { \
      X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, TRACE_FUNCTION, "Internal error. Macro X_CAST_NAMED_LL1_LIST_FROM_NO failed"); \
   }

/* Comments same as X_CAST_NAMED_LL1_LIST_FROM_NO, except _X_List must be an LL2 list */
#define X_CAST_NAMED_LL2_LIST_FROM_NO( _name, _X_List, _sListNo ) \
   if ( X_FUN_V14_OR_LATER && _X_List->sEntryLength1 == -1 ) \
   { \
      _name##_1 = (PX_LIST_1)&(_X_List[_sListNo]); \
      _name##_2 = &(_X_List[_sListNo]); \
   } \
   else \
   { \
      X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, TRACE_FUNCTION, "Internal error. Macro X_CAST_NAMED_LL2_LIST_FROM_NO failed"); \
   }

#define X_CAST_NAMED_LIST( _name, _X_List ) \
   _name##_2 = (PX_LIST_2)(_X_List); \
   _name##_1 = (PX_LIST_1)(_X_List);

/* Return either pointer as they both reference the same memory address */
/* Required as use of this macro is often to test the pointer for null  */
/* hence the original code that tested _name##_2->sEntryLength1 == -1   */
/* first was invalid.                                                   */
#define X_NAMED_LIST_PTR( _name ) \
   ( (PX_LIST_VOID)_name##_2 )

#define X_NAMED_LIST_IS_LL2( _name ) \
   ( _name##_2->sEntryLength1 == -1 )

#define X_NAMED_LIST_SIZE_OF_LIST_DATA_PAGE( _name )                                                                 \
   ( X_NAMED_LIST_IS_LL2( _name ) && X_NAMED_LIST_COMMON_ELEMENT(_name,chType) == X_WORKING_LIST                                 \
      ? ( X_NAMED_LIST_MAX_ENTRYS( _name ) != X_MAX_ENTRIES                                                          \
          ?  X_NAMED_LIST_MAX_ENTRYS( _name ) * X_NAMED_LIST_ENTRY_LENGTH( _name )                                                  \
          : ( X_NAMED_LIST_ENTRY_LENGTH( _name ) * X_NAMED_LIST_COMMON_ELEMENT(_name,sPageSize) <= X_MAX_LIST_PAGE_MEMORY_SIZE   \
              ? X_NAMED_LIST_ENTRY_LENGTH( _name ) * X_NAMED_LIST_COMMON_ELEMENT(_name,sPageSize)                                \
              : ( X_NAMED_LIST_ENTRY_LENGTH( _name ) > X_MAX_LIST_PAGE_MEMORY_SIZE                                   \
                  ? X_NAMED_LIST_ENTRY_LENGTH( _name )                                                               \
                  : (X_MAX_LIST_PAGE_MEMORY_SIZE / X_NAMED_LIST_ENTRY_LENGTH(_name) ) * X_NAMED_LIST_ENTRY_LENGTH(_name) ) ) )  \
      : ( X_NAMED_LIST_COMMON_ELEMENT(_name, sPageSize) * X_NAMED_LIST_ENTRY_LENGTH( _name ) ) )

#define X_NAMED_LIST_LIST_DATA_INCREMENT( _name )                                                                    \
      ( MIN( ( MAX( ( ( X_NAMED_LIST_COMMON_ELEMENT(_name, sPageSize) / X_NAMED_LIST_ENTRYS_PER_PAGE( _name ) ) + 1 ), 256 ) ),   \
             ( X_NAMED_LIST_ENTRYS_PER_PAGE( _name ) == 1 ? X_NAMED_LIST_MAX_ENTRYS(_name) : ( ( X_NAMED_LIST_MAX_ENTRYS( _name ) / X_NAMED_LIST_ENTRYS_PER_PAGE( _name ) ) + 1 ) ) ) )

#define X_NAMED_LIST_ENTRYS_PER_PAGE( _name )                                 \
   ( X_NAMED_LIST_IS_LL2( _name )                                             \
      ? (X_NAMED_LIST_SIZE_OF_LIST_DATA_PAGE( _name ) / X_NAMED_LIST_ENTRY_LENGTH( _name ) ) \
      : _name##_1->sPageSize )

#define X_NAMED_LIST_LIST_PAGE_FROM_ENTRY( _name, _entry ) \
   ( ( (_entry - 1) / X_NAMED_LIST_ENTRYS_PER_PAGE( _name ) ) + 1 )

#define X_NAMED_LIST_COMMON_ELEMENT( _name, _element ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? _name##_2->_element \
      : _name##_1->_element )

#define X_NAMED_LIST_COMMON_ELEMENT_ADDRESS( _name, _element ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? &(_name##_2->_element) \
      : &(_name##_1->_element) )

#define X_NAMED_LIST_COMMON_ELEMENT_SIZEOF( _name, _element ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? sizeof(_name##_2->_element) \
      : sizeof(_name##_1->_element) )

#define X_NAMED_LIST_ENTRY_LENGTH( _name ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? _name##_2->lcEntryLength \
      : _name##_1->sEntryLength1 )

#define X_NAMED_LIST_MAX_ENTRYS( _name ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? _name##_2->lcMaxEntrys \
      : _name##_1->sMaxEntrys1 )

#define X_NAMED_LIST_COUNT_ENTRYS( _name ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? _name##_2->lcCountEntrys \
      : _name##_1->sCountEntrys1 )

#define X_NAMED_LIST_CURRENT_ENTRY( _name ) \
   ( _name##_2->sEntryLength1 == -1 \
      ? _name##_2->lcCurrentEntry \
      : _name##_1->sCurrentEntry1 )

#define X_SET_NAMED_LIST_COMMON_ELEMENT( _name, _element, _var ) \
   if ( _name##_2->sEntryLength1 == -1 ) \
   { \
      _name##_2->_element = _var; \
   } \
   else \
   { \
      _name##_1->_element = _var; \
   }

#define X_SET_NAMED_LIST_ENTRY_LENGTH( _name, _var ) \
   if ( _name##_2->sEntryLength1 == -1 ) \
   { \
      _name##_2->lcEntryLength = _var; \
   } \
   else \
   { \
      _name##_1->sEntryLength1 = (X_SHORT)_var; \
   }

#define X_SET_NAMED_LIST_MAX_ENTRYS( _name, _var ) \
   if ( _name##_2->sEntryLength1 == -1 ) \
   { \
      _name##_2->lcMaxEntrys = _var; \
   } \
   else \
   { \
      _name##_1->sMaxEntrys1 = (X_SHORT)_var; \
   }

#define X_SET_NAMED_LIST_COUNT_ENTRYS( _name, _var ) \
   if ( _name##_2->sEntryLength1 == -1 ) \
   { \
      _name##_2->lcCountEntrys = _var; \
   } \
   else \
   { \
      _name##_1->sCountEntrys1 = (X_SHORT)_var; \
   }

#define X_SET_NAMED_LIST_CURRENT_ENTRY( _name, _var ) \
   if ( _name##_2->sEntryLength1 == -1 ) \
   { \
      _name##_2->lcCurrentEntry = _var; \
   } \
   else \
   { \
      _name##_1->sCurrentEntry1 = (X_SHORT)_var; \
   }

#define X_DEFAULT_LL2_PAGE_SIZE   500     /* Number of entries to allocate page pointers for */
#define X_MAX_PAGE_SIZE           32767   /* Page Size is a short so this is the maximum     */
#define X_MAX_ENTRIES   X_LONG_HIVAL

/* This value should probably vary for each platform. 32 kb is the size of */
/* memory page on 32-bit windows. Reduce this by 100 bytes to allow for    */
/* overhead when allocating memory.                                        */
#define X_MAX_LIST_PAGE_MEMORY_SIZE            (0x7FFF - 100)

typedef struct _LIST_2
  {
     X_VCHAR         vchName[X_OBJECT_NAME_LEN+1];
     X_TYPE_FLAG     chType;
     X_SHORT         sEntryLength1;    /* -1 for V2 lists and later*/
     X_LIST_COUNT    lcEntryLength;
     X_LIST_COUNT    lcMaxEntrys;
     X_LIST_COUNT    lcCountEntrys;
     X_LIST_COUNT    lcCurrentEntry;
     X_SHORT         sFld;
     struct X_FLD   *pX_Fld;
     X_SHORT         sCond;
     struct X_COND  *pX_Cond;
     struct X_LMAP  *pX_LMap;
     X_SHORT         sPageSize;
     X_YES_NO        chReceived;
     X_YES_NO        chChangeF;
     X_SHORT         svCounter;
     X_SHORT         svPageSize;
     X_SHORT         svTopEntry;
     X_SHORT         svSelEntry;
     X_SHORT         svScrollTxt;
     X_SHORT         svSelectField;
     X_PVOID         pCurrentEntry1;
     X_PVOID         pEntryStorage1;
     union
     {
        struct X_PANEL_FLD       *pX_Panel_Fld;
        X_LIST_OPERATION_TABLE   *pOperationTable;
     };
     X_YES_NO        chScreening;
     X_YES_NO        chOSelected;
     X_YES_NO        chOAltered;
     X_YES_NO        chONotNull;
     X_YES_NO        chODisplay;
     X_YES_NO        chOAdd;
     X_YES_NO        chOChange;
     X_YES_NO        chODelete;
     X_SHORT         sX_ListVersion;   /* Set to X_LIST_V2 */
   } X_LIST_2,* PX_LIST_2,** PPX_LIST_2;


/* Component list type */
typedef X_LIST_2 X_LIST_COMP;

/* ================================================================= */
/*  X_FLD_PACKED_STRUCTURE_ALIGNMENT :                               */
/* ================================================================= */

#ifdef X_OPERATING_SYSTEM_ISERIES
   #define X_FLD_PACKED_STRUCTURE_ALIGNMENT( _X_Fld, _f ) \
           ( X_VECTOR_STORED_AS_CHAR(   _X_Fld, _f ) ? 16 : \
             X_VECTOR_STORED_AS_BINARY( _X_Fld, _f ) ? 16 : \
                           1 )
#else
   #define X_FLD_PACKED_STRUCTURE_ALIGNMENT( _X_Fld, _f ) 1
#endif

/* ================================================================ */
/* Macro       : X_GET_USED_BYTE_LEN_IN_PACKED                      */
/* Description : TN: Calculate the number of used bytes for a PACKED*/
/*               except the sign. The result bases on the number of */
/*               digits in the PACKED.                              */
/* Arguments   : _L [i]  = Total number of digits in packed data    */
/*               _B [out]= Number of used bytes                     */
/* ================================================================ */
#define X_GET_USED_BYTE_LEN_IN_PACKED(_B, _L) \
{ \
   X_SHORT sLen = (X_SHORT)(_L); \
   if (sLen % 2 == 0) \
   { \
      sLen++; \
   } \
   (_B) = (sLen + 1)/2; \
}

/* ================================================================  */
/* Macro       : X_GET_FIELD_VALUE_MAX_SIZE_WIDECHAR                 */
/* Description : Same as X_GET_FIELD_VALUE_MAX_SIZE except for       */
/*               X_FLD_CHAR with WideChar - value returnes is max    */
/*               bytes when stored as Widechar (not multibyte as     */
/*               per standard routine                                */
/* ================================================================  */
#define X_GET_FIELD_VALUE_MAX_SIZE_WIDECHAR(_SZ, _PTR , _FLD) \
{ \
   if ((X_VECTOR_FIELD_IS_CHAR((_FLD), 0) ) || (X_COMPONENT_FIELD_IS_CHAR((_FLD), 0))) \
   { \
      if ( X_FLD_CHAR_HAS_WIDECHAR(_PTR) ) \
      { \
         (_SZ) = ((PX_FLD_NCHAR)(_PTR))->ulMaxChars * 2; \
      } \
      else \
      { \
         X_GET_FIELD_VALUE_MAX_SIZE(_SZ, _PTR , _FLD) \
      } \
   } \
   else \
   { \
      X_GET_FIELD_VALUE_MAX_SIZE(_SZ, _PTR , _FLD) \
   } \
}

/* ================================================================  */
/* Macro       : X_GET_FIELD_VALUE_MAX_SIZE                          */
/* Description : Get the size (in bytes )of the data of a field,     */
/*             the field can be LL1 or LL2                           */
/*             If the field is LL1 it is just a copy of the old      */
/*             sByteLen                                              */
/*             TN: For PACKED and SIGNED this macro will give back   */
/*             the max number of bytes that MAY be used by the field's */
/*             data not the max number of bytes ALLOCATED for the    */
/*             data.                                                 */
/*                                                                   */
/* Arguments   : _FLD[in] = pointer to field vector                  */
/*               _PTR[in] = the pField of the field                  */
/*               (Always use  X_GET_INDEX_DIRECT or X_GET_INDEX to   */
/*                get this pointer                                   */
/*               we cannot use  _FLD->pFieldExt or _FLD->pField because */
/*               the _FLD may be an array element so the pField or   */
/*               pFieldExt will point to another vector (index vector) */
/*               _SZ = size of the data ( should be X_ULONG type )   */
/* ================================================================  */

#ifdef X_OPERATING_TARGET_CSHARP

#define X_GET_FIELD_VALUE_MAX_SIZE(_SZ, _PTR , _FLD)                          \
{                                                                             \
   if (X_VECTOR_FIELD_IS_LL2(_FLD, 0) )                                       \
   {                                                                          \
      if ( X_VECTOR_STORED_AS_X_VAR(_FLD, 0) )                                \
      {                                                                       \
         _SZ = (int)((X_FLD_CHAR)(_PTR.X_FLD.pField))->ulMaxSize;             \
      }                                                                       \
      else if ( X_VECTOR_STORED_AS_SHORT_CHAR(_FLD,0) )                       \
      {                                                                       \
         _SZ = _FLD[0]->sLen;                                                 \
      }                                                                       \
      else if ( X_VECTOR_STORED_AS_DATE(_FLD, 0) )                            \
      {                                                                       \
         /* TN : DATETIME, DATE, TIME are NULL terminated */                  \
         /* so the effective length will be actual length -1 */               \
         _SZ = X_MAX_SIZE_DATE_LEN - 1;                                       \
      }                                                                       \
      else if ( X_VECTOR_STORED_AS_TIME(_FLD, 0) )                            \
      {                                                                       \
         _SZ = X_MAX_SIZE_TIME_LEN - 1;                                       \
      }                                                                       \
      else if ( X_VECTOR_STORED_AS_DATETIME_ONLY(_FLD, 0) )                   \
      {                                                                       \
         _SZ = X_MAX_SIZE_DATETIME_LEN - 1;                                   \
      }                                                                       \
      else if ( X_VECTOR_STORED_AS_LOB(_FLD, 0) )                             \
      {                                                                       \
         _SZ = X_MAX_SIZE_LOB_FILE_NAME;                                      \
      }                                                                       \
      else if ((X_VECTOR_STORED_AS_SIGNED(_FLD,0)) || (X_VECTOR_STORED_AS_INTEGER(_FLD,0))) \
      {                                                                       \
         _SZ = _FLD[0]->sLen;                                                 \
      }                                                                       \
      else if (X_VECTOR_STORED_AS_PACKED(_FLD,0))                             \
      {                                                                       \
         X_GET_USED_BYTE_LEN_IN_PACKED( _SZ, _FLD[0]->sLen )                  \
      }                                                                       \
      else                                                                    \
      {                                                                       \
         _SZ = (int)(_FLD[0]->sByteLen ) ;                                    \
      }                                                                       \
   }                                                                          \
   else                                                                       \
   {                                                                          \
      /* The field is LL1*/                                                   \
      _SZ = (int)(_FLD[0]->sByteLen);                                         \
   }                                                                          \
}

#else

#define X_GET_FIELD_VALUE_MAX_SIZE(_SZ, _PTR , _FLD) \
{ \
   if (X_VECTOR_FIELD_IS_LL2((_FLD), 0) )\
   {   \
      if ( X_VECTOR_STORED_AS_X_VAR((_FLD), 0) )\
      {\
         (_SZ) = ((PX_FLD_CHAR)(_PTR))->ulMaxSize;\
      }\
      else if ( X_VECTOR_STORED_AS_SHORT_CHAR((_FLD),0) ) \
      {\
         (_SZ) = (_FLD)->sLen; \
      }\
      else if ( X_VECTOR_STORED_AS_DATE((_FLD), 0) ) \
      {\
         /* TN : DATETIME, DATE, TIME are NULL terminated */\
         /* so the effective length will be actual length -1 */\
         (_SZ) = X_MAX_SIZE_DATE_LEN - 1;\
      }\
      else if ( X_VECTOR_STORED_AS_TIME((_FLD), 0) ) \
      {\
         (_SZ) = X_MAX_SIZE_TIME_LEN - 1;\
      }\
      else if ( X_VECTOR_STORED_AS_DATETIME_ONLY((_FLD), 0) ) \
      {\
         (_SZ) = X_MAX_SIZE_DATETIME_LEN - 1;\
      }\
      else if ( X_VECTOR_STORED_AS_LOB((_FLD), 0) ) \
      {\
         (_SZ) = X_MAX_SIZE_LOB_FILE_NAME;\
      }\
      else if ((X_VECTOR_STORED_AS_SIGNED((_FLD),0)) || (X_VECTOR_STORED_AS_INTEGER((_FLD),0))) \
      {\
         (_SZ) = (_FLD)->sLen; \
      }\
      else if (X_VECTOR_STORED_AS_PACKED((_FLD),0)) \
      {\
         X_GET_USED_BYTE_LEN_IN_PACKED( (_SZ), (_FLD)->sLen ) \
      }\
      else \
      {\
         (_SZ) = (X_ULONG)((_FLD)->sByteLen - sizeof( X_FLD_INFO )) ; \
      }\
   }  \
   else \
   { \
      /* The field is LL1*/ \
      (_SZ) = (X_ULONG)((_FLD)->sByteLen); \
   }\
}

#endif // X_OPERATING_TARGET_CSHARP

/* ================================================================ */
/* Macro       : X_VARCHAR_INIT                                     */
/* Description : Initialise a X_FLD_CHAR structure                  */
/* Arguments     _PVARCHAR = pointer to the varchar structure       */
/* ================================================================ */
#define X_VARCHAR_INIT(_PVARCHAR )   \
{\
   memset( (_PVARCHAR), 0, sizeof( X_FLD_CHAR ));\
   ((X_FLD_CHAR*)(_PVARCHAR))->i8Version = X_FLDDATA_V1; \
   ((X_FLD_CHAR*)(_PVARCHAR))->ulMaxSize = X_MAX_CHAR_FIELD_LEN;\
}

/* ================================================================ */
/* Macro       : X_VARBINARY_INIT                                   */
/* Description : Initialise a X_FLD_BINARY structure                */
/* Arguments     _PVARBINARY = pointer to the varbinary structure   */
/* ================================================================ */
#define X_VARBINARY_INIT(_PVARBINARY )   \
{\
   memset( (_PVARBINARY), 0, sizeof( X_FLD_BINARY ));\
   ((X_FLD_BINARY*)(_PVARBINARY))->i8Version = X_FLDDATA_V1; \
   ((X_FLD_BINARY*)(_PVARBINARY))->ulMaxSize = X_MAX_BINARY_FIELD_LEN;\
}

/* ================================================================ */
/* Macro       : X_VARCHAR_UTF8_INIT                                */
/* Description : Initialise a X_FLD_CHAR structure that will contain*/
/* UTF-8. That is, it may be double the size of an MBCS vector      */
/* Arguments     _PVARCHAR = pointer to the varchar structure       */
/* ================================================================ */
#define X_VARCHAR_UTF8_INIT(_PVARCHAR )   \
{\
   memset( (_PVARCHAR), 0, sizeof( X_FLD_CHAR ));\
   ((X_FLD_CHAR*)(_PVARCHAR))->i8Version = X_FLDDATA_V1; \
   ((X_FLD_CHAR*)(_PVARCHAR))->ulMaxSize = X_MAX_CHAR_FIELD_LEN * 2;\
}

/* ================================================================ */
/* Macro       : X_WIDECHAR_INIT                                    */
/* Description : Initialise a X_FLD_NCHAR structure for Wide Chars  */
/* Arguments     _PWIDECHAR = pointer to the varchar structure      */
/* ================================================================ */
#define X_WIDECHAR_INIT(_PWIDECHAR )   \
{\
   memset( (_PWIDECHAR), 0, sizeof( X_FLD_NCHAR ));\
   ((X_FLD_NCHAR*)(_PWIDECHAR))->i8Version = X_FLDDATA_V2; \
   ((X_FLD_NCHAR*)(_PWIDECHAR))->bFieldState = FsHasWideCharData; \
   ((X_FLD_NCHAR*)(_PWIDECHAR))->ulMaxSize = X_MAX_WIDECHAR_MBCS_LEN( X_MAX_CHAR_FIELD_LEN );\
   ((X_FLD_NCHAR*)(_PWIDECHAR))->ulMaxChars = X_MAX_CHAR_FIELD_LEN;\
}

#ifdef X_VAR_SUPPORT
/* ================================================================ */
/* Macro       : X_VARCHAR_RELEASE                                  */
/* Description : RELEASE  a X_FLD_CHAR structure                    */
/*                                                                  */
/* Arguments    PXIDS,  standard system def. structure              */
/*              PXPRO,  standard process defn. structure            */
/*              PXFUN,  standard function defn. structure           */
/*              _PVARCHAR = pointer to the varchar structure        */
/* ================================================================ */
   #define X_VARCHAR_RELEASE(PXIDS, PXPRO, PXFUN, _PVARCHAR)\
   X_VAR_VarChar_Release((PXIDS), (PXPRO), (PXFUN), ((X_FLD_CHAR*)(_PVARCHAR)));
#else

   /* just a dummy */
   #define X_VARCHAR_RELEASE(PXIDS, PXPRO, PXFUN, _PVARCHAR)
#endif

#ifdef X_VAR_SUPPORT
/* ================================================================ */
/* Macro       : X_VARBINARY_RELEASE                                */
/* Description : RELEASE  a X_FLD_BINARY structure                  */
/*                                                                  */
/* Arguments    PXIDS,  standard system def. structure              */
/*              PXPRO,  standard process defn. structure            */
/*              PXFUN,  standard function defn. structure           */
/*              _PVARBINARY = pointer to the varbinary structure    */
/* ================================================================ */
   #define X_VARBINARY_RELEASE(PXIDS, PXPRO, PXFUN, _PVARBINARY)\
   X_VAR_VarBinary_Release ((PXIDS), (PXPRO), (PXFUN), ((X_FLD_BINARY*)(_PVARBINARY)));
#else

   /* just a dummy */
   #define X_VARBINARY_RELEASE(PXIDS, PXPRO, PXFUN, _PVARBINARY)
#endif
/* ================================================================= */
/*  X_UIM : LANSA/X User Interface Management Structure              */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* StructSize        Size of this structure                          */
/* pUIMData          Pointer to a structure containing internal UIM  */
/*                   information. Allocated by X_UIM_Manager when    */
/*                   X_UIM_ACTIVATE is requested.                    */
/* vchAID            Selected Function Key                           */
/* sMenuOpt          Selected Menu Option                            */
/* vchABOpt          Selected Action Bar Item                        */
/* vchPDOpt          Selected Pull Down Option                       */
/* svFocusField      Vector Number of current Field with Focus       */
/* seFocusEntry      Entry # of current List Entry with Focus        */
/* chPanelRedraw     Indicates what needs to be redrawn. See below.  */

                                                         /*  Redraw? */
#define X_REDRAW_ALL       'A'   /* All objects are indoubt. All     */
#define X_REDRAW_NONE      'N'   /* Nothing has changed.     Nothing */
#define X_REDRAW_CONTENTS  'C'   /* No objects changed.      Contents*/
#define X_REDRAW_ERRORS    'E'   /* Flag Errors only.        Colour  */

struct X_UIM
   {
      X_LONG         sStructSize;
      X_PVOID        pUIMData;
      X_VCHAR        vchAID[X_FKEY_AID_LEN + 1];
      X_SHORT        sMenuOpt;
      X_VCHAR        vchABOpt[X_ABOPT_PDOPT_LEN + 1];
      X_VCHAR        vchPDOpt[X_ABOPT_PDOPT_LEN + 1];
      X_SHORT        svFocusField;
      X_SHORT        seFocusEntry;
      X_TYPE_FLAG    chPanelRedraw;
   } ;


/* ================================================================= */
/*  X_LANG : Current Language List for a compiled process            */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* LangCode          Language Code                                   */
/* LangType          Language Type                                   */

struct X_LANG
{
   X_VCHAR       vchLangCode[X_LANGUAGE_CODE_LEN + 1];
   X_TYPE_FLAG   chLangType;

} ;

/* ================================================================= */
/*  X_MTXT : Multilingual Text string Initial Values                 */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* Value             Current Value of multilingual text string       */

struct X_MTXT
{
   X_PVCHAR      pvchValue;
} ;

/* ================================================================= */
/*  X_MFLD : Multilingual Field Definition structure                 */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* Label             Pointer to field's label                        */
/* ColHdg1           Pointer to field's column heading 1             */
/* ColHdg2           Pointer to field's column heading 2             */
/* ColHdg3           Pointer to field's column heading 3             */
/* Desc              Pointer to field's description                  */

struct X_MFLD
{
   X_PVCHAR      pvchLabel;
   X_PVCHAR      pvchColHdg1;
   X_PVCHAR      pvchColHdg2;
   X_PVCHAR      pvchColHdg3;
   X_PVCHAR      pvchDesc;
} ;

/* ================================================================= */
/*  X_PROTEXT : Process Textual Definition Block                     */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* LangNo            Language Number (ie: Offset in X_LANG)          */
/* Type              Type of Text string                             */
/* Ident1            Identifier 1 of this string                     */
/* Ident2            Identifier 2 of this string                     */
/* pText             Pointer to text string (may be NULL)            */

#define X_PROCESS_PROTEXT_PROCESS   1
#define X_PROCESS_PROTEXT_FUNTION   2
#define X_PROCESS_PROTEXT_ACTBAR    3
#define X_PROCESS_PROTEXT_PULLDOWN  4

struct X_PROTEXT
{
   X_SHORT      sLangNo;
   X_SHORT      sType;
   X_SHORT      sIdent1;
   X_SHORT      sIdent2;
   X_PVCHAR     pText;
} ;

/* ================================================================= */
/*  MESSAGE : A warning message                                      */
/* ================================================================= */

typedef struct _MESSAGE
   {
      X_LONG   lMsgId;
      X_SHORT  sXTEXTMsgId; /* Id of message for X_TEXT() macro */
   }
      MESSAGE, *PMESSAGE, **PPMESSAGE;


/* ================================================================= */
/*  X_Module_Binding : Generated code binding info                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* BindingState    State of binding. Initially zero                  */
/* ModuleIndex     Index of loaded module                            */
/* ProcedureIndex  Index of procedure to call                        */

#define X_MODULE_BINDING_OAM_UNBOUND               0
#define X_MODULE_BINDING_OAM_BOUND              1000

#define X_MODULE_BINDING_FUNCTION_UNBOUND         10
#define X_MODULE_BINDING_FUNCTION_BOUND         1010

typedef struct _X_Module_Binding
{
   X_LONG                     lBindingState;
   X_LONG                     lModuleIndex;
   X_LONG                     lProcedureIndex;
}
   X_Module_Binding,
   *pX_Module_Binding,
   **ppX_Module_Binding;


/* ================================================================= */
/*  X_DBM_WHERE : Standard DBM where structure definition            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Oper            Type of Operation required                        */
/* Field           Optional vector number of field involved          */

#define X_DBM_WHERE_OB         'A'
#define X_DBM_WHERE_CB         'B'
#define X_DBM_WHERE_AD         'C'
#define X_DBM_WHERE_SU         'D'
#define X_DBM_WHERE_MU         'E'
#define X_DBM_WHERE_DV         'F'
#define X_DBM_WHERE_EQ         'G'
#define X_DBM_WHERE_NE         'H'
#define X_DBM_WHERE_LT         'I'
#define X_DBM_WHERE_LE         'J'
#define X_DBM_WHERE_GT         'K'
#define X_DBM_WHERE_GE         'L'
#define X_DBM_WHERE_AN         'M'
#define X_DBM_WHERE_OR         'N'
#define X_DBM_WHERE_NAME       'O'
#define X_DBM_WHERE_VALUE      'P'
#define X_DBM_WHERE_SQLNULL    'Q'

struct X_DBM_WHERE
  {
     X_TYPE_FLAG chOper;
     X_SHORT     sField;
  };

/* ================================================================= */
/*  X_DBM_OPNQRYF : Open Query File Emulation Details                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* StructSize      Size of Structure                                 */
/* sQrysltVector   Vector number of QRYSLT parameter                 */
/* sKeyfldVector   Vector number of KEYFLD parameter                 */
/* vchAlwcpydta    ALWCPYDTA parameter                               */
/* vchOptimize     OPTIMIZE parameter                                */
/* vchSeqonly1     SEQONLY parameter part 1                          */
/* sSeqonly2       SEQONLY parameter part 2                          */
/* vchCommit       COMMIT parameter                                  */
/* vchType         TYPE parameter                                    */

#define X_ALWCPYDTA_LEN           4
#define X_OPTIMIZE_LEN            8
#define X_SEQONLY1_LEN            4
#define X_COMMIT_LEN              4
#define X_TYPE_LEN                8

#define X_DBM_OPNQRYF_SELECT_ALL -1
#define X_DBM_OPNQRYF_KEY_NONE   -1
#define X_DBM_OPNQRYF_KEY_FILE   -2

struct X_DBM_OPNQRYF
  {
     X_SHORT     sStructSize;
     X_SHORT     sQrysltVector;
     X_SHORT     sKeyfldVector;
     X_VCHAR     vchAlwcpydta[X_ALWCPYDTA_LEN + 1];
     X_VCHAR     vchOptimize[X_OPTIMIZE_LEN + 1];
     X_VCHAR     vchSeqonly1[X_SEQONLY1_LEN + 1];
     X_SHORT     sSeqonly2;
     X_VCHAR     vchCommit[X_COMMIT_LEN + 1];
     X_VCHAR     vchType[X_TYPE_LEN + 1];
  };

/* ================================================================= */
/*  X_DBM_EXPRESSION_COMPONENT : Expression Component Definition     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* chType          Type of component                                 */
/* sVector         Vector Number of Component                        */

#define X_DBM_COMPONENT_FIELD_NAME        'A'
#define X_DBM_COMPONENT_FIELD_VALUE       'B'
#define X_DBM_COMPONENT_LGL_RESULT        'C'
#define X_DBM_COMPONENT_NUM_RESULT        'D'
#define X_DBM_COMPONENT_ALP_RESULT        'E'
#define X_DBM_COMPONENT_SQLNULL_VALUE     'F'

struct X_DBM_EXPRESSION_COMPONENT
  {
     X_CHAR      chType;
     X_SHORT     sVector;
  };

/* ================================================================= */
/*  X_DBM_EXPRESSION_ACTIVITY : Expressions Activity Definition      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* chType          Type of Activity                                  */
/* sComponent1     Component 1                                       */
/* sComponent2     Component 2                                       */
/* sResult         Result Component                                  */

#define X_DBM_ACTIVITY_IF    'A'
#define X_DBM_ACTIVITY_AN    'B'
#define X_DBM_ACTIVITY_OR    'C'
#define X_DBM_ACTIVITY_AD    'D'
#define X_DBM_ACTIVITY_SU    'E'
#define X_DBM_ACTIVITY_MU    'F'
#define X_DBM_ACTIVITY_DV    'G'
#define X_DBM_ACTIVITY_EQ    'H'
#define X_DBM_ACTIVITY_NE    'I'
#define X_DBM_ACTIVITY_LT    'J'
#define X_DBM_ACTIVITY_LE    'K'
#define X_DBM_ACTIVITY_GT    'L'
#define X_DBM_ACTIVITY_GE    'M'
#define X_DBM_ACTIVITY_MB    'N'
#define X_DBM_ACTIVITY_ZA    'O'
#define X_DBM_ACTIVITY_EQ_UC 'P'
#define X_DBM_ACTIVITY_NE_UC 'Q'
#define X_DBM_ACTIVITY_LT_UC 'R'
#define X_DBM_ACTIVITY_LE_UC 'S'
#define X_DBM_ACTIVITY_GT_UC 'T'
#define X_DBM_ACTIVITY_GE_UC 'U'

struct X_DBM_EXPRESSION_ACTIVITY
  {
     X_CHAR      chType;
     X_SHORT     sComponent1;
     X_SHORT     sComponent2;
     X_SHORT     sResult;
  };

/* ================================================================= */
/*  X_DBM : LANSA/X Data Base Management Structure                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* lX_DBMVersion   Version Number of this structure                  */
/* vchTableName    Name of the table/index being accessed            */
/* sDBMRequest     I/O module request                                */
/* vchReturnCode   I/O module return code                            */
/* sCursorID       Cursor number assigned                            */
/* pX_Fld          Pointer to field vector structures                */
/* scGrpFlds       Count of group field vectors                      */
/* psGrpFlds       Pointer to group field vectors                    */
/* scKeyFlds       Count of key field vectors                        */
/* psKeyFlds       Pointer to key field vectors                      */
/* chWhereRDML     Where is evaluated at RDML level (not DBM level)  */
/* scWhere         Number of X_DBM_WHERE structures used for command */
/* pWhere          Pointer to first X_DBM_WHERE structure            */
/* chWithRRNO      WITH_RRN field vector specified                   */
/* sWithRRNO       WITH_RRN field vector                             */
/* chRetRRNO       RETURN_RRN field vector specified                 */
/* sRetRRNO        RETURN_RRN field vector                           */
/* chMsgReqd       Flag for not found/inserted message required      */
/* chValOnly       Flag for validation checks only required          */
/* chActionRow     Flag for delete/update required on DELETE_NEXT or */
/*                 UPDATE_NEXT                                       */
/* chGeneric       Generic searching used                            */
/* chBackwards     Backwards processing required                     */
/* chStartKey      Key supplied is a starting position key           */
/* chEndWhere      End search when where condition is not true       */
/* chOPNQRYF       Open Query File Option is to be used              */
/* pOPNQRYF        Pointer to Open Query File Details                */
/* chForceClose    Specific CLOSE file RDML command                  */
/* sSequence       Sequence no. of the I/O RDML command              */
/* scXComponent    Counter of expression components                  */
/* pXComponent     Pointer to first X_DBM_EXPRESSION_COMPONENT       */
/* scXActivity     Counter of expression activitys                   */
/* pXComponent     Pointer to first X_DBM_EXPRESSION_ACTIVITY        */
/* vchPhysical     Physical file name                                */
/* chKeepOpen      USE_OPTION(*KEEPOPEN) specified for OPEN          */
/* pvchFile        LOAD_FILE_DATA: Path to .dat file                 */
/* chTrigger       LOAD_FILE_DATA: Skip triggers Y/N                 */
/* chDuplicate     LOAD_FILE_DATA: Ignore duplicate key errors Y/N   */
/* pDatabase       PC Other File database details                    */
/* chSystem        Y if OAM from system dir rather than part dir     */
/* fUseNativeIO    If TRUE, use Native IO, else use SQL              */
/* fExternal       If True, is an Other File                         */
/* vchCollection   Library - Default is X_FILE_LIB_DFT               */
/* chLock          Enable lock on fetch, Default N.                  */
/* vchMember       File Member - Default is X_FILE_MBR_DFT           */
/* vchBaseMbr      Base PF Member - Default is X_FILE_MBR_DFT        */
/* ================================================================= */

#define X_TABLE_NAME_LEN            10
#define X_DBM_DECIMAL_EDIT_CODE     'P'

#ifndef X_OPERATING_TARGET_CSHARP
   #define X_SQL_RETURN_CODE           sqlca.sqlcode
#endif // X_OPERATING_TARGET_CSHARP

/* NOTE : DO NOT USE THESE VALUES       */
#define X_DBM_SQL_OKAY              0
#define X_DBM_SQL_NOT_FOUND         100
#define X_DBM_DUPLICATE_KEY        -803
/*                                      */

#define X_DBM_CHECK_FOR          10
#define X_DBM_CLOSE              20
#define X_DBM_FORCE_CLOSE        25
#define X_DBM_COMMIT             30
#define X_DBM_CONTROL_INSTANCE   32
#define X_DBM_DELETE             40
#define X_DBM_DELETE_NEXT        41
#define X_DBM_FETCH              50
#define X_DBM_FETCH_NEXT         51
#define X_DBM_FILECHECK          60
#define X_DBM_INSERT             70
#define X_DBM_OPEN               80
#define X_DBM_ROLLBACK           90
#define X_DBM_SELECT            100
#define X_DBM_SELECT_NEXT       101
#define X_DBM_UPDATE            120
#define X_DBM_UPDATE_NEXT       121
#define X_DBM_CURSOR_CLOSE      130
#define X_DBM_UNLOAD_DATA       140
#define X_DBM_LOAD_DATA         150


#define X_DBM_ALLOCATE_SQLDA          200
#define X_DBM_ALLOCATE_SQLDA_2        202
#define X_DBM_ALLOCATE_SQLDA_3        203
#define X_DBM_ALLOCATE_SQLDA_4        204 /* Identical to _2 - _4 indicates file is under commitment control */
#define X_DBM_ALLOCATE_SQLDA_5        205
#define X_DBM_ALLOCATE_SQLDA_6        206 /* Used for NCHAR fields */
#define X_DBM_DEALLOCATE_SQLDA        210
#define X_DBM_PREPARE_STMNT           220
#define X_DBM_PREPARE_STMNT_2         222
#define X_DBM_PREPARE_STMNT_3         223
#define X_DBM_OPEN_CURSOR             230
#define X_DBM_CLOSE_CURSOR            240
#define X_DBM_FETCH_ROW               250
#define X_DBM_EXECUTE                 260
#define X_DBM_EXECUTE_IMMED           270
#define X_DBM_CONNECT                 280
#define X_DBM_DISCONNECT              290
#define X_DBM_DROP_STATEMENTS         300
#define X_DBM_FREE_STATEMENT          302 /* For freeing prepared but unrequired statement */
#define X_DBM_ALLOC_HDBC              310 /* For use by X_DBI only */
#define X_DBM_DEALLOC_HDBC            320 /* For use by X_DBI only */
#define X_DBM_HANDLE_SELECT_SQL_READ  330
#define X_DBM_HANDLE_SELECT_SQL_READ_2 333
#define X_DBM_HANDLE_SELECT_SQL_CLOSE 340
#define X_DBM_HANDLE_SELECT_SQL_CLOSE_2 343
#define X_DBM_MAP_FROM_TABLE          350
#define X_DBM_MAP_FROM_TABLE_2        353
#define X_DBM_MAP_SINGLE_FLD_FROM_TABLE   354
#define X_DBM_MAP_TO_TABLE_2          356
#define X_DBM_MAP_TO_TABLE_NO_RRNO    358
#define X_DBM_MAP_SINGLE_FLD_TO_TABLE     359
#define X_DBM_CONNECT_SERVER          360
#define X_DBM_DISCONNECT_SERVER       370
#define X_DBM_DESTROY_INSTANCE        380
#define X_DBM_QUERY_CONNECTION        390
#define X_DBM_INSERT_RRN              400
#define X_DBM_EXECUTE_ROWCOUNT        410
#define X_DBM_EXECUTE_LOAD_DATA       411
#define X_DBM_SET_SQLDA_NO            420
#define X_DBM_MAP_LOOKUP_FROM_SQLDA   430
#define X_DBM_MAP_COLUMN_FUNCTIONS_FROM_SQLDA 440
#define X_DBM_FISROWNOTFOUND          450
#define X_DBM_FORMAT_DATETIME_LITERAL 460
#define X_DBM_BIND_SESSION            470 /* For use by X_DBI only */
#define X_DBM_FORMAT_UNICODE_LITERAL  480
#define X_DBM_FORMAT_UTF16_LITERAL    485
#define X_DBM_FORMAT_BINARY_LITERAL   490

#define X_DBM_NATIVE_OPEN             500
#define X_DBM_NATIVE_OPEN_2           503
#define X_DBM_NATIVE_CLOSE            510
#define X_DBM_NATIVE_READ             520
#define X_DBM_NATIVE_READ_2           523
#define X_DBM_NATIVE_LOCATE           530
#define X_DBM_NATIVE_LOCATE_2         533
#define X_DBM_NATIVE_UPDATE           540
#define X_DBM_NATIVE_UPDATE_2         543
#define X_DBM_NATIVE_INSERT           550
#define X_DBM_NATIVE_INSERT_2         553
#define X_DBM_NATIVE_DELETE           560
#define X_DBM_NATIVE_UNLOCK           570
#define X_DBM_MAP_NATIVE_TO_OAM       580
#define X_DBM_MAP_NATIVE_TO_OAM_2     583
#define X_DBM_MAP_NATIVE_TO_OAM_3     585
#define X_DBM_MAP_OAM_TO_NATIVE       590
#define X_DBM_MAP_OAM_TO_NATIVE_2     593
#define X_DBM_MAP_OAM_TO_NATIVE_3     595
#define X_DBM_MAP_OAM_TO_NATIVE_KEY   600
#define X_DBM_MAP_OAM_TO_NATIVE_KEY_2 603
#define X_DBM_MAP_OAM_TO_NATIVE_KEY_3 605
#define X_DBM_NATIVE_BUILD_WHERE      610
#define X_DBM_NATIVE_BUILD_WHERE_2    613
#define X_DBM_NATIVE_BUILD_WHERE_3    615
#define X_DBM_NATIVE_EVALUATE_WHERE   620
#define X_DBM_NATIVE_EVALUATE_WHERE_2 623
#define X_DBM_NATIVE_EVALUATE_WHERE_3 625

#define X_DBM_OKAY               "OK"
#define X_DBM_FATAL_ERROR        "ER"
#define X_DBM_VALIDATION_ERROR   "VE"
#define X_DBM_NO_RECORD          "NR"
#define X_DBM_END_FILE           "EF"
#define X_DBM_BEGIN_FILE         "BF"
#define X_DBM_NOT_EQUAL_KEY      "NE"
#define X_DBM_EQUAL_KEY          "EQ"
#define X_DBM_NO_TABLE           "NT"

#define X_DBM_INSERT_OPERATION        'A'
#define X_DBM_INSERT_SYSRRN_OPERATION 'B'
#define X_DBM_UPDATE_OPERATION        'U'
#define X_DBM_UPDATE_SYSRRN_OPERATION 'V'
#define X_DBM_DELETE_OPERATION        'D'

#define X_DBM_COMMIT_NO         'N'
#define X_DBM_COMMIT_YES        'Y'
#define X_DBM_COMMIT_FILE       'F'

#define X_DBM_ENDWHERE_NO       'N'
#define X_DBM_ENDWHERE_YES      'Y'
#define X_DBM_ENDWHERE_SQL      'S'

#define X_DEFAULT_DATETIME "1900-01-01 00:00:00.000000000"
/* Null mapping values */
#define X_IS_DB2_NOT_NULL      '0'
#define X_IS_DB2_NULL          '1'
#define X_IS_DB2_MAPPING_ERROR '2'
/* Trigger buffer values */
#define X_IS_DB2_INSERT '1'
#define X_IS_DB2_DELETE '2'
#define X_IS_DB2_UPDATE '3'
#define X_IS_DB2_READ   '4'
#define X_IS_DB2_AFTER  '1'
#define X_IS_DB2_BEFORE '2'
/* Special fields values */
#define X_DB2_IS_NOT_SPECIAL                0
#define X_DB2_IS_OTHBIN                     1
#define X_DB2_IS_VARLEN                     2
#define X_DB2_IS_DATE_ISO                   X_DB2_IS_NOT_SPECIAL
#define X_DB2_IS_DATE_USA                   3
#define X_DB2_IS_DATE_EUR                   4
#define X_DB2_IS_DATE_JIS                   X_DB2_IS_NOT_SPECIAL
#define X_DB2_IS_DATE_MDY_SLASH             5
#define X_DB2_IS_DATE_MDY_DASH              6
#define X_DB2_IS_DATE_MDY_DOT               7
#define X_DB2_IS_DATE_MDY_COMMA             8
#define X_DB2_IS_DATE_MDY_BLANK             9
#define X_DB2_IS_DATE_DMY_SLASH            10
#define X_DB2_IS_DATE_DMY_DASH             11
#define X_DB2_IS_DATE_DMY_DOT              12
#define X_DB2_IS_DATE_DMY_COMMA            13
#define X_DB2_IS_DATE_DMY_BLANK            14
#define X_DB2_IS_DATE_YMD_SLASH            15
#define X_DB2_IS_DATE_YMD_DASH             16
#define X_DB2_IS_DATE_YMD_DOT              17
#define X_DB2_IS_DATE_YMD_COMMA            18
#define X_DB2_IS_DATE_YMD_BLANK            19
#define X_DB2_IS_DATE_JUL_SLASH            20
#define X_DB2_IS_DATE_JUL_DASH             21
#define X_DB2_IS_DATE_JUL_DOT              22
#define X_DB2_IS_DATE_JUL_COMMA            23
#define X_DB2_IS_DATE_JUL_BLANK            24
#define X_DB2_IS_TIME_ISO                  X_DB2_IS_NOT_SPECIAL
#define X_DB2_IS_TIME_USA                  25
#define X_DB2_IS_TIME_EUR                  X_DB2_IS_NOT_SPECIAL
#define X_DB2_IS_TIME_JIS                  26
#define X_DB2_IS_TIME_HMS_COLON            27
#define X_DB2_IS_TIME_HMS_DOT              X_DB2_IS_NOT_SPECIAL
#define X_DB2_IS_TIME_HMS_BLANK            28

#ifdef X_OPERATING_SYSTEM_ISERIES
   #if X_OPERATING_SYSTEM_ISERIES_VRM < 530
#define X_DB2_IS_DECIMAL_TRUNCATE          29
   #else
#define X_DB2_IS_DECIMAL_TRUNCATE          X_DB2_IS_NOT_SPECIAL
   #endif
#else
#define X_DB2_IS_DECIMAL_TRUNCATE          29
#endif
#define X_DB2_IS_TIME_HMS_COMMA            30
#define X_DB2_IS_UCS2                      31
#define X_DB2_IS_UCS2_VARLEN               32
#define X_DB2_IS_UTF16                     33
#define X_DB2_IS_UTF16_VARLEN              34

#define X_DB2_IS_BINARY                    35
#define X_DB2_IS_BINARY_VARLEN             36
#define X_DB2_IS_BITDATA_VARLEN            X_DB2_IS_VARLEN
#define X_DB2_IS_DECFLOAT                  37

#define X_DB2_IS_UTF8                      38
#define X_DB2_IS_UTF8_VARLEN               39

typedef struct
{
  X_CHAR         chType;
  X_CHAR         szNtvFmt[3 + 1];
  X_CHAR         chNtvSep;
  X_SHORT        sNtvDTDecode;
  X_CHAR         szNtvPic[11 + 1];
  X_CHAR         chNtvBifFmt;
  X_CHAR         chNtvBifSep;
} X_NTV_DT_DECODE;

#define X_DECLARE_NTV_DT_DECODE_TABLE(_T) \
   X_NTV_DT_DECODE  _T[] = { \
   { X_TYPE_DATE, "ISO", BLANK, X_DB2_IS_DATE_ISO,       "YYYY-MM-DD", 'K', '-'   }, \
   { X_TYPE_DATE, "USA", BLANK, X_DB2_IS_DATE_USA,       "MM/DD/YYYY", 'M', '/'   }, \
   { X_TYPE_DATE, "EUR", BLANK, X_DB2_IS_DATE_EUR,       "DD.MM.YYYY", 'I', '.'   }, \
   { X_TYPE_DATE, "JIS", BLANK, X_DB2_IS_DATE_JIS,       "YYYY-MM-DD", 'K', '-'   }, \
   { X_TYPE_DATE, "MDY", '/'  , X_DB2_IS_DATE_MDY_SLASH, "MM/DD/YY",   'G', '/'   }, \
   { X_TYPE_DATE, "MDY", '-'  , X_DB2_IS_DATE_MDY_DASH,  "MM-DD-YY",   'G', '-'   }, \
   { X_TYPE_DATE, "MDY", '.'  , X_DB2_IS_DATE_MDY_DOT,   "MM.DD.YY",   'G', '.'   }, \
   { X_TYPE_DATE, "MDY", ','  , X_DB2_IS_DATE_MDY_COMMA, "MM,DD,YY",   'G', ','   }, \
   { X_TYPE_DATE, "MDY", BLANK, X_DB2_IS_DATE_MDY_BLANK, "MM DD YY",   'G', BLANK }, \
   { X_TYPE_DATE, "DMY", '/',   X_DB2_IS_DATE_DMY_SLASH, "DD/MM/YY",   'C', '/'   }, \
   { X_TYPE_DATE, "DMY", '-',   X_DB2_IS_DATE_DMY_DASH,  "DD-MM-YY",   'C', '-'   }, \
   { X_TYPE_DATE, "DMY", '.',   X_DB2_IS_DATE_DMY_DOT,   "DD.MM.YY",   'C', '.'   }, \
   { X_TYPE_DATE, "DMY", ',',   X_DB2_IS_DATE_DMY_COMMA, "DD,MM,YY",   'C', ','   }, \
   { X_TYPE_DATE, "DMY", BLANK, X_DB2_IS_DATE_DMY_BLANK, "DD MM YY",   'C', BLANK }, \
   { X_TYPE_DATE, "YMD", '/',   X_DB2_IS_DATE_YMD_SLASH, "YY/MM/DD",   'E', '/'   }, \
   { X_TYPE_DATE, "YMD", '-',   X_DB2_IS_DATE_YMD_DASH,  "YY-MM-DD",   'E', '-'   }, \
   { X_TYPE_DATE, "YMD", '.',   X_DB2_IS_DATE_YMD_DOT,   "YY.MM.DD",   'E', '.'   }, \
   { X_TYPE_DATE, "YMD", ',',   X_DB2_IS_DATE_YMD_COMMA, "YY,MM,DD",   'E', ','   }, \
   { X_TYPE_DATE, "YMD", BLANK, X_DB2_IS_DATE_YMD_BLANK, "YY MM DD",   'E', BLANK }, \
   { X_TYPE_DATE, "JUL", '/',   X_DB2_IS_DATE_JUL_SLASH, "YY/DDD",     'E', '/'   }, \
   { X_TYPE_DATE, "JUL", '-',   X_DB2_IS_DATE_JUL_DASH,  "YY-DDD",     'E', '-'   }, \
   { X_TYPE_DATE, "JUL", '.',   X_DB2_IS_DATE_JUL_DOT,   "YY.DDD",     'E', '.'   }, \
   { X_TYPE_DATE, "JUL", ',',   X_DB2_IS_DATE_JUL_COMMA, "YY,DDD",     'E', ','   }, \
   { X_TYPE_DATE, "JUL", BLANK, X_DB2_IS_DATE_JUL_BLANK, "YY DDD",     'E', BLANK }, \
   { X_TYPE_TIME, "ISO", BLANK, X_DB2_IS_TIME_ISO,       "HH.MI.SS", BLANK, '.'   }, \
   { X_TYPE_TIME, "USA", BLANK, X_DB2_IS_TIME_USA,       "HH:MI AP", BLANK, ':'   }, \
   { X_TYPE_TIME, "EUR", BLANK, X_DB2_IS_TIME_EUR,       "HH.MI.SS", BLANK, '.'   }, \
   { X_TYPE_TIME, "JIS", BLANK, X_DB2_IS_TIME_JIS,       "HH:MI:SS", BLANK, ':'   }, \
   { X_TYPE_TIME, "HMS", ':',   X_DB2_IS_TIME_HMS_COLON, "HH:MI:SS", BLANK, ':'   }, \
   { X_TYPE_TIME, "HMS", '.',   X_DB2_IS_TIME_HMS_DOT,   "HH.MI.SS", BLANK, '.'   }, \
   { X_TYPE_TIME, "HMS", BLANK, X_DB2_IS_TIME_HMS_BLANK, "HH MI SS", BLANK, BLANK }, \
   { X_TYPE_TIME, "HMS", ',',   X_DB2_IS_TIME_HMS_COMMA, "HH,MI,SS", BLANK, ','   } \
   };

#define X_DBM_LENGTH_VARCHAR(A,B,C) \
  for (A = X_Fld[B].sByteLen-1; A > 0; A--) \
  { \
     if (X_Fld[B].pField[A] != BLANK) \
        break; \
  } \
  C = A + 1;

/* Bit flags for X_DBM_MAP_TO_TABLE and X_DBM_MAP_FROM_TABLE */
/* Passed in 6th arg to X_DBM_OP macro (an X_SHORT)          */
#define X_DBM_MAP_SKIP_LOBS    (X_SHORT) 0x8000 /* 1000000000000000 in Binary */
#define X_DBM_MAP_SKIP_INITIAL (X_SHORT) 0x4000 /* 0100000000000000 in Binary */

/* These macros are intended for use in IOMs and DBM.                     */
/* They assume pDatabase is connected, and pX_Ids and pX_DBM are defined. */

#define X_DBMS_INFO \
   ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo \
                                             : pX_Ids->pUserDBMSInfo)

#define X_DBMS_INFO_QUOTE_CHAR \
 (X_CHAR)((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->chIdentifierQuoteChar \
                                           : pX_Ids->pUserDBMSInfo->chIdentifierQuoteChar)

#define X_DBMS_INFO_COLLECTIONS \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fDBMSCollections \
                                           : pX_Ids->pUserDBMSInfo->fDBMSCollections)

#define X_DBMS_INFO_EMULATE_COLLECTIONS \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fDBMSEmulateCollections \
                                           : pX_Ids->pUserDBMSInfo->fDBMSEmulateCollections)

#define X_DBMS_INFO_OKAY \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSOkay \
                                           : pX_Ids->pUserDBMSInfo->lDBMSOkay)

#define X_DBMS_INFO_ROW_NOT_FOUND \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSRowNotFound \
                                           : pX_Ids->pUserDBMSInfo->lDBMSRowNotFound)

#define X_DBMS_INFO_ROW_LOCKED \
   ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSRowLocked \
                                             : pX_Ids->pUserDBMSInfo->lDBMSRowLocked )

#define X_DBMS_INFO_DUPLICATE_ROW \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSDuplicateRow \
                                           : pX_Ids->pUserDBMSInfo->lDBMSDuplicateRow)

#define X_DBMS_INFO_DUPLICATE_ROW2 \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSDuplicateRow2 \
                                           : pX_Ids->pUserDBMSInfo->lDBMSDuplicateRow2)

#define X_DBMS_INFO_DUPLICATE_ROW3 \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSDuplicateRow3 \
                                           : pX_Ids->pUserDBMSInfo->lDBMSDuplicateRow3)

#define X_DBMS_INFO_IS_DUPLICATE_ROW(_SQLCODE) \
        ((_SQLCODE == X_DBMS_INFO_DUPLICATE_ROW) \
     || (_SQLCODE == X_DBMS_INFO_DUPLICATE_ROW2) \
     || (_SQLCODE == X_DBMS_INFO_DUPLICATE_ROW3))

#define X_DBMS_INFO_NO_TABLE_EXISTS \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSNoTableExists \
                                           : pX_Ids->pUserDBMSInfo->lDBMSNoTableExists)

#define X_DBMS_INFO_NO_TABLE_EXISTS2 \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDBMSNoTableExists2 \
                                           : pX_Ids->pUserDBMSInfo->lDBMSNoTableExists2)

#define X_DBMS_INFO_TABLE_DOES_NOT_EXIST(_SQLCODE) \
        ((_SQLCODE == X_DBMS_INFO_NO_TABLE_EXISTS) \
     || (_SQLCODE == X_DBMS_INFO_NO_TABLE_EXISTS2))

/* Always use setting for main database */
#define X_DBMS_INFO_MIXED_MODE pX_Ids->pUserDBMSInfo->fDBMSMixedModeCommitment

#define X_DBMS_INFO_USE_INTERNAL_NAMES \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fUseInternalName \
                                           : pX_Ids->pUserDBMSInfo->fUseInternalName)

#define X_DBMS_INFO_IGNORE_NATIVE_SUPPORT \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fIgnoreNativeSupport \
                                           : pX_Ids->pUserDBMSInfo->fIgnoreNativeSupport)

/* Note, X_DBMS_INFO_MIXED_MODE overrides this! */
#define X_DBMS_INFO_USE_NATIVE_CMTCTL \
 (!X_DBMS_INFO_MIXED_MODE && \
  ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fUseNativeCmtCtl \
                                            : pX_Ids->pUserDBMSInfo->fUseNativeCmtCtl))

/* Default behaviour is leave as-is. OAMs generated before 10.3 will use        */
/* X_Quote_String() which does not know which database type a file is connected */
/* to. X_Quote_String() calls are all for other files, though.                  */
#define X_DBMS_INFO_REFORMAT_DATE_AS_TIMESTAMP \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fDatetimeOnly && !(pX_DBM->pDatabase->pDBMSInfo->fDateAsDatetime) \
                                           : FALSE )

#define X_DBMS_INFO_REFORMAT_TIME_AS_TIMESTAMP \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fDatetimeOnly && !(pX_DBM->pDatabase->pDBMSInfo->fTimeAsDatetime) \
                                           : FALSE )

#define X_DBMS_INFO_DATETIME_MAX_DIGITS \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->lDATETIMEMaxDigit \
                                           : pX_Ids->pUserDBMSInfo->lDATETIMEMaxDigit)

#define X_DBMS_INFO_CATEGORY_ID \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->sDBMSCategory \
                                           : pX_Ids->pUserDBMSInfo->sDBMSCategory)

#define X_DBMS_INFO_PRODUCT_ID \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->sDBMSProduct \
                                           : pX_Ids->pUserDBMSInfo->sDBMSProduct)
#define X_DBMS_INFO_VERSION \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->vchDBMSVersion \
                                           : pX_Ids->pUserDBMSInfo->vchDBMSVersion)
#define X_DBMS_INFO_USE_SINGLE_CONNECTION \
 ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->fUseSingleConnection \
                                           : pX_Ids->pUserDBMSInfo->fUseSingleConnection)

#define X_DBMS_INFO_LOCK_TIMEOUT \
   (pX_Ids->iLockTimeout > 0 ? pX_Ids->iLockTimeout \
                             : ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->iLockTimeout \
                                                                         : pX_Ids->pUserDBMSInfo->iLockTimeout) )

#define X_DBMS_INFO_CMD_LOCK_TIMEOUT \
   ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->vchLockTimeoutCommand \
                                             : pX_Ids->pUserDBMSInfo->vchLockTimeoutCommand)

#define X_DBMS_INFO_LOCK_TYPE \
   ((X_DBM_V3_OR_LATER && pX_DBM->pDatabase) ? pX_DBM->pDatabase->pDBMSInfo->vchLockType[0] \
                                             : pX_Ids->pUserDBMSInfo->vchLockType[0] )

#define X_DBMS_INFO_LOCK_TYPE_CONNECTION     'C'
#define X_DBMS_INFO_LOCK_TYPE_STATEMENT      'S'

/* The following will eventually be replaced by a lookup to DBMS_INFO */
#ifdef X_OPERATING_SYSTEM_ISERIES

#define X_DBMS_INFO_COLLECTION_SEP "/"

#else

#define X_DBMS_INFO_COLLECTION_SEP ((X_DBMS_INFO_EMULATE_COLLECTIONS) ? "_" : "." )

#endif
/* End IOM and DBM macros */

#define X_DBM_V2           -2
#define X_DBM_V3           -3
#define X_DBM_V4           -4
#define X_DBM_V5           -5
#define X_DBM_V6           -6
#define X_DBM_V7           -7
#define X_DBM_V8           -8
#define X_DBM_V9           -9
#define X_DBM_V10          -10
#define X_DBM_V11          -11
#define X_DBM_CURRENT      X_DBM_V11 /* Make sure this is updated with the latest version number */
                                     /* Search for all users of this and make sure they use the  */
                                     /* new structure element(s) correctly.                      */

#define X_DBM_V11_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V11)
#define X_DBM_NOT_V11_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V11)
#define X_DBM_V10_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V10)
#define X_DBM_NOT_V10_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V10)
#define X_DBM_V9_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V9)
#define X_DBM_NOT_V9_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V9)
#define X_DBM_V8_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V8)
#define X_DBM_NOT_V8_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V8)
#define X_DBM_V7_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V7)
#define X_DBM_NOT_V7_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V7)
#define X_DBM_V6_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V6)
#define X_DBM_NOT_V6_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V6)
#define X_DBM_V5_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V5)
#define X_DBM_NOT_V5_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V5)
#define X_DBM_V4_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V4)
#define X_DBM_NOT_V4_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V4)
#define X_DBM_V3_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V3)
#define X_DBM_NOT_V3_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V3)
#define X_DBM_V2_OR_LATER     (pX_DBM->lX_DBMVersion <= X_DBM_V2)
#define X_DBM_NOT_V2_OR_LATER (pX_DBM->lX_DBMVersion > X_DBM_V2)

#define X_DBM_FORCE_COMMIT_ON_CLOSE_CURSOR   0x00000001

struct X_DBM
{
     X_INT32                              lX_DBMVersion;
     X_VCHAR                              vchTableName[X_TABLE_NAME_LEN+1];
     X_SHORT                              sDBMRequest;
     X_VCHAR                              vchReturnCode[X_DBM_RETURN_CODE_LEN + 1];
     X_SHORT                              sCursorID;
     struct X_FLD                      *  pX_Fld;
     X_SHORT                              scGrpFlds;
     X_PSHORT                             psGrpFlds;
     X_SHORT                              scKeyFlds;
     X_PSHORT                             psKeyFlds;
     X_YES_NO                             chWhereRDML;
     X_SHORT                              scWhere;
     struct X_DBM_WHERE                *  pWhere;
     X_YES_NO                             chWithRRNO;
     X_SHORT                              sWithRRNO;
     X_YES_NO                             chRetRRNO;
     X_SHORT                              sRetRRNO;
     X_YES_NO                             chMsgReqd;
     X_YES_NO                             chValOnly;
     X_YES_NO                             chActionRow;
     X_YES_NO                             chGeneric;
     X_YES_NO                             chBackwards;
     X_YES_NO                             chStartKey;
     X_CHAR                               chEndWhere;
     X_CHAR                               chAutoCommit;
     X_YES_NO                             chOPNQRYF;
     struct X_DBM_OPNQRYF              *  pOPNQRYF;
     X_CHAR                               chForceClose;
     X_SHORT                              sSequence;
     X_SHORT                              scXComponent;
     struct X_DBM_EXPRESSION_COMPONENT *  pXComponent;
     X_SHORT                              scXActivity;
     struct X_DBM_EXPRESSION_ACTIVITY  *  pXActivity;
     X_VCHAR                              vchPhysical[X_TABLE_NAME_LEN + 1];
     X_CHAR                               chKeepOpen;
     X_PVCHAR                             pvchFile;
     X_YES_NO                             chTrigger;
     X_YES_NO                             chDuplicate;
     struct X_CONNECT_DATABASE         *  pDatabase;
     X_YES_NO                             chSystem;
     X_BOOL                               fUseNativeIO;
     X_BOOL                               fExternal;
     X_VCHAR                              vchCollection[X_COLLECTION_NAME_LEN + 1];
     X_YES_NO                             chLock;
     X_VCHAR                              vchMember[X_MEMBER_NAME_LEN + 1];
     X_VCHAR                              vchBaseMbr[X_MEMBER_NAME_LEN + 1];
     X_SHORT                              scEvaluations;
     X_PSHORT                             psEvaluations;
     X_Module_Binding                  *  pModuleBinding;
     X_VCHAR                              vchFilePoint[X_TABLE_NAME_LEN + 1];
     X_UINT32                             ulFlags;
};

typedef struct _X_DBM_INSERT_RRN_PARMS
{
   X_DOUBLE          xdVal;
   X_PVOID           pSqlda;
   struct X_FLD     *pX_Fld;
} X_DBM_INSERT_RRN_PARMS;

typedef struct _X_PJF_SQLDA_PARMS
{
   struct X_FLD *pX_Fld;
   X_SHORT       scTgtFlds;
   X_PSHORT      psTgtFlds;
   X_PFCHAR      pchTgtFldsSREV;
   X_PVOID       pSqlda;
} X_PJF_SQLDA_PARMS;

typedef struct _X_DBM_FISROWNOTFOUND_PARMS
{
   X_SHORT     sSourceFldVector;
   X_PVOID     pSqlda;
   X_LONG      lFetchCode;
   X_CHAR      chType;
} X_DBM_FISROWNOTFOUND_PARMS;

typedef struct _X_DBM_MAP_FLD_PARMS
{
   X_SHORT        sSource;
   X_SHORT        sTarget;
   X_PVOID        pSqlda;
   struct X_FLD  *pX_Fld;
} X_DBM_MAP_FLD_PARMS;

typedef struct _X_DBM_ALLOC_SQLDA_2_PARMS
{
   X_PVCHAR pvchSqlStmnt;
   X_PPVOID ppSqlda;
   X_SHORT  fRDMLXFile;
   X_SHORT  scLOBColumns;
   X_PSHORT psLOBColumns;
} X_DBM_ALLOC_SQLDA_2_PARMS;

typedef struct _X_DBM_ALLOC_SQLDA_5_PARMS
{
   X_PVCHAR pvchSqlStmnt;
   X_PPVOID ppSqlda;
   X_SHORT  fRDMLXFile;
   X_SHORT  scLOBColumns;
   X_PSHORT psLOBColumns;
   X_SHORT  scSUNIColumns; /* Indicates treat as Wchar. Can be SUNI or Nchar */
   X_PSHORT psSUNIColumns;
} X_DBM_ALLOC_SQLDA_5_PARMS;

typedef struct _X_DBM_ALLOC_SQLDA_6_PARMS
{
   X_PVCHAR pvchSqlStmnt;
   X_PPVOID ppSqlda;
   X_SHORT  fRDMLXFile;
   X_SHORT  fOAMCommits;
   X_SHORT  scLOBColumns;
   X_PSHORT psLOBColumns;
   X_SHORT  scSUNIColumns; /* Indicates treat as Wchar. Can be SUNI or Nchar */
   X_PSHORT psSUNIColumns;
} X_DBM_ALLOC_SQLDA_6_PARMS;

typedef struct _X_DBM_FORMAT_UTF16_PARMS
{
   X_UTF16_VCHAR *pvchFromWideChar;
   X_ULONG        ulWideCharLen;
   X_BOOL         fEscapeProcessing;
   X_PPVCHAR      ppvchResult;
   X_ULONG        ulPadLength;
} X_DBM_FORMAT_UTF16_PARMS;

typedef struct _X_DBM_OPEN_FILE
{
   X_VCHAR     vchFile[X_OBJECT_NAME_LEN + 1];
   X_VCHAR     vchLibrary[X_OBJECT_NAME_LEN + 1];
   X_VCHAR     vchMember[X_OBJECT_NAME_LEN + 1];
   X_VCHAR     vchFileDeclared[X_OBJECT_NAME_LEN + 1];
   X_VCHAR     vchLibraryOpen[X_OBJECT_NAME_LEN + 1];
   X_VCHAR     vchFileOpen[X_OBJECT_NAME_LEN + 1];
} X_DBM_OPEN_FILE;

typedef struct _X_DBM_PREP_STMNT_2_PARMS
{
   X_PVCHAR pvchSqlStmnt;
   X_PSHORT psCursorID;
   X_PVOID  *pOpenFile;
} X_DBM_PREP_STMNT_2_PARMS;

typedef struct _X_DBM_FMT_BIN_LIT_PARMS
{
   X_ULONG ulMaxLen;
   X_ULONG ulCurLen;
   X_PVOID pData;
} X_DBM_FMT_BIN_LIT_PARMS;

/* ================================================================= */
/*  X_POINT_FILE : Point a file at a different file                  */
/* Only use in generated code so it can be changed at will.          */
/* ================================================================= */
typedef struct _X_POINT_FILE
{
   X_VCHAR  vchFilePoint[ X_TABLE_NAME_LEN + 1];
   X_VCHAR  vchLibrary[ X_COLLECTION_NAME_LEN + 1];
   X_VCHAR  vchMember[ X_MEMBER_NAME_LEN + 1];
} X_POINT_FILE, *PX_POINT_FILE;

/* ================================================================= */
/*  X_ODBC_SELECT : Records details of an imbedded SELECT_SQL cmd    */
/* ================================================================= */

#define X_ODBC_SELECT_DISTINCT_OPTION    '\x01'
#define X_ODBC_SELECT_COLUMN             '\x02'
#define X_ODBC_SELECT_TABLE              '\x03'
#define X_ODBC_SELECT_COLLECTION         '\x04'
#define X_ODBC_SELECT_CORRELATION        '\x05'
#define X_ODBC_SELECT_WHERE              '\x06'
#define X_ODBC_SELECT_WHERE_FIELD        '\x07'
#define X_ODBC_SELECT_GROUP_BY           '\x08'
#define X_ODBC_SELECT_HAVING             '\x09'
#define X_ODBC_SELECT_HAVING_FIELD       '\x10'
#define X_ODBC_SELECT_ORDER_BY           '\x11'
#define X_ODBC_SELECT_HANDLE             '\x12'
#define X_ODBC_SELECT_IO_STATUS          '\x14'
#define X_ODBC_SELECT_WHERE_REF_FIELD    '\x15'
#define X_ODBC_SELECT_HAVING_REF_FIELD   '\x16'
#define X_ODBC_SELECT_GROUP_BY_FIELD     '\x17'
#define X_ODBC_SELECT_ORDER_BY_FIELD     '\x18'
#define X_ODBC_SELECT_COLUMN_FIELD       '\x19'
#define X_ODBC_SELECT_USING              '\x20'
#define X_ODBC_SELECT_FILE_LIBRARY_NAME  '\x21'
#define X_ODBC_SELECT_FILE_NAME          '\x22'

struct X_ODBC_SELECT
  {
     X_CHAR           chInfoType;
     X_ULONG          ulInfoValue1;
     X_ULONG          ulInfoValue2;
     X_PVCHAR         pvchInfoValue3;
  };

#define X_ODBC_SELECT_V1            -1

/* This structure must exactly match the first 4 variables in X_ODBC_SELECT   */
/* This ensures that fewer changes are required to support both the old and   */
/* new structures                                                             */
struct X_ODBC_SELECT_2
  {
     X_CHAR           chInfoType;
     X_ULONG          ulInfoValue1;
     X_ULONG          ulInfoValue2;
     X_PVCHAR         pvchInfoValue3;
     X_SHORT          sVersion;
     X_ULONG          ulSize;
     X_PVCHAR         pvchRealName;
  };


/* ================================================================= */
/*  FNPROCESS : Function to run a process                            */
/* ================================================================= */

typedef X_VOID_FUNCTION FNPROCESS ( struct X_IDS *,
                                       X_PVCHAR,
                                       X_SHORT,
                                       struct X_PARM []);
typedef FNPROCESS *PFNPROCESS;

/* ================================================================= */
/*  FNRDMLFUNC : Function to run an RDML Function                    */
/* ================================================================= */

typedef X_VOID_FUNCTION FNRDMLFUNC (struct X_IDS *,
                                       struct X_PRO *,
                                       X_SHORT,
                                       struct X_PARM []);
typedef FNRDMLFUNC *PFNRDMLFUNC;

/* ================================================================= */
/*  FNUSERDBIF : User defined builtin function definition            */
/* ================================================================= */

typedef X_VOID_FUNCTION FNUSERDBIF (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       struct X_BIF * pX_Bif,
                                       struct X_FLD  X_Fld[],
                                       X_LIST_VOID  * X_List_Void,  /* This needs to be cast to  X_LIST_x name[] */
                                       X_SHORT       sInCount,
                                       X_SHORT       sInVec[],
                                       X_SHORT       sRetCount,
                                       X_SHORT       sRetVec[]);

typedef FNUSERDBIF *PFNUSERDBIF;


/* ================================================================= */
/*  FNCURSORCLS : Function to close an open SQL cursor               */
/* ================================================================= */

#if defined(X_16BIT_COMPILER)
typedef X_VOID_FUNCTION FNCURSORCLS (FUNCTION_STD_ARGS);
#else
typedef X_VOID_INTERNAL_FUNCTION FNCURSORCLS (FUNCTION_STD_ARGS);
#endif

typedef FNCURSORCLS *PFNCURSORCLS;

/* ================================================================= */
/*  FNUSERIOOP : I/O operation to user level table                   */
/* ================================================================= */

typedef X_LONG_FUNCTION FNUSERIOOP (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_DBM *,
                                       X_SHORT,
                                       X_PVCHAR,
                                       X_SHORT,
                                       X_PVOID);
typedef FNUSERIOOP *PFNUSERIOOP;

#if defined(X_OPERATING_SYSTEM_ISERIES)
/* ================================================================= */
/*  FNUSERISNIOOP : iSeries Native I/O operation to user level table */
/* ================================================================= */

struct X_DBM_NATIVE_IO_CONTROL;

typedef X_LONG_FUNCTION FNUSERISNIOOP (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_DBM *,
                                       X_SHORT,
                                       struct X_DBM_NATIVE_IO_CONTROL *,
	                                    struct X_FLD *,
	                                    X_PSHORT,
	                                    struct X_DBM_WHERE * );
typedef FNUSERISNIOOP *PFNUSERISNIOOP;
#endif

/* ================================================================= */
/*  FNINTLIOOP : I/O operation to internal / LANSA level table       */
/* ================================================================= */

typedef X_VOID_FUNCTION FNINTLIOOP (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PVOID);
typedef FNINTLIOOP *PFNINTLIOOP;

/* ================================================================= */
/*  X_KEEP_LAST : Track Keep_Last values for an RDML function        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Current         Current Number of stored entries                  */
/* Next            Next place to store an entry                      */
/* Maximum         Maximum number of stored entries allowable        */
/* EntryLength     Aggregate entry length of stored entry            */
/* pEntries        Pointer to block of stored entries                */

struct X_KEEP_LAST
  {
     X_SHORT             sCurrent;
     X_SHORT             sNext;
     X_SHORT             sMaximum;
     X_SHORT             sEntryLength;
     X_PDICTIONARY_FIELD pEntries;
  };


/* ================================================================= */
/*  X_FIELD_DEFINITION : Definition of a field from the dictionary   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/*                                                                   */
/*   *** Refer to associated SQL table definitions for details ***   */
/*                                                                   */

struct X_FIELD_DEFINITION
  {
     X_FCHAR     X03FLD[10+1];
     X_CHAR      X03TYP;
     X_LONG      X03LEN;
     X_SHORT     X03DEC;
     X_CHAR      X03XTP;
     X_FCHAR     X03REF[10+1];
     X_FCHAR     X03IAT[40+1];
     X_FCHAR     X03OAT[40+1];
     X_CHAR      X03EDC;
     X_FCHAR     X03EDW[24+1];
     X_FCHAR     X03DFT[20+1];
     X_FCHAR     X03ALS[30+1];
     X_CHAR      X03SYS;
     X_FCHAR     X03PRO[10+1];
     X_FCHAR     X03FUN[7+1];
     X_CHAR      X03KSH;
     X_FCHAR     X03SP1[100+1];
     X_FCHAR     X62DES[40+1];
     X_FCHAR     X62LBL[15+1];
     X_FCHAR     X62CH1[20+1];
     X_FCHAR     X62CH2[20+1];
     X_FCHAR     X62CH3[20+1];
  };

#include "x_strpck.h" /* 105292 Force single-byte alignment */

   typedef X_PACKED struct _X_FIELDX03SP1
   {
      char     chCompileStatus;    /* Bytes   1 ->   1   */
      char     fchCompileDate[6];  /* Bytes   2 ->   7   */
      char     fchCompileTime[6];  /* Bytes   8 ->  13   */
      char     fchMetaClass[5];    /* Bytes  14 ->  18   */
      char     fchVisualStyle[5];  /* Bytes  19 ->  23   */
      char     chUsesImbeddedSQL;  /* Bytes  24 ->  24   */
      char     fchFiller[76];      /* Bytes  25 -> 100   */
      char     fchTerminator;      /* Terminator for I/O */
   }             X_FIELDX03SP1,
             *  PX_FIELDX03SP1,
            ** PPX_FIELDX03SP1;

#include "x_endpck.h" /* 105292 */

#define PX03SP1_IS_SIMPLE_FIELD(_P) \
   ( (_P->fchMetaClass[0] == LOVAL) || (memcmp(_P->fchMetaClass,"     ",5) == 0) || (memcmp(_P->fchMetaClass,"00000",5) == 0) )

#define PX03SP1_IS_WAM(_P) ( memcmp(_P->fchMetaClass,"00008",5) == 0 )

#define PX03SP1_IS_EXTERNAL_RESOURCE(_P) ( memcmp(_P->fchMetaClass,"00009",5) == 0 )

#define PX03SP1_IS_COMPONENT(_P)   !( PX03SP1_IS_SIMPLE_FIELD(_P) )


/* ================================================================= */
/*  X_PIM : LANSA/X Printer Interface Management Structures          */
/* ================================================================= */

typedef FILE *X_FFIL;

struct X_PIM
   {
      X_LONG   sStructSize;
      X_SHORT  sReport_No;
      X_SHORT  sLineWidth;
      X_SHORT  sPageLength;
      X_SHORT  sOverFlowLine;
      X_SHORT  sLastDetailLine;
      X_SHORT  sCurrentLine;
      X_SHORT  sCurrentPage;
      X_FFIL   fFilePointer;
      X_VCHAR  vchSpare1[X_OLD_FILE_PATH_LENGTH + 1];
      X_SHORT  svRetLength;
      X_SHORT  svRetWidth;
      X_SHORT  svRetOverFlow;
      X_SHORT  svRetLine;
      X_SHORT  svRetPage;
      X_SHORT  svREPnPAGE;
      X_YES_NO chOpen;
      X_SHORT  sPIMCallCount;
      X_YES_NO chOverFlowOn;
      X_YES_NO chNewPageFlag;
      X_YES_NO chLevelBreak;
      X_YES_NO chClosingReport;
      X_VCHAR  vchFileName[X_NEW_FILE_PATH_LENGTH + 1];
      X_SHORT  sVersion;
      X_VCHAR  vchPrintFileName[10 + 1];
      X_VCHAR  vchPrintFileLibr[10 + 1];
      X_SHORT  svOutputQueue;
      X_SHORT  svNumberCopies;
      X_SHORT  svFormtype;
      X_SHORT  svOtherOverrides;
   } ;

/* ============================================ */
/* DO NOT USE - for backward compatibility only */
/* ============================================ */
struct X_PIM_V1
   {
      X_LONG   sStructSize;
      X_SHORT  sReport_No;
      X_SHORT  sLineWidth;
      X_SHORT  sPageLength;
      X_SHORT  sOverFlowLine;
      X_SHORT  sLastDetailLine;
      X_SHORT  sCurrentLine;
      X_SHORT  sCurrentPage;
      X_FFIL   fFilePointer;
      X_VCHAR  vchSpare1[X_OLD_FILE_PATH_LENGTH + 1];
      X_SHORT  svRetLength;
      X_SHORT  svRetWidth;
      X_SHORT  svRetOverFlow;
      X_SHORT  svRetLine;
      X_SHORT  svRetPage;
      X_SHORT  svREPnPAGE;
      X_YES_NO chOpen;
      X_SHORT  sPIMCallCount;
      X_YES_NO chOverFlowOn;
      X_YES_NO chNewPageFlag;
      X_YES_NO chLevelBreak;
      X_YES_NO chClosingReport;
      X_VCHAR  vchFileName[X_NEW_FILE_PATH_LENGTH + 1];
   } ;

struct X_REPORT_CTL
   {
      X_SHORT  sSpace_Before;
      X_SHORT  sSpace_After;
      X_SHORT  sSkip_Before;
      X_SHORT  sSkip_After;
   };

struct X_REPORT_TXT
   {
      X_PVCHAR pvchText;
      X_SHORT  sPosn;
      X_SHORT  sCond1;
      X_SHORT  sCond2;
   };

struct X_REPORT_FLD
   {
      X_SHORT  sVec_Fld;
      X_SHORT  sPosn;
      X_SHORT  sCond1;
      X_SHORT  sCond2;
      X_CHAR   chEditCode;
      X_PVCHAR pvchEditWord;
      X_SHORT  sPrintLength;
   };



#ifdef X_WINDOWS_PRINTING

typedef struct _X_WIN_DOCUMENT
{
   X_LONG                   sStructSize;
   struct _X_WIN_DOCUMENT * pNextDocument;
   X_SHORT                  sReport_No;
   X_VCHAR                  vchOwnerFunction[X_FUNCTION_NAME_LEN+1];
   X_PVOID                  pvPage;
   X_DOUBLE                 dWidthUnits;
   X_DOUBLE                 dLengthUnits;
   X_BOOL                   fEndPagePending;

}     X_WIN_DOCUMENT,
  *  PX_WIN_DOCUMENT,
 ** PPX_WIN_DOCUMENT;

typedef struct _X_WIN_PRINTER
{
   X_PVOID                  pvSetupDlg;
   struct X_PIM             LastReport;
   X_VCHAR                  vchLastPrinterName[ X_PRINTER_NAME_LEN + 1 ];
   X_VCHAR                  vchLastPrinterSetupFile[ X_NEW_FILE_PATH_LENGTH + 1 ];

}     X_WIN_PRINTER,
  *  PX_WIN_PRINTER,
 ** PPX_WIN_PRINTER;

typedef struct _X_WIN_PRINTER_FONT
{
   X_PVOID                  pvChooseFont;
   struct X_PIM             LastReport;

}     X_WIN_PRINTER_FONT,
  *  PX_WIN_PRINTER_FONT,
 ** PPX_WIN_PRINTER_FONT;


#define X_WIN_PRINTER_REQUEST_FORM_FEED          'F'
#define X_WIN_PRINTER_REQUEST_LINE_FEED          'L'
#define X_WIN_PRINTER_REQUEST_TEXT_STRING        'T'
#define X_WIN_PRINTER_REQUEST_FIELD_VALUE        'V'


typedef struct _X_WIN_PRINTER_REQUEST_GENERIC
{
   X_CHAR  chRequest;
   X_FCHAR fchPage[5];
   X_CHAR chEOS;
}    X_WIN_PRINTER_REQUEST_GENERIC,
  *  PX_WIN_PRINTER_REQUEST_GENERIC,
 ** PPX_WIN_PRINTER_REQUEST_GENERIC;

typedef struct _X_WIN_PRINTER_REQUEST_TEXT
{
   X_CHAR  chRequest;
   X_FCHAR fchPage[5];
   X_CHAR  chAlignment;
   X_CHAR  chTrimBlank;
   X_FCHAR fchRow[5];
   X_FCHAR fchColumn[5];
   X_VCHAR vchText[256 + 2];
}    X_WIN_PRINTER_REQUEST_TEXT,
  *  PX_WIN_PRINTER_REQUEST_TEXT,
 ** PPX_WIN_PRINTER_REQUEST_TEXT;

typedef struct _X_WIN_PRINTER_REQUEST_FIELD
{
   X_CHAR  chRequest;
   X_FCHAR fchPage[5];
   X_CHAR  chAlignment;
   X_CHAR  chTrimBlank;
   X_FCHAR fchRow[5];
   X_FCHAR fchColumn[5];
   X_FCHAR fchPrintLength[5];
   X_VCHAR vchValue[256 + 2];
}    X_WIN_PRINTER_REQUEST_FIELD,
  *  PX_WIN_PRINTER_REQUEST_FIELD,
 ** PPX_WIN_PRINTER_REQUEST_FIELD;

#endif

/* ================================================================= */
/*  X_OVERRIDE_LIBRARY: Define_Override_File BIF data structure.     */
/* ================================================================= */

#define X_OVERRIDE_LIBRARY_UPDATE_ALL     'A'
#define X_OVERRIDE_LIBRARY_UPDATE_OWNER   'O'
#define X_OVERRIDE_LIBRARY_UPDATE_TABLE   'T'

typedef struct _X_OVERRIDE_LIBRARY
{
   X_CHAR   chUpdateType;
   X_VCHAR  vchLibrary[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchFile[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchOverrideOwner[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchOverrideTable[X_CTD_OBJECT_NAME_LENGTH + 1];
   struct _X_OVERRIDE_LIBRARY * pPrev;
   struct _X_OVERRIDE_LIBRARY * pNext;

} X_OVERRIDE_LIBRARY;

/* ================================================================= */
/* X_IMPORT_OPTION: Import_Objects BIF options.                      */
/* ================================================================= */

#define X_IMPORT_OPTION_V1    -1

#define X_IMPORT_FILE_LIBRARY_TO_PARTDTALIB     'P'
#define X_IMPORT_IGNORE_FILE_LIBRARY_OVERRIDE   'I'
#define X_IMPORT_APPLY_FILE_LIBRARY_OVERRIDE    'O'

#define X_IMPORT_OPTION_OVERRIDE_LIBRARY_TO_PARTDTALIB   0x00000001
#define X_IMPORT_OPTION_FORCE_OVERRIDE_ALTERNATE_NAME    0x00000002
#define X_IMPORT_OPTION_IGNORE_FILE_LIBRARY_OVERRIDE     0x00000004
#define X_IMPORT_OPTION_APPLY_PACKAGE_SETTING            0x00000008
#define X_IMPORT_OPTION_ALLOW_NAME_CHANGES               0x00000010
#define X_IMPORT_OPTION_VERIFY                           0x00000020
#define X_IMPORT_OPTION_GET_PROMPT_LIB                   0x00000040
#define X_IMPORT_OPTION_FILE_LIBRARY_OVERRIDE_STORED     0x00000080
#define X_IMPORT_OPTION_ALLOW_TYPE_CHANGES               0x00000100

typedef struct _X_IMPORT_OPTION
{
   X_INT32  lVersion;
   X_UINT32 ulSize;
   X_UINT32 ulOptions;

} X_IMPORT_OPTION;

/* ================================================================= */
/*  X_DATA_FILE_XYZ: LANSA table data file structures.               */
/* ================================================================= */

#include "x_strpck.h"

#define X_DATA_FILE_VERSION      -1
#define X_DATA_FILE_VERSION_LL2  -2
#define X_DATA_OAM_VERSION       -1

typedef X_PACKED struct
{
   X_INT32  lVersion;
   X_INT32  lBuildNumber;

} X_DATA_OAM_HEADER;

typedef X_PACKED struct
{
   X_VCHAR  vchTable[X_OBJECT_NAME_LEN + 1];
   X_INT16  sColumns;
   X_INT16  sRecordSize;
   X_INT32  lRecords;

} X_DATA_FILE_HEADER;

typedef X_PACKED struct
{
   X_VCHAR  vchTable[X_OBJECT_NAME_LEN + 1];
   X_INT16  sColumns;
   X_INT16  sRecordSize;
   X_INT32  lRecords;
   X_CHAR   chEyeCatcher;
   X_INT32  lVersion;
   X_INT32  lBuildNumber;
   X_VCHAR  vchRelease[X_BUILD_NUMBER_LEN + 1];
   X_VCHAR  vchDate[X_BUILD_NUMBER_LEN + 1];
   X_VCHAR  vchCopyRight[X_BUILD_NUMBER_LEN + 1];
   X_INT32  lReserve1;
   X_INT32  lReserve2;
   X_CHAR   vchReserve3[X_DESCRIPTION_LEN + 1];

} X_DATA_FILE_HEADER_EX;

typedef X_PACKED struct
{
   X_VCHAR  vchColumn[X_OBJECT_NAME_LEN + 1];
   X_CHAR   chType;
   X_INT16  sByteLen;

} X_DATA_FILE_COLUMN;

typedef X_PACKED struct
{
   X_VCHAR     vchColumn[X_OBJECT_NAME_LEN + 1];
   X_TYPE_FLAG chType;
   X_INT16     sByteLen;
   X_TYPE_FLAG chSubType;
   X_YES_NO    chDBCS;
   X_INT16     sLength;
   X_INT16     sDecimal;
   X_UINT32    lReserve1;
   X_INT32     lReserve2;
   X_CHAR      vchReserve3[X_DESCRIPTION_LEN + 1];

} X_DATA_FILE_COLUMN_EX;

typedef struct
{
   X_BOOL                     fMapped;
   X_DATA_FILE_COLUMN_EX   *  pDatColumn;
   X_DATA_FILE_COLUMN_EX   *  pOamColumn;
   X_PVCHAR                   pvchDatBuffer;
   X_PVCHAR                   pvchOamBuffer;

} X_DATA_MAPPING;

typedef struct
{
   X_BOOL                     fMapped;
   X_DATA_FILE_COLUMN_EX   *  pDatColumn;
   X_DATA_FILE_COLUMN_EX   *  pOamColumn;
   X_PVCHAR                   pvchDatBuffer;
   X_PVCHAR                   pvchOamBuffer;
   XFIELDSTATE             *  pXFieldState;

} X_DATA_MAPPING_EX;

#include "x_endpck.h"

typedef struct
{
   X_UINT32 ulCurrLen;
   X_UINT32 ulAllocLen;
   X_PVOID  pvBuffer;

} X_DATA_X_VAR;

/* ================================================================= */
/*  X_PROCESS_INSTANCE : Process instance tracking assignment        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Version Number                                    */
/* pX_Ids          Pointer to associated / linked X_IDS              */
/* CurrInvoc       Current Invocation Level Value                    */
/* pPrevInst       Previous Instance                                 */
/* pNextInst       Next Instance                                     */
/* pX_Pro          Pointer to X_PRO structure                        */
/* pX_ProFunc      Pointer to X_PROFUNC structure                    */
/* pX_FKeyLang     Pointer to X_FKEY_LANG structure                  */
/* pX_FKey         Pointer to X_FKEY structure                       */

#define X_PROCESS_INSTANCE_VERSION     -2

struct X_PROCESS_INSTANCE
  {
     X_SHORT                         sVersion;
     struct  X_IDS                 * pX_Ids;
     X_SHORT                         sCurrInvoc;
     struct  X_PROCESS_INSTANCE    * pPrevInst;
     struct  X_PROCESS_INSTANCE    * pNextInst;
     struct  X_PRO                 * pX_Pro;
     X_SHORT                         scX_ProFunc;
     struct  X_PROFUNC             * pX_ProFunc;
     struct  X_FKEY_LANG           * pX_FKeyLang;
     struct  X_FKEY                * pX_FKey;
  };

/* ================================================================= */
/*  X_GENERIC_INSTANCE : Generic instance tracking assignment        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pX_Ids          Pointer to associated / linked X_IDS              */
/* pPrevInst       Previous Instance                                 */
/* pNextInst       Next Instance                                     */
/* InstanceLen     Instance Length                                   */
/* InstanceData    Pointer to Instance Data                          */


struct X_GENERIC_INSTANCE
  {
     struct  X_IDS                 * pX_Ids;
     struct  X_GENERIC_INSTANCE    * pPrevInst;
     struct  X_GENERIC_INSTANCE    * pNextInst;
     X_ULONG                         lInstanceLen;
     X_PVOID                         pInstanceData;
  };

/*===================================================================*/
/* FUNCTION_INSTANCE : Function instance tracking                    */
/*===================================================================*/

#define X_FUNCTION_INSTANCE_VERSION     -1

struct X_FUNCTION_INSTANCE
   {
     X_SHORT                         sVersion;
     struct X_FUNCTION_INSTANCE      * pNextInstance;
     struct X_IDS                    * pX_Ids_Identifier;
     struct X_FUN                    * pX_Fun;
     struct X_FLD                    * pX_Fld;
     X_LIST_VOID                     * pX_List;
     struct X_FKEY                   * pX_FKey;
     struct FUNCTION_STATIC_GLOBAL_1 * pGlobal1;
     struct FUNCTION_STATIC_GLOBAL_2 * pGlobal2;
   };


/* ================================================================= */
/*  X_ENTRY_POINT : Track DLL entry points                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Entry Point Name                                  */
/* Address         Entry Point Address                               */


#define X_DLL_TYPE_PROCESS           '\x01'
#define X_DLL_TYPE_FUNCTION          '\x02'
#define X_DLL_TYPE_OAMODULE          '\x03'
#define X_DLL_TYPE_UBIF              '\x04'
#define X_DLL_TYPE_DBMS              '\x05'
#define X_DLL_TYPE_COMMS             '\x06'
#define X_DLL_TYPE_USERFUNCTION      '\x07'
#define X_DLL_TYPE_PCXFUNCTION       '\x08'
#define X_DLL_TYPE_COMPONENT         '\x09'
#define X_DLL_TYPE_COMPONENT_MANAGER '\x10'
#define X_DLL_TYPE_LSERVER_MANAGER   '\x11'
#define X_DLL_TYPE_SSERVER_MANAGER   '\x12'
#define X_DLL_TYPE_UIM_MANAGER       '\x13'
#define X_DLL_TYPE_COMPONENT_DESIGN  '\x14'
#define X_DLL_TYPE_RDMLX_FUNCTION    '\x15'
#define X_DLL_TYPE_DEBUG_MANAGER     '\x16'
#define X_DLL_TYPE_RPG_FUNCTION      '\x17'
#define X_DLL_TYPE_WEB_RUNTIME       '\xF0'

#define X_DLL_TYPE_ANY               '\xFF'



#ifdef X_DLL_TRACKING_INFO

struct X_ENTRY_POINT
  {
     X_VCHAR       vchName[X_DLL_ENTRY_POINT_NAME_LENGTH  + 1];
     X_PFN         pfnAddress;
  };



/* ================================================================= */
/*  X_DLL : Tracks DLLs that are loaded and used                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* NextDLL         Pointer to the next DLL's details in the chain    */
/* Type            Class of DLL as defined by X_DLL_TYPE_xxxxxxxxxx  */
/* NameLength      Length of DLL Name for faster searches            */
/* Name            Name that DLL is loaded / known by                */
/* DLLHandle       Handle to DLL                                     */
/* Loaded          Currently Loaded                                  */
/* UsageCount      Usage Count (to handle recursive calls/loads)     */
/* EntryPoints     Number of known entry points                      */
/* EntryPoint      Array of entry point details                      */
/* SelfShutDown    DLL is a process or function with shutdown support*/

typedef struct X_DLL
{
   X_CHAR                   chType;
   X_USHORT                 usNameLength;
   X_VCHAR                  vchName[X_DLL_QUALIFIED_NAME_LENGTH  + 1];
   X_MODULEHANDLE           hDLLHandle;
   X_BOOL                   fLoaded;
   X_LONG                   lUsageCount;
   X_USHORT                 usEntryPoints;
   struct X_ENTRY_POINT     EntryPoint[X_DLL_MAXIMUM_ENTRY_POINTS ];
   X_BOOL                   fSelfShutDown;
   X_ULONG                  ulLoadModuleProcessOrder;
}
   *pX_DLL,
   **ppX_DLL;

#endif


#ifdef X_ENVIRON_INFO


/* -------------------------------------------------------------- */
/*  X_ENVIRON details                                             */
/* -------------------------------------------------------------- */

#if defined(X_OPERATING_SYSTEM_UNIX)
   #define X_ENVIRON_FILE "/x_lansa/x_bldenv.dat"
#else
   #define X_ENVIRON_FILE "\\X_LANSA\\X_BLDENV.DAT"
#endif

#define X_ENVIRON_CONTEXT_MAXIMUM     5
#define X_ENVIRON_CONTEXT_TYPE_LENGTH 3
#define X_ENVIRON_CONTEXT_TYPE_CRT    "CRT"
#define X_ENVIRON_CONTEXT_TYPE_OAM    "OAM"
#define X_ENVIRON_CONTEXT_TYPE_PRO    "PRO"
#define X_ENVIRON_CONTEXT_TYPE_FUN    "FUN"
#define X_ENVIRON_CONTEXT_TYPE_FSQ    "FSQ"

#define X_ENVIRON_NAME_LENGTH         80

#define X_ENVIRON_TYPE_LENGTH         4
#define X_ENVIRON_TYPE_OS2            "OS2"
#define X_ENVIRON_TYPE_W31            "W31"
#define X_ENVIRON_TYPE_W95            "W95"
#define X_ENVIRON_TYPE_W32            "W32"
#define X_ENVIRON_TYPE_W64            "W64"
#define X_ENVIRON_TYPE_AIX            "AIX"
#define X_ENVIRON_TYPE_UNIX           "UNIX"
#define X_ENVIRON_TYPE_DEC            "DEC"
#define X_ENVIRON_TYPE_HPUX           "HPUX"
#define X_ENVIRON_TYPE_IS             "IS"

#define X_ENVIRON_TYPE_TRANS_FILE_SUFFIX_LENGTH    4
#define X_ENVIRON_TYPE_OS2_TRANS_FILE_SUFFIX       "os2"
#define X_ENVIRON_TYPE_W31_TRANS_FILE_SUFFIX       "w31"
#define X_ENVIRON_TYPE_W95_TRANS_FILE_SUFFIX       "w95"
#define X_ENVIRON_TYPE_IS_TRANS_FILE_SUFFIX        "is"
#define X_ENVIRON_TYPE_UNX_TRANS_FILE_SUFFIX       "unx"

#define X_ENVIRON_DBNM_LENGTH         20

#define X_ENVIRON_DBTP_LENGTH         10
#define X_ENVIRON_DBTP_DB2            "DB2"
#define X_ENVIRON_DBTP_ODBC           "ODBC"

#define X_ENVIRON_VALUE_LENGTH        256

#define X_ENVIRON_VALUE_MAXIMUM       9

/*  Moved before ids definition for use there */
/* #define X_ENVIRON_MAXIMUM_LANGUAGES   20   */

struct X_ENVIRON_DBCS
{
  X_CHAR achExists[256];
  X_CHAR achByte1[256];
  X_CHAR achByte2[256];
};

struct X_ENVIRON_TRANSLATE_TABLE
{
  X_VCHAR     vchLangCode[X_LANGUAGE_CODE_LEN + 1];
  X_TYPE_FLAG chLangType;
  X_BOOL      fSBCSModified;
  X_BOOL      fDBCSModified;
  X_CHAR      achSBCS[256];
  X_CHAR      chDBCSPossible;
  struct      X_ENVIRON_DBCS *pDBCS[256];
};


struct X_ENVIRON_VALUE
{
   X_VCHAR  vchVALUE[X_ENVIRON_VALUE_LENGTH + 1];
};

struct X_ENVIRON_CONTEXT
{
   X_VCHAR  vchTYPE[X_ENVIRON_CONTEXT_TYPE_LENGTH + 1];
   X_BOOL   bENAB;
   struct   X_ENVIRON_VALUE SKLx[X_ENVIRON_VALUE_MAXIMUM];
   struct   X_ENVIRON_VALUE FILx[X_ENVIRON_VALUE_MAXIMUM];
   struct   X_ENVIRON_VALUE CMDx[X_ENVIRON_VALUE_MAXIMUM];
};

struct X_ENVIRON
{
   X_BOOL   bPRIM;
   X_VCHAR  vchTYPE[X_ENVIRON_TYPE_LENGTH + 1];
   X_VCHAR  vchTransFileSuffix[X_ENVIRON_TYPE_TRANS_FILE_SUFFIX_LENGTH];
   X_VCHAR  vchNAME[X_ENVIRON_NAME_LENGTH + 1];
   X_VCHAR  vchDRIV[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR  vchPATH[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR  vchDBNM[X_ENVIRON_DBNM_LENGTH + 1];
   X_VCHAR  vchDBTP[X_ENVIRON_DBTP_LENGTH + 1];
   X_BOOL   bENAB;
   X_BOOL   b16BC;
   struct   X_ENVIRON_CONTEXT ENV[X_ENVIRON_CONTEXT_MAXIMUM];
   struct   X_ENVIRON * pNextEnv;
   X_SHORT  sTotalTT;
   struct   X_ENVIRON_TRANSLATE_TABLE TT[X_ENVIRON_MAXIMUM_LANGUAGES];
};

struct X_ENVIRON_OBJECT
{
   X_VCHAR vchPART[3+1];
   X_VCHAR vchLANG[4+1];
   X_VCHAR vchOBJT[3+1];
   X_VCHAR vchOBJN[10+1];
   X_VCHAR vchOBJE[10+1];
   X_VCHAR vchOBJC[10+1];
   X_VCHAR vchMODC[10+1];
   X_VCHAR vchMODD[40+1];
   X_VCHAR vchOBJD[40+1];
   X_BOOL  bDBUG;
   X_BOOL  bKEEP;
   X_SHORT sComponents;
};


#endif



/* ===================================== */
/* XDB_ DBF File production definitions  */
/* ===================================== */

#ifdef XDB_FILE_SUPPORT


#include "x_strpck.h"


   #define  SIZE_FLDNAME             11
   #define  SIZE_FIELDVAL           254      /* TN :DBF supports up to 254 bytes ( Character type ) ONLY */
   #define  SIZE_DECIMALS           256

   #define  FIELD_TABLE_TERMINATOR  0x0d
   #define  VALID_HDR_TYPE          0x03
   #define  VALID_HDR_MEMO_TYPE     0x83

   typedef  char              LX_CHAR  ;
   typedef  unsigned char     LX_BYTE  ;
   typedef  int               LX_INT32 ;
   typedef  unsigned int      LX_BOOL  ;
   typedef  unsigned int      LX_UINT32;
   typedef  short             LX_INT16 ;
   typedef  unsigned short    LX_UINT16;

   #define  MAX_DBASE_FILES         20


   typedef struct _DBF_DATE
   {
      LX_CHAR                 m_Year;
      LX_CHAR                 m_Month;
      LX_CHAR                 m_Day;
   }
      DBF_DATE,
   * PDBF_DATE;

   typedef struct _DB_HDR
   {
      LX_BYTE                 m_ValidType          ;
      DBF_DATE                m_DateYYMMDD;
      LX_INT32                m_NumTableRecords    ;
      LX_INT16                m_NumBytesInHeader   ;
      LX_INT16                m_NumBytesInRecord   ;
      LX_BYTE                 m_Reserved1          [   3 ];
      LX_BYTE                 m_Reserved2          [  13 ];
      LX_BYTE                 m_Reserved3          [   4 ];
   }
      DB_HDR,
   * PDB_HDR;

   typedef struct _DB_TFHDR
   {
      DB_HDR                  m_DataBaseHdr        ;
   }
      DB_TFHDR,
   * PDB_TFHDR;


   typedef struct _FIELDTABLE
   {
      LX_BYTE                 m_FieldName          [ SIZE_FLDNAME ];
      LX_BYTE                 m_FieldType          ;
      LX_BYTE                 m_FieldLength        ;
      LX_BYTE                 m_FieldDecimals  ;
   }
      FIELDTABLE,
   * PFIELDTABLE;


   typedef struct _DB_FIELD
   {
      LX_BYTE                 m_FieldName          [ SIZE_FLDNAME ];
      LX_BYTE                 m_FieldType          ;
      LX_BYTE                 m_Reserved1          [ 4  ];
      LX_BYTE                 m_FieldLength        ;
      LX_BYTE                 m_FieldDecimalCount  ;
      LX_BYTE                 m_Reserved2          [ 2  ];
      LX_BYTE                 m_WorkAreaID         ;
      LX_BYTE                 m_Reserved3          [ 10 ];
      LX_BYTE                 m_MDXfieldFlag       ;
   }
      DB_FIELD,
   * PDB_FIELD;

   typedef struct _DBASE_FIELD
   {
      LX_INT32                m_BufferPosition;
      LX_INT32                m_BufferLength;
      DB_FIELD                m_Field;
   }
      DB_FLD,
   * PDB_FLD;



   typedef struct _DBASE_CONTROLLER
   {
      PDB_TFHDR               m_TableFileHeader;
      FILE                 *  m_FileHandle;
      LX_BOOL                 m_bOpenForRead;
      LX_BOOL                 m_bOpenForWrite;
      LX_INT32                m_CurrFilePos;
      LX_INT32                m_StartOfRecs;
      LX_INT32                m_RecordSize;
      LX_INT32                m_RecordCount;
      LX_INT32                m_CurrRow;
      LX_INT32                m_CurrFieldPos;
      LX_BOOL                 m_bAtEndOfFile;
      PDB_FLD               * m_pFieldTable;
      LX_INT32                m_FieldCount;
      LX_BYTE               * m_RecordBuffer;
      LX_INT32                m_CurrState;
      LX_BOOL                 m_bHeaderWritten;
      LX_BOOL                 m_bFieldsWritten;
   }
      DB_C,
   * PDB_C;


   typedef struct _DB_ADMIN
   {
      DB_C                 *  m_ControllerList[MAX_DBASE_FILES];
   }
      DB_ADMIN,
    * PDB_ADMIN;


#include "x_endpck.h"


#endif



/* ================================================================= */
/* The following macros are for expanding process alias values       */
/* They are defined as macros as they are used by the LXR and LXG    */
/* familiy of programs                                               */
/* ================================================================= */

#define X_PROCESS_ALIAS_UNLOAD(_P) \
if (_P != NULL) \
{ \
   free(_P); \
   _P = NULL; \
}


#define X_PROCESS_ALIAS_LOAD_STR(_P) \
for (i = 0; i < X_PROCESS_ALIAS_SUBSTR; i++) \
{ \
   pvchS = pvchE + 1; \
   pvchE = strchr(pvchS,','); \
   if (pvchE != NULL) pvchE[0] = '\x00'; \
   _P[e].asSPos[i] = atoi(pvchS); \
   pvchS = pvchE + 1; \
   pvchE = strchr(pvchS,','); \
   if (pvchE != NULL) pvchE[0] = '\x00'; \
   _P[e].asSLen[i] = atoi(pvchS); \
}


#define X_PROCESS_ALIAS_LOAD(_F,_P) \
if (_P == NULL) \
{ \
    FILE *pFile = NULL; \
    pFile = fopen( _F, "rb" ); \
    if (pFile != NULL) \
    { \
       X_SHORT  e = 0; \
       X_VCHAR  vchLine[80]; \
       X_PVCHAR pvchS; \
       X_PVCHAR pvchE; \
       X_SHORT  i; \
       X_CHAR   chChar; \
       _P = (struct X_PROCESS_ALIAS *) malloc(X_PROCESS_ALIAS_MAX * sizeof(struct X_PROCESS_ALIAS)); \
       memset((char *) _P,'\x00',(X_PROCESS_ALIAS_MAX * sizeof(struct X_PROCESS_ALIAS))); \
       memset(vchLine,'\x00',sizeof(vchLine)); \
       fgets (vchLine,sizeof(vchLine), pFile); \
       while ( (!feof(pFile)) && (!ferror(pFile)) ) \
       { \
          if (vchLine[0] != '*') \
          { \
             pvchS = &vchLine[0]; \
             pvchE = strchr(pvchS,','); \
             pvchE[0] = '\x00'; \
             strcpy(_P[e].vchMask,pvchS); \
             _P[e].sMaskLen = X_SHORT_SIZE_T_CAST( strlen(_P[e].vchMask) ); \
             for (i = 0; i < _P[e].sMaskLen; i++) \
             { \
                chChar = toupper(_P[e].vchMask[i]); \
                _P[e].vchMask[i] = chChar; \
             } \
             X_PROCESS_ALIAS_LOAD_STR(_P) \
             e++; \
          } \
          memset(vchLine,'\x00',sizeof(vchLine)); \
          fgets (vchLine,sizeof(vchLine), pFile); \
       } \
       fclose(pFile); \
    } \
}

#define X_PROCESS_ALIAS_CHECK(_P, _O, _N, _L) \
strcpy(_N,_O); \
if (_P != NULL) \
{ \
   X_CHAR  chMatch; \
   X_SHORT i; \
   X_SHORT j; \
   X_SHORT sOldLen =  X_SHORT_SIZE_T_CAST( strlen(_O) ); \
   for (i = 0; ((i < X_PROCESS_ALIAS_MAX) && (_P[i].sMaskLen > 0)); i++) \
   { \
      if (_P[i].sMaskLen == sOldLen) \
      { \
         chMatch = 'Y'; \
         for (j = 0; j < sOldLen; j++) \
         { \
           if ((_P[i].vchMask[j] != '\?') && (_P[i].vchMask[j] != _N[j])) \
           { \
              chMatch = 'N'; \
              break; \
           } \
         } \
         if (chMatch == 'Y') \
         { \
            short k = 0; \
            memset(_N,'\x00',_L); \
            for (j = 0; j < X_PROCESS_ALIAS_SUBSTR; j++) \
            { \
               if ((_P[i].asSPos[j] > 0) && (_P[i].asSLen[j] > 0)) \
               { \
                  memcpy(&(_N[k]),&(_O[_P[i].asSPos[j]-1]),_P[i].asSLen[j]); \
                  k = k + _P[i].asSLen[j]; \
               } \
            } \
            break; \
         } \
      } \
   } \
}

/* -------------------------------------------------------------- */
/*  X_LICENCE details                                             */
/* -------------------------------------------------------------- */
#define X_LICENCE_KEY_FILE_NAME "x_lickey.dat"

#define X_LICENCE_GET   '\x00'
#define X_LICENCE_DROP  '\x10'
#define X_LICENCE_SHOW  '\x20'
#define X_LICENCE_CHECK '\x40'

#define X_LICENCE_OKAY           '\x00'
#define X_LICENCE_INVALID        '\x10'
#define X_LICENCE_NOT_AVAILABLE  '\x20'
#define X_LICENCE_VALID          '\x01'
#define X_LICENCE_NOT_YET_VALID  '\x02'
#define X_LICENCE_EXPIRED        '\x03'



#define X_FILE_TYPE_FILE 'F'
#define X_FILE_TYPE_DIR  'D'

/* -------------------------------------------------------------- */
/*  Value Validation Macro.                                       */
/* -------------------------------------------------------------- */

#define X_VALID_VALUE_YES     0x0001
#define X_VALID_VALUE_NO      0x0002
#define X_VALID_VALUE_DYNAMIC 0x0004
#define X_VALID_VALUE_ALL     0xFFFF

#define X_VALIDATE_VALUE( chValue, ulFlags, chDefault )  \
      ( ( ( ( ulFlags ) & X_VALID_VALUE_YES ) && ( chValue == YES ) )  \
      || ( ( ( ulFlags ) & X_VALID_VALUE_NO ) && ( chValue == NO ) )   \
      || ( ( ( ulFlags ) & X_VALID_VALUE_DYNAMIC ) && ( chValue == DYNAMIC ) ) ) ? chValue : chDefault

/* ---------------------------------------------------------------- */
/* Space tracking structures used just by routines in this function */
/* ---------------------------------------------------------------- */


#define X_SPACE_TEMP_LENGTH    (17 * 16) /* Must ALWAYS be an exact multiple of 16 bytes that is > X_MAX_ALPHA_FIELD_LEN + 1 */
#define X_SPACE_MAXIMUM_KEYS    20
#define X_SPACE_MAXIMUM_ITEMS   20
#define X_SPACE_MAXIMUM_COLUMNS 20

typedef struct _X_SPACE_COLUMN
{
   X_INT          iLength;
   X_CHAR         chMapType;
   int            iTreeType;
   struct X_FLD   X_Fld;

}      X_SPACE_COLUMN,
  *   PX_SPACE_COLUMN,
  ** PPX_SPACE_COLUMN;


typedef struct _X_SPACE_ENTRY
{
   X_ULONG ulTotalColumns;
   X_ULONG aulColumnNumber[X_SPACE_MAXIMUM_COLUMNS];
   X_BOOL  afIsKeyColumn[X_SPACE_MAXIMUM_COLUMNS];
   X_ULONG ulTotalKeys;
   struct  _X_SPACE_COLUMN   Key[X_SPACE_MAXIMUM_KEYS];
   X_ULONG ulTotalItems;
   struct  _X_SPACE_COLUMN   Item[X_SPACE_MAXIMUM_ITEMS];
   X_PVOID pvUserSpaceTree;

}      X_SPACE_ENTRY,
  *   PX_SPACE_ENTRY,
  ** PPX_SPACE_ENTRY;


#if defined X_OPERATING_SYSTEM_PASE
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "iSeries PASE";
#elif defined X_OPERATING_SYSTEM_AIX
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "AIX";
#elif defined X_OPERATING_SYSTEM_WIN
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         if (X_PDF_Get_Version() == X_OS_TYPE_WINNT) \
         { \
            static char szOSVersion[ 256 + 1]; \
            int            numProc=0; \
            int            numBits=0; \
            _XOPENV = szOSVersion; \
            getOSVerString ( szOSVersion, &numProc , &numBits); \
         } \
         else \
            _XOPENV = "Windows 95/98/Me Unsupported";
      
#elif defined X_OPERATING_SYSTEM_ISERIES
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "iSeries";
#elif defined X_OPERATING_SYSTEM_SOL
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "Solaris";
#elif defined X_OPERATING_SYSTEM_LNX
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "Linux";
#elif defined X_OPERATING_SYSTEM_IOS
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "iOS";
#elif defined X_OPERATING_SYSTEM_ANDROID
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "Android";
#elif defined X_OPERATING_SYSTEM_JAVASCRIPT
#define X_GET_OPERATING_ENVIRONMENT(_XOPENV) \
         _XOPENV = "JavaScript";
#else
#error Specify _XOPENV for this new platform!
#endif

/* ================================================================= */
/*  FNHELPLINE : Callback to process a Help Line for LANSA/Server    */
/* ================================================================= */

typedef X_BOOL_FUNCTION FNHELPLINE (struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    X_PVOID,
                                    X_PVCHAR );
typedef FNHELPLINE *PFNHELPLINE;

/* ===================================================================== */
/* Formats for X_Vec_Encode_from_String() and X_Vec_Decode_from_String() */
/* ===================================================================== */
#define X_ENCODE_FORMAT_SQL_WITH_SUTC  "SS" /* SQL Format for Datetime based on SUTC */
#define X_ENCODE_FORMAT_SQL_WITH_UTC   "SU" /* SQL Format for Datetime in UTC */
#define X_ENCODE_FORMAT_SQL_WITH_LOCAL "SL" /* SQL Format for Datetime in local time */
#define X_ENCODE_FORMAT_ISO_8601       "I8" /* Format for Datetime in ISO 8601 */

/* ====================================================== */
/*  Panel Field Flags for X_ValidateFieldAssign()         */
/*  Copied from x_uimstr.h which cannot be included here  */
/* ====================================================== */
#define X_FIELDFLAGS_INPUT_AB   0x0008
#define X_FIELDFLAGS_INPUT_LC   0x0010
#define X_FIELDFLAGS_INPUT_M10  0x0020
#define X_FIELDFLAGS_INPUT_M11  0x0040
#define X_FIELDFLAGS_INPUT_RA   0x0080
#define X_FIELDFLAGS_INPUT_RB   0x0100
#define X_FIELDFLAGS_INPUT_RZ   0x0200
#define X_FIELDFLAGS_INPUT_VN   0x0400
#define X_FIELDFLAGS_INPUT_ME   0x4000
#define X_FIELDFLAGS_INPUT_MF   0x8000

/* ================================================================= */
/*  X_PARM_BLOCK:  Stores parameter blocks for requests to call      */
/*                 3GL programs. (This used to be in x_lsvstr.h)     */
/* ================================================================= */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Direction       Parameter block direction (ID_PAR_PASS,           */
/*                  ID_PAR_BOTH, ID_PAR_RETURN).                     */
/* Len             Parameter block length.                           */
/* Data            Pointer to parameter block data.                  */
/*-------------------------------------------------------------------*/

#ifdef X_OPERATING_SYSTEM_UNIX
#include "x_strpck.h"
#endif

typedef X_PACKED struct
{
   X_UCHAR    chDirection;
   X_SHORT    sLen;
}  X_PARM_BLOCK_HDR;

typedef struct
{
   X_PVCHAR   pfchData;
}  X_PARM_BLOCK;

#ifdef X_OPERATING_SYSTEM_UNIX
#include "x_endpck.h"
#endif


/* ======================================================================= */
/*  X_FUN_VECTOR_ASSIGN_FUNCTION : Prototype of Vector Assignment Function */
/* ======================================================================= */

#if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_ISERIES)

   typedef
      void X_FUN_VECTOR_ASSIGN_FUNCTION   (
         struct X_IDS                     *  pX_Ids,
         struct X_PRO                     *  pX_Pro,
         struct X_FUN                     *  pX_Fun,
         struct X_FLD                     *  pX_FldSrc,
         X_SHORT                             sVectorSrc,
         struct X_FLD                     *  pX_FldTgt,
         X_SHORT                             sVectorTgt );

#else

   typedef
      void __cdecl X_FUN_VECTOR_ASSIGN_FUNCTION (
         struct X_IDS                           *  pX_Ids,
         struct X_PRO                           *  pX_Pro,
         struct X_FUN                           *  pX_Fun,
         struct X_FLD                           *  pX_FldSrc,
         X_SHORT                                   sVectorSrc,
         struct X_FLD                           *  pX_FldTgt,
         X_SHORT                                   sVectorTgt );

#endif

typedef X_FUN_VECTOR_ASSIGN_FUNCTION   *   PX_FUN_VECTOR_ASSIGN_FUNCTION;
typedef X_FUN_VECTOR_ASSIGN_FUNCTION   **  PPX_FUN_VECTOR_ASSIGN_FUNCTION;

/* Max Export version supported */
#define X_EXPORT_MAX_VERSION_TEXT "003"

/* Centralise code for getting X60CHR into UTC_LANGUAGE */
#define X_SET_CCSIDS_FROM_CHARSET(_FROMSTR,_TO_UTCLANG) \
   X_Remove_Blanks( pX_Ids, pX_Pro, pX_Fun, _FROMSTR, X_STRIP_BLANKS_TRAILING ); \
   strncpy( (_TO_UTCLANG)->sziSeriesCCSID, _FROMSTR, UTC_X60_CCSID_LEN ); \
   if ( strlen(_FROMSTR) > UTC_X60_CCSID_LEN ) \
   { \
      /* Windows CCSID is set */ \
      strncpy( (_TO_UTCLANG)->szWindowsCCSID, _FROMSTR + UTC_X60_CCSID_LEN, UTC_X60_CCSID_LEN ); \
   }

/* Centralise code for converting X_LANGUAGE into UTC_LANGUAGE */
#define X_SET_UTC_LANG_FROM_X_LANG(_FROM_X_LANG,_TO_UTCLANG) \
{ \
   X_VCHAR vchCharSet[UTC_X60CHR_LEN + 1]; \
   strcpy((_TO_UTCLANG)->szLanguage,(_FROM_X_LANG)->vchLangCode); \
   if ( (_TO_UTCLANG)->szLanguage[X_LANGUAGE_CODE_LEN - 1] == BLANK ) \
   { \
      (_TO_UTCLANG)->szLanguage[X_LANGUAGE_CODE_LEN - 1] = LOVAL; \
   } \
   switch ((_FROM_X_LANG)->chLangType) \
   { \
      case X_LANGUAGE_DBCS: \
         (_TO_UTCLANG)->chDBCS = YES; \
         (_TO_UTCLANG)->chRLT  = NO; \
         break; \
      case X_LANGUAGE_RLTB: \
         (_TO_UTCLANG)->chDBCS = NO; \
         (_TO_UTCLANG)->chRLT  = YES; \
         break; \
      default: \
         (_TO_UTCLANG)->chDBCS = NO; \
         (_TO_UTCLANG)->chRLT  = NO; \
         break; \
   } \
   strcpy( vchCharSet, (_FROM_X_LANG)->vchCharSet ); \
   X_SET_CCSIDS_FROM_CHARSET(vchCharSet,_TO_UTCLANG) \
}

/* ================================================================  */
/* Macro       : X_GET_INDEX_DIRECT                                  */
/* Description : Get the pField of a vector                          */
/* Arguments   :  _PTR[out] = will points to pField                  */
/*                _FLD[in]  = pointer to field vector                */
/*                _XFLD[in] = vector array                           */
/*                _VEC[in]  = vector number                          */
/*               _SZ = size of the data                              */
/* ================================================================  */

#ifdef X_VAR_SUPPORT /* VAR Support exists */

#ifdef X_OPERATING_TARGET_CSHARP

#define X_GET_INDEX_DIRECT(_PFIELDTOGET, _PFLD, _XFLD, _VEC)                                          \
{                                                                                                     \
   if ( _PFLD[0]->chSubType == X_SUBTYPE_COMPONENT_EVALUATION)                                        \
   {                                                                                                  \
      _PFLD[0] = X_VAR_DLL.X_VAR_ResolveEvaluationVariable( pX_Ids, pX_Pro, pX_Fun, (_XFLD), (_VEC) );\
      _PFIELDTOGET.X_FLD = _PFLD[0];                                                                  \
   }                                                                                                  \
   else if ( _PFLD[0]->chSubType == X_SUBTYPE_ARRAY )                                                 \
   {                                                                                                  \
      _PFIELDTOGET.X_FLD = X_VAR_DLL.X_Vec_Apply_Index (pX_Ids, pX_Pro, pX_Fun, (_XFLD), (_VEC));     \
   }                                                                                                  \
   else                                                                                               \
   {                                                                                                  \
      _PFIELDTOGET.X_FLD = _PFLD[0];                                                                  \
   }                                                                                                  \
}

#else

#define X_GET_INDEX_DIRECT(_PTR, _FLD, _XFLD, _VEC) \
{ \
   if ( (_FLD)->chSubType == X_SUBTYPE_COMPONENT_EVALUATION) \
   { \
      (_FLD) = X_VAR_ResolveEvaluationVariable( pX_Ids, pX_Pro, pX_Fun, (_XFLD), (_VEC) ); \
      (_PTR) = (_FLD)->pField; \
   } \
   else if ((_FLD)->chSubType == X_SUBTYPE_ARRAY) \
        (_PTR) = X_Vec_Apply_Index (pX_Ids, pX_Pro, pX_Fun, (_XFLD), (_VEC)); \
   else \
        (_PTR) = (_FLD)->pField; \
}

#endif // X_OPERATING_TARGET_CSHARP

#else  /* VAR Support exists */

#define X_GET_INDEX_DIRECT(_PTR, _FLD, _XFLD, _VEC) \
{ \
   if ((_FLD)->chSubType == X_SUBTYPE_ARRAY) \
        (_PTR) = X_Vec_Apply_Index (pX_Ids, pX_Pro, pX_Fun, (_XFLD), (_VEC)); \
   else \
        (_PTR) = (_FLD)->pField; \
}

#endif  /* !VAR Support exists */

/* ================================================================  */
/* Macro       : X_GET_DATA_STORAGE_POINTER                          */
/* Description : Get the pointer to the data of a field, the field   */
/*               can be LL1 or LL2                                   */
/*             If the field is LL1 it is just a copy of the old      */
/*             pField pointer                                        */
/*                                                                   */
/* Arguments   : _FLD[in] = pointer to field vector                  */
/*                                                                   */
/*               _PTR[in] = the pField of the field                  */
/*               _PTR1[out]= Pointer to the actual data of the field */
/*                                                                   */
/* Note:       To simplify the macro the pointer to the data area    */
/*             for INTEGER, FLOAT and BOOLEAN is calculated in one   */
/*             way like it is done for LL2 SIGNED                    */
/* ================================================================  */


/* Components require some differences in this macro */
#ifdef LP__HPP
   #define X_BEGIN_STORAGE_POINTER( _FLD )

   #define X_FATAL_STORAGE_POINTER \
   return ( LpVarFrame::FatalError( "X_TEXT(162)" ) );

#else
   #define X_BEGIN_STORAGE_POINTER( _FLD )\
   /* if it is a Component we should refresh it first to get the right value from component side */\
   if ( X_VECTOR_FIELD_IS_COMPONENT((_FLD), 0))\
   {\
      X_Refresh_Field_Value(  pX_Ids, pX_Pro, pX_Fun, (_FLD));\
   }

   #define X_FATAL_STORAGE_POINTER \
   X_Fatal_Error( pX_Ids,\
                  pX_Pro,\
                  pX_Fun,\
                  pvchRoutine,\
                  X_TEXT(162));

#endif

#define X_GET_DATA_STORAGE_POINTER_WIDECHAR(_PTR1, _PTR, _FLD) \
{ \
   if ((X_VECTOR_FIELD_IS_CHAR((_FLD), 0) ) || (X_COMPONENT_FIELD_IS_CHAR((_FLD), 0))) \
   { \
      X_BEGIN_STORAGE_POINTER( (_FLD) ) \
      if ( X_FLD_CHAR_HAS_WIDECHAR(_PTR) ) \
      { \
         X_VAR_VarChar_GetAsUtf16Vchar(pX_Ids,pX_Pro,pX_Fun, (X_FLD_CHAR*)(_PTR),(X_UTF16_VCHAR **)&(_PTR1)); \
      } \
      else \
      { \
         X_GET_DATA_STORAGE_POINTER(_PTR1, _PTR, _FLD) \
      } \
   } \
   else \
   { \
      X_GET_DATA_STORAGE_POINTER(_PTR1, _PTR, _FLD) \
   } \
}

#ifdef X_OPERATING_TARGET_CSHARP

#define X_GET_DATA_STORAGE_POINTER(_PTR1, _PTR, _FLD)                                                          \
{                                                                                                              \
   /*X_GET_DATA_STORAGE_POINTER*/                                                                              \
   X_BEGIN_STORAGE_POINTER( _FLD )                                                                             \
}

#else

#define X_GET_DATA_STORAGE_POINTER(_PTR1, _PTR, _FLD) \
{ \
 \
   X_BEGIN_STORAGE_POINTER( (_FLD) ) \
   if X_VECTOR_FIELD_IS_LL2((_FLD), 0) \
   {  \
      if (( X_VECTOR_FIELD_IS_BOOLEAN((_FLD), 0) )       || (X_COMPONENT_FIELD_IS_BOOLEAN((_FLD), 0)) )  \
      { \
         (_PTR1) = (X_PVCHAR)(((PX_FLD_SIGNED)(_PTR))->fchData) ; \
      } \
      else if ( (X_VECTOR_FIELD_IS_SIGNED((_FLD), 0))    || (X_COMPONENT_FIELD_IS_SIGNED((_FLD), 0)) )  \
      { \
         (_PTR1) =  (X_PVCHAR)(((PX_FLD_SIGNED)(_PTR))->fchData) ; \
      } \
      else if ( (X_VECTOR_FIELD_IS_PACKED((_FLD), 0))    || (X_COMPONENT_FIELD_IS_PACKED((_FLD), 0))) \
      {\
         (_PTR1) = (X_PVCHAR)(((PX_FLD_PACKED)(_PTR))->fchData) ; \
      } \
      else if ( (X_VECTOR_FIELD_IS_CLOB((_FLD), 0))     || (X_COMPONENT_FIELD_IS_CLOB((_FLD), 0)) ) \
      {  \
         (_PTR1) = ((PX_FLD_CLOB)(_PTR))->vchFileName;\
      }  \
      else if ( (X_VECTOR_FIELD_IS_BLOB((_FLD), 0))     || (X_COMPONENT_FIELD_IS_BLOB((_FLD), 0)) ) \
      {  \
         (_PTR1) = ((PX_FLD_BLOB)(_PTR))->vchFileName;\
      }  \
      else if ( (X_VECTOR_FIELD_IS_NCLOB((_FLD), 0))     || (X_COMPONENT_FIELD_IS_NCLOB((_FLD), 0)) ) \
      {  \
         (_PTR1) = ((PX_FLD_NCLOB)(_PTR))->vchFileName;\
      }  \
      else if ((X_VECTOR_FIELD_IS_DATE((_FLD), 0))      || (X_COMPONENT_FIELD_IS_DATE((_FLD), 0))) \
      { \
         (_PTR1) = ((PX_FLD_DATE)(_PTR))->vchDate;\
      } \
      else if ((X_VECTOR_FIELD_IS_TIME((_FLD), 0))      || (X_COMPONENT_FIELD_IS_TIME((_FLD), 0)))   \
      {  \
         (_PTR1) = ((PX_FLD_TIME)(_PTR))->vchTime;\
      }  \
      else if ((X_VECTOR_FIELD_IS_DATETIME((_FLD), 0))  || (X_COMPONENT_FIELD_IS_DATETIME((_FLD), 0))) \
      { \
         (_PTR1) = ((PX_FLD_DATETIME)(_PTR))->vchDateTime;\
      }  \
      else if ( ( X_VECTOR_FIELD_IS_SHORT_CHAR((_FLD), 0) ) || ( X_COMPONENT_FIELD_IS_SHORT_CHAR((_FLD), 0) ) ) \
      { \
         (_PTR1) = ((PX_FLD_SHORT_CHAR)(_PTR))->vchData;\
      }\
      else if ((X_VECTOR_FIELD_IS_CHAR((_FLD), 0) )     || (X_COMPONENT_FIELD_IS_CHAR((_FLD), 0))) \
      { \
         X_VAR_VarChar_GetAsVchar(pX_Ids, pX_Pro, pX_Fun,(X_FLD_CHAR *)(_PTR), (X_VCHAR **)&(_PTR1) );\
      }\
      else if ((X_VECTOR_FIELD_IS_BINARY((_FLD), 0) ) || (X_COMPONENT_FIELD_IS_BINARY((_FLD), 0))) \
      {\
         X_VAR_VarBinary_GetPointer(pX_Ids, pX_Pro, pX_Fun,(X_FLD_BINARY *)(_PTR), (X_VOID **)&(_PTR1) );\
      }\
      else if  ((X_VECTOR_FIELD_IS_INTEGER((_FLD), 0) )|| (X_COMPONENT_FIELD_IS_INTEGER((_FLD), 0))) \
      {\
           (_PTR1) = (X_PVCHAR)(((PX_FLD_SIGNED)(_PTR))->fchData) ;\
      }\
      else if (( X_VECTOR_FIELD_IS_FLOAT((_FLD), 0) )|| (X_COMPONENT_FIELD_IS_FLOAT((_FLD), 0))) \
      {\
           (_PTR1) = (X_PVCHAR)(((PX_FLD_SIGNED)(_PTR))->fchData) ;\
      }\
      else  \
      { /* TN: None of the supported types  */\
         X_FATAL_STORAGE_POINTER \
      } \
   }  \
   else \
   { /* The field is LL1*/ \
      (_PTR1) = (_PTR); \
   }\
}

#endif // X_OPERATING_TARGET_CSHARP

#ifdef X_OPERATING_SYSTEM_UNIX
/* ================================================================= */
/*  X_FILE_PERMISSION: Valid File Permission settings                */
/* ================================================================= */

/* This is based on POSIX (UNIX/Linux) file permissions */
typedef enum
{                              /* OTHGRPOWN */
   X_FP_EX_OWNER = 0x00000001, /* --------x */
   X_FP_WR_OWNER = 0x00000002, /* -------w- */
   X_FP_RD_OWNER = 0x00000004, /* ------r-- */
   X_FP_EX_GROUP = 0x00000008, /* -----x--- */
   X_FP_WR_GROUP = 0x00000010, /* ----w---- */
   X_FP_RD_GROUP = 0x00000020, /* ---r----- */
   X_FP_EX_OTHER = 0x00000040, /* --x------ */
   X_FP_WR_OTHER = 0x00000080, /* -w------- */
   X_FP_RD_OTHER = 0x00000100  /* r-------- */
} X_FILE_PERMISSION;

#define X_FP_EVERYONE_READ  X_FP_RD_OWNER | X_FP_RD_GROUP | X_FP_RD_OTHER
#define X_FP_EVERYONE_WRITE X_FP_WR_OWNER | X_FP_WR_GROUP | X_FP_WR_OTHER
#define X_FP_EVERYONE_EXEC  X_FP_EX_OWNER | X_FP_EX_GROUP | X_FP_EX_OTHER

#define X_FP_EVERYONE_READ_WRITE X_FP_EVERYONE_READ | X_FP_EVERYONE_WRITE
#define X_FP_OWNER_READ_WRITE X_FP_RD_OWNER | X_FP_WR_OWNER

#endif /* UNIX */

#define X_MAX_SAVED_STATEMENTS_DEFAULT 50

#ifdef X_OPERATING_SYSTEM_ISERIES
/* ================================================================= */
/*  iSeries DB Triggers                                              */
/* ================================================================= */

#define DBTRIGENV_V1       -1
#define DBTRIGENV_CURRENT  DBTRIGENV_V1 /* Make sure this is updated with the latest version number */

typedef struct
{
   X_SHORT sVersion;
   X_FCHAR fchProgramLibrary[X_OBJECT_NAME_LEN];
   X_FCHAR fchPartition[3];
   X_FCHAR fchLanguage[4];
   X_CHAR  chDateSource;
   X_VCHAR vchProgramLibrary[X_OBJECT_NAME_LEN + 1];
} DBTRIGENV;

#define X_DBTRIG_V1       -1
#define X_DBTRIG_CURRENT  X_DBTRIG_V1 /* Make sure this is updated with the latest version number */

/* Trigger request values */
#define X_DBT_TRIGGER_NOT_SET  0
#define X_DBT_AFTER_READ       1
#define X_DBT_BEFORE_INSERT    2
#define X_DBT_AFTER_INSERT     3
#define X_DBT_BEFORE_DELETE    4
#define X_DBT_AFTER_DELETE     5
#define X_DBT_BEFORE_UPDATE    6
#define X_DBT_AFTER_UPDATE     7

typedef struct
{
   X_SHORT sVersion;
   X_SHORT sTrigRequest;
   X_PVOID pOldBuffer;
   X_PVOID pOldNullMap;
   X_PVOID pNewBuffer;
   X_PVOID pNewNullMap;
} X_DBTRIG;

/* Messages for when the message file cannot be found */
#define X_DBT_MSGFMT_IOM0200 "IOM0200: DB trigger program %s in %s for file %s in %s failed"
#define X_DBT_MSGFMT_IOM0201 "IOM0201: DB trigger program %s in %s unable to call DB Trigger Environment User Exit"
#define X_DBT_MSGFMT_IOM0202 "IOM0202: DB trigger program %s in %s unable to initialise RDML Environment"
#define X_DBT_MSGFMT_IOM0203 "IOM0203: DB trigger program %s in %s unable to resolve to RDMLX environment"
#define X_DBT_MSGFMT_IOM0204 "IOM0204: DB trigger program %s in %s unable to resolve to OAM"
#define X_DBT_MSGFMT_IOM0205 "IOM0205: DB trigger program %s in %s unable to establish RDMLX environment"
#define X_DBT_MSGFMT_IOM0206 "IOM0206: DB trigger program %s in %s invalidly called"

#endif

/* ================================================================= */
/*  Business Objects - Data Records                                  */
/* ================================================================= */

/* ================================================================= */
/*  X_DRD : LANSA/X Data Record Description                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Version         Structure version                                 */
/* Name            Record Name                                       */
/* RecordLength    Byte Length of a record                           */
/* sFld            Total Fields in Vector array of structures        */
/* pX_Fld          Pointer to Vector List array of structures        */
/* pX_LMap         Pointer to list map                               */
/* pOffsetTable    Pointer to table of vector offsets into record    */
/* Record          Pointer to a static record instance               */
/* OperationTable  Pointer to a table of functions                   */

#define X_DRD_V1           -1
#define X_DRD_CURRENT      X_DRD_V1

#define X_DRD_V1_OR_LATER(_P)       (_P->lX_DRDVersion <= X_DRD_V1)
#define X_DRD_NOT_V1_OR_LATER(_P)   (_P->lX_DRDVersion > X_DRD_V1)

struct X_DRD
{
   X_LONG                              lX_DRDVersion;
   X_VCHAR                             vchName[X_COMPONENT_NAME_LEN + 1];
   X_ULONG                             ulRecordLength;
   X_SHORT                             sFld;
   struct X_FLD                     *  pX_Fld;
   struct X_LMAP                    *  pX_LMap;
   X_ULONG                          *  pOffsetTable;
   X_VOID                           *  pvRecord;
   X_VOID                           *  pOperationTable;
};


/* ================================================================= */
/*  In-memory import structures                                      */
/* ================================================================= */

struct X_IMPORT_TABLE
{
   X_VCHAR vchInternalName[32 + 1];
   X_VCHAR vchExternalName[32 + 1];
   X_LONG  lTotalColumns;
   X_BOOL  fRepTable;
   X_BOOL  fStatementPrepared;
   X_LONG  lTotalAttemptedInserts;
   X_BOOL  fError632Issued;
};

// structure is not used in generated code so no version number required

typedef struct _X_IN_MEMORY_IMPORT
{
   X_PVOID           pvCallersData;
   X_COMP_CALLBACK   pfnDataCallback;

} X_IN_MEMORY_IMPORT,
  *PX_IN_MEMORY_IMPORT,
  **PPX_IN_MEMORY_IMPORT;

#ifndef X_OPERATING_TARGET_CSHARP

typedef struct _X_IN_MEMORY_DATA
{
   struct X_IDS               * pX_Ids;
   struct X_PRO               * pX_Pro;
   struct X_FUN               * pX_Fun;
   struct X_IMPORT_TABLE      * pTable;
   struct X_XQL_REQUEST_BLOCK * pRequest;
   X_PLONG                      plTotalFatals;
   X_PLONG                      plTotalWarnings;
   X_PLONG                      plTotalDuplicates;
   X_PVCHAR                     pvchMessage;
} X_IN_MEMORY_DATA,
  *PX_IN_MEMORY_DATA,
  **PPX_IN_MEMORY_DATA;

#endif // X_OPERATING_TARGET_CSHARP


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !def __INCL_X_FUNSTR_H__ */
