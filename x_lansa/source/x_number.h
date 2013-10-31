/* ================================================================= */
/* ====== LANSA FOR WINDOWS PLATFORM INDEPENDENT FUNCTIONS ========= */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_FUNINT.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/*                                                                   */
/* Description         : This .H file is used for the definition     */
/*                       of macros required in OAMs for Native I/O   */
/*                                                                   */
/*                       It should only be included into generated   */
/*                       code as these macros are also in x_funint.h */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*                                                                   */
/* ================================================================= */


/* ================================================================= */
/*  X_NUMBER : Standard numeric interchange format                   */
/* ================================================================= */
/* Name            Description                                       */
/* ----            -----------                                       */
/* Sign            Sign of number                                    */
/* Number          Number in fixed form with implied decimals        */

#define X_NUMBER_DECIMAL_POINT         '.'
#define X_NUMBER_POSITIVE_SIGN         '+'
#define X_NUMBER_NEGATIVE_SIGN         '-'
#define X_NUMBER_LONG_MAX_DIGITS       9
#define X_NUMBER_LONGLONG_MAX_DIGITS   19
#define X_NUMBER_DOUBLE_MAX_DIGITS     X_MAXIMUM_DIGITS
#define X_NUMBER_START_DEC_DIGITS(_N)  _N->uchNumber[X_MAX_NUMERIC_DIGITS]
#define X_NUMBER_END_SIG_DIGITS(_N)    _N->uchNumber[X_MAX_NUMERIC_DIGITS - 1]

#if defined(X_OPERATING_SYSTEM_ISERIES)
#define X_SIGNED_POSITIVE  '\xF0'
#define X_SIGNED_NEGATIVE  '\xD0'
#else
#define X_SIGNED_POSITIVE  '\x30'
#define X_SIGNED_NEGATIVE  '\x40'
#endif

#define X_PACKED_POSITIVE  '\x0F'
#define X_PACKED_NEGATIVE  '\x0D'

typedef struct X_NUMBER
{
   X_CHAR   chSign;
   X_UCHAR  uchNumber[X_MAX_NUMERIC_DIGITS + X_MAX_NUMERIC_DECIMALS];
} X_NUMBER;

/* ================================================================ */
/* Macro       : X_SET_NUMBER_TO_ZERO                               */
/* Description : Set an X_NUMBER structure to zero                  */
/* Arguments   : _N = The X_NUMBER structure                        */
/* ================================================================ */

#define X_SET_NUMBER_TO_ZERO(_N) \
{ \
   (_N)->chSign = X_NUMBER_POSITIVE_SIGN; \
   memset((_N)->uchNumber,'0',sizeof((_N)->uchNumber)); \
}

/* ================================================================ */
/* Macro       : X_UNPACK_ZONE                                      */
/* Description : Unpack the zone (leftmost 4 bits) of a byte to     */
/*               produce a character representation of the number.  */
/* Arguments   : _PTGT = Pointer to target byte                     */
/*               _PSRC = Pointer to source byte                     */
/* ================================================================ */

#define X_UNPACK_ZONE(_PTGT,_PSRC) \
  *(_PTGT) = (((*(_PSRC) >> 4) & '\x0F') | X_SIGNED_POSITIVE);

/* ================================================================ */
/* Macro       : X_PACK_ZONE                                        */
/* Description : Pack the zone (leftmost 4 bits) of a byte          */
/* Arguments   : _PTGT = Pointer to target byte                     */
/*               _PSRC = Pointer to source byte                     */
/* ================================================================ */

#define X_PACK_ZONE(_PTGT,_PSRC) \
   *(_PTGT) = ((*(_PTGT) & '\x0F') | (*(_PSRC) << 4));


/* ================================================================ */
/* Macro       : X_UNPACK_DIGIT                                     */
/* Description : Unpack the digit (rightmost 4 bits) of a byte      */
/* Arguments   : _PTGT = Pointer to target byte                     */
/*               _PSRC = Pointer to source byte                     */
/* ================================================================ */

#define X_UNPACK_DIGIT(_PTGT,_PSRC) \
   *(_PTGT) = ((*(_PSRC) & '\x0F') | X_SIGNED_POSITIVE);

