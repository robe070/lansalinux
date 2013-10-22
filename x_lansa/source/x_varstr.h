/* ================================================================= */
/* === VISUAL LANSA VARIANT EXPRESSION GLOBAL STRUCTURS         ==== */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_VARSTR.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : Variant Expression structure definition(s)  */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*                                                                   */
/* ================================================================= */

#ifndef _X_VARSTR_H
#define _X_VARSTR_H

/* ================================================================= */
/* ================================================================= */
/* == LPVARSTDHDRS.i C# CONVERT_H_START                           == */
/* ================================================================= */
/* ================================================================= */

/* ================================================================= */
/*  X_VAR_FACTOR :                                                   */
/*                                                                   */
/* ================================================================= */

typedef long
   X_VAR_FACTOR;

#define X_VAR_FACTOR_NULL                                      -1L

/* ================================================================= */
/*  X_VAR_COMPARE_MASK :                                             */
/*                                                                   */
/*    Designed to be OR'ed together                                  */
/* ================================================================= */

typedef long
   X_VAR_COMPARE_MASK;

#define X_VAR_COMPARE_MASK_EQUAL                               0x00000001
#define X_VAR_COMPARE_MASK_LESS                                0x00000010
#define X_VAR_COMPARE_MASK_GREATER                             0x00000100


/* ================================================================= */
/*  X_VAR_ROUNDING_MASK :                                            */
/*                                                                   */
/*    Defines rounding operation during assignment                   */
/* ================================================================= */

typedef long
   X_VAR_ROUNDING_OPERATION;

#define X_VAR_ROUNDING_OPERATION_DOWN                          1L
#define X_VAR_ROUNDING_OPERATION_HALF_UP                       2L


/* ================================================================= */
/*  X_VAR_DATETIME_FORMAT :                                          */
/*                                                                   */
/*    Defines DateTime Standard Formats                              */
/* ================================================================= */

typedef long
   X_VAR_DATETIME_FORMAT;

#define X_VAR_DATETIME_FORMAT_ISO_SQL                          1
#define X_VAR_DATETIME_FORMAT_ISO_8601                         2
#define X_VAR_DATETIME_FORMAT_LOCALIZED_ISO_SQL                3
#define X_VAR_DATETIME_FORMAT_LOCALIZED_ISO_8601               4
#define X_VAR_DATETIME_FORMAT_JSON                             5


/* ================================================================= */
/*  X_VAR_VARCHAR_COPY_FLAGS :                                       */
/*                                                                   */
/*    Defines Flags used by X_VAR_VarChar_CopyString                 */
/* ================================================================= */

typedef unsigned long
   X_VAR_VARCHAR_COPY_FLAGS;

#define X_VAR_VARCHAR_COPY_ALIGN_LEFT                          0x00000001
#define X_VAR_VARCHAR_COPY_ALIGN_RIGHT                         0x00000002
#define X_VAR_VARCHAR_COPY_ALIGN_MASK                          0x0000000F

#define X_VAR_VARCHAR_COPY_FILL_BLANKS                         0x00000010
#define X_VAR_VARCHAR_COPY_FILL_ZEROES                         0x00000020
#define X_VAR_VARCHAR_COPY_FILL_MASK                           0x000000F0

#define X_VAR_VARCHAR_COPY_TYPE_NTS                            0x00000100
#define X_VAR_VARCHAR_COPY_TYPE_FIXED                          0x00000200
#define X_VAR_VARCHAR_COPY_TYPE_MASK                           0x00000F00


/* ================================================================= */
/*  X_VAR_HEADER_KIND :                                              */
/*                                                                   */
/* ================================================================= */

typedef long
   X_VAR_HEADER_KIND;

#define X_VAR_HEADER_KIND_NULL                                 0L

#define X_VAR_HEADER_KIND_FRAME                                1000L

#define X_VAR_HEADER_KIND_PARENT_FRAME                         0x00000100
#define X_VAR_HEADER_KIND_CHILD_FRAME                          0x00000101
#define X_VAR_HEADER_KIND_EXPRESSION_FRAME                     0x00000110
#define X_VAR_HEADER_KIND_DISPATCH_VALUE                       0x00000200
#define X_VAR_HEADER_KIND_EVALUATION_CALLBACK                  0x00000300
#define X_VAR_HEADER_KIND_EVALUATION_DISPATCH                  0x00000400
#define X_VAR_HEADER_KIND_FACTOR_FIELD_VECTOR                  0x00000500
#define X_VAR_HEADER_KIND_FACTOR_SYSVAR_VECTOR                 0x00000600
#define X_VAR_HEADER_KIND_FACTOR_DECIMAL                       0x00000700
#define X_VAR_HEADER_KIND_FACTOR_INT64                         0x00000800
#define X_VAR_HEADER_KIND_FACTOR_STRING                        0x00000900
#define X_VAR_HEADER_KIND_FACTOR_NUMERIC_STRING                0x00000A00
#define X_VAR_HEADER_KIND_FACTOR_DISPATCH_ID                   0x00000B00
#define X_VAR_HEADER_KIND_FACTOR_TABLE_HEADER_ID               0x00000C00
#define X_VAR_HEADER_KIND_FACTOR_LONG                          0x00000D00
#define X_VAR_HEADER_KIND_FACTOR_BOOLEAN                       0x00000E00
#define X_VAR_HEADER_KIND_FACTOR_DOUBLE                        0x00000F00
#define X_VAR_HEADER_KIND_FACTOR_SYSVAR_EVALUATION             0x00001000
#define X_VAR_HEADER_KIND_FACTOR_RESULT                        0x00001100
#define X_VAR_HEADER_KIND_FACTOR_NULL                          0x00001200
#define X_VAR_HEADER_KIND_FACTOR_SQLNULL                       0x00001300
#define X_VAR_HEADER_KIND_FACTOR_STRING_RESULT                 0x00001400
#define X_VAR_HEADER_KIND_FACTOR_NUMERIC_RESULT                0x00001500
#define X_VAR_HEADER_KIND_FACTOR_BOOLEAN_RESULT                0x00001600
#define X_VAR_HEADER_KIND_FACTOR_INT32_RESULT                  0x00001700
#define X_VAR_HEADER_KIND_FACTOR_INT64_RESULT                  0x00001800
#define X_VAR_HEADER_KIND_FACTOR_DECIMAL_RESULT                0x00001900
#define X_VAR_HEADER_KIND_FACTOR_FLOAT_RESULT                  0x00001A00
#define X_VAR_HEADER_KIND_FACTOR_LIST_FIELD_VECTOR             0x00001B00
#define X_VAR_HEADER_KIND_FACTOR_BINARY_STRING_RESULT          0x00001C00
#define X_VAR_HEADER_KIND_FACTOR_DECIMAL_DOUBLE                0x00001D00
#define X_VAR_HEADER_KIND_FACTOR_DECIMAL_PACKED                0x00001E00
#define X_VAR_HEADER_KIND_FACTOR_RECORD_FIELD_VECTOR           0x00001F00
#define X_VAR_HEADER_KIND_FACTOR_VECTOR_LIST                   0x00002000


