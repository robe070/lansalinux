/* ================================================================= */
/* ========== LANSA FOR WINDOWS GLOBAL DEFINITIONS ================= */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_CTYPES.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Not Recommended                             */
/* Description         : LANSA Global Defintions                     */
/*                                                                   */
/* ================================================================= */

#ifndef __INCL_X_CTYPES_H__
#define __INCL_X_CTYPES_H__

#ifndef __cplusplus
#include <wchar.h>
#endif

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif
#include <stdint.h>

#include "x_platform.h"
#include "x_cutil.h"

#include <float.h>

#if defined(X_OPERATING_SYSTEM_WIN)
#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
// Macros min() and max() should be from x_cutil.h
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif
#endif

#ifdef X_OPERATING_SYSTEM_UNIX
#include <sys/types.h>
#include <limits.h>
#endif

#ifndef FALSE
#define FALSE (0)
#endif
#ifndef TRUE
#define TRUE  (!FALSE)
#endif

/* ================================================================= */
/*  Operating system dependent defines and redefines                 */
/* ================================================================= */

/* Windows generically */

#if defined(X_OPERATING_SYSTEM_WIN)

#if defined(X_WATCOM)
   #ifdef X_OPERATING_SYSTEM_WIN95
     #define X_FUNTYPE        __export __cdecl
     #define X_PASCALFUNTYPE  __export __pascal
   #endif
#else /* Microsoft Visual C */
   #define X_FUNTYPE

   /* Note that __declspec(dllexport) cannot be used with pascal as the */
   /* names are mangled, unlike Watcom.                                 */
   /* Also __declspec must be before the return type unlike ALL other   */
   /* currently supported compilers                                     */
   #define X_PASCALFUNTYPE WINAPI

   /* Remove references to obsolete keywords */
   #ifdef __export
   #undef __export
   #endif
   #define __export

   #ifdef _export
   #undef _export
   #endif
   #define _export

#define X_EXPORT __declspec( dllexport )
#endif

#ifndef _X_MODULEHANDLE_DEFINED
#define _X_MODULEHANDLE_DEFINED
typedef HMODULE X_MODULEHANDLE;
#endif

#define X_NULLMODULEHANDLE ((X_MODULEHANDLE)(0))

#ifndef _X_APIRET_DEFINED
#define _X_APIRET_DEFINED
typedef unsigned long X_APIRET;
#endif

#ifndef _X_PFN_DEFINED
#define _X_PFN_DEFINED
typedef LONG_PTR X_PFN;
#endif

#endif /* def X_O_S_WIN */

/* Unix */

#if defined(X_OPERATING_SYSTEM_UNIX)

#ifdef __OS400__
#ifndef _INTPTR_T
typedef int64_t intptr_t;
#endif
#ifndef _UINTPTR_T
typedef uint64_t uintptr_t;
#endif
#endif

#ifndef _HWND_DEFINED
#define _HWND_DEFINED
typedef void *HWND; /* @4252A1 */
#endif

#ifndef _LONG_PTR_DEFINED
#define _LONG_PTR_DEFINED
typedef intptr_t LONG_PTR;
#endif

#ifndef _UINT_PTR_DEFINED
#define _UINT_PTR_DEFINED
typedef uintptr_t UINT_PTR;
#endif

#ifndef _X_MODULEHANDLE_DEFINED
#define _X_MODULEHANDLE_DEFINED
typedef void *X_MODULEHANDLE;
#endif

#define X_NULLMODULEHANDLE ((X_MODULEHANDLE)(NULL))

#ifndef _X_APIRET_DEFINED
#define _X_APIRET_DEFINED
typedef int X_APIRET;
#endif

#ifndef _X_PFN_DEFINED
#define _X_PFN_DEFINED
typedef long (*X_PFN)();
#endif

#define X_PASCALFUNTYPE /* @2506A1 */

#endif /* def X_O_S_UNIX */

#ifndef _X_LONG_PTR_DEFINED
#define _X_LONG_PTR_DEFINED
typedef LONG_PTR X_LONG_PTR;
#endif

/* =================================================================== */
/*  Redefines of functions. Please state reason                        */
/* =================================================================== */

#if defined( X_OPERATING_SYSTEM_WIN) && defined( X_MSVC )

