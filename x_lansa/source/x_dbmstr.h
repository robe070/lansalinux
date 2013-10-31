/* ================================================================= */
/* ========= LANSA FOR WINDOWS GLOBAL STRUCTURES =================== */
/* ================================================================= */
/*                                                                   */
/* Source File         : x_dbmstr.h                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : X_SQLDA definition                          */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*  3230  95/02/13  Add ODBC Support structure                       */
/*        95/10/05  add generic macro def. for SQLDA                 */
/*        98/04/14  Change defaults for ORACLE                       */
/* 100819 02/01/14  Remove database-specific structs                 */
/*                                                                   */

#ifndef _X_DBMSTR_H
#define _X_DBMSTR_H

/* Do not move this code into x_funstr.h as it clashes with SQLDA    */
/* defined in the development environment.                           */

/* Hide details of SQLDA */
struct SQLDA;
typedef struct SQLDA X_SQLDA;

/* The following is only used by OAMs */
#define X_RESET_SQLDA_NO -1
#define X_RESET_SQLDA_NO_MIN_1 -2 /* For removing second @@UPID column from read sqlda */

/* The following is only used by OAMs and X_Choose_SQLDA() - x_fun6.c*/
#define X_MAX_SQLDA 6
#define X_SQLDA_ANY     'A' /* Not to be used by files with LOBs */
#define X_SQLDA_SEL_DEL 'S'
#define X_SQLDA_INS_UPD 'M' /* Not to be used by files with LOBs */
#define X_SQLDA_INSERT  'I'
#define X_SQLDA_UPDATE  'U'
#define X_SQLDA_DELETE  'D'
#define X_SQLDA_READ    'R'

#ifdef X_DATABASE_DB2
typedef long X_HDBC;
typedef long X_HSTMT;
#else
typedef void *X_HDBC;
typedef void *X_HSTMT;
#endif

/* ================================================================= */
/* Native I/O control structure                                      */
/* ================================================================= */
/* This contains information to help control the native I/O          */
/*                                                                   */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pFile              File pointer used by Native I/O APIs           */
/* vchFileName        File definition name                           */
/* vchLibrName        Library name for file definition               */
/* fInput             File is to be input only                       */
/*                     (as against insert/update/delete).            */
/* fArrivalSeq        File is to be opened in arrival sequence only  */
/*                     (as against via keyed sequence).              */
/* fCommit            File is to be opened under commitment control  */
/* fShare             File is to be opened to share Open Data Paths  */
/* fActualShare       File additional parms is SHARE(*YES)           */
/* fSecure            File is to be secured from other overrides     */
/* vchFileNameOpen    File name to open / opened                     */
/* vchLibrNameOpen    Library name to open / opened                  */
/*                     (*LIBL to use library list)                   */
/* vchMembNameOpen    Member name to open / opened                   */
/*                     (*N or *FIRST to use first or only member)    */
/* pFunctionOpening   Function that opened the file                  */
/* pProcessOpening    Process that opened the file                   */
/* pX_Rec             Record buffer for file (includes space for RRN)*/
/* pX_Fld_Rec         X_Fld for real fields in file                  */
/*                     (pointing to record buffer).                  */
/* lRecLength         Length of record buffer                        */
/* sFldCount          Count of fields in file                        */
/* pX_Key             Key buffer for file                            */
/* pX_Fld_Key         X_Fld for key for file                         */
/*                     (pointing to key buffer).                     */
/* lKeyLength         Length of key buffer for this I/O              */
/* sKeyCount          Count of fields in key for this I/O            */
/* fLocateForward     Locate is to be in forwards direction          */
/* fLocateByKey       Locate is to be by key                         */
/* fLocateStartKey    Locate is to be for a start key                */
/* fReadForward       Read is to be in forwards direction            */
/* fReadByKey         Read is to be by key                           */
/* fLock              Read is to lock the record                     */
/* lRRN               Relative record number of the record to be read*/
/* pPFWhere           Postfix where list                             */
/* scPFWhere          Count of entries in Postfix where list         */
/* fFirstRow          First row for where evaluation                 */
/* sOperandsStackMaxDepth   Current maximum depth for operands stack */
/*                              for where evaluation                 */
/* pOperandsStack     Operands stack for where evaluation            */
/* pSingleX_FLDListFirst    First intermediate result                */
/*                              for where evaluation                 */
/* pSingleX_FLDListLast     Last intermediate result                 */
/*                              for where evaluation                 */
/* pfX_Rec_LglFlds          The field is in the file                 */
/* pX_Rec_Specials         The field is special (iSeries Other       */
/*                          Binary or VarLen. etc)                   */
/* pX_Rec_Input_Key_Vecs   Vectors in X_Fld_Rec for key vectors      */
/* pchX_Rec_NullMap        Null map for the fields in the record     */
/* pchX_Key_NullMap        Null map for the fields in the key        */
/* sKeyMaxCount            Maximum number of keys for this file      */
/* pX_Rec_NativeLens       Native lengths of all the fields          */
/* pWhereEvaluationFrame   X_VAR_EXPRESSION_FRAME for where eval'n   */
/*-------------------------------------------------------------------*/
struct X_DBM_NATIVE_IO_CONTROL
{
   X_PVOID         pFile;
   X_VCHAR         vchFileName[10 + 1];
   X_VCHAR         vchLibrName[10 + 1];
   X_BOOL          fInput; 
   X_BOOL          fArrivalSeq; 
   X_BOOL          fCommit; 
   X_BOOL          fShare;
   X_BOOL          fActualShare;
   X_BOOL          fSecure;
   X_VCHAR         vchFileNameOpen[10 + 1];
   X_VCHAR         vchLibrNameOpen[10 + 1];
   X_VCHAR         vchMembNameOpen[10 + 1];
   struct X_FUN   *pFunctionOpening;
   struct X_PRO   *pProcessOpening;
   X_PVOID         pX_Rec;
   X_PVOID         pX_Fld_Rec;
   X_LONG          lRecLength;
   X_SHORT         sFldCount;
   X_PVOID         pX_Key;
   X_PVOID         pX_Fld_Key;
   X_LONG          lKeyLength;
   X_SHORT         sKeyCount;
   X_BOOL          fLocateForward; 
   X_BOOL          fLocateByKey; 
   X_BOOL          fLocateStartKey; 
   X_BOOL          fReadForward; 
   X_BOOL          fReadByKey; 
   X_BOOL          fLock; 
   X_LONG          lRRN;
   X_PVOID         pPFWhere;
   X_SHORT         scPFWhere;
   X_BOOL          fFirstRow; 
   X_SHORT         sOperandsStackMaxDepth;
   X_PVOID         pOperandsStack;
   X_PVOID         pSingleX_FLDListFirst;
   X_PVOID         pSingleX_FLDListLast;
   X_PVOID         pfX_Rec_LglFlds;
   X_PVOID         pX_Rec_Specials;
   X_PVOID         pX_Rec_Input_Key_Vecs;
   X_BOOL          fNullCapable;
   X_PCHAR         pchX_Rec_NullMap;
   X_PCHAR         pchX_Key_NullMap;
   X_SHORT         sKeyMaxCount;
   X_PVOID         pX_Rec_NativeLens;
   X_PVOID         pWhereEvaluationFrame;
};