/* ================================================================= */
/*  X_VAR_HEADER :                                                   */
/*                                                                   */
/*    LANSA Full RDMLX Generic Expression Header                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */

typedef struct _X_VAR_HEADER
{
   unsigned long                                   ulHeaderKind;
}
      X_VAR_HEADER,
   *  PX_VAR_HEADER,
   ** PPX_VAR_HEADER;


/* ================================================================= */
/*  X_VAR_FACTOR_TABLE_HEADER :                                      */
/*                                                                   */
/*    LANSA Full RDMLX Generic Expression Dispatch Table Header      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* lDispatchId     Dispatch Id                                       */

typedef struct _X_VAR_FACTOR_TABLE_HEADER
{
   unsigned long                                   ulHeaderKind;
   long                                            lEntryCount;
}
      X_VAR_FACTOR_TABLE_HEADER,
   *  PX_VAR_FACTOR_TABLE_HEADER,
   ** PPX_VAR_FACTOR_TABLE_HEADER;


/* ================================================================= */
/*  X_VAR_FACTOR_VECTOR :                                            */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation X_FLD Vector Factor     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_FIELD_VECTOR          */
/*                    X_VAR_HEADER_KIND_FACTOR_SYSVAR_VECTOR         */
/*                                                                   */
/* pX_Fld          Source X_FLD Table                                */
/* sVector         Index of X_FLD in X_FLD Table                     */

struct  X_FLD;

typedef struct _X_VAR_FACTOR_VECTOR
{
   unsigned long                                   ulHeaderKind;
   X_DEFS_FLD_TABLE                                pX_Fld;
   X_SHORT                                         sFieldVector;
}
      X_VAR_FACTOR_VECTOR,
   *  PX_VAR_FACTOR_VECTOR,
   ** PPX_VAR_FACTOR_VECTOR;


/* ================================================================= */
/*  X_VAR_FACTOR_LIST_VECTOR :                                       */
/*                                                                   */
/* LANSA Full RDMLX Expression Evaluation X_LIST X_FLD Vector Factor */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_LIST_FIELD_VECTOR     */
/*                                                                   */
/* pX_List         Source X_LIST Table                               */
/* sListVector     Index of source X_LIST                            */
/* sVector         Index of X_FLD in X_LIST.pX_FLD Table             */

struct  X_FLD;

typedef struct _X_VAR_FACTOR_LIST_VECTOR
{
   unsigned long                                   ulHeaderKind;
   struct X_LIST                                *  pX_List;
   X_SHORT                                         sListVector;
   X_SHORT                                         sFieldVector;
}
      X_VAR_FACTOR_LIST_VECTOR,
   *  PX_VAR_FACTOR_LIST_VECTOR,
   ** PPX_VAR_FACTOR_LIST_VECTOR;


/* ================================================================= */
/*  X_VAR_FACTOR_RECORD_VECTOR :                                     */
/*                                                                   */
/* LANSA Full RDMLX Expression Evaluation X_FLD_RECORD Vector Factor */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_RECORD_FIELD_VECTOR   */
/*                                                                   */
/* sRecordVector   Index of Record in X_FLD                          */
/* sFieldVector    Index of X_FLD in X_DRD.pX_FLD Table              */

typedef struct _X_VAR_FACTOR_RECORD_VECTOR
{
   unsigned long                                   ulHeaderKind;
   X_SHORT                                         sRecordVector;
   X_SHORT                                         sFieldVector;
}
      X_VAR_FACTOR_RECORD_VECTOR,
   *  PX_VAR_FACTOR_RECORD_VECTOR,
   ** PPX_VAR_FACTOR_RECORD_VECTOR;

/* ================================================================= */
/*  X_VAR_FACTOR_SYSVAR_EVALUATION :                                 */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation X_FLD Vector Factor     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_SYSVAR_EVALUATION     */
/*                                                                   */
/* pX_Fld          Source X_FLD Table                                */
/* sVector         Index of X_FLD in X_FLD Table                     */
/* pvchPgmName     Evaluation program name                           */

typedef struct _X_VAR_FACTOR_SYSVAR_EVALUATION
{
   unsigned long                                   ulHeaderKind;
   X_DEFS_FLD_TABLE                                pX_Fld;
   X_SHORT                                         sFieldVector;
   X_VCHAR                                      *  pvchPgmName;
}
      X_VAR_FACTOR_SYSVAR_EVALUATION,
   *  PX_VAR_FACTOR_SYSVAR_EVALUATION,
   ** PPX_VAR_FACTOR_SYSVAR_EVALUATION;


/* ================================================================= */
/*  X_VAR_FACTOR_DECIMAL :                                           */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation X_FLD_DECIMAL Factor    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_DECIMAL               */
/*                                                                   */
/* lLength         No. of digits in value. Use 0 for Generic decimal */
/* lDecimals       Decimal digits in value. lDecimals <= lLength     */
/* pX_FldDecimal   Source X_FLD_DECIMAL Table                        */
/* pX_FldDecimal   Source X_FLD_DECIMAL Table                        */