/*
 *  *** FIX ME ***
 *  This header is meant for type definitions and this redirection
 *  is obviously misplaced. This kind of redirection should be put
 *  together in its own header file. Or in this case of strdup(),
 *  utilstr.h offers a better way of proper redirection.
 */
/* Without the '_' strdup does not allocate the ptr in the CRT heap, */
/* thus free() fails.  Found when using MSVC 6.0 CRT rather that the */
/* one were were installing before 10.0 */
#ifndef strdup
#define strdup _strdup
#endif

#endif

/* ================================================================= */
/*  LANSA/X Variable and function declaration values                 */
/* ================================================================= */

/* setup default defines that are not already set */

#ifndef X_FUNTYPE
#define X_FUNTYPE
#endif

#ifndef X_EXPORT
#define X_EXPORT
#endif

#ifndef X_PASCALFUNTYPE
#define X_PASCALFUNTYPE _Pascal
#endif

#ifdef NULL
   #define pX_NULL NULL
#else
   #ifdef __cplusplus
      #define pX_NULL (0)
   #else
      #define pX_NULL ((void *)0)
  #endif
#endif

/* VOID types */

#ifndef _X_VOID_DEFINED
#define _X_VOID_DEFINED
#if defined(__GNUC__) && __GNUC__ >= 4
#define X_VOID void
#else
typedef void X_VOID;
#endif
#endif

#ifndef _X_PVOID_DEFINED
#define _X_PVOID_DEFINED
typedef X_VOID * X_PVOID;
#endif

#ifndef _X_PPVOID_DEFINED
#define _X_PPVOID_DEFINED
typedef X_PVOID * X_PPVOID;
#endif

#ifndef _X_PCVOID_DEFINED
#define _X_PCVOID_DEFINED
typedef const X_VOID * X_PCVOID;
#endif

#ifndef _X_PPCVOID_DEFINED
#define _X_PPCVOID_DEFINED
typedef X_PCVOID * X_PPCVOID;
#endif

/* CHAR types */

#ifndef _X_CHAR_DEFINED
#define _X_CHAR_DEFINED
typedef char X_CHAR;
#endif

#ifndef _X_PCHAR_DEFINED
#define _X_PCHAR_DEFINED
typedef X_CHAR * X_PCHAR;
#endif

#ifndef _X_PPCHAR_DEFINED
#define _X_PPCHAR_DEFINED
typedef X_PCHAR * X_PPCHAR;
#endif

#ifndef _X_UCHAR_DEFINED
#define _X_UCHAR_DEFINED
typedef unsigned char X_UCHAR;
#endif

#ifndef _X_PUCHAR_DEFINED
#define _X_PUCHAR_DEFINED
typedef X_UCHAR * X_PUCHAR;
#endif

#ifndef _X_PPUCHAR_DEFINED
#define _X_PPUCHAR_DEFINED
typedef X_PUCHAR * X_PPUCHAR;
#endif

#ifndef _X_CCHAR_DEFINED
#define _X_CCHAR_DEFINED
typedef const X_CHAR X_CCHAR;
#endif

#ifndef _X_PCCHAR_DEFINED
#define _X_PCCHAR_DEFINED
typedef X_CCHAR * X_PCCHAR;
#endif

#ifndef _X_PPCCHAR_DEFINED
#define _X_PPCCHAR_DEFINED
typedef X_PCCHAR * X_PPCCHAR;
#endif

#ifndef _X_CUCHAR_DEFINED
#define _X_CUCHAR_DEFINED
typedef const X_UCHAR X_CUCHAR;
#endif

#ifndef _X_PCUCHAR_DEFINED
#define _X_PCUCHAR_DEFINED
typedef X_CUCHAR * X_PCUCHAR;
#endif

#ifndef _X_PPCUCHAR_DEFINED
#define _X_PPCUCHAR_DEFINED
typedef X_PCUCHAR * X_PPCUCHAR;
#endif

/* NUMBERIC types */

#ifndef _X_INT_DEFINED
#define _X_INT_DEFINED
typedef int X_INT;
#endif

#ifndef _X_PINT_DEFINED
#define _X_PINT_DEFINED
typedef X_INT * X_PINT;
#endif

#ifndef _X_UINT_DEFINED
#define _X_UINT_DEFINED
typedef unsigned int X_UINT;
#endif

