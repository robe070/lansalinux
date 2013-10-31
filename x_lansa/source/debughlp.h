/*
 *  $Workfile:: debughlp.h                                       $
 *   $Archive:: /VL/Trunk/work/x_win95/x_lansa/src/debughlp.h    $
 *  $Revision:: 48                                               $
 *    $Author:: Kelvin                                           $
 *      $Date:: 2013-04-18 14:42:07+10:00                        $
 */

#ifndef __INCL_DEBUGHLP_H__
#define __INCL_DEBUGHLP_H__

/*
 *  Debugging Facilities for Win32|Unix|Linux|iSeries
 *
 *  The routines are included as static functions to eliminate
 *  the requirement of linking to a complied library and hence
 *  changing related makefiles.
 *
 *  All identifiers starting with __dbg are supposed to be
 *  internal.
 *
 *  Normally, this header file is used in this way:
 *
 *    #undef X_DEBUG_WIN32
 *    #ifdef X_OPERATING_SYSTEM_WIN
 *    #ifdef X_DEBUG
 *    #define X_DEBUG_WIN32
 *    #define USE_DEBUG_DIALOG   // if using debug_dialog...
 *    #define USE_DEBUG_{other}  // if using other facilities
 *    #include "debughlp.h"
 *    #endif
 *    #endif
 *
 *  If no USE_DEBUG_{facility) is defined, this header file will
 *  not define any identifier or macro for the source file.
 *
 *  [Debug Dialog]
 *
 *    Activated by
 *       #define USE_DEBUG_DIALOG
 *
 *    Pop-up a stay-on-top message box upon specified condition.
 *    The routines have similar list of parameters:
 *
 *    debug_dialog{_for_condition}
 *    (
 *       {cond1, cond2, ...},
 *       __file, __line, __func,       // common
 *       format, {info1, info2, ...}   // common
 *    );
 *
 *    where
 *       cond1, cond2, ...    specify the condition must be
 *                            satisfied for the message box
 *                            to pop-up
 *       === information to be shown in the caption
 *       __file               source file name, usually __FILE__
 *       __line               line number, usually __LINE__
 *       __func               __func name
 *       === message text to be shown
 *       format, info1, ...   printf style string formatting
 *
 *    Current process id will also be shown in the caption.
 *
 *    In general, if a file is accessed to check for a condition,
 *    the file must be located inside __DBG_DIRECTORY__, which
 *    can be overrided by environment setting of the same name.
 *    The default file __DBG_FILE__ can also be overrided by
 *    environment setting of the same name.
 *
 *    Formatted caption and message must be shorter than
 *    __DBG_CAPTION_SIZE__ and __DBG_MESSAGE_SIZE__ bytes respectively.
 *    If compiled using C compiler other than MSVC, debug_dialog
 *    routines may crash if either formatted caption or message is
 *    longer than __DBG_CAPTION_SIZE__ or __DBG_MESSAGE_SIZE__ bytes.
 *    Because, for instance, Watcom has no safer equivalent versions
 *    of sprintf() and vsprintf(),
 *    i.e. snprintf() and vsnprintf().
 *
 *    The routines will return 1 if the message box has been
 *    poped-up, i.e. condition is satisfied.
 *    Otherwise, 0 will be returned.
 *
 *    debug_dialog([common params...])
 *       Message box always pop-up.
 *
 *    debug_dialog_check_file([common params...])
 *       Message box pop-up if default debug file exists.
 *
 *    debug_dialog_check_file_ex(debugfile, [common params...])
 *       Message box pop-up if specified debug file exists.
 *
 *    debug_dialog_str_eq(string1, string2, [common params...])
 *       Message box pop-up if string1 == string2
 *       Compared using strcasecmp()
 *
 *    debug_dialog_data_eq(buffer1, buffer2, buflen,
 *                         [common params...])
 *       Message box pop-up if the beginning buflen bytes of data
 *       in buffer1 and buffer2 are exactly the same
 *
 *    debug_dialog_match_text(sourcetext, matchtext,
 *                            [common params...])
 *       Message box pop-up if sourcetext is containing matchtext
 *       Compared using strcasecmp()
 *       If both sourcetext and matchtext are "", they are matched
 *       If sourcetext != "" and matchtext == "", they are not matched
 *       If strlen(sourcetext) < strlen(matchtext), they are not matched
 *
 *    debug_dialog_match_text_file(sourcetext, textfile,
 *                                 [common params...])
 *       Message box pop-up if sourcetext is containing text inside
 *          textfile
 *       Each line of textfile will be matched against sourcetext
 *          using the same algorithm in debug_dialog_match_text();
 *          whenever a line is matched, message box will pop-up
 *       Empty lines at end of textfile will be ignored
 *       To match for empty string "", a non-empty line must be added
 *          after an empty line
 *       If a text line is starting with "*", the matching is always
 *          success; hence, the behaviour becomes the same as
 *          debug_dialog_check_file_ex();
 *
 *  [Debug Log]
 *
 *    Activated by
 *       #define USE_DEBUG_LOG
 *
 *    Append text information to a log file upon specified condition.
 *    The routines have similar list of parameters:
 *
 *    debug_log{_for_condition}
 *    (
 *       {cond1, cond2, ...},
 *       logfile,                      // common
 *       __file, __line, __func,       // common
 *       format, {info1, info2, ...}   // common
 *    );
 *
 *    where
 *       cond1, cond2, ..., __file, __line, __func,
 *          format, info1, info2, ... are the same as those for
 *          debug_dialog
 *       logfile              log file where text information
 *                            is appended
 *
 *    If the log file can't be opened for append, no error will be
 *    reported.
 *
 *    The behaviour of the followings are the same as the
 *    debug_dialog counter parts except that messages are appended
 *    to log files instead of poped-up:
 *
 *    debug_log([common params...])
 *    debug_log_check_file([common params...])
 *    debug_log_check_file_ex(debugfile, [common params...])
 *    debug_log_str_eq(string1, string2, [common params...])
 *    debug_log_data_eq(buffer1, buffer2, buflen,
 *                      [common params...])
 *    debug_log_match_text(sourcetext, matchtext,
 *                         [common params...])
 *    debug_log_match_text_file(sourcetext, textfile,
 *                              [common params...])
 */

#if defined(_MSC_VER) || defined(__WATCOMC__)
#pragma pack(push, 8) /* VC default */
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4505)
#endif

#if defined(USE_DEBUG_LOG) && defined(DEBUG_LOG_TIMING) && !defined(USE_DEBUG_TIMER)
#define USE_DEBUG_TIMER
#endif

#if defined(USE_DEBUG_DIALOG) || defined(USE_DEBUG_LOG) || defined(USE_DEBUG_TIMER)
#ifndef USE_DEBUG_COMMON
#define USE_DEBUG_COMMON
#endif
#endif

#ifdef USE_DEBUG_COMMON

#ifdef __GNUC__
#define __DBG_CHECK_FORMAT__(__f__) __attribute__((format __f__))
#else
#define __DBG_CHECK_FORMAT__(__f__)
#endif

#ifdef __GNUC__
#define __DBG_UNUSED__ __attribute__((unused))
#else
#define __DBG_UNUSED__
#endif

#ifndef __DEBUG_COMMON_DEFINED__
#define __DEBUG_COMMON_DEFINED__

#if (defined(unix) || defined(__unix) || defined(__unix__) \
         || defined(linux) || defined(__linux) || defined(__linux__) \
         || defined(__FreeBSD__) \
         || defined(sun) || defined(__sun) || defined(__sun__) \
         || defined(hpux) || defined(__hpux) || defined(__hpux__) \
         || defined(_AIX) \
         || defined(__CYGWIN__) \
         || defined(__OS400__) \
         || defined(X_OPERATING_SYSTEM_UNIX)) \
      && !defined(DEBUG_FORCED_WIN32)
#ifndef __DEBUG_WIN32__
#define __DEBUG_WIN32__ 0
#endif
#ifndef __DEBUG_UNIX__
#define __DEBUG_UNIX__  1
#endif
#elif defined(_MSC_VER) || defined(__MINGW32__) || defined(__WATCOMC__) \
         || defined(WINDOWS) || defined(_WINDOWS) || defined(WIN32) || defined(_WIN32) \
         || defined(X_OPERATING_SYSTEM_WIN) \
         || defined(DEBUG_FORCED_WIN32)
#ifndef __DEBUG_WIN32__
#define __DEBUG_WIN32__ 1
#endif
#ifndef __DEBUG_UNIX__
#define __DEBUG_UNIX__  0
#endif
#else
#ifndef __DEBUG_WIN32__
#define __DEBUG_WIN32__ 0
#endif
#ifndef __DEBUG_UNIX__
#define __DEBUG_UNIX__  0
#endif
#endif

#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#if __DEBUG_WIN32__

#include <io.h>

#elif __DEBUG_UNIX__

#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

#if defined(linux) || defined(__linux) || defined(__linux__)
#include <linux/unistd.h>
#endif

#if defined(__OS400__) || defined(DEBUG_USE_PTHREAD)
#define __DBG_USE_PTHREAD__
#endif

#ifdef __DBG_USE_PTHREAD__
#include <pthread.h>
#endif

#undef __DBG_DEFINED_POSIX_C_SOURCE__
#if !defined(_POSIX_C_SOURCE) && (defined(sun) || defined(__sun) || defined(__sun__))
/* Required to bring in prototypes for shm_open() on Sun boxes */
#define _POSIX_C_SOURCE 3
#define __DBG_DEFINED_POSIX_C_SOURCE__
#endif

#include <sys/mman.h>

#ifdef __DBG_DEFINED_POSIX_C_SOURCE__
#undef _POSIX_C_SOURCE
#undef __DBG_DEFINED_POSIX_C_SOURCE__
#endif

#if defined(__OS400__)

#ifndef __DBG_FILE_MODE
#define __DBG_FILE_MODE 0666
#endif

#include <ctype.h>

#endif /* def __OS400__ */

#endif /* __DEBUG_WIN32__ || __DEBUG_UNIX__ */

#if __DEBUG_UNIX__
#ifdef USE_DEBUG_PYTHON
#include "Python.h"
#endif
#endif

#ifndef __TO_STRING__
#define __TO_STRING__(L) #L
#endif
#ifndef __MAKE_STRING__
#define __MAKE_STRING__(M, L) M(L)
#endif
#ifndef __LINE_NUMBER__
#define __LINE_NUMBER__ __MAKE_STRING__(__TO_STRING__, __LINE__)
#endif
#ifndef __FILE_LINE__
#define __FILE_LINE__ __FILE__ "(" __LINE_NUMBER__ ")"
#endif

#if __DEBUG_WIN32__

#ifndef _WIN32_WINNT
#ifdef __DBG_VERBOSE__
#ifdef _MSC_VER
#pragma message(__FILE_LINE__ " : note: _WIN32_WINNT not defined!")
#endif
#endif
#define _WIN32_WINNT 0x400
#define __XXX_WIN32_WINNT_DEFINED_XXX__
#endif

#ifndef _WINDOWS_

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#else /* def _WINDOWS_ */

/*
 *  The problem happens here is that windows.h was included
 *  with NOMB, NOUSER, NONLS defined.
 *  But I can't simply undefine these macros and include
 *  windows.h (or winuser.h and winnls.h) again.
 *  So...
 *
 *  Yes, this is ugly but I can't find any workaround yet...
 */

#if defined(NOUSER) || defined(NODESKTOP)

#define DESKTOP_READOBJECTS         0x0001L
#define DESKTOP_CREATEWINDOW        0x0002L
#define DESKTOP_CREATEMENU          0x0004L
#define DESKTOP_HOOKCONTROL         0x0008L
#define DESKTOP_JOURNALRECORD       0x0010L
#define DESKTOP_JOURNALPLAYBACK     0x0020L
#define DESKTOP_ENUMERATE           0x0040L
#define DESKTOP_WRITEOBJECTS        0x0080L
#define DESKTOP_SWITCHDESKTOP       0x0100L

WINUSERAPI
HDESK
WINAPI
OpenDesktopA(
    LPSTR lpszDesktop,
    DWORD dwFlags,
    BOOL fInherit,
    ACCESS_MASK dwDesiredAccess);
WINUSERAPI
HDESK
WINAPI
OpenDesktopW(
    LPWSTR lpszDesktop,
    DWORD dwFlags,
    BOOL fInherit,
    ACCESS_MASK dwDesiredAccess);
#ifdef UNICODE
#define OpenDesktop  OpenDesktopW
#else
#define OpenDesktop  OpenDesktopA
#endif /* !UNICODE */

WINUSERAPI
BOOL
WINAPI
SetThreadDesktop(
    HDESK hDesktop);

WINUSERAPI
BOOL
WINAPI
CloseDesktop(
    HDESK hDesktop);

WINUSERAPI
HDESK
WINAPI
GetThreadDesktop(
    DWORD dwThreadId);

#endif /* def NOUSER || def NODESKTOP */

#if defined(NOUSER) || defined(NOWINDOWSTATION)

#define WINSTA_ENUMDESKTOPS         0x0001L
#define WINSTA_READATTRIBUTES       0x0002L
#define WINSTA_ACCESSCLIPBOARD      0x0004L
#define WINSTA_CREATEDESKTOP        0x0008L
#define WINSTA_WRITEATTRIBUTES      0x0010L
#define WINSTA_ACCESSGLOBALATOMS    0x0020L
#define WINSTA_EXITWINDOWS          0x0040L
#define WINSTA_ENUMERATE            0x0100L
#define WINSTA_READSCREEN           0x0200L

WINUSERAPI
HWINSTA
WINAPI
OpenWindowStationA(
    LPSTR lpszWinSta,
    BOOL fInherit,
    ACCESS_MASK dwDesiredAccess);
WINUSERAPI
HWINSTA
WINAPI
OpenWindowStationW(
    LPWSTR lpszWinSta,
    BOOL fInherit,
    ACCESS_MASK dwDesiredAccess);
#ifdef UNICODE
#define OpenWindowStation  OpenWindowStationW
#else
#define OpenWindowStation  OpenWindowStationA
#endif /* !UNICODE */

WINUSERAPI
BOOL
WINAPI
CloseWindowStation(
    HWINSTA hWinSta);

WINUSERAPI
BOOL
WINAPI
SetProcessWindowStation(
    HWINSTA hWinSta);

WINUSERAPI
HWINSTA
WINAPI
GetProcessWindowStation(
    VOID);

#endif /* def NOUSER || def NOWINDOWSTATION */

#if defined(NOUSER) || defined(NOMB)

/* code taken from winuser.h */

#ifndef MB_OK
#define MB_OK 0x00000000L
#endif

WINUSERAPI
int
WINAPI
MessageBoxA(
    HWND hWnd ,
    LPCSTR lpText,
    LPCSTR lpCaption,
    UINT uType);
WINUSERAPI
int
WINAPI
MessageBoxW(
    HWND hWnd ,
    LPCWSTR lpText,
    LPCWSTR lpCaption,
    UINT uType);
#ifdef UNICODE
#define MessageBox  MessageBoxW
#else
#define MessageBox  MessageBoxA
#endif /* !UNICODE */

#endif /* def NOUSER || def NOMB */

/* code taken from winnls.h */

#endif /* ?def _WINDOWS_ */

#ifdef _MSC_VER
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")
#endif

#ifndef InterlockedBitTestAndSet

/*
 *  A rough (very rough) check if Windows Vista SDK is in use.
 *  If so, not define our own and hopefully to pick up the one
 *  from Windows Vista SDK.
 */
#ifndef _INC_SDKDDKVER
#if defined(_MSC_VER) && (!defined(_MSC_FULL_VER) || _MSC_FULL_VER < 14000101)

#ifndef FORCEINLINE
#if (_MSC_VER >= 1200)
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE __inline
#endif
#endif

/*
 *  Copied from Windows Vista SDK header winnt.h
 */

#if defined(_M_IX86)

#pragma warning(push)
#pragma warning(disable:4035 4793)
FORCEINLINE
BOOLEAN
__dbg_InterlockedBitTestAndSet (
    IN LONG volatile *Base,
    IN LONG Bit
    )
{
    __asm {
           mov eax, Bit
           mov ecx, Base
           lock bts [ecx], eax
           setc al
    };
}
#pragma warning(pop)

#define __dbg_InterlockedBitTestAndSet __dbg_InterlockedBitTestAndSet

#endif /* def _M_IX86 */

#elif defined(__GNUC__)

static __inline__ __attribute__((always_inline))
unsigned char
__dbg_InterlockedBitTestAndSet
(
   long volatile *base,
   const long bit
)
{
   unsigned char retval;
   __asm__(
      "lock btsl %[bit], %[base]" "\n\t"
      "setc %b[retval]"
      : [retval] "=q" (retval), [base] "+m" (*base)
      : [bit] "Ir" (bit)
      : "memory");
   return retval;
}

#define __dbg_InterlockedBitTestAndSet __dbg_InterlockedBitTestAndSet

#endif /* ?def _MSC_VER || ?def __GNUC__ */
#endif /* !def _INC_SDKDDKVER */

#endif /* !def InterlockedBitTestAndSet */

#ifndef __dbg_InterlockedBitTestAndSet
#define __dbg_InterlockedBitTestAndSet InterlockedBitTestAndSet
#endif

#define __DBG_WINSTA_ALL_ACCESS__ \
   (WINSTA_ACCESSCLIPBOARD | WINSTA_ACCESSGLOBALATOMS | \
      WINSTA_CREATEDESKTOP | WINSTA_ENUMDESKTOPS | \
      WINSTA_ENUMERATE | WINSTA_EXITWINDOWS | \
      WINSTA_READATTRIBUTES | WINSTA_READSCREEN | \
      WINSTA_WRITEATTRIBUTES)

