/* ================================================================= */
/* ========== LANSA FOR WINDOWS GLOBAL DEFINITIONS ================= */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_GLODEF.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : LANSA Global Defintions                     */
/*                                                                   */
/* ================================================================= */

#ifndef RC_INVOKED

#ifndef __INCL_X_GLODEF_H__
#define __INCL_X_GLODEF_H__

#include "x_platform.h"
#include "x_ctypes.h"

/* ================================================================= */
/*  LANSA/X Standard strings and values definitions                  */
/* ================================================================= */

#define X_LANSAX_V1_30_OR_LATER

#define LOVAL                 '\0'
#define HIVAL                 '\xFF'
#define HIVAL2                '\xFE'
#define QUOTE                 '\''
#define DOUBLE_QUOTE          '\"'
#define QUESTION_MARK         '\?'
#ifndef CARRIAGE_RETURN /* Also defined in lx_gdef.h */
#define CARRIAGE_RETURN       '\r'
#endif
#define STR_CARRIAGE_RETURN   "\r"  /* string */
#define WSTR_CARRIAGE_RETURN  L"\r"  /* string */

#ifndef LINE_FEED /* Also defined in lx_gdef.h */
#ifndef X_OPERATING_SYSTEM_ISERIES
#define LINE_FEED             '\x0A'
#else
#define LINE_FEED             '\x25'
#endif
#endif
#define NEW_LINE              '\n'
#define STR_NEW_LINE          "\n"  /* string */
#define STR_FORM_FEED         "\f"  /* string */
#ifndef BACK_SPACE /* Also defined in lx_gdef.h */
#define BACK_SPACE            '\b'
#endif
#ifndef HORZ_TAB /* Also defined in lx_gdef.h */
#define HORZ_TAB              '\t'
#endif
#ifndef VERT_TAB /* Also defined in lx_gdef.h */
#define VERT_TAB              '\v'
#endif
#define HASH                  '#'
#define END_OF_STRING         '\0'
#define BACK_SLASH            '\\'
#ifndef BLANK /* Also defined in lx_gdef.h */
#define BLANK                 ' '
#endif
#define YES                   'Y'
#define NO                    'N'
#define X_YES                 'Y'
#define X_NO                  'N'
#define PROMPT                'P'
#define CONTINUE              'C'
#define ABORT                 'A'
#define DYNAMIC               'D'
#ifndef FALSE
#define FALSE                  (0)
#endif
#ifndef TRUE
#define TRUE                   (!FALSE)
#endif
#define X_LEADING_REPLACE     'X'
#define X_NON_LEADING_REPLACE '_'
#define X_ON                  '1'
#define X_OFF                 ' '
#define X_INVOKE_AS_MAIN_EXE   'E'
#define X_INVOKE_AS_SUBROUTINE 'S'
#define X_GLODEF_WARNING      'W'

#define X_UPGD_REFRESH        'R'
#define X_UPGD_ALL            'A'
#define X_ASKC_REOPEN         'R'

#ifndef TRIM_TO_STANDARD_STRING
#define TRIM_TO_STANDARD_STRING(_S) \
   { \
   char *const __sp = (_S); \
   if (*__sp != '\0') \
      { \
      char *__ep = __sp + strlen(__sp); \
      while (__ep > __sp) \
         { \
         __ep--; \
         if ((*__ep == BLANK) \
         || (*__ep == '\f') \
         || (*__ep == '\n') \
         || (*__ep == '\r')) *__ep = LOVAL; \
            else break; \
         } \
      } \
   }
#endif

/* All the X_INTERNAL_xxx values are defaults for values set in x_defxxx.h */
/* that generated objects use.                                             */
/* ======================================================================= */

#define X_INTERNAL_SYSTEM_OWNER               "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* Special value *DATABASE indicates that the  */
                             /* value from the LX_F96 table column X96OWN   */
                             /* should be used                              */

#define X_INTERNAL_SPECIAL_SECURITY_OFFICER   "QSECOFR"
                             /* max. "xxxxxxxxxx"                           */
                             /* Special value *DATABASE indicates that the  */
                             /* special security officer should be set to   */
                             /* the same value as the system owner.         */

#define X_INTERNAL_PARTITION_SECURITY_OFFICER "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* Special value *DATABASE indicates that the  */
                             /* value from the LX_F46 table column X46SEC   */
                             /* associated with the current partition       */
                             /* should be used                              */

#define X_INTERNAL_GROUP_AUTHORITY            "*ALL"
                             /* max. "xxxxxxxxxx" */

#define X_INTERNAL_AUTOMATIC_HELP             YES
                             /* max. 'x'          */

#define X_INTERNAL_CENTURY_COMPARE_DATE       "40"
                             /* max. "xx"         */

#define X_INTERNAL_CENTURY_GREATER_DATE       "19"
                             /* max. "xx"         */

#define X_INTERNAL_CENTURY_LESS_DATE          "20"
                             /* max. "xx"         */

#define X_INTERNAL_DATE_SEPARATOR             '/'
                             /* max. 'x'          */

#define X_INTERNAL_CURRENCY_SYMBOL            '$'
                             /* max. 'x'          */

#define X_INTERNAL_DECIMAL_POINT_CHAR         '.'
                             /* max. 'x'          */

#define X_INTERNAL_TIME_SEPARATOR             ':'
                             /* max. 'x'          */

/* ================================================================= */
/*                                                                   */
/* The below X_FILE_SECURITY_DISABLED, X_PROCESS_SECURITY_DISABLED   */
/* and X_FUNCTION_SECURITY_DISABLED are set to a default value of    */
/* 'D' (Dynamic) which indicates that the value is retrieved from    */
/* internal file LX_F96 at runtime.  The System Owner or Partition   */
/* Security Officer can set these values from the System Maintenance */
/* option on the Visual LANSA main window, but if connecting to an   */
/* IBM i master, these values will be overwritten by any             */
/* subsequent System Initialisation (Plug-in or Refresh).            */
/*                                                                   */
/* ================================================================= */

#define X_INTERNAL_FILE_SECURITY_DISABLED     'D'
                             /* max. 'x'          */

#define X_INTERNAL_PROCESS_SECURITY_DISABLED  'D'
                             /* max. 'x'          */

#define X_INTERNAL_FUNCTION_SECURITY_DISABLED 'D'
                             /* max. 'x'          */

#define X_INTERNAL_GEN_AT_SIGN_CHAR           '@'
                             /* max. 1 character   */

#define X_INTERNAL_STANDARD_MESSAGE_FILE      "DC@M01"
                             /* max. 10 characters */

#define X_INTERNAL_DOLLAR_SIGN_CHAR           '$'
                             /* max. 1 character   */

#define X_INTERNAL_HASH_SIGN_CHAR             '#'
                             /* max. 1 character   */

#define X_INTERNAL_AT_SIGN_CHAR               '@'
                             /* max. 1 character   */



/* =================================================================== */
/*  Component inclusions : Make X_COMP and X_COMPONENT interchangeable */
/* =================================================================== */

#if defined(X_COMP) && !defined(X_COMPONENT)
#define X_COMPONENT
#endif


#if !defined(X_COMP) && defined(X_COMPONENT)
#define X_COMP
#endif

#if !defined(X_COMP_RUN_TIME_SUPPORT)
#define X_COMP_RUN_TIME_SUPPORT
#endif

#include "liiodef.h"

/* ================================================================= */
/*  Warnings to switch off globally so that warning level 4 is useful*/
/* ================================================================= */

#ifdef X_WARNINGS
/* warning C4100: 'pvchDatabase' : unreferenced formal parameter           */
/* warning C4115: '_RPC_ASYNC_STATE' : named type definition in parentheses*/
/* warning C4127: conditional expression is constant                       */
/* warning C4152: nonstandard extension, function/data pointer conversion in expression */
/* warning C4201: nonstandard extension used : nameless struct/union       */
/* warning C4211: nonstandard extension used : redefined extern to static  */
/* warning C4996: <function> was declared deprecated   Required for VS 2005*/
#pragma warning (disable : 4100 4115 4127 4152 4201 4211 4996)
#endif

#ifndef X_OPERATING_TARGET_CSHARP

/* ------------------------------ */
/* DLL entry point function types */
/* ------------------------------ */

#define X_VOID_FUNCTION       X_VOID X_FUNTYPE
#define X_PVOID_FUNCTION      X_PVOID X_FUNTYPE

#define X_INT_FUNCTION        X_INT X_FUNTYPE
#define X_PINT_FUNCTION       X_PINT X_FUNTYPE

#define X_UINT_FUNCTION       X_UINT X_FUNTYPE
#define X_PUINT_FUNCTION      X_PUINT X_FUNTYPE

#define X_SHORT_FUNCTION      X_SHORT X_FUNTYPE
#define X_PSHORT_FUNCTION     X_PSHORT X_FUNTYPE

#define X_USHORT_FUNCTION     X_USHORT X_FUNTYPE
#define X_PUSHORT_FUNCTION    X_PUSHORT X_FUNTYPE

#define X_LONG_FUNCTION       X_LONG X_FUNTYPE
#define X_PLONG_FUNCTION      X_PLONG X_FUNTYPE

#define X_ULONG_FUNCTION      X_ULONG X_FUNTYPE
#define X_PULONG_FUNCTION     X_PULONG X_FUNTYPE

#define X_DOUBLE_FUNCTION     X_DOUBLE X_FUNTYPE
#define X_PDOUBLE_FUNCTION    X_PDOUBLE X_FUNTYPE

#define X_CHAR_FUNCTION       X_CHAR X_FUNTYPE
#define X_PCHAR_FUNCTION      X_PCHAR X_FUNTYPE

#define X_FCHAR_FUNCTION      X_FCHAR X_FUNTYPE
#define X_PFCHAR_FUNCTION     X_PFCHAR X_FUNTYPE

#define X_TYPE_FLAG_FUNCTION  X_TYPE_FLAG X_FUNTYPE
#define X_PTYPE_FLAG_FUNCTION X_PTYPE_FLAG X_FUNTYPE

#define X_YES_NO_FUNCTION     X_YES_NO X_FUNTYPE
#define X_PYES_NO_FUNCTION    X_PYES_NO X_FUNTYPE

#define X_VCHAR_FUNCTION      X_VCHAR X_FUNTYPE
#define X_PVCHAR_FUNCTION     X_PVCHAR X_FUNTYPE
#define X_PPVCHAR_FUNCTION    X_PPVCHAR X_FUNTYPE

#define X_BOOL_FUNCTION       X_BOOL X_FUNTYPE
#define X_PBOOL_FUNCTION      X_PBOOL X_FUNTYPE

#define X_CCHAR_FUNCTION      X_CCHAR X_FUNTYPE
#define X_PCCHAR_FUNCTION     X_PCCHAR X_FUNTYPE

#define X_PFILE_HANDLE_FUNCTION X_PFILE_HANDLE X_FUNTYPE

#define X_JOBID_FUNCTION      X_JOBID X_FUNTYPE

#define X_JOBEXTID_FUNCTION   X_JOBEXTID X_FUNTYPE

#define X_PID_FUNCTION        X_PID X_FUNTYPE

#define X_PIDEXT_FUNCTION     X_PIDEXT X_FUNTYPE

#define X_FILEBUFFERING_FUNCTION X_FILEBUFFERING X_FUNTYPE

#endif // X_OPERATING_TARGET_CSHARP

#ifndef X_OPERATING_TARGET_CSHARP

/* ------------------------------- */
/* DLL/EXE internal function types */
/* ------------------------------- */

#define X_VOID_INTERNAL_FUNCTION       X_VOID
#define X_PVOID_INTERNAL_FUNCTION      X_PVOID

#define X_INT_INTERNAL_FUNCTION        X_INT
#define X_PINT_INTERNAL_FUNCTION       X_PINT

#define X_UINT_INTERNAL_FUNCTION       X_UINT
#define X_PUINT_INTERNAL_FUNCTION      X_PUINT

#define X_SHORT_INTERNAL_FUNCTION      X_SHORT
#define X_PSHORT_INTERNAL_FUNCTION     X_PSHORT

#define X_USHORT_INTERNAL_FUNCTION     X_USHORT
#define X_PUSHORT_INTERNAL_FUNCTION    X_PUSHORT

#define X_LONG_INTERNAL_FUNCTION       X_LONG
#define X_PLONG_INTERNAL_FUNCTION      X_PLONG

#define X_SIZE_INTERNAL_FUNCTION       size_t
#define X_PSIZE_INTERNAL_FUNCTION      (X_SIZE_INTERNAL_FUNCTION *)

#define X_ULONG_INTERNAL_FUNCTION      X_ULONG
#define X_PULONG_INTERNAL_FUNCTION     X_PULONG

#define X_DOUBLE_INTERNAL_FUNCTION     X_DOUBLE
#define X_PDOUBLE_INTERNAL_FUNCTION    X_PDOUBLE

#define X_CHAR_INTERNAL_FUNCTION       X_CHAR
#define X_PCHAR_INTERNAL_FUNCTION      X_PCHAR

#define X_FCHAR_INTERNAL_FUNCTION      X_FCHAR
#define X_PFCHAR_INTERNAL_FUNCTION     X_PFCHAR

#define X_TYPE_FLAG_INTERNAL_FUNCTION  X_TYPE_FLAG
#define X_PTYPE_FLAG_INTERNAL_FUNCTION X_PTYPE_FLAG

#define X_YES_NO_INTERNAL_FUNCTION     X_YES_NO
#define X_PYES_NO_INTERNAL_FUNCTION    X_PYES_NO

#define X_VCHAR_INTERNAL_FUNCTION      X_VCHAR
#define X_PVCHAR_INTERNAL_FUNCTION     X_PVCHAR
#define X_PPVCHAR_INTERNAL_FUNCTION    X_PPVCHAR

#define X_BOOL_INTERNAL_FUNCTION       X_BOOL
#define X_PBOOL_INTERNAL_FUNCTION      X_PBOOL

#endif // X_OPERATING_TARGET_CSHARP

#ifndef X_OPERATING_TARGET_CSHARP

/* ------------------------------------- */
/* DLL PASCAL entry point function types */
/* ------------------------------------- */

#define X_VOID_PASCAL_FUNCTION         X_VOID X_PASCALFUNTYPE
#define X_PVOID_PASCAL_FUNCTION        X_PVOID X_PASCALFUNTYPE