#ifndef _X_PUINT_DEFINED
#define _X_PUINT_DEFINED
typedef X_UINT * X_PUINT;
#endif

#ifndef _X_SHORT_DEFINED
#define _X_SHORT_DEFINED
typedef short X_SHORT;
#endif

#ifndef _X_PSHORT_DEFINED
#define _X_PSHORT_DEFINED
typedef X_SHORT * X_PSHORT;
#endif

#ifndef _X_USHORT_DEFINED
#define _X_USHORT_DEFINED
typedef unsigned short X_USHORT;
#endif

#ifndef _X_PUSHORT_DEFINED
#define _X_PUSHORT_DEFINED
typedef X_USHORT * X_PUSHORT;
#endif

#if !defined(X_USE_INT_NOT_LONG)

#ifndef _X_LONG_DEFINED
#define _X_LONG_DEFINED
typedef long X_LONG;
#endif

#ifndef _X_ULONG_DEFINED
#define _X_ULONG_DEFINED
typedef unsigned long X_ULONG;
#endif

#else /* def X_USE_INT_NOT_LONG */

#ifndef _X_LONG_DEFINED
#define _X_LONG_DEFINED
typedef int X_LONG;
#endif

#ifndef _X_ULONG_DEFINED
#define _X_ULONG_DEFINED
typedef unsigned int X_ULONG;
#endif

#endif /* ?def X_USE_INT_NOT_LONG */

// Document where SIZE_T is cast to ULONG so it can be easily found
#ifndef _X_ULONG_SIZE_T_CAST_DEFINED
#define _X_ULONG_SIZE_T_CAST_DEFINED
#ifdef __cplusplus
#define X_ULONG_SIZE_T_CAST( _var ) \
   static_cast<X_ULONG>(_var)
#else
#define X_ULONG_SIZE_T_CAST( _var ) \
   (X_ULONG) (_var)
#endif
#endif

#ifndef _X_LONG_SIZE_T_CAST_DEFINED
#define _X_LONG_SIZE_T_CAST_DEFINED
#ifdef __cplusplus
#define X_LONG_SIZE_T_CAST( _var ) \
   static_cast<X_LONG>(_var)
#else
#define X_LONG_SIZE_T_CAST( _var ) \
   (X_LONG) (_var)
#endif
#endif

#ifndef _X_INT_SIZE_T_CAST_DEFINED
#define _X_INT_SIZE_T_CAST_DEFINED
#ifdef __cplusplus
#define X_INT_SIZE_T_CAST( _var ) \
   static_cast<X_INT>(_var)
#else
#define X_INT_SIZE_T_CAST( _var ) \
   (X_INT) (_var)
#endif
#endif

#ifndef _X_UINT_SIZE_T_CAST_DEFINED
#define _X_UINT_SIZE_T_CAST_DEFINED
#ifdef __cplusplus
#define X_UINT_SIZE_T_CAST( _var ) \
   static_cast<X_UINT>(_var)
#else
#define X_UINT_SIZE_T_CAST( _var ) \
   (X_UINT) (_var)
#endif
#endif

#ifndef _X_USHORT_SIZE_T_CAST_DEFINED
#define _X_USHORT_SIZE_T_CAST_DEFINED
#ifdef __cplusplus
#define X_USHORT_SIZE_T_CAST( _var ) \
   static_cast<X_USHORT>(_var)
#else
#define X_USHORT_SIZE_T_CAST( _var ) \
   (X_USHORT) (_var)
#endif
#endif

#ifndef _X_SHORT_SIZE_T_CAST_DEFINED
#define _X_SHORT_SIZE_T_CAST_DEFINED
#ifdef __cplusplus
#define X_SHORT_SIZE_T_CAST( _var ) \
   static_cast<X_SHORT>(_var)
#else
#define X_SHORT_SIZE_T_CAST( _var ) \
   (X_SHORT) (_var)
#endif
#endif

#ifndef _X_LONG_PTR_ARITHMETIC_CAST_DEFINED
#define _X_LONG_PTR_ARITHMETIC_CAST_DEFINED
#ifdef __cplusplus
#define X_LONG_PTR_ARITHMETIC_CAST( _var ) \
   static_cast<X_LONG>(_var)
#else
#define X_LONG_PTR_ARITHMETIC_CAST( _var ) \
   (X_LONG) (_var)