/* ================================================================ */
/* Macro       : X_PACK_DIGIT                                       */
/* Description : Pack the digit (rightmost 4 bits) of a byte        */
/* Arguments   : _PTGT = Pointer to target byte                     */
/*               _PSRC = Pointer to source byte                     */
/* ================================================================ */

#define X_PACK_DIGIT(_PTGT,_PSRC) \
   *(_PTGT) = ((*(_PTGT) & '\xF0') | (*(_PSRC) & '\x0F'));

/* ================================================================ */
/* Macro       : X_GET_PACKED_SIGN                                  */
/* Description : Get sign of a packed decimal variable              */
/* Arguments   : _TGT   = Char target to contain resulting sign     */
/*               _PBYTE = Pointer to byte containing the sign       */
/* ================================================================ */

#define X_GET_PACKED_SIGN(_TGT,_PBYTE) \
   (_TGT) = ((*(_PBYTE) & '\x0F') == X_PACKED_NEGATIVE) \
          ? X_NUMBER_NEGATIVE_SIGN  \
          : X_NUMBER_POSITIVE_SIGN;

/* ================================================================ */
/* Macro       : X_SET_PACKED_SIGN                                  */
/* Description : Set the sign of a packed decimal field             */
/* Arguments   : _SIGN  = Char source containing the sign           */
/*               _PBYTE = Pointer to byte containing the sign       */
/* ================================================================ */

#define X_SET_PACKED_SIGN(_SIGN,_PBYTE) \
{ \
   X_CHAR  chWork  = ((_SIGN) == X_NUMBER_NEGATIVE_SIGN) ? X_PACKED_NEGATIVE : X_PACKED_POSITIVE; \
   X_PUCHAR puchSign = (_PBYTE); \
   *puchSign = (*puchSign & '\xF0'); \
   *puchSign = (*puchSign | chWork); \
}

/* ================================================================ */
/* Macro       : X_GET_SIGNED_SIGN                                  */
/* Description : Get the sign of a signed decimal variable          */
/* Arguments   : _TGT   = Char target to contain resulting sign     */
/*               _PBYTE = Pointer to byte containing the sign       */
/* ================================================================ */

#define X_GET_SIGNED_SIGN(_TGT,_PBYTE) \
   (_TGT) = ((*(_PBYTE) & '\xF0') == X_SIGNED_POSITIVE) \
          ? X_NUMBER_POSITIVE_SIGN  \
          : X_NUMBER_NEGATIVE_SIGN;

/* ================================================================ */
/* Macro       : X_SET_SIGNED_SIGN                                  */
/* Description : Set the sign of a signed decimal field             */
/* Arguments   : _SIGN  = Char source containing the sign           */
/*               _PBYTE = Pointer to byte containing the sign       */
/* ================================================================ */

#define X_SET_SIGNED_SIGN(_SIGN,_PBYTE) \
{ \
   X_CHAR  chWork  = ((_SIGN) == X_NUMBER_NEGATIVE_SIGN) ? X_SIGNED_NEGATIVE : X_SIGNED_POSITIVE; \
   X_PUCHAR puchSign = (X_PUCHAR)(_PBYTE); \
   *puchSign = (*puchSign & '\x0F'); \
   *puchSign = (*puchSign | chWork); \
}

/* ================================================================ */
/* Macro       : X_SET_NUMBER_FROM_PACKED                           */
/* Description : Set an X_NUMBER from a packed vector               */
/* Arguments   : _N = The X_NUMBER structure                        */
/*               _P = Pointer to the packed data                    */
/*               _B = Byte length of the packed data                */
/*               _L = Total number of digits in packed data         */
/*               _D = Number of decimal positions in packed data    */
/* ================================================================ */