#define X_SHORT_PASCAL_FUNCTION        X_SHORT X_PASCALFUNTYPE
#define X_PSHORT_PASCAL_FUNCTION       X_PSHORT X_PASCALFUNTYPE

#define X_USHORT_PASCAL_FUNCTION       X_USHORT X_PASCALFUNTYPE
#define X_PUSHORT_PASCAL_FUNCTION      X_PUSHORT X_PASCALFUNTYPE

#define X_LONG_PASCAL_FUNCTION         X_LONG X_PASCALFUNTYPE
#define X_PLONG_PASCAL_FUNCTION        X_PLONG X_PASCALFUNTYPE

#define X_ULONG_PASCAL_FUNCTION        X_ULONG X_PASCALFUNTYPE
#define X_PULONG_PASCAL_FUNCTION       X_PULONG X_PASCALFUNTYPE

#define X_DOUBLE_PASCAL_FUNCTION       X_DOUBLE X_PASCALFUNTYPE
#define X_PDOUBLE_PASCAL_FUNCTION      X_PDOUBLE X_PASCALFUNTYPE

#define X_CHAR_PASCAL_FUNCTION         X_CHAR X_PASCALFUNTYPE
#define X_PCHAR_PASCAL_FUNCTION        X_PCHAR X_PASCALFUNTYPE

#define X_FCHAR_PASCAL_FUNCTION        X_FCHAR X_PASCALFUNTYPE
#define X_PFCHAR_PASCAL_FUNCTION       X_PFCHAR X_PASCALFUNTYPE

#define X_TYPE_FLAG_PASCAL_FUNCTION    X_TYPE_FLAG X_PASCALFUNTYPE
#define X_PTYPE_FLAG_PASCAL_FUNCTION   X_PTYPE_FLAG X_PASCALFUNTYPE

#define X_YES_NO_PASCAL_FUNCTION       X_YES_NO X_PASCALFUNTYPE
#define X_PYES_NO_PASCAL_FUNCTION      X_PYES_NO X_PASCALFUNTYPE

#define X_VCHAR_PASCAL_FUNCTION        X_VCHAR X_PASCALFUNTYPE
#define X_PVCHAR_PASCAL_FUNCTION       X_PVCHAR X_PASCALFUNTYPE
#define X_PPVCHAR_PASCAL_FUNCTION      X_PPVCHAR X_PASCALFUNTYPE

#define X_BOOL_PASCAL_FUNCTION         X_BOOL X_PASCALFUNTYPE
#define X_PBOOL_PASCAL_FUNCTION        X_PBOOL X_PASCALFUNTYPE

#define COMPONENT_STD_FUNCTION         X_LONG_FUNCTION

#endif // X_OPERATING_TARGET_CSHARP

/* -------------------------------------------------------------------- */
/* Calling convention that is identical to Microsoft __cdecl convention.*/
/* All it does is strip the leading underscore off the standard Watcom  */
/* __cdecl.                                                             */
/* This is used only in new DLLs that do not have to be backward        */
/* compatible with previously built generated objects. First used in    */
/* X_VAR.DLL so that a Watcom version was not required.                 */
/* attempts where made to use __MS_cdecl like __cdecl but the compiler  */
/* rejects it. There must be something more to do to 'publish' an alias */
/* so that it can be used 'inline' which is what is required to create  */
/* a #define like X_VOID_FUNCTION_MS_CDECL that can be used without     */
/* specifically assigning the alias to every single function.           */
/* -------------------------------------------------------------------- */

/*
Use X_MS_CDECL as in:
#ifdef X_WATCOM
#pragma aux (MS_cdecl) X_VAR_VarChar_GetAsVchar;
#endif
X_VOID_FUNCTION_MS_CDECL X_VAR_VarChar_GetAsVchar(
      struct X_IDS                        *  pX_Ids )
*/

typedef X_VOID_FUNCTION    X_VOID_FUNCTION_MS_CDECL;
typedef X_BOOL_FUNCTION    X_BOOL_FUNCTION_MS_CDECL;
typedef X_LONG_FUNCTION    X_LONG_FUNCTION_MS_CDECL;
typedef X_ULONG_FUNCTION   X_ULONG_FUNCTION_MS_CDECL;
typedef X_SHORT_FUNCTION   X_SHORT_FUNCTION_MS_CDECL;

#if defined(X_WATCOM)
#pragma aux __MS_cdecl "*" \
                parm caller [] \
                value struct float struct routine [eax] \
                modify [eax ecx edx];
#endif

/* Make it easy to use callback function pointers that are cross-platform */
#ifndef X_OPERATING_SYSTEM_WIN
#ifndef __cdecl
#define __cdecl
#endif
#endif
/* ================================================================= */
/*  LANSA/Server GetSQLName prototypes                               */
/* ================================================================= */

#ifndef _X_PFNGETSQLNAME_DEFINED
#define _X_PFNGETSQLNAME_DEFINED
typedef X_PVCHAR_FUNCTION (*X_PFNGETSQLNAME) ( X_PVCHAR );
#endif

#define X_GETSQLNAME_ENTRY_POINT  "X_GetSQLName"

/* =================================================================== */
/*  Object Function Pointer Prototypes                                 */
/* =================================================================== */

#ifndef _X_PFNGETIDPTR_DEFINED
#define _X_PFNGETIDPTR_DEFINED
typedef X_PVOID_FUNCTION (*X_PFNGETIDPTR)( void );
#endif

#ifndef _X_PFNGETBUILDNUMBER_DEFINED
#define _X_PFNGETBUILDNUMBER_DEFINED
typedef X_LONG_FUNCTION (*X_PFNGETBUILDNUMBER)( void );
#endif

#ifdef X_OPERATING_SYSTEM_WIN
#ifndef _SMISC_PFNISLL2OBJECT_DEFINED
#define _SMISC_PFNISLL2OBJECT_DEFINED
typedef X_BOOL_FUNCTION (*SMISC_PFNISLL2OBJECT)( X_SHORT, X_PVCHAR, X_PVCHAR, X_PVCHAR * );
#endif
#endif

/******* moved to x_comstr.h
typedef X_LONG_FUNCTION (*X_PFNUNLOADFILEDATA)( struct X_IDS   *,
                                                struct X_PRO   *,
                                                struct X_FUN   *,
                                                X_VCHAR        ,
                                                X_BOOL         );

typedef X_LONG_FUNCTION (*X_PFNLOADFILEDATA)(struct X_IDS   *,
                                             struct X_PRO   *,
                                             struct X_FUN   *,
                                             X_VCHAR        );
******/

#define X_GETIDENTIFICATIONPTR_ENTRY_POINT   "X_GetIdentificationPtr"
#define X_UNLOADFILEDATA_ENTRY_POINT         "X_UnloadFileData"
#define X_LOADFILEDATA_ENTRY_POINT           "X_LoadFileData"

/* ================================================================= */
/*  LANSA/X Object and Authority definitions                         */
/* ================================================================= */

#define X_OBJECT_TYPE_LEN          2
#define X_OBJECT_TYPE_PROCESS      "PD"
#define X_OBJECT_TYPE_FUNCTION     "PF"
#define X_OBJECT_TYPE_FIELD        "DF"
#define X_OBJECT_TYPE_FILE         "FD"
#define X_OBJECT_TYPE_SYSTEM_VAR   "SV"
#define X_OBJECT_TYPE_MULTI_VAR    "MT"
#define X_OBJECT_TYPE_PARTITION    "P#"
#define X_OBJECT_TYPE_TEMPLATE     "AT"
#define X_OBJECT_TYPE_XML_APP      "AA"
#define X_OBJECT_TYPE_LOGICAL_VIEW "LV"
#define X_OBJECT_TYPE_ACCESS_RIGHT "ME"

#define X_OBJECT_AUTH_LEN          2
#define X_OBJECT_AUTH_LIST_LEN     20
#define X_OBJECT_AUTH_USE          "UD"
#define X_OBJECT_AUTH_MODIFY       "MD"
#define X_OBJECT_AUTH_DELETE       "DD"
#define X_OBJECT_AUTH_READ_DATA    "DS"
#define X_OBJECT_AUTH_ADD_DATA     "AD"
#define X_OBJECT_AUTH_CHANGE_DATA  "CH"
#define X_OBJECT_AUTH_DELETE_DATA  "DL"

/* ================================================================= */
/*  LANSA/X Standard Message Message File                            */
/* ================================================================= */

#define X_STANDARD_MESSAGE_FILE_QUSRMSG   "QUSRMSG"
#define X_STANDARD_TEXT_MESSAGE_ID        "DCM0425"
#define X_MESSAGE_TYPE_INFO               'I'
#define X_MESSAGE_TYPE_STATUS             'S'
#define X_MESSAGE_TYPE_WINDOW             'W'
#define X_NEXT_ACTION                     'N'
#define X_ERROR_ACTION                    'E'
#define X_ACCEPT_ACTION                   'A'

#define X_MTXT_ID_LENGTH                  20
#define X_MTXT_TEXT_LENGTH                234
#define X_MTXT_TEXT_LENGTH_OLD            78
#define X_MTXT_TEXT_NOT_FOUND             "\?"

#define X_DESCRIPTION_LENGTH_OLD          40
#define X_DESCRIPTION_LENGTH              120

#define X_LABEL_LENGTH_OLD                15
#define X_LABEL_LENGTH                    45

#define X_COLUMN_HEADING_LENGTH_OLD       20
#define X_COLUMN_HEADING_LENGTH           60    

/* ================================================================= */
/*  LANSA/X Language dependent text control                          */
/* ================================================================= */

#define X_TEXT_STRING_FILE        "x_txt%s.dat"
#define X_TEXT_MAXIMUM_STRINGS    1200     /* duplicate define in LX_GDEF.H */
#define X_TEXT_MAXIMUM_LENGTH     256
#define X_TEXT_ERROR_LENGTH       200

/* ================================================================= */
/*  LANSA/X vector control values                                    */
/* ================================================================= */

#define V_NOT_AVAILABLE                -1
#define V_BIF_ARG_ALREADY_INITIALIZED  -2

#define V_MINIMUM_VALUE                    0
#define V_MAXIMUM_VALUE                16000
#define V_DEFCOND_REFERENCE            16001

#define V_VALID_VECTOR_VALUE(_A) \
((_A >= V_MINIMUM_VALUE) && (_A <= V_MAXIMUM_VALUE))


/* ================================================================= */
/*  LANSA/X Process and Action Bar Definition Options                */
/* ================================================================= */

#define X_ACTION_BAR_ITEMS         18
#define X_MENU_ITEMS               50
#define X_ALLOW_NEXT_FUNCTIONS     20
#define X_ABAR_DESCRIPTION_LENGTH  30
#define X_PDOWN_DESCRIPTION_LENGTH 60
#define X_ABAR_DESCRIPTION_LENGTH_OLD  10
#define X_PDOWN_DESCRIPTION_LENGTH_OLD 20

/* ================================================================= */
/*  LANSA/X User Interface Manager Request Type                      */
/* ================================================================= */

/*-----------------*\
| Generic Functions |
\*-----------------*/
#define X_UIM_ACTIVATE        10    /* Activate/Open UIM Session     */
#define X_UIM_DEACTIVATE      11    /* Deactivate/Close UIM Session  */
#define X_UIM_NOT_STARTED     12    /* UIM Session not started       */
#define X_UIM_INIT            14    /* Initialise font, etc.         */

/*--------------*\
| User Windowing |
\*--------------*/

#define X_UIM_SHOW_MENU               140   /* Show Menu                                */
#define X_UIM_SHOW_ABAR               150   /* Show Action Bar                          */
#define X_UIM_SHOW_PANEL              160   /* Show Panel (backward compatibility only) */
#define X_UIM_SHOW_PANEL_EXT          165   /* Show Panel with extensions               */
#define X_UIM_SHOW_CURRENT_PANEL      167   /* Show (or hide) the current Panel         */
#define X_UIM_SHOW_HELP               170   /* Show Help Details                        */
#define X_UIM_SHOW_HELP_FOR_COMPONENT 171   /* Show Help Details for a component        */
#define X_UIM_GET_HELP_LINES          175   /* Get Help Lines                           */
#define X_UIM_SHOW_MESSAGES           180   /* Show Message Details                     */
#define X_UIM_MESSAGE_POPUP           190   /* Display message pop-up                   */
#define X_UIM_END_FUNCTION            195   /* End a function.                          */
#define X_UIM_SET_IME_MODE            197   /* Set IME Mode for a window                */

/*-------*\
| Logging |
\*-------*/
#define X_UIM_OPEN_LOG        200   /* Open event log      */
#define X_UIM_CLOSE_LOG       210   /* Close event log     */
#define X_UIM_LOG_EVENT       220   /* Log an event        */
#define X_UIM_CLEAR_LOG       230   /* Clear the event log */
#define X_UIM_LOG_UPDATE      231   /* Allow msg loop to continue */
#define X_UIM_RECURSIVE_IMP_BMP  232   /* Show recursive import bitmaps */
#define X_UIM_RECURSIVE_EXP_BMP  233   /* Show recursive export bitmaps */
#define X_UIM_RECURSIVE_PCTOPC_BMP  234   /* Show recursive PC TO PC bitmaps */

/*--------------*\
| Error Handling |
\*--------------*/
#define X_UIM_SHOW_ERROR      300   /* Show error details  */
#define X_UIM_SHOW_WARNING    310   /* Show warning details  */
#define X_UIM_SHOW_ERROR_FORCE 320  /* Always Show error details  */
#define X_UIM_SHOW_ERROR_NEVER 330  /* Just log error details  */

/*--------------------*\
| Debugging Facilities |
\*--------------------*/
#define X_UIM_START_DEBUG     400   /* Start debug session           */
#define X_UIM_END_DEBUG       410   /* End debug session             */
#define X_UIM_CHECK_DEBUG     420   /* Check for debug functions     */
#define X_UIM_BREAK_POINT     430   /* Display a breakpoint          */
#define X_UIM_VERIFY_START    440   /* Verifier - Start              */
#define X_UIM_VERIFY_END      441   /* Verifier - End                */
#define X_UIM_VERIFY_FAILURE  442   /* Verifier - Self test failure  */

