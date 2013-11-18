/*===================================================================*/
/*                                                                   */
/*                 WARNING WARNING WARNING WARNING                   */
/*                                                                   */
/*              This is more important than GLOBAL WARMING...        */
/*                                                                   */
/*                                                                   */
/*                  IMPORTANT NOTE ( July 2007 )                     */
/*                                                                   */
/*  When making changes related to X_COM processing be sure to check */
/*  if the same change needs to be made in the LANSA Open .NET       */
/*  project.                                                         */
/*                                                                   */
/*===================================================================*/


/* ================================================================= */
/* ========= LANSA FOR WINDOWS GLOBAL STRUCTURES =================== */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_COMSTR.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : Standard X_ structures                      */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*   4291  97/08/19 Port Super/Server to UNIX                        */
/*   5183  01/03/05 Remove Original image from X_MIOAR_CTL           */
/*                                                                   */
/* ================================================================= */
/*  #defines used within this source file                            */
/* ================================================================= */


/*===================================================================*/
/*                                                                   */
/*                 WARNING WARNING WARNING WARNING                   */
/*                                                                   */
/*              This is more important than GLOBAL WARMING...        */
/*                                                                   */
/*                                                                   */
/*                  IMPORTANT NOTE ( July 2007 )                     */
/*                                                                   */
/*  When making changes related to X_COM processing be sure to check */
/*  if the same change needs to be made in the LANSA Open .NET       */
/*  project.                                                         */
/*                                                                   */
/*===================================================================*/

#ifndef X_COM_STR_INCLUDED
#define X_COM_STR_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#define X_MIOAR_KEY                  'K'
#define X_MIOAR_FIELD                'F'
#define X_MIOAR_MAX_FIELDS           100
#define X_MIOAR_MAX_KEYS             20
#define X_MIOAR_MAX_LENGTH           9985

#define X_COM_INTEGER_DIGITS         10
#define X_COM_MAXIMUM_WORKING_LIST   32000 /* Increased from 9974 */
#define X_COM_MAX_REC_LEN            65535
#define X_COM_MAX_FIELDS_IN_GROUP    1001

#define X_COM_RECORD_LENGTH_LENGTH   2

#define X_COM_CPIC_CID_LENGTH        8
#define X_COM_CPIC_HEADER_LENGTH     4
#define X_COM_LOGICAL_BUFFER_LENGTH  (4096)
#define X_COM_PHYSICAL_BUFFER_LENGTH (4096 + X_COM_CPIC_HEADER_LENGTH)

#define X_COM_STD_TRANSACTION_PROGRAM    "LXXP0010"
#define X_COM_VL400_TRANSACTION_PROGRAM  "LXIP0010"
#define X_COM_ANY_TRANSACTION_PROGRAM    "LXXP0100"

#define X_COM_CLIENT_TYPE_LEN        3

#if defined(X_OPERATING_SYSTEM_WIN)
#define X_COM_CLIENT_TYPE            "W32"
#define X_COM_CLIENT_IS_EBCDIC       FALSE
#endif
#define X_COM_CLIENT_TYPE_W32        "W32"

#if defined(X_OPERATING_SYSTEM_ISERIES)
#define X_COM_CLIENT_TYPE            "ISE"
#define X_COM_CLIENT_IS_EBCDIC       TRUE
#endif
#define X_COM_CLIENT_TYPE_ISE        "ISE"

#if defined(X_OPERATING_SYSTEM_SOL)
#define X_COM_CLIENT_TYPE            "SOL"
#define X_COM_CLIENT_IS_EBCDIC       FALSE
#endif
#define X_COM_CLIENT_TYPE_SOL        "SOL"

#if defined(X_OPERATING_SYSTEM_LNX)
#define X_COM_CLIENT_TYPE            "LNX"
#define X_COM_CLIENT_IS_EBCDIC       FALSE
#endif
#define X_COM_CLIENT_TYPE_LNX        "LNX"


#define X_COM_AUTOMATIC_CONNECT_SSN  "AS400"
#define X_COM_AUTOOTHER_CONNECT_SSN  "DTASERVER"
#define X_COM_ASXX_CONNECT_SSN       "*APPSERVER"
#define X_COM_GET_FIRST_COMPUTER     "*FIRST"

#define X_COM_ASCII_ZONE            '\x3F'
#define X_COM_ASCII_MINUS_SIGN      '\x2D'
#define X_COM_EBCDIC_MINUS_SIGN     '\x60'
#define X_COM_ASCII_PLUS_SIGN       '\x2B'
#define X_COM_EBCDIC_PLUS_SIGN      '\x4E'

#define X_COM_DETERMINE_TRANSLATION_TYPE( _CT, _TT ) \
   switch ( _CT ) \
   { \
      case X_COM_CONVERT_TO_SERVER: \
      { \
         if ( COM_SESSION_SERVER_IS_EBCDIC( pComputer ) ) \
         { \
            _TT = X_COM_CONVERT_ASCII_TO_EBCDIC; \
         } \
         else \
         { \
            _TT = X_COM_CONVERT_EBCDIC_TO_ASCII; \
         } \
         break; \
      } \
      \
      case X_COM_CONVERT_TO_CLIENT: \
      { \
         if ( X_COM_CLIENT_IS_EBCDIC ) \
         { \
            _TT = X_COM_CONVERT_ASCII_TO_EBCDIC; \
         } \
         else \
         { \
            _TT = X_COM_CONVERT_EBCDIC_TO_ASCII; \
         } \
         break; \
      } \
      \
      default: \
      { \
         X_Fatal_Error( pX_Ids, pX_Pro, pX_Fun, "X_Convert_DBCS_Data", X_TEXT(210) ); \
         break; \
      } \
   }

#define COM_SESSION_IS_TO_AS400(_PCOM) \
( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_OS400 )

#define COM_SESSION_IS_TO_OTHER(_PCOM) \
( ( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_WINDOWS ) \
|| ( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_LINUX ) \
|| ( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_OTHER ) )

#define COM_SESSION_IS_TO_VL400(_PCOM) \
( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_VL400 )

#define COM_SESSION_IS_TO_UNKNOWN(_PCOM) \
( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_UNKNOWN )

#define COM_SESSION_IS_TO_VL(_PCOM) \
( COM_SESSION_IS_TO_OTHER(_PCOM) || COM_SESSION_IS_TO_VL400(_PCOM) || COM_SESSION_IS_TO_UNKNOWN(_PCOM) )

#define COMM_SESSION_IS_ON_CLIENT(_PCOM) \
( COM_SESSION_IS_TO_VL(_PCOM) || COM_SESSION_IS_TO_AS400(_PCOM) || COM_SESSION_IS_TO_UNKNOWN(_PCOM) )

#define COMM_SESSION_IS_ON_SERVER(_PCOM) \
(((_PCOM)->chConnectionType == X_CONNECT_TYPE_SERVER_FOR_LSERVER) || ((_PCOM)->chConnectionType == X_CONNECT_TYPE_SERVER_FOR_XSERVER))

#define COM_SESSION_SERVER_IS_EBCDIC(_PCOM) \
( COM_SESSION_IS_TO_AS400(_PCOM) || COM_SESSION_IS_TO_VL400(_PCOM) )

#if defined(X_OPERATING_SYSTEM_WIN)
#define COM_SESSION_DATA_CONVERSION_REQUIRED(_PCOM) \
( COM_SESSION_IS_TO_AS400(_PCOM) || COM_SESSION_IS_TO_VL400(_PCOM) || COM_SESSION_IS_TO_UTF8_SYSTEM(_PCOM) )
#elif defined(X_OPERATING_SYSTEM_ISERIES)
#define COM_SESSION_DATA_CONVERSION_REQUIRED(_PCOM) \
( COM_SESSION_IS_TO_OTHER(_PCOM) || COM_SESSION_IS_TO_UNKNOWN(_PCOM) )
#elif defined(X_OPERATING_SYSTEM_UNIX)
#define COM_SESSION_DATA_CONVERSION_REQUIRED(_PCOM) \
( COM_SESSION_IS_TO_AS400(_PCOM) || COM_SESSION_IS_TO_VL400(_PCOM) || ( COM_SESSION_IS_TO_OTHER(_PCOM) && !( COM_SESSION_IS_TO_UTF8_SYSTEM(_PCOM) ) ) )
#endif

#define COM_SESSION_IS_TO_UTF8_SYSTEM(_PCOM)       FALSE /* \
( (_PCOM)->chConnectionType == X_CONNECT_TYPE_CLIENT_TO_LINUX ) */

#define COM_SESSION_UPPERCASE_SECURITY(_PCOM) \
( COM_SESSION_IS_TO_AS400(_PCOM) || COM_SESSION_IS_TO_VL400(_PCOM) )


#define X_COM_UPGD_UNNECESSARY     '\x01'
#define X_COM_UPGD_ERROR           '\x02'
#define X_COM_UPGD_DOWNLOAD_NEEDED '\x03'
#define X_COM_UPGD_UPDATE_X        '\x04'

#define X_COM_TRANSFER_FILE_TYPE_BINARY '\x01'
#define X_COM_TRANSFER_FILE_TYPE_TEXT   '\x02'
#define X_COM_TRANSFER_FILE_TYPE_EMPTY  '\x03'
#define X_COM_TRANSFER_FILE_TYPE_SOURCE '\x04' /* Stays in Windows codepage */
#define X_COM_TRANSFER_FILE_TYPE_UTF8   '\x05'

#define X_COM_BUILD_NOT_AVAILABLE  '\x01'
#define X_COM_BUILD_IN_PACKAGE     '\x02'
#define X_COM_BUILD_IN_XBOOT       '\x03'

#define X_COM_BUILD_NOT_REQUIRED       '\x01'
#define X_COM_BUILD_REQUIRED           '\x02'
#define X_COM_BUILD_COMPARE_VERSIONS   '\x03'
#define X_COM_BUILD_CAB1_ONLY          '\x04'

/* ================================================================= */
/*               Record Length Handling                              */
/* ================================================================= */

#define X_CONNECT_DEFAULT_TEMP_AREA_SIZE \
   (COM_SESSION_IS_TO_AS400(pComputer) \
      ? (10 * 1024) \
      : ( ( sizeof( X_COM_VECTOR_LIST ) * 2 ) \
          + sizeof( X_INT16 ) \
          + sizeof( XFIELDSTATE ) \
          + sizeof( X_UINT32 ) \
          + X_MAX_CHAR_FIELD_LEN + 1 ) )

#define _X_COM_BYTE_TO_INT(b, _INTTYPE) ((_INTTYPE)((X_UINT8)(b)))

#define _X_COM_BYTE_TO_UINT16(b) _X_COM_BYTE_TO_INT((b), X_UINT16)
#define _X_COM_BYTE_TO_UINT32(b) _X_COM_BYTE_TO_INT((b), X_UINT32)

#define X_COM_GET_REC_LEN(_VRECLEN, _SRECLEN) \
   { \
      _SRECLEN = (_X_COM_BYTE_TO_UINT16((_VRECLEN)[0]) << 8) \
                     | (_X_COM_BYTE_TO_UINT16((_VRECLEN)[1])); \
   }

#define X_COM_MAKE_REC_LEN(_VRECLEN, _SRECLEN) \
   { \
      X_UINT16 const sValue = (X_UINT16)(_SRECLEN); \
      (_VRECLEN)[0] = ((sValue >> 8) & 0xff); \
      (_VRECLEN)[1] = (sValue & 0xff); \
   }

/* ================================================================= */
/*             NETWORK OBJECT MANAGEMENT                             */
/* ================================================================= */

/* ENDIAN CONVERSION MACROS */