#define __DBG_DESKTOP_ALL_ACCESS__ \
   (DESKTOP_CREATEMENU | DESKTOP_CREATEWINDOW | \
      DESKTOP_ENUMERATE | DESKTOP_HOOKCONTROL | \
      DESKTOP_JOURNALPLAYBACK | DESKTOP_JOURNALRECORD | \
      DESKTOP_READOBJECTS | DESKTOP_SWITCHDESKTOP | \
      DESKTOP_WRITEOBJECTS)

#endif /* __DEBUG_WIN32__ */

#if defined(USE_DEBUG_DIALOG) || defined(USE_DEBUG_LOG)
#include "dbgproc.h"
#endif

#ifndef __DBG_INLINE__
#undef __DBG_HAVE_NO_INLINE__
#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)
#define __DBG_INLINE__ inline
#elif defined(_MSC_VER)
#define __DBG_INLINE__ __inline
#elif defined(__GNUC__) || defined(__clang__)
#define __DBG_INLINE__ __inline__
#else
#define __DBG_INLINE__
#define __DBG_HAVE_NO_INLINE__
#endif
#endif /* !def __DBG_INLINE__ */

#ifndef __DBG_EXTERN_C__
#if defined(__cplusplus)
#define __DBG_EXTERN_C__ extern "C"
#else
#define __DBG_EXTERN_C__
#endif
#endif /* !def __DBG_EXTERN_C__ */

#undef DEBUG_HAVE_SNPRINTF
#undef DEBUG_HAVE_VSNPRINTF
#undef DEBUG_HAVE__SNPRINTF
#undef DEBUG_HAVE__VSNPRINTF
#undef DEBUG_HAVE__SNPRINTF_S
#undef DEBUG_HAVE__VSNPRINTF_S

#undef DEBUG_SNPRINTF_DO_NULL_TERMINATION
#undef DEBUG_SNPRINTF_OVERFLOW_RETURN_REQUIRED_LEN
#undef DEBUG_SNPRINTF_OVERFLOW_RETURN_NEGATIVE_VALUE
#undef DEBUG_SNPRINTF_OVERFLOW_RETURN_BUFFER_LEN
#undef DEBUG_SNPRINTF_OVERFLOW_RETURN_STRING_LEN

/*
 *  Note for iSeries:
 *    When compiling C++, only __OS400__ and __IBMCPP__ are defined.
 *    When compiling C, only __OS400__, __ILEC400__, __IBMC__ and
 *    __ILEC400_TGTVRM__ are defined and normally __IBMC__ is equal
 *    to __ILEC400_TGTVRM__.
 */

#if defined(__WATCOMC__) \
   || (defined(__OS400__) \
         && (  /* C for V5R1 or before */ \
               (!defined(__IBMCPP__) \
                  && (  (defined(__ILEC400__) && defined(__ILEC400_TGTVRM__) && (__ILEC400_TGTVRM__ < 520)) \
                     || (defined(__IBMC__) && (__IBMC__ < 520)) \
                     ) \
               ) \
            || /* C++ for V5R1 or before */ \
               (defined(__IBMCPP__) && (__IBMCPP__ < 600)) \
            ) \
      )
/* Ancient platforms without snprintf/vsnprintf() */
#elif defined(_MSC_VER) || defined(X_MSVC)
#if defined(_MSC_VER) && _MSC_VER >= 1400
#define DEBUG_HAVE__SNPRINTF_S
#define DEBUG_HAVE__VSNPRINTF_S
#else
#define DEBUG_HAVE__SNPRINTF
#define DEBUG_HAVE__VSNPRINTF
#endif
#define DEBUG_SNPRINTF_OVERFLOW_RETURN_NEGATIVE_VALUE
#else
/* Default to assume snprintf/vsnprintf() exist */
#define DEBUG_HAVE_SNPRINTF
#define DEBUG_HAVE_VSNPRINTF
/* Most of the snprintf/vsnprintf() implementations do *DO* null termination */
/* To be reset if that's not the case */
#define DEBUG_SNPRINTF_DO_NULL_TERMINATION
#ifdef __GNUC__
#define DEBUG_SNPRINTF_OVERFLOW_RETURN_REQUIRED_LEN
#elif defined(hpux) || defined(__hpux) || defined(__hpux__)
#define DEBUG_SNPRINTF_OVERFLOW_RETURN_NEGATIVE_VALUE
#elif defined(_AIX)
#define DEBUG_SNPRINTF_OVERFLOW_RETURN_BUFFER_LEN
#else
#define DEBUG_SNPRINTF_OVERFLOW_RETURN_STRING_LEN
#endif
#endif

/* Do not override if both have already been defined */
#if !defined(DEBUG_SNPRINTF) || !defined(DEBUG_SNPRINTF_BUF)
#undef DEBUG_SNPRINTF
#undef DEBUG_SNPRINTF_BUF
#if defined(DEBUG_HAVE__SNPRINTF_S)
#define DEBUG_SNPRINTF _snprintf_s
#define DEBUG_SNPRINTF_BUF(s, n) (s), (n), _TRUNCATE
#elif defined(DEBUG_HAVE__SNPRINTF)
#define DEBUG_SNPRINTF _snprintf
#define DEBUG_SNPRINTF_BUF(s, n) (s), (n)
#elif defined(DEBUG_HAVE_SNPRINTF)
#define DEBUG_SNPRINTF snprintf
#define DEBUG_SNPRINTF_BUF(s, n) (s), (n)
#else
#define DEBUG_SNPRINTF sprintf
#define DEBUG_SNPRINTF_BUF(s, n) (s)
#endif
#endif

/* Do not override if both have already been defined */
#if !defined(DEBUG_VSNPRINTF) || !defined(DEBUG_VSNPRINTF_BUF)
#undef DEBUG_VSNPRINTF
#undef DEBUG_VSNPRINTF_BUF
#if defined(DEBUG_HAVE__VSNPRINTF_S)
#define DEBUG_VSNPRINTF _vsnprintf_s
#define DEBUG_VSNPRINTF_BUF(s, n) (s), (n), _TRUNCATE
#elif defined(DEBUG_HAVE__VSNPRINTF)
#define DEBUG_VSNPRINTF _vsnprintf
#define DEBUG_VSNPRINTF_BUF(s, n) (s), (n)
#elif defined(DEBUG_HAVE_VSNPRINTF)
#define DEBUG_VSNPRINTF vsnprintf
#define DEBUG_VSNPRINTF_BUF(s, n) (s), (n)
#else
#define DEBUG_VSNPRINTF vsprintf
#define DEBUG_VSNPRINTF_BUF(s, n) (s)
#endif
#endif

#define DEBUG_SNPRINTF_CHECK(b, l, n) \
   (((n) < 0 || (size_t)(n) >= (size_t)(l)) ? (((b)[(l)-1] = '\0'), (void)0) : (void)0)
#define DEBUG_SNPRINTF_BUF_CHECK(b, n) DEBUG_SNPRINTF_CHECK((b), sizeof((b)), (n))

#ifdef __INCL_WXMEM_H__
#define __dbg_malloc(s)       wx_malloc(s)
#define __dbg_calloc(n, s)    wx_calloc(n, s)
#define __dbg_realloc(p, s)   wx_realloc(p, s)
#define __dbg_free(p)         wx_free(p)
#else
#define __dbg_malloc(s)       malloc(s)
#define __dbg_calloc(n, s)    calloc(n, s)
#define __dbg_realloc(p, s)   realloc(p, s)
#define __dbg_free(p)         free(p)
#endif

#ifndef __dbg_strcpy_s
#if defined(_MSC_VER) && _MSC_VER >= 1400
#define __dbg_strcpy_s(d, n, s) strcpy_s((d), (n), (s))
#else
#define __dbg_strcpy_s(d, n, s) strcpy((d), (s))
#endif
#endif

#ifndef __dbg_strncpy_s
#if defined(_MSC_VER) && _MSC_VER >= 1400
#define __dbg_strncpy_s(d, n, s, l) strncpy_s((d), (n), (s), (l))
#else
#define __dbg_strncpy_s(d, n, s, l) strncpy((d), (s), (l))
#endif
#endif

#undef __DBG_HAVE_GETENV_S
#if defined(_MSC_VER) && _MSC_VER >= 1400
#define __DBG_HAVE_GETENV_S
#endif

#if __DEBUG_WIN32__

typedef unsigned long __dbg_pid_t;

#define __dbg_GetCurrentProcessId() ((unsigned long)GetCurrentProcessId())
#define __dbg_GetCurrentThreadId()  ((unsigned long)GetCurrentThreadId())
#define DEBUG_HAVE_THREAD_ID 1

#define __DBG_PID_FMT   "%lu"
#define __DBG_PID_FMT_0 "%04lu"
#define __DBG_TID_FMT   "%#lx"
#define __DBG_TID_FMT_0 "%#06lx"

#if defined(_MSC_VER) && _MSC_VER >= 1400
#define __dbg_strcasecmp(a, b)      _stricmp((a), (b))
#define __dbg_strncasecmp(a, b, n)  _strnicmp((a), (b), (n))
#else
#define __dbg_strcasecmp(a, b)      stricmp((a), (b))
#define __dbg_strncasecmp(a, b, n)  strnicmp((a), (b), (n))
#endif

#elif __DEBUG_UNIX__

#if defined(__OS400__)

#include <qusec.h>
#include <qusrjobi.h>

typedef long __dbg_pid_t;

