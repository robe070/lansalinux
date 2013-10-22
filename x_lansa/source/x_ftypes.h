/* ================================================================= */
/* ========= LANSA FOR WINDOWS GLOBAL STRUCTURES =================== */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_FTYPES.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : LANSA Field Types                           */
/*                                                                   */
/*===================================================================*/
/* $Archive:: /VL/Trunk/work/x_win95/x_lansa/source/x_ftypes.h     $ */
/*===================================================================*/
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Ref     Date     Description                                      */
/* ~~~~~~~ ~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*                                                                   */
/* ================================================================= */

#ifndef __INCL_X_FTYPES_H__
#define __INCL_X_FTYPES_H__

#include "x_platform.h"

#ifdef __cplusplus
extern "C" {
#endif


/* BINARY and VARBINARY only differ when creating tables, and    */
/* CHAR and VARCHAR only differ when creating tables. Therefore, */
/* we do not need to distinguish the VAR type in the runtime code*/
/* But, the LX_F03 value and the runtime are synonymous, so the  */
/* Code Generator uses the X_TYPE_xxx when converting from, say, */
/* VARCHAR to CHAR.                                              */

/*
 *  NOTE:
 *  1. Type code 'X', 'K', 'Q' are used for special purposes of
 *     the Web Runtime so all these should be avoided.
 *     See w3xgdef.h for further information.
 *  2. FFC uses 'T' to denote internal TMAPs, so don't use that either.
 *  3. Type code 'L' is also used in the Web Runtime for low-case
 *     capable ALPHA fields.
 */

#define X_TYPE_LONG              'L'
#define X_TYPE_ALPHA             'A'
#define X_TYPE_DATETIME          'Z'
#define X_TYPE_BOOLEAN           'Y'

#define X_TYPE_COMPONENT         'C'
#define X_TYPE_CHAR              'H'
#define X_TYPE_INTEGER           'I'
#define X_TYPE_TIME              'M'
#define X_TYPE_DATE              'E'
#define X_TYPE_DOUBLE            'D'

#define X_TYPE_BINARY            'B'
#define X_TYPE_PACKED            'P'
#define X_TYPE_FLOAT             'F'
#define X_TYPE_SIGNED            'S'
#define X_TYPE_SHORT_CHAR        'U'

#define X_TYPE_VARCHAR           '1'  /* Only for use by Code Generator. Cannot occur in execution */
#define X_TYPE_VARBINARY         '2'  /* Only for use by Code Generator. Cannot occur in execution */
#define X_TYPE_CLOB              '3'
#define X_TYPE_BLOB              '4'
#define X_TYPE_DECIMAL           '5'
#define X_TYPE_VARIANT           '6'  /* Only for use when describing result of X_SUBTYPE_COMPONENT_EVALUATION */
#define X_TYPE_RECORD            '7'
#define X_TYPE_NCHAR             '8'  /* Only for use by Code Generator. Cannot occur in execution */
#define X_TYPE_NVARCHAR          '9'  /* Only for use by Code Generator. Cannot occur in execution */
#define X_TYPE_NCLOB             '0'  /* Digit not letter. Only for use by Code Generator. Cannot occur in execution */

#define X_TYPE_TMAP              'T'

#define X_TYPE_UNICODE           'u'   /* Only used by BIF Arguments to indicate it allows all alpha including Unicode */
#define X_TYPE_ALL_EX_UNICODE    'w'  /* Only used by BIF arguments to indicate all field types are allowed EXCEPT for Unicode*/

#define X_TYPE_IGNORE            'X'
#define X_TYPE_ALPHA_LOWER       'L' /* ALPHA, case preserving, i.e. with attribute LC */
#define X_TYPE_CHAR_LOWER        'K' /* LL2 CHAR/VARCHAR, case preserving, i.e. with attribute LC */
#define X_TYPE_LL2               'Q' /* all other LL2 field types */

#define X_SUBTYPE_SIMPLE_FIELD               'F'
#define X_SUBTYPE_C_EVALUATION               X_SUBTYPE_COMPONENT_EVALUATION /* text is Same length as X_SUBTYPE_SIMPLE_FIELD  for generated code*/
#define X_SUBTYPE_LITERAL                    'L'
#define X_SUBTYPE_ARRAY                      'R'
#define X_SUBTYPE_INDEX                      'I'
#define X_SUBTYPE_SYSTEM_VARIABLE            'V'
#define X_SUBTYPE_USER_PARAMETER             'P'
#define X_SUBTYPE_COMPONENT_ALPHA            'A'
#define X_SUBTYPE_COMPONENT_PACKED           'C'
#define X_SUBTYPE_COMPONENT_SIGNED           'S'
#define X_SUBTYPE_COMPONENT_LONG             'O' /* The letter not the digit */
#define X_SUBTYPE_COMPONENT_DOUBLE           'D'
#define X_SUBTYPE_COMPONENT_CHAR             'H'
#define X_SUBTYPE_COMPONENT_BINARY           'B'
#define X_SUBTYPE_COMPONENT_BOOLEAN          'Y'
#define X_SUBTYPE_COMPONENT_DATE             'E'
#define X_SUBTYPE_COMPONENT_TIME             'M'
#define X_SUBTYPE_COMPONENT_DATETIME         'Z'
#define X_SUBTYPE_COMPONENT_INTEGER          'N'
#define X_SUBTYPE_COMPONENT_FLOAT            'G'
#define X_SUBTYPE_COMPONENT_SHORT_CHAR       'U'
#define X_SUBTYPE_COMPONENT_EVALUATION       'W'
#define X_SUBTYPE_COMPONENT_CLOB             '3'
#define X_SUBTYPE_COMPONENT_BLOB             '4'
#define X_SUBTYPE_COMPONENT_DECIMAL          '5'
#define X_SUBTYPE_COMPONENT_VARIANT          '6'
#define X_SUBTYPE_COMPONENT_RECORD           '7'
#define X_SUBTYPE_WEB_VARIABLE_COLOUR        'c'
#define X_SUBTYPE_WEB_VARIABLE_TEXT          't'
#define X_SUBTYPE_WEB_VARIABLE_FILE          'f'
#define X_SUBTYPE_COMPONENT_NCLOB            '0' /* The digit not the letter */

// When the (old) runtime asks for the value of a Unicode string, it receives the value 
// translated to the native codepage.

// To ensure it can actually hold this value, set the max-size to be a large enough to hold
// the worst case scenario bytes needed for a specific number of characters. ( i.e. 5 bytes for 
   // every 2 characters on iSeries ( Shift-in, Double-Byte, Shift-out, Single-Byte )
#define X_MAX_WIDECHAR_MBCS_LEN(_Chars)     ( ( (int)( ( _Chars + 1 ) / 2 ) * 5 ) + 1 )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !def __INCL_X_FTYPES_H__ */