/*-----------*\
| BIF Support |
\*-----------*/
#define X_UIM_SET_DD_VALUES   500   /* Allocate DropDown values  */
#define X_UIM_DROP_DD_VALUES  510   /* Deallocate DropDown values*/
#define X_UIM_EXECUTE_IN_UIM  520   /* Execute something in UIM Thread */
#define X_UIM_EXEC_SHELL      0     /* ShellExecuteEx             */
#define X_UIM_EXEC_MESSAGEBOX 1     /* MessageBox                 */

/*-----------------------------*\
|  WEB_STATIC_PAGE BIF Support  |
\*---------------------------- */
#define X_UIM_ACTIVATE_WEB_STATIC_PAGE    600

/* ================================================================= */
/* Memory management limitations                                     */
/* ================================================================= */

#define X_MAXIMIUM_SUPPORTED_ALLOC_SIZE   16777216

/*----------------------------------*\
| Common definitions used by Runsql |
\*----------------------------------*/
#define X_EPCNUMLEN              5
#define X_DBBUILDLEN             10
#define X_CCSIDLEN               5
#define X_CCSIDLEN_UNIX          10   /* To match current length in X60CHR which will need to be increased */
#define X_CCSIDLEN2              32   /* For use in parsing ccsid.txt entries */
#define X_OBJECTNAMELEN          10
#define X_TRANSTABLELEN          20
#define X_LANGCODELEN            4
#define X_CONNNAMELEN            20
#define X_ISOCHARSETLEN          5

#define X_DBSYSTEMBUILDOFFSET    20
#define X_INTEGRATEDOFFSET       31
#define X_X96SP1_CCSID           32
#define X_X96SP1_ATCHAR          37
#define X_X96SP1_DOLLARCHAR      38
#define X_X96SP1_FIELDPREFIX     39
#define X_X96SP1_LANGCODE        40
#define X_X96SP1_MSGFILE         44
#define X_X96SP1_CTOSTRANSTBL    54
#define X_X96SP1_STOCTRANSTBL    74
#define X_X96SP1_EPC             95    /* Will occupy 5 bytes */
#define X_X96SP1_VCS             101
#define X_X96SP1_JOBCCSID        168   /* Will occupy 5 bytes */
#define X_X96SP1_SUPPRESS_LZ_LVL 196   /* *blank/0 or 1       */
#define X_X96SP1_LONG_USER_AUDIT 197   /* 'Y' or 'N'          */
#define X_X96SP1_LENGTH          500

#define X_PARTITION_LENGTH       3
#define X_X46SP1_LENGTH          100
#define X_X46SP1_LANG_LEVELOFFSET   3
#define X_X46SP1_ENABLE_SHORT_CHAR  14
#define X_X46SP1_WEBENABLEDOFFSET   61

enum X_SystemTypes {
   X_SLAVE     =          'N',
   X_MASTER    =          'Y',
   X_VLSLAVE   =          'V'
};

/* ================================================================= */
/* System macros and definitions                                     */
/* ================================================================= */


#define  X_SUBR_FAILED          -2
#define  X_SUBR_REQUEST_END     -1
#define  X_SUBR_NORMAL_END       0


#define  X_COMR_FAILED          X_COMP_RETURN_ERROR
#define  X_COMR_REQUEST_END     X_COMP_RETURN_CLOSE_REQUESTED
#define  X_COMR_NORMAL_END      X_COMP_RETURN_OK


#define X_MAIN_HANDLE_ACTION_BAR(_A) \
   if ((pX_Pro->scX_ABar > 0) && (pX_Pro->vchNextFunc[0] == LOVAL)) \
   { \
      X_End_Function_##_A (FUNCTION_STD_PARMS,NO); \
      return; \
   }

#define X_MAIN_TRANSFER(_A) \
      X_End_Function_##_A (FUNCTION_STD_PARMS,NO); \
      return;

#define X_MAIN_EXIT(_A) \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_EXIT); \
   X_End_Function_##_A (FUNCTION_STD_PARMS,NO); \
   return;

#define X_MAIN_CANCEL(_A) \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_MENU); \
   X_End_Function_##_A (FUNCTION_STD_PARMS,NO); \
   return;

#define X_MAIN_RETURN(_A) \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_RETURN); \
   X_End_Function_##_A (FUNCTION_STD_PARMS,NO); \
   return;

#define X_MAIN_ABORT(_A) \
   pX_Ids->chFatalError = YES; \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_ERROR); \
   X_End_Function_##_A (FUNCTION_STD_PARMS,YES); \
   return;

#define X_MAIN_CHECK_FATAL(_A) \
   if (pX_Ids->chFatalError == YES) \
   { \
      strcpy(pX_Pro->vchNextFunc,X_PROCESS_ERROR); \
      X_End_Function_##_A (FUNCTION_STD_PARMS,YES); \
      return; \
   }

#define X_MAIN_CHECK_EXECUTION(_A, _B) \
   if ((_A) != X_SUBR_NORMAL_END) \
   { \
      if ((_A) == X_SUBR_REQUEST_END) \
         X_End_Function_##_B (FUNCTION_STD_PARMS,NO); \
      else \
         X_End_Function_##_B (FUNCTION_STD_PARMS,YES); \
      return; \
   }

#define X_MAIN_CHECK_DISPATCH(_A, _B) \
   X_MAIN_CHECK_FATAL(_B) \
   if ((_A) != X_COMR_NORMAL_END) \
   { \
      if ( ( (_A) == X_COMR_REQUEST_END ) || ( (_A) == X_COMP_RETURN_TRUE ) ) \
      { \
         strcpy(pX_Pro->vchNextFunc, ( ( (_A) == X_COMR_REQUEST_END ) ? X_PROCESS_EXIT : X_PROCESS_MENU ) ); \
         X_End_Function_##_B( FUNCTION_STD_PARMS, NO ); \
      } \
      else \
         X_End_Function_##_B( FUNCTION_STD_PARMS, YES ); \
      return; \
   }

#define X_BREAK_CHECK_EXECUTION(_A, _B) \
   if ((_A) != X_SUBR_NORMAL_END) return;


#define X_SUBR_HANDLE_ACTION_BAR \
   if ((pX_Pro->scX_ABar > 0) && (pX_Pro->vchNextFunc[0] == LOVAL)) \
   { \
      return (X_SUBR_REQUEST_END); \
   }

#define X_SUBR_TRANSFER \
      return (X_SUBR_REQUEST_END);

#define X_SUBR_EXIT \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_EXIT); \
   return (X_SUBR_REQUEST_END);

#define X_SUBR_CANCEL \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_MENU); \
   return (X_SUBR_REQUEST_END);

#define X_SUBR_RETURN \
   return (X_SUBR_NORMAL_END);

#define X_SUBR_ABORT \
   pX_Ids->chFatalError = YES; \
   strcpy(pX_Pro->vchNextFunc,X_PROCESS_ERROR); \
   return (X_SUBR_FAILED);

#define X_SUBR_CHECK_FATAL \
   if (pX_Ids->chFatalError == YES) \
   { \
      strcpy(pX_Pro->vchNextFunc,X_PROCESS_ERROR); \
      return (X_SUBR_FAILED); \
   }

#define X_SUBR_CHECK_DISPATCH(_A) \
   X_SUBR_CHECK_FATAL \
   if ((_A) != X_COMR_NORMAL_END) \
   { \
      if ( ( (_A) == X_COMR_REQUEST_END ) || ( (_A) == X_COMP_RETURN_TRUE ) ) \
      { \
         strcpy(pX_Pro->vchNextFunc, ( ( (_A) == X_COMR_REQUEST_END ) ? X_PROCESS_EXIT : X_PROCESS_MENU ) ); \
         return (X_SUBR_REQUEST_END); \
      } \
      return (X_SUBR_FAILED); \
   }

#define X_SUBR_CHECK_EXECUTION(_A) \
   if (_A != X_SUBR_NORMAL_END) \
   { \
      return (_A); \
   }

#define X_DISPATCH_COMPONENT_COMMAND( _DI, _RI, _SV, _CN, _AN, _DR, _EH ) \
{ \
   X_PVOID \
      apvAgreedArgs[2]; \
   X_COMP_DISPATCH_ID \
      lDispatchId = ((X_COMP_DISPATCH_ID)( _DI )); \
   apvAgreedArgs[0] = ((X_PVOID)( pX_Fun->pvModuleFrame )); \
   apvAgreedArgs[1] = ((X_PVOID)( &lDispatchId )); \
   if ( ( lReturnCode = Dispatch_Component_Manager( FUNCTION_STD_PARMS, _RI, _SV, _DR, apvAgreedArgs, _CN, _AN ) ) != X_COMP_RETURN_OK ) { _EH } \
}

#define X_DISPATCH_COMPONENT_COMMAND_1( _DI, _RI, _SV, _CN, _AN, _DR, _P1, _EH ) \
{ \
   X_PVOID \
      apvAgreedArgs[3]; \
   X_COMP_DISPATCH_ID \
      lDispatchId = ((X_COMP_DISPATCH_ID)( _DI )); \
   apvAgreedArgs[0] = ((X_PVOID)( pX_Fun->pvModuleFrame )); \
   apvAgreedArgs[1] = ((X_PVOID)( &lDispatchId )); \
   apvAgreedArgs[2] = ((X_PVOID)( _P1 )); \
   if ( ( lReturnCode = Dispatch_Component_Manager( FUNCTION_STD_PARMS, _RI, _SV, _DR, apvAgreedArgs, _CN, _AN ) ) != X_COMP_RETURN_OK ) { _EH } \
}

#define X_DISPATCH_COMPONENT_COMMAND_2( _DI, _RI, _SV, _CN, _AN, _DR, _P1, _P2, _EH ) \
{ \
   X_PVOID \
      apvAgreedArgs[4]; \
   X_COMP_DISPATCH_ID \
      lDispatchId = ((X_COMP_DISPATCH_ID)( _DI )); \
   apvAgreedArgs[0] = ((X_PVOID)( pX_Fun->pvModuleFrame )); \
   apvAgreedArgs[1] = ((X_PVOID)( &lDispatchId )); \
   apvAgreedArgs[2] = ((X_PVOID)( _P1 )); \
   apvAgreedArgs[3] = ((X_PVOID)( _P2 )); \
   if ( ( lReturnCode = Dispatch_Component_Manager( FUNCTION_STD_PARMS, _RI, _SV, _DR, apvAgreedArgs, _CN, _AN ) ) != X_COMP_RETURN_OK ) { _EH } \
}

#define X_START_COMPONENT_ROUTINE(_TYPE, _MI, _MO) \
{ \
   pX_Ids->pActiveCompRtnX_Fun = pX_Fun; \
   pX_Fun->pX_Fld = pX_Fld; \
   RoutineInfo.sVersionAndState = X_COMPONENT_INFO_V1 + _MI + _MO; \
   RoutineInfo.chRoutineType = _TYPE; \
   lReturnCode = X_Start_Component_Routine(pX_Ids,pX_Pro,pX_Fun,&(RoutineInfo),ulNoofNegotiableComps,aNegotiableComps); \
   if (lReturnCode != X_COMP_RETURN_OK) return(lReturnCode); \
}

#define X_TERMINATE_COMPONENT_ROUTINE \
   return( Terminate_Component_Routine(FUNCTION_STD_PARMS,lReturnCode,&(RoutineInfo), \
           pSTACKActiveCompRtnX_Fun,ulNoofNegotiableComps,aNegotiableComps, sEntryCursors) );

#define X_COMR_HANDLE_ACTION_BAR \
   lReturnCode = X_COMR_REQUEST_END; \
   X_TERMINATE_COMPONENT_ROUTINE

#define X_COMR_TRANSFER \
   lReturnCode = X_COMR_REQUEST_END; \
   X_TERMINATE_COMPONENT_ROUTINE

#define X_COMR_EXIT \
   lReturnCode = X_COMR_REQUEST_END; \
   X_TERMINATE_COMPONENT_ROUTINE


#define X_COMR_CANCEL \
   lReturnCode = X_COMR_REQUEST_END; \
   X_TERMINATE_COMPONENT_ROUTINE

#define X_COMR_RETURN \
   lReturnCode = X_COMR_NORMAL_END; \
   X_TERMINATE_COMPONENT_ROUTINE

#define X_COMR_ABORT \
   pX_Ids->chFatalError = YES; \
   lReturnCode = X_COMR_FAILED; \
   X_TERMINATE_COMPONENT_ROUTINE

#define X_COMR_CHECK_FATAL \
   if (pX_Ids->chFatalError == YES) \
   { \
      lReturnCode = X_COMR_FAILED; \
      X_TERMINATE_COMPONENT_ROUTINE \
   }

/* Convert the SUBROUTINE return code to a Component return code */
/* Then handle it */
#define X_COMR_CHECK_EXECUTION(_SUBR) \
   switch (_SUBR ) \
   { \
      case X_SUBR_FAILED: \
         lReturnCode = X_COMR_FAILED; \
         break; \
      case X_SUBR_REQUEST_END: \
         lReturnCode = X_COMR_REQUEST_END; \
         break; \
      case X_SUBR_NORMAL_END: \
         lReturnCode = X_COMR_NORMAL_END; \
         break; \
   } \
   if (lReturnCode != X_COMR_NORMAL_END) \
   { \
      X_TERMINATE_COMPONENT_ROUTINE \
   }


#define X_GET_IO_STATUS(_A) \
   if (pX_Ids->chFatalError == YES) \
   { \
      strcpy( INSTANCE(vchLastIOStatus), X_DBM_FATAL_ERROR ); \
      pX_Ids->chFatalError = NO; \
   } \
   else \
   { \
      strcpy( INSTANCE(vchLastIOStatus), _A.vchReturnCode ); \
   }

#define X_CONVERT_IO_STATUS(_S, _T) \
   if (memcmp(INSTANCE(vchLastIOStatus),_S,2) == 0) \
   { \
      memcpy(INSTANCE(vchLastIOStatus),_T,2); \
   }

#define X_ISSUE_SELECT_SQL_ERROR \
   { \
      X_VCHAR vchErrorMsgText[80]; \
      sprintf(vchErrorMsgText,"SELECT_SQL at RDML command %d received SQL error code %d", \
              (X_SHORT) pX_Fun->sSequence, (X_SHORT) sqlca.sqlcode); \
      X_Issue_Message_VChar (pX_Ids, pX_Pro, pX_Fun, pX_Ids->vchStandardMessageFile, \
                             X_STANDARD_TEXT_MESSAGE_ID,vchErrorMsgText); \
   }