#ifdef __cplusplus
extern "C" {
#endif

static struct
{
#ifdef __DBG_USE_PTHREAD__
   pthread_once_t once;
#endif
   int inited;
   __dbg_pid_t jobid;
} __dbg_CurrentJob =
   {
#ifdef __DBG_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
#endif
      0,
      0
   };

#ifdef __DBG_USE_PTHREAD__
static void
__dbg_GetCurrentProcessId_once(void)
#else
static __dbg_pid_t
__dbg_GetCurrentProcessId(void)
#endif
{
   if (0 == __dbg_CurrentJob.inited)
   {
      Qwc_JOBI0100_t JobInfo;
      Qus_EC_t ErrBuffer;

      ErrBuffer.Bytes_Provided = sizeof(ErrBuffer);

      QUSRJOBI(
         &JobInfo, sizeof(JobInfo),
         "JOBI0100",
         "*                         ",
         "                 ",
         &ErrBuffer);

      if (ErrBuffer.Bytes_Available != 0)
      {
         __dbg_CurrentJob.inited = -1;
      }
      else
      {
         char szJobId[sizeof(JobInfo.Job_Number) + 1];

         __dbg_strncpy_s(szJobId, sizeof(szJobId), JobInfo.Job_Number, sizeof(JobInfo.Job_Number));
         szJobId[sizeof(szJobId) - 1] = '\0';

         __dbg_CurrentJob.jobid = (__dbg_pid_t)atol(szJobId);

         __dbg_CurrentJob.inited = 1;
      }
   }

#ifndef __DBG_USE_PTHREAD__
   return __dbg_CurrentJob.jobid;
#endif
}

#ifdef __DBG_USE_PTHREAD__
static __dbg_pid_t
__dbg_GetCurrentProcessId(void)
{
   pthread_once(&__dbg_CurrentJob.once, __dbg_GetCurrentProcessId_once);
   return __dbg_CurrentJob.jobid;
}
#endif

#define __dbg_GetCurrentThreadId() __dbg_GetCurrentProcessId()
#define DEBUG_HAVE_THREAD_ID 0

#define __DBG_PID_FMT   "%ld"
#define __DBG_PID_FMT_0 "%06ld"
#define __DBG_TID_FMT   __DBG_PID_FMT
#define __DBG_TID_FMT_0 __DBG_PID_FMT_0

static int
__dbg_strcasecmp
(
   const char *a,
   const char *b
)
{
   while (*a != '\0' && tolower(*a) == tolower(*b))
   {
      ++a; ++b;
   }
   /* I know, this is not exactly correct for EBCDIC machines */
   return tolower(*a) - tolower(*b);
}

static int
__dbg_strncasecmp
(
   const char *a,
   const char *b,
   size_t n
)
{
   while (n > 0 && *a != '\0' && tolower(*a) == tolower(*b))
   {
      ++a; ++b; --n;
   }
   /* I know, this is not exactly correct for EBCDIC machines */
   return (n == 0) ? 0 : (tolower(*a) - tolower(*b));
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#else /* !def __OS400__ */

typedef pid_t __dbg_pid_t;

#define __dbg_GetCurrentProcessId() getpid()
#if defined(linux) || defined(__linux) || defined(__linux__)
#define __dbg_GetCurrentThreadId()  ((pid_t)syscall(__NR_gettid))
#define DEBUG_HAVE_THREAD_ID 1
#else
#define __dbg_GetCurrentThreadId()  getpid()
#define DEBUG_HAVE_THREAD_ID 0
#endif

#if defined(__sun) && !defined(__LP64__)
#define __DBG_PID_FMT   "%ld"
#define __DBG_PID_FMT_0 "%05ld"
#else
#define __DBG_PID_FMT   "%d"
#define __DBG_PID_FMT_0 "%05d"
#endif
#define __DBG_TID_FMT   __DBG_PID_FMT
#define __DBG_TID_FMT_0 __DBG_PID_FMT_0

#define __dbg_strcasecmp(a, b)      strcasecmp((a), (b))
#define __dbg_strncasecmp(a, b, n)  strncasecmp((a), (b), (n))

#endif /* ?def __OS400__ */

#endif

#ifndef __DBG_DIRECTORY__
#if __DEBUG_WIN32__
#define __DBG_DIRECTORY__     "C:\\LANSAdbg"
#elif __DEBUG_UNIX__
#define __DBG_DIRECTORY__     "/tmp/lansadbg"
#endif
#endif

#ifndef __DBG_FILE__
#define __DBG_FILE__          "all"
#endif

#ifndef __DBG_CONFIG_FILE__
#define __DBG_CONFIG_FILE__   "debug.cfg"
#endif

#if __DEBUG_WIN32__

#ifndef __DBG_PATH_SEP__
#define __DBG_PATH_SEP__      '\\'
#endif

#ifndef __DBG_PATH_SEP2__
#define __DBG_PATH_SEP2__     '/'
#endif

#ifndef __DBG_DRIVE_SEP__
#define __DBG_DRIVE_SEP__     ':'
#endif

#ifndef __DBG_IS_PATH_SEP_ONLY__
#define __DBG_IS_PATH_SEP_ONLY__(c) \
   ((__DBG_PATH_SEP__ == (c)) || (__DBG_PATH_SEP2__ == (c)))
#endif

#ifndef __DBG_IS_DRIVE_SEP__
#define __DBG_IS_DRIVE_SEP__(c) \
   (__DBG_DRIVE_SEP__ == (c))
#endif

#ifndef __DBG_IS_PATH_SEP__
#define __DBG_IS_PATH_SEP__(c) \
   (__DBG_IS_PATH_SEP_ONLY__((c)) || __DBG_IS_DRIVE_SEP__((c)))
#endif

#ifndef __DBG_FILE_NAME_IS_CONSOLE__
#define __DBG_FILE_NAME_IS_CONSOLE__(fn) \
   (((fn)[0] == 'c' || (fn)[0] == 'C') \
      && ((fn)[1] == 'o' || (fn)[0] == 'O') \
      && ((fn)[2] == 'n' || (fn)[0] == 'N') \
      && __DBG_IS_DRIVE_SEP__((fn)[3]) \
      && '\0' == (fn)[4])
#endif

#elif __DEBUG_UNIX__

#ifndef __DBG_PATH_SEP__
#define __DBG_PATH_SEP__      '/'
#endif

#ifndef __DBG_IS_PATH_SEP_ONLY__
#define __DBG_IS_PATH_SEP_ONLY__(c) \
   (__DBG_PATH_SEP__ == (c))
#endif

#ifndef __DBG_IS_PATH_SEP__
#define __DBG_IS_PATH_SEP__(c) \
   (__DBG_IS_PATH_SEP_ONLY__((c)))
#endif

#endif

#ifndef __DBG_CAPTION_SIZE__
#define __DBG_CAPTION_SIZE__  (8 * 1024)
#endif

#ifndef __DBG_MESSAGE_SIZE__
#define __DBG_MESSAGE_SIZE__  (16 * 1024)
#endif

#ifndef __DBG_FILENAME_SIZE__
#if __DEBUG_WIN32__
#ifdef _MAX_PATH
#define __DBG_FILENAME_SIZE__ _MAX_PATH
#else
#define __DBG_FILENAME_SIZE__ 1024
#endif
#elif __DEBUG_UNIX__
#define __DBG_FILENAME_SIZE__ PATH_MAX
#endif
#endif

#ifndef __FUNCNAME__
#define __FUNCNAME__(funcname) \
   static const char __FUNC__[] __DBG_UNUSED__ = funcname
#endif

#ifndef __DBGARGS__
#define __DBGARGS__  __FILE__, __LINE__, __FUNC__
#endif

#ifndef __DBG_ASSERT__
#ifdef __DEBUG_USE_ASSERT__
#define __DBG_ASSERT__(a) assert(a)
#else
#define __DBG_ASSERT__(a)
#endif
#endif

#define __DBG_LOG_ENDLINE_DOS__      "\r\n"
#define __DBG_LOG_ENDLINE_DOS_SZ__   2

#if defined(__OS400__) && !defined(__IFS_IO__)
#define __DBG_LOG_ENDLINE_BIN__      "\x25" /* EBCDIC '\n' */
#else
#define __DBG_LOG_ENDLINE_BIN__      "\n"
#endif
#define __DBG_LOG_ENDLINE_BIN_SZ__   1

#undef __DBG_LOG_ENDLINE__
#undef __DBG_LOG_ENDLINE_SZ__
#undef __DBG_DOSFMT__
#if __DEBUG_WIN32__ && defined(DEBUG_LOG_DOSTEXT_FORMAT)
#define __DBG_LOG_ENDLINE__      __DBG_LOG_ENDLINE_DOS__
#define __DBG_LOG_ENDLINE_SZ__   __DBG_LOG_ENDLINE_DOS_SZ__
#define __DBG_DOSFMT__ 1
#else
#define __DBG_LOG_ENDLINE__      __DBG_LOG_ENDLINE_BIN__
#define __DBG_LOG_ENDLINE_SZ__   __DBG_LOG_ENDLINE_BIN_SZ__
#define __DBG_DOSFMT__ 0
#endif

#undef __DEBUG_WITH_WIN32_FILE__
#undef __DEBUG_WITH_POSIX_FILE__
#if __DEBUG_WIN32__
#define __DEBUG_WITH_WIN32_FILE__ 1
#define __DEBUG_WITH_POSIX_FILE__ 0
#elif __DEBUG_UNIX__
#define __DEBUG_WITH_WIN32_FILE__ 0
#define __DEBUG_WITH_POSIX_FILE__ 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  NOTE:
 *  All the following native file I/O abstraction are limited
 *  to handle file of size < 4GB.
 */

#if __DEBUG_WITH_WIN32_FILE__

typedef HANDLE DEBUG_FILE_HANDLE;

#define DEBUG_INVALID_FILE_HANDLE INVALID_HANDLE_VALUE
#define DEBUG_FILE_HANDLE_IS_VALID(fh) (DEBUG_INVALID_FILE_HANDLE != (fh))

__DBG_INLINE__
static DEBUG_FILE_HANDLE
__dbg_file_create_write_excl
(
   const char *filename
)
{
   DEBUG_FILE_HANDLE fh;

   fh = CreateFileA(filename, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                     CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
   __DBG_ASSERT__("__dbg_file_create_write_excl" && fh != DEBUG_INVALID_FILE_HANDLE);
   return fh;
}

__DBG_INLINE__
static DEBUG_FILE_HANDLE
__dbg_file_open_read
(
   const char *filename
)
{
   DEBUG_FILE_HANDLE fh;

   fh = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL,
                     OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
   __DBG_ASSERT__("__dbg_file_open_read" && fh != DEBUG_INVALID_FILE_HANDLE);
   return fh;
}

__DBG_INLINE__
static DEBUG_FILE_HANDLE
__dbg_file_open_append
(
   const char *filename
)
{
   DEBUG_FILE_HANDLE fh = DEBUG_INVALID_FILE_HANDLE;
   int i;

   for (i = 0; i < 100; ++i)
   {
      fh = CreateFileA(filename, GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,
                        OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
      if (DEBUG_FILE_HANDLE_IS_VALID(fh))
      {
         if (!__DBG_FILE_NAME_IS_CONSOLE__(filename)
               && SetFilePointer(fh, 0, NULL, FILE_END) == ((DWORD)-1))
         {
            __DBG_ASSERT__("__dbg_file_open_append" && "SetFilePointer(fh, 0, NULL, FILE_END) != ((DWORD)-1)" && FALSE);
            CloseHandle(fh);
            fh = DEBUG_INVALID_FILE_HANDLE;
         }
         break;
      }
      else
      {
         DWORD err = GetLastError();
#if 0
         fprintf(stderr, "[%d] LastError=%d\n", i, GetLastError());
#endif
         if (err != ERROR_SHARING_VIOLATION)
         {
            break;
         }
         Sleep(0);
      }
   }

   __DBG_ASSERT__("__dbg_file_open_append" && fh != DEBUG_INVALID_FILE_HANDLE);
   return fh;
}

__DBG_INLINE__
static int
__dbg_file_read
(
   DEBUG_FILE_HANDLE fh,
   void *buf,
   size_t count
)
{
   DWORD nRead = 0;
   if (!ReadFile(fh, buf, (DWORD)count, &nRead, NULL))
   {
      /* DWORD err = GetLastError(); */
      __DBG_ASSERT__("!ReadFile(fh, buf, (DWORD)count, &nRead, NULL)" && FALSE);
      return -1;
   }
   return (int)nRead;
}

__DBG_INLINE__
static int
__dbg_file_write
(
   DEBUG_FILE_HANDLE fh,
   const void *buf,
   size_t count
)
{
   DWORD nWrite = 0;
   if (!WriteFile(fh, buf, (DWORD)count, &nWrite, NULL))
   {
      /* DWORD err = GetLastError(); */
      __DBG_ASSERT__("!WriteFile(fh, buf, (DWORD)count, &nWrite, NULL)" && FALSE);
      return -1;
   }
   return (int)nWrite;
}

__DBG_INLINE__
static int
__dbg_file_close
(
   DEBUG_FILE_HANDLE fh
)
{
   return CloseHandle(fh) ? 0 : -1;
}

__DBG_INLINE__
static size_t
__dbg_file_get_size
(
   DEBUG_FILE_HANDLE fh
)
{
   DWORD lo, hi = 0;
   lo = GetFileSize(fh, &hi);
   if (0 == lo && 0 != hi) lo = 0xffffffff;
   return lo;
}

__DBG_INLINE__
static size_t
__dbg_file_seek_end
(
   DEBUG_FILE_HANDLE fh
)
{
   return SetFilePointer(fh, 0, NULL, FILE_END);
}

#if defined(USE_DEBUG_DIALOG) || defined(USE_DEBUG_LOG)

__DBG_INLINE__
static int
__dbg_file_lock
(
   DEBUG_FILE_HANDLE fh,
   size_t offset
)
{
   OVERLAPPED ov;
   int rc = -1;
   ov.Internal = 0;
   ov.InternalHigh = 0;
   ov.Offset = (DWORD)offset;
   ov.OffsetHigh = 0;
   ov.hEvent = 0;
   /*
    *  This also works within threads of the same process.
    */
   if (LockFileEx(fh, LOCKFILE_EXCLUSIVE_LOCK, 0, ((DWORD)-1), ((DWORD)-1), &ov))
   {
      rc = 0;
   }
   __DBG_ASSERT__("__dbg_file_lock" && rc == 0);
   return rc;
}

__DBG_INLINE__
static int
__dbg_file_unlock
(
   DEBUG_FILE_HANDLE fh,
   size_t offset
)
{
   OVERLAPPED ov;
   int rc = -1;
   ov.Internal = 0;
   ov.InternalHigh = 0;
   ov.Offset = (DWORD)offset;
   ov.OffsetHigh = 0;
   ov.hEvent = 0;
   /*
    *  This also works within threads of the same process.
    */
   if (UnlockFileEx(fh, 0, ((DWORD)-1), ((DWORD)-1), &ov))
   {
      rc = 0;
   }
   __DBG_ASSERT__("__dbg_file_unlock" && rc == 0);
   return rc;
}

#endif /* def USE_DEBUG_DIALOG || def USE_DEBUG_LOG */

#endif /* __DEBUG_WITH_WIN32_FILE__ */

#if __DEBUG_WITH_POSIX_FILE__

#if defined(O_CREAT)
#define __DBG_O_CREAT O_CREAT
#elif defined(_O_CREAT)
#define __DBG_O_CREAT _O_CREAT
#endif
#if defined(O_EXCL)
#define __DBG_O_EXCL O_EXCL
#elif defined(_O_EXCL)
#define __DBG_O_EXCL _O_EXCL
#endif
#if defined(O_APPEND)
#define __DBG_O_APPEND O_APPEND
#elif defined(_O_APPEND)
#define __DBG_O_APPEND _O_APPEND
#endif
#if defined(O_WRONLY)
#define __DBG_O_WRONLY O_WRONLY
#elif defined(_O_WRONLY)
#define __DBG_O_WRONLY _O_WRONLY
#endif
#if defined(O_RDONLY)
#define __DBG_O_RDONLY O_RDONLY
#elif defined(_O_RDONLY)
#define __DBG_O_RDONLY _O_RDONLY
#endif
#if defined(O_RDWR)
#define __DBG_O_RDWR O_RDWR
#elif defined(_O_RDWR)
#define __DBG_O_RDWR _O_RDWR
#endif
#if defined(O_BINARY)
#define __DBG_O_BINARY O_BINARY
#elif defined(_O_BINARY)
#define __DBG_O_BINARY _O_BINARY
#else
#define __DBG_O_BINARY 0
#endif

#if defined(S_IRUSR)
#define __DBG_S_IRUSR S_IRUSR
#elif defined(_S_IRUSR)
#define __DBG_S_IRUSR _S_IRUSR
#endif
#if defined(S_IWUSR)
#define __DBG_S_IWUSR S_IWUSR
#elif defined(_S_IWUSR)
#define __DBG_S_IWUSR _S_IWUSR
#endif
#if defined(S_IRGRP)
#define __DBG_S_IRGRP S_IRGRP
#elif defined(_S_IRGRP)
#define __DBG_S_IRGRP _S_IRGRP
#endif
#if defined(S_IWGRP)
#define __DBG_S_IWGRP S_IWGRP
#elif defined(_S_IWGRP)
#define __DBG_S_IWGRP _S_IWGRP
#endif

#ifndef __DBG_FILE_MODE
#define __DBG_FILE_MODE (__DBG_S_IRUSR|__DBG_S_IWUSR|__DBG_S_IRGRP|__DBG_S_IWGRP)
#endif

#ifdef DEBUG_WITH_PTHREAD_LOCK

/*
 *  To support file locking within threads of the
 *  same process.
 */

/* TODO: Not that simple!!! */

#else /* !def DEBUG_WITH_PTHREAD_LOCK */

/*
 *  In this case, file locking does not work within
 *  threads of the same process.
 */

typedef int DEBUG_FILE_HANDLE;
#define DEBUG_INVALID_FILE_HANDLE (-1)
#define DEBUG_FILE_HANDLE_IS_VALID(fh) (DEBUG_INVALID_FILE_HANDLE != (fh))

#define __dbg_file_create_write_excl(filename)  open((filename), (__DBG_O_WRONLY|__DBG_O_CREAT|__DBG_O_EXCL|__DBG_O_BINARY), (__DBG_FILE_MODE))
#define __dbg_file_open_read(filename)          open((filename), (__DBG_O_RDONLY|__DBG_O_BINARY))
#define __dbg_file_open_append(filename)        open((filename), (__DBG_O_WRONLY|__DBG_O_CREAT|__DBG_O_APPEND|__DBG_O_BINARY), (__DBG_FILE_MODE))
#define __dbg_file_read(fh, buf, count)         read((fh), (buf), (count))
#define __dbg_file_write(fh, buf, count)        write((fh), (buf), (count))
#define __dbg_file_close(fh)                    close((fh))
#define __dbg_file_seek_end(fh)                 lseek((fh), 0, SEEK_END)

#endif /* ?def DEBUG_WITH_PTHREAD_LOCK */

__DBG_INLINE__
static size_t
__dbg_file_get_size
(
   DEBUG_FILE_HANDLE fh
)
{
   struct stat st;

   if (fstat(fh, &st) == 0)
      return st.st_size;
   return 0;
}

#if defined(USE_DEBUG_DIALOG) || defined(USE_DEBUG_LOG)

__DBG_INLINE__
static int
__dbg_file_lock
(
   DEBUG_FILE_HANDLE fh,
   size_t offset
)
{
#if __DEBUG_UNIX__ && !defined(DEBUG_LOG_NO_LOCKING)
   /*
    *  WARNING:
    *  Be very aware that on Solaris (and may be other Unices)
    *  this may impose a very long delay if the file being
    *  locked is on a NFS mount. On Solaris, the delay can be
    *  up to 60 seconds.
    */
   struct flock lck;
   int rc;
   lck.l_type = F_WRLCK;
   lck.l_whence = SEEK_SET;
   lck.l_start = offset;
   lck.l_len = 0;
   lck.l_pid = 0;
   /*
    *  This does not work within threads (at least in Linux)
    *  of the same process.
    */
   do {
      rc = fcntl(fh, F_SETLKW, &lck);
   } while (rc == -1 && errno == EINTR);
   return rc;
#else
   return 0;
#endif
}

__DBG_INLINE__
static int
__dbg_file_unlock
(
   DEBUG_FILE_HANDLE fh,
   size_t offset
)
{
#if __DEBUG_UNIX__ && !defined(DEBUG_LOG_NO_LOCKING)
   struct flock lck;
   int rc;
   lck.l_type = F_UNLCK;
   lck.l_whence = SEEK_SET;
   lck.l_start = offset;
   lck.l_len = 0;
   lck.l_pid = 0;
   /*
    *  This does not work within threads (at least in Linux)
    *  of the same process.
    */
   do {
      rc = fcntl(fh, F_SETLKW, &lck);
   } while (rc == -1 && errno == EINTR);
   return rc;
#else
   return 0;
#endif
}

#endif /* def USE_DEBUG_DIALOG || def USE_DEBUG_LOG */

#endif /* __DEBUG_WITH_POSIX_FILE__ */

#if 0
/*
 *  NOTE:
 *  This one does not work very well on Windows
 *  so not really used.
 */
__DBG_INLINE__
static int
__dbg_file_lock_fromend
(
   DEBUG_FILE_HANDLE fh,
   size_t *pendpos
)
{
   size_t endpos = __dbg_file_seek_end(fh);
   if (NULL != pendpos) *pendpos = endpos;
   return __dbg_file_lock(fh, endpos);
}
#endif

#if 0
__DBG_INLINE__
static int
__dbg_file_lock_wholefile
(
   DEBUG_FILE_HANDLE fh
)
{
   return __dbg_file_lock(fh, 0);
}
#else
#define __dbg_file_lock_wholefile(fh) __dbg_file_lock((fh), 0)
#endif

#if 0
__DBG_INLINE__
static int
__dbg_file_unlock_wholefile
(
   DEBUG_FILE_HANDLE fh
)
{
   return __dbg_file_unlock(fh, 0);
}
#else
#define __dbg_file_unlock_wholefile(fh) __dbg_file_unlock((fh), 0)
#endif

#if defined(USE_DEBUG_DIALOG) || defined(USE_DEBUG_LOG)

#define __dbg_file_write_endline(fh, dosfmt) \
   __dbg_file_write((fh), \
      (dosfmt) ? __DBG_LOG_ENDLINE_DOS__ : __DBG_LOG_ENDLINE_BIN__, \
      (dosfmt) ? __DBG_LOG_ENDLINE_DOS_SZ__ : __DBG_LOG_ENDLINE_BIN_SZ__)

static char *
__dbg_file_read_wholefile
(
   const char *filename,
   const char **ptextend,
   size_t *ptextsz
)
{
#ifdef WX_DEBUG_WXMEM
   __FUNCNAME__("__dbg_file_read_wholefile");
#endif
   DEBUG_FILE_HANDLE fh;
   char *text = NULL;

   if (NULL != ptextend) *ptextend = NULL;
   if (NULL != ptextsz) *ptextsz = 0;

   fh = __dbg_file_open_read(filename);
   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      size_t fsz = __dbg_file_get_size(fh);
      text = (char *)__dbg_malloc(fsz + 1);
      if (NULL != text)
      {
         int n = __dbg_file_read(fh, text, fsz);
         if (n < 0) n = 0;
         if ((size_t)n > fsz) n = (int)fsz;
         text[n] = '\0';
         if (NULL != ptextend) *ptextend = text + n;
         if (NULL != ptextsz) *ptextsz = n;
      }
      __dbg_file_close(fh);
   }

   return text;
}

__DBG_INLINE__
static int
__dbg_file_exists
(
   const char *file
)
{
#if __DEBUG_WIN32__
   HFILE hFile;
   OFSTRUCT ofs = { 0 };
   hFile = OpenFile(file, &ofs, OF_EXIST);
   return hFile != HFILE_ERROR;
#elif __DEBUG_UNIX__
   return access(file, F_OK) == 0;
#endif
}

/*
 *  NOTE: All '\r' and '\n' in text will be changed to '\0'.
 */
static char *
__dbg_buffer_getline
(
   char *textcur,
   const char *textend,
   char **ptextnext
)
{
   if (textcur < textend)
   {
      char *cp;
      size_t pos = strcspn(textcur, "\r\n");
      if (textcur[pos] == '\r' && textcur[pos+1] == '\n') textcur[pos+1] = '\0';
      textcur[pos] = '\0';
      cp = textcur + pos;
      while (cp < textend && '\0' == *cp)
         ++cp;
      *ptextnext = cp;
      return textcur;
   }
   else
   {
      *ptextnext = NULL;
      return NULL;
   }
}

/*
 *  NOTE: '\r' will be converted to '\n' unless it is following by '\n'.
 */
static int
__dbg_file_write_text
(
   DEBUG_FILE_HANDLE fh,
   int dosfmt,
   const char *text
)
{
   int writecount = 0;
   const char *cp = text;

   while ('\0' != *cp) {
      size_t pos = strcspn(cp, "\r\n");
      int rc = __dbg_file_write(fh, cp, pos);
      if (rc > 0) writecount += rc;
      cp += pos;
      if ('\r' == *cp || '\n' == *cp)
      {
         rc = __dbg_file_write_endline(fh, dosfmt);
         if (rc > 0) writecount += rc;
         if ('\r' == *cp && '\n' == *(cp+1)) cp += 2;
         else ++cp;
      }
   }
   return writecount;
}

#endif /* def USE_DEBUG_DIALOG || def USE_DEBUG_LOG */

#undef __DEBUG_HAVE_TIMER__
#define __DEBUG_HAVE_TIMER__ 0

#ifdef USE_DEBUG_TIMER

#ifndef __DEBUG_TIMER_DEFINED__
#define __DEBUG_TIMER_DEFINED__

#ifndef DEBUG_LOG_TIMING_PRECISION
#define DEBUG_LOG_TIMING_PRECISION 4
#endif

#undef __DBG_LOG_TIMING_INCL_DELTA__
#ifdef DEBUG_LOG_TIMING_INCL_DELTA
#define __DBG_LOG_TIMING_INCL_DELTA__ 1
#else
#define __DBG_LOG_TIMING_INCL_DELTA__ 0
#endif

#if __DEBUG_WIN32__

#define __DBG_LI_CPY(li, lisrc) \
   memcpy(&(li), &(lisrc), sizeof(LARGE_INTEGER))

#define __DBG_LI_SUB(li, lisub) \
   ((li).QuadPart -= (lisub).QuadPart)

#ifdef __WATCOMC__
#define __DBG_LI2DBL(li) (((double)((li).HighPart) * 4294967296.0) \
                                 + (double)((li).LowPart))
#else
#define __DBG_LI2DBL(li) ((double)((li).QuadPart))
#endif

#define __DBG_LI2SEC(li) (__DBG_LI2DBL((li)) / (__dbg_timer.pglobal->m_dFreq))

struct __dbg_timer_global_t
{
   LARGE_INTEGER m_liFreq;
   LARGE_INTEGER m_liStart;
   LARGE_INTEGER m_liLast;
   double m_dFreq;
   int m_iDispPrec;
   int m_iInclDelta;
};

#define __DBG_TIMER_GLOBAL_SZ (sizeof(struct __dbg_timer_global_t))

static struct
{
   CRITICAL_SECTION lock;
   int inited;
   HANDLE hshm;
   int display_precision;
   int include_delta;
   struct __dbg_timer_global_t *pglobal;
} __dbg_timer =
   {
      { 0 },
      0,
      NULL,
      DEBUG_LOG_TIMING_PRECISION,
      __DBG_LOG_TIMING_INCL_DELTA__,
      NULL
   };

static void
__dbg_timer_lock_init(void)
{
   static long __initlock = 0;
   static int volatile __inited = -1;

   if (__dbg_InterlockedBitTestAndSet(&__initlock, 0) == 0)
   {
      InitializeCriticalSection(&__dbg_timer.lock);
      __inited = 1;
   }
   else
   {
      while (__inited < 0)
      {
         Sleep(0);
      }
   }
}

#define __dbg_timer_lock() \
   (__dbg_timer_lock_init(), EnterCriticalSection(&__dbg_timer.lock))
#define __dbg_timer_unlock() \
   LeaveCriticalSection(&__dbg_timer.lock)

static void debug_timer_terminate(void);

static void
__dbg_timer_terminate(void)
{
   if (NULL != __dbg_timer.pglobal)
   {
      UnmapViewOfFile(__dbg_timer.pglobal);
      __dbg_timer.pglobal = NULL;
   }
   if (NULL != __dbg_timer.hshm)
   {
      CloseHandle(__dbg_timer.hshm);
      __dbg_timer.hshm = NULL;
   }
}

static int
debug_timer_initialize(void)
{
   __dbg_timer_lock();

   if (0 == __dbg_timer.inited)
   {
      char shmname[128];

      __dbg_timer.inited = -1;

      DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(shmname, sizeof(shmname)),
         "__dbg_timer_" __DBG_PID_FMT,
         __dbg_GetCurrentProcessId());

      __dbg_timer.hshm =
         CreateFileMappingA(
            INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE | SEC_COMMIT,
            0, __DBG_TIMER_GLOBAL_SZ, shmname);
      if (NULL != __dbg_timer.hshm)
      {
         DWORD rcCreateMap = GetLastError();

         SetHandleInformation(__dbg_timer.hshm, HANDLE_FLAG_INHERIT, 0);

         __dbg_timer.pglobal =
            (struct __dbg_timer_global_t *)
               MapViewOfFile(__dbg_timer.hshm, FILE_MAP_WRITE, 0, 0, 0);
         if (NULL != __dbg_timer.pglobal)
         {
            if (rcCreateMap == ERROR_ALREADY_EXISTS)
            {
               __dbg_timer.inited = 1;
            }
            else
            {
               if (QueryPerformanceFrequency(&__dbg_timer.pglobal->m_liFreq)
                        && QueryPerformanceCounter(&__dbg_timer.pglobal->m_liStart))
               {
                  __dbg_timer.pglobal->m_dFreq =
                     __DBG_LI2DBL(__dbg_timer.pglobal->m_liFreq);
                  if (__dbg_timer.pglobal->m_dFreq < 1.0)
                     __dbg_timer.pglobal->m_dFreq = 1.0;

                  __DBG_LI_CPY(__dbg_timer.pglobal->m_liLast, __dbg_timer.pglobal->m_liStart);
                  __dbg_timer.pglobal->m_iDispPrec = DEBUG_LOG_TIMING_PRECISION;
                  __dbg_timer.pglobal->m_iInclDelta = __DBG_LOG_TIMING_INCL_DELTA__;

                  __dbg_timer.inited = 1;
               }
            }
         }
      }

      if (__dbg_timer.inited > 0)
      {
         __dbg_timer.display_precision = __dbg_timer.pglobal->m_iDispPrec;
         __dbg_timer.include_delta = __dbg_timer.pglobal->m_iInclDelta;
         atexit(debug_timer_terminate);
      }
      else if (__dbg_timer.inited < 0)
      {
         __dbg_timer_terminate();
      }
   }

   __dbg_timer_unlock();

   return __dbg_timer.inited;
}

static void
debug_timer_terminate(void)
{
   __dbg_timer_lock();
   if (__dbg_timer.inited > 0)
   {
      __dbg_timer_terminate();
      __dbg_timer.inited = 0;
   }
   __dbg_timer_unlock();
}

__DBG_INLINE__
static double
debug_timer_current(void)
{
   double t = 0.0;

   if (debug_timer_initialize() > 0)
   {
      LARGE_INTEGER liCount;

      __dbg_timer_lock();
      if (QueryPerformanceCounter(&liCount))
      {
         t = __DBG_LI2SEC(liCount);
      }
      __dbg_timer_unlock();
   }

   return t;
}

__DBG_INLINE__
static double
debug_timer_elapsed(void)
{
   double t = 0.0;

   if (debug_timer_initialize() > 0)
   {
      LARGE_INTEGER liCount;

      __dbg_timer_lock();
      if (QueryPerformanceCounter(&liCount))
      {
         __DBG_LI_SUB(liCount, __dbg_timer.pglobal->m_liStart);
         t = __DBG_LI2SEC(liCount);
      }
      __dbg_timer_unlock();
   }

   return t;
}

__DBG_INLINE__
static double
debug_timer_elapsed_ex(double *pdelta)
{
   double d = 0.0;
   double t = 0.0;

   if (debug_timer_initialize() > 0)
   {
      LARGE_INTEGER liCount;

      __dbg_timer_lock();
      if (QueryPerformanceCounter(&liCount))
      {
         LARGE_INTEGER liOrg;
         LARGE_INTEGER liDelta;

         __DBG_LI_CPY(liOrg, liCount);
         __DBG_LI_CPY(liDelta, liCount);

         __DBG_LI_SUB(liCount, __dbg_timer.pglobal->m_liStart);
         __DBG_LI_SUB(liDelta, __dbg_timer.pglobal->m_liLast);
         __DBG_LI_CPY(__dbg_timer.pglobal->m_liLast, liOrg);

         d = __DBG_LI2SEC(liDelta);
         t = __DBG_LI2SEC(liCount);
      }
      __dbg_timer_unlock();
   }

   if (pdelta != NULL) *pdelta = d;
   return t;
}

#undef __DEBUG_HAVE_TIMER__
#define __DEBUG_HAVE_TIMER__ 1

#endif /* __DEBUG_WIN32__ */

#if __DEBUG_UNIX__

#define __DBG_TV_CPY(tv, tvsrc) \
   memcpy(&(tv), &(tvsrc), sizeof(struct timeval))

#define __DBG_TV_SUB(tv, tvsub) { \
   if ((tv).tv_usec < (tvsub).tv_usec) \
   { \
      (tv).tv_usec += 1000000; --(tv).tv_sec; \
   } \
   (tv).tv_sec -= (tvsub).tv_sec; \
   (tv).tv_usec -= (tvsub).tv_usec; \
}