#define X_SET_NUMBER_FROM_PACKED(_N, _P, _B, _L, _D) \
{ \
   X_PUCHAR  puchSource      = (X_PUCHAR)(_P); /* Defaults for odd length packed */ \
   X_PUCHAR  puchSourceEnd   = puchSource + ((_B) - 1); \
   X_PUCHAR  puchTargetZone  = (&(X_NUMBER_START_DEC_DIGITS((_N))) - ((_L) - (_D))); \
   X_PUCHAR  puchTargetDigit = puchTargetZone + 1; \
   X_SET_NUMBER_TO_ZERO((_N)) ;\
   if ((((_L) + 1) / 2) != (_B)) /* Even length packed  */ \
   { \
      puchTargetZone++; \
      puchTargetDigit--; \
      puchSource++; \
   } \
   /* ----------------- */ \
   /* Do the zones      */ \
   /* ----------------- */ \
   for (               ; puchSource <= puchSourceEnd; puchSource++, puchTargetZone += 2) \
   { \
      X_UNPACK_ZONE(puchTargetZone,puchSource) ;\
   } \
   /* ----------------- */ \
   /* Do the digits     */ \
   /* ----------------- */ \
   for (puchSource = (X_PUCHAR)(_P) ; puchSource < puchSourceEnd; puchSource++, puchTargetDigit += 2) \
   { \
      X_UNPACK_DIGIT(puchTargetDigit,puchSource) ;\
   } \
   X_GET_PACKED_SIGN((_N)->chSign, puchSourceEnd) ;\
}

/* ================================================================ */
/* Macro       : X_GET_NUMBER_AS_PACKED                             */
/* Description : Set a packed vector from an X_NUMBER structure     */
/* Arguments   : _N = The X_NUMBER structure                        */
/*               _P = Pointer to the packed data                    */
/*               _B = Byte length of the packed data                */
/*                Only for backward compatible not used any more    */
/*               _L = Total number of digits in packed data         */
/*               _D = Number of decimal positions in packed data    */
/* ================================================================ */

#define X_GET_NUMBER_AS_PACKED(_N, _P, _B, _L, _D) \
{ \
   X_PUCHAR  puchTarget      = (X_PUCHAR)(_P); /* Defaults for odd length packed */ \
   X_PUCHAR  puchTargetEnd; \
   X_PUCHAR  puchSourceZone  = (&(X_NUMBER_START_DEC_DIGITS((_N))) - ((_L) - (_D))); \
   X_PUCHAR  puchSourceDigit = puchSourceZone + 1; \
   X_SHORT   sByteLen; \
   X_GET_USED_BYTE_LEN_IN_PACKED(sByteLen , (_L)); \
   puchTargetEnd = puchTarget + (sByteLen - 1); \
   if ((((_L) + 1) / 2) != sByteLen) \
   { \
      puchSourceZone++; \
      puchSourceDigit--; \
      *puchTarget = LOVAL; /* Set unused first leading zone */ \
      puchTarget++; \
   } \
   /* ----------------- */ \
   /* Do the zones      */ \
   /* ----------------- */ \
   for (               ; puchTarget <= puchTargetEnd; puchTarget++, puchSourceZone += 2) \
   { \
      X_PACK_ZONE(puchTarget,puchSourceZone) \
   } \
   /* ----------------- */ \
   /* Do the digits     */ \
   /* ----------------- */ \
   for (puchTarget = (X_PUCHAR)(_P) ; puchTarget < puchTargetEnd; puchTarget++, puchSourceDigit += 2) \
   { \
      X_PACK_DIGIT(puchTarget,puchSourceDigit) \
   } \
   X_SET_PACKED_SIGN(_N->chSign, puchTargetEnd) \
}


/* ================================================================ */
/* Macro       : X_SET_NUMBER_FROM_SIGNED                           */
/* Description : Set an X_NUMBER from a signed vector               */
/* Arguments   : _N = The X_NUMBER structure                        */
/*               _P = Pointer to the signed data                    */
/*               _B = Byte length of the signed data                */
/*               _L = Total number of digits in signed data         */
/*               _D = Number of decimal positions in signed data    */
/* ================================================================ */

#define X_SET_NUMBER_FROM_SIGNED(_N, _P, _B, _L, _D) \
{ \
   X_PUCHAR  puchTarget = (&(X_NUMBER_START_DEC_DIGITS(_N)) - ((_L) - (_D))); \
   X_ULONG  ulUnsignedDigits = ((_L) - 1); \
   X_SET_NUMBER_TO_ZERO(_N) ;\
   memcpy(puchTarget, (_P), ulUnsignedDigits); \
   X_UNPACK_DIGIT((puchTarget + ulUnsignedDigits),((_P) + ulUnsignedDigits)) ;\
   X_GET_SIGNED_SIGN((_N)->chSign,((_P) + ulUnsignedDigits)) ;\
}