#define X_DBM_IS_GET_LGLFLD_VEC(_V,_W) \
   { \
      X_SHORT m; \
 \
      if ( pfLglFlds != pX_NULL ) \
      { \
         for ( m = 0, _W = 0; m < _V; m++ ) \
         { \
            if ( pfLglFlds[m] == TRUE ) \
               _W++; \
         } \
      } \
   }
/* ulMaxSize set correctly only for small char or binaries, OK for key lengths */
#define X_DBM_IS_CREATE_XFLD_FROM_NATIVE_XFLD(_X,_D,_R,_W) \
{ \
   memcpy( _X, &( _R[_W] ), sizeof(struct X_FLD) ); \
   if ( X_VECTOR_FIELD_IS_LL2(_X, 0) ) \
   { \
      if ( _X->chType == X_TYPE_NCHAR ) \
      { \
         _X->chType = X_TYPE_CHAR; \
         memset( (&_D), 0, sizeof( X_FLD_NCHAR )); \
         ((X_FLD_NCHAR*)(&_D))->i8Version = X_FLDDATA_V2; \
         ((X_FLD_NCHAR*)(&_D))->bFieldState = FsHasWideCharData; \
         ((X_FLD_NCHAR*)(&_D))->ulMaxChars = _X->sLen; \
         ((X_FLD_NCHAR*)(&_D))->ulMaxSize = X_MAX_WIDECHAR_MBCS_LEN( _X->sLen ); \
      } \
      else \
      { \
         memset(&_D,LOVAL,sizeof(_D)); \
         _D.Int8.i8Version = X_FLDDATA_V1;\
         if ( ( X_VECTOR_STORED_AS_CHAR( _X, 0 ) ) \
              || ( X_VECTOR_STORED_AS_BINARY( _X, 0 ) ) ) \
         { \
            _D.Char.ulMaxSize = _X->sLen; \
         } \
      } \
   } \
   _X->pField = (X_PDICTIONARY_FIELD) &_D; \
} 

#endif