typedef struct _X_VAR_FACTOR_DECIMAL
{
   unsigned long                                   ulHeaderKind;
   X_LONG                                          lLength;
   X_LONG                                          lDecimals;
   void                                         *  pX_FldDecimal;
}
      X_VAR_FACTOR_DECIMAL,
   *  PX_VAR_FACTOR_DECIMAL,
   ** PPX_VAR_FACTOR_DECIMAL;


/* ================================================================= */
/*  X_VAR_FACTOR_LONG :                                              */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation Long Factor             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_LONG                  */
/*                    X_VAR_HEADER_KIND_FACTOR_BOOLEAN               */
/*                                                                   */
/* iLong           32-bit Integer value                              */

typedef struct _X_VAR_FACTOR_LONG
{
   unsigned long                                   ulHeaderKind;
   X_LONG                                          lValue;
}
      X_VAR_FACTOR_LONG,
   *  PX_VAR_FACTOR_LONG,
   ** PPX_VAR_FACTOR_LONG;


/* ================================================================= */
/*  X_VAR_FACTOR_INT64 :                                             */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation INT64 Factor            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_INT64                 */
/*                                                                   */
/* iInt64          64-bit Integer value                              */

typedef struct _X_VAR_FACTOR_INT64
{
   unsigned long                                   ulHeaderKind;
   X_INT64                                         iInt64;
}
      X_VAR_FACTOR_INT64,
   *  PX_VAR_FACTOR_INT64,
   ** PPX_VAR_FACTOR_INT64;


/* ================================================================= */
/*  X_VAR_FACTOR_DOUBLE :                                            */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation Double Factor           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_DOUBLE                */
/*                                                                   */
/* dValue          64-bit floating point value                       */

typedef struct _X_VAR_FACTOR_DOUBLE
{
   unsigned long                                   ulHeaderKind;
   X_DOUBLE                                        dValue;
}
      X_VAR_FACTOR_DOUBLE,
   *  PX_VAR_FACTOR_DOUBLE,
   ** PPX_VAR_FACTOR_DOUBLE;


/* ================================================================= */
/*  X_VAR_FACTOR_DECIMAL_DOUBLE :                                    */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation DECIMAL_DOUBLE Factor   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_DECIMAL_DOUBLE        */
/*                                                                   */
/* lDecimals       Decimal digits in original decimal value          */
/* dValue          64-bit floating point value                       */

typedef struct _X_VAR_FACTOR_DECIMAL_DOUBLE
{
   unsigned long                                   ulHeaderKind;
   X_LONG                                          lDecimals;
   X_DOUBLE                                        dValue;
}
      X_VAR_FACTOR_DECIMAL_DOUBLE,
   *  PX_VAR_FACTOR_DECIMAL_DOUBLE,
   ** PPX_VAR_FACTOR_DECIMAL_DOUBLE;


/* ================================================================= */
/*  X_VAR_FACTOR_DECIMAL_PACKED :                                    */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation DECIMAL_PACKED Factor   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_DECIMAL_PACKED        */
/*                                                                   */
/* lByteLength     Byte length of packed decimal value               */
/* lDecimals       Decimal digits of packed decimal value            */
/* pchPackedValue  Pointer to packed value                           */

typedef struct _X_VAR_FACTOR_DECIMAL_PACKED
{
   unsigned long                                   ulHeaderKind;
   X_LONG                                          lByteLength;
   X_LONG                                          lDecimals;
   const X_DICTIONARY_PACKED                    *  pchPackedValue;
}
      X_VAR_FACTOR_DECIMAL_PACKED,
   *  PX_VAR_FACTOR_DECIMAL_PACKED,
   ** PPX_VAR_FACTOR_DECIMAL_PACKED;


/* ================================================================= */
/*  X_VAR_FACTOR_STRING :                                            */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation String Factor           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_STRING                */
/*                    X_VAR_HEADER_KIND_FACTOR_NUMERIC_STRING        */
/*                                                                   */
/* pvchValue       String value                                      */

typedef struct _X_VAR_FACTOR_STRING
{
   unsigned long                                   ulHeaderKind;
   long                                            lSize;
   const X_VCHAR                                *  pvchValue;
}
      X_VAR_FACTOR_STRING,
   *  PX_VAR_FACTOR_STRING,
   ** PPX_VAR_FACTOR_STRING;


/* ================================================================= */
/*  X_VAR_FACTOR_DISPATCH_ID :                                       */
/*                                                                   */
/*    LANSA Full RDMLX Generic Expression Dispatch Value Block       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_DISPATCH_ID           */
/*                                                                   */
/* lDispatchId     Dispatch Id                                       */

typedef struct _X_VAR_FACTOR_DISPATCH_ID
{
   unsigned long                                   ulHeaderKind;
   X_COMP_DISPATCH_ID                              lDispatchId;
}
      X_VAR_FACTOR_DISPATCH_ID,
   *  PX_VAR_FACTOR_DISPATCH_ID,
   ** PPX_VAR_FACTOR_DISPATCH_ID;


/* ================================================================= */
/*  X_VAR_FACTOR_RESULT                                              */
/*                                                                   */
/*    LANSA Full RDMLX Generic Expression Result Factor              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_STRING_RESULT         */
/*                    X_VAR_HEADER_KIND_FACTOR_BOOLEAN_RESULT        */
/*                    X_VAR_HEADER_KIND_FACTOR_NUMERIC_RESULT        */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_INT32_RESULT          */
/*                    X_VAR_HEADER_KIND_FACTOR_INT64_RESULT          */
/*                    X_VAR_HEADER_KIND_FACTOR_FLOAT_RESULT          */
/*                                                                   */
/* ulFactor        Id of factor                                      */

typedef struct _X_VAR_FACTOR_RESULT
{
   unsigned long                                   ulHeaderKind;
}
      X_VAR_FACTOR_RESULT,
   *  PX_VAR_FACTOR_RESULT,
   ** PPX_VAR_FACTOR_RESULT;