#define X_COMPARE_GENERIC(_A, _B, _R) \
{ \
   X_SHORT i; \
   _R = 0; \
   for (i = 0; ; i++) \
   { \
      if ((_A[i] == LOVAL) && (_B[i] == LOVAL)) break; \
      if ((_A[i] == '*') || (_B[i] == '*')) break; \
      if ((_A[i] == LOVAL) || (_B[i] == LOVAL) || (_A[i] != _B[i])) \
      { \
         _R = 1; \
         break; \
      } \
   } \
}

#define X_TEXT(_N) X_Get_Text_String(_N)



#define X_TEXT_ISSUE_MESSAGE(_N,_VAR1,_VAR2) \
{ \
   X_VCHAR vchTextTempMessage[X_TEXT_MAXIMUM_LENGTH + 1]; \
   sprintf(vchTextTempMessage,(X_TEXT_NOID(_N)),_VAR1,_VAR2); \
   X_Store_Message_Extended (pX_Ids, pX_Pro, pX_Fun, \
                             "          ", \
                             "       ", \
                             (X_LONG)strlen(vchTextTempMessage), \
                             vchTextTempMessage, \
                             (X_LONG)strlen(vchTextTempMessage), \
                             vchTextTempMessage); \
}

#define X_TEXT_ID_ISSUE_MESSAGE( _N, _M, _a1, _a2, _a3, _a4, _a5 ) \
{ \
   X_PCCHAR const _Msg = (_M) ? (_M) : X_TEXT(_N); \
   X_VCHAR vchTextTempMessage[X_TEXT_MAXIMUM_LENGTH + 1]; \
   X_ULONG ulLength; \
   ulLength = sprintf( vchTextTempMessage, _Msg, (_a1), (_a2), (_a3), (_a4), (_a5) ); \
   X_Store_Message_Extended( pX_Ids, pX_Pro, pX_Fun, \
                             "          ", \
                             "       ", \
                             ulLength, \
                             vchTextTempMessage, \
                             ulLength, \
                             vchTextTempMessage ); \
}

#define X_TEXT_NOID(_N) X_Get_Text_String_NoId(_N)

#define X_CLEAR_RENAME_STACK  INSTANCE(scX_RenameStack) = 0;

#define X_APPLY_RENAME(_N, _O) \
{ \
   X_SHORT i = INSTANCE(scX_RenameStack); \
   memcpy(INSTANCE(X_RenameStack[i].fchOrgName),pX_Fld[_N].fchName2,X_VARIABLE_NAME_LEN); \
   INSTANCE(X_RenameStack[i].sVector) = _N; \
   INSTANCE(scX_RenameStack++); \
   memcpy(pX_Fld[_N].fchName2,pX_Fld[_O].fchName2,X_VARIABLE_NAME_LEN); \
}

#define X_REMOVE_RENAMES \
{ \
   X_SHORT i; \
   X_SHORT j = INSTANCE(scX_RenameStack); \
   for (i = 0; i < j; i++) \
   { \
      memcpy(pX_Fld[INSTANCE(X_RenameStack[i].sVector)].fchName2, \
             INSTANCE(X_RenameStack[i].fchOrgName), \
             X_VARIABLE_NAME_LEN); \
   } \
   INSTANCE(scX_RenameStack) = 0; \
}

/* If a fatal error has occurred, don't bother reporting another DB error */
/* Without this DB errors in the 1000's were reported. E.g. SELECT_SQL using PSxx params */
/* Set the return code to an error so we do not get an infinite loop. */
#define X_DBM_ERROR( _R, _Macro, _MsgNum ) \
   if ( pX_Ids->chFatalError == NO ) \
   { \
      X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, _Macro, X_TEXT(_MsgNum)); \
   } \
   _R = -1;

/******************************************************************/
/* Now allows for no main database for PC Other file access       */
/* Generally this should not be used. Use X_DBM_OP or X_DBM_OP_NAT*/
/* or X_DBM_OP_SQL                                                */
/* Use the equate X_DBM_OP_OLD rather than                        */
/* X_PERFORM_DBMS_OPERATION                                       */
/******************************************************************/
#define X_PERFORM_DBMS_OPERATION(_R, _O, _C, _S, _V) \
if ( pX_DBM && X_DBM_V5_OR_LATER ) \
{ \
   /* If the X_DBM structure is not set up properly, and version is V5 */ \
   /* this is now always wrong and must cause a fatal error            */ \
   if ( pX_DBM->pDatabase == pX_NULL || !X_CONNECT_DB_V2_OR_LATER ) \
   { \
      X_DBM_ERROR( _R, "X_DBM_OP_OLD macro", 905 ); \
   } \
   else \
   { \
      _R = ((PFNUSERIOOP) pX_DBM->pDatabase->pfnUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
   } \
} \
else \
{ \
   /* Support old OAMs or the call has passed a NULL pX_DBM and so we use *LOCALDB */ \
   if (pX_Ids->pfUserIO == pX_NULL) \
   { \
      X_DBM_ERROR( _R, "X_DBM_OP_OLD macro", 276 ); \
   } \
   else \
   { \
      _R = ((PFNUSERIOOP) pX_Ids->pfUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
   } \
}
#define X_DBM_OP_OLD X_PERFORM_DBMS_OPERATION

/******************************************************************/
/* This is for use in most IO operations. The type of IO performed*/
/* is set by the caller on IBM i. Everywhere else it always       */
/* calls the SQL Layer.                                           */
/******************************************************************/
#define X_DBM_OP(_R, _O, _C, _S, _V) \
if ( pX_DBM ) \
{ \
   if ( X_DBM_V5_OR_LATER ) \
   { \
      /* If the X_DBM structure is not set up properly, and version is V5 */ \
      /* this is now always wrong and must cause a fatal error            */ \
      if ( pX_DBM->pDatabase == pX_NULL || !X_CONNECT_DB_V2_OR_LATER || !pX_DBM->pDatabase->pfnUserIO ) \
      { \
         X_DBM_ERROR( _R, "X_DBM_OP macro", 905 ); \
      } \
      else \
      { \
         _R = ((PFNUSERIOOP) pX_DBM->pDatabase->pfnUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
      } \
   } \
   else \
   { \
      if ( X_DBM_V3_OR_LATER && pX_DBM->pDatabase ) \
      { \
         if (!X_CONNECT_DB_V2_OR_LATER || !pX_DBM->pDatabase->pfnUserIO ) \
         { \
            X_DBM_ERROR( _R, "X_DBM_OP macro", 905 ); \
         } \
         else \
         { \
            _R = ((PFNUSERIOOP) pX_DBM->pDatabase->pfnUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
         } \
      } \
      else \
      { \
         /* Use the main database */ \
         if (pX_Ids->pfUserIO == pX_NULL) \
         { \
            X_DBM_ERROR( _R, "X_DBM_OP macro", 276 ); \
         } \
         else \
         { \
            _R = ((PFNUSERIOOP) pX_Ids->pfUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
         } \
      } \
   } \
} \
else \
{ \
   X_DBM_ERROR( _R, "X_DBM_OP macro", 903 ); \
}

/******************************************************************/
/* This is for use when the IO MUST be performed against the      */
/* SQL/ODBC interface. It is rare to use this.                    */
/******************************************************************/
#define X_DBM_OP_SQL(_R, _O, _C, _S, _V) \
if ( pX_DBM ) \
{ \
   if ( X_DBM_V5_OR_LATER ) \
   { \
      /* If the X_DBM structure is not set up properly, and version is V5 */ \
      /* this is now always wrong and must cause a fatal error            */ \
      if ( pX_DBM->pDatabase == pX_NULL || !X_CONNECT_DB_V2_OR_LATER || !pX_DBM->pDatabase->pfnUserIO ) \
      { \
         X_DBM_ERROR( _R, "X_DBM_OP_SQL macro", 905 ); \
      } \
      else \
      { \
         _R = ((PFNUSERIOOP) pX_DBM->pDatabase->pfnUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
      } \
   } \
   else \
   { \
      if ( X_DBM_V3_OR_LATER && pX_DBM->pDatabase ) \
      { \
         if (!X_CONNECT_DB_V2_OR_LATER || !pX_DBM->pDatabase->pfnUserIO ) \
         { \
            X_DBM_ERROR( _R, "X_DBM_OP_SQL macro", 905 ); \
         } \
         else \
         { \
            _R = ((PFNUSERIOOP) pX_DBM->pDatabase->pfnUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
         } \
      } \
      else \
      { \
         /* Use the main database */ \
         if (pX_Ids->pfUserIO == pX_NULL) \
         { \
            X_DBM_ERROR( _R, "X_DBM_OP_SQL macro", 276 ); \
         } \
         else \
         { \
            _R = ((PFNUSERIOOP) pX_Ids->pfUserIO) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _S, _V); \
         } \
      } \
   } \
} \
else \
{ \
   X_DBM_ERROR( _R, "X_DBM_OP_SQL macro", 905 ); \
}

/******************************************************************/
/* This is for use when the IO Must be performed against the      */
/* native IO interface.                                           */
/* It checks if the native interface is available. All calls to   */
/* pX_DBM->pDatabase->pfnUserIONative must be preceded by this    */
/* check.                                                         */
/* pX_DBM->pDatabase must be set up correctly.                    */
/* Usual usage would be as follows:                               */
#if(0)
   X_DBM_CHK_NATIVE
   else
   {
      lRetCode = ((PFNUSERIOOP) pX_DBM->pDatabase->pfnUserIONative) (pX_Ids, pX_Pro, pX_Fun, pX_DBM, sRequest, [various parms]);
   }
#endif
/******************************************************************/
#if !defined( X_OPERATING_SYSTEM_ISERIES)
#define X_DBM_CHK_NATIVE
#else
#define X_DBM_CHK_NATIVE \
if ( !pX_DBM || !X_DBM_V5_OR_LATER || pX_DBM->pDatabase->pfnUserIONative == pX_NULL ) \
{ \
   if ( pX_Ids->chFatalError == NO ) \
     X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, "X_DBM_CHK_NATIVE macro", X_TEXT(904)); \
}

#define X_DBM_OP_NATIVE(_R, _O, _C, _F, _S, _W) \
_R = (( PFNUSERISNIOOP ) pX_DBM->pDatabase->pfnUserIONative) ( pX_Ids, pX_Pro, pX_Fun, pX_DBM, _O, _C, _F, _S, _W );

#define X_DBM_OP_NATIVE_CONTROL(_R, _O, _C ) X_DBM_OP_NATIVE(_R, _O, _C, pX_NULL, pX_NULL, pX_NULL)
#define X_DBM_OP_NATIVE_CONTROL_UNLOCK(_R, _C ) X_DBM_OP_NATIVE_CONTROL(_R, X_DBM_NATIVE_UNLOCK, _C)
#define X_DBM_OP_NATIVE_MAP(_R, _O, _C, _F, _S ) X_DBM_OP_NATIVE(_R, _O, _C, _F, _S, pX_NULL)

#endif

/* Internal IO is always to the main database, *LOCALDB, so it has no need of multi-database support */
#define X_PERFORM_INTERNAL_DBMS_OPERATION(_B) \
if (pX_Ids->chInternalDBMSSource != X_LOCAL_CLIENT_DATA_BASE) \
{ \
   if ( pX_Ids->chFatalError == NO ) \
      X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, "X_DBI_Internal_IO_Operation", X_TEXT(284)); \
} \
else \
{ \
   ((PFNINTLIOOP) pX_Ids->pfInternalIO) (pX_Ids, pX_Pro, pX_Fun, _B); \
}
#define X_DBI_OP X_PERFORM_INTERNAL_DBMS_OPERATION

#if !defined( X_OPERATING_SYSTEM_ISERIES)
   #define X_DBM_IS_USING_NATIVE_IO \
   (FALSE)
#else
   /* Note that IBM i is at least X_DBM_V5_OR_LATER so that is not tested for */
   #define X_DBM_IS_USING_NATIVE_IO \
   (pX_DBM && pX_DBM->fUseNativeIO)
#endif

#if !defined( X_OPERATING_SYSTEM_ISERIES)
   #define X_DBM_USE_SQL
#else
   /* Note that IBM i is at least X_DBM_V5_OR_LATER so that is not tested for */
   #define X_DBM_USE_SQL \
   if (pX_DBM ) \
   { \
      pX_DBM->fUseNativeIO = FALSE; \
   } \
   else \
   { \
      if ( pX_Ids->chFatalError == NO ) \
         X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, "X_DBM_USE_SQL macro", X_TEXT(903)); \
   }
#endif

#if !defined( X_OPERATING_SYSTEM_ISERIES)
   #define X_DBM_USE_NATIVE
#else
   /* Note that IBM i is at least X_DBM_V5_OR_LATER so that is not tested for */
   #define X_DBM_USE_NATIVE \
   if (pX_DBM ) \
   { \
      pX_DBM->fUseNativeIO = TRUE; \
   } \
   else \
   { \
      if ( pX_Ids->chFatalError == NO ) \
         X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, "X_DBM_USE_NATIVE macro", X_TEXT(903)); \
   }
#endif

   /* Not an error on Windows if X_DBM is old - this macro used to have no effect */
#if !defined( X_OPERATING_SYSTEM_ISERIES )
   #define X_DBM_USE_DEFAULT \
   if (pX_DBM && X_DBM_V5_OR_LATER) \
   { \
      pX_DBM->fUseNativeIO = pX_Ids->fUseNativeIO; \
   }
#else
   /* Note that IBM i is at least X_DBM_V5_OR_LATER so that is not tested for */
   #define X_DBM_USE_DEFAULT \
   if (pX_DBM ) \
   { \
      pX_DBM->fUseNativeIO = pX_Ids->fUseNativeIO; \
   } \
   else \
   { \
      if ( pX_Ids->chFatalError == NO ) \
         X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, "X_DBM_USE_DEFAULT macro", X_TEXT(903)); \
   }
#endif

/* if pX_DBM is not defined, use pX_Ids->pUserDBMSInfo explicitly */
#define X_DBM_INFO(_RetCode) \
   ((pX_DBM && X_DBM_V5_OR_LATER && pX_DBM->pDatabase != pX_NULL && X_CONNECT_DB_V2_OR_LATER) \
      ? pX_DBM->pDatabase->pDBMSInfo->_RetCode : pX_Ids->pUserDBMSInfo->_RetCode)

/* Need a blank line above here for previous macro to work */

#define X_REAL_REPOSITORY_AVAILABLE(_TABLENAME) \
   ( pX_Ids->chInternalDBMSSource == X_LOCAL_CLIENT_DATA_BASE )


#define X_USE_REAL_REPOSITORY(_TABLENAME) \
   ( (!(pX_Ids->fForceAllXQFileUsage)) && (X_REAL_REPOSITORY_AVAILABLE(_TABLENAME)) )

/* ======================================================================= */
/* Support C\WPF & Silverlight generation tergets                          */
/* ======================================================================= */

#define X_GEN_TARGET_C                 'C'
#define X_GEN_TARGET_CSHARP            '#'

#define FUNCTION_STD_ARGS_CSHARP       "X_IDS pX_Ids, X_PRO pX_Pro, X_FUN pX_Fun, X_FLD[] pX_Fld, X_LIST[] pX_List, X_FKEY X_FKey, FUNCTION_STATIC_GLOBAL_1 pGlobal1, FUNCTION_STATIC_GLOBAL_2 pGlobal2"
#define FUNCTION_STD_PARMS_CSHARP_1    "pX_Ids, pX_Pro, pX_Fun, pX_Fld, pX_List, X_FKey, pGlobal1, pGlobal2"
#define FUNCTION_STD_PARMS_CSHARP_2    "pX_Ids, pX_Pro, pX_Fun, pX_Fld, pX_List, X_FKey, pGlobal1, pGlobal2, lReturnCode, RoutineInfo, pSTACKActiveCompRtnX_Fun,ulNoofNegotiableComps, aNegotiableComps, sEntryCursors"

#define FUNCTION_STD_ARGS  struct X_IDS                    * pX_Ids,   \
                           struct X_PRO                    * pX_Pro,   \
                           struct X_FUN                    * pX_Fun,   \
                           struct X_FLD                    * pX_Fld,   \
                           struct X_LIST                   * pX_List,  \
                           struct X_FKEY                   * X_FKey,   \
                           struct FUNCTION_STATIC_GLOBAL_1 * pGlobal1, \
                           struct FUNCTION_STATIC_GLOBAL_2 * pGlobal2

#define FUNCTION_STD_PARMS pX_Ids,   \
                           pX_Pro,   \
                           pX_Fun,   \
                           pX_Fld,   \
                           pX_List,  \
                           X_FKey,   \
                           pGlobal1, \
                           pGlobal2

#define FUNCTION_STD_PARMS_FRAME(_FRAME) \
   pX_Ids, \
   pX_Pro, \
   (_FRAME)->pX_Fun,  \
   (_FRAME)->pX_Fld,  \
   (_FRAME)->pX_List, \
   pX_FKey, \
   ( (struct FUNCTION_STATIC_GLOBAL_1 *) (_FRAME)->pGlobal1 ), \
   ( (struct FUNCTION_STATIC_GLOBAL_2 *) (_FRAME)->pGlobal2 )

#define COMPONENT_STD_PARMS_FRAME(_FRAME,_PPFKEY) \
   pX_Ids, \
   pX_Pro, \
   (_FRAME)->pX_Fun,  \
   (_FRAME)->pX_Fld,  \
   (_FRAME)->pX_List, \
   _PPFKEY, \
   ( (struct FUNCTION_STATIC_GLOBAL_1 *) (_FRAME)->pGlobal1 ), \
   ( (struct FUNCTION_STATIC_GLOBAL_2 *) (_FRAME)->pGlobal2 )


#define COMPONENT_STD_ARGS  PX_COMP_SERVICES_POINT_REQUEST pRequestBlock,         \
                            X_PVOID                        apvAgreedArgs[],       \
                            X_ULONG                        ulNoofNegotiableComps, \
                            X_COMP_NEGOTIABLE_COMPONENT    aNegotiableComps[]

#define COMPONENT_STD_PARMS pRequestBlock,         \
                            apvAgreedArgs,         \
                            ulNoofNegotiableComps, \
                            aNegotiableComps


#define INSTANCE(_V)    pGlobal1->_V

#define INSTANCE_S2(_V) pGlobal2->_V


#define MODULE1(_V)     pGlobal1->_V

#define MODULE2(_V)     pGlobal2->_V

#define COMPONENT(_V)   pComponent->_V

#define ROUTINE(_V)     pRoutine->_V


#ifdef MIN
#undef MIN
#endif
#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

#ifdef MAX
#undef MAX
#endif
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )

#define PAD_STRING(_A, _B) \
   { \
      if ((_A) != NULL) \
      { \
         size_t __n__ = strlen((_A)); \
         size_t __m__ = sizeof((_A)) - 1; \
         if (__n__ < __m__) \
         { \
            memset((_A) + __n__, (_B), (__m__ - __n__)); \
         } \
         (_A)[__m__] = '\0'; \
      } \
   }

#define HANDLE_SQL_ERROR(_A, _B) \
   { \
      if ((_A) != 0 && (_A) != pX_Ids->pInternalDBMSInfo->lDBMSRowNotFound) \
      { \
         X_SQL_Error (pX_Ids, \
                      pX_Pro, \
                      pX_Fun, \
                      __FILE__, \
                      X_TEXT(183), \
                      (_B), \
                      (_A)); \
      } \
   }

#define HANDLE_SQL_ERROR_EX(_IDS, _PRO, _FUN, _A, _B) \
   { \
      if ((_A) != 0 && (_A) != (_IDS)->pInternalDBMSInfo->lDBMSRowNotFound) \
      { \
         X_SQL_Error ((_IDS), \
                      (_PRO), \
                      (_FUN), \
                      __FILE__, \
                      X_TEXT(183), \
                      (_B), \
                      (_A)); \
      } \
   }

#define REVERSE_STRING(_A) \
   { \
      if ((_A) != NULL) \
      { \
         X_PCHAR __front__ = (_A); \
         X_PCHAR __end__ = (_A) + (strlen((_A)) - 1); \
         while ( __end__ > __front__ ) \
         { \
            X_CHAR __tmpch__ = *__front__; \
            *__front__ = *__end__; \
            *__end__ = __tmpch__; \
            __front__++; __end__--; \
         } \
      } \
   }

#define TRAILING_BLANKS 0x01
#define LEADING_BLANKS  0x02
#define ALL_BLANKS      0x03

#define REMOVE_BLANKS(_A, _B) \
   { \
      if ((_A) != NULL && (_A)[0] != '\0') \
      { \
         size_t __n__ = strlen((_A)); \
         if ((_B) & TRAILING_BLANKS) \
         { \
            while (__n__ > 0 && (_A)[__n__ - 1] == BLANK) \
               __n__--; \
            (_A)[__n__] = '\0'; \
         } \
         if ((_B) & LEADING_BLANKS) \
         { \
            X_PCHAR __cp__ = (_A); \
            while (*__cp__ == BLANK) \
               __cp__++; \
            if (__cp__ > (_A)) \
            { \
               memmove((_A), __cp__, (__n__ + 1 - (__cp__ - (_A)))); \
            } \
         } \
      } \
   }

#define X_FIX_EMPTY_STRING(_STR) \
   { \
      if (*(_STR) == LOVAL) \
      { \
         *(_STR) = BLANK; \
         *((_STR) + 1) = LOVAL; \
      } \
   }

#define X_SET_EMPTY_STRING(_STR) \
   { \
      *(_STR) = BLANK; \
      *((_STR) + 1) = LOVAL; \
   }

#define X_RESOLVE_FUNCTION_POINTER(_FUNC, _DLLN, _ENTN, _FPTR) \
   { \
      X_BOOL         bLoadError = FALSE; \
      X_LONG         lErrorCode = 0; \
      X_APIRET       apiRet = 0; \
      X_MODULEHANDLE hmodDLL = X_NULLMODULEHANDLE; \
      apiRet = X_DosLoadModule(pX_Ids, pX_Pro, pX_Fun, X_DLL_TYPE_UBIF, "", (_DLLN), &(hmodDLL)); \
      if (apiRet != 0) \
      { \
         bLoadError = TRUE; \
         lErrorCode = (X_LONG) apiRet; \
      } \
      else \
      { \
         X_PFN pfn = (X_PFN)NULL; \
         apiRet = X_DosQueryProcAddr(pX_Ids, pX_Pro, pX_Fun, hmodDLL, (_ENTN), &(pfn)); \
         if (apiRet != 0) \
         { \
            bLoadError = TRUE; \
            lErrorCode = (X_LONG) apiRet; \
         } \
         else \
         { \
            (_FPTR) = (X_PVOID) pfn; \
         } \
      } \
      if (bLoadError) \
      { \
        X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, (_FUNC), X_TEXT(420), lErrorCode, (_DLLN), (_ENTN)); \
      } \
   }


#define X_BIF_GET_ARG_AS_SHORT(_A, _S) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Short(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], &(_S)); \
   }


#define X_BIF_GET_ARG_AS_LONG(_A, _L) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Long(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], &(_L)); \
   }


#define X_BIF_GET_ARG_AS_DOUBLE(_A, _D) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Double(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], &(_D)); \
   }


#define X_BIF_GET_ARG_AS_VCHAR(_A, _V) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Vchar(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], sizeof(_V), _V); \
   }


#define X_BIF_SET_RET_FROM_SHORT(_R, _S) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Short(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], _S); \
   }


#define X_BIF_SET_RET_FROM_LONG(_R, _L) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Long(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], _L); \
   }


#define X_BIF_SET_RET_FROM_DOUBLE(_R, _D) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Double(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], _D); \
   }


#define X_BIF_SET_RET_FROM_VCHAR(_R, _V) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Vchar(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], _V); \
   }

#ifndef X_INCLUDE_CTDDEF_EXPLICITLY
#include "x_ctddef.h"
#endif

#if defined(X_OPERATING_SYSTEM_ISERIES)
/* IBM i C++ has these declarations */
#ifndef __cplusplus
extern int strcasecmp(const char *, const char *);
extern int strncasecmp(const char *, const char *, size_t);
extern char *strdup(const char *);
#endif
#endif

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_OPERATING_SYSTEM_UNIX) \
      && (!defined(X_OPERATING_SYSTEM_ISERIES) || !defined(__cplusplus))

/* IBM i C++ has this declaration */
#ifdef __cplusplus
extern "C" {
#endif
extern int memicmp(void *vpVal1, void *vpVal2, int iCount);
#ifdef __cplusplus
} /* extern "C" */
#endif

/* Deprecated - should be avoided */
#ifndef strcmpi
#define strcmpi strcasecmp
#endif

/* Generated code rely on these */
#ifndef stricmp
#define stricmp strcasecmp
#endif
#ifndef strnicmp
#define strnicmp strncasecmp
#endif

#endif

#endif // X_OPERATING_TARGET_CSHARP

#if defined(X_OPERATING_SYSTEM_WIN) || defined(_MSC_VER)

#define atoi64(s)       (_atoi64((s)))

#define itosz(i, s)     (_itoa((i), (s), 10))
#define ltosz(i, s)     (_ltoa((i), (s), 10))
#define ultosz(i, s)    (_ultoa((i), (s), 10))
#define i64tosz(i, s)   (_i64toa((i), (s), 10))
#define ui64tosz(i, s)  (_ui64toa((i), (s), 10))

#elif defined(X_OPERATING_SYSTEM_LNX) \
      || defined(X_OPERATING_SYSTEM_AIX) \
      || defined(X_OPERATING_SYSTEM_SOL) \
      || defined(X_OPERATING_SYSTEM_ISERIES) \
      || defined(__GNUC__) || defined(__xlC__) || defined(__SUNPRO_C) || defined(__HP_cc) || defined(__ILEC400__)

#define atoi64(s)       (strtoll((s), NULL, 10))
#define itosz(i, s)     ((void)sprintf((s), "%d", (int)(i)), (s))
#define ltosz(i, s)     ((void)sprintf((s), "%ld", (long)(i)), (s))
#define ultosz(i, s)    ((void)sprintf((s), "%lu", (unsigned long)(i)), (s))
#define i64tosz(i, s)   ((void)sprintf((s), "%lld", (long long)(i)), (s))
#define ui64tosz(i, s)  ((void)sprintf((s), "%llu", (unsigned long long)(i)), (s))

#endif

#define X_XENV(_NAME) (X_XENV_Query_Setting(pX_Ids,_NAME,TRUE) != pX_NULL)

#define X_NOT_XENV(_NAME) (X_XENV_Query_Setting(pX_Ids,_NAME,TRUE) == pX_NULL)

#define INVOKE_COMPONENT_MANAGER(_MOD,_IDS,_RET,_REQ,_AGREED,_NONEG,_NEG) \
if ((_IDS)->pX_IdsComponent->pfnComponentManager == pX_NULL) \
{ \
   _RET = X_COMP_RETURN_INVALID_PARAMETERS; \
   X_Fatal_Error(pX_Ids,pX_NULL,pX_NULL,_MOD,X_TEXT(586),((X_LONG)_REQ),((X_LONG)_RET)); \
} \
else \
{ \
   X_COMP_SERVICES_POINT_REQUEST CompRequest; \
   PFN_COMP_SERVICES_POINT pfnServicesPoint = (PFN_COMP_SERVICES_POINT) (_IDS)->pX_IdsComponent->pfnComponentManager; \
   CompRequest.lRequest = (X_LONG) _REQ; \
   CompRequest.pX_Ids = (X_PVOID) (_IDS); \
   CompRequest.pfnLANSAServices = (X_PVOID) X_LANSAX_Services; \
   CompRequest.ulRDMLXLineNumber = ((X_ULONG) 0); \
   _RET = (X_COMP_RETURN_CODE) pfnServicesPoint (&(CompRequest),_AGREED,_NONEG,_NEG); \
}