static const X_CHAR achEbcdicToAscii[] =
{
   /* Server x00 becomes Client -> */ '\x00',
   /* Server x01 becomes Client -> */ '\x01',
   /* Server x02 becomes Client -> */ '\x02',
   /* Server x03 becomes Client -> */ '\x03',
   /* Server x04 becomes Client -> */ '\x9C',
   /* Server x05 becomes Client -> */ '\x09',
   /* Server x06 becomes Client -> */ '\x86',
   /* Server x07 becomes Client -> */ '\x7F',
   /* Server x08 becomes Client -> */ '\x97',
   /* Server x09 becomes Client -> */ '\x8D',
   /* Server x0A becomes Client -> */ '\x8E',
   /* Server x0B becomes Client -> */ '\x0B',
   /* Server x0C becomes Client -> */ '\x0C',
   /* Server x0D becomes Client -> */ '\x0D',
   /* Server x0E becomes Client -> */ '\x0E',
   /* Server x0F becomes Client -> */ '\x0F',
   /* Server x10 becomes Client -> */ '\x10',
   /* Server x11 becomes Client -> */ '\x11',
   /* Server x12 becomes Client -> */ '\x12',
   /* Server x13 becomes Client -> */ '\x13',
   /* Server x14 becomes Client -> */ '\x9D',
   /* Server x15 becomes Client -> */ '\x85',
   /* Server x16 becomes Client -> */ '\x08',
   /* Server x17 becomes Client -> */ '\x87',
   /* Server x18 becomes Client -> */ '\x18',
   /* Server x19 becomes Client -> */ '\x19',
   /* Server x1A becomes Client -> */ '\x92',
   /* Server x1B becomes Client -> */ '\x8F',
   /* Server x1C becomes Client -> */ '\x1C',
   /* Server x1D becomes Client -> */ '\x1D',
   /* Server x1E becomes Client -> */ '\x1E',
   /* Server x1F becomes Client -> */ '\x1F',
   /* Server x20 becomes Client -> */ '\x80',
   /* Server x21 becomes Client -> */ '\x81',
   /* Server x22 becomes Client -> */ '\x82',
   /* Server x23 becomes Client -> */ '\x83',
   /* Server x24 becomes Client -> */ '\x84',
   /* Server x25 becomes Client -> */ '\x0A',
   /* Server x26 becomes Client -> */ '\x17',
   /* Server x27 becomes Client -> */ '\x1B',
   /* Server x28 becomes Client -> */ '\x88',
   /* Server x29 becomes Client -> */ '\x89',
   /* Server x2A becomes Client -> */ '\x8A',
   /* Server x2B becomes Client -> */ '\x8B',
   /* Server x2C becomes Client -> */ '\x8C',
   /* Server x2D becomes Client -> */ '\x05',
   /* Server x2E becomes Client -> */ '\x06',
   /* Server x2F becomes Client -> */ '\x07',
   /* Server x30 becomes Client -> */ '\x90',
   /* Server x31 becomes Client -> */ '\x91',
   /* Server x32 becomes Client -> */ '\x16',
   /* Server x33 becomes Client -> */ '\x93',
   /* Server x34 becomes Client -> */ '\x94',
   /* Server x35 becomes Client -> */ '\x95',
   /* Server x36 becomes Client -> */ '\x96',
   /* Server x37 becomes Client -> */ '\x04',
   /* Server x38 becomes Client -> */ '\x98',
   /* Server x39 becomes Client -> */ '\x99',
   /* Server x3A becomes Client -> */ '\x9A',
   /* Server x3B becomes Client -> */ '\x9B',
   /* Server x3C becomes Client -> */ '\x14',
   /* Server x3D becomes Client -> */ '\x15',
   /* Server x3E becomes Client -> */ '\x9E',
   /* Server x3F becomes Client -> */ '\x1A',
   /* Server x40 becomes Client -> */ '\x20',
   /* Server x41 becomes Client -> */ '\xA0',
   /* Server x42 becomes Client -> */ '\xA1',
   /* Server x43 becomes Client -> */ '\xA2',
   /* Server x44 becomes Client -> */ '\xA3',
   /* Server x45 becomes Client -> */ '\xA4',
   /* Server x46 becomes Client -> */ '\xA5',
   /* Server x47 becomes Client -> */ '\xA6',
   /* Server x48 becomes Client -> */ '\xA7',
   /* Server x49 becomes Client -> */ '\xA8',
   /* Server x4A becomes Client -> */ '\x5B',
   /* Server x4B becomes Client -> */ '\x2E',
   /* Server x4C becomes Client -> */ '\x3C',
   /* Server x4D becomes Client -> */ '\x28',
   /* Server x4E becomes Client -> */ '\x2B',
   /* Server x4F becomes Client -> */ '\x21',
   /* Server x50 becomes Client -> */ '\x26',
   /* Server x51 becomes Client -> */ '\xA9',
   /* Server x52 becomes Client -> */ '\xAA',
   /* Server x53 becomes Client -> */ '\xAB',
   /* Server x54 becomes Client -> */ '\xAC',
   /* Server x55 becomes Client -> */ '\xAD',
   /* Server x56 becomes Client -> */ '\xAE',
   /* Server x57 becomes Client -> */ '\xAF',
   /* Server x58 becomes Client -> */ '\xB0',
   /* Server x59 becomes Client -> */ '\xB1',
   /* Server x5A becomes Client -> */ '\x5D',
   /* Server x5B becomes Client -> */ '\x24',
   /* Server x5C becomes Client -> */ '\x2A',
   /* Server x5D becomes Client -> */ '\x29',
   /* Server x5E becomes Client -> */ '\x3B',
   /* Server x5F becomes Client -> */ '\x5E',
   /* Server x60 becomes Client -> */ '\x2D',
   /* Server x61 becomes Client -> */ '\x2F',
   /* Server x62 becomes Client -> */ '\xB2',
   /* Server x63 becomes Client -> */ '\xB3',
   /* Server x64 becomes Client -> */ '\xB4',
   /* Server x65 becomes Client -> */ '\xB5',
   /* Server x66 becomes Client -> */ '\xB6',
   /* Server x67 becomes Client -> */ '\xB7',
   /* Server x68 becomes Client -> */ '\xB8',
   /* Server x69 becomes Client -> */ '\xB9',
   /* Server x6A becomes Client -> */ '\x7C',
   /* Server x6B becomes Client -> */ '\x2C',
   /* Server x6C becomes Client -> */ '\x25',
   /* Server x6D becomes Client -> */ '\x5F',
   /* Server x6E becomes Client -> */ '\x3E',
   /* Server x6F becomes Client -> */ '\x3F',
   /* Server x70 becomes Client -> */ '\xBA',
   /* Server x71 becomes Client -> */ '\xBB',
   /* Server x72 becomes Client -> */ '\xBC',
   /* Server x73 becomes Client -> */ '\xBD',
   /* Server x74 becomes Client -> */ '\xBE',
   /* Server x75 becomes Client -> */ '\xBF',
   /* Server x76 becomes Client -> */ '\xC0',
   /* Server x77 becomes Client -> */ '\xC1',
   /* Server x78 becomes Client -> */ '\xC2',
   /* Server x79 becomes Client -> */ '\x60',
   /* Server x7A becomes Client -> */ '\x3A',
   /* Server x7B becomes Client -> */ '\x23',
   /* Server x7C becomes Client -> */ '\x40',
   /* Server x7D becomes Client -> */ '\x27',
   /* Server x7E becomes Client -> */ '\x3D',
   /* Server x7F becomes Client -> */ '\x22',
   /* Server x80 becomes Client -> */ '\xC3',
   /* Server x81 becomes Client -> */ '\x61',
   /* Server x82 becomes Client -> */ '\x62',
   /* Server x83 becomes Client -> */ '\x63',
   /* Server x84 becomes Client -> */ '\x64',
   /* Server x85 becomes Client -> */ '\x65',
   /* Server x86 becomes Client -> */ '\x66',
   /* Server x87 becomes Client -> */ '\x67',
   /* Server x88 becomes Client -> */ '\x68',
   /* Server x89 becomes Client -> */ '\x69',
   /* Server x8A becomes Client -> */ '\xC4',
   /* Server x8B becomes Client -> */ '\xC5',
   /* Server x8C becomes Client -> */ '\xC6',
   /* Server x8D becomes Client -> */ '\xC7',
   /* Server x8E becomes Client -> */ '\xC8',
   /* Server x8F becomes Client -> */ '\xC9',
   /* Server x90 becomes Client -> */ '\xCA',
   /* Server x91 becomes Client -> */ '\x6A',
   /* Server x92 becomes Client -> */ '\x6B',
   /* Server x93 becomes Client -> */ '\x6C',
   /* Server x94 becomes Client -> */ '\x6D',
   /* Server x95 becomes Client -> */ '\x6E',
   /* Server x96 becomes Client -> */ '\x6F',
   /* Server x97 becomes Client -> */ '\x70',
   /* Server x98 becomes Client -> */ '\x71',
   /* Server x99 becomes Client -> */ '\x72',
   /* Server x9A becomes Client -> */ '\xCB',
   /* Server x9B becomes Client -> */ '\xCC',
   /* Server x9C becomes Client -> */ '\xCD',
   /* Server x9D becomes Client -> */ '\xCE',
   /* Server x9E becomes Client -> */ '\xCF',
   /* Server x9F becomes Client -> */ '\xD0',
   /* Server xA0 becomes Client -> */ '\xD1',
   /* Server xA1 becomes Client -> */ '\x7E',
   /* Server xA2 becomes Client -> */ '\x73',
   /* Server xA3 becomes Client -> */ '\x74',
   /* Server xA4 becomes Client -> */ '\x75',
   /* Server xA5 becomes Client -> */ '\x76',
   /* Server xA6 becomes Client -> */ '\x77',
   /* Server xA7 becomes Client -> */ '\x78',
   /* Server xA8 becomes Client -> */ '\x79',
   /* Server xA9 becomes Client -> */ '\x7A',
   /* Server xAA becomes Client -> */ '\xD2',
   /* Server xAB becomes Client -> */ '\xD3',
   /* Server xAC becomes Client -> */ '\xD4',
   /* Server xAD becomes Client -> */ '\xD5',
   /* Server xAE becomes Client -> */ '\xD6',
   /* Server xAF becomes Client -> */ '\xD7',
   /* Server xB0 becomes Client -> */ '\xD8',
   /* Server xB1 becomes Client -> */ '\xD9',
   /* Server xB2 becomes Client -> */ '\xDA',
   /* Server xB3 becomes Client -> */ '\xDB',
   /* Server xB4 becomes Client -> */ '\xDC',
   /* Server xB5 becomes Client -> */ '\xDD',
   /* Server xB6 becomes Client -> */ '\xDE',
   /* Server xB7 becomes Client -> */ '\xDF',
   /* Server xB8 becomes Client -> */ '\xE0',
   /* Server xB9 becomes Client -> */ '\xE1',
   /* Server xBA becomes Client -> */ '\xE2',
   /* Server xBB becomes Client -> */ '\xE3',
   /* Server xBC becomes Client -> */ '\xE4',
   /* Server xBD becomes Client -> */ '\xE5',
   /* Server xBE becomes Client -> */ '\xE6',
   /* Server xBF becomes Client -> */ '\xE7',
   /* Server xC0 becomes Client -> */ '\x7B',
   /* Server xC1 becomes Client -> */ '\x41',
   /* Server xC2 becomes Client -> */ '\x42',
   /* Server xC3 becomes Client -> */ '\x43',
   /* Server xC4 becomes Client -> */ '\x44',
   /* Server xC5 becomes Client -> */ '\x45',
   /* Server xC6 becomes Client -> */ '\x46',
   /* Server xC7 becomes Client -> */ '\x47',
   /* Server xC8 becomes Client -> */ '\x48',
   /* Server xC9 becomes Client -> */ '\x49',
   /* Server xCA becomes Client -> */ '\xE8',
   /* Server xCB becomes Client -> */ '\xE9',
   /* Server xCC becomes Client -> */ '\xEA',
   /* Server xCD becomes Client -> */ '\xEB',
   /* Server xCE becomes Client -> */ '\xEC',
   /* Server xCF becomes Client -> */ '\xED',
   /* Server xD0 becomes Client -> */ '\x7D',
   /* Server xD1 becomes Client -> */ '\x4A',
   /* Server xD2 becomes Client -> */ '\x4B',
   /* Server xD3 becomes Client -> */ '\x4C',
   /* Server xD4 becomes Client -> */ '\x4D',
   /* Server xD5 becomes Client -> */ '\x4E',
   /* Server xD6 becomes Client -> */ '\x4F',
   /* Server xD7 becomes Client -> */ '\x50',
   /* Server xD8 becomes Client -> */ '\x51',
   /* Server xD9 becomes Client -> */ '\x52',
   /* Server xDA becomes Client -> */ '\xEE',
   /* Server xDB becomes Client -> */ '\xEF',
   /* Server xDC becomes Client -> */ '\xF0',
   /* Server xDD becomes Client -> */ '\xF1',
   /* Server xDE becomes Client -> */ '\xF2',
   /* Server xDF becomes Client -> */ '\xF3',
   /* Server xE0 becomes Client -> */ '\x5C',
   /* Server xE1 becomes Client -> */ '\x9F',
   /* Server xE2 becomes Client -> */ '\x53',
   /* Server xE3 becomes Client -> */ '\x54',
   /* Server xE4 becomes Client -> */ '\x55',
   /* Server xE5 becomes Client -> */ '\x56',
   /* Server xE6 becomes Client -> */ '\x57',
   /* Server xE7 becomes Client -> */ '\x58',
   /* Server xE8 becomes Client -> */ '\x59',
   /* Server xE9 becomes Client -> */ '\x5A',
   /* Server xEA becomes Client -> */ '\xF4',
   /* Server xEB becomes Client -> */ '\xF5',
   /* Server xEC becomes Client -> */ '\xF6',
   /* Server xED becomes Client -> */ '\xF7',
   /* Server xEE becomes Client -> */ '\xF8',
   /* Server xEF becomes Client -> */ '\xF9',
   /* Server xF0 becomes Client -> */ '\x30',
   /* Server xF1 becomes Client -> */ '\x31',
   /* Server xF2 becomes Client -> */ '\x32',
   /* Server xF3 becomes Client -> */ '\x33',
   /* Server xF4 becomes Client -> */ '\x34',
   /* Server xF5 becomes Client -> */ '\x35',
   /* Server xF6 becomes Client -> */ '\x36',
   /* Server xF7 becomes Client -> */ '\x37',
   /* Server xF8 becomes Client -> */ '\x38',
   /* Server xF9 becomes Client -> */ '\x39',
   /* Server xFA becomes Client -> */ '\xFA',
   /* Server xFB becomes Client -> */ '\xFB',
   /* Server xFC becomes Client -> */ '\xFC',
   /* Server xFD becomes Client -> */ '\xFD',
   /* Server xFE becomes Client -> */ '\xFE',
   /* Server xFF becomes Client -> */ '\xFF'
};

/* ========================================== */
/* Default Client to Server Conversion Table  */
/* ========================================== */