/* ================================================================= */
/*  X_VAR_FACTOR_PRECISE_RESULT                                      */
/*                                                                   */
/*    LANSA Full RDMLX Generic Expression Result Factor              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_DECIMAL_RESULT        */
/*                                                                   */
/* ulFactor        Id of factor                                      */

typedef struct _X_VAR_FACTOR_PRECISE_RESULT
{
   unsigned long                                   ulHeaderKind;
   X_INT32                                         iLength;
   X_INT32                                         iDecimals;
}
      X_VAR_FACTOR_PRECISE_RESULT,
   *  PX_VAR_FACTOR_PRECISE_RESULT,
   ** PPX_VAR_FACTOR_PRECISE_RESULT;


/* ================================================================= */
/*  X_VAR_FACTOR_VECTOR_LIST :                                       */
/*                                                                   */
/* LANSA Full RDMLX Expression Evaluation Vector List Factor         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind. Supports:           */
/*                                                                   */
/*                    X_VAR_HEADER_KIND_FACTOR_VECTOR_LIST           */
/*                                                                   */
/* sRecordVector   Index of Record in X_FLD                          */
/* sFieldVector    Index of X_FLD in X_DRD.pX_FLD Table              */

typedef struct _X_VAR_FACTOR_VECTOR_LIST
{
   unsigned long                                   ulHeaderKind;
   unsigned long                                   ulVectorCount;
   X_SHORT                                      *  asVectors;
}
      X_VAR_FACTOR_VECTOR_LIST,
   *  PX_VAR_FACTOR_VECTOR_LIST,
   ** PPX_VAR_FACTOR_VECTOR_LIST;

/* ================================================================= */
/*  X_VAR_FRAME :                                                    */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation Tracking Block          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* pVarFrame       Frame Implementation                              */

typedef struct _X_VAR_FRAME
{
   unsigned long                                   ulHeaderKind;
   void                                         *  pVarFrame;
}
      X_VAR_FRAME,
   *  PX_VAR_FRAME,
   ** PPX_VAR_FRAME;


/* ================================================================= */
/*  X_VAR_BASE_FRAME :                                               */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation Base Tracking Block     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* pVarFrame       Frame Implementation                              */

typedef struct _X_VAR_BASE_FRAME
{
   unsigned long                                   ulHeaderKind;
   void                                         *  pVarFrame;
   X_DEFS_VAR_HEADER_TABLE                         ppFactorTable;
}
      X_VAR_BASE_FRAME,
   *  PX_VAR_BASE_FRAME,
   ** PPX_VAR_BASE_FRAME;


/* ================================================================= */
/*  X_VAR_CHILD_FRAME :                                              */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation Child Tracking Block    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* pVarFrame       Frame Implementation                              */

typedef struct _X_VAR_CHILD_FRAME
{
   unsigned long                                   ulHeaderKind;
   void                                         *  pVarFrame;
   X_DEFS_VAR_HEADER_TABLE                         ppFactorTable;
}
      X_VAR_CHILD_FRAME,
   *  PX_VAR_CHILD_FRAME,
   ** PPX_VAR_CHILD_FRAME;


/* ================================================================= */
/*  X_VAR_FRAME_1 :                                                  */
/*                                                                   */
/*    LANSA Full RDMLX Expression Evaluation Parent Tracking Block   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* pVarFrame       Frame Implementation                              */

typedef struct _X_VAR_PARENT_FRAME
{
   unsigned long                                   ulHeaderKind;
   void                                         *  pVarFrame;
   X_DEFS_HEADER_TABLE                             ppFactorTable;
   struct X_IDS                                 *  pX_Ids;
   struct X_PRO                                 *  pX_Pro;
   struct X_FUN                                 *  pX_Fun;
   X_DEFS_FLD_TABLE                                pX_Fld;
   X_DEFS_LIST_TABLE                               pX_List;
}
      X_VAR_PARENT_FRAME,
   *  PX_VAR_PARENT_FRAME,
   ** PPX_VAR_PARENT_FRAME;


/* ================================================================= */
/*  X_VAR_DISPATCH_VALUE :                                           */
/*                                                                   */
/*    LANSA Full RDMLX Generic Expression Dispatch Value Block       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* pDispatchValue  Dispatch value Implementation                     */

typedef struct _X_VAR_DISPATCH_VALUE
{
   unsigned long                                   ulHeaderKind;
   void                                         *  pDispatchValue;
}
      X_VAR_DISPATCH_VALUE,
   *  PX_VAR_DISPATCH_VALUE,
   ** PPX_VAR_DISPATCH_VALUE;


/* ================================================================= */
/*  X_VAR_FACTOR_BLOCK : LANSA/X X_VAR Factor Block                  */
/*                                                                   */
/*  NO REFERENCES TO ELEMENTS OF THIS STRUCTURE ARE ALLOWED IN       */
/*  GENERATED RDML CODE .... ONLY IN EXTERNAL COMPILED COMPONENTS    */
/* ================================================================= */
/* Name              Description                                     */
/* ----              -----------                                     */
/* lTotalFactors     Count of factors in the block                   */
/* lAllocatedFactors Count of factors allocated so far               */
/* pFactor           Array of LpVarFactor objects                    */

typedef struct _X_VAR_FACTOR_BLOCK
{
   X_LONG                                          lTotalFactors;
   X_LONG                                          lAllocatedFactors;
   X_PVOID                                         pFactors[1];
}
   X_VAR_FACTOR_BLOCK,
   *PX_VAR_FACTOR_BLOCK;


/* ================================================================= */
/*  X_VAR_EVALUATION_FCN :                                           */
/*                                                                   */
/*  Type definition of expression callback routines                  */
/* ================================================================= */

#ifndef X_OPERATING_TARGET_CSHARP

#define X_VAR_STD_ARGS_CSHARP    "_X_VAR_FRAME pParentFrame, object[] apvAgreedArgs, uint ulNoofNegotiableComps, X_COMP_NEGOTIABLE_COMPONENT[] aNegotiableComps"

