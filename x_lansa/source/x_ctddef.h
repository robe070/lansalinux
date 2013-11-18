/* ================================================================= */
/* ========== LANSA FOR WINDOWS GLOBAL DEFINITIONS ================= */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_CTDDEF.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : LANSA Common Table Definitions              */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*  nnnnn  YY/MM/DD                                                  */
/*                                                                   */
/* ================================================================= */

#ifndef X_CTD_DEF_INCLUDED

#define X_CTD_DEF_INCLUDED

#include <stdio.h>

#include "x_glodef.h"

#define X_CTD_MAXIMUM_DATABASE_TYPES   50

#define  _MACRO_STR_SIZE(s) (sizeof((s)) - sizeof(""))

/*---------------------------------------------------------*/
/* The following two enumerations list DBMS Category Ids   */
/* and DBMS Type Ids.  Categories map to a particular      */
/* database layer DLL, e.g. ODBC or DB2. It can be         */
/* considered as the METHOD of access, wheras Type is the  */
/* database ACTUALLY accessed.                             */
/* Types are the actual native DBMS that is being used to  */
/* store the data, e.g. SQL Anywhere or DB2.               */
/* There is not a one-to-one mapping because ODBC is       */
/* (sort of!) supported by many databases.                 */
/* It is possible, though not tested, for the DBMS Type DB2*/
/* to be ACCESSED through either Category DB2 (i.e. native)*/
/* or through Category ODBC.                               */
/*---------------------------------------------------------*/
/* This enumeration MUST be in the same order as the array */
/* apszDBMSCategories in x_ctd1.c                          */
/*<A HREF="..\source\x_ctd1.c#enum apszDBMSCategories">*/
/* Ensure you keep them in sync.                           */
/*---------------------------------------------------------*/
enum DBMSCategoryIds      /* <A NAME="enum DBMSCategoryIds"> */ /* @2506C1 */
{
   X_CTD_DBMS_CAT_DB2_ID = 0,
   X_CTD_DBMS_CAT_ODBC_ID,
   X_CTD_DBMS_CAT_ORACLE_ID,
   X_CTD_DBMS_CAT_MAX_ID      /* This must be the last entry */
};

#define    X_CTD_DBMS_CAT_DB2          ((const char *)"DB2")
#define    X_CTD_DBMS_CAT_ODBC         ((const char *)"ODBC")
#define    X_CTD_DBMS_CAT_ORACLE       ((const char *)"ORACLE")

/*---------------------------------------------------------*/
/* This enumeration MUST be in the same order as the array */
/* apszDBMSProducts in x_ctd1.c                            */
/*<A HREF="..\source\x_ctd1.c#enum apszDBMSProducts"> */
/* Ensure you keep them in sync.                           */
/*---------------------------------------------------------*/
enum DBMSProductIds        /* <A NAME="enum DBMSProductIds"> */ /* @2506C1 */
{
   X_CTD_DBMS_PRODUCT_DB2400_ID = 0, /* Used to be DB2 for OS/2 */
   X_CTD_DBMS_PRODUCT_MSACCESS_ID,
   X_CTD_DBMS_PRODUCT_ORACLE_ID,
   X_CTD_DBMS_PRODUCT_SQLSERVER_ID,
   X_CTD_DBMS_PRODUCT_SQLANYWHERE_ID,
   X_CTD_DBMS_PRODUCT_MYSQL_ID,
   X_CTD_DBMS_PRODUCT_USERDEFINED_ID,
   X_CTD_DBMS_PRODUCT_DB2UWO_ID,  /* Currently not used */
   X_CTD_DBMS_PRODUCT_SQLAZURE_ID,
   X_CTD_DBMS_PRODUCT_MAX_ID      /* This must be the last entry */
};

enum X_CTD_OPERATION
{
   X_CTD_OP_DELETE_TABLE = 1,
   X_CTD_OP_CREATE_TABLE,
   X_CTD_OP_DELETE_INDEX,
   X_CTD_OP_CREATE_INDEX,
   X_CTD_OP_DELETE_VIEW,
   X_CTD_OP_CREATE_VIEW,
   X_CTD_OP_CREATE_CLUSTER_INDEX
};

#define    X_CTD_DBMS_PRODUCT_DB2400      ((const char *)"DB2400")
#define    X_CTD_DBMS_PRODUCT_MSACCESS    ((const char *)"MSACCESS")
#define    X_CTD_DBMS_PRODUCT_ORACLE      ((const char *)"ORACLE")
#define    X_CTD_DBMS_PRODUCT_SQLSERVER   ((const char *)"SQLSERVER")
#define    X_CTD_DBMS_PRODUCT_SQLANYWHERE ((const char *)"SQLANYWHERE")
#define    X_CTD_DBMS_PRODUCT_MYSQL       ((const char *)"MYSQL")
#define    X_CTD_DBMS_PRODUCT_USERDEFINED ((const char *)"USERDEFINED")
#define    X_CTD_DBMS_PRODUCT_DB2UWO      ((const char *)"DB2UWO")
#define    X_CTD_DBMS_PRODUCT_SQLAZURE    ((const char *)"SQLAZURE")

/* ----------------------------------------------------------- */
/* DBMS specific setting codes                                 */
/* ----------------------------------------------------------- */
#define X_CTD_DBMS_PHYSICAL_FILE    "PF"
#define X_CTD_DBMS_LOGICAL_FILE     "LF"
#define X_CTD_DBMS_FIELD            "DF"
#define X_CTD_DBMS_INDEX_LOGICAL    "IF"

#define X_CTD_DBMS_RECTYPE_APPEND   "A"
#define X_CTD_DBMS_RECTYPE_ALLOCATE "B"

/* ----------------------------------------------------------- */
/* These are the x_dbmenv.dat DATABASE TYPEs. Currently they   */
/* are the same as DBMS Names.  That is just historical. These */
/* reflect a unique DB Access combination of DBMS Category &   */
/* DBMS Product and are a single entry in x_dbmenv.dat.        */
/* Each type has an appropriate Category and Product.  E.g.    */
/* Type SQLSERVER has Category ODBC and Product SQLSERVER.     */
/* If we were to have native support for SQL Server then we    */
/* would set up a DB Type of, say, SQLSERVERNATIVE which would */
/* have DB Category of SQLSERVER and DB Product of SQLSERVER.  */
/* When coding, consider if the code is dependent on the       */
/* particular access method (ODBC v. Native) or the actual DB  */
/* Product, and use DB Category and DB Product to differentiate*/
/* DB TYPE IS NOT TO BE USED FOR DETERMINING BEHAVIOUR.        */
/* It is for accessing a set of values, and nothing else.      */
/* Another way of putting it is that the DB Type can be        */
/* anything! e.g. "$#@^", It is the Category and Product that  */
/* are the driving forces that determine the behaviour of      */
/* the DB Type.  The DB Type is specified as a configuration   */
/* item by LANSA/PC and LANSA/X.  This is used to look up the  */
/* appropriate DB Type entry in x_dbmenv.dat to obtain all the */
/* DBMS capabilities.  It is these capabilities which are      */
/* precise and determine behaviour, 2 of which are the Category*/
/* and Product.                                                */
/* ----------------------------------------------------------- */
#define    X_CTD_DBMS_TYPE_DB2ISERIES  "DB2ISERIES" 
#define    X_CTD_DBMS_TYPE_MSACCESS    "MSACCESS"
#define    X_CTD_DBMS_TYPE_ORACLE      "ORACLE"
#define    X_CTD_DBMS_TYPE_ODBCORACLE  "ODBCORACLE"
#define    X_CTD_DBMS_TYPE_SQLSERVER   "MSSQLS"
#define    X_CTD_DBMS_TYPE_SQLANYWHERE "SQLANYWHERE"
#define    X_CTD_DBMS_TYPE_MYSQL       "MYSQL"
#define    X_CTD_DBMS_TYPE_DB2RPG      "DB2RPG" 
#define    X_CTD_DBMS_TYPE_SQLAZURE    "SQLAZURE" 

/* No type added for DB2UWO yet, as not used */

#if defined(X_OPERATING_SYSTEM_WIN)
   #if (defined( X_OPERATING_SYSTEM_WIN) || defined(WIN32) )
      #define X_CTD_DEFAULT_DATABASE_TYPE       X_CTD_DBMS_TYPE_SQLSERVER
      #define X_CTD_DEFAULT_DATABASE_PRODUCT_ID X_CTD_DBMS_PRODUCT_SQLSERVER_ID
   #else
      #define X_CTD_DEFAULT_DATABASE_TYPE       X_CTD_DBMS_TYPE_MSACCESS
      #define X_CTD_DEFAULT_DATABASE_PRODUCT_ID X_CTD_DBMS_PRODUCT_MSACCESS_ID
   #endif
#elif defined(X_OPERATING_SYSTEM_ISERIES)
   #define X_CTD_DEFAULT_DATABASE_TYPE       X_CTD_DBMS_TYPE_DB2ISERIES
   #define X_CTD_DEFAULT_DATABASE_PRODUCT_ID X_CTD_DBMS_PRODUCT_DB2400_ID
#else
   #define X_CTD_DEFAULT_DATABASE_TYPE       X_CTD_DBMS_TYPE_ODBCORACLE
   #define X_CTD_DEFAULT_DATABASE_PRODUCT_ID X_CTD_DBMS_PRODUCT_ORACLE_ID
#endif

#define X_CTD_ENVIRONMENT_FILE        "x_dbmenv.dat"

#define X_CTD_INFO_MESSAGE            'I'
#define X_CTD_WARNING_MESSAGE         'W'
#define X_CTD_FATAL_MESSAGE           'F'

#define X_CTD_MESSAGE_MAXIMUM_LENGTH  (256 * 4)

#define X_CTD_OBJECT_NAME_LENGTH      256
#define X_CTD_VALUE_LENGTH            32

#define X_CTD_CONNECT_PARMS_LENGTH    2000
#define X_CTD_SPARE_LENGTH            255

#define X_CTD_VERSION_LENGTH          32

#define X_CTD_DESCRIPTION_LENGTH      40

#define X_CTD_SQL_COMMAND_LENGTH      (65535 + (X_CTD_OBJECT_NAME_LENGTH * 100) + 1)
#define X_CTD_ID_LENGTH               ((X_CTD_OBJECT_NAME_LENGTH * 2) + 100 + 1)    // e.g. "<collection>"."<table>" with each id up to 256 long plus quotes and some extra
#define X_CTD_RUNSQL_COMMAND_LENGTH   20000

