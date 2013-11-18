/* ================================================================= */
/* == LANSA FOR WINDOWS PLATFORM INDEPENDENT FUNCTION PROTOTYPES === */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_FUNPRO.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : Standard function prototypes                */
/*                                                                   */
/* ================================================================= */

#ifndef __INCL_X_FUNPRO_H__
#define __INCL_X_FUNPRO_H__

#include <stdarg.h>

#include "liiodef.h"
#include "x_oidstr.h"


#ifdef __cplusplus
extern "C" {
#endif

/* ================================================================= */
/*  LANSA FOR MOBILE functions                                       */
/* ================================================================= */

#if defined(X_OPERATING_SYSTEM_ANDROID)

#include <jni.h>

X_VOID_FUNCTION X_IOS_RT_RUN_FORM ( const char *, JNIEnv * env, jobject pThis );
X_VOID_FUNCTION X_IOS_RT_ADD_MODULE( const char *, void * );
X_VOID_FUNCTION X_IOS_RT_HANDLE_EVENT ( int hObject, int idEvent, JNIEnv * env, jobject pThis );
X_VOID_FUNCTION X_IOS_RT_HANDLE_TEXT_CHANGED ( int hObject, const char* pvchText, JNIEnv * env, jobject pThis );

#elif defined(X_OPERATING_SYSTEM_IOS)

X_VOID_FUNCTION X_IOS_RT_RUN_FORM ( const char *, void * );
X_VOID_FUNCTION X_IOS_RT_ADD_MODULE( const char *, void * );

#endif 

/* ================================================================= */
/*  X_OIDFUN.C functions                                             */
/* ================================================================= */

X_LONG_FUNCTION X_FUN_Get_Build_Number( void );

/* ================================================================= */
/*  X_FUN1.C functions                                               */
/* ================================================================= */
X_VOID_FUNCTION X_Set_Alpha_from_Vchar(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PVCHAR,
                                       X_PFCHAR,
                                       X_SHORT);

X_VOID_FUNCTION  X_Set_Vchar_from_Alpha(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PFCHAR,
                                       X_SHORT,
                                       X_PVCHAR,
                                       X_SHORT);

X_VOID_FUNCTION  X_Set_Long_from_Vchar(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      X_PVCHAR,
                                      X_PLONG);

X_VOID_FUNCTION  X_Set_Short_from_Vchar(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PVCHAR,
                                       X_PSHORT);

X_VOID_FUNCTION  X_Set_Double_from_Vchar(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_PVCHAR,
                                        X_PDOUBLE);

X_VOID_FUNCTION  X_Set_Long_from_Alpha(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      X_PVCHAR,
                                      X_SHORT,
                                      X_PLONG);

X_VOID_FUNCTION  X_Set_Short_from_Alpha(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PFCHAR,
                                       X_SHORT,
                                       X_PSHORT);

X_VOID_FUNCTION  X_Set_Double_from_Alpha(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_PFCHAR,
                                        X_SHORT,
                                        X_PDOUBLE);

X_VOID_FUNCTION  X_Set_Long_from_Packed(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PFCHAR,
                                       X_SHORT,
                                       X_SHORT,
                                       X_PLONG);

X_VOID_FUNCTION  X_Set_Short_from_Packed(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_PFCHAR,
                                        X_SHORT,
                                        X_SHORT,
                                        X_PSHORT);

X_VOID_FUNCTION  X_Set_Double_from_Packed(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT,
                                         X_PDOUBLE);

X_VOID_FUNCTION  X_Set_Long_from_Signed(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PFCHAR,
                                       X_SHORT,
                                       X_SHORT,
                                       X_PLONG);

X_VOID_FUNCTION  X_Set_Short_from_Signed(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_PFCHAR,
                                        X_SHORT,
                                        X_SHORT,
                                        X_PSHORT);

X_VOID_FUNCTION  X_Set_Double_from_Signed(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT,
                                         X_PDOUBLE);

X_VOID_FUNCTION X_Set_String_from_Signed(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PFCHAR pfchSigned,
                                         X_SHORT sPrecision,
                                         X_SHORT sScale,
                                         X_PVCHAR pvchString );

X_VOID_FUNCTION  X_Set_Packed_from_Long(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_LONG,
                                       X_PFCHAR,
                                       X_SHORT,
                                       X_SHORT);

X_VOID_FUNCTION  X_Set_Packed_from_Short(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_SHORT,
                                        X_PFCHAR,
                                        X_SHORT,
                                        X_SHORT);

X_VOID_FUNCTION  X_Set_Packed_from_Double(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_DOUBLE,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT);

X_VOID_FUNCTION  X_Set_Signed_from_Long(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_LONG,
                                       X_PFCHAR,
                                       X_SHORT,
                                       X_SHORT);

X_VOID_FUNCTION  X_Set_Signed_from_Short(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_SHORT,
                                        X_PFCHAR,
                                        X_SHORT,
                                        X_SHORT);

X_VOID_FUNCTION  X_Set_Signed_from_Double(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_DOUBLE,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT);

X_VOID_FUNCTION  X_Set_Signed_from_Packed(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT);

X_VOID_FUNCTION X_Set_String_from_Packed(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PFCHAR pfchPacked,
                                         X_SHORT  sPrecision,
                                         X_SHORT  sScale,
                                         X_PVCHAR pvchString);

X_VOID_FUNCTION  X_Set_Packed_from_Signed(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT,
                                         X_PFCHAR,
                                         X_SHORT,
                                         X_SHORT);

X_VOID_FUNCTION  X_Set_String_from_Edit_Code(struct X_IDS *,
                                            struct X_PRO *,
                                            struct X_FUN *,
                                            struct X_FLD [],
                                            X_SHORT,
                                            X_PVCHAR,
                                            X_CHAR,
                                            X_ULONG *,
                                            X_PVCHAR,
                                            X_BOOL *);

X_VOID_FUNCTION  X_Set_String_from_Edit_Word(struct X_IDS *,
                                            struct X_PRO *,
                                            struct X_FUN *,
                                            X_PVCHAR,
                                            X_PCCHAR,
                                            X_ULONG *,
                                            X_PVCHAR);

X_VOID_FUNCTION  X_Set_Packed_from_Alpha(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                X_PDICTIONARY_FIELD,
                                X_PDICTIONARY_FIELD);

X_VOID_FUNCTION X_Set_Vchar_from_Double(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_DOUBLE,
                                        X_PVCHAR,
                                        X_SHORT,
                                        X_SHORT,
                                        X_SHORT);

X_LONG_FUNCTION X_Vec_Query_Scope(struct X_IDS * pX_Ids,
                                  struct X_PRO * pX_Pro,
                                  struct X_FUN * pX_Fun,
                                  struct X_FLD   X_Fld[],
                                  X_SHORT        sVec);

X_VOID_FUNCTION X_SetBifGlobal( X_PVOID pGlobal );
X_PVOID_FUNCTION X_GetBifGlobal( void );

X_VOID_FUNCTION X_HeapListInsert( void );
X_VOID_FUNCTION X_PIM_HeapListInsert( void );
X_VOID_FUNCTION X_BIF_HeapListInsert( void );

/* ================================================================= */
/*  X_FUN2.C functions                                               */
/* ================================================================= */

#ifdef __GNUC__
__attribute__((format(printf, 5, 6)))
#endif
X_VOID_FUNCTION X_Fatal_Error_Never_Show(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PCCHAR pvchFunction,
                                         X_PCCHAR pvchFormat,
                                         ...);

#ifdef __GNUC__
__attribute__((format(printf, 5, 6)))
#endif
X_VOID_FUNCTION X_Fatal_Error_Force_Show(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         X_PCCHAR pvchFunction,
                                         X_PCCHAR pvchFormat,
                                         ...);

#ifdef __GNUC__
__attribute__((format(printf, 5, 6)))
#endif
X_BOOL_FUNCTION X_Fatal_Error(struct X_IDS *pX_Ids,
                              struct X_PRO *pX_Pro,
                              struct X_FUN *pX_Fun,
                              X_PCCHAR pvchFunction,
                              X_PCCHAR pvchFormat,
                              ...);

#ifdef __GNUC__
__attribute__((format(printf, 5, 8)))
#endif
X_VOID_FUNCTION X_SQL_Error(struct X_IDS *pX_Ids,
                            struct X_PRO *pX_Pro,
                            struct X_FUN *pX_Fun,
                            X_PCCHAR pvchFunction,
                            X_PCCHAR pvchFormat,
                            X_PCCHAR pvchTableName,
                            X_LONG lSQLErrorCode,
                            ...);

#ifdef __GNUC__
__attribute__((format(printf, 5, 8)))
#endif
X_VOID_FUNCTION X_OS_Error(struct X_IDS *pX_Ids,
                           struct X_PRO *pX_Pro,
                           struct X_FUN *pX_Fun,
                           X_PCCHAR pvchFunction,
                           X_PCCHAR pvchFormat,
                           X_LONG lMsgNumber,
                           X_PVCHAR pvchMsgText,
                           ...);

X_INT_FUNCTION X_Open_SSL_Errors_Callback(
   struct X_IDS *pX_Ids,
   struct X_PRO *pX_Pro,
   struct X_FUN *pX_Fun,
   X_PCCHAR pvchErrorText );


X_VOID_FUNCTION X_Warn_Error_Va(struct X_IDS *pX_Ids,
                                struct X_PRO *pX_Pro,
                                struct X_FUN *pX_Fun,
                                X_SHORT sUimRequest,
                                X_LONG lMsgId,
                                va_list va);

X_VOID_FUNCTION X_Warn_Error_Ex(struct X_IDS *pX_Ids,
                                struct X_PRO *pX_Pro,
                                struct X_FUN *pX_Fun,
                                X_SHORT sUimRequest,
                                X_LONG lMsgId,
                                ...);

X_VOID_FUNCTION X_Warn_Error(struct X_IDS *pX_Ids,
                             struct X_PRO *pX_Pro,
                             struct X_FUN *pX_Fun,
                             X_LONG lMsgId,
                             ...);

X_VOID_FUNCTION X_SimpleErrorDisplay(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_PVCHAR,
                                     X_PVCHAR);

/* ================================================================= */
/*  X_FUN3.C functions                                               */
/* ================================================================= */

X_VOID_FUNCTION X_XENV_Apply_Standard_Settings(struct X_IDS *pX_Ids);

X_VOID_FUNCTION X_XENV_Save_Setting(struct X_IDS * pX_Ids,
                                    X_PVCHAR       pvchSettingString);

X_PVCHAR_FUNCTION X_XENV_Query_Setting(struct X_IDS * pX_Ids,
                                       X_PVCHAR       pvchVariableName,
                                       X_BOOL         fQueryOSifNotFound);

X_VOID_FUNCTION X_XENV_Destroy_Settings(struct X_IDS * pX_Ids);

X_BOOL_FUNCTION X_DBCF_Apply_Setting( struct X_IDS *     pX_Ids,
                                      X_PVCHAR           pvchSettingString,
                                      X_DB_CONNECT_TYPE *pCtOptions );

X_VOID_FUNCTION X_DBCF_Trace_Settings( struct X_IDS *     pX_Ids,
                                       X_DB_CONNECT_TYPE  CtOptions );

X_BOOL_FUNCTION X_DBCF_Decode_Settings( struct X_IDS *     pX_Ids,
                                        X_DB_CONNECT_TYPE  CtOptions,
                                        X_PVCHAR           pvchSettingString,
                                        X_USHORT           usLen );

X_BOOL_FUNCTION X_Bit_Flag_Apply_Setting( struct X_IDS * pX_Ids,
                                          X_PVCHAR       pvchSettingString,
                                          PX_BITFLAG     pBitFlagEnvTable,
                                          X_ENUM *       pBitFlags);

X_VOID_FUNCTION X_Bit_Flag_Trace_Settings( struct X_IDS *   pX_Ids,
                                           PX_BITFLAG       pBitFlagEnvTable,
                                           X_ENUM           BitFlags);

X_BOOL_FUNCTION X_Bit_Flag_Decode_Settings( struct X_IDS *  pX_Ids,
                                            X_ENUM          BitFlags,
                                            X_PVCHAR        pvchSettingString,
                                            X_USHORT        usLen,
                                            PX_BITFLAG      pBitFlagEnvTable,
                                            X_PVCHAR        pvchParameterName );

X_VOID_FUNCTION X_Convert_Double_To_String(struct X_IDS *,
                                           struct X_PRO *,
                                           struct X_FUN *,
                                           struct X_FLD [],
                                           X_SHORT,
                                           X_DOUBLE,
                                           X_PVCHAR);

X_PDICTIONARY_FIELD X_FUNTYPE X_Vec_Apply_Index(struct X_IDS *,
                                                struct X_PRO *,
                                                struct X_FUN *,
                                                struct X_FLD [],
                                                X_SHORT);

X_VOID_FUNCTION X_Vec_Set_Index(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD [],
                                X_SHORT);

X_VOID_FUNCTION X_Vec_Init(struct X_IDS *,
                           struct X_PRO *,
                           struct X_FUN *,
                           struct X_FLD [],
                           X_SHORT);

X_VOID_FUNCTION X_Vec_Init_Subtype(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   X_SHORT,
                                   struct X_FLD [],
                                   X_CHAR);

X_VOID_FUNCTION X_Vec_Init_Group(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_FLD [],
                                 X_SHORT,
                                 X_SHORT[]);

X_VOID_FUNCTION X_Vec_Set_from_Double(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_DOUBLE);

X_VOID_FUNCTION X_Vec_Set_from_Long(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_LONG);

X_VOID_FUNCTION X_Vec_Set_from_LongLong(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_FLD [],
                                        X_SHORT,
                                        X_LONGLONG);

X_VOID_FUNCTION X_Vec_Set_from_Short(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_SHORT);

X_VOID_FUNCTION X_Vec_Set_from_Vchar(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_PVCHAR);

X_VOID_FUNCTION X_Vec_Set_from_Binary(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_PVCHAR);

X_VOID_FUNCTION X_Vec_Set_from_Binary2(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_PFCHAR ,
                                       X_ULONG);

X_VOID_FUNCTION X_Vec_Set_from_SysVar(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_PCCHAR);

X_VOID_FUNCTION X_Vec_Get_as_Vchar(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_FLD [],
                                   X_SHORT,
                                   X_SHORT,
                                   X_PVCHAR);

X_VOID_FUNCTION X_Vec_Get_as_Utf8Vchar(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_ULONG,
                                       X_PVCHAR);

X_VOID_FUNCTION X_Vec_Get_as_Utf8Vchar_Helper(struct X_IDS *pX_Ids,
                                              struct X_PRO *pX_Pro,
                                              struct X_FUN *pX_Fun,
                                              X_PDICTIONARY_FIELD pField,
                                              struct X_FLD *pFld,
                                              X_TYPE_FLAG chType,
                                              X_ULONG lTMaxLen,
                                              X_PVCHAR pvchString);

X_VOID_FUNCTION X_Vec_Set_from_Utf8Vchar(struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         struct X_FLD X_Fld[],
                                         X_SHORT sVec,
                                         X_PVCHAR pvchString);

X_VOID_FUNCTION X_Vec_Get_as_Double(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_PDOUBLE);

X_VOID_FUNCTION X_Vec_Get_as_Long(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_FLD [],
                                  X_SHORT,
                                  X_PLONG);

X_VOID_FUNCTION X_Vec_Get_as_LongLong(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_PLONGLONG);

X_VOID_FUNCTION X_Vec_Get_as_Short(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_FLD [],
                                   X_SHORT,
                                   X_PSHORT);

X_BOOL_FUNCTION X_Find_List_By_Name(struct X_IDS *    pX_Ids,
                                    struct X_PRO *    pX_Pro,
                                    struct X_FUN *    pX_Fun,
                                    X_BOOL            fSeachInvocStack,
                                    X_PVCHAR          pvchListName,
                                    X_PSHORT          psListNo,
                                    X_LIST_VOID **    ppList,
                                    struct X_FUN **   ppFunction );


X_VOID_FUNCTION X_Destroy_Sorted_Vector_List ( struct X_IDS * pX_Ids,
                                               struct X_PRO * pX_Pro,
                                               struct X_FUN * pX_Fun );


X_VOID_FUNCTION X_Create_Sorted_Vector_List ( struct X_IDS * pX_Ids,
                                              struct X_PRO * pX_Pro,
                                              struct X_FUN * pX_Fun );


X_BOOL_FUNCTION X_Vec_Get_as_String_by_Name( struct X_IDS *  pX_Ids,
                                             struct X_PRO *  pX_Pro,
                                             struct X_FUN *  pX_Fun,
                                             X_BOOL          fSeachInvocStack,
                                             X_PVCHAR        pvchName,
                                             X_CHAR          chEditCode,
                                             X_PCCHAR        pvchEditWord,
                                             X_PVCHAR        pvchString,
                                             X_PSHORT        psReturnVector,
                                             struct X_FUN ** ppReturnFunction );

X_BOOL_FUNCTION X_Vec_Get_as_Varchar_by_Name( struct X_IDS *  pX_Ids,
                                              struct X_PRO *  pX_Pro,
                                              struct X_FUN *  pX_Fun,
                                              X_BOOL          fSeachInvocStack,
                                              X_PCCHAR        pvchName,
                                              X_CHAR          chEditCode,
                                              X_PCCHAR        pvchEditWord,
                                              PX_FLD_CHAR     pVarChar,
                                              X_PVCHAR  *     ppvchString,
                                              X_PSHORT        psReturnVector,
                                              struct X_FUN ** ppReturnFunction,
                                              X_PCCHAR        pvchFormat );

X_BOOL_FUNCTION X_Vec_Get_as_Utf8Vchar_by_Name( struct X_IDS *  pX_Ids,
                                                struct X_PRO *  pX_Pro,
                                                struct X_FUN *  pX_Fun,
                                                X_BOOL          fSeachInvocStack,
                                                X_PCCHAR        pvchName,
                                                PX_FLD_CHAR     pVarChar,
                                                X_ULONG         ulDataLength,
                                                X_PVCHAR        pvchString,
                                                X_PSHORT        psReturnVector,
                                                struct X_FUN ** ppReturnFunction );

X_BOOL_FUNCTION X_Vec_Find_Vector_by_Name( struct X_IDS *  pX_Ids,
                                           struct X_PRO *  pX_Pro,
                                           struct X_FUN *  pX_Fun,
                                           X_BOOL          fSeachInvocStack,
                                           X_PCCHAR        pvchName,
                                           X_PSHORT        psReturnVector,
                                           struct X_FUN ** ppReturnFunction );

X_VOID_FUNCTION  X_Vec_Get_as_String(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_CHAR,
                                    X_PCCHAR,
                                    X_PSHORT,
                                    X_PVCHAR);

X_LONG_FUNCTION X_Comp_Get_as_String(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT ,
                                    X_SHORT ,
                                    X_PVCHAR );

X_VOID_FUNCTION  X_Vec_Get_as_String2( struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_CHAR,
                                       X_PCCHAR,
                                       X_PULONG,
                                       X_PVCHAR *,
                                       PX_FLD_CHAR,
                                       X_BOOL   *);

X_VOID_FUNCTION X_Vec_Get_as_VarChar(  struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT ,
                                       X_CHAR  ,
                                       X_PCCHAR ,
                                       PX_FLD_CHAR,
                                       X_BOOL   *);

X_SHORT_FUNCTION  X_Vec_Set_from_String_Ex(struct X_IDS *,
                                           struct X_PRO *,
                                           struct X_FUN *,
                                           struct X_FLD [],
                                           X_SHORT,
                                           X_CHAR,
                                           X_PCCHAR,
                                           X_PCCHAR,
                                           X_BOOL);

X_SHORT_FUNCTION  X_Vec_Set_from_String(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_FLD [],
                                        X_SHORT,
                                        X_CHAR,
                                        X_PCCHAR,
                                        X_PVCHAR);

X_SHORT_FUNCTION  X_Vec_Set_from_String2(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_FLD [],
                                        X_SHORT,
                                        X_CHAR,
                                        X_PCCHAR,
                                        X_PCCHAR,
                                        X_BOOL);

X_VOID_FUNCTION  X_Vec_Force_from_String(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_PVCHAR);

X_VOID_FUNCTION  X_Vec_Assign_Identical_Field(struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD [],
                             X_SHORT,
                             struct X_FLD [],
                             X_SHORT,
                             X_BOOL);

X_VOID_FUNCTION X_Vec_Assign_from_Data_Structure(   struct  X_IDS *pX_Ids,
                                          struct  X_PRO *pX_Pro,
                                          struct  X_FUN *pX_Fun,
                                          X_PDICTIONARY_FIELD pSource,
                                          struct  X_FLD X_FldTgt[],
                                          X_SHORT sVector_Tgt );

X_VOID_FUNCTION X_Vec_Assign_to_Data_Structure(   struct  X_IDS *pX_Ids,
                                          struct  X_PRO *pX_Pro,
                                          struct  X_FUN *pX_Fun,
                                          struct  X_FLD X_FldSrc[],
                                          X_SHORT sVector_Src,
                                          X_PDICTIONARY_FIELD pTarget );

X_VOID_FUNCTION  X_Vec_Assign(struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD [],
                             X_SHORT,
                             struct X_FLD [],
                             X_SHORT);

X_VOID_FUNCTION  X_Vec_Assign_Grp(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_FLD [],
                                 X_SHORT,
                                 X_SHORT[],
                                 struct X_FLD [],
                                 X_SHORT,
                                 X_SHORT[]);

X_SHORT_FUNCTION  X_Vec_Compare(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_FLD [],
                               X_SHORT,
                               struct X_FLD [],
                               X_SHORT);

X_SHORT_FUNCTION  X_Vec_Compare_Generic(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       struct X_FLD [],
                                       X_SHORT);

X_VOID_FUNCTION  X_Vec_Get_Vchar_Len(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_PSHORT);

X_YES_NO_FUNCTION  X_Vec_Null(struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD [],
                             X_SHORT);

X_VOID_FUNCTION  X_Vec_Increment(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD [],
                                X_SHORT,
                                X_SHORT);

X_VOID_FUNCTION  X_Vec_Substring(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD [],
                                X_SHORT,
                                X_SHORT,
                                X_SHORT,
                                struct X_FLD [],
                                X_SHORT,
                                X_SHORT,
                                X_SHORT);

X_VOID_FUNCTION  X_Vec_Substring2(  struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_ULONG,
                                    X_ULONG,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_ULONG,
                                    X_ULONG);

X_SHORT_FUNCTION  X_Compare_Identical_SorP(X_PDICTIONARY_FIELD,
                                          X_PDICTIONARY_FIELD,
                                          X_TYPE_FLAG,
                                          X_SHORT);

X_VOID_FUNCTION  X_Vec_Save_Values (struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_FLD [],
                                   X_SHORT,
                                   X_SHORT [],
                                   X_SHORT,
                                   X_PDICTIONARY_FIELD []);

X_VOID_FUNCTION  X_Vec_Restore_Values (struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_SHORT [],
                                      X_SHORT,
                                      X_PDICTIONARY_FIELD []);

X_SHORT_FUNCTION  X_Vec_Compare_Values (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_SHORT [],
                                       X_SHORT,
                                       X_PDICTIONARY_FIELD []);

X_VOID_FUNCTION  X_Vec_Save_All_Fields (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_SHORT,
                                       X_PDICTIONARY_FIELD []);

X_VOID_FUNCTION  X_Vec_Restore_All_Fields (struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          struct X_FLD [],
                                          X_SHORT,
                                          X_SHORT,
                                          X_PDICTIONARY_FIELD []);


X_LONG_FUNCTION  X_Comp_Get_as_Vchar(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_SHORT,
                                     X_PVCHAR);

X_LONG_FUNCTION  X_Comp_Get_as_Utf8Vchar(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_ULONG,
                                     X_PVCHAR);

X_LONG_FUNCTION  X_Comp_Get_as_Double(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_PDOUBLE);

X_LONG_FUNCTION  X_Comp_Get_as_Long(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD [],
                                    X_SHORT,
                                    X_PLONG);

X_LONG_FUNCTION  X_Comp_Get_as_Short(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_PSHORT);
X_LONG_FUNCTION X_Comp_Get_as_Binary(  struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT ,
                                       void * );
X_LONG_FUNCTION X_Comp_Get_as_Int64(   struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT ,
                                       X_INT64 *);

X_LONG_FUNCTION  X_Comp_Set_from_Double(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_FLD [],
                                        X_SHORT,
                                        X_DOUBLE);

X_LONG_FUNCTION  X_Comp_Set_from_Long(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_LONG);

X_LONG_FUNCTION  X_Comp_Set_from_Short(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_SHORT);


X_LONG_FUNCTION  X_Comp_Set_from_Vchar(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT,
                                       X_PVCHAR);

X_LONG_FUNCTION X_Comp_Set_from_String(struct X_IDS *pX_Ids,
                                       struct X_PRO *pX_Pro,
                                       struct X_FUN *pX_Fun,
                                       struct X_FLD X_Fld[],
                                       X_SHORT sVec,
                                       X_PVCHAR pvchString);

X_LONG_FUNCTION X_Comp_Set_from_Binary(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD [],
                                       X_SHORT ,
                                       void * );

X_LONG_FUNCTION X_Comp_Set_from_Int64(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT ,
                                     X_INT64 );

X_VOID_FUNCTION  X_Vec_Notify_Component(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_FLD [],
                                        X_SHORT);

X_VOID_FUNCTION  X_Vec_Notify_Component_Error(struct X_IDS *,
                                              struct X_PRO *,
                                              struct X_FUN *,
                                              struct X_FLD [],
                                              X_SHORT);

X_LONG_FUNCTION X_Convert_Field_to_Temp_Component( struct X_IDS  * pX_Ids,
                                                   struct X_PRO  * pX_Pro,
                                                   struct X_FUN  * pX_Fun,
                                                   struct X_FLD  * pX_FldSrc,
                                                   struct X_FLD  * pX_Fld);

X_LONG_FUNCTION X_Convert_Component_to_Temp_Field ( struct X_IDS  * pX_Ids,
                                                    struct X_PRO  * pX_Pro,
                                                    struct X_FUN  * pX_Fun,
                                                    struct X_FLD  * pX_FldSrc,
                                                    struct X_FLD  * pX_Fld );

X_LONG_FUNCTION X_Refresh_Field_Value (struct X_IDS  * pX_Ids,
                                       struct X_PRO  * pX_Pro,
                                       struct X_FUN  * pX_Fun,
                                       struct X_FLD  * pX_Fld);

X_LONG_FUNCTION X_Refresh_Component_Value (struct X_IDS  * pX_Ids,
                                           struct X_PRO  * pX_Pro,
                                           struct X_FUN  * pX_Fun,
                                           struct X_FLD  * pX_Fld);


X_LONG_FUNCTION X_Refresh_Field_Group_Values (struct X_IDS  * pX_Ids,
                                              struct X_PRO  * pX_Pro,
                                              struct X_FUN  * pX_Fun,
                                              struct X_FLD    X_Fld[],
                                              X_SHORT         scGroupCount,
                                              X_SHORT         asGVector[]);

X_LONG_FUNCTION X_Refresh_Component_Group_Values( struct X_IDS  * pX_Ids,
                                                  struct X_PRO  * pX_Pro,
                                                  struct X_FUN  * pX_Fun,
                                                  struct X_FLD    X_Fld[],
                                                  X_SHORT         scGroupCount,
                                                  X_SHORT         asGVector[] );

X_LONG_FUNCTION X_Refresh_Field_All_Values (struct X_IDS  * pX_Ids,
                                            struct X_PRO  * pX_Pro,
                                            struct X_FUN  * pX_Fun,
                                            struct X_FLD    X_Fld[],
                                            X_SHORT         scX_Fld);

X_LONG_FUNCTION X_Refresh_Component_All_Values( struct X_IDS  * pX_Ids,
                                                struct X_PRO  * pX_Pro,
                                                struct X_FUN  * pX_Fun,
                                                struct X_FLD    X_Fld[],
                                                X_SHORT         scX_Fld );

X_LONG_FUNCTION X_Comp_Init(struct X_IDS *pX_Ids,
                            struct X_PRO *pX_Pro,
                            struct X_FUN *pX_Fun,
                            struct X_FLD X_Fld[],
                            X_SHORT sVec);



X_LONG_FUNCTION X_Flip_to_RDML_Vec_Format (struct X_IDS  * pX_Ids,
                                           struct X_PRO  * pX_Pro,
                                           struct X_FUN  * pX_Fun,
                                           struct X_FLD  * pX_Fld,
                                           X_SHORT         scX_Fld,
                                           X_PVOID       * ppvSaveFlips,
                                           X_PVOID       * ppvSaveSpace,
                                           X_BOOL          fSpare1,
                                           X_BOOL          fSpare2);

X_LONG_FUNCTION X_Flop_to_RDMLX_Vec_Format (struct X_IDS  * pX_Ids,
                                            struct X_PRO  * pX_Pro,
                                            struct X_FUN  * pX_Fun,
                                            struct X_FLD  * pX_Fld,
                                            X_SHORT         scX_Fld,
                                            X_PVOID       * ppvSaveFlips,
                                            X_BOOL          fForceRefresh,
                                            X_PVOID       * ppvSaveSpace,
                                            X_BOOL          fSpare1,
                                            X_BOOL          fSpare2);


X_VOID_FUNCTION X_Comp_Set_Error_On ( struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      struct X_FLD   X_Fld[],
                                      X_SHORT        sVec);

X_VOID_FUNCTION X_Comp_Set_Error_Off ( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       struct X_FLD   X_Fld[],
                                       X_SHORT        sVec);

X_LONG_FUNCTION X_Comp_Set_All_Errors_Off ( struct X_IDS * pX_Ids,
                                            struct X_PRO * pX_Pro,
                                            struct X_FUN * pX_Fun,
                                            X_SHORT        scX_Fld,
                                            struct X_FLD   X_Fld[] );

X_LONG_FUNCTION X_Exchange_Vector_Value( PX_COMP_SERVICES_POINT_REQUEST   pRequestBlock,
                                         X_PVOID                         apvAgreedArgs[],
                                         struct X_IDS                  * pX_Ids,
                                         struct X_PRO                  * pX_Pro,
                                         struct X_FUN                  * pX_Fun,
                                         struct X_FLD                  * pX_Fld,
                                         PX_VECTOR_COMPONENT_EXCHANGE    pBaseExchange,
                                         X_PULONG                        pulExchangeCount);

X_VOID_FUNCTION X_Vec_Get_as_String_Ex( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        struct X_FLD     X_Fld[],
                                        X_SHORT          sVec,
                                        X_CHAR           chEditCode,
                                        X_PCCHAR         pvchEditWord,
                                        X_PSHORT         psRetLength,
                                        X_PVCHAR         pvchString,
                                        X_BOOL        *  pfTrimReq );

X_VOID_FUNCTION X_Vec_Encode_as_String( struct X_IDS *pX_Ids,
                                        struct X_PRO *pX_Pro,
                                        struct X_FUN *pX_Fun,
                                        struct X_FLD X_Fld[],
                                        X_SHORT  sVec,
                                        X_CHAR   chEditCode,
                                        X_PCCHAR pvchEditWord,
                                        X_PULONG pulRetLength,
                                        X_PVCHAR * ppvchString,
                                        PX_FLD_CHAR pVarChar,
                                        X_BOOL   *  pfAddBlank,
                                        X_PCCHAR pvchFormat );

X_SHORT_FUNCTION X_Vec_Decode_from_String(struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro,
                                          struct X_FUN *pX_Fun,
                                          struct X_FLD X_Fld[],
                                          X_SHORT  sVec,
                                          X_CHAR   chEditCode,
                                          X_PCCHAR pvchEditWord,
                                          X_LONG   lLength,
                                          X_PCCHAR pvchString,
                                          X_PCCHAR pvchFormat,
                                          X_BOOL   fKeepPreviousXVAR);

X_VOID_FUNCTION X_Vec_Encode_as_UTF16_String( struct X_IDS *pX_Ids,
                                              struct X_PRO *pX_Pro,
                                              struct X_FUN *pX_Fun,
                                              struct X_FLD X_Fld[],
                                              X_SHORT  sVec,
                                              X_CHAR   chEditCode,
                                              X_PCCHAR pvchEditWord,
                                              X_PULONG pulRetLength,
                                              X_UTF16_VCHAR **ppwchString,
                                              PX_FLD_CHAR pVarChar,
                                              X_BOOL   *  pfAddBlank,
                                              X_PCCHAR pvchFormat );

X_SHORT_FUNCTION X_Vec_Decode_from_UTF16_String(struct X_IDS *pX_Ids,
                                                struct X_PRO *pX_Pro,
                                                struct X_FUN *pX_Fun,
                                                struct X_FLD X_Fld[],
                                                X_SHORT  sVec,
                                                X_CHAR   chEditCode,
                                                X_PCCHAR pvchEditWord,
                                                X_LONG   lLength,
                                                const X_UTF16_VCHAR * pwchString,
                                                X_PCCHAR pvchFormat,
                                                X_BOOL   fKeepPreviousXVAR);

X_BOOL_FUNCTION X_CheckRDMLField(struct X_IDS *pX_Ids,
                                 struct X_PRO *pX_Pro,
                                 struct X_FUN *pX_Fun,
                                 struct X_FLD *pFld,
                                 X_SHORT sVector,
                                 X_CHAR chKeyboardShift,
                                 X_DWORD dwFieldFlags,
                                 X_ULONG nFieldLen,
                                 X_PCCHAR pszValue,
                                 X_PPCHAR ppszNewValue,
                                 X_PLONG plMessageId);

X_BOOL_FUNCTION
   X_CheckRDMLField_UTF16        (
      struct X_IDS         *  pX_Ids,
      struct X_PRO         *  pX_Pro,
      struct X_FUN         *  pX_Fun,
      struct X_FLD         *  pFld,
      X_SHORT                 sVector,
      X_CHAR                  chKeyboardShift,
      X_DWORD                 dwFieldFlags,
      X_ULONG                 nFieldLen,
      X_PCCHAR                pszValue,
      const X_UTF16_VCHAR*    pszUTF16Value,
      X_PPCHAR                ppszNewValue,
      X_UTF16_VCHAR**         ppszUTF16NewValue,
      X_PLONG                 plMessageId );

X_LONG_FUNCTION
X_ValidateFieldAssign(
   struct X_IDS *pX_Ids, struct X_PRO *pX_Pro, struct X_FUN *pX_Fun,
   struct X_FLD *pFld,
   X_CHAR chEditCode, X_PCCHAR pszEditWord,
   X_CHAR chKeyboardShift, X_DWORD dwFieldFlags,
   X_ULONG nFieldLen, X_PCCHAR pszValue,
   X_BOOL fSuppressWarning, X_BOOL fIssueMessage, X_PLONG plMessageId,
   X_BOOL fKeepPreviousXVAR);

X_LONG_FUNCTION
X_ValidateFieldAssignWithPanelField(
   struct X_IDS *pX_Ids, struct X_PRO *pX_Pro, struct X_FUN *pX_Fun,
   struct X_FLD *pFld,
   struct X_PANEL_FLD *pPanelFld,
   X_ULONG nFieldLen, X_PCCHAR pszValue,
   X_BOOL fSuppressWarning, X_BOOL fIssueMessage, X_PLONG plMessageId,
   X_BOOL fKeepPreviousXVAR);

X_LONG_FUNCTION
X_ValidateFieldAssign_UTF16(
   struct X_IDS *pX_Ids, struct X_PRO *pX_Pro, struct X_FUN *pX_Fun,
   struct X_FLD *pFld,
   X_CHAR chEditCode, X_PCCHAR pszEditWord,
   X_CHAR chKeyboardShift, X_DWORD dwFieldFlags,
   X_ULONG nFieldLen, const X_UTF16_VCHAR* pszValue,
   X_BOOL fSuppressWarning, X_BOOL fIssueMessage, X_PLONG plMessageId,
   X_BOOL fKeepPreviousXVAR);

   void*
      X_FUN_Allocator(
         void* pAnchor,
         size_t uiBytes);

X_VOID_FUNCTION X_BuildGenericNumericKey( struct   X_IDS *pX_Ids,
                                          struct   X_PRO *pX_Pro,
                                          struct   X_FUN *pX_Fun,
                                          X_PVCHAR pvchColumn,
                                          X_SHORT  sColumnLen,
                                          struct   X_FLD X_Fld[],
                                          X_SHORT  sVector_Src,
                                          X_PVCHAR pvchSqlStmnt,
                                          X_CHAR   chAOD,
                                          X_CHAR   chBackwards );

X_BOOL_FUNCTION X_Authenticate_User( struct X_IDS  *pX_Ids,
                                     struct X_PRO  *pX_Pro,
                                     struct X_FUN  *pX_Fun,
                                     X_PVCHAR      pvchPrincipalName,
                                     X_SHORT       sBuffSize );

#ifdef X_OPERATING_SYSTEM_ISERIES
X_VOID_FUNCTION X_Vec_Get_as_NativeBuffer(    struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              struct X_FLD  *  pX_FldOAM,
                                              X_SHORT          sVecOAM,
                                              struct X_FLD  *  pX_FldNtv,
                                              X_SHORT          sVecNtv,
                                              X_PSHORT         psNtvSpecial,
                                              X_PCHAR          pchNullInd );

X_VOID_FUNCTION X_Vec_Set_from_NativeBuffer(  struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              struct X_FLD  *  pX_FldOAM,
                                              X_SHORT          sVecOAM,
                                              struct X_FLD  *  pX_FldNtv,
                                              X_SHORT          sVecNtv,
                                              X_PSHORT         psNtvSpecial,
                                              X_PCHAR          pchNullInd );
X_VOID_FUNCTION X_Vec_Get_as_NativeBuffer_2(  struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              struct X_FLD  *  pX_FldOAM,
                                              X_SHORT          sVecOAM,
                                              struct X_FLD  *  pX_FldNtv,
                                              X_SHORT          sVecNtv,
                                              X_PSHORT         psNtvSpecial,
                                              X_PCHAR          pchNullInd,
                                              X_UINT           uiNativeLen );

X_VOID_FUNCTION X_Vec_Set_from_NativeBuffer_2(struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              struct X_FLD  *  pX_FldOAM,
                                              X_SHORT          sVecOAM,
                                              struct X_FLD  *  pX_FldNtv,
                                              X_SHORT          sVecNtv,
                                              X_PSHORT         psNtvSpecial,
                                              X_PCHAR          pchNullInd,
                                              X_UINT           uiNativeLen );
#endif

/* ================================================================= */
/*  X_FUN3A.C functions                                              */
/* ================================================================= */

X_VOID_FUNCTION
   X_Vec_Resolve_Assignment               (
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct  X_FLD                          X_FldSrc[],
      X_SHORT                                sVector_Src,
      struct X_FLD                           X_FldTgt[],
      X_SHORT                                sVector_Tgt,
      X_FUN_VECTOR_ASSIGN_FUNCTION        ** ppVectorAssignFunction );

/* ================================================================= */
/*  X_FUN3C.C functions                                              */
/* ================================================================= */

X_VOID_FUNCTION X_Set_Remembered_Value ( struct X_IDS * pX_Ids,
                                         struct X_PRO * pX_Pro,
                                         struct X_FUN * pX_Fun,
                                         struct X_FLD   X_Fld[],
                                         X_SHORT        sRememberVector,
                                         X_SHORT        sRememberFormat );

X_VOID_FUNCTION X_Save_Remembered_Values ( struct X_IDS * pX_Ids,
                                           struct X_PRO * pX_Pro,
                                           struct X_FUN * pX_Fun,
                                           struct X_FLD   X_Fld[],
                                           X_BOOL         fFreeMemory );




X_VOID_FUNCTION X_DestroySpaceTreeofTrees ( struct X_IDS * pX_Ids );

X_VOID_FUNCTION X_CreateSpace ( struct X_IDS *  pX_Ids,
                                struct X_PRO *  pX_Pro,
                                struct X_FUN *  pX_Fun,
                                X_PVCHAR        pvchSpaceName,
                                PX_SPACE_ENTRY  pSpaceEntry,
                                X_ULONG         ulInitialSize,
                                X_BOOL          fCreateAutomatically );

X_VOID_FUNCTION X_DestroySpace ( struct X_IDS *  pX_Ids,
                                 struct X_PRO *  pX_Pro,
                                 struct X_FUN *  pX_Fun,
                                 X_PVCHAR        pvchSpaceName );

X_VOID_FUNCTION X_AddSpaceColumn ( struct X_IDS * pX_Ids,
                                   struct X_PRO * pX_Pro,
                                   struct X_FUN * pX_Fun,
                                   X_PVCHAR pvchSpaceName,
                                   X_PVCHAR pvchColumnAttributes,
                                   struct X_FLD * pX_ProtoFld );

X_BOOL_FUNCTION X_InserttoSpace (  struct X_IDS *  pX_Ids,
                                   struct X_PRO *  pX_Pro,
                                   struct X_FUN *  pX_Fun,
                                   X_PVCHAR        pvchSpaceName,
                                   X_ULONG         ulVectors,
                                   struct X_FUN *  apX_Fun[],
                                   X_SHORT         asVector[] );

X_BOOL_FUNCTION X_FetchinSpace (  struct X_IDS *  pX_Ids,
                                  struct X_PRO *  pX_Pro,
                                  struct X_FUN *  pX_Fun,
                                  X_PVCHAR        pvchSpaceName,
                                  X_ULONG         ulKeyVectors,
                                  struct X_FUN *  apKeyX_Fun[],
                                  X_SHORT         asKeyVector[],
                                  X_ULONG         ulRetVectors,
                                  struct X_FUN *  apRetX_Fun[],
                                  X_SHORT         asRetVector[]);

X_BOOL_FUNCTION X_SelectinSpace (  struct X_IDS *  pX_Ids,
                                   struct X_PRO *  pX_Pro,
                                   struct X_FUN *  pX_Fun,
                                   X_PVCHAR        pvchSpaceName,
                                   X_ULONG         ulCursorNumber,
                                   X_ULONG         ulKeyVectors,
                                   struct X_FUN *  apKeyX_Fun[],
                                   X_SHORT         asKeyVector[],
                                   X_ULONG         ulRetVectors,
                                   struct X_FUN *  apRetX_Fun[],
                                   X_SHORT         asRetVector[]);

X_BOOL_FUNCTION X_SelectNextinSpace (  struct X_IDS *  pX_Ids,
                                       struct X_PRO *  pX_Pro,
                                       struct X_FUN *  pX_Fun,
                                       X_PVCHAR        pvchSpaceName,
                                       X_ULONG         ulCursorNumber,
                                       X_ULONG         ulKeyVectors,
                                       struct X_FUN *  apKeyX_Fun[],
                                       X_SHORT         asKeyVector[],
                                       X_ULONG         ulRetVectors,
                                       struct X_FUN *  apRetX_Fun[],
                                       X_SHORT         asRetVector[]);

X_BOOL_FUNCTION X_DeleteinSpace (  struct X_IDS *  pX_Ids,
                                   struct X_PRO *  pX_Pro,
                                   struct X_FUN *  pX_Fun,
                                   X_PVCHAR        pvchSpaceName,
                                   X_ULONG         ulCursorNumber,
                                   X_ULONG         ulKeyVectors,
                                   struct X_FUN *  apKeyX_Fun[],
                                   X_SHORT         asKeyVector[] );

X_BOOL_FUNCTION X_UpdateinSpace (  struct X_IDS *  pX_Ids,
                                   struct X_PRO *  pX_Pro,
                                   struct X_FUN *  pX_Fun,
                                   X_PVCHAR        pvchSpaceName,
                                   X_ULONG         ulVectors,
                                   struct X_FUN *  apX_Fun[],
                                   X_SHORT         asVector[] );

X_VOID_FUNCTION X_Vec_Encode_as_SQL_UTF16_Hex_Literal( struct X_IDS * pX_Ids,
                                                       struct X_PRO * pX_Pro,
                                                       struct X_FUN * pX_Fun,
                                                       struct X_DBM * pX_DBM,
                                                       struct X_FLD   X_Fld[],
                                                       X_SHORT        sVec,
                                                       X_PULONG       pulRetLength,
                                                       X_PVCHAR     * ppvchString,
                                                       X_BOOL         fLike,
                                                       X_ULONG        ulPadLength );

/* ================================================================= */
/*  X_FUN4.C functions                                               */
/* ================================================================= */

X_VOID_FUNCTION  X_Add_to_Invocation_Stack
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_TYPE_FLAG,
                               X_YES_NO,
                               X_YES_NO,
                               X_YES_NO);