#define X_VAR_STD_ARGS           X_VAR_FRAME                   * pParentFrame,            \
                                 void                          * apvAgreedArgs[],         \
	                              unsigned long                   ulNoofNegotiableComps,   \
	                              X_COMP_NEGOTIABLE_COMPONENT     aNegotiableComps[]

#endif // X_OPERATING_TARGET_CSHARP

#if defined(X_OPERATING_SYSTEM_UNIX)

typedef X_VOID_FUNCTION X_VAR_EVALUATION_FCN             (
   X_VAR_FRAME                                           *  pParentFrame,
   void                                                  *  apvAgreedArgs[],
	unsigned long                                            ulNoofNegotiableComps,
	X_COMP_NEGOTIABLE_COMPONENT                              aNegotiableComps[] );

#else

typedef X_VOID_FUNCTION __cdecl X_VAR_EVALUATION_FCN     (
   X_VAR_FRAME                                           *  pParentFrame,
   void                                                  *  apvAgreedArgs[],
	unsigned long                                            ulNoofNegotiableComps,
	X_COMP_NEGOTIABLE_COMPONENT                              aNegotiableComps[] );

#endif

typedef X_VAR_EVALUATION_FCN
   *  PX_VAR_EVALUATION_FCN,
   ** PPX_VAR_EVALUATION_FCN;


/* ================================================================= */
/*  X_VAR_EVALUATION_CALLBACK :                                      */
/*                                                                   */
/*  LANSA Full RDMLX Evaluation Callback Routine description         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* ulTypeInfo      Type info of result                               */
/* ulMaxLength     Maximum length of result                          */
/* ulMaxDecimals   Maximum decimals of result                        */
/* pfnEvaluation   Pointer to Evaluation Routines                    */

typedef struct _X_VAR_EVALUATION_CALLBACK
{
   unsigned long                                   ulHeaderKind;
   X_COMP_EVALUATION_TYPE_INFO                     ulTypeInfo;
   unsigned long                                   ulMaxLength;
   unsigned long                                   ulMaxDecimals;
   X_VAR_EVALUATION_FCN                         *  pfnEvaluation;

}
   X_VAR_EVALUATION_CALLBACK,
   *PX_VAR_EVALUATION_CALLBACK,
   **PPX_VAR_EVALUATION_CALLBACK;


/* ================================================================= */
/*  X_VAR_EVALUATION_DISPATCH :                                      */
/*                                                                   */
/*  LANSA Full RDMLX Evaluation Dispatch Routine description         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* ulHeaderKind    Self identifying header kind                      */
/* ulTypeInfo      Type info of result                               */
/* ulMaxLength     Maximum length of result                          */
/* ulMaxDecimals   Maximum decimals of result                        */
/* pfnEvaluation   Pointer to Evaluation Routines                    */

typedef struct _X_VAR_EVALUATION_DISPATCH
{
   unsigned long                                   ulHeaderKind;
   X_COMP_EVALUATION_TYPE_INFO                     ulTypeInfo;
   unsigned long                                   ulMaxLength;
   unsigned long                                   ulMaxDecimals;
   X_COMP_DISPATCH_ID                              lDispatchId;

}
   X_VAR_EVALUATION_DISPATCH,
   *PX_VAR_EVALUATION_DISPATCH,
   **PPX_VAR_EVALUATION_DISPATCH;


/* ================================================================= */
/*  X_VAR_DEFINE_PARENT_FRAME                                        */
/*                                                                   */
/*  Define and initialize Parent Frame                               */
/* ================================================================= */
#define X_VAR_DEFINE_PARENT_FRAME( _IDS, _PRO, _FUN, _FLD, _LST )     \
                                                                      \
   X_VAR_PARENT_FRAME                                                 \
      frame;                                                          \
   X_VAR_FRAME                                                        \
      *pFrame = ((X_VAR_FRAME*) &frame);                              \
                                                                      \
   frame.ulHeaderKind   = X_VAR_HEADER_KIND_PARENT_FRAME;             \
   frame.pVarFrame      = NULL;                                       \
   frame.ppFactorTable  = ((X_VAR_HEADER**) factorTable);             \
   frame.pX_Ids         = _IDS;                                       \
   frame.pX_Pro         = _PRO;                                       \
   frame.pX_Fun         = _FUN;                                       \
   frame.pX_Fld         = _FLD;                                       \
   frame.pX_List        = _LST;

/* ================================================================= */
/*  X_VAR_DEFINE_CHILD_FRAME                                         */
/*                                                                   */
/*  Define and initialize Child Frame                                */
/* ================================================================= */
#define X_VAR_DEFINE_CHILD_FRAME( _PF )                               \
                                                                      \
   X_VAR_CHILD_FRAME                                                  \
      frame;                                                          \
   X_VAR_FRAME                                                        \
      *pFrame = ((X_VAR_FRAME*) &frame);                              \
                                                                      \
   frame.ulHeaderKind   = X_VAR_HEADER_KIND_CHILD_FRAME;              \
   frame.pVarFrame      = ( _PF )->pVarFrame;                         \
   frame.ppFactorTable  = ((X_VAR_HEADER**) factorTable);



/* ================================================================= */
/*  X_VAR_OPERATION_CODES                                            */
/*                                                                   */
/* ================================================================= */


/* ================================================================= */
/*  X_VAR_STACK_VECTOR_ELEMENT                                       */
/* ================================================================= */

typedef struct _X_VAR_STACK_VECTOR_ELEMENT
{
   struct X_FLD                           *  m_Fld;
   X_PDICTIONARY_FIELD                       m_Field;
}
   X_VAR_STACK_VECTOR_ELEMENT,
   *PX_VAR_STACK_VECTOR_ELEMENT,
   **PPX_VAR_STACK_VECTOR_ELEMENT;

/* ================================================================= */
/*  X_VAR_STACK_STRING_ELEMENT                                       */
/* ================================================================= */