static const X_CHAR achAsciiToEbcdic[] =
{
   /* Client x00 becomes Server -> */ '\x00',
   /* Client x01 becomes Server -> */ '\x01',
   /* Client x02 becomes Server -> */ '\x02',
   /* Client x03 becomes Server -> */ '\x03',
   /* Client x04 becomes Server -> */ '\x37',
   /* Client x05 becomes Server -> */ '\x2D',
   /* Client x06 becomes Server -> */ '\x2E',
   /* Client x07 becomes Server -> */ '\x2F',
   /* Client x08 becomes Server -> */ '\x16',
   /* Client x09 becomes Server -> */ '\x05',
   /* Client x0A becomes Server -> */ '\x25',
   /* Client x0B becomes Server -> */ '\x0B',
   /* Client x0C becomes Server -> */ '\x0C',
   /* Client x0D becomes Server -> */ '\x0D',
   /* Client x0E becomes Server -> */ '\x0E',
   /* Client x0F becomes Server -> */ '\x0F',
   /* Client x10 becomes Server -> */ '\x10',
   /* Client x11 becomes Server -> */ '\x11',
   /* Client x12 becomes Server -> */ '\x12',
   /* Client x13 becomes Server -> */ '\x13',
   /* Client x14 becomes Server -> */ '\x3C',
   /* Client x15 becomes Server -> */ '\x3D',
   /* Client x16 becomes Server -> */ '\x32',
   /* Client x17 becomes Server -> */ '\x26',
   /* Client x18 becomes Server -> */ '\x18',
   /* Client x19 becomes Server -> */ '\x19',
   /* Client x1A becomes Server -> */ '\x3F',
   /* Client x1B becomes Server -> */ '\x27',
   /* Client x1C becomes Server -> */ '\x1C',
   /* Client x1D becomes Server -> */ '\x1D',
   /* Client x1E becomes Server -> */ '\x1E',
   /* Client x1F becomes Server -> */ '\x1F',
   /* Client x20 becomes Server -> */ '\x40',
   /* Client x21 becomes Server -> */ '\x4F',
   /* Client x22 becomes Server -> */ '\x7F',
   /* Client x23 becomes Server -> */ '\x7B',
   /* Client x24 becomes Server -> */ '\x5B',
   /* Client x25 becomes Server -> */ '\x6C',
   /* Client x26 becomes Server -> */ '\x50',
   /* Client x27 becomes Server -> */ '\x7D',
   /* Client x28 becomes Server -> */ '\x4D',
   /* Client x29 becomes Server -> */ '\x5D',
   /* Client x2A becomes Server -> */ '\x5C',
   /* Client x2B becomes Server -> */ '\x4E',
   /* Client x2C becomes Server -> */ '\x6B',
   /* Client x2D becomes Server -> */ '\x60',
   /* Client x2E becomes Server -> */ '\x4B',
   /* Client x2F becomes Server -> */ '\x61',
   /* Client x30 becomes Server -> */ '\xF0',
   /* Client x31 becomes Server -> */ '\xF1',
   /* Client x32 becomes Server -> */ '\xF2',
   /* Client x33 becomes Server -> */ '\xF3',
   /* Client x34 becomes Server -> */ '\xF4',
   /* Client x35 becomes Server -> */ '\xF5',
   /* Client x36 becomes Server -> */ '\xF6',
   /* Client x37 becomes Server -> */ '\xF7',
   /* Client x38 becomes Server -> */ '\xF8',
   /* Client x39 becomes Server -> */ '\xF9',
   /* Client x3A becomes Server -> */ '\x7A',
   /* Client x3B becomes Server -> */ '\x5E',
   /* Client x3C becomes Server -> */ '\x4C',
   /* Client x3D becomes Server -> */ '\x7E',
   /* Client x3E becomes Server -> */ '\x6E',
   /* Client x3F becomes Server -> */ '\x6F',
   /* Client x40 becomes Server -> */ '\x7C',
   /* Client x41 becomes Server -> */ '\xC1',
   /* Client x42 becomes Server -> */ '\xC2',
   /* Client x43 becomes Server -> */ '\xC3',
   /* Client x44 becomes Server -> */ '\xC4',
   /* Client x45 becomes Server -> */ '\xC5',
   /* Client x46 becomes Server -> */ '\xC6',
   /* Client x47 becomes Server -> */ '\xC7',
   /* Client x48 becomes Server -> */ '\xC8',
   /* Client x49 becomes Server -> */ '\xC9',
   /* Client x4A becomes Server -> */ '\xD1',
   /* Client x4B becomes Server -> */ '\xD2',
   /* Client x4C becomes Server -> */ '\xD3',
   /* Client x4D becomes Server -> */ '\xD4',
   /* Client x4E becomes Server -> */ '\xD5',
   /* Client x4F becomes Server -> */ '\xD6',
   /* Client x50 becomes Server -> */ '\xD7',
   /* Client x51 becomes Server -> */ '\xD8',
   /* Client x52 becomes Server -> */ '\xD9',
   /* Client x53 becomes Server -> */ '\xE2',
   /* Client x54 becomes Server -> */ '\xE3',
   /* Client x55 becomes Server -> */ '\xE4',
   /* Client x56 becomes Server -> */ '\xE5',
   /* Client x57 becomes Server -> */ '\xE6',
   /* Client x58 becomes Server -> */ '\xE7',
   /* Client x59 becomes Server -> */ '\xE8',
   /* Client x5A becomes Server -> */ '\xE9',
   /* Client x5B becomes Server -> */ '\x4A',
   /* Client x5C becomes Server -> */ '\xE0',
   /* Client x5D becomes Server -> */ '\x5A',
   /* Client x5E becomes Server -> */ '\x5F',
   /* Client x5F becomes Server -> */ '\x6D',
   /* Client x60 becomes Server -> */ '\x79',
   /* Client x61 becomes Server -> */ '\x81',
   /* Client x62 becomes Server -> */ '\x82',
   /* Client x63 becomes Server -> */ '\x83',
   /* Client x64 becomes Server -> */ '\x84',
   /* Client x65 becomes Server -> */ '\x85',
   /* Client x66 becomes Server -> */ '\x86',
   /* Client x67 becomes Server -> */ '\x87',
   /* Client x68 becomes Server -> */ '\x88',
   /* Client x69 becomes Server -> */ '\x89',
   /* Client x6A becomes Server -> */ '\x91',
   /* Client x6B becomes Server -> */ '\x92',
   /* Client x6C becomes Server -> */ '\x93',
   /* Client x6D becomes Server -> */ '\x94',
   /* Client x6E becomes Server -> */ '\x95',
   /* Client x6F becomes Server -> */ '\x96',
   /* Client x70 becomes Server -> */ '\x97',
   /* Client x71 becomes Server -> */ '\x98',
   /* Client x72 becomes Server -> */ '\x99',
   /* Client x73 becomes Server -> */ '\xA2',
   /* Client x74 becomes Server -> */ '\xA3',
   /* Client x75 becomes Server -> */ '\xA4',
   /* Client x76 becomes Server -> */ '\xA5',
   /* Client x77 becomes Server -> */ '\xA6',
   /* Client x78 becomes Server -> */ '\xA7',
   /* Client x79 becomes Server -> */ '\xA8',
   /* Client x7A becomes Server -> */ '\xA9',
   /* Client x7B becomes Server -> */ '\xC0',
   /* Client x7C becomes Server -> */ '\x6A',
   /* Client x7D becomes Server -> */ '\xD0',
   /* Client x7E becomes Server -> */ '\xA1',
   /* Client x7F becomes Server -> */ '\x07',
   /* Client x80 becomes Server -> */ '\x20',
   /* Client x81 becomes Server -> */ '\x21',
   /* Client x82 becomes Server -> */ '\x22',
   /* Client x83 becomes Server -> */ '\x23',
   /* Client x84 becomes Server -> */ '\x24',
   /* Client x85 becomes Server -> */ '\x15',
   /* Client x86 becomes Server -> */ '\x06',
   /* Client x87 becomes Server -> */ '\x17',
   /* Client x88 becomes Server -> */ '\x28',
   /* Client x89 becomes Server -> */ '\x29',
   /* Client x8A becomes Server -> */ '\x2A',
   /* Client x8B becomes Server -> */ '\x2B',
   /* Client x8C becomes Server -> */ '\x2C',
   /* Client x8D becomes Server -> */ '\x09',
   /* Client x8E becomes Server -> */ '\x0A',
   /* Client x8F becomes Server -> */ '\x1B',
   /* Client x90 becomes Server -> */ '\x30',
   /* Client x91 becomes Server -> */ '\x31',
   /* Client x92 becomes Server -> */ '\x1A',
   /* Client x93 becomes Server -> */ '\x33',
   /* Client x94 becomes Server -> */ '\x34',
   /* Client x95 becomes Server -> */ '\x35',
   /* Client x96 becomes Server -> */ '\x36',
   /* Client x97 becomes Server -> */ '\x08',
   /* Client x98 becomes Server -> */ '\x38',
   /* Client x99 becomes Server -> */ '\x39',
   /* Client x9A becomes Server -> */ '\x3A',
   /* Client x9B becomes Server -> */ '\x3B',
   /* Client x9C becomes Server -> */ '\x04',
   /* Client x9D becomes Server -> */ '\x14',
   /* Client x9E becomes Server -> */ '\x3E',
   /* Client x9F becomes Server -> */ '\xE1',
   /* Client xA0 becomes Server -> */ '\x41',
   /* Client xA1 becomes Server -> */ '\x42',
   /* Client xA2 becomes Server -> */ '\x43',
   /* Client xA3 becomes Server -> */ '\x44',
   /* Client xA4 becomes Server -> */ '\x45',
   /* Client xA5 becomes Server -> */ '\x46',
   /* Client xA6 becomes Server -> */ '\x47',
   /* Client xA7 becomes Server -> */ '\x48',
   /* Client xA8 becomes Server -> */ '\x49',
   /* Client xA9 becomes Server -> */ '\x51',
   /* Client xAA becomes Server -> */ '\x52',
   /* Client xAB becomes Server -> */ '\x53',
   /* Client xAC becomes Server -> */ '\x54',
   /* Client xAD becomes Server -> */ '\x55',
   /* Client xAE becomes Server -> */ '\x56',
   /* Client xAF becomes Server -> */ '\x57',
   /* Client xB0 becomes Server -> */ '\x58',
   /* Client xB1 becomes Server -> */ '\x59',
   /* Client xB2 becomes Server -> */ '\x62',
   /* Client xB3 becomes Server -> */ '\x63',
   /* Client xB4 becomes Server -> */ '\x64',
   /* Client xB5 becomes Server -> */ '\x65',
   /* Client xB6 becomes Server -> */ '\x66',
   /* Client xB7 becomes Server -> */ '\x67',
   /* Client xB8 becomes Server -> */ '\x68',
   /* Client xB9 becomes Server -> */ '\x69',
   /* Client xBA becomes Server -> */ '\x70',
   /* Client xBB becomes Server -> */ '\x71',
   /* Client xBC becomes Server -> */ '\x72',
   /* Client xBD becomes Server -> */ '\x73',
   /* Client xBE becomes Server -> */ '\x74',
   /* Client xBF becomes Server -> */ '\x75',
   /* Client xC0 becomes Server -> */ '\x76',
   /* Client xC1 becomes Server -> */ '\x77',
   /* Client xC2 becomes Server -> */ '\x78',
   /* Client xC3 becomes Server -> */ '\x80',
   /* Client xC4 becomes Server -> */ '\x8A',
   /* Client xC5 becomes Server -> */ '\x8B',
   /* Client xC6 becomes Server -> */ '\x8C',
   /* Client xC7 becomes Server -> */ '\x8D',
   /* Client xC8 becomes Server -> */ '\x8E',
   /* Client xC9 becomes Server -> */ '\x8F',
   /* Client xCA becomes Server -> */ '\x90',
   /* Client xCB becomes Server -> */ '\x9A',
   /* Client xCC becomes Server -> */ '\x9B',
   /* Client xCD becomes Server -> */ '\x9C',
   /* Client xCE becomes Server -> */ '\x9D',
   /* Client xCF becomes Server -> */ '\x9E',
   /* Client xD0 becomes Server -> */ '\x9F',
   /* Client xD1 becomes Server -> */ '\xA0',
   /* Client xD2 becomes Server -> */ '\xAA',
   /* Client xD3 becomes Server -> */ '\xAB',
   /* Client xD4 becomes Server -> */ '\xAC',
   /* Client xD5 becomes Server -> */ '\xAD',
   /* Client xD6 becomes Server -> */ '\xAE',
   /* Client xD7 becomes Server -> */ '\xAF',
   /* Client xD8 becomes Server -> */ '\xB0',
   /* Client xD9 becomes Server -> */ '\xB1',
   /* Client xDA becomes Server -> */ '\xB2',
   /* Client xDB becomes Server -> */ '\xB3',
   /* Client xDC becomes Server -> */ '\xB4',
   /* Client xDD becomes Server -> */ '\xB5',
   /* Client xDE becomes Server -> */ '\xB6',
   /* Client xDF becomes Server -> */ '\xB7',
   /* Client xE0 becomes Server -> */ '\xB8',
   /* Client xE1 becomes Server -> */ '\xB9',
   /* Client xE2 becomes Server -> */ '\xBA',
   /* Client xE3 becomes Server -> */ '\xBB',
   /* Client xE4 becomes Server -> */ '\xBC',
   /* Client xE5 becomes Server -> */ '\xBD',
   /* Client xE6 becomes Server -> */ '\xBE',
   /* Client xE7 becomes Server -> */ '\xBF',
   /* Client xE8 becomes Server -> */ '\xCA',
   /* Client xE9 becomes Server -> */ '\xCB',
   /* Client xEA becomes Server -> */ '\xCC',
   /* Client xEB becomes Server -> */ '\xCD',
   /* Client xEC becomes Server -> */ '\xCE',
   /* Client xED becomes Server -> */ '\xCF',
   /* Client xEE becomes Server -> */ '\xDA',
   /* Client xEF becomes Server -> */ '\xDB',
   /* Client xF0 becomes Server -> */ '\xDC',
   /* Client xF1 becomes Server -> */ '\xDD',
   /* Client xF2 becomes Server -> */ '\xDE',
   /* Client xF3 becomes Server -> */ '\xDF',
   /* Client xF4 becomes Server -> */ '\xEA',
   /* Client xF5 becomes Server -> */ '\xEB',
   /* Client xF6 becomes Server -> */ '\xEC',
   /* Client xF7 becomes Server -> */ '\xED',
   /* Client xF8 becomes Server -> */ '\xEE',
   /* Client xF9 becomes Server -> */ '\xEF',
   /* Client xFA becomes Server -> */ '\xFA',
   /* Client xFB becomes Server -> */ '\xFB',
   /* Client xFC becomes Server -> */ '\xFC',
   /* Client xFD becomes Server -> */ '\xFD',
   /* Client xFE becomes Server -> */ '\xFE',
   /* Client xFF becomes Server -> */ '\xFF'
};

#define _X_COM_TYPE_CHECK(_VALUE, _TYPE) \
   { \
      const _TYPE *const _sanity_check = &(_VALUE); /* Don't do casting here */ \
      (void)_sanity_check; /* suppress warning about unused variable */ \
   }

#define _X_COM_BSWAP_2(_p) \
   { \
      X_PUINT8 const p = (X_PUINT8)(_p); \
      X_UINT8 t; \
      t = p[0]; p[0] = p[1]; p[1] = t; \
   }
#define _X_COM_BSWAP_4(_p) \
   { \
      X_PUINT8 const p = (X_PUINT8)(_p); \
      X_UINT8 t; \
      t = p[0]; p[0] = p[3]; p[3] = t; \
      t = p[1]; p[1] = p[2]; p[2] = t; \
   }
#define _X_COM_BSWAP_8(_p) \
   { \
      X_PUINT8 const p = (X_PUINT8)(_p); \
      X_UINT8 t; \
      t = p[0]; p[0] = p[7]; p[7] = t; \
      t = p[1]; p[1] = p[6]; p[6] = t; \
      t = p[2]; p[2] = p[5]; p[5] = t; \
      t = p[3]; p[3] = p[4]; p[4] = t; \
   }

#if defined(X_BIG_ENDIAN)

#define X_INT16_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_INT16) \
      _X_COM_BSWAP_2(&(_VALUE)) \
   }

#define X_INT16_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_INT16_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_PINT16_PLATFORM_TO_NETWORK_ENDIAN(_PVALUE) \
   { \
      _X_COM_TYPE_CHECK(*(_PVALUE), X_INT16) \
      _X_COM_BSWAP_2((_PVALUE)) \
   }

#define X_PINT16_NETWORK_TO_PLATFORM_ENDIAN(_PVALUE) \
   X_PINT16_PLATFORM_TO_NETWORK_ENDIAN(_PVALUE)

#define X_UINT16_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_UINT16) \
      _X_COM_BSWAP_2(&(_VALUE)) \
   }

#define X_UINT16_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_UINT16_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_INT32_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_INT32) \
      _X_COM_BSWAP_4(&(_VALUE)) \
   }

#define X_INT32_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_INT32_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_UINT32_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_UINT32) \
      _X_COM_BSWAP_4(&(_VALUE)) \
   }

#define X_UINT32_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_UINT32_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_INT64_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_INT64) \
      _X_COM_BSWAP_8(&(_VALUE)) \
   }

#define X_INT64_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_INT64_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_UINT64_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_UINT64) \
      _X_COM_BSWAP_8(&(_VALUE)) \
   }

#define X_UINT64_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_UINT64_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_BOOL_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_BOOL) \
      _X_COM_BSWAP_4(&(_VALUE)) \
   }

#define X_BOOL_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_BOOL_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_FLOAT_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_FLOAT) \
      _X_COM_BSWAP_4(&(_VALUE)) \
   }