#define __DBG_TV2DBL(tv) ((double)((tv).tv_sec) + ((double)((tv).tv_usec) / 1000000.0))

__DBG_INLINE__
static double
debug_timer_current(void)
{
   struct timeval tv;

   if (gettimeofday(&tv, NULL) == 0)
   {
      return __DBG_TV2DBL(tv);
   }

   return (double)time(NULL);
}

#undef __DEBUG_HAVE_SHM__
#ifndef DEBUG_DISABLE_SHM
#if defined(__FreeBSD__)
#define __DEBUG_HAVE_SHM__ 1
#elif defined(sun) || defined(__sun) || defined(__sun__) \
         || defined(linux) || defined(__linux) || defined(__linux__)
/*
 *  Actually Solaris and Linux do have shared memory, but that
 *  requires linking to librt.so and hence not really convenient.
 */
 #ifdef DEBUG_ENABLE_SHM
 #define __DEBUG_HAVE_SHM__ 1
 #else
 #define __DEBUG_HAVE_SHM__ 0
 #endif
#elif defined(hpux) || defined(__hpux) || defined(__hpux__)
/*
 *  Unfortunately on HP/UX, the same file cannot be mmap'ed for
 *  multiple times within the same process, so HP/UX does not
 *  support what we wanted to do here!
 */
#define __DEBUG_HAVE_SHM__ 0
#endif
#endif /* def DEBUG_DISABLE_SHM */

#ifndef __DEBUG_HAVE_SHM__
#define __DEBUG_HAVE_SHM__ 0
#endif

#if __DEBUG_HAVE_SHM__

#if defined(linux) || defined(__linux) || defined(__linux__) \
      || defined(sun) || defined(__sun) || defined(__sun__)
#define __DBG_SHM_FILENAME "/__dbg_timer_" __DBG_PID_FMT
#elif defined(__FreeBSD__) \
      || defined(hpux) || defined(__hpux) || defined(__hpux__)
#define __DBG_SHM_FILENAME "/tmp/__dbg_timer_" __DBG_PID_FMT
#endif

struct __dbg_timer_global_t
{
   int m_nUsage;
   struct timeval m_tvStart;
   struct timeval m_tvLast;
   int m_iDispPrec;
   int m_iInclDelta;
};

#define __DBG_TIMER_GLOBAL_SZ (sizeof(struct __dbg_timer_global_t))

static struct
{
#ifdef __DBG_USE_PTHREAD__
   pthread_once_t once;
   pthread_mutex_t lock;
#endif
   int inited;
   int shm_fd;
   char shm_filename[__DBG_FILENAME_SIZE__];
   int display_precision;
   int include_delta;
   struct __dbg_timer_global_t *pglobal;
} __dbg_timer =
   {
#ifdef __DBG_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
      PTHREAD_MUTEX_INITIALIZER,
#endif
      0,
      -1,
      "",
      DEBUG_LOG_TIMING_PRECISION,
      __DBG_LOG_TIMING_INCL_DELTA__,
      NULL
   };

#ifdef __DBG_USE_PTHREAD__

static void
__dbg_timer_lock_init_once(void)
{
   pthread_mutexattr_t attr;
   if (pthread_mutexattr_init(&attr) == 0)
   {
      if (pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE) == 0)
      {
         pthread_mutex_init(&__dbg_timer.lock, &attr);
      }
   }
}

#define __dbg_timer_lock_init() \
   ((void)pthread_once(&__dbg_timer.once, __dbg_timer_lock_init_once))

#define __dbg_timer_lock() \
   (__dbg_timer_lock_init(), (void)pthread_mutex_lock(&__dbg_timer.lock))
#define __dbg_timer_unlock() \
   ((void)pthread_mutex_unlock(&__dbg_timer.lock))

#else /* !__DBG_USE_PTHREAD__ */

#define __dbg_timer_lock()
#define __dbg_timer_unlock()

#endif /* ?__DBG_USE_PTHREAD__ */

static void debug_timer_terminate(void);

static void
__dbg_timer_terminate(int forced_unlink_shm)
{
   int unlink_shm = 0;

   if (NULL != __dbg_timer.pglobal)
   {
      unlink_shm = (--__dbg_timer.pglobal->m_nUsage <= 0);
      munmap(__dbg_timer.pglobal, __DBG_TIMER_GLOBAL_SZ);
      __dbg_timer.pglobal = NULL;
   }
   if (__dbg_timer.shm_fd >= 0)
   {
      close(__dbg_timer.shm_fd);
      __dbg_timer.shm_fd = -1;
   }
   if ((unlink_shm || forced_unlink_shm) && '\0' != __dbg_timer.shm_filename[0])
   {
      shm_unlink(__dbg_timer.shm_filename);
   }
   __dbg_timer.shm_filename[0] = '\0';
}

static int
debug_timer_initialize(void)
{
   __dbg_timer_lock();

   if (0 == __dbg_timer.inited)
   {
      int created_shm = 0;

      __dbg_timer.inited = -1;

      DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(__dbg_timer.shm_filename, sizeof(__dbg_timer.shm_filename)),
         __DBG_SHM_FILENAME,
         __dbg_GetCurrentProcessId());

      __dbg_timer.shm_fd = shm_open(__dbg_timer.shm_filename,
                                    __DBG_O_CREAT|__DBG_O_RDWR|__DBG_O_EXCL,
                                    __DBG_FILE_MODE);
      if (__dbg_timer.shm_fd < 0)
      {
         if (errno == EEXIST)
         {
            __dbg_timer.shm_fd = shm_open(__dbg_timer.shm_filename,
                                          __DBG_O_RDWR,
                                          __DBG_FILE_MODE);
         }
      }
      else
      {
         created_shm = 1;
         if (ftruncate(__dbg_timer.shm_fd, __DBG_TIMER_GLOBAL_SZ) != 0)
         {
            close(__dbg_timer.shm_fd);
            __dbg_timer.shm_fd = -1;
         }
      }
      if (__dbg_timer.shm_fd >= 0)
      {
         __dbg_timer.pglobal =
            (struct __dbg_timer_global_t *)
               mmap(0, __DBG_TIMER_GLOBAL_SZ,
                     PROT_READ|PROT_WRITE, MAP_SHARED,
                     __dbg_timer.shm_fd, 0);
         if (MAP_FAILED != __dbg_timer.pglobal)
         {
            if (!created_shm)
            {
               ++__dbg_timer.pglobal->m_nUsage;
               __dbg_timer.inited = 1;
            }
            else
            {
               __dbg_timer.pglobal->m_nUsage = 1;
               if (gettimeofday(&__dbg_timer.pglobal->m_tvStart, NULL) == 0)
               {
                  __DBG_TV_CPY(__dbg_timer.pglobal->m_tvLast, __dbg_timer.pglobal->m_tvStart);
                  __dbg_timer.pglobal->m_iDispPrec = DEBUG_LOG_TIMING_PRECISION;
                  __dbg_timer.pglobal->m_iInclDelta = __DBG_LOG_TIMING_INCL_DELTA__;

                  __dbg_timer.inited = 1;
               }
            }
         }
         else
         {
            __dbg_timer.pglobal = NULL;
         }
      }

      if (__dbg_timer.inited > 0)
      {
         __dbg_timer.display_precision = __dbg_timer.pglobal->m_iDispPrec;
         __dbg_timer.include_delta = __dbg_timer.pglobal->m_iInclDelta;
         atexit(debug_timer_terminate);
      }
      else if (__dbg_timer.inited < 0)
      {
         __dbg_timer_terminate(created_shm);
      }
   }

   __dbg_timer_unlock();

   return __dbg_timer.inited;
}

static void
debug_timer_terminate(void)
{
   __dbg_timer_lock();
   if (__dbg_timer.inited > 0)
   {
      __dbg_timer_terminate(0);
      __dbg_timer.inited = 0;
   }
   __dbg_timer_unlock();
}

__DBG_INLINE__
static double
debug_timer_elapsed(void)
{
   double t = 0.0;

   if (debug_timer_initialize() > 0)
   {
      struct timeval tv;

      __dbg_timer_lock();
      if (gettimeofday(&tv, NULL) == 0)
      {
         __DBG_TV_SUB(tv, __dbg_timer.pglobal->m_tvStart);
         t = __DBG_TV2DBL(tv);
      }
      __dbg_timer_unlock();
   }

   return t;
}

__DBG_INLINE__
static double
debug_timer_elapsed_ex(double *pdelta)
{
   double d = 0.0;
   double t = 0.0;

   if (debug_timer_initialize() > 0)
   {
      struct timeval tv;

      __dbg_timer_lock();
      if (gettimeofday(&tv, NULL) == 0)
      {
         struct timeval tvOrg;
         struct timeval tvDelta;

         __DBG_TV_CPY(tvOrg, tv);
         __DBG_TV_CPY(tvDelta, tv);

         __DBG_TV_SUB(tv, __dbg_timer.pglobal->m_tvStart);
         __DBG_TV_SUB(tvDelta, __dbg_timer.pglobal->m_tvLast);
         __DBG_TV_CPY(__dbg_timer.pglobal->m_tvLast, tvOrg);

         d = __DBG_TV2DBL(tvDelta);
         t = __DBG_TV2DBL(tv);
      }
      __dbg_timer_unlock();
   }

   if (pdelta != NULL) *pdelta = d;
   return t;
}

#undef __DEBUG_HAVE_TIMER__
#define __DEBUG_HAVE_TIMER__ 1

#endif /* ?__DEBUG_HAVE_SHM__ */

#endif /* __DEBUG_UNIX__ */

#ifdef __DBG_VERBOSE__
#ifdef _MSC_VER
#pragma message(__FILE_LINE__ " : note: USE_DEBUG_TIMER defined.")
#endif
#endif

#endif /* !def __DEBUG_TIMER_DEFINED__ */

#endif /* def USE_DEBUG_TIMER */

#if !__DEBUG_HAVE_TIMER__

