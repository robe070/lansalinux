/* ================================================================= */
/* ===== LANSA FOR WINDOWS USER DBMS FUNCTION PROTOTYPES (DBM) ===== */
/* ================================================================= */
/*                                                                   */
/* Source File         : x_dbmpro.h                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not recommended                             */
/* Description         : Database Management(DBM) function prototypes*/
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*  G92620 93/07/29 Add new commit and rollback functions            */
/*                  Add new single entry point which will call all   */
/*                  other functions to allow for execution           */
/*                  without DB/2.                                    */
/*  3230   95/02/13 Add ODBC Support.                                */
/*  2715   95/12/28 Add Predetermined Join Field (PJF) support.      */
/*                                                                   */
/* ================================================================= */

#include "x_dbmstr.h" /* Note this will not be included if   */
                      /* x_dbmint.h has already been included.*/                  

#ifndef _X_DBMPRO_H
#define _X_DBMPRO_H

#ifdef __cplusplus
extern "C" {
#endif

/* ================================================================= */
/*  x_dbm1.c functions                                               */
/* ================================================================= */


X_LONG_FUNCTION X_DBM_User_IO_Operation(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_DBM *,
                                        X_SHORT,
                                        X_PVCHAR,
                                        X_SHORT,
                                        X_PVOID);

X_LONG_FUNCTION X_DBM_Allocate_SQLDA(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_DBM *,
                                     X_PVCHAR,
                                     X_SQLDA **);

X_LONG_FUNCTION X_DBM_Deallocate_SQLDA(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_DBM *,
                                       X_SQLDA **);

X_LONG_FUNCTION X_DBM_Prepare_Stmnt(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_DBM *,
                                    X_PVCHAR,
                                    X_PSHORT);

X_LONG_FUNCTION X_DBM_Open_Cursor(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_DBM *,
                                  X_SHORT,
                                  X_SQLDA *);

X_LONG_FUNCTION X_DBM_Close_Cursor(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_DBM *,
                                   X_SHORT);
 
X_LONG_FUNCTION X_DBM_Fetch_Row(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_DBM *,
                                X_SHORT,
                                X_SQLDA *);

X_LONG_FUNCTION X_DBM_Execute(struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_DBM *,
                              X_SHORT,
                              X_SQLDA *);

X_LONG_FUNCTION X_DBM_Execute_Immed(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_DBM *,
                                    X_PVCHAR);

X_LONG_FUNCTION X_DBM_Commit_2(struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_DBM *);

X_LONG_FUNCTION X_DBM_Rollback_2(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_DBM *);

X_VOID_FUNCTION X_DBM_Connect(struct X_IDS *,
                              struct X_PRO *,
                              struct X_FUN *,
                              struct X_DBM *,
                              X_PVCHAR);

X_VOID_FUNCTION X_DBM_Disconnect(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_DBM *,
                                 X_PVCHAR);

X_LONG_FUNCTION X_DBM_Connect_Server(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_DBM *,
                                     struct X_CONNECT_DATABASE *,
                                     X_PVCHAR);

X_LONG_FUNCTION X_DBM_Disconnect_Server(struct X_IDS *,
                                        struct X_PRO *,
                                        struct X_FUN *,
                                        struct X_DBM *,
                                        struct X_CONNECT_DATABASE *);

X_SHORT_FUNCTION X_DBM_Set_All_Statement_Attributes(
                                    struct X_IDS *pX_Ids,
                                    struct X_PRO *pX_Pro,
                                    struct X_FUN *pX_Fun,
                                    struct X_DBM *pX_DBM,
                                    X_HDBC        hdbc,
                                    X_HSTMT       hstmt );

X_VOID_FUNCTION X_DBM_Map_from_Table(struct X_IDS *,
                                     struct X_PRO *,
                                     struct X_FUN *,
                                     struct X_FLD *,
                                     struct X_DBM *,
                                     X_SQLDA *);

X_VOID_FUNCTION X_DBM_Map_to_Table(struct X_IDS *,
                                   struct X_PRO *,
                                   struct X_FUN *,
                                   struct X_FLD *,
                                   struct X_DBM *,
                                   X_SQLDA *);

X_VOID_FUNCTION X_DBM_Map_to_Table_No_RRNO( struct X_IDS *pX_Ids,
                                            struct X_PRO *pX_Pro,
                                            struct X_FUN *pX_Fun,
                                            struct X_FLD *pX_Fld,
                                            struct X_DBM *pX_DBM,
                                            X_SQLDA *pSqlda);

X_VOID_FUNCTION X_DBM_Insert_RRN(
   struct X_IDS *,
   struct X_PRO *,
   struct X_FUN *,
   struct X_FLD *,
   X_SQLDA      *,
   X_DOUBLE     );

X_VOID_FUNCTION X_DBM_Set_SQLDA_No(
   struct X_IDS *,
   struct X_PRO *,
   struct X_FUN *,
   struct X_DBM *,
   X_SQLDA      *,
   long         );

X_LONG_FUNCTION X_DBM_Execute_RowCount(struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       struct X_DBM *,
                                       X_SHORT,
                                       X_SQLDA *,
  				                           X_PLONG);


/* ================================================================= */
/*  x_dbm2.c functions                                               */
/* ================================================================= */


X_VOID_FUNCTION X_Batch_Control(struct X_IDS *,
                                struct X_PRO *,
                                struct X_FUN *,
                                struct X_FLD[],
                                struct X_FLD[],
                                X_SHORT,
                                X_SHORT[],
                                X_SHORT,
                                X_SHORT[],
                                X_PVCHAR,
                                X_PVCHAR,
                                struct X_FLD[],
                                X_SHORT,
                                X_SHORT[],
                                X_SHORT,
                                X_SHORT[],
                                X_SHORT,
                                X_SHORT[],
                                X_YES_NO,
                                X_SQLDA *,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_PVCHAR,
                                X_CHAR,
                                X_PYES_NO);

/* ================================================================= */
/*  x_dbm3.c functions                                               */
/* ================================================================= */

X_VOID_FUNCTION X_DBM_Derive_PJF(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_FLD[],
                                 X_SHORT,
                                 X_SHORT[],
                                 X_PVCHAR,
                                 X_SHORT,
                                 X_SHORT[],
                                 X_PVCHAR,
                                 X_PVCHAR,
                                 X_PVCHAR,
                                 X_PVCHAR,
                                 X_PVCHAR,
                                 X_CHAR,
                                 X_CHAR,
                                 X_PYES_NO);

#if defined(X_OPERATING_SYSTEM_ISERIES)

/* ================================================================= */
/*  x_dbm_i1.c functions                                             */
/* ================================================================= */

X_LONG_FUNCTION X_DBM_Native_User_IO_Operation(
                                         struct X_IDS *pX_Ids,
                                         struct X_PRO *pX_Pro,
                                         struct X_FUN *pX_Fun,
                                         struct X_DBM *pX_DBM,
                                         X_SHORT  sOperation,
                                         struct X_DBM_NATIVE_IO_CONTROL *,
	                                      struct X_FLD *,
	                                      X_PSHORT,
	                                      struct X_DBM_WHERE * );
/* ================================================================= */
/*  x_dbm_i2.c functions                                             */
/* ================================================================= */

X_VOID_FUNCTION X_DBM_Native_Batch_Control(struct X_IDS *pX_Ids,
                                           struct X_PRO *pX_Pro,
                                           struct X_FUN *pX_Fun,
                                           struct X_DBM *pX_DBMParent,
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
	                                        struct X_DBM_NATIVE_IO_CONTROL *pX_Native_File,
                                           X_CHAR        chType,
                                           X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_DBM_Native_Batch_Control_2(struct X_IDS *pX_Ids,
                                             struct X_PRO *pX_Pro,
                                             struct X_FUN *pX_Fun,
                                             struct X_DBM *pX_DBMParent,
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
	                                          struct X_DBM_NATIVE_IO_CONTROL *pX_Native_File,
                                             X_CHAR        chType,
                                             X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_DBM_Native_Batch_Control_3(struct X_IDS *pX_Ids,
                                             struct X_PRO *pX_Pro,
                                             struct X_FUN *pX_Fun,
                                             struct X_DBM *pX_DBMParent,
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
	                                          struct X_DBM_NATIVE_IO_CONTROL *pX_Native_File,
                                             X_CHAR        chType,
                                             X_PYES_NO     pchReturn);

/* ================================================================= */
/*  x_dbm_i3.c functions                                             */
/* ================================================================= */

X_VOID_FUNCTION X_DBM_Native_Derive_PJF(
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
                                 struct X_DBM_NATIVE_IO_CONTROL *pX_Native_File,
                                 X_SHORT       scSrcFlds,
                                 X_SHORT       psSrcFlds[],
                                 struct X_FLD  X_FldTemp[],
                                 X_CHAR        chAction,
                                 X_CHAR        chType,
                                 X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_DBM_Native_Derive_PJF_2(
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
                                 struct X_DBM_NATIVE_IO_CONTROL *pX_Native_File,
                                 X_SHORT       scSrcFlds,
                                 X_SHORT       psSrcFlds[],
                                 struct X_FLD  X_FldTemp[],
                                 X_CHAR        chAction,
                                 X_CHAR        chType,
                                 X_PYES_NO     pchReturn);

X_VOID_FUNCTION X_DBM_Native_Derive_PJF_3(
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
                                 struct X_DBM_NATIVE_IO_CONTROL *pX_Native_File,
                                 X_SHORT       scSrcFlds,
                                 X_SHORT       psSrcFlds[],
                                 struct X_FLD  X_FldTemp[],
                                 X_CHAR        chAction,
                                 X_CHAR        chType,
                                 X_PYES_NO     pchReturn);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !def _X_DBMPRO_H */
