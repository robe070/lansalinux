#ifndef __INCL_X_BIF000_H__
#define __INCL_X_BIF000_H__

#include "x_bldcfg.h"

#ifndef X_ALLOW_10_0_STRUCTURES
#include "x_varstr.h"
#include "x_varpro.h"
#endif

#define U_BIF_STANDARD_PARAMETERS  \
        struct  X_IDS   *pX_Ids,   \
        struct  X_PRO   *pX_Pro,   \
        struct  X_FUN   *pX_Fun,   \
        struct  X_BIF   *pX_Bif,   \
        struct  X_FLD   X_Fld[],   \
        struct  X_LIST  X_List[],  \
        X_SHORT         sInCount,  \
        X_SHORT         sInVec[],  \
        X_SHORT         sRetCount, \
        X_SHORT         sRetVec[]

typedef struct date
{
   X_SHORT sDay;
   X_SHORT sMonth;
   X_SHORT sYear;
   X_SHORT sCent;
   X_VCHAR vchDay[3];
   X_VCHAR vchMonth[3];
   X_VCHAR vchYear[3];
   X_VCHAR vchCent[3];
}
X_DATE;


typedef X_VOID_FUNCTION   FX_BUILTIN_NNN (U_BIF_STANDARD_PARAMETERS);
typedef FX_BUILTIN_NNN *  PFX_BUILTIN_NNN;
typedef FX_BUILTIN_NNN ** PPFX_BUILTIN_NNN;


/*==============================================*/
/* Parms common to the 'put check' bifs.        */
/*==============================================*/
typedef struct {
   X_VCHAR  vchValidationLevel[2];
   X_VCHAR  vchField[X_OBJECT_NAME_LEN + 1];
   X_LONG   lSequence;
   X_VCHAR  vchDescription[30 + 1];
   X_VCHAR  vchEnableForAdd[2];
   X_VCHAR  vchEnableForChange[2];
   X_VCHAR  vchEnableForDelete[2];
   X_VCHAR  vchActionTrue[6 + 1];
   X_VCHAR  vchActionFalse[6 + 1];
   X_VCHAR  vchMsgDetails[27 + 1];
   X_VCHAR  vchMsgText[80 + 1];
} X_CHECK_PARMS, *X_PCHECK_PARMS;

typedef struct _X_X96_DEFAULTS
{
   X_PVCHAR  pvchDefaultFileSIZE;
   X_PVCHAR  pvchDefaultFileLVLCHK;
   X_CHAR    chDefaultCommitmentControl;
} X_X96_DEFAULTS, *X_PX96_DEFAULTS;

/*===================================================================*/
/* Function prototypes                                               */
/*===================================================================*/

X_VOID_FUNCTION X_UnformatDate(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_BIF *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_DATE *);

X_VOID_FUNCTION X_FormatDate(struct X_IDS *,
                               struct X_PRO *,
                               struct X_FUN *,
                               struct X_BIF *,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_PVCHAR,
                               X_DATE *);

X_VOID_FUNCTION X_InitDateStruct(struct X_IDS *,
                                 struct X_PRO *,
                                 struct X_FUN *,
                                 struct X_BIF *,
                                 X_DATE *);

X_VOID_FUNCTION X_SetCentury(struct X_IDS *,
                             struct X_PRO *,
                             struct X_FUN *,
                             struct X_BIF *,
                             X_PVCHAR,
                             X_DATE *);

X_VOID_FUNCTION X_CheckDateValidity(struct X_IDS *,
                                    struct X_PRO *,
                                    struct X_FUN *,
                                    struct X_BIF *,
                                    X_PVCHAR,
                                    X_DATE *);

X_LONG_FUNCTION X_GetDaysFromDate(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_BIF *,
                                  X_PVCHAR,
                                  X_DATE *);

X_VOID_FUNCTION X_GetDateFromDays(struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_BIF *,
                                  X_PVCHAR,
                                  X_LONG,
                                  X_DATE *);

/*==============================================*/
/* Function to add an element to a realloc'd    */
/* array.                                       */
/*==============================================*/
X_VOID_INTERNAL_FUNCTION AddElement(U_BIF_STANDARD_PARAMETERS,
                                    X_PVOID *,
                                    X_USHORT,
                                    X_USHORT *,
                                    X_PVOID);

/*==============================================*/
/* Function to remove an element from a         */
/* realloc'd array.                             */
/*==============================================*/
X_VOID_INTERNAL_FUNCTION RemoveElement(U_BIF_STANDARD_PARAMETERS,
                                       X_PVOID *,
                                       X_USHORT,
                                       X_USHORT *,
                                       X_USHORT);
/*==============================================================*/
/* Function to verify that the common parms associated with the */
/* 'put check' bifs are valid.                                  */
/*==============================================================*/
X_BOOL_INTERNAL_FUNCTION fValidCheckParms(U_BIF_STANDARD_PARAMETERS,
                                          X_PCHECK_PARMS);

X_BOOL_INTERNAL_FUNCTION fLogicalFileExists(U_BIF_STANDARD_PARAMETERS,
                                            X_PCHAR,
                                            X_PCHAR,
                                            X_PCHAR);
X_BOOL_INTERNAL_FUNCTION fProcessExists(U_BIF_STANDARD_PARAMETERS,
                                        X_PCHAR);
X_BOOL_INTERNAL_FUNCTION fFunctionExists(U_BIF_STANDARD_PARAMETERS,
                                         X_PCHAR,
                                         X_PCHAR);
X_BOOL_INTERNAL_FUNCTION fFieldExists(U_BIF_STANDARD_PARAMETERS,
                                      X_PCHAR,
                                      LX_F03_PKEY *,
                                      LX_F03_DATA *);
X_BOOL_INTERNAL_FUNCTION fUniqueName(U_BIF_STANDARD_PARAMETERS,
                                     X_PCHAR,
                                     X_PCHAR);
X_BOOL_INTERNAL_FUNCTION fFileExists(U_BIF_STANDARD_PARAMETERS,
                                     X_PCHAR,
                                     X_PCHAR);

X_BOOL_INTERNAL_FUNCTION CheckFileExist( U_BIF_STANDARD_PARAMETERS,
                                         X_PVCHAR  pvchFile,
                                         X_PVCHAR  pvchLibrary,
                                         LX_F27_PKEY * pF27Key,
                                         LX_F27_DATA * pF27Data );

X_BOOL_INTERNAL_FUNCTION fValidFileLevel(U_BIF_STANDARD_PARAMETERS,
                                         X_PCHECK_PARMS);
X_BOOL_INTERNAL_FUNCTION fValidDictLevel(U_BIF_STANDARD_PARAMETERS,
                                         X_PCHECK_PARMS,
                                         X_USHORT);
X_VOID_INTERNAL_FUNCTION GetCheckParms(U_BIF_STANDARD_PARAMETERS,
                                       X_PCHECK_PARMS);


X_BOOL_INTERNAL_FUNCTION Count_Process_Attachments( U_BIF_STANDARD_PARAMETERS,
                                                      X_PUSHORT pusCount );     /* x_bif082.c */

struct _xdef_rdml;

X_BOOL_INTERNAL_FUNCTION Add_PCX_RDML_To_Working_List( struct X_IDS * pX_Ids,
                                                         struct X_PRO * pX_Pro,
                                                         struct X_FUN * pX_Fun,
                                                         struct X_FLD pX_Fld[],
                                                         struct X_LIST * pRDMLList,
                                                         struct _xdef_rdml * pRDML,
                                                         X_PVCHAR pvchMsgID,
                                                         X_PVCHAR pvchReason );   /* x_bif088.c */