X_VOID_FUNCTION  X_Rmv_from_Invocation_Stack
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_TYPE_FLAG,
                               X_YES_NO);

X_VOID_FUNCTION  X_Issue_Message_Vec
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               struct X_FLD [],
                               X_SHORT,
                               X_SHORT[]);

X_VOID_FUNCTION  X_Issue_Message_FChar
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_LONG,
                               X_PFCHAR);

X_VOID_FUNCTION  X_Store_Message
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_LONG,
                               X_PFCHAR);

X_VOID_FUNCTION  X_Store_Message_Fixed
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_LONG,
                               X_PFCHAR);

X_VOID_FUNCTION  X_Store_Message_Extended
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_LONG,
                               X_PVCHAR,
                               X_LONG,
                               X_PVCHAR);

X_VOID_FUNCTION  X_Issue_Message_VChar
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_PCCHAR);

X_VOID_FUNCTION  X_Issue_Message_VChar_Ptrs
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_SHORT,
                               X_PVCHAR[]);

X_VOID_FUNCTION  X_Clear_Messages( struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   X_BOOL);


X_SHORT_FUNCTION  X_First_Message( struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   X_PVCHAR,
                                   X_PVCHAR,
                                   X_PVCHAR,
                                   X_PCHAR);

X_SHORT_FUNCTION  X_Next_Message( struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_CHAR,
                                  X_PCHAR);