__DBG_INLINE__
static int
debug_timer_initialize(void)
{
   return -1;
}

__DBG_INLINE__
static void
debug_timer_terminate(void)
{
}

__DBG_INLINE__
static double
debug_timer_elapsed(void)
{
   return 0.0;
}

__DBG_INLINE__
static double
debug_timer_elapsed_ex(double *pdelta)
{
   if (pdelta != NULL) *pdelta = 0.0;
   return 0.0;
}

#endif /* !__DEBUG_HAVE_TIMER__ */

#undef __DBG_TIMESTAMP_INCL_TIMING__
#if defined(DEBUG_LOG_TIMING) && __DEBUG_HAVE_TIMER__
#define __DBG_TIMESTAMP_INCL_TIMING__ 1
#else
#define __DBG_TIMESTAMP_INCL_TIMING__ 0
#endif

#if defined(__OS400__)

#include <except.h>
#include <xxdtaa.h>
#include <qrcvdtaq.h>

#define __DBG_ISERIES_CONFIG_ENTRIES   4
#define __DBG_ISERIES_CONFIG_ENTRY_SZ  128
#define __DBG_ISERIES_CONFIG_SZ        (__DBG_ISERIES_CONFIG_ENTRIES * __DBG_ISERIES_CONFIG_ENTRY_SZ)

static struct
{
#ifdef __DBG_USE_PTHREAD__
   pthread_once_t once;
#endif
   int inited;
   char config[__DBG_ISERIES_CONFIG_SZ];
} __dbg_iSeriesConfig =
   {
#ifdef __DBG_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
#endif
      0,
      ""
   };

#ifdef __DBG_USE_PTHREAD__
static void
__dbg_iseries_load_config_once(void)
#else
static void
__dbg_iseries_load_config(void)
#endif
{
   if (__dbg_iSeriesConfig.inited == 0)
   {
      _DTAA_NAME_T DAName;
      int i;
      char *entry;

      memset(&DAName, ' ', sizeof(DAName));
      memcpy(DAName.dtaa_name, "DEBUGHLP", 8);
      memcpy(DAName.dtaa_lib, "*LIBL", 5);

#pragma exception_handler( \
            Lbl_QXXRTVDA_Failed, 0, 0, \
            _C2_MH_ESCAPE | _C2_MH_FUNCTION_CHECK, _CTLA_HANDLE_NO_MSG )

      QXXRTVDA(DAName, 1, __DBG_ISERIES_CONFIG_SZ, __dbg_iSeriesConfig.config);

#pragma disable_handler

      goto Lbl_Continue;

Lbl_QXXRTVDA_Failed:
      memset(__dbg_iSeriesConfig.config, ' ', sizeof(__dbg_iSeriesConfig.config));

Lbl_Continue:
      for (i = 0, entry = __dbg_iSeriesConfig.config;
            i < __DBG_ISERIES_CONFIG_ENTRIES;
            ++i, entry += __DBG_ISERIES_CONFIG_ENTRY_SZ)
      {
         int l = __DBG_ISERIES_CONFIG_ENTRY_SZ - 1;
         while (l > 0 && entry[l-1] == ' ') --l;
         entry[l] = '\0';
      }

      __dbg_iSeriesConfig.inited = 1;
   }
}

#ifdef __DBG_USE_PTHREAD__
static void
__dbg_iseries_load_config(void)
{
   pthread_once(&__dbg_iSeriesConfig.once, __dbg_iseries_load_config_once);
}
#endif

#define __DBG_ISERIES_CONFIG(n) \
   (((n) >= 0 && (n) < __DBG_ISERIES_CONFIG_ENTRIES) \
      ? (__dbg_iSeriesConfig.config + ((n) * __DBG_ISERIES_CONFIG_ENTRY_SZ)) \
      : NULL)

#define __DBG_ISERIES_DEBUG_DIRECTORY  __DBG_ISERIES_CONFIG(0)
#define __DBG_ISERIES_DEBUG_FILE       __DBG_ISERIES_CONFIG(1)

#endif /* def __OS400__ */

#if defined(USE_DEBUG_DIALOG) || defined(USE_DEBUG_LOG)

static struct
{
#if __DEBUG_WIN32__
   CRITICAL_SECTION lock;
#endif
#ifdef __DBG_USE_PTHREAD__
   pthread_once_t once;
   pthread_mutex_t lock;
#endif
   char debugdir[__DBG_FILENAME_SIZE__];
   char debugfile[__DBG_FILENAME_SIZE__];
} __dbg_settings =
   {
#if __DEBUG_WIN32__
      { 0 },
#endif
#ifdef __DBG_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
      PTHREAD_MUTEX_INITIALIZER,
#endif
      "",
      ""
   };

#if __DEBUG_WIN32__

static void
__dbg_settings_lock_init(void)
{
   static long __initlock = 0;
   static int volatile __inited = -1;

   if (__dbg_InterlockedBitTestAndSet(&__initlock, 0) == 0)
   {
      InitializeCriticalSection(&__dbg_settings.lock);
      __inited = 1;
   }
   else
   {
      while (__inited < 0)
      {
         Sleep(0);
      }
   }
}

#define __dbg_settings_lock() \
   (__dbg_settings_lock_init(), EnterCriticalSection(&__dbg_settings.lock))
#define __dbg_settings_unlock() \
   LeaveCriticalSection(&__dbg_settings.lock)

#elif defined(__DBG_USE_PTHREAD__)

static void
__dbg_settings_lock_init_once(void)
{
   pthread_mutexattr_t attr;
   if (pthread_mutexattr_init(&attr) == 0)
   {
      if (pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE) == 0)
      {
         pthread_mutex_init(&__dbg_settings.lock, &attr);
      }
   }
}

#define __dbg_settings_lock_init() \
   ((void)pthread_once(&__dbg_settings.once, __dbg_settings_lock_init_once))

#define __dbg_settings_lock() \
   (__dbg_settings_lock_init(), (void)pthread_mutex_lock(&__dbg_settings.lock))
#define __dbg_settings_unlock() \
   ((void)pthread_mutex_unlock(&__dbg_settings.lock))

#else /* !__DEBUG_WIN32__ && !__DBG_USE_PTHREAD__ */

#define __dbg_settings_lock()
#define __dbg_settings_unlock()

#endif

#if 0
__DBG_INLINE__
static int
__dbg_invalid_str
(
   const char *s
)
{
   if (NULL == s) return 1;
   return ('\0' == *s);
}
#else
#define __dbg_invalid_str(s) (NULL == (s) || '\0' == *(s))
#endif

static void
__dbg_set_debugdir
(
   const char* debugdir
)
{
   if (__dbg_invalid_str(debugdir))
   {
#ifdef __DBG_HAVE_GETENV_S
      char val[256];
      size_t vallen;
#endif

#if defined(__OS400__)
      __dbg_iseries_load_config();
#endif

#if defined(__OS400__)
      debugdir = __DBG_ISERIES_DEBUG_DIRECTORY;
#elif defined(__DBG_HAVE_GETENV_S)
      debugdir =
         (getenv_s(&vallen, val, sizeof(val), "DEBUG_DIRECTORY") == 0)
            ? val : NULL;
#else
      debugdir = getenv("DEBUG_DIRECTORY");
#endif
      if (__dbg_invalid_str(debugdir))
         debugdir = __DBG_DIRECTORY__;
   }
   __dbg_strncpy_s(__dbg_settings.debugdir, sizeof(__dbg_settings.debugdir),
                     debugdir, sizeof(__dbg_settings.debugdir)-1);
   __dbg_settings.debugdir[sizeof(__dbg_settings.debugdir)-1] = '\0';
}

static void
debug_set_debugdir
(
   const char* debugdir
)
{
   __dbg_settings_lock();
   __dbg_set_debugdir(debugdir);
   __dbg_settings_unlock();
}

static void
__dbg_set_debugfile
(
   const char* debugfile
)
{
   if (__dbg_invalid_str(debugfile))
   {
#ifdef __DBG_HAVE_GETENV_S
      char val[256];
      size_t vallen;
#endif

#if defined(__OS400__)
      __dbg_iseries_load_config();
#endif

#if defined(__OS400__)
      debugfile = __DBG_ISERIES_DEBUG_FILE;
#elif defined(__DBG_HAVE_GETENV_S)
      debugfile =
         (getenv_s(&vallen, val, sizeof(val), "DEBUG_FILE") == 0)
            ? val : NULL;
#else
      debugfile = getenv("DEBUG_FILE");
#endif
      if (__dbg_invalid_str(debugfile))
         debugfile = __DBG_FILE__;
   }
   __dbg_strncpy_s(__dbg_settings.debugfile, sizeof(__dbg_settings.debugfile),
                     debugfile, sizeof(__dbg_settings.debugfile)-1);
   __dbg_settings.debugfile[sizeof(__dbg_settings.debugfile)-1] = '\0';
}

static void
debug_set_debugfile
(
   const char* debugfile
)
{
   __dbg_settings_lock();
   __dbg_set_debugfile(debugfile);
   __dbg_settings_unlock();
}

/*
 *  Filename generated here is always relative to
 *  debug base directory (DEBUG_DIRECTORY).
 */
static const char *
__dbg_debug_filename_ex
(
   const char *debugdir,
   const char *debugfile,
   char *filename, size_t filenamesz,
   int inclexe, int inclpid, int incltid
)
{
   int sep;
   size_t l, debugfilelen, basenamelen;
   const char pathsep[2] = { __DBG_PATH_SEP__, '\0' };
   const char *exestr;
   char pidstr[16], tidstr[16];

   __dbg_settings_lock();

   if (__dbg_invalid_str(debugdir))
   {
      if ('\0' == __dbg_settings.debugdir[0])
      {
         __dbg_set_debugdir(NULL);
      }
      debugdir = __dbg_settings.debugdir;
   }
   if (__dbg_invalid_str(debugfile))
   {
      if ('\0' == __dbg_settings.debugfile[0])
      {
         __dbg_set_debugfile(NULL);
      }
      debugfile = __dbg_settings.debugfile;
   }

   l = strlen(debugdir) - 1;
   sep = __DBG_IS_PATH_SEP_ONLY__(debugdir[l]);

   l = strlen(debugfile);
   while (l > 0 && __DBG_IS_PATH_SEP__(debugfile[l-1]))
      --l;
   debugfilelen = l;
   basenamelen = l;
   while (l > 0 && debugfile[l-1] != '.'
            && !__DBG_IS_PATH_SEP__(debugfile[l-1]))
      --l;
   if (l > 0 && debugfile[l-1] == '.')
   {
      basenamelen = l - 1;
   }

   exestr = (inclexe) ? __dbg_ProcessFileBaseName() : "";
   if (inclpid)
   {
      DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(pidstr, sizeof(pidstr)),
         "-" __DBG_PID_FMT_0, __dbg_GetCurrentProcessId());
      pidstr[sizeof(pidstr)-1] = '\0';
   }
   else
   {
      pidstr[0] = '\0';
   }
#if DEBUG_HAVE_THREAD_ID
   if (incltid)
   {
      DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(tidstr, sizeof(tidstr)),
         "-" __DBG_TID_FMT_0, __dbg_GetCurrentThreadId());
      tidstr[sizeof(tidstr)-1] = '\0';
   }
   else
#endif
   {
      tidstr[0] = '\0';
   }

   {
      int n;
      n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(filename, filenamesz),
               "%s%s%.*s%s%s%s%s%.*s",
               debugdir,
               sep ? "" : pathsep,
               (int)basenamelen, debugfile,
               __dbg_invalid_str(exestr) ? "" : "-",
               __dbg_invalid_str(exestr) ? "" : exestr,
               pidstr, tidstr,
               (int)(debugfilelen - basenamelen), debugfile + basenamelen);
      if (n < 0 || n >= (int)filenamesz) n = (int)filenamesz - 1;
      filename[n] = '\0';
   }

   __dbg_settings_unlock();

   return filename;
}

#if 0
__DBG_INLINE__
static const char *
__dbg_debug_filename
(
   const char *debugfile,
   char *filename, size_t filenamesz
)
{
   return __dbg_debug_filename_ex(NULL, debugfile, filename, filenamesz, 0, 0, 0);
}
#else
#define __dbg_debug_filename(d, f, s) __dbg_debug_filename_ex(NULL, (d), (f), (s), 0, 0, 0)
#endif

/*
 *  Skip filename generation if debugfile is a full path,
 *  i.e. starts with a path sep (Unix) or drive letter (Windows)
 *  or UNC path (Windows).
 *  If skipped, filename buffer is untouched.
 */
__DBG_INLINE__
static const char *
__dbg_debug_use_filename_ex
(
   const char *debugdir,
   const char *debugfile,
   char *filename, size_t filenamesz,
   int inclexe, int inclpid, int incltid
)
{
   if (!__dbg_invalid_str(debugfile))
   {
      if (
#if __DEBUG_WIN32__
            (!__DBG_IS_PATH_SEP__(debugfile[0])
               && __DBG_IS_DRIVE_SEP__(debugfile[1])
               && __DBG_IS_PATH_SEP_ONLY__(debugfile[2])) /* With drive letter */
         || (__DBG_IS_PATH_SEP_ONLY__(debugfile[0])
               && __DBG_IS_PATH_SEP_ONLY__(debugfile[1])) /* UNC path */
         || __DBG_FILE_NAME_IS_CONSOLE__(debugfile) /* con: */
#else
         __DBG_IS_PATH_SEP__(debugfile[0]) /* Starts from root */
#endif
      ) return debugfile; /* use full path */

#if __DEBUG_WIN32__
      if (!__DBG_IS_PATH_SEP__(debugfile[0]) && __DBG_IS_DRIVE_SEP__(debugfile[1])) debugfile += 2;
      else while (__DBG_IS_PATH_SEP__(*debugfile)) ++debugfile;
#endif
   }

   return __dbg_debug_filename_ex(debugdir, debugfile, filename, filenamesz, inclexe, inclpid, incltid);
}

#if 0
__DBG_INLINE__
static const char *
__dbg_debug_use_filename
(
   const char *debugfile,
   char *filename, size_t filenamesz
)
{
   return __dbg_debug_use_filename_ex(NULL, debugfile, filename, filenamesz, 0, 0, 0);
}
#else
#define __dbg_debug_use_filename(d, f, s) __dbg_debug_use_filename_ex(NULL, (d), (f), (s), 0, 0, 0)
#endif

__DBG_INLINE__
static int
__dbg_check_file_exists
(
   const char *checkfile
)
{
   char debug_file[__DBG_FILENAME_SIZE__];
   return __dbg_file_exists(__dbg_debug_use_filename(checkfile, debug_file, sizeof(debug_file)));
}

static int
__dbg_match_text
(
   const char *source, const char *search
)
{
   size_t lsource, lsearch, i;
   int found = 0;

   lsource = strlen(source);
   lsearch = strlen(search);

   if (0 == lsource && 0 == lsearch)
      return 1;

   if (lsource >= lsearch)
   {
      for (i = 0; i <= lsource-lsearch; ++i)
      {
         if (__dbg_strncasecmp(source+i, search, lsearch) == 0)
         {
            found = 1;
            break;
         }
      }
   }

   return found;
}

static int
__dbg_match_text_file
(
   const char *source, const char *file
)
{
#ifdef WX_DEBUG_WXMEM
   __FUNCNAME__("__dbg_match_text_file");
#endif
   int found = 0;

   if (__dbg_file_exists(file))
   {
      char *text;
      const char *textend = NULL;
      size_t textsz = 0;

      if ((text = __dbg_file_read_wholefile(file, &textend, &textsz)) != NULL)
      {
         char *textcur = text, *textnext;

         while ((textcur = __dbg_buffer_getline(textcur, textend, &textnext))
                     != NULL)
         {
            switch (*textcur)
            {
            case '\0':
               found = ('\0' == *source);
               break;
            case '*':
               found = 1;
               break;
            default:
               found = __dbg_match_text(source, textcur);
               break;
            }
            if (found) break;
            textcur = textnext;
         }

         __dbg_free(text);
      }
   }

   return found;
}

#endif /* def USE_DEBUG_DIALOG || def USE_DEBUG_LOG */

static int
debug_noop(void)
{
   return 0;
}

__DBG_INLINE__
static const char*
debug_path_get_basename_ex
(
   const char* path,
   int incldir
)
{
   const char* cp;
   if (!path || incldir < 0) return path;
   cp = path + strlen(path);
   for (;;)
   {
      while (cp > path && !__DBG_IS_PATH_SEP__(*(cp-1))) --cp;
      if (incldir-- == 0 || cp <= path) break;
      while (cp > path && __DBG_IS_PATH_SEP__(*(cp-1))) --cp;
   }
   return cp;
}

__DBG_INLINE__
static const char*
debug_path_get_basename
(
   const char* path
)
{
   return debug_path_get_basename_ex(path, 0);
}

#define debug_set_break_point_here() debug_noop()
#define __DEBUG_SET_BREAK_POINT_HERE__ debug_set_break_point_here();

#define __DBG_TIMESTAMP_MAX_LEN__ 64

static char *
debug_timestamp_ex2
(
   char *timebuf,
   size_t timebuflen,
   int incldate,
   int incltimer,
   size_t *ptimelen
)
{
   size_t timelen = 0;
   int n;

#if __DEBUG_WIN32__
   {
      SYSTEMTIME systm;
      GetLocalTime(&systm);
      if (incldate)
      {
         n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf, timebuflen),
               "%04d-%02d-%02d %02d:%02d:%02d.%03d",
               systm.wYear, systm.wMonth, systm.wDay,
               systm.wHour, systm.wMinute, systm.wSecond, systm.wMilliseconds);
      }
      else
      {
         n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf, timebuflen),
               "%02d:%02d:%02d.%03d",
               systm.wHour, systm.wMinute, systm.wSecond, systm.wMilliseconds);
      }
      if (n < 0 || (size_t)n >= timebuflen) n = (int)timebuflen - 1;
      timebuf[n] = '\0';
      timelen = n;
   }