X_VOID_INTERNAL_FUNCTION UpdateMemX05Record(U_BIF_STANDARD_PARAMETERS,
                                            X_PCHECK_PARMS,
                                            X_PVCHAR,
                                            X_PVCHAR,
                                            X_BOOL,
                                            LX_F05_RECD *);

X_VOID_INTERNAL_FUNCTION UpdateDBX05Record(U_BIF_STANDARD_PARAMETERS,
                                           X_PCHECK_PARMS,
                                           X_PVCHAR,
                                           X_PVCHAR);
X_VOID_INTERNAL_FUNCTION RemoveRuleFromMem(U_BIF_STANDARD_PARAMETERS,
                                    LX_F05_PKEY *,
                                    LX_F05_DATA *);
X_VOID_INTERNAL_FUNCTION RemoveRuleFromDB(U_BIF_STANDARD_PARAMETERS,
                                    LX_F05_PKEY *,
                                    LX_F05_DATA *);
X_VOID_INTERNAL_FUNCTION FillInHeadings(U_BIF_STANDARD_PARAMETERS,
                                        X_PVCHAR,
                                        X_PVCHAR,
                                        X_PVCHAR,
                                        X_PVCHAR,
                                        X_PVCHAR,
                                        X_PVCHAR,
                                        X_PVCHAR);

X_VOID_FUNCTION X_BIF_Create_Edit_File    (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);
X_VOID_FUNCTION X_BIF_Destroy_Edit_File   (struct X_IDS * pX_Ids,
                                       struct X_PRO * pX_Pro,
                                       struct X_FUN * pX_Fun);
X_VOID_FUNCTION X_BIF_HeapListInsert( void );

#ifdef X_OPERATING_SYSTEM_WIN
X_BOOL_INTERNAL_FUNCTION fLansaRunning( U_BIF_STANDARD_PARAMETERS );
X_LONG_INTERNAL_FUNCTION lRemoteSystemStatus( U_BIF_STANDARD_PARAMETERS, X_SHORT );
X_BOOL_INTERNAL_FUNCTION fRSMRunningAnywhere( U_BIF_STANDARD_PARAMETERS, X_PVCHAR );
X_LONG_INTERNAL_FUNCTION lGetRSMID(  U_BIF_STANDARD_PARAMETERS,
                                   X_PVCHAR       pvchSystem,
                                   X_BOOL );
X_LONG_INTERNAL_FUNCTION lSetRSMDeliverTo( U_BIF_STANDARD_PARAMETERS,
                                          X_SHORT     sRSMID,
                                          X_BOOL      fUseKerberos );
X_LONG_INTERNAL_FUNCTION lSetRSMKerberos( U_BIF_STANDARD_PARAMETERS,
                                         X_SHORT     sRSMID,
                                         X_BOOL      fKerberos );
X_LONG_INTERNAL_FUNCTION lSetRSMUserID(   U_BIF_STANDARD_PARAMETERS,
                                         X_SHORT     sRSMID,
                                         X_PVCHAR    pvchUserID );
X_LONG_INTERNAL_FUNCTION lSetRSMPassword(   U_BIF_STANDARD_PARAMETERS,
                                         X_SHORT     sRSMID,
                                         X_PVCHAR    pvchPassword );
X_LONG_INTERNAL_FUNCTION lSetRSMTaskID(   U_BIF_STANDARD_PARAMETERS,
                                         X_SHORT     sRSMID,
                                         X_PVCHAR    pvchTaskID );
X_LONG_INTERNAL_FUNCTION lRemoteSystemMonitorStartStop( U_BIF_STANDARD_PARAMETERS,
                                                       X_USHORT       usMsg, 
                                                       X_SHORT        sRSMID );

X_BOOL_INTERNAL_FUNCTION IsLL2Object( U_BIF_STANDARD_PARAMETERS ,X_SHORT , X_PVCHAR , X_PVCHAR  );
X_BOOL_INTERNAL_FUNCTION IsLL2Function(  U_BIF_STANDARD_PARAMETERS, X_PVCHAR, X_PVCHAR);
X_VOID_INTERNAL_FUNCTION GetX96SP1( U_BIF_STANDARD_PARAMETERS, X_PX96_DEFAULTS pX96Defaults );
X_VOID_INTERNAL_FUNCTION FreeX96SP1( U_BIF_STANDARD_PARAMETERS, X_PX96_DEFAULTS pX96Defaults );
#endif

void *
   X_BIF_Allocator (
   void        *  pAnchor,
   X_SIZE         uiBytes);

/*===================================================================*/
/* User Defined Builtin Functions macros                             */
/*===================================================================*/
#define U_BIF_CHECK_FATAL_ERROR_RET(_B) \
{ \
   if (pX_Ids->chFatalError == YES) \
   { \
      return(_B);\
   } \
}

#define U_BIF_CHECK_FATAL_ERROR() \
{ \
   if (pX_Ids->chFatalError == YES) \
   { \
      return;\
   } \
}

#define U_BIF_COLUMN_ERROR "Invalid working list column number referenced in U_BIF macro"
#define U_BIF_LIST_ERROR   "Invalid working list number referenced in U_BIF macro"

#define U_BIF_LANSA_FUNCTION         pX_Fun->vchName

#define U_BIF_LANSA_FUNCTION_DESC    pX_Fun->vchDesc

#define U_BIF_LANSA_PROCESS          pX_Pro->vchName

#define U_BIF_LANSA_PROCESS_DESC     pX_Pro->vchDesc

#define U_BIF_GET_HWND(_R) \
   _R = (HWND)pX_Ids->pX_IdsOS->hwndX_UIM;

/* Ensure the topmost window handle is up-to-date */
/* Before getting the hwnd                        */
#define U_BIF_UPDATE_HWND(_R) \
      { \
         X_PVOID  pvTrackInfo = pX_NULL; \
         if (X_IS_COMPONENT(pX_Fun)) \
         { \
            X_Start_Call_RDML_from_RDMLX (pX_Ids,pX_Pro,pX_Fun,&(pvTrackInfo)); \
         } \
         _R = (HWND)pX_Ids->pX_IdsOS->hwndX_UIM; \
         if (X_IS_COMPONENT(pX_Fun))  \
         { \
            X_End_Call_RDML_from_RDMLX (pX_Ids,pX_Pro,pX_Fun,&(pvTrackInfo)); \
         } \
      }

#define U_BIF_FATAL_ERROR \
   (pX_Ids->chFatalError == YES)

#define U_BIF_ISSUE_FATAL_ERROR(_T) \
   X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, _T); \
   return;
#define U_BIF_ISSUE_FATAL_ERROR_RET(_T,_R) \
   X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, _T); \
   return(_R);
#define U_BIF_ISSUE_FATAL_ERROR_PARM1(_T,_P) \
   X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, _T, _P); \
   return;
#define U_BIF_ISSUE_FATAL_ERROR_PARM1_RET(_T,_P,_R) \
   X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, _T, _P); \
   return(_R);
#define U_BIF_ISSUE_FATAL_ERROR_PARM2(_T,_P, _P2) \
   X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, _T, _P, _P2); \
   return;

#define U_BIF_HANDLE_FATAL_ERROR \
 if (pX_Ids->chFatalError == YES) return;

#define U_BIF_HANDLE_FATAL_ERROR_RET( _RET )  \
 if (pX_Ids->chFatalError == YES) return (_RET );