#define X_VAR_STACK_STRING_ELEMENT_TYPE_CHAR               'C'       /* m_Char + m_Length             */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_UTF16_CHAR         'D'       /* m_Utf16Char + m_Length        */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_FLD_CHAR           'F'       /* m_FldChar                     */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_FLD_BINARY         'B'       /* m_FldBinary                   */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_FLD_SHORT_CHAR     'U'       /* m_FldShortChar                */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_VAR_CHAR           'V'       /* m_VarChar                     */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_UTF16_VAR_CHAR     'W'       /* m_Utf16VarChar                */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_STRING             '1'       /* m_FldChar + m_StringField     */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_STRING_PTR         '2'       /* m_FldChar                     */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_BINARY             '3'       /* m_FldBinary + m_BinaryField   */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_BINARY_PTR         '4'       /* m_FldBinary                   */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_UTF16_STRING       '5'       /* m_FldChar + m_StringField     */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_UTF16_STRING_PTR   '6'       /* m_FldChar                     */
#define X_VAR_STACK_STRING_ELEMENT_TYPE_ENUMERATION        'E'       /* m_Int32                       */

typedef struct _X_VAR_STACK_STRING_ELEMENT
{
   X_ULONG                                   m_Type;
   X_ULONG                                   m_Length;

#ifndef LP_CSHARP
   union
#endif // LP_CSHARP
   {
      X_VCHAR                             *  m_Char;
      X_UTF16_VCHAR                       *  m_Utf16Char;
      X_FLD_CHAR                          *  m_FldChar;
      X_FLD_BINARY                        *  m_FldBinary;
      X_FLD_SHORT_CHAR                    *  m_FldShortChar;
      X_VCHAR                             *  m_VarChar;
      X_UTF16_VCHAR                       *  m_Utf16VarChar;
      X_INT32                                m_Int32;
   };
#ifndef LP_CSHARP
   union
#endif // LP_CSHARP
   {
      X_FLD_CHAR                             m_String;
      X_FLD_BINARY                           m_Binary;
   };
}
   X_VAR_STACK_STRING_ELEMENT,
   *PX_VAR_STACK_STRING_ELEMENT,
   **PPX_VAR_STACK_STRING_ELEMENT;

/* ================================================================= */
/*  X_VAR_STACK_DOUBLE_ELEMENT                                       */
/* ================================================================= */

typedef struct _X_VAR_STACK_DOUBLE_ELEMENT
{
   X_ULONG                                   m_Decimals;
   X_DOUBLE                                  m_Data;
}
   X_VAR_STACK_DOUBLE_ELEMENT,
   *PX_VAR_STACK_DOUBLE_ELEMENT,
   **PPX_VAR_STACK_DOUBLE_ELEMENT;

/* ================================================================= */
/*  X_VAR_STACK_PACKED31_ELEMENT                                     */
/* ================================================================= */

#define X_VAR_STACK_PACKED31_BYTES                          16       /* ML1 : decimal(31,0) <-> decimal(31,31) */
#define X_VAR_STACK_SIGNED31_BYTES                          31

typedef struct _X_VAR_STACK_PACKED31_ELEMENT
{
   X_ULONG                                   m_Length;
   X_ULONG                                   m_Decimals;
   X_FCHAR                                   m_Data[ X_VAR_STACK_PACKED31_BYTES ];
}
   X_VAR_STACK_PACKED31_ELEMENT,
   *PX_VAR_STACK_PACKED31_ELEMENT,
   **PPX_VAR_STACK_PACKED31_ELEMENT;

/* ================================================================= */
/*  X_VAR_STACK_PACKED63_ELEMENT                                     */
/* ================================================================= */

#define X_VAR_STACK_PACKED63_BYTES                          32       /* ML2 : decimal(63,0) <-> decimal(63,63) */
#define X_VAR_STACK_SIGNED63_BYTES                          63

typedef struct _X_VAR_STACK_PACKED63_ELEMENT
{
   X_ULONG                                   m_Length;
   X_ULONG                                   m_Decimals;
   X_FCHAR                                   m_Data[ X_VAR_STACK_PACKED63_BYTES ];
}
   X_VAR_STACK_PACKED63_ELEMENT,
   *PX_VAR_STACK_PACKED63_ELEMENT,
   **PPX_VAR_STACK_PACKED63_ELEMENT;

/* ================================================================= */
/*  X_VAR_EXPRESSION_OPERAND                                         */
/* ================================================================= */

typedef struct _X_VAR_EXPRESSION_OPERAND
{
#ifndef LP_CSHARP
   X_ULONG                                   m_State;
#else
   XFIELDSTATE                               m_State;
#endif

#ifndef LP_CSHARP
   union
#endif // LP_CSHARP
   {
      X_BOOL                                 m_Boolean;
      X_INT32                                m_Int32;
      X_INT64                                m_Int64;
      X_FLT64                                m_Flt64;
      X_VCHAR                                m_Date[X_MAX_SIZE_DATE_LEN];         /* For Date YYYY-MM-DD */
      X_VCHAR                                m_Time[X_MAX_SIZE_TIME_LEN];         /* For Time HH:MM:SS   */
      X_VCHAR                                m_DateTime[X_MAX_SIZE_DATETIME_LEN]; /* For Time YYYY-MM-DD HH:MM:SS.FFFFFFFFF : 9 digits after fraction point */
      X_VCHAR                                m_Gregorian[X_MAX_SIZE_GREGORIAN_LEN];
      X_VCHAR                                m_Duration[X_MAX_SIZE_DURATION_LEN];
      X_VAR_STACK_VECTOR_ELEMENT             m_Vector;
      X_VAR_STACK_STRING_ELEMENT             m_String;
      X_VAR_STACK_DOUBLE_ELEMENT             m_Double;
      X_VAR_STACK_PACKED31_ELEMENT           m_Packed31;
      X_VAR_STACK_PACKED63_ELEMENT           m_Packed63;
      void                                *  m_Decimal;
      void                                *  m_Variant;
      X_VAR_FACTOR_VECTOR_LIST            *  m_VectorListFactor;
      X_FCHAR                                m_NeverUsed[124];
   };
}
   X_VAR_EXPRESSION_OPERAND,
   *PX_VAR_EXPRESSION_OPERAND,
   **PPX_VAR_EXPRESSION_OPERAND;