X_SHORT_FUNCTION  X_Last_Message( struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_PCHAR,
                                  X_BOOL );

X_VOID_FUNCTION  X_Handle_Message_Ex ( struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD[],
                                    X_CHAR,
                                    X_CHAR,
                                    X_PVCHAR,
                                    X_PVCHAR,
                                    X_PVCHAR,
                                    X_SHORT,
                                    X_SHORT,
                                    X_SHORT[],
                                    X_BOOL );

X_VOID_FUNCTION  X_Handle_Message ( struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_FLD[],
                                    X_CHAR,
                                    X_CHAR,
                                    X_PVCHAR,
                                    X_PVCHAR,
                                    X_PVCHAR,
                                    X_SHORT,
                                    X_SHORT,
                                    X_SHORT[] );

X_VOID_FUNCTION  X_Handle_Message_Abort ( struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          struct X_FLD[],
                                          X_CHAR,
                                          X_CHAR,
                                          X_PVCHAR,
                                          X_PVCHAR,
                                          X_PVCHAR,
                                          X_SHORT,
                                          X_SHORT,
                                          X_SHORT[] );

X_VOID_FUNCTION  X_Get_Message_Text_Extended
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_SHORT,
                               X_PSHORT,
                               X_PVCHAR,
                               X_SHORT,
                               X_PSHORT,
                               X_PVCHAR);

X_PVCHAR_FUNCTION  X_Get_Text_String (X_LONG);

X_PVCHAR_FUNCTION  X_Get_Text_String_NoId (X_LONG);

X_VOID_FUNCTION   X_Save_Ids_Pointer (struct X_IDS *);

X_VOID_FUNCTION   X_Drop_Ids_Pointer (X_VOID);

struct X_IDS * X_FUNTYPE  X_Get_Ids_Pointer (X_VOID);

X_VOID_FUNCTION  X_Compress ( struct   X_IDS *,
                              struct   X_PRO *,
                              struct   X_FUN *,
                              X_SHORT  sInputLength,
                              X_PFCHAR pfchInputData,
                              X_PSHORT psOutputLength,
                              X_PFCHAR pfchOutputData);

X_VOID_FUNCTION  X_Decompress (  struct   X_IDS *,
                                 struct   X_PRO *,
                                 struct   X_FUN *,
                                 X_PFCHAR pfchInputData,
                                 X_PSHORT psOutputLength,
                                 X_PFCHAR pfchOutputData);

X_VOID_FUNCTION  X_Yield_to_Component_Manager ( struct   X_IDS *,
                                                struct   X_PRO *,
                                                struct   X_FUN * );

#ifdef X_OPERATING_SYSTEM_ISERIES
X_VOID_FUNCTION  X_Map_Messages_to_iSeries_RDML(struct X_IDS *,
                                                struct X_PRO *,
                                                struct X_FUN *,
                                                X_CHAR);
X_VOID_FUNCTION  X_Map_Messages_from_iSeries_RDML(struct X_IDS *,
                                                  struct X_PRO *,
                                                  struct X_FUN *);
#endif
/* ================================================================= */
/*  X_FUN5.C functions                                               */
/* ================================================================= */
#if defined(X_OPERATING_SYSTEM_ISERIES)
X_BOOL_FUNCTION X_Get_Message_Iseries( struct X_IDS *pX_Ids,
                                       struct X_PRO *pX_Pro,
                                       struct X_FUN *pX_Fun,
                                       X_PCCHAR      pvchMsgF,
                                       X_PCCHAR      pvchMsgId,
                                       X_PVCHAR      pvchMsg,
                                       X_PVCHAR      pvchHlpMsg,
                                       X_PVCHAR      pvchMsgsub);
#endif

X_VOID_FUNCTION  X_Get_Message_Text
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_SHORT,
                               X_PSHORT,
                               X_PVCHAR,
                               X_SHORT,
                               X_PSHORT,
                               X_PVCHAR);

X_VOID_FUNCTION  X_Get_Message_Text_Fixed
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_PCCHAR,
                               X_SHORT,
                               X_PSHORT,
                               X_PVCHAR,
                               X_SHORT,
                               X_PSHORT,
                               X_PVCHAR);

X_YES_NO_FUNCTION X_Check_Authority
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_PVCHAR);

X_VOID_FUNCTION  X_Get_Field_Label(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR);

X_BOOL_FUNCTION  X_Get_ML_Text(struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              X_PVCHAR,
                              X_PVCHAR,
                              X_PCHAR);

X_BOOL_FUNCTION X_Get_ML_Text_Ex( struct X_IDS  *  pX_Ids,
                                  struct X_PRO  *  pX_Pro,
                                  struct X_FUN  *  pX_Fun,
                                  X_PVCHAR         pvchMText,
                                  X_PVCHAR         pvchLang,
                                  X_PVCHAR         pvchValue,
                                  X_PCHAR          pchOpt,
                                  X_BOOL           fGetDefaultValue );

X_VOID_FUNCTION X_Initialise_Ids(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *);