#endif
#endif

#ifndef _X_ULONG_PTR_ARITHMETIC_CAST_DEFINED
#define _X_ULONG_PTR_ARITHMETIC_CAST_DEFINED
#ifdef __cplusplus
#define X_ULONG_PTR_ARITHMETIC_CAST( _var ) \
   static_cast<X_ULONG>(_var)
#else
#define X_ULONG_PTR_ARITHMETIC_CAST( _var ) \
   (X_ULONG) (_var)
#endif
#endif

#ifndef _X_INT_PTR_ARITHMETIC_CAST_DEFINED
#define _X_INT_PTR_ARITHMETIC_CAST_DEFINED
#ifdef __cplusplus
#define X_INT_PTR_ARITHMETIC_CAST( _var ) \
   static_cast<X_INT>(_var)
#else
#define X_INT_PTR_ARITHMETIC_CAST( _var ) \
   (X_INT) (_var)
#endif
#endif

#ifndef _X_UINT_PTR_ARITHMETIC_CAST_DEFINED
#define _X_UINT_PTR_ARITHMETIC_CAST_DEFINED
#ifdef __cplusplus
#define X_UINT_PTR_ARITHMETIC_CAST( _var ) \
   static_cast<X_UINT>(_var)
#else
#define X_UINT_PTR_ARITHMETIC_CAST( _var ) \
   (X_UINT) (_var)
#endif
#endif

#ifndef _X_SHORT_PTR_ARITHMETIC_CAST_DEFINED
#define _X_SHORT_PTR_ARITHMETIC_CAST_DEFINED
#ifdef __cplusplus
#define X_SHORT_PTR_ARITHMETIC_CAST( _var ) \
   static_cast<X_SHORT>(_var)
#else
#define X_SHORT_PTR_ARITHMETIC_CAST( _var ) \
   (X_SHORT) (_var)
#endif

#endif

#ifndef _X_USHORT_PTR_ARITHMETIC_CAST_DEFINED
#define _X_USHORT_PTR_ARITHMETIC_CAST_DEFINED
#ifdef __cplusplus
#define X_USHORT_PTR_ARITHMETIC_CAST( _var ) \
   static_cast<X_USHORT>(_var)
#else
#define X_USHORT_PTR_ARITHMETIC_CAST( _var ) \
   (X_USHORT) (_var)
#endif
#endif

#ifndef _X_SIZE_T_SIGNED_CAST_DEFINED
#define _X_SIZE_T_SIGNED_CAST_DEFINED
#ifdef __cplusplus
#define X_SIZE_T_SIGNED_CAST( _var ) \
   static_cast<size_t>(_var)
#else
#define X_SIZE_T_SIGNED_CAST( _var ) \
   (size_t) (_var)
#endif
#endif

#ifndef _X_PLONG_DEFINED
#define _X_PLONG_DEFINED
typedef X_LONG * X_PLONG;
#endif

#ifndef _X_PULONG_DEFINED
#define _X_PULONG_DEFINED
typedef X_ULONG * X_PULONG;
#endif

#ifndef _X_SIZE_DEFINED
#define _X_SIZE_DEFINED
typedef size_t X_SIZE;
typedef X_SIZE *X_PSIZE;
#endif

// Note that iSeries has 64 bit size_t, not 128.
// Use LP_SSIZE_T when need to be assigned from size_t but current interfaces use signed integer (or signed long)
#ifndef _X_SSIZE_DEFINED
#define _X_SSIZE_DEFINED
#ifdef X_SIZE_T_32BIT
typedef int32_t X_SSIZE;
#else
typedef int64_t X_SSIZE;
#endif
typedef X_SSIZE *X_PSSIZE;
#endif

#if defined(X_LONG_DOUBLES_SUPPORTED)

#ifndef _X_DOUBLE_DEFINED
#define _X_DOUBLE_DEFINED
typedef long double X_DOUBLE;
#endif

#else /* !def X_LONG_DOUBLES_SUPPORTED */

#ifndef _X_DOUBLE_DEFINED
#define _X_DOUBLE_DEFINED
typedef double X_DOUBLE;
#endif

#endif /* ?def X_LONG_DOUBLES_SUPPORTED */