#define X_FLOAT_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_FLOAT_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_DOUBLE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, X_DOUBLE) \
      _X_COM_BSWAP_8(&(_VALUE)) \
   }

#define X_DOUBLE_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_DOUBLE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE)

#define X_FIELDSTATE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, XFIELDSTATE); \
      _X_COM_BSWAP_4(&(_VALUE)) \
   }

#define X_FIELDSTATE_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_FIELDSTATE_PLATFORM_TO_NETWORK_ENDIAN( _VALUE )

#define X_FUNCTIONSTATE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   { \
      _X_COM_TYPE_CHECK(_VALUE, XFUNCTIONSTATE); \
      _X_COM_BSWAP_4(&(_VALUE)) \
   }

#define X_FUNCTIONSTATE_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   X_FUNCTIONSTATE_PLATFORM_TO_NETWORK_ENDIAN( _VALUE )

#else /* X_OPERATING_SYSTEM_UNIX */

#define X_INT16_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_INT16)

#define X_INT16_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_INT16)

#define X_PINT16_PLATFORM_TO_NETWORK_ENDIAN(_PVALUE) \
   _X_COM_TYPE_CHECK(*(_PVALUE), X_INT16)

#define X_PINT16_NETWORK_TO_PLATFORM_ENDIAN(_PVALUE) \
   _X_COM_TYPE_CHECK(*(_PVALUE), X_INT16)

#define X_UINT16_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_UINT16)

#define X_UINT16_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_UINT16)

#define X_INT32_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_INT32)

#define X_INT32_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_INT32)

#define X_UINT32_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_UINT32)

#define X_UINT32_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_UINT32)

#define X_INT64_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_INT64)

#define X_INT64_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_INT64)

#define X_UINT64_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_UINT64)

#define X_UINT64_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_UINT64)

#define X_BOOL_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_BOOL)

#define X_BOOL_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_BOOL)

#define X_FLOAT_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_FLOAT)

#define X_FLOAT_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_FLOAT)

#define X_DOUBLE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_DOUBLE)

#define X_DOUBLE_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, X_DOUBLE)

#define X_FIELDSTATE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, XFIELDSTATE)

#define X_FIELDSTATE_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, XFIELDSTATE)

#define X_FUNCTIONSTATE_PLATFORM_TO_NETWORK_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, XFUNCTIONSTATE)

#define X_FUNCTIONSTATE_NETWORK_TO_PLATFORM_ENDIAN(_VALUE) \
   _X_COM_TYPE_CHECK(_VALUE, XFUNCTIONSTATE)

#endif /* X_OPERATING_SYSTEM_UNIX */

/* -------------------------------------------------- */
/* Network Object Management                          */
/* Max bytes = X_NET_OBJECT_MAXIMUM_NAME_LENGTH       */
/* -------------------------------------------------- */

// format for intptr_t
#ifdef X_SIZE_T_64BIT
#ifdef X_L64
#define _X_NETNAME_PTR_FMT      "%lX"
#else
#define _X_NETNAME_PTR_FMT      "%llX"
#endif
#else
#define _X_NETNAME_PTR_FMT      "%X"
#endif

#define X_MAKE_DBM_SEQ_NETNAME(_RESULT,_TYPE,_LINK,_ID1,_ID2) \
if ( X_IS_COMPONENT(pX_Fun) ) \
{ \
   X_VCHAR vchTemp[ X_NET_OBJECT_GENERATED_NAME_LENGTH + 1 ]; \
   sprintf( vchTemp, "%lX.%s."_X_NETNAME_PTR_FMT".%c.%s.%hX", \
            ((long)(_LINK)), pX_Fun->vchOwnProcess, X_FUN_FUNCTION_INSTANCE_ID(pX_Fun), _TYPE+0x20, pX_DBM->vchTableName, ((X_SHORT)pX_DBM->sSequence) ); \
   if ( pX_Ids->fInternalTracing ) { TRACE_EVENT( pX_Ids, TRACE_NOT_SIGNIFICANT, "DBM1 <", vchTemp, ">" ) } \
   X_EncodeNetObjectName( pX_Ids, _RESULT, X_NET_OBJECT_MAXIMUM_NAME_LENGTH, vchTemp ); \
   if ( pX_Ids->fInternalTracing ) { TRACE_EVENT( pX_Ids, TRACE_NOT_SIGNIFICANT, "DBM2 <", _RESULT, ">" ) } \
} \
else \
   sprintf( _RESULT, "%ld.%s.%c.%s.%d", \
            ((long)(_LINK)), pX_Fun->vchName, _TYPE, pX_DBM->vchTableName, ((X_SHORT)pX_DBM->sSequence) );

#define X_MAKE_FUNCTION_NETNAME(_RESULT,_TYPE,_LINK,_ID1,_ID2) \
if ( X_IS_COMPONENT(pX_Fun) ) \
{ \
   X_VCHAR vchTemp[ X_NET_OBJECT_GENERATED_NAME_LENGTH + 1 ]; \
   sprintf( vchTemp, "%lX.%s."_X_NETNAME_PTR_FMT".%c.%hX.%hX", \
            ((long)(_LINK)), pX_Fun->vchOwnProcess, X_FUN_FUNCTION_INSTANCE_ID(pX_Fun), _TYPE+0x20, ((X_SHORT)_ID1), ((X_SHORT)_ID2) ); \
   if ( pX_Ids->fInternalTracing ) { TRACE_EVENT( pX_Ids, TRACE_NOT_SIGNIFICANT, "FUN1 <", vchTemp, ">" ) } \
   X_EncodeNetObjectName( pX_Ids, _RESULT, X_NET_OBJECT_MAXIMUM_NAME_LENGTH, vchTemp ); \
   if ( pX_Ids->fInternalTracing ) { TRACE_EVENT( pX_Ids, TRACE_NOT_SIGNIFICANT, "FUN2 <", _RESULT, ">" ) } \
} \
else \
   sprintf( _RESULT, "%ld.%s.%c.%d.%d", \
            ((long)(_LINK)), pX_Fun->vchName, _TYPE, ((X_SHORT)_ID1), ((X_SHORT)_ID2) );

#define X_MAKE_FUNCTION_SEQ_NETNAME(_RESULT,_TYPE,_ID1,_ID2) \
if ( X_IS_COMPONENT(pX_Fun) ) \
{ \
   X_VCHAR vchTemp[ X_NET_OBJECT_GENERATED_NAME_LENGTH + 1 ]; \
   sprintf( vchTemp, "%s."_X_NETNAME_PTR_FMT".%c.%hX.%hX.%hX", \
            pX_Fun->vchOwnProcess, X_FUN_FUNCTION_INSTANCE_ID(pX_Fun), _TYPE+0x20, ((X_SHORT)pX_Fun->sSequence), ((X_SHORT)_ID1), ((X_SHORT)_ID2) ); \
   if ( pX_Ids->fInternalTracing ) { TRACE_EVENT( pX_Ids, TRACE_NOT_SIGNIFICANT, "FUN SEQ1 <", vchTemp, ">" ) } \
   X_EncodeNetObjectName( pX_Ids, _RESULT, X_NET_OBJECT_MAXIMUM_NAME_LENGTH, vchTemp ); \
   if ( pX_Ids->fInternalTracing ) { TRACE_EVENT( pX_Ids, TRACE_NOT_SIGNIFICANT, "FUN SEQ2 <", _RESULT, ">" ) } \
} \
else \
   sprintf( _RESULT, "%s.%c.%d.%d.%d", \
            pX_Fun->vchName, _TYPE, ((X_SHORT)pX_Fun->sSequence), ((X_SHORT)_ID1), ((X_SHORT)_ID2) );

#define X_NET_OBJECT_GENERATED_NAME_LENGTH   64
#define X_NET_OBJECT_MAXIMUM_NAME_LENGTH     48
#define X_NET_MAXIMUM_OBJECTS_PER_POD        256
#define X_NET_MAXIMUM_OBJECT_TYPES           20

typedef X_UINT32 X_NET_OBJECT_ID;
typedef X_NET_OBJECT_ID * PX_NET_OBJECT_ID;

typedef X_UINT32 X_NET_REQUEST_ID;
typedef X_NET_REQUEST_ID * PX_NET_REQUEST_ID;

typedef X_BOOL FNOBJECTPROCESSOR( struct X_IDS *,
                                  struct X_PRO *,
                                  struct X_FUN *,
                                  struct X_CONNECT_COMPUTER *,
                                  X_NET_OBJECT_ID,
                                  X_NET_OBJECT_ID,
                                  X_LONG,
                                  X_PVOID,
                                  X_PVOID *,
                                  X_PLONG,
                                  X_PLONG );

typedef FNOBJECTPROCESSOR  * PFNOBJECTPROCESSOR;

typedef PFNOBJECTPROCESSOR * PPFNOBJECTPROCESSOR;

/** moved from x_glodef.h  **/
typedef X_LONG (*X_PFNUNLOADFILEDATA)( struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_VCHAR       ,
                                       X_BOOL       );

typedef X_LONG (*X_PFNLOADFILEDATA)(   struct X_IDS *,
                                       struct X_PRO *,
                                       struct X_FUN *,
                                       X_VCHAR      );

/* -------------- */
/* Network Object */
/* -------------- */


typedef struct _X_NET_OBJECT
{
   X_NET_OBJECT_ID    ulObjectId;
   X_NET_OBJECT_ID    ulLinkedObjectId;
   X_VCHAR            vchObjectName[X_NET_OBJECT_MAXIMUM_NAME_LENGTH];
   X_INT32            lObjectSize;
   X_PVOID            pvObject;

}     X_NET_OBJECT,
  *  PX_NET_OBJECT,
 ** PPX_NET_OBJECT;

/* -------------- */
/* Pod of objects */
/* -------------- */

typedef struct _X_NET_OBJECT_POD
{
   struct _X_NET_OBJECT_POD * pNextObjectPod;
   X_BOOL                     fSorted;
   X_UINT32                   ulObjectsinPod;
   X_NET_OBJECT               Object[X_NET_MAXIMUM_OBJECTS_PER_POD];

}     X_NET_OBJECT_POD,
  *  PX_NET_OBJECT_POD,
 ** PPX_NET_OBJECT_POD;


/* ------------ */
/* Object Types */
/* ------------ */


#define X_NET_OBJECT_TYPE_BROWSE_LIST_DEF          '\x21'
#define X_NET_OBJECT_TYPE_BROWSE_LIST_COLUMN_DEFS  '\x22'
#define X_NET_OBJECT_TYPE_FUNCTION                 '\x23'
#define X_NET_OBJECT_TYPE_FUNCTION_FIELD           '\x24'
#define X_NET_OBJECT_TYPE_DBM                      '\x25'
#define X_NET_OBJECT_TYPE_GROUP                    '\x26'
#define X_NET_OBJECT_TYPE_KEY                      '\x27'
#define X_NET_OBJECT_TYPE_WHERE                    '\x28'
#define X_NET_OBJECT_TYPE_FUNCTION_BOUNDS          '\x29'
#define X_NET_OBJECT_TYPE_FUNCTION_RENAMES         '\x30'

typedef struct _X_NET_OBJECT_TYPE
{
   X_CHAR              chType;
   PFNOBJECTPROCESSOR  pfnSendProcessor;
   PFNOBJECTPROCESSOR  pfnReceiveProcessor;
   PFNOBJECTPROCESSOR  pfnDestructProcessor;
   X_NET_OBJECT_ID     ulNextObjectId;
   PX_NET_OBJECT_POD   pFirstObjectPod;
   X_INT32             lMaximumSize;

}     X_NET_OBJECT_TYPE,
  *  PX_NET_OBJECT_TYPE,
 ** PPX_NET_OBJECT_TYPE;

/* --------------------------- */
/* Type Clusters of Pod Chains */
/* --------------------------- */

typedef struct _X_NET_OBJECT_TYPE_CLUSTER
{
   X_UINT32           ulTotalTypes;
   X_NET_OBJECT_TYPE  Cluster[X_NET_MAXIMUM_OBJECT_TYPES];

}     X_NET_OBJECT_TYPE_CLUSTER,
  *  PX_OBJECT_TYPE_CLUSTER,
 ** PPX_OBJECT_TYPE_CLUSTER;


/* ----------------- */
/* Transaction Queue */
/* ----------------- */

typedef struct _X_COM_QUEUE_ENTRY
{
   struct _X_COM_QUEUE_ENTRY * pNextQueueEntry;
   X_UINT32                    ulQueueEntrySize;
   X_VCHAR                     vchQueueEntry[1]; /* Variable length queue entry */

}     X_COM_QUEUE_ENTRY,
  *  PX_COM_QUEUE_ENTRY,
 ** PPX_COM_QUEUE_ENTRY;

typedef struct _X_COM_QUEUE
{
   struct _X_COM_QUEUE * pNextQueue;
   X_NET_OBJECT_ID       ulQueueIdentifier;
   PX_COM_QUEUE_ENTRY    pFirstQueueEntry;
   PX_COM_QUEUE_ENTRY    pLastQueueEntry;
   X_INT32               lUserEntryCounter;

}     X_COM_QUEUE,
  *  PX_COM_QUEUE,
 ** PPX_COM_QUEUE;

/* =============================================== */   /* @4291M5 */
/* These are comms records so get constant packing */
/* =============================================== */

#include "x_strpck.h"

/* ================================================================= */
/*  X_COM_INTEGER : Standard Comminications Integer Value            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Sign            Type of Key                                       */
/* Value           Length of Key                                     */


typedef X_PACKED struct
{
   X_CHAR       chSign;
   X_FCHAR      fchValue[X_COM_INTEGER_DIGITS];
} X_COM_INTEGER;

/* ================================================================= */
/*  X_MKEYL : Key List Layout                                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Type            Type of Key                                       */
/* Length          Length of Key                                     */
/* Decimals        Number of Decimals                                */
/* MIOARPosition   Starting Position in MIOAR                        */

typedef X_PACKED struct
{
   X_CHAR       chType;
   X_FCHAR      fchLength[3];
   X_CHAR       chDecimals;
   X_FCHAR      fchMIOARPosition[4];
} X_MKEYL;

/* ================================================================= */
/*  X_MFLDL : Field List Layout                                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Name            Type of Field                                     */
/* Type            Type of Field                                     */
/* Length          Length of Field                                   */
/* Decimals        Number of Decimals                                */
/* MIOARPosition   Starting Position in MIOAR                        */
/* Ignore          Ignore this field                                 */
/* MERRBEntry      Position in Error Block                           */

typedef X_PACKED struct
{
   X_FCHAR      fchName[10];
   X_CHAR       chType;
   X_FCHAR      fchLength[3];
   X_CHAR       chDecimals;
   X_FCHAR      fchMIOARPosition[4];
   X_CHAR       chIgnore;
   X_FCHAR      fchMERRBEntry[3];
} X_MFLDL;

/* ================================================================= */
/*  X_MERRB : Error Block Entry                                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Error           Error Indicator                                   */