X_LONG_FUNCTION X_Get_Data_Area( struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 X_PVCHAR,
                                 X_PVCHAR,
                                 X_CHAR,
                                 X_PCHAR,
                                 X_PVCHAR,
                                 X_ULONG );

X_VOID_FUNCTION  X_Put_Data_Area( struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_CHAR,
                                  X_CHAR,
                                  X_PVCHAR,
                                  X_ULONG );

#if defined(X_OPERATING_SYSTEM_ISERIES)
X_BOOL_FUNCTION X_Get_Data_Area_Native(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_PVCHAR,
                                       X_PVCHAR,
                                       X_CHAR,
                                       X_PCHAR,
                                       X_PVCHAR,
                                       X_ULONG);

X_BOOL_FUNCTION X_Get_Data_Area_as_Vchar( struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          X_PVCHAR,
                                          X_PVCHAR,
                                          X_PVCHAR,
                                          X_SHORT,
                                          X_SHORT);

X_YES_NO_FUNCTION X_Check_Authority_OAM_IS
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_YES_NO *);

#endif

X_PVCHAR_FUNCTION X_Lock_Object(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_CHAR,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_PVCHAR);

X_PVCHAR_FUNCTION X_Unlock_Object(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_CHAR);

X_VOID_FUNCTION  X_Unlock_Temp_Object(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_CHAR);

X_VOID_FUNCTION  X_Get_Description(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_SHORT,
                                  X_PVCHAR);

X_VOID_FUNCTION   X_Prompt_Field (X_SHORT,
                                 struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_PANEL_CTL *,
                                 X_SHORT,
                                 struct X_FLD [],
                                 struct X_COND [],
                                 struct X_FKEY [],
                                 X_SHORT,
                                 struct X_ABAR [],
                                 X_SHORT,
                                 struct X_PANEL_TXT [],
                                 X_SHORT,
                                 struct X_PANEL_FLD [],
                                 X_SHORT,
                                 struct X_FLD [],
                                 X_SHORT,
                                 struct X_PANEL_FLD [],
                                 struct X_COND [],
                                 PX_LIST_VOID,
                                 X_SHORT,
                                 X_SHORT,
                                 X_SHORT []);

X_VOID_FUNCTION  X_Get_Field_Description
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               X_PVCHAR);

X_YES_NO_FUNCTION X_Get_Field_Definition
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_PVCHAR,
                               struct X_FIELD_DEFINITION *,
                               X_PFCHAR,
                               X_PFCHAR);

X_SHORT_FUNCTION X_Load_Languages
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *);

X_VOID_FUNCTION  X_Free_Languages
                              (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *);

X_LONG_FUNCTION X_Commit_DBMS (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_DBM *);

X_LONG_FUNCTION X_Rollback_DBMS (struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_DBM *);

X_VOID_FUNCTION X_FUNRTR_Create (struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *);

X_VOID_FUNCTION  X_FUNRTR_Destroy (struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *);

X_VOID_FUNCTION  X_FUNRTR_Locate (struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR,
                                  X_PVCHAR);

X_YES_NO_FUNCTION X_FUNRTR_Unformat(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    X_PVCHAR,
                                    X_PVCHAR,
                                    X_PVCHAR);

X_YES_NO_FUNCTION X_FUNRTR_Validate_Line(struct X_IDS *,
                                         struct X_PRO *,
                                         struct X_FUN *,
                                         X_PVCHAR,
                                         X_PLONG,
                                         X_PLONG,
                                         X_PVCHAR,
                                         X_PVCHAR);

X_PVOID_FUNCTION  X_Get_Object_ID( struct X_IDS * ,
                                   struct X_PRO * ,
                                   struct X_FUN * ,
                                   X_OBJ_ID_TABLE *,
                                   X_LONG );

X_BOOL_INTERNAL_FUNCTION X_CheckSupGroupProfiles( struct X_IDS *pX_Ids );

X_LONG_FUNCTION X_GetLX_FSVMasterName( struct X_IDS * pX_Ids,
                                 struct X_PRO * pX_Pro,
                                 struct X_FUN * pX_Fun,
                                 X_BOOL fRefresh,
                                 X_PVCHAR pvchServerName );

X_LONG_FUNCTION X_GetServerName( struct X_IDS * pX_Ids,
                                 struct X_PRO * pX_Pro,
                                 struct X_FUN * pX_Fun,
                                 X_PVCHAR pvchServerName,
                                 X_BOOL   fSetDefault );

X_LONG_FUNCTION X_GetMasterNameNoDefault( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          X_PVCHAR pvchServerName );

X_VOID_FUNCTION X_Reset_AuditUser( struct X_IDS  *pX_Ids );


/* ================================================================= */
/*  X_FUN6.C   functions                                             */
/* ================================================================= */

X_VOID_FUNCTION  X_Quote_String_Ex(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   X_PVCHAR,
                                   X_SHORT,
                                   X_BOOL);

X_VOID_FUNCTION  X_Quote_String(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                X_PVCHAR,
                                X_SHORT);

X_VOID_FUNCTION  X_Remove_Blanks(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                X_PVCHAR,
                                X_USHORT);

X_BOOL_FUNCTION  X_Check_VN(struct X_IDS *,
                            struct X_PRO *,
                            struct X_FUN *,
                            X_PCCHAR,
                            X_PSHORT );

X_VOID_FUNCTION  X_Get_Valid_SQL_Name(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_PFCHAR,
                                     X_PVCHAR);

X_VOID_FUNCTION  X_Put_Stamp_Attribute(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD [],
                                      X_SHORT,
                                      X_PVCHAR,
                                      X_TYPE_FLAG);

X_VOID_FUNCTION  X_Reverse_String(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 X_PFCHAR,
                                 X_SHORT);

X_VOID_FUNCTION X_Replace_Chars(struct X_IDS *pX_Ids,
                                struct X_PRO *pX_Pro,
                                struct X_FUN *pX_Fun,
                                X_CHAR        chSearchFor,
                                X_CHAR        chReplaceWith,
                                X_PVCHAR      pvchString);

X_VOID_FUNCTION  X_Create_DBMS_Details (struct X_IDS * pX_Ids);