#define X_CTD_TOKEN_LENGTH            100

#define X_DEFINE_TABLE        "DEFINE_TABLE"
#define X_DEFINE_VIEW         "DEFINE_VIEW"
#define X_DEFINE_COLUMNS      "DEFINE_COLUMNS"
#define X_DEFINE_INDEX        "DEFINE_INDEX"
#define X_DEFINE_INDEX_KEY    "DEFINE_INDEX_KEYS"
#define X_DEFINE_PRIMARY_KEYS "DEFINE_PRIMARY_KEYS"
#define X_DEFINE_IG_IF_NATIVE "IGNORE_IF_NATIVE"

#define X_DEFINE_INTN_        "INTERNAL="
#define X_DEFINE_INTN_LEN     _MACRO_STR_SIZE(X_DEFINE_INTN_)

#define X_DEFINE_EXTN_        "TABLE="
#define X_DEFINE_EXTN_LEN     _MACRO_STR_SIZE(X_DEFINE_EXTN_)

#define X_DEFINE_ALTERNATE_    "ALTERNATE="
#define X_DEFINE_ALTERNATE_LEN _MACRO_STR_SIZE(X_DEFINE_ALTERNATE_)

#define X_DEFINE_COLL_        "COLLECTION="
#define X_DEFINE_COLL_LEN     _MACRO_STR_SIZE(X_DEFINE_COLL_)

#define X_DEFINE_DESC_        "DESC="
#define X_DEFINE_DESC_LEN     _MACRO_STR_SIZE(X_DEFINE_DESC_)

#define X_DEFINE_DTALIB_      "DTALIB="
#define X_DEFINE_DTALIB_LEN   _MACRO_STR_SIZE(X_DEFINE_DTALIB_)

#define X_DEFINE_ALTER_       "ALTER"
#define X_DEFINE_ALTER_LEN    _MACRO_STR_SIZE(X_DEFINE_ALTER_)

#define X_DEFINE_DSN_         "DSN="
#define X_DEFINE_DSN_LEN      _MACRO_STR_SIZE(X_DEFINE_DSN_)

#define X_DEFINE_QUALIFIER_    "QUALIFIER="
#define X_DEFINE_QUALIFIER_LEN _MACRO_STR_SIZE(X_DEFINE_QUALIFIER_)

#define X_DEFINE_DBTYPE_      "DBTYPE="
#define X_DEFINE_DBTYPE_LEN   _MACRO_STR_SIZE(X_DEFINE_DBTYPE_)

#define X_DEFINE_CONNECTION_    "CONNECTION="
#define X_DEFINE_CONNECTION_LEN _MACRO_STR_SIZE(X_DEFINE_CONNECTION_)

#define X_DEFINE_SPARE_       "SPARE="
#define X_DEFINE_SPARE_LEN    _MACRO_STR_SIZE(X_DEFINE_SPARE_)

#define X_DEFINE_ENCRYPTED_    "ENCRYPTED="
#define X_DEFINE_ENCRYPTED_LEN _MACRO_STR_SIZE(X_DEFINE_ENCRYPTED_)

#define X_DEFINE_NAMEFLAG_      "NAMEFLAG="
#define X_DEFINE_NAMEFLAG_LEN   _MACRO_STR_SIZE(X_DEFINE_NAMEFLAG_)

#define X_DEFINE_OVERRIDE_COLLECTION_     "OVERRIDE_COLLECTION="
#define X_DEFINE_OVERRIDE_COLLECTION_LEN  _MACRO_STR_SIZE(X_DEFINE_OVERRIDE_COLLECTION_)

#define X_DEFINE_OVERRIDE_DTALIB_         "OVERRIDE_DTALIB="
#define X_DEFINE_OVERRIDE_DTALIB_LEN      _MACRO_STR_SIZE(X_DEFINE_OVERRIDE_DTALIB_)

#define X_DEFINE_NAME_OLDDEFAULT ' '
#define X_DEFINE_NAME_CONVERTED  '0'
#define X_DEFINE_NAME_LANSADEF   '1'

#define X_DEFINE_ATSIGN_      "ATSIGN="
#define X_DEFINE_ATSIGN_LEN   _MACRO_STR_SIZE(X_DEFINE_ATSIGN_)

#define X_DEFINE_NAME_        "NAME="
#define X_DEFINE_NAME_LEN     _MACRO_STR_SIZE(X_DEFINE_NAME_)

#define X_DEFINE_TYPE_        "TYPE="
#define X_DEFINE_TYPE_LEN     _MACRO_STR_SIZE(X_DEFINE_TYPE_)

#define X_DEFINE_CMTCTL_      "CMTCTL="
#define X_DEFINE_CMTCTL_LEN   _MACRO_STR_SIZE(X_DEFINE_CMTCTL_)

#define X_DEFINE_TYPE_ALPHA         "ALPHA"
#define X_DEFINE_TYPE_ALPHASBIN     "ALPHASBIN"
#define X_DEFINE_TYPE_CHAR          "CHAR"
#define X_DEFINE_TYPE_FIXCHAR       "FIXCHAR"
#define X_DEFINE_TYPE_VARCHAR       "VARCHAR"
#define X_DEFINE_TYPE_LONGVARCHAR   "LONGVARCHAR"
#define X_DEFINE_TYPE_DECIMAL       "DECIMAL"
#define X_DEFINE_TYPE_TINYINT       "TINYINT"
#define X_DEFINE_TYPE_SMALLINT      "SMALLINT"
#define X_DEFINE_TYPE_INTEGER       "INTEGER"
#define X_DEFINE_TYPE_REAL          "REAL"
#define X_DEFINE_TYPE_DOUBLE        "DOUBLE"
#define X_DEFINE_TYPE_BINARY        "BINARY"
#define X_DEFINE_TYPE_VARBINARY     "VARBINARY"
#define X_DEFINE_TYPE_LONGVARBINARY "LONGVARBINARY"
#define X_DEFINE_TYPE_UNKNOWN       "UNKNOWN"
#define X_DEFINE_TYPE_NUMERIC       "NUMERIC"
#define X_DEFINE_TYPE_BIGINT        "BIGINT"
#define X_DEFINE_TYPE_DATE          "DATE"
#define X_DEFINE_TYPE_TIME          "TIME"
#define X_DEFINE_TYPE_DATETIME      "DATETIME"
#define X_DEFINE_TYPE_UCHAR         "UCHAR"
#define X_DEFINE_TYPE_UVARCHAR      "UVARCHAR"
#define X_DEFINE_TYPE_UCLOB         "UCLOB"

#define X_DEFINE_LENG_        "LEN="
#define X_DEFINE_LENG_LEN      _MACRO_STR_SIZE(X_DEFINE_LENG_)

#define X_DEFINE_DECP_        "DEC="
#define X_DEFINE_DECP_LEN      _MACRO_STR_SIZE(X_DEFINE_DECP_)

#define X_DEFINE_COLN_        "COLUMN="
#define X_DEFINE_COLN_LEN     _MACRO_STR_SIZE(X_DEFINE_COLN_)

#define X_DEFINE_UNIQ_        "UNIQUE"
#define X_DEFINE_UNIQ_LEN      _MACRO_STR_SIZE(X_DEFINE_UNIQ_)

#define X_DEFINE_DSCD_        "DESCENDING"
#define X_DEFINE_DSCD_LEN      _MACRO_STR_SIZE(X_DEFINE_DSCD_)

#define X_DEFINE_AUTO_        "AUTO"
#define X_DEFINE_AUTO_LEN     _MACRO_STR_SIZE(X_DEFINE_AUTO_)

#define X_DEFINE_CRTC_        "COMMAND="
#define X_DEFINE_CRTC_LEN      _MACRO_STR_SIZE(X_DEFINE_CRTC_)

#define X_DEFINE_CRTC_A_      "COMMAND+="
#define X_DEFINE_CRTC_A_LEN    strlen(X_DEFINE_CRTC_A_)

#define X_DEFINE_INTN_CMD_    "INTCMD="
#define X_DEFINE_INTN_CMD_LEN _MACRO_STR_SIZE( X_DEFINE_INTN_CMD_ )

#define X_DEFINE_INTN_CMD_A_   "INTCMD+="
#define X_DEFINE_INTN_CMD_A_LEN  strlen( X_DEFINE_INTN_CMD_A_ )

#define X_DEFINE_NOTN_        "NOT_NULL"
#define X_DEFINE_NOTN_LEN     _MACRO_STR_SIZE(X_DEFINE_NOTN_)

#define X_DEFINE_DTYP_        "DATABASE_TYPE="
#define X_DEFINE_DTYP_LEN     _MACRO_STR_SIZE(X_DEFINE_DTYP_)

#define X_DEFINE_C2B_         "CHAR_TO_BINARY"
#define X_DEFINE_C2B_LEN      _MACRO_STR_SIZE( X_DEFINE_C2B_ )

#define X_DEFINE_KSHIFT_      "KSH="
#define X_DEFINE_KSHIFT_LEN   _MACRO_STR_SIZE( X_DEFINE_KSHIFT_ )

#define X_DEFINE_ALLOC_       "ALLOC="
#define X_DEFINE_ALLOC_LEN    _MACRO_STR_SIZE( X_DEFINE_ALLOC_ )

#define X_DEFINE_TBL_APPEND_    "CREATE_TABLE_APPEND_%s="
#define X_DEFINE_INDEX_APPEND_  "CREATE_INDEX_APPEND_%s="