#elif __DEBUG_UNIX__
   {
      struct timeval tv;
      time_t curtime;
      struct tm tb;
      struct tm *ptm;
      int rc;

      rc = gettimeofday(&tv, NULL);
      if (rc == 0)
      {
         curtime = tv.tv_sec;
      }
      else
      {
         time(&curtime);
      }
      /*  In RedHat EL 5 (and possibly other distros), somehow strftime()
       *  would cause a deadlock if called inside a signal handler for
       *  SIGABRT. And so it is simply replaced with snprintf().
       */
      ptm = localtime_r(&curtime, &tb);
      if (NULL != ptm
            && (timelen = ((incldate)
                              ? DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf, timebuflen),
                                 "%04d-%02d-%02d %02d:%02d:%02d",
                                 ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday,
                                 ptm->tm_hour, ptm->tm_min, ptm->tm_sec)
                              : DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf, timebuflen),
                                 "%02d:%02d:%02d",
                                 ptm->tm_hour, ptm->tm_min, ptm->tm_sec)
                           )) > 0)   
      {
         if (rc == 0)
         {
            size_t rem = timebuflen - timelen;
            n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf + timelen, rem),
                  ".%06d", (int)(tv.tv_usec));
            if (n < 0 || (size_t)n >= rem) n = (int)rem - 1;
            timelen += n;
            timebuf[timelen] = '\0';
         }
      }
      else
      {
         timebuf[0] = '\0'; timelen = 0;
      }
   }
#else
#error Not supported platform!
#endif

   if (incltimer)
   {
#if __DEBUG_HAVE_TIMER__
      size_t rem = timebuflen - timelen;
      if (__dbg_timer.include_delta)
      {
         double lapsec, delta;
         lapsec = debug_timer_elapsed_ex(&delta);
         n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf + timelen, rem),
               " %#0.*f %#0.*f",
               __dbg_timer.display_precision, lapsec,
               __dbg_timer.display_precision, delta);
      }
      else
      {
         n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(timebuf + timelen, rem),
               " %#0.*f",
               __dbg_timer.display_precision, debug_timer_elapsed());
      }
      if (n < 0 || (size_t)n >= rem) n = (int)rem - 1;
      timelen += n;
      timebuf[timelen] = '\0';
#endif
   }

   if (ptimelen != NULL) *ptimelen = timelen;
   return timebuf;
}

#define debug_timestamp_ex(t, l, i, p) debug_timestamp_ex2((t), (l), 1, (i), (p))
#define debug_timestamp(t, l)          debug_timestamp_ex((t), (l), 0, NULL)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !def __DEBUG_COMMON_DEFINED__ */

#endif /* def USE_DEBUG_COMMON */

#ifdef USE_DEBUG_DIALOG

#ifndef __DEBUG_DIALOG_DEFINED__
#define __DEBUG_DIALOG_DEFINED__

#if __DEBUG_WIN32__
#ifndef MB_SERVICE_NOTIFICATION
#ifdef __DBG_VERBOSE__
#ifdef _MSC_VER
#pragma message(__FILE_LINE__ " : note: MB_SERVICE_NOTIFICATION not defined!")
#endif
#endif
#define MB_SERVICE_NOTIFICATION 0x00200000L
#define __XXX_MB_SERVICE_NOTIFICATION_DEFINED_XXX__
#endif
#endif

#ifndef DEBUG_DIALOG_CAPTION_FORMAT
#if 0 && DEBUG_HAVE_THREAD_ID
#define DEBUG_DIALOG_CAPTION_FORMAT "%s @ %s:%d (pid=" __DBG_PID_FMT ",tid=" __DBG_TID_FMT ")"
#else
#if DEBUG_HAVE_THREAD_ID
#define DEBUG_DIALOG_CAPTION_FORMAT __DBG_PID_FMT "/t" __DBG_TID_FMT "/%s @ %s:%d"
#else
#define DEBUG_DIALOG_CAPTION_FORMAT __DBG_PID_FMT "/%s @ %s:%d"
#endif
#endif
#endif

#ifndef DEBUG_DIALOG_CAPTION_ARGS
#if 0 && DEBUG_HAVE_THREAD_ID
#define DEBUG_DIALOG_CAPTION_ARGS __func, __file, __line, pid, tid
#else
#if DEBUG_HAVE_THREAD_ID
#define DEBUG_DIALOG_CAPTION_ARGS pid, tid, __func, __file, __line
#else
#define DEBUG_DIALOG_CAPTION_ARGS pid, __func, __file, __line
#endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if __DEBUG_WIN32__
static BOOL
__dbg_switch_desktop
(
   const char* winstation,
   const char* windesktop,
   HWINSTA* phwsNew,
   HDESK* phdkNew,
   HWINSTA* phwsSave,
   HDESK* phdkSave
)
{
   BOOL switchedWinStation = FALSE;
   BOOL switched = FALSE;

   *phwsNew = NULL;
   *phdkNew = NULL;
   *phwsSave = NULL;
   *phdkSave = NULL;

   *phwsSave = GetProcessWindowStation();
   *phdkSave = GetThreadDesktop(GetCurrentThreadId());
   if (*phwsSave == NULL || *phdkSave == NULL) goto exithere;

   *phwsNew = OpenWindowStationA((LPSTR)winstation, FALSE, __DBG_WINSTA_ALL_ACCESS__);
   if (*phwsNew == NULL) goto exithere;
   if (!SetProcessWindowStation(*phwsNew)) goto exithere;
   switchedWinStation = TRUE;

   *phdkNew = OpenDesktopA((LPSTR)windesktop, 0, FALSE, __DBG_DESKTOP_ALL_ACCESS__);
   if (*phdkNew == NULL) goto exithere;
   if (!SetThreadDesktop(*phdkNew)) goto exithere;
   switched = TRUE;

exithere:
   if (!switched)
   {
      if (switchedWinStation && *phwsSave != NULL)
      {
         SetProcessWindowStation(*phwsSave);
      }
      if (*phdkNew != NULL)
      {
         CloseDesktop(*phdkNew);
         *phdkNew = NULL;
      }
      if (*phwsNew != NULL)
      {
         CloseWindowStation(*phwsNew);
         *phwsNew = NULL;
      }
      *phwsSave = NULL;
      *phdkSave = NULL;
   }
   return switched;
}
#endif /* __DEBUG_WIN32__ */

#if __DEBUG_WIN32__
static void
__dbg_restore_desktop
(
   HWINSTA* phwsNew,
   HDESK* phdkNew,
   HWINSTA* phwsSave,
   HDESK* phdkSave
)
{
   if (*phdkSave != NULL)
   {
      SetThreadDesktop(*phdkSave);
      *phdkSave = NULL;
   }
   if (*phwsSave != NULL)
   {
      SetProcessWindowStation(*phwsSave);
      *phwsSave = NULL;
   }
   if (*phdkNew != NULL)
   {
      CloseDesktop(*phdkNew);
      *phdkNew = NULL;
   }
   if (*phwsNew != NULL)
   {
      CloseWindowStation(*phwsNew);
      *phwsNew = NULL;
   }
}
#endif /* __DEBUG_WIN32__ */

#if __DEBUG_UNIX__

#if !defined(linux) && !defined(__linux) && !defined(__linux__)

static int
__dbg_setenv
(
   const char *name,
   const char *value,
   int overwrite
)
{
   char buf[1024];

   DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(buf, sizeof(buf)), "%s=%s", name, value);
   buf[sizeof(buf)-1] = '\0';
   return putenv(buf);
}

#define setenv(e, v, f) __dbg_setenv((e), (v), (f))

#endif /* linux */

static struct
{
#ifdef __DBG_USE_PTHREAD__
   pthread_once_t once;
#endif
   int inited;
   char Display[128];
   char MessageBoxMode[128];
   char ExternalProgram[PATH_MAX];
   char PythonPath[PATH_MAX];
   char PythonModule[128];
   char PythonFunction[128];
} __dbg_Config =
   {
#ifdef __DBG_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
#endif
      0,
      "localhost:0.0",
      "external",
      "msgbox",
      ".",
      "msgbox",
      "MessageBox",
   };

#ifdef __DBG_USE_PTHREAD__
static void
__dbg_LoadDebugConfig_once(void)
#else
static void
__dbg_LoadDebugConfig(void)
#endif
{
#ifdef WX_DEBUG_WXMEM
   __FUNCNAME__("__dbg_LoadDebugConfig");
#endif

   if (__dbg_Config.inited == 0)
   {
      char config_file[__DBG_FILENAME_SIZE__];
      if (__dbg_file_exists(__dbg_debug_filename(__DBG_CONFIG_FILE__, config_file, sizeof(config_file))))
      {
         char *text;
         const char *textend = NULL;
         size_t textsz = 0;

         if ((text = __dbg_file_read_wholefile(config_file, &textend, &textsz)) != NULL)
         {
            const struct
            {
               const char* c;
               size_t n;
               char *p;
               size_t l;
               int e;
            } cfg[] =
               {
                  { "display",           7, __dbg_Config.Display,         sizeof(__dbg_Config.Display),         0 },
                  { "messageboxmode",   14, __dbg_Config.MessageBoxMode,  sizeof(__dbg_Config.MessageBoxMode),  0 },
                  { "message_box_mode", 16, __dbg_Config.MessageBoxMode,  sizeof(__dbg_Config.MessageBoxMode),  0 },
                  { "externalprogram",  15, __dbg_Config.ExternalProgram, sizeof(__dbg_Config.ExternalProgram), 0 },
                  { "external_program", 16, __dbg_Config.ExternalProgram, sizeof(__dbg_Config.ExternalProgram), 0 },
                  { "pythonpath",       10, __dbg_Config.PythonPath,      sizeof(__dbg_Config.PythonPath),      0 },
                  { "python_path",      11, __dbg_Config.PythonPath,      sizeof(__dbg_Config.PythonPath),      0 },
                  { "pythonmodule",     12, __dbg_Config.PythonModule,    sizeof(__dbg_Config.PythonModule),    0 },
                  { "python_module",    13, __dbg_Config.PythonModule,    sizeof(__dbg_Config.PythonModule),    0 },
                  { "pythonfunction",   14, __dbg_Config.PythonFunction,  sizeof(__dbg_Config.PythonFunction),  0 },
                  { "python_function",  15, __dbg_Config.PythonFunction,  sizeof(__dbg_Config.PythonFunction),  0 },
               };
            const int ncfg = sizeof(cfg) / sizeof(cfg[0]);
            char *textcur = text, *textnext;

            while ((textcur = __dbg_buffer_getline(textcur, textend, &textnext)) != NULL)
            {
               const char *sp = textcur;
               while (*sp == ' ' || *sp == '\t') ++sp;
               if (*sp != ';' && *sp != '=' && *sp != '\0')
               {
                  const char *cp = sp;
                  while (*cp != '=' && *cp != '\0') ++cp;
                  if (*cp == '=')
                  {
                     size_t n = cp - sp;
                     while (n > 0 && (sp[n-1] == ' ' || sp[n-1] == '\t')) --n;
                     if (n > 0)
                     {
                        size_t l;
                        int i;
                        ++cp; /* skip the '=' sign */
                        while (*cp == ' ' || *cp == '\t') ++cp;
                        l = strlen(cp);
                        while (l > 0 && (cp[l-1] == ' ' || cp[l-1] == '\t')) --l;
                        for (i = 0; i < ncfg; ++i)
                        {
                           if (cfg[i].n == n && __dbg_strncasecmp(cfg[i].c, sp, n) == 0
                                 && (cfg[i].e || l > 0))
                           {
                              if (l >= cfg[i].l) l = cfg[i].l - 1;
                              __dbg_strncpy_s(cfg[i].p, cfg[i].l, cp, l);
                              cfg[i].p[l] = '\0';
                              break;
                           }
                        }
                     }
                  }
               }
               textcur = textnext;
            }

            __dbg_free(text);
         }
      }
      __dbg_Config.inited = 1;
   }
}

#ifdef __DBG_USE_PTHREAD__
static void
__dbg_LoadDebugConfig(void)
{
   pthread_once(&__dbg_Config.once, __dbg_LoadDebugConfig_once);
}
#endif

#ifdef USE_DEBUG_PYTHON

#ifdef USE_DEBUG_LOG
__DBG_CHECK_FORMAT__((printf, 5, 6))
static void
debug_log
(
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
);
#endif

#define HANDLE_PY_ERROR if (PyErr_Occurred()) { PyErr_Print(); PyErr_Clear(); }

#ifdef USE_DEBUG_LOG
#define __DBG_PYRUN_DEBUG(s) s
#define __DBG_PYRUN_LOG "pyrun.log"
#else
#define __DBG_PYRUN_DEBUG(s)
#endif

static int
__dbg_pyrun
(
   const char* pszModule,
   const char* pszFunction,
   int nArgs,
   const char* aszArgs[]
)
{
#ifdef USE_DEBUG_LOG
   __FUNCNAME__("__dbg_pyrun");
#endif
   PyObject *pName, *pModule, *pDict, *pFunc;
   PyObject *pArgs, *pValue;
   int rc = 1;
   int i;

   Py_Initialize();
   pName = PyString_FromString(pszModule);
   /* Error checking of pName left out */

   pModule = PyImport_Import(pName);
   Py_DECREF(pName);

   if (pModule != NULL)
   {
      pDict = PyModule_GetDict(pModule);
      /* pDict is a borrowed reference */

      pFunc = PyDict_GetItemString(pDict, pszFunction);
      /* pFun: Borrowed reference */

      if (pFunc && PyCallable_Check(pFunc))
      {
         pArgs = PyTuple_New(nArgs);
         for (i = 0; i < nArgs; ++i)
         {
            pValue = PyString_FromString(aszArgs[i]);
            if (pValue == NULL)
            {
               Py_DECREF(pArgs);
               Py_DECREF(pModule);
               __DBG_PYRUN_DEBUG(debug_log(__DBG_PYRUN_LOG, __DBGARGS__, "Cannot convert argument"));
               HANDLE_PY_ERROR
               goto pyrun_exit;
            }
            /* pValue reference stolen here: */
            PyTuple_SetItem(pArgs, i, pValue);
         }
         pValue = PyObject_CallObject(pFunc, pArgs);
         Py_DECREF(pArgs);
         if (pValue != NULL)
         {
#ifdef USE_DEBUG_LOG
            PyObject *pValueStr = PyObject_Str(pValue);
            const char* pszValueStr = NULL;
            if (pValueStr != NULL)
            {
               pszValueStr = PyString_AsString(pValueStr);
            }
            debug_log(__DBG_PYRUN_LOG, __DBGARGS__, "Result of call: %s", pszValueStr);
            HANDLE_PY_ERROR
#endif
            Py_DECREF(pValue);
            rc = 0;
         }
         else
         {
            __DBG_PYRUN_DEBUG(debug_log(__DBG_PYRUN_LOG, __DBGARGS__, "Call failed"));
            HANDLE_PY_ERROR
         }
         /* pDict and pFunc are borrowed and must not be Py_DECREF-ed */
      }
      else
      {
         __DBG_PYRUN_DEBUG(debug_log(__DBG_PYRUN_LOG, __DBGARGS__, "Cannot find __func \"%s\"", pszFunction));
         HANDLE_PY_ERROR
      }
      Py_DECREF(pModule);
   }
   else
   {
      __DBG_PYRUN_DEBUG(debug_log(__DBG_PYRUN_LOG, __DBGARGS__, "Failed to load \"%s\"", pszModule));
      HANDLE_PY_ERROR
   }

pyrun_exit:
   Py_Finalize();
   return rc;
}

static void
__dbg_MessageBox_Python
(
   const char *message,
   const char *caption
)
{
   char oldDisplay[128];
   char *cp;

   __dbg_LoadDebugConfig();

   cp = getenv("DISPLAY");
   if (cp != NULL)
   {
      __dbg_strncpy_s(oldDisplay, sizeof(oldDisplay), cp, sizeof(oldDisplay)-1);
      oldDisplay[sizeof(oldDisplay)-1] = '\0';
   }
   else
   {
      oldDisplay[0] = '\0';
   }

   setenv("DISPLAY", __dbg_Config.Display, 1);

   setenv("PYTHONPATH", __dbg_Config.PythonPath, 1);

   {
      const char *aszArgs[2] = { message, caption };
      __dbg_pyrun(__dbg_Config.PythonModule, __dbg_Config.PythonFunction, 2, aszArgs);
   }

   setenv("DISPLAY", oldDisplay, 1);
}

static int
__dbg_py_tkMessageBox
(
   int nArgs,
   const char* aszArgs[]
)
{
   const char *py_msgbox_begin =
      "import sys\n"
      "if not sys.__dict__.has_key('argv'):\n"
      "  sys.argv = [ 'py' ]\n"
      "from Tkinter import Tk\n"
      "import tkMessageBox\n"
      "tk = Tk()\n"
      "tk.wm_withdraw()\n"
      "tkMessageBox.showerror(";
   const char *py_msgbox_end =
      ")\n"
      "del tk\n";
   char *py_msgbox = NULL;
   size_t argttlsz = 0;
   size_t progsz = 0;
   int i;

   for (i = 0; i < nArgs; ++i)
      argttlsz += strlen(aszArgs[i]);
   progsz = strlen(py_msgbox_begin) + (argttlsz * 4) + (nArgs * 2)
               + strlen(py_msgbox_end) + 256;
   py_msgbox = (char *)__dbg_malloc(progsz);
   if (py_msgbox != NULL)
   {
      char *cp = py_msgbox;
      cp += sprintf(cp, py_msgbox_begin);
      for (i = 0; i < nArgs; ++i)
      {
         const char *ap = aszArgs[i];
         int qc = 0;
         if (i > 0) { *cp++ = ','; *cp++ = ' '; }
         strcpy(cp, "r'''"); cp += 4;
         while (*ap != '\0')
         {
            if (*ap == '\'') ++qc; else qc = 0;
            *cp++ = *ap++;
            if (qc >= 3) { cp += sprintf(cp, "\"'''\"r'''"); qc = 0; }
         }
         strcpy(cp, "'''"); cp += 3;
      }
      cp += sprintf(cp, py_msgbox_end);

      Py_Initialize();
      PyRun_SimpleString(py_msgbox);
      Py_Finalize();

      __dbg_free(py_msgbox);
   }

   return 0;
}