X_VOID_FUNCTION  X_Destroy_DBMS_Details (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_Create_DBMSInfo ( struct X_IDS * pX_Ids,
                                    struct X_CTD_DBMS_INFO **ppInfo,
                                    X_PVCHAR       pvchDBMSType,
                                    X_PVCHAR       pvchFatalMessage,
                                    X_SHORT        sMessageBytes);
X_VOID_FUNCTION X_Destroy_DBMSInfo ( struct X_IDS * pX_Ids,
                                     struct X_CTD_DBMS_INFO **ppInfo );

X_BOOL_FUNCTION X_Valid_DBMS_Type(struct X_IDS * pX_Ids,
                                  X_PVCHAR       pvchDBMSType);

X_BOOL_FUNCTION X_EXPR_Open (struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             X_PVCHAR                  pvchFileName,
                             struct X_CTD_EXPR_FILE ** ppEXPR,
                             X_ULONG                   ulOpenFor);

X_BOOL_FUNCTION X_EXPR_Close (struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_CTD_EXPR_FILE ** ppEXPR);

X_ULONG_FUNCTION X_EXPR_Write (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_CTD_EXPR_FILE * pEXPR);

X_ULONG_FUNCTION X_EXPR_Read (struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_CTD_EXPR_FILE * pEXPR);

X_ULONG_FUNCTION X_Get_Table_Columns (struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      X_PVCHAR       pvchSystemTableName,
                                      X_PVCHAR       pvchExtension,
                                      X_BOOL         fIsRepositoryTable,
                                      X_PLONG        plTotalColumns,
                                      struct X_CTD_COLUMN_DEFINITION * pColumn);

X_VOID_FUNCTION  X_Record_Removeable_File(struct X_IDS *,
                                          struct X_PRO *,
                                          struct X_FUN *,
                                          X_PVCHAR pvchFileName,
                                          X_BOOL   fIssueMessage);

X_LONG_FUNCTION  X_Destroy_Removeable_Files(struct X_IDS *,
                                            struct X_PRO *,
                                            struct X_FUN *,
                                            PFNGENLPURP pfnMessageCallback,
                                            X_PVCHAR    pvchMessage);

struct X_CONNECT_DATABASE * X_FUNTYPE X_Locate_Database_SSN (struct X_IDS *pX_Ids,
                                                   struct X_PRO *pX_Pro,
                                                   struct X_FUN *pX_Fun,
                                                   X_PVCHAR pvchSSN);

struct X_CONNECT_DATABASE * X_FUNTYPE X_Locate_Database_Type(struct X_IDS *pX_Ids,
                                                   struct X_PRO *pX_Pro,
                                                   struct X_FUN *pX_Fun,
                                                   X_PVCHAR pvchType);


struct X_CONNECT_DATABASE * X_FUNTYPE X_Add_Database_SSN( struct X_IDS *pX_Ids,
                                                        struct X_PRO *pX_Pro,
                                                        struct X_FUN *pX_Fun,
                                                        struct X_CONNECT_DATABASE *pDB,
                                                        X_PVCHAR pvchSSN);

struct X_CONNECT_DATABASE * X_FUNTYPE X_Add_Local_Database_SSN( struct X_IDS *pX_Ids,
                                                     struct X_PRO *pX_Pro,
                                                     struct X_FUN *pX_Fun,
                                                     struct X_CONNECT_DATABASE *pDB);

struct X_CONNECT_DATABASE * X_FUNTYPE X_Add_Remote_Database_SSN( struct X_IDS *pX_Ids,
                                                        struct X_PRO *pX_Pro,
                                                        struct X_FUN *pX_Fun,
                                                        struct X_CONNECT_DATABASE *pDB);
X_VOID_FUNCTION X_Check_Database_SSN(struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     struct X_DBM *pX_DBM,
                                     X_BOOL fExternal,
                                     struct X_CONNECT_DATABASE *pConnectDB);

X_VOID_FUNCTION X_Check_File_Redirected(struct X_IDS *pX_Ids,
                                        struct X_PRO *pX_Pro,
                                        struct X_FUN *pX_Fun,
                                        struct X_DBM *pX_DBM,
                                           X_PVCHAR);

X_VOID_FUNCTION X_Drop_Database_Connects (struct X_IDS *pX_Ids,
                                          struct X_PRO *pX_Pro,
                                          struct X_FUN *pX_Fun);

X_PVOID_FUNCTION X_Create_Database_Connect(  struct X_IDS *pX_Ids,
                                            struct X_PRO *pX_Pro,
                                            struct X_FUN *pX_Fun );

X_PVOID_FUNCTION X_Locate_Database_Connect( struct X_IDS *pX_Ids,
                                            struct X_PRO *pX_Pro,
                                            struct X_FUN *pX_Fun,
                                            X_PVCHAR pvchDBID );

X_LONG_FUNCTION X_Commit_All_DB_Servers(struct X_IDS *pX_Ids,
                            struct X_PRO *pX_Pro,
                            struct X_FUN *pX_Fun,
                            struct X_DBM *pX_DBM);

X_LONG_FUNCTION X_Rollback_All_DB_Servers(struct X_IDS *pX_Ids,
                            struct X_PRO *pX_Pro,
                            struct X_FUN *pX_Fun,
                            struct X_DBM *pX_DBM);

X_VOID_FUNCTION X_EscapeSQLWildcards( struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun,
                                      struct X_CTD_DBMS_INFO *pDBMSInfo,
                                      X_PVCHAR      pvchString,
                                      X_SHORT       sLength,
                                      X_BOOL        fEscPercent,
                                      X_BOOL        fEscUnder,
                                      X_BOOL        fEscEscape,
                                      X_CHAR        chDBCSCapable,
                                      X_PVCHAR      pvchEscapeClause,
                                      X_SHORT       sEscapeLength);

X_VOID_FUNCTION X_EscapeSQLWildcards_2( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        struct X_CTD_DBMS_INFO *  pDBMSInfo,
                                        X_PVCHAR         pvchString,
                                        X_LONG           lLength,
                                        X_BOOL           fEscPercent,
                                        X_BOOL           fEscUnder,
                                        X_BOOL           fEscEscape,
                                        X_CHAR           chDBCSCapable,
                                        X_PVCHAR         pvchEscapeClause,
                                        X_SHORT          sEscapeLength );

X_VOID_FUNCTION X_Batch_Control_2(
                                struct X_IDS *pX_Ids,
                                struct X_PRO *pX_Pro,
                                struct X_FUN *pX_Fun,
                                struct X_DBM *pX_DBM,
                                struct X_FLD  X_Fld[],
                                struct X_FLD  X_FldPrev[],
                                X_SHORT       scX_BCF,
                                X_SHORT       psX_BCF[],
                                X_SHORT       scX_BCK,
                                X_SHORT       psX_BCK[],
                                X_PVCHAR      pvchTable,
                                X_PVCHAR      pvchLibrary,
                                struct X_FLD  X_FldControl[],
                                X_SHORT       scX_FldControl,
                                X_SHORT       psX_FldControl[],
                                X_SHORT       scX_BCC,
                                X_SHORT       psX_BCC[],
                                X_SHORT       scX_KeyControl,
                                X_SHORT       psX_KeyControl[],
                                X_YES_NO      chCreateRecord,
                                X_PVOID       pSqlda,
                                X_PVCHAR      pvchSelect,
                                X_PVCHAR      pvchUpdate,
                                X_PVCHAR      pvchInsert,
                                X_CHAR        chType,
                                X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_Batch_Control_3(
                                struct X_IDS *pX_Ids,
                                struct X_PRO *pX_Pro,
                                struct X_FUN *pX_Fun,
                                struct X_DBM *pX_DBM,
                                struct X_FLD  X_Fld[],
                                struct X_FLD  X_FldPrev[],
                                X_SHORT       scX_BCF,
                                X_SHORT       psX_BCF[],
                                X_SHORT       scX_BCK,
                                X_SHORT       psX_BCK[],
                                X_PVCHAR      pvchTable,
                                X_PVCHAR      pvchLibrary,
                                struct X_FLD  X_FldControl[],
                                X_SHORT       scX_FldControl,
                                X_SHORT       psX_FldControl[],
                                X_SHORT       scX_BCC,
                                X_SHORT       psX_BCC[],
                                X_SHORT       scX_KeyControl,
                                X_SHORT       psX_KeyControl[],
                                X_YES_NO      chCreateRecord,
                                X_PVOID       pSqlda,
                                X_PVCHAR      pvchSelect,
                                X_PVCHAR      pvchUpdate,
                                X_PVCHAR      pvchInsert,
                                X_CHAR        chType,
                                X_CHAR        chLANSADefName,
                                X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_Batch_Control_4(
                                struct X_IDS *pX_Ids,
                                struct X_PRO *pX_Pro,
                                struct X_FUN *pX_Fun,
                                struct X_DBM *pX_DBM,
                                struct X_FLD  X_Fld[],
                                struct X_FLD  X_FldPrev[],
                                X_SHORT       scX_BCF,
                                X_SHORT       psX_BCF[],
                                X_SHORT       scX_BCK,
                                X_SHORT       psX_BCK[],
                                X_PVCHAR      pvchTable,
                                X_PVCHAR      pvchLibrary,
                                struct X_FLD  X_FldControl[],
                                X_PVCHAR     *ppvchAlternateNames,
                                X_SHORT       scX_FldControl,
                                X_SHORT       psX_FldControl[],
                                X_SHORT       scX_BCC,
                                X_SHORT       psX_BCC[],
                                X_SHORT       scX_KeyControl,
                                X_SHORT       psX_KeyControl[],
                                X_YES_NO      chCreateRecord,
                                X_PVOID       pSqlda,
                                X_PVCHAR      pvchSelect,
                                X_PVCHAR      pvchUpdate,
                                X_PVCHAR      pvchInsert,
                                X_CHAR        chType,
                                X_CHAR        chLANSADefName,
                                X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_Derive_PJF(
                                 struct X_IDS *pX_Ids,
                                 struct X_PRO *pX_Pro,
                                 struct X_FUN *pX_Fun,
                                 struct X_FLD  X_Fld[],
                                 struct X_DBM *pX_DBM,
                                 X_SHORT       scTgtFlds,
                                 X_SHORT       psTgtFlds[],
                                 X_PFCHAR      pchTgtFldsSREV,
                                 X_SHORT       scX_AccKeys,
                                 X_SHORT       psX_AccKeys[],
                                 X_PFCHAR      pchX_AccKeysSREV,
                                 X_PVCHAR      pvchTable,
                                 X_PVCHAR      pvchLibrary,
                                 X_PVCHAR      pvchAccessKeys,
                                 X_PVCHAR      pvchSelect,
                                 X_CHAR        chAction,
                                 X_CHAR        chType,
                                 X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_Derive_PJF_2( struct X_IDS *  pX_Ids,
                                struct X_PRO *  pX_Pro,
                                struct X_FUN *  pX_Fun,
                                struct X_FLD    X_Fld[],
                                struct X_DBM *  pX_DBMParent,
                                X_SHORT         scTgtFlds,
                                X_SHORT         psTgtFlds[],
                                X_PFCHAR        pchTgtFldsSREV,
                                X_SHORT         scX_AccKeys,
                                X_SHORT         psX_AccKeys[],
                                X_PFCHAR        pchX_AccKeysSREV,
                                X_PVCHAR        pvchTable,
                                X_PVCHAR        pvchLibrary,
                                X_PVCHAR        pvchAccessKeys,
                                X_SHORT         sAccessKeyLen,
                                X_SHORT         psX_AccTgtKeys[],
                                X_PVCHAR        pvchSelect,
                                X_CHAR          chAction,
                                X_CHAR          chType,
                                X_PYES_NO       pchReturn );

X_SHORT_FUNCTION X_Map_LOB_To_DBM(struct X_IDS         * pX_Ids,
                                  struct X_PRO         * pX_Pro,
                                  struct X_FUN         * pX_Fun,
                                  struct X_FLD         * pX_Fld,
                                  struct X_DBM         * pX_DBM,
                                  X_PVOID                pSqlda,
                                  X_PVCHAR               pvchTable,
                                  X_SHORT                sVec,
                                  X_SHORT                sFileCol,
                                  X_PVCHAR               pvchFileCol,
                                  X_SHORT                sTimestampCol,
                                  X_PVCHAR               pvchTimestampCol,
                                  X_PVCHAR               pvchLoadBase,
                                  X_PVCHAR               pvchFile,
                                  X_PVCHAR               pvchField,
                                  X_PVCHAR               pvchExclWhere);

X_SHORT_FUNCTION X_Map_LOB_To_DBM_2( struct X_IDS  *  pX_Ids,
                                     struct X_PRO  *  pX_Pro,
                                     struct X_FUN  *  pX_Fun,
                                     struct X_FLD  *  pX_Fld,
                                     struct X_DBM  *  pX_DBM,
                                     X_PVOID          pSqlda,
                                     X_PVCHAR         pvchTable,
                                     X_PVCHAR         pvchLobFile,
                                     X_SHORT          sVec,
                                     X_SHORT          sFileCol,
                                     X_PVCHAR         pvchFileCol,
                                     X_SHORT          sTimestampCol,
                                     X_PVCHAR         pvchTimestampCol,
                                     X_PVCHAR         pvchLoadBase,
                                     X_PVCHAR         pvchFile,
                                     X_PVCHAR         pvchField,
                                     X_PVCHAR         pvchExclWhere );

X_BOOL_FUNCTION X_Cleanup_LOB_Files( struct X_IDS         * pX_Ids,
                                     struct X_PRO         * pX_Pro,
                                     struct X_FUN         * pX_Fun,
                                     X_PVCHAR               pvchFile,
                                     X_PVCHAR               pvchField );

X_SHORT_FUNCTION X_Map_LOB_From_DBM(struct X_IDS         * pX_Ids,
                                    struct X_PRO         * pX_Pro,
                                    struct X_FUN         * pX_Fun,
                                    struct X_FLD         * pX_Fld,
                                    struct X_DBM         * pX_DBM,
                                    X_PVOID                pSqlda,
                                    X_SHORT                sCursorID,
                                    X_SHORT                sVec,
                                    X_SHORT                sLOBCol,
                                    X_SHORT                sFileCol,
                                    X_SHORT                sTstampCol,
                                    X_PVCHAR               pvchLOBDir,
                                    X_TYPE_FLAG            chAttrib,
                                    PX_LIST_VOID           pX_List,
                                    X_SHORT                sListNo);

X_BOOL_FUNCTION X_CreateLOBCursorDetails( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          struct X_DBM * pX_DBM,
                                          X_PVCHAR       pvchFile,
                                          X_PVCHAR       pvchField,
                                          X_SHORT        sCursorID,
                                          X_PVOID      * ppTreeEntry );

X_SHORT_FUNCTION X_RetrieveLOBCursorDetails( struct X_IDS * pX_Ids,
                                             struct X_PRO * pX_Pro,
                                             struct X_FUN * pX_Fun,
                                             struct X_DBM * pX_DBM,
                                             X_PVCHAR       pvchFile,
                                             X_PVCHAR       pvchField,
                                             X_PVOID        pCurrentEntry,
                                             X_PVOID      * ppTreeEntry  );

X_SHORT_FUNCTION X_UpdateLOBCursorDetails( struct X_IDS * pX_Ids,
                                           struct X_PRO * pX_Pro,
                                           struct X_FUN * pX_Fun,
                                           struct X_DBM * pX_DBM,
                                           X_PVCHAR       pvchFile,
                                           X_PVCHAR       pvchField,
                                           X_SHORT        sCursorID,
                                           X_PVOID        pCurrentEntry );

X_BOOL_FUNCTION X_RemoveLOBCursorDetails( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          struct X_DBM * pX_DBM,
                                          X_PVCHAR       pvchFile,
                                          X_PVCHAR       pvchField,
                                          X_BOOL         fRemoveAll,
                                          X_PVOID        pTreeEntry );

X_VOID_FUNCTION X_FreeAllLOBCursorDetails( struct X_IDS * pX_Ids );

X_BOOL_FUNCTION X_ValidLOBField( struct X_IDS         * pX_Ids,
                                 struct X_PRO         * pX_Pro,
                                 struct X_FUN         * pX_Fun,
                                 struct X_FLD         * pX_Fld,
                                 X_SHORT                sVec );

X_VOID_FUNCTION X_Get_Valid_C_Name_Len( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        X_PFCHAR         pvchInName,
                                        X_PVCHAR         pvchOutName,
                                        X_LONG           lMaxLen );

X_VOID_FUNCTION X_Get_Valid_SQL_Collection_Name( struct X_IDS  *  pX_Ids,
                                                 struct X_PRO  *  pX_Pro,
                                                 struct X_FUN  *  pX_Fun,
                                                 X_PFCHAR         pvchInName,
                                                 X_PVCHAR         pvchOutName );

X_ULONG_FUNCTION X_Update_CTD_Override_Library( struct X_IDS * pX_Ids,
                                                struct X_PRO * pX_Pro,
                                                struct X_FUN * pX_Fun,
                                                X_CHAR         chSearch,
                                                X_PVCHAR       pvchFile,
                                                X_PVCHAR       pvchLibrary,
                                                X_PVCHAR       pvchOverrideLib,
                                                X_PVCHAR       pvchPath );

X_ULONG_FUNCTION X_Read_CTD_File( struct X_IDS  *  pX_Ids,
                                  struct X_PRO  *  pX_Pro,
                                  struct X_FUN  *  pX_Fun,
                                  X_CHAR           chSearch,
                                  X_PVCHAR         pvchFile,
                                  X_PVCHAR         pvchLibrary,
                                  X_PVCHAR         pvchPath,
                                  X_PVOID          pParam1,
                                  X_PVOID          pParam2,
                                  PFNCALBACK       pfnCallback );

X_ULONG_FUNCTION X_Parse_CTD_Table( struct X_IDS  *  pX_Ids,
                                    struct X_PRO  *  pX_Pro,
                                    struct X_FUN  *  pX_Fun,
                                    struct X_CTD_TABLE_DEFINITION * pTable,
                                    X_PVOID          pParam,
                                    PFNCALBACK       pfnCallback );

/* ================================================================= */
/*  X_FUN7.C   functions                                             */
/* ================================================================= */

X_VOID_FUNCTION  X_Range_Check(struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_FLD [],
                              X_SHORT,
                              X_SHORT,
                              X_SHORT[],
                              X_CHAR,
                              X_CHAR,
                              X_PVCHAR,
                              X_PVCHAR,
                              X_SHORT,
                              X_SHORT[],
                              X_PCHAR);

X_VOID_FUNCTION  X_Values_Check(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_FLD [],
                               X_SHORT,
                               X_SHORT,
                               X_SHORT[],
                               X_CHAR,
                               X_CHAR,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_SHORT,
                               X_SHORT[],
                               X_PCHAR);

X_BOOL_FUNCTION  X_HSKC_Locate (struct X_IDS * pX_Ids,
                                struct X_PRO * pX_Pro,
                                struct X_FUN * pX_Fun,
                                X_PVCHAR       pvchAccessFile,
                                X_PVCHAR       pvchPhysicalFile,
                                X_USHORT       uscX_Key,
                                X_SHORT        asVec[],
                                struct X_FLD   X_Key[]);

X_VOID_FUNCTION    X_HSKC_Insert (struct X_IDS * pX_Ids,
                                  struct X_PRO * pX_Pro,
                                  struct X_FUN * pX_Fun,
                                  X_PVCHAR       pvchAccessFile,
                                  X_PVCHAR       pvchPhysicalFile,
                                  X_USHORT       uscX_Key,
                                  X_SHORT        asVec[],
                                  struct X_FLD   X_Key[]);


X_VOID_FUNCTION    X_HSKC_Drop   (struct X_IDS * pX_Ids,
                                  struct X_PRO * pX_Pro,
                                  struct X_FUN * pX_Fun,
                                  X_PVCHAR       pvchPhysicalFile);


X_VOID_FUNCTION  X_Code_File_Check(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_FLD [],
                                  X_SHORT,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_SHORT,
                                  X_SHORT[],
                                  X_CHAR,
                                  X_CHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_SHORT,
                                  X_SHORT[],
                                  X_PCHAR);

X_VOID_FUNCTION X_Code_File_Check_2(struct X_IDS *pX_Ids,
                                  struct X_PRO *pX_Pro,
                                  struct X_FUN *pX_Fun,
                                  struct X_DBM *pX_DBM,
                                  X_PVCHAR pvchIOModule,
                                  X_PVCHAR pvchFile,
                                  X_SHORT  sKeyValues,
                                  X_SHORT  sGVecs[],
                                  X_CHAR   chPosAct,
                                  X_CHAR   chNegAct,
                                  X_PVCHAR pvchMsgId,
                                  X_PVCHAR pvchMsgFile,
                                  X_SHORT  sSubsVar,
                                  X_SHORT  sSubVec[],
                                  X_PCHAR  pchResult);

X_VOID_FUNCTION  X_Date_Check(struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD [],
                             X_SHORT,
                             X_PVCHAR,
                             X_LONG,
                             X_LONG,
                             X_CHAR,
                             X_CHAR,
                             X_PVCHAR,
                             X_PVCHAR,
                             X_SHORT,
                             X_SHORT[],
                             X_PCHAR);

X_VOID_FUNCTION  X_Condition_Check(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_FLD [],
                                  X_SHORT,
                                  X_YES_NO,
                                  X_CHAR,
                                  X_CHAR,
                                  X_PVCHAR,
                                  X_PVCHAR,
                                  X_SHORT,
                                  X_SHORT[],
                                  X_PCHAR);


X_VOID_FUNCTION  X_Complex_Logic_Check(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     X_SHORT,
                                     X_PVCHAR,
                                     X_SHORT,
                                     X_SHORT[],
                                     X_CHAR,
                                     X_CHAR,
                                     X_PVCHAR,
                                     X_PVCHAR,
                                     X_SHORT,
                                     X_SHORT[],
                                     X_PCHAR);

X_VOID_FUNCTION X_Destroy_DD_Attributes (struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_Set_DD_Attributes (struct X_IDS * pX_Ids,
                                     struct X_PRO * pX_Pro,
                                     struct X_FUN * pX_Fun,
                                     X_PVCHAR       pvchId,
                                     X_SHORT        sStyle,
                                     X_SHORT        sLength);

X_VOID_FUNCTION X_Get_DD_Attributes (struct X_IDS * pX_Ids,
                                     X_PVCHAR       pvchId,
                                     X_PSHORT       psStyle,
                                     X_PSHORT       psLength);

X_PVOID_FUNCTION X_Create_Environment_Chain(struct X_IDS * pX_Ids,
                                            struct X_PRO * pX_Pro,
                                            struct X_FUN * pX_Fun,
                                            X_BOOL fShowLocates);

X_VOID_FUNCTION X_Destroy_Environment_Chain (struct X_IDS * pX_Ids,
                                             struct X_PRO * pX_Pro,
                                             struct X_FUN * pX_Fun,
                                             X_PVOID pEnvRoot);

X_VOID_FUNCTION X_Translate_Environment_String (struct X_IDS     * pX_Ids,
                                                struct X_PRO     * pX_Pro,
                                                struct X_FUN     * pX_Fun,
                                                X_PVOID            pEnv,
                                                X_PVCHAR           pvchLangCode,
                                                X_USHORT           usLength,
                                                X_PVCHAR           pvchString);

X_BOOL_FUNCTION  X_IsLeapYear( struct X_IDS  *  pX_Ids,
                               struct X_PRO  *  pX_Pro,
                               struct X_FUN  *  pX_Fun,
                               X_SHORT          sYear );

/* ================================================================= */
/*  X_FUN8.C   functions                                             */
/* ================================================================= */

X_VOID_FUNCTION X_Create_List_Instances (struct X_IDS  *  pX_Ids,
                                         struct X_PRO  *  pX_Pro,
                                         struct X_FUN  *  pX_Fun,
                                         X_SHORT          sLists,
                                         X_LIST_VOID *  pSrcList,
                                         struct X_LIST ** ppTgtList);

X_VOID_FUNCTION X_Create_List_Instances_2 (struct X_IDS  *  pX_Ids,
                                         struct X_PRO  *  pX_Pro,
                                         struct X_FUN  *  pX_Fun,
                                         X_SHORT          sLists1,
                                         X_LIST_1 *       pSrcList,
                                         X_SHORT          sLists2,
                                         X_LIST_2 *       pSrcList2,
                                         struct X_LIST ** ppTgtList);

X_VOID_FUNCTION X_Destroy_List_Instances (struct X_IDS  *  pX_Ids,
                                          struct X_PRO  *  pX_Pro,
                                          struct X_FUN  *  pX_Fun,
                                          X_SHORT          sLists,
                                          X_LIST_VOID *  pTgtList);

X_CHAR_FUNCTION X_Determine_Mode (struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_PVCHAR );

X_VOID_FUNCTION  X_Reset_Function_Mode (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD[],
                                       X_SHORT);

X_VOID_FUNCTION  X_Assemble_Entry  (struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_FLD[],
                                   X_SHORT,
                                   PX_LIST_VOID,
                                   X_YES_NO,
                                   X_CHAR,
                                   X_BOOL);

X_VOID_FUNCTION  X_Set_Error_States (struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD[],
                                     X_SHORT,
                                     PX_LIST_VOID,
                                     X_YES_NO);

X_CHAR_FUNCTION X_DisAssemble_Entry (struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD[],
                                     X_SHORT,
                                     PX_LIST_VOID,
                                     X_YES_NO *,
                                     X_YES_NO *,
                                     X_YES_NO);

X_VOID_FUNCTION  X_Upd_Entry (struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD [],
                             struct X_COND *,
                             X_SHORT,
                             PX_LIST_VOID,
                             X_CHAR,
                             X_YES_NO);

X_VOID_FUNCTION  X_Upd_Entry_UIM (struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_FLD [],
                                  struct X_COND *,
                                  X_SHORT,
                                  PX_LIST_VOID,
                                  X_LIST_COUNT,
                                  X_CHAR,
                                  X_YES_NO);

X_CHAR_FUNCTION X_Get_Entry (struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD[],
                             struct X_COND *,
                             X_LONG,
                             PX_LIST_VOID,
                             X_SHORT,
                             X_YES_NO,
                             X_YES_NO *);

X_CHAR_FUNCTION X_Get_Entry_2 (struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD[],
                             struct X_COND *,
                             X_LONG,
                             PX_LIST_VOID,
                             X_LIST_COUNT,
                             X_YES_NO,
                             X_YES_NO *);

X_CHAR_FUNCTION X_Get_Entry_Ext (struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD[],
                                struct X_COND *,
                                X_SHORT,
                                PX_LIST_VOID,
                                X_LIST_COUNT,
                                X_YES_NO,
                                X_YES_NO *,
                                X_BOOL );

X_VOID_FUNCTION X_Get_Entry_to_Entry(
   struct X_IDS         *     pX_Ids,
   struct X_PRO         *     pX_Pro,
   struct X_FUN         *     pX_Fun,
   struct X_FLD         *     pX_Fld,
   X_SHORT                    sListNo,
   PX_LIST_VOID               X_List,
   X_PCHAR                    pTargetEntry);

X_VOID_FUNCTION X_Dlt_Entry (struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_FLD[],
                             X_SHORT,
                             PX_LIST_VOID,
                             X_SHORT,
                             X_PLONG);

X_CHAR_FUNCTION X_Get_Entry_UIM (struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_FLD[],
                                 struct X_COND *,
                                 X_SHORT,
                                 PX_LIST_VOID,
                                 X_LIST_COUNT,
                                 X_YES_NO,
                                 X_YES_NO *);

X_VOID_FUNCTION  X_Add_Entry  (struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_FLD [],
                              struct X_COND *,
                              X_SHORT,
                              PX_LIST_VOID,
                              X_YES_NO,
                              X_YES_NO,
                              X_CHAR,
                              X_YES_NO);

X_VOID_FUNCTION  X_Add_Entry_After  (struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD [],
                                     struct X_COND *,
                                     X_SHORT,
                                     PX_LIST_VOID,
                                     X_YES_NO,
                                     X_YES_NO,
                                     X_CHAR,
                                     X_YES_NO,
                                     X_SHORT,
                                     X_PLONG);

X_VOID_FUNCTION X_Add_Entry_from_Entry(
   struct X_IDS         *     pX_Ids,
   struct X_PRO         *     pX_Pro,
   struct X_FUN         *     pX_Fun,
   struct X_FLD         *     pX_Fld,
   X_SHORT                    sListNo,
   PX_LIST_VOID               X_List,
   X_PCHAR                    pSourceEntry);


X_VOID_FUNCTION  X_Check_List_Usage (struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     X_SHORT,
                                     PX_LIST_VOID);

X_VOID_FUNCTION X_Sort_List ( struct X_IDS *pX_Ids,
                              struct X_PRO *pX_Pro,
                              struct X_FUN *pX_Fun,
                              struct X_FLD *pX_Fld,
                              X_SHORT sListNo,
                              PX_LIST_VOID X_List,
                              int (__cdecl *compare )(const void *elem1, const void *elem2 ) );


X_VOID_FUNCTION  X_Inz_Entries (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_FLD [],
                               struct X_COND *,
                               X_SHORT,
                               PX_LIST_VOID,
                               X_YES_NO,
                               X_YES_NO,
                               X_SHORT,
                               X_CHAR);


X_VOID_FUNCTION  X_Drop_Entries (struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD [],
                                X_SHORT,
                                PX_LIST_VOID,
                                X_YES_NO);

X_VOID_FUNCTION  X_Store_Entry (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               X_SHORT,
                               PX_LIST_VOID,
                               X_LIST_COUNT,
                               X_LIST_COUNT,
                               X_LONG);

X_CHAR_FUNCTION X_Retrieve_Entry (struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_SHORT,
                                  PX_LIST_VOID,
                                  X_LIST_COUNT);

X_VOID_FUNCTION  X_Allocate_Lists (struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_SHORT,
                                  PX_LIST_VOID);

X_VOID_FUNCTION  X_Deallocate_Lists (struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    X_SHORT,
                                    PX_LIST_VOID);

X_VOID_FUNCTION  X_Clear_Exchange_List(struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *);

X_VOID_FUNCTION  X_Receive_Exchange_List(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        X_SHORT,
                                        struct X_FLD[]);

X_SHORT_FUNCTION  X_Receive_Exchange_List_Entries( struct X_IDS *,
                                                   struct X_PRO *,
                                                   struct X_FUN *,
                                                   X_SHORT,
                                                   struct X_FLD[],
                                                   X_SHORT,
                                                   X_SHORT[] );

X_VOID_FUNCTION  X_Put_To_Exchange_List(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD[],
                                       X_SHORT,
                                       X_SHORT[]);

X_BOOL_FUNCTION X_List_Uses_LL2_Field_Type ( struct X_IDS *pX_Ids,
                                             struct X_PRO *pX_Pro,
                                             struct X_FUN *pX_Fun,
                                             PX_LIST_VOID  X_List,
                                             X_SHORT       sListNo);

X_YES_NO_FUNCTION X_Put_to_Exchange_from_String(struct X_IDS *,
                                                struct X_PRO *,
                                                struct X_FUN *,
                                                struct X_FLD *,
                                                X_SHORT,
                                                X_PVCHAR,
                                                X_SHORT);

X_PVOID_FUNCTION X_Search_in_LL2_Exchange_List (struct X_IDS    *,
                                                struct X_PRO   *,
                                                struct X_FUN   *,
                                                PX_EXCHL2,
                                                X_PVCHAR,
                                                X_PVOID *,
                                                PX_EXCHANGE_LIST_FIELD_INFO) ;

X_BOOL_FUNCTION X_Save_Exchange_List(  struct X_IDS      *,
                                       struct X_PRO      *,
                                       struct X_FUN      *,
                                       PX_EXCHL2         ,
                                       PX_SAVE_EXCHANGE_LIST_HEADER ,
                                       PPX_SAVE_EXCHANGE_LIST_FIELD *,
                                       X_UINT * ,
                                       X_BOOL  ,
                                       X_PVCHAR ,
                                       X_BOOL  );

X_VOID_FUNCTION X_Free_Saved_Exchange_List(  struct X_IDS  *,
                                             struct X_PRO  *,
                                             struct X_FUN  *,
                                             PX_SAVE_EXCHANGE_LIST_FIELD * ,
                                             X_UINT );

X_VOID_FUNCTION X_Restore_Exchange_List(  struct X_IDS  *,
                                          struct X_PRO  *,
                                          struct X_FUN  *,
                                          PX_SAVE_EXCHANGE_LIST_HEADER ,
                                          PPX_SAVE_EXCHANGE_LIST_FIELD ,
                                          X_UINT );

X_VOID_FUNCTION X_Read_LL2_Exch_List_From_File(  struct X_IDS      *,
                                                   struct X_PRO      *,
                                                   struct X_FUN      *,
                                                   X_PVCHAR ,
                                                   X_BOOL ,              /* Erase File     */
                                                   PX_SAVE_EXCHANGE_LIST_HEADER ,
                                                   PPX_SAVE_EXCHANGE_LIST_FIELD * ,
                                                   X_UINT *);

X_VOID_FUNCTION  X_Reset_List_Mode (struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   X_SHORT,
                                   PX_LIST_VOID,
                                   X_CHAR);

X_VOID_FUNCTION  X_Receive_Working_List (struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_FLD[],
                                        X_SHORT,
                                        PX_LIST_VOID,
                                        X_SHORT,
                                        X_SHORT,
                                        struct X_PARM[]);

X_VOID_FUNCTION  X_Return_Working_List (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_FLD[],
                                       X_SHORT,
                                       PX_LIST_VOID,
                                       X_SHORT,
                                       X_SHORT,
                                       struct X_PARM[]);

X_VOID_FUNCTION  X_Reset_List_Counter (struct X_IDS *,
                                      struct X_PRO *,
                                      struct X_FUN *,
                                      struct X_FLD[],
                                      X_SHORT,
                                      PX_LIST_VOID);

X_VOID_FUNCTION  X_Handle_Trigger_Info (struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_CHAR,
                                       struct X_FLD[],
                                       X_SHORT,
                                       PX_LIST_VOID,
                                       X_SHORT,
                                       X_SHORT,
                                       X_SHORT,
                                       struct X_PARM[]);

X_VOID_FUNCTION  X_Search_Last (struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_FLD [],
                               struct X_KEEP_LAST *,
                               X_SHORT,
                               X_SHORT[],
                               X_SHORT,
                               X_SHORT[],
                               X_PVCHAR);

X_VOID_FUNCTION  X_Store_Last (struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_FLD[],
                              struct X_KEEP_LAST *,
                              X_SHORT,
                              X_SHORT[],
                              X_SHORT,
                              X_SHORT[],
                              X_SHORT);
X_VOID_FUNCTION X_Free_Last ( struct X_IDS      *pX_Ids,
                              struct X_PRO      *pX_Pro,
                              struct X_FUN      *pX_Fun,
                              struct X_FLD       X_Fld[],
                              struct X_KEEP_LAST *pX_KLast,
                              X_SHORT            scX_Keys,
                              X_SHORT            X_Keys[],
                              X_SHORT            scX_Data,
                              X_SHORT            X_Data[] );

X_YES_NO_FUNCTION X_Locate_Data_Structure (struct X_IDS  *,
                                           struct X_PRO  *,
                                           struct X_FUN  *,
                                           X_PVCHAR,
                                           X_SHORT,
                                           X_PCHAR);

X_VOID_FUNCTION  X_Store_Data_Structure (struct X_IDS  *,
                                        struct X_PRO  *,
                                        struct X_FUN  *,
                                        X_PVCHAR,
                                        X_SHORT,
                                        X_PCHAR);

X_VOID_FUNCTION  X_Clear_Data_Structures (struct X_IDS  *,
                                         struct X_PRO  *,
                                         struct X_FUN  *);

X_VOID_FUNCTION X_Set_Component_List_Entry_Count ( struct X_IDS *pX_Ids,
                                                   struct X_PRO *pX_Pro,
                                                   struct X_FUN *pX_Fun,
                                                   struct X_FLD  X_Fld[],
                                                   PX_LIST_VOID,
                                                   X_SHORT       sListNo );


X_VOID_FUNCTION X_Receive_BIF_Args( struct X_IDS  * pX_Ids,
                                    struct X_PRO  * pX_Pro,
                                    struct X_FUN  * pX_Fun,
                                    X_SHORT         scX_Parm,
                                    struct X_PARM * pX_Parm,
                                    X_SHORT         scX_List,
                                    X_LIST_VOID * pX_List,
                                    X_SHORT         scX_Args,
                                    PX_BIFPARM      pX_Arg,
                                    X_SHORT         scX_Rets,
                                    PX_BIFPARM      pX_Ret );


X_VOID_FUNCTION X_Return_BIF_Rets( struct X_IDS  * pX_Ids,
                                   struct X_PRO  * pX_Pro,
                                   struct X_FUN  * pX_Fun,
                                   X_SHORT         scX_Parm,
                                   struct X_PARM * pX_Parm,
                                   X_SHORT         scX_List,
                                   X_LIST_VOID * pX_List,
                                   X_SHORT         scX_Args,
                                   PX_BIFPARM      pX_Arg,
                                   X_SHORT         scX_Rets,
                                   PX_BIFPARM      pX_Ret );

X_PVOID_FUNCTION X_WebGetFieldData( struct X_FLD *pField,
                                    X_PULONG pulDataSize,
                                    X_PBOOL pfIsXVar );

X_BOOL_FUNCTION X_WebAddFormVarToLL2ExchangeList( struct X_IDS *pX_Ids,
                                                  struct X_PRO *pX_Pro,
                                                  struct X_FUN *pX_Fun,
                                                  X_PCVOID pRequestInfo );

#ifdef X_OPERATING_SYSTEM_ISERIES
X_VOID_FUNCTION  X_Map_Exchange_List_to_iSeries_RDML(struct X_IDS *,
                                                     struct X_PRO *,
                                                     struct X_FUN *);
X_VOID_FUNCTION  X_Map_Exchange_List_from_iSeries_RDML(struct X_IDS *,
                                                       struct X_PRO *,
                                                       struct X_FUN *);
#endif
/* ================================================================= */
/*  X_FUN9.C   functions                                             */
/* ================================================================= */

struct X_PROCESS_INSTANCE  * X_FUNTYPE X_Create_Process_Instance
                         (struct  X_IDS               *  pX_Ids,
                          struct  X_PROCESS_INSTANCE ** ppX_RootPI,
                          struct  X_PROCESS_INSTANCE  *  pX_TemplatePI,
                          X_SHORT                       sLanguageNumber);

X_VOID_FUNCTION  X_Destroy_Process_Instance
                          (struct  X_IDS               *  pX_Ids,
                           struct  X_PROCESS_INSTANCE ** ppX_RootPI,
                           struct  X_PROCESS_INSTANCE  *  pX_CurrentPI);

struct X_GENERIC_INSTANCE  * X_FUNTYPE X_Create_Generic_Instance
                         (struct  X_IDS               *  pX_Ids,
                          struct  X_GENERIC_INSTANCE ** ppRootGI,
                          X_ULONG                       lTemplateGILen,
                          X_PVOID                       pTemplateGI);

X_VOID_FUNCTION  X_Destroy_Generic_Instance
                          (struct  X_IDS               *  pX_Ids,
                           struct  X_GENERIC_INSTANCE ** ppRootGI,
                           struct  X_GENERIC_INSTANCE   *  pCurrentGI);

X_VOID_FUNCTION  X_Make_Automatic_Connection (struct X_IDS *,
                                             struct X_PRO *,
                                             struct X_FUN *);

X_VOID_FUNCTION  X_Process_Run   (struct X_IDS *,
                                 struct X_PRO *,
                                 X_PVCHAR,
                                 X_SHORT,
                                 struct X_PARM [],
                                 X_SHORT,
                                 struct X_LANG [],
                                 X_SHORT,
                                 struct X_PROTEXT [],
                                 X_SHORT,
                                 struct X_PROFUNC [],
                                 X_SHORT,
                                 struct X_ABAR [],
                                 struct X_FKEY []);

X_VOID_FUNCTION  X_Function_Start (struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  X_SHORT,
                                  struct X_LANG []);

X_VOID_FUNCTION  X_Function_End (struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                X_YES_NO);

X_YES_NO_FUNCTION X_Loop_Function (struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *);

X_SHORT_FUNCTION X_Process_Get_Language (struct X_IDS *,
                                         struct X_PRO *,
                                         X_SHORT,
                                         struct X_LANG []);

X_PVCHAR_FUNCTION X_Process_Get_Text (struct X_IDS *,
                                      struct X_PRO *,
                                      X_SHORT,
                                      struct X_PROTEXT [],
                                      X_SHORT,
                                      X_SHORT,
                                      X_SHORT,
                                      X_SHORT);

X_VOID_FUNCTION  X_Process_End    (struct X_IDS *,
                                  struct X_PRO *,
                                  X_YES_NO);

X_VOID_FUNCTION  X_Process_Get_Next   (struct X_IDS *,
                                      struct X_PRO *,
                                      X_SHORT,
                                      struct X_PROFUNC []);

X_VOID_FUNCTION  X_Process_Validate_Next (struct X_IDS *,
                                         struct X_PRO *,
                                         X_SHORT,
                                         struct X_PROFUNC [],
                                         X_SHORT,
                                         struct X_ABAR []);

X_VOID_FUNCTION  X_Process_Menu   (struct X_IDS *,
                                  struct X_PRO *,
                                  X_SHORT,
                                  struct X_PROFUNC [],
                                  X_SHORT,
                                  struct X_ABAR [],
                                  struct X_FKEY []);

X_VOID_FUNCTION  X_Process_Function (struct X_IDS *,
                                    struct X_PRO *,
                                    X_SHORT,
                                    struct X_PROFUNC [],
                                    X_SHORT,
                                    struct X_ABAR [],
                                    struct X_FKEY [],
                                    X_SHORT,
                                    struct X_PARM []);

X_VOID_FUNCTION  X_Process_Command (struct X_IDS *,
                                   struct X_PRO *,
                                   X_SHORT,
                                   struct X_PROFUNC []);

X_VOID_FUNCTION  X_Process_External (struct X_IDS *,
                                    struct X_PRO *,
                                    X_SHORT,
                                    struct X_PROFUNC [],
                                    X_SHORT,
                                    struct X_PARM []);

X_VOID_FUNCTION  X_Process_Help (struct X_IDS *,
                                struct X_PRO *,
                                struct X_FKEY []);

X_VOID_FUNCTION   X_Present_Panel (X_SHORT,
                                  struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_PANEL_CTL *,
                                  X_SHORT,
                                  struct X_FLD [],
                                  struct X_COND [],
                                  struct X_FKEY [],
                                  X_SHORT,
                                  struct X_ABAR [],
                                  X_SHORT,
                                  struct X_PANEL_TXT [],
                                  X_SHORT,
                                  struct X_PANEL_FLD [],
                                  X_SHORT,
                                  struct X_FLD [],
                                  X_SHORT,
                                  struct X_PANEL_FLD [],
                                  struct X_COND [],
                                  struct X_LIST [],
                                  X_SHORT,
                                  X_SHORT,
                                  X_SHORT []);

X_VOID_FUNCTION  X_Compute_Keys (struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD[],
                                struct X_DBM *);

X_VOID_FUNCTION  X_Check_Key_Count (struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_FLD[],
                                   struct X_DBM *,
                                   X_SHORT);

X_VOID_FUNCTION X_Connect_LansaPC  (struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun);

X_VOID_FUNCTION X_Connect_LansaPCEx(struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_BOOL,
                                    X_BOOL );

X_VOID_FUNCTION X_DisConnect_LansaPC  (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);

X_VOID_FUNCTION X_Create_Edit_Proc    (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);

X_VOID_FUNCTION X_Destroy_Edit_Proc   (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);

X_VOID_FUNCTION X_Kill_Proc_Edit      (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PVCHAR       pvchMessageId,
                                       X_SHORT        scSubVar,
                                       X_PVCHAR       apvchSubVar[]);

X_VOID_FUNCTION X_Kill_File_Edit      (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PVCHAR       pvchMessageId,
                                       X_SHORT        scSubVar,
                                       X_PVCHAR       apvchSubVar[]);


X_VOID_FUNCTION X_Create_Edit_File    (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);

X_VOID_FUNCTION X_Destroy_Edit_File   (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);

X_BOOL_FUNCTION X_LansaPC_Validate_Name( struct X_IDS *  pX_Ids,
                                         struct X_PRO *  pX_Pro,
                                         struct X_FUN *  pX_Fun,
                                         X_PVCHAR        pvchObjectName,
                                         X_PVCHAR        pvchObjectType,
                                         X_SHORT         sObjectType );

X_BOOL_FUNCTION X_LansaPC_Can_I_Do_This( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          X_PCCHAR       pvchObjectName,
                                          X_PCCHAR       pvchObjectNameExtension,
                                          X_USHORT       usObjectType,
                                          X_USHORT       usRequestedActivity);

X_BOOL_FUNCTION X_LansaPC_Validate_Passwd( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          X_PVCHAR       pvchPassword);


X_BOOL_FUNCTION X_LansaPC_Can_I_Do_This_Query(struct X_IDS * pX_Ids,
                                              struct X_PRO * pX_Pro,
                                              struct X_FUN * pX_Fun,
                                              X_PCCHAR       pvchObjectName,
                                              X_PCCHAR       pvchObjectNameExtension,
                                              X_USHORT       usObjectType,
                                              X_USHORT       usRequestedActivity);

X_BOOL_FUNCTION X_LansaPC_Release_Dev_Lock(struct X_IDS * pX_Ids,
                                              struct X_PRO * pX_Pro,
                                              struct X_FUN * pX_Fun,
                                              X_PVCHAR       pvchObjectName,
                                              X_PVCHAR       pvchObjectNameExtension,
                                              X_PVCHAR       pvchObjectType,
                                              X_USHORT       usLockType);

X_BOOL_FUNCTION X_LansaPC_I_Just_Did_This( struct X_IDS * pX_Ids,
                                           struct X_PRO * pX_Pro,
                                           struct X_FUN * pX_Fun,
                                           X_PCCHAR       pvchObjectName,
                                           X_PCCHAR       pvchObjectNameExtension,
                                           X_USHORT       usObjectType,
                                           X_PCCHAR       pvchObjectDescription,
                                           X_USHORT       usPerformedActivity,
                                           X_USHORT       usObjectAuthority );


X_BOOL_FUNCTION X_FUN_IsDevEnvironment( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun );

X_BOOL_FUNCTION X_FUN_IsSystemOwner( struct X_IDS  *  pX_Ids,
                                     struct X_PRO  *  pX_Pro,
                                     struct X_FUN  *  pX_Fun );

X_BOOL_FUNCTION X_FUN_SendMessageToDev( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        X_ULONG          ulMessage );

X_BOOL_FUNCTION X_LansaPC_Dongle_Check( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun );

X_BOOL_FUNCTION X_LansaPC_Lic_Check( struct X_IDS * pX_Ids,
                                     struct X_PRO * pX_Pro,
                                     struct X_FUN * pX_Fun,
                                     X_USHORT TestLic );

X_VOID_FUNCTION X_LansaPC_Clear_Template_Answers( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          X_PVCHAR pvchProcessName,
                                          X_PVCHAR pvchFunctionName );

X_BOOL_FUNCTION X_LansaPC_Delete_Process( struct X_IDS * pX_Ids,
                                          struct X_PRO * pX_Pro,
                                          struct X_FUN * pX_Fun,
                                          X_PVCHAR pvchProcessName);

X_BOOL_FUNCTION X_LansaPC_Delete_Field( struct X_IDS * pX_Ids,
                                        struct X_PRO * pX_Pro,
                                        struct X_FUN * pX_Fun,
                                        X_PVCHAR pvchFieldName);

X_BOOL_FUNCTION X_LansaPC_Delete_File( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PVCHAR pvchFileName,
                                       X_PVCHAR pvchLibrary);

X_VOID_FUNCTION X_Issue_LansaPC_Messages( struct X_IDS *pX_Ids,
                                             struct X_PRO *pX_Pro,
                                             struct X_FUN *pX_Fun );

X_BOOL_FUNCTION X_LansaPC_Get_Next_Rule_Ptr( struct X_IDS * pX_Ids,
                                             struct X_PRO * pX_Pro,
                                             struct X_FUN * pX_Fun,
                                             X_PVCHAR       pvchRulePtr );
X_LONG_FUNCTION X_LansaPC_Check_Out( struct X_IDS *pX_Ids,
                                     struct X_PRO *pX_Pro,
                                     struct X_FUN *pX_Fun,
                                     X_PVCHAR pvchObjectType,
                                     X_BOOL   fUpdate,
                                     X_PVCHAR pvchObjectName,
                                     X_PVCHAR pvchObjectExt,
                                     X_PVCHAR pvchIOV,
                                     X_PVCHAR pvchSEN );

X_BOOL_FUNCTION X_LansaPC_Tidy_Host_Monitor(struct X_IDS *pX_Ids,
                                            struct X_PRO *pX_Pro,
                                            struct X_FUN *pX_Fun,
                                            X_SHORT sRSMID );

X_LONG_FUNCTION X_LansaPC_HM_Request( struct X_IDS *pX_Ids,
                                      struct X_PRO *pX_Pro,
                                      struct X_FUN *pX_Fun,
                                      X_PVCHAR pvchServer,
                                      X_PVCHAR pvchWorkstation,
                                      X_LONG   lJobNumber,
                                      X_PVCHAR pvchRequest,
                                      X_PVCHAR pvchObjType,
                                      X_PVCHAR pvchObject,
                                      X_PVCHAR pvchExtension,
                                      X_PVCHAR pvchIOV,
                                      X_PVCHAR pvchSen,
                                      X_PVCHAR pvchOptList,
                                      X_LONG   lNbrOfOptions,
                                      X_PVCHAR pvchFunList,
                                      X_LONG   lNbrOfFunctions,
                                      X_PVCHAR pvchTraceString );

X_VOID_FUNCTION X_Execute_Component(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_Initialise_Component_Env(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_Terminate_Component_Env(struct X_IDS * pX_Ids);

X_VOID_FUNCTION X_Execute_WAM(struct X_IDS *pX_Ids, struct X_PRO *pX_Pro);

X_VOID_FUNCTION X_Execute_RDMLX_Function( struct X_IDS              * pX_Ids,
                                          struct X_PRO              * pX_Pro,
                                          X_PVCHAR                    pvchRequestorFunction,
                                          X_SHORT                     scX_Parm,
                                          struct X_PARM             * pX_Parm );


X_VOID_FUNCTION X_Run_Initialization_Function (struct X_IDS * pX_Ids,
                                               struct X_PRO * pX_Pro);


X_VOID_FUNCTION X_Run_Termination_Function (struct X_IDS * pX_Ids,
                                            struct X_PRO * pX_Pro);

X_VOID_FUNCTION X_Start_Call_RDML_from_RDMLX (struct X_IDS * pX_Ids,
                                              struct X_PRO * pX_Pro,
                                              struct X_FUN * pX_Fun,
                                              void        ** ppvTrackInfo);

X_VOID_FUNCTION X_End_Call_RDML_from_RDMLX (struct X_IDS * pX_Ids,
                                            struct X_PRO * pX_Pro,
                                            struct X_FUN * pX_Fun,
                                            void        ** ppvTrackInfo);

X_LONG_FUNCTION X_Start_Component_Routine ( struct X_IDS              * pX_Ids,
                                            struct X_PRO              * pX_Pro,
                                            struct X_FUN              * pX_Fun,
                                            PX_COMPONENT_ROUTINE_INFO   pRoutineInfo,
                                            X_ULONG                     ulNumberOptArgs,
                                            X_COMP_NEGOTIABLE_COMPONENT apvOptArgs[] );

X_LONG_FUNCTION X_Terminate_Component_Routine ( struct X_IDS              * pX_Ids,
                                                struct X_PRO              * pX_Pro,
                                                struct X_FUN              * pX_Fun,
                                                PX_COMPONENT_ROUTINE_INFO   pRoutineInfo,
                                                X_ULONG                     ulNumberOptArgs,
                                                X_COMP_NEGOTIABLE_COMPONENT apvOptArgs[] );

X_LONG_FUNCTION X_LansaPC_Func_Error_Free( struct X_IDS  *  pX_Ids,
                                           struct X_PRO  *  pX_Pro,
                                           struct X_FUN  *  pX_Fun,
                                           unsigned short   usArgs,
                                           void          *  (*papArgs[]) );

X_LONG_FUNCTION X_LansaPC_Func (struct X_IDS *pX_Ids,
                                struct X_PRO * pX_Pro,
                                struct X_FUN * pX_Fun,
                                unsigned short usArgs,
                                void *(*papArgs[]));

X_LONG_FUNCTION X_Object_Locking (struct X_IDS *pX_Ids,
                                  struct X_PRO * pX_Pro,
                                  struct X_FUN * pX_Fun,
                                  unsigned short usArgs,
                                  void *(*papArgs[]));

X_VOID_FUNCTION X_Release_CIDT_Object_Locking(struct X_IDS *pX_Ids,
                                              struct X_PRO *pX_Pro,
                                              struct X_FUN *pX_Fun,
                                              X_PVCHAR pvchObjectType,
                                              X_PVCHAR pvchObjectName,
                                              X_PVCHAR pvchObjectExt);

#if defined(X_OPERATING_SYSTEM_WIN)
X_VOID_FUNCTION X_SignalUIMWasActivated(   struct X_IDS * pX_Ids,
                                           struct X_PRO * pX_Pro,
                                           struct X_FUN * pX_Fun );
X_VOID_FUNCTION X_SignalUIMMayBeActivated( struct X_IDS * pX_Ids,
                                           struct X_PRO * pX_Pro,
                                           struct X_FUN * pX_Fun );
#endif


X_VOID_FUNCTION X_CreateDummyProcess( struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      X_PVCHAR       pvchName,
                                      X_PVCHAR       pvchDesc );

X_VOID_FUNCTION X_CreateDummyFunction( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun,
                                       X_PVCHAR       pvchName,
                                       X_PVCHAR       pvchDesc );

X_VOID_FUNCTION X_DestroyDummyFunction( struct X_IDS * pX_Ids,
                                        struct X_PRO * pX_Pro,
                                        struct X_FUN * pX_Fun );


X_VOID_FUNCTION X_DestroyDummyProcess( struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro );

X_VOID_FUNCTION X_FUN_Disconnect_COMP_DLL (struct X_IDS * pX_Ids);

X_ULONG_FUNCTION X_Get_Exchange_List_Item_Data_Size( struct X_IDS *  pX_Ids,
                                                     struct X_PRO *  pX_Pro,
                                                     struct X_FUN *  pX_Fun,
                                                     PX_SAVE_EXCHANGE_LIST_FIELD pSavedExchList[],
                                                     X_UINT uiTotalItems,
                                                     X_UINT uiIndex );

/* ================================================================= */
/*  X_FUN10.C   functions                                             */
/* ================================================================= */

X_VOID_FUNCTION X_InitGlobals(struct X_IDS *);

X_VOID_FUNCTION X_TermLastGlobals(struct X_IDS *pX_Ids);

X_VOID_FUNCTION X_InitWebInfo(
   struct X_WEB_INFO *pWebInfo, X_LONG lJobId,
   X_PCCHAR pvchIfsExt, X_BOOL fBatchDebug);

X_VOID_FUNCTION X_Trace(struct X_IDS *pX_Ids,
                        X_PCCHAR      pvchCFile,
                        const X_ULONG ulCLine,
                        X_PCCHAR      pvchCFunction,
                        const X_ULONG ulEventClass,
                        X_PCCHAR      pvchEventCategory,
                        const X_ULONG ulEventLevel,
                        X_PCCHAR      pvchText1,
                        X_PCCHAR      pvchText2,
                        X_PCCHAR      pvchText3);

X_VOID_FUNCTION X_Trace_Fixed(struct X_IDS *pX_Ids,
   X_PCCHAR      pvchCFile,
   const X_ULONG ulCLine,
   X_PCCHAR      pvchCFunction,
   const X_ULONG ulEventClass,
   X_PCCHAR      pvchEventCategory,
   const X_ULONG ulEventLevel,
   X_PCCHAR      pvchText1,
   X_PCCHAR      pfchFixed2,
   const X_LONGLONG ulFixed2,
   X_PCCHAR      pfchFixed3,
   const X_LONGLONG ulFixed3 );

X_VOID_FUNCTION X_Trace_Fun(struct X_IDS *pX_Ids,
                            struct X_PRO *pX_Pro,
                            struct X_FUN *pX_Fun,
                        X_PCCHAR      pvchCFile,
                        const X_ULONG ulCLine,
                        X_PCCHAR      pvchCFunction,
                        const X_ULONG ulEventClass,
                        X_PCCHAR      pvchEventCategory,
                        const X_ULONG ulEventLevel,
                        X_PCCHAR      pvchText1,
                        X_PCCHAR      pvchText2,
                        X_PCCHAR      pvchText3);

X_VOID_FUNCTION X_Trace_Start(struct X_IDS *pX_Ids);

X_VOID_FUNCTION X_Trace_End(struct X_IDS *pX_Ids);

X_LONG_FUNCTION X_LANSAX_Services(PX_COMP_SERVICES_POINT_REQUEST pRequestBlock,
                                  X_PVOID                        apvAgreedArgs[],
                                  X_ULONG                        ulNoofNegotiableComps,
                                  X_COMP_NEGOTIABLE_COMPONENT    aNegotiableComps[] );

X_LONG_FUNCTION X_WAM_Services(
   PX_COMP_SERVICES_POINT_REQUEST pRequestBlock,
   X_PVOID apvAgreedArgs[],
   X_ULONG ulNoofNegotiableComps,
   X_COMP_NEGOTIABLE_COMPONENT aNegotiableComps[]);

X_VOID_FUNCTION X_DestroyExtendedPrinter(struct X_IDS *pX_Ids);

X_VOID_FUNCTION X_DestroyExtendedPrinterFont(struct X_IDS *pX_Ids);

X_VOID_FUNCTION X_DuplicateExtendedPrinterInfo(struct X_IDS * pX_Ids,
                                               X_PVCHAR       pvchAppendtoString,
                                               X_BOOL         fLocalPrnInfo);

X_VOID_FUNCTION X_Get_Web_Graphical_Variable( struct X_IDS *pX_Ids,
                                              struct X_PRO *pX_Pro,
                                              struct X_FUN *pX_Fun,
                                              X_PVCHAR pvchName,
                                              X_PVCHAR pvchBuff,
                                              X_SHORT  sBuffSize,
                                              X_PCHAR  pchType );

X_LONG_FUNCTION X_XslLoadWebRoutineEx( struct X_IDS  *  pX_Ids,
                                       struct X_PRO  *  pX_Pro,
                                       struct X_FUN  *  pX_Fun,
                                       X_PVOID          pParam,
                                       X_PCCHAR         pszPartition,
                                       X_PCCHAR         pszWam,
                                       X_PCCHAR         pszLangCode,
                                       X_PCCHAR         pszRoutine,
                                       X_PCCHAR         pszEntityId,
                                       X_PCCHAR         pszXmlApp,
                                       X_LONG        *  piXslSet,
                                       X_COMP_CALLBACK  pfnXslHandler,
                                       X_LONG        *  piXmlSet,
                                       X_COMP_CALLBACK  pfnXmlHandler );

X_LONG_FUNCTION X_XslLoadWebRoutine( struct X_IDS  *  pX_Ids,
                                     struct X_PRO  *  pX_Pro,
                                     struct X_FUN  *  pX_Fun,
                                     X_PVOID          pParam,
                                     X_PCCHAR         pszWam,
                                     X_PCCHAR         pszLangCode,
                                     X_PCCHAR         pszRoutine,
                                     X_PCCHAR         pszEntityId,
                                     X_PCCHAR         pszXmlApp,
                                     X_LONG        *  piXslSet,
                                     X_COMP_CALLBACK  pfnXslHandler,
                                     X_LONG        *  piXmlSet,
                                     X_COMP_CALLBACK  pfnXmlHandler );

X_LONG_FUNCTION X_WebRoutineLookupEx( struct X_IDS   *  pX_Ids,
                                      struct X_PRO   *  pX_Pro,
                                      struct X_FUN   *  pX_Fun,
                                      X_PVOID           pParam,
                                      X_PCCHAR          pvchPartition,
                                      X_PCCHAR          pvchService,
                                      X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_WebRoutineLookup( struct X_IDS   *  pX_Ids,
                                    struct X_PRO   *  pX_Pro,
                                    struct X_FUN   *  pX_Fun,
                                    X_PVOID           pParam,
                                    X_PCCHAR          pvchService,
                                    X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_XmlAppPropertyLookup( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        X_PVOID          pParam,
                                        const X_PCCHAR   pvchEntity,
                                        const X_PCCHAR   pvchXmlApp,
                                        const X_LONG     lPropertyId,
                                        X_COMP_CALLBACK  pfnfCallback );

X_LONG_FUNCTION X_XslLoadWeblet( struct X_IDS   *  pX_Ids,
                                 struct X_PRO   *  pX_Pro,
                                 struct X_FUN   *  pX_Fun,
                                 X_PVOID           pParam,
                                 const X_PCCHAR    pvchWeblet,
                                 const X_PCCHAR    pvchLangCode,
                                 const X_PCCHAR    pvchEntity,
                                 const X_PCCHAR    pvchXmlApp,
                                 X_LONG         *  plXslSet,
                                 X_COMP_CALLBACK   pfnXslHandler,
                                 X_LONG         *  plXmlSet,
                                 X_COMP_CALLBACK   pfnXmlHandler,
                                 X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_ConvertCharToBlob( struct X_IDS  *  pX_Ids,
                                     struct X_PRO  *  pX_Pro,
                                     struct X_FUN  *  pX_Fun,
                                     X_PVOID          pParam,
                                     X_LONG           lReqSize,
                                     X_LONG           lLength,
                                     X_PVCHAR         pvchString,
                                     X_COMP_CALLBACK  pfnfCallback );

X_BOOL_FUNCTION X_ConvertBlobToChar( struct X_IDS  *  pX_Ids,
                                     struct X_PRO  *  pX_Pro,
                                     struct X_FUN  *  pX_Fun,
                                     X_LONG           lLength,
                                     X_PVCHAR         pvchBlob,
                                     X_LONG        *  plBufLen,
                                     X_PVCHAR         pvchBuffer );

X_LONG_FUNCTION X_CreateWamService( struct X_IDS   *  pX_Ids,
                                    struct X_PRO   *  pX_Pro,
                                    struct X_FUN   *  pX_Fun,
                                    X_PVCHAR          pvchService,
                                    X_PVCHAR          pvchLangCode,
                                    X_PVCHAR          pvchWam,
                                    X_PVCHAR          pvchRoutine );

X_LONG_FUNCTION X_GetGlobalParamData( struct X_IDS   *  pX_Ids,
                                      struct X_PRO   *  pX_Pro,
                                      struct X_FUN   *  pX_Fun,
                                      X_PVOID           pParam,
                                      X_LONG            lGlobalParamId,
                                      X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_EnumPartitionLanguages( struct X_IDS   *  pX_Ids,
                                          struct X_PRO   *  pX_Pro,
                                          struct X_FUN   *  pX_Fun,
                                          X_PVOID           pParam,
                                          X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_IsPartitionDefaultLanguage( struct X_IDS  *  pX_Ids,
                                              struct X_PRO  *  pX_Pro,
                                              struct X_FUN  *  pX_Fun,
                                              X_PVCHAR         pvchLangCode );

X_LONG_FUNCTION X_XslWebRoutineExist( struct X_IDS *  pX_Ids,
                                      struct X_PRO *  pX_Pro,
                                      struct X_FUN *  pX_Fun,
                                      X_PVCHAR        pvchWam,
                                      X_PVCHAR        pvchRoutine,
                                      X_PVCHAR        pvchLangCode,
                                      X_PVCHAR        pvchEntity,
                                      X_PVCHAR        pvchXmlApp,
                                      X_LONG          lSet );

X_LONG_FUNCTION X_XslWebletExist( struct X_IDS  *  pX_Ids,
                                  struct X_PRO  *  pX_Pro,
                                  struct X_FUN  *  pX_Fun,
                                  const X_PVCHAR   pvchWeblet,
                                  const X_PVCHAR   pvchLangCode,
                                  const X_PVCHAR   pvchEntity,
                                  const X_PVCHAR   pvchXmlApp,
                                  X_LONG          lSet );

X_LONG_FUNCTION X_GetWebRoutineTimestamp( struct X_IDS   *  pX_Ids,
                                          struct X_PRO   *  pX_Pro,
                                          struct X_FUN   *  pX_Fun,
                                          X_PVOID           pParam,
                                          const X_PCCHAR    pvchWam,
                                          const X_PCCHAR    pvchLangCode,
                                          const X_PCCHAR    pvchRoutine,
                                          const X_PCCHAR    pvchEntity,
                                          const X_PCCHAR    pvchXmlApp,
                                          X_LONG            lXslSet,
                                          X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_GetWebletTimestamp( struct X_IDS *  pX_Ids,
                                      struct X_PRO *  pX_Pro,
                                      struct X_FUN *  pX_Fun,
                                      X_PVOID         pParam,
                                      const X_PCCHAR  pvchWeblet,
                                      const X_PCCHAR  pvchLangCode,
                                      const X_PCCHAR  pvchEntity,
                                      const X_PCCHAR  pvchXmlApp,
                                      X_LONG          lXslSet,
                                      X_COMP_CALLBACK pfnfCallback );

X_LONG_FUNCTION X_EnumWebRoutine( struct X_IDS  *  pX_Ids,
                                  struct X_PRO  *  pX_Pro,
                                  struct X_FUN  *  pX_Fun,
                                  X_PVOID          pParam,
                                  const X_PVCHAR   pvchWam,
                                  X_COMP_CALLBACK  pfnfCallback );

X_LONG_FUNCTION X_EnumWebRoutineApp( struct X_IDS  *  pX_Ids,
                                     struct X_PRO  *  pX_Pro,
                                     struct X_FUN  *  pX_Fun,
                                     X_PVOID          pParam1,
                                     X_PVOID          pParam2,
                                     const X_PVCHAR   pvchWam,
                                     const X_PVCHAR   pvchRoutine,
                                     X_COMP_CALLBACK  pfnfCallback );

X_LONG_FUNCTION X_EnumWebletApp( struct X_IDS   *  pX_Ids,
                                 struct X_PRO   *  pX_Pro,
                                 struct X_FUN   *  pX_Fun,
                                 X_PVOID           pParam1,
                                 X_PVOID           pParam2,
                                 const X_PVCHAR    pvchWeblet,
                                 const X_PVCHAR    pvchLangCode,
                                 X_LONG            lSet,
                                 X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_EnumWebletAppLang( struct X_IDS   *  pX_Ids,
                                     struct X_PRO   *  pX_Pro,
                                     struct X_FUN   *  pX_Fun,
                                     X_PVOID           pParam1,
                                     X_PVOID           pParam2,
                                     const X_PVCHAR    pvchWeblet,
                                     const X_PVCHAR    pvchLangCode,
                                     X_LONG            lSet,
                                     X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_EnumXrefReferenceId( struct X_IDS   *  pX_Ids,
                                       struct X_PRO   *  pX_Pro,
                                       struct X_FUN   *  pX_Fun,
                                       X_PVOID           pParam1,
                                       X_PVOID           pParam2,
                                       const X_PVCHAR    pvchLangCode,
                                       const X_PVCHAR    pvchEntity,
                                       const X_PVCHAR    pvchXmlApp,
                                       const X_PVCHAR    pvchObject,
                                       const X_PVCHAR    pvchExtend,
                                       X_LONG            lObjectType,
                                       X_ULONG           ulRtyTypes,
                                       X_COMP_CALLBACK   pfnfCallback );

X_LONG_FUNCTION X_EnumXrefReferrer( struct X_IDS *  pX_Ids,
                                    struct X_PRO *  pX_Pro,
                                    struct X_FUN *  pX_Fun,
                                    X_PVOID         pParam1,
                                    X_PVOID         pParam2,
                                    const X_PVCHAR  pvchObject,
                                    const X_PVCHAR  pvchExtend,
                                    X_ULONG         ulRtyTypes,
                                    X_COMP_CALLBACK pfnfCallback );

X_LONG_FUNCTION X_EnumTechServiceDocument( struct X_IDS  *  pX_Ids,
                                           struct X_PRO  *  pX_Pro,
                                           struct X_FUN  *  pX_Fun,
                                           X_PVOID          pParam1,
                                           X_PVOID          pParam2,
                                           const X_PVCHAR   pvchEntity,
                                           const X_PVCHAR   pvchXmlApp,
                                           X_COMP_CALLBACK  pfnfCallback );

X_LONG_FUNCTION X_LoadTechServiceDocument( struct X_IDS        *  pX_Ids,
                                           struct X_PRO        *  pX_Pro,
                                           struct X_FUN        *  pX_Fun,
                                           X_PVOID                pParam1,
                                           X_PVOID                pParam2,
                                           X_COMP_XML_APP_KEY  *  pKey,
                                           X_COMP_CALLBACK        pfnfCallback );

X_LONG_FUNCTION X_SaveTechServiceDocument( struct X_IDS        *  pX_Ids,
                                           struct X_PRO        *  pX_Pro,
                                           struct X_FUN        *  pX_Fun,
                                           X_COMP_XML_APP_DATA *  pData );

X_LONG_FUNCTION X_GetLanguageCodePage( struct X_IDS   *  pX_Ids,
                                       struct X_PRO   *  pX_Pro,
                                       struct X_FUN   *  pX_Fun,
                                       X_PVOID           pParam1,
                                       X_PVOID           pParam2,
                                       const X_PCCHAR    pszLangCode,
                                       X_COMP_CALLBACK   pfnfCallback );

X_PVCHAR_FUNCTION X_GetPartitionDefaultLanguage( struct X_IDS  * pX_Ids );

X_BOOL_FUNCTION X_ValidateLanguageCode( struct X_IDS       * pX_Ids,
                                        const X_PCCHAR       pvchLanguage,
                                        struct X_LANGUAGE ** ppRetLang );

X_LONG_FUNCTION X_RestoreExternalResourceObject( struct X_IDS  *  pX_Ids,
                                                 struct X_PRO  *  pX_Pro,
                                                 struct X_FUN  *  pX_Fun,
                                                 const X_PVCHAR   pvchExternalResource,
                                                 PFNGENLPURP      pfnMessage );

X_LONG_FUNCTION X_LoadExternalResource( struct X_IDS  *  pX_Ids,
                                        struct X_PRO  *  pX_Pro,
                                        struct X_FUN  *  pX_Fun,
                                        X_PVOID          pParam1,
                                        X_PVOID          pParam2,
                                        const X_PVCHAR   pvchExternalResource,
                                        X_COMP_CALLBACK  pfnfCallback,
                                        X_BOOL           fRestoreFullPath,
                                        X_BOOL           fConvertSlashChar );

X_VOID_FUNCTION X_EndExternalResourceLoader( struct X_IDS  *  pX_Ids,
                                             struct X_PRO  *  pX_Pro,
                                             struct X_FUN  *  pX_Fun );

X_BOOL_FUNCTION X_GetLanguageIsoCharset( struct X_IDS  *  pX_Ids,
                                         struct X_PRO  *  pX_Pro,
                                         struct X_FUN  *  pX_Fun,
                                         X_PCCHAR         pszLangCode,
                                         X_PVCHAR         pvchIsoCharsetBuf,
                                         X_INT            iIsoCharsetBufSize );

X_BOOL_FUNCTION X_ObjIdToString( X_LONG lObjType, X_PVCHAR pvchObjType );

/* ================================================================= */
/*  X_UIMMGR.C functions                                             */
/* ================================================================= */

X_VOID_FUNCTION X_UIM_Manager(X_SHORT,
                              struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              ...);

/* ================================================================= */
/*  X_PIM3.C functions                                               */
/* ================================================================= */

X_YES_NO_FUNCTION X_Open_Report(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_PIM *,
                                struct X_FLD[]);

X_YES_NO_FUNCTION X_Close_Report(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_PIM *,
                                 struct X_FLD[]);

X_YES_NO_FUNCTION X_Pim_Print(struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_PIM *,
                              struct X_REPORT_CTL *,
                              struct X_COND[],
                              struct X_FLD[],
                              X_SHORT,
                              struct X_REPORT_TXT[],
                              X_SHORT,
                              struct X_REPORT_FLD[]);


/* ================================================================= */
/*  X_FUN11.C functions                                              */
/* ================================================================= */


X_VOID_FUNCTION TEA_Encrypt( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVCHAR       pvchPassword,
                             X_LONG         lTextLength,  /* Must be a multiple of 8 */
                             X_PFCHAR       pfchPlainText );

X_VOID_FUNCTION TEA_Decrypt( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVCHAR       pvchPassword,
                             X_LONG         lTextLength,   /* Must be a multiple of 8 */
                             X_PFCHAR       pfchPlainText );

/* ============================================================================== */
/*  Functions to prepare the buffer to hold the list data from a iSeries function */
/*  and to map the data in to a list                                              */
/* ============================================================================== */
X_BOOL_FUNCTION X_Prepare_ISeries_List_Buffer ( struct X_IDS         *     pX_Ids,
                                                struct X_PRO         *     pX_Pro,
                                                struct X_FUN         *     pX_Fun,
                                                X_SHORT                    sListNo,
                                                PX_LIST_VOID               X_List,
                                                X_PVCHAR             *     ppvchBuffer);

X_BOOL_FUNCTION  X_Map_ISeries_Buffer_To_List(  struct X_IDS         *     pX_Ids,
                                                struct X_PRO         *     pX_Pro,
                                                struct X_FUN         *     pX_Fun,
                                                struct X_FLD               X_Fld[],
                                                X_PVCHAR                   pvchBuffer,
                                                X_LIST_COUNT               lc70ListCountEntries,
                                                X_SHORT                    sListNo,
                                                PX_LIST_VOID               X_List);


#ifdef XDB_FILE_SUPPORT

enum ColumnType
{
   typeUnknown,
   typeBinary,
   typeChar,
   typeDate,
   typeTimestamp,
   typeLong,
   typeDouble,
   typeFloat,
   typeGeneral,
   typeLogical,
   typeMemo,
   typeNumeric
};

enum ControllerState
{
   stateNone,
   stateSetHeaderRec,
   stateSetColumnType,
   stateSetColumnValue,
   stateInsertRow
};


X_PVOID_FUNCTION LXDB_OpenOutputFile( struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      X_PVCHAR       pFileName );


X_BOOL_FUNCTION LXDB_DefineColumn( struct X_IDS * pX_Ids,
                                   struct X_PRO * pX_Pro,
                                   struct X_FUN * pX_Fun,
                                   X_PVOID           hDB,
                                   X_PVCHAR          fldName,
                                   enum ColumnType   fldType,
                                   X_LONG            fldSize,
                                   X_LONG            fldDecimals );


X_BOOL_FUNCTION LXDB_SetColumnValue( struct X_IDS * pX_Ids,
                                     struct X_PRO * pX_Pro,
                                     struct X_FUN * pX_Fun,
                                     X_PVOID        hDB,
                                     X_PVOID        fldValue );

X_BOOL_FUNCTION LXDB_InsertRow( struct X_IDS * pX_Ids,
                                struct X_PRO * pX_Pro,
                                struct X_FUN * pX_Fun,
                                X_PVOID        hDB );


X_BOOL_FUNCTION LXDB_CloseOutputFile( struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      X_PVOID        hDB );


X_PVOID_FUNCTION LXDB_OpenInputFile( struct X_IDS * pX_Ids,
                                     struct X_PRO * pX_Pro,
                                     struct X_FUN * pX_Fun,
                                     X_PVCHAR       pFileName );

X_LONG_FUNCTION LXDB_GetNumRows( struct X_IDS * pX_Ids,
                                 struct X_PRO * pX_Pro,
                                 struct X_FUN * pX_Fun,
                                 X_PVOID           hDB );

X_LONG_FUNCTION LXDB_GetNumColumns( struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_PVOID        hDB );

X_LONG_FUNCTION LXDB_GetColumnTypeAt( struct X_IDS * pX_Ids,
                                      struct X_PRO * pX_Pro,
                                      struct X_FUN * pX_Fun,
                                      X_PVOID        hDB,
                                      LX_INT32       pos );


X_BOOL_FUNCTION LXDB_CloseInputFile( struct X_IDS * pX_Ids,
                                     struct X_PRO * pX_Pro,
                                     struct X_FUN * pX_Fun,
                                     X_PVOID        hDB );


X_BOOL_FUNCTION LXDB_GetColValueByPosition( struct X_IDS * pX_Ids,
                                            struct X_PRO * pX_Pro,
                                            struct X_FUN * pX_Fun,
                                            X_PVOID        hDB,
                                            X_LONG         pos,
                                            X_PVOID        pWriteBuffer,
                                            X_LONG         writeBufferSize );

X_BOOL_FUNCTION LXDB_GetColumnName( struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_PVOID        hDB,
                                    X_LONG         pos,
                                    X_PVOID        pWriteBuffer,
                                    X_LONG         writeBufferSize );

X_LONG_FUNCTION LXDB_GetColumnSize( struct X_IDS * pX_Ids,
                                    struct X_PRO * pX_Pro,
                                    struct X_FUN * pX_Fun,
                                    X_PVOID         hDB,
                                    X_LONG         pos );

X_BOOL_FUNCTION LXDB_ToTop ( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVOID        hDB );

X_BOOL_FUNCTION LXDB_ToLast( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVOID        hDB );

X_BOOL_FUNCTION LXDB_ToNext( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVOID        hDB );


X_BOOL_FUNCTION LXDB_ToPrev( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVOID        hDB   );


X_BOOL_FUNCTION LXDB_GetRow( struct X_IDS * pX_Ids,
                             struct X_PRO * pX_Pro,
                             struct X_FUN * pX_Fun,
                             X_PVOID        hDB );


X_BOOL_FUNCTION LXDB_CreateEnvironment( struct X_IDS * pX_Ids,
                                        struct X_PRO * pX_Pro,
                                        struct X_FUN * pX_Fun );


X_VOID_FUNCTION LXDB_DestroyEnvironment( struct X_IDS * pX_Ids );

#endif /* def XDB_FILE_SUPPORT */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !def __INCL_X_FUNPRO_H__ */