#define X_QUERY_DATABASE_DESCRIPTION       "DATABASE_DESCRIPTION"
#define X_QUERY_DATABASE_CATEGORY          "DATABASE_CATEGORY"
#define X_QUERY_DATABASE_PRODUCT           "DATABASE_PRODUCT"
#define X_QUERY_DATABASE_DRIVER            "DATABASE_DRIVER"
#define X_QUERY_SUPPORTS_COLLECTIONS       "SUPPORTS_COLLECTIONS"
#define X_QUERY_EMULATE_COLLECTIONS        "EMULATE_COLLECTIONS"
#define X_QUERY_SUPPORTS_COLLECTIONS_IDX   "SUPPORTS_COLLECTIONS_IDX"
#define X_QUERY_SUPPORTS_DROP_COLLECTIONS_IDX   "SUPPORTS_DROP_COLLECTIONS_IDX"
#define X_QUERY_SUPPORTS_NOT_NULL          "SUPPORTS_NOT_NULL"
#define X_QUERY_SUPPORTS_PRIMARY_KEY       "SUPPORTS_PRIMARY_KEY"
#define X_QUERY_SUPPORTS_DESC_KEYS         "SUPPORTS_DESC_KEYS"
#define X_QUERY_USER_DATABASE_DLL          "USER_DATABASE_DLL"
#define X_QUERY_REPOSITORY_DATABASE_DLL    "REPOSITORY_DATABASE_DLL"
#define X_QUERY_DEVELOPMENT_DATABASE_DLL   "DEVELOPMENT_DATABASE_DLL"
#define X_QUERY_CONVERT_PRIM_KEY_TO_INDEX  "CONVERT_PRIMARY_KEY_TO_INDEX"
#define X_QUERY_CREATE_WITH_COLLECTIONS    "CREATE_WITH_COLLECTIONS"
#define X_QUERY_USE_INTERNAL_NAMES         "USE_INTERNAL_NAMES"
#define X_QUERY_IGNORE_CHAR_TO_BINARY      "IGNORE_CHAR_TO_BINARY"
#define X_QUERY_IGNORE_NATIVE_SUPPORT      "IGNORE_NATIVE_SUPPORT"
#define X_QUERY_SUPPORTS_LANSA_DEF_DB      "SUPPORTS_LANSA_DEFINED_DB"
#define X_QUERY_CREATE_ALPHA_AS_FIXED      "CREATE_ALPHA_AS_FIXED"
#define X_QUERY_SUPPORTS_ALLOC_BEHAVIOUR   "SUPPORTS_ALLOC_BEHAVIOUR"
#define X_QUERY_SUPPORTS_KSH_BEHAVIOUR     "SUPPORTS_KSH_BEHAVIOUR"
#define X_QUERY_KSH_EOJ_APPEND             "KSH_EOJ_APPEND"
#define X_QUERY_KSH_G_LEN_DIVISOR          "KSH_G_LEN_DIVISOR"
#define X_QUERY_LOCK_TYPE                  "LOCK_TYPE"
#define X_QUERY_LOCK_TIMEOUT               "LOCK_TIMEOUT"
#define X_QUERY_CMD_LOCK_TIMEOUT           "CMD_LOCK_TIMEOUT"

#define X_QUERY_DATETIME_ONLY              "NATIVE_DATETIME_ONLY"
#define X_QUERY_DATE_AS_DATETIME           "DATE_AS_DATETIME_LITERAL"
#define X_QUERY_TIME_AS_DATETIME           "TIME_AS_DATETIME_LITERAL"
#define X_QUERY_USE_SINGLE_CONNECTION      "USE_SINGLE_CONNECTION"

#define X_QUERY_SET_AUTO_ID_AS_PRIMARY_KEY   "SET_AUTO_ID_AS_PRIMARY_KEY"

#define X_QUERY_DBMS_RETCODE_OK                   "DBMS_RETCODE_OK"
#define X_QUERY_DBMS_RETCODE_DUPLICATE_ROW        "DBMS_RETCODE_DUPLICATE_ROW"
#define X_QUERY_DBMS_RETCODE_DUPLICATE_ROW_2      "DBMS_RETCODE_DUPLICATE_ROW_2"
#define X_QUERY_DBMS_RETCODE_DUPLICATE_ROW_3      "DBMS_RETCODE_DUPLICATE_ROW_3"
#define X_QUERY_DBMS_RETCODE_ROW_NOT_FOUND        "DBMS_RETCODE_ROW_NOT_FOUND"
#define X_QUERY_DBMS_RETCODE_TABLE_DOES_NOT_EXIST "DBMS_RETCODE_TABLE_DOES_NOT_EXIST"
#define X_QUERY_DBMS_RETCODE_TABLE_DOES_NOT_EXIST_2 "DBMS_RETCODE_TABLE_DOES_NOT_EXIST_2"
#define X_QUERY_DBMS_RETCODE_INDEX_DOES_NOT_EXIST "DBMS_RETCODE_INDEX_DOES_NOT_EXIST"
#define X_QUERY_DBMS_RETCODE_TABLE_ALREADY_EXISTS "DBMS_RETCODE_TABLE_ALREADY_EXISTS"
#define X_QUERY_DBMS_RETCODE_INDEX_ALREADY_EXISTS "DBMS_RETCODE_INDEX_ALREADY_EXISTS"
#define X_QUERY_DBMS_RETCODE_INDEX_ALREADY_EXISTS_2 "DBMS_RETCODE_INDEX_ALREADY_EXISTS_2"
#define X_QUERY_DBMS_RETCODE_VIEW_ALREADY_EXISTS  "DBMS_RETCODE_VIEW_ALREADY_EXISTS"
#define X_QUERY_DBMS_RETCODE_USER_ALREADY_EXISTS  "DBMS_RETCODE_USER_ALREADY_EXISTS"
#define X_QUERY_DBMS_RETCODE_INSUFF_PRIVILEGES  "DBMS_RETCODE_INSUFF_PRIVILEGES"
#define X_QUERY_DBMS_RETCODE_COLUMN_ALREADY_EXISTS "DBMS_RETCODE_COLUMN_ALREADY_EXISTS"
#define X_QUERY_DBMS_RETCODE_ROW_LOCKED           "DBMS_RETCODE_ROW_LOCKED"
#define X_QUERY_DBMS_RETCODE_COLUMN_DECREASE_PRECISION   "DBMS_RETCODE_COLUMN_DECREASE_PRECISION"
#define X_QUERY_DBMS_MIXED_MODE_COMMITMENT        "MIXED_MODE_COMMITMENT"
#define X_QUERY_DBMS_NATIVE_COMMITMENT            "NATIVE_COMMITMENT"
#define X_QUERY_DBMS_INDEX_DROPPED_WITH_TABLE     "INDEX_DROPPED_WITH_TABLE"
#define X_QUERY_DBMS_CREATE_RRNO_INDEXES          "CREATE_RRNO_INDEXES"

#define X_QUERY_CMD_CREATE_COLLECTION      "CMD_CREATE_COLLECTION"
#define X_QUERY_CMD_CREATE_COLLECTION_2000 "CMD_CREATE_COLLECTION_2000"
#define X_QUERY_CMD_GRANT_COLLECTION_PRIVS "CMD_GRANT_COLLECTION_PRIVS"
#define X_QUERY_CMD_GRANT_COLLECTION_PRIVS_2000 "CMD_GRANT_COLLECTION_PRIVS_2000"
#define X_QUERY_CMD_GRANT_TABLE_PRIVS      "CMD_GRANT_TABLE_PRIVS"
#define X_QUERY_CMD_GRANT_TABLE_PRIVS_2000 "CMD_GRANT_TABLE_PRIVS_2000"

#define X_QUERY_SUPPORTS_TYPE_CHAR           "SUPPORTS_TYPE_CHAR"
#define X_QUERY_SUPPORTS_TYPE_VARCHAR        "SUPPORTS_TYPE_VARCHAR"
#define X_QUERY_SUPPORTS_TYPE_LONGVARCHAR    "SUPPORTS_TYPE_LONGVARCHAR"
#define X_QUERY_SUPPORTS_TYPE_DECIMAL        "SUPPORTS_TYPE_DECIMAL"
#define X_QUERY_SUPPORTS_TYPE_TINYINT        "SUPPORTS_TYPE_TINYINT"
#define X_QUERY_SUPPORTS_TYPE_SMALLINT       "SUPPORTS_TYPE_SMALLINT"
#define X_QUERY_SUPPORTS_TYPE_INTEGER        "SUPPORTS_TYPE_INTEGER"
#define X_QUERY_SUPPORTS_TYPE_DOUBLE         "SUPPORTS_TYPE_DOUBLE"
#define X_QUERY_SUPPORTS_TYPE_BIGINT         "SUPPORTS_TYPE_BIGINT"
#define X_QUERY_SUPPORTS_TYPE_BINARY         "SUPPORTS_TYPE_BINARY"
#define X_QUERY_SUPPORTS_TYPE_VARBINARY      "SUPPORTS_TYPE_VARBINARY"
#define X_QUERY_SUPPORTS_TYPE_LONGVARBINARY  "SUPPORTS_TYPE_LONGVARBINARY"
#define X_QUERY_SUPPORTS_TYPE_NUMERIC        "SUPPORTS_TYPE_NUMERIC"
#define X_QUERY_SUPPORTS_TYPE_REAL           "SUPPORTS_TYPE_REAL"
#define X_QUERY_SUPPORTS_TYPE_DATE           "SUPPORTS_TYPE_DATE"
#define X_QUERY_SUPPORTS_TYPE_TIME           "SUPPORTS_TYPE_TIME"
#define X_QUERY_SUPPORTS_TYPE_DATETIME       "SUPPORTS_TYPE_DATETIME"
#define X_QUERY_SUPPORTS_TYPE_UCHAR          "SUPPORTS_TYPE_UCHAR"
#define X_QUERY_SUPPORTS_TYPE_UVARCHAR       "SUPPORTS_TYPE_UVARCHAR"
#define X_QUERY_SUPPORTS_TYPE_UCLOB          "SUPPORTS_TYPE_UCLOB"

#define X_QUERY_TYPE_CHAR_NATIVE_NAME     "TYPE_CHAR_NATIVE_NAME"

#define X_QUERY_TYPE_CHAR_NAME            "TYPE_CHAR_NAME"
#define X_QUERY_TYPE_VARCHAR_NAME         "TYPE_VARCHAR_NAME"
#define X_QUERY_TYPE_LONGVARCHAR_NAME     "TYPE_LONGVARCHAR_NAME"
#define X_QUERY_TYPE_DECIMAL_NAME         "TYPE_DECIMAL_NAME"
#define X_QUERY_TYPE_TINYINT_NAME         "TYPE_TINYINT_NAME"
#define X_QUERY_TYPE_SMALLINT_NAME        "TYPE_SMALLINT_NAME"
#define X_QUERY_TYPE_INTEGER_NAME         "TYPE_INTEGER_NAME"
#define X_QUERY_TYPE_DOUBLE_NAME          "TYPE_DOUBLE_NAME"
#define X_QUERY_TYPE_BIGINT_NAME          "TYPE_BIGINT_NAME"
#define X_QUERY_TYPE_BINARY_NAME          "TYPE_BINARY_NAME"
#define X_QUERY_TYPE_VARBINARY_NAME       "TYPE_VARBINARY_NAME"
#define X_QUERY_TYPE_LONGVARBINARY_NAME   "TYPE_LONGVARBINARY_NAME"
#define X_QUERY_TYPE_NUMERIC_NAME         "TYPE_NUMERIC_NAME"
#define X_QUERY_TYPE_REAL_NAME            "TYPE_REAL_NAME"
#define X_QUERY_TYPE_DATE_NAME            "TYPE_DATE_NAME"
#define X_QUERY_TYPE_TIME_NAME            "TYPE_TIME_NAME"
#define X_QUERY_TYPE_DATETIME_NAME        "TYPE_DATETIME_NAME"
#define X_QUERY_TYPE_UCHAR_NAME           "TYPE_UCHAR_NAME"
#define X_QUERY_TYPE_UVARCHAR_NAME        "TYPE_UVARCHAR_NAME"
#define X_QUERY_TYPE_UCLOB_NAME           "TYPE_UCLOB_NAME"