#define INVOKE_RDMLX_COMPONENT_MANAGER(_MOD,_IDS,_PRO,_FUN,_RET,_REQ,_SEQ,_AGREED,_NONEG,_NEG) \
if ((_IDS)->pX_IdsComponent->pfnComponentManager == pX_NULL) \
{ \
   X_Fatal_Error((_IDS),(_PRO),(_FUN),_MOD,"Invalid attempt to reference the Component Manager"); \
   _RET = X_COMP_RETURN_INVALID_PARAMETERS; \
} \
else \
{ \
   X_COMP_SERVICES_POINT_REQUEST CompRequest; \
   PFN_COMP_SERVICES_POINT pfnServicesPoint = (PFN_COMP_SERVICES_POINT) (_IDS)->pX_IdsComponent->pfnComponentManager; \
   CompRequest.lRequest = (X_LONG) _REQ; \
   CompRequest.pX_Ids = (X_PVOID) (_IDS); \
   CompRequest.pfnLANSAServices = (X_PVOID) X_LANSAX_Services; \
   CompRequest.ulRDMLXLineNumber = ((X_ULONG) _SEQ); \
   _RET = (X_COMP_RETURN_CODE) pfnServicesPoint (&(CompRequest),_AGREED,_NONEG,_NEG); \
   if (_RET != X_COMP_RETURN_OK ) \
   { \
      X_VCHAR vchErrorMessageText[X_ERROR_TEXT_LEN]; \
      sprintf(vchErrorMessageText,"Fatal error code %ld returned by the Component Manager",((X_LONG)_RET)); \
      X_Fatal_Error((_IDS),(_PRO),(_FUN),_MOD,vchErrorMessageText); \
   } \
}

#define INVOKE_COMPONENT_MANAGER_FOR_WAM(_MOD,_IDS,_RET,_REQ,_AGREED,_NONEG,_NEG) \
if ((_IDS)->pX_IdsComponent->pfnComponentManager == pX_NULL) \
{ \
   _RET = X_COMP_RETURN_INVALID_PARAMETERS; \
   X_Fatal_Error(pX_Ids,pX_NULL,pX_NULL,_MOD,X_TEXT(586),((X_LONG)_REQ),((X_LONG)_RET)); \
} \
else \
{ \
   X_COMP_SERVICES_POINT_REQUEST CompRequest; \
   PFN_COMP_SERVICES_POINT pfnServicesPoint = (PFN_COMP_SERVICES_POINT) (_IDS)->pX_IdsComponent->pfnComponentManager; \
   CompRequest.lRequest = (X_LONG) _REQ; \
   CompRequest.pX_Ids = (X_PVOID) (_IDS); \
   CompRequest.pfnLANSAServices = (X_PVOID) X_WAM_Services; \
   CompRequest.ulRDMLXLineNumber = ((X_ULONG) 0); \
   _RET = (X_COMP_RETURN_CODE) pfnServicesPoint (&(CompRequest),_AGREED,_NONEG,_NEG); \
}


/* ================================================================= */
/*  Internal Tracing Definitions                                     */
/* ================================================================= */

#define TRACE_FILE_NAME_DEVENV        "d_trace"
#define TRACE_FILE_NAME               "x_trace"

#define TRACE_BEGIN                    0
#define TRACE_END                      1
#define TRACE_FUNCTION_BEGIN           2
#define TRACE_FUNCTION_END             3
#define TRACE_MESSAGE                  4

/* Trace Levels */

#define TRACE_ERROR                    0
#define TRACE_SIGNIFICANT              1
#define TRACE_MODERATE                 2
#define TRACE_NOT_SIGNIFICANT          3
#define TRACE_HIGHLY_DETAILED          9

/* Trace Categories */

#define TRACE_CATEGORY_LENGTH          3

#define TRACE_ALL                      "ALL"
#define TRACE_DBM                      "DBM"
#define TRACE_UIM                      "UIM"
#define TRACE_FUN                      "FUN"
#define TRACE_PIM                      "PIM"
#define TRACE_COM                      "COM"
#define TRACE_PDF                      "PDF"
#define TRACE_BIF                      "BIF"
#define TRACE_PRO                      "PRO"
#define TRACE_RDML                     "RDM"
#define TRACE_RDMLX                    "RDX"
#define TRACE_HEAP                     "HEP"
#define TRACE_WEB                      "WEB"
#define TRACE_WAM                      "WAM"

#if !defined(RC_INVOKED)

#define DEFINE_TRACEABLE_FUNCTION(_FUN,_CAT,_LVL) \
static const X_VCHAR TRACE_FUNCTION[]          = _FUN; \
static const X_VCHAR TRACE_FUNCTION_CATEGORY[] = _CAT;\
static const X_ULONG TRACE_FUNCTION_LEVEL      = _LVL; \

#define TRACE_FUNCTION_START_NOFUN(_PIDS) \
if (_PIDS->fInternalTracing) \
{ \
  X_Trace(_PIDS, __FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_FUNCTION_BEGIN ,TRACE_FUNCTION_CATEGORY,TRACE_FUNCTION_LEVEL, \
          TRACE_FUNCTION,"started",pX_NULL); \
}

#define TRACE_FUNCTION_START(_PIDS) \
   if (_PIDS->fInternalTracing) \
{ \
   X_Trace_Fun(_PIDS, pX_Pro, pX_Fun, __FILE__,__LINE__, \
   TRACE_FUNCTION,TRACE_FUNCTION_BEGIN ,TRACE_FUNCTION_CATEGORY,TRACE_FUNCTION_LEVEL, \
   TRACE_FUNCTION,"started",pX_NULL); \
}

#define TRACE_VOID_RETURN(_PIDS) \
{ \
TRACE_FUNCTION_RETURN(_PIDS) \
return; \
}

#define TRACE_VALUE_RETURN(_PIDS,_VALUE) \
{ \
TRACE_FUNCTION_RETURN(_PIDS) \
return(_VALUE); \
}


#define TRACE_FUNCTION_RETURN(_PIDS) \
if (_PIDS->fInternalTracing) \
{ \
  X_PCCHAR pvchTraceText; \
  if (_PIDS->chFatalError == X_YES) pvchTraceText = "ended (chFatalError = Y)"; \
  else pvchTraceText = "ended"; \
  X_Trace(_PIDS,__FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_FUNCTION_END,TRACE_FUNCTION_CATEGORY,TRACE_FUNCTION_LEVEL, \
          TRACE_FUNCTION,pvchTraceText,pX_NULL); \
}

#define TRACE_EVENT(_PIDS,_LVL,_TEXT1,_TEXT2,_TEXT3) \
if (_PIDS->fInternalTracing) \
{ \
  X_Trace(_PIDS,__FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_MESSAGE,TRACE_FUNCTION_CATEGORY,_LVL, \
          _TEXT1,_TEXT2,_TEXT3); \
}

#define TRACE_EVENT_FIXED(_PIDS,_LVL,_TEXT1,_FIXED2,_LEN2,_FIXED3,_LEN3) \
   if (_PIDS->fInternalTracing) \
{ \
   X_Trace_Fixed(_PIDS,__FILE__,__LINE__, \
   TRACE_FUNCTION,TRACE_MESSAGE,TRACE_FUNCTION_CATEGORY,_LVL, \
   _TEXT1,_FIXED2,_LEN2,_FIXED3,_LEN3); \
}

#define TRACE_INVOKE(_PIDS,_LVL,_FUN) \
if (_PIDS->fInternalTracing) \
{ \
  X_Trace(_PIDS,__FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_MESSAGE,TRACE_FUNCTION_CATEGORY,_LVL, \
          _FUN,"is being invoked",pX_NULL); \
}

#define TRACE_RETURN(_PIDS,_LVL,_FUN) \
if (_PIDS->fInternalTracing) \
{ \
  X_PCCHAR pvchTraceText; \
  if (_PIDS->chFatalError == X_YES) pvchTraceText = "returned control (chFatalError = Y)"; \
  else pvchTraceText = "returned control"; \
  X_Trace(_PIDS,__FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_MESSAGE,TRACE_FUNCTION_CATEGORY,_LVL, \
          _FUN,pvchTraceText,pX_NULL); \
}

#define TRACE_EXTERNAL_INVOKE(_PIDS,_LVL,_FUN) \
if (_PIDS->fInternalTracing) \
{ \
  X_Trace(_PIDS,__FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_MESSAGE,TRACE_FUNCTION_CATEGORY,_LVL, \
          "External function",_FUN,"is being invoked"); \
}

#define TRACE_EXTERNAL_RETURN(_PIDS,_LVL,_FUN,_RET) \
if (_PIDS->fInternalTracing) \
{ \
  X_VCHAR vchTraceText[50]; \
  X_LONG  lTraceReturnCode = _RET; \
  sprintf(vchTraceText, "returned control. Return code was %ld", (long)lTraceReturnCode); \
  X_Trace(_PIDS,__FILE__,__LINE__, \
          TRACE_FUNCTION,TRACE_MESSAGE,TRACE_FUNCTION_CATEGORY,_LVL, \
          "External function",_FUN,vchTraceText); \
}

/* Required when a Component vector has not been refreshed */
#define TRACE_VECTOR_DIRECT(_PIDS,_PPRO,_PFUN,_TEXT,_XFLD,_VECTOR,_BASEADDR) \
if (_PIDS->fInternalTracing) \
{ \
   struct X_FLD _tempFld; \
   struct X_FLD * _pTempFld = &(_tempFld); \
   if (!X_VECTOR_FIELD_IS_EVALUATION(_XFLD,_VECTOR)) \
   { \
      X_Convert_Component_to_Temp_Field(_PIDS,_PPRO,_PFUN,_XFLD,_pTempFld); \
   } \
   TRACE_VECTOR_X(_PIDS,_PPRO,_PFUN,_TEXT,_pTempFld,0,_BASEADDR ) \
}

#define TRACE_VECTOR(_PIDS,_PPRO,_PFUN,_TEXT,_XFLD,_VECTOR,_BASEADDR) \
if (_PIDS->fInternalTracing) \
{ \
   TRACE_VECTOR_X(_PIDS,_PPRO,_PFUN,_TEXT,_XFLD,_VECTOR,_BASEADDR) \
}

#define TRACE_VECTOR_X(_PIDS,_PPRO,_PFUN,_TEXT,_XFLD,_VECTOR,_BASEADDR) \
if (_PIDS->fInternalTracing) \
{ \
   X_VCHAR     vchSprintfValue[X_MAX_ALPHA_FIELD_LEN + 100]; \
   X_PVCHAR    pvchBaseAddr   = (X_PVCHAR) _BASEADDR; \
   if (pvchBaseAddr == pX_NULL) pvchBaseAddr = (X_PVCHAR) _XFLD[_VECTOR].pField; \
   sprintf(  vchSprintfValue, \
            "%s -> Name=%20.20s, Info=0x%02x, Type=%c, SubType=%c, Len=%ld, Dec=%ld, ByteLen=%ld, Offset=%ld", \
             _TEXT, \
             _XFLD[_VECTOR].fchName2, \
             ((int) _XFLD[_VECTOR].chFieldInfo), \
             _XFLD[_VECTOR].chType, \
             _XFLD[_VECTOR].chSubType, \
             ((long) _XFLD[_VECTOR].sLen), \
             ((long) _XFLD[_VECTOR].sDec), \
             ((long) _XFLD[_VECTOR].sByteLen), \
             ((long)(_XFLD[_VECTOR].pField - pvchBaseAddr))  ); \
   TRACE_EVENT(pX_Ids,TRACE_FUNCTION_LEVEL,vchSprintfValue,pX_NULL,pX_NULL) \
   if ( !X_VECTOR_FIELD_IS_EVALUATION(_XFLD,_VECTOR) ) \
   { \
      if ( X_VECTOR_FIELD_IS_SQL_NULL(_XFLD,_VECTOR,pvchBaseAddr) ) \
      { \
         TRACE_EVENT(_PIDS,TRACE_FUNCTION_LEVEL,"State=*SQLNULL",pX_NULL,pX_NULL) \
      } \
      else \
      { \
         X_FLD_CHAR  Varchar;\
         X_FLD_CHAR  Varchar2;\
         X_PVCHAR    pvchBuff       = pX_NULL;\
         X_ULONG     ulTempLength   =  0;\
         X_VARCHAR_INIT(&Varchar)\
         X_VARCHAR_INIT(&Varchar2)\
         X_VAR_VarChar_SetFromVchar( _PIDS, _PPRO, _PFUN, "Value=", &Varchar2 );\
         if ( X_VECTOR_STORED_AS_BINARY(_XFLD,_VECTOR) || X_VECTOR_STORED_AS_WIDECHAR(_XFLD, _VECTOR) ) \
         { \
            X_ULONG ulSize; \
            X_PDICTIONARY_FIELD     pField; \
            struct   X_FLD        * pXFld = &(_XFLD[_VECTOR]); \
            X_GET_INDEX_DIRECT( pField, pXFld, _XFLD, _VECTOR) \
            if ( X_VECTOR_FIELD_IS_COMPONENT( pXFld, 0 ) ) \
            { \
               X_VAR_GetFldDataUsingDispatchOperation( pX_Ids, pX_Pro, pX_Fun, pXFld, 0 ); \
            } \
            else \
            { \
               pXFld = X_VECTOR_RESOLVE_FIELD_ADDRESS( _PIDS, _PPRO, _PFUN, _XFLD, _VECTOR ); \
            } \
            if (  X_VECTOR_FIELD_IS_BINARY( pXFld, 0) ) \
            { \
               X_VAR_VarBinary_GetCurSize( _PIDS, _PPRO, _PFUN, (X_FLD_BINARY *) pXFld->pField, (X_ULONG *) &ulSize ); \
            } \
            if ( X_FLD_CHAR_HAS_WIDECHAR(pXFld->pField) ) \
            { \
               X_VAR_VarChar_GetUtf16CurSize( _PIDS, _PPRO, _PFUN, (X_FLD_CHAR *) pXFld->pField, (X_ULONG *) &ulSize ); \
               ulSize = ulSize * 2; \
               Varchar.ulMaxSize = ulSize * 2; \
               Varchar2.ulMaxSize = Varchar.ulMaxSize + 6; \
            } \
            if ( ulSize == 0 ) \
            { \
               X_VAR_VarChar_SetFromVchar( _PIDS, _PPRO, _PFUN, "", &Varchar ); \
            } \
            else \
            { \
               { \
                  X_PVCHAR pvchTemp = X_PDF_Allocate_Memory(_PIDS, _PPRO, _PFUN,(ulSize * 2) + 1); \
                  if ( pvchTemp ) \
                  { \
                     X_PVOID pData; \
                     if ( X_FLD_CHAR_HAS_WIDECHAR(pXFld->pField) ) \
                     { \
                        X_VAR_VarChar_GetAsUtf16Vchar(_PIDS, _PPRO, _PFUN, (X_FLD_CHAR *) pXFld->pField, ((X_UTF16_VCHAR **) &pData)); \
                     } \
                     else \
                     { \
                        X_VAR_VarBinary_GetPointer(_PIDS, _PPRO, _PFUN, (X_FLD_BINARY *) pXFld->pField, &pData ); \
                     } \
                     LUTE_AsciiToHex( pvchTemp, (const char *)pData, ulSize ); \
                     pvchTemp[(ulSize * 2)] = END_OF_STRING; \
                     X_VAR_VarChar_SetFromVchar( _PIDS, _PPRO, _PFUN, pvchTemp, &Varchar ); \
                     X_PDF_Free_Memory(_PIDS, _PPRO, _PFUN,(X_PVOID) pvchTemp); \
                  } \
               } \
            } \
         } \
         else \
         { \
            X_Vec_Get_as_String2(_PIDS,_PPRO,_PFUN,_XFLD,_VECTOR,X_STND_EDIT_CODE,pX_NULL, \
                                 &ulTempLength, &pvchBuff, &Varchar, pX_NULL);\
         } \
         X_VAR_VarChar_Concatenate( _PIDS, _PPRO, _PFUN,pX_NULL,0,&Varchar,&Varchar2 );\
         X_VAR_VarChar_GetAsVchar( _PIDS, _PPRO, _PFUN, &Varchar2, &pvchBuff);\
         TRACE_EVENT(_PIDS,TRACE_FUNCTION_LEVEL,pvchBuff,pX_NULL,pX_NULL) \
         X_VARCHAR_RELEASE( _PIDS, _PPRO, _PFUN, &Varchar ) \
         X_VARCHAR_RELEASE( _PIDS, _PPRO, _PFUN, &Varchar2 ) \
      } \
   } \
}