#define U_BIF_SET_GOOD_RETURN \
   pX_Bif->chReturnCode = YES;


#define U_BIF_SET_BAD_RETURN \
   pX_Bif->chReturnCode = NO;


#define U_BIF_RETURN \
   return;


#define U_BIF_SHUTDOWN_REQUEST \
   pX_Bif->chShutDown == YES


#define U_BIF_STANDARD_ARGUMENTS   \
        pX_Ids,    \
        pX_Pro,    \
        pX_Fun,    \
        pX_Bif,    \
        X_Fld,     \
        X_List,    \
        sInCount,  \
        sInVec,    \
        sRetCount, \
        sRetVec


#ifdef X_OPERATING_SYSTEM_UNIX
   #define U_BIF_OPERATING_SYSTEM_UNIX
#endif
#ifdef X_OPERATING_SYSTEM_WIN
   #define U_BIF_OPERATING_SYSTEM_WIN
#endif
#ifdef X_OPERATING_SYSTEM_WIN64
   #define U_BIF_OPERATING_SYSTEM_WIN
#endif


#define U_BIF_GET_ARGUMENT_COUNT(_R) \
_R = sInCount;


#define U_BIF_ARGUMENT_PASSED(_N) \
((_N >= 0) && (_N < sInCount) && (sInVec[_N] != V_NOT_AVAILABLE))


#define U_BIF_GET_RETURN_COUNT(_R) \
_R = sRetCount;


#define U_BIF_RETURN_REQUIRED(_N) \
((_N >= 0) && (_N < sRetCount) && (sRetVec[_N] != V_NOT_AVAILABLE))


#define U_BIF_GET_ARG_AS_SHORT(_A, _S) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Short(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], (X_PSHORT) &(_S)); \
   }


#define U_BIF_GET_ARG_AS_LONG(_A, _L) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Long(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], (X_PLONG) &(_L)); \
   }


#define U_BIF_GET_ARG_AS_DOUBLE(_A, _D) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Double(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], (X_PDOUBLE) &(_D)); \
   }


#define U_BIF_GET_ARG_AS_VCHAR(_A, _V) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Get_as_Vchar(pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], sizeof(_V), _V); \
   }

#define U_BIF_GET_ARG_AS_WIDECHAR(_A, _V) \
      {                                                                          \
         if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE))    \
         {                                                                       \
            if ( X_VECTOR_STORED_AS_WIDECHAR( X_Fld, sInVec[_A] ) )              \
            {                                                                    \
               X_ULONG                                                           \
                  ulCurSize = 0;                                                 \
               X_UTF16_VCHAR  *                                                  \
                  pwcsTemp;                                                      \
               X_FLD_NCHAR                                                       \
                  NVarChar;                                                      \
               X_WIDECHAR_INIT( &NVarChar );                                     \
               X_Vec_Get_as_VarChar( pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], 'P', pX_NULL, (X_FLD_CHAR *)&NVarChar, pX_NULL ); \
               X_VAR_VarChar_GetAsUtf16Vchar( pX_Ids, pX_Pro, pX_Fun, (X_FLD_CHAR *)&NVarChar, &pwcsTemp );  \
               X_VAR_VarChar_GetUtf16CurSize( pX_Ids, pX_Pro, pX_Fun, (X_FLD_CHAR *)&NVarChar, &ulCurSize);  \
               _V = X_PDF_Allocate_Memory( pX_Ids, pX_Pro, pX_Fun, ((ulCurSize +  1) * sizeof( X_UTF16_VCHAR ) ) );              \
               memcpy( _V, pwcsTemp, (ulCurSize * sizeof( X_UTF16_VCHAR ) ) );      \
               _V[ ulCurSize ] = 0;                                              \
               X_VARCHAR_RELEASE( pX_Ids, pX_Pro, pX_Fun, &NVarChar )            \
            }                                                                    \
            else                                                                 \
            {                                                                    \
               X_PVCHAR                                                          \
                  pvchTemp;                                                      \
               X_SIZE                                                            \
                  ulCurSize = 0;                                                 \
               X_FLD_CHAR                                                        \
                  VarChar;                                                       \
               X_VARCHAR_INIT( &VarChar );                                       \
               X_Vec_Get_as_VarChar( pX_Ids, pX_Pro, pX_Fun, X_Fld, sInVec[_A], 'P', pX_NULL, &VarChar, pX_NULL ); \
               X_VAR_VarChar_GetAsVchar( pX_Ids, pX_Pro, pX_Fun, &VarChar, &pvchTemp ); \
               X_Remove_Blanks( pX_Ids, pX_Pro, pX_Fun, pvchTemp, X_STRIP_BLANKS_TRAILING ); \
               if ( UTC_INVALID_RESULT == UTC_MultiByteToWideChar( &Anchor,      \
                        UTC_NATIVE,                                                    \
                        pvchTemp,                                                      \
                        strlen( pvchTemp ),                                            \
                        &_V,                                                           \
                        &ulCurSize,                                                    \
                        X_BIF_Allocator,                                               \
                        UTC_CODEPAGE_DEFAULT ) )                                        \
               { \
                  _V = X_PDF_Allocate_Memory( pX_Ids, pX_Pro, pX_Fun, sizeof( X_UTF16_VCHAR ) );              \
               } \
               _V[ ulCurSize ] = 0;                                              \
               X_VARCHAR_RELEASE( pX_Ids, pX_Pro, pX_Fun, &VarChar )             \
            }                                                                    \
         }                                                                       \
      }



#define U_BIF_SET_RET_FROM_SHORT(_R, _S) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Short(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R],  X_SHORT_SIZE_T_CAST( _S )); \
   }


#define U_BIF_SET_RET_FROM_LONG(_R, _L) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Long(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R],  X_LONG_SIZE_T_CAST( _L )); \
   }

#define U_BIF_SET_RET_FROM_LONGLONG(_R, _L64) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_LongLong(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], _L64); \
   }


#define U_BIF_SET_RET_FROM_DOUBLE(_R, _D) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Double(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], _D); \
   }


#define U_BIF_SET_RET_FROM_VCHAR(_R, _V) \
   if ((_R >= 0) && (_R < sRetCount) && (sRetVec[_R] != V_NOT_AVAILABLE)) \
   { \
      X_Vec_Set_from_Vchar(pX_Ids, pX_Pro, pX_Fun, X_Fld, sRetVec[_R], (X_PVCHAR) _V); \
   }


#ifdef X_ALLOW_10_0_STRUCTURES

#define U_BIF_DECLARE_LIST_POINTER(_P) \
   struct X_LIST * _P = pX_NULL;

#define U_BIF_SET_ARG_LIST_POINTER(_L, _A) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      _L = &(((struct X_LIST *)X_List)[sInVec[_A]]); \
   } \
   else \
   { \
      U_BIF_ISSUE_FATAL_ERROR(U_BIF_LIST_ERROR); \
   }

#define U_BIF_SET_ARG_LIST_POINTER_OPTIONAL(_L, _A) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      _L = &(((struct X_LIST *)X_List)[sInVec[_A]]); \
   }

#define U_BIF_GET_LIST_CURRENT_ENTRYS(_L, _R) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   X_Set_Component_List_Entry_Count(pX_Ids,pX_Pro,pX_Fun,X_Fld,pUBIFWList,0); \
   _R = (X_SHORT)pUBIFWList->sCurrentEntrys; \
}