#ifndef _X_PDOUBLE_DEFINED
#define _X_PDOUBLE_DEFINED
typedef X_DOUBLE * X_PDOUBLE;
#endif

/* BOOL types */

#ifndef _X_BOOL_DEFINED
#define _X_BOOL_DEFINED
typedef int X_BOOL;
#endif

#ifndef _X_PBOOL_DEFINED
#define _X_PBOOL_DEFINED
typedef X_BOOL * X_PBOOL;
#endif

/* FIXED-SIZE types */

#ifndef _X_BYTE_DEFINED
#define _X_BYTE_DEFINED
typedef unsigned char X_BYTE;
#endif

#ifndef _X_PBYTE_DEFINED
#define _X_PBYTE_DEFINED
typedef X_BYTE * X_PBYTE;
#endif

#ifndef _X_WORD_DEFINED
#define _X_WORD_DEFINED
typedef unsigned short X_WORD;
#endif

#ifndef _X_PWORD_DEFINED
#define _X_PWORD_DEFINED
typedef X_WORD * X_PWORD;
#endif

/* int is 32-bit for all currently supported platforms */
#ifndef _X_DWORD_DEFINED
#define _X_DWORD_DEFINED
typedef unsigned int X_DWORD;
#endif

#ifndef _X_PDWORD_DEFINED
#define _X_PDWORD_DEFINED
typedef X_DWORD * X_PDWORD;
#endif

/* New types added for V11.0 */

#ifdef X_OPERATING_SYSTEM_WIN

#ifndef _X_LONGLONG_DEFINED
#define _X_LONGLONG_DEFINED
typedef LONGLONG X_LONGLONG;
#endif

#ifndef __WATCOMC__
#ifndef _X_ULONGLONG_DEFINED
#define _X_ULONGLONG_DEFINED
typedef ULONGLONG X_ULONGLONG;
#endif
#endif

#if defined(__WATCOMC__) || _MSC_VER <= 1300

/* Watcom C or VC before VC.NET does not support suffixes LL and ULL */
#define X_CONST_LONGLONG_IS_LONG

#ifndef LL_CONST
#define LL_CONST(n) n ## L
#endif
#ifndef ULL_CONST
#define ULL_CONST(n) n ## UL
#endif
#endif

#else

#ifndef _X_LONGLONG_DEFINED
#define _X_LONGLONG_DEFINED
typedef long long X_LONGLONG;
#endif

#ifndef __WATCOMC__
#ifndef _X_ULONGLONG_DEFINED
#define _X_ULONGLONG_DEFINED
typedef unsigned long long X_ULONGLONG;
#endif
#endif

#endif

/* Default suffixes LL and ULL handling if not being overridden */
#ifndef LL_CONST
#define LL_CONST(n) n ## LL
#endif
#ifndef ULL_CONST
#define ULL_CONST(n) n ## ULL
#endif

#ifndef _X_PLONGLONG_DEFINED
#define _X_PLONGLONG_DEFINED
typedef X_LONGLONG * X_PLONGLONG;
#endif

#ifdef _X_ULONGLONG_DEFINED
#ifndef _X_PULONGLONG_DEFINED
#define _X_PULONGLONG_DEFINED
typedef X_ULONGLONG * X_PULONGLONG;
#endif
#endif

#ifndef _X_FLOAT_DEFINED
#define _X_FLOAT_DEFINED
typedef float X_FLOAT;
#endif

#ifndef _X_PFLOAT_DEFINED
#define _X_PFLOAT_DEFINED
typedef X_FLOAT * X_PFLOAT;
#endif

#ifndef _X_INT8_DEFINED
#define _X_INT8_DEFINED
typedef int8_t X_INT8;
#endif

#ifndef _X_PINT8_DEFINED
#define _X_PINT8_DEFINED
typedef X_INT8 * X_PINT8;
#endif

#ifndef _X_UINT8_DEFINED
#define _X_UINT8_DEFINED
typedef uint8_t X_UINT8;
#endif

#ifndef _X_PUINT8_DEFINED
#define _X_PUINT8_DEFINED
typedef X_UINT8 * X_PUINT8;
#endif

#ifndef _X_INT16_DEFINED
#define _X_INT16_DEFINED
typedef int16_t X_INT16;
#endif