#define X_QUERY_TYPE_CHAR_MAX_DIGITS            "TYPE_CHAR_MAX_DIGITS"
#define X_QUERY_TYPE_VARCHAR_MAX_DIGITS         "TYPE_VARCHAR_MAX_DIGITS"
#define X_QUERY_TYPE_LONGVARCHAR_MAX_DIGITS     "TYPE_LONGVARCHAR_MAX_DIGITS"
#define X_QUERY_TYPE_DECIMAL_MAX_DIGITS         "TYPE_DECIMAL_MAX_DIGITS"
#define X_QUERY_TYPE_SMALLINT_MAX_DIGITS        "TYPE_SMALLINT_MAX_DIGITS"
#define X_QUERY_TYPE_INTEGER_MAX_DIGITS         "TYPE_INTEGER_MAX_DIGITS"
#define X_QUERY_TYPE_DOUBLE_MAX_DIGITS          "TYPE_DOUBLE_MAX_DIGITS"
#define X_QUERY_TYPE_BIGINT_MAX_DIGITS          "TYPE_BIGINT_MAX_DIGITS"
#define X_QUERY_TYPE_BINARY_MAX_DIGITS          "TYPE_BINARY_MAX_DIGITS"
#define X_QUERY_TYPE_VARBINARY_MAX_DIGITS       "TYPE_VARBINARY_MAX_DIGITS"
#define X_QUERY_TYPE_LONGVARBINARY_MAX_DIGITS   "TYPE_LONGVARBINARY_MAX_DIGITS"
#define X_QUERY_TYPE_NUMERIC_MAX_DIGITS         "TYPE_NUMERIC_MAX_DIGITS"
#define X_QUERY_TYPE_DATETIME_MAX_DIGITS        "TYPE_DATETIME_MAX_DIGITS"
#define X_QUERY_TYPE_UCHAR_MAX_DIGITS           "TYPE_UCHAR_MAX_DIGITS"
#define X_QUERY_TYPE_UVARCHAR_MAX_DIGITS        "TYPE_UVARCHAR_MAX_DIGITS"
#define X_QUERY_TYPE_UCLOB_MAX_DIGITS           "TYPE_UCLOB_MAX_DIGITS"

#define X_QUERY_TYPE_CHAR_MAX_DECIMALS          "TYPE_CHAR_MAX_DECIMALS"
#define X_QUERY_TYPE_VARCHAR_MAX_DECIMALS       "TYPE_VARCHAR_MAX_DECIMALS"
#define X_QUERY_TYPE_LONGVARCHAR_MAX_DECIMALS   "TYPE_LONGVARCHAR_MAX_DECIMALS"
#define X_QUERY_TYPE_DECIMAL_MAX_DECIMALS       "TYPE_DECIMAL_MAX_DECIMALS"
#define X_QUERY_TYPE_SMALLINT_MAX_DECIMALS      "TYPE_SMALLINT_MAX_DECIMALS"
#define X_QUERY_TYPE_INTEGER_MAX_DECIMALS       "TYPE_INTEGER_MAX_DECIMALS"
#define X_QUERY_TYPE_DOUBLE_MAX_DECIMALS        "TYPE_DOUBLE_MAX_DECIMALS"
#define X_QUERY_TYPE_BIGINT_MAX_DECIMALS        "TYPE_BIGINT_MAX_DECIMALS"
#define X_QUERY_TYPE_BINARY_MAX_DECIMALS        "TYPE_BINARY_MAX_DECIMALS"
#define X_QUERY_TYPE_VARBINARY_MAX_DECIMALS     "TYPE_VARBINARY_MAX_DECIMALS"
#define X_QUERY_TYPE_LONGVARBINARY_MAX_DECIMALS "TYPE_LONGVARBINARY_MAX_DECIMALS"
#define X_QUERY_TYPE_NUMERIC_MAX_DECIMALS       "TYPE_NUMERIC_MAX_DECIMALS"
#define X_QUERY_TYPE_DATETIME_MAX_DECIMALS      "TYPE_DATETIME_MAX_DECIMALS"

#define X_QUERY_TYPE_LONGVARCHAR_REQ_LEN        "TYPE_LONGVARCHAR_REQUIRES_LEN"
#define X_QUERY_TYPE_LONGVARBINARY_REQ_LEN      "TYPE_LONGVARBINARY_REQUIRES_LEN"
#define X_QUERY_TYPE_UCLOB_REQ_LEN              "TYPE_UCLOB_REQUIRES_LEN"
#define X_QUERY_TYPE_LONGVARCHAR_DEF_LEN        "TYPE_LONGVARCHAR_DEFAULT_LEN"
#define X_QUERY_TYPE_LONGVARBINARY_DEF_LEN      "TYPE_LONGVARBINARY_DEFAULT_LEN"
#define X_QUERY_TYPE_LONGVARGRAPHIC_DEF_LEN     "TYPE_LONGVARGRAPHIC_DEFAULT_LEN"
#define X_QUERY_TYPE_UCLOB_DEF_LEN              "TYPE_UCLOB_DEFAULT_LEN"

#define X_QUERY_TYPE_DATETIME_APPEND            "TYPE_DATETIME_APPEND"
#define X_QUERY_TYPE_BINARY_APPEND              "TYPE_BINARY_APPEND"
#define X_QUERY_TYPE_VARBINARY_APPEND           "TYPE_VARBINARY_APPEND"
#define X_QUERY_TYPE_UCHAR_APPEND               "TYPE_UCHAR_APPEND"
#define X_QUERY_TYPE_UVARCHAR_APPEND            "TYPE_UVARCHAR_APPEND"
#define X_QUERY_TYPE_UCLOB_APPEND               "TYPE_UCLOB_APPEND"

#define X_CONTEXT_TABLE        1
#define X_CONTEXT_VIEW         2
#define X_CONTEXT_COLUMNS      3
#define X_CONTEXT_INDEX        4
#define X_CONTEXT_INDEX_KEY    5
#define X_CONTEXT_PRIMARY_KEYS 6
#define X_CONTEXT_UNKNOWN      999

#define X_CTD_CAPABILITY_NAME_LENGTH  50
#define X_CTD_CAPABILITY_VALUE_LENGTH 150

typedef X_PVCHAR_FUNCTION FNGETTEXT (X_LONG);
typedef FNGETTEXT *PFNGETTEXT;

typedef X_LONG (*X_CTD_CALLBACK)( X_PVOID, X_PVOID, X_PVOID );

/* ----------------------------------------------------------------- */
/*  X_CTD_MESSAGE : Message                                          */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pNextMessage    Pointer to next message in the chain of message   */
/* Type            Message Type                                      */
/* Text            Message Text                                      */


struct X_CTD_MESSAGE
{
   struct X_CTD_MESSAGE * pNextMessage;
   X_CHAR                 chType;
   X_VCHAR                vchText[X_CTD_MESSAGE_MAXIMUM_LENGTH + 1];
};

/* ----------------------------------------------------------------- */
/*  X_CTD_COLUMN_DEFINITION : Definition of a table column           */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Column Name                                       */
/* Description     Description                                       */
/* Type            Type                                              */
/* Length          Length (Total Length / Digits)                    */
/* Decimals        Decimals                                          */
/* NotNull         Not Null                                          */
/* Auto            Automatically generate a unique number.           */

#define X_CTD_COLUMN_TYPE_ALPHA         'A'         
#define X_CTD_COLUMN_TYPE_BINARY        'B'
#define X_CTD_COLUMN_TYPE_UCHAR         'C'
#define X_CTD_COLUMN_TYPE_DECIMAL       'D'
#define X_CTD_COLUMN_TYPE_DATE          'E'
#define X_CTD_COLUMN_TYPE_FIXBINARY     'F'
#define X_CTD_COLUMN_TYPE_BIGINT        'G'
#define X_CTD_COLUMN_TYPE_CHAR          'H'
#define X_CTD_COLUMN_TYPE_INTEGER       'I'
#define X_CTD_COLUMN_TYPE_UCLOB         'L'
#define X_CTD_COLUMN_TYPE_NUMERIC       'N'
#define X_CTD_COLUMN_TYPE_TINYINT       'Q'
#define X_CTD_COLUMN_TYPE_REAL          'R'
#define X_CTD_COLUMN_TYPE_SMALLINT      'S'
#define X_CTD_COLUMN_TYPE_TIME          'T'
#define X_CTD_COLUMN_TYPE_DOUBLE        'U'
#define X_CTD_COLUMN_TYPE_UVARCHAR      'V'
#define X_CTD_COLUMN_TYPE_ALPHASBIN     'W'         
#define X_CTD_COLUMN_TYPE_FIXCHAR       'X'
#define X_CTD_COLUMN_TYPE_DATETIME      'Z'
#define X_CTD_COLUMN_TYPE_VCHAR         '1'
#define X_CTD_COLUMN_TYPE_VARCHAR       '1'
#define X_CTD_COLUMN_TYPE_VARBINARY     '2'
#define X_CTD_COLUMN_TYPE_LONGVARCHAR   '3'
#define X_CTD_COLUMN_TYPE_LONGVARBINARY '4'
#

#define X_CTD_COLUMN_KSHIFT_E           'E'
#define X_CTD_COLUMN_KSHIFT_O           'O'
#define X_CTD_COLUMN_KSHIFT_J           'J'