/* ================================================================= */
/*  X_VAR_EXPRESSION_FRAME :                                         */
/*                                                                   */
/*                                                                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/*                                                                   */
/*                                                                   */
/*                                                                   */

#define X_VAR_EXPRESSION_FRAME_V1         -1
#define X_VAR_EXPRESSION_FRAME_CURRENT    X_VAR_EXPRESSION_FRAME_V1

typedef struct _X_VAR_EXPRESSION_FRAME
{
   X_LONG                                          lVersion;
   X_ULONG                                         ulInstructionCount;
   X_ULONG                                         ulOperandSize;
   struct X_IDS                                 *  pX_Ids;
   struct X_PRO                                 *  pX_Pro;
   struct X_FUN                                 *  pX_Fun;
   X_DEFS_FLD_TABLE                                pX_Fld;
   X_DEFS_LIST_TABLE                               pX_List;
   X_DEFS_FLD_TABLE                                pX_FldFile;
   X_DEFS_VAR_HEADER_TABLE                         ppOperandTable;
   X_DEFS_X_SHORT_TABLE                            psInstructionTable;
   X_SHORT                                      *  psCurInstruction;
   X_DEFS_VAR_OPERAND_TABLE                        pOperandStack;
   X_VAR_EXPRESSION_OPERAND                     *  pCurOperand;
   X_VAR_FRAME                                  *  pParentFrame;
   X_DEFS_AGREED_ARGS_PTR                          ppvAgreedArgs;
	unsigned long                                   ulNoofNegotiableComps;
}
   X_VAR_EXPRESSION_FRAME,
   *PX_VAR_EXPRESSION_FRAME,
   **PPX_VAR_EXPRESSION_FRAME;

/* ================================================================= */
/*  X_VAR_DEFINE_EXPRESSION_FRAME                                    */
/*                                                                   */
/*  Define and initialize Expression Frame                           */
/* ================================================================= */
#define X_VAR_DEFINE_EXPRESSION_FRAME( _IDS, _PRO, _FUN, _FLD, _LST, _FIL, _OPT )   \
                                                                                    \
   X_VAR_EXPRESSION_FRAME                                                           \
      frame;                                                                        \
                                                                                    \
   frame.lVersion             = X_VAR_EXPRESSION_FRAME_CURRENT;                     \
   frame.pX_Ids               = _IDS;                                               \
   frame.pX_Pro               = _PRO;                                               \
   frame.pX_Fun               = _FUN;                                               \
   frame.pX_Fld               = _FLD;                                               \
   frame.pX_List              = _LST;                                               \
   frame.pX_FldFile           = _FIL;                                               \
   frame.ppOperandTable       = ((X_VAR_HEADER**) _OPT);                            \
   frame.psInstructionTable   = ((X_SHORT*) asInstructionTable);                    \
   frame.ulInstructionCount   = sizeof(asInstructionTable) / sizeof(X_SHORT);       \
   frame.pOperandStack        = operandStack;                                       \
   frame.ulOperandSize        = sizeof( X_VAR_EXPRESSION_OPERAND );


/* ================================================================= */
/*  X_VAR_DEFINE_CALLBACK_EXPRESSION_FRAME                           */
/*                                                                   */
/*  Define and initialize Expression Frame                           */
/* ================================================================= */
#define X_VAR_DEFINE_CALLBACK_EXPRESSION_FRAME( _OPT )                              \
                                                                                    \
   X_VAR_EXPRESSION_FRAME                                                           \
      frame;                                                                        \
                                                                                    \
   frame.lVersion                = X_VAR_EXPRESSION_FRAME_CURRENT;                  \
   frame.pX_Ids                  = pX_NULL;                                         \
   frame.pX_Pro                  = pX_NULL;                                         \
   frame.pX_Fun                  = pX_NULL;                                         \
   frame.pX_Fld                  = pX_Fld;                                          \
   frame.pX_List                 = pX_NULL;                                         \
   frame.pX_FldFile              = pX_NULL;                                         \
   frame.ppOperandTable          = ((X_VAR_HEADER**) _OPT);                         \
   frame.psInstructionTable      = ((X_SHORT*) asInstructionTable);                 \
   frame.ulInstructionCount      = sizeof(asInstructionTable) / sizeof(X_SHORT);    \
   frame.pOperandStack           = operandStack;                                    \
   frame.ulOperandSize           = sizeof( X_VAR_EXPRESSION_OPERAND );              \
   frame.pParentFrame            = pParentFrame;                                    \
   frame.ppvAgreedArgs           = apvAgreedArgs;                                   \
	frame.ulNoofNegotiableComps   = ulNoofNegotiableComps;


/* ================================================================= */
/*  X_VAR_DEFINE_COMPONENT_EXPRESSION_FRAME                          */
/*                                                                   */
/*  Define and initialize Expression Frame                           */
/* ================================================================= */
#define X_VAR_DEFINE_COMPONENT_EXPRESSION_FRAME( _LST, _OPT )                       \
                                                                                    \
   X_VAR_EXPRESSION_FRAME                                                           \
      frame;                                                                        \
                                                                                    \
   frame.lVersion                = X_VAR_EXPRESSION_FRAME_CURRENT;                  \
   frame.pX_Ids                  = pX_Ids;                                          \
   frame.pX_Pro                  = pX_Ids->pX_IdsComponent->pX_ProComponent;        \
   frame.pX_Fun                  = pModuleFrame->pX_Fun;                            \
   frame.pX_Fld                  = pX_Fld;                                          \
   frame.pX_List                 = _LST;                                            \
   frame.pX_FldFile              = pX_NULL;                                         \
   frame.ppOperandTable          = ((X_VAR_HEADER**) _OPT);                         \
   frame.psInstructionTable      = ((X_SHORT*) asInstructionTable);                 \
   frame.ulInstructionCount      = sizeof(asInstructionTable) / sizeof(X_SHORT);    \
   frame.pOperandStack           = operandStack;                                    \
   frame.ulOperandSize           = sizeof( X_VAR_EXPRESSION_OPERAND );              \
   frame.ppvAgreedArgs           = apvAgreedArgs;                                   \
	frame.ulNoofNegotiableComps   = ulNoofNegotiableComps;