#ifndef _X_PINT16_DEFINED
#define _X_PINT16_DEFINED
typedef X_INT16 * X_PINT16;
#endif

#ifndef _X_UINT16_DEFINED
#define _X_UINT16_DEFINED
typedef uint16_t X_UINT16;
#endif

#ifndef _X_PUINT16_DEFINED
#define _X_PUINT16_DEFINED
typedef X_UINT16 * X_PUINT16;
#endif

// Intentionally not using int32_t as some platforms would define that
// as long while others would define that as int.
// As all supported platforms use 32-bit int, this is simpler and more
// consistent.
#ifndef _X_INT32_DEFINED
#define _X_INT32_DEFINED
typedef int X_INT32;
#endif

#ifndef _X_PINT32_DEFINED
#define _X_PINT32_DEFINED
typedef X_INT32 * X_PINT32;
#endif

// Intentionally not using uint32_t as some platforms would define that
// as unsigned long while others would define that as unsigned int.
// As all supported platforms use 32-bit unsigned int, this is simpler
// and more consistent.
#ifndef _X_UINT32_DEFINED
#define _X_UINT32_DEFINED
typedef unsigned X_UINT32;
#endif

#ifndef _X_PUINT32_DEFINED
#define _X_PUINT32_DEFINED
typedef X_UINT32 * X_PUINT32;
#endif

#ifndef _X_INT64_DEFINED
#define _X_INT64_DEFINED
typedef int64_t X_INT64;
#endif

#ifndef _X_PINT64_DEFINED
#define _X_PINT64_DEFINED
typedef X_INT64 * X_PINT64;
#endif

#ifdef _X_ULONGLONG_DEFINED
#ifndef _X_UINT64_DEFINED
#define _X_UINT64_DEFINED
typedef uint64_t X_UINT64;
#endif
#endif

#ifdef _X_UINT64_DEFINED
#ifndef _X_PUINT64_DEFINED
#define _X_PUINT64_DEFINED
typedef X_UINT64 * X_PUINT64;
#endif
#endif

#ifndef _X_FLT32_DEFINED
#define _X_FLT32_DEFINED
typedef X_FLOAT X_FLT32;
#endif

#ifndef _X_PFLT32_DEFINED
#define _X_PFLT32_DEFINED
typedef X_FLT32 * X_PFLT32;
#endif

#ifndef _X_FLT64_DEFINED
#define _X_FLT64_DEFINED
typedef X_DOUBLE X_FLT64;
#endif

#ifndef _X_PFLT64_DEFINED
#define _X_PFLT64_DEFINED
typedef X_FLT64 * X_PFLT64;
#endif

/* LANSA/X types */

#ifndef _X_FCHAR_DEFINED
#define _X_FCHAR_DEFINED
typedef char X_FCHAR;
#endif

#ifndef _X_PFCHAR_DEFINED
#define _X_PFCHAR_DEFINED
typedef X_FCHAR * X_PFCHAR;
#endif

#ifndef _X_PPFCHAR_DEFINED
#define _X_PPFCHAR_DEFINED
typedef X_PFCHAR * X_PPFCHAR;
#endif

#ifndef _X_VCHAR_DEFINED
#define _X_VCHAR_DEFINED
typedef char X_VCHAR;
#endif

#ifndef _X_UTF16_VCHAR_DEFINED
   #define _X_UTF16_VCHAR_DEFINED

   #if defined(X_OPERATING_SYSTEM_WIN)
      typedef wchar_t X_UTF16_VCHAR;
   #elif defined(X_OPERATING_SYSTEM_ISERIES)
      #define X_UTF16_VCHAR wchar_t
   #else
      typedef unsigned short X_UTF16_VCHAR;
   #endif
#endif

#ifndef _X_PVCHAR_DEFINED
#define _X_PVCHAR_DEFINED
typedef X_VCHAR * X_PVCHAR;
#endif

#ifndef _X_PPVCHAR_DEFINED
#define _X_PPVCHAR_DEFINED
typedef X_PVCHAR * X_PPVCHAR;
#endif

#ifndef _X_TYPE_FLAG_DEFINED
#define _X_TYPE_FLAG_DEFINED
typedef char X_TYPE_FLAG;
#endif

#ifndef _X_PTYPE_FLAG_DEFINED
#define _X_PTYPE_FLAG_DEFINED
typedef X_TYPE_FLAG * X_PTYPE_FLAG;
#endif