typedef X_PACKED struct
{
   X_CHAR       chError;
} X_MERRB;

/* ================================================================= */
/*  X_MIOAR : I/O Area                                               */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* pNextMIOAR      Next MIOAR in MIOAR chain.                        */
/* vchReturnCode   Return associated with this MIOAR.                */
/* lRRNO           Relative record no. associated with this MIOAR    */
/* vchData         Data associated with this I/O Area                */
/*                 Defined length is 9999 bytes but in use length    */
/*                 may actually be allocated in the range 1 to 9999  */

typedef struct X_MIOAR
{
   struct X_MIOAR    *pNextMIOAR;
   X_CHAR            vchReturnCode[2+1];
   X_INT32           lRRNO;
   X_FCHAR           abfMappingFlags[ (X_MIOAR_MAX_KEYS +
                                       X_MIOAR_MAX_FIELDS) / 8 ];
   X_VCHAR           vchData[X_MIOAR_MAX_LENGTH];
} * PX_MIOAR;

/* ================================================================= */
/*  X_MIOAR_MAP : Map of layout of X_MIOAR vchData                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Usage           Usage of area in X_MIOAR.vchData.                 */
/* MIOAROffset     Offset from start on X_MIOAR.vchData.             */
/* VectorNo        Vector that maps to/from this area.               */


typedef X_PACKED struct
{
   X_CHAR            chUsage;
   X_INT16           sMIOAROffset;
   X_INT16           sVectorNo;
} X_MIOAR_MAP;

/* ================================================================= */
/*  X_MIOAR_CTL : MIOAR Controlling / Definition Structure           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* cMIOARMap       Count of X_MIOAR_MAP structures that exist        */
/* pMIOARMap       Pointer to first X_MIOAR_MAP in contigous storage */
/*                                                                   */
/* cMKEYL          Count of X_MKEYL structures that exist            */
/* pMKEYL          Pointer to first X_MKEYL in contigous storage     */
/*                                                                   */
/* cMFLDL          Count of X_MFLDL structures that exist            */
/* pMFLDL          Pointer to first X_MFLDL in contigous storage     */
/*                                                                   */
/* cMERRB          Count of X_MERRB structures that exist            */
/* pMERRB          Pointer to first X_MERRB in contigous storage     */
/*                                                                   */
/* LengthMIOAR     Length of MIOAR blocks MIOAR chain.               */
/*                 Defined length is 9999 bytes but in use length    */
/*                 may actually be allocated in the range 1 to 9999  */
/* LengthKeys      Length of keys in MIOAR blocks.                   */
/* pFirstMIOAR     First MIOAR in MIOAR chain.                       */
/* pLastMIOAR      Last MIOAR in MIOAR chain.                        */
/* pCurrMIOAR      Current MIOAR processing for SELECTs.             */
/* lSelectLimit    Maximum records limit for SELECTs to this file    */
/* lSelectCount    Number of SELECTed records count                  */
/* pfMapValueBack  True for simple fields and components             */
/*                                                                   */


typedef struct X_MIOAR_CTL
{
   X_INT16        scMIOARMap;
   X_MIOAR_MAP    *pMIOARMap;
   X_INT16        scMKEYL;
   X_MKEYL        *pMKEYL;
   X_INT16        scMFLDL;
   X_MFLDL        *pMFLDL;
   X_INT16        scMERRB;
   X_MERRB        *pMERRB;
   X_INT16        sLengthMIOAR;
   X_INT16        sLengthKeys;
   struct X_MIOAR *pFirstMIOAR;
   struct X_MIOAR *pLastMIOAR;
   struct X_MIOAR *pCurrMIOAR;
   X_INT32        lSelectLimit;
   X_INT32        lSelectCount;

} * PX_MIOAR_CTL;

/* ========================================================== */
/* This structure will hold the address of the MIOC structure */
/* for the particular function and sequence number (unique)   */
/* ========================================================== */


typedef struct X_MIOC_LIST
{
   struct X_FUN        * pX_FunOwnerInstance;
   X_VCHAR               vchFunName[X_FUNCTION_NAME_LEN + 1]; /* Only for Retrieve from Server */
   X_INT16               sSequence;
   struct X_MIOAR_CTL  * pMIOC;
   struct X_MIOC_LIST  * pNextMIOC_L;
} * PX_MIOC_LIST;


/* ================================================================= */
/*  Communication Record Identifiers                                 */
/* ================================================================= */

#define X_CID_START_SESSION                    '\x01'
#define X_CID_SET_CLIENT_TO_SERVER_CONVERSION  '\x02'
#define X_CID_SET_SERVER_TO_CLIENT_CONVERSION  '\x03'
#define X_CID_TEXT_MESSAGE                     '\x04'
#define X_CID_END_OF_TRANSACTION               '\x05'
#define X_CID_END_OF_SESSION                   '\x06'
#define X_CID_FATAL_ERROR                      '\x07'

#define X_CID_SET_MKEYL                        '\x08'
#define X_CID_SET_MFLDL                        '\x09'
#define X_CID_SET_MERRB                        '\x0A'
#define X_CID_SET_MIOAR                        '\x0B'
#define X_CID_SET_RR_NUMBER                    '\x0C'
#define X_CID_RET_RR_NUMBER                    '\x0D'
#define X_CID_SET_FUNCTION_NAME                '\x0E'
#define X_CID_SET_OPNQRYF_VALUES               '\x0F'
#define X_CID_SET_IO_RETURN_CODE               '\x10'

#define X_CID_PERFORM_IO_OPERATION             '\x11'
#define X_CID_PERFORM_COMMIT                   '\x12'
#define X_CID_PERFORM_ROLLBACK                 '\x13'
#define X_CID_CLEAR_EXCHANGE_LIST              '\x14'
#define X_CID_ADD_TO_EXCHANGE_LIST             '\x15'
#define X_CID_ADD_TO_EXCHANGE_LIST_DIRECT      '\x39'
#define X_CID_CLEAR_STORED_WORKING_LISTS       '\x16'
#define X_CID_STORE_WORKING_LIST               '\x17'
#define X_CID_CALL_FUNCTION                    '\x18'

#define X_CID_ALLOCATE_CONFIRM                 '\x19'
#define X_CID_LOCK_OBJECT                      '\x20'
#define X_CID_UNLOCK_OBJECT                    '\x21'
#define X_CID_LOCK_OBJECT_RESULT               '\x23'
#define X_CID_DROP_FUNCTION_LOCKS              '\x24'

#define X_CID_CLEAR_FLD_KEY_COUNTS             '\x25'
#define X_CID_UNLOCK_OBJECT_RESULT             '\x26'

#define X_CID_CLEAR_EXPRESSIONS                '\x27'
#define X_CID_ADD_EXPRESSION_COMPONENT         '\x28'
#define X_CID_ADD_EXPRESSION_ACTIVITY          '\x29'

#define X_CID_TRANSFER_DIRECTORY               '\x30'
#define X_CID_CREATE_TRANSFER_DIRECTORY        '\x31'
#define X_CID_OPEN_TRANSFER_FILE               '\x32'
#define X_CID_WRITE_TRANSFER_FILE              '\x33'
#define X_CID_CLOSE_TRANSFER_FILE              '\x34'
#define X_CID_TRANSFER_RESULT                  '\x35'

#define X_CID_REQUEST_AUTO_VALUE               '\x36'
#define X_CID_RETURN_AUTO_VALUE                '\x37'

#define X_CID_EXCEPTION_ARGUMENTS              '\x38'
#define X_CID_NET_OBJECT                       '\x40'
#define X_CID_ACTIVATE_WORKING_LIST            '\x41'
#define X_CID_CALL_IOMODULE                    '\x42'
#define X_CID_ACTIVATE_FUNCTION                '\x43'
#define X_CID_ACTIVATE_DBM                     '\x44'
#define X_CID_VECTOR_LIST                      '\x45'
#define X_CID_CALL_IOMODULE_RESPONSE           '\x47'
#define X_CID_SWITCH_TO_QUEUE                  '\x48'
#define X_CID_SWITCH_FROM_QUEUE                '\x49'
#define X_CID_END_OF_QUEUED_TRANSACTION        '\x50'
#define X_CID_ERROR_LIST                       '\x51'
#define X_CID_REQUEST_AUTO_VALUE_DIRECT        '\x52'
#define X_CID_RETURN_AUTO_VALUE_DIRECT         '\x53'
#define X_CID_BEGIN_SYNC                       '\x54'
#define X_CID_END_SYNC                         '\x55'
#define X_CID_SET_SCKEYFLDS                    '\x56'
#define X_CID_CHECK_DLL_VERSIONS               '\x57'
#define X_CID_DLL_VERSION                      '\x58'
#define X_CID_CHECK_DLL_VERSIONS_RESPONSE      '\x59'
#define X_CID_DOWNLOAD_DLL                     '\x60'
#define X_CID_OPEN_TRANSFER_FILE_PCX           '\x61'
#define X_CID_BEGIN_DLL_DOWNLOAD               '\x62' /* No longer in use */
#define X_CID_END_DLL_DOWNLOAD                 '\x63' /* No longer in use */
#define X_CID_LIST_APPLICATIONS                '\x64'
#define X_CID_APPLICATION_LIST                 '\x65'
#define X_CID_CHECK_APP_STATUS                 '\x66'
#define X_CID_CHECK_APP_STATUS_RESPONSE        '\x67'
#define X_CID_PACKAGE_STATUS_LIST              '\x68'
#define X_CID_CHECK_OBJECT_AUTHORITY           '\x69'
#define X_CID_RET_OBJECT_AUTHORITY             '\x70'
#define X_CID_SET_SYSTEM_AUTHORITIES           '\x71'
#define X_CID_DOWNLOAD_DLL_2                   '\x72'
#define X_CID_END_OF_TRANSFER_FILES            '\x73'
#define X_CID_DOWNLOAD_PACKAGE                 '\x74'
#define X_CID_DOWNLOAD_BUILD                   '\x75'
#define X_CID_BLD_COMPONENT_LIST               '\x76'
#define X_CID_DOWNLOAD_BUILD_RESPONSE          '\x77'
#define X_CID_SET_MAPPING_FLAGS                '\x78'
#define X_CID_INDEXVOV_LIST                    '\x79'
#define X_CID_VECTOR_LIST_RDMLX                '\x80'
#define X_CID_WORKING_LIST_RDMLX               '\x81'
#define X_CID_SEND_EXCHANGE_LIST               '\x82'
#define X_CID_ADD_TO_EXCHANGE_LIST_RDMLX       '\x83'
#define X_CID_COPY_PACKAGE                     '\x84'
#define X_CID_REQUEST_TRANS_TABLE              '\x85'
#define X_CID_EVAL_VECTOR_LIST                 '\x86'
#define X_CID_SET_LAST_DBMS_ERROR              '\x87'
#define X_CID_CREATE_TRANSLATION_TABLES        '\x88'
#define X_CID_CHECK_MSI_STATUS                 '\x89'
#define X_CID_CHECK_MSI_STATUS_RESPONSE        '\x8A'
#define X_CID_MSI_STATUS_LIST                  '\x8B'
#define X_CID_MSI_FILE_LIST                    '\x8C'
#define X_CID_DOWNLOAD_MSI                     '\x8D'
#define X_CID_BOM_ENVELOPE                     '\x8E'


/* Next allocation is X'90' */

#define X_CID_NO_OPERATION_MESSAGE             '\x99' /* Used to make messages visible at higher level */

/* ================================================================= */
/*                 X_COM_GENERIC_RECORD                              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_GENERIC_RECORD;

/* ================================================================= */
/*                       X_COM_BEGIN_SYNC                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_INT32     lValue;
} X_COM_BEGIN_SYNC;

/* ================================================================= */
/*                      X_COM_VECTOR_LIST                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */


typedef X_PACKED struct _X_COM_VECTOR_LIST
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;

}    X_COM_VECTOR_LIST,
 *  PX_COM_VECTOR_LIST,
 ** PPX_COM_VECTOR_LIST;


/* ================================================================= */
/*                      X_COM_ERROR_LIST                             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */


typedef X_PACKED struct _X_COM_ERROR_LIST
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;

}    X_COM_ERROR_LIST,
 *  PX_COM_ERROR_LIST,
 ** PPX_COM_ERROR_LIST;

/* ================================================================= */
/*                 X_ALLOCATE_CONFIRM                                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_ALLOCATE_CONFIRM;


/* ================================================================= */
/*                 X_COM/CID_START_SESSION                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Partition       Partition                                         */
/* Language        Language                                          */
/* JobPriority     Job Priority                                      */
/* DateSource      Source of Date information                        */
/* TaskId          Task Id                                           */
/* CommitControl   Commitment Control                                */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchPartition[3];
   X_FCHAR     fchLanguage[4];
   X_FCHAR     fchJobPty[2];
   X_CHAR      chDateSource;
   X_FCHAR     fchTaskId[8];
   X_CHAR      chCommitControl;
   X_FCHAR     fchClienttoServerTableN[X_OBJECT_NAME_LEN];
   X_FCHAR     fchServertoClientTableN[X_OBJECT_NAME_LEN];
   X_FCHAR     fchClientType[X_COM_CLIENT_TYPE_LEN];
   X_INT32     lClientBuildNo;
} X_COM_START_SESSION;

/* ================================================================= */
/*                 X_CID_EXCEPTION_ARGUMENTS                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_VCHAR     vchXRUNExceptArgs[512 + 1];
   X_VCHAR     vchServerExceptArgs[512 + 1];
   X_VCHAR     vchXRUNDefaultArgs[4096 + 1];
   X_VCHAR     vchLUName[X_CONNECT_CPIC_LUNAME_LENGTH + 1];
} X_COM_EXCEPTION_ARGUMENTS ;

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_VCHAR     vchXRUNExceptArgs[256 + 1];
   X_VCHAR     vchServerExceptArgs[256 + 1];
   X_VCHAR     vchXRUNDefaultArgs[2048 + 1];
   X_VCHAR     vchLUName[X_CONNECT_CPIC_LUNAME_LENGTH + 1];
} X_COM_EXCEPTION_ARGUMENTS_V1;

/* ================================================================= */
/*            X_COM/CID_SET_CLIENT_TO_SERVER_CONVERSION              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ConvertTable    Conversion Table                                  */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchConvertTable[256];
} X_COM_SET_CLIENT_TO_SERVER_CONVERSION;

/* ================================================================= */
/*            X_COM/CID_SET_SERVER_TO_CLIENT_CONVERSION              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ConvertTable    Conversion Table                                  */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchConvertTable[256];
} X_COM_SET_SERVER_TO_CLIENT_CONVERSION;