struct X_CTD_COLUMN_DEFINITION
{
   X_VCHAR  vchName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchAlternateName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchDescription[X_CTD_DESCRIPTION_LENGTH + 1];
   X_VCHAR  chType;
   X_ULONG  ulLength;
   X_ULONG  ulDecimals;
   X_BOOL   fNotNull;
   X_BOOL   fAuto;
   X_VCHAR  vchIntName[X_CTD_OBJECT_NAME_LENGTH  + 1];
   X_BOOL   fIgnoreIfNative;
   X_BOOL   fChanged;
   X_CHAR   chKShift;
   X_BOOL   fNewColumn;
   X_USHORT usAlloc;
};

/* ----------------------------------------------------------------- */
/*  X_CTD_PRIM_KEY_DEFINITION : Definition of a primary Key          */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Column Name                                       */

struct X_CTD_PRIM_KEY_DEFINITION
{
   X_VCHAR  vchName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchIntName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_PVCHAR pvchAlternateName;
};

/* ----------------------------------------------------------------- */
/*  X_CTD_VIEW_DEFINITION : Definition of a view                     */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Column Name                                       */
/* Definition      Definition with collections                       */

struct X_CTD_VIEW_DEFINITION
{
   X_VCHAR  vchName[X_CTD_OBJECT_NAME_LENGTH + 2 + 1];
   X_PVCHAR pvchDefinition;
   X_VCHAR  vchIntName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_PVCHAR pvchIntCommand;
   X_VCHAR  vchAlternateName[X_CTD_OBJECT_NAME_LENGTH + 1];
};


/* ----------------------------------------------------------------- */
/*  X_CTD_INDEX_KEY_DEFINITION : Definition of an index key          */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Column Name                                       */
/* Descending      Key is Descending                                 */
/* Internal Name   Column's Real Name.                               */

struct X_CTD_INDEX_KEY_DEFINITION
{
   X_VCHAR  vchName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_BOOL   fDescending;
   X_VCHAR  vchIntName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_PVCHAR pvchAlternateName;
};


/* ----------------------------------------------------------------- */
/*  X_CTD_INDEX_DEFINITION : Definition of an index                  */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Index Name                                        */
/* IndexKeys       Count of keys for this index                      */
/* pIndexKey       Pointer to first index key                        */
/* Unique          Index is unique                                   */
/* fChanged        Flag if index has changed                         */

struct X_CTD_INDEX_DEFINITION
{
   X_VCHAR  vchName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_USHORT uscIndexKeys;
   struct X_CTD_INDEX_KEY_DEFINITION * pIndexKey;
   X_BOOL   fUnique;
   X_BOOL   fChanged;
   X_USHORT usDBMSTypes;
   X_VCHAR  vchAlternateName[X_CTD_OBJECT_NAME_LENGTH + 1];
   struct X_CTD_APPEND_STMT * pAppendStmt[X_CTD_MAXIMUM_DATABASE_TYPES];
};


/* ----------------------------------------------------------------- */
/*  X_CTD_APPEND_STMT : Definition of extra text to append to the    */
/*                      CREATE statement                             */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Index Name                                        */
/* IndexKeys       Count of keys for this index                      */
/* pIndexKey       Pointer to first index key                        */
/* Unique          Index is unique                                   */

struct X_CTD_APPEND_STMT
{
   X_VCHAR  vchDBMSType[X_CTD_VALUE_LENGTH + 1];
   X_VCHAR  vchStmt[X_CTD_SQL_COMMAND_LENGTH + 1];
};


/* ----------------------------------------------------------------- */
/*  X_CTD_TABLE_DEFINITION : Definition of a table                   */
/* ----------------------------------------------------------------- */
/* Name            Description                                       */
/* ----            -----------                                       */
/* InternalName    InternalName                                      */
/* vchExternalName Real Name.                                        */
/* vchAlternateName Alternate Name (Long Name).                      */
/* CollectionName  Collection Name                                   */
/* Description     Description                                       */
/* pFirstMessage   Pointer to first associated message               */
/* pLastMessage    Pointer to last associated message                */
/* pCurrentMessage Pointer to current message                        */
/* usColumns       Count of columns                                  */
/* pColumn         Pointer to first column                           */
/* PrimaryIndexNameName of primary index (if applicable)             */
/* PrimaryKeys     Number of primary keys                            */
/* pPrimKey        Pointer to first primary key                      */
/* Views           Number of views                                   */
/* pView           Pointer to first view                             */
/* Indicies        Number of indicies                                */
/* pIndex          Pointer to first index                            */
/* pfGetText       Pointer to text retreival function                */

struct X_CTD_TABLE_DEFINITION
{
   X_VCHAR  vchInternalName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchExternalName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchAlternateName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchCollectionName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchDescription[X_CTD_DESCRIPTION_LENGTH + 1];

   struct X_CTD_MESSAGE * pFirstMessage;
   struct X_CTD_MESSAGE * pLastMessage;
   struct X_CTD_MESSAGE * pNextMessage;

   X_USHORT usDBMSTypes;
   struct X_CTD_APPEND_STMT * pAppendStmt[X_CTD_MAXIMUM_DATABASE_TYPES];

   X_USHORT usColumns;
   struct X_CTD_COLUMN_DEFINITION * pColumn;

   X_VCHAR  vchPrimaryIndexName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_USHORT usPrimKeys;
   struct X_CTD_PRIM_KEY_DEFINITION * pPrimKey;

   X_USHORT usViews;
   struct X_CTD_VIEW_DEFINITION * pView;

   X_USHORT usIndicies;
   struct X_CTD_INDEX_DEFINITION * pIndex;

   PFNGETTEXT pfGetText;

   /* ------------------------------ */
   /* PC Other Files Data            */
   /* Valid if fExternalFile is TRUE */
   /* ------------------------------ */
   short  fExternalFile;