// _TEXT1 is presumed to be a nul terminated string.
// It is converted to hex before displaying.
#define TRACE_EVENT_HEX(_PIDS,_PPRO,_PFUN,_TITLE,_TEXT1 ) \
if (_PIDS->fInternalTracing) \
{ \
   X_LONG  ulSize =  X_LONG_SIZE_T_CAST( strlen( _TEXT1 ) ); \
   X_PVCHAR pvchHex = X_PDF_Allocate_Memory(_PIDS, _PPRO, _PFUN, 2 * ulSize + 1); \
   if ( pvchHex ) \
   { \
      LUTE_AsciiToHex( pvchHex, (const char *)_TEXT1, ulSize ); \
      pvchHex[ 2 * ulSize ] = END_OF_STRING; \
      TRACE_EVENT(_PIDS,TRACE_FUNCTION_LEVEL, _TITLE, pvchHex, pX_NULL) \
      X_PDF_Free_Memory(_PIDS, _PPRO, _PFUN,(X_PVOID) pvchHex); \
   } \
}
#endif /* !def RC_INVOKED */

/* ==================================================================== */
/* Full leakage testing redefine - DO NOT DEFINE IN PRODUCTION SOFTWARE */
/* ==================================================================== */


#if defined(X_LEAK_CHECKING_CODE)

#include <windows.h>


      #define LANSAXLOADLIBRARY(_A)          X_Leak_LoadLibrary(_A,__FILE__,__LINE__)

      #define LANSAXFREELIBRARY(_A)          X_Leak_FreeLibrary((X_WIN_HINSTANCE)_A)

      #define REGOPENKEY(_A,_B,_C)           X_Leak_RegOpenKey(_A,_B,_C,__FILE__,__LINE__)

      #define REGOPENKEYEX(_A,_B,_C,_D,_E)   X_Leak_RegOpenKeyEx(_A,_B,_C,_D,_E,__FILE__,__LINE__)

      #define REGOPENKEYEX_ENCODED(_A,_B,_C,_D,_E)   X_Leak_RegOpenKeyExEncoded(pX_Ids,_A,_B,_C,_D,_E,__FILE__,__LINE__)

      #define REGCLOSEKEY(_A)                X_Leak_RegCloseKey(_A)

      #define REGCREATEKEY(_A,_B,_C)         X_Leak_RegCreateKey(_A,_B,_C,__FILE__,__LINE__)

      #define REGCREATEKEYEX(_A,_B,_C,_D,_E,_F,_G,_H,_I) X_Leak_RegCreateKeyEx(_A,_B,_C,_D,_E,_F,_G,_H,_I,__FILE__,__LINE__)


#else

      #define LANSAXLOADLIBRARY(_A)        LoadLibrary(_A)

      #define LANSAXFREELIBRARY(_A)        FreeLibrary(_A)

      #define REGOPENKEY(_A,_B,_C)         RegOpenKey(_A,_B,_C)

      #define REGOPENKEYEX(_A,_B,_C,_D,_E) RegOpenKeyEx(_A,_B,_C,_D,_E)

      #define REGOPENKEYEX_ENCODED(_A,_B,_C,_D,_E) X_Leak_RegOpenKeyExEncoded(pX_Ids,_A,_B,_C,_D,_E,__FILE__,__LINE__)

      #define REGCLOSEKEY(_A)              RegCloseKey(_A)

      #define REGCREATEKEY(_A,_B,_C)       RegCreateKey(_A,_B,_C)

      #define REGCREATEKEYEX(_A,_B,_C,_D,_E,_F,_G,_H,_I) RegCreateKeyEx(_A,_B,_C,_D,_E,_F,_G,_H,_I)

#endif


#if defined(X_LEAK_CHECKING_CODE)
#include <stdio.h>

     #define fopen(_A,_B) X_Leak_fopen(_A,_B,__FILE__,__LINE__)

     #define fclose(_A)   X_Leak_fclose(_A)

     #define fgets(_A,_B,_C) X_Leak_fgets(_A,_B,_C)

     #define fread(_A,_B,_C,_D) X_Leak_fread(_A,_B,_C,_D)

     #define fputs(_A,_B) X_Leak_fputs(_A,_B)

     #define fwrite(_A,_B,_C,_D) X_Leak_fwrite(_A,_B,_C,_D)

     #define malloc(_A)     X_Leak_malloc(_A,__FILE__,__LINE__)

     #define realloc(_A,_B) X_Leak_realloc(_A,_B,__FILE__,__LINE__)

     #define free(_A)       X_Leak_free(_A)


#endif


#if defined(X_LEAK_CHECKING_CODE)

#ifdef __cplusplus
extern "C" {
#endif

     FILE * X_FUNTYPE X_Leak_fopen( const char *  pvchFilename,
                                    const char *  pvchMode,
                                    const char *  pvchCFile,
                                    unsigned long ulCLine );

     int X_FUNTYPE X_Leak_fclose( FILE * pfStream );


     char * X_FUNTYPE X_Leak_fgets( char * string, int n, FILE * stream );


     size_t X_FUNTYPE X_Leak_fread( void *buffer, size_t size, size_t count, FILE * stream);

     int X_FUNTYPE X_Leak_fputs(const char *string, FILE *stream);

     size_t X_FUNTYPE X_Leak_fwrite( const void *buffer, size_t size, size_t count, FILE *stream );

     X_MODULEHANDLE X_FUNTYPE X_FUNTYPE X_Leak_LoadLibrary( char * lpLibFileName,
                                                            const char *  pvchCFile,
                                                            unsigned long ulCLine);

     int X_FUNTYPE X_Leak_FreeLibrary(X_WIN_HINSTANCE hLibModule);

     LONG X_FUNTYPE X_Leak_RegOpenKey( HKEY         hKey,
                             char       * lpSubKey,
                             PHKEY        phkResult,
                             const char *  pvchCFile,
                             unsigned long ulCLine);

     LONG X_FUNTYPE X_Leak_RegOpenKeyEx(HKEY   hKey,
                              char * lpSubKey,
                              DWORD ulOptions,
                              REGSAM samDesired,
                              PHKEY phkResult,
                              const char *  pvchCFile,
                              unsigned long ulCLine);

     LONG X_FUNTYPE X_Leak_RegCloseKey(HKEY hKey);

     LONG X_FUNTYPE X_Leak_RegCreateKey(HKEY hKey,
                              LPCTSTR lpSubKey,
                              PHKEY phkResult,
                              const char *  pvchCFile,
                              unsigned long ulCLine);

     LONG X_FUNTYPE X_Leak_RegCreateKeyEx( HKEY hKey,
                                 LPCTSTR lpSubKey,
                                 DWORD Reserved,
                                 LPTSTR lpClass,
                                 DWORD dwOptions,
                                 REGSAM samDesired,
                                 LPSECURITY_ATTRIBUTES lpSecurityAttributes,
                                 PHKEY phkResult,
                                 LPDWORD lpdwDisposition,
                                 const char *  pvchCFile,
                                 unsigned long ulCLine);

     void * X_FUNTYPE X_Leak_malloc(size_t size, char * pvchCFile, unsigned long ulCLine);

     void * X_FUNTYPE X_Leak_realloc( void *memblock, size_t size, char * pvchCFile, unsigned long ulCLine);

     void   X_FUNTYPE X_Leak_free(void *memblock);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif

/* ======================================================================== */
/* Full leakage testing redefine end - DO NOT DEFINE IN PRODUCTION SOFTWARE */
/* ======================================================================== */

/* To use this macro, put X_TRACE_REGISTERS in code and copy the TraceReg   */
/* function to a C file in your executable                                  */
#define X_TRACE_REGISTERS(_TEXT) \
   __asm { push esp }      \
   __asm { push ebp }      \
   __asm { push edx }      \
   __asm { push ecx }      \
   __asm { push ebx }      \
   __asm { push eax }      \
   TraceReg(pX_Ids, _TEXT);\
   __asm { pop eax }       \
   __asm { pop ebx }       \
   __asm { pop ecx }       \
   __asm { pop edx }       \
   __asm { pop ebp }       \
   __asm { pop esp }

#if(0)
   __asm {                 \
      push esp             \
      push ebp             \
      push edx             \
      push ecx             \
      push ebx             \
      push eax             \
   }                       \
   TraceReg(pX_Ids, _TEXT);\
   __asm {                 \
      pop eax              \
      pop ebx              \
      pop ecx              \
      pop edx              \
      pop ebp              \
      pop esp              \
   }
void TraceReg(struct X_IDS *pX_Ids, char *pszText, ...)
{
   DEFINE_TRACEABLE_FUNCTION("TraceReg",TRACE_DBM,TRACE_NOT_SIGNIFICANT)

   X_VCHAR  vchRegisters[100];
   va_list  va;
   unsigned long *p;

   TRACE_FUNCTION_START(pX_Ids)

   va_start(va, pszText);
   p = (unsigned long *)va;
   sprintf(vchRegisters, "eax=%p,ebx=%p,ecx=%p,edx=%p,ebp=%p,esp=%p", p[0], p[1], p[2], p[3], p[4], p[5]);
   TRACE_EVENT(pX_Ids,TRACE_NOT_SIGNIFICANT,
               "Registers",
               pszText,
               vchRegisters)
   va_end(va);
   TRACE_FUNCTION_RETURN(pX_Ids)
}
#endif

#ifndef X_OPERATING_TARGET_CSHARP

   #if defined( X_OPERATING_SYSTEM_WIN )
   #ifdef X_OS_64BIT
   #define X_CONNECT_BASE_DIR           "\\connect64\\"
   #else
   #define X_CONNECT_BASE_DIR           "\\connect\\"
   #endif
   #else
   #define X_CONNECT_BASE_DIR           "/connect/"
   #endif

   #if defined( X_OPERATING_SYSTEM_WIN )
      #define  X_HEAP_ZERO_MEMORY            HEAP_ZERO_MEMORY
      #define  X_HEAP_GENERATE_EXCEPTIONS    HEAP_GENERATE_EXCEPTIONS
   #else
      /* Copied from winnt.h, MSVC 6 */
      #define X_HEAP_GENERATE_EXCEPTIONS        0x00000004
      #define X_HEAP_ZERO_MEMORY                0x00000008
   #endif

   // #if defined( X_OPERATING_SYSTEM_WIN ) && !defined(X_DEBUG)
   #if defined( X_OPERATING_SYSTEM_WIN )
      #define  X_TRY       __try
      #define  X_EXCEPT    __except
      #define  X_FINALLY   __finally
   #else
      #define  X_TRY
      #define  X_EXCEPT(_DummyArg)    if(0)
      #define  X_FINALLY
   #endif

   #ifndef _X_HEAP_HANDLE_DEFINED
   #define _X_HEAP_HANDLE_DEFINED
   typedef void * X_HEAP_HANDLE;
   #endif

   #ifndef _X_HEAP_DEFINED
   #define _X_HEAP_DEFINED
   #if defined(X_OPERATING_SYSTEM_UNIX) && !defined(X_OPERATING_SYSTEM_ISERIES)
   typedef struct _X_HEAP
   {
      X_HEAP_HANDLE  hHeap;            /* Heap Handle */
      X_PCCHAR       pvchHeapName;     /* Heap Name to display in error handling */
      X_PVOID        pDllInit;         /* Address of the module's DllInit procedure */
      X_PVOID        pDllTerm;         /* Address of the module's DllTerm procedure */
      X_PVOID        pMapProcedure;    /* Address of the module's MapProcedure procedure */
   } X_HEAP;
   #else
   typedef struct _X_HEAP
   {
      X_HEAP_HANDLE  hHeap;            /* Heap Handle */
      X_PCCHAR       pvchHeapName;     /* Heap Name to display in error handling */
      X_PVOID        pDllMain;         /* Address of the module's DllMain procedure */
      X_PVOID        pMapProcedure;    /* Address of the module's MapProcedure procedure */
   } X_HEAP;
   #endif

   #endif

   #ifndef _X_PHEAP_DEFINED
   #define _X_PHEAP_DEFINED
   typedef X_HEAP *X_PHEAP;
   #endif

#endif // X_OPERATING_TARGET_CSHARP

#ifndef X_OPERATING_TARGET_CSHARP

#ifdef X_LANSAX_BUILD

#ifdef __cplusplus
extern "C" {
#endif

extern X_PHEAP const g_pModuleHeap;

#ifndef X_PDFPRO
/* Repeat the declarations here so x_pdfpro.h can be optional */
X_VOID_FUNCTION X_PDF_HeapListInsert(X_PHEAP pHeap);
X_VOID_FUNCTION X_PDF_HeapListRemove(X_PHEAP pHeap);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/* -------------------------------------------------------------------------*/
/* Declare this in a DLL to support private heaps                           */
/* -------------------------------------------------------------------------*/

#define X_MODULE_MAPPROC(_Module)   MapProcedure_##_Module
#define X_DEF_MODULE_MAPPROC(_Module) \
   static void X_MODULE_MAPPROC(_Module)(void) { /* Intentionally dummy */ }

#define X_MODULE_HEAP(_Module)      ModuleHeap_##_Module
#define X_PMODULE_HEAP(_Module)     (&X_MODULE_HEAP(_Module))

#define X_PMODULE_HEAP_IN_USE       g_pModuleHeap

#define X_DECLARE_MODULE_HEAP(_Module) \
   extern X_HEAP X_MODULE_HEAP(_Module);

#if defined(X_OPERATING_SYSTEM_WIN) && defined(X_MSVC)

#define X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize) \
   extern BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved); \
   X_DEF_MODULE_MAPPROC(_Module) \
   X_HEAP X_MODULE_HEAP(_Module) = \
      { NULL, _HeapName, DllMain, X_MODULE_MAPPROC(_Module) }; \
   X_PHEAP const g_pModuleHeap = X_PMODULE_HEAP(_Module); \
   BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved) \
   { \
      switch (fdwReason) \
      { \
         case DLL_PROCESS_ATTACH: \
            /* Note that if this fails, the default LANSA Heap will be used */ \
            /* automatically by the memory allocation routines.             */ \
            X_MODULE_HEAP(_Module).hHeap = HeapCreate(X_HEAP_GENERATE_EXCEPTIONS, (_HeapSize), 0); \
            X_PDF_HeapListInsert(&X_MODULE_HEAP(_Module)); \
            break; \
         case DLL_THREAD_ATTACH: \
            break; \
         case DLL_THREAD_DETACH: \
            break; \
         case DLL_PROCESS_DETACH: \
            if (X_MODULE_HEAP(_Module).hHeap) \
            { \
               HeapDestroy(X_MODULE_HEAP(_Module).hHeap); \
               X_MODULE_HEAP(_Module).hHeap = NULL; \
            } \
            X_PDF_HeapListRemove(&X_MODULE_HEAP(_Module)); \
            break; \
         default: \
            break; \
      } \
      return TRUE; \
   }

