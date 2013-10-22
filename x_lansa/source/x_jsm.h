#ifdef _WIN32
#include <windows.h>
#endif

#include "x_bldcfg.h"

#define JSM_SERVER_SIZE              50
#define JSM_COMMAND_SIZE             256
#define JSM_STATUS_SIZE              20
#define JSM_RESPONSE_SIZE            256

#define JSM_RESPONSE_PREFIX          "JSMMSG "
#define JSM_RESPONSE_PREFIX_LENGTH   7

#define JSM_MAX_REDIRECT_COUNT      20                   /* TN: Maximum redirect times while attempting to connect to JSMServer */ 
#define JSM_MAX_NOCONNECT_COUNT     20                   /* TN: Maximum Noconnect times while attempting to connect to JSMServer */

#ifdef __WATCOMC__
#pragma aux __cdecl "*" \
            parm caller [] \
            value struct float struct routine [eax] \
            modify [eax ecx edx]
#define JSM_FUNCTION __cdecl
#else
#define JSM_FUNCTION
#endif

#ifndef _X_SOCKET_DEFINED
#define _X_SOCKET_DEFINED
#ifdef X_OS_WIN
typedef SOCKET X_SOCKET;
#else
typedef long X_SOCKET;
#endif
#endif

/***********************/
/* 3GL RDML Client API */
/***********************/

#ifdef __cplusplus
extern "C" {
#endif

void JSM_FUNCTION JSMOPEN ( char* pfchServer,
                            char* pfchStatus,
                            char* pfchResponse );

void JSM_FUNCTION JSMCLOSE ( char* pfchStatus,
                             char* pfchResponse );

void JSM_FUNCTION JSMCMD ( char* pfchCommand,
                           char* pfchStatus,
                           char* pfchResponse );

void JSM_FUNCTION JSMCMDX ( char* pfchCommand,
                            char* pfchByteArray,
                            int*  pfiByteArrayLength,
                            char* pfchStatus,
                            char* pfchResponse );

void JSM_FUNCTION JSMBYTELNGTH (  int* pfiByteArrayLength );

void JSM_FUNCTION JSMBYTERECV ( char* pfchByteArray );

#ifdef __cplusplus
}
#endif

/************************/
/* 3GL RDMLX Client API */
/************************/

#ifdef __cplusplus
extern "C" {
#endif

long JSM_FUNCTION JSMXOPEN ( char* pfchServer,
                             char* pfchStatus,
                             char** ppfchResponse );

void JSM_FUNCTION JSMXCLOSE ( long handle,
                              char* pfchStatus,
                              char** ppfchResponse );

void JSM_FUNCTION JSMXCMD ( long handle,
                            char* pfchCommand,
                            char* pfchStatus,
                            char** ppfchResponse );

void JSM_FUNCTION JSMXCMDX ( long handle, 
                             char* pfchCommand,
                             char* pfchByteArray,
                             int*  pfiByteArrayLength,
                             char* pfchStatus,
                             char** ppfchResponse );

void JSM_FUNCTION JSMXBYTELNGTH ( long handle,
                                  int* pfiByteArrayLength );

void JSM_FUNCTION JSMXBYTERECV ( long handle, 
                                 char* pfchByteArray );

void JSM_FUNCTION JSMXFREERESPONSE( char** ppfchResponse );

#ifdef __cplusplus
}
#endif

/************************************************/
/* Signed EBCDIC <-> ASCII Conversion Functions */
/************************************************/

#ifdef __cplusplus
extern "C" {
#endif

void JSM_FUNCTION SignedASCIIToEBCDIC ( char* fieldDataDest, 
                                        char* fieldDataSrc,
                                        int length ) ;

void JSM_FUNCTION SignedEBCDICToASCII ( char* fieldDataDest, 
                                        char* fieldDataSrc,
                                        int length ) ;

#ifdef __cplusplus
}
#endif

/*********************/
/* Parse Response ID */
/*********************/

#ifdef __cplusplus
extern "C" {
#endif

long JSM_FUNCTION JSMResponseNumber ( char* pfchResponse ) ;

#ifdef __cplusplus
}
#endif

