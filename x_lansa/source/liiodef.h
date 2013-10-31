/**********************************************************************/
/*                                                                    */
/* MODULE:              LIIODEF.H                                     */
/*                                                                    */
/* DESCRIPTION:         Contains definitions that define various      */
/*                      interfaces between LANSA/PC, LANSA/X and      */
/*                      the Component Editor.                         */
/*                                                                    */
/**********************************************************************/

#ifndef LIIODEF_INCLUDE

#define LIIODEF_INCLUDE

/* ================================================ */
/* These are shared records so get constant packing */
/* ================================================ */
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable:4103) // alignment changed after including header
#ifdef __cplusplus
#pragma warning (disable:4510) // default constructor could not be generated
#pragma warning (disable:4512) // assignment operator could not be generated
#pragma warning (disable:4610) // struct can never be instantiated
#endif
#endif

#include "x_bldcfg.h"

#if defined(X_OPERATING_SYSTEM_WIN)
// Includes earlier to avoid WIN32_LEAN_AND_MEAN
// and macros min() and max() should be from x_cutil.h
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "windows.h"
#endif

#include "x_ctypes.h"

#if 0
/* Not shipping utilcp.h and so cannot use it */
#include "utilcp.h"
#endif

#include "x_strpck.h"

#ifdef __cplusplus
extern "C" {
#endif

struct X_IDS;
struct X_PRO;
struct X_FUN;
struct X_FLD;
struct X_FKEY;

/**********************************************************************/
/*                                                                    */
/*               GENERIC MATERIAL USED BY ALL INTERFACES              */
/*               ---------------------------------------              */
/* The following material defines generic interfaces between all      */
/* forms of LANSA/PC, LANSA/X and Component Routines.                 */
/*                                                                    */
/**********************************************************************/

#define X_COMP_RETURN_CODE X_LONG

#define X_COMP_DLLIMPORT   __declspec( dllimport )
#define X_COMP_DLLEXPORT   __declspec( dllexport )
#define X_COMP_DLLENTRY
#define X_COMP_DLLCALL

#if 0
/*
 *  Should following UTC_CodePage in utilcp.h and
 *  utilconv.c will consume variables of this type.
 */
#if defined(X_OPERATING_SYSTEM_WIN) || defined(X_OPERATING_SYSTEM_ISERIES)
typedef int    X_COMP_CODEPAGE;
#else
typedef char*  X_COMP_CODEPAGE;
#endif
#else
#if 0
/* Not shipping utilcp.h and so cannot use it */
typedef UTC_CodePage X_COMP_CODEPAGE;
#else
/* Follow as close as possible to utilcp.h */
#if defined(X_OPERATING_SYSTEM_WIN) || defined(X_OPERATING_SYSTEM_ISERIES)
typedef unsigned int X_COMP_CODEPAGE;
#elif defined(X_OPERATING_SYSTEM_UNIX)
#ifndef UTC_PAGECODE_NAME_LEN
#if defined(X_OPERATING_SYSTEM_PASE) || defined(X_OPERATING_SYSTEM_AIX)
#define UTC_PAGECODE_NAME_LEN    20
#else
#define UTC_PAGECODE_NAME_LEN    30
#endif
#endif
typedef char X_COMP_CODEPAGE[UTC_PAGECODE_NAME_LEN + 1];
#endif
#endif
#endif

/**********************************************************************/
/*                                                                    */
/*                         LENGTH CONSTANTS                           */
/*                                                                    */
/**********************************************************************/

enum ObjectDll
{
   ODEF_DLL_NONE = 1,
   ODEF_DLL_PART = 2,
   ODEF_DLL_SYST = 3,
   ODEF_DLL_DATA_LIB = 4,
   ODEF_DLL_MODULE_LIB = 5
};

enum WamOption
{
   ODEF_WEBROUTINE_NONE = 0,
   ODEF_WEBROUTINE_NEW = 1,
   ODEF_WEBROUTINE_ALL = 3
};

#define ODEF_STD_FIELD                    ""
#define ODEF_STD_VS                       "STD_VS"
#define ODEF_STD_RVP                      "STD_PANL"
#define ODEF_STD_CURSOR                   "STD_CRSR"
#define ODEF_STD_ICON                     "STD_ICON"
#define ODEF_STD_BITMAP                   "STD_BTMAP"
#define ODEF_STD_FORM                     "STD_FORM"
#define ODEF_STD_DATE                     "STD_DATE"
#define ODEF_STD_ALPHA                    "STD_ALPHA"
#define ODEF_STD_NUMERIC                  "STD_NUMBR"
#define ODEF_STD_ENTRY                    "STD_ENTRY"
#define ODEF_STD_SPINBUTTON               "STD_SPNBTN"
#define ODEF_STD_RADIOBUTTON              "STD_RADBTN"
#define ODEF_STD_CHECKBOX                 "STD_CHKBOX"
#define ODEF_STD_ACTIVEX                  "STD_ACTVX"
#define ODEF_STD_BO                       "STD_BO"
#define ODEF_STD_WAM                      "STD_WAM"

/* Class identifiers for metaclasses */
#define ODEF_MCID_FIELD                   0
#define ODEF_MCID_PRIMITIVE               2
#define ODEF_MCID_DERIVED                 3
#define ODEF_MCID_FORM                    4
#define ODEF_MCID_REUSABLEVISUALPART      5
#define ODEF_MCID_ACTIVEX                 6
#define ODEF_MCID_BUSINESSOBJECT          7
#define ODEF_MCID_WEB_APPLICATION_MODULE  8
#define ODEF_MCID_EXTERNAL_RESOURCE       9
#define ODEF_MCID_DOT_NET_PROXY           10
#define ODEF_MCID_WEB_SERVICE_PROXY       11
#define ODEF_MCID_WEB_PAGE                12
#define ODEF_MCID_RESOURCE                100
#define ODEF_MCID_VISUALSTYLE             101
#define ODEF_MCID_BITMAP                  102
#define ODEF_MCID_ICON                    103
#define ODEF_MCID_CURSOR                  104
#define ODEF_MCID_ALL                     1000

#define ODEF_VSID_ENTRY                   1
#define ODEF_VSID_RADIOBUTTON             2
#define ODEF_VSID_CHECKBOX                3
#define ODEF_VSID_SPINBUTTON              4

#define ODEF_OBJTYPE_FIELD                0
#define ODEF_OBJTYPE_FILE                 1
#define ODEF_OBJTYPE_PROCESS              2
#define ODEF_OBJTYPE_FUNCTION             3
#define ODEF_OBJTYPE_VARIABLE             4
#define ODEF_OBJTYPE_RTMESSAGE            5
#define ODEF_OBJTYPE_COMPONENT            6
#define ODEF_OBJTYPE_MEMBER               7
#define ODEF_OBJTYPE_METHOD               8
#define ODEF_OBJTYPE_EVENT                9
#define ODEF_OBJTYPE_PROPERTY             10
#define ODEF_OBJTYPE_CLASS                11

#define ODEF_CLASSNAMELEN                 9
#define ODEF_METACLASSLEN                 5
#define ODEF_VISUALSTYLELEN               5
#define ODEF_COMPONENTNAMELEN             20
#define ODEF_EVENTNAMELEN                 20
#define ODEF_PROPERTYNAMELEN              20
#define ODEF_MAPUSAGEIDLEN                20
#define ODEF_SELECTORNAMELEN              20
#define ODEF_ROUTINENAMELEN               20
#define ODEF_BLOBLEN                      250
#define ODEF_RDMLPARMLEN                  100
#define ODEF_BLOBIDLEN                    10
#define ODEF_MEMBERNAMELEN                20
#define ODEF_METHODNAMELEN                20
#define ODEF_PROPERTYVALUELEN             20
#define ODEF_WEB_DATA_LEN                 500
#define ODEF_WEB_SERVICE_NAME_LEN         30
#define ODEF_QUALIFIED_NAME_LEN           40

#define ODEF_GROUP_NAME_LEN               20
#define ODEF_GROUP_DESC_LEN               40
#define ODEF_FRAMEWORK_NAME_LEN           20
#define ODEF_FRAMEWORK_DESC_LEN           40


#define ODEF_COMPONENT_DESC_LEN           40
#define ODEF_COMPONENT_HELPTEXT_LEN       250

#define ODEF_SEQUENCE_INCREMENT           1

#define ODEF_FORMPAINTER                  "LIIYMAIN.EXE"

#define ODEF_CHAR_TRUE                    '1'
#define ODEF_CHAR_FALSE                   '0'

#define ODEF_QUERY_LOCAL_DIR                 1
#define ODEF_QUERY_LOCAL_DSN_DIR             2
#define ODEF_QUERY_DEV_ENV_LANGUAGE          3
#define ODEF_QUERY_ENCODED_LANSA_ROOT        4
#define ODEF_QUERY_PARTITION_ID              5
#define ODEF_QUERY_ALL_TASK_ID               6
#define ODEF_QUERY_LX_EXECUTE_DIR            7
#define ODEF_QUERY_X_RUN_COMMAND_LINE        8
#define ODEF_QUERY_DEFAULT_LIBRARY           9
#define ODEF_QUERY_DECIMAL_POINT_CHAR        10
#define ODEF_QUERY_DEFAULT_LANGUAGE          11
#define ODEF_QUERY_CURRENT_LANGUAGE          12
#define ODEF_QUERY_WAM_LICENCE               13
#define ODEF_QUERY_DEFINED_FUNCTION          14
#define ODEF_QUERY_DEFINED_NEXT_FUNCTION     15
#define ODEF_QUERY_IS_USER_QSECOFR           16
#define ODEF_QUERY_CPU_NUMBER                17
#define ODEF_QUERY_CONFIG_NAME               18
#define ODEF_QUERY_ISERIES_CONNECTION        19
#define ODEF_QUERY_LX_SOURCE_DIR             20
#define ODEF_QUERY_LX_LANSA_DIR              21
#define ODEF_QUERY_VL_FRAMEWORK_STATUS       22
#define ODEF_QUERY_USER_ID                   23
#define ODEF_QUERY_GROUP_USER_ID             24
#define ODEF_QUERY_LICENCE                   25
#define ODEF_QUERY_SYSTEM_ROOT_DIR           26
#define ODEF_QUERY_LX_OBJECT_DIR             27
#define ODEF_QUERY_LX_PARTITION_DIR          28
#define ODEF_QUERY_LX_PARTITION_SOURCE_DIR   29
#define ODEF_QUERY_LX_PARTITION_OBJECT_DIR   30
#define ODEF_QUERY_LX_PARTITION_EXECUTE_DIR  31
#define ODEF_QUERY_LX_PACKAGE_DIR            32
#define ODEF_QUERY_LX_TEMP_DIR               33
#define ODEF_QUERY_TASK_PREFIX               34
#define ODEF_QUERY_TASK_UNLOCK_CHECK_IN      35
#define ODEF_QUERY_SYSTEM_OWNER              36
#define ODEF_QUERY_PART_SEC_OFFICER          37
#define ODEF_QUERY_WINDOWS_TEMP_DIR          38
#define ODEF_QUERY_LX_WIN95_DIR              39
#define ODEF_QUERY_DEVELOPMENT_ROOT_DIR      40
#define ODEF_QUERY_WEB_IMAGES_ROOT_DIR       41
#define ODEF_QUERY_WEB_SCRIPT_ROOT_DIR       42
#define ODEF_QUERY_WEB_STYLE_ROOT_DIR        43
#define ODEF_QUERY_DEFAULT_LANGUAGE_ISO      44


#define ODEF_GETSET_LOCK                     1
#define ODEF_GETSET_AUTO_CLOSE               2
#define ODEF_GETSET_CANCEL_CHANGE_MESSAGE    3
#define ODEF_GETSET_DEV_LANGUAGE             4
#define ODEF_GETSET_LL2_FIELD                5
#define ODEF_GETSET_TASK_ID                  6
#define ODEF_GETSET_BUILD_BIF_DEFINITION     7
#define ODEF_GETSET_COMPILE_OPTION           8
#define ODEF_GETSET_VERSIONING               9

#define ODEF_LICENCE_DEMO                    0
#define ODEF_LICENCE_VL_DEVELOPMENT          0x0001
#define ODEF_LICENCE_WEB                     0x0002
/* #define ODEF_LICENCE_XML                     0x0004 */ /*OBSOLETE*/
#define ODEF_LICENCE_REPOSITORY              0x0008
#define ODEF_LICENCE_5250                    0x0010
#define ODEF_LICENCE_ROM                     0x0020

/* -------------- */
/* Type constants */
/* -------------- */

#define ODEF_RDML_TYPE_ALPHA        "*CHAR"
#define ODEF_RDML_TYPE_PACKED       "*PACKED"
#define ODEF_RDML_TYPE_PACKED_2     "*DEC"
#define ODEF_RDML_TYPE_SIGNED       "*SIGNED"
#define ODEF_RDML_TYPE_SIGNED_2     "*SIGN"
#define ODEF_RDML_TYPE_VARCHAR      "*VARCHAR"
#define ODEF_RDML_TYPE_STRING       "*STRING"
#define ODEF_RDML_TYPE_BINARY       "*BIN"
#define ODEF_RDML_TYPE_BOOLEAN      "*BOOLEAN"
#define ODEF_RDML_TYPE_DATE         "*DATE"
#define ODEF_RDML_TYPE_TIME         "*TIME"
#define ODEF_RDML_TYPE_DATETIME     "*DATETIME"
#define ODEF_RDML_TYPE_INTEGER      "*INT"
#define ODEF_RDML_TYPE_FLOAT        "*FLOAT"
#define ODEF_RDML_TYPE_CLOB         "*CLOB"
#define ODEF_RDML_TYPE_BLOB         "*BLOB"
#define ODEF_RDML_TYPE_NVARCHAR     "*NVARCHAR"

#define ODEF_FFC_TYPE_ALPHA         "*CHAR  "
#define ODEF_FFC_TYPE_PACKED        "*PACKED"
#define ODEF_FFC_TYPE_PACKED_2      "*DEC   "
#define ODEF_FFC_TYPE_SIGNED        "*SIGNED"
#define ODEF_FFC_TYPE_SIGNED_2      "*SIGN  "
#define ODEF_FFC_TYPE_VARCHAR       "*VARCHA"
#define ODEF_FFC_TYPE_STRING        "*STRING"
#define ODEF_FFC_TYPE_BINARY        "*BIN   "
#define ODEF_FFC_TYPE_BOOLEAN       "*BOOLEA"
#define ODEF_FFC_TYPE_DATE          "*DATE  "
#define ODEF_FFC_TYPE_TIME          "*TIME  "
#define ODEF_FFC_TYPE_DATETIME      "*DATETI"
#define ODEF_FFC_TYPE_INTEGER       "*INT   "
#define ODEF_FFC_TYPE_FLOAT         "*FLOAT "
#define ODEF_FFC_TYPE_CLOB          "*CLOB  "
#define ODEF_FFC_TYPE_BLOB          "*BLOB  "
#define ODEF_FFC_TYPE_NVARCHAR      "*NVARCH"

#define ODEF_OPERATOR_NONE          0
#define ODEF_OPERATOR_EQUAL         1
#define ODEF_OPERATOR_NOT_EQUAL     2
#define ODEF_OPERATOR_GREATER_THAN  3
#define ODEF_OPERATOR_GREATER_EQUAL 4
#define ODEF_OPERATOR_LESS_THAN     5
#define ODEF_OPERATOR_LESS_EQUAL    6
#define ODEF_OPERATOR_LIKE          7

/* ------------ */
/* Return Codes */
/* ------------ */

#define X_COMP_RETURN_ILLEGAL_TRANSFER_REQUESTED 23L
#define X_COMP_RETURN_WAM_NOT_FOUND              22L
#define X_COMP_RETURN_MODULE_NOT_A_WAM           21L
#define X_COMP_RETURN_WEB_ROUTINE_NOT_FOUND      20L

#define X_COMP_RETURN_TRANSFER_REQUESTED         12L
#define X_COMP_RETURN_NO_CLOSE                   11L
#define X_COMP_RETURN_CLOSE_REQUESTED            10L

#define X_COMP_RETURN_MESSAGE_NOT_HANDLED        4L
#define X_COMP_RETURN_TERMINATE_ENUMERATION      3L
#define X_COMP_RETURN_NOTHING_FOUND              2L
#define X_COMP_RETURN_TRUE                       1L

#define X_COMP_RETURN_OK                         0L
#define X_COMP_RETURN_FALSE                      0L

#define X_COMP_RETURN_CALLBACK_FAILED           -2L
#define X_COMP_RETURN_INVALID_NAME              -3L
#define X_COMP_RETURN_INVALID_ARGUMENT          -4L
#define X_COMP_RETURN_ERROR                     -1L
#define X_COMP_RETURN_INVALID_PARAMETERS        -2L
#define X_COMP_RETURN_INITIALIZATION_FAILED     -3L
#define X_COMP_RETURN_OBJECT_NOT_FOUND          -5L
#define X_COMP_RETURN_ERRORS_IN_ARGUMENTS       -6L

#define X_COMP_RETURN_OBJECT_UNKNOWN            -7L
#define X_COMP_RETURN_OBJECT_INVALID            -8L

#define X_COMP_RETURN_TEMPLATE_NOT_FOUND        -9L
#define X_COMP_RETURN_TEMPLATE_FAILED           -10L

#define X_COMP_PROPERTY_NOT_FOUND               -11L
#define X_COMP_PROPERTY_NO_GET                  -12L

#define X_COMP_RETURN_BUSY                      -14L

#define X_COMP_RETURN_LOCK_FAILURE              -15L
#define X_COMP_RETURN_TSP_NOT_FOUND             -16L
#define X_COMP_RETURN_ACCESS_RIGHT_FAILED       -17L

#define X_COMP_RETURN_DISPATCH_NOT_PROCESSED    -20L
#define X_COMP_RETURN_DISPATCH_INVALID_VALUE    -21L
#define X_COMP_RETURN_DISPATCH_INVALID_CAST     -22L

#define X_COMP_RETURN_WEB_SESSION_TIMEOUT       -30L
#define X_COMP_RETURN_WEB_SESSION_INVALID       -31L
#define X_COMP_RETURN_WEB_SESSION_LOCK_FAILED   -32L

#define X_COMP_RETURN_NOT_AUTHORIZED_TO_DELETE_OBJECT    -40L
#define X_COMP_RETURN_NOT_AUTHORIZED_TO_MODIFY_OBJECT    -41L
#define X_COMP_RETURN_CURRENT_TASK_IS_CLOSED             -42L
#define X_COMP_RETURN_NOT_AUTHORIZED_TO_CURRENT_TASK     -43L
#define X_COMP_RETURN_NOT_CHECKED_OUT                    -44L
#define X_COMP_RETURN_LOCKED_TO_OTHER_TASK               -45L
#define X_COMP_RETURN_USED_BY_OTHER                      -46L
#define X_COMP_RETURN_LOCKED_TO_OTHER_PC                 -47L

#define X_COMP_RETURN_DISPATCH_SCOPING_NONE       0L
#define X_COMP_RETURN_DISPATCH_SCOPING_READ       1L
#define X_COMP_RETURN_DISPATCH_SCOPING_READ_WRITE 2L


typedef int (_X_COMP_CALLBACK)(void *, void *, void *);
typedef int (*X_COMP_CALLBACK)(void *, void *, void *);
typedef int (*X_COMP_PROMPTCALLBACK)(void **);

#define ODEF_STD_CONTEXTID 0

/**********************************************************************/
/*                                                                    */
/*             LANSA/X AND X_DEFS ASSEMBLY DEFINITIONS                */
/*             ---------------------------------------                */
/* The following material defines interfaces between LANSA/X runtime  */
/* routines and the C# X_DEFS assembly runtime routines.              */
/*                                                                    */
/**********************************************************************/

#ifndef X_OPERATING_TARGET_CSHARP

#define X_DEFS_LANSA_SERVICES_FUNCTION       void *
#define X_DEFS_DISPATCH_ID_TABLE             const X_COMP_DISPATCH_ID*
#define X_DEFS_HEADER_TABLE                  const X_COMP_HEADER**
#define X_DEFS_VAR_HEADER_TABLE              X_VAR_HEADER**
#define X_DEFS_FLD_TABLE                     struct X_FLD *
#define X_DEFS_X_SHORT_TABLE                 X_SHORT *
#define X_DEFS_VAR_OPERAND_TABLE             X_VAR_EXPRESSION_OPERAND *
#define X_DEFS_LIST_TABLE                    struct X_LIST *
#define X_DEFS_LIST_VOID_TABLE               PX_LIST_VOID
#define X_DEFS_LIST_DATA_PTR                 X_PCHAR
#define X_DEFS_COMPONENT_MANAGER_FUNCTION    X_PVOID
#define X_DEFS_INVOCATION_TRACKING_PTR       struct X_INVOC_TRACKING * 
#define X_DEFS_INVOCATION_FRAMES             X_PVOID*
#define X_DEFS_FLD_PACKED_DATA_PTR           X_FCHAR
#define X_DEFS_FLD_SIGNED_DATA_PTR           X_FCHAR
#define X_DEFS_FLD_EVALUATION_TABLE_PTR      X_PPVOID
#define X_DEFS_FLD_SHORT_PTR                 X_PSHORT    
#define X_DEFS_AGREED_ARGS_PTR               void**
#define X_DEFS_LANG_TABLE                    const struct X_LANG *

#endif // X_OPERATING_TARGET_CSHARP


/**********************************************************************/
/*                                                                    */
/*               LANSA/X AND X_COMP.DLL INTERFACES                    */
/*               ---------------------------------                    */
/* The following material defines interfaces between LANSA/X run      */
/* time routines and X_COMP.DLL run time routines.                    */
/*                                                                    */
/**********************************************************************/

#ifndef X_OPERATING_SYSTEM_ISERIES
   #define X_COMP_SERVICES_DLL_NAME          "x_comp"
#else
   #define X_COMP_SERVICES_DLL_NAME          "X_COMP"
#endif
#define X_COMP_SERVICES_ENTRY_POINT_NAME  "X_COMPONENT_SERVICES"

/* ------------------------------------------------------------------ */
/* Standard request block passed between LANSA/X and Component Editor */
/* ------------------------------------------------------------------ */


typedef struct _X_COMP_SERVICES_POINT_REQUEST
{

   long                             lRequest;
   void *                           pX_Ids;
   X_DEFS_LANSA_SERVICES_FUNCTION   pfnLANSAServices;
   unsigned long                    ulRDMLXLineNumber;

}     X_COMP_SERVICES_POINT_REQUEST,
  *  PX_COMP_SERVICES_POINT_REQUEST,
 ** PPX_COMP_SERVICES_POINT_REQUEST;


/* ---------------------------------------- */
/* Standard negotiable component definition */
/* ---------------------------------------- */

#define X_COMP_NAME_CONTEXT_COMPONENT   '\x01'

#define X_COMP_NAME_CONTEXT_OTHER       '\x02'


typedef struct _X_COMP_NEGOTIABLE_COMPONENT
{

   unsigned char                 chNameContext;
   unsigned long                 ulNameHandle;
   void *                        pvActualObject;

}     X_COMP_NEGOTIABLE_COMPONENT,
  *  PX_COMP_NEGOTIABLE_COMPONENT,
 ** PPX_COMP_NEGOTIABLE_COMPONENT;


/* ------------------------------------------------------ */
/* Definition of interface between LANSA/X and X_COMP.DLL */
/* ------------------------------------------------------ */
/* @2506C1 */
#if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_ISERIES)

typedef X_COMP_RETURN_CODE FN_COMP_SERVICES_POINT
    ( PX_COMP_SERVICES_POINT_REQUEST pRequestBlock,
      void *                         apvAgreedArgs[],
      X_ULONG                        ulNoofNegotiableComps,
      X_COMP_NEGOTIABLE_COMPONENT    aNegotiableComps[] );

#else

typedef X_COMP_RETURN_CODE __cdecl FN_COMP_SERVICES_POINT
    ( PX_COMP_SERVICES_POINT_REQUEST pRequestBlock,
      void *                         apvAgreedArgs[],
      X_ULONG                        ulNoofNegotiableComps,
      X_COMP_NEGOTIABLE_COMPONENT    aNegotiableComps[] );

#endif

typedef FN_COMP_SERVICES_POINT *   PFN_COMP_SERVICES_POINT;
typedef FN_COMP_SERVICES_POINT ** PPFN_COMP_SERVICES_POINT;

/* -------------------------------------------------------- */
/* -------------------------------------------------------- */
/* Run time service requests between LANSA/X and X_COMP.DLL */
/* -------------------------------------------------------- */
/* -------------------------------------------------------- */

#define X_COMP_SERVICES_START                               1L
#define X_COMP_SERVICES_TERMINATE                           2L
#define X_COMP_SERVICES_RUN_FORM                            3L
#define X_COMP_SERVICES_RUN_FUNCTION                        4L
#define X_COMP_SERVICES_RUN_WEB_ROUTINE                     5L
#define X_COMP_SERVICES_CREATE_INSTANCE                     6L
#define X_COMP_SERVICES_PROCESS_BOM_MESSAGE_SSV             7L
#define X_COMP_SERVICES_CREATE_BOM_OPERATION_COMPONENT      8L

#define X_COMP_SERVICES_REGISTER_MODULE                     10L
#define X_COMP_SERVICES_UNREGISTER_MODULE                   11L

#define X_COMP_SERVICES_LOAD_COMPONENT                      5001L
#define X_COMP_SERVICES_UNLOAD_COMPONENT                    5002L
#define X_COMP_SERVICES_CHECK_FATAL_ERROR                   5003L
#define X_COMP_SERVICES_ISSUE_MESSAGE                       5004L
#define X_COMP_SERVICES_SET_IME_MODE                        5005L

#define X_COMP_GET_COMPONENT_AS_LONG                        5007L
#define X_COMP_GET_COMPONENT_AS_DOUBLE                      5008L
#define X_COMP_GET_COMPONENT_AS_STRING                      5009L
#define X_COMP_SET_COMPONENT_FROM_LONG                      5010L
#define X_COMP_SET_COMPONENT_FROM_DOUBLE                    5011L
#define X_COMP_SET_COMPONENT_FROM_STRING                    5012L

#define X_COMP_SERVICES_QUERY_SYSTEM_INFO                   5014L
#define X_COMP_SERVICES_PREPARE_FOR_OUTPUT                  5015L
#define X_COMP_SERVICES_VERIFY_FOR_INPUT                    5016L
#define X_COMP_SERVICES_GET_LIST_ENTRY                      5017L
#define X_COMP_SERVICES_UPDATE_LIST_ENTRY                   5018L

#define X_COMP_GET_FIRST_LEVEL_TEXT                         5019L
#define X_COMP_GET_SECOND_LEVEL_TEXT                        5020L

#define X_COMP_SERVICES_ISSUE_FATAL_MESSAGE                 5030L

#define X_COMP_SERVICES_LOAD_DLL                            5040L
#define X_COMP_SERVICES_UNLOAD_DLL                          5041L
#define X_COMP_SERVICES_QUERY_PROC_ADDRESS                  5042L
#define X_COMP_SERVICES_EXECUTE_FUNCTION                    5043L
#define X_COMP_SERVICES_WRITE_TO_EXCHANGE_LIST              5044L
#define X_COMP_SERVICES_READ_FROM_EXCHANGE_LIST             5045L
#define X_COMP_SERVICES_RESOLVE_VECTOR_ASSIGNMENT_FCN       5046L

#define X_COMP_SERVICES_SHOW_HELP                           5050L
#define X_COMP_SERVICES_TRY_HELP                            5051L

#define X_COMP_SERVICES_GET_EBCDIC_LENGTH                   5060L

#define X_COMP_SERVICES_SET_ALL_ERRORS_OFF                  5070L
#define X_COMP_SERVICES_CLEAR_MESSAGES                      5071L

#define X_COMP_SERVICES_TRACE_START                         5080L
#define X_COMP_SERVICES_TRACE_EVENT                         5081L
#define X_COMP_SERVICES_TRACE_END                           5082L

#define X_COMP_SERVICES_CREATE_COMPONENT                    5090L
#define X_COMP_SERVICES_RELEASE_COMPONENT                   5091L
#define X_COMP_SERVICES_GET_COM_INTERFACE                   5092L
#define X_COMP_SERVICES_QUERY_DEVLOPMENT_ENV                5093L

#define X_COMP_DISPATCH_RDMLX_COMMAND                       5100L

#define X_COMP_CREATE_LIST_ENTRY                            5110L
#define X_COMP_UPDATE_LIST_GET_ENTRY                        5111L
#define X_COMP_GET_LIST_ENTRY                               5112L
#define X_COMP_DELETE_LIST_ENTRY                            5113L
#define X_COMP_CLEAR_LIST                                   5114L
#define X_COMP_GET_LIST_CURRENT_ENTRY_COUNT                 5115L
#define X_COMP_PREPARE_CREATE_LIST_ENTRY                    5116L
#define X_COMP_UPDATE_LIST_UPD_ENTRY                        5117L

#define X_COMP_CLEAR_MESSAGES                               5120L
#define X_COMP_ADD_NEW_MESSAGE                              5121L
#define X_COMP_SHOW_STATUS_MESSAGE                          5122L

#define X_COMP_DISPATCH_RDMLX_CONDITION                     5130L

#define X_COMP_DISPATCH_ITERATOR_STEP                       5140L
#define X_COMP_DISPATCH_ITERATOR_DESTROY                    5141L
#define X_COMP_DISPATCH_ITERATOR_DISASSEMBLE                5142L

#define X_COMP_QUERY_COMPONENT_SCOPE                        5200L
#define X_COMP_SIGNAL_RESTARTING_AFTER_DEBUG                5201L
#define X_COMP_SIGNAL_STOPPING_FOR_DEBUG                    5202L
#define X_COMP_SIGNAL_UIM_WAS_ACTIVATED                     5203L
#define X_COMP_SIGNAL_UIM_MAYBE_ACTIVATED                   5204L
#define X_COMP_SIGNAL_DEBUGGER_CLOSING                      5205L

#define X_COMP_SET_ERROR_STATE_ON                           5300L
#define X_COMP_SET_ERROR_STATE_OFF                          5301L
#define X_COMP_SET_ALL_ERRORS_OFF                           5302L

#define X_COMP_HANDLE_YIELD_PROCESSING                      5400L

/* ------------------------------------------------ */
/* Run time service requests supporting WAMS        */
/* ------------------------------------------------ */

#define X_COMP_SERVICES_WAM_BEGIN_WEB_ROUTINE         5500L
#define X_COMP_SERVICES_WAM_END_WEB_ROUTINE           5501L

#define X_COMP_SERVICES_WAM_MAP_LIST_IN               5510L
#define X_COMP_SERVICES_WAM_MAP_FIELD_IN              5511L
#define X_COMP_SERVICES_WAM_MAP_LIST_MERGE            5512L

#define X_COMP_SERVICES_WAM_MAP_LIST_OUT              5520L
#define X_COMP_SERVICES_WAM_MAP_FIELD_OUT             5521L

#define X_COMP_SERVICES_WAM_MAP_LIST_SAVE             5530L
#define X_COMP_SERVICES_WAM_MAP_FIELD_SAVE            5531L

#define X_COMP_SERVICES_WAM_MAP_LIST_RESTORE          5540L
#define X_COMP_SERVICES_WAM_MAP_FIELD_RESTORE         5541L

#define X_COMP_SERVICES_WAM_FROM_SERVICE_NAME         5550L

#define X_COMP_SERVICES_WAM_PRE_INVOKE_WEB_ROUTINE    5560L
#define X_COMP_SERVICES_WAM_POST_INVOKE_WEB_ROUTINE   5561L

#define X_COMP_SERVICES_WAM_BEGIN_HTTP_RESPONSE       5570L
#define X_COMP_SERVICES_WAM_END_HTTP_RESPONSE         5571L
#define X_COMP_SERVICES_WAM_HTTP_RESPONSE_SET_HEADER  5572L

/* --------------------------------------------------- */
/* Run time service requests supporting component DLLs */
/* --------------------------------------------------- */

#define X_COMP_GET_MODULE_INFO                  1L
#define X_COMP_INIT_MODULE_INSTANCE             2L
#define X_COMP_TERM_MODULE_INSTANCE             3L
#define X_COMP_INIT_COMPONENT_INSTANCE          4L
#define X_COMP_TERM_COMPONENT_INSTANCE          5L
#define X_COMP_INIT_ROUTINE_INSTANCE            6L
#define X_COMP_RUN_ROUTINE_INSTANCE             7L
#define X_COMP_TERM_ROUTINE_INSTANCE            8L
#define X_COMP_INITIALIZE_LOADED_MODULE_DLL     9L
#define X_COMP_GET_VECTOR_VALUE_DIRECT          10L
#define X_COMP_SET_VECTOR_VALUE_DIRECT          11L
#define X_COMP_SHUTDOWN_LOADED_MODULE           12L
#define X_COMP_GET_COMPONENT_EXCHANGE_ADDRESS   14L
#define X_COMP_GET_COMPONENT_EXCHANGE_COUNT     15L
#define X_COMP_APPLY_MFLD_ADDRESSABILITY        16L
#define X_COMP_RUN_FUNCTION                     17L
#define X_COMP_GET_VECTOR_VALUE_GENERIC         18L
#define X_COMP_SET_VECTOR_VALUE_GENERIC         19L
#define X_COMP_GET_MODULE_MEMBER_INFO           20L

#define X_COMP_EXCHANGE_AS_STRING               1L
#define X_COMP_EXCHANGE_AS_LONG                 2L
#define X_COMP_EXCHANGE_AS_DOUBLE               3L
#define X_COMP_EXCHANGE_NOT_POSSIBLE            4L
#define X_COMP_EXCHANGE_AS_INT8                 5L
#define X_COMP_EXCHANGE_AS_UINT8                6L
#define X_COMP_EXCHANGE_AS_INT16                7L
#define X_COMP_EXCHANGE_AS_INT32                8L
#define X_COMP_EXCHANGE_AS_INT64                9L
#define X_COMP_EXCHANGE_AS_SIGNED               10L

/* --------------------------------------- */
/* Template generated code routing options */
/* --------------------------------------- */

#define X_COMP_TEMPLATE_ROUTE_TO_BEGIN         '\x01'
#define X_COMP_TEMPLATE_ROUTE_TO_END           '\x02'
#define X_COMP_TEMPLATE_ROUTE_TO_CURSOR        '\x03'
#define X_COMP_TEMPLATE_ROUTE_TO_DEFINITIONS   '\x04'
#define X_COMP_TEMPLATE_ROUTE_TO_ROUTINES      '\x05'

/* --------------------------------------- */
/* Target presentation options             */
/* --------------------------------------- */

#define X_COMP_EXECUTE_RENDER_WIN32             'W'  // Win32
#define X_COMP_EXECUTE_RENDER_MIXED             'M'  // Win32 & DirectX
#define X_COMP_EXECUTE_RENDER_DIRECTX           'X'  // DirectX

#define X_COMP_EXECUTE_RENDER_HARDWARE          'H'  // Hardware
#define X_COMP_EXECUTE_RENDER_SOFTWARE          'S'  // Software

/* ----------------------------------------------------------------- */
/* Component services interface structures used by LIIOSRV.DLL       */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VISUAL_STYLE
{
   long                                            lIdentifier;
   char                                         *  pvchDescription;
   void                                         *  hIcon;
   char                                         *  pvchTemplate;
}  X_COMP_VISUAL_STYLE,
   *PX_COMP_VISUAL_STYLE,
   **PPX_COMP_VISUAL_STYLE;

/* ----------------------------------------------------------------- */
/* Component Metaclass                                               */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_METACLASS
{
   long                                            lIdentifier;
   char                                         *  pvchDescription;
   int                                             fIsRepositoryField;
   int                                             fIsCompilable;
   int                                             fIsExecutable;
   char                                         *  pvchTemplate;
   void                                         *  hIcon;
   long                                            lNumVisualStyles;
   PX_COMP_VISUAL_STYLE                            aVisualStyles;
}  X_COMP_METACLASS,
   *PX_COMP_METACLASS,
   **PPX_COMP_METACLASS;

/* ----------------------------------------------------------------- */
/* Component Grouping                                                */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_GROUPING
{
   long                                            lGroupId1;
   long                                            lGroupId2;
}  X_COMP_COMPONENT_GROUPING,
   *PX_COMP_COMPONENT_GROUPING,
   **PPX_COMP_COMPONENT_GROUPING;

/* ----------------------------------------------------------------- */
/* Component Reference                                               */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_REFERENCE
{
   char                                         *  pvchReferencedClass;
   char                                         *  pvchReferenceSummary;
   long                                            lReferenceContext;
}  X_COMP_COMPONENT_REFERENCE,
   *PX_COMP_COMPONENT_REFERENCE,
   **PPX_COMP_COMPONENT_REFERENCE;

/* ----------------------------------------------------------------- */
/* Component Feature Usage                                           */
/* ----------------------------------------------------------------- */

#define X_COMP_FEATURE_USED_AS_PTY_GET_ROUTINE  1L
#define X_COMP_FEATURE_USED_AS_PTY_SET_ROUTINE  2L
#define X_COMP_FEATURE_USED_AS_DEFAULT_PROPERTY 3L

#define X_COMP_FEATURE_MODIFIED_PUBLIC_ACCESS   10L
#define X_COMP_FEATURE_MODIFIED_PROTECT_ACCESS  11L
#define X_COMP_FEATURE_MODIFIED_PRIVATE_ACCESS  12L

typedef struct _X_COMP_COMPONENT_FEATURE_USAGE
{
   long                                            lUsageType;
   char                                         *  pvchFeatureName;

}  X_COMP_COMPONENT_FEATURE_USAGE,
   *PX_COMP_COMPONENT_FEATURE_USAGE,
   **PPX_COMP_COMPONENT_FEATURE_USAGE;

/* ----------------------------------------------------------------- */
/* Component Map                                                     */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_MAPPING
{
   char                                         *  pvchUsageIdentifier;
   char                                         *  pvchSelectorVisualName;
   long                                            lUsageType;
   char                                            chUsedFor;
   char                                         *  pvchSelectorPattern;
   char                                         *  pvchSelectorClass;
   char                                            chMandatory;
   char                                            chPassBy;
   char                                         *  pvchDescription;
   char                                         *  pvchHelpText;

}  X_COMP_COMPONENT_MAPPING,
   *PX_COMP_COMPONENT_MAPPING,
   **PPX_COMP_COMPONENT_MAPPING;

/* ----------------------------------------------------------------- */
/* Component Event                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_EVENT
{
   char                                         *  pvchVisualName;
   char                                            chAccess;
   char                                            chRedefined;
   char                                            chResetErrors;
   char                                            chResetMessages;
   char                                         *  pvchDescription;
   char                                         *  pvchHelpText;
   long                                            lNumMappings;
   struct _X_COMP_COMPONENT_MAPPING             *  aMappings;
}  X_COMP_COMPONENT_EVENT,
   *PX_COMP_COMPONENT_EVENT,
   **PPX_COMP_COMPONENT_EVENT;

/* ----------------------------------------------------------------- */
/* Component Method                                                  */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_METHOD
{
   char                                         *  pvchVisualName;
   char                                            chAccess;
   char                                            chRedefined;
   char                                         *  pvchDescription;
   char                                         *  pvchHelpText;
   long                                            lNumMappings;
   struct _X_COMP_COMPONENT_MAPPING             *  aMappings;

}  X_COMP_COMPONENT_METHOD,
   *PX_COMP_COMPONENT_METHOD,
   **PPX_COMP_COMPONENT_METHOD;

/* ----------------------------------------------------------------- */
/* Component Property                                                */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_PROPERTY
{
   char                                         *  pvchVisualName;
   char                                            chSupportsGet;
   char                                            chSupportsSet;
   char                                            chAccess;
   char                                            chRedefined;
   char                                            chStored;
   char                                         *  pvchDescription;
   char                                         *  pvchHelpText;
   long                                            lNumMappings;
   struct _X_COMP_COMPONENT_MAPPING             *  aMappings;
   long                                            lNumFeatureUsages;
   struct _X_COMP_COMPONENT_FEATURE_USAGE       *  aFeatureUsages;

}  X_COMP_COMPONENT_PROPERTY,
   *PX_COMP_COMPONENT_PROPERTY,
   **PPX_COMP_COMPONENT_PROPERTY;

/* ----------------------------------------------------------------- */
/* Component Routine                                                 */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_ROUTINE
{
   char                                         *  pvchVisualName;
   long                                            lUsageType;
   char                                            chAccess;
   char                                            chRedefined;
   char                                            chResetErrors;
   char                                            chResetMessages;
   char                                         *  pvchDescription;
   char                                         *  pvchHelpText;
   long                                            lNumMappings;
   struct _X_COMP_COMPONENT_MAPPING             *  aMappings;

}  X_COMP_COMPONENT_ROUTINE,
   *PX_COMP_COMPONENT_ROUTINE,
   **PPX_COMP_COMPONENT_ROUTINE;

/* ----------------------------------------------------------------- */
/* Component Blob                                                    */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_BLOB
{
   char                                         *  pvchIdentifier1;
   char                                         *  pvchIdentifier2;
   char                                         *  pvchBlob;

}  X_COMP_COMPONENT_BLOB,
   *PX_COMP_COMPONENT_BLOB,
   **PPX_COMP_COMPONENT_BLOB;

/* ----------------------------------------------------------------- */
/* Component Blob                                                    */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_BLOB_DATA
{
   int                                             iContextId;
   int                                             iLine;
   int                                             iSeq;
   int                                             iLength;
   unsigned char                                *  pbBlob;

}  X_COMP_COMPONENT_BLOB_DATA,
   *PX_COMP_COMPONENT_BLOB_DATA,
   **PPX_COMP_COMPONENT_BLOB_DATA;

/* ----------------------------------------------------------------- */
/* Timestamp                                                         */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION_RDML_TIMESTAMP
{
   char  *  pvchDate;
   char  *  pvchUser;
   char  *  pvchTaskId;

}  X_COMP_FUNCTION_RDML_TIMESTAMP,
   *PX_COMP_FUNCTION_RDML_TIMESTAMP,
   **PPX_COMP_FUNCTION_RDML_TIMESTAMP;

/* ----------------------------------------------------------------- */
/* Component Rdml                                                    */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_RDML
{
   char                                         *  pvchLabel;
   char                                         *  pvchCommand;
   long                                            lCommandId;
   char                                         *  pvchParameters;
   struct _X_COMP_FUNCTION_RDML_TIMESTAMP       *  pTimeStamp;

}  X_COMP_COMPONENT_RDML,
   *PX_COMP_COMPONENT_RDML,
   **PPX_COMP_COMPONENT_RDML;

/* ----------------------------------------------------------------- */
/* Component Property Settings                                       */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_PROPERTY_SETTINGS
{
   char                                         *  pvchOwnerComponentName;
   char                                         *  pvchPropertyName;
   char                                         *  pvchValue;
   unsigned long                                   ullExpressionModifiers;

}  X_COMP_COMPONENT_PROPERTY_SETTINGS,
   *PX_COMP_COMPONENT_PROPERTY_SETTINGS,
   **PPX_COMP_COMPONENT_PROPERTY_SETTINGS;

/* ----------------------------------------------------------------- */
/* Component Identifier                                              */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_IDENTIFIER
{
   char                                         *  pvchName;
   long                                            lContextIdentifier;
   long                                            lMetaClass;
   int                                             fNewlyCreated;

}  X_COMP_COMPONENT_IDENTIFIER,
   *PX_COMP_COMPONENT_IDENTIFIER,
   **PPX_COMP_COMPONENT_IDENTIFIER;

/* ----------------------------------------------------------------- */
/* Impact List Analysis Query                                        */
/* ----------------------------------------------------------------- */

typedef unsigned long
   X_COMP_OBJECT_TYPES;

#define X_COMP_OBJECT_TYPES_FIELD                              0x00000001
#define X_COMP_OBJECT_TYPES_FILE                               0x00000002
#define X_COMP_OBJECT_TYPES_FORM                               0x00000004
#define X_COMP_OBJECT_TYPES_FUNCTION                           0x00000008
#define X_COMP_OBJECT_TYPES_PROCESS                            0x00000010
#define X_COMP_OBJECT_TYPES_REUSABLE_PART                      0x00000020
#define X_COMP_OBJECT_TYPES_ACTIVE_X                           0x00000040
#define X_COMP_OBJECT_TYPES_BITMAP                             0x00000080
#define X_COMP_OBJECT_TYPES_CURSOR                             0x00000100
#define X_COMP_OBJECT_TYPES_ICON                               0x00000200
#define X_COMP_OBJECT_TYPES_VISUAL_STYLE                       0x00000400
#define X_COMP_OBJECT_TYPES_MULTILINGUAL_VARIABLE              0x00000800
#define X_COMP_OBJECT_TYPES_SYSTEM_VARIABLE                    0x00001000
#define X_COMP_OBJECT_TYPES_EXTERNAL_RESOURCE                  0x00002000
#define X_COMP_OBJECT_TYPES_WAM                                0x00004000
#define X_COMP_OBJECT_TYPES_WEBLET                             0x00008000
#define X_COMP_OBJECT_TYPES_MESSAGE_FILE                       0x00010000
#define X_COMP_OBJECT_TYPES_IMPACT_LIST                        0x00020000

typedef unsigned long
   X_COMP_COMPILATION_STATUS;

#define X_COMP_COMPILATION_STATUS_BUILD_COMPILE_NOT_REQUIRED   0x00000001
#define X_COMP_COMPILATION_STATUS_LAST_BUILD_COMPILE_FAILED    0x00000002
#define X_COMP_COMPILATION_STATUS_COMPILE_REQUIRED             0x00000004
#define X_COMP_COMPILATION_STATUS_BUILD_AND_COMPILE_REQUIRED   0x00000008
#define X_COMP_COMPILATION_STATUS_NEVER_COMPILE                0x00000010

typedef struct _X_COMP_IMPACT_ANALYSIS_QUERY
{
   // Common Filters
   X_COMP_OBJECT_TYPES                             ulObjectTypes;
   long                                            lCommonNameOperator;
   char                                         *  pvchCommonNameValue;
   long                                            lCommonDescriptionOperator;
   char                                         *  pvchCommonDescriptionValue;
   long                                            lCommonUserOperator;
   char                                         *  pvchCommonUserValue;
   long                                            lCommonTaskOperator;
   char                                         *  pvchCommonTaskValue;
   long                                            lCommonReferringToOperator;
   char                                         *  pvchCommonReferringToValue;
   long                                            lCommonReferredToByOperator;
   char                                         *  pvchCommonReferredToByValue;
   long                                            lCommonStatusOperator;
   X_COMP_COMPILATION_STATUS                       ulCommonStatusValue;
   long                                            lCommonModifiedBeforeOperator;
   char                                         *  pvchCommonModifiedBeforeValue;
   long                                            lCommonModifiedAfterOperator;
   char                                         *  pvchCommonModifiedAfterValue;
   long                                            lCommonRDMLXEnabledOperator;
   char                                         *  pvchCommonRDMLXEnabledValue;
   long                                            lCommonTextToFindOperator;
   char                                         *  pvchCommonTextToFindValue;
   // Field Filters
   long                                            lFieldTypeOperator;
   char                                         *  pvchFieldTypeValue;
   long                                            lFieldLengthOperator;
   char                                         *  pvchFieldLengthValue;
   long                                            lFieldDecimalsOperator;
   char                                         *  pvchFieldDecimalsValue;
   long                                            lFieldDefaultValueOperator;
   char                                         *  pvchFieldDefaultValueValue;
   long                                            lFieldReferenceFieldOperator;
   char                                         *  pvchFieldReferenceFieldValue;
   long                                            lFieldLabelOperator;
   char                                         *  pvchFieldLabelValue;
   long                                            lFieldHeading1Operator;
   char                                         *  pvchFieldHeading1Value;
   long                                            lFieldHeading2Operator;
   char                                         *  pvchFieldHeading2Value;
   long                                            lFieldHeading3Operator;
   char                                         *  pvchFieldHeading3Value;
   long                                            lFieldEditCodeOperator;
   char                                         *  pvchFieldEditCodeValue;
   long                                            lFieldEditWordOperator;
   char                                         *  pvchFieldEditWordValue;
   long                                            lFieldKeyboardShiftOperator;
   char                                         *  pvchFieldKeyboardShiftValue;
   long                                            lFieldInputAttributesOperator;
   char                                         *  pvchFieldInputAttributesValue;
   long                                            lFieldOutputAttributesOperator;
   char                                         *  pvchFieldOutputAttributesValue;
   long                                            lFieldFieldVisualizationOperator;
   char                                         *  pvchFieldFieldVisualizationValue;
   //File Filters
   long                                            lFileLibraryOperator;
   char                                         *  pvchFileLibraryValue;
   long                                            lFileTypeOperator;
   char                                         *  pvchFileTypeValue;
   long                                            lFileRecordFormatNameOperator;
   char                                         *  pvchFileRecordFormatNameValue;
   long                                            lFileDBTriggerUsedOperator;
   char                                         *  pvchFileDBTriggerUsedValue;
   long                                            lFileDBTriggerProgramOperator;
   char                                         *  pvchFileDBTriggerProgramValue;
   long                                            lFileAccessRouteFileOperator; // N/A
   char                                         *  pvchFileAccessRouteFileValue;
   long                                            lFileBatchControlFileOperator; // N/A
   char                                         *  pvchFileBatchControlFileValue;
   long                                            lFileVirtualFieldNameOperator;
   char                                         *  pvchFileVirtualFieldNameValue;
   long                                            lFileVirtualFieldDescriptionOperator; // N/A
   char                                         *  pvchFileVirtualFieldDescriptionValue;
   long                                            lFileDeriveValueOperator; // N/A
   char                                         *  pvchFileDeriveValueValue;
   long                                            lFilePopulateValueOperator; // N/A
   char                                         *  pvchFilePopulateValueValue;
   long                                            lFileAccessRouteNameOperator; // N/A
   char                                         *  pvchFileAccessRouteNameValue;
   long                                            lFileAcessRouteDescriptionOperator; // N/A
   char                                         *  pvchFileAcessRouteDescriptionValue;
   long                                            lFileAccessedFileOperator; // N/A
   char                                         *  pvchFileAccessedFileValue;
   long                                            lFileMaximumRecordOperator; // N/A
   char                                         *  pvchFileMaximumRecordValue;
   long                                            lFileBatchControlFileNameOperator; // N/A
   char                                         *  pvchFileBatchControlFileNameValue;
   long                                            lFileLinkSourceFieldOperator; // N/A
   char                                         *  pvchFileLinkSourceFieldValue;
   long                                            lFileLinkTargetFieldOperator; // N/A
   char                                         *  pvchFileLinkTargetFieldValue;
   long                                            lFileSupportedDBOperator; // N/A
   char                                         *  pvchFileSupportedDBValue;
   //Process Filters
   long                                            lProcessWebEnabledOperator;
   char                                         *  pvchProcessWebEnabledValue;
   long                                            __obs_lProcessXmlEnabledOperator; /*OBSOLETE*/
   char                                         *  __obs_pvchProcessXmlEnabledValue; /*OBSOLETE*/
   //Multilingual Variable Filters
   long                                            lMLLengthOperator;
   char                                         *  pvchMLLengthValue;
   long                                            lMLLanguageOperator;
   char                                         *  pvchMLLanguageValue;
   //System Variable Filters
   long                                            lSVMethodOfDerivationOperator;
   char                                         *  pvchSVMethodOfDerivationValue;
   long                                            lSVDataTypeOperator;
   char                                         *  pvchSVDataTypeValue;
   long                                            lSVLengthOperator;
   char                                         *  pvchSVLengthValue;
   long                                            lSVDecimalsOperator;
   char                                         *  pvchSVDecimalsValue;
   //Message Filters
   long                                            lMessageFileNameOperator;
   char                                         *  pvchMessageFileNameValue;
   long                                            lMessageFileLanguageOperator;
   char                                         *  pvchMessageFileLanguageValue;

}  X_COMP_IMPACT_ANALYSIS_QUERY,
   *PX_COMP_IMPACT_ANALYSIS_QUERY,
   **PPX_COMP_IMPACT_ANALYSIS_QUERY;



/* ----------------------------------------------------------------- */
/* Component Definition                                              */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT
{
   char                                         *  pvchComponentIdentifier;
   char                                         *  pvchAncestorIdentifier;
   char                                         *  pvchVisualIdentifier;
   char                                         *  pvchDescription;
   char                                         *  pvchHint;
   int                                             fPrimitive;
   int                                             f4GLVisible;
   long                                            lFrameworkIdentifier1;
   long                                            lFrameworkIdentifier2;
   long                                            lScope;
   long                                            lMetaClass;
   long                                            lVisualStyle;
   char                                         *  pvchImplementationName;

}  X_COMP_COMPONENT,
   *PX_COMP_COMPONENT,
   **PPX_COMP_COMPONENT;

/* ----------------------------------------------------------------- */
/* Component Member                                                  */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPONENT_MEMBER
{
   char                                         *  pvchVisualName;
   char                                         *  pvchMemberPattern;
   char                                         *  pvchMemberClass;
   char                                            chScope;
   char                                            chUsage;
   char                                         *  pvchDescription;
   char                                         *  pvchHelpText;
   long                                            lNumPropertySettings;
   struct _X_COMP_COMPONENT_PROPERTY_SETTINGS   *  aPropertySettings;
   long                                            lNumFeatureUsages;
   struct _X_COMP_COMPONENT_FEATURE_USAGE       *  aFeatureUsages;

}  X_COMP_COMPONENT_MEMBER,
   *PX_COMP_COMPONENT_MEMBER,
   **PPX_COMP_COMPONENT_MEMBER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_MTXT
{
   char                                         *  pvchName;
   char                                         *  pvchLang;
   char                                         *  pvchValue;
   short                                           sLength;
   char                                         *  pvchModifiedDate;
}  X_COMP_MTXT,
   *PX_COMP_MTXT,
   **PPX_COMP_MTXT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_SYSVAR
{
   char                                         *  pvchName;
   char                                         *  pvchDesc;
   char                                            chType;
   short                                           sLength;
   short                                           sDecimals;
   char                                         *  pvchProgram;
   char                                            chDynamic;
   char                                         *  pvchModifiedDate;

}  X_COMP_SYSVAR,
   *PX_COMP_SYSVAR,
   **PPX_COMP_SYSVAR;

/* ----------------------------------------------------------------- */
/* X_COMP_FILE                                                       */
/* Some parts of this structure are duplicated from FILE_ATTRIBUTE.  */
/* This is the neatest way of handling it so as to keep memory       */
/* management clean and have consistent patterns.                    */
/* This is the lightweight proxy carried by the IDE.                 */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FILE
{
   char                                         *  pvchName;
   char                                         *  pvchLibrary;
   char                                         *  pvchDescription;
   char                                         *  pvchModifiedDate;
   char                                         *  pvchDBTriggerProgramName;  // Also in X_COMP_FILE_ATTRIBUTE
   char                                            chStatus;
   char                                            chType;                    // Also in X_COMP_FILE_ATTRIBUTE
   char                                            chLanguageLevel;
   int                                             fInternal;
   int                                             fReadOnly;                 // Also in X_COMP_FILE_ATTRIBUTE
   int                                             fAutoRRNO;                 // Also in X_COMP_FILE_ATTRIBUTE
   int                                             fEnabledForLongNames;      // Also in X_COMP_FILE_ATTRIBUTE

}  X_COMP_FILE,
   *PX_COMP_FILE,
   **PPX_COMP_FILE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FILE_ATTRIBUTE
{
   char                                            chType;
   char                                         *  pvchParameter;
   int                                             fCommitControl;
   int                                             fAutoCommit;
   int                                             fShare;
   int                                             fSecure;
   int                                             fStripDebug;
   int                                             fSuppressIOM0034Message;
   int                                             fIgnoreDecimalError;
   char                                         *  pvchRecordFormatName;
   char                                         *  pvchAltSeq;
   int                                             fCreateIOM;
   int                                             fCreateBatchControl;
   int                                             fiSeriesHighSpeedTable;
   char                                            chIOMLibrary;
   int                                             fAutoRRNO;
   int                                             fCreateRRNOColumn;
   int                                             fUseSQL;
   int                                             fReadOnly;
   char                                            chNamingLevel;
   int                                             fDBTriggerEnabled;
   char                                         *  pvchDBTriggerProgramName;
   int                                             fFixedAutoRRNO;
   int                                             fEnabledForLongNames;

}  X_COMP_FILE_ATTRIBUTE,
   *PX_COMP_FILE_ATTRIBUTE,
   **PPX_COMP_FILE_ATTRIBUTE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FILE_DB_ATTRIBUTE
{
   char                                         *  pvchDBType;
   char                                         *  pvchType;
   char                                         *  pvchObject;
   int                                             iSeq;
   char                                         *  pvchData;

}  X_COMP_FILE_DB_ATTRIBUTE,
   *PX_COMP_FILE_DB_ATTRIBUTE,
   **PPX_COMP_FILE_DB_ATTRIBUTE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TEMPLATE
{
   long                                            lDisplaySequence;
   char                                         *  pvchName;
   char                                         *  pvchDescription;
   char                                         *  pvchExtDescription1;
   char                                         *  pvchExtDescription2;
   char                                         *  pvchExtDescription3;

}  X_COMP_TEMPLATE,
   *PX_COMP_TEMPLATE,
   **PPX_COMP_TEMPLATE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TEMPLATE_COMMAND
{
   char                                         *  pvchCommand;

}  X_COMP_TEMPLATE_COMMAND,
   *PX_COMP_TEMPLATE_COMMAND,
   **PPX_COMP_TEMPLATE_COMMAND;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TEMPLATE_HELP_TEXT
{
   char                                      *  pvchPanelId;
   char                                      *  pvchPanelDesc;
   char                                      *  pvchHelpText;
   long                                         lDisplaySequence;

}  X_COMP_TEMPLATE_HELP_TEXT,
   *PX_COMP_TEMPLATE_HELP_TEXT,
   **PPX_COMP_TEMPLATE_HELP_TEXT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TEMPLATE_OUTPUT
{
   long                                            lLineNumber;
   char                                         *  pvchOutputLine;
}
   X_COMP_TEMPLATE_OUTPUT,
   *PX_COMP_TEMPLATE_OUTPUT,
   **PPX_COMP_TEMPLATE_OUTPUT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VERSIONING
{
   char                                         *  pvchCompany;
   char                                         *  pvchCopyRight;
   char                                         *  pvchTradeMark;
   char                                         *  pvchProduct;
   char                                         *  pvchComment;
   char                                         *  pvchProductVersion;
   char                                         *  pvchFileVersion;
}
   X_COMP_VERSIONING,
   *PX_COMP_VERSIONING,
   **PPX_COMP_VERSIONING;

/* ----------------------------------------------------------------- */
/* Component Selection Criteria                                      */
/* ----------------------------------------------------------------- */

#define X_COMP_SELECTION_CRITERIA_IS_NONE          0
#define X_COMP_SELECTION_CRITERIA_IS_LETTER        1
#define X_COMP_SELECTION_CRITERIA_IS_LIKE          2
#define X_COMP_SELECTION_CRITERIA_IS_BETWEEN       3
#define X_COMP_SELECTION_CRITERIA_IS_BY_NAME       4
#define X_COMP_SELECTION_CRITERIA_IS_NOT_A_TO_Z    5
#define X_COMP_SELECTION_CRITERIA_IS_LANGUAGE      6
#define X_COMP_SELECTION_CRITERIA_IS_GROUP_BY_NAME 7

typedef struct _X_COMP_SELECTION_CRITERIA
{
   long                                            lSelectionCriteriaKind;
   char                                         *  pvchValueOne;
   char                                         *  pvchValueTwo;
}
   X_COMP_SELECTION_CRITERIA,
   *PX_COMP_SELECTION_CRITERIA,
   **PPX_COMP_SELECTION_CRITERIA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

#ifndef X_OPERATING_TARGET_CSHARP

typedef struct _X_COMP_BUILDFLAGS
{
   unsigned int fDebug             : 1;
   unsigned int fKeepSource        : 1;
   unsigned int fRebuildComponent  : 1;
   unsigned int fRecompileComponent: 1;
}  X_COMP_BUILDFLAGS,
   *PX_COMP_BUILDFLAGS,
   **PPX_COMP_BUILDFLAGS;

#endif // X_OPERATING_TARGET_CSHARP

/* ----------------------------------------------------------------- */
/* Types of help.                                                    */
/* ----------------------------------------------------------------- */

#define ODEF_WINHELP_CONTEXT_SENSITIVE 0
#define ODEF_WINHELP_GENERAL_HELP      1
#define ODEF_WINHELP_INDEXED_HELP      2
#define ODEF_WINHELP_MENU_HELP         4

/* ----------------------------------------------------------------- */
/* Types of Window command show.                                     */
/* ----------------------------------------------------------------- */

#define ODEF_SHOWWINDOW_HIDE           0
#define ODEF_SHOWWINDOW_SHOW           1
#define ODEF_SHOWWINDOW_POPUP          2

/* ----------------------------------------------------------------- */
/* Types of request supported by the LPC/Component editor interface. */
/* See request/response blocks below.                                */
/* ----------------------------------------------------------------- */

#define ODEF_LPCREQUEST_EDITCOMPONENT              1
#define ODEF_LPCREQUEST_UPDATE_COMPONENT           2
#define ODEF_LPCREQUEST_EDITCHECKCOMPONENT         3
#define ODEF_LPCREQUEST_ALIVE                      4
#define ODEF_LPCREQUEST_DESTROY                    5
#define ODEF_LPCREQUEST_SHOW_WINDOW                6
#define ODEF_LPCREQUEST_QUERY_CLOSE                7
#define ODEF_LPCREQUEST_EDIT_OBJECT_LIST           8
#define ODEF_LPCREQUEST_DELETE_COMPONENT           9
#define ODEF_LPCREQUEST_UPDATE_STATUS              10
#define ODEF_LPCREQUEST_HANDLE_FFC_JOB_BEGIN       11
#define ODEF_LPCREQUEST_HANDLE_FFC_JOB_END         12
#define ODEF_LPCREQUEST_HANDLE_COMPILE_JOB_BEGIN   13
#define ODEF_LPCREQUEST_HANDLE_COMPILE_JOB_END     14
#define ODEF_LPCREQUEST_HANDLE_JOB_ERROR           15
#define ODEF_LPCREQUEST_HANDLE_JOB_COMPLETE        16
#define ODEF_LPCREQUEST_HANDLE_JOB_ABORT           17

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_REQ_COMPONENT_IDENTIFIER
{
   char  chName[ODEF_QUALIFIED_NAME_LEN + 1];
   long  lContextIdentifier;
   long  lMetaClass;
   int   fNewlyCreated;
   long  lObjectType;

} X_COMP_REQ_COMPONENT_IDENTIFIER,
  *PX_COMP_REQ_COMPONENT_IDENTIFIER,
  **PPX_COMP_REQ_COMPONENT_IDENTIFIER;

/* ----------------------------------------------------------------- */
/* Request block mappings for the LPC/Component communications block */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LPCCMPE_EDIT_REQUEST
{
   X_COMP_REQ_COMPONENT_IDENTIFIER ComponentId;
} X_COMP_LPCCMPE_EDIT_REQUEST,
  *PX_COMP_LPCCMPE_EDIT_REQUEST,
  **PPX_COMP_LPCCMPE_EDIT_REQUEST;

/* ----------------------------------------------------------------- */
/* Events for the UpdateRequest block.                               */
/* ----------------------------------------------------------------- */

#define ODEF_EVENT_CHANGE 0
#define ODEF_EVENT_DELETE 1

typedef struct _X_COMP_LPCCMPE_UPDATE_REQUEST
{
   X_COMP_REQ_COMPONENT_IDENTIFIER  ComponentId;
   short                            sEvent;

} X_COMP_LPCCMPE_UPDATE_REQUEST,
  *PX_COMP_LPCCMPE_UPDATE_REQUEST,
  **PPX_COMP_LPCCMPE_UPDATE_REQUEST;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LPCCMPE_EDITCHECK_REQUEST
{
   X_COMP_REQ_COMPONENT_IDENTIFIER  ComponentId;

} X_COMP_LPCCMPE_EDITCHECK_REQUEST,
  *PX_COMP_LPCCMPE_EDITCHECK_REQUEST,
  **PPX_COMP_LPCCMPE_EDITCHECK_REQUEST;

/* ----------------------------------------------------------------- */
/* Response block mappings for the LPC/Component communications      */
/* block.                                                            */
/* ----------------------------------------------------------------- */

typedef union _X_COMP_LPCCMPE_GENERIC_RESPONSE
{
   X_COMP_RETURN_CODE   ReturnCode;

} X_COMP_LPCCMPE_GENERIC_RESPONSE,
  *PX_COMP_LPCCMPE_GENERIC_RESPONSE,
  **PPX_COMP_LPCCMPE_GENERIC_RESPONSE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef union _X_COMP_LPCCMPE_EDIT_RESPONSE
{
   X_COMP_RETURN_CODE   ReturnCode;

} X_COMP_LPCCMPE_EDIT_RESPONSE,
  *PX_COMP_LPCCMPE_EDIT_RESPONSE,
  **PPX_COMP_LPCCMPE_EDIT_RESPONSE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef union _X_COMP_LPCCMPE_EDITCHECK_RESPONSE
{
   X_COMP_RETURN_CODE   ReturnCode;

} X_COMP_LPCCMPE_EDITCHECK_RESPONSE,
  *PX_COMP_LPCCMPE_EDITCHECK_RESPONSE,
  **PPX_COMP_LPCCMPE_EDITCHECK_RESPONSE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef union _X_COMP_LPCCMPE_UPDATE_RESPONSE
{
   X_COMP_RETURN_CODE   ReturnCode;

} X_COMP_LPCCMPE_UPDATE_RESPONSE,
  *PX_COMP_LPCCMPE_UPDATE_RESPONSE,
  **PPX_COMP_LPCCMPE_UPDATE_RESPONSE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef union _X_COMP_LPCCMPE_RESPONSE_BLOCK
{
   X_COMP_LPCCMPE_EDIT_RESPONSE        EditResponse;
   X_COMP_LPCCMPE_UPDATE_RESPONSE      UpdateResponse;
   X_COMP_LPCCMPE_EDITCHECK_RESPONSE   EditCheckResponse;
   X_COMP_LPCCMPE_GENERIC_RESPONSE     GenericResponse;

} X_COMP_LPCCMPE_RESPONSE_BLOCK,
  *PX_COMP_LPCCMPE_RESPONSE_BLOCK,
  **PPX_COMP_LPCCMPE_RESPONSE_BLOCK;

/* ----------------------------------------------------------------- */
/* Request block for the LPC/Component comms block.                  */
/* ----------------------------------------------------------------- */

typedef union _X_COMP_LPCCMPE_REQUEST_BLOCK
{
   X_COMP_LPCCMPE_EDIT_REQUEST      EditRequest;
   X_COMP_LPCCMPE_UPDATE_REQUEST    UpdateRequest;
   X_COMP_LPCCMPE_EDITCHECK_REQUEST EditCheckRequest;

} X_COMP_LPCCMPE_REQUEST_BLOCK,
  *PX_COMP_LPCCMPE_REQUEST_BLOCK,
  **PPX_COMP_LPCCMPE_REQUEST_BLOCK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LPC_ANCHOR_BLOCK
{
   void                                *  hwndLPC;
   struct _X_COMP_LPCCMPE_COMMS_BLOCK  *  pLPCCMPECommsBlock;
   void                                *  hGDEFGlobalParms;
   void                                *  pGDEFGlobalParms;
   void                                *  pGDEFRDML;
   void                                *  pGDEFCUA;
   void                                *  pGDEFField;
} X_COMP_LPC_ANCHOR_BLOCK,
  *PX_COMP_LPC_ANCHOR_BLOCK,
  **PPX_COMP_LPC_ANCHOR_BLOCK;


/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LPCCMPE_COMMS_BLOCK
{
   void                             *  hwndFormPainter;
   void                             *  hwndParent;
   void                             *  hevFormStarted;
   void                             *  hsemRequestBlockAccess;
   short                               sRequest;
   X_COMP_LPCCMPE_REQUEST_BLOCK        RequestBlock;
   X_COMP_LPCCMPE_RESPONSE_BLOCK       ResponseBlock;

} X_COMP_LPCCMPE_COMMS_BLOCK,
  *PX_COMP_LPCCMPE_COMMS_BLOCK,
  **PPX_COMP_LPCCMPE_COMMS_BLOCK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_CMPE_ANCHOR_BLOCK
{
   PX_COMP_COMPONENT_IDENTIFIER     pComponentId;
   long                             lCursorPosition;
   void                          *  pObject;

} X_COMP_CMPE_ANCHOR_BLOCK,
  *PX_COMP_CMPE_ANCHOR_BLOCK,
  **PPX_COMP_CMPE_ANCHOR_BLOCK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_ANCHOR_ADAPTER_BLOCK
{
   void                                *  pVoid1;
   void                                *  pVoid2;
   void                                *  pVoid3;

} X_COMP_ANCHOR_ADAPTER_BLOCK,
  *PX_COMP_ANCHOR_ADAPTER_BLOCK,
  **PPX_COMP_ANCHOR_ADAPTER_BLOCK;

/* ----------------------------------------------------------------- */
/* Adapter to allow reinterpret_cast from void pointer back to       */
/* X_COMP_CALLBACK                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_CALLBACK_ADAPTER
{
   X_COMP_CALLBACK                        pfnfCallback;

} X_COMP_CALLBACK_ADAPTER,
  *PX_COMP_CALLBACK_ADAPTER,
  **PPX_COMP_CALLBACK_ADAPTER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_START_FORM_RESPONSE_BLOCK
{
   void  *  hwndFormPainter;
   void  *  hwndParent;

} X_COMP_START_FORM_RESPONSE_BLOCK,
  *PX_COMP_START_FORM_RESPONSE_BLOCK,
  **PPX_COMP_START_FORM_RESPONSE_BLOCK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PARTITION
{
   char                                      *  pvchName;
   char                                      *  pvchModuleLib;
   char                                         chUniquePrefix;
   char                                      *  pvchSecOfficer;
   char                                      *  pvchDefaultLib;
   int                                          fLibraryList;
   int                                          fAnsiStandard;
   int                                          fDocumentor;
   int                                          fTaskTracking;
   int                                          fCreateRRNO;
   int                                          fIgnorePropagateDelete;
   int                                          fPropagateDeleteCheck;
   int                                          fNumberProcessMenu;
   int                                          fUppercaseProcTitle;
   int                                          fUppercaseFuncTitle;
   int                                          fDisplayPanelId;
   int                                          fProcDateTime;
   int                                          fFuncDateTime;
   int                                          iFunctionKeyLine1;
   int                                          iFunctionKeyLine2;
   int                                          iMessageLineNumber;
   char                                         chWindowSide;
   char                                         chWindowTopBottom;
   char                                         chWindowTopCorner;
   char                                         chWindowBottomCorner;
   int                                          fSAAStandard;
   char                                         chLanguageLevel;
   int                                          fLL2OnNewComponent;
   int                                          fLL2OnNewFunction;
   int                                          fLL2OnNewField;
   int                                          fLL2OnNewFile;
   int                                          fIsScecurityOn;
   int                                          fSupportDB2;
   int                                          fSupportASA;
   int                                          fSupportSQLServer;
   int                                          fSupportOracle;
   int                                          fWebEnabled;
   char                                      *  pvchFunctionKeys;
   int                                          fForceEndWhereSQL;
   char                                         chEnableShortChar;
   char                                         chEnableLongNames;
   char                                         chLongNameWarning;

}  X_COMP_PARTITION,
   *PX_COMP_PARTITION,
   **PPX_COMP_PARTITION;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_USER
{
   char                                      *  pvchUser;
   char                                      *  pvchSystem;
   char                                      *  pvchUserProfile;
   char                                      *  pvchGroupUserProfile;
   char                                      *  pvchListUserProfile;
   char                                      *  pvchPassword;

}  X_COMP_USER,
   *PX_COMP_USER,
   **PPX_COMP_USER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_KERBEROS_USER
{
   char                                      *  pvchUser;
   char                                      *  pvchPrincipalName;

}  X_COMP_KERBEROS_USER,
   *PX_COMP_KERBEROS_USER,
   **PPX_COMP_KERBEROS_USER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_USER_SECURITY
{
   char                                      *  pvchSecurity;
   char                                      *  pvchUser;

}  X_COMP_USER_SECURITY,
   *PX_COMP_USER_SECURITY,
   **PPX_COMP_USER_SECURITY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_SERVER
{
   char                                      *  pvchServerName;
   char                                      *  pvchServerDesc;
   char                                         chServerType;
   char                                         chCommunicationMethod;
   int                                          fCreatedLocally;
   char                                      *  pvchCommunicationModuleName;
   char                                      *  pvchBuildEnvironmentName;
   char                                      *  pvchAllowablePartitions;
   char                                      *  pvchSSNName;

}  X_COMP_SERVER,
   *PX_COMP_SERVER,
   **PPX_COMP_SERVER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VL_FRAMEWORK_SETTING
{
   int                                          fAdminEnabled;
   int                                          fDesignEnabled;
   int                                          fUserEnabled;

}  X_COMP_VL_FRAMEWORK_SETTING,
   *PX_COMP_VL_FRAMEWORK_SETTING,
   **PPX_COMP_VL_FRAMEWORK_SETTING;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_SYSTEM_SETTING
{
   char                                         chV2Windows;
   char                                         chWindowTrim;
   char                                         chExtended_Triggers;
   char                                         chV2WAF;
   char                                         chUIMHelp;
   char                                         chSelectChar;
   char                                         chCheckBox;
   char                                         chRadioButton;
   char                                         chDropDown;
   char                                         chIOMNoAdopt;
   char                                         chIOMXServer;
   char                                         chIOMBlockByKey;
   char                                         chIOMBlockByRRN;
   char                                         chServerDebug;
   char                                         chRPGIV;
   char                                         chHStabExtend;
   char                                         chPermFilOvr;
   char                                      *  pvchMiniScreenMsgLin;
   char                                         chILE;
   char                                         chTTG6FuncLocking;
   char                                         chODBC;
   char                                         chFwdSlash;
   char                                         chBckSlash;
   char                                         chNoLADComp;
   char                                         chNoL4WComp;
   char                                         chNoWebExp;
   char                                         chNoWebImp;
   char                                         chImpRefFldNoProp;
   char                                         chFunRtrLibl;
   char                                         chWebNumVal;
   char                                         chOther_DateTime;
   char                                         chOther_VarChar;
   char                                         chNoXMLExp;
   char                                         chNoXMLImp;
   char                                         chCrudeWarnOnly;
   char                                      *  pvchLibraryPath;
   char                                      *  pvchLibrary;
   char                                      *  pvchSysOwner;
   int                                          iDefaultPrinterWidth;
   int                                          iDefaultPrinterFormLength;
   int                                          iDefaultPrinterOverflowLineNumber;
   int                                          iDefaultScreenWidth;
   int                                          iDefaultScreenLength;
   char                                      *  pvchDefaultAlphaInputAttribute;
   char                                      *  pvchDefaultNumericInputAttribute;
   char                                      *  pvchDefaultAlphaOutputAttribute;
   char                                      *  pvchDefaultNumericOutputAttribute;
   char                                      *  pvchSystemDateFormat;
   char                                         chDecimalFormat;
   char                                         chLabelFillChar;
   char                                         chUnderlineChar;
   int                                          fPromptKeyEnabled;
   int                                          f3GLExchangeListRequired;
   int                                          fFuncSecurityEnabled;
   int                                          fProcSecurityEnabled;
   int                                          fFileSecurityEnabled;
   char                                      *  pvchDefaultFileSIZE;
   char                                      *  pvchDefaultFileLVLCHK;
   char                                         chDefaultCommitmentControl;
   char                                      *  pvchCompany;
   int                                          iVersion;
   char                                      *  pvchMinorVersionLevel;
   char                                      *  pvchProduct;
   char                                         chOS400Version;
   char                                         chDbcsBuild;
   char                                         chSqlBuild;
   char                                         chSuppressLzLevel;
   char                                         chLongUserAudit;
   char                                         chVCSEnabled;
}  X_COMP_SYSTEM_SETTING,
   *PX_COMP_SYSTEM_SETTING,
   **PPX_COMP_SYSTEM_SETTING;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LOCK_DATA
{
   char                                      *  pvchNode;
   char                                      *  pvchUser;
   int                                          iProcId;
   int                                          iYear;
   int                                          iMonth;
   int                                          iDay;
   int                                          iHour;
   int                                          iMinute;
   int                                          iSecond;
   char                                      *  pszLock;
   char                                      *  pszPartition;
   char                                      *  pszLockType;
   char                                      *  pszObjectType;
   char                                      *  pszObject;
   char                                      *  pszExtent;

}  X_COMP_LOCK_DATA,
   *PX_COMP_LOCK_DATA,
   **PPX_COMP_LOCK_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DEV_LANGUAGE
{
   char                                      *  pvchCode;
   char                                      *  pvchDesc;
   int                                          fIsCurrent;
   int                                          fIsSaved;

}  X_COMP_DEV_LANGUAGE,
   *PX_COMP_DEV_LANGUAGE,
   *PPX_COMP_DEV_LANGUAGE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LANGUAGE
{
   char                                      *  pvchCode;
   char                                      *  pvchDesc;
   int                                          fIsDBCS;
   int                                          fIsRLTB;
   int                                          fIsCurrent;
   int                                          fIsDevLang;
   int                                          fLocale;
   int                                          fDefault;
   char                                      *  pvchPartitionDesc;
   int                                          fIGCCNV;
   char                                      *  pvchIGCCNVFuncKey;
   char                                      *  pvchIGCCNVFuncKeyDesc;
   char                                      *  pvchIGCCNVLineNumber;
   char                                      *  pvchProcMenuPromptLine;
   char                                      *  pvchHelpOption;
   char                                      *  pvchReturnPrefix;
   char                                      *  pvchExitOption;
   char                                      *  pvchMessageFiles;
   char                                      *  pvchCodePage;
   char                                      *  pvchFunctionKeyDesc;
   char                                      *  pvchIsoCharset;

}  X_COMP_LANGUAGE,
   *PX_COMP_LANGUAGE,
   **PPX_COMP_LANGUAGE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LANGUAGE_CODE_PAGE
{
   const char                                *  pvchLang;
   X_COMP_CODEPAGE                              CpClientCCSID;
   X_COMP_CODEPAGE                              CpServerCCSID;
   const char                                *  pvchIsoCharset;

}  X_COMP_LANGUAGE_CODE_PAGE,
   *PX_COMP_LANGUAGE_CODE_PAGE,
   **PPX_COMP_LANGUAGE_CODE_PAGE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FRAMEWORK
{
   long                                         lFrameworkIdentifier1;
   long                                         lFrameworkIdentifier2;
   int                                          fSystem;
   char                                      *  pvchShortName;
   char                                      *  pvchLongName;

}  X_COMP_FRAMEWORK,
   *PX_COMP_FRAMEWORK,
   **PPX_COMP_FRAMEWORK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_GROUP
{
   long                                         lGroupIdentifier1;
   long                                         lGroupIdentifier2;
   int                                          fSystem;
   char                                      *  pvchShortName;
   char                                      *  pvchLongName;

}  X_COMP_GROUP,
   *PX_COMP_GROUP,
   **PPX_COMP_GROUP;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_RDML_TOKENIZED
{
   char                                      *  pvchLabel;
   char                                      *  pvchCommand;
   long                                         lCommandId;
   long                                         lTokenizedParametersLength;
   char                                      *  pvchTokenizedParameters;

}  X_COMP_RDML_TOKENIZED,
   *PX_COMP_RDML_TOKENIZED,
   **PPX_COMP_RDML_TOKENIZED;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TASK_ID
{
   char                                      *  pvchTaskId;
   char                                      *  pvchDescription;
   int                                          fCurrentTask;
   char                                      *  pvchUsers;
   char                                      *  pvchStatus;
   char                                      *  pvchModifiedDate; /* TN: Updated date */

}  X_COMP_TASK_ID,
   *PX_COMP_TASK_ID,
   **PPX_COMP_TASK_ID;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TASK_PREFIX
{
   char                                      *  pvchSystem;
   char                                      *  pvchUser;
   char                                      *  pvchTask;

}  X_COMP_TASK_PREFIX,
   *PX_COMP_TASK_PREFIX,
   **PPX_COMP_TASK_PREFIX;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct X_COMP_TASK_UNLOCK_CHECK_IN
{
   int                                          fSystem;
   int                                          fUser;
   int                                          fTask;

}  X_COMP_TASK_UNLOCK_CHECK_IN,
   *PX_COMP_TASK_UNLOCK_CHECK_IN,
   **PPX_COMP_TASK_UNLOCK_CHECK_IN;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_HELP_TEXT
{
   char                                      *  pvchLangCode;
   char                                      *  pvchHelpText;

}  X_COMP_HELP_TEXT,
   *PX_COMP_HELP_TEXT,
   **PPX_COMP_HELP_TEXT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_MULTILINGUAL_TEXT
{
   char                                      *  pvchLanguageCode;
   char                                      *  pvchDescription;
   char                                      *  pvchLabel;
   char                                      *  pvchColumnHeading1;
   char                                      *  pvchColumnHeading2;
   char                                      *  pvchColumnHeading3;

}  X_COMP_MULTILINGUAL_TEXT,
   *PX_COMP_MULTILINGUAL_TEXT,
   **PPX_COMP_MULTILINGUAL_TEXT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE
{
   char                                      *  pvchCheckType;
   char                                      *  pvchDescription;
   char                                      *  pvchMessageText;
   char                                      *  pvchMessageId;
   char                                      *  pvchMessageFileName;
   char                                      *  pvchMessageFileLibrary;
   char                                         chPositiveAction;
   char                                         chNegativeAction;
   char                                         chAddAction;
   char                                         chChangeAction;
   char                                         chDeleteAction;

}  X_COMP_VALIDATION_RULE,
   *PX_COMP_VALIDATION_RULE,
   **PPX_COMP_VALIDATION_RULE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_RANGE
{
   char                                      *  pvchFromValue;
   char                                      *  pvchToValue;

}  X_COMP_VALIDATION_RULE_RANGE,
   *PX_COMP_VALIDATION_RULE_RANGE,
   **PPX_COMP_VALIDATION_RULE_RANGE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_LIST
{
   char                                      *  pvchValue;

}  X_COMP_VALIDATION_RULE_LIST,
   *PX_COMP_VALIDATION_RULE_LIST,
   **PPX_COMP_VALIDATION_RULE_LIST;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_LOOKUP
{
   char                                      *  pvchTable;
   char                                      *  pvchKeys;

}  X_COMP_VALIDATION_RULE_LOOKUP,
   *PX_COMP_VALIDATION_RULE_LOOKUP,
   **PPX_COMP_VALIDATION_RULE_LOOKUP;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_SIMPLE_CHECK
{
   char                                      *  pvchExpression ;

}  X_COMP_VALIDATION_RULE_SIMPLE_CHECK,
   *PX_COMP_VALIDATION_RULE_SIMPLE_CHECK,
   **PPX_COMP_VALIDATION_RULE_SIMPLE_CHECK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_COMPLEX_CHECK
{
   char                                      *  pvchProgramName;
   char                                      *  pvchParameters;

}  X_COMP_VALIDATION_RULE_COMPLEX_CHECK,
   *PX_COMP_VALIDATION_RULE_COMPLEX_CHECK,
   **PPX_COMP_VALIDATION_RULE_COMPLEX_CHECK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_DATE_CHECK
{
   char                                      *  pvchDateFormat;
   int                                          iDaysBefore;
   int                                          iDaysAfter;

}  X_COMP_VALIDATION_RULE_DATE_CHECK,
   *PX_COMP_VALIDATION_RULE_DATE_CHECK,
   **PPX_COMP_VALIDATION_RULE_DATE_CHECK;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VALIDATION_RULE_TRIGGER
{
   char                                      *  pvchTriggerName;
   char                                      *  pvchTriggerType;
   char                                      *  pvchTriggerBefore;
   char                                      *  pvchTriggerAfter;
   int                                          iConditionCount;
   char                                      *  pvchAndOr;
   char                                      *  pvchFieldName;
   char                                      *  pvchOperation;
   char                                      *  pvchValue;

}  X_COMP_VALIDATION_RULE_TRIGGER,
   *PX_COMP_VALIDATION_RULE_TRIGGER,
   **PPX_COMP_VALIDATION_RULE_TRIGGER;


/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DATA_SOURCE
{
   char                                      *  pvchName;
   char                                      *  pvchType;

}  X_COMP_DATA_SOURCE,
   *PX_COMP_DATA_SOURCE,
   **PPX_COMP_DATA_SOURCE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DATA_SOURCE_OBJECT
{
   char                                      *  pvchName;
   char                                      *  pvchQualifier;
   char                                      *  pvchDescription;
   char                                      *  pvchOwner;
   int                                          fUsedByLansa;
   char                                      *  pvchFile;
   char                                      *  pvchLibrary;
   int                                          fIsView;

}  X_COMP_DATA_SOURCE_OBJECT,
   *PX_COMP_DATA_SOURCE_OBJECT,
   **PPX_COMP_DATA_SOURCE_OBJECT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DATA_SOURCE_OPTION
{
   int                                          fCreateRRNOColumn;
   int                                          fAddLobColumn;

}  X_COMP_DATA_SOURCE_OPTION,
   *PX_COMP_DATA_SOURCE_OPTION,
   **PPX_COMP_DATA_SOURCE_OPTION;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DATA_SOURCE_OBJECT_COLUMN
{
   char                                      *  pvchName;
   char                                      *  pvchDescription;
   char                                      *  pvchTypeName;
   int                                          iType;
   long                                         lPrecision;
   long                                         lLength;
   int                                          iScale;
   int                                          iRadix;
   int                                          iNullable;
   int                                          iKeySeq;
   char                                      *  pvchField;
   char                                      *  pvchColumnDefault;

}  X_COMP_DATA_SOURCE_OBJECT_COLUMN,
   *PX_COMP_DATA_SOURCE_OBJECT_COLUMN,
   **PPX_COMP_DATA_SOURCE_OBJECT_COLUMN;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DATA_SOURCE_OBJECT_INDEX
{
   char                                      *  pvchName;
   char                                      *  pvchDescription;
   char                                         chAccessPathMaintenance;
   int                                          fUnique;
   int                                          fDynamic;

}  X_COMP_DATA_SOURCE_OBJECT_INDEX,
   *PX_COMP_DATA_SOURCE_OBJECT_INDEX,
   **PPX_COMP_DATA_SOURCE_OBJECT_INDEX;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_DATA_SOURCE_OBJECT_INDEX_KEY
{
   char                                      *  pvchName;
   char                                         chKeyOrder;
   char                                         chNumOrder;

}  X_COMP_DATA_SOURCE_OBJECT_INDEX_KEY,
   *PX_COMP_DATA_SOURCE_OBJECT_INDEX_KEY,
   **PPX_COMP_DATA_SOURCE_OBJECT_INDEX_KEY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_ISERIES_OTHER_FILE_COLUMN
{
   char                                      *  pvchName;
   char                                      *  pvchDescription;
   char                                      *  pvchTypeName;
   char                                         chType;
   int                                          iLength;
   int                                          iDecimal;
   char                                      *  pvchFormat;
   char                                         chSeparator;

}  X_COMP_ISERIES_OTHER_FILE_COLUMN,
   *PX_COMP_ISERIES_OTHER_FILE_COLUMN,
   **PPX_COMP_ISERIES_OTHER_FILE_COLUMN;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_OTHER_FILE_LOAD_FILE
{
   X_COMP_FILE                                  fileInfo;
   X_COMP_FILE_ATTRIBUTE                        fileAttributes;
   int                                          iAuthorityType;
   X_COMP_DATA_SOURCE_OBJECT                 *  pDataSourceObject;
   X_COMP_DATA_SOURCE                        *  pDataSource;
   X_COMP_DATA_SOURCE_OPTION                 *  pOption;

}  X_COMP_OTHER_FILE_LOAD_FILE,
   *PX_COMP_OTHER_FILE_LOAD_FILE,
   **PPX_COMP_OTHER_FILE_LOAD_FILE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FIELD_PROXY
{
   char                                      *  pvchName;
   char                                      *  pvchDescription;
   char                                      *  pvchModifiedDate;
   char                                         chStatus;
   char                                         chLanguageLevel;
   X_COMP_COMPONENT                          *  pComponent;
   long                                         lMetaClass;

   char                                      *  pvchRefField;
   char                                         chType;
   int                                          iLength;
   int                                          iDecimal;
   int                                          fSystemField;
   int                                          iUnicodeLength;

}  X_COMP_FIELD_PROXY,
   *PX_COMP_FIELD_PROXY,
   **PPX_COMP_FIELD_PROXY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FIELD
{
   char                                      *  pvchName;
   char                                      *  pvchRefField;
   char                                      *  pvchDefaultValue;
   char                                         chType;
   int                                          iLength;
   int                                          iDecimal;
   char                                         chKeyboardShift;
   char                                         chEditCode;
   char                                      *  pvchEditWord;
   char                                      *  pvchInputAttribute;
   char                                      *  pvchOutputAttribute;
   char                                      *  pvchPromptProc;
   char                                      *  pvchPromptFunc;
   char                                      *  pvchAlias;
   int                                          fSystemField;
   char                                         chLanguageLevel;
   int                                          iCCSID;
   int                                          iNativeFieldLength;
   int                                          iUnicodeLength;

}  X_COMP_FIELD,
   *PX_COMP_FIELD,
   **PPX_COMP_FIELD;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FIELD_TYPE
{
   char                                         chType;
   int                                          fIsUsable;
   int                                          fIsUsableInFile;
   char                                      *  pvchDefaultValue;
   char                                         chKeyboardShift;
   int                                          iLength;
   int                                          iDecimal;
   char                                         chEditCode;
   char                                      *  pvchInputAttribute;
   char                                      *  pvchOutputAttribute;

}  X_COMP_FIELD_TYPE,
   *PX_COMP_FIELD_TYPE,
   **PPX_COMP_FIELD_TYPE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FILE_FIELD
{
   char                                      *  pvchType;
   char                                      *  pvchField;
   char                                      *  pvchColumn;
   int                                          iKeySeq;
   char                                         chFieldType;
   int                                          iLength;
   int                                          iDecimal;
   char                                         chSecure;
   int                                          fIdentityColumn;
   int                                          fReadOnlyColumn;
   X_COMP_DATA_SOURCE_OBJECT_COLUMN          *  pColumn;
   X_COMP_ISERIES_OTHER_FILE_COLUMN          *  pIColumn;
   char                                         chAttribute;
   char                                      *  pvchSource;

}  X_COMP_FILE_FIELD,
   *PX_COMP_FILE_FIELD,
   **PPX_COMP_FILE_FIELD;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_SERIALIZED_PC_OTHER_FILE_TABLE_DATA
{
   char                                      *  pvchDataSource;
   char                                      *  pvchQualifier;
   char                                      *  pvchOwner;
   char                                      *  pvchTable;
   char                                      *  pvchType;
   char                                      *  pvchConnectData;
   char                                      *  pvchEncrypt;
   char                                      *  pvchData;

}  X_COMP_SERIALIZED_PC_OTHER_FILE_TABLE_DATA,
   *PX_COMP_SERIALIZED_PC_OTHER_FILE_TABLE_DATA,
   **PPX_COMP_SERIALIZED_PC_OTHER_FILE_TABLE_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_SERIALIZED_PC_OTHER_FILE_COLUM_DATA
{
   char                                      *  pvchPointer;
   char                                      *  pvchColumn;
   int                                          iDataType;
   long                                         lPrecision;
   long                                         lLength;
   int                                          iScale;
   int                                          iRadix;
   int                                          iNullable;
   char                                      *  pvchData;

}  X_COMP_SERIALIZED_PC_OTHER_FILE_COLUM_DATA,
   *PX_COMP_SERIALIZED_PC_OTHER_FILE_COLUM_DATA,
   **PPX_COMP_SERIALIZED_PC_OTHER_FILE_COLUM_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_SERIALIZED_ISERIES_FILE_COLUM_DATA
{
   char                                      *  pvchType;
   int                                          iKeySeq;
   char                                      *  pvchValue;
   char                                      *  pvchKeyInfo;

}  X_COMP_SERIALIZED_ISERIES_FILE_COLUM_DATA,
   *PX_COMP_SERIALIZED_ISERIES_FILE_COLUM_DATA,
   **PPX_COMP_SERIALIZED_ISERIES_FILE_COLUM_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

#define ODEF_PC_OTHER_FILE       0x0001
#define ODEF_ISERIES_OTHER_FILE  0x0002

typedef struct _X_COMP_OTHER_FILE_FIELD
{
   char                                      *  pvchName;
   char                                      *  pvchPointer;
   int                                          fIsUsed;
   long                                         lFileType;
   long                                         lPrecision;

}  X_COMP_OTHER_FILE_FIELD,
   *PX_COMP_OTHER_FILE_FIELD,
   **PPX_COMP_OTHER_FILE_FIELD;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LOGICAL_FILE
{
   char                                      *  pvchParentName;
   char                                      *  pvchName;
   char                                      *  pvchLibrary;
   char                                      *  pvchDescription;
   char                                         chAccessPathMaintenance;
   int                                          fUniqueKey;
   int                                          fDynamicSelect;
   char                                      *  pvchParameter;
   char                                      *  pvchRecordFormatName;
   char                                      *  pvchAltSeq;

}  X_COMP_LOGICAL_FILE,
   *PX_COMP_LOGICAL_FILE,
   **PPX_COMP_LOGICAL_FILE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LOGICAL_VIEW_FIELD
{
   char                                      *  pvchField;
   int                                          fAscendingOrder;
   char                                         chNumericOrder;
   int                                          iKeySeq;

}  X_COMP_LOGICAL_VIEW_FIELD,
   *PX_COMP_LOGICAL_VIEW_FIELD,
   **PPX_COMP_LOGICAL_VIEW_FIELD;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_LOGICAL_VIEW_CRITERIA
{
   char                                      *  pvchField;
   char                                         chOption;
   char                                      *  pvchCriteria;

}  X_COMP_LOGICAL_VIEW_CRITERIA,
   *PX_COMP_LOGICAL_VIEW_CRITERIA,
   **PPX_COMP_LOGICAL_VIEW_CRITERIA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_ACCESS_ROUTE
{
   char                                      *  pvchName;
   char                                      *  pvchDescription;
   char                                      *  pvchAccessFile;
   char                                      *  pvchAccessLibrary;
   char                                      *  pvchDefaultAction;
   int                                          iMaxRecord;

}  X_COMP_ACCESS_ROUTE,
   *PX_COMP_ACCESS_ROUTE,
   **PPX_COMP_ACCESS_ROUTE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_ACCESS_ROUTE_KEY
{
   char                                      *  pvchField;

}  X_COMP_ACCESS_ROUTE_KEY,
   *PX_COMP_ACCESS_ROUTE_KEY,
   **PPX_COMP_ACCESS_ROUTE_KEY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_VIRTUAL_FIELD_DATA
{
   char                                      *  pvchType;
   int                                          iSeq1;
   int                                          iSeq2;
   char                                      *  pvchData;

}  X_COMP_VIRTUAL_FIELD_DATA,
   *PX_COMP_VIRTUAL_FIELD_DATA,
   **PPX_COMP_VIRTUAL_FIELD_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_BATCH_CONTROL
{
   char                                      *  pvchFile;
   char                                      *  pvchLibrary;
   char                                      *  pvchDescription;

}  X_COMP_BATCH_CONTROL,
   *PX_COMP_BATCH_CONTROL,
   **PPX_COMP_BATCH_CONTROL;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_BATCH_CONTROL_FIELD
{
   char                                      *  pvchField;
   char                                      *  pvchType;

}  X_COMP_BATCH_CONTROL_FIELD,
   *PX_COMP_BATCH_CONTROL_FIELD,
   **PPX_COMP_BATCH_CONTROL_FIELD;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPILE
{
   char                                      *  pvchObject;
   char                                      *  pvchExtension;
   int                                          iObjectType;

}  X_COMP_COMPILE,
   *PX_COMP_COMPILE,
   **PPX_COMP_COMPILE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPILE_OPTION
{
   int                                          fStandardCompilerEnabled;
   int                                          fStandardCompilerSelected;
   int                                          fMicrosoftCompilerEnabled;
   int                                          fMicrosoftCompilerSelected;
   int                                          fIntel64BitEnabled;
   int                                          fIntel64BitSelected;
   int                                          fUnixEnabled;
   int                                          fUnixSelected;
   int                                          fISeriesEnabled;
   int                                          fISeriesSelected;
   int                                          fExtendCompileEnabled;
   int                                          fExtendCompileSelected;
   int                                          fGenerateSourceOnly;

}  X_COMP_COMPILE_OPTION,
   *PX_COMP_COMPILE_OPTION,
   **PPX_COMP_COMPILE_OPTION;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPILE_PROC
{
   char                                      *  pvchJobItem;
   char                                      *  pvchCompileOutput;
   char                                      *  pvchObject;
   char                                      *  pvchExtent;
   int                                          fDebug;
   int                                          fRecompile;
   int                                          fGenerateC;
   int                                          fGenerateHTM;
   int                                          __obs_fGenerateXML; /*OBSOLETE*/
   int                                          fValidateNumeric;
   int                                          fGenerateRPG;
   int                                          fKeepSource;
   int                                          fIncludeFunction;
   int                                          fRecompileFunction;
   int                                          fGenerateSourceOnly;

}  X_COMP_COMPILE_PROC,
   *PX_COMP_COMPILE_PROC,
   **PPX_COMP_COMPILE_PROC;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPILE_FUNC
{
   char                                      *  pvchJobItem;
   char                                      *  pvchBuildOutput;
   char                                      *  pvchCompileOutput;
   char                                      *  pvchObject;
   char                                      *  pvchExtent;

}  X_COMP_COMPILE_FUNC,
   *PX_COMP_COMPILE_FUNC,
   **PPX_COMP_COMPILE_FUNC;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPILE_COMP
{
   char                                      *  pvchJobItem;
   char                                      *  pvchBuildOutput;
   char                                      *  pvchCompileOutput;
   char                                      *  pvchObject;
   int                                          fDebug;
   int                                          fRecompile;
   int                                          fKeepSource;
   int                                          iWamOption;
   int                                          fGenerateSourceOnly;

}  X_COMP_COMPILE_COMP,
   *PX_COMP_COMPILE_COMP,
   **PPX_COMP_COMPILE_COMP;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_COMPILE_FILE
{
   char                                      *  pvchJobItem;
   char                                      *  pvchCompileOutput;
   char                                      *  pvchObject;
   char                                      *  pvchExtent;
   int                                          fDebug;
   int                                          fDropTable;
   int                                          fSaveData;
   int                                          fReloadData;
   int                                          fKeepSavedData;
   int                                          fRecompile;
   int                                          fRebuildTable;
   int                                          fRebuildIndex;
   int                                          fRebuildOAM;
   int                                          fKeepSource;
   int                                          fGenerateSourceOnly;

}  X_COMP_COMPILE_FILE,
   *PX_COMP_COMPILE_FILE,
   **PPX_COMP_COMPILE_FILE;

#ifndef X_OPERATING_TARGET_CSHARP

#ifdef X_OPERATING_SYSTEM_WIN

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_EXECUTE_COMP
{
   char                                      *  pvchObject;
   char                                      *  pvchExtend;
   int                                          iObjectType;
   int                                          fDebugMode;
   int                                          fInvokeDlg;
   unsigned int                                 uMsgEditorNotify;
   void                                      *  hwndEditor;
   char                                      *  pszDebugServicePort;

}  X_COMP_EXECUTE_COMP,
   *PX_COMP_EXECUTE_COMP,
   **PPX_COMP_EXECUTE_COMP;

#endif // X_OPERATING_SYSTEM_WIN

#endif // X_OPERATING_TARGET_CSHARP

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS
{
   char                                      *  pvchName;
   char                                      *  pvchDescription;
   char                                      *  pvchModifiedDate;
   char                                         chStatus;
   char                                         chLanguageLevel;

}  X_COMP_PROCESS,
   *PX_COMP_PROCESS,
   **PPX_COMP_PROCESS;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS_ATTRIBUTE
{
   int                                          fLightUsage;
   int                                          fActionBar;
   int                                          fOptimizedRemoteCommunication;
   int                                          fWebEnable;
   int                                          __obs_fXmlEnable; /*OBSOLETE*/

}  X_COMP_PROCESS_ATTRIBUTE,
   *PX_COMP_PROCESS_ATTRIBUTE,
   **PPX_COMP_PROCESS_ATTRIBUTE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS_SPECIAL_ENTRY
{
   char                                      *  pvchCommand;
   char                                         chRuntimePrompt;

}  X_COMP_PROCESS_SPECIAL_ENTRY,
   *PX_COMP_PROCESS_SPECIAL_ENTRY,
   **PPX_COMP_PROCESS_SPECIAL_ENTRY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS_ATTACHMENT
{
   char                                      *  pvchProcess;
   char                                      *  pvchFunction;

}  X_COMP_PROCESS_ATTACHMENT,
   *PX_COMP_PROCESS_ATTACHMENT,
   **PPX_COMP_PROCESS_ATTACHMENT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS_PARAMETER
{
   char                                         chType;
   int                                          iLength;
   int                                          iDecimal;
   char                                      *  pvchDescription;

}  X_COMP_PROCESS_PARAMETER,
   *PX_COMP_PROCESS_PARAMETER,
   **PPX_COMP_PROCESS_PARAMETER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS_ACTION_BAR
{
   char                                      *  pvchCode;

}  X_COMP_PROCESS_ACTION_BAR,
   *PX_COMP_PROCESS_ACTION_BAR,
   **PPX_COMP_PROCESS_ACTION_BAR;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PROCESS_ACTION_BAR_PULL_DOWN
{
   char                                      *  pvchCode;
   char                                      *  pvchType;
   char                                      *  pvchProcess;
   char                                      *  pvchFunction;
   char                                      *  pvchAccelerator;
   char                                         chInitialAvailability;


}  X_COMP_PROCESS_ACTION_BAR_PULL_DOWN,
   *PX_COMP_PROCESS_ACTION_BAR_PULL_DOWN,
   **PPX_COMP_PROCESS_ACTION_BAR_PULL_DOWN;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION
{
   char                                      *  pvchName;
   char                                      *  pvchProcess;
   char                                      *  pvchDescription;
   char                                         chLanguageLevel;
   char                                      *  pvchModifiedDate;
   char                                         chStatus;

}  X_COMP_FUNCTION,
   *PX_COMP_FUNCTION,
   **PPX_COMP_FUNCTION;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION_ATTRIBUTE
{
   char                                      *  pvchName;
   int                                          fDisplayOnMenu;
   char                                      *  pvchMenuSequence;
   char                                      *  pvchDefaultNextFunction;
   char                                      *  pvchAllowNextFunctionList;

}  X_COMP_FUNCTION_ATTRIBUTE,
   *PX_COMP_FUNCTION_ATTRIBUTE,
   **PPX_COMP_FUNCTION_ATTRIBUTE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION_MISC
{
   char                                      *  pvchKey1;
   char                                      *  pvchKey2;
   char                                      *  pvchData;
   int                                          iSeq;

}  X_COMP_FUNCTION_MISC,
   *PX_COMP_FUNCTION_MISC,
   **PPX_COMP_FUNCTION_MISC;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION_RDML
{
   short                                        sCommandId;
   char                                      *  pvchLabel;
   char                                      *  pvchParameters;
   char                                      *  pvchParameterText;
   struct _X_COMP_FUNCTION_RDML_TIMESTAMP    *  pTimeStamp;
   char                                      *  pvchCmdName;

}  X_COMP_FUNCTION_RDML,
   *PX_COMP_FUNCTION_RDML,
   **PPX_COMP_FUNCTIN_RDML;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION_RDML_CHANGED
{
   int                                          iCommandNo;
   X_COMP_FUNCTION_RDML                      *  pFuncRDML;

}  X_COMP_FUNCTION_RDML_CHANGED,
   *PX_COMP_FUNCTION_RDML_CHANGED,
   **PPX_COMP_FUNCTION_RDML_CHANGED;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_RDML
{
   int                                          iCmdId;
   char                                      *  pvchCommand;
   char                                      *  pvchDescription;

}  X_COMP_RDML,
   *PX_COMP_RDML,
   **PPX_COMP_RDML;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_RDML_PARAMETER
{
   int                                          iParamId;
   char                                      *  pvchParameter;
   int                                          fRequired;
   int                                          iRepetition;
   char                                      *  pvchDescription;

}  X_COMP_RDML_PARAMETER,
   *PX_COMP_RDML_PARAMETER,
   **PPX_COMP_RDML_PARAMETER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_RDML_PARAMETER_ITEM
{
   int                                          iParamId;
   char                                      *  pvchDescription;
   int                                          iParamItemId;
   int                                          iPromptType;
   char                                      *  pszDefaultValue;
   int                                          iRules;
   short                                     *  piRules;
   char                                      *  pszListValues;

}  X_COMP_RDML_PARAMETER_ITEM,
   *PX_COMP_RDML_PARAMETER_ITEM,
   **PPX_COMP_RDML_PARAMETER_ITEM;

#define X_COMP_MESSAGE_FATAL 'F'
#define X_COMP_MESSAGE_WARNING 'W'
#define X_COMP_MESSAGE_INFORMATION 'I'

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_MESSAGE_RDMLX
{
   char                                      *  pvchMessageId;
   long                                         lMessageTextLength;
   char                                      *  pvchMessageText;
   char                                         chMessageSeverity;
   long                                         lErrorPosition;
   unsigned long                                ulCurrentBuildUnitIdentifier;
   unsigned long                                ulRDMLXLineNumber;
   unsigned long                                ulPassNumber;

}  X_COMP_MESSAGE_RDMLX,
   *PX_COMP_MESSAGE_RDMLX,
   **PPX_COMP_MESSAGE_RDMLX;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEB_MENU
{
   char                                      *  pvchWebMenuText;
   char                                      *  pvchWebLinkText;

}  X_COMP_WEB_MENU,
   *PX_COMP_WEB_MENU,
   **PPX_COMP_WEB_MENU;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_BIF
{
   char                                      *  pvchBif;
   char                                      *  pvchDescription;
   int                                          iBifId;
   int                                          iInArgs;
   int                                          iOutArgs;

}  X_COMP_BIF,
   *PX_COMP_BIF,
   **PPX_COMP_BIF;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_BIF_ARG
{
   int                                          iArgSeq;
   int                                          fRequired;
   char                                      *  pvchDescription;
   char                                      *  pvchDefault;
   char                                         chType;
   int                                          iMaxLen;
   int                                          iMinLen;
   int                                          iMaxDec;
   int                                          iMinDec;

}  X_COMP_BIF_ARG,
   *PX_COMP_BIF_ARG,
   **PPX_COMP_BIF_ARG;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_RULE_LIST_ITEM
{
   int                                          iRuleType;
   char                                      *  pvchParameters;

}  X_COMP_RULE_LIST_ITEM,
   *PX_COMP_RULE_LIST_ITEM,
   **PPX_COMP_RULE_LIST_ITEM;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_RULE_LIST_HEADER
{
   char                                      *  pvchList;
   char                                      *  pvchDescription;
   struct _X_COMP_RULE_LIST_ITEM                RuleListItem;

}  X_COMP_RULE_LIST_HEADER,
   *PX_COMP_RULE_LIST_HEADER,
   **PPX_COMP_RULE_LIST_HEADER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_IMPACT_LIST_HEADER
{
   char                                      *  pvchList;
   char                                      *  pvchDescription;

}  X_COMP_IMPACT_LIST_HEADER,
   *PX_COMP_IMPACT_LIST_HEADER,
   **PPX_COMP_IMPACT_LIST_HEADER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_IMPACT_LIST_ITEM
{
   char                                      *  pvchObject;
   char                                      *  pvchExtension;
   char                                      *  pvchExtension2;
   int                                          iObjectType;
   int                                          iReasonId;
   int                                          iMetaClass;

}  X_COMP_IMPACT_LIST_ITEM,
   *PX_COMP_IMPACT_LIST_ITEM,
   **PPX_COMP_IMPACT_LIST_ITEM;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_IMPACT_LIST_ITEM_REASON
{
   char                                      *  pvchMessageId;
   char                                      *  pvchMessageType;
   char                                      *  pvchMessageParameters;

}  X_COMP_IMPACT_LIST_ITEM_REASON,
   *PX_COMP_IMPACT_LIST_ITEM_REASON,
   **PPX_COMP_IMPACT_LIST_ITEM_REASON;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XREF_DETAILS
{
   int                                          iObjectType;
   char                                      *  pvchObject;
   char                                      *  pvchExtension;
   int                                          iReferenceType;
   char                                      *  pvchReferenceInfo;
   char                                      *  pvchLangCode;
   char                                      *  pvchExtension2;
   char                                      *  pvchExtension3;

}  X_COMP_XREF_DETAILS,
   *PX_COMP_XREF_DETAILS,
   **PPX_COMP_XREF_DETAILS;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XREF_REF_ID
{
   int                                          iReferenceType;
   char                                      *  pvchReferenceId;
   char                                      *  pvchReferenceInfo;

}  X_COMP_XREF_REF_ID,
   *PX_COMP_XREF_REF_ID,
   **PPX_COMP_XREF_REF_ID;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_OBJECT_TASK_REGISTER
{
   int                                          iObjectType;
   char                                      *  pvchObject;
   char                                      *  pvchExtension;
   char                                      *  pvchTaskId;
   char                                      *  pvchPcName;
   char                                      *  pvchUserId;
   char                                      *  pvchDate;
   char                                         chStatus;
   int                                          iAction;

}  X_COMP_OBJECT_TASK_REGISTER,
   *PX_COMP_OBJECT_TASK_REGISTER,
   **PPX_COMP_OBJECT_TASK_REGISTER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_MESSAGE_FILE
{
   char                                      *  pvchName;
   char                                      *  pvchLangCode;

}  X_COMP_MESSAGE_FILE,
   *PX_COMP_MESSAGE_FILE,
   **PPX_COMP_MESSAGE_FILE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_MESSAGE_TEXT
{
   char                                      *  pvchLanguage;
   char                                      *  pvchMessageFile;
   char                                      *  pvchMessageId;
   char                                      *  pvchFirstLevelText;
   char                                      *  pvchSecondLevelText;
   char                                      *  pvchSubstitution;

}  X_COMP_MESSAGE_TEXT,
   *PX_COMP_MESSAGE_TEXT,
   **PPX_COMP_MESSAGE_TEXT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEB_ROUTINE_NAME
{
   char                                      *  pvchWam;
   char                                      *  pvchRoutine;

}  X_COMP_WEB_ROUTINE_NAME,
   *PX_COMP_WEB_ROUTINE_NAME,
   **PPX_COMP_WEB_ROUTINE_NAME;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEB_ROUTINE_KEY
{
   char                                      *  pvchWam;
   char                                      *  pvchRoutine;
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   int                                          iSet;
   char                                      *  pvchLangCode;

}  X_COMP_WEB_ROUTINE_KEY,
   *PX_COMP_WEB_ROUTINE_KEY,
   **PPX_COMP_WEB_ROUTINE_KEY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEB_ROUTINE_DATA
{
   char                                      *  pvchRoutine;
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   int                                          iSet;
   char                                      *  pvchData;
   int                                          iDate;
   int                                          iTime;

}  X_COMP_WEB_ROUTINE_DATA,
   *PX_COMP_WEB_ROUTINE_DATA,
   **PPX_COMP_WEB_ROUTINE_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEB_ROUTINE_DATA_2
{
   char                                      *  pvchRoutine;
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   int                                          iSet;
   char                                      *  pvchData;
   char                                      *  pvchLangCode;

}  X_COMP_WEB_ROUTINE_DATA_2,
   *PX_COMP_WEB_ROUTINE_DATA_2,
   **PPX_COMP_WEB_ROUTINE_DATA_2;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET
{
   char                                      *  pvchWeblet;
   char                                      *  pvchDescription;

}  X_COMP_WEBLET,
   *PX_COMP_WEBLET,
   **PPX_COMP_WEBLET;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_KEY
{
   char                                      *  pvchWeblet;
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   int                                          iSet;
   char                                      *  pvchLangCode;

}  X_COMP_WEBLET_KEY,
   *PX_COMP_WEBLET_KEY,
   **PPX_COMP_WEBLET_KEY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_DATA
{
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   int                                          iSet;
   char                                      *  pvchData;
   int                                          iDate;
   int                                          iTime;

}  X_COMP_WEBLET_DATA,
   *PX_COMP_WEBLET_DATA,
   **PPX_COMP_WEBLET_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_IMPORT_INFO
{
   const X_UTF16_VCHAR                       *  pvchImport;
}  X_COMP_WEBLET_IMPORT_INFO,
   *PX_COMP_WEBLET_IMPORT_INFO,
   **PPX_COMP_WEBLET_IMPORT_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_DATA_TYPE_INFO
{
   const X_UTF16_VCHAR                       *  pvchDataType;
}  X_COMP_WEBLET_DATA_TYPE_INFO,
   *PX_COMP_WEBLET_DATA_TYPE_INFO,
   **PPX_COMP_WEBLET_DATA_TYPE_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

enum WebletEnumType
{
   WEBLET_ENUM_UNKNOWN = 0,
   WEBLET_ENUM = 1,
   WEBLET_ENUMLIST = 2
};

typedef struct _X_COMP_WEBLET_DATA_TYPE_ENUM_VALUE
{
   enum WebletEnumType                          eEnumType;
   const X_UTF16_VCHAR                       *  pvchValue;
   const X_UTF16_VCHAR                       *  pvchDisplayValue;
}  X_COMP_WEBLET_DATA_TYPE_ENUM_VALUE,
   *PX_COMP_WEBLET_DATA_TYPE_ENUM_VALUE,
   **PPX_COMP_WEBLET_DATA_TYPE_ENUM_VALUE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_XSL_TEMPLATE_INFO
{
   const X_UTF16_VCHAR                       *  pvchTemplate;
}  X_COMP_WEBLET_XSL_TEMPLATE_INFO,
   *PX_COMP_WEBLET_XSL_TEMPLATE_INFO,
   **PPX_COMP_WEBLET_XSL_TEMPLATE_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_WD_TEMPLATE_INFO
{
   const X_UTF16_VCHAR                       *  pvchTemplate;
}  X_COMP_WEBLET_WD_TEMPLATE_INFO,
   *PX_COMP_WEBLET_WD_TEMPLATE_INFO,
   **PPX_COMP_WEBLET_WD_TEMPLATE_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_WD_PARAMETER_INFO
{
   const X_UTF16_VCHAR                       *  pvchParameter;
}  X_COMP_WEBLET_WD_PARAMETER_INFO,
   *PX_COMP_WEBLET_WD_PARAMETER_INFO,
   **PPX_COMP_WEBLET_WD_PARAMETER_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_XSL_PARAMETER_INFO
{
   const X_UTF16_VCHAR                       *  pvchParameter;
   const X_UTF16_VCHAR                       *  pvchDataType;
   const X_UTF16_VCHAR                       *  pvchTipId;
   const X_UTF16_VCHAR                       *  pvchDefaultValue;
}  X_COMP_WEBLET_XSL_PARAMETER_INFO,
   *PX_COMP_WEBLET_XSL_PARAMETER_INFO,
   **PPX_COMP_WEBLET_XSL_PARAMETER_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_PARAMETER_TIP_INFO
{
   const X_UTF16_VCHAR                       *  pvchLang;
   const X_UTF16_VCHAR                       *  pvchText;
}  X_COMP_WEBLET_PARAMETER_TIP_INFO,
   *PX_COMP_WEBLET_PARAMETER_TIP_INFO,
   **PPX_COMP_WEBLET_PARAMETER_TIP_INFO;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_INSPECTOR_ERROR
{
   unsigned int                                 nLineNbr;
   unsigned int                                 nColumnNbr;
   const X_UTF16_VCHAR                       *  pvchText;
}  X_COMP_WEBLET_INSPECTOR_ERROR,
   *PX_COMP_WEBLET_INSPECTOR_ERROR,
   **PPX_COMP_WEBLET_INSPECTOR_ERROR;


/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

/* FIXME: Replaced with X_COMP_WEBLET_DATA_TYPE_ENUM_VALUE */
typedef struct _X_COMP_WEBLET_PARAMETER_ENUM_VALUE
{
   char                                      *  pvchDataType;
   char                                      *  pvchValue;
   char                                      *  pvchDisplayName;
}  X_COMP_WEBLET_PARAMETER_ENUM_VALUE,
   *PX_COMP_WEBLET_PARAMETER_ENUM_VALUE,
   **PPX_COMP_WEBLET_PARAMETER_ENUM_VALUE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEB_COMPONENT
{
   char                                      *  pvchName;
   char                                      *  pvchExtend1;
   char                                      *  pvchExtend2;
   char                                         chAttribute;
   char                                      *  pvchDescription;
   char                                      *  pvchType;

}  X_COMP_WEB_COMPONENT,
   *PX_COMP_WEB_COMPONENT,
   **PPX_COMP_WEB_COMPONENT;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TECH_SERVICE_PROVIDER
{
   char                                      *  pvchEntity;
   char                                      *  pvchDescription;

}  X_COMP_TECH_SERVICE_PROVIDER,
   *PX_COMP_TECH_SERVICE_PROVIDER,
   **PPX_COMP_TECH_SERVICE_PROVIDER;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TECH_SERVICE_PROPERTY
{
   int                                          iPropertyId;
   char                                      *  pvchLabel;
   char                                      *  pvchDescription;
   char                                         chOptional;
   char                                         chType;
   int                                          iLength;

}  X_COMP_TECH_SERVICE_PROPERTY,
   *PX_COMP_TECH_SERVICE_PROPERTY,
   **PPX_COMP_TECH_SERVICE_PROPERTY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TECH_SERVICE_PROPERTY_VALUE
{
   int                                          iPropertyId;
   char                                      *  pvchValue;

}  X_COMP_TECH_SERVICE_PROPERTY_VALUE,
   *PX_COMP_TECH_SERVICE_PROPERTY_VALUE,
   **PPX_COMP_TECH_SERVICE_PROPERTY_VALUE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WAM
{
   char                                      *  pvchLayoutWeblet;
   char                                         chNumericValidation;
   char                                         chInlineOption;

}  X_COMP_WAM,
   *PX_COMP_WAM,
   **PPX_COMP_WAM;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WAM_SERVICE
{
   char                                      *  pvchWam;
   char                                      *  pvchRoutine;
   char                                      *  pvchService;
   char                                      *  pvchLangCode;

}  X_COMP_WAM_SERVICE,
   *PX_COMP_WAM_SERVICE,
   **PPX_COMP_WAM_SERVICE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WAM_DESIGN_DATA
{
   char                                      *  pvchWam;
   char                                      *  pszLangCode;
   X_COMP_WEB_ROUTINE_DATA                   *  pXslData;
   X_COMP_WEB_ROUTINE_DATA                   *  pXmlData;

}  X_COMP_WAM_DESIGN_DATA,
   *PX_COMP_WAM_DESIGN_DATA,
   **PPX_COMP_WAM_DESIGN_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_DESIGN_DATA
{
   char                                      *  pvchWeblet;
   char                                      *  pszLangCode;
   X_COMP_WEBLET_DATA                        *  pXslData;
   X_COMP_WEBLET_DATA                        *  pXmlData;

}  X_COMP_WEBLET_DESIGN_DATA,
   *PX_COMP_WEBLET_DESIGN_DATA,
   **PPX_COMP_WEBLET_DESIGN_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_WEBLET_DESCRIPTION
{
   char                                      *  pvchWeblet;
   char                                      *  pszLangCode;
   X_COMP_WEBLET                             *  pWeblet;

}  X_COMP_WEBLET_DESCRIPTION,
   *PX_COMP_WEBLET_DESCRIPTION,
   **PPX_COMP_WEBLET_DESCRIPTION;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XML_APP
{
   char                                      *  pvchEntityId;
   char                                      *  pvchXmlApp;
   char                                      *  pvchCaption;
   char                                      *  pvchDescription;

}  X_COMP_XML_APP,
   *PX_COMP_XML_APP,
   **PPX_COMP_XML_APP;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XML_APP_LANG
{
   char                                      *  pvchEntityId;
   char                                      *  pvchXmlApp;
   char                                      *  pvchLangCode;

}  X_COMP_XML_APP_LANG,
   *PX_COMP_XML_APP_LANG,
   **PPX_COMP_XML_APP_LANG;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XML_APP_PROPERTY
{
   char                                      *  pvchEntity;
   char                                      *  pvchXmlApp;
   int                                          iPropertyId;
   char                                      *  pvchValue;

}  X_COMP_XML_APP_PROPERTY,
   *PX_COMP_XML_APP_PROPERTY,
   **PPX_COMP_XML_APP_PROPERTY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XML_APP_KEY
{
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   char                                      *  pvchDoc;
   int                                          iSet;

}  X_COMP_XML_APP_KEY,
   *PX_COMP_XML_APP_KEY,
   **PPX_COMP_XML_APP_KEY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_XML_APP_DATA
{
   char                                      *  pvchEntity;
   char                                      *  pvchApp;
   char                                      *  pvchDoc;
   int                                          iSet;
   char                                      *  pvchData;

}  X_COMP_XML_APP_DATA,
   *PX_COMP_XML_APP_DATA,
   **PPX_COMP_XML_APP_DATA;

/* ----------------------------------------------------------------- */
/* Any modification to this structure needs to rebuild DC@P6241.     */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_EXTERNAL_RESOURCE
{
   char                                      *  pvchName;
   char                                      *  pvchTimestamp;
   int                                          iFolderType;
   char                                      *  pvchFileName;
   int                                          iWinCodePage;
   char                                         chFileType;

}  X_COMP_EXTERNAL_RESOURCE,
   *PX_COMP_EXTERNAL_RESOURCE,
   **PPX_COMP_EXTERNAL_RESOURCE;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_EXTERNAL_RESOURCE_DATA
{
   char                                      *  pvchData;
   unsigned long                                ulLength;

}  X_COMP_EXTERNAL_RESOURCE_DATA,
   *PX_COMP_EXTERNAL_RESOURCE_DATA,
   **PPX_COMP_EXTERNAL_RESOURCE_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_EXTERNAL_RESOURCE_PROXY
{
   char                                      *  pvchName;
   char                                      *  pvchTimestamp;
   char                                      *  pvchMetaData;
   int                                          iFolderType;
   char                                      *  pvchFileName;
   char                                      *  pvchDesc;
   char                                      *  pvchModifiedDate;
   int                                          iWinCodePage;
   char                                         chFileType;

}  X_COMP_EXTERNAL_RESOURCE_PROXY,
   *PX_COMP_EXTERNAL_RESOURCE_PROXY,
   **PPX_COMP_EXTERNAL_RESOURCE_PROXY;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_TIMESTAMP
{
   int                                          iDate;
   int                                          iTime;

}  X_COMP_TIMESTAMP,
   *PX_COMP_TIMESTAMP,
   **PPX_COMP_TIMESTAMP;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_OTHER_FILE_LOAD_FIELD
{
   X_COMP_COMPONENT_IDENTIFIER                  identifierInfo;
   int                                          iAuthorityType;
   X_COMP_FIELD                                 fieldInfo;
   X_COMP_COMPONENT                             componentInfo;
   X_COMP_OTHER_FILE_FIELD                   *  pOtherFileField;

}  X_COMP_OTHER_FILE_LOAD_FIELD,
   *PX_COMP_OTHER_FILE_LOAD_FIELD,
   **PPX_COMP_OTHER_FILE_LOAD_FIELD;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_FUNCTION_DESIGN_DATA
{
   char                                      *  pvchFunction;
   int                                          fAdjustColHdgs;
   int                                          fAdjustLabels;
   int                                          fAdjustDescs;
   int                                          fAdjustTexts;
   int                                          fMessageLine;
   int                                          fDisplayPanelID;
   char                                         chRLL;
   char                                         chDBCSDev;
   char                                         chStdHeadings;
   char                                         chMultiLingualPartition;
   char                                         chOv2[ 20 ];

}  X_COMP_FUNCTION_DESIGN_DATA,
   *PX_COMP_FUNCTION_DESIGN_DATA,
   **PPX_COMP_FUNCTION_DESIGN_DATA;

/* ----------------------------------------------------------------- */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_ALT_NAME
{
   int                                          iObjectType;
   char                                      *  pvchObject;
   char                                      *  pvchExtend;
   char                                      *  pvchExtend2;
   char                                      *  pvchUniqueName;
   char                                      *  pvchEnteredName;

}  X_COMP_ALT_NAME,
   *PX_COMP_ALT_NAME,
   **PPX_COMP_ALT_NAME;

/* ------------------------- */
/* System Settings Interface */
/* ------------------------- */

#define X_COMP_SYSTEM_INFO_VERSION_1     1
#define X_COMP_SYSTEM_INFO_VERSION_2     2

typedef struct _X_COMP_SYSTEM_INFO
{
   unsigned short usStructVersionNumber; /* Currently X_COMP_SYSTEM_INFO_VERSION_2 */
   char           chAutoHelp;
   char           chDateSeparator;
   char           chCurrencySymbol;
   char           chDecimalPoint;
   char           chThousandSep;
   char           chTimeSeparator;
   char           chHashSign;
   char           chAtSign;
   char           chGenAtSign;
   char           chDollarSign;
   int            fStripTrailingDBCSBlanks;

}     X_COMP_SYSTEM_INFO,
   * PX_COMP_SYSTEM_INFO,
  ** PPX_COMP_SYSTEM_INFO;

/* ------------------------ */
/* System Editing Interface */
/* ------------------------ */

#define X_COMP_EDIT_EXCHANGE_VERSION_1   1


typedef struct _X_COMP_EDIT_EXCHANGE
{

   /* Input Values */

   unsigned short usStructVersionNumber;    /* Currently X_COMP_EDIT_EXCHANGE_VERSION_1                          */
   unsigned short usExchangeFormat;         /* As per standard exchange formats                                  */
   void        *  pvInputValue;             /* Pointer to input value consistent with exchange format            */
   short          sLen;                     /* Maximum allowable length ot total digits including decimals       */
   short          sDec;                     /* Number of allowable decimals                                      */
   char           chEditCode;               /* Blank if not available or not applicable                          */
   char        *  pvchEditWord;             /* NULL or pointer to null string if not available or not applicable */
   char           chKeyboardShift;          /* Keyboard Shift character                                          */
   unsigned long  ulMaxOutputValueLength;   /* Maximum allowable returned output value length                    */
   unsigned long  ulMaxErrorMessageLength;  /* Maximum allowable returned error message length                   */

   /* Returned Values */

   void        *  pvOutputValue;
   char        *  pvchErrorMessage;

}      X_COMP_EDIT_EXCHANGE,
   *  PX_COMP_EDIT_EXCHANGE,
  ** PPX_COMP_EDIT_EXCHANGE;

#if defined(X_COMP_FCC_SUPPORT) || defined(X_COMP_RUN_TIME_SUPPORT)

/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
/* Dispatch identifiers for component module dispatch tables.         */
/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */

typedef long 
   X_COMP_DISPATCH_ID,
   X_COMP_LANSAX_DISPATCH_ID;

typedef unsigned long 
   X_COMP_KIND,
   X_COMP_PARTID;

#define X_COMP_KIND_NULL                                  0L
#define X_COMP_PART_ID_NULL                               0L
#define X_COMP_DISPATCH_ID_NULL                          -1L

/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
/* Dispatching Types                                                  */
/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ */
/* Codes for Static References                                        */
/* ------------------------------------------------------------------ */

#define X_COMP_DISPATCH_ID_MOUSE                         -2L
#define X_COMP_DISPATCH_ID_KEYBOARD                      -3L
#define X_COMP_DISPATCH_ID_APPLICATION                   -4L
#define X_COMP_DISPATCH_ID_EVENT_SENDER                  -5L
#define X_COMP_DISPATCH_ID_BOOLEAN_TRUE                  -6L
#define X_COMP_DISPATCH_ID_BOOLEAN_FALSE                 -7L
#define X_COMP_DISPATCH_ID_COM_ERR_INFO                  -8L
#define X_COMP_DISPATCH_ID_SQLNULL_IDENTIFIER            -9L
#define X_COMP_DISPATCH_ID_NULL_IDENTIFIER               -10L
#define X_COMP_DISPATCH_ID_WEB_RESOURCE                  -11L

/* ------------------------------------------------------------------ */
/* Codes for Modified Features.                                       */
/* ------------------------------------------------------------------ */

#define X_COMP_MODIFIED_FEATURE_NULL                     -1L
#define X_COMP_MODIFIED_FEATURE_AS_DEFAULT_PROPERTY      -2L
#define X_COMP_MODIFIED_FEATURE_AS_PUBLIC_PROPERTY       -3L
#define X_COMP_MODIFIED_FEATURE_AS_PROTECTED_PROPERTY    -4L
#define X_COMP_MODIFIED_FEATURE_AS_PRIVATE_PROPERTY      -5L

/* ------------------------------------------------------------------ */
/* Codes for Local Domains                                            */
/* ------------------------------------------------------------------ */

#define X_COMP_LOCAL_DOMAIN_LONG                         -2L
#define X_COMP_LOCAL_DOMAIN_DOUBLE                       -3L
#define X_COMP_LOCAL_DOMAIN_STRING                       -4L
#define X_COMP_LOCAL_DOMAIN_VARIANT                      -5L
#define X_COMP_LOCAL_DOMAIN_DECIMAL                      -6L

/* ------------------------------------------------------------------ */
/* Codes for For command operations                                   */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_FOR_OPERATION_KIND;

#define X_COMP_FOR_OPERATION_DEFAULT                           0L
#define X_COMP_FOR_OPERATION_KIND_OF                           1L
#define X_COMP_FOR_OPERATION_INSTANCE_OF                       2L
#define X_COMP_FOR_OPERATION_DYNAMIC_CAST                      3L

/* ------------------------------------------------------------------ */
/* Masks for ulFieldSpec1 in X_COMP_FIELD_PATTERN                     */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_FIELD_SPEC_1;

#define X_COMP_FIELD_SPEC_1_FIELD_TYPE_MASK                    ((unsigned long)0x000000FF)
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_MASK                     ((unsigned long)0x0000FF00)
#define X_COMP_FIELD_SPEC_1_FIELD_STATE_MASK                   ((unsigned long)0x00FF0000)
#define X_COMP_FIELD_SPEC_1_DATA_CLASS_TYPE_MASK               ((unsigned long)0xFF000000)

#define X_COMP_FIELD_SPEC_1_EDIT_CODE_NULL                     ((unsigned long)(0 << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_NONE                     ((unsigned long)(' ' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_1                        ((unsigned long)('1' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_2                        ((unsigned long)('2' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_3                        ((unsigned long)('3' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_4                        ((unsigned long)('4' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_A                        ((unsigned long)('A' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_B                        ((unsigned long)('B' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_C                        ((unsigned long)('C' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_D                        ((unsigned long)('D' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_J                        ((unsigned long)('J' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_K                        ((unsigned long)('K' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_L                        ((unsigned long)('L' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_M                        ((unsigned long)('M' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_N                        ((unsigned long)('N' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_O                        ((unsigned long)('O' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_P                        ((unsigned long)('P' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_Q                        ((unsigned long)('Q' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_W                        ((unsigned long)('W' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_X                        ((unsigned long)('X' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_Y                        ((unsigned long)('Y' << 8))
#define X_COMP_FIELD_SPEC_1_EDIT_CODE_Z                        ((unsigned long)('Z' << 8))

/* ------------------------------------------------------------------ */
/* Masks for ulFieldSpec2 in X_COMP_FIELD_PATTERN                     */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_FIELD_SPEC_2;

#define X_COMP_FIELD_SPEC_2_FIELD_LENGTH_MASK                  ((unsigned long)0x0000FFFF)
#define X_COMP_FIELD_SPEC_2_FIELD_DECIMALS_MASK                ((unsigned long)0xFFFF0000)

/* ------------------------------------------------------------------ */
/* Masks for ulFieldSpec3 in X_COMP_FIELD_PATTERN                     */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_FIELD_SPEC_3;

#define X_COMP_FIELD_SPEC_3_FIELD_CHARS_MASK                   ((unsigned long)0x0000FFFF)

/* ------------------------------------------------------------------ */
/* Masks for ulFieldAttributes in X_COMP_FIELD_PATTERN                */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_FIELD_ATTRIBUTES;

#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_MASK             0x000000FF
#define X_COMP_FIELD_ATTRIBUTE_AB                              0x00000100
#define X_COMP_FIELD_ATTRIBUTE_LC                              0x00000200
#define X_COMP_FIELD_ATTRIBUTE_M10                             0x00000400
#define X_COMP_FIELD_ATTRIBUTE_M11                             0x00000800
#define X_COMP_FIELD_ATTRIBUTE_RA                              0x00001000
#define X_COMP_FIELD_ATTRIBUTE_RB                              0x00002000
#define X_COMP_FIELD_ATTRIBUTE_RZ                              0x00004000
#define X_COMP_FIELD_ATTRIBUTE_VN                              0x00008000
#define X_COMP_FIELD_ATTRIBUTE_ME                              0x00010000
#define X_COMP_FIELD_ATTRIBUTE_MF                              0x00020000

#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_BLANK            ((unsigned long)(' '))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_ALPHA_ONLY       ((unsigned long)('X'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_ALPHA            ((unsigned long)('A'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_NUMERIC          ((unsigned long)('N'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_SIGNED_NUMERIC   ((unsigned long)('S'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_NUMERIC_ONLY     ((unsigned long)('Y'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_KATAKANA         ((unsigned long)('W'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_INHIBIT_ONLY     ((unsigned long)('I'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_DIGITS_ONLY      ((unsigned long)('D'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_NUMERIC_KEYS     ((unsigned long)('M'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_DBCS_ONLY        ((unsigned long)('G'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_DBCS_AS_MIXED    ((unsigned long)('J'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_SBCS_OR_DBCS     ((unsigned long)('E'))
#define X_COMP_FIELD_ATTRIBUTE_KEYBOARD_SHIFT_SBCS_AND_DBCS    ((unsigned long)('O'))

/* ------------------------------------------------------------------ */
/* Masks for ulTypeInfo in :                                          */
/*                                                                    */
/*    X_COMP_FCC_GET_PROPERTY_INFO                                    */
/*                                                                    */
/*    X_VAR_EVALUATION_CALLBACK                                       */
/*    X_VAR_EVALUATION_DISPATCH                                       */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_EVALUATION_TYPE_INFO;

#define X_COMP_EVALUATION_TYPE_INFO_VALUE_IS_READABLE          0x01000000
#define X_COMP_EVALUATION_TYPE_INFO_VALUE_IS_WRITEABLE         0x02000000

#define X_COMP_EVALUATION_TYPE_INFO_FIELD_TYPE_MASK            0x000000FF
#define X_COMP_EVALUATION_TYPE_INFO_FIELD_INFO_MASK            0x0000FF00


/* ------------------------------------------------------------------ */
/* Codes for Singular/Binary Evaluation Kinds                         */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_EVALUATION_KIND;

#define X_COMP_EVALUATE_NULL                                   0L

#define X_COMP_EVALUATE_UNARY_PLUS                             1010L
#define X_COMP_EVALUATE_UNARY_MINUS                            1011L
#define X_COMP_EVALUATE_UNARY_COMPONENT_IS_NULL                1012L
#define X_COMP_EVALUATE_UNARY_COMPONENT_IS_NOT_NULL            1013L
#define X_COMP_EVALUATE_UNARY_NOT                              1014L

#define X_COMP_EVALUATE_INTEGER_PLUS                           1100L
#define X_COMP_EVALUATE_INTEGER_MINUS                          1101L
#define X_COMP_EVALUATE_INTEGER_DIVIDE                         1102L
#define X_COMP_EVALUATE_INTEGER_MULTIPLY                       1103L

#define X_COMP_EVALUATE_STRING_PLUS                            1110L

#define X_COMP_EVALUATE_VARIANT_PLUS                           1120L
#define X_COMP_EVALUATE_VARIANT_MINUS                          1121L
#define X_COMP_EVALUATE_VARIANT_DIVIDE                         1122L
#define X_COMP_EVALUATE_VARIANT_MULTIPLY                       1123L

#define X_COMP_EVALUATE_DECIMAL_PLUS                           1130L
#define X_COMP_EVALUATE_DECIMAL_MINUS                          1131L
#define X_COMP_EVALUATE_DECIMAL_DIVIDE                         1132L
#define X_COMP_EVALUATE_DECIMAL_MULTIPLY                       1133L

#define X_COMP_EVALUATE_STRING_ASSIGNMENT                      1200L
#define X_COMP_EVALUATE_STRING_PLUS_ASSIGNMENT                 1201L

#define X_COMP_EVALUATE_INTEGER_ASSIGNMENT                     1210L
#define X_COMP_EVALUATE_INTEGER_PLUS_ASSIGNMENT                1211L
#define X_COMP_EVALUATE_INTEGER_MINUS_ASSIGNMENT               1212L
#define X_COMP_EVALUATE_INTEGER_DIVIDE_ASSIGNMENT              1213L
#define X_COMP_EVALUATE_INTEGER_MULTIPLY_ASSIGNMENT            1214L

#define X_COMP_EVALUATE_VARIANT_ASSIGNMENT                     1220L
#define X_COMP_EVALUATE_VARIANT_PLUS_ASSIGNMENT                1221L
#define X_COMP_EVALUATE_VARIANT_MINUS_ASSIGNMENT               1222L
#define X_COMP_EVALUATE_VARIANT_DIVIDE_ASSIGNMENT              1223L
#define X_COMP_EVALUATE_VARIANT_MULTIPLY_ASSIGNMENT            1224L

#define X_COMP_EVALUATE_DECIMAL_ASSIGNMENT                     1230L
#define X_COMP_EVALUATE_DECIMAL_PLUS_ASSIGNMENT                1231L
#define X_COMP_EVALUATE_DECIMAL_MINUS_ASSIGNMENT               1232L
#define X_COMP_EVALUATE_DECIMAL_DIVIDE_ASSIGNMENT              1233L
#define X_COMP_EVALUATE_DECIMAL_MULTIPLY_ASSIGNMENT            1234L

#define X_COMP_EVALUATE_BOOLEAN_OR                             1240L
#define X_COMP_EVALUATE_BOOLEAN_AND                            1241L
#define X_COMP_EVALUATE_BOOLEAN_OR_IF                          1242L
#define X_COMP_EVALUATE_BOOLEAN_AND_IF                         1243L

#define X_COMP_EVALUATE_COMPONENT_REFERENCE_CAST               1300L
#define X_COMP_EVALUATE_COMPONENT_INSTANCE_OF                  1301L
#define X_COMP_EVALUATE_COMPONENT_NOT_INSTANCE_OF              1302L
#define X_COMP_EVALUATE_BOUND_FEATURE_EQUAL                    1303L
#define X_COMP_EVALUATE_BOUND_FEATURE_NOT_EQUAL                1304L
#define X_COMP_EVALUATE_COMPONENT_IS_EQUAL_TO                  1305L
#define X_COMP_EVALUATE_COMPONENT_IS_NOT_EQUAL_TO              1306L
#define X_COMP_EVALUATE_COMPONENT_IS_OF_TYPE                   1307L
#define X_COMP_EVALUATE_COMPONENT_IS_NOT_OF_TYPE               1308L

#define X_COMP_EVALUATE_STRING_EQUAL                           1400L
#define X_COMP_EVALUATE_STRING_NOT_EQUAL                       1401L
#define X_COMP_EVALUATE_STRING_LESS_THAN                       1402L
#define X_COMP_EVALUATE_STRING_GREATER_THAN                    1403L
#define X_COMP_EVALUATE_STRING_LESS_THAN_OR_EQUAL              1404L
#define X_COMP_EVALUATE_STRING_GREATER_THAN_OR_EQUAL           1405L

#define X_COMP_EVALUATE_INTEGER_EQUAL                          1410L
#define X_COMP_EVALUATE_INTEGER_NOT_EQUAL                      1411L
#define X_COMP_EVALUATE_INTEGER_LESS_THAN                      1412L
#define X_COMP_EVALUATE_INTEGER_GREATER_THAN                   1413L
#define X_COMP_EVALUATE_INTEGER_LESS_THAN_OR_EQUAL             1414L
#define X_COMP_EVALUATE_INTEGER_GREATER_THAN_OR_EQUAL          1415L

#define X_COMP_EVALUATE_VARIANT_EQUAL                          1420L
#define X_COMP_EVALUATE_VARIANT_NOT_EQUAL                      1421L
#define X_COMP_EVALUATE_VARIANT_LESS_THAN                      1422L
#define X_COMP_EVALUATE_VARIANT_GREATER_THAN                   1423L
#define X_COMP_EVALUATE_VARIANT_LESS_THAN_OR_EQUAL             1424L
#define X_COMP_EVALUATE_VARIANT_GREATER_THAN_OR_EQUAL          1425L

#define X_COMP_EVALUATE_DECIMAL_EQUAL                          1430L
#define X_COMP_EVALUATE_DECIMAL_NOT_EQUAL                      1431L
#define X_COMP_EVALUATE_DECIMAL_LESS_THAN                      1432L
#define X_COMP_EVALUATE_DECIMAL_GREATER_THAN                   1433L
#define X_COMP_EVALUATE_DECIMAL_LESS_THAN_OR_EQUAL             1434L
#define X_COMP_EVALUATE_DECIMAL_GREATER_THAN_OR_EQUAL          1435L

#define X_COMP_EVALUATE_BOOLEAN_EQUAL                          1440L
#define X_COMP_EVALUATE_BOOLEAN_NOT_EQUAL                      1441L
#define X_COMP_EVALUATE_BOOLEAN_LESS_THAN                      1442L
#define X_COMP_EVALUATE_BOOLEAN_GREATER_THAN                   1443L
#define X_COMP_EVALUATE_BOOLEAN_LESS_THAN_OR_EQUAL             1444L
#define X_COMP_EVALUATE_BOOLEAN_GREATER_THAN_OR_EQUAL          1445L

/* ------------------------------------------------------------------ */
/* X_COMP_KIND identifiers for component module dispatch tables.      */
/* ------------------------------------------------------------------ */

#define X_COMP_KIND_DEF_PRIMITIVE_MODULE                       1000L
#define X_COMP_KIND_DEF_DERIVED_MODULE                         1010L
#define X_COMP_KIND_DEF_DERIVED_MODULE_1                       1011L
#define X_COMP_KIND_DEF_WEB_ACCESS_MODULE                      1020L
#define X_COMP_KIND_DEF_WEB_ACCESS_MODULE_1                    1021L
#define X_COMP_KIND_DEF_DERIVED_MODULE_MEMBER                  1030L
#define X_COMP_KIND_DEF_DERIVED_MODULE_MEMBER_1                1031L

#define X_COMP_KIND_DEF_FORM_PATTERN                           1100L
#define X_COMP_KIND_DEF_VISUAL_PART_PATTERN                    1110L
#define X_COMP_KIND_DEF_FIELD_PATTERN                          1120L
#define X_COMP_KIND_DEF_FIELD_PATTERN_1                        1121L
#define X_COMP_KIND_DEF_FIELD_PATTERN_2                        1122L
#define X_COMP_KIND_DEF_FIELD_PATTERN_3                        1123L
#define X_COMP_KIND_DEF_FIELD_PATTERN_4                        1124L
#define X_COMP_KIND_DEF_BITMAP_PATTERN                         1130L
#define X_COMP_KIND_DEF_BITMAP_PATTERN_1                       1131L
#define X_COMP_KIND_DEF_CURSOR_PATTERN                         1140L
#define X_COMP_KIND_DEF_ICON_PATTERN                           1150L
#define X_COMP_KIND_DEF_VISUAL_STYLE_PATTERN                   1160L
#define X_COMP_KIND_DEF_EXTERNAL_FORM_PATTERN                  1170L
#define X_COMP_KIND_DEF_EXTERNAL_VISUAL_PART_PATTERN           1180L
#define X_COMP_KIND_DEF_EXTERNAL_PRIMITIVE_PATTERN             1190L
#define X_COMP_KIND_DEF_COM_PROXY_PATTERN                      1200L
#define X_COMP_KIND_DEF_COM_PROXY_PATTERN_1                    1201L
#define X_COMP_KIND_DEF_WEB_PATTERN                            1210L
#define X_COMP_KIND_DEF_FUNCTION_PATTERN                       1220L
#define X_COMP_KIND_DEF_EXTERNAL_WAM_PATTERN                   1230L
#define X_COMP_KIND_DEF_BUSINESS_OBJECT_PATTERN                1240L
#define X_COMP_KIND_DEF_EXTERNAL_BUSINESS_OBJECT_PATTERN       1250L
#define X_COMP_KIND_DEF_DERIVED_MODULE_PATTERN                 1260L
#define X_COMP_KIND_DEF_DOT_NET_PROXY_PATTERN                  1270L
#define X_COMP_KIND_DEF_WEB_SERVICE_PROXY_PATTERN              1280L
#define X_COMP_KIND_DEF_WEB_PAGE_PATTERN                       1290L
#define X_COMP_KIND_DEF_EXTERNAL_WEB_PAGE_PATTERN              1300L

#define X_COMP_KIND_DEF_TLB_BLOB                               1400L


#define X_COMP_KIND_DEF_DERIVED_CLASS                          1500L
#define X_COMP_KIND_DEF_LOCAL_CLASS                            1510L
#define X_COMP_KIND_DEF_FIELD_VISUAL_CLASS                     1520L
#define X_COMP_KIND_DEF_FIELD_PICKLIST_CLASS                   1530L
#define X_COMP_KIND_DEF_FIELD_PROMPTER_CLASS                   1540L
#define X_COMP_KIND_DEF_FIELD_VISUAL_PART_CLASS                1550L
#define X_COMP_KIND_DEF_WEB_CLASS                              1560L
#define X_COMP_KIND_DEF_DERIVED_MEMBER_CLASS                   1570L
#define X_COMP_KIND_DEF_DERIVED_MEMBER_CLASS_LINK              1580L
#define X_COMP_KIND_DEF_FIELD_VISUAL_HOST_CLASS                1590L
#define X_COMP_KIND_DEF_FIELD_DYNAMIC_PICKLIST_CLASS           1600L

#define X_COMP_KIND_REF_PATTERN                                2100L
#define X_COMP_KIND_REF_NAMESPACE                              2110L
#define X_COMP_KIND_REF_CLASS                                  2200L
#define X_COMP_KIND_REF_VARIANT_DATA_TYPE                      2210L
#define X_COMP_KIND_REF_LIBRARY                                2220L
#define X_COMP_KIND_REF_PARAMETERIZED_TYPE                     2230L
#define X_COMP_KIND_REF_SINGLE_PARAMETERIZED_TYPE              2240L

#define X_COMP_KIND_DEF_STATIC_INSTANCE_REF                    3000L
#define X_COMP_KIND_DEF_STATIC_SHARED_REF                      3010L
#define X_COMP_KIND_DEF_STATIC_LOCAL_REF                       3020L
#define X_COMP_KIND_DEF_STATIC_APPLICATION_REF                 3030L
#define X_COMP_KIND_DEF_DYNAMIC_INSTANCE_REF                   3050L
#define X_COMP_KIND_DEF_DYNAMIC_SHARED_REF                     3060L
#define X_COMP_KIND_DEF_DYNAMIC_LOCAL_REF                      3070L
#define X_COMP_KIND_DEF_DYNAMIC_APPLICATION_REF                3080L
#define X_COMP_KIND_DEF_DEFERRED_INSTANCE_REF                  3100L
#define X_COMP_KIND_DEF_DEFERRED_SHARED_REF                    3110L
#define X_COMP_KIND_DEF_DEFERRED_LOCAL_REF                     3120L
#define X_COMP_KIND_DEF_DEFERRED_APPLICATION_REF               3130L

#define X_COMP_KIND_DEF_EVENT                                  3200L
#define X_COMP_KIND_DEF_METHOD                                 3210L
#define X_COMP_KIND_DEF_PROPERTY                               3220L
#define X_COMP_KIND_DEF_KEYED_PROPERTY                         3230L
#define X_COMP_KIND_DEF_CONSTRUCTOR                            3240L
#define X_COMP_KIND_DEF_FEATURE_ATTRIBUTE                      3250L
#define X_COMP_KIND_DEF_INTERFACE_FEATURE                      3260L

#define X_COMP_KIND_DEF_EVENT_PARM                             3300L
#define X_COMP_KIND_DEF_METHOD_PARM                            3310L
#define X_COMP_KIND_DEF_PROPERTY_PARM                          3320L
#define X_COMP_KIND_DEF_CONSTRUCTOR_PARM                       3340L
#define X_COMP_KIND_DEF_NEW_OPERATION_PARM                     3350L

#define X_COMP_KIND_DEF_EVT_ROUTINE                            3400L
#define X_COMP_KIND_DEF_EVT_ROUTINE_1                          3401L
#define X_COMP_KIND_DEF_EVT_ROUTINE_2                          3402L
#define X_COMP_KIND_DEF_MTH_ROUTINE                            3410L
#define X_COMP_KIND_DEF_MTH_ROUTINE_1                          3411L
#define X_COMP_KIND_DEF_MTH_ROUTINE_2                          3412L
#define X_COMP_KIND_DEF_PTY_ROUTINE                            3420L
#define X_COMP_KIND_DEF_PTY_ROUTINE_1                          3421L
#define X_COMP_KIND_DEF_PTY_ROUTINE_2                          3422L
#define X_COMP_KIND_DEF_PTY_ROUTINE_3                          3423L
#define X_COMP_KIND_DEF_SUB_ROUTINE                            3430L
#define X_COMP_KIND_DEF_SUB_ROUTINE_1                          3431L
#define X_COMP_KIND_DEF_SUB_ROUTINE_2                          3432L
#define X_COMP_KIND_DEF_CON_ROUTINE                            3440L
#define X_COMP_KIND_DEF_CON_ROUTINE_1                          3441L
#define X_COMP_KIND_DEF_CON_ROUTINE_2                          3442L
#define X_COMP_KIND_DEF_SCOPING_MTH_ROUTINE                    3450L

#define X_COMP_KIND_DEF_EVT_ROUTINE_MAP                        3500L
#define X_COMP_KIND_DEF_MTH_ROUTINE_MAP                        3510L
#define X_COMP_KIND_DEF_PTY_ROUTINE_MAP                        3520L
#define X_COMP_KIND_DEF_CON_ROUTINE_MAP                        3530L

#define X_COMP_KIND_DEF_OBSERVATION                            3600L
#define X_COMP_KIND_DEF_OBSERVATION_1                          3601L
#define X_COMP_KIND_DEF_OBSERVATION_PARM                       3610L
#define X_COMP_KIND_DEF_COLLECTION_OBSERVATION                 3620L
#define X_COMP_KIND_DEF_ANCESTOR_OBSERVATION                   3630L
#define X_COMP_KIND_DEF_BOUND_OBSERVATION                      3640L

#define X_COMP_KIND_DEF_REDEFINED_SHARED_REF                   3700L
#define X_COMP_KIND_DEF_REDEFINED_INSTANCE_REF                 3710L

#define X_COMP_KIND_DEF_WEB                                    3800L
#define X_COMP_KIND_DEF_WEB_1                                  3801L
#define X_COMP_KIND_DEF_WEB_ROUTINE                            3810L
#define X_COMP_KIND_DEF_WEB_ROUTINE_FIELD_MAP                  3820L
#define X_COMP_KIND_DEF_WEB_ROUTINE_LIST_MAP                   3830L
#define X_COMP_KIND_DEF_WEB_ROUTINE_LIST_FIELD_MAP             3840L

#define X_COMP_KIND_DEF_INVOKE                                 4000L
#define X_COMP_KIND_DEF_INVOKE_OPERATION                       4010L
#define X_COMP_KIND_DEF_INVOKE_PARM                            4020L
#define X_COMP_KIND_DEF_INVOKE_ROUTINE_OPERATION               4030L
#define X_COMP_KIND_DEF_INVOKE_ROUTINE_PARM                    4040L
#define X_COMP_KIND_DEF_CALL_METHOD_OPERATION                  4050L
#define X_COMP_KIND_DEF_CALL_ROUTINE_OPERATION                 4060L
#define X_COMP_KIND_DEF_INVOKE_CONSTRUCTOR_OPERATION           4070L
#define X_COMP_KIND_DEF_INVOKE_CONSTRUCTOR_OPERATION_1         4071L
#define X_COMP_KIND_DEF_INVOKE_CONSTRUCTOR_PARM                4080L
#define X_COMP_KIND_DEF_SET                                    4100L
#define X_COMP_KIND_DEF_SET_OPERATION                          4110L
#define X_COMP_KIND_DEF_SET_RECORD_OPERATION                   4115L
#define X_COMP_KIND_DEF_SET_PARM                               4120L
#define X_COMP_KIND_DEF_GET_PARM                               4125L
#define X_COMP_KIND_DEF_KEYED_SET_PARM                         4130L
#define X_COMP_KIND_DEF_KEYED_GET_PARM                         4135L
#define X_COMP_KIND_DEF_CLASS_ATTRIBUTE_PARM                   4140L
#define X_COMP_KIND_DEF_ASSIGN                                 4150L
#define X_COMP_KIND_DEF_PERFORM                                4160L
#define X_COMP_KIND_DEF_GET                                    4170L
#define X_COMP_KIND_DEF_SIGNAL                                 4200L
#define X_COMP_KIND_DEF_SIGNAL_OPERATION                       4210L
#define X_COMP_KIND_DEF_SIGNAL_PARM                            4220L
#define X_COMP_KIND_DEF_INVOKE_NEW_OPERATION                   4230L

#define X_COMP_KIND_DEF_SET_REF_TO_NULL                        4300L
#define X_COMP_KIND_DEF_SET_REF_TO_NULL_1                      4301L
#define X_COMP_KIND_DEF_SET_REF_TO_VARIABLE                    4310L
#define X_COMP_KIND_DEF_SET_REF_TO_VARIABLE_1                  4311L
#define X_COMP_KIND_DEF_SET_REF_DYNAMIC                        4320L
#define X_COMP_KIND_DEF_SET_REF_DYNAMIC_1                      4321L
#define X_COMP_KIND_DEF_SET_REF_CREATE_AS                      4330L
#define X_COMP_KIND_DEF_SET_REF_CREATE_AS_1                    4331L
#define X_COMP_KIND_DEF_SET_REF_CREATE_FROM                    4340L
#define X_COMP_KIND_DEF_SET_REF_CREATE_FROM_1                  4341L
#define X_COMP_KIND_DEF_SET_REF_OPEN                           4350L
#define X_COMP_KIND_DEF_SET_REF_OPEN_1                         4351L
#define X_COMP_KIND_DEF_SET_REF_TO_ATTRIBUTE_OF_FEATURE        4360L
#define X_COMP_KIND_DEF_SET_REF_TO_ATTRIBUTE_OF_FEATURE_1      4361L

#define X_COMP_KIND_DEF_IF_REF                                 4400L
#define X_COMP_KIND_DEF_IF_REF_IS_NULL                         4410L
#define X_COMP_KIND_DEF_IF_REF_IS_KIND_OF                      4420L
#define X_COMP_KIND_DEF_IF_REF_IS_INSTANCE_OF                  4430L
#define X_COMP_KIND_DEF_IF_REF_IS_EQUAL_TO_VARIABLE            4440L
#define X_COMP_KIND_DEF_IF_REF_IS_NOT_NULL                     4450L
#define X_COMP_KIND_DEF_IF_REF_IS_NOT_KIND_OF                  4460L
#define X_COMP_KIND_DEF_IF_REF_IS_NOT_INSTANCE_OF              4470L
#define X_COMP_KIND_DEF_IF_REF_IS_NOT_EQUAL_TO_VARIABLE        4480L

#define X_COMP_KIND_DEF_VARIANT_SET_PARM                       4500L
#define X_COMP_KIND_DEF_VARIANT_GET_PARM                       4505L
#define X_COMP_KIND_DEF_KEYED_VARIANT_SET_PARM                 4510L
#define X_COMP_KIND_DEF_KEYED_VARIANT_GET_PARM                 4515L
#define X_COMP_KIND_DEF_VARIANT_INVOKE_OPERATION               4520L
#define X_COMP_KIND_DEF_VARIANT_INVOKE_PARM                    4530L
#define X_COMP_KIND_DEF_VARIANT_CALL_METHOD_OPERATION          4540L
#define X_COMP_KIND_DEF_VARIANT_POSITIONAL_INVOKE_PARM         4550L

#define X_COMP_KIND_DEF_FOR                                    4600L
#define X_COMP_KIND_DEF_ITERATOR                               4610L
#define X_COMP_KIND_DEF_COLLECTION_ACCESSOR                    4620L
#define X_COMP_KIND_DEF_ENUMERATOR                             4630L
#define X_COMP_KIND_DEF_VARIANT_ENUMERATOR                     4640L

#define X_COMP_KIND_DEF_WEB_EXEC                               4700L

#define X_COMP_KIND_DEF_BOM_COMMAND_ADD_ENTRY                  4800L
#define X_COMP_KIND_DEF_BOM_COMMAND_DLT_ENTRY                  4810L
#define X_COMP_KIND_DEF_BOM_COMMAND_GET_ENTRY                  4820L
#define X_COMP_KIND_DEF_BOM_COMMAND_LOC_ENTRY                  4830L
#define X_COMP_KIND_DEF_BOM_COMMAND_UPD_ENTRY                  4840L
#define X_COMP_KIND_DEF_BOM_COMMAND_CLR_LIST                   4850L
#define X_COMP_KIND_DEF_BOM_COMMAND_INZ_LIST                   4860L
#define X_COMP_KIND_DEF_BOM_COMMAND_SELECT_LIST                4870L
#define X_COMP_KIND_DEF_BOM_COMMAND_ADD_ENTRY_AFTER            4880L

#define X_COMP_KIND_DEF_UDC_COMMAND_ADD_ENTRY                  4900L
#define X_COMP_KIND_DEF_UDC_COMMAND_DLT_ENTRY                  4910L
#define X_COMP_KIND_DEF_UDC_COMMAND_GET_ENTRY                  4920L
#define X_COMP_KIND_DEF_UDC_COMMAND_LOC_ENTRY                  4930L
#define X_COMP_KIND_DEF_UDC_COMMAND_UPD_ENTRY                  4940L
#define X_COMP_KIND_DEF_UDC_COMMAND_CLR_LIST                   4950L
#define X_COMP_KIND_DEF_UDC_COMMAND_INZ_LIST                   4960L
#define X_COMP_KIND_DEF_UDC_COMMAND_SELECT_LIST                4970L
#define X_COMP_KIND_DEF_UDC_COMMAND_ADD_ENTRY_AFTER            4980L

#define X_COMP_KIND_REF_EVENT                                  5000L
#define X_COMP_KIND_REF_METHOD                                 5010L
#define X_COMP_KIND_REF_PROPERTY                               5020L
#define X_COMP_KIND_REF_ROUTINE                                5030L
#define X_COMP_KIND_REF_CONSTRUCTOR                            5040L
#define X_COMP_KIND_REF_WEB                                    5050L

#define X_COMP_KIND_REF_EVT_ROUTINE_MAP                        5100L
#define X_COMP_KIND_REF_MTH_ROUTINE_MAP                        5110L
#define X_COMP_KIND_REF_PTY_ROUTINE_MAP                        5120L
#define X_COMP_KIND_REF_CON_ROUTINE_MAP                        5130L

#define X_COMP_KIND_REF_STATIC_INSTANCE_REF                    5200L
#define X_COMP_KIND_REF_DEFERRED_INSTANCE_REF                  5210L
#define X_COMP_KIND_REF_STATIC_SHARED_REF                      5220L
#define X_COMP_KIND_REF_DEFERRED_SHARED_REF                    5230L
#define X_COMP_KIND_REF_STATIC_LOCAL_REF                       5240L
#define X_COMP_KIND_REF_DEFERRED_LOCAL_REF                     5250L
#define X_COMP_KIND_REF_OWNER_COMPONENT                        5260L
#define X_COMP_KIND_REF_STATIC_COMPONENT                       5270L
#define X_COMP_KIND_REF_ANCESTOR_COMPONENT                     5280L
#define X_COMP_KIND_REF_SELF_COMPONENT                         5290L

#define X_COMP_KIND_REF_EVENT_PARM                             5300L
#define X_COMP_KIND_REF_METHOD_PARM                            5310L
#define X_COMP_KIND_REF_ROUTINE_MAP                            5320L
#define X_COMP_KIND_REF_CONSTRUCTOR_PARM                       5330L

#define X_COMP_KIND_REF_ANCESTOR_SHARED_REF                    5400L
#define X_COMP_KIND_REF_ANCESTOR_INSTANCE_REF                  5410L
#define X_COMP_KIND_REF_COM_SENDER                             5420L
#define X_COMP_KIND_REF_DYNAMIC_LOCAL_REF                      5430L
#define X_COMP_KIND_REF_DYNAMIC_SHARED_REF                     5440L
#define X_COMP_KIND_REF_DYNAMIC_INSTANCE_REF                   5450L
#define X_COMP_KIND_REF_FOR_VARIABLE                           5460L
#define X_COMP_KIND_REF_FOR_KEY_VARIABLE                       5470L

#define X_COMP_KIND_REF_STATIC_APPLICATION_REF                 5500L
#define X_COMP_KIND_REF_DEFERRED_APPLICATION_REF               5510L
#define X_COMP_KIND_REF_DYNAMIC_APPLICATION_REF                5520L
#define X_COMP_KIND_REF_ANCESTOR_APPLICATION_REF               5530L

#define X_COMP_KIND_REF_BOM_RECORD                             5800L
#define X_COMP_KIND_DEF_BOM_RECORD_OPERATION_GET               5810L
#define X_COMP_KIND_DEF_BOM_RECORD_OPERATION_SET               5820L

#define X_COMP_KIND_REF_UDC_RECORD                             5900L

#define X_COMP_KIND_DEF_PTY_OPERATION                          6000L
#define X_COMP_KIND_DEF_UNKEYED_PTY_OPERATION                  6005L
#define X_COMP_KIND_DEF_LIST_OPERATION                         6010L
#define X_COMP_KIND_DEF_UDC_LIST_OPERATION                     6011L
#define X_COMP_KIND_DEF_LIST_COLUMN_OPERATION                  6020L
#define X_COMP_KIND_DEF_DEFAULT_PTY_OPERATION                  6030L
#define X_COMP_KIND_DEF_UNKEYED_DEFAULT_PTY_OPERATION          6035L
#define X_COMP_KIND_DEF_PTY_ROUTINE_OPERATION                  6040L
#define X_COMP_KIND_DEF_PTY_ROUTINE_OPERATION_1                6041L
#define X_COMP_KIND_DEF_KEYED_OPERATION                        6050L
#define X_COMP_KIND_DEF_UNKEYED_OPERATION                      6060L
#define X_COMP_KIND_DEF_UNKEYED_OPERATION_1                    6061L
#define X_COMP_KIND_DEF_UNKEYED_VARIANT_OPERATION              6065L
#define X_COMP_KIND_DEF_VARIANT_VARIABLE_OPERATION             6070L
#define X_COMP_KIND_DEF_VARIANT_PROPERTY_OPERATION             6080L
#define X_COMP_KIND_DEF_UNKEYED_VARIANT_PROPERTY_OPERATION     6085L
#define X_COMP_KIND_DEF_BOUND_FEATURE_OPERATION                6090L

#define X_COMP_KIND_DEF_STRING_LITERAL                         6100L
#define X_COMP_KIND_DEF_LONG_LITERAL                           6110L
#define X_COMP_KIND_DEF_DOUBLE_LITERAL                         6120L
#define X_COMP_KIND_DEF_DECIMAL_LITERAL                        6130L
#define X_COMP_KIND_DEF_LONGLONG_LITERAL                       6140L

#define X_COMP_KIND_DEF_STRING_EXCHANGE                        6200L
#define X_COMP_KIND_DEF_LONG_EXCHANGE                          6210L
#define X_COMP_KIND_DEF_DOUBLE_EXCHANGE                        6220L
#define X_COMP_KIND_DEF_DECIMAL_EXCHANGE                       6230L
#define X_COMP_KIND_DEF_GENERIC_EXCHANGE                       6240L
#define X_COMP_KIND_DEF_MTXT_EXCHANGE                          6250L

#define X_COMP_KIND_DEF_KEYED_PTY_OPERATION                    6300L
#define X_COMP_KIND_DEF_KEYED_DEFAULT_PTY_OPERATION            6310L
#define X_COMP_KIND_DEF_DEFAULT_KEYED_PTY_OPERATION            6320L
#define X_COMP_KIND_DEF_DEFAULT_KEYED_DEFAULT_PTY_OPERATION    6330L
#define X_COMP_KIND_DEF_KEYED_ROUTINE_CALL_OPERATION           6340L
#define X_COMP_KIND_DEF_KEYED_VARIANT_OF_DEFAULT_PTY_OPERATION 6350L
#define X_COMP_KIND_DEF_KEYED_VARIANT_PROPERTY_OPERATION       6360L
#define X_COMP_KIND_DEF_KEYED_VARIANT_FEATURE_GET_OPERATION    X_COMP_KIND_DEF_KEYED_VARIANT_PROPERTY_OPERATION
#define X_COMP_KIND_DEF_KEYED_VARIANT_OF_PTY_OPERATION         6370L

#define X_COMP_KIND_DEF_MODIFIED_FEATURE                       6400L

/* RJH? */
#define X_COMP_KIND_DEF_EVALUATION_OPERATION                   6500L
#define X_COMP_KIND_DEF_EXPRESSION_EVALUATION                  6510L
#define X_COMP_KIND_DEF_UNARY_EVALUATION                       6520L
#define X_COMP_KIND_DEF_BINARY_EVALUATION                      6530L

#define X_COMP_KIND_DEF_FIELD_ATTRIBUTE_OPERATION              6600L

#define X_COMP_KIND_DEF_MODULE_FRAME                           7000L


/* ----------------------------------------------------------------- */
/* X_COMP_HEADER                                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       All of the above                                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_HEADER
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_HEADER,
      *PX_COMP_HEADER,
      **PPX_COMP_HEADER;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_HEADER_FCC
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_HEADER_FCC,
      *PX_COMP_HEADER_FCC,
      **PPX_COMP_HEADER_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_NULL                                                       */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_NULL                                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_NULL
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_NULL,
      *PX_COMP_NULL,
      **PPX_COMP_NULL;

#endif

#endif // X_OPERATING_TARGET_CSHARP

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_NULL_FCC
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_NULL_FCC,
      *PX_COMP_NULL_FCC,
      **PPX_COMP_NULL_FCC;

#endif

#endif // X_OPERATING_TARGET_CSHARP

/* ----------------------------------------------------------------- */
/* X_COMP_PRIMITIVE_MODULE                                           */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_PRIMITIVE_MODULE                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PRIMITIVE_MODULE
   {
      X_COMP_KIND                         ulKind;
      const void                       *  pvTopPrimitive;
   }
      X_COMP_PRIMITIVE_MODULE,
      *PX_COMP_PRIMITIVE_MODULE,
      **PPX_COMP_PRIMITIVE_MODULE;

#endif


#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PRIMITIVE_MODULE_FCC
   {
      X_COMP_KIND                         ulKind;
      const void                       *  pvTopPrimitive;
   }
      X_COMP_PRIMITIVE_MODULE_FCC,
      *PX_COMP_PRIMITIVE_MODULE_FCC,
      **PPX_COMP_PRIMITIVE_MODULE_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_DERIVED_MODULE                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_DERIVED_MODULE                              */
/*       X_COMP_KIND_DEF_DERIVED_MODULE_1                            */
/*                                                                   */
/*       X_COMP_KIND_DEF_WEB_ACCESS_MODULE                           */
/*       X_COMP_KIND_DEF_WEB_ACCESS_MODULE_1                         */
/*                                                                   */
/*       X_COMP_KIND_DEF_DERIVED_MODULE_MEMBER                       */
/*       X_COMP_KIND_DEF_DERIVED_MODULE_MEMBER_1                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DERIVED_MODULE
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulFldTableEntries;
      unsigned long                       ulListTableEntries;
      unsigned long                       ulGlobal1Size;
      unsigned long                       ulGlobal2Size;
      unsigned long                       ulDispatchEntries;
      X_DEFS_HEADER_TABLE                 pDispatchTable;
      unsigned long                       ulDerivedPatternEntries;
      X_DEFS_DISPATCH_ID_TABLE            pDerivedPatternTable;
      unsigned long                       ulDerivedDescriptionEntries;
      X_DEFS_DISPATCH_ID_TABLE            pDerivedDescriptionTable;
      FN_COMP_SERVICES_POINT           *  pfnServicesCreatePoint;
      FN_COMP_SERVICES_POINT           *  pfnServicesDestroyPoint;
      FN_COMP_SERVICES_POINT           *  pfnVectorExchangePoint;
      X_MODULEHANDLE                      hmodDerivedModule;
      FN_COMP_SERVICES_POINT           *  pfnServicesInitializePoint;
      /* VERSION_TAG 1 */
      unsigned long                       ulLanguageEntries;
      X_DEFS_LANG_TABLE                   pLanguageTable;
   }
      X_COMP_DERIVED_MODULE,
      *PX_COMP_DERIVED_MODULE,
      **PPX_COMP_DERIVED_MODULE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_DERIVED_MODULE_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulDerivedPatternEntries;
      X_DEFS_DISPATCH_ID_TABLE            pDerivedPatternTable;
      unsigned long                       ulDerivedDescriptionEntries;
      X_DEFS_DISPATCH_ID_TABLE            pDerivedDescriptionTable;
   }
      X_COMP_DERIVED_MODULE_FCC,
      *PX_COMP_DERIVED_MODULE_FCC,
      **PPX_COMP_DERIVED_MODULE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DERIVED_PATTERN                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_WEB_PATTERN                                 */
/*       X_COMP_KIND_DEF_FORM_PATTERN                                */
/*       X_COMP_KIND_DEF_VISUAL_PART_PATTERN                         */
/*       X_COMP_KIND_DEF_FUNCTION_PATTERN                            */
/*                                                                   */
/*   Version 1 Supports:                                             */
/*       X_COMP_KIND_DEF_BUSINESS_OBJECT_PATTERN                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DERIVED_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      /* VERSION_TAG 1 */
      X_COMP_DISPATCH_ID                  ulModel;
   }
      X_COMP_DERIVED_PATTERN,
      *PX_COMP_DERIVED_PATTERN,
      **PPX_COMP_DERIVED_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_DERIVED_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      /* VERSION_TAG 1 */
      X_COMP_DISPATCH_ID                  ulModel;
   }
      X_COMP_DERIVED_PATTERN_FCC,
      *PX_COMP_DERIVED_PATTERN_FCC,
      **PPX_COMP_DERIVED_PATTERN_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_FIELD_PATTERN                                              */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_FIELD_PATTERN                               */
/*                                                                   */
/*   Version 1 Supports:                                             */
/*       X_COMP_KIND_DEF_FIELD_PATTERN_1                             */
/*       X_COMP_KIND_DEF_FIELD_PATTERN_2                             */
/*                                                                   */
/*   Version 3 Supports:                                             */
/*       X_COMP_KIND_DEF_FIELD_PATTERN_3                             */
/*                                                                   */
/*   Version 4 Supports:                                             */
/*       X_COMP_KIND_DEF_FIELD_PATTERN_4                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_FIELD_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchLabel;
      const unsigned char              *  pvchColumnHeading1;
      const unsigned char              *  pvchColumnHeading2;
      const unsigned char              *  pvchColumnHeading3;
      X_COMP_FIELD_SPEC_1                 ulFieldSpec1;
      X_COMP_FIELD_SPEC_2                 ulFieldSpec2;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulModifiers;
      /* VERSION_TAG 1 */
      const unsigned char              *  pvchEditWord;
      /* VERSION_TAG 3 */
      X_COMP_FIELD_ATTRIBUTES             ulFieldAttributes;
      /* VERSION_TAG 4 */
      X_COMP_FIELD_SPEC_3                 ulFieldSpec3;
   }
      X_COMP_FIELD_PATTERN,
      *PX_COMP_FIELD_PATTERN,
      **PPX_COMP_FIELD_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_FIELD_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      X_COMP_FIELD_SPEC_1                 ulFieldSpec1;
      X_COMP_FIELD_SPEC_2                 ulFieldSpec2;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulModifiers;
      /* VERSION_TAG 1 */
      const unsigned char              *  pvchEditWord;
      /* VERSION_TAG 3 */
      X_COMP_FIELD_ATTRIBUTES             ulFieldAttributes;
      /* VERSION_TAG 4 */
      X_COMP_FIELD_SPEC_3                 ulFieldSpec3;
   }
      X_COMP_FIELD_PATTERN_FCC,
      *PX_COMP_FIELD_PATTERN_FCC,
      **PPX_COMP_FIELD_PATTERN_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_RESOURCE_PATTERN                                           */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_VISUAL_STYLE_PATTERN                        */
/*                                                                   */
/*    Version 1 Supports:                                            */
/*       X_COMP_KIND_DEF_ICON_PATTERN                                */
/*       X_COMP_KIND_DEF_BITMAP_PATTERN                              */
/*       X_COMP_KIND_DEF_CURSOR_PATTERN                              */
/*       X_COMP_KIND_DEF_TLB_BLOB                                    */
/*                                                                   */
/*    Version 2 Supports:                                            */
/*       X_COMP_KIND_DEF_BITMAP_PATTERN_1                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_RESOURCE_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;

      /* VERSION_TAG 1 */
      unsigned long                       ulLength;
      unsigned short                      usResourceId;

      /* VERSION_TAG 2 */
      unsigned long                       ulResourceKind;
   }
      X_COMP_RESOURCE_PATTERN,
      *PX_COMP_RESOURCE_PATTERN,
      **PPX_COMP_RESOURCE_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_RESOURCE_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulLength;
      const unsigned char              *  pvchBLOB;
      const unsigned char              *  pvchNameSuffix;
      const unsigned char              *  pvchFileSuffix;
      const unsigned char              *  pvchRCType;
      unsigned long                       ulResourceKind;
      unsigned long                       ulLengthCSharp;
      const unsigned char              *  pvchBLOBCSharp;
   }
      X_COMP_RESOURCE_PATTERN_FCC,
      *PX_COMP_RESOURCE_PATTERN_FCC,
      **PPX_COMP_RESOURCE_PATTERN_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_EXTERNAL_PATTERN                                           */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_EXTERNAL_PRIMITIVE_PATTERN                  */
/*       X_COMP_KIND_DEF_EXTERNAL_FORM_PATTERN                       */
/*       X_COMP_KIND_DEF_EXTERNAL_VISUAL_PART_PATTERN                */
/*       X_COMP_KIND_DEF_EXTERNAL_WAM_PATTERN                        */
/*       X_COMP_KIND_DEF_EXTERNAL_BUSINESS_OBJECT_PATTERN            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EXTERNAL_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchDllName;
   }
      X_COMP_EXTERNAL_PATTERN,
      *PX_COMP_EXTERNAL_PATTERN,
      **PPX_COMP_EXTERNAL_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_EXTERNAL_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchDllName;
   }
      X_COMP_EXTERNAL_PATTERN_FCC,
      *PX_COMP_EXTERNAL_PATTERN_FCC,
      **PPX_COMP_EXTERNAL_PATTERN_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DERIVED_MODULE_PATTERN                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_DERIVED_MODULE_PATTERN                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DERIVED_MODULE_PATTERN
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_DERIVED_MODULE_PATTERN,
      *PX_COMP_DERIVED_MODULE_PATTERN,
      **PPX_COMP_DERIVED_MODULE_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_DERIVED_MODULE_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_DERIVED_MODULE_PATTERN_FCC,
      *PX_COMP_DERIVED_MODULE_PATTERN_FCC,
      **PPX_COMP_DERIVED_MODULE_PATTERN_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_COM_PROXY_PATTERN                                          */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_COM_PROXY_PATTERN                           */
/*                                                                   */
/*    Version 1 Supports:                                            */
/*       X_COMP_KIND_DEF_COM_PROXY_PATTERN_1                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_COM_PROXY_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchProgId;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;

      /* Persistent property BLOB */
      unsigned long                       ulPropStreamLength;
      unsigned short                      usPropStreamResourceId;

      /* VERSION_TAG 1 */
      unsigned long                       ulModifiers;
   }
      X_COMP_COM_PROXY_PATTERN,
      *PX_COMP_COM_PROXY_PATTERN,
      **PPX_COMP_COM_PROXY_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_COM_PROXY_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchProgId;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;

      /* Persistent property BLOB */
      unsigned long                       ulPropStreamLength;
      const unsigned char              *  pvchPropStreamBLOB;

      /* VERSION_TAG 1 */
      unsigned long                       ulModifiers;
   }
      X_COMP_COM_PROXY_PATTERN_FCC,
      *PX_COMP_COM_PROXY_PATTERN_FCC,
      **PPX_COMP_COM_PROXY_PATTERN_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DOT_NET_PROXY_PATTERN                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_DOT_NET_PROXY_PATTERN                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DOT_NET_PROXY_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchFilename;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulModifiers;
   }
      X_COMP_DOT_NET_PROXY_PATTERN,
      *PX_COMP_DOT_NET_PROXY_PATTERN,
      **PPX_COMP_DOT_NET_PROXY_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_DOT_NET_PROXY_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchFilename;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulModifiers;
   }
      X_COMP_DOT_NET_PROXY_PATTERN_FCC,
      *PX_COMP_DOT_NET_PROXY_PATTERN_FCC,
      **PPX_COMP_DOT_NET_PROXY_PATTERN_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_WEB_SERVICE_PROXY_PATTERN                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_WEB_SERVICE_PROXY_PATTERN                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_WEB_SERVICE_PROXY_PATTERN
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchFilename;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulModifiers;
   }
      X_COMP_WEB_SERVICE_PROXY_PATTERN,
      *PX_COMP_WEB_SERVICE_PROXY_PATTERN,
      **PPX_COMP_WEB_SERVICE_PROXY_PATTERN;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_WEB_SERVICE_PROXY_PATTERN_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPatternName;
      const unsigned char              *  pvchFilename;
      unsigned long                       ulClassEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassTable;
      unsigned long                       ulModifiers;
   }
      X_COMP_WEB_SERVICE_PROXY_PATTERN_FCC,
      *PX_COMP_WEB_SERVICE_PROXY_PATTERN_FCC,
      **PPX_COMP_WEB_SERVICE_PROXY_PATTERN_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DERIVED_CLASS                                              */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_WEB_CLASS                                   */
/*       X_COMP_KIND_DEF_DERIVED_CLASS                               */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DERIVED_CLASS
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulFldTableEntries;
      unsigned long                       ulListTableEntries;
      X_COMP_DISPATCH_ID                  ulPattern;
      unsigned long                       ulRole;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulObservationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pObservationTable;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_DERIVED_CLASS,
      *PX_COMP_DERIVED_CLASS,
      **PPX_COMP_DERIVED_CLASS;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_DERIVED_CLASS_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      unsigned long                       ulRole;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulObservationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pObservationTable;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_DERIVED_CLASS_FCC,
      *PX_COMP_DERIVED_CLASS_FCC,
      **PPX_COMP_DERIVED_CLASS_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_LOCAL_CLASS                                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_LOCAL_CLASS                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_LOCAL_CLASS
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
   }
      X_COMP_LOCAL_CLASS,
      *PX_COMP_LOCAL_CLASS,
      **PPX_COMP_LOCAL_CLASS;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_LOCAL_CLASS_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
   }
      X_COMP_LOCAL_CLASS_FCC,
      *PX_COMP_LOCAL_CLASS_FCC,
      **PPX_COMP_LOCAL_CLASS_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DERIVED_MEMBER_CLASS                                       */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_DERIVED_MEMBER_CLASS                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DERIVED_MEMBER_CLASS
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulRole;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulObservationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pObservationTable;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_DERIVED_MEMBER_CLASS,
      *PX_COMP_DERIVED_MEMBER_CLASS,
      **PPX_COMP_DERIVED_MEMBER_CLASS;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_DERIVED_MEMBER_CLASS_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulRole;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulObservationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pObservationTable;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_DERIVED_MEMBER_CLASS_FCC,
      *PX_COMP_DERIVED_MEMBER_CLASS_FCC,
      **PPX_COMP_DERIVED_MEMBER_CLASS_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DERIVED_MEMBER_CLASS_LINK                                  */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_DERIVED_MEMBER_CLASS_LINK                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DERIVED_MEMBER_CLASS_LINK
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      FN_COMP_SERVICES_POINT           *  pfnServicesCreatePoint;
      // X_COMP_DERIVED_MEMBER_CLASS      *  pDerivedMemberClass;
   }
      X_COMP_DERIVED_MEMBER_CLASS_LINK,
      *PX_COMP_DERIVED_MEMBER_CLASS_LINK,
      **PPX_COMP_DERIVED_MEMBER_CLASS_LINK;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_DERIVED_MEMBER_CLASS_LINK_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchName;
      long                                lMemberIdentifier;
   }
      X_COMP_DERIVED_MEMBER_CLASS_LINK_FCC,
      *PX_COMP_DERIVED_MEMBER_CLASS_LINK_FCC,
      **PPX_COMP_DERIVED_MEMBER_CLASS_LINK_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_REFERENCE                                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_STATIC_INSTANCE_REF                         */
/*       X_COMP_KIND_DEF_STATIC_LOCAL_REF                            */
/*       X_COMP_KIND_DEF_STATIC_SHARED_REF                           */
/*                                                                   */
/*       X_COMP_KIND_DEF_DEFERRED_INSTANCE_REF                       */
/*       X_COMP_KIND_DEF_DEFERRED_LOCAL_REF                          */
/*       X_COMP_KIND_DEF_DEFERRED_SHARED_REF                         */
/*                                                                   */
/*       X_COMP_KIND_DEF_DYNAMIC_INSTANCE_REF                        */
/*       X_COMP_KIND_DEF_DYNAMIC_LOCAL_REF                           */
/*       X_COMP_KIND_DEF_DYNAMIC_SHARED_REF                          */
/*                                                                   */
/*       X_COMP_KIND_DEF_REDEFINED_SHARED_REF                        */
/*       X_COMP_KIND_DEF_REDEFINED_INSTANCE_REF                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_REFERENCE
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulObservationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pObservationTable;
   }
      X_COMP_REFERENCE,
      *PX_COMP_REFERENCE,
      **PPX_COMP_REFERENCE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_REFERENCE_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulObservationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pObservationTable;
   }
      X_COMP_REFERENCE_FCC,
      *PX_COMP_REFERENCE_FCC,
      **PPX_COMP_REFERENCE_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_EVENT                                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_EVENT                                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EVENT
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_EVENT,
      *PX_COMP_EVENT,
      **PPX_COMP_EVENT;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_EVENT_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_EVENT_FCC,
      *PX_COMP_EVENT_FCC,
      **PPX_COMP_EVENT_FCC;


#endif


/* ----------------------------------------------------------------- */
/* X_COMP_METHOD                                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_METHOD                                      */
/*       X_COMP_KIND_DEF_CONSTRUCTOR                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_METHOD
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
      X_COMP_DISPATCH_ID                  ulRoutine;
   }
      X_COMP_METHOD,
      *PX_COMP_METHOD,
      **PPX_COMP_METHOD;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_METHOD_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
      X_COMP_DISPATCH_ID                  ulRoutine;
   }
      X_COMP_METHOD_FCC,
      *PX_COMP_METHOD_FCC,
      **PPX_COMP_METHOD_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_PROPERTY                                                   */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_PROPERTY                                    */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PROPERTY
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      X_COMP_DISPATCH_ID                  ulGetRoutine;
      X_COMP_DISPATCH_ID                  ulSetRoutine;
   }
      X_COMP_PROPERTY,
      *PX_COMP_PROPERTY,
      **PPX_COMP_PROPERTY;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PROPERTY_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      X_COMP_DISPATCH_ID                  ulGetRoutine;
      X_COMP_DISPATCH_ID                  ulSetRoutine;
   }
      X_COMP_PROPERTY_FCC,
      *PX_COMP_PROPERTY_FCC,
      **PPX_COMP_PROPERTY_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_KEYED_PROPERTY                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_KEYED_PROPERTY                              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_KEYED_PROPERTY
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      X_COMP_DISPATCH_ID                  ulGetRoutine;
      X_COMP_DISPATCH_ID                  ulSetRoutine;
      unsigned long                       ulReadParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pReadParameterTable;
      unsigned long                       ulWriteParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pWriteParameterTable;
   }
      X_COMP_KEYED_PROPERTY,
      *PX_COMP_KEYED_PROPERTY,
      **PPX_COMP_KEYED_PROPERTY;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_KEYED_PROPERTY_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      X_COMP_DISPATCH_ID                  ulGetRoutine;
      X_COMP_DISPATCH_ID                  ulSetRoutine;
      unsigned long                       ulReadParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pReadParameterTable;
      unsigned long                       ulWriteParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pWriteParameterTable;
   }
      X_COMP_KEYED_PROPERTY_FCC,
      *PX_COMP_KEYED_PROPERTY_FCC,
      **PPX_COMP_KEYED_PROPERTY_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_FEATURE_ATTRIBUTE                                          */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_FEATURE_ATTRIBUTE                           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_FEATURE_ATTRIBUTE
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      unsigned long                       ulModifiers;
      X_COMP_DISPATCH_ID                  ulAttributeType;
      X_COMP_DISPATCH_ID                  ulTargetFeature;
      X_COMP_DISPATCH_ID                  ulConstructorOperation;
   }
      X_COMP_FEATURE_ATTRIBUTE,
      *PX_COMP_FEATURE_ATTRIBUTE,
      **PPX_COMP_FEATURE_ATTRIBUTE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_FEATURE_ATTRIBUTE_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulModifiers;
      X_COMP_DISPATCH_ID                  ulAttributeType;
      X_COMP_DISPATCH_ID                  ulTargetFeature;
      X_COMP_DISPATCH_ID                  ulConstructorOperation;
   }
      X_COMP_FEATURE_ATTRIBUTE_FCC,
      *PX_COMP_FEATURE_ATTRIBUTE_FCC,
      **PPX_COMP_FEATURE_ATTRIBUTE_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_INTERFACE_FEATURE                                          */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_INTERFACE_FEATURE                           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_INTERFACE_FEATURE
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      X_COMP_DISPATCH_ID                  ulInterfaceType;
   }
      X_COMP_INTERFACE_FEATURE,
      *PX_COMP_INTERFACE_FEATURE,
      **PPX_COMP_INTERFACE_FEATURE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_INTERFACE_FEATURE_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      X_COMP_DISPATCH_ID                  ulInterfaceType;
   }
      X_COMP_INTERFACE_FEATURE_FCC,
      *PX_COMP_INTERFACE_FEATURE_FCC,
      **PPX_COMP_INTERFACE_FEATURE_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_PARAMETER                                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_EVENT_PARM                                  */
/*       X_COMP_KIND_DEF_METHOD_PARM                                 */
/*       X_COMP_KIND_DEF_PROPERTY_PARM                               */
/*       X_COMP_KIND_DEF_CONSTRUCTOR_PARM                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PARAMETER
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      X_COMP_DISPATCH_ID                  ulDefaultValue;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
   }
      X_COMP_PARAMETER,
      *PX_COMP_PARAMETER,
      **PPX_COMP_PARAMETER;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PARAMETER_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      X_COMP_DISPATCH_ID                  ulDefaultValue;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
   }
      X_COMP_PARAMETER_FCC,
      *PX_COMP_PARAMETER_FCC,
      **PPX_COMP_PARAMETER_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_EVT_ROUTINE_MAP                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_EVT_ROUTINE_MAP                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EVT_ROUTINE_MAP
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulParameter;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
   }
      X_COMP_EVT_ROUTINE_MAP,
      *PX_COMP_EVT_ROUTINE_MAP,
      **PPX_COMP_EVT_ROUTINE_MAP;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_EVT_ROUTINE_MAP_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulParameter;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
   }
      X_COMP_EVT_ROUTINE_MAP_FCC,
      *PX_COMP_EVT_ROUTINE_MAP_FCC,
      **PPX_COMP_EVT_ROUTINE_MAP_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_MTH_ROUTINE_MAP                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_CON_ROUTINE_MAP                             */
/*       X_COMP_KIND_DEF_MTH_ROUTINE_MAP                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_MTH_ROUTINE_MAP
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_MTH_ROUTINE_MAP,
      *PX_COMP_MTH_ROUTINE_MAP,
      **PPX_COMP_MTH_ROUTINE_MAP;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_MTH_ROUTINE_MAP_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_MTH_ROUTINE_MAP_FCC,
      *PX_COMP_MTH_ROUTINE_MAP_FCC,
      **PPX_COMP_MTH_ROUTINE_MAP_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_PTY_ROUTINE_MAP                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_PTY_ROUTINE_MAP                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PTY_ROUTINE_MAP
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      X_COMP_DISPATCH_ID                  ulDefaultValue;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
   }
      X_COMP_PTY_ROUTINE_MAP,
      *PX_COMP_PTY_ROUTINE_MAP,
      **PPX_COMP_PTY_ROUTINE_MAP;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PTY_ROUTINE_MAP_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      X_COMP_DISPATCH_ID                  ulDefaultValue;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
   }
      X_COMP_PTY_ROUTINE_MAP_FCC,
      *PX_COMP_PTY_ROUTINE_MAP_FCC,
      **PPX_COMP_PTY_ROUTINE_MAP_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_ROUTINE                                                    */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_EVT_ROUTINE                                 */
/*       X_COMP_KIND_DEF_MTH_ROUTINE                                 */
/*       X_COMP_KIND_DEF_PTY_ROUTINE                                 */
/*       X_COMP_KIND_DEF_SUB_ROUTINE                                 */
/*                                                                   */
/*    Version 1 Supports:                                            */
/*       X_COMP_KIND_DEF_EVT_ROUTINE_1                               */
/*       X_COMP_KIND_DEF_MTH_ROUTINE_1                               */
/*       X_COMP_KIND_DEF_PTY_ROUTINE_1                               */
/*       X_COMP_KIND_DEF_SUB_ROUTINE_1                               */
/*                                                                   */
/*    Version 3 Supports:                                            */
/*       X_COMP_KIND_DEF_CON_ROUTINE_2                               */
/*       X_COMP_KIND_DEF_EVT_ROUTINE_2                               */
/*       X_COMP_KIND_DEF_MTH_ROUTINE_2                               */
/*       X_COMP_KIND_DEF_PTY_ROUTINE_2                               */
/*       X_COMP_KIND_DEF_SCOPING_MTH_ROUTINE                         */
/*       X_COMP_KIND_DEF_SUB_ROUTINE_2                               */
/*       X_COMP_KIND_DEF_WEB_ROUTINE                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_ROUTINE
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulMapEntries;
      X_DEFS_DISPATCH_ID_TABLE            pMapTable;
      unsigned long                       ulReferenceEntries;
      X_DEFS_DISPATCH_ID_TABLE            pReferenceTable;
      FN_COMP_SERVICES_POINT           *  pfnServicesRunPoint;

      /* VERSION_TAG 1 */
      unsigned long                       ulModifiers;

      /* VERSION_TAG 2 */
      unsigned long                       ulRDMLXLineNumber;
   }
      X_COMP_ROUTINE,
      *PX_COMP_ROUTINE,
      **PPX_COMP_ROUTINE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_ROUTINE_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulMapEntries;
      X_DEFS_DISPATCH_ID_TABLE            pMapTable;
      unsigned long                       ulReferenceEntries;
      X_DEFS_DISPATCH_ID_TABLE            pReferenceTable;

      /* VERSION_TAG 1 */
      unsigned long                       ulModifiers;
  }
      X_COMP_ROUTINE_FCC,
      *PX_COMP_ROUTINE_FCC,
      **PPX_COMP_ROUTINE_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_NAMED_ROUTINE                                              */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_PTY_ROUTINE_3                               */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_NAMED_ROUTINE
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulMapEntries;
      X_DEFS_DISPATCH_ID_TABLE            pMapTable;
      unsigned long                       ulReferenceEntries;
      X_DEFS_DISPATCH_ID_TABLE            pReferenceTable;
      FN_COMP_SERVICES_POINT           *  pfnServicesRunPoint;
      unsigned long                       ulModifiers;
      unsigned long                       ulRDMLXLineNumber;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
   }
      X_COMP_NAMED_ROUTINE,
      *PX_COMP_NAMED_ROUTINE,
      **PPX_COMP_NAMED_ROUTINE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_NAMED_ROUTINE_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulMapEntries;
      X_DEFS_DISPATCH_ID_TABLE            pMapTable;
      unsigned long                       ulReferenceEntries;
      X_DEFS_DISPATCH_ID_TABLE            pReferenceTable;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
  }
      X_COMP_NAMED_ROUTINE_FCC,
      *PX_COMP_NAMED_ROUTINE_FCC,
      **PPX_COMP_NAMED_ROUTINE_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_OBSERVATION                                                */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_OBSERVATION                                 */
/*                                                                   */
/*   Version 1 Supports:                                             */
/*       X_COMP_KIND_DEF_OBSERVATION_1                               */
/*       X_COMP_KIND_DEF_COLLECTION_OBSERVATION                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_OBSERVATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEvent;
      X_COMP_DISPATCH_ID                  ulRoutine;
      /* VERSION_TAG 1 */
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_OBSERVATION,
      *PX_COMP_OBSERVATION,
      **PPX_COMP_OBSERVATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_OBSERVATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEvent;
      X_COMP_DISPATCH_ID                  ulRoutine;
      /* VERSION_TAG 1 */
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
  }
      X_COMP_OBSERVATION_FCC,
      *PX_COMP_OBSERVATION_FCC,
      **PPX_COMP_OBSERVATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_BOUND_OBSERVATION                                          */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_BOUND_OBSERVATION                           */
/*                                                                   */
/*   Note:                                                           */
/*      The layout of this structure matches Version 1 of the        */
/*      X_COMP_OBSERVATION structure.                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_BOUND_OBSERVATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEvent;
      X_COMP_DISPATCH_ID                  ulRoutine;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
      X_COMP_DISPATCH_ID                  ulProperty;
   }
      X_COMP_BOUND_OBSERVATION,
      *PX_COMP_BOUND_OBSERVATION,
      **PPX_COMP_BOUND_OBSERVATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_BOUND_OBSERVATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEvent;
      X_COMP_DISPATCH_ID                  ulRoutine;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
      X_COMP_DISPATCH_ID                  ulProperty;
  }
      X_COMP_BOUND_OBSERVATION_FCC,
      *PX_COMP_BOUND_OBSERVATION_FCC,
      **PPX_COMP_BOUND_OBSERVATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_ANCESTOR_OBSERVATION                                       */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_ANCESTOR_OBSERVATION                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_ANCESTOR_OBSERVATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulFeature;
      X_COMP_DISPATCH_ID                  ulObservation;
   }
      X_COMP_ANCESTOR_OBSERVATION,
      *PX_COMP_ANCESTOR_OBSERVATION,
      **PPX_COMP_ANCESTOR_OBSERVATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_ANCESTOR_OBSERVATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulFeature;
      X_COMP_DISPATCH_ID                  ulObservation;
  }
      X_COMP_ANCESTOR_OBSERVATION_FCC,
      *PX_COMP_ANCESTOR_OBSERVATION_FCC,
      **PPX_COMP_ANCESTOR_OBSERVATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_OBSERVATION_PARM                                           */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_OBSERVATION_PARM                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_OBSERVATION_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_OBSERVATION_PARM,
      *PX_COMP_OBSERVATION_PARM,
      **PPX_COMP_OBSERVATION_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_OBSERVATION_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_OBSERVATION_PARM_FCC,
      *PX_COMP_OBSERVATION_PARM_FCC,
      **PPX_COMP_OBSERVATION_PARM_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_INVOKE_DISPATCH                                            */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_INVOKE                                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_INVOKE_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_INVOKE_DISPATCH,
      *PX_COMP_INVOKE_DISPATCH,
      **PPX_COMP_INVOKE_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_INVOKE_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_INVOKE_DISPATCH_FCC,
      *PX_COMP_INVOKE_DISPATCH_FCC,
      **PPX_COMP_INVOKE_DISPATCH_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_INVOKE_OPERATION                                           */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_INVOKE_OPERATION                            */
/*       X_COMP_KIND_DEF_INVOKE_ROUTINE_OPERATION                    */
/*       X_COMP_KIND_DEF_CALL_METHOD_OPERATION                       */
/*       X_COMP_KIND_DEF_CALL_ROUTINE_OPERATION                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_INVOKE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      X_COMP_DISPATCH_ID                  ulMethod;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_INVOKE_OPERATION,
      *PX_COMP_INVOKE_OPERATION,
      **PPX_COMP_INVOKE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_INVOKE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      X_COMP_DISPATCH_ID                  ulMethod;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_INVOKE_OPERATION_FCC,
      *PX_COMP_INVOKE_OPERATION_FCC,
      **PPX_COMP_INVOKE_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_INVOKE_PARM                                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_INVOKE_PARM                                 */
/*       X_COMP_KIND_DEF_INVOKE_ROUTINE_PARM                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_INVOKE_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulMethodParm;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_INVOKE_PARM,
      *PX_COMP_INVOKE_PARM,
      **PPX_COMP_INVOKE_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_INVOKE_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulMethodParm;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_INVOKE_PARM_FCC,
      *PX_COMP_INVOKE_PARM_FCC,
      **PPX_COMP_INVOKE_PARM_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_VARIANT_INVOKE_OPERATION                                   */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_VARIANT_INVOKE_OPERATION                    */
/*       X_COMP_KIND_DEF_VARIANT_CALL_METHOD_OPERATION               */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_VARIANT_INVOKE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      const unsigned char              *  pvchMethodName;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_VARIANT_INVOKE_OPERATION,
      *PX_COMP_VARIANT_INVOKE_OPERATION,
      **PPX_COMP_VARIANT_INVOKE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_VARIANT_INVOKE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      const unsigned char              *  pvchMethodName;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_VARIANT_INVOKE_OPERATION_FCC,
      *PX_COMP_VARIANT_INVOKE_OPERATION_FCC,
      **PPX_COMP_VARIANT_INVOKE_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_CONSTRUCTOR_OPERATION                                      */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_INVOKE_CONSTRUCTOR_OPERATION                */
/*       X_COMP_KIND_DEF_INVOKE_CONSTRUCTOR_OPERATION_1              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_CONSTRUCTOR_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;

      /* VERSION_TAG 1 */
      X_COMP_DISPATCH_ID                  ulConstructor;
   }
      X_COMP_CONSTRUCTOR_OPERATION,
      *PX_COMP_CONSTRUCTOR_OPERATION,
      **PPX_COMP_CONSTRUCTOR_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_CONSTRUCTOR_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulType;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      X_COMP_DISPATCH_ID                  ulConstructor;
   }
      X_COMP_CONSTRUCTOR_OPERATION_FCC,
      *PX_COMP_CONSTRUCTOR_OPERATION_FCC,
      **PPX_COMP_CONSTRUCTOR_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_NEW_OPERATION                                              */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_INVOKE_NEW_OPERATION                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_NEW_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulConstructor;
      X_COMP_DISPATCH_ID                  ulClass;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_NEW_OPERATION,
      *PX_COMP_NEW_OPERATION,
      **PPX_COMP_NEW_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_NEW_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulConstructor;
      X_COMP_DISPATCH_ID                  ulClass;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_NEW_OPERATION_FCC,
      *PX_COMP_NEW_OPERATION_FCC,
      **PPX_COMP_NEW_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_GET_DISPATCH                                               */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_GET                                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_GET_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  idReference;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      X_COMP_DISPATCH_ID                  idRecordGetOperation;
   }
      X_COMP_GET_DISPATCH,
      *PX_COMP_GET_DISPATCH,
      **PPX_COMP_GET_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_GET_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  idReference;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      X_COMP_DISPATCH_ID                  idRecordGetOperation;
   }
      X_COMP_GET_DISPATCH_FCC,
      *PX_COMP_GET_DISPATCH_FCC,
      **PPX_COMP_GET_DISPATCH_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_SET_DISPATCH                                               */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_SET                                         */
/*       X_COMP_KIND_DEF_ASSIGN                                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SET_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_SET_DISPATCH,
      *PX_COMP_SET_DISPATCH,
      **PPX_COMP_SET_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SET_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_SET_DISPATCH_FCC,
      *PX_COMP_SET_DISPATCH_FCC,
      **PPX_COMP_SET_DISPATCH_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_SET_OPERATION                                              */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_SET_OPERATION                               */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SET_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idReference;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
   }
      X_COMP_SET_OPERATION,
      *PX_COMP_SET_OPERATION,
      **PPX_COMP_SET_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SET_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idReference;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
   }
      X_COMP_SET_OPERATION_FCC,
      *PX_COMP_SET_OPERATION_FCC,
      **PPX_COMP_SET_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_SET_RECORD_OPERATION                                       */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_SET_RECORD_OPERATION                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SET_RECORD_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idReference;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      X_COMP_DISPATCH_ID                  idRecordSetOperation;
   }
      X_COMP_SET_RECORD_OPERATION,
      *PX_COMP_SET_RECORD_OPERATION,
      **PPX_COMP_SET_RECORD_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SET_RECORD_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idReference;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      X_COMP_DISPATCH_ID                  idRecordSetOperation;
   }
      X_COMP_SET_RECORD_OPERATION_FCC,
      *PX_COMP_SET_RECORD_OPERATION_FCC,
      **PPX_COMP_SET_RECORD_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_SET_PARM                                                   */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_GET_PARM                                    */
/*       X_COMP_KIND_DEF_SET_PARM                                    */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SELECTOR_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulProperty;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_SELECTOR_PARM,
      *PX_COMP_SELECTOR_PARM,
      **PPX_COMP_SELECTOR_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SELECTOR_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulProperty;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_SELECTOR_PARM_FCC,
      *PX_COMP_SELECTOR_PARM_FCC,
      **PPX_COMP_SELECTOR_PARM_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_KEYED_SET_PARM                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_KEYED_GET_PARM                              */
/*       X_COMP_KIND_DEF_KEYED_SET_PARM                              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_KEYED_SELECTOR_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulProperty;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_KEYED_SELECTOR_PARM,
      *PX_COMP_KEYED_SELECTOR_PARM,
      **PPX_COMP_KEYED_SELECTOR_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_KEYED_SELECTOR_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulProperty;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_KEYED_SELECTOR_PARM_FCC,
      *PX_COMP_KEYED_SELECTOR_PARM_FCC,
      **PPX_COMP_KEYED_SELECTOR_PARM_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_CLASS_ATTRIBUTE_PARM                                       */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_CLASS_ATTRIBUTE_PARM                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_CLASS_ATTRIBUTE_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulAttributeIdentifier;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_CLASS_ATTRIBUTE_PARM,
      *PX_COMP_CLASS_ATTRIBUTE_PARM,
      **PPX_COMP_CLASS_ATTRIBUTE_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_CLASS_ATTRIBUTE_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulAttributeIdentifier;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_CLASS_ATTRIBUTE_PARM_FCC,
      *PX_COMP_CLASS_ATTRIBUTE_PARM_FCC,
      **PPX_COMP_CLASS_ATTRIBUTE_PARM_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_VARIANT_POSITIONAL_PARM                                    */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_VARIANT_POSITIONAL_INVOKE_PARM              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_VARIANT_POSITIONAL_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_VARIANT_POSITIONAL_PARM,
      *PX_COMP_VARIANT_POSITIONAL_PARM,
      **PPX_COMP_VARIANT_POSITIONAL_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_VARIANT_POSITIONAL_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_VARIANT_POSITIONAL_PARM_FCC,
      *PX_COMP_VARIANT_POSITIONAL_PARM_FCC,
      **PPX_COMP_VARIANT_POSITIONAL_PARM_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_NAMED_FEATURE_PARM                                         */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_VARIANT_SET_PARM                            */
/*       X_COMP_KIND_DEF_VARIANT_INVOKE_PARM                         */
/*       X_COMP_KIND_DEF_INVOKE_CONSTRUCTOR_PARM                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_NAMED_FEATURE_PARM
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchFeatureName;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_NAMED_FEATURE_PARM,
      *PX_COMP_NAMED_FEATURE_PARM,
      **PPX_COMP_NAMED_FEATURE_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_NAMED_FEATURE_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchFeatureName;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_NAMED_FEATURE_PARM_FCC,
      *PX_COMP_NAMED_FEATURE_PARM_FCC,
      **PPX_COMP_NAMED_FEATURE_PARM_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_KEYED_VARIANT_SET_PARM                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_KEYED_VARIANT_GET_PARM                      */
/*       X_COMP_KIND_DEF_KEYED_VARIANT_SET_PARM                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_KEYED_VARIANT_SELECTOR_PARM
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPropertyName;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_KEYED_VARIANT_SELECTOR_PARM,
      *PX_COMP_KEYED_VARIANT_SELECTOR_PARM,
      **PPX_COMP_KEYED_VARIANT_SELECTOR_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_KEYED_VARIANT_SELECTOR_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchPropertyName;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_KEYED_VARIANT_SELECTOR_PARM_FCC,
      *PX_COMP_KEYED_VARIANT_SELECTOR_PARM_FCC,
      **PPX_COMP_KEYED_VARIANT_SELECTOR_PARM_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_PERFORM_DISPATCH                                           */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_PERFORM                                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PERFORM_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  ulPerformExpression;
   }
      X_COMP_PERFORM_DISPATCH,
      *PX_COMP_PERFORM_DISPATCH,
      **PPX_COMP_PERFORM_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PERFORM_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_COMP_DISPATCH_ID                  ulPerformExpression;
   }
      X_COMP_PERFORM_DISPATCH_FCC,
      *PX_COMP_PERFORM_DISPATCH_FCC,
      **PPX_COMP_PERFORM_DISPATCH_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_SIGNAL_DISPATCH                                            */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_SIGNAL                                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SIGNAL_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_SIGNAL_DISPATCH,
      *PX_COMP_SIGNAL_DISPATCH,
      **PPX_COMP_SIGNAL_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SIGNAL_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulOperationEntries;
      X_DEFS_DISPATCH_ID_TABLE            pOperationTable;
   }
      X_COMP_SIGNAL_DISPATCH_FCC,
      *PX_COMP_SIGNAL_DISPATCH_FCC,
      **PPX_COMP_SIGNAL_DISPATCH_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_SIGNAL_OPERATION                                           */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_SIGNAL_OPERATION                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SIGNAL_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      X_COMP_DISPATCH_ID                  ulEvent;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_SIGNAL_OPERATION,
      *PX_COMP_SIGNAL_OPERATION,
      **PPX_COMP_SIGNAL_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SIGNAL_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      X_COMP_DISPATCH_ID                  ulEvent;
      unsigned long                       ulParameterEntries;
      X_DEFS_DISPATCH_ID_TABLE            pParameterTable;
   }
      X_COMP_SIGNAL_OPERATION_FCC,
      *PX_COMP_SIGNAL_OPERATION_FCC,
      **PPX_COMP_SIGNAL_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_SIGNAL_PARM                                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_SIGNAL_PARM                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SIGNAL_PARM
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEventParm;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_SIGNAL_PARM,
      *PX_COMP_SIGNAL_PARM,
      **PPX_COMP_SIGNAL_PARM;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SIGNAL_PARM_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEventParm;
      X_COMP_DISPATCH_ID                  ulValue;
   }
      X_COMP_SIGNAL_PARM_FCC,
      *PX_COMP_SIGNAL_PARM_FCC,
      **PPX_COMP_SIGNAL_PARM_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_SET_REF_DISPATCH                                           */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_SET_REF_OPEN                                */
/*       X_COMP_KIND_DEF_SET_REF_DYNAMIC                             */
/*       X_COMP_KIND_DEF_SET_REF_TO_NULL                             */
/*       X_COMP_KIND_DEF_SET_REF_CREATE_AS                           */
/*       X_COMP_KIND_DEF_SET_REF_TO_VARIABLE                         */
/*       X_COMP_KIND_DEF_SET_REF_CREATE_FROM                         */
/*                                                                   */
/*    Version 1 Supports:                                            */
/*       X_COMP_KIND_DEF_SET_REF_OPEN_1                              */
/*       X_COMP_KIND_DEF_SET_REF_DYNAMIC_1                           */
/*       X_COMP_KIND_DEF_SET_REF_TO_NULL_1                           */
/*       X_COMP_KIND_DEF_SET_REF_CREATE_AS_1                         */
/*       X_COMP_KIND_DEF_SET_REF_TO_VARIABLE_1                       */
/*       X_COMP_KIND_DEF_SET_REF_CREATE_FROM_1                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SET_REF_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  ulSource;
      unsigned long                       ulVariableEntries;
      X_DEFS_DISPATCH_ID_TABLE            pVariableTable;

      /* VERSION_TAG 1 */
      unsigned long                       ulOperationFlags;
   }
      X_COMP_SET_REF_DISPATCH,
      *PX_COMP_SET_REF_DISPATCH,
      **PPX_COMP_SET_REF_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_SET_REF_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  ulSource;
      unsigned long                       ulVariableEntries;
      X_DEFS_DISPATCH_ID_TABLE            pVariableTable;

      /* VERSION_TAG 1 */
      unsigned long                       ulOperationFlags;
   }
      X_COMP_SET_REF_DISPATCH_FCC,
      *PX_COMP_SET_REF_DISPATCH_FCC,
      **PPX_COMP_SET_REF_DISPATCH_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_IF_REF_DISPATCH                                            */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_IF_REF                                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_IF_REF_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      unsigned long                       ulConditionEntries;
      X_DEFS_DISPATCH_ID_TABLE            pConditionTable;
      unsigned long                       ulVariableEntries;
      X_DEFS_DISPATCH_ID_TABLE            pVariableTable;
   }
      X_COMP_IF_REF_DISPATCH,
      *PX_COMP_IF_REF_DISPATCH,
      **PPX_COMP_IF_REF_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_IF_REF_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulConditionEntries;
      X_DEFS_DISPATCH_ID_TABLE            pConditionTable;
      unsigned long                       ulVariableEntries;
      X_DEFS_DISPATCH_ID_TABLE            pVariableTable;
   }
      X_COMP_IF_REF_DISPATCH_FCC,
      *PX_COMP_IF_REF_DISPATCH_FCC,
      **PPX_COMP_IF_REF_DISPATCH_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_IF_REF_CONDITION                                           */
/*                                                                   */
/*   Supports:                                                       */
/*                                                                   */
/*       X_COMP_KIND_DEF_IF_REF_IS_NULL                              */
/*       X_COMP_KIND_DEF_IF_REF_IS_KIND_OF                           */
/*       X_COMP_KIND_DEF_IF_REF_IS_INSTANCE_OF                       */
/*       X_COMP_KIND_DEF_IF_REF_IS_EQUAL_TO_VARIABLE                 */
/*                                                                   */
/*       X_COMP_KIND_DEF_IF_REF_IS_NOT_NULL                          */
/*       X_COMP_KIND_DEF_IF_REF_IS_NOT_KIND_OF                       */
/*       X_COMP_KIND_DEF_IF_REF_IS_NOT_INSTANCE_OF                   */
/*       X_COMP_KIND_DEF_IF_REF_IS_NOT_EQUAL_TO_VARIABLE             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_IF_REF_CONDITION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulSource;
   }
      X_COMP_IF_REF_CONDITION,
      *PX_COMP_IF_REF_CONDITION,
      **PPX_COMP_IF_REF_CONDITION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_IF_REF_CONDITION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulSource;
   }
      X_COMP_IF_REF_CONDITION_FCC,
      *PX_COMP_IF_REF_CONDITION_FCC,
      **PPX_COMP_IF_REF_CONDITION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_FOR_DISPATCH                                               */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_FOR                                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_FOR_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      X_COMP_FOR_OPERATION_KIND           ulOperation;
      const unsigned long                 ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  ulIterator;
      X_COMP_DISPATCH_ID                  ulVariableType;
      const unsigned char              *  pvchForVariableName;
      const unsigned char              *  pvchKeyVariableName;
   }
      X_COMP_FOR_DISPATCH,
      *PX_COMP_FOR_DISPATCH,
      **PPX_COMP_FOR_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_FOR_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_FOR_OPERATION_KIND           ulOperation;
      unsigned long                       ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  ulIterator;
      X_COMP_DISPATCH_ID                  ulVariableType;
      const unsigned char              *  pvchForVariableName;
      const unsigned char              *  pvchKeyVariableName;
   }
      X_COMP_FOR_DISPATCH_FCC,
      *PX_COMP_FOR_DISPATCH_FCC,
      **PPX_COMP_FOR_DISPATCH_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_ITERATOR_DISPATCH                                          */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_ITERATOR                                    */
/*       X_COMP_KIND_DEF_ENUMERATOR                                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_ITERATOR_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      X_COMP_DISPATCH_ID                  ulCreateIteratorOperation;
      X_COMP_DISPATCH_ID                  ulMoveNextOperation;
      X_COMP_DISPATCH_ID                  ulCurrentOperation;
      X_COMP_DISPATCH_ID                  ulCurrentKeyOperation;
   }
      X_COMP_ITERATOR_DISPATCH,
      *PX_COMP_ITERATOR_DISPATCH,
      **PPX_COMP_ITERATOR_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_ITERATOR_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      X_COMP_DISPATCH_ID                  ulCreateIteratorOperation;
      X_COMP_DISPATCH_ID                  ulMoveNextOperation;
      X_COMP_DISPATCH_ID                  ulCurrentOperation;
      X_COMP_DISPATCH_ID                  ulCurrentKeyOperation;
   }
      X_COMP_ITERATOR_DISPATCH_FCC,
      *PX_COMP_ITERATOR_DISPATCH_FCC,
      **PPX_COMP_ITERATOR_DISPATCH_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_COLLECTION_ACCESSOR_DISPATCH                               */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_COLLECTION_ACCESSOR                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_COLLECTION_ACCESSOR_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      X_COMP_DISPATCH_ID                  ulCreateAccessorOperation;
   }
      X_COMP_COLLECTION_ACCESSOR_DISPATCH,
      *PX_COMP_COLLECTION_ACCESSOR_DISPATCH,
      **PPX_COMP_COLLECTION_ACCESSOR_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_COLLECTION_ACCESSOR_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      X_COMP_DISPATCH_ID                  ulCreateAccessorOperation;
   }
      X_COMP_COLLECTION_ACCESSOR_DISPATCH_FCC,
      *PX_COMP_COLLECTION_ACCESSOR_DISPATCH_FCC,
      **PPX_COMP_COLLECTION_ACCESSOR_DISPATCH_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_WEB_EXEC_DISPATCH                                          */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_WEB_EXEC                                    */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_WEB_EXEC_DISPATCH
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      const unsigned long                 ulFlags;
      X_COMP_DISPATCH_ID                  ulIdentifier;
   }
      X_COMP_WEB_EXEC_DISPATCH,
      *PX_COMP_WEB_EXEC_DISPATCH,
      **PPX_COMP_WEB_EXEC_DISPATCH;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_WEB_EXEC_DISPATCH_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      unsigned long                       ulFlags;
      X_COMP_DISPATCH_ID                  ulIdentifier;
   }
      X_COMP_WEB_EXEC_DISPATCH_FCC,
      *PX_COMP_WEB_EXEC_DISPATCH_FCC,
      **PPX_COMP_WEB_EXEC_DISPATCH_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_BOM_DISPATCH_COMMAND                                       */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_DEF_BOM_COMMAND_CLR_LIST                        */
/*       X_COMP_KIND_DEF_BOM_COMMAND_ADD_ENTRY                       */
/*       X_COMP_KIND_DEF_BOM_COMMAND_DLT_ENTRY                       */
/*       X_COMP_KIND_DEF_BOM_COMMAND_GET_ENTRY                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_BOM_DISPATCH_COMMAND
   {
      X_COMP_KIND                         ulKind;
      const unsigned long                 ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  idReference;
      X_COMP_DISPATCH_ID                  idCollectionType;
      X_COMP_DISPATCH_ID                  idDispatchRecord;
   }
      X_COMP_BOM_DISPATCH_COMMAND,
      *PX_COMP_BOM_DISPATCH_COMMAND,
      **PPX_COMP_BOM_DISPATCH_COMMAND;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_BOM_DISPATCH_COMMAND_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulRDMLXLineNumber;
      X_COMP_DISPATCH_ID                  idReference;
      X_COMP_DISPATCH_ID                  idCollectionType;
      X_COMP_DISPATCH_ID                  idDispatchRecord;
   }
      X_COMP_BOM_DISPATCH_COMMAND_FCC,
      *PX_COMP_BOM_DISPATCH_COMMAND_FCC,
      **PPX_COMP_BOM_DISPATCH_COMMAND_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_PATTERN_REF                                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_PATTERN                                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PATTERN_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
   }
      X_COMP_PATTERN_REF,
      *PX_COMP_PATTERN_REF,
      **PPX_COMP_PATTERN_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_PATTERN_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
   }
      X_COMP_PATTERN_REF_FCC,
      *PX_COMP_PATTERN_REF_FCC,
      **PPX_COMP_PATTERN_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_CLASS_REF                                                  */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_REF_CLASS                                       */
/*       X_COMP_KIND_REF_LIBRARY                                     */
/*       X_COMP_KIND_REF_NAMESPACE                                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_CLASS_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
   }
      X_COMP_CLASS_REF,
      *PX_COMP_CLASS_REF,
      **PPX_COMP_CLASS_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_CLASS_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
   }
      X_COMP_CLASS_REF_FCC,
      *PX_COMP_CLASS_REF_FCC,
      **PPX_COMP_CLASS_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_VARIANT_DATA_TYPE_REF                                      */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_REF_VARIANT_DATA_TYPE                           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_VARIANT_DATA_TYPE_REF
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_VARIANT_DATA_TYPE_REF,
      *PX_COMP_VARIANT_DATA_TYPE_REF,
      **PPX_COMP_VARIANT_DATA_TYPE_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_VARIANT_DATA_TYPE_REF_FCC
   {
      X_COMP_KIND                         ulKind;
   }
      X_COMP_VARIANT_DATA_TYPE_REF_FCC,
      *PX_COMP_VARIANT_DATA_TYPE_REF_FCC,
      **PPX_COMP_VARIANT_DATA_TYPE_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_PARAMETERIZED_TYPE_REF                                     */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_REF_PARAMETERIZED_TYPE                          */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PARAMETERIZED_TYPE_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulGenericType;
      unsigned long                       ulQualifyingTypeEntries;
      X_DEFS_DISPATCH_ID_TABLE            pQualifyingTypeTable;
   }
      X_COMP_PARAMETERIZED_TYPE_REF,
      *PX_COMP_PARAMETERIZED_TYPE_REF,
      **PPX_COMP_PARAMETERIZED_TYPE_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_PARAMETERIZED_TYPE_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulGenericType;
      unsigned long                       ulQualifyingTypeEntries;
      X_DEFS_DISPATCH_ID_TABLE            pQualifyingTypeTable;
   }
      X_COMP_PARAMETERIZED_TYPE_REF_FCC,
      *PX_COMP_PARAMETERIZED_TYPE_REF_FCC,
      **PPX_COMP_PARAMETERIZED_TYPE_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_SINGLE_PARAMETERIZED_TYPE_REF                              */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_REF_SINGLE_PARAMETERIZED_TYPE                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_SINGLE_PARAMETERIZED_TYPE_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulGenericType;
      X_COMP_DISPATCH_ID                  ulQualifyingType;
   }
      X_COMP_SINGLE_PARAMETERIZED_TYPE_REF,
      *PX_COMP_SINGLE_PARAMETERIZED_TYPE_REF,
      **PPX_COMP_SINGLE_PARAMETERIZED_TYPE_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_COMP_SINGLE_PARAMETERIZED_TYPE_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulGenericType;
      X_COMP_DISPATCH_ID                  ulQualifyingType;
   }
      X_COMP_SINGLE_PARAMETERIZED_TYPE_REF_FCC,
      *PX_COMP_SINGLE_PARAMETERIZED_TYPE_REF_FCC,
      **PPX_COMP_SINGLE_PARAMETERIZED_TYPE_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_EVENT_REF                                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_EVENT                                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EVENT_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_EVENT_REF,
      *PX_COMP_EVENT_REF,
      **PPX_COMP_EVENT_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_EVENT_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_EVENT_REF_FCC,
      *PX_COMP_EVENT_REF_FCC,
      **PPX_COMP_EVENT_REF_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_METHOD_REF                                                 */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_METHOD                                      */
/*       X_COMP_KIND_REF_ROUTINE                                     */
/*       X_COMP_KIND_REF_CONSTRUCTOR                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_METHOD_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_METHOD_REF,
      *PX_COMP_METHOD_REF,
      **PPX_COMP_METHOD_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_METHOD_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_METHOD_REF_FCC,
      *PX_COMP_METHOD_REF_FCC,
      **PPX_COMP_METHOD_REF_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_PROPERTY_REF                                               */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_PROPERTY                                    */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PROPERTY_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_PROPERTY_REF,
      *PX_COMP_PROPERTY_REF,
      **PPX_COMP_PROPERTY_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PROPERTY_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_PROPERTY_REF_FCC,
      *PX_COMP_PROPERTY_REF_FCC,
      **PPX_COMP_PROPERTY_REF_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_WEB_REF                                                    */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_WEB                                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_WEB_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_WEB_REF,
      *PX_COMP_WEB_REF,
      **PPX_COMP_WEB_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_WEB_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_WEB_REF_FCC,
      *PX_COMP_WEB_REF_FCC,
      **PPX_COMP_WEB_REF_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_PARAMETER_REF                                              */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_EVENT_PARM                                  */
/*       X_COMP_KIND_REF_METHOD_PARM                                 */
/*       X_COMP_KIND_REF_ROUTINE_MAP                                 */
/*       X_COMP_KIND_REF_CONSTRUCTOR_PARM                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PARAMETER_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulFeature;
      const unsigned char              *  pvchName;
   }
      X_COMP_PARAMETER_REF,
      *PX_COMP_PARAMETER_REF,
      **PPX_COMP_PARAMETER_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PARAMETER_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulFeature;
      const unsigned char              *  pvchName;
   }
      X_COMP_PARAMETER_REF_FCC,
      *PX_COMP_PARAMETER_REF_FCC,
      **PPX_COMP_PARAMETER_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_REFERENCE_REF                                              */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_STATIC_SHARED_REF                           */
/*       X_COMP_KIND_REF_STATIC_INSTANCE_REF                         */
/*       X_COMP_KIND_REF_STATIC_LOCAL_REF                            */
/*                                                                   */
/*       X_COMP_KIND_REF_DEFERRED_SHARED_REF                         */
/*       X_COMP_KIND_REF_DEFERRED_INSTANCE_REF                       */
/*       X_COMP_KIND_REF_DEFERRED_LOCAL_REF                          */
/*                                                                   */
/*       X_COMP_KIND_REF_DYNAMIC_SHARED_REF                          */
/*       X_COMP_KIND_REF_DYNAMIC_INSTANCE_REF                        */
/*       X_COMP_KIND_REF_DYNAMIC_LOCAL_REF                           */
/*                                                                   */
/*       X_COMP_KIND_REF_SELF_COMPONENT                              */
/*       X_COMP_KIND_REF_OWNER_COMPONENT                             */
/*       X_COMP_KIND_REF_ANCESTOR_COMPONENT                          */
/*                                                                   */
/*       X_COMP_KIND_REF_STATIC_COMPONENT                            */
/*                                                                   */
/*       X_COMP_KIND_REF_COM_SENDER                                  */
/*       X_COMP_KIND_REF_FOR_VARIABLE                                */
/*       X_COMP_KIND_REF_FOR_KEY_VARIABLE                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_REFERENCE_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulFeature;
   }
      X_COMP_REFERENCE_REF,
      *PX_COMP_REFERENCE_REF,
      **PPX_COMP_REFERENCE_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_REFERENCE_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulFeature;
   }
      X_COMP_REFERENCE_REF_FCC,
      *PX_COMP_REFERENCE_REF_FCC,
      **PPX_COMP_REFERENCE_REF_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_ANCESTOR_REFERENCE_REF                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_ANCESTOR_SHARED_REF                         */
/*       X_COMP_KIND_REF_ANCESTOR_INSTANCE_REF                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_ANCESTOR_REFERENCE_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_ANCESTOR_REFERENCE_REF,
      *PX_COMP_ANCESTOR_REFERENCE_REF,
      **PPX_COMP_ANCESTOR_REFERENCE_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_ANCESTOR_REFERENCE_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulClass;
      const unsigned char              *  pvchName;
   }
      X_COMP_ANCESTOR_REFERENCE_REF_FCC,
      *PX_COMP_ANCESTOR_REFERENCE_REF_FCC,
      **PPX_COMP_ANCESTOR_REFERENCE_REF_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_ROUTINE_MAP_REF                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_REF_EVT_ROUTINE_MAP                             */
/*       X_COMP_KIND_REF_MTH_ROUTINE_MAP                             */
/*       X_COMP_KIND_REF_PTY_ROUTINE_MAP                             */
/*       X_COMP_KIND_REF_CON_ROUTINE_MAP                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_ROUTINE_MAP_REF
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_ROUTINE_MAP_REF,
      *PX_COMP_ROUTINE_MAP_REF,
      **PPX_COMP_ROUTINE_MAP_REF;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_ROUTINE_MAP_REF_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_ROUTINE_MAP_REF_FCC,
      *PX_COMP_ROUTINE_MAP_REF_FCC,
      **PPX_COMP_ROUTINE_MAP_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_PTY_OPERATION                                              */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_PTY_OPERATION                               */
/*       X_COMP_KIND_DEF_BOUND_FEATURE_OPERATION                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PTY_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulProperty;
      X_COMP_DISPATCH_ID                  ulQualifier;
   }
      X_COMP_PTY_OPERATION,
      *PX_COMP_PTY_OPERATION,
      **PPX_COMP_PTY_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PTY_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulProperty;
      X_COMP_DISPATCH_ID                  ulQualifier;
   }
      X_COMP_PTY_OPERATION_FCC,
      *PX_COMP_PTY_OPERATION_FCC,
      **PPX_COMP_PTY_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DEFAULT_PTY_OPERATION                                      */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_DEFAULT_PTY_OPERATION                       */
/*       X_COMP_KIND_DEF_VARIANT_VARIABLE_OPERATION                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DEFAULT_PTY_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
   }
      X_COMP_DEFAULT_PTY_OPERATION,
      *PX_COMP_DEFAULT_PTY_OPERATION,
      **PPX_COMP_DEFAULT_PTY_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_DEFAULT_PTY_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
   }
      X_COMP_DEFAULT_PTY_OPERATION_FCC,
      *PX_COMP_DEFAULT_PTY_OPERATION_FCC,
      **PPX_COMP_DEFAULT_PTY_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_KEYED_PTY_OPERATION                                        */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_KEYED_PTY_OPERATION                         */
/*       X_COMP_KIND_DEF_DEFAULT_KEYED_PTY_OPERATION                 */
/*       X_COMP_KIND_DEF_KEYED_VARIANT_OF_PTY_OPERATION              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_KEYED_PTY_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      X_COMP_DISPATCH_ID                  ulProperty;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_KEYED_PTY_OPERATION,
      *PX_COMP_KEYED_PTY_OPERATION,
      **PPX_COMP_KEYED_PTY_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_KEYED_PTY_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      X_COMP_DISPATCH_ID                  ulProperty;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_KEYED_PTY_OPERATION_FCC,
      *PX_COMP_KEYED_PTY_OPERATION_FCC,
      **PPX_COMP_KEYED_PTY_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_KEYED_DEFAULT_PTY_OPERATION                                */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_KEYED_DEFAULT_PTY_OPERATION                 */
/*       X_COMP_KIND_DEF_DEFAULT_KEYED_DEFAULT_PTY_OPERATION         */
/*                                                                   */
/*       X_COMP_KIND_DEF_KEYED_ROUTINE_CALL_OPERATION                */
/*                                                                   */
/*       X_COMP_KIND_DEF_KEYED_VARIANT_OF_DEFAULT_PTY_OPERATION      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_KEYED_DEFAULT_PTY_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_KEYED_DEFAULT_PTY_OPERATION,
      *PX_COMP_KEYED_DEFAULT_PTY_OPERATION,
      **PPX_COMP_KEYED_DEFAULT_PTY_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_KEYED_DEFAULT_PTY_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_KEYED_DEFAULT_PTY_OPERATION_FCC,
      *PX_COMP_KEYED_DEFAULT_PTY_OPERATION_FCC,
      **PPX_COMP_KEYED_DEFAULT_PTY_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_VARIANT_PTY_OPERATION                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_VARIANT_PROPERTY_OPERATION                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_VARIANT_PTY_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      const unsigned char              *  pvchPropertyName;
   }
      X_COMP_VARIANT_PTY_OPERATION,
      *PX_COMP_VARIANT_PTY_OPERATION,
      **PPX_COMP_VARIANT_PTY_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_VARIANT_PTY_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      const unsigned char              *  pvchPropertyName;
   }
      X_COMP_VARIANT_PTY_OPERATION_FCC,
      *PX_COMP_VARIANT_PTY_OPERATION_FCC,
      **PPX_COMP_VARIANT_PTY_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_VARIANT_KEYED_PTY_OPERATION                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_KEYED_VARIANT_PROPERTY_OPERATION            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_VARIANT_KEYED_PTY_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      const unsigned char              *  pvchPropertyName;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_VARIANT_KEYED_PTY_OPERATION,
      *PX_COMP_VARIANT_KEYED_PTY_OPERATION,
      **PPX_COMP_VARIANT_KEYED_PTY_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_VARIANT_KEYED_PTY_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulQualifier;
      const unsigned char              *  pvchPropertyName;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_VARIANT_KEYED_PTY_OPERATION_FCC,
      *PX_COMP_VARIANT_KEYED_PTY_OPERATION_FCC,
      **PPX_COMP_VARIANT_KEYED_PTY_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_PTY_ROUTINE_OPERATION                                      */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_PTY_ROUTINE_OPERATION                       */
/*       X_COMP_KIND_DEF_PTY_ROUTINE_OPERATION_1                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_PTY_ROUTINE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulRoutine;
   }
      X_COMP_PTY_ROUTINE_OPERATION,
      *PX_COMP_PTY_ROUTINE_OPERATION,
      **PPX_COMP_PTY_ROUTINE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_PTY_ROUTINE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulRoutine;
   }
      X_COMP_PTY_ROUTINE_OPERATION_FCC,
      *PX_COMP_PTY_ROUTINE_OPERATION_FCC,
      **PPX_COMP_PTY_ROUTINE_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_KEYED_OPERATION                                            */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_KEYED_OPERATION                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_KEYED_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_KEYED_OPERATION,
      *PX_COMP_KEYED_OPERATION,
      **PPX_COMP_KEYED_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_KEYED_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      unsigned long                       ulKeyEntries;
      X_DEFS_DISPATCH_ID_TABLE            pKeyTable;
   }
      X_COMP_KEYED_OPERATION_FCC,
      *PX_COMP_KEYED_OPERATION_FCC,
      **PPX_COMP_KEYED_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_UNKEYED_OPERATION                                          */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_UNKEYED_OPERATION                           */
/*       X_COMP_KIND_DEF_UNKEYED_OPERATION_1                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_UNKEYED_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
   }
      X_COMP_UNKEYED_OPERATION,
      *PX_COMP_UNKEYED_OPERATION,
      **PPX_COMP_UNKEYED_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_UNKEYED_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
   }
      X_COMP_UNKEYED_OPERATION_FCC,
      *PX_COMP_UNKEYED_OPERATION_FCC,
      **PPX_COMP_UNKEYED_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_REFERENCE_OPERATION                                        */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_LIST_OPERATION                              */
/*       X_COMP_KIND_DEF_LIST_COLUMN_OPERATION                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_REFERENCE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      unsigned long                       ulOperationIndex;
      long                                lListNumber;
   }
      X_COMP_REFERENCE_OPERATION,
      *PX_COMP_REFERENCE_OPERATION,
      **PPX_COMP_REFERENCE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_REFERENCE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulReference;
      unsigned long                       ulOperationIndex;
      X_COMP_DISPATCH_ID                  ulComponentListDispatchId;
   }
      X_COMP_REFERENCE_OPERATION_FCC,
      *PX_COMP_REFERENCE_OPERATION_FCC,
      **PPX_COMP_REFERENCE_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_UDC_REFERENCE_OPERATION                                    */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_DEF_UDC_LIST_OPERATION                          */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_UDC_REFERENCE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idReference;
      X_COMP_DISPATCH_ID                  idCollectionType;
      X_COMP_DISPATCH_ID                  idDispatchRecord;
      unsigned long                       ulOperationIndex;
   }
      X_COMP_UDC_REFERENCE_OPERATION,
      *PX_COMP_UDC_REFERENCE_OPERATION,
      **PPX_COMP_UDC_REFERENCE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_UDC_REFERENCE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idReference;
      X_COMP_DISPATCH_ID                  idCollectionType;
      X_COMP_DISPATCH_ID                  idDispatchRecord;
      unsigned long                       ulOperationIndex;
   }
      X_COMP_UDC_REFERENCE_OPERATION_FCC,
      *PX_COMP_UDC_REFERENCE_OPERATION_FCC,
      **PPX_COMP_UDC_REFERENCE_OPERATION_FCC;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_EXCHANGE_OPERATION                                         */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_DOUBLE_EXCHANGE                             */
/*       X_COMP_KIND_DEF_LONG_EXCHANGE                               */
/*       X_COMP_KIND_DEF_STRING_EXCHANGE                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EXCHANGE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulExchangeIdentifier;
   }
      X_COMP_EXCHANGE_OPERATION,
      *PX_COMP_EXCHANGE_OPERATION,
      **PPX_COMP_EXCHANGE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_EXCHANGE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulExchangeIdentifier;
   }
      X_COMP_EXCHANGE_OPERATION_FCC,
      *PX_COMP_EXCHANGE_OPERATION_FCC,
      **PPX_COMP_EXCHANGE_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_MODIFIED_FEATURE                                           */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_MODIFIED_FEATURE                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_MODIFIED_FEATURE
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  lModification;
      const unsigned char              *  pvchFeatureName;
   }
      X_COMP_MODIFIED_FEATURE,
      *PX_COMP_MODIFIED_FEATURE,
      **PPX_COMP_MODIFIED_FEATURE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_MODIFIED_FEATURE_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  lModification;
      const unsigned char              *  pvchFeatureName;
   }
      X_COMP_MODIFIED_FEATURE_FCC,
      *PX_COMP_MODIFIED_FEATURE_FCC,
      **PPX_COMP_MODIFIED_FEATURE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_STRING_LITERAL                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_STRING_LITERAL                              */
/*       X_COMP_KIND_DEF_DECIMAL_LITERAL                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_STRING_LITERAL
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchLiteral;
   }
      X_COMP_STRING_LITERAL,
      *PX_COMP_STRING_LITERAL,
      **PPX_COMP_STRING_LITERAL;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_STRING_LITERAL_FCC
   {
      X_COMP_KIND                         ulKind;
      const unsigned char              *  pvchLiteral;
   }
      X_COMP_STRING_LITERAL_FCC,
      *PX_COMP_STRING_LITERAL_FCC,
      **PPX_COMP_STRING_LITERAL_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_LONG_LITERAL                                               */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_LONG_LITERAL                                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_LONG_LITERAL
   {
      X_COMP_KIND                       ulKind;
      long                              lLiteral;
   }
      X_COMP_LONG_LITERAL,
      *PX_COMP_LONG_LITERAL,
      **PPX_COMP_LONG_LITERAL;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_LONG_LITERAL_FCC
   {
      X_COMP_KIND                       ulKind;
      long                              lLiteral;
   }
      X_COMP_LONG_LITERAL_FCC,
      *PX_COMP_LONG_LITERAL_FCC,
      **PPX_COMP_LONG_LITERAL_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DOUBLE_LITERAL                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_DOUBLE_LITERAL                              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DOUBLE_LITERAL
   {
      X_COMP_KIND                         ulKind;
      double                              dLiteral;
   }
      X_COMP_DOUBLE_LITERAL,
      *PX_COMP_DOUBLE_LITERAL,
      **PPX_COMP_DOUBLE_LITERAL;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_LITERAL_FCC
   {
      X_COMP_KIND                         ulKind;
      double                              dLiteral;
   }
      X_COMP_DOUBLE_LITERAL_FCC,
      *PX_COMP_DOUBLE_LITERAL_FCC,
      **PPX_COMP_DOUBLE_LITERAL_FCC;

#endif


/* ----------------------------------------------------------------- */
/* RJH? X_COMP_EVALUATION_OPERATION                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_EVALUATION_OPERATION                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EVALUATION_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEvaluation;
   }
      X_COMP_EVALUATION_OPERATION,
      *PX_COMP_EVALUATION_OPERATION,
      **PPX_COMP_EVALUATION_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_EVALUATION_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulEvaluation;
   }
      X_COMP_EVALUATION_OPERATION_FCC,
      *PX_COMP_EVALUATION_OPERATION_FCC,
      **PPX_COMP_EVALUATION_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_EXPRESSION_EVALUATION                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_EXPRESSION_EVALUATION                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_EXPRESSION_EVALUATION
   {
      X_COMP_KIND                         ulKind;
      FN_COMP_SERVICES_POINT           *  pfnServicesRunPoint;
   }
      X_COMP_EXPRESSION_EVALUATION,
      *PX_COMP_EXPRESSION_EVALUATION,
      **PPX_COMP_EXPRESSION_EVALUATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_EXPRESSION_EVALUATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulExpression;
   }
      X_COMP_EXPRESSION_EVALUATION_FCC,
      *PX_COMP_EXPRESSION_EVALUATION_FCC,
      **PPX_COMP_EXPRESSION_EVALUATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_UNARY_EVALUATION                                           */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_UNARY_EVALUATION                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_UNARY_EVALUATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_EVALUATION_KIND              ulEvaluationKind;
      X_COMP_DISPATCH_ID                  ulOperand;
   }
      X_COMP_UNARY_EVALUATION,
      *PX_COMP_UNARY_EVALUATION,
      **PPX_COMP_UNARY_EVALUATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_UNARY_EVALUATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_EVALUATION_KIND              ulEvaluationKind;
      X_COMP_DISPATCH_ID                  ulOperand;
   }
      X_COMP_UNARY_EVALUATION_FCC,
      *PX_COMP_UNARY_EVALUATION_FCC,
      **PPX_COMP_UNARY_EVALUATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_BINARY_EVALUATION                                          */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_BINARY_EVALUATION                           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_BINARY_EVALUATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_EVALUATION_KIND              ulEvaluationKind;
      X_COMP_DISPATCH_ID                  ulSubjectOperand;
      X_COMP_DISPATCH_ID                  ulObjectOperand;
   }
      X_COMP_BINARY_EVALUATION,
      *PX_COMP_BINARY_EVALUATION,
      **PPX_COMP_BINARY_EVALUATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_BINARY_EVALUATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_EVALUATION_KIND              ulEvaluationKind;
      X_COMP_DISPATCH_ID                  ulSubjectOperand;
      X_COMP_DISPATCH_ID                  ulObjectOperand;
   }
      X_COMP_BINARY_EVALUATION_FCC,
      *PX_COMP_BINARY_EVALUATION_FCC,
      **PPX_COMP_BINARY_EVALUATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_MODULE_FRAME                                               */
/*                                                                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_MODULE_FRAME
   {
      unsigned long                       ulKind;
      unsigned long                       ulFrameSize;
      X_DEFS_FLD_TABLE                    pX_Fld;
      X_DEFS_LIST_TABLE                   pX_List;
      void                             *  pGlobal1;
      void                             *  pGlobal2;
      struct X_FUN                     *  pX_Fun;
      void                             *  pDerivedFrame;
      void                             *  pCurScope;
      const X_COMP_DERIVED_MODULE      *  pTemplate;
   }
      X_COMP_MODULE_FRAME,
      *PX_COMP_MODULE_FRAME,
      **PPX_COMP_MODULE_FRAME;

#endif


/* ----------------------------------------------------------------- */
/* X_COMP_FIELD_SIMPLE_CLASS                                         */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_FIELD_VISUAL_CLASS                          */
/*       X_COMP_KIND_DEF_FIELD_PROMPTER_CLASS                        */
/*       X_COMP_KIND_DEF_FIELD_VISUAL_PART_CLASS                     */
/*       X_COMP_KIND_DEF_FIELD_VISUAL_HOST_CLASS                     */
/*       X_COMP_KIND_DEF_FIELD_DYNAMIC_PICKLIST_CLASS                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_FIELD_SIMPLE_CLASS
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
      X_COMP_DISPATCH_ID                  ulAssociatedRef;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulClassAttributeEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassAttributeTable;
   }
      X_COMP_FIELD_SIMPLE_CLASS,
      *PX_COMP_FIELD_SIMPLE_CLASS,
      **PPX_COMP_FIELD_SIMPLE_CLASS;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_FIELD_SIMPLE_CLASS_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
      X_COMP_DISPATCH_ID                  ulAssociatedRef;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulClassAttributeEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassAttributeTable;
   }
      X_COMP_FIELD_SIMPLE_CLASS_FCC,
      *PX_COMP_FIELD_SIMPLE_CLASS_FCC,
      **PPX_COMP_FIELD_SIMPLE_CLASS_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_FIELD_FEATURED_CLASS                                       */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_FIELD_PICKLIST_CLASS                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_FIELD_FEATURED_CLASS
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulClassAttributeEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassAttributeTable;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
   }
      X_COMP_FIELD_FEATURED_CLASS,
      *PX_COMP_FIELD_FEATURED_CLASS,
      **PPX_COMP_FIELD_FEATURED_CLASS;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_FIELD_FEATURED_CLASS_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulPattern;
      const unsigned char              *  pvchName;
      X_COMP_DISPATCH_ID                  ulAncestor;
      unsigned long                       ulSelectorEntries;
      X_DEFS_DISPATCH_ID_TABLE            pSelectorTable;
      unsigned long                       ulClassAttributeEntries;
      X_DEFS_DISPATCH_ID_TABLE            pClassAttributeTable;
      unsigned long                       ulFeatureEntries;
      X_DEFS_DISPATCH_ID_TABLE            pFeatureTable;
   }
      X_COMP_FIELD_FEATURED_CLASS_FCC,
      *PX_COMP_FIELD_FEATURED_CLASS_FCC,
      **PPX_COMP_FIELD_FEATURED_CLASS_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_WEB                                                        */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_WEB                                         */
/*                                                                   */
/*   Version 1 Supports:                                             */
/*       X_COMP_KIND_DEF_WEB_1                                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_WEB
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulMapEntries;
      X_DEFS_DISPATCH_ID_TABLE            pMapTable;
      X_COMP_DISPATCH_ID                  ulRoutine;
      unsigned long                       ulSessionState;

      /* VERSION_TAG 1 */
      unsigned long                       ulResponseType;
      unsigned long                       ulResponseOptions;
   }
      X_COMP_WEB,
      *PX_COMP_WEB,
      **PPX_COMP_WEB;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_WEB_FCC
   {
      X_COMP_KIND                         ulKind;
      unsigned long                       ulModifiers;
      const unsigned char              *  pvchName;
      const unsigned char              *  pvchDescription;
      const unsigned char              *  pvchHelpText;
      unsigned long                       ulMapEntries;
      X_DEFS_DISPATCH_ID_TABLE            pMapTable;
      X_COMP_DISPATCH_ID                  ulRoutine;
      unsigned long                       ulSessionState;

      /* VERSION_TAG 1 */
      unsigned long                       ulResponseType;
      unsigned long                       ulResponseOptions;
   }
      X_COMP_WEB_FCC,
      *PX_COMP_WEB_FCC,
      **PPX_COMP_WEB_FCC;

#endif

/* ------------------------------------------------------------------ */
/* Codes describing Web Routine Field Map modifiers                   */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_WEB_ROUTINE_MAP_MODIFIER;

#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_FOR_NONE                  0x00000001
#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_FOR_INPUT                 0x00000002
#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_FOR_OUTPUT                0x00000004

#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_OPTION_PERSISTENT         0x00000010
#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_OPTION_MERGE_INPUT        0x00000020
#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_OPTION_INLINE             0x00000040

#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_SCOPE_SHARED              0x00000100

#define X_COMP_WEB_ROUTINE_MAP_MODIFIER_OPTION_JSON               0x00001000

/* ----------------------------------------------------------------- */
/* X_COMP_WEB_ROUTINE_FIELD_MAP                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_WEB_ROUTINE_FIELD_MAP                       */
/*       X_COMP_KIND_DEF_WEB_ROUTINE_LIST_FIELD_MAP                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_WEB_ROUTINE_FIELD_MAP
   {
      X_COMP_KIND                               ulKind;
      X_COMP_DISPATCH_ID                        ulFieldPattern;
      X_COMP_WEB_ROUTINE_MAP_MODIFIER           ulModifiers;
      short                                     sFieldVector;
   }
      X_COMP_WEB_ROUTINE_FIELD_MAP,
      *PX_COMP_WEB_ROUTINE_FIELD_MAP,
      **PPX_COMP_WEB_ROUTINE_FIELD_MAP;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_WEB_ROUTINE_FIELD_MAP_FCC
   {
      X_COMP_KIND                               ulKind;
      const unsigned char                    *  pvchName;
      X_COMP_DISPATCH_ID                        ulFieldPattern;
      X_COMP_WEB_ROUTINE_MAP_MODIFIER           ulModifiers;
   }
      X_COMP_WEB_ROUTINE_FIELD_MAP_FCC,
      *PX_COMP_WEB_ROUTINE_FIELD_MAP_FCC,
      **PPX_COMP_WEB_ROUTINE_FIELD_MAP_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_WEB_ROUTINE_LIST_MAP                                       */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_KIND_DEF_WEB_ROUTINE_LIST_MAP                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_WEB_ROUTINE_LIST_MAP
   {
      X_COMP_KIND                               ulKind;
      const unsigned char                    *  pvchName;
      X_COMP_WEB_ROUTINE_MAP_MODIFIER           ulModifiers;
      unsigned long                             ulFieldEntries;
      X_DEFS_DISPATCH_ID_TABLE                  pFieldTable;
      short                                     sListVector;
   }
      X_COMP_WEB_ROUTINE_LIST_MAP,
      *PX_COMP_WEB_ROUTINE_LIST_MAP,
      **PPX_COMP_WEB_ROUTINE_LIST_MAP;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_WEB_ROUTINE_LIST_MAP_FCC
   {
      X_COMP_KIND                               ulKind;
      const unsigned char                    *  pvchName;
      X_COMP_WEB_ROUTINE_MAP_MODIFIER           ulModifiers;
      unsigned long                             ulFieldEntries;
      X_DEFS_DISPATCH_ID_TABLE                  pFieldTable;
   }
      X_COMP_WEB_ROUTINE_LIST_MAP_FCC,
      *PX_COMP_WEB_ROUTINE_LIST_MAP_FCC,
      **PPX_COMP_WEB_ROUTINE_LIST_MAP_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_DEF_FIELD_ATTRIBUTE_OPERATION                              */
/*                                                                   */
/*    Supports:                                                      */
/*                                                                   */
/*       X_COMP_KIND_FIELD_ATTRIBUTE_OPERATION                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_DEF_FIELD_ATTRIBUTE_OPERATION
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulField;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_DEF_FIELD_ATTRIBUTE_OPERATION,
      *PX_COMP_DEF_FIELD_ATTRIBUTE_OPERATION,
      **PPX_COMP_DEF_FIELD_ATTRIBUTE_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)
   typedef struct X_COMP_DEF_FIELD_ATTRIBUTE_OPERATION_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  ulField;
      X_COMP_DISPATCH_ID                  ulParameter;
   }
      X_COMP_DEF_FIELD_ATTRIBUTE_OPERATION_FCC,
      *PX_COMP_DEF_FIELD_ATTRIBUTE_OPERATION_FCC,
      **PPX_COMP_DEF_FIELD_ATTRIBUTE_OPERATION_FCC;

#endif


/* ------------------------------------------------------------------ */
/* Codes for Instrinic identifiers                                    */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_INTRINSIC_ID;

#define X_COMP_INTRINSIC_ID_NULL                               0L

#define X_COMP_INTRINSIC_ID_STRING_CUR_SIZE                    0x01000101L
#define X_COMP_INTRINSIC_ID_STRING_CUR_EBCDIC_SIZE             0x01000201L
#define X_COMP_INTRINSIC_ID_STRING_CUR_CHARS                   0x01000301L
#define X_COMP_INTRINSIC_ID_STRING_BYTE_TYPE_AT                0x01000401L
#define X_COMP_INTRINSIC_ID_STRING_CHAR_TYPE_AT                0x01000501L

#define X_COMP_INTRINSIC_ID_STRING_TRIM                        0x01000202L
#define X_COMP_INTRINSIC_ID_STRING_LEFT_TRIM                   0x01000302L
#define X_COMP_INTRINSIC_ID_STRING_RIGHT_TRIM                  0x01000402L

#define X_COMP_INTRINSIC_ID_STRING_CENTER                      0x01000502L
#define X_COMP_INTRINSIC_ID_STRING_REPEAT                      0x01000602L
#define X_COMP_INTRINSIC_ID_STRING_REVERSE                     0x01000701L
#define X_COMP_INTRINSIC_ID_STRING_LOWER_CASE                  0x01000801L
#define X_COMP_INTRINSIC_ID_STRING_UPPER_CASE                  0x01000901L

#define X_COMP_INTRINSIC_ID_STRING_LEFT_MOST                   0x01000A02L
#define X_COMP_INTRINSIC_ID_STRING_RIGHT_MOST                  0x01000B02L
#define X_COMP_INTRINSIC_ID_STRING_SUBSTRING                   0x01000C03L
#define X_COMP_INTRINSIC_ID_STRING_INSERT_STRING               0x01000D03L
#define X_COMP_INTRINSIC_ID_STRING_DELETE_SUBSTRING            0x01000E03L
#define X_COMP_INTRINSIC_ID_STRING_REPLACE_SUBSTRING           0x01000F04L

#define X_COMP_INTRINSIC_ID_STRING_CONCAT                      0x0100100BL
#define X_COMP_INTRINSIC_ID_STRING_TRIM_CONCAT                 0x0100110BL
#define X_COMP_INTRINSIC_ID_STRING_BLANK_CONCAT                0x0100120BL
#define X_COMP_INTRINSIC_ID_STRING_TRIM_BLANK_CONCAT           0x0100130BL
#define X_COMP_INTRINSIC_ID_STRING_SUBSTITUTE                  0x0100140AL
#define X_COMP_INTRINSIC_ID_STRING_TRIM_SUBSTITUTE             0x0100150AL
#define X_COMP_INTRINSIC_ID_STRING_RIGHT_ADJUST                0x01001603L

#define X_COMP_INTRINSIC_ID_STRING_CONTAINS                    0x01002003L
#define X_COMP_INTRINSIC_ID_STRING_POSITION_IN                 0x01002103L
#define X_COMP_INTRINSIC_ID_STRING_POSITION_OF                 0x01002203L
#define X_COMP_INTRINSIC_ID_STRING_OCCURRENCES_IN              0x01002303L
#define X_COMP_INTRINSIC_ID_STRING_OCCURRENCES_OF              0x01002403L
#define X_COMP_INTRINSIC_ID_STRING_LAST_POSITION_IN            0x01002502L
#define X_COMP_INTRINSIC_ID_STRING_LAST_POSITION_OF            0x01002602L
#define X_COMP_INTRINSIC_ID_STRING_CONTAINS_ONLY               0x01002702L
#define X_COMP_INTRINSIC_ID_STRING_REMOVE_CHARACTERS           0x01002802L
#define X_COMP_INTRINSIC_ID_STRING_REMOVE                      0x01002902L
#define X_COMP_INTRINSIC_ID_STRING_REMOVE_ALL                  0x01002A02L
#define X_COMP_INTRINSIC_ID_STRING_REPLACE                     0x01002B04L
#define X_COMP_INTRINSIC_ID_STRING_REPLACE_ALL                 0x01002C04L
#define X_COMP_INTRINSIC_ID_STRING_TRANSLATE_CHARACTERS        0x01002D03L
#define X_COMP_INTRINSIC_ID_STRING_MAX                         0x01002E0BL
#define X_COMP_INTRINSIC_ID_STRING_MIN                         0x01002F0BL

#define X_COMP_INTRINSIC_ID_STRING_AS_DATE                     0x01003002L
#define X_COMP_INTRINSIC_ID_STRING_AS_TIME                     0x01003102L
#define X_COMP_INTRINSIC_ID_STRING_AS_NUMBER                   0x01003201L
#define X_COMP_INTRINSIC_ID_STRING_AS_BOOLEAN                  0x01003301L
#define X_COMP_INTRINSIC_ID_STRING_AS_DATETIME                 0x01003402L
#define X_COMP_INTRINSIC_ID_STRING_AS_VARCHAR_VALUE            0x01003502L
#define X_COMP_INTRINSIC_ID_STRING_AS_FIXEDCHAR_VALUE          0x01003602L
#define X_COMP_INTRINSIC_ID_STRING_AS_INTEGER                  0x01003702L
#define X_COMP_INTRINSIC_ID_STRING_AS_FIXEDCHAR                0x01003802L
#define X_COMP_INTRINSIC_ID_STRING_AS_FLOAT                    0x01003901L
#define X_COMP_INTRINSIC_ID_STRING_AS_DURATION                 0x01003A01L
#define X_COMP_INTRINSIC_ID_STRING_AS_GREGORIAN_DAY            0x01003B01L
#define X_COMP_INTRINSIC_ID_STRING_AS_GREGORIAN_YEAR           0x01003C01L
#define X_COMP_INTRINSIC_ID_STRING_AS_GREGORIAN_MONTH          0x01003D01L
#define X_COMP_INTRINSIC_ID_STRING_AS_GREGORIAN_MONTHDAY       0x01003E01L
#define X_COMP_INTRINSIC_ID_STRING_AS_GREGORIAN_YEARMONTH      0x01003F01L

#define X_COMP_INTRINSIC_ID_STRING_IS_DATE                     0x01004002L
#define X_COMP_INTRINSIC_ID_STRING_IS_TIME                     0x01004102L
#define X_COMP_INTRINSIC_ID_STRING_IS_NUMBER                   0x01004201L
#define X_COMP_INTRINSIC_ID_STRING_IS_BOOLEAN                  0x01004301L
#define X_COMP_INTRINSIC_ID_STRING_IS_DATETIME                 0x01004402L
#define X_COMP_INTRINSIC_ID_STRING_IS_VARCHAR_NULL             0x01004501L
#define X_COMP_INTRINSIC_ID_STRING_IS_FIXEDCHAR_NULL           0x01004601L
#define X_COMP_INTRINSIC_ID_STRING_IS_SBCS                     0x01004701L
#define X_COMP_INTRINSIC_ID_STRING_IS_DBCS                     0x01004801L
#define X_COMP_INTRINSIC_ID_STRING_IS_MIXED                    0x01004901L
#define X_COMP_INTRINSIC_ID_STRING_AS_SBCS_STRING              0x01004A03L
#define X_COMP_INTRINSIC_ID_STRING_AS_DBCS_STRING              0x01004B03L
#define X_COMP_INTRINSIC_ID_STRING_AS_DBCS_FIXEDCHAR           0x01004C03L
#define X_COMP_INTRINSIC_ID_STRING_IS_FLOAT                    0x01004D01L
#define X_COMP_INTRINSIC_ID_STRING_COMPARE                     0x01004E01L

#define X_COMP_INTRINSIC_ID_STRING_IS_GREGORIAN_DAY            0x01004F01L
#define X_COMP_INTRINSIC_ID_STRING_IS_GREGORIAN_YEAR           0x01005001L
#define X_COMP_INTRINSIC_ID_STRING_IS_GREGORIAN_MONTH          0x01005101L
#define X_COMP_INTRINSIC_ID_STRING_IS_GREGORIAN_MONTHDAY       0x01005201L
#define X_COMP_INTRINSIC_ID_STRING_IS_GREGORIAN_YEARMONTH      0x01005301L
#define X_COMP_INTRINSIC_ID_STRING_IS_DURATION                 0x01005401L

#define X_COMP_INTRINSIC_ID_NUMBER_MIN                         0x02000102L
#define X_COMP_INTRINSIC_ID_NUMBER_MAX                         0x02000202L
#define X_COMP_INTRINSIC_ID_NUMBER_INC                         0x02000301L
#define X_COMP_INTRINSIC_ID_NUMBER_DEC                         0x02000401L
#define X_COMP_INTRINSIC_ID_NUMBER_SUCC                        0x02000501L
#define X_COMP_INTRINSIC_ID_NUMBER_PRED                        0x02000601L
#define X_COMP_INTRINSIC_ID_NUMBER_ROUND                       0x02000702L
#define X_COMP_INTRINSIC_ID_NUMBER_BOUND                       0x02000803L

#define X_COMP_INTRINSIC_ID_NUMBER_AS_STRING                   0x02002001L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_DATE                     0x02002102L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_TIME                     0x02002202L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_DATETIME                 0x02002302L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_BOOLEAN                  0x02002401L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_LONG_VALUE               0x02002502L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_FLOAT                    0x02002602L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_DECIMAL_VALUE            0x02002702L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_LONGLONG_VALUE           0x02002802L

#define X_COMP_INTRINSIC_ID_LONGLONG_AS_BINSTRING              0x02002902L
#define X_COMP_INTRINSIC_ID_NUMBER_AS_DISPLAY_STRING           0x02002A02L

#define X_COMP_INTRINSIC_ID_INTEGER_BIT_OR                     0x02003002L
#define X_COMP_INTRINSIC_ID_INTEGER_BIT_AND                    0x02003102L
#define X_COMP_INTRINSIC_ID_INTEGER_BIT_NOT                    0x02003201L
#define X_COMP_INTRINSIC_ID_INTEGER_BIT_XOR                    0x02003302L
#define X_COMP_INTRINSIC_ID_INTEGER_AS_BYTE                    0x02003401L
#define X_COMP_INTRINSIC_ID_INTEGER_AS_CHAR                    0x02003501L
#define X_COMP_INTRINSIC_ID_INTEGER_AS_BINSTRING               0x02003601L
#define X_COMP_INTRINSIC_ID_INTEGER_MOD                        0x02003701L
#define X_COMP_INTRINSIC_ID_INTEGER_DIV                        0x02003801L
#define X_COMP_INTRINSIC_ID_INTEGER_AS_UNICODE_STRING          0x02003901L

#define X_COMP_INTRINSIC_ID_NUMBER_IS_NULL                     0x02004001L
#define X_COMP_INTRINSIC_ID_NUMBER_IS_DATE                     0x02004102L
#define X_COMP_INTRINSIC_ID_NUMBER_IS_TIME                     0x02004202L
#define X_COMP_INTRINSIC_ID_NUMBER_IS_BOOLEAN                  0x02004201L
#define X_COMP_INTRINSIC_ID_NUMBER_IS_DATETIME                 0x02004402L
#define X_COMP_INTRINSIC_ID_NUMBER_IS_BETWEEN                  0x02004503L

#define X_COMP_INTRINSIC_ID_FLOAT_MIN                          0x02005102L
#define X_COMP_INTRINSIC_ID_FLOAT_MAX                          0x02005202L
#define X_COMP_INTRINSIC_ID_FLOAT_INC                          0x02005301L
#define X_COMP_INTRINSIC_ID_FLOAT_DEC                          0x02005401L
#define X_COMP_INTRINSIC_ID_FLOAT_SUCC                         0x02005501L
#define X_COMP_INTRINSIC_ID_FLOAT_PRED                         0x02005601L
#define X_COMP_INTRINSIC_ID_FLOAT_BOUND                        0x02005703L
#define X_COMP_INTRINSIC_ID_FLOAT_IS_BETWEEN                   0x02005803L
#define X_COMP_INTRINSIC_ID_FLOAT_AS_VALUE                     0x02005902L
#define X_COMP_INTRINSIC_ID_FLOAT_AS_STRING                    0x02005A01L
#define X_COMP_INTRINSIC_ID_FLOAT_AS_DECIMAL                   0x02005B01L

#define X_COMP_INTRINSIC_ID_FLOAT_ADD                          0x02006002L
#define X_COMP_INTRINSIC_ID_FLOAT_SUBTRACT                     0x02006102L
#define X_COMP_INTRINSIC_ID_FLOAT_MULTIPLY                     0x02006202L
#define X_COMP_INTRINSIC_ID_FLOAT_DIVIDE                       0x02006302L

#define X_COMP_INTRINSIC_ID_FLOAT_SINE                         0x02006401L
#define X_COMP_INTRINSIC_ID_FLOAT_SINEH                        0x02006501L
#define X_COMP_INTRINSIC_ID_FLOAT_ARCSINE                      0x02006601L

#define X_COMP_INTRINSIC_ID_FLOAT_COSINE                       0x02006701L
#define X_COMP_INTRINSIC_ID_FLOAT_COSINEH                      0x02006801L
#define X_COMP_INTRINSIC_ID_FLOAT_ARCCOSINE                    0x02006901L

#define X_COMP_INTRINSIC_ID_FLOAT_TANGENT                      0x02006A01L
#define X_COMP_INTRINSIC_ID_FLOAT_TANGENTH                     0x02006B01L
#define X_COMP_INTRINSIC_ID_FLOAT_ARCTANGENT                   0x02006C01L
#define X_COMP_INTRINSIC_ID_FLOAT_ARCTANGENT2                  0x02006D01L

#define X_COMP_INTRINSIC_ID_FLOAT_SQRT                         0x02006E01L
#define X_COMP_INTRINSIC_ID_FLOAT_POWER                        0x02006F01L
#define X_COMP_INTRINSIC_ID_FLOAT_FMOD                         0x02006F11L
#define X_COMP_INTRINSIC_ID_FLOAT_FABS                         0x02006F21L

#define X_COMP_INTRINSIC_ID_FLOAT_LOGARITHM                    0x02007001L
#define X_COMP_INTRINSIC_ID_FLOAT_LOGARITHM10                  0x02007201L
#define X_COMP_INTRINSIC_ID_FLOAT_EXPONENTIAL                  0x02007301L

#define X_COMP_INTRINSIC_ID_FLOAT_ISNANORND                    0x02007401L

#define X_COMP_INTRINSIC_ID_VAR_TYPE                           0x03000101L
#define X_COMP_INTRINSIC_ID_VAR_AS_TYPE                        0x03000202L

#define X_COMP_INTRINSIC_ID_VAR_AS_STRING                      0x03002001L
#define X_COMP_INTRINSIC_ID_VAR_AS_BOOLEAN                     0x03002101L
#define X_COMP_INTRINSIC_ID_VAR_AS_DECIMAL                     0x03002201L
#define X_COMP_INTRINSIC_ID_VAR_AS_INTEGER                     0x03002301L
#define X_COMP_INTRINSIC_ID_VAR_AS_REFERENCE                   0x03002401L
#define X_COMP_INTRINSIC_ID_VAR_AS_DATE                        0x03002501L
#define X_COMP_INTRINSIC_ID_VAR_AS_TIME                        0x03002601L
#define X_COMP_INTRINSIC_ID_VAR_AS_DATETIME                    0x03002701L

#define X_COMP_INTRINSIC_ID_VAR_IS_NULL                        0x03005001L
#define X_COMP_INTRINSIC_ID_VAR_IS_EMPTY                       0x03005101L
#define X_COMP_INTRINSIC_ID_VAR_IS_NUMBER                      0x03005201L
#define X_COMP_INTRINSIC_ID_VAR_IS_STRING                      0x03005301L
#define X_COMP_INTRINSIC_ID_VAR_IS_DATE                        0x03005401L
#define X_COMP_INTRINSIC_ID_VAR_IS_BOOLEAN                     0x03005501L
#define X_COMP_INTRINSIC_ID_VAR_IS_REFERENCE                   0x03005601L
#define X_COMP_INTRINSIC_ID_VAR_IS_NULL_REFERENCE              0x03005701L
#define X_COMP_INTRINSIC_ID_VAR_IS_TIME                        0x03005801L
#define X_COMP_INTRINSIC_ID_VAR_IS_DATETIME                    0x03005901L


#define X_COMP_INTRINSIC_ID_BOOLEAN_IS_TRUE                    0x04000101L
#define X_COMP_INTRINSIC_ID_BOOLEAN_IS_FALSE                   0x04000201L
#define X_COMP_INTRINSIC_ID_BOOLEAN_IS_NULL                    0x04000301L

#define X_COMP_INTRINSIC_ID_BOOLEAN_OR                         0x04001002L
#define X_COMP_INTRINSIC_ID_BOOLEAN_AND                        0x04001102L
#define X_COMP_INTRINSIC_ID_BOOLEAN_NOT                        0x04001201L

#define X_COMP_INTRINSIC_ID_BOOLEAN_AS_STRING                  0x04002001L
#define X_COMP_INTRINSIC_ID_BOOLEAN_AS_VALUE                   0x04002102L
#define X_COMP_INTRINSIC_ID_BOOLEAN_AS_NUMBER                  0x04002201L


#define X_COMP_INTRINSIC_ID_DATE_NOW                           0x05000101L
#define X_COMP_INTRINSIC_ID_DATE_DAY                           0x05000201L
#define X_COMP_INTRINSIC_ID_DATE_YEAR                          0x05000301L
#define X_COMP_INTRINSIC_ID_DATE_MONTH                         0x05000401L
#define X_COMP_INTRINSIC_ID_DATE_ADJUST                        0x05000503L
#define X_COMP_INTRINSIC_ID_DATE_DIFFERENCE                    0x05000602L
#define X_COMP_INTRINSIC_ID_DATE_MIN                           0x0500070BL
#define X_COMP_INTRINSIC_ID_DATE_MAX                           0x0500080BL
#define X_COMP_INTRINSIC_ID_DATE_WEEK                          0x05000901L

#define X_COMP_INTRINSIC_ID_DATE_AS_NUMBER                     0x05002002L
#define X_COMP_INTRINSIC_ID_DATE_AS_STRING                     0x05002101L
#define X_COMP_INTRINSIC_ID_DATE_AS_DISPLAY_STRING             0x05002202L
#define X_COMP_INTRINSIC_ID_DATE_AS_VALUE                      0x05002302L
#define X_COMP_INTRINSIC_ID_DATE_AS_DAYS                       0x05002401L
#define X_COMP_INTRINSIC_ID_DATE_AS_DATETIME                   0x05002501L
#define X_COMP_INTRINSIC_ID_DATE_AS_DAY_OF_WEEK                0x05002601L

#define X_COMP_INTRINSIC_ID_DATE_IS_NULL                       0x05003101L


#define X_COMP_INTRINSIC_ID_TIME_NOW                           0x05010101L
#define X_COMP_INTRINSIC_ID_TIME_HOUR                          0x05010201L
#define X_COMP_INTRINSIC_ID_TIME_MINUTE                        0x05010301L
#define X_COMP_INTRINSIC_ID_TIME_SECOND                        0x05010401L
#define X_COMP_INTRINSIC_ID_TIME_ADJUST                        0x05010503L
#define X_COMP_INTRINSIC_ID_TIME_DIFFERENCE                    0x05010602L
#define X_COMP_INTRINSIC_ID_TIME_MIN                           0x0501070BL
#define X_COMP_INTRINSIC_ID_TIME_MAX                           0x0501080BL

#define X_COMP_INTRINSIC_ID_TIME_AS_NUMBER                     0x05012002L
#define X_COMP_INTRINSIC_ID_TIME_AS_STRING                     0x05012101L
#define X_COMP_INTRINSIC_ID_TIME_AS_DISPLAY_STRING             0x05012202L
#define X_COMP_INTRINSIC_ID_TIME_AS_VALUE                      0x05012302L
#define X_COMP_INTRINSIC_ID_TIME_AS_SECONDS                    0x05012401L
#define X_COMP_INTRINSIC_ID_TIME_AS_DATETIME                   0x05012502L

#define X_COMP_INTRINSIC_ID_TIME_IS_NULL                       0x05013101L


#define X_COMP_INTRINSIC_ID_DATETIME_NOW                       0x05020101L
#define X_COMP_INTRINSIC_ID_DATETIME_DATE                      0x05020201L
#define X_COMP_INTRINSIC_ID_DATETIME_TIME                      0x05020301L
#define X_COMP_INTRINSIC_ID_DATETIME_FRACTIONAL_SECONDS        0x05020401L
#define X_COMP_INTRINSIC_ID_DATETIME_MIN                       0x0502050BL
#define X_COMP_INTRINSIC_ID_DATETIME_MAX                       0x0502060BL

#define X_COMP_INTRINSIC_ID_DATETIME_AS_NUMBER                 0x05022002L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_STRING                 0x05022101L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_DISPLAY_STRING         0x05022202L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_VALUE                  0x05022302L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_LOCALIZED_DATETIME     0x05022401L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_UNIVERSAL_DATETIME     0x05022501L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_SECONDS                0x05022601L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_CUSTOM_DISPLAY_STRING  0x05022701L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_GREGORIAN_DAY          0x05022801L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_GREGORIAN_YEAR         0x05022901L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_GREGORIAN_MONTH        0x05022A01L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_AS_GREGORIAN_MONTHDAY  0x05022B01L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_AS_GREGORIAN_YEARMONTH 0x05022C01L
#define X_COMP_INTRINSIC_ID_DATETIME_AS_DURATION               0x05022D01L

#define X_COMP_INTRINSIC_ID_DATETIME_IS_NULL                   0x05023101L


#define X_COMP_INTRINSIC_ID_GENERAL_IS_SQLNULL                 0x06000101L
#define X_COMP_INTRINSIC_ID_GENERAL_IS_NOT_SQLNULL             0x06000201L


#define X_COMP_INTRINSIC_ID_FIELD_TYPE                         0x07000101L
#define X_COMP_INTRINSIC_ID_FIELD_LENGTH                       0x07000201L
#define X_COMP_INTRINSIC_ID_FIELD_DECIMALS                     0x07000301L
#define X_COMP_INTRINSIC_ID_FIELD_ATTRIBUTE_AS_STRING          0x07000401L
#define X_COMP_INTRINSIC_ID_FIELD_DEFAULT                      0x07000501L
#define X_COMP_INTRINSIC_ID_FIELD_LOB_FILENAME                 0x07000601L

#define X_COMP_INTRINSIC_ID_FIELD_IS_DEFAULT                   0x07003001L


#define X_COMP_INTRINSIC_ID_BINARY_CUR_SIZE                    0x08000101L

#define X_COMP_INTRINSIC_ID_BINARY_AS_BYTE                     0x08003002L
#define X_COMP_INTRINSIC_ID_BINARY_AS_VALUE                    0x08003101L
#define X_COMP_INTRINSIC_ID_BINARY_AS_STRING                   0x08003201L
#define X_COMP_INTRINSIC_ID_BINARY_AS_INTEGER                  0x08003302L
#define X_COMP_INTRINSIC_ID_BINARY_AS_HEXSTRING                0x08003401L
#define X_COMP_INTRINSIC_ID_BINARY_AS_HEXTOINT                 0x08003402L

#define X_COMP_INTRINSIC_ID_BINARY_IS_NULL                     0x08004001L

#define X_COMP_INTRINSIC_ID_BOM_IS_NULL                        0x09000000L
#define X_COMP_INTRINSIC_ID_BOM_IS_DEFAULT                     0x09000001L
#define X_COMP_INTRINSIC_ID_BOM_ASSIGN_NULL                    0x09000002L
#define X_COMP_INTRINSIC_ID_BOM_ASSIGN_DEFAULT                 0x09000003L
#define X_COMP_INTRINSIC_ID_BOM_ASSEMBLE                       0x09000004L
#define X_COMP_INTRINSIC_ID_BOM_DISASSEMBLE                    0x09000005L

#define X_COMP_INTRINSIC_ID_BOM_ADD_ENTRY                      0x09000010L
#define X_COMP_INTRINSIC_ID_BOM_STORE_ENTRY                    0x09000011L

#define X_COMP_INTRINSIC_ID_BOM_HANDLE_IO_ERROR                0x09000020L
#define X_COMP_INTRINSIC_ID_BOM_HANDLE_NOT_FOUND               0x09000021L   

#define X_COMP_INTRINSIC_ID_UTF16_STRING_CUR_SIZE              0x0A000101L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_CUR_EBCDIC_SIZE       0x0A000201L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_CUR_CHARS             0x0A000301L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_BYTE_TYPE_AT          0x0A000401L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_CHAR_TYPE_AT          0x0A000501L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_TRIM                  0x0A000202L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_LEFT_TRIM             0x0A000302L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_RIGHT_TRIM            0x0A000402L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_CENTER                0x0A000502L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REPEAT                0x0A000602L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REVERSE               0x0A000701L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_LOWER_CASE            0x0A000801L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_UPPER_CASE            0x0A000901L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_LEFT_MOST             0x0A000A02L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_RIGHT_MOST            0x0A000B02L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_SUBSTRING             0x0A000C03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_INSERT_STRING         0x0A000D03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_DELETE_SUBSTRING      0x0A000E03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REPLACE_SUBSTRING     0x0A000F04L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_CONCAT                0x0A00100BL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_TRIM_CONCAT           0x0A00110BL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_BLANK_CONCAT          0x0A00120BL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_TRIM_BLANK_CONCAT     0x0A00130BL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_SUBSTITUTE            0x0A00140AL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_TRIM_SUBSTITUTE       0x0A00150AL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_RIGHT_ADJUST          0x0A001603L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_COMPARE               0x0A001703L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_CONTAINS              0x0A002003L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_POSITION_IN           0x0A002103L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_POSITION_OF           0x0A002203L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_OCCURRENCES_IN        0x0A002303L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_OCCURRENCES_OF        0x0A002403L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_LAST_POSITION_IN      0x0A002502L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_LAST_POSITION_OF      0x0A002602L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_CONTAINS_ONLY         0x0A002702L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REMOVE_CHARACTERS     0x0A002802L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REMOVE                0x0A002902L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REMOVE_ALL            0x0A002A02L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REPLACE               0x0A002B04L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_REPLACE_ALL           0x0A002C04L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_TRANSLATE_CHARACTERS  0x0A002D03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_MAX                   0x0A002E0BL
#define X_COMP_INTRINSIC_ID_UTF16_STRING_MIN                   0x0A002F0BL

#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_DATE               0x0A003002L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_TIME               0x0A003102L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_NUMBER             0x0A003201L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_BOOLEAN            0x0A003301L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_DATETIME           0x0A003402L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_VALUE              0x0A003502L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_INTEGER            0x0A003602L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_FIXEDCHAR          0x0A003702L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_FLOAT              0x0A003801L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_CODE_POINT         0x0A003901L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_DATE               0x0A004002L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_TIME               0x0A004102L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_NUMBER             0x0A004201L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_BOOLEAN            0x0A004301L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_DATETIME           0x0A004402L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_VARCHAR_NULL       0x0A004501L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_FIXEDCHAR_NULL     0x0A004601L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_SBCS               0x0A004701L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_DBCS               0x0A004801L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_MIXED              0x0A004901L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_SBCS_STRING        0x0A004A03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_DBCS_STRING        0x0A004B03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_DBCS_FIXEDCHAR     0x0A004C03L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_FLOAT              0x0A004D01L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_GREGORIAN_DAY       0x0A005001L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_GREGORIAN_YEAR      0x0A005101L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_GREGORIAN_MONTH     0x0A005201L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_GREGORIAN_MONTHDAY  0x0A005301L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_GREGORIAN_YEARMONTH 0x0A005401L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_IS_DURATION            0x0A005501L

#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_DURATION            0x0A005601L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_GREGORIAN_DAY       0x0A005701L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_GREGORIAN_YEAR      0x0A005801L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_GREGORIAN_MONTH     0x0A005901L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_GREGORIAN_MONTHDAY  0x0A005A01L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_GREGORIAN_YEARMONTH 0x0A005B01L
#define X_COMP_INTRINSIC_ID_UTF16_STRING_AS_NATIVE_STRING       0x0A005C01L

#define X_COMP_INTRINSIC_ID_GREGORIAN_DAY_AS_STRING            0x08005001L
#define X_COMP_INTRINSIC_ID_GREGORIAN_DAY_AS_DATETIME          0x08005002L
#define X_COMP_INTRINSIC_ID_GREGORIAN_YEAR_AS_STRING           0x08005003L
#define X_COMP_INTRINSIC_ID_GREGORIAN_YEAR_AS_DATETIME         0x08005004L
#define X_COMP_INTRINSIC_ID_GREGORIAN_MONTH_AS_STRING          0x08005005L
#define X_COMP_INTRINSIC_ID_GREGORIAN_MONTH_AS_DATETIME        0x08005006L
#define X_COMP_INTRINSIC_ID_GREGORIAN_MONTHDAY_AS_STRING       0x08005007L
#define X_COMP_INTRINSIC_ID_GREGORIAN_MONTHDAY_AS_DATETIME     0x08005008L
#define X_COMP_INTRINSIC_ID_GREGORIAN_YEARMONTH_AS_STRING      0x08005009L
#define X_COMP_INTRINSIC_ID_GREGORIAN_YEARMONTH_AS_DATETIME    0x0800500AL
#define X_COMP_INTRINSIC_ID_DURATION_AS_STRING                 0x0800500BL
#define X_COMP_INTRINSIC_ID_DURATION_AS_DATETIME               0x0800500CL

/* ----------------------------------------------------------------- */
/* OpCode identifers for X_VAR expression evaluation                 */
/* ----------------------------------------------------------------- */

typedef unsigned long
   X_COMP_OPCODE;

#define X_COMP_OPCODE_NOP                                            0

/* PUSH CONSTANT instructions 0x0001 - 0x003F (Last 0x0030) */
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_LONG                    0x00000001L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_LONGLONG                0x00000002L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_DOUBLE                  0x00000003L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_PACKED31                0x00000004L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_PACKED63                0x00000005L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_DECIMAL                 0x00000006L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_INT32                   0x00000007L
#define X_COMP_OPCODE_PUSH_INT32_CONSTANT_AS_INT64                   0x00000008L

#define X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_LONGLONG                0x00000009L
#define X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_DOUBLE                  0x0000000AL
#define X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_PACKED31                0x0000000BL
#define X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_PACKED63                0x0000000CL
#define X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_DECIMAL                 0x0000000DL
#define X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_INT64                   0x0000000EL

#define X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_DOUBLE                 0x0000000FL
#define X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_PACKED31               0x00000010L
#define X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_PACKED63               0x00000011L
#define X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_DECIMAL                0x00000012L

#define X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_LONGLONG               0x00000013L
#define X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_DOUBLE                 0x00000014L
#define X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_PACKED31               0x00000015L
#define X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_PACKED63               0x00000016L
#define X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_DECIMAL                0x00000017L
#define X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_INT64                  0x00000018L

#define X_COMP_OPCODE_PUSH_FLOAT64_CONSTANT_AS_FLOAT64               0x00000019L

#define X_COMP_OPCODE_PUSH_STRING_CONSTANT_AS_STRING                 0x0000001AL
#define X_COMP_OPCODE_PUSH_STRING_CONSTANT_AS_DATE                   0x0000001BL
#define X_COMP_OPCODE_PUSH_STRING_CONSTANT_AS_TIME                   0x0000001CL
#define X_COMP_OPCODE_PUSH_STRING_CONSTANT_AS_DATETIME               0x0000001DL
#define X_COMP_OPCODE_PUSH_STRING_CONSTANT_AS_BINARY                 0x0000001EL
#define X_COMP_OPCODE_PUSH_STRING_CONSTANT_AS_VARIANT                0x0000001FL

#define X_COMP_OPCODE_PUSH_BOOLEAN_TRUE_CONSTANT                     0x00000020L
#define X_COMP_OPCODE_PUSH_BOOLEAN_FALSE_CONSTANT                    0x00000021L
#define X_COMP_OPCODE_PUSH_BOOLEAN_CONSTANT_AS_BOOLEAN               0x00000022L

#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_LONG                     0x00000023L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_LONGLONG                 0x00000024L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_DOUBLE                   0x00000025L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_PACKED31                 0x00000026L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_PACKED63                 0x00000027L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_DECIMAL                  0x00000028L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_INT32                    0x00000029L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_INT64                    0x0000002AL
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_FLOAT64                  0x0000002BL
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_VARIANT                  0x0000002CL
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_BOOLEAN                  0x0000002DL
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_STRING                   0x0000002EL
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_DATE                     0x0000002FL
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_TIME                     0x00000030L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_DATETIME                 0x00000031L
#define X_COMP_OPCODE_PUSH_NULL_CONSTANT_AS_BINARY                   0x00000032L

#define X_COMP_OPCODE_PUSH_SQLNULL                                   0x00000033L
#define X_COMP_OPCODE_PUSH_DEFAULT_PARAMETER                         0x00000034L

/* Vector PUSH instructions 0x0040 - 0x00FF (Last 0x00BF) */
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_LONG                     0x00000040L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_LONGLONG                 0x00000041L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_DOUBLE                   0x00000042L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_PACKED31                 0x00000043L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_PACKED63                 0x00000044L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_DECIMAL                  0x00000045L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_INT32                    0x00000046L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR_AS_INT64                    0x00000047L

#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_LONG               0x00000048L
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_LONGLONG           0x00000049L
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_DOUBLE             0x0000004AL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_PACKED31           0x0000004BL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_PACKED63           0x0000004CL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_DECIMAL            0x0000004DL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_INT32              0x0000004EL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR_AS_INT64              0x0000004FL

#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_LONG                    0x00000050L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_LONGLONG                0x00000051L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_DOUBLE                  0x00000052L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_PACKED31                0x00000053L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_PACKED63                0x00000054L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_DECIMAL                 0x00000055L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_INT32                   0x00000056L
#define X_COMP_OPCODE_PUSH_PACKED_VECTOR2_AS_INT64                   0x00000057L

#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_LONG              0x00000058L
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_LONGLONG          0x00000059L
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_DOUBLE            0x0000005AL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_PACKED31          0x0000005BL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_PACKED63          0x0000005CL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_DECIMAL           0x0000005DL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_INT32             0x0000005EL
#define X_COMP_OPCODE_PUSH_PACKED_STACK_VECTOR2_AS_INT64             0x0000005FL

#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_LONG                     0x00000060L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_LONGLONG                 0x00000061L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_DOUBLE                   0x00000062L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_PACKED31                 0x00000063L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_PACKED63                 0x00000064L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_DECIMAL                  0x00000065L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_INT32                    0x00000066L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR_AS_INT64                    0x00000067L

#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_LONG               0x00000068L
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_LONGLONG           0x00000069L
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_DOUBLE             0x0000006AL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_PACKED31           0x0000006BL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_PACKED63           0x0000006CL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_DECIMAL            0x0000006DL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_INT32              0x0000006EL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR_AS_INT64              0x0000006FL

#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_LONG                    0x00000070L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_LONGLONG                0x00000071L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_DOUBLE                  0x00000072L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_PACKED31                0x00000073L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_PACKED63                0x00000074L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_DECIMAL                 0x00000075L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_INT32                   0x00000076L
#define X_COMP_OPCODE_PUSH_SIGNED_VECTOR2_AS_INT64                   0x00000077L

#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_LONG              0x00000078L
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_LONGLONG          0x00000079L
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_DOUBLE            0x0000007AL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_PACKED31          0x0000007BL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_PACKED63          0x0000007CL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_DECIMAL           0x0000007DL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_INT32             0x0000007EL
#define X_COMP_OPCODE_PUSH_SIGNED_STACK_VECTOR2_AS_INT64             0x0000007FL

#define X_COMP_OPCODE_PUSH_INT8_VECTOR_AS_INT32                      0x00000080L
#define X_COMP_OPCODE_PUSH_INT8_STACK_VECTOR_AS_INT32                0x00000081L
#define X_COMP_OPCODE_PUSH_INTU8_VECTOR_AS_INT32                     0x00000082L
#define X_COMP_OPCODE_PUSH_INTU8_STACK_VECTOR_AS_INT32               0x00000083L
#define X_COMP_OPCODE_PUSH_INT16_VECTOR_AS_INT32                     0x00000084L
#define X_COMP_OPCODE_PUSH_INT16_STACK_VECTOR_AS_INT32               0x00000085L
#define X_COMP_OPCODE_PUSH_INT32_VECTOR_AS_INT32                     0x00000086L
#define X_COMP_OPCODE_PUSH_INT32_STACK_VECTOR_AS_INT32               0x00000087L
#define X_COMP_OPCODE_PUSH_INT64_VECTOR_AS_INT64                     0x00000088L
#define X_COMP_OPCODE_PUSH_INT64_STACK_VECTOR_AS_INT64               0x00000089L
#define X_COMP_OPCODE_PUSH_FLOAT32_VECTOR_AS_FLOAT64                 0x0000008AL
#define X_COMP_OPCODE_PUSH_FLOAT32_STACK_VECTOR_AS_FLOAT64           0x0000008BL
#define X_COMP_OPCODE_PUSH_FLOAT64_VECTOR_AS_FLOAT64                 0x0000008CL
#define X_COMP_OPCODE_PUSH_FLOAT64_STACK_VECTOR_AS_FLOAT64           0x0000008DL
#define X_COMP_OPCODE_PUSH_ALPHA_VECTOR_AS_ALPHA                     0x0000008EL
#define X_COMP_OPCODE_PUSH_ALPHA_VECTOR_AS_STRING                    0x0000008FL
#define X_COMP_OPCODE_PUSH_ALPHA_VECTOR_AS_VARIANT                   0x00000090L
#define X_COMP_OPCODE_PUSH_ALPHA_STACK_VECTOR_AS_ALPHA               0x00000091L
#define X_COMP_OPCODE_PUSH_ALPHA_STACK_VECTOR_AS_STRING              0x00000092L
#define X_COMP_OPCODE_PUSH_ALPHA_STACK_VECTOR_AS_VARIANT             0x00000093L
#define X_COMP_OPCODE_PUSH_STRING_VECTOR_AS_STRING                   0x00000094L
#define X_COMP_OPCODE_PUSH_STRING_VECTOR_AS_VARIANT                  0x00000095L
#define X_COMP_OPCODE_PUSH_STRING_STACK_VECTOR_AS_STRING             0x00000096L
#define X_COMP_OPCODE_PUSH_STRING_STACK_VECTOR_AS_VARIANT            0x00000097L
#define X_COMP_OPCODE_PUSH_BLOB_VECTOR_AS_STRING                     0x00000098L
#define X_COMP_OPCODE_PUSH_BLOB_VECTOR_AS_VARIANT                    0x00000099L
#define X_COMP_OPCODE_PUSH_BLOB_STACK_VECTOR_AS_STRING               0x0000009AL
#define X_COMP_OPCODE_PUSH_BLOB_STACK_VECTOR_AS_VARIANT              0x0000009BL
#define X_COMP_OPCODE_PUSH_CLOB_VECTOR_AS_STRING                     0x0000009CL
#define X_COMP_OPCODE_PUSH_CLOB_VECTOR_AS_VARIANT                    0x0000009DL
#define X_COMP_OPCODE_PUSH_CLOB_STACK_VECTOR_AS_STRING               0x0000009EL
#define X_COMP_OPCODE_PUSH_CLOB_STACK_VECTOR_AS_VARIANT              0x0000009FL
#define X_COMP_OPCODE_PUSH_BINARY_VECTOR_AS_BINARY                   0x000000A0L
#define X_COMP_OPCODE_PUSH_BINARY_VECTOR_AS_VARIANT                  0x000000A1L
#define X_COMP_OPCODE_PUSH_BINARY_STACK_VECTOR_AS_BINARY             0x000000A2L
#define X_COMP_OPCODE_PUSH_BINARY_STACK_VECTOR_AS_VARIANT            0x000000A3L
#define X_COMP_OPCODE_PUSH_DATE_VECTOR_AS_DATE                       0x000000A4L
#define X_COMP_OPCODE_PUSH_DATE_STACK_VECTOR_AS_DATE                 0x000000A5L
#define X_COMP_OPCODE_PUSH_TIME_VECTOR_AS_TIME                       0x000000A6L
#define X_COMP_OPCODE_PUSH_TIME_STACK_VECTOR_AS_TIME                 0x000000A7L
#define X_COMP_OPCODE_PUSH_DATETIME_VECTOR_AS_DATETIME               0x000000A8L
#define X_COMP_OPCODE_PUSH_DATETIME_STACK_VECTOR_AS_DATETIME         0x000000A9L
#define X_COMP_OPCODE_PUSH_BOOLEAN_VECTOR_AS_BOOLEAN                 0x000000AAL
#define X_COMP_OPCODE_PUSH_BOOLEAN_STACK_VECTOR_AS_BOOLEAN           0x000000ABL
#define X_COMP_OPCODE_PUSH_LONG_VECTOR_AS_LONG                       0x000000ACL
#define X_COMP_OPCODE_PUSH_LONG_VECTOR_AS_INT32                      0x000000ADL
#define X_COMP_OPCODE_PUSH_DOUBLE_VECTOR_AS_DOUBLE                   0x000000AEL
#define X_COMP_OPCODE_PUSH_RECORD_VECTOR_AS_SQLNULL                  0x000000AFL

#define X_COMP_OPCODE_PUSH_VECTOR_AS_SQLNULL                         0x000000B0L
#define X_COMP_OPCODE_PUSH_LIST_VECTOR_AS_SQLNULL                    0x000000B1L
#define X_COMP_OPCODE_PUSH_ARRAY_VECTOR_AS_SQLNULL                   0x000000B2L
#define X_COMP_OPCODE_PUSH_VECTOR2_AS_SQLNULL                        0x000000B3L
#define X_COMP_OPCODE_PUSH_LIST_VECTOR2_AS_SQLNULL                   0x000000B4L
#define X_COMP_OPCODE_PUSH_ARRAY_VECTOR2_AS_SQLNULL                  0x000000B5L
#define X_COMP_OPCODE_PUSH_VECTOR_AS_STACK_VECTOR                    0x000000B6L
#define X_COMP_OPCODE_PUSH_LIST_VECTOR_AS_STACK_VECTOR               0x000000B7L
#define X_COMP_OPCODE_PUSH_ARRAY_VECTOR_AS_STACK_VECTOR              0x000000B8L
#define X_COMP_OPCODE_PUSH_STRING_LOVAL                              0x000000B9L
#define X_COMP_OPCODE_PUSH_STRING_HIVAL                              0x000000BAL
#define X_COMP_OPCODE_PUSH_DECIMAL_LOVAL                             0x000000BBL
#define X_COMP_OPCODE_PUSH_DECIMAL_HIVAL                             0x000000BCL
#define X_COMP_OPCODE_PUSH_EVALUATION_VECTOR_AS_SQLNULL              0x000000BDL
#define X_COMP_OPCODE_PUSH_EVALUATION_VECTOR_AS_STACK_VECTOR         0x000000BEL
#define X_COMP_OPCODE_PUSH_RECORD_VECTOR2_AS_SQLNULL                 0x000000BFL

#define X_COMP_OPCODE_PUSH_FILE_VECTOR_AS_SQLNULL                    0x000000C0L
#define X_COMP_OPCODE_PUSH_FILE_VECTOR2_AS_SQLNULL                   0x000000C1L
#define X_COMP_OPCODE_PUSH_FILE_VECTOR_AS_STACK_VECTOR               0x000000C2L
#define X_COMP_OPCODE_PUSH_FILE_VECTOR2_AS_STACK_VECTOR              0x000000C3L
#define X_COMP_OPCODE_PUSH_INT16_NTV_VECTOR_AS_LONG                  0x000000C4L       /* X_DB2_IS_OTHBIN            */
#define X_COMP_OPCODE_PUSH_INT32_NTV_VECTOR_AS_LONGLONG              0x000000C5L       /* X_DB2_IS_OTHBIN            */
#define X_COMP_OPCODE_PUSH_PACKED31_NTV_VECTOR_AS_PACKED31           0x000000C6L       /* X_DB2_IS_DECIMAL_TRUNCATE  */
#define X_COMP_OPCODE_PUSH_SIGNED31_NTV_VECTOR_AS_PACKED31           0x000000C7L       /* X_DB2_IS_DECIMAL_TRUNCATE  */
#define X_COMP_OPCODE_PUSH_INT16_NTV_VECTOR_AS_INT32                 0x000000C8L
#define X_COMP_OPCODE_PUSH_INT32_NTV_VECTOR_AS_INT32                 0x000000C9L
#define X_COMP_OPCODE_PUSH_INT64_NTV_VECTOR_AS_INT64                 0x000000CAL
#define X_COMP_OPCODE_PUSH_FLOAT32_NTV_VECTOR_AS_FLOAT64             0x000000CBL
#define X_COMP_OPCODE_PUSH_FLOAT64_NTV_VECTOR_AS_FLOAT64             0x000000CCL
#define X_COMP_OPCODE_PUSH_NTV_VECTOR_AS_STRING                      0x000000CDL
#define X_COMP_OPCODE_PUSH_VARLEN_NTV_VECTOR_AS_STRING               0x000000CEL       /* X_DB2_IS_VARLEN            */
#define X_COMP_OPCODE_PUSH_NTV_VECTOR_AS_BINARY                      0x000000CFL
#define X_COMP_OPCODE_PUSH_VARLEN_NTV_VECTOR_AS_BINARY               0x000000D0L       /* X_DB2_IS_VARLEN            */
#define X_COMP_OPCODE_PUSH_UCS2_NTV_VECTOR_AS_STRING                 0x000000D1L       /* X_DB2_IS_UCS2              */
#define X_COMP_OPCODE_PUSH_UCS2_VARLEN_NTV_VECTOR_AS_STRING          0x000000D2L       /* X_DB2_IS_UCS2_VARLEN       */
#define X_COMP_OPCODE_PUSH_UTF16_NTV_VECTOR_AS_STRING                0x000000D3L       /* X_DB2_IS_UTF16             */
#define X_COMP_OPCODE_PUSH_UTF16_VARLEN_NTV_VECTOR_AS_STRING         0x000000D4L       /* X_DB2_IS_UTF16_VARLEN      */
#define X_COMP_OPCODE_PUSH_DATE_NTV_VECTOR_AS_DATE                   0x000000D5L       /* X_DB2_IS_DATE_ISO, _JIS    */
#define X_COMP_OPCODE_PUSH_USA_DATE_NTV_VECTOR_AS_DATE               0x000000D6L       /* X_DB2_IS_DATE_USA          */
#define X_COMP_OPCODE_PUSH_EUR_DATE_NTV_VECTOR_AS_DATE               0x000000D7L       /* X_DB2_IS_DATE_EUR          */
#define X_COMP_OPCODE_PUSH_MDY_DATE_NTV_VECTOR_AS_DATE               0x000000D8L       /* X_DB2_IS_DATE_MDY_xxx      */
#define X_COMP_OPCODE_PUSH_DMY_DATE_NTV_VECTOR_AS_DATE               0x000000D9L       /* X_DB2_IS_DATE_DMY_xxx      */
#define X_COMP_OPCODE_PUSH_YMD_DATE_NTV_VECTOR_AS_DATE               0x000000DAL       /* X_DB2_IS_DATE_YMD_xxx      */
#define X_COMP_OPCODE_PUSH_JULIAN_NTV_VECTOR_AS_DATE                 0x000000DBL       /* X_DB2_IS_DATE_JUL_xxx      */
#define X_COMP_OPCODE_PUSH_TIME_NTV_VECTOR_AS_TIME                   0x000000DCL       /* X_DB2_IS_DATE_ISO          */
#define X_COMP_OPCODE_PUSH_USA_TIME_NTV_VECTOR_AS_TIME               0x000000DDL       /* X_DB2_IS_TIME_USA          */
#define X_COMP_OPCODE_PUSH_DATETIME_NTV_VECTOR_AS_DATETIME           0x000000DEL
#define X_COMP_OPCODE_PUSH_RECORD_VECTOR_AS_STACK_VECTOR             0x000000DFL

/* Evaluated Vector PUSH instructions 0x00E0 - 0x00FF (Last 0x00F2) */
#define X_COMP_OPCODE_PUSH_PACKED_RESULT_VECTOR_AS_STACK_VECTOR      0x000000E0L
#define X_COMP_OPCODE_PUSH_PACKED_RESULT_VECTOR2_AS_STACK_VECTOR     0x000000E1L
#define X_COMP_OPCODE_PUSH_SIGNED_RESULT_VECTOR_AS_STACK_VECTOR      0x000000E2L
#define X_COMP_OPCODE_PUSH_SIGNED_RESULT_VECTOR2_AS_STACK_VECTOR     0x000000E3L
#define X_COMP_OPCODE_PUSH_INT8_RESULT_VECTOR_AS_STACK_VECTOR        0x000000E4L
#define X_COMP_OPCODE_PUSH_INTU8_RESULT_VECTOR_AS_STACK_VECTOR       0x000000E5L
#define X_COMP_OPCODE_PUSH_INT16_RESULT_VECTOR_AS_STACK_VECTOR       0x000000E6L
#define X_COMP_OPCODE_PUSH_INT32_RESULT_VECTOR_AS_STACK_VECTOR       0x000000E7L
#define X_COMP_OPCODE_PUSH_INT64_RESULT_VECTOR_AS_STACK_VECTOR       0x000000E8L
#define X_COMP_OPCODE_PUSH_FLOAT32_RESULT_VECTOR_AS_STACK_VECTOR     0x000000E9L
#define X_COMP_OPCODE_PUSH_FLOAT64_RESULT_VECTOR_AS_STACK_VECTOR     0x000000EAL
#define X_COMP_OPCODE_PUSH_ALPHA_RESULT_VECTOR_AS_STACK_VECTOR       0x000000EBL
#define X_COMP_OPCODE_PUSH_STRING_RESULT_VECTOR_AS_STACK_VECTOR      0x000000ECL
#define X_COMP_OPCODE_PUSH_BINARY_RESULT_VECTOR_AS_STACK_VECTOR      0x000000EDL
#define X_COMP_OPCODE_PUSH_BLOB_RESULT_VECTOR_AS_STACK_VECTOR        0x000000EEL
#define X_COMP_OPCODE_PUSH_CLOB_RESULT_VECTOR_AS_STACK_VECTOR        0x000000EFL
#define X_COMP_OPCODE_PUSH_DATE_RESULT_VECTOR_AS_STACK_VECTOR        0x000000F0L
#define X_COMP_OPCODE_PUSH_TIME_RESULT_VECTOR_AS_STACK_VECTOR        0x000000F1L
#define X_COMP_OPCODE_PUSH_DATETIME_RESULT_VECTOR_AS_STACK_VECTOR    0x000000F2L
#define X_COMP_OPCODE_PUSH_BOOLEAN_RESULT_VECTOR_AS_STACK_VECTOR     0x000000F3L
#define X_COMP_OPCODE_PUSH_SHORT_CHAR_VECTOR_AS_STRING               0x000000F4L
#define X_COMP_OPCODE_PUSH_SHORT_CHAR_VECTOR_AS_VARIANT              0x000000F5L
#define X_COMP_OPCODE_PUSH_SHORT_CHAR_STACK_VECTOR_AS_STRING         0x000000F6L
#define X_COMP_OPCODE_PUSH_SHORT_CHAR_STACK_VECTOR_AS_VARIANT        0x000000F7L
#define X_COMP_OPCODE_PUSH_UTF16_STRING_HIVAL                        0x000000F8L
#define X_COMP_OPCODE_PUSH_UTF16_STRING_LOVAL                        0x000000F9L
#define X_COMP_OPCODE_PUSH_UTF16_STRING_VECTOR_AS_UTF16_STRING       0x000000FAL
#define X_COMP_OPCODE_PUSH_UTF16_STRING_STACK_VECTOR_AS_UTF16_STRING 0x000000FBL

#define X_COMP_OPCODE_PUSH_SIGNED1_NTV_VECTOR_AS_BOOLEAN             0x000000FCL
#define X_COMP_OPCODE_PUSH_UTF16_STRING_RESULT_VECTOR_AS_STACK_VECTOR 0x000000FDL
#define X_COMP_OPCODE_PUSH_UTF16_NTV_VECTOR_AS_UTF16_STRING          0x000000FEL
#define X_COMP_OPCODE_PUSH_UTF16_VARLEN_NTV_VECTOR_AS_UTF16_STRING   0x000000FFL

/* Dispatched PUSH instructions 0x0100 - 0x011F (Last 0x0114) */
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_LONG                      0x00000100L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_LONGLONG                  0x00000101L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DOUBLE                    0x00000102L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_PACKED31                  0x00000103L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_PACKED63                  0x00000104L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DECIMAL                   0x00000105L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_INT32                     0x00000106L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_INT64                     0x00000107L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_FLOAT64                   0x00000108L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_VARIANT                   0x00000109L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_BOOLEAN                   0x0000010AL
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DATE                      0x0000010BL
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_TIME                      0x0000010CL
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DATETIME                  0x0000010DL
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_STRING                    0x0000010EL
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_BINARY                    0x0000010FL
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_SQLNULL                   0x00000110L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_REFERENCE                 0x00000111L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DYNAMIC_DECIMALS_INT32    0x00000112L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DYNAMIC_PRECISION_INT32   0x00000113L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_UTF16_STRING              0x00000114L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_GREGORIAN_DAY             0x00000115L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_GREGORIAN_YEAR            0x00000116L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_GREGORIAN_MONTH           0x00000117L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_GREGORIAN_MONTHDAY        0x00000118L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_GREGORIAN_YEARMONTH       0x00000119L
#define X_COMP_OPCODE_PUSH_DISPATCH_GET_AS_DURATION                  0x0000011AL

#define X_COMP_OPCODE_PUSH_UTF8_NTV_VECTOR_AS_UTF16_STRING           0x0000011BL
#define X_COMP_OPCODE_PUSH_UTF8_VARLEN_NTV_VECTOR_AS_UTF16_STRING    0x0000011CL
#define X_COMP_OPCODE_PUSH_UDC_VECTOR_AS_STACK_VECTOR                0x0000011DL

/* Only spare values in this range are 11E and 11F */

/* COERSION instructions 0x0120 - 0x01AF (Last 0x01A5) */
#define X_COMP_OPCODE_COERCE_LONG_TO_LONGLONG                        0x00000120L
#define X_COMP_OPCODE_COERCE_LONG_TO_DOUBLE                          0x00000121L
#define X_COMP_OPCODE_COERCE_LONG_TO_PACKED31                        0x00000122L
#define X_COMP_OPCODE_COERCE_LONG_TO_PACKED63                        0x00000123L
#define X_COMP_OPCODE_COERCE_LONG_TO_DECIMAL                         0x00000124L
#define X_COMP_OPCODE_COERCE_LONG_TO_INT32                           0x00000125L
#define X_COMP_OPCODE_COERCE_LONG_TO_INT64                           0x00000126L
#define X_COMP_OPCODE_COERCE_LONG_TO_FLOAT64                         0x00000127L
#define X_COMP_OPCODE_COERCE_LONG_TO_VARIANT                         0x00000128L
#define X_COMP_OPCODE_COERCE_LONG_TO_BOOLEAN                         0x00000129L

#define X_COMP_OPCODE_COERCE_LONGLONG_TO_LONG                        0x0000012AL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_DOUBLE                      0x0000012BL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_PACKED31                    0x0000012CL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_PACKED63                    0x0000012DL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_DECIMAL                     0x0000012EL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_INT32                       0x0000012FL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_INT64                       0x00000130L
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_FLOAT64                     0x00000131L
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_VARIANT                     0x00000132L
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_BOOLEAN                     0x00000133L

#define X_COMP_OPCODE_COERCE_DOUBLE_TO_LONG                          0x00000134L
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_LONGLONG                      0x00000135L
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_PACKED31                      0x00000136L
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_PACKED63                      0x00000137L
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_DECIMAL                       0x00000138L
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_INT32                         0x00000139L
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_INT64                         0x0000013AL
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_FLOAT64                       0x0000013BL
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_VARIANT                       0x0000013CL
#define X_COMP_OPCODE_COERCE_DOUBLE_TO_BOOLEAN                       0x0000013DL

#define X_COMP_OPCODE_COERCE_PACKED31_TO_LONG                        0x0000013EL
#define X_COMP_OPCODE_COERCE_PACKED31_TO_LONGLONG                    0x0000013FL
#define X_COMP_OPCODE_COERCE_PACKED31_TO_DOUBLE                      0x00000140L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_PACKED63                    0x00000141L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_DECIMAL                     0x00000142L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_INT32                       0x00000143L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_INT64                       0x00000144L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_FLOAT64                     0x00000145L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_VARIANT                     0x00000146L
#define X_COMP_OPCODE_COERCE_PACKED31_TO_BOOLEAN                     0x00000147L

#define X_COMP_OPCODE_COERCE_PACKED63_TO_LONG                        0x00000148L
#define X_COMP_OPCODE_COERCE_PACKED63_TO_LONGLONG                    0x00000149L
#define X_COMP_OPCODE_COERCE_PACKED63_TO_DOUBLE                      0x0000014AL
#define X_COMP_OPCODE_COERCE_PACKED63_TO_PACKED31                    0x0000014BL
#define X_COMP_OPCODE_COERCE_PACKED63_TO_DECIMAL                     0x0000014CL
#define X_COMP_OPCODE_COERCE_PACKED63_TO_INT32                       0x0000014DL
#define X_COMP_OPCODE_COERCE_PACKED63_TO_INT64                       0x0000014EL
#define X_COMP_OPCODE_COERCE_PACKED63_TO_FLOAT64                     0x0000014FL
#define X_COMP_OPCODE_COERCE_PACKED63_TO_VARIANT                     0x00000150L
#define X_COMP_OPCODE_COERCE_PACKED63_TO_BOOLEAN                     0x00000151L

#define X_COMP_OPCODE_COERCE_DECIMAL_TO_LONG                         0x00000152L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_LONGLONG                     0x00000153L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_DOUBLE                       0x00000154L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_PACKED31                     0x00000155L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_PACKED63                     0x00000156L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_INT32                        0x00000157L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_INT64                        0x00000158L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_FLOAT64                      0x00000159L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_VARIANT                      0x0000015AL
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_BOOLEAN                      0x0000015BL

#define X_COMP_OPCODE_COERCE_INT32_TO_LONG                           0x0000015CL
#define X_COMP_OPCODE_COERCE_INT32_TO_LONGLONG                       0x0000015DL
#define X_COMP_OPCODE_COERCE_INT32_TO_DOUBLE                         0x0000015EL
#define X_COMP_OPCODE_COERCE_INT32_TO_PACKED31                       0x0000015FL
#define X_COMP_OPCODE_COERCE_INT32_TO_PACKED63                       0x00000160L
#define X_COMP_OPCODE_COERCE_INT32_TO_DECIMAL                        0x00000161L
#define X_COMP_OPCODE_COERCE_INT32_TO_INT64                          0x00000162L
#define X_COMP_OPCODE_COERCE_INT32_TO_FLOAT64                        0x00000163L
#define X_COMP_OPCODE_COERCE_INT32_TO_VARIANT                        0x00000164L
#define X_COMP_OPCODE_COERCE_INT32_TO_BOOLEAN                        0x00000165L

#define X_COMP_OPCODE_COERCE_INT64_TO_LONG                           0x00000166L
#define X_COMP_OPCODE_COERCE_INT64_TO_LONGLONG                       0x00000167L
#define X_COMP_OPCODE_COERCE_INT64_TO_DOUBLE                         0x00000168L
#define X_COMP_OPCODE_COERCE_INT64_TO_PACKED31                       0x00000169L
#define X_COMP_OPCODE_COERCE_INT64_TO_PACKED63                       0x0000016AL
#define X_COMP_OPCODE_COERCE_INT64_TO_DECIMAL                        0x0000016BL
#define X_COMP_OPCODE_COERCE_INT64_TO_INT32                          0x0000016CL
#define X_COMP_OPCODE_COERCE_INT64_TO_FLOAT64                        0x0000016DL
#define X_COMP_OPCODE_COERCE_INT64_TO_VARIANT                        0x0000016EL
#define X_COMP_OPCODE_COERCE_INT64_TO_BOOLEAN                        0x0000016FL

#define X_COMP_OPCODE_COERCE_FLOAT64_TO_LONG                         0x00000170L
#define X_COMP_OPCODE_COERCE_FLOAT64_TO_LONGLONG                     0x00000171L
#define X_COMP_OPCODE_COERCE_FLOAT64_TO_DECIMAL                      0x00000172L
#define X_COMP_OPCODE_COERCE_FLOAT64_TO_INT32                        0x00000173L
#define X_COMP_OPCODE_COERCE_FLOAT64_TO_INT64                        0x00000174L
#define X_COMP_OPCODE_COERCE_FLOAT64_TO_VARIANT                      0x00000175L
#define X_COMP_OPCODE_COERCE_FLOAT64_TO_BOOLEAN                      0x00000176L

#define X_COMP_OPCODE_COERCE_VARIANT_TO_LONG                         0x00000177L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_LONGLONG                     0x00000178L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_DOUBLE                       0x00000179L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_PACKED31                     0x0000017AL
#define X_COMP_OPCODE_COERCE_VARIANT_TO_PACKED63                     0x0000017BL
#define X_COMP_OPCODE_COERCE_VARIANT_TO_DECIMAL                      0x0000017CL
#define X_COMP_OPCODE_COERCE_VARIANT_TO_INT32                        0x0000017DL
#define X_COMP_OPCODE_COERCE_VARIANT_TO_INT64                        0x0000017EL
#define X_COMP_OPCODE_COERCE_VARIANT_TO_FLOAT64                      0x0000017FL
#define X_COMP_OPCODE_COERCE_VARIANT_TO_BOOLEAN                      0x00000180L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_STRING                       0x00000181L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_BINARY                       0x00000182L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_DATE                         0x00000183L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_TIME                         0x00000184L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_DATETIME                     0x00000185L

#define X_COMP_OPCODE_COERCE_DATE_TO_DATETIME                        0x00000186L
#define X_COMP_OPCODE_COERCE_DATE_TO_VARIANT                         0x00000187L
#define X_COMP_OPCODE_COERCE_TIME_TO_DATETIME                        0x00000188L
#define X_COMP_OPCODE_COERCE_TIME_TO_VARIANT                         0x00000189L
#define X_COMP_OPCODE_COERCE_DATETIME_TO_DATE                        0x0000018AL
#define X_COMP_OPCODE_COERCE_DATETIME_TO_TIME                        0x0000018BL
#define X_COMP_OPCODE_COERCE_DATETIME_TO_VARIANT                     0x0000018CL

#define X_COMP_OPCODE_COERCE_BINARY_TO_VARIANT                       0x0000018DL
#define X_COMP_OPCODE_COERCE_STRING_TO_VARIANT                       0x0000018EL

#define X_COMP_OPCODE_COERCE_BOOLEAN_TO_INT32                        0x0000018FL
#define X_COMP_OPCODE_COERCE_BOOLEAN_TO_STRING                       0x00000190L
#define X_COMP_OPCODE_COERCE_BOOLEAN_TO_VARIANT                      0x00000191L

#define X_COMP_OPCODE_COERCE_DECIMAL_TO_PRECISE_DECIMAL              0x00000192L

#define X_COMP_OPCODE_COERCE_FIXED_CHAR_TO_STRING                    0x00000193L
#define X_COMP_OPCODE_COERCE_FIXED_CHAR_TO_VARIANT                   0x00000194L

#define X_COMP_OPCODE_COERCE_PACKED31_TO_SQLNULL                     0x00000195L
#define X_COMP_OPCODE_COERCE_PACKED63_TO_SQLNULL                     0x00000196L
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_SQLNULL                      0x00000197L
#define X_COMP_OPCODE_COERCE_VARIANT_TO_SQLNULL                      0x00000198L
#define X_COMP_OPCODE_COERCE_STRING_TO_SQLNULL                       0x00000199L
#define X_COMP_OPCODE_COERCE_BINARY_TO_SQLNULL                       0x0000019AL

#define X_COMP_OPCODE_COERCE_LONG_TO_STRING                          0x0000019BL
#define X_COMP_OPCODE_COERCE_LONGLONG_TO_STRING                      0x0000019CL
#define X_COMP_OPCODE_COERCE_DECIMAL_TO_STRING                       0x0000019DL
#define X_COMP_OPCODE_COERCE_INT32_TO_STRING                         0x0000019EL
#define X_COMP_OPCODE_COERCE_INT64_TO_STRING                         0x0000019FL
#define X_COMP_OPCODE_COERCE_INT32_TO_ENUMERATION                    0x000001A0L
#define X_COMP_OPCODE_COERCE_STRING_TO_BOOLEAN                       0x000001A1L
#define X_COMP_OPCODE_COERCE_STRING_TO_UTF16_STRING                  0x000001A2L
#define X_COMP_OPCODE_COERCE_UTF16_STRING_TO_STRING                  0x000001A3L
#define X_COMP_OPCODE_COERCE_UTF16_STRING_TO_SQLNULL                 0x000001A4L
#define X_COMP_OPCODE_COERCE_FIXED_CHAR_TO_UTF16_STRING              0x000001A5L
#define X_COMP_OPCODE_COERCE_MTXT_FIXED_CHAR_TO_UTF16_STRING         0x000001A6L
#define X_COMP_OPCODE_COERCE_UTF16_STRING_TO_VARIANT                 0x000001A7L

/* PULL instructions 0x01B0 - 0x035F (Last 0x03DF) */
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LONG                   0x000001B0L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LONG_A                 0x000001B1L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LONG_B                 0x000001B2L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LONGLONG               0x000001B3L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LONGLONG_A             0x000001B4L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LONGLONG_B             0x000001B5L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_DOUBLE                 0x000001B6L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_DOUBLE_A               0x000001B7L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_DOUBLE_B               0x000001B8L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_PACKED31               0x000001B9L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_PACKED31_A             0x000001BAL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_PACKED31_B             0x000001BBL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_PACKED63               0x000001BCL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_DECIMAL                0x000001BDL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_INT32                  0x000001BEL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_INT32_A                0x000001BFL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_INT32_B                0x000001C0L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_INT64                  0x000001C1L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_INT64_A                0x000001C2L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_INT64_B                0x000001C3L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_FLOAT64                0x000001C4L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_VARIANT                0x000001C5L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_NULL                   0x000001C6L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_HIVAL                  0x000001C7L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR_FROM_LOVAL                  0x000001C8L

#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LONG                  0x000001D0L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LONG_A                0x000001D1L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LONG_B                0x000001D2L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LONGLONG              0x000001D3L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LONGLONG_A            0x000001D4L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LONGLONG_B            0x000001D5L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_DOUBLE                0x000001D6L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_DOUBLE_A              0x000001D7L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_DOUBLE_B              0x000001D8L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_PACKED31              0x000001D9L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_PACKED31_A            0x000001DAL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_PACKED31_B            0x000001DBL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_PACKED63              0x000001DCL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_DECIMAL               0x000001DDL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_INT32                 0x000001DEL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_INT32_A               0x000001DFL
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_INT32_B               0x000001E0L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_INT64                 0x000001E1L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_INT64_A               0x000001E2L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_INT64_B               0x000001E3L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_FLOAT64               0x000001E4L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_VARIANT               0x000001E5L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_NULL                  0x000001E6L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_SQLNULL               0x000001E7L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_HIVAL                 0x000001E8L
#define X_COMP_OPCODE_PULL_PACKED_VECTOR2_FROM_LOVAL                 0x000001E9L

#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LONG                   0x000001F0L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LONG_A                 0x000001F1L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LONG_B                 0x000001F2L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LONGLONG               0x000001F3L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LONGLONG_A             0x000001F4L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LONGLONG_B             0x000001F5L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_DOUBLE                 0x000001F6L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_DOUBLE_A               0x000001F7L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_DOUBLE_B               0x000001F8L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_PACKED31               0x000001F9L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_PACKED31_A             0x000001FAL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_PACKED31_B             0x000001FBL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_PACKED63               0x000001FCL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_DECIMAL                0x000001FDL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_INT32                  0x000001FEL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_INT32_A                0x000001FFL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_INT32_B                0x00000200L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_INT64                  0x00000201L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_INT64_A                0x00000202L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_INT64_B                0x00000203L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_FLOAT64                0x00000204L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_VARIANT                0x00000205L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_NULL                   0x00000206L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_HIVAL                  0x00000207L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR_FROM_LOVAL                  0x00000208L

#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LONG                  0x00000210L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LONG_A                0x00000211L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LONG_B                0x00000212L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LONGLONG              0x00000213L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LONGLONG_A            0x00000214L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LONGLONG_B            0x00000215L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_DOUBLE                0x00000216L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_DOUBLE_A              0x00000217L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_DOUBLE_B              0x00000218L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_PACKED31              0x00000219L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_PACKED31_A            0x0000021AL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_PACKED31_B            0x0000021BL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_PACKED63              0x0000021CL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_DECIMAL               0x0000021DL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_INT32                 0x0000021EL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_INT32_A               0x0000021FL
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_INT32_B               0x00000220L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_INT64                 0x00000221L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_INT64_A               0x00000222L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_INT64_B               0x00000223L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_FLOAT64               0x00000224L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_VARIANT               0x00000225L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_NULL                  0x00000226L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_SQLNULL               0x00000227L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_HIVAL                 0x00000228L
#define X_COMP_OPCODE_PULL_SIGNED_VECTOR2_FROM_LOVAL                 0x00000229L

#define X_COMP_OPCODE_PULL_INT8_VECTOR_FROM_INT32                    0x00000230L
#define X_COMP_OPCODE_PULL_INT8_VECTOR_FROM_NULL                     0x00000231L
#define X_COMP_OPCODE_PULL_INT8_VECTOR_FROM_SQLNULL                  0x00000232L
#define X_COMP_OPCODE_PULL_INT8_VECTOR_FROM_HIVAL                    0x00000233L
#define X_COMP_OPCODE_PULL_INT8_VECTOR_FROM_LOVAL                    0x00000234L
#define X_COMP_OPCODE_PULL_INTU8_VECTOR_FROM_INT32                   0x00000235L
#define X_COMP_OPCODE_PULL_INTU8_VECTOR_FROM_NULL                    0x00000236L
#define X_COMP_OPCODE_PULL_INTU8_VECTOR_FROM_SQLNULL                 0x00000237L
#define X_COMP_OPCODE_PULL_INTU8_VECTOR_FROM_HIVAL                   0x00000238L
#define X_COMP_OPCODE_PULL_INTU8_VECTOR_FROM_LOVAL                   0x00000239L
#define X_COMP_OPCODE_PULL_INT16_VECTOR_FROM_INT32                   0x0000023AL
#define X_COMP_OPCODE_PULL_INT16_VECTOR_FROM_NULL                    0x0000023BL
#define X_COMP_OPCODE_PULL_INT16_VECTOR_FROM_SQLNULL                 0x0000023CL
#define X_COMP_OPCODE_PULL_INT16_VECTOR_FROM_HIVAL                   0x0000023DL
#define X_COMP_OPCODE_PULL_INT16_VECTOR_FROM_LOVAL                   0x0000023EL
#define X_COMP_OPCODE_PULL_INT32_VECTOR_FROM_INT32                   0x0000023FL
#define X_COMP_OPCODE_PULL_INT32_VECTOR_FROM_NULL                    0x00000240L
#define X_COMP_OPCODE_PULL_INT32_VECTOR_FROM_SQLNULL                 0x00000241L
#define X_COMP_OPCODE_PULL_INT32_VECTOR_FROM_HIVAL                   0x00000242L
#define X_COMP_OPCODE_PULL_INT32_VECTOR_FROM_LOVAL                   0x00000243L
#define X_COMP_OPCODE_PULL_INT64_VECTOR_FROM_INT64                   0x00000244L
#define X_COMP_OPCODE_PULL_INT64_VECTOR_FROM_NULL                    0x00000245L
#define X_COMP_OPCODE_PULL_INT64_VECTOR_FROM_SQLNULL                 0x00000246L
#define X_COMP_OPCODE_PULL_INT64_VECTOR_FROM_HIVAL                   0x00000247L
#define X_COMP_OPCODE_PULL_INT64_VECTOR_FROM_LOVAL                   0x00000248L
#define X_COMP_OPCODE_PULL_FLOAT32_VECTOR_FROM_FLOAT64               0x00000249L
#define X_COMP_OPCODE_PULL_FLOAT32_VECTOR_FROM_NULL                  0x0000024AL
#define X_COMP_OPCODE_PULL_FLOAT32_VECTOR_FROM_SQLNULL               0x0000024BL
#define X_COMP_OPCODE_PULL_FLOAT32_VECTOR_FROM_HIVAL                 0x0000024CL
#define X_COMP_OPCODE_PULL_FLOAT32_VECTOR_FROM_LOVAL                 0x0000024DL
#define X_COMP_OPCODE_PULL_FLOAT64_VECTOR_FROM_FLOAT64               0x0000024EL
#define X_COMP_OPCODE_PULL_FLOAT64_VECTOR_FROM_NULL                  0x0000024FL
#define X_COMP_OPCODE_PULL_FLOAT64_VECTOR_FROM_SQLNULL               0x00000250L
#define X_COMP_OPCODE_PULL_FLOAT64_VECTOR_FROM_HIVAL                 0x00000251L
#define X_COMP_OPCODE_PULL_FLOAT64_VECTOR_FROM_LOVAL                 0x00000252L
#define X_COMP_OPCODE_PULL_BOOLEAN_VECTOR_FROM_BOOLEAN               0x00000253L
#define X_COMP_OPCODE_PULL_BOOLEAN_VECTOR_FROM_NULL                  0x00000254L
#define X_COMP_OPCODE_PULL_BOOLEAN_VECTOR_FROM_SQLNULL               0x00000255L
#define X_COMP_OPCODE_PULL_BOOLEAN_VECTOR_FROM_HIVAL                 0x00000256L
#define X_COMP_OPCODE_PULL_BOOLEAN_VECTOR_FROM_LOVAL                 0x00000257L
#define X_COMP_OPCODE_PULL_DATE_VECTOR_FROM_DATE                     0x00000258L
#define X_COMP_OPCODE_PULL_DATE_VECTOR_FROM_DATETIME                 0x00000259L
#define X_COMP_OPCODE_PULL_DATE_VECTOR_FROM_NULL                     0x0000025AL
#define X_COMP_OPCODE_PULL_DATE_VECTOR_FROM_SQLNULL                  0x0000025BL
#define X_COMP_OPCODE_PULL_DATE_VECTOR_FROM_HIVAL                    0x0000025CL
#define X_COMP_OPCODE_PULL_DATE_VECTOR_FROM_LOVAL                    0x0000025DL
#define X_COMP_OPCODE_PULL_TIME_VECTOR_FROM_TIME                     0x0000025EL
#define X_COMP_OPCODE_PULL_TIME_VECTOR_FROM_DATETIME                 0x0000025FL
#define X_COMP_OPCODE_PULL_TIME_VECTOR_FROM_NULL                     0x00000260L
#define X_COMP_OPCODE_PULL_TIME_VECTOR_FROM_SQLNULL                  0x00000261L
#define X_COMP_OPCODE_PULL_TIME_VECTOR_FROM_HIVAL                    0x00000262L
#define X_COMP_OPCODE_PULL_TIME_VECTOR_FROM_LOVAL                    0x00000263L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_DATE                 0x00000264L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_TIME                 0x00000265L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_DATETIME             0x00000266L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_NULL                 0x00000267L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_SQLNULL              0x00000268L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_HIVAL                0x00000269L
#define X_COMP_OPCODE_PULL_DATETIME_VECTOR_FROM_LOVAL                0x0000026AL
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_STRING                  0x0000026BL
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_VARIANT                 0x0000026CL
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_NULL                    0x0000026DL
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_HIVAL                   0x0000026EL
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_LOVAL                   0x0000026FL
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_NAVAIL                  0x00000270L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_STRING                 0x00000271L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_VARIANT                0x00000272L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_NULL                   0x00000273L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_SQLNULL                0x00000274L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_HIVAL                  0x00000275L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_LOVAL                  0x00000276L
#define X_COMP_OPCODE_PULL_STRING_VECTOR_FROM_NAVAIL                 0x00000277L
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_STRING                 0x00000278L
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_BINARY                 0x00000279L
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_VARIANT                0x0000027AL
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_NULL                   0x0000027BL
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_SQLNULL                0x0000027CL
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_HIVAL                  0x0000027DL
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_LOVAL                  0x0000027EL
#define X_COMP_OPCODE_PULL_BINARY_VECTOR_FROM_NAVAIL                 0x0000027FL
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_STRING                    0x00000280L
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_VARIANT                   0x00000281L
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_NULL                      0x00000282L
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_SQLNULL                   0x00000283L
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_HIVAL                     0x00000284L
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_LOVAL                     0x00000285L
#define X_COMP_OPCODE_PULL_LOB_VECTOR_FROM_NAVAIL                    0x00000286L
#define X_COMP_OPCODE_PULL_ALPHA_VECTOR_FROM_STRING_PLUS             0x00000287L
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_STRING             0x00000288L
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_VARIANT            0x00000289L
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_NULL               0x0000028AL
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_SQLNULL            0x0000028BL
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_HIVAL              0x0000028CL
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_LOVAL              0x0000028DL
#define X_COMP_OPCODE_PULL_SHORT_CHAR_VECTOR_FROM_NAVAIL             0x0000028EL

#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_UTF16_STRING     0x00000290L
#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_VARIANT          0x00000291L
#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_NULL             0x00000292L
#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_SQLNULL          0x00000293L
#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_HIVAL            0x00000294L
#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_LOVAL            0x00000295L
#define X_COMP_OPCODE_PULL_UTF16_STRING_VECTOR_FROM_NAVAIL           0x00000296L

#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_LONG                    0x000002A0L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_LONGLONG                0x000002A1L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_DOUBLE                  0x000002A2L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_PACKED31                0x000002A3L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_PACKED63                0x000002A4L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_DECIMAL                 0x000002A5L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_INT32                   0x000002A6L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_INT64                   0x000002A7L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_FLOAT64                 0x000002A8L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_VARIANT                 0x000002A9L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_BOOLEAN                 0x000002AAL
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_DATE                    0x000002ABL
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_TIME                    0x000002ACL
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_DATETIME                0x000002ADL
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_STRING                  0x000002AEL
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_BINARY                  0x000002AFL
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_NULL                    0x000002B0L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_SQLNULL                 0x000002B1L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_REFERENCE               0x000002B2L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_NAVAIL                  0x000002B3L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_UTF16_STRING            0x000002B4L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_GREGORIAN_DAY           0x000002B5L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_GREGORIAN_YEAR          0x000002B6L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_GREGORIAN_MONTH         0x000002B7L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_GREGORIAN_MONTHDAY      0x000002B8L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_GREGORIAN_YEARMONTH     0x000002B9L
#define X_COMP_OPCODE_PULL_DISPATCH_SET_FROM_DURATION                0x000002BAL

#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_LONG                  0x000002C0L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_LONGLONG              0x000002C1L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_DOUBLE                0x000002C2L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_PACKED31              0x000002C3L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_PACKED63              0x000002C4L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_DECIMAL               0x000002C5L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_INT32                 0x000002C6L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_INT64                 0x000002C7L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_FLOAT64               0x000002C8L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_VARIANT               0x000002C9L
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_BOOLEAN               0x000002CAL
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_DATE                  0x000002CBL
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_TIME                  0x000002CCL
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_DATETIME              0x000002CDL
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_STRING                0x000002CEL
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_BINARY                0x000002CFL
#define X_COMP_OPCODE_PULL_RESULT_VARIANT_FROM_UTF16_STRING          0x000002D0L

#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR_FROM_STACK_VECTOR        0x000002E0L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR_FROM_STACK_VECTOR_A      0x000002E1L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR_FROM_STACK_VECTOR_B      0x000002E2L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR2_FROM_STACK_VECTOR       0x000002E3L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR2_FROM_STACK_VECTOR_A     0x000002E4L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR2_FROM_STACK_VECTOR_B     0x000002E5L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR2_FROM_STACK_VECTOR_C     0x000002E6L
#define X_COMP_OPCODE_PULL_IDENTICAL_VECTOR2_FROM_STACK_VECTOR_D     0x000002E7L

/* LOGICAL instructions 0x0300 - 0x031F (Last 0x030B) */
#define X_COMP_OPCODE_LOGICAL_NOT                                    0x00000300L
#define X_COMP_OPCODE_LOGICAL_OR                                     0x00000301L
#define X_COMP_OPCODE_LOGICAL_AND                                    0x00000302L
#define X_COMP_OPCODE_LOGICAL_BEGIN_ORIF                             0x00000303L
#define X_COMP_OPCODE_LOGICAL_END_ORIF                               0x00000304L
#define X_COMP_OPCODE_LOGICAL_BEGIN_ANDIF                            0x00000305L
#define X_COMP_OPCODE_LOGICAL_END_ANDIF                              0x00000306L
#define X_COMP_OPCODE_LOGICAL_IS_SQLNULL                             0x00000307L
#define X_COMP_OPCODE_LOGICAL_IS_NOT_SQLNULL                         0x00000308L
#define X_COMP_OPCODE_LOGICAL_IF                                     0x00000309L
#define X_COMP_OPCODE_LOGICAL_ELSE                                   0x0000030AL
#define X_COMP_OPCODE_LOGICAL_ENDIF                                  0x0000030BL
#define X_COMP_OPCODE_LOGICAL_WHEN_BLOCK_BEGIN                       0x0000030CL
#define X_COMP_OPCODE_LOGICAL_WHEN_BLOCK_END                         0x0000030DL
#define X_COMP_OPCODE_LOGICAL_OTHERWISE_BLOCK_BEGIN                  0x0000030EL
#define X_COMP_OPCODE_LOGICAL_OTHERWISE_BLOCK_END                    0x0000030FL


/* COMPARE instructions 0x0320 - 0x038F (Last 0x037C) */
#define X_COMP_OPCODE_COMPARE_LONG_EQ_LONG                           0x00000320L
#define X_COMP_OPCODE_COMPARE_LONG_LT_LONG                           0x00000321L
#define X_COMP_OPCODE_COMPARE_LONG_LE_LONG                           0x00000322L
#define X_COMP_OPCODE_COMPARE_LONG_GT_LONG                           0x00000323L
#define X_COMP_OPCODE_COMPARE_LONG_GE_LONG                           0x00000324L
#define X_COMP_OPCODE_COMPARE_LONG_NE_LONG                           0x00000325L
#define X_COMP_OPCODE_COMPARE_LONGLONG_EQ_LONGLONG                   0x00000326L
#define X_COMP_OPCODE_COMPARE_LONGLONG_LT_LONGLONG                   0x00000327L
#define X_COMP_OPCODE_COMPARE_LONGLONG_LE_LONGLONG                   0x00000328L
#define X_COMP_OPCODE_COMPARE_LONGLONG_GT_LONGLONG                   0x00000329L
#define X_COMP_OPCODE_COMPARE_LONGLONG_GE_LONGLONG                   0x0000032AL
#define X_COMP_OPCODE_COMPARE_LONGLONG_NE_LONGLONG                   0x0000032BL
#define X_COMP_OPCODE_COMPARE_DOUBLE_EQ_DOUBLE                       0x0000032CL
#define X_COMP_OPCODE_COMPARE_DOUBLE_LT_DOUBLE                       0x0000032DL
#define X_COMP_OPCODE_COMPARE_DOUBLE_LE_DOUBLE                       0x0000032EL
#define X_COMP_OPCODE_COMPARE_DOUBLE_GT_DOUBLE                       0x0000032FL
#define X_COMP_OPCODE_COMPARE_DOUBLE_GE_DOUBLE                       0x00000330L
#define X_COMP_OPCODE_COMPARE_DOUBLE_NE_DOUBLE                       0x00000331L
#define X_COMP_OPCODE_COMPARE_PACKED31_EQ_PACKED31                   0x00000332L
#define X_COMP_OPCODE_COMPARE_PACKED31_LT_PACKED31                   0x00000333L
#define X_COMP_OPCODE_COMPARE_PACKED31_LE_PACKED31                   0x00000334L
#define X_COMP_OPCODE_COMPARE_PACKED31_GT_PACKED31                   0x00000335L
#define X_COMP_OPCODE_COMPARE_PACKED31_GE_PACKED31                   0x00000336L
#define X_COMP_OPCODE_COMPARE_PACKED31_NE_PACKED31                   0x00000337L
#define X_COMP_OPCODE_COMPARE_PACKED63_EQ_PACKED63                   0x00000338L
#define X_COMP_OPCODE_COMPARE_PACKED63_LT_PACKED63                   0x00000339L
#define X_COMP_OPCODE_COMPARE_PACKED63_LE_PACKED63                   0x0000033AL
#define X_COMP_OPCODE_COMPARE_PACKED63_GT_PACKED63                   0x0000033BL
#define X_COMP_OPCODE_COMPARE_PACKED63_GE_PACKED63                   0x0000033CL
#define X_COMP_OPCODE_COMPARE_PACKED63_NE_PACKED63                   0x0000033DL
#define X_COMP_OPCODE_COMPARE_DECIMAL_EQ_DECIMAL                     0x0000033EL
#define X_COMP_OPCODE_COMPARE_DECIMAL_LT_DECIMAL                     0x0000033FL
#define X_COMP_OPCODE_COMPARE_DECIMAL_LE_DECIMAL                     0x00000340L
#define X_COMP_OPCODE_COMPARE_DECIMAL_GT_DECIMAL                     0x00000341L
#define X_COMP_OPCODE_COMPARE_DECIMAL_GE_DECIMAL                     0x00000342L
#define X_COMP_OPCODE_COMPARE_DECIMAL_NE_DECIMAL                     0x00000343L
#define X_COMP_OPCODE_COMPARE_INT32_EQ_INT32                         0x00000344L
#define X_COMP_OPCODE_COMPARE_INT32_LT_INT32                         0x00000345L
#define X_COMP_OPCODE_COMPARE_INT32_LE_INT32                         0x00000346L
#define X_COMP_OPCODE_COMPARE_INT32_GT_INT32                         0x00000347L
#define X_COMP_OPCODE_COMPARE_INT32_GE_INT32                         0x00000348L
#define X_COMP_OPCODE_COMPARE_INT32_NE_INT32                         0x00000349L
#define X_COMP_OPCODE_COMPARE_INT64_EQ_INT64                         0x0000034AL
#define X_COMP_OPCODE_COMPARE_INT64_LT_INT64                         0x0000034BL
#define X_COMP_OPCODE_COMPARE_INT64_LE_INT64                         0x0000034CL
#define X_COMP_OPCODE_COMPARE_INT64_GT_INT64                         0x0000034DL
#define X_COMP_OPCODE_COMPARE_INT64_GE_INT64                         0x0000034EL
#define X_COMP_OPCODE_COMPARE_INT64_NE_INT64                         0x0000034FL
#define X_COMP_OPCODE_COMPARE_FLOAT64_EQ_FLOAT64                     0x00000350L
#define X_COMP_OPCODE_COMPARE_FLOAT64_LT_FLOAT64                     0x00000351L
#define X_COMP_OPCODE_COMPARE_FLOAT64_LE_FLOAT64                     0x00000352L
#define X_COMP_OPCODE_COMPARE_FLOAT64_GT_FLOAT64                     0x00000353L
#define X_COMP_OPCODE_COMPARE_FLOAT64_GE_FLOAT64                     0x00000354L
#define X_COMP_OPCODE_COMPARE_FLOAT64_NE_FLOAT64                     0x00000355L
#define X_COMP_OPCODE_COMPARE_VARIANT_EQ_VARIANT                     0x00000356L
#define X_COMP_OPCODE_COMPARE_VARIANT_LT_VARIANT                     0x00000357L
#define X_COMP_OPCODE_COMPARE_VARIANT_LE_VARIANT                     0x00000358L
#define X_COMP_OPCODE_COMPARE_VARIANT_GT_VARIANT                     0x00000359L
#define X_COMP_OPCODE_COMPARE_VARIANT_GE_VARIANT                     0x0000035AL
#define X_COMP_OPCODE_COMPARE_VARIANT_NE_VARIANT                     0x0000035BL
#define X_COMP_OPCODE_COMPARE_DATE_EQ_DATE                           0x0000035CL
#define X_COMP_OPCODE_COMPARE_DATE_LT_DATE                           0x0000035DL
#define X_COMP_OPCODE_COMPARE_DATE_LE_DATE                           0x0000035EL
#define X_COMP_OPCODE_COMPARE_DATE_GT_DATE                           0x0000035FL
#define X_COMP_OPCODE_COMPARE_DATE_GE_DATE                           0x00000360L
#define X_COMP_OPCODE_COMPARE_DATE_NE_DATE                           0x00000361L
#define X_COMP_OPCODE_COMPARE_TIME_EQ_TIME                           0x00000362L
#define X_COMP_OPCODE_COMPARE_TIME_LT_TIME                           0x00000363L
#define X_COMP_OPCODE_COMPARE_TIME_LE_TIME                           0x00000364L
#define X_COMP_OPCODE_COMPARE_TIME_GT_TIME                           0x00000365L
#define X_COMP_OPCODE_COMPARE_TIME_GE_TIME                           0x00000366L
#define X_COMP_OPCODE_COMPARE_TIME_NE_TIME                           0x00000367L
#define X_COMP_OPCODE_COMPARE_DATETIME_EQ_DATETIME                   0x00000368L
#define X_COMP_OPCODE_COMPARE_DATETIME_LT_DATETIME                   0x00000369L
#define X_COMP_OPCODE_COMPARE_DATETIME_LE_DATETIME                   0x0000036AL
#define X_COMP_OPCODE_COMPARE_DATETIME_GT_DATETIME                   0x0000036BL
#define X_COMP_OPCODE_COMPARE_DATETIME_GE_DATETIME                   0x0000036CL
#define X_COMP_OPCODE_COMPARE_DATETIME_NE_DATETIME                   0x0000036DL
#define X_COMP_OPCODE_COMPARE_STRING_EQ_STRING                       0x0000036EL
#define X_COMP_OPCODE_COMPARE_STRING_LT_STRING                       0x0000036FL
#define X_COMP_OPCODE_COMPARE_STRING_LE_STRING                       0x00000370L
#define X_COMP_OPCODE_COMPARE_STRING_GT_STRING                       0x00000371L
#define X_COMP_OPCODE_COMPARE_STRING_GE_STRING                       0x00000372L
#define X_COMP_OPCODE_COMPARE_STRING_NE_STRING                       0x00000373L
#define X_COMP_OPCODE_COMPARE_BINARY_EQ_BINARY                       0x00000374L
#define X_COMP_OPCODE_COMPARE_BINARY_LT_BINARY                       0x00000375L
#define X_COMP_OPCODE_COMPARE_BINARY_LE_BINARY                       0x00000376L
#define X_COMP_OPCODE_COMPARE_BINARY_GT_BINARY                       0x00000377L
#define X_COMP_OPCODE_COMPARE_BINARY_GE_BINARY                       0x00000378L
#define X_COMP_OPCODE_COMPARE_BINARY_NE_BINARY                       0x00000379L
#define X_COMP_OPCODE_COMPARE_BOOLEAN_EQ_BOOLEAN                     0x0000037AL
#define X_COMP_OPCODE_COMPARE_BOOLEAN_NE_BOOLEAN                     0x0000037BL
#define X_COMP_OPCODE_COMPARE_UTF16_STRING_EQ_UTF16_STRING           0x0000037CL
#define X_COMP_OPCODE_COMPARE_UTF16_STRING_LT_UTF16_STRING           0x0000037DL
#define X_COMP_OPCODE_COMPARE_UTF16_STRING_LE_UTF16_STRING           0x0000037EL
#define X_COMP_OPCODE_COMPARE_UTF16_STRING_GT_UTF16_STRING           0x0000037FL
#define X_COMP_OPCODE_COMPARE_UTF16_STRING_GE_UTF16_STRING           0x00000380L
#define X_COMP_OPCODE_COMPARE_UTF16_STRING_NE_UTF16_STRING           0x00000381L

/* IS instructions 0x038F - 0x039F (Last 0x39F) */
#define X_COMP_OPCODE_IS_UTF16_STRING_NULL                           0x0000038FL
#define X_COMP_OPCODE_IS_LONG_NULL                                   0x00000390L
#define X_COMP_OPCODE_IS_LONGLONG_NULL                               0x00000391L
#define X_COMP_OPCODE_IS_DOUBLE_NULL                                 0x00000392L
#define X_COMP_OPCODE_IS_PACKED31_NULL                               0x00000393L
#define X_COMP_OPCODE_IS_PACKED63_NULL                               0x00000394L
#define X_COMP_OPCODE_IS_DECIMAL_NULL                                0x00000395L
#define X_COMP_OPCODE_IS_INT32_NULL                                  0x00000396L
#define X_COMP_OPCODE_IS_INT64_NULL                                  0x00000397L
#define X_COMP_OPCODE_IS_FLOAT64_NULL                                0x00000398L
#define X_COMP_OPCODE_IS_VARIANT_NULL                                0x00000399L
#define X_COMP_OPCODE_IS_DATE_NULL                                   0x0000039AL
#define X_COMP_OPCODE_IS_TIME_NULL                                   0x0000039BL
#define X_COMP_OPCODE_IS_DATETIME_NULL                               0x0000039CL
#define X_COMP_OPCODE_IS_BOOLEAN_NULL                                0x0000039DL
#define X_COMP_OPCODE_IS_STRING_NULL                                 0x0000039EL
#define X_COMP_OPCODE_IS_BINARY_NULL                                 0x0000039FL

/* MATHS instructions 0x03A0 - 0x03DF (Last 0x03D0) */
#define X_COMP_OPCODE_LONG_PLUS                                      0x000003A0L
#define X_COMP_OPCODE_LONG_MINUS                                     0x000003A1L
#define X_COMP_OPCODE_LONG_DIVIDE                                    0x000003A2L
#define X_COMP_OPCODE_LONG_MULTIPLY                                  0x000003A3L
#define X_COMP_OPCODE_LONGLONG_PLUS                                  0x000003A4L
#define X_COMP_OPCODE_LONGLONG_MINUS                                 0x000003A5L
#define X_COMP_OPCODE_LONGLONG_DIVIDE                                0x000003A6L
#define X_COMP_OPCODE_LONGLONG_MULTIPLY                              0x000003A7L
#define X_COMP_OPCODE_DOUBLE_PLUS                                    0x000003A8L
#define X_COMP_OPCODE_DOUBLE_MINUS                                   0x000003A9L
#define X_COMP_OPCODE_DOUBLE_DIVIDE                                  0x000003AAL
#define X_COMP_OPCODE_DOUBLE_MULTIPLY                                0x000003ABL
#define X_COMP_OPCODE_PACKED31_PLUS                                  0x000003ACL
#define X_COMP_OPCODE_PACKED31_MINUS                                 0x000003ADL
#define X_COMP_OPCODE_PACKED31_DIVIDE                                0x000003AEL
#define X_COMP_OPCODE_PACKED31_MULTIPLY                              0x000003AFL
#define X_COMP_OPCODE_PACKED63_PLUS                                  0x000003B0L
#define X_COMP_OPCODE_PACKED63_MINUS                                 0x000003B1L
#define X_COMP_OPCODE_PACKED63_DIVIDE                                0x000003B2L
#define X_COMP_OPCODE_PACKED63_MULTIPLY                              0x000003B3L
#define X_COMP_OPCODE_DECIMAL_PLUS                                   0x000003B4L
#define X_COMP_OPCODE_DECIMAL_MINUS                                  0x000003B5L
#define X_COMP_OPCODE_DECIMAL_DIVIDE                                 0x000003B6L
#define X_COMP_OPCODE_DECIMAL_DIVIDE_FILE                            0x000003B7L
#define X_COMP_OPCODE_DECIMAL_MULTIPLY                               0x000003B8L
#define X_COMP_OPCODE_INT32_PLUS                                     0x000003B9L
#define X_COMP_OPCODE_INT32_MINUS                                    0x000003BAL
#define X_COMP_OPCODE_INT32_DIVIDE                                   0x000003BBL
#define X_COMP_OPCODE_INT32_MULTIPLY                                 0x000003BCL
#define X_COMP_OPCODE_INT64_PLUS                                     0x000003BDL
#define X_COMP_OPCODE_INT64_MINUS                                    0x000003BEL
#define X_COMP_OPCODE_INT64_DIVIDE                                   0x000003BFL
#define X_COMP_OPCODE_INT64_MULTIPLY                                 0x000003C0L
#define X_COMP_OPCODE_FLOAT64_PLUS                                   0x000003C1L
#define X_COMP_OPCODE_FLOAT64_MINUS                                  0x000003C2L
#define X_COMP_OPCODE_FLOAT64_DIVIDE                                 0x000003C3L
#define X_COMP_OPCODE_FLOAT64_MULTIPLY                               0x000003C4L
#define X_COMP_OPCODE_VARIANT_PLUS                                   0x000003C5L
#define X_COMP_OPCODE_VARIANT_MINUS                                  0x000003C6L
#define X_COMP_OPCODE_VARIANT_DIVIDE                                 0x000003C7L
#define X_COMP_OPCODE_VARIANT_MULTIPLY                               0x000003C8L
#define X_COMP_OPCODE_ROUND_HALFUP_DOUBLE                            0x000003C9L
#define X_COMP_OPCODE_ROUND_HALFUP_PACKED31                          0x000003CAL
#define X_COMP_OPCODE_ROUND_HALFUP_PACKED63                          0x000003CBL
#define X_COMP_OPCODE_ROUND_HALFUP_DECIMAL                           0x000003CCL
#define X_COMP_OPCODE_ROUND_HALFUP_FLOAT64                           0x000003CDL
#define X_COMP_OPCODE_ROUND_HALFUP_VARIANT                           0x000003CEL
#define X_COMP_OPCODE_STRING_PLUS                                    0x000003CFL
#define X_COMP_OPCODE_BINARY_PLUS                                    0x000003D0L
#define X_COMP_OPCODE_UTF16_STRING_PLUS                              0x000003D1L


/* WHEN instructions 0x03E0 - 0x041F (Last 0x0410) */
#define X_COMP_OPCODE_WHEN_SUBJECT_LONG                              0x000003E0L
#define X_COMP_OPCODE_WHEN_SUBJECT_LONGLONG                          0x000003E1L
#define X_COMP_OPCODE_WHEN_SUBJECT_DOUBLE                            0x000003E2L
#define X_COMP_OPCODE_WHEN_SUBJECT_PACKED31                          0x000003E3L
#define X_COMP_OPCODE_WHEN_SUBJECT_PACKED63                          0x000003E4L
#define X_COMP_OPCODE_WHEN_SUBJECT_DECIMAL                           0x000003E5L
#define X_COMP_OPCODE_WHEN_SUBJECT_INT32                             0x000003E6L
#define X_COMP_OPCODE_WHEN_SUBJECT_INT64                             0x000003E7L
#define X_COMP_OPCODE_WHEN_SUBJECT_FLOAT64                           0x000003E8L
#define X_COMP_OPCODE_WHEN_SUBJECT_BOOLEAN                           0x000003E9L
#define X_COMP_OPCODE_WHEN_SUBJECT_VARIANT                           0x000003EAL
#define X_COMP_OPCODE_WHEN_SUBJECT_DATE                              0x000003EBL
#define X_COMP_OPCODE_WHEN_SUBJECT_TIME                              0x000003ECL
#define X_COMP_OPCODE_WHEN_SUBJECT_DATETIME                          0x000003EDL
#define X_COMP_OPCODE_WHEN_SUBJECT_STRING                            0x000003EEL
#define X_COMP_OPCODE_WHEN_SUBJECT_BINARY                            0x000003EFL

#define X_COMP_OPCODE_WHEN_TRUE_LONG                                 0x000003F0L
#define X_COMP_OPCODE_WHEN_TRUE_LONGLONG                             0x000003F1L
#define X_COMP_OPCODE_WHEN_TRUE_DOUBLE                               0x000003F2L
#define X_COMP_OPCODE_WHEN_TRUE_PACKED31                             0x000003F3L
#define X_COMP_OPCODE_WHEN_TRUE_PACKED63                             0x000003F4L
#define X_COMP_OPCODE_WHEN_TRUE_DECIMAL                              0x000003F5L
#define X_COMP_OPCODE_WHEN_TRUE_INT32                                0x000003F6L
#define X_COMP_OPCODE_WHEN_TRUE_INT64                                0x000003F7L
#define X_COMP_OPCODE_WHEN_TRUE_FLOAT64                              0x000003F8L
#define X_COMP_OPCODE_WHEN_TRUE_BOOLEAN                              0x000003F9L
#define X_COMP_OPCODE_WHEN_TRUE_VARIANT                              0x000003FAL
#define X_COMP_OPCODE_WHEN_TRUE_DATE                                 0x000003FBL
#define X_COMP_OPCODE_WHEN_TRUE_TIME                                 0x000003FCL
#define X_COMP_OPCODE_WHEN_TRUE_DATETIME                             0x000003FDL
#define X_COMP_OPCODE_WHEN_TRUE_STRING                               0x000003FEL
#define X_COMP_OPCODE_WHEN_TRUE_BINARY                               0x000003FFL

#define X_COMP_OPCODE_WHEN_ALL_FALSE_LONG                            0x00000400L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_LONGLONG                        0x00000401L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_DOUBLE                          0x00000402L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_PACKED31                        0x00000403L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_PACKED63                        0x00000404L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_DECIMAL                         0x00000405L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_INT32                           0x00000406L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_INT64                           0x00000407L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_FLOAT64                         0x00000408L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_BOOLEAN                         0x00000409L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_VARIANT                         0x0000040AL
#define X_COMP_OPCODE_WHEN_ALL_FALSE_DATE                            0x0000040BL
#define X_COMP_OPCODE_WHEN_ALL_FALSE_TIME                            0x0000040CL
#define X_COMP_OPCODE_WHEN_ALL_FALSE_DATETIME                        0x0000040DL
#define X_COMP_OPCODE_WHEN_ALL_FALSE_STRING                          0x0000040EL
#define X_COMP_OPCODE_WHEN_ALL_FALSE_BINARY                          0x0000040FL

#define X_COMP_OPCODE_WHEN_SUBJECT_UTF16_STRING                      0x00000410L
#define X_COMP_OPCODE_WHEN_TRUE_UTF16_STRING                         0x00000411L
#define X_COMP_OPCODE_WHEN_ALL_FALSE_UTF16_STRING                    0x00000412L

/* OTHER instructions 0x0420 - 0x042F (Last 0x0421) */
#define X_COMP_OPCODE_EVALUATE_SYSTEM_VARIABLE                       0x00000420L
#define X_COMP_OPCODE_INITIALIZE_CALLBACK_FRAME                      0x00000421L
#define X_COMP_OPCODE_SET_INDEX                                      0x00000422L
#define X_COMP_OPCODE_REFRESH_COMPONENT                              0x00000423L
#define X_COMP_OPCODE_REFRESH_FIELD                                  0x00000424L
#define X_COMP_OPCODE_REFRESH_USER_STATUS                            0x00000425L
#define X_COMP_OPCODE_PUSH_GLOBAL_STORAGE_OFFSET                     0x00000426L
#define X_COMP_OPCODE_INITIALIZE_DBM_WHERE_FRAME                     0x00000427L
#define X_COMP_OPCODE_TERMINATE_DBM_WHERE_FRAME                      0x00000428L
#define X_COMP_OPCODE_PUSH_DECIMAL_PRECISION_AS_INT32                0x00000429L

/* INTRINSIC instructions 0x0430 - 0x04FF (Last 0x04EA) */
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CUR_SIZE                  0x00000430L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CUR_EBCDIC_SIZE           0x00000431L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CUR_CHARS                 0x00000432L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_BYTE_TYPE_AT              0x00000433L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CHAR_TYPE_AT              0x00000434L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_TRIM                      0x00000435L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_LEFT_TRIM                 0x00000436L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_RIGHT_TRIM                0x00000437L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CENTER                    0x00000438L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REPEAT                    0x00000439L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REVERSE                   0x0000043AL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_LOWER_CASE                0x0000043BL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_UPPER_CASE                0x0000043CL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_SUBSTRING                 0x0000043DL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_LEFT_MOST                 0x0000043EL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_RIGHT_MOST                0x0000043FL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_INSERT_STRING             0x00000440L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_DELETE_SUBSTRING          0x00000441L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REPLACE_SUBSTRING         0x00000442L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CONCAT                    0x00000443L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_TRIM_CONCAT               0x00000444L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_BLANK_CONCAT              0x00000445L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_TRIM_BLANK_CONCAT         0x00000446L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_SUBSTITUTE                0x00000447L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_TRIM_SUBSTITUTE           0x00000448L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_RIGHT_ADJUST              0x00000449L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CONTAINS                  0x0000044AL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_POSITION_IN               0x0000044BL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_POSITION_OF               0x0000044CL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_OCCURRENCES_IN            0x0000044DL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_OCCURRENCES_OF            0x0000044EL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_LAST_POSITION_IN          0x0000044FL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_LAST_POSITION_OF          0x00000450L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_CONTAINS_ONLY             0x00000451L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REMOVE_CHARACTERS         0x00000452L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REMOVE                    0x00000453L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REMOVE_ALL                0x00000454L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REPLACE                   0x00000455L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_REPLACE_ALL               0x00000456L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_TRANSLATE_CHARACTERS      0x00000457L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_DATE                   0x00000458L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_TIME                   0x00000459L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_FLOAT                  0x0000045AL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_NUMBER                 0x0000045BL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_BOOLEAN                0x0000045CL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_INTEGER                0x0000045DL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_DATETIME               0x0000045EL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_VALUE                  0x0000045FL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_SBCS_STRING            0x00000460L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_DBCS_STRING            0x00000461L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_DBCS_FIXEDCHAR         0x00000462L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_DATE                   0x00000463L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_TIME                   0x00000464L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_FLOAT                  0x00000465L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_NUMBER                 0x00000466L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_BOOLEAN                0x00000467L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_DATETIME               0x00000468L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_NULL                   0x00000469L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_SBCS                   0x0000046AL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_DBCS                   0x0000046BL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_MIXED                  0x0000046CL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_MIN                       0x0000046DL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_MAX                       0x0000046EL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_SUCC                      0x0000046FL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_PRED                      0x00000470L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_ROUND                     0x00000471L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_BOUND                     0x00000472L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_DATE                   0x00000473L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_TIME                   0x00000474L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_FLOAT                  0x00000475L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_STRING                 0x00000476L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_BOOLEAN                0x00000477L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_DATETIME               0x00000478L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_DECIMAL_VALUE          0x00000479L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_LONG_VALUE             0x0000047AL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_LONGLONG_VALUE         0x0000047BL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_INT32_VALUE            0x0000047CL
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_INT64_VALUE            0x0000047DL
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_BIT_OR                   0x0000047EL
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_BIT_AND                  0x0000047FL
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_BIT_NOT                  0x00000480L
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_BIT_XOR                  0x00000481L
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_AS_BYTE                  0x00000482L
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_AS_CHAR                  0x00000483L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_IS_NULL                   0x00000484L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_IS_DATE                   0x00000485L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_IS_TIME                   0x00000486L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_IS_BOOLEAN                0x00000487L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_IS_DATETIME               0x00000488L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_IS_BETWEEN                0x00000489L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_MIN                        0x0000048AL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_MAX                        0x0000048BL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_SUCC                       0x0000048CL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_PRED                       0x0000048DL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_BOUND                      0x0000048EL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_IS_BETWEEN                 0x0000048FL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_AS_VALUE                   0x00000490L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_AS_STRING                  0x00000491L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_AS_DECIMAL                 0x00000492L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_ADD                        0x00000493L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_SUBTRACT                   0x00000494L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_MULTIPLY                   0x00000495L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_DIVIDE                     0x00000496L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_TYPE                         0x00000497L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_TYPE                      0x00000498L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_STRING                    0x00000499L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_BOOLEAN                   0x0000049AL
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_DECIMAL                   0x0000049BL
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_INTEGER                   0x0000049CL
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_REFERENCE                 0x0000049DL
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_DATE                      0x0000049EL
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_TIME                      0x0000049FL
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_AS_DATETIME                  0x000004A0L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_NULL                      0x000004A1L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_EMPTY                     0x000004A2L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_NUMBER                    0x000004A3L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_STRING                    0x000004A4L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_DATE                      0x000004A5L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_BOOLEAN                   0x000004A6L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_REFERENCE                 0x000004A7L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_NULL_REFERENCE            0x000004A8L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_TIME                      0x000004A9L
#define X_COMP_OPCODE_IMP_INTRINSIC_VAR_IS_DATETIME                  0x000004AAL
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_IS_TRUE                  0x000004ABL
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_IS_FALSE                 0x000004ACL
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_IS_NULL                  0x000004ADL
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_OR                       0x000004AEL
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_AND                      0x000004AFL
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_NOT                      0x000004B0L
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_AS_STRING                0x000004B1L
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_AS_VALUE                 0x000004B2L
#define X_COMP_OPCODE_IMP_INTRINSIC_BOOLEAN_AS_NUMBER                0x000004B3L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_NOW                         0x000004B4L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_DAY                         0x000004B5L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_YEAR                        0x000004B6L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_MONTH                       0x000004B7L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_ADJUST                      0x000004B8L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_DIFFERENCE                  0x000004B9L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_NUMBER                   0x000004BAL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_STRING                   0x000004BBL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_DISPLAY_STRING           0x000004BCL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_VALUE                    0x000004BDL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_DAYS                     0x000004BEL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_DATETIME                 0x000004BFL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_AS_DAY_OF_WEEK              0x000004C0L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_IS_NULL                     0x000004C1L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_NOW                         0x000004C2L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_HOUR                        0x000004C3L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_MINUTE                      0x000004C4L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_SECOND                      0x000004C5L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_ADJUST                      0x000004C6L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_DIFFERENCE                  0x000004C7L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_AS_NUMBER                   0x000004C8L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_AS_STRING                   0x000004C9L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_AS_DISPLAY_STRING           0x000004CAL
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_AS_VALUE                    0x000004CBL
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_SECONDS                     0x000004CCL
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_AS_DATETIME                 0x000004CDL
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_IS_NULL                     0x000004CEL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_NOW                     0x000004CFL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_DATE                    0x000004D0L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_TIME                    0x000004D1L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_FRACTIONAL_SECONDS      0x000004D2L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_NUMBER               0x000004D3L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_STRING               0x000004D4L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_DISPLAY_STRING       0x000004D5L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_VALUE                0x000004D6L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_LOCALIZED_DATETIME   0x000004D7L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_UNIVERSAL_DATETIME   0x000004D8L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_SECONDS              0x000004D9L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_IS_NULL                 0x000004DAL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_CUR_SIZE                  0x000004DBL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_AS_BYTE                   0x000004DCL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_AS_VALUE                  0x000004DDL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_AS_STRING                 0x000004DEL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_AS_INTEGER                0x000004DFL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_IS_NULL                   0x000004E0L
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_IS_IN_RANGE              0x000004E1L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_MIN                         0x000004E2L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_MAX                         0x000004E3L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_MIN                         0x000004E4L
#define X_COMP_OPCODE_IMP_INTRINSIC_TIME_MAX                         0x000004E5L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_MIN                     0x000004E6L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_MAX                     0x000004E7L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_MIN                       0x000004E8L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_MAX                       0x000004E9L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_COSINE                     0x000004EAL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_ARCCOSINE                  0x000004EBL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_COSINEH                    0x000004ECL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_SINE                       0x000004EDL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_ARCSINE                    0x000004EEL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_SINEH                      0x000004EFL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_SQRT                       0x000004F0L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_POWER                      0x000004F1L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_TANGENT                    0x000004F2L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_TANGENTH                   0x000004F3L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_LOGARITHM                  0x000004F4L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_ISNANORND                  0x000004F5L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_ARCTANGENT                 0x000004F6L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_ARCTANGENT2                0x000004F7L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_EXPONENTIAL                0x000004F8L
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_LOGARITHM10                0x000004F9L
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_AS_HEXSTRING              0x000004FAL
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_AS_BINSTRING             0x000004FBL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_FMOD                       0x000004FCL
#define X_COMP_OPCODE_IMP_INTRINSIC_FLOAT_FABS                       0x000004FDL
#define X_COMP_OPCODE_IMP_INTRINSIC_BINARY_AS_HEXTOINT               0x000004FEL
#define X_COMP_OPCODE_IMP_INTRINSIC_LONGLONG_AS_BINSTRING            0x000004FFL

/* Evaluate instructions 0x00500 - 0x0050F (Last 0x00500) */
#define X_COMP_OPCODE_EVALUATE_DATE_CHECK                               0x00000500L

#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_MOD                         0x00000501L
#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_DIV                         0x00000502L
#define X_COMP_OPCODE_IMP_INTRINSIC_NUMBER_AS_DISPLAY_STRING            0x00000503L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATE_WEEK                           0x00000504L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_CUSTOM_DISPLAY_STRING   0x00000505L

#define X_COMP_OPCODE_IMP_INTRINSIC_INTEGER_AS_UNICODE_STRING           0x00000508L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_COMPARE                      0x00000509L

#define X_COMP_OPCODE_EVALUATE_BOM_ADD_ENTRY                            0x00000510L
#define X_COMP_OPCODE_EVALUATE_BOM_ADD_ENTRY_AFTER                      0x00000511L
#define X_COMP_OPCODE_EVALUATE_BOM_DLT_ENTRY                            0x00000512L
#define X_COMP_OPCODE_EVALUATE_BOM_GET_ENTRY                            0x00000513L
#define X_COMP_OPCODE_EVALUATE_BOM_INZ_LIST                             0x00000514L
#define X_COMP_OPCODE_EVALUATE_BOM_DLT_ENTRY_CURRENT                    0x00000515L

#define X_COMP_OPCODE_EVALUATE_BOM_HANDLE_IO_ERROR                      0x00000516L
#define X_COMP_OPCODE_EVALUATE_BOM_HANDLE_NOT_FOUND                     0x00000517L

#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_CUR_SIZE               0x00000520L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_CUR_CHARS              0x00000521L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_TRIM                   0x00000522L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_LEFT_TRIM              0x00000523L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_RIGHT_TRIM             0x00000524L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_CENTER                 0x00000525L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REPEAT                 0x00000526L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REVERSE                0x00000527L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_LOWER_CASE             0x00000528L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_UPPER_CASE             0x00000529L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_SUBSTRING              0x0000052AL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_LEFT_MOST              0x0000052BL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_RIGHT_MOST             0x0000052CL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_INSERT_UTF16_STRING    0x0000052DL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_DELETE_SUBSTRING       0x0000052EL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REPLACE_SUBSTRING      0x0000052FL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_CONCAT                 0x00000530L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_TRIM_CONCAT            0x00000531L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_BLANK_CONCAT           0x00000532L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_TRIM_BLANK_CONCAT      0x00000533L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_SUBSTITUTE             0x00000534L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_TRIM_SUBSTITUTE        0x00000535L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_RIGHT_ADJUST           0x00000536L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_CONTAINS               0x00000537L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_POSITION_IN            0x00000538L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_POSITION_OF            0x00000539L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_OCCURRENCES_IN         0x0000053AL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_OCCURRENCES_OF         0x0000053BL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_LAST_POSITION_IN       0x0000053CL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_LAST_POSITION_OF       0x0000053DL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_CONTAINS_ONLY          0x0000053EL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REMOVE_CHARACTERS      0x0000053FL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REMOVE                 0x00000540L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REMOVE_ALL             0x00000541L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REPLACE                0x00000542L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_REPLACE_ALL            0x00000543L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_TRANSLATE_CHARACTERS   0x00000544L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_AS_VALUE               0x00000545L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_AS_BOOLEAN             0x00000546L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_IS_BOOLEAN             0x00000547L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_MIN                    0x00000548L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_MAX                    0x00000549L
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_AS_CODE_POINT          0x0000054AL
#define X_COMP_OPCODE_IMP_INTRINSIC_UTF16_STRING_COMPARE                0x0000054BL

#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_GREGORIAN_DAY             0x00000550L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_GREGORIAN_YEAR            0x00000551L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_GREGORIAN_MONTH           0x00000552L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_GREGORIAN_MONTHDAY        0x00000553L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_GREGORIAN_YEARMONTH       0x00000554L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_IS_DURATION                  0x00000555L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_GREGORIAN_DAY             0x00000556L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_GREGORIAN_YEAR            0x00000557L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_GREGORIAN_MONTH           0x00000558L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_GREGORIAN_MONTHDAY        0x00000559L
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_GREGORIAN_YEARMONTH       0x0000055AL
#define X_COMP_OPCODE_IMP_INTRINSIC_STRING_AS_DURATION                  0x0000055BL
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_DAY_AS_STRING             0x0000055CL
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_DAY_AS_DATETIME           0x0000055DL
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_YEAR_AS_STRING            0x0000055EL
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_YEAR_AS_DATETIME          0x0000055FL
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_MONTH_AS_STRING           0x00000560L
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_MONTH_AS_DATETIME         0x00000561L
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_MONTHDAY_AS_STRING        0x00000562L
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_MONTHDAY_AS_DATETIME      0x00000563L
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_YEARMONTH_AS_STRING       0x00000564L
#define X_COMP_OPCODE_IMP_INTRINSIC_GREGORIAN_YEARMONTH_AS_DATETIME     0x00000565L
#define X_COMP_OPCODE_IMP_INTRINSIC_DURATION_AS_STRING                  0x00000566L
#define X_COMP_OPCODE_IMP_INTRINSIC_DURATION_AS_DATETIME                0x00000567L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_GREGORIAN_DAY           0x00000568L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_GREGORIAN_YEAR          0x00000569L
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_GREGORIAN_MONTH         0x0000056AL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_GREGORIAN_MONTHDAY      0x0000056BL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_GREGORIAN_YEARMONTH     0x0000056CL
#define X_COMP_OPCODE_IMP_INTRINSIC_DATETIME_AS_DURATION                0x0000056DL

/* New instructions that don't fit above 0x00600 - 0x006FF (Last 0x00602) */
#define X_COMP_OPCODE_PUSH_NCLOB_VECTOR_AS_STRING                       0x00000600L
#define X_COMP_OPCODE_PUSH_NCLOB_RESULT_VECTOR_AS_STACK_VECTOR          0x00000601L
#define X_COMP_OPCODE_PUSH_NCLOB_STACK_VECTOR_AS_STRING                 0x00000602L

/* Next available range */
#define X_COMP_OPCODE_LAST                                              0x00000700L


/* Following OPCODE's used to assist code generation and have no runtime implementation */

/* CASE SUBJECT instructions 0x10000 - 0x1000F (Last 0x1000F) */
#define X_COMP_OPCODE_CASE_SUBJECT_LONG                              0x00010000L
#define X_COMP_OPCODE_CASE_SUBJECT_LONGLONG                          0x00010001L
#define X_COMP_OPCODE_CASE_SUBJECT_DOUBLE                            0x00010002L
#define X_COMP_OPCODE_CASE_SUBJECT_PACKED31                          0x00010003L
#define X_COMP_OPCODE_CASE_SUBJECT_PACKED63                          0x00010004L
#define X_COMP_OPCODE_CASE_SUBJECT_DECIMAL                           0x00010005L
#define X_COMP_OPCODE_CASE_SUBJECT_INT32                             0x00010006L
#define X_COMP_OPCODE_CASE_SUBJECT_INT64                             0x00010007L
#define X_COMP_OPCODE_CASE_SUBJECT_FLOAT64                           0x00010008L
#define X_COMP_OPCODE_CASE_SUBJECT_BOOLEAN                           0x00010009L
#define X_COMP_OPCODE_CASE_SUBJECT_VARIANT                           0x0001000AL
#define X_COMP_OPCODE_CASE_SUBJECT_DATE                              0x0001000BL
#define X_COMP_OPCODE_CASE_SUBJECT_TIME                              0x0001000CL
#define X_COMP_OPCODE_CASE_SUBJECT_DATETIME                          0x0001000DL
#define X_COMP_OPCODE_CASE_SUBJECT_STRING                            0x0001000EL
#define X_COMP_OPCODE_CASE_SUBJECT_BINARY                            0x0001000FL
#define X_COMP_OPCODE_CASE_SUBJECT_UTF16_STRING                      0x00010010L

#define X_COMP_OPCODE_COERCE_GENERIC_TO_SQLNULL                      0x00010020L

/* ----------------------------------------------------------------- */
/* PCode structures used by LIIO->DC_P3109 for LL2 Expressions       */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

/* ------------------------------------------------------------------ */
/* Codes for pcode instructions                                       */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_COMP_PCODE_KIND,
   X_COMP_PCODE_FACTOR,
   X_COMP_PCODE_EXPRESSION_FLAGS,
   X_COMP_PCODE_INSTRUCTION_FLAGS,
   X_COMP_PCODE_UNARY_FACTOR_FLAGS,
   X_COMP_PCODE_BINARY_COMPARE_FLAGS;

#define X_COMP_PCODE_KIND_NULL                                       0L
#define X_COMP_PCODE_KIND_BLOCK                                      10L
#define X_COMP_PCODE_KIND_ARGUMENT                                   20L
#define X_COMP_PCODE_KIND_SEPARATOR                                  30L
#define X_COMP_PCODE_KIND_INSTRUCTION                                40L
#define X_COMP_PCODE_KIND_GENERIC_SOLUTION                           50L
#define X_COMP_PCODE_KIND_LONGLONG_SOLUTION                          51L
#define X_COMP_PCODE_KIND_DECIMAL_SOLUTION                           52L
#define X_COMP_PCODE_KIND_SOLUTION_EVALUATION                        60L
#define X_COMP_PCODE_KIND_SOLUTION_ASSIGNMENT                        61L
#define X_COMP_PCODE_KIND_SOLUTION_IDENTICAL_ASSIGNMENT              62L

#define X_COMP_PCODE_KIND_DEF_COMMAND_PROC                           100L
#define X_COMP_PCODE_KIND_DEF_COMPONENT_PROC                         110L
#define X_COMP_PCODE_KIND_DEF_BOOLEAN_FUNC                           120L
#define X_COMP_PCODE_KIND_DEF_XVAR_BOOLEAN_FUNC                      121L
#define X_COMP_PCODE_KIND_DEF_STRING_FUNC                            130L
#define X_COMP_PCODE_KIND_DEF_VALUE_ASSIGNMENT_PROC                  140L
#define X_COMP_PCODE_KIND_DEF_CASE_PROC                              150L
#define X_COMP_PCODE_KIND_DEF_WHEN_FUNC                              151L
#define X_COMP_PCODE_KIND_DEF_EVALUATION_PROC                        160L
#define X_COMP_PCODE_KIND_DEF_VALIDATION_FUNC                        170L
#define X_COMP_PCODE_KIND_DEF_EXECUTE_RECEIVED_PROC                  180L
#define X_COMP_PCODE_KIND_DEF_EXECUTE_RETURNED_PROC                  181L
#define X_COMP_PCODE_KIND_DEF_BOM_DRD_PROC                           182L

#define X_COMP_PCODE_KIND_BEGIN_WHERE_TABLES                         200L
#define X_COMP_PCODE_KIND_END_WHERE_TABLES                           210L
#define X_COMP_PCODE_KIND_BEGIN_WHERE_ITEMS                          200L
#define X_COMP_PCODE_KIND_END_WHERE_ITEMS                            210L
#define X_COMP_PCODE_KIND_BEGIN_WHERE_FACTORS                        220L
#define X_COMP_PCODE_KIND_END_WHERE_FACTORS                          230L
#define X_COMP_PCODE_KIND_BEGIN_WHERE_ACTIVITIES                     240L
#define X_COMP_PCODE_KIND_END_WHERE_ACTIVITIES                       250L

#define X_COMP_PCODE_KIND_DEFINE_ROUNDING_PRECISION                  260L
#define X_COMP_PCODE_KIND_DEFINE_RESULT_PRECISION                    261L
#define X_COMP_PCODE_KIND_DEFINE_VECTOR_LIST                         262L

#define X_COMP_PCODE_KIND_DEFINE_DBM_WHERE_ITEM                      270L
#define X_COMP_PCODE_KIND_DEFINE_DBM_WHERE_FACTOR                    271L
#define X_COMP_PCODE_KIND_DEFINE_DBM_WHERE_ACTIVITY                  272L

#define X_COMP_PCODE_KIND_BEGIN_BOM_DRD_MAPPING_TABLE                280L
#define X_COMP_PCODE_KIND_END_BOM_DRD_MAPPING_TABLE                  281L

#define X_COMP_PCODE_KIND_DEFINE_BOM_DRD_MAPPING_GET                 285L
#define X_COMP_PCODE_KIND_DEFINE_BOM_DRD_MAPPING_SET                 286L

#define X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_USER                    300L
#define X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_SYSTEM                  301L
#define X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_FUNCTION                302L
#define X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_USER_IN_SYSTEM          303L

#define X_COMP_PCODE_KIND_PUSH_LONG                                  1000L
#define X_COMP_PCODE_KIND_PUSH_FLOAT                                 1001L
#define X_COMP_PCODE_KIND_PUSH_DOUBLE                                1002L
#define X_COMP_PCODE_KIND_PUSH_STRING                                1003L
#define X_COMP_PCODE_KIND_PUSH_BOOLEAN                               1004L
#define X_COMP_PCODE_KIND_PUSH_DECIMAL                               1005L
#define X_COMP_PCODE_KIND_PUSH_DISPATCH_OPERATION                    1006L
#define X_COMP_PCODE_KIND_PUSH_FIELD                                 1007L
#define X_COMP_PCODE_KIND_PUSH_SYSTEM_VARIABLE                       1008L
#define X_COMP_PCODE_KIND_PUSH_MTXT_VARIABLE                         1009L
#define X_COMP_PCODE_KIND_PUSH_NULL                                  1010L
#define X_COMP_PCODE_KIND_PUSH_SQLNULL                               1011L
#define X_COMP_PCODE_KIND_PUSH_LONGLONG                              1012L
#define X_COMP_PCODE_KIND_PUSH_LITERAL_EXCHANGE                      1013L
#define X_COMP_PCODE_KIND_PUSH_FILE_FIELD                            1014L
#define X_COMP_PCODE_KIND_PUSH_LIST_FIELD                            1015L
#define X_COMP_PCODE_KIND_PUSH_RESULT_VECTOR                         1016L
#define X_COMP_PCODE_KIND_PUSH_LONG_LOVAL                            1017L
#define X_COMP_PCODE_KIND_PUSH_LONGLONG_LOVAL                        1018L
#define X_COMP_PCODE_KIND_PUSH_RECORD                                1019L
#define X_COMP_PCODE_KIND_PUSH_RECORD_FIELD                          1020L
#define X_COMP_PCODE_KIND_PUSH_UDC_FIELD                             1021L

#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_ASSIGNMENT               0x00000001L
#define X_COMP_PCODE_EXPRESSION_FLAG_REMEMBERED_VALUE_ASSIGNMENT     0x00000002L
#define X_COMP_PCODE_EXPRESSION_FLAG_DECIMAL_ASSIGNMENT              0x00000004L

#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_LONG_ASSIGNMENT          0x00000010L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_LONGLONG_ASSIGNMENT      0x00000020L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_DECIMAL_ASSIGNMENT       0x00000040L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_DOUBLE_ASSIGNMENT        0x00000080L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_FLOAT_ASSIGNMENT         0x00000100L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_STRING_ASSIGNMENT        0x00000200L

#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_LONG_COMPARISON          0x00001000L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_LONGLONG_COMPARISON      0x00002000L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_DECIMAL_COMPARISON       0x00004000L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_DOUBLE_COMPARISON        0x00008000L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_FLOAT_COMPARISON         0x00010000L
#define X_COMP_PCODE_EXPRESSION_FLAG_SIMPLE_STRING_COMPARISON        0x00020000L

#define X_COMP_PCODE_UNARY_FACTOR_FLAG_VECTORED_COMPONENT            0x00000001L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_ARRAY_INDEX_VARIABLE          0x00000002L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_SQLNULL_VARIABLE              0x00000004L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_IOSTS_VARIABLE                0x00000008L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_SYSVAR_ZEROS                  0x00000010L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_SYSVAR_BLANKS                 0x00000020L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_UNSIGNED_INTEGER_VARIABLE     0x00000040L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_FULL_RDMLX_VECTOR             0x00000080L
#define X_COMP_PCODE_UNARY_FACTOR_FLAG_MBCS_VECTOR                   0x00000100L

#define X_COMP_PCODE_BINARY_COMPARE_FLAG_EQUAL                       0x00000001L
#define X_COMP_PCODE_BINARY_COMPARE_FLAG_LESS                        0x00000010L
#define X_COMP_PCODE_BINARY_COMPARE_FLAG_GREATER                     0x00000100L
#define X_COMP_PCODE_BINARY_COMPARE_FLAG_NOT_EQUAL                   0x00000110L
#define X_COMP_PCODE_BINARY_COMPARE_FLAG_LESS_OR_EQUAL               0x00000011L
#define X_COMP_PCODE_BINARY_COMPARE_FLAG_GREATER_OR_EQUAL            0x00000101L

#define X_COMP_PCODE_INSTRUCTION_FLAG_HANDLE_SQLNULL                 0x00000001L
#define X_COMP_PCODE_INSTRUCTION_FLAG_PRECISE_RESULT                 0x00000002L
#define X_COMP_PCODE_INSTRUCTION_FLAG_ML2                            0x00000004L
#define X_COMP_PCODE_INSTRUCTION_FLAG_COERCED_ALPHA                  0x00000008L
#define X_COMP_PCODE_INSTRUCTION_FLAG_ROUNDING_DROPS_DECIMALS        0x00000010L
#define X_COMP_PCODE_INSTRUCTION_FLAG_PROMOTE_INTERMEDIATE_RESULT    0x00000020L

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_HEADER                                               */
/*                                                                   */
/*    Supports:                                                      */
/*       All of the above                                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#ifndef X_OPERATING_TARGET_CSHARP

typedef struct _X_COMP_PCODE_HEADER
{
   X_COMP_PCODE_KIND                            ulKind;
}
   X_COMP_PCODE_HEADER,
   *PX_COMP_PCODE_HEADER,
   **PPX_COMP_PCODE_HEADER;

#endif // X_OPERATING_TARGET_CSHARP

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_INSTRUCTION                                          */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_INSTRUCTION                               */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_INSTRUCTION
{
   X_COMP_PCODE_KIND                            ulKind;
   X_COMP_OPCODE                                ulOpcode;
   X_COMP_PCODE_HEADER                       *  pOperand;
   X_COMP_PCODE_INSTRUCTION_FLAGS               ulFlags;
}
   X_COMP_PCODE_INSTRUCTION,
   *PX_COMP_PCODE_INSTRUCTION,
   **PPX_COMP_PCODE_INSTRUCTION;

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_SOLUTION_EVALUATION                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_SOLUTION_EVALUATION                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_SOLUTION_EVALUATION
{
   X_COMP_PCODE_KIND                            ulKind;
   X_COMP_PCODE_HEADER                       *  pOperation;
   X_COMP_PCODE_HEADER                       *  pTarget;
   X_COMP_PCODE_HEADER                       *  pSubject;
   X_COMP_PCODE_HEADER                       *  pObject;
}
   X_COMP_PCODE_SOLUTION_EVALUATION,
   *PX_COMP_PCODE_SOLUTION_EVALUATION,
   **PPX_COMP_PCODE_SOLUTION_EVALUATION;

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_SOLUTION                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_GENERIC_SOLUTION                          */
/*       X_COMP_PCODE_KIND_LONGLONG_SOLUTION                         */
/*       X_COMP_PCODE_KIND_DECIMAL_SOLUTION                          */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_SOLUTION
{
   X_COMP_KIND                                  ulKind;
   unsigned long                                ulInstructionCount;
   X_COMP_PCODE_HEADER                       ** ppInstructions;
}
   X_COMP_PCODE_SOLUTION,
   *PX_COMP_PCODE_SOLUTION,
   **PPX_COMP_PCODE_SOLUTION;

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_BLOCK                                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_DEFINE_BLOCK                              */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_BLOCK
{
   X_COMP_KIND                                  ulKind;
   X_COMP_PCODE_EXPRESSION_FLAGS                ulExpressionFlags;
   unsigned long                                ulOperationCount;
   X_COMP_PCODE_HEADER                       ** ppOperations;
   unsigned long                                ulInstructionCount;
   X_COMP_PCODE_INSTRUCTION                  ** ppInstructions;
   unsigned long                                ulSolutionCount;
   X_COMP_PCODE_SOLUTION                     ** ppSolutions;
}
   X_COMP_PCODE_BLOCK,
   *PX_COMP_PCODE_BLOCK,
   **PPX_COMP_PCODE_BLOCK;


/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_PROC                                                 */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_DEF_COMMAND_PROC                          */
/*       X_COMP_PCODE_KIND_DEF_COMPONENT_PROC                        */
/*       X_COMP_PCODE_KIND_DEF_BOOLEAN_FUNC                          */
/*       X_COMP_PCODE_KIND_DEF_STRING_FUNC                           */
/*       X_COMP_PCODE_KIND_DEF_VALUE_ASSIGNMENT_PROC                 */
/*       X_COMP_PCODE_KIND_DEF_CASE_PROC                             */
/*       X_COMP_PCODE_KIND_DEF_WHEN_FUNC                             */
/*       X_COMP_PCODE_KIND_DEF_EVALUATION_PROC                       */
/*       X_COMP_PCODE_KIND_DEF_VALIDATION_FUNC                       */
/*       X_COMP_PCODE_KIND_DEF_EXECUTE_RECEIVED_PROC                 */
/*       X_COMP_PCODE_KIND_DEF_EXECUTE_RETURNED_PROC                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_PROC
{
   X_COMP_PCODE_KIND                            ulKind;
   X_COMP_DISPATCH_ID                           ulIdentifier;
   unsigned long                                ulStackSize;
   unsigned long                                ulFactorCount;
   X_COMP_PCODE_HEADER                       ** ppFactors;
   unsigned long                                ulOperationCount;
   X_COMP_PCODE_HEADER                       ** ppOperations;
   unsigned long                                ulBlockCount;
   X_COMP_PCODE_BLOCK                        ** ppBlocks;
}
   X_COMP_PCODE_PROC,
   *PX_COMP_PCODE_PROC,
   **PPX_COMP_PCODE_PROC;


/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_DEFINE_PRECISION                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_DEFINE_ROUNDING_PRECISION                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_DEFINE_PRECISION
{
   X_COMP_PCODE_KIND                            ulKind;
   unsigned long                                ulLength;
   unsigned long                                ulDecimals;
}
   X_COMP_PCODE_DEFINE_PRECISION,
   *PX_COMP_PCODE_DEFINE_PRECISION,
   **PPX_COMP_PCODE_DEFINE_PRECISION;


/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_UNARY_FACTOR                                         */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_PUSH_FIELD                                */
/*                                                                   */
/*       X_COMP_PCODE_KIND_PUSH_MTXT_VARIABLE                        */
/*       X_COMP_PCODE_KIND_PUSH_SYSTEM_VARIABLE                      */
/*       X_COMP_PCODE_KIND_PUSH_LITERAL_EXCHANGE                     */
/*                                                                   */
/*       X_COMP_PCODE_KIND_PUSH_DISPATCH_OPERATION                   */
/*                                                                   */
/*       X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_USER                   */
/*       X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_SYSTEM                 */
/*       X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_FUNCTION               */
/*       X_COMP_PCODE_KIND_REMEMBER_VALUE_FOR_USER_IN_SYSTEM         */
/*                                                                   */
/*       X_COMP_PCODE_KIND_PUSH_LONG                                 */
/*       X_COMP_PCODE_KIND_PUSH_DOUBLE                               */
/*       X_COMP_PCODE_KIND_PUSH_STRING                               */
/*       X_COMP_PCODE_KIND_PUSH_BOOLEAN                              */
/*       X_COMP_PCODE_KIND_PUSH_DECIMAL                              */
/*       X_COMP_PCODE_KIND_PUSH_LONGLONG                             */
/*                                                                   */
/*       X_COMP_PCODE_KIND_PUSH_NULL                                 */
/*       X_COMP_PCODE_KIND_PUSH_SQLNULL                              */
/*                                                                   */
/*                                                                   */
/*       X_COMP_PCODE_KIND_PUSH_FILE_FIELD                           */
/*       X_COMP_PCODE_KIND_PUSH_LIST_FIELD                           */
/*       X_COMP_PCODE_KIND_PUSH_RESULT_VECTOR                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_UNARY_FACTOR
{
   X_COMP_PCODE_KIND                            ulKind;
   X_COMP_PCODE_FACTOR                          ulFactor;
   unsigned long                                ulVectorExchangeIdentifer;
   unsigned char                             *  pvchIdentifier;
   unsigned char                             *  pvchQualifyingIdentifier;

   X_COMP_DISPATCH_ID                           ulDispatchId;
   X_COMP_OPCODE                                ulOpcode;

   void                                      *  pvLiteralValue;
   void                                      *  pvPackedLiteralValue;
   void                                      *  pvPackedLiteralValueCSharp;
   unsigned long                                ulFactorLength;
   unsigned long                                ulFactorDecimals;
   unsigned long                                ulFactorEbcdicLength;
   unsigned long                                ulOpcodeCount;
   X_COMP_PCODE_UNARY_FACTOR_FLAGS              ulFlags;

}
   X_COMP_PCODE_UNARY_FACTOR,
   *PX_COMP_PCODE_UNARY_FACTOR,
   **PPX_COMP_PCODE_UNARY_FACTOR;

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_DEFINE_VECTOR_LIST                                   */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_DEFINE_VECTOR_LIST                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_DEFINE_VECTOR_LIST
{
   X_COMP_PCODE_KIND                            ulKind;
   unsigned long                                ulOperandCount;
   X_COMP_PCODE_HEADER                       ** ppOperands;
}
   X_COMP_PCODE_DEFINE_VECTOR_LIST,
   *PX_COMP_PCODE_DEFINE_VECTOR_LIST,
   **PPX_COMP_PCODE_DEFINE_VECTOR_LIST;

/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_DBM_WHERE                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_BEGIN_WHERE_TABLES                        */
/*       X_COMP_PCODE_KIND_END_WHERE_TABLES                          */
/*                                                                   */
/*       X_COMP_PCODE_KIND_BEGIN_WHERE_ITEMS                         */
/*       X_COMP_PCODE_KIND_END_WHERE_ITEMS                           */
/*                                                                   */
/*       X_COMP_PCODE_KIND_BEGIN_WHERE_FACTORS                       */
/*       X_COMP_PCODE_KIND_END_WHERE_FACTORS                         */
/*                                                                   */
/*       X_COMP_PCODE_KIND_BEGIN_WHERE_ACTIVITIES                    */
/*       X_COMP_PCODE_KIND_END_WHERE_ACTIVITIES                      */
/*                                                                   */
/*       X_COMP_PCODE_KIND_DEFINE_DBM_WHERE_ITEM                     */
/*       X_COMP_PCODE_KIND_DEFINE_DBM_WHERE_FACTOR                   */
/*       X_COMP_PCODE_KIND_DEFINE_DBM_WHERE_ACTIVITY                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_DBM_WHERE
{
   X_COMP_PCODE_KIND                               ulKind;
   char                                            chOperation;
   X_COMP_PCODE_UNARY_FACTOR                    *  pOperand;
   X_COMP_PCODE_FACTOR                             ulSubjectFactor;
   X_COMP_PCODE_FACTOR                             ulObjectFactor;
   X_COMP_PCODE_FACTOR                             ulResultFactor;
}
   X_COMP_PCODE_DBM_WHERE,
   *PX_COMP_PCODE_DBM_WHERE,
   **PPX_COMP_PCODE_DBM_WHERE;


/* ----------------------------------------------------------------- */
/* X_COMP_PCODE_BOM_DRD_MAP                                          */
/*                                                                   */
/*    Supports:                                                      */
/*       X_COMP_PCODE_KIND_BEGIN_BOM_DRD_MAPPING_TABLE               */
/*       X_COMP_PCODE_KIND_END_BOM_DRD_MAPPING_TABLE                 */
/*                                                                   */
/*       X_COMP_PCODE_KIND_DEFINE_BOM_DRD_MAPPING_GET                */
/*       X_COMP_PCODE_KIND_DEFINE_BOM_DRD_MAPPING_SET                */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_COMP_PCODE_BOM_DRD_MAP
{
   X_COMP_PCODE_KIND                               ulKind;
   X_COMP_PCODE_UNARY_FACTOR                    *  pOperand;
   X_COMP_PARTID                                   ulRecordPartId;
}
   X_COMP_PCODE_BOM_DRD_MAP,
   *PX_COMP_PCODE_BOM_DRD_MAP,
   **PPX_COMP_PCODE_BOM_DRD_MAP;

#endif


/* ----------------------------------------------------------------- */
/* Communication structures used between X_LIIO and DC_P3100         */
/* ----------------------------------------------------------------- */

   /* ----------------------------------------------------------------- */
   /* LL2 Token byte 1 - Escaped Token Escape Character definitions     */
   /* ----------------------------------------------------------------- */
   #define ODEF_LL2_EXPRESSION_ID_ESCAPE_CHAR            '\x03'
   #define ODEF_LL2_ET_ESCAPE_CHAR                       '\x03'

#if defined(X_COMP_FCC_SUPPORT)

   #ifndef X_OPERATING_TARGET_CSHARP

      /* -------------------------------------------------------------- */
      /* Standard callback interface declaration                        */
      /* -------------------------------------------------------------- */
      #if defined(X_OPERATING_SYSTEM_UNIX)
           #define LIIO_FCC_INTERFACE X_COMP_RETURN_CODE
      #else
           #define LIIO_FCC_INTERFACE X_COMP_RETURN_CODE __cdecl
      #endif

   #endif // X_OPERATING_TARGET_CSHARP

   /* ================================================================= */
   /* FCC_DICTIONARY_INFO                                               */
   /* ================================================================= */
   /*                                                                   */
   /* Types used to exchange type information between LIIV and LIIO     */
   /*                                                                   */
   /* ================================================================= */

   /* ulVectorExchangeIdentifier values */

   #define X_COMP_VECTOR_EXCHANGE_ID_NULL       ((unsigned long)0xFFFFFFFF)

   /* usMajorType Values */

   #define X_COMP_MAJOR_TYPE_ALPHA              1
   #define X_COMP_MAJOR_TYPE_NUMERIC            2
   #define X_COMP_MAJOR_TYPE_COMPONENT          3

   /* usMinor Type Values */

   #define X_COMP_MINOR_TYPE_LITERAL            1
   #define X_COMP_MINOR_TYPE_FIELD              2
   #define X_COMP_MINOR_TYPE_SYSTEM_VARIABLE    3
   #define X_COMP_MINOR_TYPE_COMPONENT          4

   /* usExchangeFormat Values */

   /* #define X_COMP_EXCHANGE_AS_STRING            1 */
   /* #define X_COMP_EXCHANGE_AS_LONG              2 */
   /* #define X_COMP_EXCHANGE_AS_DOUBLE            3 */
   /* #define X_COMP_EXCHANGE_NOT_POSSIBLE         4 */

   /* ulResourceKind Values */

   #define X_COMP_RESOURCE_KIND_NULL            0
   #define X_COMP_RESOURCE_KIND_BITMAP          1
   #define X_COMP_RESOURCE_KIND_PNG             2
   #define X_COMP_RESOURCE_KIND_JPG             3

   typedef struct _X_COMP_FCC_DICTIONARY_INFO
   {
      struct _X_COMP_FCC_DICTIONARY_INFO  *  pNext;
      unsigned char                          fchFormalName[50];
      unsigned long                          ulVectorExchangeIdentifer;
      unsigned short                         usMajorType;
      unsigned short                         usMinorType;
      unsigned short                         usLength;
      unsigned short                         usDecimals;
      unsigned short                         usExchangeFormat;
      int                                    fSpareField1;
      int                                    fIsDYNSYSVARReference;
   }
           X_COMP_FCC_DICTIONARY_INFO,
      *   PX_COMP_FCC_DICTIONARY_INFO,
      ** PPX_COMP_FCC_DICTIONARY_INFO;


   /* usMajorType Values */

   #define X_COMP_SCOPE_TYPE_NULL         0
   #define X_COMP_SCOPE_TYPE_SHARED       1
   #define X_COMP_SCOPE_TYPE_INSTANCE     2
   #define X_COMP_SCOPE_TYPE_LOCAL        3

   typedef struct _X_COMP_FCC_GET_PROPERTY_INFO
   {
      unsigned long                          ulPropertyExchangeIdentifer;
      unsigned short                         usExchangeFormat;
      unsigned short                         usLength;
      unsigned short                         usDecimals;
      unsigned short                         usScope;
      X_COMP_EVALUATION_TYPE_INFO            ulFieldInfo;
   }
         X_COMP_FCC_GET_PROPERTY_INFO,
    *   PX_COMP_FCC_GET_PROPERTY_INFO,
    ** PPX_COMP_FCC_GET_PROPERTY_INFO;


   typedef struct _X_COMP_FCC_GET_LITERAL_INFO
   {
      unsigned char                       *  pvchLiteral;
      unsigned short                         usLiteralLength;
      unsigned short                         usLiteralEbcdicLength;
   }
         X_COMP_FCC_GET_LITERAL_INFO,
    *   PX_COMP_FCC_GET_LITERAL_INFO,
    ** PPX_COMP_FCC_GET_LITERAL_INFO;


   /* ================================================================= */
   /* LL2 Escaped Tokens types                                          */
   /* ================================================================= */
   /*                                                                   */
   /*    LL2 Expression Escape Character                                */
   /*    LL2 Command Procedure/Functions                                */
   /*    LL2 Parameters                                                 */
   /*                                                                   */
   /* FN_TOKEN_TYPE_FIELD_CALLBACK                                      */
   /*    Callback to recieve field element as member of a list          */
   /*                                                                   */
   /* LIIO_FCC_EnumerateTokenTypeParmFieldAttributeList                 */
   /*    LIIO service called by DC_P3100 to enumerate the field         */
   /*    and field attribute members of a Field Attr list parm          */
   /* ================================================================= */

   /* ----------------------------------------------------------------- */
   /* LL2 Token definitions                                             */
   /* ----------------------------------------------------------------- */
   #define ODEF_LL2_ET_SIZE                              9

   #define ODEF_LL2_ET_ESCAPE_OFFSET                     0
   #define ODEF_LL2_ET_TYPE_OFFSET                       1
   #define ODEF_LL2_ET_PAYLOAD_OFFSET                    2

   #define ODEF_LL2_ET_PAYLOAD_SIZE                      7

   /* ----------------------------------------------------------------- */
   /* LL2 Token byte 2 - Escaped Token Type definitions                 */
   /* ----------------------------------------------------------------- */
   #define ODEF_LL2_ETT_NOP_ID                           '1'
   #define ODEF_LL2_ETT_PENDING_ID                       '2'

   #define ODEF_LL2_ETT_CMD_DISPATCH_ID                  'A'
   #define ODEF_LL2_ETT_CMD_COMMAND_PROC                 'B'
   #define ODEF_LL2_ETT_CMD_COMPONENT_PROC               'C'
   #define ODEF_LL2_ETT_BOOLEAN_FUNC                     'D'
   #define ODEF_LL2_ETT_STRING_FUNC                      'E'
   #define ODEF_LL2_ETT_WHEN_FUNC                        'F'
   #define ODEF_LL2_ETT_CASE_PROC                        'G'
   #define ODEF_LL2_ETT_EXECUTE_PROC                     'H'

   #define ODEF_LL2_ETT_IDENTIFIER_WITH_LONG_NAME        'L'
   #define ODEF_LL2_ETT_PARM_FLD_ATTR_LIST               'M'
   #define ODEF_LL2_ETT_PARM_CALLBACK_EVALUATION         'N'
   #define ODEF_LL2_ETT_PARM_DEFAULT_VALUE_PROC          'O'
   #define ODEF_LL2_ETT_FIELD                            'P'
   #define ODEF_LL2_ETT_FIELD_COMPONENT                  'Q'
   #define ODEF_LL2_ETT_PARM_COMPONENT_EVALUATION        'R'
   #define ODEF_LL2_ETT_VECTORED_LITERAL                 'S'
   #define ODEF_LL2_ETT_STATIC_LITERAL                   'T'

   /* ----------------------------------------------------------------- */
   /* LL2 ET Field Attribute List parameter callback definitions        */
   /* ----------------------------------------------------------------- */
   typedef LIIO_FCC_INTERFACE
      FN_LL2_ETT_FIELD_CALLBACK                                (
         unsigned char                                         *  pvchFieldName,
         unsigned char                                         *  pvchStructuredAttributeList,
         void                                                  *  pVoidOne,
         void                                                  *  pVoidTwo );

   typedef FN_LL2_ETT_FIELD_CALLBACK
      *PFN_LL2_ETT_FIELD_CALLBACK;

   typedef FN_LL2_ETT_FIELD_CALLBACK
      **PPFN_LL2_ETT_FIELD_CALLBACK;

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_EnumerateFieldAttributeParmList         (
         unsigned char                                         *  pvchEscapedToken,
         PFN_LL2_ETT_FIELD_CALLBACK                               pfnFieldCallBack,
         void                                                  *  pVoidOne,
         void                                                  *  pVoidTwo ),
      LIIO_FCC_LL2_ETT_EnumerateWhereExpressionFileFieldList   (
         unsigned char                                         *  pvchEscapedToken,
         PFN_LL2_ETT_FIELD_CALLBACK                               pfnFieldCallBack,
         void                                                  *  pVoidOne,
         void                                                  *  pVoidTwo );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_LL2_ETT_QueryGetLiteralInfo                           */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_QueryGetLiteralInfo               (
         unsigned char                                   *  pvchEscapedToken,
         X_COMP_FCC_GET_LITERAL_INFO                     *  pInfo );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_LL2_ETT_QueryGetLongName                              */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_QueryGetLongName                  (
         unsigned char                                   *  pvchEscapedToken,
         unsigned char                                   *  pvchAltName );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_LL2_ETT_QueryGetTypeInfo                              */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_QueryGetTypeInfo                  (
         PX_COMP_LPC_ANCHOR_BLOCK                           pLPCAnchor,
         unsigned char                                   *  pvchEscapedToken,
         PX_COMP_FCC_GET_PROPERTY_INFO                      pInfo );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_LL2_ETT_ResolvePendingEscapedParameter                */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_ResolvePendingEscapedParameter (
         PX_COMP_LPC_ANCHOR_BLOCK                        pLPCAnchor,
         unsigned char                                *  pvchPendingEscapedToken,
         unsigned char                                *  pvchResolvedToken,
         int                                             iMaxLength );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_LL2_ETT_IsListUsedAsAnXList                           */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_ListRequiresXListHandling   (
         unsigned char                             *  pvchEscapedToken,
         unsigned char                             *  pchListUsed );

   /* ----------------------------------------------------------------- */
   /* LL2 ET Enumerate Evaluation Escaped Tokens by statement number    */
   /* ----------------------------------------------------------------- */
   typedef LIIO_FCC_INTERFACE
      FN_LL2_ETT_EVALUATION_CALLBACK                     (
         unsigned char                                   *  pvchEscapedToken,
         void                                            *  pVoidOne,
         void                                            *  pVoidTwo );

   typedef FN_LL2_ETT_EVALUATION_CALLBACK
      *PFN_LL2_ETT_EVALUATION_CALLBACK;

   typedef FN_LL2_ETT_EVALUATION_CALLBACK
      **PPFN_LL2_ETT_EVALUATION_CALLBACK;

   LIIO_FCC_INTERFACE
      LIIO_FCC_LL2_ETT_EnumerateStatementEvaluations     (
         unsigned long                                      ulLineNumber,
         PFN_LL2_ETT_EVALUATION_CALLBACK                    pfnEvaluationCallBack,
         void                                            *  pVoidOne,
         void                                            *  pVoidTwo );

   /* -------------------------------------------------------------- */
   /* FCC_ERROR_MESSAGE                                              */
   /* -------------------------------------------------------------- */

   /* usMessageType Values */

   #define X_COMP_WARNING_MESSAGE             1
   #define X_COMP_FATAL_MESSAGE               2

   typedef struct _X_COMP_FCC_ERROR_MESSAGE
   {
      unsigned short                         usMessageType;
      unsigned char                       *  pvchMessage;
   }
      X_COMP_FCC_ERROR_MESSAGE,
      *PX_COMP_FCC_ERROR_MESSAGE,
      **PPX_COMP_FCC_ERROR_MESSAGE;


   /* -------------------------------------------------------------- */
   /* FCC_COMMAND                                                    */
   /* -------------------------------------------------------------- */

   typedef struct _X_COMP_FCC_COMMAND
   {
      unsigned long                          ulLineNumber;
      unsigned long                          ulCommandLength;
      unsigned char                       *  pvchCommand;
      X_COMP_DISPATCH_ID                     lDispatchId;
      unsigned char                          chLL2EscapedToken[ ODEF_LL2_ET_SIZE + 1 ];
      int                                    bUsingFullRDMLX;
      int                                    bUsingRDML2Expression;
      int                                    bUsingEnhancedRDML;
   }
      X_COMP_FCC_COMMAND,
      *PX_COMP_FCC_COMMAND,
      **PPX_COMP_FCC_COMMAND;

   /* -------------------------------------------------------------- */
   /* FCC_RDMLX_FILE_INFO                                            */
   /* -------------------------------------------------------------- */

   #define X_COMP_FCC_RDMLX_FILE_REQUEST_DEFINE                      1
   #define X_COMP_FCC_RDMLX_FILE_REQUEST_CHECK                       2
   #define X_COMP_FCC_RDMLX_FILE_REQUEST_GET_ESCAPED_TOKEN           3

   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_DEFAULT_VALUE            1
   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_SIMPLE_CHECK             2
   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_RANGE_CHECK              3
   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_LIST_CHECK               4
   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_LOOKUP_CHECK_KEY         5
   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_DATE_CHECK               6
   #define X_COMP_FCC_RDMLX_FILE_PART_FIELD_COMPLEX_CHECK_PARM       7
   #define X_COMP_FCC_RDMLX_FILE_PART_TRIGGER_CONDITION              8
   #define X_COMP_FCC_RDMLX_FILE_PART_ACCESS_ROUTE_KEY               9
   #define X_COMP_FCC_RDMLX_FILE_PART_SELECT_OMIT_VALUE_CHECK        10
   #define X_COMP_FCC_RDMLX_FILE_PART_SELECT_OMIT_RANGE_CHECK        11
   #define X_COMP_FCC_RDMLX_FILE_PART_SELECT_OMIT_SIMPLE_CHECK       12
   #define X_COMP_FCC_RDMLX_FILE_PART_CODE_FRAGMENT                  13

   typedef struct _X_COMP_FCC_RDMLX_FILE_INFO
   {
      unsigned long                          ulFilePart;
      unsigned char                       *  pvchIdentifier;
      unsigned char                       *  pvchQualifier1;
      unsigned char                       *  pvchQualifier2;
      unsigned char                       *  pvchExpression;
      unsigned char                       *  pvchExpression2;
      unsigned char                          chLL2EscapedToken[ ODEF_LL2_ET_SIZE + 1 ];
      int                                    bUsingRDML2Feature;
   }
      X_COMP_FCC_RDMLX_FILE_INFO,
      *PX_COMP_FCC_RDMLX_FILE_INFO,
      **PPX_COMP_FCC_RDMLX_FILE_INFO;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to query the type of       */
   /* a simple vectored field or string                              */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_DICTIONARY_INFO_CALLBACK         (
         unsigned char                    *  pvchObjectReference,
         PX_COMP_FCC_DICTIONARY_INFO         pObject,
         int                                 bQueryOnly );

   typedef FN_DICTIONARY_INFO_CALLBACK
      *PFN_DICTIONARY_INFO_CALLBACK;

   typedef FN_DICTIONARY_INFO_CALLBACK
      **PPFN_DICTIONARY_INFO_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to register                */
   /* field component usage                                          */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_REGISTER_FIELD_CALLBACK          (
         unsigned char                    *  pvchClassName,
         unsigned char                    *  pvchVariableName,
         unsigned char                    *  pvchIdentifier,
         X_COMP_DISPATCH_ID                  ulDispatchId,
         int                                 bAncestorDefinition );

   typedef FN_REGISTER_FIELD_CALLBACK
      *PFN_REGISTER_FIELD_CALLBACK;

   typedef FN_REGISTER_FIELD_CALLBACK
      **PPFN_REGISTER_FIELD_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to register                */
   /* list component usage                                           */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_REGISTER_LIST_CALLBACK           (
         unsigned char                    *  pvchListClassName,
         unsigned char                    *  pvchListName,
         char                                chListType,
         X_COMP_DISPATCH_ID                  ulDispatchId,
         int                                 bFullRdmlxList );

   typedef FN_REGISTER_LIST_CALLBACK
      *PFN_REGISTER_LIST_CALLBACK;

   typedef FN_REGISTER_LIST_CALLBACK
      **PPFN_REGISTER_LIST_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to register                */
   /* list column component usage                                    */
   /* -------------------------------------------------------------- */
   typedef LIIO_FCC_INTERFACE
      FN_REGISTER_LIST_COLUMN_CALLBACK    (
         unsigned char                    *  pvchListName,
         unsigned char                    *  pvchListColumnClassName,
         unsigned char                    *  pvchListColumnName,
         X_COMP_DISPATCH_ID                  ulDispatchId,
         unsigned char                    *  pvchSourceFieldName  );

   typedef FN_REGISTER_LIST_COLUMN_CALLBACK
      *PFN_REGISTER_LIST_COLUMN_CALLBACK;

   typedef FN_REGISTER_LIST_COLUMN_CALLBACK
      **PPFN_REGISTER_LIST_COLUMN_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to return tokenized RDML2  */
   /* commands                                                       */
   /* -------------------------------------------------------------- */
   typedef LIIO_FCC_INTERFACE
      FN_APPLY_RDML2_TOKENIZED_CALLBACK   (
         unsigned long                       ulLineNumber,
         unsigned char                    *  pvchTokenStream );

   typedef FN_APPLY_RDML2_TOKENIZED_CALLBACK
      *PFN_APPLY_RDML2_TOKENIZED_CALLBACK;

   typedef FN_APPLY_RDML2_TOKENIZED_CALLBACK
      **PPFN_APPLY_RDML2_TOKENIZED_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC_EnumerateComponentModule            */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_TABLE_ENUMERATE_CALLBACK      (
         void                          *  pVoidHeader,
         void                          *  ppTableChain,
         void                          *  pTable );

   typedef FN_TABLE_ENUMERATE_CALLBACK
      *PFN_TABLE_ENUMERATE_CALLBACK;

   typedef FN_TABLE_ENUMERATE_CALLBACK
      **PPFN_TABLE_ENUMERATE_CALLBACK;


   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to lookup dictionary       */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_DICTIONARY_INFO_CALLBACK         (
         unsigned char                    *  pvchObjectReference,
         PX_COMP_FCC_DICTIONARY_INFO         pObject,
         int                                 bQueryOnly );

   typedef FN_DICTIONARY_INFO_CALLBACK
      *PFN_DICTIONARY_INFO_CALLBACK;

   typedef FN_DICTIONARY_INFO_CALLBACK
      **PPFN_DICTIONARY_INFO_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC routines to issue a message         */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_ISSUE_FATAL_MESSAGE_CALLBACK     (
         PX_COMP_FCC_ERROR_MESSAGE           pErrorMessage );

   typedef FN_ISSUE_FATAL_MESSAGE_CALLBACK
      *PFN_ISSUE_FATAL_MESSAGE_CALLBACK;

   typedef FN_ISSUE_FATAL_MESSAGE_CALLBACK
      **PPFN_ISSUE_FATAL_MESSAGE_CALLBACK;


   /* -------------------------------------------------------------- */
   /* LIIO_FCC_EnumerateComponentModule                              */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_EnumerateComponentModule   (
         PFN_TABLE_ENUMERATE_CALLBACK        pfnTableCallBack,
         void                             *  ppTableChain,
         void                             *  pTable );

   /* -------------------------------------------------------------- */
   /* LL2 Expression Pcode enumeration types                         */
   /*                                                                */
   /* FN_PCODE_ENUMERATE_CALLBACK                                    */
   /*    Callback to recieve pcode as X_COMP_PCODE_HEADER's          */
   /*                                                                */
   /* LIIO_FCC_EnumerateRoutinePcode                                 */
   /* LIIO_FCC_EnumerateExpressionPcode                              */
   /*    LIIO service called by DC_P3109 to enumerate the pcode      */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_PCODE_ENUMERATE_CALLBACK      (
         void                          *  pPcodeHeader,
         void                          *  pVoidOne,
         void                          *  pVoidTwo );

   typedef FN_PCODE_ENUMERATE_CALLBACK
      *PFN_PCODE_ENUMERATE_CALLBACK;

   typedef FN_PCODE_ENUMERATE_CALLBACK
      **PPFN_PCODE_ENUMERATE_CALLBACK;

   LIIO_FCC_INTERFACE
      LIIO_FCC_EnumerateExpressionPcode   (
         PFN_PCODE_ENUMERATE_CALLBACK        pfnRoutineCallBack,
         void                             *  pVoidOne,
         void                             *  pVoidTwo ),

      LIIO_FCC_EnumerateRoutinePcode      (
         unsigned char                    *  pvchEscapedToken,
         PFN_PCODE_ENUMERATE_CALLBACK        pfnRoutineCallBack,
         void                             *  pVoidOne,
         void                             *  pVoidTwo );


   /* -------------------------------------------------------------- */
   /* LIIO_FCC_EnumerateXREFDetails                                  */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_EnumerateXREFDetails ( void );

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO routines to record component XREF       */
   /* details                                                        */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_RECORD_XREF_DETAILS           (
         short                            sReferenceType,
         char                          *  pvchReferenceObjectId,
         char                          *  pvchReferenceObjectIdExtension1,
         char                          *  pvchReferenceObjectIdExtension2,
         char                          *  pvchXREFInfo );

   typedef FN_RECORD_XREF_DETAILS
      *PFN_RECORD_XREF_DETAILS;

   typedef FN_RECORD_XREF_DETAILS
      **PPFN_RECORD_XREF_DETAILS;


   /* -------------------------------------------------------------- */
   /* CONTROL_FCC                                                    */
   /* -------------------------------------------------------------- */

   /* usModeofOperation Values */

   #define X_COMP_FCC_OPERATING_FROM_EDITOR     1
   #define X_COMP_FCC_OPERATING_IN_BATCH        2

   typedef struct _X_COMP_CONTROL_FCC
   {
      unsigned char                    *  pvchPrimaryComponentName;
      unsigned short                      usModeofOperation;
      unsigned char                    *  pvchPrimaryComponentAncestorName;
      unsigned char                    *  pvchProcessName;
      unsigned char                    *  pvchFunctionName;
      unsigned char                    *  pvchFileName;
      unsigned char                    *  pvchFileLibraryName;
      int                                 fIsLanguageLevelTwo;
      int                                 fIsComponentModuleRequired;
      int                                 fCompoundBuild;
      int                                 iBuildUnitCount;
      int                                 iCurrentBuildUnit;
      int                                 iCurrentBuildUnitIdentifier;
      FN_REGISTER_FIELD_CALLBACK       *  pfnFieldCallback;
      FN_REGISTER_LIST_CALLBACK        *  pfnListCallback;
      FN_REGISTER_LIST_COLUMN_CALLBACK *  pfnListColumnCallback;
      FN_DICTIONARY_INFO_CALLBACK      *  pfnGetDictionaryInfoCallBack;
      FN_RECORD_XREF_DETAILS           *  pfnRecordXREFCallback;
   }
           X_COMP_FCC_CONTROL,
      *   PX_COMP_FCC_CONTROL,
      ** PPX_COMP_FCC_CONTROL;

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_Batch_Start and LIIO_FCC_Batch_End                    */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_Batch_Start                (  );

   LIIO_FCC_INTERFACE
      LIIO_FCC_Batch_End                  (  );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_StartBuild and LIIO_FCC_EndBuild                      */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_StartBuild                 (
         X_COMP_LPC_ANCHOR_BLOCK          *  pLPCAnchor,
         X_COMP_FCC_CONTROL               *  pFCCControl );

   LIIO_FCC_INTERFACE
      LIIO_FCC_EndBuild                   (
         X_COMP_LPC_ANCHOR_BLOCK          *  pLPCAnchor,
         X_COMP_FCC_CONTROL               *  pFCCControl );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC PASS1 and PASS2 Checking APIs:                        */
   /*                                                                */
   /*    LIIO_FCC_StartChecking                                      */
   /*    LIIO_FCC_CompleteChecking                                   */
   /*    LIIO_FCC_EndChecking                                        */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_StartChecking              (
         X_COMP_LPC_ANCHOR_BLOCK          *  pLPCAnchor,
         X_COMP_FCC_CONTROL               *  pFCCControl );

   LIIO_FCC_INTERFACE
      LIIO_FCC_CompleteChecking           (
         X_COMP_LPC_ANCHOR_BLOCK          *  pLPCAnchor,
         X_COMP_FCC_CONTROL               *  pFCCControl );

   LIIO_FCC_INTERFACE
      LIIO_FCC_EndChecking                (
         X_COMP_LPC_ANCHOR_BLOCK          *  pLPCAnchor,
         X_COMP_FCC_CONTROL               *  pFCCControl );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_RetrieveCompoundComponentRDMLX                        */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_RetrieveCompoundComponentRDMLX   (
         PX_COMP_LPC_ANCHOR_BLOCK                  pLPCAnchor,
         X_COMP_CALLBACK                           pfnApplyComponentRDML );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_TokenizeCommand                                       */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_TokenizeCommand                  (
         PX_COMP_LPC_ANCHOR_BLOCK                  pLPCAnchor,
         PX_COMP_FCC_COMMAND                       pRDMLXCommand,
         PFN_ISSUE_FATAL_MESSAGE_CALLBACK          pfnIssueMessage,
         PFN_APPLY_RDML2_TOKENIZED_CALLBACK        pfnApplyTokenizedCommand );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_ParseRDMLX                                            */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_ParseRDMLX                       (
         PX_COMP_LPC_ANCHOR_BLOCK                  pLPCAnchor,
         unsigned long                             ulPassNumber,
         PX_COMP_FCC_COMMAND                       pRDMLXCommand,
         PFN_ISSUE_FATAL_MESSAGE_CALLBACK          pfnIssueMessage,
         PFN_DICTIONARY_INFO_CALLBACK              pfnGetDictionaryInfo );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_ParseRDML2                                            */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_ParseRDML2                       (
         PX_COMP_LPC_ANCHOR_BLOCK                  pLPCAnchor,
         unsigned long                             ulPassNumber,
         PX_COMP_FCC_COMMAND                       pRDMLXCommand,
         PFN_ISSUE_FATAL_MESSAGE_CALLBACK          pfnIssueMessage,
         PFN_DICTIONARY_INFO_CALLBACK              pfnGetDictionaryInfo,
         PFN_APPLY_RDML2_TOKENIZED_CALLBACK        pfnApplyTokenizedCommand );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_ParseRDMLX_File                                       */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_ParseRDMLX_File                  (
         PX_COMP_LPC_ANCHOR_BLOCK                  pLPCAnchor,
         unsigned long                             ulRequest,
         PX_COMP_FCC_RDMLX_FILE_INFO               pFileInfo,
         PFN_ISSUE_FATAL_MESSAGE_CALLBACK          pfnIssueMessage,
         PFN_DICTIONARY_INFO_CALLBACK              pfnGetDictionaryInfo );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_QueryGETProperty                                      */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_QueryGetProperty           (
         PX_COMP_LPC_ANCHOR_BLOCK            pLPCAnchor,
         unsigned char                    *  pvchQualifiedName,
         PX_COMP_FCC_GET_PROPERTY_INFO       pGetPropertyInfo );

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_PrepareFieldDefaultValue                              */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_PrepareFieldDefaultValue   (
         PX_COMP_LPC_ANCHOR_BLOCK            pLPCAnchor,
         unsigned char                    *  pvchFieldName,
         unsigned char                    *  pvchDefaultValue,
         unsigned char                    *  pvchEscapedToken );

   /* ================================================================= */
   /*                                                                   */
   /*  FN_RUN_WAM_ENUMERATION_CALLBACK: Callback for WAM Enumeration    */
   /*                                                                   */
   /* ==================================================================*/
   /* Name            Description                                       */
   /* ----            -----------                                       */
   /* Parm1           PX_COMP_LPC_ANCHOR_BLOCK                          */
   /* Parm2           PX_COMP_CMPE_ANCHOR_BLOCK (NULL)                  */
   /* Parm3           PX_COMP_TSP_ANCHOR_BLOCK                          */
   /* Parm4           X_TSP_CALLBACK - fnStartWamCallBack               */
   /* Parm5           X_TSP_CALLBACK - fnStartWebRoutineCallBack        */
   /* Parm6           X_TSP_CALLBACK - fnAddFieldParameterCallBack      */
   /* Parm7           X_TSP_CALLBACK - fnAddListParameterCallBack       */
   /* Parm8           X_TSP_CALLBACK - fnAddListFieldCallBack           */
   /* Parm9           X_TSP_CALLBACK - fnEndListParameterCallBack       */
   /* Parm10          X_TSP_CALLBACK - fnEndWamCallBack                 */
   /*                                                                   */
   /* ================================================================= */

   typedef LIIO_FCC_INTERFACE
      FN_RUN_WAM_ENUMERATION_CALLBACK     (
         PX_COMP_LPC_ANCHOR_BLOCK            pLPCAnchor,
         PX_COMP_CMPE_ANCHOR_BLOCK           pCMPEAnchor,
         void                             *  pTSPAnchor,
         void                             *  pfnStartWamCallback,
         void                             *  pfnStartWebRoutineCallback,
         void                             *  pfnAddFieldParameterCallback,
         void                             *  pfnAddListParameterCallback,
         void                             *  pfnAddListFieldCallback,
         void                             *  pfnEndListParameterCallback,
         void                             *  pfnEndWamCallback );

   typedef FN_RUN_WAM_ENUMERATION_CALLBACK
      *PFN_RUN_WAM_ENUMERATION_CALLBACK;

   typedef FN_RUN_WAM_ENUMERATION_CALLBACK
      **PPFN_RUN_WAM_ENUMERATION_CALLBACK;

   /* -------------------------------------------------------------- */
   /* Call back used by LIIO_FCC_EnumerateWebAccessModule            */
   /* -------------------------------------------------------------- */

   typedef LIIO_FCC_INTERFACE
      FN_INITIATE_WAM_ENUMERATION_CALLBACK   (
         PX_COMP_LPC_ANCHOR_BLOCK               pLPCAnchor,
         PFN_RUN_WAM_ENUMERATION_CALLBACK       pfnRunWamEnumeration );

   typedef FN_INITIATE_WAM_ENUMERATION_CALLBACK
      *PFN_INITIATE_WAM_ENUMERATION_CALLBACK;

   typedef FN_INITIATE_WAM_ENUMERATION_CALLBACK
      **PPFN_INITIATE_WAM_ENUMERATION_CALLBACK;

   /* -------------------------------------------------------------- */
   /* LIIO_FCC_EnumerateWebAccessModule                              */
   /* -------------------------------------------------------------- */

   LIIO_FCC_INTERFACE
      LIIO_FCC_EnumerateWebAccessModule         (
         PX_COMP_LPC_ANCHOR_BLOCK                  pLPCAnchor,
         PFN_INITIATE_WAM_ENUMERATION_CALLBACK     pfnInitiateWamEnumeration );

#endif /* X_COMP_FCC_SUPPORT */

/* ----------------------------------------------------------------- */
/* Communication structures used between LANSA/X and X_COMP          */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   /* -------------------------------------------------------------- */
   /* X_COMP_MESSAGE_EXCHANGE                                        */
   /* -------------------------------------------------------------- */
   typedef struct _X_COMP_MESSAGE_EXCHANGE
   {
      char                             vchMessageId[7 + 1];
      char                             vchMessageFile[10 + 1];
      char                             chMessageFormat;
      char                             fchSubstitutionData[512]; /* repeat of X_MESSAGE_DATA_LEN */
   }
      X_COMP_MESSAGE_EXCHANGE,
      *PX_COMP_MESSAGE_EXCHANGE,
      **PPX_COMP_MESSAGE_EXCHANGE;

#endif /* X_COMP_RUN_TIME_SUPPORT */

/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
/* Code and types for Business Object Module building                 */
/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ */
/* Request identifiers for Record service functions.                  */
/* ------------------------------------------------------------------ */

typedef long
   X_COMP_RECORD_SERVICE_REQUEST;

#define X_COMP_RECORD_SERVICE_REQUEST_NULL                           0L

#define X_COMP_RECORD_SERVICE_REQUEST_PROXY_ADD_ENTRY                1L
#define X_COMP_RECORD_SERVICE_REQUEST_PROXY_STORE_ENTRY              2L

#define X_COMP_RECORD_SERVICE_REQUEST_DOCUMENT_ADD_ENTRY            10L
#define X_COMP_RECORD_SERVICE_REQUEST_DOCUMENT_STORE_ENTRY          11L
#define X_COMP_RECORD_SERVICE_REQUEST_DOCUMENT_REPORT_ERROR         12L

/* ------------------------------------------------------ */
/* Definition of interface for Record Service functions   */
/* ------------------------------------------------------ */

#if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_ISERIES)

typedef X_COMP_RETURN_CODE 
   X_COMP_RECORD_SERVICES_POINT_FCN       ( 
      X_COMP_RECORD_SERVICE_REQUEST          lRequest,
	   void                                *  apvAgreedArgs[] );

#else

typedef X_COMP_RETURN_CODE __cdecl 
   X_COMP_RECORD_SERVICES_POINT_FCN       ( 
      X_COMP_RECORD_SERVICE_REQUEST          lRequest,
	   void                                *  apvAgreedArgs[] );

#endif

typedef X_COMP_RECORD_SERVICES_POINT_FCN 
   *  PX_COMP_RECORD_SERVICES_POINT_FCN,
   ** PPX_COMP_RECORD_SERVICES_POINT_FCN;

/* ------------------------------------------------------------------ */
/* Kind identifiers for BOM dispatch tables.                          */
/* ------------------------------------------------------------------ */

typedef unsigned long
   X_BOM_KIND;

#define X_BOM_KIND_NULL                                           0L

#define X_BOM_KIND_DEF_CONTENT_MODEL_HOME                         1000L
#define X_BOM_KIND_DEF_CONTENT_LINK_MODEL_SERVICES_HANDLER        1010L
#define X_BOM_KIND_DEF_CONTENT_LINK_MODEL_SHARED_HANDLER          1011L
#define X_BOM_KIND_DEF_CONTENT_LINK_DATA_TYPE_COMPONENT_HANDLER   1020L
#define X_BOM_KIND_DEF_CONTENT_LINK_DATA_TYPE_SERVICES_HANDLER    1021L
#define X_BOM_KIND_DEF_CONTENT_LINK_DATA_TYPE_SHARED_HANDLER      1022L
#define X_BOM_KIND_DEF_CONTENT_MODEL_CLIENT                       1070L
#define X_BOM_KIND_DEF_CONTENT_USER_DEFINED_CONTROL               1080L

#define X_BOM_KIND_DEF_DATA_TYPE_RECORD                           1100L
#define X_BOM_KIND_DEF_UDC_RECORD                                 1110L

#define X_BOM_KIND_DEF_RECORD_FIELD                               1200L
#define X_BOM_KIND_DEF_RECORD_CHILD_STORE                         1210L

#define X_BOM_KIND_DEF_DISPATCH_DATA_TYPE_RECORD                  1300L
#define X_BOM_KIND_DEF_DISPATCH_DATA_TYPE_RECORD_SET              1310L
#define X_BOM_KIND_DEF_DISPATCH_DATA_TYPE_RECORD_GET              1320L
#define X_BOM_KIND_DEF_DISPATCH_UDC_RECORD                        1330L

#define X_BOM_KIND_DEF_SERVICE_PROXY_LOADER                       1400L
#define X_BOM_KIND_DEF_SERVICE_PROXY_SEARCH                       1410L

#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_RESTORE                   1500L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_READ                      1510L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_INSERT                    1520L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_UPDATE                    1530L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_DELETE                    1540L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_DELETE_ALL                1550L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_DELETE_CURRENT            1560L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_CROSS_UPDATE_CHECK        1570L
#define X_BOM_KIND_DEF_SERVICE_DOCUMENT_VERIFY                    1580L

#define X_BOM_KIND_DEF_SERVICE_ELEMENT_BLOCK                      1600L
#define X_BOM_KIND_DEF_SERVICE_CODE_POINT                         1610L
#define X_BOM_KIND_DEF_SERVICE_CROSS_UPDATE_CHECK_GROUP           1620L
#define X_BOM_KIND_DEF_SERVICE_CROSS_UPDATE_CHECK_CONDITION       1630L
#define X_BOM_KIND_DEF_SERVICE_VERIFY_BLOCK                       1640L
#define X_BOM_KIND_DEF_SERVICE_VERIFY_RULE                        1650L

#define X_BOM_KIND_DEF_UDC_TYPE                                   1700L
#define X_BOM_KIND_DEF_UDC_TYPE_MEMBER                            1710L

#define X_BOM_KIND_DEF_MODEL_DATA_TYPE                            2000L
#define X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER                     2010L
#define X_BOM_KIND_DEF_MODEL_DATA_TYPE_ACTION                     2020L
#define X_BOM_KIND_DEF_MODEL_DATA_TYPE_ACTION_PART                2030L

#define X_BOM_KIND_DEF_MODEL_REQUEST_OPERATION                    2100L
#define X_BOM_KIND_DEF_MODEL_REQUEST_OPERATION_PART               2110L

#define X_BOM_KIND_DEF_MODEL_ENTITY_REF_FIELD                     3000L
#define X_BOM_KIND_DEF_MODEL_ENTITY_REF_FILE_FIELD                3010L
#define X_BOM_KIND_DEF_MODEL_ENTITY_REF_DATA_TYPE                 3020L
#define X_BOM_KIND_DEF_MODEL_ENTITY_REF_REUSABLE_PART             3030L

/* ----------------------------------------------------------------- */
/* X_BOM_HEADER                                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       All of the above                                            */
/*                                                                   */
/* ----------------------------------------------------------------- */

typedef struct _X_BOM_HEADER
{
   X_BOM_KIND                                                  ulKind;
}
   X_BOM_HEADER,
   *PX_BOM_HEADER,
   **PPX_BOM_HEADER;

/* ----------------------------------------------------------------- */
/* X_BOM_CONTENT                                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_CONTENT_MODEL_HOME                           */
/*       X_BOM_KIND_DEF_CONTENT_DOCUMENT_HOME                        */
/*       X_BOM_KIND_DEF_CONTENT_PROXY_SERVER                         */
/*       X_BOM_KIND_DEF_CONTENT_DOCUMENT_SERVER                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_CONTENT
   {
      X_BOM_KIND                                               ulKind;
      unsigned long                                            ulFlags;
      const unsigned char                                   *  pvchBuildGuid;
      X_BOM_HEADER                                          *  pImplementation;
      X_BOM_HEADER                                          *  pRepresentativeDataType;
      unsigned long                                            ulItemCount;
      X_BOM_HEADER                                          ** ppItemTable;
      unsigned long                                            ulFeatureCount;
      X_BOM_KIND                                            *  pFeatureTable;
   }
      X_BOM_CONTENT,
      *PX_BOM_CONTENT,
      **PPX_BOM_CONTENT;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_CONTENT_FCC
   {
      X_BOM_KIND                                               ulKind;
      unsigned long                                            ulFlags;
      const unsigned char                                   *  pvchBuildGuid;
      X_BOM_HEADER                                          *  pImplementation;
      X_BOM_HEADER                                          *  pRepresentativeDataType;
      unsigned long                                            ulItemCount;
      X_BOM_HEADER                                          ** ppItemTable;
   }
      X_BOM_CONTENT_FCC,
      *PX_BOM_CONTENT_FCC,
      **PPX_BOM_CONTENT_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_CONTENT_LINK                                                */
/*                                                                   */
/*   Supports:                                                       */
/*       X_BOM_KIND_DEF_CONTENT_LINK_DOCUMENT_HOME                   */
/*       X_BOM_KIND_DEF_CONTENT_LINK_PROXY_SERVER                    */
/*       X_BOM_KIND_DEF_CONTENT_LINK_DOCUMENT_SERVER                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_CONTENT_LINK
   {
      X_COMP_KIND                         ulKind;
      FN_COMP_SERVICES_POINT           *  pfnMemberServices;
   }
      X_BOM_CONTENT_LINK,
      *PX_BOM_CONTENT_LINK,
      **PPX_BOM_CONTENT_LINK;

#endif

#if defined(X_COMP_FCC_SUPPORT)

  typedef struct _X_BOM_CONTENT_LINK_FCC
   {
      X_COMP_KIND                         ulKind;
      long                                lFragmentIdentifier;
   }
      X_BOM_CONTENT_LINK_FCC,
      *PX_BOM_CONTENT_LINK_FCC,
      **PPX_BOM_CONTENT_LINK_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_FEATURE                                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_FEATURE                                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_FEATURE
   {
      X_BOM_KIND                                               ulKind;
   }
      X_BOM_FEATURE,
      *PX_BOM_FEATURE,
      **PPX_BOM_FEATURE;

#endif

#endif // X_OPERATING_TARGET_CSHARP

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_FEATURE_FCC
   {
      X_BOM_KIND                                               ulKind;
   }
      X_BOM_FEATURE_FCC,
      *PX_BOM_FEATURE_FCC,
      **PPX_BOM_FEATURE_FCC;

#endif

#endif // X_OPERATING_TARGET_CSHARP

/* ----------------------------------------------------------------- */
/* X_BOM_DISPATCH_RECORD                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_DISPATCH_PROXY_RECORD                        */
/*       X_BOM_KIND_DEF_DISPATCH_SEARCH_RECORD                       */
/*       X_BOM_KIND_DEF_DISPATCH_DOCUMENT_RECORD                     */
/*       X_BOM_KIND_DEF_DISPATCH_IDENTIFIER_RECORD                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   #if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_ISERIES)

      typedef void
         X_COMP_BOM_DISPATCH_RECORD_COPY_FCN                (
            struct X_IDS                                    *  pX_Ids,
            struct X_PRO                                    *  pX_Pro,
            struct X_FUN                                    *  pX_Fun,
            struct X_FLD                                    *  pX_Fld,
            const void                                      *  pvRec );

      typedef void
         X_COMP_BOM_DISPATCH_RECORD_TRANSFER_FCN   (
            const void                             * pvRec1,
            const void                             * pvRec2 );

   #else

      typedef void __cdecl
         X_COMP_BOM_DISPATCH_RECORD_COPY_FCN                ( 
            struct X_IDS                                    *  pX_Ids,
            struct X_PRO                                    *  pX_Pro,
            struct X_FUN                                    *  pX_Fun,
            struct X_FLD                                    *  pX_Fld,
            const void                                      *  pvRec );

      typedef void __cdecl
         X_COMP_BOM_DISPATCH_RECORD_TRANSFER_FCN   ( 
            const void                             * pvRec1,
            const void                             * pvRec2 );

   #endif

   typedef struct _X_BOM_DISPATCH_RECORD
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulEntityPID;
      unsigned long                                            ulDispatchVector;
      const struct X_DRD                                    *  pDescription;
      X_COMP_BOM_DISPATCH_RECORD_COPY_FCN                   *  pfnAssembleRecord;
      X_COMP_BOM_DISPATCH_RECORD_COPY_FCN                   *  pfnDisassembleRecord;
      X_COMP_BOM_DISPATCH_RECORD_TRANSFER_FCN               *  pfnTransferRecord;
   }
      X_BOM_DISPATCH_RECORD,
      *PX_BOM_DISPATCH_RECORD,
      **PPX_BOM_DISPATCH_RECORD;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_RECORD                                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_PROXY_RECORD                                 */
/*       X_BOM_KIND_DEF_DOCUMENT_RECORD                              */
/*       X_BOM_KIND_DEF_IDENTIFIER_RECORD                            */
/*       X_BOM_KIND_DEF_DATA_TYPE_RECORD                             */
/*                                                                   */
/*       X_BOM_KIND_DEF_DISPATCH_DATA_TYPE_RECORD                    */
/*                                                                   */
/*       X_BOM_KIND_DEF_DISPATCH_DATA_TYPE_RECORD_GET                */
/*       X_BOM_KIND_DEF_DISPATCH_DATA_TYPE_RECORD_SET                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   #if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_ISERIES)

      typedef void
         X_COMP_BOM_DATA_RECORD_RELEASE_FCN        (
            void                                   *  pvDR );

      typedef void
         X_COMP_BOM_DATA_RECORD_COPY_FCN           (
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

      typedef void
         X_COMP_BOM_DATA_RECORD_MOVE_FCN           (
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

      typedef X_UINT32 
         X_COMP_BOM_DATA_RECORD_HASH_FCN           ( 
	         void                                   *  pvDR );

      typedef X_INT32 
         X_COMP_BOM_DATA_RECORD_COMPARE_FCN        ( 
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

      typedef X_BOOL 
         X_COMP_BOM_DATA_RECORD_ISEQUAL_FCN        ( 
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

   #else

      typedef void __cdecl
         X_COMP_BOM_DATA_RECORD_RELEASE_FCN        (
	         void                                   *  pvDR );

      typedef void __cdecl
         X_COMP_BOM_DATA_RECORD_COPY_FCN           (
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

      typedef void __cdecl
         X_COMP_BOM_DATA_RECORD_MOVE_FCN           (
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

      typedef X_UINT32 __cdecl
         X_COMP_BOM_DATA_RECORD_HASH_FCN           ( 
	         void                                   *  pvDR );

      typedef X_INT32 __cdecl
         X_COMP_BOM_DATA_RECORD_COMPARE_FCN        ( 
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

      typedef X_BOOL __cdecl
         X_COMP_BOM_DATA_RECORD_ISEQUAL_FCN        ( 
            void                                   *  pvDR1,
	         void                                   *  pvDR2 );

   #endif

   typedef struct _X_BOM_RECORD
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulEntityPID;
      long                                                     lChildIndex;
      long                                                     lChildrenCount;
      const struct X_DRD                                    *  pDescription;
      X_COMP_BOM_DATA_RECORD_RELEASE_FCN                    *  pfnReleaseD;
      X_COMP_BOM_DATA_RECORD_COPY_FCN                       *  pfnCopyDDD;
      X_COMP_BOM_DATA_RECORD_COPY_FCN                       *  pfnCopyDII;
      X_COMP_BOM_DATA_RECORD_COPY_FCN                       *  pfnCopyIDI;
      X_COMP_BOM_DATA_RECORD_MOVE_FCN                       *  pfnMoveDDD;
      X_COMP_BOM_DATA_RECORD_HASH_FCN                       *  pfnHashDI;
      X_COMP_BOM_DATA_RECORD_COMPARE_FCN                    *  pfnCompareDDD;
      X_COMP_BOM_DATA_RECORD_COMPARE_FCN                    *  pfnCompareDII;
      X_COMP_BOM_DATA_RECORD_COMPARE_FCN                    *  pfnCompareDDI;
      X_COMP_BOM_DATA_RECORD_ISEQUAL_FCN                    *  pfnIsEqualDDD;
      X_COMP_BOM_DATA_RECORD_ISEQUAL_FCN                    *  pfnIsEqualDII;
      X_COMP_BOM_DATA_RECORD_ISEQUAL_FCN                    *  pfnIsEqualDDI;
      X_COMP_BOM_DISPATCH_RECORD_COPY_FCN                   *  pfnAssemble;
      X_COMP_BOM_DISPATCH_RECORD_COPY_FCN                   *  pfnDisassemble;
   }
      X_BOM_RECORD,
      *PX_BOM_RECORD,
      **PPX_BOM_RECORD;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_RECORD_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulEntityPID;
      long                                                     lChildIndex;
      long                                                     lChildrenCount;
      X_COMP_DISPATCH_ID                                       idDispatchRecord;
      X_COMP_DISPATCH_ID                                       idDispatchOperation;
      unsigned long                                            ulFieldCount;
      X_BOM_HEADER                                          ** ppFieldTable;
      unsigned long                                            ulVectorCount;
      X_BOM_HEADER                                          ** ppVectorTable;
   }
      X_BOM_RECORD_FCC,
      *PX_BOM_RECORD_FCC,
      **PPX_BOM_RECORD_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_RECORD_FIELD                                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_RECORD_FIELD                                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_RECORD_FIELD
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFieldName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_RECORD_FIELD,
      *PX_BOM_RECORD_FIELD,
      **PPX_BOM_RECORD_FIELD;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_RECORD_FIELD_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFieldName;
      const unsigned char                                   *  pvchMemberName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_RECORD_FIELD_FCC,
      *PX_BOM_RECORD_FIELD_FCC,
      **PPX_BOM_RECORD_FIELD_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_RECORD_CHILD_STORE                                          */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_RECORD_CHILD_STORE                           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_RECORD_CHILD_STORE
   {
      X_BOM_KIND                                               ulKind;
      unsigned long                                            ulElementPID;
      const unsigned char                                   *  pvchChildRecordName;
   }
      X_BOM_RECORD_CHILD_STORE,
      *PX_BOM_RECORD_CHILD_STORE,
      **PPX_BOM_RECORD_CHILD_STORE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_RECORD_CHILD_STORE_FCC
   {
      X_BOM_KIND                                               ulKind;
      unsigned long                                            ulElementPID;
      const unsigned char                                   *  pvchChildRecordName;
   }
      X_BOM_RECORD_CHILD_STORE_FCC,
      *PX_BOM_RECORD_CHILD_STORE_FCC,
      **PPX_BOM_RECORD_CHILD_STORE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVICE_ROUTINE                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_SERVICE_PROXY_LOADER                         */
/*       X_BOM_KIND_DEF_SERVICE_PROXY_SEARCH                         */
/*                                                                   */
/*       X_BOM_KIND_DEF_SERVICE_RESTORE                              */
/*       X_BOM_KIND_DEF_SERVICE_READ                                 */
/*       X_BOM_KIND_DEF_SERVICE_INSERT                               */
/*       X_BOM_KIND_DEF_SERVICE_UPDATE                               */
/*       X_BOM_KIND_DEF_SERVICE_DELETE                               */
/*       X_BOM_KIND_DEF_SERVICE_DELETE_ALL                           */
/*       X_BOM_KIND_DEF_SERVICE_DELETE_CURRENT                       */
/*       X_BOM_KIND_DEF_SERVICE_CROSS_UPDATE_CHECK_GROUP             */
/*                                                                   */
/*       X_BOM_KIND_DEF_SERVICE_VERIFY                               */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_SERVICE_ROUTINE
   {
      X_BOM_KIND                                               ulKind;
      FN_COMP_SERVICES_POINT                                *  pfnServicesRunPoint;
   }
      X_BOM_SERVICE_ROUTINE,
      *PX_BOM_SERVICE_ROUTINE,
      **PPX_BOM_SERVICE_ROUTINE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVICE_ROUTINE_FCC
   {
      X_BOM_KIND                                               ulKind;
      unsigned long                                            ulItemCount;
      X_BOM_HEADER                                          ** ppItemTable;
   }
      X_BOM_SERVICE_ROUTINE_FCC,
      *PX_BOM_SERVICE_ROUTINE_FCC,
      **PPX_BOM_SERVICE_ROUTINE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_DISPATCH_OPERATION_DOCUMENT                                 */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_DISPATCH_OPERATION_VERIFY_DOCUMENT           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_DISPATCH_OPERATION_DOCUMENT_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulPartId;
      unsigned long                                            ulStepCount;
      X_BOM_HEADER                                          ** ppStepTable;
   }
      X_BOM_DISPATCH_OPERATION_DOCUMENT_FCC,
      *PX_BOM_DISPATCH_OPERATION_DOCUMENT_FCC,
      **PPX_BOM_DISPATCH_OPERATION_DOCUMENT_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVER_SERVICE_ELEMENT_BLOCK                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_SERVICE_ELEMENT_BLOCK                        */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVER_SERVICE_ELEMENT_BLOCK_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulPartId;
      unsigned long                                            ulStepCount;
      X_BOM_HEADER                                          ** ppStepTable;
   }
      X_BOM_SERVER_SERVICE_ELEMENT_BLOCK_FCC,
      *PX_BOM_SERVER_SERVICE_ELEMENT_BLOCK_FCC,
      **PPX_BOM_SERVER_SERVICE_ELEMENT_BLOCK_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVICE_UNARY_BLOCK                                         */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_SERVICE_VERIFY_BLOCK                         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVICE_UNARY_BLOCK_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulPartId;
      unsigned long                                            ulStepCount;
      X_BOM_HEADER                                          ** ppStepTable;
   }
      X_BOM_SERVICE_UNARY_BLOCK_FCC,
      *PX_BOM_SERVICE_UNARY_BLOCK_FCC,
      **PPX_BOM_SERVICE_UNARY_BLOCK_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVICE_BINARY_BLOCK                                        */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_SERVER_SERVICE_DOCUMENT_BLOCK                */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVICE_BINARY_BLOCK_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      unsigned long                                            ulPartId;
      unsigned long                                            ulSubjectCount;
      X_BOM_HEADER                                          ** ppSubjectTable;
      unsigned long                                            ulObjectCount;
      X_BOM_HEADER                                          ** ppObjectTable;
   }
      X_BOM_SERVICE_BINARY_BLOCK_FCC,
      *PX_BOM_SERVICE_BINARY_BLOCK_FCC,
      **PPX_BOM_SERVICE_BINARY_BLOCK_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVICE_RECORD_FIELD_REF                                    */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_SERVICE_CROSS_UPDATE_CHECK_CONDITION         */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVICE_RECORD_FIELD_REF_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchQualifyingIdentifier;
      const unsigned char                                   *  pvchIdentifier;
      unsigned long                                            ulVectorExchangeIdentifer;
   }
      X_BOM_SERVICE_RECORD_FIELD_REF_FCC,
      *PX_BOM_SERVICE_RECORD_FIELD_REF_FCC,
      **PPX_BOM_SERVICE_RECORD_FIELD_REF_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVICE_VERIFY_RULE                                         */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_DISPATCH_OPERATION_VERIFY_STEP               */
/*       X_BOM_KIND_DEF_DISPATCH_CODE_POINT_RESTORE                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVICE_VERIFY_RULE_FCC
   {
      X_BOM_KIND                                               ulKind;
      unsigned char                                            chLL2EscapedToken[ ODEF_LL2_ET_SIZE + 1 ];
      const unsigned char                                   *  pvchSubroutineName;
   }
      X_BOM_SERVICE_VERIFY_RULE_FCC,
      *PX_BOM_SERVICE_VERIFY_RULE_FCC,
      **PPX_BOM_SERVICE_VERIFY_RULE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_SERVICE_CODE_POINT                                          */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_SERVICE_CODE_POINT                           */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_SERVICE_CODE_POINT_FCC
   {
      X_BOM_KIND                                               ulKind;
      unsigned char                                            chLL2EscapedToken[ ODEF_LL2_ET_SIZE + 1 ];
      const unsigned char                                   *  pvchSubroutineName;
   }
      X_BOM_SERVICE_CODE_POINT_FCC,
      *PX_BOM_SERVICE_CODE_POINT_FCC,
      **PPX_BOM_SERVICE_CODE_POINT_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_DISPATCH_ITEM                                               */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_HOME                           */
/*                                                                   */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_ORIGIN                         */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_ORIGIN_STORE                   */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_ORIGIN_DESCENDANT              */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_ORIGIN_DESCENDANT_STORE        */
/*                                                                   */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_CHILD                          */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_CHILD_STORE                    */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_CHILD_DESCENDANT               */
/*       X_BOM_KIND_DISPATCH_DOCUMENT_CHILD_DESCENDANT_STORE         */
/*                                                                   */
/*       X_BOM_KIND_DISPATCH_PROXY_ORIGIN                            */
/*       X_BOM_KIND_DISPATCH_PROXY_ORIGIN_STORE                      */
/*       X_BOM_KIND_DISPATCH_PROXY_ORIGIN_DESCENDANT                 */
/*       X_BOM_KIND_DISPATCH_PROXY_ORIGIN_DESCENDANT_STORE           */
/*                                                                   */
/*       X_BOM_KIND_DISPATCH_PROXY_CHILD                             */
/*       X_BOM_KIND_DISPATCH_PROXY_CHILD_STORE                       */
/*       X_BOM_KIND_DISPATCH_PROXY_CHILD_DESCENDANT                  */
/*       X_BOM_KIND_DISPATCH_PROXY_CHILD_DESCENDANT_STORE            */
/*                                                                   */
/* ----------------------------------------------------------------- */

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_DISPATCH_ITEM
   {
      X_BOM_KIND                                               ulKind;
   }
      X_BOM_DISPATCH_ITEM,
      *PX_BOM_DISPATCH_ITEM,
      **PPX_BOM_DISPATCH_ITEM;

#endif

#endif // X_OPERATING_TARGET_CSHARP

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_DISPATCH_ITEM_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFieldName;
   }
      X_BOM_DISPATCH_ITEM_FCC,
      *PX_BOM_DISPATCH_ITEM_FCC,
      **PPX_BOM_DISPATCH_ITEM_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_FIELD_TYPE                                            */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_FIELD_TYPE                             */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_FIELD_TYPE
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
      unsigned long                                            ulFeatureCount;
   }
      X_BOM_MODEL_FIELD_TYPE,
      *PX_BOM_MODEL_FIELD_TYPE,
      **PPX_BOM_MODEL_FIELD_TYPE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_FIELD_TYPE_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_FIELD_TYPE_FCC,
      *PX_BOM_MODEL_FIELD_TYPE_FCC,
      **PPX_BOM_MODEL_FIELD_TYPE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_DATA_TYPE                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE                              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulDataTypeActions;
      unsigned long                                            ulActionCount;
      unsigned long                                            ulMemberCount;
      unsigned long                                            ulRecordCount;
      unsigned long                                            ulHandlerCount;
      unsigned long                                            ulFeatureCount;
   }
      X_BOM_MODEL_DATA_TYPE,
      *PX_BOM_MODEL_DATA_TYPE,
      **PPX_BOM_MODEL_DATA_TYPE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulDataTypeActions;
      unsigned long                                            ulIdentifierCount;
      X_BOM_HEADER                                          ** ppIdentifierTable;
      unsigned long                                            ulActionCount;
      X_BOM_HEADER                                          ** ppActionTable;
      unsigned long                                            ulMemberCount;
      X_BOM_HEADER                                          ** ppMemberTable;
      unsigned long                                            ulRecordCount;
      X_BOM_HEADER                                          ** ppRecordTable;
      unsigned long                                            ulHandlerCount;
      X_BOM_HEADER                                          ** ppHandlerTable;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_DATA_TYPE_FCC,
      *PX_BOM_MODEL_DATA_TYPE_FCC,
      **PPX_BOM_MODEL_DATA_TYPE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_DATA_TYPE_ACTION                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_ACTION                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_HOME_OPERATION             10L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_FIND                       11L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_FIND_ALL                   12L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_LOAD_ALL                   13L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_CREATE                     14L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_RETRIEVE                   15L

#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_INSTANCE_OPERATION         50L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_DESTROY                    51L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_PREPARE_FOR_SAVE           52L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_SAVE                       53L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_UPDATE                     54L
#define X_BOM_MODEL_DATA_TYPE_ACTION_TYPE_VERIFY                     55L

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_ACTION
   {
      X_BOM_KIND                                               ulKind;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lActionType;
      unsigned long                                            ulPartCount;
      unsigned long                                            ulFeatureCount;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      const unsigned char                                   *  pvchOperationName;
      X_BOM_HEADER                                          *  pImplementationEntityRef;
   }
      X_BOM_MODEL_DATA_TYPE_ACTION,
      *PX_BOM_MODEL_DATA_TYPE_ACTION,
      **PPX_BOM_MODEL_DATA_TYPE_ACTION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_ACTION_FCC
   {
      X_BOM_KIND                                               ulKind;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lActionType;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      const unsigned char                                   *  pvchOperationName;
      X_BOM_HEADER                                          *  pImplementationEntityRef;
      unsigned long                                            ulPartCount;
      X_BOM_HEADER                                          ** ppPartTable;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_DATA_TYPE_ACTION_FCC,
      *PX_BOM_MODEL_DATA_TYPE_ACTION_FCC,
      **PPX_BOM_MODEL_DATA_TYPE_ACTION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_DATA_TYPE_ACTION_PART                                 */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_ACTION_PART                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#define X_BOM_MODEL_DATA_TYPE_ACTION_PART_DERIVATION_SINGLE          1L
#define X_BOM_MODEL_DATA_TYPE_ACTION_PART_DERIVATION_ARRAY           2L
#define X_BOM_MODEL_DATA_TYPE_ACTION_PART_DERIVATION_LIST            3L
#define X_BOM_MODEL_DATA_TYPE_ACTION_PART_DERIVATION_SET             4L
#define X_BOM_MODEL_DATA_TYPE_ACTION_PART_DERIVATION_RESULT_SET      5L

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_ACTION_PART
   {
      X_BOM_KIND                                               ulKind;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lDerivation;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_BOM_HEADER                                          *  pPartType;
      unsigned long                                            ulOccursMax;
      unsigned long                                            ulOccursMin;
      unsigned long                                            ulFeatureCount;
   }
      X_BOM_MODEL_DATA_TYPE_ACTION_PART,
      *PX_BOM_MODEL_DATA_TYPE_ACTION_PART,
      **PPX_BOM_MODEL_DATA_TYPE_ACTION_PART;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_ACTION_PART_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_BOM_HEADER                                          *  pPartType;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lDerivation;
      unsigned long                                            ulOccursMax;
      unsigned long                                            ulOccursMin;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_DATA_TYPE_ACTION_PART_FCC,
      *PX_BOM_MODEL_DATA_TYPE_ACTION_PART_FCC,
      **PPX_BOM_MODEL_DATA_TYPE_ACTION_PART_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_DATA_TYPE_MEMBER_SINGLE                               */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_SINGLE                */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_ARRAY                 */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_SINGLE                */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_ARRAY                 */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_LIST                  */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_SET                   */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_RESULT_SET            */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_PARENT_CHILD          */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_WHOLE_PART            */
/*       X_BOM_KIND_DEF_MODEL_DATA_TYPE_MEMBER_JOIN                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_SINGLE               1L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_ARRAY                2L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_LIST                 3L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_SET                  4L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_RESULT_SET           5L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_PARENT_CHILD         6L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_WHOLE_PART           7L
#define X_BOM_MODEL_DATA_TYPE_MEMBER_DERIVATION_JOIN                 8L

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_MEMBER
   {
      X_BOM_KIND                                               ulKind;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lDerivation;
      long                                                     lIndentifierPos;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_BOM_HEADER                                          *  pMemberType;
      unsigned long                                            ulOccursMax;
      unsigned long                                            ulOccursMin;
      long                                                     lRecordIndex;
      unsigned long                                            ulItemCount;
      unsigned long                                            ulFeatureCount;
   }
      X_BOM_MODEL_DATA_TYPE_MEMBER,
      *PX_BOM_MODEL_DATA_TYPE_MEMBER,
      **PPX_BOM_MODEL_DATA_TYPE_MEMBER;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_DATA_TYPE_MEMBER_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_BOM_HEADER                                          *  pMemberType;
      X_COMP_PARTID                                            ulPartId;
      long                                                     lDerivation;
      long                                                     lIndentifierPos;
      unsigned long                                            ulFlags;
      unsigned long                                            ulOccursMax;
      unsigned long                                            ulOccursMin;
      long                                                     lRecordIndex;
      unsigned long                                            ulItemCount;
      X_BOM_HEADER                                          ** ppItemTable;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_DATA_TYPE_MEMBER_FCC,
      *PX_BOM_MODEL_DATA_TYPE_MEMBER_FCC,
      **PPX_BOM_MODEL_DATA_TYPE_MEMBER_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_REQUEST_OPERATION                                     */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_REQUEST_OPERATION                      */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_REQUEST_OPERATION
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulPartCount;
      unsigned long                                            ulFeatureCount;
   }
      X_BOM_MODEL_REQUEST_OPERATION,
      *PX_BOM_MODEL_REQUEST_OPERATION,
      **PPX_BOM_MODEL_REQUEST_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_REQUEST_OPERATION_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulPartCount;
      X_BOM_HEADER                                          ** ppPartTable;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_REQUEST_OPERATION_FCC,
      *PX_BOM_MODEL_REQUEST_OPERATION_FCC,
      **PPX_BOM_MODEL_REQUEST_OPERATION_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_REQUEST_OPERATION_PART                                */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_REQUEST_OPERATION_PART                 */
/*                                                                   */
/* ----------------------------------------------------------------- */

#define X_BOM_MODEL_REQUEST_OPERATION_PART_DERIVATION_SINGLE         1L
#define X_BOM_MODEL_REQUEST_OPERATION_PART_DERIVATION_ARRAY          2L
#define X_BOM_MODEL_REQUEST_OPERATION_PART_DERIVATION_LIST           3L
#define X_BOM_MODEL_REQUEST_OPERATION_PART_DERIVATION_SET            4L
#define X_BOM_MODEL_REQUEST_OPERATION_PART_DERIVATION_RESULT_SET     5L

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_REQUEST_OPERATION_PART
   {
      X_BOM_KIND                                               ulKind;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lDerivation;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_BOM_HEADER                                          *  pPartType;
      unsigned long                                            ulOccursMax;
      unsigned long                                            ulOccursMin;
      unsigned long                                            ulFeatureCount;
   }
      X_BOM_MODEL_REQUEST_OPERATION_PART,
      *PX_BOM_MODEL_REQUEST_OPERATION_PART,
      **PPX_BOM_MODEL_REQUEST_OPERATION_PART;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_REQUEST_OPERATION_PART_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_BOM_HEADER                                          *  pPartType;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulFlags;
      long                                                     lDerivation;
      unsigned long                                            ulOccursMax;
      unsigned long                                            ulOccursMin;
      unsigned long                                            ulFeatureCount;
      X_BOM_HEADER                                          ** ppFeatureTable;
   }
      X_BOM_MODEL_REQUEST_OPERATION_PART_FCC,
      *PX_BOM_MODEL_REQUEST_OPERATION_PART_FCC,
      **PPX_BOM_MODEL_REQUEST_OPERATION_PART_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_ENTITY_REF_FIELD                                      */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_ENTITY_REF_FIELD                       */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_FIELD
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFieldName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_MODEL_ENTITY_REF_FIELD,
      *PX_BOM_MODEL_ENTITY_REF_FIELD,
      **PPX_BOM_MODEL_ENTITY_REF_FIELD;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_FIELD_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFieldName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_MODEL_ENTITY_REF_FIELD_FCC,
      *PX_BOM_MODEL_ENTITY_REF_FIELD_FCC,
      **PPX_BOM_MODEL_ENTITY_REF_FIELD_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_ENTITY_REF_FILE_FIELD                                 */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_ENTITY_REF_FILE_FIELD                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_FILE_FIELD
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFileName;
      const unsigned char                                   *  pvchLibrary;
      const unsigned char                                   *  pvchFieldName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_MODEL_ENTITY_REF_FILE_FIELD,
      *PX_BOM_MODEL_ENTITY_REF_FILE_FIELD,
      **PPX_BOM_MODEL_ENTITY_REF_FILE_FIELD;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_FILE_FIELD_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchFileName;
      const unsigned char                                   *  pvchLibrary;
      const unsigned char                                   *  pvchFieldName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_MODEL_ENTITY_REF_FILE_FIELD_FCC,
      *PX_BOM_MODEL_ENTITY_REF_FILE_FIELD_FCC,
      **PPX_BOM_MODEL_ENTITY_REF_FILE_FIELD_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_ENTITY_REF_DATA_TYPE                                  */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_ENTITY_REF_DATA_TYPE                   */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_DATA_TYPE
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchDataTypeName;
      X_COMP_PARTID                                            ulPartId;
   }
      X_BOM_MODEL_ENTITY_REF_DATA_TYPE,
      *PX_BOM_MODEL_ENTITY_REF_DATA_TYPE,
      **PPX_BOM_MODEL_ENTITY_REF_DATA_TYPE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_DATA_TYPE_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchDataTypeName;
      X_COMP_PARTID                                            ulPartId;
   }
      X_BOM_MODEL_ENTITY_REF_DATA_TYPE_FCC,
      *PX_BOM_MODEL_ENTITY_REF_DATA_TYPE_FCC,
      **PPX_BOM_MODEL_ENTITY_REF_DATA_TYPE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_MODEL_ENTITY_REF_REUSABLE_PART                              */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_MODEL_ENTITY_REF_REUSABLE_PART               */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_REUSABLE_PART
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchComponentName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_MODEL_ENTITY_REF_REUSABLE_PART,
      *PX_BOM_MODEL_ENTITY_REF_REUSABLE_PART,
      **PPX_BOM_MODEL_ENTITY_REF_REUSABLE_PART;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_MODEL_ENTITY_REF_REUSABLE_PART_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchComponentName;
      X_COMP_DISPATCH_ID                                       ulPatternDispatchId;
   }
      X_BOM_MODEL_ENTITY_REF_REUSABLE_PART_FCC,
      *PX_BOM_MODEL_ENTITY_REF_REUSABLE_PART_FCC,
      **PPX_BOM_MODEL_ENTITY_REF_REUSABLE_PART_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_UDC_TYPE                                                    */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_UDC_TYPE                                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_UDC_TYPE
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulMemberCount;
      unsigned long                                            ulRecordCount;
   }
      X_BOM_UDC_TYPE,
      *PX_BOM_UDC_TYPE,
      **PPX_BOM_UDC_TYPE;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_UDC_TYPE_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
      unsigned long                                            ulMemberCount;
      X_BOM_HEADER                                          ** ppMemberTable;
      unsigned long                                            ulRecordCount;
      X_BOM_HEADER                                          ** ppRecordTable;
   }
      X_BOM_UDC_TYPE_FCC,
      *PX_BOM_UDC_TYPE_FCC,
      **PPX_BOM_UDC_TYPE_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_BOM_UDC_TYPE_MEMBER                                             */
/*                                                                   */
/*    Supports:                                                      */
/*       X_BOM_KIND_DEF_UDC_TYPE_MEMBER                              */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_BOM_UDC_TYPE_MEMBER
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
   }
      X_BOM_UDC_TYPE_MEMBER,
      *PX_BOM_UDC_TYPE_MEMBER,
      **PPX_BOM_UDC_TYPE_MEMBER;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_BOM_UDC_TYPE_MEMBER_FCC
   {
      X_BOM_KIND                                               ulKind;
      const unsigned char                                   *  pvchName;
      const unsigned char                                   *  pvchFieldName;
      const unsigned char                                   *  pvchDescription;
      X_COMP_PARTID                                            ulPartId;
   }
      X_BOM_UDC_TYPE_MEMBER_FCC,
      *PX_BOM_UDC_TYPE_MEMBER_FCC,
      **PPX_BOM_UDC_TYPE_MEMBER_FCC;

#endif

/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
/* BOM Dependent Dispatching Types                                    */
/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */

/* ----------------------------------------------------------------- */
/* X_COMP_BOM_DISPATCH_RECORD                                        */
/*                                                                   */
/*   Supports:                                                       */
/*       X_COMP_KIND_REF_BOM_RECORD                                  */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_BOM_DISPATCH_RECORD
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idRecordType;
      const X_BOM_DISPATCH_RECORD      *  pRecordDescription;
   }
      X_COMP_BOM_DISPATCH_RECORD,
      *PX_COMP_BOM_DISPATCH_RECORD,
      **PPX_COMP_BOM_DISPATCH_RECORD;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_BOM_DISPATCH_RECORD_FCC
   {
      X_COMP_KIND                         ulKind;
      X_COMP_DISPATCH_ID                  idRecordType;
   }
      X_COMP_BOM_DISPATCH_RECORD_FCC,
      *PX_COMP_BOM_DISPATCH_RECORD_FCC,
      **PPX_COMP_BOM_DISPATCH_RECORD_FCC;

#endif

/* ----------------------------------------------------------------- */
/* X_COMP_RECORD_OPERATION                                           */
/*                                                                   */
/*   Supports:                                                       */
/*      X_COMP_KIND_DEF_BOM_RECORD_OPERATION_GET                     */
/*      X_COMP_KIND_DEF_BOM_RECORD_OPERATION_SET                     */
/*                                                                   */
/* ----------------------------------------------------------------- */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   typedef struct _X_COMP_RECORD_OPERATION
   {
      X_COMP_KIND                                  ulKind;
      X_COMP_DISPATCH_ID                           idDispatchRecord;
      X_LONG                                       lFieldVectorEntries;
      X_DEFS_X_SHORT_TABLE                         pFieldVectorTable;
      X_COMP_BOM_DISPATCH_RECORD_COPY_FCN       *  pfnRecordCopy;
   }
      X_COMP_RECORD_OPERATION,
      *PX_COMP_RECORD_OPERATION,
      **PPX_COMP_RECORD_OPERATION;

#endif

#if defined(X_COMP_FCC_SUPPORT)

   typedef struct _X_COMP_RECORD_OPERATION_FCC
   {
      X_COMP_KIND                                  ulKind;
      X_COMP_DISPATCH_ID                           idDispatchRecord;
   }
      X_COMP_RECORD_OPERATION_FCC,
      *PX_COMP_RECORD_OPERATION_FCC,
      **PPX_COMP_RECORD_OPERATION_FCC;

#endif

/* ==================================================================*/
/*  X_COMP_LIIY_SERVICES_CALLBACK                                    */
/* ==================================================================*/

/*-------------------------------------------------------------------*/
/*  X_COMP_LIIY_SERVICES_CALLBACK: Service Request codes             */
/*-------------------------------------------------------------------*/
/* Name                 Description                                  */
/* ----                 -----------                                  */
/*                                                                   */
/* Initialize Dev Env   Start up LIIY Dev Env and activate ROM       */
/*                                                                   */
/* Terminate Dev Env    Shutdown LIIY Dev Env                        */
/*                                                                   */
/*-------------------------------------------------------------------*/

#define X_COMP_LIIY_SERVICES_INITIALIZE_DEV_ENV                      1L
#define X_COMP_LIIY_SERVICES_TERMINATE_DEV_ENV                       2L

/*-------------------------------------------------------------------*/
/*  X_COMP_LIIY_SERVICES_CALLBACK: Callback for LIIY services        */
/*-------------------------------------------------------------------*/
/* Name            Description                                       */
/* ----            -----------                                       */
/* Parm1           PX_COMP_LPC_ANCHOR_BLOCK                          */
/* Parm2           long - X_COMP_LIIY_SERVICES_Xxxxx request code    */
/* Parm3           pointer - array of agreed args for request code   */
/*-------------------------------------------------------------------*/

typedef X_COMP_RETURN_CODE
   (X_COMP_LIIY_SERVICES_CALLBACK)              (
      X_COMP_LPC_ANCHOR_BLOCK                   *  pAnchorBlock,
      long                                         lServicesRequest,
      void                                      *  apvAgreedArgs[] );

/* -------------------------------------------------------------- */
/* Business Object Model retrieve description                     */
/*                                                                */
/* LIIO_FCC_BOM_RetrieveDescription                               */
/*    LIIO service called by DC_P3109 to get BOM description      */
/* -------------------------------------------------------------- */

#if defined(X_COMP_FCC_SUPPORT)

   LIIO_FCC_INTERFACE
      LIIO_FCC_BOM_RetrieveDescription    (
         X_COMP_LPC_ANCHOR_BLOCK          *  pLPCAnchor,
         X_BOM_HEADER                     ** ppDescription );

#endif

/* ================================================================= */
/*  X_COMP_DISPATCH_INTERFACE : Table of dispatch function pointers  */
/* ================================================================= */

#if defined(X_COMP_RUN_TIME_SUPPORT)

   #if defined(X_OPERATING_SYSTEM_UNIX) || defined(X_OPERATING_SYSTEM_ISERIES)

      typedef X_COMP_RETURN_CODE X_Comp_Dispatch_Rdmlx_Command_Fcn( X_COMP_MODULE_FRAME*, X_COMP_DISPATCH_ID );
      typedef X_COMP_RETURN_CODE X_Comp_Dispatch_Rdmlx_Condition_Fcn( X_COMP_MODULE_FRAME*, X_COMP_DISPATCH_ID, X_COMP_RETURN_CODE* );

   #else

      typedef X_COMP_RETURN_CODE __cdecl X_Comp_Dispatch_Rdmlx_Command_Fcn( X_COMP_MODULE_FRAME*, X_COMP_DISPATCH_ID );
      typedef X_COMP_RETURN_CODE __cdecl X_Comp_Dispatch_Rdmlx_Condition_Fcn( X_COMP_MODULE_FRAME*, X_COMP_DISPATCH_ID, X_COMP_RETURN_CODE* );

   #endif

   typedef struct X_COMP_DISPATCH_INTERFACE
   {
      X_Comp_Dispatch_Rdmlx_Command_Fcn            *  pfnDispatchRdmlxCommand;      /* X_FUN_V17_OR_LATER */
      X_Comp_Dispatch_Rdmlx_Condition_Fcn          *  pfnDispatchRdmlxCondition;    /* X_FUN_V17_OR_LATER */
   }
      *PX_COMP_DISPATCH_INTERFACE,
      **PPX_COMP_DISPATCH_INTERFACE;

#endif

#endif /* X_COMP_FCC_SUPPORT || X_COMP_RUN_TIME_SUPPORT */

#ifdef __cplusplus
} /* extern "C" */
#endif

/* =============================== */
/* Put packing back to the default */
/* =============================== */
#include "x_endpck.h"
#ifdef _MSC_VER
#pragma warning (pop)
#endif

#endif /* LIIODEF_INCLUDE */
