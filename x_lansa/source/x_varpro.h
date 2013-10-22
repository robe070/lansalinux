/* ================================================================= */
/* === VISUAL LANSA VARIANT EXPRESSION FUNCTION PROTOTYPES      ==== */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_VARPRO.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : Variant Expression function prototypes      */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*                                                                   */
/* ================================================================= */

#ifndef _X_VARPRO_H
#define _X_VARPRO_H

#ifdef __cplusplus
extern "C" {
#endif

/* ================================================================= */
/*  X_OIDPDF.C functions                                             */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Get_Build_Number;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_Get_Build_Number                 ( void );

/* ================================================================= */
/*  X_VarFrame.c functions                                           */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_InitGlobals;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_InitGlobals                      (  
      struct X_IDS                        *  pX_Ids );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_FreeGlobals;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_FreeGlobals                      (  
      struct X_IDS                        *  pX_Ids );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_InitializeComponentFrame;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_InitializeComponentFrame         (  
      struct X_IDS                        *  pX_Ids,
      X_COMP_MODULE_FRAME                 *  pModuleFrame,
      X_VAR_FRAME                         *  pFrame );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_InitializeFunctionFrame;
#endif
X_VOID_FUNCTION_MS_CDECL
   X_VAR_InitializeFunctionFrame          (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      struct X_LIST                       *  pX_List,
      struct X_FKEY                       *  X_FKey,
      struct FUNCTION_STATIC_GLOBAL_1     *  pGlobal1,
      struct FUNCTION_STATIC_GLOBAL_2     *  pGlobal2,
      X_VAR_FRAME                         *  pFrame );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_InitializeOAMFrame;
#endif
X_VOID_FUNCTION_MS_CDECL
   X_VAR_InitializeOAMFrame               (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      struct X_DBM                        *  pX_DBM,
      void                                *  pGlobalInfo,
      X_VAR_FRAME                         *  pFrame );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_InitializeOAMPreviousFrame;
#endif
X_VOID_FUNCTION_MS_CDECL
   X_VAR_InitializeOAMPreviousFrame       (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      struct X_FLD                        *  pX_FldPrev,
      struct X_DBM                        *  pX_DBM,
      void                                *  pGlobalInfo,
      X_VAR_FRAME                         *  pFrame );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_InitializeChildFrame;
#endif
X_VOID_FUNCTION_MS_CDECL
   X_VAR_InitializeChildFrame             (  
      X_VAR_FRAME                         *  pParentFrame,
      X_VAR_FRAME                         *  pChildFrame );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_TerminateFrame;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_TerminateFrame                   (  
      X_VAR_FRAME                         *  pFrame ); 

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFramePrecision;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFramePrecision                (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lDigits,
      X_LONG                                 lDecimals );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFrameRoundingPrecision;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFrameRoundingPrecision        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lDecimals );