#ifndef _X_YES_NO_DEFINED
#define _X_YES_NO_DEFINED
typedef char X_YES_NO;
#endif

#ifndef _X_PYES_NO_DEFINED
#define _X_PYES_NO_DEFINED
typedef X_YES_NO * X_PYES_NO;
#endif

#ifndef _X_DICTIONARY_PACKED_DEFINED
#define _X_DICTIONARY_PACKED_DEFINED
typedef char X_DICTIONARY_PACKED;
#endif

#ifndef _X_DICTIONARY_SIGNED_DEFINED
#define _X_DICTIONARY_SIGNED_DEFINED
typedef char X_DICTIONARY_SIGNED;
#endif

#ifndef _X_DICTIONARY_ALPHA_DEFINED
#define _X_DICTIONARY_ALPHA_DEFINED
typedef char X_DICTIONARY_ALPHA;
#endif

#ifndef _X_DICTIONARY_LONG_DEFINED
#define _X_DICTIONARY_LONG_DEFINED
typedef X_LONG X_DICTIONARY_LONG;
#endif

#if defined(X_LONG_DOUBLES_SUPPORTED)

#ifndef _X_DICTIONARY_DOUBLE_DEFINED
#define _X_DICTIONARY_DOUBLE_DEFINED
typedef long double X_DICTIONARY_DOUBLE;
#endif

#else /* !def X_LONG_DOUBLES_SUPPORTED */

#ifndef _X_DICTIONARY_DOUBLE_DEFINED
#define _X_DICTIONARY_DOUBLE_DEFINED
typedef double X_DICTIONARY_DOUBLE;
#endif

#endif /* ?def X_LONG_DOUBLES_SUPPORTED */

#ifndef _X_DICTIONARY_ARRAY_DEFINED
#define _X_DICTIONARY_ARRAY_DEFINED
typedef char X_DICTIONARY_ARRAY;
#endif

#ifndef _X_PDICTIONARY_FIELD_DEFINED
#define _X_PDICTIONARY_FIELD_DEFINED
typedef char * X_PDICTIONARY_FIELD;
#endif

/* Limits and default values */
#define X_INT8_LOVAL    (-128)
#define X_INT8_HIVAL      127
#define X_UINT8_HIVAL     0xff

#define X_UINT16_HIVAL    65535
#define X_INT16_HIVAL     32767
#define X_INT16_LOVAL   (-32768)  

#define X_UINT32_HIVAL    4294967295U
#define X_INT32_HIVAL     2147483647L
#define X_INT32_LOVAL   (-2147483647L - 1)

#define X_ULONG_HIVAL     X_UINT32_HIVAL
#define X_LONG_HIVAL      X_INT32_HIVAL 
#define X_LONG_LOVAL      X_INT32_LOVAL 

#define X_UINT64_HIVAL    ULL_CONST(0xffffffffffffffff)
#define X_INT64_HIVAL     LL_CONST(9223372036854775807)
#define X_INT64_LOVAL   ( LL_CONST(-9223372036854775807) - 1)

#if defined(X_LONG_DOUBLES_SUPPORTED)
#define X_MAXIMUM_DIGITS LDBL_DIG /*@2874M1*/
#else
#define X_MAXIMUM_DIGITS DBL_DIG /*@2874A1*/
#endif

/* Decimal library current limitations */
#define X_MAX_NUMERIC_DIGITS     63
#define X_MAX_NUMERIC_DECIMALS   63

/***************************************************************/
/* TN: Maximum number of digits ( and sign ) to hold a Integer */
/***************************************************************/
#define X_INT_MAXIMUM_DIGITS  11

#ifndef _X_PID_DEFINED
#define _X_PID_DEFINED
#if defined(X_OPERATING_SYSTEM_WIN)
typedef DWORD X_PID;
#elif defined(X_OPERATING_SYSTEM_ISERIES)
/*
 *  Used to be X_ULONG but that is compiled into different types
 *  for Classic Web (as unsigned long) and VL Web (as unsigned int)
 *  and would end up with different signatures for C++ functions.
 */
typedef unsigned int X_PID;
#elif defined(X_OPERATING_SYSTEM_UNIX)
typedef pid_t X_PID;
#endif /* ?def X_O_S */
#endif