#define U_BIF_ADD_ENTRY_TO_LIST(_L) \
   X_Add_Entry (pX_Ids, pX_Pro, pX_Fun, X_Fld, pX_NULL, 0, _L, NO, NO, 'D', NO);


#define U_BIF_GET_ENTRY_FROM_LIST(_L, _E, _R) \
{ \
   X_CHAR chChanged = NO; \
   _R = X_Get_Entry_2 (pX_Ids, pX_Pro, pX_Fun, X_Fld, pX_NULL, 0, _L, _E, NO, &(chChanged)); \
   if (_R != NO) _R = YES; \
}

#define U_BIF_SET_RET_LIST_POINTER(_L, _A) \
   if ((_A >= 0) && (_A < sRetCount) && (sRetVec[_A] != V_NOT_AVAILABLE)) \
   { \
      _L = &(X_List[sRetVec[_A]]); \
   } \
   else \
   { \
      U_BIF_ISSUE_FATAL_ERROR(U_BIF_LIST_ERROR); \
   }

#define U_BIF_CLEAR_LIST(_L) \
   X_Drop_Entries (pX_Ids, pX_Pro, pX_Fun, X_Fld, 0, _L, NO);

#define U_BIF_GET_LIST_COLUMN_AS_LONG(_L, _C, _G) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Get_as_Long(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, &(_G)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_VCHAR(_L, _C, _V) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Get_as_Vchar(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, sizeof(_V), _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_SET_LIST_COLUMN_FROM_VCHAR(_L, _C, _V) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Set_from_Vchar(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_SET_LIST_COLUMN_FROM_SHORT(_L, _C, _V) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Set_from_Short(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_SHORT(_L, _C, _S) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Get_as_Short(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, &(_S)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_DOUBLE(_L, _C, _D) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Get_as_Double(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, &(_D)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}



#define U_BIF_SET_LIST_COLUMN_FROM_LONG(_L, _C, _V) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Set_from_Long(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}


#define U_BIF_SET_LIST_COLUMN_FROM_DOUBLE(_L, _C, _V) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_Vec_Set_from_Double(pX_Ids, pX_Pro, pX_Fun, pUBIFWList->pX_Fld, _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_UPDATE_ENTRY_IN_LIST(_L) \
   X_Upd_Entry (pX_Ids, pX_Pro, pX_Fun, X_Fld, pX_NULL, 0, _L, 'D', NO);

#define U_BIF_GET_LIST_MAXIMUM_ENTRYS(_L, _R) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   _R = pUBIFWList->sMaxEntrys; \
}


#define U_BIF_GET_LIST_ENTRY_LENGTH(_L, _R) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   _R = pUBIFWList->sEntryLength; \
}


#define U_BIF_GET_LIST_COLUMN_TOTAL(_L, _R) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   _R = pUBIFWList->sFld; \
}