/* ================================================================= */
/*  X_VarFactor.c functions                                          */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorToNull;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorToNull                  (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorToSqlNull;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorToSqlNull               (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromLong;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromLong                (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      X_LONG                                 lValue );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromDouble;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromDouble              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      X_DOUBLE                               dValue );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromDecimal;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromDecimal             (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      const X_VCHAR                       *  pvchValue );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromLongLong;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromLongLong            (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      const X_VCHAR                       *  pvchValue );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromBoolean;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromBoolean             (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      X_BOOL                                 bValue );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromVarChar;
#endif
X_VOID_FUNCTION_MS_CDECL   
   X_VAR_SetFactorFromVarChar             (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      const X_VCHAR                       *  pvchValue );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromVector;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromVector              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromSysVar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromSysVar              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sSysVarVector,
      X_VCHAR                             *  pvchSysVarPgm );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorFromEvaluation;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorFromEvaluation          (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFactorAsDispatchOperation;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFactorAsDispatchOperation     (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      X_COMP_DISPATCH_ID                     lDispatchId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GetFactor;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_GetFactor                        (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      X_VAR_HEADER                        *  pFactor );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GetFactorAsString;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_GetFactorAsString                (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      X_FLD_CHAR                          *  pX_FldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GetFactorAsBoolean;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_GetFactorAsBoolean               (
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GetFactorAsConditionalBoolean;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_GetFactorAsConditionalBoolean    (
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId );

/* ================================================================= */
/*  X_VarEvaluations.c functions                                     */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_EvaluateExpression;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_EvaluateExpression         (  
      X_VAR_EXPRESSION_FRAME        *  pFrame );

/* ================================================================= */
/*  X_VarOperation.c functions                                       */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_AssignFactor;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_AssignFactor                     (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFromId,
      X_VAR_FACTOR                           lToId,
      X_VAR_ROUNDING_OPERATION               fOperation );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_AssignReferenceFactor;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_AssignReferenceFactor            (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFromId,
      X_VAR_FACTOR                           lToId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_AssignFactorToVector;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_AssignFactorToVector             (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lFactorId,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector,
      X_VAR_ROUNDING_OPERATION               fOperation );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_LogicalOr;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_LogicalOr                        (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_LogicalAnd;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_LogicalAnd                       (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BooleanCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_BooleanCompare                   (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BooleanIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_BooleanIntrinsic                 (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GeneralIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_GeneralIntrinsic                 (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

/* ================================================================= */
/*  X_VarOperations.c functions : FldData Exchange support functions */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GetFldDataUsingDispatchOperation;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_GetFldDataUsingDispatchOperation (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFldDataUsingDispatchOperation;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFldDataUsingDispatchOperation (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_GetFldDataUsingGenericVarHeader;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_GetFldDataUsingGenericVarHeader  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector,
      X_VAR_HEADER                        *  pVarHeader );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_SetFldDataUsingGenericVarHeader;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_SetFldDataUsingGenericVarHeader  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector,
      X_VAR_HEADER                        *  pVarHeader );


#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_ResolveEvaluationVariable;
#endif
struct X_FLD* X_FUNTYPE
   X_VAR_ResolveEvaluationVariable        (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_IsEvaluationVariableOfFieldType;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_IsEvaluationVariableOfFieldType  (
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sFieldVector,
      X_CHAR                                 chFirst, ...  ); 

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DispatchRecordServiceRequest;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_DispatchRecordServiceRequest     (
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sVector,
      X_COMP_RECORD_SERVICE_REQUEST          lRequest,
      void                                *  apvAgreedArgs[] );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_ProcessRecordServiceRequest;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_ProcessRecordServiceRequest      (
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      struct X_FLD                        *  pX_Fld,
      X_SHORT                                sVector,
      X_COMP_RECORD_SERVICE_REQUEST          lRequest,
      void                                *  apvAgreedArgs[] );

/* ================================================================= */
/*  X_VarNumerics.c functions                                        */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericAdd;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumericAdd                       (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericDivide;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumericDivide                    (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericMultiply;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumericMultiply                  (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericSubtract;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumericSubtract                  (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_NumericCompare                   (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberMin;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberMin                        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberMax;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberMax                        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberInc;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberInc                        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberDec;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberDec                        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberPred;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberPred                       (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberSucc;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberSucc                       (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberRound;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberRound                      (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberConversion;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberConversion                 (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberExamine;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberExamine                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_IntegerBitOr;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_IntegerBitOr                     (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_IntegerBitAnd;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_IntegerBitAnd                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_IntegerBitNot;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_IntegerBitNot                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_IntegerBitXor;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_IntegerBitXor                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumberIntrinsic                  (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericInt32Compare;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_NumericInt32Compare              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericInt64Compare;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_NumericInt64Compare              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumericFloatCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_NumericFloatCompare              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_NumberFloatIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_NumericFloatIntrinsic            (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

/* ================================================================= */
/*  X_VarStrings.c functions                                         */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringConcatenate;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringConcatenate                (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectId,
      X_VAR_FACTOR                           lObjectId,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Substring;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Substring                        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringCurSize;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringCurSize                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_StringCompare                    (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringTrim;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringTrim                       (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringConcat;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringConcat                     (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringSearch;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringSearch                     (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringConversion;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringConversion                 (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringExamine;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringExamine                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_StringIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_StringIntrinsic                  (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_CallIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_CallIntrinsic                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

/* ================================================================= */
/*  X_VarVariant.c functions                                         */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantAdd;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VariantAdd                       (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantDivide;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VariantDivide                    (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantMultiply;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VariantMultiply                  (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantSubtract;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VariantSubtract                  (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_VariantCompare                   (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectId,
      X_VAR_FACTOR                           lObjectId,
      X_VAR_FACTOR                           lResultId,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantType;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VariantType                      (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VariantAs;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VariantAs                        (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );


/* ================================================================= */
/*  X_Var Char/FixedChar/VarChar/ShortChar support functions         */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_GetAsVchar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_GetAsVchar               (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_VCHAR                             ** ppvchString );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_GetAsUtf16Vchar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_GetAsUtf16Vchar          (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_UTF16_VCHAR                       ** ppvchString );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_GetAsFixedChar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_GetAsFixedChar           (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldCharSource,
      X_CHAR                              *  pchTarget,
      X_LONG                                 lSize );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_GetCurSize;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_GetCurSize               (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_ULONG                             *  pulCurSize );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_GetUtf16CurSize;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_GetUtf16CurSize          (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_ULONG                             *  pulCurSize );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_SetFromVchar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_SetFromVchar             (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      const X_VCHAR                       *  pvchSource,
      X_FLD_CHAR                          *  pX_FldCharTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_SetFromChar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_SetFromChar              (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_CHAR                              *  pchSource,
      X_LONG                                 lSize,
      X_FLD_CHAR                          *  pX_FldCharTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_SetFromUtf16Char;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_SetFromUtf16Char         (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_UTF16_VCHAR                       *  pchSource,
      X_LONG                                 lSize,
      X_FLD_CHAR                          *  pX_FldCharTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_SetFromFixedChar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_SetFromFixedChar         (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_CHAR                              *  pchSource,
      X_LONG                                 lSize,
      X_FLD_CHAR                          *  pX_FldCharTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_SetFromUtf16FixedChar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_SetFromUtf16FixedChar    (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_UTF16_VCHAR                       *  pchSource,
      X_LONG                                 lSize,
      X_FLD_CHAR                          *  pX_FldCharTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Assign;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Assign                   (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldCharSource,
      X_FLD_CHAR                          *  pX_FldCharTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Release;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Release                  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Repeat;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Repeat                   (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VCHAR                             *  pvchSource,
      X_LONG                                 lRepeatCount,
      X_FLD_CHAR                          *  pX_FldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Reverse;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Reverse                  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Concatenate;
#endif
X_ULONG_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Concatenate              (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VCHAR                             *  pvchSourceString,
      X_ULONG                                ulSourceStringSize,
      X_FLD_CHAR                          *  pX_SourceFldChar,
      X_FLD_CHAR                          *  pX_TargetFldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_TConcatenate;
#endif
X_ULONG_FUNCTION_MS_CDECL  
   X_VAR_VarChar_TConcatenate             (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VCHAR                             *  pvchSourceString,
      X_ULONG                                ulSourceStringSize,
      X_FLD_CHAR                          *  pX_SourceFldChar,
      X_FLD_CHAR                          *  pX_TargetFldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_BConcatenate;
#endif
X_ULONG_FUNCTION_MS_CDECL  
   X_VAR_VarChar_BConcatenate             (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VCHAR                             *  pvchSourceString,
      X_ULONG                                ulSourceStringSize,
      X_FLD_CHAR                          *  pX_SourceFldChar,
      X_FLD_CHAR                          *  pX_TargetFldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Substring;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Substring                (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_SourceFldChar,
      X_ULONG                                ulSourceStart,
      X_ULONG                                ulSourceLth,
      X_FLD_CHAR                          *  pX_TargetFldChar,
      X_ULONG                                ulTargetStart,
      X_ULONG                                ulTargetLth );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_RemoveBlanks;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_RemoveBlanks             (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_USHORT                               usType);

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Quote;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_Quote                    (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_BOOL                                 fRemoveBlanks );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Compare;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_VarChar_Compare                  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_SubjectFldChar,
      X_FLD_CHAR                          *  pX_ObjectFldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_StringCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_VarChar_StringCompare            (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_CHAR                              *  pchSubject,
      X_LONG                                 lSubjectSize,
      X_FLD_CHAR                          *  pX_SubjectFldChar,
      X_CHAR                              *  pchObject,
      X_LONG                                 lObjectSize,
      X_FLD_CHAR                          *  pX_ObjectFldChar,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_Index;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_VarChar_Index                    (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_SubjectFldChar,
      X_LONG                                 lStartPosition,
      X_FLD_CHAR                          *  pX_ObjectFldChar );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_AnalyzeString;
#endif
X_ULONG_FUNCTION_MS_CDECL  
   X_VAR_VarChar_AnalyzeString            (  
      struct X_IDS                        *  pX_Ids,
      X_CCHAR                             *  pvchSourceString,
      X_ULONG                                ulSourceLength,
      X_ULONG                             *  pulDBCSByteCount,
      X_ULONG                             *  pulSBCSByteCount );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_CopyString;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_CopyString               (  
      struct X_IDS                        *  pX_Ids,
      X_CCHAR                             *  pvchSourceString,
      X_VCHAR                             *  pvchTargetString,
      X_ULONG                                ulTargetLength,
      X_CHAR                                 chKeyboardShift,
      X_VAR_VARCHAR_COPY_FLAGS               fCopyFlags );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_CopyStringUtf16;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarChar_CopyStringUtf16          (  
      struct X_IDS                        *  pX_Ids,
      const X_UTF16_VCHAR                 *  pvchSourceString,
      X_UTF16_VCHAR                       *  pvchTargetString,
      X_ULONG                                ulTargetLength,
      X_VAR_VARCHAR_COPY_FLAGS               fCopyFlags );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarChar_GetAsShortChar;
#endif
X_SHORT_FUNCTION_MS_CDECL  
   X_VAR_VarChar_GetAsShortChar           (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_CHAR                          *  pX_FldChar,
      X_VCHAR                             *  pvchTarget,
      X_LONG                                 lLength );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_ShortChar_SetFromFixedChar;
#endif
X_SHORT_FUNCTION_MS_CDECL  
   X_VAR_ShortChar_SetFromFixedChar       (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_CHAR                              *  pchSource,
      X_LONG                                 lSourceLength,
      X_VCHAR                             *  pvchTarget,
      X_LONG                                 lTargetLength );

/* ================================================================= */
/*  X_Var Binary/VarBinary support functions                         */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarBinary_GetPointer;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarBinary_GetPointer             (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_BINARY                        *  pX_FldBinary,
      X_VOID                              ** ppBinary );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarBinary_GetCurSize;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarBinary_GetCurSize             (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_BINARY                        *  pX_FldBinary,
      X_ULONG                             *  pulCurSize );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarBinary_SetFromPointer;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarBinary_SetFromPointer         (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      const X_VOID                        *  pBinarySource,
      X_ULONG                                ulSourceSize,
      X_FLD_BINARY                        *  pX_FldBinary );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarBinary_Assign;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarBinary_Assign                 (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_BINARY                        *  pX_FldBinarySource,
      X_FLD_BINARY                        *  pX_FldBinaryTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarBinary_Release;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_VarBinary_Release                (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_BINARY                        *  pX_FldBinary );


#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_VarBinary_Compare;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_VarBinary_Compare                (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_BINARY                        *  pX_SubjectFldBinary,
      X_FLD_BINARY                        *  pX_ObjectFldBinary );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BinaryStringCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_BinaryStringCompare              (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BinaryStringConcatenate;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_BinaryStringConcatenate          (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectId,
      X_VAR_FACTOR                           lObjectId,
      X_VAR_FACTOR                           lResultId );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BinaryStringIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_BinaryStringIntrinsic            (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BinaryStringConversion;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_BinaryStringConversion           (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_BinaryStringExamine;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_BinaryStringExamine              (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );


/* ================================================================= */
/*  X_Var Decimal support functions                                  */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Assign;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Decimal_Assign                   (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pSourceFactor,
      X_VAR_HEADER                        *  pResultFactor,
      X_VAR_ROUNDING_OPERATION               fRoundingOption );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Compare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_Decimal_Compare                  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pSubjectFactor,
      X_VAR_HEADER                        *  pObjectFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Add;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Decimal_Add                      (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pSubjectFactor,
      X_VAR_HEADER                        *  pObjectFactor,
      X_VAR_HEADER                        *  pResultFactor );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Subtract;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Decimal_Subtract                 (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pSubjectFactor,
      X_VAR_HEADER                        *  pObjectFactor,
      X_VAR_HEADER                        *  pResultFactor );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Multiply;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Decimal_Multiply                 (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pSubjectFactor,
      X_VAR_HEADER                        *  pObjectFactor,
      X_VAR_HEADER                        *  pResultFactor );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Divide;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Decimal_Divide                   (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pSubjectFactor,
      X_VAR_HEADER                        *  pObjectFactor,
      X_VAR_HEADER                        *  pResultFactor );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Decimal_Release;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Decimal_Release                  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_VAR_HEADER                        *  pFactor );


/* ================================================================= */
/*  X_VarDateTime.c Date functions                                   */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_DateCompare                      (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_DateIntrinsic                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateConversion;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_DateConversion                   (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Date_SetFromVchar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Date_SetFromVchar                (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      const X_VCHAR                       *  pvchSource,
      X_FLD_DATE                          *  pX_FldDateTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Date_Assign;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Date_Assign                      (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_DATE                          *  pX_FldDateSource,
      X_FLD_DATE                          *  pX_FldDateTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Date_Compare;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_Date_Compare                     (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_DATE                          *  pX_FldDateSubject,
      X_FLD_DATE                          *  pX_FldDateObject );


/* ================================================================= */
/*  X_VarDateTime.c Time functions                                   */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_TimeCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_TimeCompare                      (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_TimeIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_TimeIntrinsic                    (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_TimeConversion;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_TimeConversion                   (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Time_SetFromVchar;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Time_SetFromVchar                (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      const X_VCHAR                       *  pvchSource,
      X_FLD_TIME                          *  pX_FldTimeTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Time_Assign;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_Time_Assign                      (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_TIME                          *  pX_FldTimeSource,
      X_FLD_TIME                          *  pX_FldTimeTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Time_Compare;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_Time_Compare                     (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_TIME                          *  pX_FldTimeSubject,
      X_FLD_TIME                          *  pX_FldTimeObject );


/* ================================================================= */
/*  X_VarDateTime.c DateTime functions                               */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTimeCompare;
#endif
X_BOOL_FUNCTION_MS_CDECL 
   X_VAR_DateTimeCompare                  (  
      X_VAR_FRAME                         *  pFrame,
      X_VAR_FACTOR                           lSubjectFactor,
      X_VAR_FACTOR                           lObjectFactor,
      X_VAR_FACTOR                           lResultFactor,
      X_VAR_COMPARE_MASK                     fCompareMask );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTimeIntrinsic;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_DateTimeIntrinsic                (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTimeConversion;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_DateTimeConversion               (  
      X_VAR_FRAME                         *  pFrame,
      X_LONG                                 lIdentifier,
      X_LONG                                 lFactorCount,
      const X_VAR_FACTOR                  *  pFactors );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTime_Assign;
#endif
X_VOID_FUNCTION_MS_CDECL  
   X_VAR_DateTime_Assign                  (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_DATETIME                      *  pX_FldDateTimeSource,
      X_FLD_DATETIME                      *  pX_FldDateTimeTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTime_Compare;
#endif
X_LONG_FUNCTION_MS_CDECL 
   X_VAR_DateTime_Compare                 (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_DATETIME                      *  pX_FldDateTimeSubject,
      X_FLD_DATETIME                      *  pX_FldDateTimeObject );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTime_GetAsVchar;
#endif
X_VOID_FUNCTION_MS_CDECL
   X_VAR_DateTime_GetAsVchar     	      (
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      X_FLD_DATETIME                      *  pSource,
	   X_VAR_DATETIME_FORMAT		            fTargetFormat,
      X_VCHAR                             *  pvchTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTime_SetFromVchar;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_DateTime_SetFromVchar	          (
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      const X_VCHAR                       *  pvchSource,
      X_FLD_DATETIME                      *  pTarget,
	   X_VAR_DATETIME_FORMAT		         *  fSourceFormat );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_DateTime_SetFromLiteral;
#endif
X_BOOL_FUNCTION_MS_CDECL  
   X_VAR_DateTime_SetFromLiteral          (  
      struct X_IDS                        *  pX_Ids,
      struct X_PRO                        *  pX_Pro,
      struct X_FUN                        *  pX_Fun,
      const X_VCHAR                       *  pvchSource,
      X_FLD_DATETIME                      *  pTarget );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Date_GetJsonDateTimeString;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_Date_GetJsonDateTimeString (  
      struct X_IDS               *  pX_Ids,
      struct X_PRO               *  pX_Pro,
      struct X_FUN               *  pX_Fun,
      X_PCCHAR                      pszDate,
      X_PCHAR                       pszJsonBuf,
      X_LONG                        nJsonBufLen );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_VAR_Time_GetJsonDateTimeString;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_VAR_Time_GetJsonDateTimeString (  
      struct X_IDS               *  pX_Ids,
      struct X_PRO               *  pX_Pro,
      struct X_FUN               *  pX_Fun,
      X_PCCHAR                      pszTime,
      X_PCHAR                       pszJsonBuf,
      X_LONG                        nJsonBufLen );

/* ================================================================= */
/*  X_Dbg.cpp functions                                              */
/* ================================================================= */

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_DBG_ProcessUIMRequest;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_DBG_ProcessUIMRequest (  
      struct X_IDS         *  pX_Ids,
      struct X_PRO         *  pX_Pro,
      struct X_FUN         *  pX_Fun,
      int                     iRequest );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_DBG_QueryActivateDebugger;
#endif
X_BOOL_FUNCTION_MS_CDECL
   X_DBG_QueryActivateDebugger   (
      struct X_IDS               *  pX_Ids,
      struct X_PRO               *  pX_Pro,
      struct X_FUN               *  pX_Fun,
      int                           iRequest );

#ifdef X_WATCOM
#pragma aux (__MS_cdecl) X_DBG_GetLANSAExeWindowHandle;
#endif
X_WINDOWHANDLE
   X_DBG_GetLANSAExeWindowHandle (
      const char                 *  pszFileName );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif   /* _X_VARPRO_H */