/* ================================================================= */
/*  Following macros are used to let the compile environment resolve */
/*  the best solution                                                */
/* ================================================================= */

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_OPERATING_SYSTEM_ISERIES)

   #define X_VAR_RESOLVE_FACTOR_AS_DECIMAL_DOUBLE( _N, _BL, _D, _DV, _PV )          \
      static const X_VAR_FACTOR_DECIMAL_PACKED                                      \
         _N = { X_VAR_HEADER_KIND_FACTOR_DECIMAL_PACKED, _BL, _D, _PV };

   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_DOUBLE     X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_DOUBLE
   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_PACKED31   X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_PACKED31
   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_PACKED63   X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_PACKED63
   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_DECIMAL    X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_DECIMAL

#else

   #define X_VAR_RESOLVE_FACTOR_AS_DECIMAL_DOUBLE( _N, _BL, _D, _DV, _PV )          \
      static const X_VAR_FACTOR_DECIMAL_DOUBLE                                      \
         _N = { X_VAR_HEADER_KIND_FACTOR_DECIMAL_DOUBLE, _D, ((X_DOUBLE) _DV) };

   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_DOUBLE     X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_DOUBLE
   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_PACKED31   X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_PACKED31
   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_PACKED63   X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_PACKED63
   #define X_VAR_RESOLVE_PUSH_DOUBLE_CONSTANT_AS_DECIMAL    X_COMP_OPCODE_PUSH_DOUBLE_CONSTANT_AS_DECIMAL

#endif

#endif // X_OPERATING_TARGET_CSHARP

#ifndef X_OPERATING_TARGET_CSHARP

#if defined(X_CONST_LONGLONG_IS_LONG)

   #define X_VAR_RESOLVE_FACTOR_AS_LONGLONG( _N, _BL, _LLV, _PV )                   \
      static const X_VAR_FACTOR_DECIMAL_PACKED                                      \
         _N = { X_VAR_HEADER_KIND_FACTOR_DECIMAL_PACKED, _BL, 0, _PV };

   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_LONGLONG    X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_LONGLONG
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_DOUBLE      X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_DOUBLE
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_PACKED31    X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_PACKED31
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_PACKED63    X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_PACKED63
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_DECIMAL     X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_DECIMAL
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_INT64       X_COMP_OPCODE_PUSH_PACKED_CONSTANT_AS_INT64

#else

   #define X_VAR_RESOLVE_FACTOR_AS_LONGLONG( _N, _BL, _LLV, _PV )                   \
      static const X_VAR_FACTOR_INT64                                               \
         _N = { X_VAR_HEADER_KIND_FACTOR_INT64, _LLV };

   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_LONGLONG    X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_LONGLONG
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_DOUBLE      X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_DOUBLE
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_PACKED31    X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_PACKED31
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_PACKED63    X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_PACKED63
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_DECIMAL     X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_DECIMAL
   #define X_VAR_RESOLVE_PUSH_INT64_CONSTANT_AS_INT64       X_COMP_OPCODE_PUSH_INT64_CONSTANT_AS_INT64

#endif

#endif // X_OPERATING_TARGET_CSHARP

/* ================================================================= */
/*  X_VAR_EXPRESSION_PACKED31_XXXXX protypes for ISeries assign,     */
/*                                                                   */
/*  Prototypes for ISeries assign, compare and math evaluators.      */
/* ================================================================= */

typedef X_ULONG
   X_VAR_EXPRESSION_PACKED31_ASSIGN          (
      X_VCHAR                                *  pvchTarget,
      X_VCHAR                                *  pvchSource );

typedef X_VAR_EXPRESSION_PACKED31_ASSIGN     *   PX_VAR_EXPRESSION_PACKED31_ASSIGN;
typedef X_VAR_EXPRESSION_PACKED31_ASSIGN     **  PPX_VAR_EXPRESSION_PACKED31_ASSIGN;


typedef X_BOOL
   X_VAR_EXPRESSION_PACKED31_COMPARE         (
      X_VCHAR                                *  pvchSubject,
      X_VCHAR                                *  pvchObject );

typedef X_VAR_EXPRESSION_PACKED31_COMPARE    *   PX_VAR_EXPRESSION_PACKED31_COMPARE;
typedef X_VAR_EXPRESSION_PACKED31_COMPARE    **  PPX_VAR_EXPRESSION_PACKED31_COMPARE;


typedef X_ULONG
   X_VAR_EXPRESSION_PACKED31_MATH            (
      X_VCHAR                                *  pvchTarget,
      X_VCHAR                                *  pvchSubject,
      X_VCHAR                                *  pvchObject );

typedef X_VAR_EXPRESSION_PACKED31_MATH       *   PX_VAR_EXPRESSION_PACKED31_MATH;
typedef X_VAR_EXPRESSION_PACKED31_MATH       **  PPX_VAR_EXPRESSION_PACKED31_MATH;


#ifdef X_OPERATING_SYSTEM_ISERIES
   extern const PX_VAR_EXPRESSION_PACKED31_ASSIGN
      s_Packed31AssignEvaluators[];

   extern const PX_VAR_EXPRESSION_PACKED31_COMPARE
      s_Packed31CompareEqEvaluators[],
      s_Packed31CompareLtEvaluators[],
      s_Packed31CompareLeEvaluators[],
      s_Packed31CompareGtEvaluators[],
      s_Packed31CompareGeEvaluators[],
      s_Packed31CompareNeEvaluators[];

   extern const PX_VAR_EXPRESSION_PACKED31_MATH
      s_Packed31PlusEvaluators[],
      s_Packed31MinusEvaluators[],
      s_Packed31MultiplyEvaluators[];
#endif

/* ================================================================= */
/* ================================================================= */
/* == LPVARSTDHDRS.i C# CONVERT_H_END                             == */
/* ================================================================= */
/* ================================================================= */

#endif /* _X_VARSTR_H */