/* ================================================================= */
/*                X_COM/CID_TEXT_MESSAGE                             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* MessageId       Message Identifier                                */
/* MessageFile     Message File                                      */
/* FstLevel        FirstLevel                                        */
/* SecLevelLength  Second Level Length                               */
/* SecLevel        Second Level Text                                 */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR               fchMessageId[7];
   X_FCHAR               fchMessageFile[10];
   X_FCHAR               fchFstLevel[132];
   X_COM_INTEGER  SecLevelLength;
   X_FCHAR               fchSecLevel[3000];
} X_COM_TEXT_MESSAGE;

/* ================================================================= */
/*                X_COM/CID_END_OF_TRANSACTION                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_END_OF_TRANSACTION;

/* ================================================================= */
/*                X_COM/CID_END_OF_SESSION                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_END_OF_SESSION;

/* ================================================================= */
/*                X_COM/CID_FATAL_ERROR                              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_FATAL_ERROR;

/* ================================================================= */
/*                X_COM/CID_SET_MKEYL                                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Numberof        Number of keys provided                           */
/* vchMKEYL        Array of MKEYL values                             */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  Numberof;
   X_VCHAR               vchMKEYL[X_MIOAR_MAX_KEYS * sizeof(X_MKEYL)];
}  X_COM_SET_MKEYL;

/* ================================================================= */
/*                X_COM/CID_SET_MFLDL                                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Numberof        Number of keys provided                           */
/* vchMFLDL        Array of MFLDL values                             */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  Numberof;
   X_VCHAR               vchMFLDL[X_MIOAR_MAX_FIELDS * sizeof(X_MFLDL)];
} X_COM_SET_MFLDL;

/* ================================================================= */
/*                X_COM/CID_SET_MERRB                                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Lengthof        Aggregate Length of MERRB used                    */
/* vchMERRB        MERRB Error Block Area                            */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  Lengthof;
   X_VCHAR               vchMERRB[X_MIOAR_MAX_FIELDS * sizeof(X_MERRB)];
} X_COM_SET_MERRB;

/* ================================================================= */
/*                X_COM/CID_SET_MIOAR                                */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Lengthof        Aggrgate Length of MIOAR used                     */
/* vchMIOAR        MIOAR Data Storage Area                           */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  Lengthof;
   X_VCHAR               vchMIOAR[X_MIOAR_MAX_LENGTH];
} X_COM_SET_MIOAR;

/* ================================================================= */
/*                X_COM/CID_SET_RR_NUMBER                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* RRNumber        Relative Record Number                            */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  RRNumber;
} X_COM_SET_RR_NUMBER;

/* ================================================================= */
/*                X_COM/CID_RET_RR_NUMBER                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* RRNumber        Relative Record Number                            */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  RRNumber;
} X_COM_RET_RR_NUMBER;

/* ================================================================= */
/*                X_COM/CID_SET_FUNCTION_NAME                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Process         Process Name                                      */
/* Function        Function Name                                     */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR               fchProcess[10];
   X_FCHAR               fchFunction[7];
} X_COM_SET_FUNCTION_NAME;

/* ================================================================= */
/*                X_COM/CID_SET_OPNQRYF_VALUES                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Qryslt          QRYSLT value                                      */
/* Keyfld          KEYFLD value                                      */
/* Alwcpydta       ALWCPYDTA value                                   */
/* Optimize        OPTIMIZE value                                    */
/* Seqonly1        SEQONLY value 1                                   */
/* Seqonly2        SEQONLY value 2                                   */
/* Commit          COMMIT value                                      */
/* Type            TYPE value                                        */

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_FCHAR               fchQryslt[256];
   X_FCHAR               fchKeyfld[256];
   X_FCHAR               fchAlwcpydta[4];
   X_FCHAR               fchOptimize[8];
   X_FCHAR               fchSeqonly1[4];
   X_COM_INTEGER  Seqonly2;
   X_FCHAR               fchCommit[4];
   X_FCHAR               fchType[8];
} X_COM_SET_OPNQRYF_VALUES;

/* ================================================================= */
/*                X_COM/CID_SET_IO_RETURN_CODE                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ReturnCode      Return Code                                       */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchReturnCode[2];
} X_COM_SET_IO_RETURN_CODE;

/* ================================================================= */
/*                X_COM/CID_PERFORM_IO_OPERATION                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* File            File Name                                         */
/* PhyFile         Physical File Name                                */
/* Operation       Operation Required                                */
/* Lock            Lock Required                                     */
/* CheckOnly       Check Only                                        */
/* ForceClose      Force File to be closed                           */
/* LogicalOper     Logical Operation                                */
/* IssueMsg        Issue Message if nor record found                */
/* MaxSelect       Maximum to select                                */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR               fchFile[10];
   X_FCHAR               fchPhyFile[10];
   X_FCHAR               fchOperation[5];
   X_CHAR                chLock;
   X_CHAR                chCheckOnly;
   X_CHAR                chForceClosed;
   X_CHAR                chLogicalOper;
   X_CHAR                chIssueMsg;
   X_COM_INTEGER  MaxSelect;
} X_COM_PERFORM_IO_OPERATION;

/* ================================================================= */
/*                X_COM/CID_PERFORM_COMMIT                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_PERFORM_COMMIT;

/* ================================================================= */
/*                X_COM/CID_PERFORM_ROLLBACK                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_PERFORM_ROLLBACK;

/* ================================================================= */
/*                X_COM/CID_CLEAR_EXCHANGE_LIST                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_CLEAR_EXCHANGE_LIST;

/* ================================================================= */
/*                X_COM/CID_ADD_TO_EXCHANGE_LIST                     */
/*                X_COM/CID_ADD_TO_EXCHANGE_LIST_DIRECT              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Name            Name of Field                                     */
/* Type            Type of Field                                     */
/* Length          Length of Field                                   */
/* Decimals        Number of Decimals                                */
/* ValueLength     Length of Value                                   */
/* Value           Value of Field                                    */


typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR               fchName[10];
   X_CHAR                chType;
   X_FCHAR               fchLength[3];
   X_CHAR                chDecimals;
   X_COM_INTEGER  ValueLength;
   X_FCHAR               fchValue[X_MAX_ALPHA_FIELD_LEN];
} X_COM_ADD_TO_EXCHANGE_LIST;


typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchName[10];
   X_CHAR      chType;
   X_FCHAR     fchLength[3];
   X_CHAR      chDecimals;
   X_VCHAR     vchValue[X_MAX_ALPHA_FIELD_LEN + 1];
} X_COM_ADD_TO_EXCHANGE_LIST_DIRECT ;

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_INT32     lVersion   ;      /* TN: -1 for 10.7*/
   X_UINT16    usLL1Fields;      /* Count of number of LL1 fields in the exchange list. */
   X_UINT16    usLL2Fields;      /* Count of number of LL2 fields in the exchange list. */
} X_COM_SEND_EXCHANGE_LIST;

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchName[X_OBJECT_NAME_LEN];    /* TN: The field name */
   X_CHAR      chFieldInfo;   /* TN: originally from X_FLD*/
   X_CHAR      chType;        /* chType or chSubType (originally from X_FLD, chSubType used if type was a component) */
   X_INT32     lFieldState;   /* bFieldState (from X_FLD_XXXX). Set to 0 for LL1 fields. */
   X_UINT32    ulCurrLen;     /* The number of bytes of data following. */
                              /* If the field state indicates that the field is SQL NULL then ulCurrLen will be 0.*/
                              /* */
                              /* For fields of type Char & Binary (i.e. stored as X_VAR), */
                              /* this is the result of calling X_VAR_VarChar_GetCurSize() +1 */
                              /* or X_VAR_VarBinary_GetCurSize(). */

                              /* It is assumed this size includes the null terminator for fields of type Char.*/
                              /* For field of type BLOB & CLOB, if chLOBContents is 0x01, */
                              /* this is the length of the data (contents) being saved; */
                              /* otherwise it is the strlen of the filename + 1. */
                              /* For fields of other types, it is the strlen of the data*/
   X_VCHAR     vchValue[1];
} X_COM_ADD_TO_EXCHANGE_LIST_RDMLX;

/* ================================================================= */
/*             X_COM/CID_CLEAR_STORED_WORKING_LISTS                  */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_CLEAR_STORED_WORKING_LISTS;

/* ================================================================= */
/*             X_COM/CID_STORE_WORKING_LIST                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_COM_INTEGER  EntryLength;
   X_COM_INTEGER  TotalEntries;
   X_VCHAR               vchWorkList[X_COM_MAXIMUM_WORKING_LIST];
} X_COM_STORE_WORKING_LIST;

typedef X_PACKED struct
{
   X_FCHAR        fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR         chRecordType;
   X_INT32        lTotalEntries;
} X_COM_STORE_WORKING_LIST_RDMLX;

/* ================================================================= */
/*             X_COM/CID_CALL_FUNCTION                               */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Function        Name of function to be called                     */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchFunction[7];
} X_COM_CALL_FUNCTION;

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchFunction[7];
   X_YES_NO    chRetExch;
   X_YES_NO    chLL2;
   X_CHAR      chType;
} X_COM_CALL_FUNCTION_2;

/* ================================================================= */
/*             X_COM/CID_CALL_IOMODULE                               */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct _X_COM_CALL_IOMODULE
{
   X_FCHAR          fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR           chRecordType;
   X_INT16          sDBMRequest;
   X_INT16          sCursorID;
   X_NET_OBJECT_ID  ulXFUNNetId;
   X_NET_OBJECT_ID  ulXDBMNetId;
   X_INT32          lBlockSize;
   X_INT32          lSelectLimit;
   X_FCHAR          fchDBMRetCode[X_DBM_RETURN_CODE_LEN];

}     X_COM_CALL_IOMODULE,
  *  PX_COM_CALL_IOMODULE,
 ** PPX_COM_CALL_IOMODULE;

/* ================================================================= */
/*             X_COM/CID_SET_SCKEYFLDS                               */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct _X_COM_SET_SCKEYFLDS
{
   X_FCHAR          fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR           chRecordType;
   X_INT16          scKeyFlds;

}     X_COM_SET_SCKEYFLDS,
  *  PX_COM_SET_SCKEYFLDS,
 ** PPX_COM_SET_SCKEYFLDS;


/* ================================================================= */
/*             X_COM/CID_CALL_IOMODULE_RESPONSE                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct _X_COM_CALL_IOMODULE_RESPONSE
{
   X_FCHAR          fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR           chRecordType;
   X_VCHAR          vchReturnCode[X_DBM_RETURN_CODE_LEN+1];
   X_INT16          sCursorID;

}     X_COM_CALL_IOMODULE_RESPONSE,
  *  PX_COM_CALL_IOMODULE_RESPONSE,
 ** PPX_COM_CALL_IOMODULE_RESPONSE;


/* ================================================================= */
/*             X_COM/CID_ACTIVATE_XXXXXXX                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct _X_COM_ACTIVATE_XXXX
{
   X_FCHAR          fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR           chRecordType;
   X_NET_OBJECT_ID  ulNetObjectId;
   X_INT16          sSequence;

}     X_COM_ACTIVATE_XXXX,
  *  PX_COM_ACTIVATE_XXXX,
 ** PPX_COM_ACTIVATE_XXXX;


/* ================================================================= */
/*               X_COM/CID_LOCK_UNLOCK_OBJECT                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Process         Process Name                                      */
/* Function        Function Name                                     */
/* ObjectType      Object Type                                       */
/* ObjectId1       Object Id1                                        */
/* ObjectId2       Object Id2                                        */
/* ObjectId3       Object Id3                                        */
/* ObjectId4       Object Id4                                        */
/* LockLevel       Lock Level                                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchProcess[10];
   X_FCHAR     fchFunction[7];
   X_FCHAR     fchObjectType[20];
   X_FCHAR     fchObjectId1[10];
   X_FCHAR     fchObjectId2[10];
   X_FCHAR     fchObjectId3[10];
   X_FCHAR     fchObjectId4[10];
   X_FCHAR     fchLockLevel[4];
} X_COM_LOCK_UNLOCK_OBJECT;

/* ================================================================= */
/*               X_COM/CID_LOCK_OBJECT_RESULT                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ReturnCode      ReturnCode                                        */
/* LockJob         Locking Job                                       */
/* LockUser        Locking User                                      */
/* LockNumber      Locking Job Number                                */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchReturnCode[2];
   X_FCHAR     fchLockJob[10];
   X_FCHAR     fchLockUser[10];
   X_FCHAR     fchLockNumber[6];
} X_COM_LOCK_OBJECT_RESULT;


/* ================================================================= */
/*               X_COM/CID_UNLOCK_OBJECT_RESULT                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ReturnCode      ReturnCode                                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchReturnCode[2];
} X_COM_UNLOCK_OBJECT_RESULT;

/* ================================================================= */
/*               X_COM/CID_DROP_FUNCTION_LOCKS                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Process         Process Name                                      */
/* Function        Function Name                                     */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchProcess[10];
   X_FCHAR     fchFunction[7];
} X_COM_DROP_FUNCTION_LOCKS;


/* =================================================================== */
/*               X_COM/CID_CHECK_OBJECT_AUTHORITY/RET_OBJECT_AUTHORITY */
/* =================================================================== */
/* Name            Description                                         */
/* ----            -----------                                         */
/* RecordLength    Standard Record Length Field                        */
/* RecordType      Standard Record Type Field                          */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchObjectName[10];
   X_FCHAR     fchObjectExtension[10];
   X_FCHAR     fchObjectType[2];
   X_FCHAR     fchAccessRequired[2];
   X_FCHAR     fchAccessGranted[1];
   X_FCHAR     fchAuthorities[X_OBJECT_AUTH_LIST_LEN+1];
} X_COM_CHECK_RET_OBJECT_AUTHORITY;


/* =================================================================== */
/*               X_COM/CID_SET_SYSTEM_AUTHORITIES                      */
/* =================================================================== */
/* Name            Description                                         */
/* ----            -----------                                         */
/* RecordLength    Standard Record Length Field                        */
/* RecordType      Standard Record Type Field                          */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchFileSecurityDisabled[1];
   X_FCHAR     fchProcessSecurityDisabled[1];
   X_FCHAR     fchFunctionSecurityDisabled[1];
   X_FCHAR     fchFutureExpansion[10];
} X_COM_SET_SYSTEM_AUTHORITIES;


/* ================================================================= */
/*                X_COM/CID_CLEAR_FLD_KEY_COUNTS                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_CLEAR_FLD_KEY_COUNTS;

/* ================================================================= */
/*                X_COM/CID_CLEAR_EXRESSIONS                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
} X_COM_CLEAR_EXPRESSIONS;

/* ================================================================= */
/*             X_COM/CID_ADD_EXPRESSION_COMPONENT                    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ComponentType   Component Type                                    */
/* DataType        Data Type                                         */
/* Length          Length                                            */
/* Decimals        Decimals                                          */
/* ByteLength      Byte Length                                       */
/* Location        Location in File Record                           */
/* Name            Name                                              */
/* Value           Value                                             */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chComponentType;
   X_CHAR      chDataType;
   X_FCHAR     fchLength[4];
   X_FCHAR     chDecimals;
   X_FCHAR     fchByteLength[4];
   X_FCHAR     fchLocation[4];
   X_FCHAR     fchName[10];
   X_FCHAR     fchValue[256];
} X_COM_ADD_EXPRESSION_COMPONENT;