#define U_BIF_GET_LIST_COLUMN_MAX_SIZE(_L, _C, _MS) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
     X_PDICTIONARY_FIELD  pField; \
     struct X_FLD *       pFld = &(pUBIFWList->pX_Fld[_C]); \
     X_GET_INDEX_DIRECT(pField, pFld, pFld, 0); \
     X_GET_FIELD_VALUE_MAX_SIZE(_MS, pField, pFld); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_MAX_SIZE_ONSCREEN(_L, _C, _MS) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
     struct X_FLD *       pFld1 = &(pUBIFWList->pX_Fld[_C]); \
     X_GET_FIELD_VALUE_MAX_SIZE_ONSCREEN(_MS, pFld1, 0); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_ATTRIBS(_L, _C, _T, _E, _D, _B) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
     struct X_FLD TempField; \
     if ( X_VECTOR_FIELD_IS_COMPONENT(pUBIFWList->pX_Fld, _C) ) \
        X_Convert_Component_to_Temp_Field(pX_Ids,pX_Pro,pX_Fun,&(pUBIFWList->pX_Fld[_C]),&(TempField)); \
     else \
        memcpy(&(TempField),&(pUBIFWList->pX_Fld[_C]),sizeof(TempField)); \
     _T = TempField.chType; \
     _E = TempField.sLen; \
     _D = TempField.sDec; \
     _B = TempField.sByteLen; \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_NAME(_L, _C, _R) \
{ \
   struct X_LIST * pUBIFWList = _L; \
   if ((_C >= 0) && (_C < pUBIFWList->sFld)) \
   { \
      X_SHORT sPos; \
      strncpy(_R,pUBIFWList->pX_Fld[_C].fchName2,U_BIF_LIST_COLUMN_NAME_LEN); \
      _R[U_BIF_LIST_COLUMN_NAME_LEN] = LOVAL; \
      for (sPos = strlen(_R) - 1; ((sPos >= 0) && (_R[sPos] == BLANK)); sPos--) \
      { \
         _R[sPos] = LOVAL; \
      } \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

/* --------------------------------------------------------------------------*/
#else /* X_ALLOW_10_0_STRUCTURES */

#define U_BIF_DECLARE_LIST_POINTER(_P) \
   X_DECLARE_NAMED_WORK_LISTS(_P) \

#define U_BIF_SET_ARG_LIST_POINTER(_L, _A) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_CAST_NAMED_LIST_FROM_NO( _L, X_List, sInVec[_A], pX_Fun ) \
   } \
   else \
   { \
      U_BIF_ISSUE_FATAL_ERROR(U_BIF_LIST_ERROR); \
   }

#define U_BIF_SET_ARG_LIST_POINTER_OPTIONAL(_L, _A) \
   if ((_A >= 0) && (_A < sInCount) && (sInVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_CAST_NAMED_LIST_FROM_NO( _L, X_List, sInVec[_A], pX_Fun ) \
   }

#define U_BIF_GET_LIST_CURRENT_ENTRYS(_L, _R) \
{ \
   X_Set_Component_List_Entry_Count(pX_Ids,pX_Pro,pX_Fun,X_Fld,( X_RDML2_IS_USED( pX_Fun ) \
		? (PX_LIST_VOID)_L##_2 \
      : (PX_LIST_VOID)_L##_1 ), 0); \
   _R = X_NAMED_LIST_COUNT_ENTRYS( _L ); \
}

/* Clears the buffer that stores the values of the current entry */
/* It does not effect the list itself. This is to ensure that    */
/* X_VAR field types are not released inadvertently.             */
/* Is almost always used as a pair with U_BIF_GET_ENTRY_FROM_LIST*/
/* Note that U_BIF_ADD_ENTRY_TO_LIST always calls this macro     */
/* If current entry values are still needed, use                 */
/* U_BIF_GET_ENTRY_FROM_LIST to retrieve them again.             */
#define U_BIF_CLEAR_X_VAR_FROM_CURRENTENTRY(_L)                                                                              \
{                                                                                                                 \
   X_LIST_COUNT _i;                                                                                               \
   struct X_FLD * _pX_Fld = X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld );                                            \
                                                                                                                  \
   if ( X_NAMED_LIST_COMMON_ELEMENT( _L, chType) != X_COMPONENT_LIST  )                                           \
   {                                                                                                              \
      /* Set all X_VAR pointers to NULL so they are not released by the next assignment into the pCurrentEntry */ \
                                                                                                                  \
      for ( _i = 0; _i < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ); _i++ )                                          \
      {                                                                                                           \
         /* Note that this code relies on the Field actually being */                                             \
         /* a real CHAR, not a component or evaluation variable so */                                             \
         /* X_VECTOR_FIELD_IS_... is used to ensure no corruption  */                                             \
         /* occurs, rather than X_VECTOR_STORED_AS_.               */                                             \
         if ( X_VECTOR_FIELD_IS_CHAR(_pX_Fld, _i ) )                                                              \
         {                                                                                                        \
            ((X_FLD_CHAR *) _pX_Fld[_i].pField)->pvData = NULL;                                                   \
         }                                                                                                        \
         else if ( X_VECTOR_FIELD_IS_BINARY(_pX_Fld, _i ) )                                                       \
         {                                                                                                        \
            ((X_FLD_BINARY *) _pX_Fld[_i].pField)->pvData = NULL;                                                 \
         }                                                                                                        \
      }                                                                                                           \
   }                                                                                                              \
}

#define U_BIF_ADD_ENTRY_TO_LIST(_L)                                                                               \
{                                                                                                                 \
   struct X_FLD * _pX_Fld = X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld );                                            \
                                                                                                                  \
   X_Add_Entry (pX_Ids, pX_Pro, pX_Fun, X_Fld, pX_NULL, 0, X_NAMED_LIST_PTR(_L), NO, NO, 'D', NO);                \
   U_BIF_CLEAR_X_VAR_FROM_CURRENTENTRY( _L )                                                                                 \
}

#define U_BIF_GET_ENTRY_FROM_LIST(_L, _E, _R) \
{ \
   X_CHAR chChanged = NO; \
   _R = X_Get_Entry_2 (pX_Ids, pX_Pro, pX_Fun, X_Fld, pX_NULL, 0, X_NAMED_LIST_PTR(_L), _E, NO, &(chChanged)); \
   if (_R != NO) _R = YES; \
}

#define U_BIF_SET_RET_LIST_POINTER(_L, _A) \
   if ((_A >= 0) && (_A < sRetCount) && (sRetVec[_A] != V_NOT_AVAILABLE)) \
   { \
      X_CAST_NAMED_LIST_FROM_NO( _L, X_List, sRetVec[_A], pX_Fun ) \
   } \
   else \
   { \
      U_BIF_ISSUE_FATAL_ERROR(U_BIF_LIST_ERROR); \
   }

#define U_BIF_CLEAR_LIST(_L) \
   X_Drop_Entries (pX_Ids, pX_Pro, pX_Fun, X_Fld, 0, X_NAMED_LIST_PTR( _L ), NO);

#define U_BIF_GET_LIST_COLUMN_AS_LONG(_L, _C, _G) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Get_as_Long(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, &(_G)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_LONGLONG(_L, _C, _G) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Get_as_LongLong(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, &(_G)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_VCHAR(_L, _C, _V) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Get_as_Vchar(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, sizeof(_V), _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

/* This macro allows the value of any field type to be returned as character data   */
/* X_FLD_CHAR *_Varchar is the buffer to hold the string. Mandatory.                */
/* X_PVCHAR _String is the value of the vector in a string form. Mandatory.         */
/*          It is assigned a value by the macro. Do not malloc memory.              */
/* X_PLONG _pLength is the length of that value, can be NULL                        */
/* Note that the last two parameters MUST be passed as there must be a variable     */
/* to assign to in the macro, but its value can be NULL.                            */
#define U_BIF_GET_LIST_COLUMN_AS_STRING(_L, _C, _pVarchar, _String, _pLength, _decPoint)                          \
{                                                                                                                 \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld )))                                               \
   {                                                                                                              \
      X_ULONG     _TempLength;                                                                                    \
      X_PVCHAR    _pvchVarchar;   /* Ptr to string in _pVarchar */                                                \
      /* Change the decimal point to internal value as it is not intended to be displayed */                      \
      X_CHAR chSaveDecimalPoint = pX_Ids->chDecimalPoint; /* Save decimal point value */                          \
      pX_Ids->chDecimalPoint  = _decPoint;                                                                        \
                                                                                                                  \
      X_Vec_Encode_as_String( pX_Ids,                                                                             \
                              pX_Pro,                                                                             \
                              pX_Fun,                                                                             \
                              X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ),                                          \
                              _C,                                                                                 \
                              X_STND_EDIT_CODE,                                                                   \
                              pX_NULL,                                                                            \
                              &_TempLength,                                                                       \
                              &_pvchVarchar,                                                                      \
                              _pVarchar,                                                                          \
                              pX_NULL,                                                                            \
                              X_ENCODE_FORMAT_ISO_8601 );                                                         \
      pX_Ids->chDecimalPoint = chSaveDecimalPoint;                                                                \
                                                                                                                  \
      _String = _pvchVarchar;                                                                                     \
                                                                                                                  \
      if ( _pLength )                                                                                             \
      {                                                                                                           \
         *_pLength = _TempLength;                                                                                 \
      }                                                                                                           \
   }                                                                                                              \
   else                                                                                                           \
   {                                                                                                              \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR);                                                                 \
   }                                                                                                              \
}

#define U_BIF_SET_LIST_COLUMN_FROM_STRING(_L, _C, _String, _pFieldState, _decPoint, _R)                  \
{                                                                                                        \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld )))                                      \
   {                                                                                                     \
      X_BOOL fIsSqlNull = FALSE;                                                                         \
                                                                                                         \
      if ( _pFieldState & FsIsSqlNull )                                                                  \
      {                                                                                                  \
         fIsSqlNull = TRUE;                                                                              \
         X_SET_FLD_INFO_IS_SQL_NULL( X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].pField );             \
         _R = 0;                                                                                         \
      }                                                                                                  \
      else                                                                                               \
      {                                                                                                  \
         /* Change the decimal point to internal value as it is not intended to be displayed */          \
         X_CHAR chSaveDecimalPoint = pX_Ids->chDecimalPoint; /* Save decimal point value */              \
         pX_Ids->chDecimalPoint  = _decPoint;                                                            \
         _R = X_Vec_Decode_from_String( pX_Ids,                                                          \
                                        pX_Pro,                                                          \
                                        pX_Fun,                                                          \
                                        X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ),                       \
                                        _C,                                                              \
                                        X_STND_EDIT_CODE,                                                \
                                        pX_NULL,                                                         \
                                        -1,                                                              \
                                        _String,                                                         \
                                        X_ENCODE_FORMAT_ISO_8601,                                        \
                                        FALSE);                                                          \
         pX_Ids->chDecimalPoint = chSaveDecimalPoint ;                                                   \
      }                                                                                                  \
   }                                                                                                     \
   else                                                                                                  \
   {                                                                                                     \
      U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR);                                                       \
   }                                                                                                     \
}

/* pFieldState, will set the SQL NULL state                                         */
/* This macro will be extended as necessary to set other field states.              */
/* Otherwise the field value is set to the passed _String                           */
// Macro does NOT execute return statement 
#define U_BIF_SET_LIST_COLUMN_FROM_STRING_NORET(_L, _C, _String, _pFieldState, _R)                       \
{                                                                                                        \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld )))                                      \
   {                                                                                                     \
      X_BOOL fIsSqlNull = FALSE;                                                                         \
                                                                                                         \
      if ( _pFieldState & FsIsSqlNull )                                                                  \
      {                                                                                                  \
         fIsSqlNull = TRUE;                                                                              \
         X_SET_FLD_INFO_IS_SQL_NULL( X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].pField );             \
         _R = 0;                                                                                         \
      }                                                                                                  \
      else                                                                                               \
      {                                                                                                  \
         /* Change the decimal point to internal value as it is not intended to be displayed */          \
         X_CHAR chSaveDecimalPoint = pX_Ids->chDecimalPoint; /* Save decimal point value */              \
         pX_Ids->chDecimalPoint  = DECIMAL_POINT;                                                        \
         _R = X_Vec_Decode_from_String( pX_Ids,                                                          \
                                        pX_Pro,                                                          \
                                        pX_Fun,                                                          \
                                        X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ),                       \
                                        _C,                                                              \
                                        X_STND_EDIT_CODE,                                                \
                                        pX_NULL,                                                         \
                                        -1,                                                              \
                                        _String,                                                         \
                                        X_ENCODE_FORMAT_ISO_8601,                                        \
                                        FALSE);                                                          \
         pX_Ids->chDecimalPoint = chSaveDecimalPoint ;                                                   \
      }                                                                                                  \
   }                                                                                                     \
   else                                                                                                  \
   {                                                                                                     \
     X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, U_BIF_COLUMN_ERROR);                    \
   }                                                                                                     \
}