#elif defined(X_OPERATING_SYSTEM_IOS) || defined(X_OPERATING_SYSTEM_ANDROID) || defined(X_OPERATING_SYSTEM_JAVASCRIPT)

#define X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize) // [Danny 26/06/2013] Not sure what it means yet, seem to be ok not to have it

#elif defined(X_OPERATING_SYSTEM_UNIX) && !defined(X_OPERATING_SYSTEM_ISERIES)

#define X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize) \
   extern void _dllinit(void); \
   extern void _dllterm(void); \
   X_DEF_MODULE_MAPPROC(_Module) \
   X_HEAP X_MODULE_HEAP(_Module) = \
      { NULL, _HeapName, _dllinit, _dllterm, X_MODULE_MAPPROC(_Module) }; \
   X_PHEAP const g_pModuleHeap = X_PMODULE_HEAP(_Module); \
   void _dllinit(void) \
   { \
      X_PDF_HeapListInsert(&X_MODULE_HEAP(_Module)); \
   } \
   void _dllterm(void) \
   { \
      X_PDF_HeapListRemove(&X_MODULE_HEAP(_Module)); \
   }

#else /* IBM i or Watcom */

#define  X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize) \
   extern void DllMainDummy(void); \
   X_DEF_MODULE_MAPPROC(_Module) \
   X_HEAP X_MODULE_HEAP(_Module) = \
      { NULL, _HeapName, DllMainDummy, X_MODULE_MAPPROC(_Module) }; \
   X_PHEAP const g_pModuleHeap = X_PMODULE_HEAP(_Module); \
   /* Dummy entrypoint so that Unix and Windows are consistent */ \
   void DllMainDummy(void) \
   { \
   }

#endif

#define X_HEAPDLLMAIN(_HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX(DEFAULT, _HeapName, _HeapSize)

/* -------------------------------------------------------------------------*/
/* X_HEAPDLLMAIN_CRT is used by DLLS loaded by the C runtime in order to    */
/* support private heaps                                                    */
/* Statically linked DLLs include XQL, X_COM, X_FUN, X_BIF, X_PIM, etc.     */
/* -------------------------------------------------------------------------*/

#if defined(X_OPERATING_SYSTEM_WIN) && defined(X_MSVC)

#define X_HEAPDLLMAIN_EX_CRT(_Module, _HeapName, _HeapSize) \
   extern BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved); \
   X_DEF_MODULE_MAPPROC(_Module) \
   X_HEAP X_MODULE_HEAP(_Module) = \
      { NULL, _HeapName, DllMain, X_MODULE_MAPPROC(_Module) }; \
   X_PHEAP const g_pModuleHeap = X_PMODULE_HEAP(_Module); \
   BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved) \
   { \
      switch (fdwReason) \
      { \
         case DLL_PROCESS_ATTACH: \
            /* Note that if this fails, the default LANSA Heap will be used */ \
            /* automatically by the memory allocation routines.             */ \
            X_MODULE_HEAP(_Module).hHeap = HeapCreate(X_HEAP_GENERATE_EXCEPTIONS, (_HeapSize), 0); \
            break; \
         case DLL_THREAD_ATTACH: \
            break; \
         case DLL_THREAD_DETACH: \
            break; \
         case DLL_PROCESS_DETACH: \
            if (X_MODULE_HEAP(_Module).hHeap) \
            { \
               HeapDestroy(X_MODULE_HEAP(_Module).hHeap); \
               X_MODULE_HEAP(_Module).hHeap = NULL; \
            } \
            break; \
         default: \
            break; \
      } \
      return TRUE; \
   }

#elif defined(X_OPERATING_SYSTEM_UNIX) && !defined(X_OPERATING_SYSTEM_ISERIES)

#define X_HEAPDLLMAIN_EX_CRT(_Module, _HeapName, _HeapSize) \
   extern void _dllinit(void); \
   extern void _dllterm(void); \
   X_DEF_MODULE_MAPPROC(_Module) \
   X_HEAP X_MODULE_HEAP(_Module) = \
      { NULL, _HeapName, _dllinit, _dllterm, X_MODULE_MAPPROC(_Module) }; \
   X_PHEAP const g_pModuleHeap = X_PMODULE_HEAP(_Module); \
   void _dllinit(void) \
   { \
      /* Deliberately do nothing */ \
   } \
   void _dllterm(void) \
   { \
      /* Deliberately do nothing */ \
   }

#else /* IBM i or Watcom */

#define X_HEAPDLLMAIN_EX_CRT(_Module, _HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize)

#endif

#define X_HEAPDLLMAIN_CRT(_HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX_CRT(DEFAULT, _HeapName, _HeapSize)

/* -------------------------------------------------------------------------*/
/* X_HEAPDLLMAIN_LANSAHEAP is used by DLLS that do not create their own heap*/
/* Either the heap pointer can be left null, in which case the default      */
/* LANSA heap will be used, or another DLL can pass the heap in and it can  */
/* be set by custom code. It is the intention that Components will set the  */
/* heap that has been created by X_COMP.DLL.                                */
/* Why use this macro when a heap is not being created? Because the DLL's   */
/* entry points will be listed so that access violation locations can be    */
/* pin-pointed to the DLL that caused it.                                   */
/* -------------------------------------------------------------------------*/

#if defined(X_OPERATING_SYSTEM_WIN) && defined(X_MSVC)

#define X_HEAPDLLMAIN_EX_LANSAHEAP(_Module, _HeapName, _HeapSize) \
   extern BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved); \
   X_DEF_MODULE_MAPPROC(_Module) \
   X_HEAP X_MODULE_HEAP(_Module) = \
      { NULL, _HeapName, DllMain, X_MODULE_MAPPROC(_Module) }; \
   X_PHEAP const g_pModuleHeap = X_PMODULE_HEAP(_Module); \
   BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved) \
   { \
      switch (fdwReason) \
      { \
         case DLL_PROCESS_ATTACH: \
            X_PDF_HeapListInsert(&X_MODULE_HEAP(_Module)); \
            break; \
         case DLL_THREAD_ATTACH: \
            break; \
         case DLL_THREAD_DETACH: \
            break; \
         case DLL_PROCESS_DETACH: \
            X_PDF_HeapListRemove(&X_MODULE_HEAP(_Module)); \
            break; \
         default: \
            break; \
      } \
      return TRUE; \
   }

#else /* Unix or Watcom */

#define X_HEAPDLLMAIN_EX_LANSAHEAP(_Module, _HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize)

#endif

#define X_HEAPDLLMAIN_LANSAHEAP(_HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX_LANSAHEAP(DEFAULT, _HeapName, _HeapSize)

/* DC_* IO Modules are built with Watcom so they use the default LANSA heap */
#define X_HEAPDLLMAIN_EX_DC(_Module, _HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize)

#define X_HEAPDLLMAIN_DC(_HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX_DC(DEFAULT, _HeapName, _HeapSize)

/* All generated objects use private heaps if built with MSVC */
#define X_HEAPDLLMAIN_EX_GENERATED(_Module, _HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX(_Module, _HeapName, _HeapSize)

#define X_HEAPDLLMAIN_GENERATED(_HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX_GENERATED(DEFAULT, _HeapName, _HeapSize)

/* Components already have heap created in x_comp, so use default LANSA Heap for the little  */
/* memory allocated in the generated code. The potential is here fpr x_comp.dll to  pass     */
/* a heap in during initialisation. This will need to be in x_fun or the generated code.     */
#define X_HEAPDLLMAIN_EX_COMPONENT(_Module, _HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX_LANSAHEAP(_Module, _HeapName, _HeapSize)

#define X_HEAPDLLMAIN_COMPONENT(_HeapName, _HeapSize) \
   X_HEAPDLLMAIN_EX_COMPONENT(DEFAULT, _HeapName, _HeapSize)

#endif /* X_LANSAX_BUILD */

#endif // X_OPERATING_TARGET_CSHARP

/* -------------------------------------------------------------------------  */
/* Macros and enumeration used by all sub-systems of Visual LANSA             */
/* -------------------------------------------------------------------------  */

/* File State. Note that only 23 bits can be used, not the full 32 */
typedef enum
{
   FileIsStrictSqlNullCompare = 0x00000001,
   FileIsStrictSqlNullValue   = 0x00000002,
   FileIsMax                  = 0x10000000      /* Causes Watcom to use an int to store the enumeration   */
                                                /* Can change the identifier name to anything useful if   */
                                                /* the value needs to be used. Enumeration must just have */
                                                /* a value that requires an int to store it. See          */
                                                /* 32-bit:  Size of Enumerated Types in the Watcom doco   */
                                                /* NEVER actually use FileIsMax as only 23 bits can be    */
                                                /* stored in X27SP1.                                      */

} XFILESTATE;

#ifndef X_OPERATING_TARGET_CSHARP

   #if !defined( X_ALLOW_MESSAGE_BOX ) && defined( X_LANSAX_BUILD )

   /* Errors are often introduced by using MessageBox without consideration for non-interactive environment */
   /* So don't allow it. */

   #ifdef MessageBox
   #undef MessageBox
   #define MessageBox MessageBoxMustNotBeUsed=
   #endif

   #endif

#endif // X_OPERATING_TARGET_CSHARP

/* Macros to mimic file permissions - copied from sys/stat.h*/
#if defined(X_OPERATING_SYSTEM_WIN)
#ifndef __WATCOMC__
#ifndef S_IRUSR
#define S_IRUSR      0000400
#endif
#ifndef S_IWUSR
#define S_IWUSR      0000200
#endif
#ifndef S_IXUSR
#define S_IXUSR      0000100
#endif
#ifndef S_IRWXU
#define S_IRWXU      (S_IRUSR | S_IWUSR | S_IXUSR)
#endif
#ifndef S_IRGRP
#define S_IRGRP      0000040
#endif
#ifndef S_IWGRP
#define S_IWGRP      0000020
#endif
#ifndef S_IXGRP
#define S_IXGRP      0000010
#endif
#ifndef S_IRWXG
#define S_IRWXG      (S_IRGRP | S_IWGRP | S_IXGRP)
#endif
#ifndef S_IROTH
#define S_IROTH      0000004
#endif
#ifndef S_IWOTH
#define S_IWOTH      0000002
#endif
#ifndef S_IXOTH
#define S_IXOTH      0000001
#endif
#ifndef S_IRWXO
#define S_IRWXO      (S_IROTH | S_IWOTH | S_IXOTH)
#endif
#else /* !def __WATCOMC__ */
#include <sys/stat.h>
#endif
#endif /* if defined (X_OPERATING_SYSTEM_WIN) */

/* TN: file open mode for X_PDF_open */
#if defined(X_OPERATING_SYSTEM_UNIX)
/*
 *  For security, S_IWOTH should not be granted by default.
 *  For security sensitive files, S_IROTH should not be granted as well.
 *  So this macro should only be used for non security sensitive files.
 */
#define X_READ_AND_WRITE_PERMITTED (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#else
#define X_READ_AND_WRITE_PERMITTED (S_IRWXU | S_IRGRP)
#endif

#if defined(__x86_64__)
#ifndef SIZE_T_FMT
#define SIZE_T_FMT "lu"
#endif
#ifndef SSIZE_T_FMT
#define SSIZE_T_FMT "ld"
#endif
#else
#ifndef SIZE_T_FMT
#define SIZE_T_FMT "u"
#endif
#ifndef SSIZE_T_FMT
#define SSIZE_T_FMT "d"
#endif
#endif
#ifndef SIZEOF_FMT
#define SIZEOF_FMT SIZE_T_FMT
#endif

#if defined(X_OPERATING_SYSTEM_ISERIES) || defined(X_OPERATING_SYSTEM_UNIX)
#define X_PATH_MAX PATH_MAX
#elif defined(X_OPERATING_SYSTEM_WIN)
#define X_PATH_MAX _MAX_PATH
#else
#define X_PATH_MAX (1024)
#endif

#endif /* __INCL_X_GLODEF_H__ */

#endif