/* ================================================================= */
/*             X_COM/CID_ADD_EXPRESSION_ACTIVITY                     */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Activity        Type of Activity                                  */
/* Component1      Component 1                                       */
/* Component2      Component 2                                       */
/* Result          Resulting Component                               */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chActivity;
   X_FCHAR     fchComponent1[3];
   X_FCHAR     fchComponent2[3];
   X_FCHAR     fchResult[3];
} X_COM_ADD_EXPRESSION_ACTIVITY;


/* ================================================================= */
/*             X_COM/CID_TRANSFER_DIRECTORY                          */
/*             X_COM/CID_CREATE_TRANSFER_DIRECTORY                   */
/*             X_COM/CID_OPEN_TRANSFER_FILE                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* NameLength      Length of the Name                                */
/* Name            Name Value                                        */

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_COM_INTEGER         NameLength;
   X_FCHAR               fchName[256];
} X_COM_TRANSFER_DIRECTORY;

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_COM_INTEGER  NameLength;
   X_FCHAR               fchName[256];
   X_CHAR                chRefresh;
   X_CHAR                fchRefreshFlags[9];
   X_CHAR                fchRefreshSpareFlags[11];
   X_FCHAR               fchPassword[256];
   X_FCHAR               fchComputerName[10];
} X_COM_TRANSFER_DIRECTORY_INBOUND;

/* ================================================================= */
/*             X_COM/CID_OPEN_TRANSFER_FILE_PCX                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* NameLength      Length of the Name                                */
/* Name            Name Value                                        */
/* Date            UTC Date in DosDate format                        */
/* Time            UTC Time in DosDate format                        */
/* Type            Binary/Text_PC/Text_UNIX/Text_AS400/etc           */

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_COM_INTEGER  NameLength;
   X_FCHAR               fchName[256];
   X_INT16               sDate;
   X_INT16               sTime;
   X_CHAR                chType;
} X_COM_OPEN_TRANSFER_FILE_PCX;

/* ================================================================= */
/*             X_COM/CID_WRITE_TRANSFER_FILE                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Length          Length of Data                                    */
/* Data            Data                                              */


typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_COM_INTEGER  Length;
   X_FCHAR               fchData[9000];
} X_COM_WRITE_TRANSFER_FILE;


/* ================================================================= */
/*             X_COM/CID_CLOSE_TRANSFER_FILE                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
} X_COM_CLOSE_TRANSFER_FILE;


/* ================================================================= */
/*             X_COM/CID_TRANSFER_RESULT                             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Result          Result (OK or ER)                                 */

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_FCHAR               fchResult[2];
} X_COM_TRANSFER_RESULT;

/* ================================================================= */
/*             X_COM/CID_REQUEST_AUTO_VALUE                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* AutoValueType   Type of auto value to be evaluated                */
/* AutoValueName   Name of auto value to be evaluated                */

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_CHAR                chAutoValueType;
   X_FCHAR               fchAutoValueName[20];
} X_COM_REQUEST_AUTO_VALUE;

typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_INT16               sVector;
   X_VCHAR               vchEvalPgmName[X_OBJECT_NAME_LEN + 1];
} X_COM_REQUEST_AUTO_VALUE_DIRECT;

/* ================================================================= */
/*             X_COM/CID_RETURN_AUTO_VALUE                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* AutoValueType   Type of auto value that was evaluated             */
/* AutoValueValue  Value of auto value returned                      */


typedef X_PACKED struct
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_CHAR                chAutoValueType;
   X_VCHAR               vchAutoValueValue[256 + 1];
} X_COM_RETURN_AUTO_VALUE;


/* ================================================================= */
/*                  X_COM/CID_NET_OBJECT                             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct _X_COM_NET_OBJECT
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_CHAR                chType;
   X_NET_OBJECT_ID       ulLinkedObjectId;
   X_NET_OBJECT_ID       ulObjectId;
   X_VCHAR               vchObjectName[X_NET_OBJECT_MAXIMUM_NAME_LENGTH];
   X_INT32               lBlockSize;
   X_INT32               lObjectsinBlock;
}     X_COM_NET_OBJECT,
  *  PX_COM_NET_OBJECT,
 ** PPX_COM_NET_OBJECT;


/* ================================================================= */
/*                  X_COM/CID_ACTIVATE_WORKING_LIST                  */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */


typedef X_PACKED struct _X_COM_ACTIVATE_WORKING_LIST
{
   X_FCHAR               fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR                chRecordType;
   X_INT16               sListParmNo;
   X_NET_OBJECT_ID       ulListObjectId;
}     X_COM_ACTIVATE_WORKING_LIST,
  *  PX_COM_ACTIVATE_WORKING_LIST,
 ** PPX_COM_ACTIVATE_WORKING_LIST;

/* ================================================================= */
/*                 X_COM/CID_CHECK_DLL_VERSIONS                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* BuildNumber     Client's Build Number                             */
/* UPGDType        Value of pX_Ids->vchUPGD                          */

typedef X_PACKED struct _X_COM_CHECK_DLL_VERSIONS
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_INT32     lBuildNumber;
   X_CHAR      chUPGDType;
}     X_COM_CHECK_DLL_VERSIONS,
  *  PX_COM_CHECK_DLL_VERSIONS,
 ** PPX_COM_CHECK_DLL_VERSIONS;


/* ================================================================= */
/*                 X_COM/CID_DLL_VERSION                             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Name            DLL Name (8 char form only)                       */
/* DLLDate         DLL Date (in DOSDate format)                      */
/* DLLTime         DLL Time (in DOSTime format)                      */
/* BuildMonth      3 char month description from internal Build info */
/* BuildDayYear    yyyydd from internal Build info                   */
/* BuildTime       hhmmss from internal Build info                   */
/* BuildNumber     Build number under which DLL was generated        */

typedef X_PACKED struct _X_COM_DLL_VERSION
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchName[X_FILE_DLL_NAME_LEN];
   X_INT16     sDLLDate;
   X_INT16     sDLLTime;
   X_FCHAR     fchBuildMonth[3];
   X_INT32     lBuildDayYear;
   X_INT32     lBuildTime;
   X_INT32     lBuildNumber;
}     X_COM_DLL_VERSION,
  *  PX_COM_DLL_VERSION,
 ** PPX_COM_DLL_VERSION;


/* ================================================================= */
/*                 X_COM/CID_CHECK_DLL_VERSIONS_RESPONSE             */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ReturnCode      Result of Check DLL Versions request              */

typedef X_PACKED struct _X_COM_CHECK_DLL_VERSIONS_RESPONSE
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chReturnCode;
}     X_COM_CHECK_DLL_VERSIONS_RESPONSE,
  *  PX_COM_CHECK_DLL_VERSIONS_RESPONSE,
 ** PPX_COM_CHECK_DLL_VERSIONS_RESPONSE;

/* ================================================================= */
/*                 X_COM/CID_DOWNLOAD_DLL                            */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Name            DLL Name (8 char form only)                       */

typedef X_PACKED struct _X_COM_DOWNLOAD_DLL
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchName[X_FILE_DLL_NAME_LEN];
}     X_COM_DOWNLOAD_DLL,
  *  PX_COM_DOWNLOAD_DLL,
 ** PPX_COM_DOWNLOAD_DLL;

/* ================================================================= */
/*                      X_COM_LIST_APPLICATIONS                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef X_PACKED struct _X_COM_LIST_APPLICATIONS
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;

}    X_COM_LIST_APPLICATIONS,
 *  PX_COM_LIST_APPLICATIONS,
 ** PPX_COM_LIST_APPLICATIONS;

/* ================================================================= */
/*                      X_COM_APPLICATION_LIST                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef X_PACKED struct _X_COM_APPLICATION_LIST
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;

}    X_COM_APPLICATION_LIST,
 *  PX_COM_APPLICATION_LIST,
 ** PPX_COM_APPLICATION_LIST;

/* ================================================================= */
/*                      X_COM_CHECK_APP_STATUS                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Name            Application Name                                  */
/* UPGDType        Value of pX_Ids->vchUPGD                          */

typedef X_PACKED struct _X_COM_CHECK_APP_STATUS
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchName[X_APPL_NAME_LEN];
   X_CHAR      chUPGDType;
}    X_COM_CHECK_APP_STATUS,
 *  PX_COM_CHECK_APP_STATUS,
 ** PPX_COM_CHECK_APP_STATUS;

/* ================================================================= */
/*                      X_COM_CHECK_APP_STATUS_RESPONSE              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ReturnCode      Result of Check App Status request                */

typedef X_PACKED struct _X_COM_CHECK_APP_STATUS_RESPONSE
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chReturnCode;

}    X_COM_CHECK_APP_STATUS_RESPONSE,
 *  PX_COM_CHECK_APP_STATUS_RESPONSE,
 ** PPX_COM_CHECK_APP_STATUS_RESPONSE;


/* ================================================================= */
/*                      X_COM_PACKAGE_STATUS_LIST                    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef X_PACKED struct _X_COM_PACKAGE_STATUS_LIST
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;

}    X_COM_PACKAGE_STATUS_LIST,
 *  PX_COM_PACKAGE_STATUS_LIST,
 ** PPX_COM_PACKAGE_STATUS_LIST;

/* ================================================================= */
/*                      X_COM_CHECK_MSI_STATUS                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Name            Application Name                                  */
/* UPGDType        Value of pX_Ids->vchUPGD                          */

typedef X_PACKED struct _X_COM_CHECK_MSI_STATUS
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchName[X_APPL_NAME_LEN];
   X_CHAR      chUPGDType;
}    X_COM_CHECK_MSI_STATUS,
 *  PX_COM_CHECK_MSI_STATUS,
 ** PPX_COM_CHECK_MSI_STATUS;

/* ================================================================= */
/*                      X_COM_CHECK_MSI_STATUS_RESPONSE              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* ReturnCode      Result of Check App Status request                */

typedef X_PACKED struct _X_COM_CHECK_MSI_STATUS_RESPONSE
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chReturnCode;

}    X_COM_CHECK_MSI_STATUS_RESPONSE,
 *  PX_COM_CHECK_MSI_STATUS_RESPONSE,
 ** PPX_COM_CHECK_MSI_STATUS_RESPONSE;

/* ================================================================= */
/*                      X_COM_MSI_STATUS_LIST_VER1                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          See X_PDF_MSIVERSION_DETAIL for more info         */

typedef X_PACKED struct _X_COM_MSI_STATUS_LIST_VER1
{
   X_FCHAR              fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR               chRecordType;
   X_VCHAR              vchUpgradeCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchProductCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchPackageCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchVersion[ X_MSI_VERSION_LEN + 1];
   X_VCHAR              vchLocale[ X_MSI_LOCALE_LEN + 1];
   X_INT32              dwContext;

}    X_COM_MSI_STATUS_LIST_VER1;

/* ================================================================= */
/*                      X_COM_MSI_STATUS_LIST                        */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          See X_PDF_MSIVERSION_DETAIL for more info         */

typedef X_PACKED struct _X_COM_MSI_STATUS_LIST
{
   X_FCHAR              fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR               chRecordType;
   X_VCHAR              vchUpgradeCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchProductCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchPackageCode[ X_MSI_GUID_LEN + 1];
   X_VCHAR              vchVersion[ X_MSI_VERSION_LEN + 1];
   X_VCHAR              vchLocale[ X_MSI_LOCALE_LEN + 1];
   X_INT32              dwContext;
   X_INT32              f64Bit;

}    X_COM_MSI_STATUS_LIST,
 *  PX_COM_MSI_STATUS_LIST,
 **PPX_COM_MSI_STATUS_LIST;

/* ================================================================= */
/*                      X_COM_MSI_FILE_LIST                          */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Version         MSI/MSP Version number                            */
/* FileName        Filename of MSI/MSP                               */
typedef X_PACKED struct _X_COM_MSI_FILE_LIST
{
   X_FCHAR              fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR               chRecordType;
   X_VCHAR              vchAppName[X_APPL_NAME_LEN + 1];
   X_VCHAR              vchVersion[ X_MSI_VERSION_LEN + 1];
   X_VCHAR              vchLocale[ X_MSI_LOCALE_LEN + 1];
   X_VCHAR              vchFileName[ X_NEW_FILE_PATH_LENGTH + 1 ];

}    X_COM_MSI_FILE_LIST,
 *  PX_COM_MSI_FILE_LIST,
 **PPX_COM_MSI_FILE_LIST;

/* ================================================================= */
/*                      X_COM_DOWNLOAD_PACKAGE                       */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* AppName         Application Name                                  */
/* PkgName         Package Name                                      */
/* UPFP            Full Package? -If N, cab1 and cab2 will be skipped*/
/* LastObjLength   Length of last object (or 0)                      */
/* LastObjName     Name of last object                               */

typedef X_PACKED struct _X_COM_DOWNLOAD_PACKAGE
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchAppName[X_APPL_NAME_LEN];
   X_FCHAR     fchPkgName[X_PKG_NAME_LEN];
   X_CHAR      chUPFP;
   X_INT16     sLastObjLength;
   X_FCHAR     fchLastObjName[X_PARTIAL_OBJ_LENGTH];
}    X_COM_DOWNLOAD_PACKAGE,
 *  PX_COM_DOWNLOAD_PACKAGE,
 ** PPX_COM_DOWNLOAD_PACKAGE;

/* ================================================================= */
/*                      X_COM_DOWNLOAD_BUILD                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* GetBuild        What to do in regard to build                     */
/* BuildLocation   Get build from package or x_boot                  */
/* PkgBuildNum     Build number to download                          */
/* CltBuildNum     Installed version on client                       */
/* AppName         Application Name                                  */
/* PkgName         Package Name                                      */
/* UPFP            Full Package?                                     */
/* PrimLangId      Primary Language Identifier (if Windows client)   */
/* SubLangId       Secondary Language Identifier (if Windows client) */

typedef X_PACKED struct _X_COM_DOWNLOAD_BUILD
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chGetBuild;
   X_CHAR      chBuildLocation;
   X_INT32     lPkgBuildNum;
   X_INT32     lCltBuildNum;
   X_FCHAR     fchAppName[X_APPL_NAME_LEN];
   X_FCHAR     fchPkgName[X_PKG_NAME_LEN];
   X_CHAR      chUPFP;
   X_UINT16    usPrimLangId;
   X_UINT16    usSubLangId;
}    X_COM_DOWNLOAD_BUILD,
 *  PX_COM_DOWNLOAD_BUILD,
 ** PPX_COM_DOWNLOAD_BUILD;

/* ================================================================= */
/*                      X_COM_COPY_PACKAGE                           */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* AppName         Application Name                                  */
/* PkgName         Package Name                                      */