#ifndef _X_PPID_DEFINED
#define _X_PPID_DEFINED
typedef X_PID * X_PPID;
#endif

#ifndef _X_PIDEXT_DEFINED
#define _X_PIDEXT_DEFINED
typedef struct _X_PIDEXT
{
   X_PID pid;
#if defined(X_OPERATING_SYSTEM_ISERIES)
   X_UCHAR pidInternal[16];
#endif
} X_PIDEXT;
#endif

#if defined(X_OPERATING_SYSTEM_ISERIES)
#define X_PIDEXT_INIT { 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }
#else
#define X_PIDEXT_INIT { 0 }
#endif

#ifndef _X_PPIDEXT_DEFINED
#define _X_PPIDEXT_DEFINED
typedef X_PIDEXT * X_PPIDEXT;
#endif

#ifndef _X_JOBID_DEFINED
#define _X_JOBID_DEFINED
/*
 *  Used to be X_ULONG but that is compiled into different types
 *  for Classic Web (as unsigned long) and VL Web (as unsigned int)
 *  and would end up with different signatures for C++ functions.
 */
typedef unsigned int X_JOBID;
#endif

#ifndef _X_PJOBID_DEFINED
#define _X_PJOBID_DEFINED
typedef X_JOBID * X_PJOBID;
#endif

#ifndef _X_JOBEXTID_DEFINED
#define _X_JOBEXTID_DEFINED
typedef struct _X_JOBEXTID
{
   X_JOBID jid;
#if defined(X_OPERATING_SYSTEM_ISERIES)
   X_UCHAR jidInternal[16];
#endif
} X_JOBEXTID;
#endif

#if defined(X_OPERATING_SYSTEM_ISERIES)
#define X_JOBEXTID_INIT { 0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } }
#else
#define X_JOBEXTID_INIT { 0 }
#endif

#ifndef _X_PJOBEXTID_DEFINED
#define _X_PJOBEXTID_DEFINED
typedef X_JOBEXTID * X_PJOBEXTID;
#endif

#ifndef _X_FILE_KIND
#define _X_FILE_KIND
/* Enumerated file types */
typedef enum
{
   X_FK_TEXT_ML,
   X_FK_TEXT_PROGRAM_ML,
   X_FK_TEXT_PROGRAM_ONLY,
   X_FK_TEXT_CONVERT,
   X_FK_TEXT_LOG,
   X_FK_TEXT_TRACE,
   X_FK_EMAIL,
   X_FK_UTF8,
   X_FK_EXECUTABLE,
   X_FK_SOURCE,
   X_FK_BINARY,
   X_FK_LOCK,
   X_FK_PROGRAM_ONLY,
   X_FK_CONFIG_FILE,
   X_FK_INVARIANT_DATA
} X_FILE_KIND;
#endif

/* TN: type for buffering file reading using open and read instead of fopen and fgets*/
#ifndef _X_FILEBUFFERING
#define _X_FILEBUFFERING
typedef struct 
{
   X_INT       iFile;         /* TN: file handle returns by open()                     */
   X_PVCHAR    pvchBuf;       /* TN: Buf to read data and hold them before processing  */
   X_INT       iBufLen;       /* TN: Buffer size                                       */
   X_INT       iDataLen;      /*TN: Number of bytes read fy the last read() */
   X_INT       iDataBegin;    /*TN: index of the first unprocessed byte    */
   X_FILE_KIND kind;         /* Kind of file. Only important for UTF-8 as its read with non-platform LF */
   /* TN: by default the buffer size is 64K but the user can specify the it to be multiply time of 64 K*/ 
} X_FILEBUFFERING;
#endif

#ifndef _X_WINDOWHANDLE_DEFINED
#define _X_WINDOWHANDLE_DEFINED
typedef X_ULONG X_WINDOWHANDLE;
#endif

#define X_NULLWINDOWHANDLE ((X_WINDOWHANDLE)(0))

#ifndef _X_WIN_HINSTANCE_DEFINED
#define _X_WIN_HINSTANCE_DEFINED
typedef X_ULONG X_WIN_HINSTANCE;
#endif

#define X_WIN_NULLHINSTANCE ((X_WIN_HINSTANCE)(0))

#endif /* __INCL_X_CTYPES_H__ */