   X_VCHAR  vchDSN[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchQualifier[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchDatabaseType[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchConnectionParms[X_CTD_CONNECT_PARMS_LENGTH + 1];
   X_CHAR   chEncrypted;
   X_VCHAR  vchSpare[X_CTD_SPARE_LENGTH + 1];

   /* End PC Other Files Data */

   X_BOOL   fCreateRRNOColumn;

   /* iSeries Native Support */
   X_VCHAR  vchDtaLib[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_BOOL   fCharToBinary;
   X_BOOL   fSetupIntNameRequired;
   X_CHAR   chUnderCmtCtl;

   X_CHAR   chLANSADefName;
   X_CHAR   chAtSign;

   X_VCHAR  vchOverrideCollectionName[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_VCHAR  vchOverrideDtaLib[X_CTD_OBJECT_NAME_LENGTH + 1];
   X_BOOL   fConvertedAutoIdToPrimaryKey;
};

/* ----------------------------------------------------------------- */
/*  X_CTD_DATABASE_CAPABILITIES                                      */
/* ----------------------------------------------------------------- */

struct X_CTD_DATABASE_CAPABILITY
{
   X_VCHAR  vchCapability[X_CTD_CAPABILITY_NAME_LENGTH + 1];
   X_LONG   lNumericValue;
   X_BOOL   fBooleanValue;
   X_VCHAR  vchStringValue[X_CTD_CAPABILITY_VALUE_LENGTH + 1];
};

struct X_CTD_DATABASE_TYPE
{
   X_SHORT  usTotalTypes;
   X_VCHAR  vchDBMSType[X_CTD_VALUE_LENGTH + 1];
   X_SHORT  usCapabs;
   struct   X_CTD_DATABASE_CAPABILITY * pCapab;
};

/* ----------------------------------------------------------------- */
/*  X_CTD_DBMS_INFO                                                  */
/* ----------------------------------------------------------------- */
/* Name                Description                                   */
/* ----                -----------                                   */
/* DBMSType            Type of DBMS                                  */
/* DBMSUserDLLName     Name of User DBMS DLL to be loaded            */
/* DBMSInternalDLLName Name of Internal DBMS DLL to be loaded        */
/* DBMSCollections     Supports Collections                          */
/* DBMSOkay            DBMS Return code for OK                       */
/* DBMSDuplicateRow    DBMS Return code for Duplicate Row            */
/* DBMSRowNotFound     DBMS Return code for Row Not Found            */
/* DBMSNoTableExists   DBMS Return code for Table does not exist     */
/* DBMSTableExists     DBMS Return code for Table already exists     */
/* DBMSIndexExists     DBMS Return code for Index already exists     */
/* DBMSViewExists      DBMS Return code for View already exists      */
/* DBMSDevelopDLLName  Name L/PC (development) DBMS DLL to be loaded */
/* DBMSIndexCollections Supports Collections on indexes              */
/* DBMSCharNativeName  Native Name for Char column                   */
/* DBMSNoIndexExists   DBMS Return code for Index does not exists    */
/* DBMSDescKeys        Supports Descending keys for indexes          */
/* DBMSEmulateCollections Requires Collection Emulation              */
/* DBMSSplitRDMLLines  Requires RDML Lines to be split (LX_F28)      */
/* DBMSDuplicateRow2   DBMS Return code for Duplicate Row (error 2)  */
/* DBMSDuplicateRow3   DBMS Return code for Duplicate Row (error 3)  */
/* DBMSMixedModeCommitment DBMS supports mixed mode commitment       */ 
/* DBMSIndexExists2    DBMS Return code for Index already exists (2) */ 
/* DBMSUserExists      DBMS Return code for User already exists      */
/* DBMSInsuffPrivs     DBMS Return code for Insufficient privileges  */
/* DBMSIndexAutoDrop   Index automatically dropped with table        */
/* DBMSNoTableExists2  DBMS Return code for Table does not exist (2) */
/* ...                                                               */
/* CollectionSeparator (e.g. Collection/Table or Collection.Table)   */
/* UseNativeCmtCtl     True if use DB2 iSeries commitment control    */
/* LANSADefDB          True if we support table create in this DBMS  */
/* DatetimeOnly        True if no native Date & Time types           */
/* DateAsDatetime      True if Date only is okay for Datetime literal*/
/* TimeAsDatetime      True if Time only is okay for Datetime literal*/
/* DatetimeMaxDigits   Value from TYPE_DATETIME_MAX_DIGITS           */
/* LockTimeout         0 means no timeout. Scale used depends on DB  */
/*                     e.g. SQL Server uses milliseconds.            */

struct X_CTD_DBMS_INFO
{
   X_VCHAR  vchDBMSType[X_CTD_VALUE_LENGTH + 1];
   X_VCHAR  vchSpare1[X_OLD_FILE_PATH_LENGTH + 1];
   X_VCHAR  vchSpare2[X_OLD_FILE_PATH_LENGTH + 1];
   X_BOOL   fDBMSCollections;
   X_LONG   lDBMSOkay;
   X_LONG   lDBMSDuplicateRow;
   X_LONG   lDBMSRowNotFound;
   X_LONG   lDBMSNoTableExists;
   X_LONG   lDBMSTableExists;
   X_LONG   lDBMSIndexExists;
   X_LONG   lDBMSViewExists;
   X_VCHAR  vchSpare3[X_OLD_FILE_PATH_LENGTH + 1];
   X_VCHAR  vchDBMSProduct[X_CTD_VALUE_LENGTH + 1];
   X_SHORT  sDBMSProduct;
   X_VCHAR  vchDBMSCategory[X_CTD_VALUE_LENGTH + 1];
   X_SHORT  sDBMSCategory;
   X_BOOL   fDBMSIndexCollections;
   X_VCHAR  vchDBMSCharNativeName[X_CTD_VALUE_LENGTH];
   X_LONG   lDBMSNoIndexExists;
   X_BOOL   fDBMSDescKeys;
   X_BOOL   fDBMSEmulateCollections;
   X_BOOL   fDBMSSplitRDMLLines;
   X_LONG   lDBMSDuplicateRow2;
   X_LONG   lDBMSDuplicateRow3;
   X_BOOL   fDBMSMixedModeCommitment;
   X_LONG   lDBMSIndexExists2;
   X_LONG   lDBMSUserExists;
   X_LONG   lDBMSInsuffPrivs;
   X_BOOL   fDBMSIndexAutoDrop;
   X_LONG   lDBMSNoTableExists2;
   X_VCHAR  vchDBMSVersion[X_CTD_VERSION_LENGTH + 1];
   X_VCHAR  vchUserDBMSDLLName[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR  vchInternalDBMSDLLName[X_NEW_FILE_PATH_LENGTH + 1];
   X_VCHAR  vchDevelopDBMSDLLName[X_NEW_FILE_PATH_LENGTH + 1];
   X_LONG   lDBMSColumnExists;
   X_CHAR   chIdentifierQuoteChar;
   X_BOOL   fUseInternalName;
   X_BOOL   fIgnoreNativeSupport;
   X_BOOL   chCollectionSeparator;
   X_BOOL   fUseNativeCmtCtl;
   X_BOOL   fLANSADefDB;
   X_BOOL   fDatetimeOnly;
   X_BOOL   fDateAsDatetime;
   X_BOOL   fTimeAsDatetime;
   X_LONG   lDATETIMEMaxDigit;
   X_BOOL   fAlloc;
   X_BOOL   fKShift;
   X_LONG   lDBMSRowLocked;
   X_LONG   lDBMSColumnDecreasePrecision;
   X_BOOL   fUseSingleConnection;
   X_INT    iLockTimeout;           /* Used an INT to be identical to same value in X_IDS structure */
   X_VCHAR  vchLockTimeoutCommand[X_CTD_CAPABILITY_VALUE_LENGTH + 1];
   X_VCHAR  vchLockType[X_CTD_VALUE_LENGTH + 1];
};

/* ----------------------------------------------------------------- */
/*  X_CTD_OPERATION_DATA                                             */
/* ----------------------------------------------------------------- */
/* Name                Description                                   */
/* ----                -----------                                   */
/* iType               Operation type (X_CTD_OPERATION).             */
/* pvchDesc            Operation description or the object name.     */
/* pVoid               Untouchable argument.                         */
/* pfnFormat           Call to format SQL command.                   */

struct X_CTD_OPERATION_DATA
{
   X_INT          iType;
   X_PVCHAR       pvchDesc;
   X_PVOID        pVoid;
   X_CTD_CALLBACK pfnFormat;
};

/* ----------------------------------------------------------------- */
/* Declaration of items related to the EXPR= file                    */
/* ----------------------------------------------------------------- */

#define X_CTD_EXPR_NORMAL_IDENTIFIER      "LANSACS400EXPORTFILE=NORM="
#define X_CTD_EXPR_COMPRESSED_IDENTIFIER  "LANSACS400EXPORTFILE=COMP="
#define X_CTD_EXPR_FILE_IDENTIFIER_LENGTH  26

/* X_CTD_EXPR_MAX_ARGS must always be a multiple of 2 */

#define X_CTD_EXPR_MAX_ARGS          10     
#define X_CTD_EXPR_MAX_ARG_LENGTH    9000 /* (MSGTXT * UTC_AVG_UTF8_BYTES_PER_CHAR) */

#define X_CTD_EXPR_MAX_RECORD_LENGTH (100 + (X_CTD_EXPR_MAX_ARGS * X_CTD_EXPR_MAX_ARG_LENGTH))

#define X_CTD_EXPR_READ_FILE         1
#define X_CTD_EXPR_WRITE_FILE        2
#define X_CTD_EXPR_WRITE_FILE_COMP   3

#define X_CTD_EXPR_STORE_CMD_LENGTH  2                            /* Command Identifier */
#define X_CTD_EXPR_STORE_ARG_LENGTH  4                            /* Argument Length (# digits in X_CTD_EXPR_MAX_ARG_LENGTH) */
#define X_CTD_EXPR_STORE_CMP_LENGTH  X_CTD_EXPR_STORE_ARG_LENGTH  /* Compressed Length */

#define X_CTD_DELETE_ALL_ROWS        "*ALL_ROWS"

/* Command identifiers */

#define X_CTD_EXPR_ISSUE_TEXT_MESSAGE              1
#define X_CTD_EXPR_DEFINE_REPOSITORY_TABLE         2
#define X_CTD_EXPR_DEFINE_REPOSITORY_TABLE_COLUMN  3


#define X_CTD_EXPR_INSERT_REPOSITORY_ROW           101
#define X_CTD_EXPR_SET_REPOSITORY_COLUMN_VALUE     102
#define X_CTD_EXPR_DELETE_REPOSITORY_ROWS          103
#define X_CTD_EXPR_DELETE_REPOSITORY_ASSOC_ROWS    104
#define X_CTD_EXPR_EXECUTE_IMPORT_DIRECTIVE        105
#define X_CTD_EXPR_CHECK_PARTITION                 106
#define X_CTD_EXPR_CHECK_REFERENCES                107
#define X_CTD_EXPR_SAVE_PROMPT_DETAILS             108
#define X_CTD_EXPR_EXECUTE_IMPORT_OVERRIDE         109
#define X_CTD_EXPR_UPDATE_F46_TO_LL2               110
#define X_CTD_EXPR_DELETE_WAM_PUBLISHED_XSL        111
#define X_CTD_EXPR_DELETE_WEBLET_PUBLISHED_XSL     112
#define X_CTD_EXPR_DELETE_TECHSRV_PUBLISHED_XSL    113
#define X_CTD_EXPR_UNLOCK_OBJECT_TASK_ID           114
#define X_CTD_EXPR_UPDATE_REPOSITORY_COLUMNS       115

#define X_CTD_EXPR_REMOVE_EXPR_FILE                800

#define X_CTD_EXPR_END_OF_COMMAND_STREAM           999

/* Compression details */

#define X_CTD_EXPR_DATA_TYPE_STREAM   'S'
#define X_CTD_EXPR_DATA_TYPE_PADDING  'P'
#define X_CTD_EXPR_DATA_TYPE_ENDFLAG  'E'

typedef struct X_CTD_EXPR_DATA_TYPE
{
   X_CHAR   chType;
} _X_CTD_EXPR_DATA_TYPE; /* @2506C1 */

typedef struct X_CTD_EXPR_DATA_STREAM
{
   X_CHAR   chType;
   X_FCHAR  fchStreamLength[X_CTD_EXPR_STORE_CMP_LENGTH];
} _X_CTD_EXPR_DATA_STREAM; /* @2506C1 */

typedef struct X_CTD_EXPR_DATA_PADDING
{
   X_CHAR   chType;
   X_CHAR   chPadChar;
   X_FCHAR  fchTotalPads[X_CTD_EXPR_STORE_CMP_LENGTH];
} _X_CTD_EXPR_DATA_PADDING; /* @2506C1 */

typedef struct X_CTD_EXPR_DATA_END
{
   X_CHAR   chType;
} _X_CTD_EXPR_DATA_END;


/* ----------------------------------------------------------------- */
/*  X_CTD_EXPR_ARGUMENT                                              */
/* ----------------------------------------------------------------- */

struct X_CTD_EXPR_ARGUMENT
{
   X_ULONG ulArgLength;
   X_VCHAR vchArgValue[X_CTD_EXPR_MAX_ARG_LENGTH];
};

/* ----------------------------------------------------------------- */
/*  X_CTD_EXPR_COMMAND                                               */
/* ----------------------------------------------------------------- */

struct X_CTD_EXPR_COMMAND
{
   X_ULONG                    ulCommandId;
   X_ULONG                    ulTotalArgs;
   struct X_CTD_EXPR_ARGUMENT Arg[X_CTD_EXPR_MAX_ARGS];
};

/* ----------------------------------------------------------------- */
/*  X_CTD_EXPR_FILE                                                  */
/* ----------------------------------------------------------------- */

struct X_CTD_EXPR_FILE
{
   FILE                      * pfEXPRFile;
   X_BOOL                      fCompressed;
   X_ULONG                     ulOpenFor;
   struct X_CTD_EXPR_COMMAND   Command;
   X_PVCHAR                    pvchBufferArea1;
   X_PVCHAR                    pvchBufferArea2;
};

/* ----------------------------------------------------------------- */
/*  X_CTD_SQL_STMNT                                                  */
/* ----------------------------------------------------------------- */

struct X_CTD_SQL_CMD
{
   X_LONG   lSize;
   X_PVCHAR pvchCmd;
};

/* ----------------------------------------------------------------- */
/*  Database capability functions                                    */
/* ----------------------------------------------------------------- */

X_SHORT_FUNCTION X_CTD_Load_Capabilities( X_PVCHAR vchFullFileName,
                                          struct X_CTD_DATABASE_TYPE **ppType,
                                          X_PVCHAR pvchFatalMessage );

X_VOID_FUNCTION X_CTD_Destroy_Capabilities( struct X_CTD_DATABASE_TYPE **ppType );

X_VOID_FUNCTION X_CTD_Query_DBMS_Types( struct X_CTD_DATABASE_TYPE *pType,
                                        X_PUSHORT pusTotalTypes,
                                        X_PVCHAR  apvchTypes[] );
X_VOID_FUNCTION X_CTD_Query_DBMS_Types_With_Capability( struct X_CTD_DATABASE_TYPE *pType,
                                                        X_PVCHAR pvchCapability,
                                                        X_PVCHAR pvchStringValue,
                                                        X_PUSHORT pusTotalTypes,
                                                        X_PVCHAR  apvchTypes[] );

X_BOOL_FUNCTION X_CTD_Query_DBMS_Capability( struct X_CTD_DATABASE_TYPE *pType,
                                             X_PVCHAR pvchDBMSType,
                                             X_PVCHAR pvchCapability,
                                             X_PVCHAR pvchStringValue,
                                             X_PLONG  plNumericValue,
                                             X_PBOOL  pfBooleanValue );

X_BOOL_FUNCTION X_CTD_Query_DBMS_Category_ID( X_PVCHAR pvchDBMSCategory,
                                              X_PSHORT psDBMSCategoryID );

X_BOOL_FUNCTION X_CTD_Query_DBMS_Product_ID( X_PVCHAR pvchDBMSProduct,
                                             X_PSHORT psDBMSProductID );

X_SHORT_FUNCTION X_CTD_Populate_DBMS_Info( struct X_CTD_DATABASE_TYPE *pType,
                                           struct X_CTD_DBMS_INFO *pInfo,
                                           X_PVCHAR pvchFatalMessage );

/* This prototype requires DBMS Specific header files      */
/* User needs to include sql.h or sqlcli.h to define this. */

#ifdef X_INCLUDE_CTDDEF_EXPLICITLY
#if defined(__LANSA_SQL_LAYER) || defined(__SQL) || defined(SQL_H_SQLCLI) || ((defined(X_OPERATING_SYSTEM_UNIX)) && defined(X_DATABASE_ODBC))
X_LONG_FUNCTION X_CTD_Set_Post_Connect_DBMS_Info (
   struct X_CTD_DATABASE_TYPE *pType,
   struct X_CTD_DBMS_INFO *pInfo,
   HDBC  hdbc,
   X_PVCHAR pvchFatalMessage );
#endif
#endif
/* ----------------------------------------------------------------- */
/*  Create and Load function Prototypes                              */
/* ----------------------------------------------------------------- */

X_VOID_FUNCTION X_CTD_Load_from_Disk( X_PVCHAR vchFullFileName,
                                      struct X_CTD_TABLE_DEFINITION **ppTable,
                                      PFNGETTEXT pfGetText,
                                      X_BOOL fLoadViews,
                                      X_BOOL fLoadIndicies,
                                      struct X_CTD_DATABASE_TYPE *pType,
                                      X_PVCHAR pvchDBMSType );

X_VOID_FUNCTION X_CTD_Save_to_Disk( X_PVCHAR vchFullFileName,
                                    struct X_CTD_TABLE_DEFINITION *pTable );

X_VOID_FUNCTION X_CTD_Create( struct X_CTD_TABLE_DEFINITION **ppTable,
                              X_PVCHAR    pvchInternalName,
                              X_PVCHAR    pvchExternalName,
                              X_PVCHAR    pvchAlternateName,
                              X_PVCHAR    pvchDescription,
                              X_PVCHAR    pvchCollection,
                              short       fExternalFile,
                              short       fCreateRRNOColumn,
                              X_PVCHAR    XOFDSN, 
                              X_PVCHAR    XOFQAL, 
                              X_PVCHAR    XOFTYP, 
                              X_PVCHAR    XOFCON, 
                              X_PVCHAR    XOFCRP, 
                              X_PVCHAR    XOFSP1,
                              PFNGETTEXT  pfGetText,
                              X_PVCHAR    pvchDtaLib,
                              X_CHAR      chUnderCmtCtl,
                              X_CHAR      chLANSADefName,
                              X_CHAR      chAtSign );

X_VOID_FUNCTION X_CTD_Destroy( struct X_CTD_TABLE_DEFINITION **pTable );

/* ----------------------------------------------------------------- */
/*  Message handling function prototypes                             */
/* ----------------------------------------------------------------- */


X_VOID_FUNCTION X_CTD_Issue_Message( struct X_CTD_TABLE_DEFINITION *pTable,
                                     X_CHAR   chType,
                                     X_PVCHAR pvchMessageText );

X_VOID_FUNCTION X_CTD_Clear_Messages( struct X_CTD_TABLE_DEFINITION *pTable );

X_VOID_FUNCTION X_CTD_Check_Messages( struct X_CTD_TABLE_DEFINITION *pTable,
                                      X_PUSHORT pusTotalInfo,
                                      X_PUSHORT pusTotalWarning,
                                      X_PUSHORT pusTotalFatal );

X_VOID_FUNCTION X_CTD_Get_Message( struct X_CTD_TABLE_DEFINITION *pTable,
                                   X_PVCHAR pvchMessageText,
                                   X_YES_NO chFirstMessage,
                                   X_YES_NO chFatalsOnly );

X_PVCHAR_FUNCTION X_CTD_Default_Get_Text( X_LONG sMessageNo );


/* ----------------------------------------------------------------- */
/*  Table definition function prototypes                             */
/* ----------------------------------------------------------------- */
X_VOID_FUNCTION X_CTD_Add_Append_Stmt( struct X_CTD_TABLE_DEFINITION *pTable,
                                       X_PVCHAR pvchDBMSType,
                                       X_PVCHAR pvchAppendStmt );

X_VOID_FUNCTION X_CTD_Add_Column( struct X_CTD_TABLE_DEFINITION *pTable,
                                  X_PVCHAR pvchName,
                                  X_PVCHAR pvchAlternateName,
                                  X_PVCHAR pvchDescription,
                                  X_CHAR chType,
                                  X_ULONG ulLength,
                                  X_ULONG ulDecimals,
                                  X_BOOL fNotNull,
                                  X_BOOL fAuto,
                                  X_PVCHAR pvchRealName,
                                  X_BOOL fIgnoreIfNative,
                                  X_CHAR chKShift,
                                  X_USHORT usAlloc );

X_VOID_FUNCTION X_CTD_Add_Prim_Key( struct X_CTD_TABLE_DEFINITION *pTable,
                                    X_PVCHAR vchPrimaryIndexName,
                                    X_PVCHAR vchKeyName );

X_VOID_FUNCTION X_CTD_Add_View( struct X_CTD_TABLE_DEFINITION *pTable,
                                X_PVCHAR vchViewName,
                                X_PVCHAR vchViewIntName,
                                X_PVCHAR pvchAlternateName,
                                X_PVCHAR vchViewCommand,
                                X_PVCHAR vchViewIntCmd );

X_VOID_FUNCTION X_CTD_Add_Index( struct X_CTD_TABLE_DEFINITION *pTable,
                                 X_PVCHAR vchIndexName,
                                 X_PVCHAR pvchAlternateName,
                                 X_PVCHAR pvchPostfix,
                                 X_PVCHAR pvchAltPostfix,
                                 X_BOOL fUnique );

X_VOID_FUNCTION X_CTD_Add_Index_Append_Stmt( struct X_CTD_TABLE_DEFINITION *pTable,
                                             X_PVCHAR pvchIndexName,
                                             X_PVCHAR pvchDBMSType,
                                             X_PVCHAR pvchAppendStmt );

X_VOID_FUNCTION X_CTD_Add_Index_Key( struct X_CTD_TABLE_DEFINITION *pTable,
                                     X_PVCHAR vchColumnName,
                                     X_BOOL fDescending );

X_VOID_FUNCTION X_CTD_Remove_Last_Index (struct X_CTD_TABLE_DEFINITION *pTable);

/* ----------------------------------------------------------------- */
/*  SQL command formatting function prototypes                       */
/* ----------------------------------------------------------------- */

X_VOID_FUNCTION X_CTD_Format_Create_Table( struct X_CTD_TABLE_DEFINITION *pTable,
                                           struct X_CTD_DATABASE_TYPE *pType,
                                           struct X_CTD_DBMS_INFO *pDBMSInfo,
                                           X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Create_Table_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                              struct X_CTD_DATABASE_TYPE *pType,
                                              struct X_CTD_DBMS_INFO *pDBMSInfo,
                                              struct X_CTD_SQL_CMD *pCmd,
                                              X_PVOID pParam,
                                              X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Alter_Column( struct X_CTD_TABLE_DEFINITION *pTable,
                                           struct X_CTD_DATABASE_TYPE *pType,
                                           struct X_CTD_DBMS_INFO *pDBMSInfo,
                                           X_USHORT usColumn,
                                           X_SHORT *psCommands,
                                           X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Alter_Column_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                              struct X_CTD_DATABASE_TYPE *pType,
                                              struct X_CTD_DBMS_INFO *pDBMSInfo,
                                              X_USHORT usColumn,
                                              X_SHORT *psCommands,
                                              struct X_CTD_SQL_CMD *pCmd,
                                              X_PVOID pParam,
                                              X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Alter_Auto_RRNO_Column( struct X_CTD_TABLE_DEFINITION *pTable,
                                                     struct X_CTD_DATABASE_TYPE *pType,
                                                     struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                     X_PVCHAR pvchSQLCommand );

X_VOID_FUNCTION X_CTD_Format_Create_Collection( struct X_CTD_TABLE_DEFINITION *pTable,
                                                struct X_CTD_DATABASE_TYPE *pType,
                                                struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                X_PVCHAR pvchConnectCommand,
                                                X_PVCHAR pvchGroupCommand,
                                                X_PVCHAR pvchPermissionCommand );

X_VOID_FUNCTION X_CTD_Format_Create_Sequence( struct X_CTD_TABLE_DEFINITION *pTable,
                                              struct X_CTD_DATABASE_TYPE *pType,
                                              struct X_CTD_DBMS_INFO *pDBMSInfo,
                                              X_PVCHAR pvchSQLCommand );

X_VOID_FUNCTION X_CTD_Format_Create_Sequence_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                                 struct X_CTD_DATABASE_TYPE *pType,
                                                 struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                 struct X_CTD_SQL_CMD *pCmd,
                                                 X_PVOID pParam,
                                                 X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Create_Index( struct X_CTD_TABLE_DEFINITION *pTable,
                                           struct X_CTD_DATABASE_TYPE *pType,
                                           struct X_CTD_DBMS_INFO *pDBMSInfo,
                                           X_USHORT usIndexNo,
                                           X_PVCHAR pvchCommand);

X_VOID_FUNCTION X_CTD_Format_Create_Index_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                              struct X_CTD_DATABASE_TYPE *pType,
                                              struct X_CTD_DBMS_INFO *pDBMSInfo,
                                              X_USHORT usIndexNo,
                                              struct X_CTD_SQL_CMD *pCmd,
                                              X_PVOID pParam,
                                              X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Create_View( struct X_CTD_TABLE_DEFINITION *pTable,
                                          struct X_CTD_DATABASE_TYPE *pType,
                                          struct X_CTD_DBMS_INFO *pDBMSInfo,
                                          X_USHORT usViewNo,
                                          X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Create_View_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                             struct X_CTD_DATABASE_TYPE *pType,
                                             struct X_CTD_DBMS_INFO *pDBMSInfo,
                                             X_USHORT usViewNo,
                                             struct X_CTD_SQL_CMD *pCmd,
                                             X_PVOID pParam,
                                             X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Drop_Table( struct X_CTD_TABLE_DEFINITION *pTable,
                                         struct X_CTD_DATABASE_TYPE *pType,
                                         struct X_CTD_DBMS_INFO *pDBMSInfo,
                                         X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Drop_Table_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                            struct X_CTD_DATABASE_TYPE *pType,
                                            struct X_CTD_DBMS_INFO *pDBMSInfo,
                                            X_PVCHAR pvchSubfix,
                                            X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Drop_Table_Ex2( struct X_CTD_TABLE_DEFINITION *pTable,
                                             struct X_CTD_DATABASE_TYPE *pType,
                                             struct X_CTD_DBMS_INFO *pDBMSInfo,
                                             X_PVCHAR pvchSubfix,
                                             struct X_CTD_SQL_CMD *pCmd,
                                             X_PVOID pParam,
                                             X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Drop_View( struct X_CTD_TABLE_DEFINITION *pTable,
                                        struct X_CTD_DATABASE_TYPE *pType,
                                        struct X_CTD_DBMS_INFO *pDBMSInfo,
                                        X_USHORT usViewNo,
                                        X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Drop_View_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                           struct X_CTD_DATABASE_TYPE *pType,
                                           struct X_CTD_DBMS_INFO *pDBMSInfo,
                                           X_USHORT usViewNo,
                                           struct X_CTD_SQL_CMD *pCmd,
                                           X_PVOID pParam,
                                           X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Drop_Index( struct X_CTD_TABLE_DEFINITION *pTable,
                                         struct X_CTD_DATABASE_TYPE *pType,
                                         struct X_CTD_DBMS_INFO *pDBMSInfo,
                                         X_USHORT usIndexNo,
                                         X_PVCHAR pvchCommand,
                                         X_BOOL fForce);

X_VOID_FUNCTION X_CTD_Format_Drop_Index_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                            struct X_CTD_DATABASE_TYPE *pType,
                                            struct X_CTD_DBMS_INFO *pDBMSInfo,
                                            X_USHORT usIndexNo,
                                            X_BOOL fForce,
                                            struct X_CTD_SQL_CMD *pCmd,
                                            X_PVOID pParam,
                                            X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Table_Identifier( struct X_CTD_TABLE_DEFINITION *pTable,
                                               struct X_CTD_DATABASE_TYPE *pType,
                                               struct X_CTD_DBMS_INFO *pDBMSInfo,
                                               X_PVCHAR pvchIdentifier );

X_VOID_FUNCTION X_CTD_Format_Table_Name( struct X_CTD_TABLE_DEFINITION *pTable,
                                         struct X_CTD_DATABASE_TYPE *pType,
                                         struct X_CTD_DBMS_INFO *pDBMSInfo,
                                         X_PVCHAR pvchTableQuoted,
                                         X_PVCHAR pvchCollectionQuoted );

X_VOID_FUNCTION X_CTD_Format_Drop_Add_Primary_Key( struct X_CTD_TABLE_DEFINITION *pTable,
                                                   struct X_CTD_DATABASE_TYPE *pType,
                                                   struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                   X_PVCHAR pvchPrimKey,
                                                   X_BOOL fDropPrimKey,
                                                   X_BOOL fCreatePrimKey,
                                                   X_SHORT *psCommands,
                                                   X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Drop_Add_Primary_Key_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                                      struct X_CTD_DATABASE_TYPE *pType,
                                                      struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                      X_PVCHAR pvchPrimKey,
                                                      X_BOOL fDropPrimKey,
                                                      X_BOOL fCreatePrimKey,
                                                      X_SHORT *psCommands,
                                                      struct X_CTD_SQL_CMD *pCmd,
                                                      X_PVOID pParam,
                                                      X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Copy_Table( struct X_CTD_TABLE_DEFINITION *pTable,
                                         struct X_CTD_DATABASE_TYPE *pType,
                                         struct X_CTD_DBMS_INFO *pDBMSInfo,
                                         X_PVCHAR pvchSubfix,
                                         X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Copy_Table_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                            struct X_CTD_DATABASE_TYPE *pType,
                                            struct X_CTD_DBMS_INFO *pDBMSInfo,
                                            X_PVCHAR pvchSuffix,
                                            struct X_CTD_SQL_CMD *pCmd,
                                            X_PVOID pParam,
                                            X_CTD_CALLBACK pfnCallback );

X_VOID_FUNCTION X_CTD_Format_Restore_Table_Data( struct X_CTD_TABLE_DEFINITION *pTable,
                                                 struct X_CTD_TABLE_DEFINITION *pOldTable,
                                                 struct X_CTD_DATABASE_TYPE *pType,
                                                 struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                 X_PVCHAR pvchSubfix,
                                                 X_PVCHAR pvchCommand );

X_VOID_FUNCTION X_CTD_Format_Restore_Table_Data_Ex( struct X_CTD_TABLE_DEFINITION *pTable,
                                                    struct X_CTD_TABLE_DEFINITION *pOldTable,
                                                    struct X_CTD_DATABASE_TYPE *pType,
                                                    struct X_CTD_DBMS_INFO *pDBMSInfo,
                                                    X_PVCHAR pvchSubfix,
                                                    struct X_CTD_SQL_CMD *pCmd,
                                                    X_PVOID pParam,
                                                    X_CTD_CALLBACK pfnCallback );

X_BOOL_FUNCTION X_CTD_Set_Override_Data_Library( struct X_CTD_TABLE_DEFINITION *pTable,
                                                 X_PVCHAR pvchOverrideDtaLib,
                                                 X_PVCHAR pvchOverrideCollection );

X_BOOL_FUNCTION X_CTD_GetTableName( struct X_CTD_TABLE_DEFINITION *pTable,
                                    X_BOOL fUseInternalName,
                                    X_PVCHAR *ppvchTable,
                                    X_PVCHAR *ppvchCollection );

X_BOOL_FUNCTION X_CTD_GetStandardTableName( struct X_CTD_TABLE_DEFINITION *pTable,
                                            X_BOOL fUseInternalName,
                                            X_PVCHAR * ppvchTable,
                                            X_PVCHAR * ppvchCollection );

X_BOOL_FUNCTION X_CTD_GetTableData( struct X_CTD_TABLE_DEFINITION *pTable,
                                    X_PVCHAR pvchKeyword,
                                    X_PVCHAR *ppvchData );

X_BOOL_FUNCTION X_CTD_GetViewData( struct X_CTD_VIEW_DEFINITION *pView,
                                   X_PVCHAR pvchKeyword,
                                   X_PVCHAR *ppvchData );

X_BOOL_FUNCTION X_CTD_GetColumnName( struct X_CTD_COLUMN_DEFINITION *pColumn,
                                     X_BOOL fUseInternalName,
                                     X_PVCHAR *ppvchName );

X_BOOL_FUNCTION X_CTD_GetPrimaryKeyName( struct X_CTD_PRIM_KEY_DEFINITION *pPrimaryKey,
                                         X_BOOL fUseInternalName,
                                         X_BOOL fIgnoreAltName,
                                         X_PVCHAR *ppvchName );

X_BOOL_FUNCTION X_CTD_GetIndexName( struct X_CTD_INDEX_DEFINITION *pIndex,
                                    X_BOOL fUseInternalName,
                                    X_PVCHAR *ppvchName );

X_BOOL_FUNCTION X_CTD_GetIndexKeyName( struct X_CTD_INDEX_KEY_DEFINITION *pIndexKey,
                                       X_BOOL fUseInternalName,
                                       X_BOOL fIgnoreAltName,
                                       X_PVCHAR *ppvchName );

X_BOOL_FUNCTION X_CTD_GetViewName( struct X_CTD_VIEW_DEFINITION *pView,
                                   X_BOOL fUseInternalName,
                                   X_PVCHAR *ppvchName );

X_VOID_FUNCTION X_CTD_Format_View_Name( struct X_CTD_TABLE_DEFINITION *pTable,
                                        struct X_CTD_DATABASE_TYPE *pType,
                                        struct X_CTD_DBMS_INFO *pDBMSInfo,
                                        X_INT iView,
                                        X_PVCHAR pvchBuffer );

X_BOOL_FUNCTION X_CTD_Table_IsAlternateNameSet( struct X_CTD_TABLE_DEFINITION *pTable );
X_BOOL_FUNCTION X_CTD_View_IsAlternateNameSet( struct X_CTD_VIEW_DEFINITION *pView );

X_INT_FUNCTION X_CTD_Query_Format_Cmd(
   struct X_CTD_TABLE_DEFINITION *  pTable,
   struct X_CTD_DATABASE_TYPE    *  pType,
   struct X_CTD_DBMS_INFO        *  pDBMSInfo,
   struct X_CTD_SQL_CMD          *  pSqlCmd,
   X_PVOID                          pParam,
   X_CTD_CALLBACK                   pfnSqlCmd,
   X_CTD_CALLBACK                   pfnGetFunc,
   X_CTD_CALLBACK                   pfnExecSqlCmd );

/* ----------------------------------------------------------------- */
/*  EXPR (Export Result File Functions)                              */
/* ----------------------------------------------------------------- */

X_BOOL_FUNCTION X_CTD_EXPR_Open( X_PVCHAR pvchFileName,
                                 struct X_CTD_EXPR_FILE **ppEXPR,
                                 X_ULONG ulOpenFor );

X_BOOL_FUNCTION X_CTD_EXPR_Close( struct X_CTD_EXPR_FILE **ppEXPR );

X_ULONG_FUNCTION X_CTD_EXPR_Write( struct X_CTD_EXPR_FILE *pEXPR );

X_ULONG_FUNCTION X_CTD_EXPR_Read( struct X_CTD_EXPR_FILE *pEXPR );

#endif