typedef X_PACKED struct _X_COM_COPY_PACKAGE
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     fchAppName[X_APPL_NAME_LEN];
   X_FCHAR     fchPkgName[X_PKG_NAME_LEN];
   X_FCHAR     fchTargetPath[ 256 ];
   X_CHAR      chIfPkgExists;
   X_CHAR      chJobType;
}     X_COM_COPY_PACKAGE,
 *   PX_COM_COPY_PACKAGE,
 ** PPX_COM_COPY_PACKAGE;

/* ================================================================= */
/*             X_COM_BLD_COMPONENT_LIST                              */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* Record          Generic Data Record                               */

typedef X_PACKED struct _X_COM_BLD_COMPONENT_LIST
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
}    X_COM_BLD_COMPONENT_LIST,
 *  PX_COM_BLD_COMPONENT_LIST,
 ** PPX_COM_BLD_COMPONENT_LIST;

/* =============================================================== */
/*             X_COM_DOWNLOAD_BUILD_RESPONSE                       */
/* =============================================================== */
/* Name            Description                                     */
/* ----            -----------                                     */
/* RecordLength    Standard Record Length Field                    */
/* RecordType      Standard Record Type Field                      */
/* ReturnCode      What to do with build                           */

typedef X_PACKED struct _X_COM_DOWNLOAD_BUILD_RESPONSE
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_CHAR      chReturnCode;
}    X_COM_DOWNLOAD_BUILD_RESPONSE,
 *  PX_COM_DOWNLOAD_BUILD_RESPONSE,
 ** PPX_COM_DOWNLOAD_BUILD_RESPONSE;

/* =============================================================== */
/*             X_COM_SET_MAPPING_FLAGS                             */
/* =============================================================== */
/* Name            Description                                     */
/* ----            -----------                                     */
/* RecordLength    Standard Record Length Field                    */
/* RecordType      Standard Record Type Field                      */
/* MappingFlags    On if field data should be mapped back from svr */

typedef X_PACKED struct _X_COM_SET_MAPPING_FLAGS
{
   X_FCHAR     fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR      chRecordType;
   X_FCHAR     abfMappingFlags[ (X_MIOAR_MAX_KEYS +
                                 X_MIOAR_MAX_FIELDS) / 8 ];
}    X_COM_SET_MAPPING_FLAGS,
 *  PX_COM_SET_MAPPING_FLAGS,
 ** PPX_COM_SET_MAPPING_FLAGS;

/* ================================================================= */
/*                X_COM/CID_REQUEST_TRANS_TABLE                      */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* WindowsCCSID    Windows CCSID                                     */
/* ISeriesCCSID    ISeries CCSID                                     */

typedef X_PACKED struct
{
   X_FCHAR     fchRecordLength[ X_COM_RECORD_LENGTH_LENGTH ];
   X_CHAR      chRecordType;
   X_FCHAR     fchWindowsCCSID[ 5 ];
   X_FCHAR     fchISeriesCCSID[ 5 ];
}   X_COM_REQUEST_TRANS_TABLE,
 *  PX_COM_REQUEST_TRANS_TABLE,
 ** PPX_COM_REQUEST_TRANS_TABLE;

/* ================================================================= */
/*             X_COM/CID_SET_LAST_DBMS_ERROR                         */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* lLastError      pX_Ids->lLastError value, non-zero                */
/* vchDBMSType     Allows us to use correct db type on client        */

typedef X_PACKED struct _X_COM_SET_LAST_DBMS_ERROR
{
   X_FCHAR          fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR           chRecordType;
   X_INT32          lLastError;
   X_VCHAR          vchDBMSType[X_CTD_VALUE_LENGTH + 1];

}     X_COM_SET_LAST_DBMS_ERROR,
*  PX_COM_SET_LAST_DBMS_ERROR,
** PPX_COM_SET_LAST_DBMS_ERROR;

/* ================================================================= */
/*             X_COM_BOM_ENVELOPE                                    */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* RecordLength    Standard Record Length Field                      */
/* RecordType      Standard Record Type Field                        */
/* lLastError      pX_Ids->lLastError value, non-zero                */
/* vchDBMSType     Allows us to use correct db type on client        */

typedef X_PACKED struct _X_COM_BOM_ENVELOPE
{
   X_FCHAR           fchRecordLength[X_COM_RECORD_LENGTH_LENGTH];
   X_CHAR            chRecordType;
   X_INT32           lTotalLength;
}
   X_COM_BOM_ENVELOPE,
   *PX_COM_BOM_ENVELOPE,
   **PPX_COM_BOM_ENVELOPE;

/* ================================================================= */
/*             SPECIAL HANDLING FOR EPC CHECKING                     */
/* ================================================================= */
#define EPCCHECK_FUNCTION_TOTAL_LISTS        1
#define EPCCHECK_FUNCTION_TOTAL_LL1_LISTS    1
#define EPCCHECK_FUNCTION_TOTAL_LL2_LISTS    0

/* Also defined in utility.h. Change in both places */
#define EPCCHECK_EPCNO_LEN 6

typedef struct LIST_EPCCHECK
{
   X_DICTIONARY_SIGNED fEPCNO[ EPCCHECK_EPCNO_LEN ];
} LIST_EPCCHECK;

#define X_DEFINITIONS_FOR_EPCCHECK \
\
   /* ---------------------------- */ \
   /*  List EPCCHECK  Definitions */ \
   /* ---------------------------- */ \
   static struct LIST_EPCCHECK X_List_EPCCHECK; \
\
   /* ------------------------------------------- */ \
   /* Field Vector Definitions for list EPCCHECK */ \
   /* ------------------------------------------- */ \
   static struct X_FLD X_Fld_EPCCHECK[] = { \
      {  "EPC",0,X_TYPE_SIGNED,X_SUBTYPE_SIMPLE_FIELD,'N', \
         EPCCHECK_EPCNO_LEN,EPCCHECK_EPCNO_LEN,0, \
         &(X_List_EPCCHECK.fEPCNO[0]),0,NO \
      } \
   }; \
\
   /* -------------------------------------- */ \
   /* Browse and Working List Vector Mapping */ \
   /* -------------------------------------- */ \
   static struct X_LMAP X_LMap_EPCCHECK[] = { \
      { 0, -1 } \
   }; \
\
   /* ------------------------------------------ */ \
   /* Browse and Working Full X_LIST definitions */ \
   /* ------------------------------------------ */ \
   static X_LIST_1 FUNCTION_LIST_DEF [] = { \
      {  X_SSV_EPC_LIST,'W',sizeof(struct LIST_EPCCHECK),50,0,0, \
         1,&(X_Fld_EPCCHECK[0]),2,pX_NULL, \
         &(X_LMap_EPCCHECK[0]),50,'N','N', \
         V_NOT_AVAILABLE,V_NOT_AVAILABLE,V_NOT_AVAILABLE, \
         V_NOT_AVAILABLE,V_NOT_AVAILABLE,V_NOT_AVAILABLE,&(X_List_EPCCHECK),pX_NULL, \
         { pX_NULL }, \
         NO,NO,NO,NO,NO,NO,NO,NO \
      } \
   };


/* ================================================================= */
/*             SPECIAL HANDLING FOR LANGUAGE MAPPING                 */
/* ================================================================= */
#define LANGMAP_FUNCTION_TOTAL_LISTS        1
#define LANGMAP_FUNCTION_TOTAL_LL1_LISTS    1
#define LANGMAP_FUNCTION_TOTAL_LL2_LISTS    0

typedef struct LIST_LANGMAP
{
   X_DICTIONARY_ALPHA   fLANG[ 4 ];
   X_DICTIONARY_ALPHA   fCCSID[ 30 ];
   X_DICTIONARY_SIGNED  fSOURCE[ 2 ];
} LIST_LANGMAP;

#define X_DEFINITIONS_FOR_LANGMAP \
\
   /* ---------------------------- */ \
   /*  List LANGMAP  Definitions */ \
   /* ---------------------------- */ \
   static struct LIST_LANGMAP X_List_LANGMAP; \
\
   /* ------------------------------------------- */ \
   /* Field Vector Definitions for list LANGMAP */ \
   /* ------------------------------------------- */ \
   static struct X_FLD X_Fld_LANGMAP[] = { \
      { "LANG",0,X_TYPE_ALPHA,X_SUBTYPE_SIMPLE_FIELD,'N', \
         4,4,0, \
         &(X_List_LANGMAP.fLANG[0]),0,NO }, \
      { "CCSID",0,X_TYPE_ALPHA,X_SUBTYPE_SIMPLE_FIELD,'N', \
         30,30,0, \
         &(X_List_LANGMAP.fCCSID[0]),0,NO }, \
      { "SOURCE",0,X_TYPE_SIGNED,X_SUBTYPE_SIMPLE_FIELD,'N', \
         2,2,0, \
         &(X_List_LANGMAP.fSOURCE[0]),0,NO } \
   }; \
\
   /* -------------------------------------- */ \
   /* Browse and Working List Vector Mapping */ \
   /* -------------------------------------- */ \
   static struct X_LMAP X_LMap_LANGMAP[] = { \
      { 0, -1 }, \
      { 1, -1 }, \
      { 2, -1 } \
   }; \
\
   /* ------------------------------------------ */ \
   /* Browse and Working Full X_LIST definitions */ \
   /* ------------------------------------------ */ \
   static X_LIST_1 FUNCTION_LIST_DEF [] = { \
      {  X_SSV_LANGMAP_LIST,'W',sizeof(struct LIST_LANGMAP),100,0,0, \
         3,&(X_Fld_LANGMAP[0]),2,pX_NULL, \
         &(X_LMap_LANGMAP[0]),100,'N','N', \
         V_NOT_AVAILABLE,V_NOT_AVAILABLE,V_NOT_AVAILABLE, \
         V_NOT_AVAILABLE,V_NOT_AVAILABLE,V_NOT_AVAILABLE,&(X_List_LANGMAP),pX_NULL, \
         { pX_NULL }, \
         NO,NO,NO,NO,NO,NO,NO,NO \
      } \
   };

/* ================================================================= */
/*             SPECIAL HANDLING FOR OBJECT NAME MAPPING              */
/* ================================================================= */
#define OBJECTNAMEMAP_FUNCTION_TOTAL_LISTS        1
#define OBJECTNAMEMAP_FUNCTION_TOTAL_LL1_LISTS    1
#define OBJECTNAMEMAP_FUNCTION_TOTAL_LL2_LISTS    0

typedef struct _OBJECTNAMEMAP_FIELDS
{
   X_FCHAR                                      fchName[ 256 + 1 ];
   X_FCHAR                                      fchIdentifier[ 10 + 1 ];
} OBJECTNAMEMAP_FIELDS;

typedef struct LIST_OBJECTNAMEMAP
{
   X_DICTIONARY_ALPHA   fName[ 256 ];
   X_DICTIONARY_ALPHA   fType[ 2 ];
   X_DICTIONARY_ALPHA   fExtendedInfo[ 10 ];
   X_DICTIONARY_ALPHA   fIdentifier[ 10 ];
} LIST_OBJECTNAMEMAP;

#define X_DEFINITIONS_FOR_OBJECTNAMEMAP \
\
   /* -------------------------------- */ \
   /*  List OBJECTNAMEMAP  Definitions */ \
   /* -------------------------------- */ \
   static struct LIST_OBJECTNAMEMAP X_List_OBJECTNAMEMAP; \
\
   /* ----------------------------------------------- */ \
   /* Field Vector Definitions for list OBJECTNAMEMAP */ \
   /* ----------------------------------------------- */ \
   static struct X_FLD X_Fld_OBJECTNAMEMAP[] = { \
      { "NAME",0,X_TYPE_ALPHA,X_SUBTYPE_SIMPLE_FIELD,'N', \
         256,256,0, \
         (X_PDICTIONARY_FIELD)(&(X_List_OBJECTNAMEMAP.fName)),0,NO }, \
      { "TYPE",0,X_TYPE_ALPHA,X_SUBTYPE_SIMPLE_FIELD,'N', \
         2,2,0, \
         &(X_List_OBJECTNAMEMAP.fType[0]),0,NO }, \
      { "EXTENDEDINFO",0,X_TYPE_ALPHA,X_SUBTYPE_SIMPLE_FIELD,'N', \
         10,10,0, \
         &(X_List_OBJECTNAMEMAP.fExtendedInfo[0]),0,NO }, \
      { "IDENTIFIER",0,X_TYPE_ALPHA,X_SUBTYPE_SIMPLE_FIELD,'N', \
         10,10,0, \
         &(X_List_OBJECTNAMEMAP.fIdentifier[0]),0,NO } \
   }; \
\
   /* -------------------------------------- */ \
   /* Browse and Working List Vector Mapping */ \
   /* -------------------------------------- */ \
   static struct X_LMAP X_LMap_OBJECTNAMEMAP[] = { \
      { 0, -1 }, \
      { 1, -1 }, \
      { 2, -1 }, \
      { 3, -1 } \
   }; \
\
   /* ------------------------------------------ */ \
   /* Browse and Working Full X_LIST definitions */ \
   /* ------------------------------------------ */ \
   static X_LIST_1 FUNCTION_LIST_DEF [] = { \
      {  X_SSV_OBJECTNAMEMAP_LIST,'W',sizeof(struct LIST_OBJECTNAMEMAP),9999,0,0, \
         4,&(X_Fld_OBJECTNAMEMAP[0]),0,pX_NULL, \
         &(X_LMap_OBJECTNAMEMAP[0]),500,'N','N', \
         V_NOT_AVAILABLE,V_NOT_AVAILABLE,V_NOT_AVAILABLE, \
         V_NOT_AVAILABLE,V_NOT_AVAILABLE,V_NOT_AVAILABLE,&(X_List_OBJECTNAMEMAP),pX_NULL, \
         { pX_NULL }, \
         NO,NO,NO,NO,NO,NO,NO,NO \
      } \
   };

/* ================================================================= */
/*                        COM SUPPORT SERVICES                       */
/* ================================================================= */

///////////////////////////////////////////////////////////////////////
// Service request codes
//
#define X_COM_SERVICES_ENCODE_XRUN_PARAMETERS 1
#define X_COM_SERVICES_DECODE_XRUN_PARAMETERS 2

///////////////////////////////////////////////////////////////////////
// STRUCT: X_COM_SERVICES_POINT_REQUEST
//
typedef struct _X_COM_SERVICES_POINT_REQUEST
{
   int                                                lRequest;
   void                                            *  pX_Ids;
}
   X_COM_SERVICES_POINT_REQUEST,
   *PX_COM_SERVICES_POINT_REQUEST,
   **PPX_COM_SERVICES_POINT_REQUEST;

/* =============================== */
/* Put packing back to the default */
/* =============================== */

#include "x_endpck.h"

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* #ifndef X_COM_STR_INCLUDED */