#define U_BIF_SET_LIST_COLUMN_FROM_UTF16_STRING(_L, _C, _UTF16_String, _pFieldState, _R)                 \
{                                                                                                        \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld )))                                      \
   {                                                                                                     \
      X_BOOL fIsSqlNull = FALSE;                                                                         \
                                                                                                         \
      if ( _pFieldState & FsIsSqlNull )                                                                  \
      {                                                                                                  \
         fIsSqlNull = TRUE;                                                                              \
         X_SET_FLD_INFO_IS_SQL_NULL( X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].pField );             \
         _R = 0;                                                                                         \
      }                                                                                                  \
      else                                                                                               \
      {                                                                                                  \
         /* Change the decimal point to internal value as it is not intended to be displayed */          \
         X_CHAR chSaveDecimalPoint = pX_Ids->chDecimalPoint; /* Save decimal point value */              \
         pX_Ids->chDecimalPoint  = DECIMAL_POINT;                                                        \
         _R = X_Vec_Decode_from_UTF16_String( pX_Ids,                                                    \
                                        pX_Pro,                                                          \
                                        pX_Fun,                                                          \
                                        X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ),                       \
                                        _C,                                                              \
                                        X_STND_EDIT_CODE,                                                \
                                        pX_NULL,                                                         \
                                        -1,                                                              \
                                        _UTF16_String,                                                   \
                                        X_ENCODE_FORMAT_ISO_8601,                                        \
                                        FALSE);                                                          \
         pX_Ids->chDecimalPoint = chSaveDecimalPoint ;                                                   \
      }                                                                                                  \
   }                                                                                                     \
   else                                                                                                  \
   {                                                                                                     \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR);                                                        \
   }                                                                                                     \
}
/* pFieldState, will set the SQL NULL state                                         */
/* This macro will be extended as necessary to set other field states.              */
/* Otherwise the field value is set to the passed _String                           */
// Macro does NOT execute return statement
#define U_BIF_SET_LIST_COLUMN_FROM_UTF16_STRING_NORET(_L, _C, _UTF16_String, _pFieldState, _R)           \
{                                                                                                        \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld )))                                      \
   {                                                                                                     \
      X_BOOL fIsSqlNull = FALSE;                                                                         \
                                                                                                         \
      if ( _pFieldState & FsIsSqlNull )                                                                  \
      {                                                                                                  \
         fIsSqlNull = TRUE;                                                                              \
         X_SET_FLD_INFO_IS_SQL_NULL( X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].pField );             \
         _R = 0;                                                                                         \
      }                                                                                                  \
      else                                                                                               \
      {                                                                                                  \
         /* Change the decimal point to internal value as it is not intended to be displayed */          \
         X_CHAR chSaveDecimalPoint = pX_Ids->chDecimalPoint; /* Save decimal point value */              \
         pX_Ids->chDecimalPoint  = DECIMAL_POINT;                                                        \
         _R = X_Vec_Decode_from_UTF16_String( pX_Ids,                                                    \
                                        pX_Pro,                                                          \
                                        pX_Fun,                                                          \
                                        X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ),                       \
                                        _C,                                                              \
                                        X_STND_EDIT_CODE,                                                \
                                        pX_NULL,                                                         \
                                        -1,                                                              \
                                        _UTF16_String,                                                   \
                                        X_ENCODE_FORMAT_ISO_8601,                                        \
                                        FALSE);                                                          \
         pX_Ids->chDecimalPoint = chSaveDecimalPoint ;                                                   \
      }                                                                                                  \
   }                                                                                                     \
   else                                                                                                  \
   {                                                                                                     \
     X_Fatal_Error(pX_Ids, pX_Pro, pX_Fun, U_BIF_LANSA_FUNCTION, U_BIF_COLUMN_ERROR );                   \
   }                                                                                                     \
}


#define U_BIF_SET_LIST_COLUMN_FROM_VCHAR(_L, _C, _V) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Set_from_Vchar(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_SET_LIST_COLUMN_FROM_SHORT(_L, _C, _V) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Set_from_Short(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_SHORT(_L, _C, _S) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Get_as_Short(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, &(_S)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_AS_DOUBLE(_L, _C, _D) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Get_as_Double(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, &(_D)); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}



#define U_BIF_SET_LIST_COLUMN_FROM_LONG(_L, _C, _V) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Set_from_Long(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_SET_LIST_COLUMN_FROM_LONGLONG(_L, _C, _V) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Set_from_LongLong(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_SET_LIST_COLUMN_FROM_DOUBLE(_L, _C, _V) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      X_Vec_Set_from_Double(pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C, _V); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_UPDATE_ENTRY_IN_LIST(_L) \
   X_Upd_Entry (pX_Ids, pX_Pro, pX_Fun, X_Fld, pX_NULL, 0, X_NAMED_LIST_PTR( _L ), 'D', NO);

#define U_BIF_GET_LIST_MAXIMUM_ENTRYS(_L, _R) \
{ \
   _R = X_NAMED_LIST_MAX_ENTRYS( _L ); \
}


#define U_BIF_GET_LIST_ENTRY_LENGTH(_L, _R) \
{ \
   _R = X_NAMED_LIST_ENTRY_LENGTH( _L ); \
}


#define U_BIF_GET_LIST_COLUMN_TOTAL(_L, _R) \
{ \
   _R = X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ); \
}