static void
__dbg_MessageBox_Python_Embedded
(
   const char *message,
   const char *caption
)
{
   char oldDisplay[128];
   char *cp;

   __dbg_LoadDebugConfig();

   cp = getenv("DISPLAY");
   if (cp != NULL)
   {
      __dbg_strncpy_s(oldDisplay, sizeof(oldDisplay), cp, sizeof(oldDisplay)-1);
      oldDisplay[sizeof(oldDisplay)-1] = '\0';
   }
   else
   {
      oldDisplay[0] = '\0';
   }

   setenv("DISPLAY", __dbg_Config.Display, 1);

   {
      const char *aszArgs[2] = { caption, message };
      __dbg_py_tkMessageBox(2, aszArgs);
   }

   setenv("DISPLAY", oldDisplay, 1);
}

#endif /* def USE_DEBUG_PYTHON */

#if defined(__OS400__)

/*  iSeries does not have fork(), etc.
 *  or they are just hidden somewhere
 *  so simply use waitfile for the moment.
 */
#define __dbg_MessageBox_External(m, c) __dbg_MessageBox_WaitFile(__file, (m), (c))

#else /* !def __OS400__ */

static void
__dbg_MessageBox_External
(
   const char *message,
   const char *caption
)
{
   char oldDisplay[128];
   char *cp;
   pid_t pid;

   __dbg_LoadDebugConfig();

   cp = getenv("DISPLAY");
   if (cp != NULL)
   {
      __dbg_strncpy_s(oldDisplay, sizeof(oldDisplay), cp, sizeof(oldDisplay)-1);
      oldDisplay[sizeof(oldDisplay)-1] = '\0';
   }
   else
   {
      oldDisplay[0] = '\0';
   }

   setenv("DISPLAY", __dbg_Config.Display, 1);

   pid = fork();
   if (pid < 0)
   {
      /* error: nothing we can do! */
   }
   else if (pid == 0)
   {
      /* I am the child */
      execlp(__dbg_Config.ExternalProgram, __dbg_Config.ExternalProgram, message, caption, (const char*)0);
   }
   else
   {
      int status;
      waitpid(pid, &status, 0);
   }

   setenv("DISPLAY", oldDisplay, 1);
}

#endif /* ?def __OS400__ */

#endif /* __DEBUG_UNIX__ */

static void
__dbg_MessageBox_WaitFile
(
   const char *__file,
   const char *message,
   const char *caption
)
{
   size_t l;
   char waitbase[128];
   char waitfile[__DBG_FILENAME_SIZE__];
   DEBUG_FILE_HANDLE fh;

   l = strlen(__file);
   while (l > 0 && !__DBG_IS_PATH_SEP__(__file[l-1]))
      --l;

   DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(waitbase, sizeof(waitbase)),
      "%s.wait", __file + l);
   __dbg_debug_filename_ex(NULL, waitbase, waitfile, sizeof(waitfile),
#if __DEBUG_WIN32__ || defined(__CYGWIN__) \
         || defined(linux) || defined(__linux) || defined(__linux__)
      1 /* inclexe */,
#else
      0 /* inclexe */,
#endif
      1 /* inclpid */,
#if __DEBUG_WIN32__
      1 /* incltid */
#else
      0 /* incltid */
#endif
      );

   fh = __dbg_file_create_write_excl(waitfile);
   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      char buf[__DBG_MESSAGE_SIZE__];
      int n;

      n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(buf, sizeof(buf)),
            "PID: " __DBG_PID_FMT, __dbg_GetCurrentProcessId());
      if (n > 0) __dbg_file_write(fh, buf, n);
      __dbg_file_write_endline(fh, __DBG_DOSFMT__);
#if DEBUG_HAVE_THREAD_ID
      n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(buf, sizeof(buf)),
            "TID: " __DBG_TID_FMT, __dbg_GetCurrentThreadId());
      if (n > 0) __dbg_file_write(fh, buf, n);
      __dbg_file_write_endline(fh, __DBG_DOSFMT__);
#endif
      __dbg_file_write_endline(fh, __DBG_DOSFMT__);

      if (NULL != caption && '\0' != *caption)
      {
         __dbg_file_write(fh, "CAPTION:", 8);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
         __dbg_file_write_text(fh, __DBG_DOSFMT__, caption);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
      }
      if (NULL != message && '\0' != *message)
      {
         __dbg_file_write(fh, "MESSAGE:", 8);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
         __dbg_file_write_text(fh, __DBG_DOSFMT__, message);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
      }
      __dbg_file_close(fh);

      while (__dbg_file_exists(waitfile))
      {
#if __DEBUG_WIN32__
         Sleep(1000);
#else
         sleep(1);
#endif
      }
   }
}

static void
__dbg_debug_dialog_va
(
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, va_list va   /* message */
)
{
   char caption[__DBG_CAPTION_SIZE__];
   char message[__DBG_MESSAGE_SIZE__];
   __dbg_pid_t pid, tid;
#if __DEBUG_WIN32__
   HWINSTA hwsNew;
   HWINSTA hwsSave;
   HDESK hdkNew;
   HDESK hdkSave;
   BOOL switched;
#endif

   pid = __dbg_GetCurrentProcessId();
   tid = __dbg_GetCurrentThreadId();

   {
      int n;
      n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(caption, sizeof(caption)),
            DEBUG_DIALOG_CAPTION_FORMAT, DEBUG_DIALOG_CAPTION_ARGS);
      if (n < 0 || n >= (int)sizeof(caption)) n = sizeof(caption) - 1;
      caption[n] = '\0';
      n = DEBUG_VSNPRINTF(DEBUG_VSNPRINTF_BUF(message, sizeof(message)), format, va);
      if (n < 0 || n >= (int)sizeof(message)) n = sizeof(message) - 1;
      message[n] = '\0';
   }

#if __DEBUG_WIN32__

   switched = __dbg_switch_desktop("WinSta0", "Default", &hwsNew, &hdkNew, &hwsSave, &hdkSave);
   MessageBoxA(NULL, message, caption, MB_OK | MB_SERVICE_NOTIFICATION);
   if (switched) __dbg_restore_desktop(&hwsNew, &hdkNew, &hwsSave, &hdkSave);

#elif __DEBUG_UNIX__

   __dbg_LoadDebugConfig();

   if (__dbg_strcasecmp(__dbg_Config.MessageBoxMode, "waitfile") == 0)
   {
      __dbg_MessageBox_WaitFile(__file, message, caption);
   }
#ifdef USE_DEBUG_PYTHON
   else if (__dbg_strcasecmp(__dbg_Config.MessageBoxMode, "python") == 0)
   {
      __dbg_MessageBox_Python(message, caption);
   }
   else if (__dbg_strcasecmp(__dbg_Config.MessageBoxMode, "python_embedded") == 0)
   {
      __dbg_MessageBox_Python_Embedded(message, caption);
   }
#endif
   else
   {
      __dbg_MessageBox_External(message, caption);
   }

#else
#error Not supported platform!
#endif
}

__DBG_CHECK_FORMAT__((printf, 4, 5))
static void
debug_dialog
(
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);
}

__DBG_CHECK_FORMAT__((printf, 4, 5))
static int
debug_dialog_check_file
(
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (!__dbg_check_file_exists(NULL))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 5, 6))
static int
debug_dialog_check_file_ex
(
   const char *checkfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_invalid_str(checkfile)) return 0;
   if (!__dbg_check_file_exists(checkfile))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 6, 7))
static int
debug_dialog_str_eq
(
   const char *string1, const char *string2, /* condition */
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_strcasecmp(string1, string2) != 0) return 0;

   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_dialog_data_eq
(
   const void *buffer1, const void *buffer2, size_t count, /* condition */
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (memcmp(buffer1, buffer2, count) != 0) return 0;

   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 6, 7))
static int
debug_dialog_match_text
(
   const char *sourcetext, const char *searchtext, /* condition */
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (NULL == sourcetext || NULL == searchtext) return 0;
   if (!__dbg_match_text(sourcetext, searchtext)) return 0;

   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 6, 7))
static int
debug_dialog_match_text_file
(
   const char *sourcetext, const char *textfile, /* condition */
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   char debug_file[__DBG_FILENAME_SIZE__];
   va_list va;

   if (NULL == sourcetext || __dbg_invalid_str(textfile)) return 0;
   if (!__dbg_match_text_file(sourcetext,
      __dbg_debug_use_filename(textfile, debug_file, sizeof(debug_file)))) return 0;

   va_start(va, format);
   __dbg_debug_dialog_va(__file, __line, __func, format, va);
   va_end(va);

   return 1;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __DBG_VERBOSE__
#ifdef _MSC_VER
#pragma message(__FILE_LINE__ " : note: USE_DEBUG_DIALOG defined.")
#endif
#endif

#ifdef __XXX_MB_SERVICE_NOTIFICATION_DEFINED_XXX__
#undef __XXX_MB_SERVICE_NOTIFICATION_DEFINED_XXX__
#undef MB_SERVICE_NOTIFICATION
#endif

#endif /* !def __DEBUG_DIALOG_DEFINED__ */

#endif /* def USE_DEBUG_DIALOG */

#ifdef USE_DEBUG_LOG

#ifndef USE_DEBUG_LOG_INTERNAL_ONLY

#ifndef __DEBUG_LOG_DEFINED__
#define __DEBUG_LOG_DEFINED__

#if __DEBUG_UNIX__
#include <time.h>
#include <sys/time.h>
#endif

#ifdef DEBUG_LOG_PROCESS_NAME

#ifndef DEBUG_LOG_HEADING_FORMAT
#if DEBUG_HAVE_THREAD_ID
#define DEBUG_LOG_HEADING_FORMAT "(pid=%s:" __DBG_PID_FMT ",tid=" __DBG_TID_FMT ") < %s @ %s:%d >"
#else
#define DEBUG_LOG_HEADING_FORMAT "(pid=%s:" __DBG_PID_FMT ") < %s @ %s:%d >"
#endif
#endif

#ifndef DEBUG_LOG_HEADING_ARGS
#if DEBUG_HAVE_THREAD_ID
#define DEBUG_LOG_HEADING_ARGS \
   __dbg_ProcessFileBaseName(), pid, tid, __func, __file, __line
#else
#define DEBUG_LOG_HEADING_ARGS \
   __dbg_ProcessFileBaseName(), pid, __func, __file, __line
#endif
#endif

#else /* !def DEBUG_LOG_PROCESS_NAME */

#ifndef DEBUG_LOG_HEADING_FORMAT
#if DEBUG_HAVE_THREAD_ID
#define DEBUG_LOG_HEADING_FORMAT "(pid=" __DBG_PID_FMT ",tid=" __DBG_TID_FMT ") < %s @ %s:%d >"
#else
#define DEBUG_LOG_HEADING_FORMAT "(pid=" __DBG_PID_FMT ") < %s @ %s:%d >"
#endif
#endif

#ifndef DEBUG_LOG_HEADING_ARGS
#if DEBUG_HAVE_THREAD_ID
#define DEBUG_LOG_HEADING_ARGS pid, tid, __func, __file, __line
#else
#define DEBUG_LOG_HEADING_ARGS pid, __func, __file, __line
#endif
#endif

#endif /* ?def DEBUG_LOG_PROCESS_NAME */

#undef __DBG_LOG_FILENAME_INCL_PID__
#undef __DBG_LOG_FILENAME_INCL_TID__
#undef __DBG_LOG_FILENAME_INCL_EXE__

#ifdef DEBUG_LOG_FILENAME_INCL_PID
#define __DBG_LOG_FILENAME_INCL_PID__  1
#else
#define __DBG_LOG_FILENAME_INCL_PID__  0
#endif

#ifdef DEBUG_LOG_FILENAME_INCL_TID
#if __DEBUG_WIN32__
#define __DBG_LOG_FILENAME_INCL_TID__  1
#elif __DEBUG_UNIX__
#define __DBG_LOG_FILENAME_INCL_TID__  0
#endif
#else
#define __DBG_LOG_FILENAME_INCL_TID__  0
#endif

#ifdef DEBUG_LOG_FILENAME_INCL_EXE
#define __DBG_LOG_FILENAME_INCL_EXE__  1
#else
#define __DBG_LOG_FILENAME_INCL_EXE__  0
#endif

#ifdef DEBUG_LOG_TIMING_LOCKING
#define __DBG_LOG_TIMESTAMP_BUF_LEN__ \
   (5 /*"[ " + " ] "*/ + __DBG_TIMESTAMP_MAX_LEN__ + 1 /*' '*/ + __DBG_TIMESTAMP_MAX_LEN__)
#else
#define __DBG_LOG_TIMESTAMP_BUF_LEN__ \
   (5 /*"[ " + " ] "*/ + __DBG_TIMESTAMP_MAX_LEN__)
#endif

#define __DBG_LOG_TIMESTAMP_DECL__ \
   char __dbglog_timestamp[__DBG_LOG_TIMESTAMP_BUF_LEN__]; \
   size_t __dbglog_timestamp_len; \
   char *__dbglog_timestamp_cp;

#if defined(DEBUG_LOG_TIMING_LOCKING) || !defined(DEBUG_LOG_TIMING_UPON_LOG)
#define __DBG_LOG_TIMESTAMP_STAGE_1__() \
   { \
      debug_timestamp_ex(__dbglog_timestamp + 2, __DBG_TIMESTAMP_MAX_LEN__, \
                         __DBG_TIMESTAMP_INCL_TIMING__, &__dbglog_timestamp_len); \
      __dbglog_timestamp_cp = __dbglog_timestamp + 2 + __dbglog_timestamp_len; \
   }
#else
#define __DBG_LOG_TIMESTAMP_STAGE_1__()
#endif

#if defined(DEBUG_LOG_TIMING_LOCKING)
#define __DBG_LOG_TIMESTAMP_STAGE_2_A__() \
   { \
      size_t __timestamp_len; \
      *__dbglog_timestamp_cp++ = ' '; \
      /* not including the date */ \
      debug_timestamp_ex2(__dbglog_timestamp_cp, __DBG_TIMESTAMP_MAX_LEN__, 0, \
                          __DBG_TIMESTAMP_INCL_TIMING__, &__timestamp_len); \
      __dbglog_timestamp_len += 1 + __timestamp_len; \
      __dbglog_timestamp_cp += __timestamp_len; \
   }
#elif defined(DEBUG_LOG_TIMING_UPON_LOG)
#define __DBG_LOG_TIMESTAMP_STAGE_2_A__() \
   { \
      debug_timestamp_ex(__dbglog_timestamp + 2, __DBG_TIMESTAMP_MAX_LEN__, \
                         __DBG_TIMESTAMP_INCL_TIMING__, &__dbglog_timestamp_len); \
      __dbglog_timestamp_cp = __dbglog_timestamp + 2 + __dbglog_timestamp_len; \
   }
#else
#define __DBG_LOG_TIMESTAMP_STAGE_2_A__()
#endif

#define __DBG_LOG_TIMESTAMP_STAGE_2__() \
   { \
      __DBG_LOG_TIMESTAMP_STAGE_2_A__() \
      __dbglog_timestamp[0] = '['; __dbglog_timestamp[1] = ' '; \
      __dbglog_timestamp_cp[0] = ' '; __dbglog_timestamp_cp[1] = ']'; \
      __dbglog_timestamp_cp[2] = ' '; __dbglog_timestamp_cp[3] = '\0'; \
      __dbglog_timestamp_len += 5; \
   }

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
   DEBUG_LOG_DIRECT = 0,
   DEBUG_LOG_OPEN,
   DEBUG_LOG_KEEP_OPEN,
   DEBUG_LOG_CLOSE
} DEBUG_LOG_OPERATION;

__DBG_INLINE__
static int
__dbg_debug_log_open
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   DEBUG_FILE_HANDLE *pfilehndtouse,
   int *plocked
)
{
   switch (fileop)
   {
   case DEBUG_LOG_DIRECT:
   case DEBUG_LOG_OPEN:
      {
         char logfilename[__DBG_FILENAME_SIZE__];

         if (__dbg_invalid_str(logfile)) return -1;

         *pfilehndtouse =
            __dbg_file_open_append(
               __dbg_debug_use_filename_ex(
                  NULL, logfile, logfilename, sizeof(logfilename),
                  __DBG_LOG_FILENAME_INCL_EXE__,
                  __DBG_LOG_FILENAME_INCL_PID__,
                  __DBG_LOG_FILENAME_INCL_TID__));
         if (fileop == DEBUG_LOG_OPEN && NULL != pfilehnd)
            *pfilehnd = *pfilehndtouse;
      }
      break;
   case DEBUG_LOG_KEEP_OPEN:
   case DEBUG_LOG_CLOSE:
      {
         if (NULL != pfilehnd)
         {
            *pfilehndtouse = *pfilehnd;
            *plocked = 1;
         }
      }
      break;
   default:
      return -1;
      break;
   }

   return 0;
}