/* ================================================================ */
/* Macro       : X_GET_NUMBER_AS_SIGNED                             */
/* Description : Set a signed vector from an X_NUMBER structure     */
/* Arguments   : _N = The X_NUMBER structure                        */
/*               _P = Pointer to the signed data                    */
/*               _B = Byte length of the signed data                */
/*               _L = Total number of digits in signed data         */
/*               _D = Number of decimal positions in signed data    */
/* ================================================================ */


#define X_GET_NUMBER_AS_SIGNED(_N, _P, _B, _L, _D) \
   memcpy( _P, (&(X_NUMBER_START_DEC_DIGITS((_N))) - ((_L) - (_D))) ,(_L) ); \
   X_SET_SIGNED_SIGN( (_N)->chSign,  ((_P) + ((_L) - 1)) );


/* ================================================================ */
/* Macro       : X_SET_NUMBER_FROM_STRING                           */
/* Description : Set an X_NUMBER structure from a string            */
/* Arguments   : _N  = The X_NUMBER structure                       */
/*               _S  = Pointer to the string                        */
/*               _DP = Decimal point to be used                     */
/* ================================================================ */

#ifdef X_NUMBER_AS_ROUTINES
X_VOID_FUNCTION X_SET_NUMBER_FROM_STRING(struct X_NUMBER * _N, X_PVCHAR _S, X_CHAR _DP )
{
    X_PUCHAR puchDecimalPoint;
    X_PUCHAR puchSource;
    X_PUCHAR puchTarget;
    X_ULONG  ulCount;
    X_SET_NUMBER_TO_ZERO((_N));
    for (puchDecimalPoint = (X_PUCHAR)(_S);
         ( (*puchDecimalPoint != LOVAL) && (*puchDecimalPoint != (_DP)) );
         puchDecimalPoint++);
    if (*puchDecimalPoint == (_DP))
    {
       puchTarget     = &(X_NUMBER_START_DEC_DIGITS((_N)));
       puchSource     = puchDecimalPoint + 1;
       for (ulCount = 0;
            (*puchSource != LOVAL) && (ulCount <= X_MAX_NUMERIC_DECIMALS);
            puchSource++)
       {
          switch (*puchSource)
          {
             case X_NUMBER_POSITIVE_SIGN:
             case X_NUMBER_NEGATIVE_SIGN:
                  (_N)->chSign = *puchSource;
                  break;
             case '0' :
             case '1' :
             case '2' :
             case '3' :
             case '4' :
             case '5' :
             case '6' :
             case '7' :
             case '8' :
             case '9' :
                  *puchTarget = *puchSource;
                  puchTarget++;
                  ulCount++;
                  break;
             default  :
                  break;
          }
       }
    }
    puchTarget = &(X_NUMBER_END_SIG_DIGITS((_N)));
    puchSource = puchDecimalPoint - 1;
    for (ulCount = 0;
        ((X_PUCHAR)puchSource >= (X_PUCHAR)_S) && (ulCount <= X_MAX_NUMERIC_DIGITS);
         puchSource--)
    {
       switch (*puchSource)
       {
          case X_NUMBER_POSITIVE_SIGN:
          case X_NUMBER_NEGATIVE_SIGN:
               (_N)->chSign = *puchSource;
               break;
          case '0' :
          case '1' :
          case '2' :
          case '3' :
          case '4' :
          case '5' :
          case '6' :
          case '7' :
          case '8' :
          case '9' :
               if ( ulCount >= X_MAX_NUMERIC_DIGITS )
               {
                  /* Allow the sign in a Number(X_MAX_NUMERIC_DIGITS,0) that  */
                  /* has a value that is X_MAX_NUMERIC_DIGITS long to be      */
                  /* extracted and this code ensures that if its a digit      */
                  /* instead its ignored.                                     */
                  break;
               }
               *puchTarget = *puchSource;
               puchTarget--;
               ulCount++;
               break;
          default  :
               break;
       }
    }
}
#else
#define X_SET_NUMBER_FROM_STRING(_N, _S, _DP) \
{ \
    X_PUCHAR puchDecimalPoint; \
    X_PUCHAR puchSource; \
    X_PUCHAR puchTarget; \
    X_ULONG  ulCount; \
    X_SET_NUMBER_TO_ZERO((_N)); \
    for (puchDecimalPoint = (X_PUCHAR)(_S); \
         ( (*puchDecimalPoint != LOVAL) && (*puchDecimalPoint != (_DP)) ); \
         puchDecimalPoint++); \
    if (*puchDecimalPoint == (_DP)) \
    { \
       puchTarget     = &(X_NUMBER_START_DEC_DIGITS((_N))); \
       puchSource     = puchDecimalPoint + 1; \
       for (ulCount = 0; \
            (*puchSource != LOVAL) && (ulCount <= X_MAX_NUMERIC_DECIMALS); \
            puchSource++) \
       { \
          switch (*puchSource) \
          { \
             case X_NUMBER_POSITIVE_SIGN: \
             case X_NUMBER_NEGATIVE_SIGN: \
                  (_N)->chSign = *puchSource; \
                  break; \
             case '0' : \
             case '1' : \
             case '2' : \
             case '3' : \
             case '4' : \
             case '5' : \
             case '6' : \
             case '7' : \
             case '8' : \
             case '9' : \
                  *puchTarget = *puchSource; \
                  puchTarget++; \
                  ulCount++; \
                  break; \
             default  : \
                  break; \
          } \
       } \
    } \
    puchTarget = &(X_NUMBER_END_SIG_DIGITS((_N))); \
    puchSource = puchDecimalPoint - 1; \
    for (ulCount = 0; \
        ((X_PUCHAR)puchSource >= (X_PUCHAR)(_S)) && (ulCount <= X_MAX_NUMERIC_DIGITS); \
         puchSource--) \
    { \
       switch (*puchSource) \
       { \
          case X_NUMBER_POSITIVE_SIGN: \
          case X_NUMBER_NEGATIVE_SIGN: \
               (_N)->chSign = *puchSource; \
               break; \
          case '0' : \
          case '1' : \
          case '2' : \
          case '3' : \
          case '4' : \
          case '5' : \
          case '6' : \
          case '7' : \
          case '8' : \
          case '9' : \
               if ( ulCount >= X_MAX_NUMERIC_DIGITS ) \
               { \
                  /* Allow the sign in a Number(X_MAX_NUMERIC_DIGITS,0) that  */ \
                  /* has a value that is X_MAX_NUMERIC_DIGITS long to be      */ \
                  /* extracted and this code ensures that if its a digit      */ \
                  /* instead its ignored.                                     */ \
                  break; \
               } \
               *puchTarget = *puchSource; \
               puchTarget--; \
               ulCount++; \
               break; \
          default  : \
               break; \
       } \
    } \
}
#endif /* X_NUMBER_AS_ROUTINES */


/* ================================================================== */
/* Macro       : X_GET_NUMBER_AS_STRING                               */
/* Description : Get the content of an X_NUMBER structure as a double */
/* Arguments   : _N  = The X_NUMBER structure                         */
/*               _R  = The string value to be returned                */
/*               _L  = Total number of digits to be returned          */
/*               _D  = Number of decimal positions to be returned     */
/*               _DP = Decimal point to be returned                   */
/* ================================================================== */

#define X_GET_NUMBER_AS_STRING(_N, _R, _L, _D, _DP) \
{ \
   X_ULONG  ulSigDig = ((_L) - (_D)); \
   X_ULONG  ulDec = (_D); \
   X_ULONG  ulPos = 0; \
   (_R)[ulPos++] = (_N)->chSign; \
   memcpy(&(_R)[ulPos],(&(X_NUMBER_START_DEC_DIGITS((_N))) - ulSigDig),ulSigDig); \
   ulPos += ulSigDig; \
   if (ulDec > 0) \
   { \
      (_R)[ulPos++] = (_DP); \
      memcpy(&(_R)[ulPos],&(X_NUMBER_START_DEC_DIGITS((_N))),ulDec); \
      ulPos += ulDec; \
   } \
   (_R)[ulPos] = LOVAL; \
}