#define U_BIF_GET_LIST_COLUMN_MAX_SIZE(_L, _C, _MS) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
     X_PDICTIONARY_FIELD  pField; \
     struct X_FLD *       pFld = &(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[ _C ]); \
     X_GET_INDEX_DIRECT(pField, pFld, pFld, 0); \
     X_GET_FIELD_VALUE_MAX_SIZE(_MS, pField, pFld); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_MAX_SIZE_ONSCREEN(_L, _C, _MS) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
     struct X_FLD *       pFld1 = &(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[ _C ]); \
     X_GET_FIELD_VALUE_MAX_SIZE_ONSCREEN(_MS, pFld1, 0); \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_ATTRIBS(_L, _C, _T, _E, _D, _B) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
     struct X_FLD TempField; \
     if ( X_VECTOR_FIELD_IS_COMPONENT(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C) ) \
        X_Convert_Component_to_Temp_Field(pX_Ids,pX_Pro,pX_Fun,&(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C]),&(TempField)); \
     else \
        memcpy(&(TempField),&(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C]),sizeof(TempField)); \
     _T = TempField.chType; \
     _E = TempField.sLen; \
     _D = TempField.sDec; \
     _B = TempField.sByteLen; \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_ATTRIBS_EX(_L, _C, _T, _E, _D, _B, _FieldState) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      struct X_FLD TempField; \
      if ( X_VECTOR_FIELD_IS_COMPONENT(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C) ) \
         X_Convert_Component_to_Temp_Field(pX_Ids,pX_Pro,pX_Fun,&(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C]),&(TempField)); \
      else \
         memcpy(&(TempField),&(X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C]),sizeof(TempField)); \
      _T = TempField.chType; \
      _E = TempField.sLen; \
      _D = TempField.sDec; \
      _B = TempField.sByteLen; \
      if ( X_VECTOR_FIELD_IS_LL2( (&TempField), 0) )  _FieldState = ((X_FLD_INFO*)( TempField.pField ))->bFieldState; \
   } \
   else \
   { \
      U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_NAME(_L, _C, _R) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      size_t sPos; \
      strncpy(_R,X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].fchName2,U_BIF_LIST_COLUMN_NAME_LEN); \
      _R[U_BIF_LIST_COLUMN_NAME_LEN] = LOVAL; \
      for (sPos = strlen(_R) - 1; ((sPos >= 0) && (_R[sPos] == BLANK)); sPos--) \
      { \
         _R[sPos] = LOVAL; \
      } \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_FIELDINFO(_L, _C, _R) \
{ \
   if ((_C >= 0) && (_C < X_NAMED_LIST_COMMON_ELEMENT( _L, sFld ))) \
   { \
      _R = X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].chFieldInfo; \
   } \
   else \
   { \
     U_BIF_ISSUE_FATAL_ERROR(U_BIF_COLUMN_ERROR); \
   } \
}

#define U_BIF_GET_LIST_COLUMN_FIELDSTATE(_L, _C, _F) \
{ \
   if ( X_VECTOR_FIELD_IS_LL2( X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld ), _C ) )             \
   {                                                                                         \
      _F = ((PX_FLD_INFO)X_NAMED_LIST_COMMON_ELEMENT( _L, pX_Fld )[_C].pField)->bFieldState; \
   }                                                                                         \
   else                                                                                      \
   {                                                                                         \
      _F = (XFIELDSTATE)0x00;                                                                \
   }                                                                                         \
}

#endif /* X_ALLOW_10_0_STRUCTURES */
/* --------------------------------------------------------------------------*/

#define U_BIF_LIST_COLUMN_NAME_LEN   10

#define X_SAVED_LIST_V2                   2

#define X_RDMLX_SAVED_LIST_RECORD_TYPE_0  0
#define X_RDMLX_SAVED_LIST_RECORD_TYPE_1  1
#define X_RDMLX_SAVED_LIST_RECORD_TYPE_2  2

/* ================================================================= */
/*  X_SAVED_RDMLX_LIST_RECORD_0:                                     */
/*                                          Holds a header for a     */
/*                         saved RDMLX list (RECORD TYPE 0 )         */
/* Name            Description                                       */
/* ----            -----------                                       */
/* fRDMLList      RDML list flag.TRUE if RDML list else FALSE.       */
/*                That is, RDMLX lists set this value to 0,          */
/*                which is not a valid value in an LL1 list as       */
/*                it is converted to 0xFF                            */
/* sSavedListVersion                                                 */
/*                Saved list version number.                         */
/*                Initially X_SAVED_LIST_V2                          */
/* sX_ListVersion List version number.                               */
/*                Initially X_LIST_V2                                */
/* ================================================================= */
struct X_SAVED_RDMLX_LIST_RECORD_0
{
   X_BOOL                        fRDMLList;
   X_SHORT                       sSavedListVersion;
   X_SHORT                       sX_ListVersion;
   X_SHORT                       sFld;
};

/* ================================================================= */
/*  X_SAVED_RDMLX_LIST_RECORD_1:                                     */
/*                Holds a record type 1 of                           */
/*                         saved RDMLX list (RECORD TYPE 1 )         */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Btype          Record Type.Always 1.                              */
/* vbCurrentEntry  Current Entry value. Length of this value is       */
/*                written to X80BSZ. pvData pointers in field type   */
/*                values that require an X_VAR structure are         */
/*                meaningless                                        */
/* ================================================================= */
struct X_SAVED_RDMLX_LIST_RECORD_1
{
   X_BYTE                        Btype;
};

/* ================================================================= */
/*  X_SAVED_RDMLX_LIST_RECORD_2:                                     */
/*                Holds a record type 1 of                           */
/*                         saved RDMLX list (RECORD TYPE 1 )         */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Btype          Record Type.Always 2.                              */
/* ulCurSize      Variable data value length.The only optional       */
/*                record. This record type exists for each           */
/*                vbCurrentEntry if the field type requires an       */
/*                X_VAR to store it. E.g. X_TYPE_CHAR. If            */
/*                pvData = pX_NULL, or the current length is 0,      */
/*                this value is 0                                    */
/* vbData         ulCurSize bytes.                                   */
/* ================================================================= */
struct X_SAVED_RDMLX_LIST_RECORD_2
{
   X_BYTE       Btype;
   X_ULONG      vbCurSize;
};

#define X_DATA_QUEUE_V2 2

/* ================================================================= */
/*  X_RDMLX_DATA_QUEUE_0:                                            */
/*                                          Holds a header for a     */
/*                         saved RDMLX list (RECORD TYPE 0 )         */
/*                in the data queue                                  */
/* Name            Description                                       */
/* ----            -----------                                       */
/* fRDMLList      RDML list flag.TRUE if RDML list else FALSE.       */
/*                That is, RDMLX lists set this value to 0,          */
/*                which is not a valid value in an LL1 list as       */
/*                it is converted to 0xFF                            */
/* sDataQueueVersion                                                 */
/*                Saved list version number.                         */
/*                Initially X_SAVED_LIST_V2                          */
/* sX_ListVersion List version number.                               */
/*                Initially X_LIST_V2                                */
/* ================================================================= */
struct X_RDMLX_DATA_QUEUE_0
{
   X_BOOL                        fRDMLList;
   X_SHORT                       sDataQueueVersion;
   X_SHORT                       sX_ListVersion;
   X_SHORT                       sFld;
   X_LONG                        lListEntrySize;   /* the size of an entry in the list */
};

/*********************************************************************/
/*                                                                   */
/* Macro U_BIF_REALLOCATE_BUFFER                                     */
/*                                                                   */
/* Description: Reallocate the buffer if the required mem is bigger  */
/*              than the current one                                 */
/*                                                                   */
 /*********************************************************************/
#define U_BIF_REALLOCATE_MEM( P_MEM, REQUIRED_MEM_SIZE , CURRENT_MEM_SIZE )  \
{  \
   if ( REQUIRED_MEM_SIZE > CURRENT_MEM_SIZE ) \
   {  \
      P_MEM = X_PDF_ReAllocate_Memory(  pX_Ids, \
                                        pX_NULL, \
                                        pX_NULL, \
                                        P_MEM, \
                                        REQUIRED_MEM_SIZE);\
      U_BIF_CHECK_FATAL_ERROR();\
      CURRENT_MEM_SIZE  = REQUIRED_MEM_SIZE;\
   } \
}

X_ULONG_INTERNAL_FUNCTION SetUpRDMLXListX_VARData( struct X_IDS *,
                                                   struct X_PRO *,
                                                   struct X_FUN *,
                                                   struct X_FLD *,
                                                   X_PVOID  ,
                                                   X_PVCHAR ,
                                                   X_PVCHAR *, 
                                                   X_PBOOL );