static int
__dbg_debug_log_close
(
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   DEBUG_FILE_HANDLE filehndtouse,
   int locked,
   int addnl,
   int dosfmt
)
{
   if (pfilehnd == NULL) fileop = DEBUG_LOG_CLOSE;

   switch (fileop)
   {
   case DEBUG_LOG_DIRECT:
   case DEBUG_LOG_CLOSE:
      {
         if (addnl) __dbg_file_write_endline(filehndtouse, dosfmt);

         if (locked) __dbg_file_unlock_wholefile(filehndtouse);
         __dbg_file_close(filehndtouse);

         if (fileop == DEBUG_LOG_CLOSE && NULL != pfilehnd)
            *pfilehnd = DEBUG_INVALID_FILE_HANDLE;
      }
      break;
   default:
      return -1;
      break;
   }

   return 0;
}

static void
__dbg_debug_log_va
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, va_list va   /* message */
)
{
   DEBUG_FILE_HANDLE fh = DEBUG_INVALID_FILE_HANDLE;
   int locked = 0;
   __DBG_LOG_TIMESTAMP_DECL__

   __DBG_LOG_TIMESTAMP_STAGE_1__()

   if (__dbg_debug_log_open(logfile, pfilehnd, fileop, &fh, &locked) != 0)
      return;

   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      char caption[__DBG_CAPTION_SIZE__];
      char message[__DBG_MESSAGE_SIZE__];
      __dbg_pid_t pid, tid;
      int n;

      pid = __dbg_GetCurrentProcessId();
      tid = __dbg_GetCurrentThreadId();

      n = DEBUG_SNPRINTF(DEBUG_SNPRINTF_BUF(caption, sizeof(caption)),
            DEBUG_LOG_HEADING_FORMAT, DEBUG_LOG_HEADING_ARGS);
      if (n < 0 || n >= (int)sizeof(caption)) n = sizeof(caption) - 1;
      caption[n] = '\0';
      n = DEBUG_VSNPRINTF(DEBUG_VSNPRINTF_BUF(message, sizeof(message)), format, va);
      if (n < 0 || n >= (int)sizeof(message)) n = sizeof(message) - 1;
      message[n] = '\0';

      if (!locked)
         locked = (__dbg_file_lock_wholefile(fh) == 0);
      __dbg_file_seek_end(fh);

      __DBG_LOG_TIMESTAMP_STAGE_2__()

      /* write to log regardless whether we have the lock or not! */
      __dbg_file_write(fh, __dbglog_timestamp, __dbglog_timestamp_len);

      __dbg_file_write_text(fh, __DBG_DOSFMT__, caption);
      __dbg_file_write_endline(fh, __DBG_DOSFMT__);

      if ('\0' != *message)
      {
         __dbg_file_write_text(fh, __DBG_DOSFMT__, message);
         __dbg_file_write_endline(fh, __DBG_DOSFMT__);
      }

      __dbg_debug_log_close(pfilehnd, fileop, fh, locked, 1, __DBG_DOSFMT__);
   }
}

__DBG_CHECK_FORMAT__((printf, 5, 6))
static void
debug_log
(
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static void
debug_log2
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);
}

__DBG_CHECK_FORMAT__((printf, 5, 6))
static void
debug_log3
(
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);
}

__DBG_CHECK_FORMAT__((printf, 5, 6))
static int
debug_log_check_file
(
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (!__dbg_check_file_exists(NULL))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log2_check_file
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (!__dbg_check_file_exists(NULL))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 5, 6))
static int
debug_log3_check_file
(
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (!__dbg_check_file_exists(NULL))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 6, 7))
static int
debug_log_check_file_ex
(
   const char *checkfile,
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_invalid_str(checkfile)) return 0;
   if (!__dbg_check_file_exists(checkfile))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 8, 9))
static int
debug_log2_check_file_ex
(
   const char *checkfile,
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_invalid_str(checkfile)) return 0;
   if (!__dbg_check_file_exists(checkfile))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 6, 7))
static int
debug_log3_check_file_ex
(
   const char *checkfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_invalid_str(checkfile)) return 0;
   if (!__dbg_check_file_exists(checkfile))
      return 0; /* checkfile does not exist */

   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log_str_eq
(
   const char *string1, const char *string2, /* condition */
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_strcasecmp(string1, string2) != 0) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 9, 10))
static int
debug_log2_str_eq
(
   const char *string1, const char *string2, /* condition */
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_strcasecmp(string1, string2) != 0) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log3_str_eq
(
   const char *string1, const char *string2, /* condition */
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (__dbg_strcasecmp(string1, string2) != 0) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 8, 9))
static int
debug_log_data_eq
(
   const void *buffer1, const void *buffer2, size_t count, /* condition */
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (memcmp(buffer1, buffer2, count) != 0) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 10, 11))
static int
debug_log2_data_eq
(
   const void *buffer1, const void *buffer2, size_t count, /* condition */
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (memcmp(buffer1, buffer2, count) != 0) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 8, 9))
static int
debug_log3_data_eq
(
   const void *buffer1, const void *buffer2, size_t count, /* condition */
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (memcmp(buffer1, buffer2, count) != 0) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log_match_text
(
   const char *sourcetext, const char *searchtext, /* condition */
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (NULL == sourcetext || NULL == searchtext) return 0;
   if (!__dbg_match_text(sourcetext, searchtext)) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 9, 10))
static int
debug_log2_match_text
(
   const char *sourcetext, const char *searchtext, /* condition */
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (NULL == sourcetext || NULL == searchtext) return 0;
   if (!__dbg_match_text(sourcetext, searchtext)) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log3_match_text
(
   const char *sourcetext, const char *searchtext, /* condition */
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   va_list va;

   if (NULL == sourcetext || NULL == searchtext) return 0;
   if (!__dbg_match_text(sourcetext, searchtext)) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log_match_text_file
(
   const char *sourcetext, const char *textfile, /* condition */
   const char *logfile,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   char debug_file[__DBG_FILENAME_SIZE__];
   va_list va;

   if (NULL == sourcetext || __dbg_invalid_str(textfile)) return 0;
   if (!__dbg_match_text_file(sourcetext,
      __dbg_debug_use_filename(textfile, debug_file, sizeof(debug_file)))) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, NULL, DEBUG_LOG_DIRECT,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 9, 10))
static int
debug_log2_match_text_file
(
   const char *sourcetext, const char *textfile, /* condition */
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   char debug_file[__DBG_FILENAME_SIZE__];
   va_list va;

   if (NULL == sourcetext || __dbg_invalid_str(textfile)) return 0;
   if (!__dbg_match_text_file(sourcetext,
      __dbg_debug_use_filename(textfile, debug_file, sizeof(debug_file)))) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      logfile, pfilehnd, fileop,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

__DBG_CHECK_FORMAT__((printf, 7, 8))
static int
debug_log3_match_text_file
(
   const char *sourcetext, const char *textfile, /* condition */
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *__file, int __line,  /* caption */
   const char *__func,              /* caption */
   const char *format, ...          /* message */
)
{
   char debug_file[__DBG_FILENAME_SIZE__];
   va_list va;

   if (NULL == sourcetext || __dbg_invalid_str(textfile)) return 0;
   if (!__dbg_match_text_file(sourcetext,
      __dbg_debug_use_filename(textfile, debug_file, sizeof(debug_file)))) return 0;

   va_start(va, format);
   __dbg_debug_log_va(
      NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN,
      __file, __line, __func, format, va);
   va_end(va);

   return 1;
}

static void
__dbg_debug_print_va
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *format, va_list va
)
{
   DEBUG_FILE_HANDLE fh = DEBUG_INVALID_FILE_HANDLE;
   int locked = 0;

   if (__dbg_debug_log_open(logfile, pfilehnd, fileop, &fh, &locked) != 0)
      return;

   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      char message[__DBG_MESSAGE_SIZE__];
      int n;

      n = DEBUG_VSNPRINTF(DEBUG_VSNPRINTF_BUF(message, sizeof(message)), format, va);
      if (n < 0 || n >= (int)sizeof(message)) n = sizeof(message) - 1;
      message[n] = '\0';

      if (!locked)
         locked = (__dbg_file_lock_wholefile(fh) == 0);
      __dbg_file_seek_end(fh);

      /* write to log regardless whether we have the lock or not! */
      __dbg_file_write_text(fh, __DBG_DOSFMT__, message);

      __dbg_debug_log_close(pfilehnd, fileop, fh, locked, 0, __DBG_DOSFMT__);
   }
}

__DBG_CHECK_FORMAT__((printf, 2, 3))
static void
debug_print
(
   const char *logfile,
   const char *format, ...
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_print_va(logfile, NULL, DEBUG_LOG_DIRECT, format, va);
   va_end(va);
}

__DBG_CHECK_FORMAT__((printf, 4, 5))
static void
debug_print2
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *format, ...
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_print_va(logfile, pfilehnd, fileop, format, va);
   va_end(va);
}

__DBG_CHECK_FORMAT__((printf, 2, 3))
static void
debug_print3
(
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *format, ...
)
{
   va_list va;
   va_start(va, format);
   __dbg_debug_print_va(NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN, format, va);
   va_end(va);
}

static void
debug_writetext2
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const char *text
)
{
   DEBUG_FILE_HANDLE fh = DEBUG_INVALID_FILE_HANDLE;
   int locked = 0;

   if (__dbg_debug_log_open(logfile, pfilehnd, fileop, &fh, &locked) != 0)
      return;

   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      if (!locked)
         locked = (__dbg_file_lock_wholefile(fh) == 0);
      __dbg_file_seek_end(fh);

      /* write to log regardless whether we have the lock or not! */
      __dbg_file_write_text(fh, __DBG_DOSFMT__, text);

      __dbg_debug_log_close(pfilehnd, fileop, fh, locked, 0, __DBG_DOSFMT__);
   }
}

static void
debug_writetext
(
   const char *logfile,
   const char *text
)
{
   debug_writetext2(logfile, NULL, DEBUG_LOG_DIRECT, text);
}

static void
debug_writetext3
(
   DEBUG_FILE_HANDLE *pfilehnd,
   const char *text
)
{
   debug_writetext2(NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN, text);
}

static void
debug_writedata2
(
   const char *logfile,
   DEBUG_FILE_HANDLE *pfilehnd,
   DEBUG_LOG_OPERATION fileop,
   const void *data,
   size_t datalen
)
{
   DEBUG_FILE_HANDLE fh = DEBUG_INVALID_FILE_HANDLE;
   int locked = 0;

   if (__dbg_debug_log_open(logfile, pfilehnd, fileop, &fh, &locked) != 0)
      return;

   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      if (!locked)
         locked = (__dbg_file_lock_wholefile(fh) == 0);
      __dbg_file_seek_end(fh);

      /* write to log regardless whether we have the lock or not! */
      __dbg_file_write(fh, data, datalen);

      __dbg_debug_log_close(pfilehnd, fileop, fh, locked, 0, __DBG_DOSFMT__);
   }
}

static void
debug_writedata
(
   const char *logfile,
   const void *data,
   size_t datalen
)
{
   debug_writedata2(logfile, NULL, DEBUG_LOG_DIRECT, data, datalen);
}

static void
debug_writedata3
(
   DEBUG_FILE_HANDLE *pfilehnd,
   const void *data,
   size_t datalen
)
{
   debug_writedata2(NULL, pfilehnd, DEBUG_LOG_KEEP_OPEN, data, datalen);
}

__DBG_CHECK_FORMAT__((printf, 2, 3))
static void
debug_onelinelog
(
   const char *logfile,
   const char *format, ...
)
{
   DEBUG_FILE_HANDLE fh = DEBUG_INVALID_FILE_HANDLE;
   int locked = 0;
   va_list va;
   __DBG_LOG_TIMESTAMP_DECL__

   __DBG_LOG_TIMESTAMP_STAGE_1__()

   if (__dbg_debug_log_open(logfile, NULL, DEBUG_LOG_DIRECT, &fh, &locked) != 0)
      return;

   if (DEBUG_FILE_HANDLE_IS_VALID(fh))
   {
      char message[__DBG_MESSAGE_SIZE__];
      int n;

      va_start(va, format);
      n = DEBUG_VSNPRINTF(DEBUG_VSNPRINTF_BUF(message, sizeof(message)), format, va);
      va_end(va);
      if (n < 0 || n >= (int)sizeof(message)) n = sizeof(message) - 1;
      while (n > 0 && (message[n-1] == '\r' || message[n-1] == '\n'))
         --n;
      message[n] = '\0';

      if (!locked)
         locked = (__dbg_file_lock_wholefile(fh) == 0);
      __dbg_file_seek_end(fh);

      __DBG_LOG_TIMESTAMP_STAGE_2__()

      /* write to log regardless whether we have the lock or not! */
      __dbg_file_write(fh, __dbglog_timestamp, __dbglog_timestamp_len);

      /* write to log regardless whether we have the lock or not! */
      if ('\0' != *message)
      {
         __dbg_file_write_text(fh, __DBG_DOSFMT__, message);
      }
      __dbg_file_write_endline(fh, __DBG_DOSFMT__);

      __dbg_debug_log_close(NULL, DEBUG_LOG_DIRECT, fh, locked, 0, __DBG_DOSFMT__);
   }
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __DBG_VERBOSE__
#ifdef _MSC_VER
#pragma message(__FILE_LINE__ " : note: USE_DEBUG_LOG defined.")
#endif
#endif

#endif /* !def __DEBUG_LOG_DEFINED__ */

#endif /* !def USE_DEBUG_LOG_INTERNAL_ONLY */

#endif /* def USE_DEBUG_LOG */

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DEBUG_COMMON_DEFINED__)

__DBG_INLINE__
static void
__dbg_call_all_to_prevent_warning(void)
{
#if defined(__DEBUG_DIALOG_DEFINED__) || defined(__DEBUG_LOG_DEFINED__)
   __dbg_ProcessFileName();
   __dbg_ProcessFileBaseName();
   __dbg_file_lock(0, 0);
   __dbg_file_unlock(0, 0);
#endif
#if 0
   __dbg_file_lock_fromend(0, NULL);
#endif
#if 0 /* these are now macros */
   __dbg_file_lock_wholefile(0);
   __dbg_file_unlock_wholefile(0);
#endif
#if defined(__DEBUG_DIALOG_DEFINED__) || defined(__DEBUG_LOG_DEFINED__)
   debug_set_debugdir(NULL);
   debug_set_debugfile(NULL);
#endif
   debug_noop();
   debug_path_get_basename(NULL);
   debug_timestamp_ex(NULL, 0, 0, NULL);
#if __DEBUG_HAVE_TIMER__
   debug_timer_initialize();
   debug_timer_terminate();
   debug_timer_current();
   debug_timer_elapsed();
   debug_timer_elapsed_ex(NULL);
#endif
#ifdef __DEBUG_DIALOG_DEFINED__
   debug_dialog(NULL, 0, NULL, " ");
   debug_dialog_check_file(NULL, 0, NULL, " ");
   debug_dialog_check_file_ex(NULL, NULL, 0, NULL, " ");
   debug_dialog_str_eq(NULL, NULL, NULL, 0, NULL, " ");
   debug_dialog_data_eq(NULL, NULL, 0, NULL, 0, NULL, " ");
   debug_dialog_match_text(NULL, NULL, NULL, 0, NULL, " ");
   debug_dialog_match_text_file(NULL, NULL, NULL, 0, NULL, " ");
#endif
#ifdef __DEBUG_LOG_DEFINED__
   debug_log(NULL, NULL, 0, NULL, " ");
   debug_log2(NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3(NULL, NULL, 0, NULL, " ");
   debug_log_check_file(NULL, NULL, 0, NULL, " ");
   debug_log2_check_file(NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3_check_file(NULL, NULL, 0, NULL, " ");
   debug_log_check_file_ex(NULL, NULL, NULL, 0, NULL, " ");
   debug_log2_check_file_ex(NULL, NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3_check_file_ex(NULL, NULL, NULL, 0, NULL, " ");
   debug_log_str_eq(NULL, NULL, NULL, NULL, 0, NULL, " ");
   debug_log2_str_eq(NULL, NULL, NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3_str_eq(NULL, NULL, NULL, NULL, 0, NULL, " ");
   debug_log_data_eq(NULL, NULL, 0, NULL, NULL, 0, NULL, " ");
   debug_log2_data_eq(NULL, NULL, 0, NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3_data_eq(NULL, NULL, 0, NULL, NULL, 0, NULL, " ");
   debug_log_match_text(NULL, NULL, NULL, NULL, 0, NULL, " ");
   debug_log2_match_text(NULL, NULL, NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3_match_text(NULL, NULL, NULL, NULL, 0, NULL, " ");
   debug_log_match_text_file(NULL, NULL, NULL, NULL, 0, NULL, " ");
   debug_log2_match_text_file(NULL, NULL, NULL, NULL, DEBUG_LOG_DIRECT, NULL, 0, NULL, " ");
   debug_log3_match_text_file(NULL, NULL, NULL, NULL, 0, NULL, " ");
   debug_print(NULL, " ");
   debug_print2(NULL, NULL, DEBUG_LOG_DIRECT, " ");
   debug_print3(NULL, " ");
   debug_writetext(NULL, NULL);
   debug_writetext3(NULL, NULL);
   debug_writedata(NULL, NULL, 0);
   debug_writedata3(NULL, NULL, 0);
   debug_onelinelog(NULL, " ");
#endif
   __dbg_call_all_to_prevent_warning();
}

#endif /* def __DEBUG_COMMON_DEFINED__ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef USE_DEBUG_COMMON
#ifdef __XXX_WIN32_WINNT_DEFINED_XXX__
#undef __XXX_WIN32_WINNT_DEFINED_XXX__
#undef _WIN32_WINNT
#endif
#endif

#if defined(_MSC_VER) || defined(__WATCOMC__)
#pragma pack(pop)
#endif

#endif /* !def __INCL_DEBUGHLP_H__ */
/* vim:syntax=cpp:sw=3:sts=3:ts=8:et
*/