/******************************************************************************/
/*                                                                            */
/* Macro U_BIF_ISSUE_ERROR_IF_LL2                                             */
/*                                                                            */
/* Description: Issue fatal error 920 if given list contains LL2 fields       */
/*             List num is the index of the given list )                      */
/*                                                                            */
 /*****************************************************************************/
#define U_BIF_ISSUE_ERROR_IF_LL2( _LIST_NUM )  \
{  \
   if( X_List_Uses_LL2_Field_Type(  pX_Ids, pX_Pro, pX_Fun, X_List, _LIST_NUM ) ) \
   {\
      U_BIF_ISSUE_FATAL_ERROR_PARM1(X_TEXT(920) , X_LIST_COMMON_ELEMENT( vchName ) )\
   }\
}

/*********************************************************************/
/*                                                                   */
/* Macro U_BIF_ISSUE_ERROR_IF_LL2_PTR                                */
/*                                                                   */
/* Description: Issue error 920 if given list contains LL2 fields    */
/*             _PTR is the pointer to the given list                 */
/*                                                                   */
/*********************************************************************/
#define U_BIF_ISSUE_ERROR_IF_LL2_PTR( _PTR )  \
{  \
   if( X_List_Uses_LL2_Field_Type(  pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_PTR(_PTR), 0 ) ) \
   {\
      U_BIF_ISSUE_FATAL_ERROR_PARM1(X_TEXT(920) , X_NAMED_LIST_COMMON_ELEMENT(_PTR,vchName)  )\
   }\
}

#define U_BIF_ISSUE_ERROR_IF_LL2_PTR_RET( _PTR, _RET )  \
{  \
   if( X_List_Uses_LL2_Field_Type(  pX_Ids, pX_Pro, pX_Fun, X_NAMED_LIST_PTR(_PTR), 0 ) ) \
   {\
      U_BIF_ISSUE_FATAL_ERROR_PARM1_RET(X_TEXT(920) , X_NAMED_LIST_COMMON_ELEMENT(_PTR,vchName), _RET  )\
   }\
}

#ifdef X_OPERATING_SYSTEM_WIN
/***********************************************************************/
/*                                                                     */
/* Macro U_BIF_IS_IT_LL2                                               */
/*                                                                     */
/* Description: Check if the object is LL2 or not                      */
/* will not call "return"  . It is used for Specialised BIFs.          */
/*                                                                     */
/* _OBJTYP      Object Type                                            */
/* _OBJ         Object Name                                            */
/* _OBJEXT      Object Extension                                       */
/* _ISLL2       should be set to FALSE by the caller                   */
/***********************************************************************/

#define U_BIF_IS_IT_LL2(_OBJTYP, _OBJ, _OBJEXT, _ISLL2 ) \
   if ( IsLL2Object( U_BIF_STANDARD_ARGUMENTS, _OBJTYP, _OBJ, _OBJEXT)) \
   { \
      _ISLL2 = TRUE; \
   }
#else

#define U_BIF_IS_IT_LL2(_OBJTYP, _OBJ, _OBJEXT, _ISLL2 )

#endif

#ifdef X_OPERATING_SYSTEM_WIN
/***********************************************************************/
/*                                                                     */
/* Macro U_BIF_NON_FATAL_IF_LL2                                        */
/*                                                                     */
/* Description: Issue non Fatal error if the given object is LL2. This */
/*              macro is used for Specialised BIFs                     */
/*                                                                     */
/* _OBJTYP      Object Type                                            */
/* _OBJ         Object Name                                            */
/* _OBJEXT      Object Extension                                       */
/* _ERR         Error ID ( from LX_MSG )                               */
/***********************************************************************/

#define U_BIF_NON_FATAL_IF_LL2(_OBJTYP, _OBJ, _OBJEXT, _ERR ) \
   if ( IsLL2Object( U_BIF_STANDARD_ARGUMENTS, _OBJTYP, _OBJ, _OBJEXT)) \
   {  \
      X_Issue_Message_VChar(  pX_Ids, pX_Pro, pX_Fun, \
                              pX_Ids->vchStandardMessageFile,  \
                              _ERR, \
                              _OBJ);   \
      U_BIF_SET_RET_FROM_VCHAR(0, "ER");\
      return ;\
   }
#else
/* Just a dummy so the code will be easier to read */
#define U_BIF_NON_FATAL_IF_LL2( _OBJTYP, _OBJ, _OBJEXT, _ERR )
#endif

#ifdef X_OPERATING_SYSTEM_WIN

/***********************************************************************/
/*                                                                     */
/* Macro U_BIF_NON_FATAL_IF_LL2_RET                                    */
/*                                                                     */
/* Description: Issue non Fatal error if the given object is LL2. This */
/*              macro will return _RET . It is used for Specialised    */
/*              BIFs.                                                  */
/*                                                                     */
/* _OBJTYP      Object Type                                            */
/* _OBJ         Object Name                                            */
/* _OBJEXT      Object Extension                                       */
/* _ERR         Error ID ( from LX_MSG )                               */
/* _RET         FALSE or TRUE                           */
/***********************************************************************/

#define U_BIF_NON_FATAL_IF_LL2_RET(_OBJTYP, _OBJ, _OBJEXT, _ERR , _RET ) \
   if ( IsLL2Object( U_BIF_STANDARD_ARGUMENTS, _OBJTYP, _OBJ, _OBJEXT)) \
   { \
      X_Issue_Message_VChar(pX_Ids, pX_Pro, pX_Fun, \
                            pX_Ids->vchStandardMessageFile, \
                            _ERR, \
                            _OBJ); \
      U_BIF_SET_RET_FROM_VCHAR(0, "ER");\
      return (_RET); \
   }
#else

#define U_BIF_NON_FATAL_IF_LL2_RET ( _OBJTYP, _OBJ, _OBJEXT, _ERR , _RET )

#endif

#ifdef X_OPERATING_SYSTEM_WIN

/***********************************************************************/
/*                                                                     */
/* Macro U_BIF_NON_FATAL_IF_LL2_RET                                    */
/*                                                                     */
/* Description: Issue non Fatal error if the given object is LL2. This */
/*              macro will set _ISLL2 to TRUE if the object is LL2, and*/
/* will not call "return"  . It is used for Specialised BIFs.          */
/*                                                                     */
/* _OBJTYP      Object Type                                            */
/* _OBJ         Object Name                                            */
/* _OBJEXT      Object Extension                                       */
/* _ERR         Error ID ( from LX_MSG )                               */
/* _ISLL2       should be set to FALSE by the caller                   */
/***********************************************************************/

#define U_BIF_NON_FATAL_IF_LL2_NOT_RET(_OBJTYP, _OBJ, _OBJEXT, _ERR , _ISLL2 ) \
   if ( IsLL2Object( U_BIF_STANDARD_ARGUMENTS, _OBJTYP, _OBJ, _OBJEXT)) \
   { \
      X_Issue_Message_VChar(pX_Ids, pX_Pro, pX_Fun, \
                            pX_Ids->vchStandardMessageFile, \
                            _ERR, \
                            _OBJ); \
      U_BIF_SET_RET_FROM_VCHAR(0, "ER");\
      _ISLL2 = TRUE; \
   }
#else

#define U_BIF_NON_FATAL_IF_LL2_NOT_RET ( _OBJTYP, _OBJ, _OBJEXT, _ERR , _ISLL2 )

#endif


#endif // #ifndef __INCL_X_BIF000_H__
