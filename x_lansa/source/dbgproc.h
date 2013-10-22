/*
 *  $Workfile:: dbgproc.h                                        $
 *   $Archive:: /VL/Trunk/work/x_win95/x_lansa/src/dbgproc.h     $
 *  $Revision:: 25                                               $
 *    $Author:: robert                                           $
 *      $Date:: 2013-01-09 15:16:10+11:00                        $
 */

#ifndef __INCL_DBGPROC_H__
#define __INCL_DBGPROC_H__

#if defined(_MSC_VER) || defined(__WATCOMC__)
#pragma pack(push, 8) /* VC default */
#endif

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if __DEBUG_WIN32__ && !defined(_WINDOWS_)
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#if __DEBUG_UNIX__

#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

#if defined(__OS400__) || defined(DEBUG_USE_PTHREAD)
#define __DBGPROC_USE_PTHREAD__
#endif

#ifdef __DBGPROC_USE_PTHREAD__
#include <pthread.h>
#endif

#endif /* __DEBUG_UNIX__ */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __dbg_strcpy_s
#if defined(_MSC_VER) && _MSC_VER >= 1400
#define __dbg_strcpy_s(d, n, s) strcpy_s((d), (n), (s))
#else
#define __dbg_strcpy_s(d, n, s) strcpy((d), (s))
#endif
#endif

#if __DEBUG_WIN32__

typedef DWORD __dbgproc_pid_t;
#define __dbgproc_GetCurrentProcessId() GetCurrentProcessId()
#define __dbgproc_GetCurrentThreadId()  GetCurrentThreadId()

#ifndef __DBGPROC_PATH_SEP__
#define __DBGPROC_PATH_SEP__      '\\'
#endif

#ifndef __DBGPROC_PATH_SEP2__
#define __DBGPROC_PATH_SEP2__     '/'
#endif

#ifndef __DBGPROC_DRIVE_SEP__
#define __DBGPROC_DRIVE_SEP__     ':'
#endif

#ifndef __DBGPROC_IS_PATH_SEP__
#define __DBGPROC_IS_PATH_SEP__(c) \
   (((c) == __DBGPROC_PATH_SEP__) || ((c) == __DBGPROC_PATH_SEP2__) || \
      ((c) == __DBGPROC_DRIVE_SEP__))
#endif

#elif __DEBUG_UNIX__

typedef pid_t __dbgproc_pid_t;
#define __dbgproc_GetCurrentProcessId() getpid()
#define __dbgproc_GetCurrentThreadId()  getpid()

#ifndef __DBGPROC_PATH_SEP__
#define __DBGPROC_PATH_SEP__      '/'
#endif

#ifndef __DBGPROC_IS_PATH_SEP__
#define __DBGPROC_IS_PATH_SEP__(c) \
   ((c) == __DBGPROC_PATH_SEP__)
#endif

#endif /* __DEBUG_WIN32__ || __DEBUG_UNIX__ */

#ifndef __DBGPROC_FILENAME_SIZE__
#if __DEBUG_WIN32__
#ifdef _MAX_PATH
#define __DBGPROC_FILENAME_SIZE__ _MAX_PATH
#else
#define __DBGPROC_FILENAME_SIZE__ 1024
#endif
#elif __DEBUG_UNIX__
#define __DBGPROC_FILENAME_SIZE__ PATH_MAX
#endif
#endif

#if __DEBUG_WIN32__

#ifdef _MSC_VER
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "advapi32.lib")
#endif

#ifdef __dbg_InterlockedBitTestAndSet
#define __dbgproc_InterlockedBitTestAndSet __dbg_InterlockedBitTestAndSet
#else

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
__dbgproc_InterlockedBitTestAndSet (
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

#define __dbgproc_InterlockedBitTestAndSet __dbgproc_InterlockedBitTestAndSet

#endif /* def _M_IX86 */

#elif defined(__GNUC__)

static __inline__ __attribute__((always_inline))
unsigned char
__dbgproc_InterlockedBitTestAndSet
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

#define __dbgproc_InterlockedBitTestAndSet __dbgproc_InterlockedBitTestAndSet

#endif /* ?def _MSC_VER || ?def __GNUC__ */
#endif /* !def _INC_SDKDDKVER */

#endif /* !def InterlockedBitTestAndSet */

#endif /* ?def __dbg_InterlockedBitTestAndSet */

#ifndef __dbgproc_InterlockedBitTestAndSet
#define __dbgproc_InterlockedBitTestAndSet InterlockedBitTestAndSet
#endif

typedef BOOL WINAPI FN_EnumProcessModules(HANDLE, HMODULE *, DWORD, LPDWORD);
typedef FN_EnumProcessModules *PFN_EnumProcessModules;
typedef DWORD WINAPI FN_GetModuleFileNameExA(HANDLE, HMODULE, LPSTR, DWORD);
typedef FN_GetModuleFileNameExA *PFN_GetModuleFileNameExA;

/*
 * Static variables for maintaining the loaded PSAPI.DLL
 * and some entry points
 */
static struct
{
   CRITICAL_SECTION Lock;
   /*
    * Loaded state:
    *    0 - not loaded
    *    1 - loaded
    *   -1 - tried but error, won't try again
    */
   int Loaded;
   /* Handle of the loaded PSAPI.DLL */
   HMODULE hModule;
   /* EnumProcessModules */
   PFN_EnumProcessModules EnumProcessModules;
   /* GetModuleFileNameExA */
   PFN_GetModuleFileNameExA GetModuleFileNameExA;
} __dbgproc_PSAPI =
   {
      { 0 },
      0,
      NULL,
      NULL,
      NULL
   };

static void
__dbg_PSAPI_DLL_CS_Init(void)
{
   static long __InitLock = 0;
   static int volatile __Inited = -1;

   if (__dbgproc_InterlockedBitTestAndSet(&__InitLock, 0) == 0)
   {
      InitializeCriticalSection(&__dbgproc_PSAPI.Lock);
      __Inited = 1;
   }
   else
   {
      while (__Inited < 0)
      {
         Sleep(0);
      }
   }
}

/*
 * __dbg_Load_PSAPI_DLL
 *
 * Description:
 *    Load PSAPI.DLL and obtain the required entry points:
 *       EnumProcessModules
 *       GetModuleFileNameExA
 *
 * Parameters:
 *    Nil
 *
 * Return values:
 *    1 if succeed
 *    -1 if error in loading PSAPI.DLL or obtaining the entry points
 *
 * Remarks:
 *    The function only tries to load PSAPI.DLL during the first call.
 *    (__dbgproc_PSAPI.Loaded = 0)
 *    After the first call, __dbgproc_PSAPI.Loaded will be either:
 *       1 - loaded PSAPI.DLL and obtained entry points
 *      -1 - error obtained and won't try again when the function
 *           is called again
 *
 * Requirements:
 *    Windows NT 4.0 or 2000 or later
 *    PSAPI.DLL
 *
 */
static int
__dbg_Load_PSAPI_DLL(void)
{
   __dbg_PSAPI_DLL_CS_Init();
   EnterCriticalSection(&__dbgproc_PSAPI.Lock);

   if (__dbgproc_PSAPI.Loaded == 0)
   {
      int iLoaded = -1;

      /* Load PSAPI.DLL */
      __dbgproc_PSAPI.hModule = LoadLibraryA("PSAPI.DLL");
      if (NULL != __dbgproc_PSAPI.hModule)
      {
         /* Obtain some entry points */
         __dbgproc_PSAPI.EnumProcessModules = (PFN_EnumProcessModules)
            GetProcAddress(__dbgproc_PSAPI.hModule, "EnumProcessModules");
         __dbgproc_PSAPI.GetModuleFileNameExA = (PFN_GetModuleFileNameExA)
            GetProcAddress(__dbgproc_PSAPI.hModule, "GetModuleFileNameExA");

         if (NULL == __dbgproc_PSAPI.EnumProcessModules
               || NULL == __dbgproc_PSAPI.GetModuleFileNameExA)
         {
            FreeLibrary(__dbgproc_PSAPI.hModule);
            __dbgproc_PSAPI.hModule = NULL;
            __dbgproc_PSAPI.EnumProcessModules = NULL;
            __dbgproc_PSAPI.GetModuleFileNameExA = NULL;
         }
         else
         {
            iLoaded = 1;
         }
      }

      __dbgproc_PSAPI.Loaded = iLoaded;
   }

   LeaveCriticalSection(&__dbgproc_PSAPI.Lock);

   return __dbgproc_PSAPI.Loaded;
}

/*
 * __dbg_Unload_PSAPI_DLL
 *
 * Description:
 *    Unload PSAPI.DLL if previously loaded.
 *    Clean up all the relating variables.
 *
 * Parameters:
 *    Nil
 *
 * Return values:
 *    Nil
 *
 * Remarks:
 *    The function will reset the loaded state to unloaded.
 *
 * Requirements:
 *    Windows NT 4.0 or 2000 or later
 *    PSAPI.DLL
 *
 */
static void
__dbg_Unload_PSAPI_DLL(void)
{
   __dbg_PSAPI_DLL_CS_Init();
   EnterCriticalSection(&__dbgproc_PSAPI.Lock);

   if (__dbgproc_PSAPI.Loaded > 0)
   {
      FreeLibrary(__dbgproc_PSAPI.hModule);
      __dbgproc_PSAPI.hModule = NULL;
      __dbgproc_PSAPI.EnumProcessModules = NULL;
      __dbgproc_PSAPI.GetModuleFileNameExA = NULL;

      __dbgproc_PSAPI.Loaded = 0;
   }

   LeaveCriticalSection(&__dbgproc_PSAPI.Lock);
}

static BOOL
__dbg_EnablePrivilege
(
   HANDLE hToken,
   LPCTSTR szPrivName,
   BOOL fEnable
)
{
   TOKEN_PRIVILEGES tp;
   tp.PrivilegeCount = 1;
   LookupPrivilegeValue(NULL, szPrivName, &tp.Privileges[0].Luid);
   tp.Privileges[0].Attributes = fEnable ? SE_PRIVILEGE_ENABLED : 0;
   AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL);
   return GetLastError() == ERROR_SUCCESS;
}

static BOOL
__dbg_EnableDebugPrivilege(void)
{
   static long __EnableLock = 0;
   static int volatile __Enabled = -1;

   if (__dbgproc_InterlockedBitTestAndSet(&__EnableLock, 0) == 0)
   {
      if (__Enabled < 0)
      {
         /*
          *  NOTE: Do not modify __Enabled until the last split second
          *  as the waiting loop below rely on that to work.
          */

         HANDLE hToken;
         int iEnabled;

         if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
         {
            iEnabled = __dbg_EnablePrivilege(hToken, SE_DEBUG_NAME, TRUE) ? 1 : 0;
            CloseHandle(hToken);
         }
         else
         {
            iEnabled = 0;
         }

         __Enabled = iEnabled;
      }
   }
   else
   {
      /*
       *  Some other thread is enabling debug privilege, wait until it finishes.
       */
      while (__Enabled < 0)
      {
         Sleep(0);
      }
   }

   return __Enabled;
}

/*
 * __dbg_GetProcessFileName
 *
 * Description:
 *    Obtain the process file name of a given PID
 *
 * Parameters:
 *    pid
 *       [in]        Process ID
 *    pszFileNameBuf
 *       [in/out]    Buffer for storing the process file name
 *    nFileNameBufLen
 *       [in]        Length of the buffer
 *
 * Return values:
 *    TRUE if process of PID is running and process file name
 *       has been obtained with the help of PSAPI.DLL.
 *    FALSE otherwise.
 *
 * Remarks:
 *    The process file name will be truncated if the buffer
 *    is not large enough.
 *    The stored process file name is always NUL terminated.
 *
 * Requirements:
 *    Windows NT 4.0 or 2000 or later
 *    PSAPI.DLL
 *
 */
static int
__dbg_GetProcessFileName
(
   __dbgproc_pid_t pid,
   char *pszFileNameBuf,
   size_t nFileNameBufLen
)
{
#if 0
   __FUNCNAME__("GetProcessFileName");
#endif
   HANDLE hProcess;
   DWORD dwError;
   int rc = 0;

   if (pszFileNameBuf == NULL || nFileNameBufLen <= 0)
      return rc;

   /* Fail if there is no PSAPI.DLL */
   if (__dbgproc_PSAPI.Loaded <= 0)
   {
      pszFileNameBuf[0] = '\0';
      return rc;
   }

   __dbg_EnableDebugPrivilege();

   hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
   if (NULL != hProcess)
   {
      for (;;)
      {
         HMODULE hModule;
         DWORD dwSize = 0;

         if (__dbgproc_PSAPI.EnumProcessModules(
               hProcess, &hModule, sizeof(hModule), &dwSize) != 0)
         {
            if ((dwSize = __dbgproc_PSAPI.GetModuleFileNameExA(
                  hProcess, hModule, pszFileNameBuf, (DWORD)nFileNameBufLen)) != 0)
            {
               if (dwSize >= nFileNameBufLen) dwSize = (DWORD)nFileNameBufLen - 1;
               pszFileNameBuf[dwSize] = '\0';
               rc = 1;
            }
            else
            {
#if 0
               dwError = GetLastError();
               if (debug_dialog_check_file_ex(
                     "GetProcessFileName",
                     __DBGARGS__,
                     "GetModuleFileNameExA() failed with error = %d", dwError))
                  __DEBUG_SET_BREAK_POINT_HERE__
#endif
            }
            break;
         }
         else
         {
            /*
             *  EnumProcessModules() may return ERROR_PARTIAL_COPY
             *  in case of the process has not been completely created
             *  or other not-yet-known reasons, so we need to try
             *  again in case of this error.
             *  BTW, potentially, there may be a dead loop here!
             *  For other errors, just return failure.
             */
            dwError = GetLastError();
            if (dwError != ERROR_PARTIAL_COPY)
            {
#if 0
               if (debug_dialog_check_file_ex(
                     "GetProcessFileName",
                     __DBGARGS__,
                     "EnumProcessModules() failed with error = %d", dwError))
                  __DEBUG_SET_BREAK_POINT_HERE__
#endif
               break;
            }
         }
      }
      CloseHandle(hProcess);
   }
#if 0
   else
   {
      /*
       *  OpenProcess() returns ERROR_INVALID_PARAMETER
       *  in case of the process of Pid does not exist.
       */
      dwError = GetLastError();
      if (dwError != ERROR_INVALID_PARAMETER)
      {
         if (debug_dialog_check_file_ex(
               "GetProcessFileName",
               __DBGARGS__,
               "OpenProcess() failed with error = %d", dwError))
            __DEBUG_SET_BREAK_POINT_HERE__
      }
   }
#endif

   if (!rc) pszFileNameBuf[0] = '\0';

   return rc;
}

#endif /* __DEBUG_WIN32__ */

#if __DEBUG_UNIX__

#if !defined(__OS400__)

static int
__dbg_GetProcessFileName
(
   __dbgproc_pid_t pid,
   char *pszFileNameBuf,
   size_t nFileNameBufLen
)
{
   int rc = 0;

   if (pszFileNameBuf == NULL || nFileNameBufLen <= 0)
      return rc;

#if defined(linux) || defined(__linux) || defined(__linux__) \
      || defined(__CYGWIN__)
   {
      char szExeName[PATH_MAX];
      char szBuffer[PATH_MAX];

      snprintf(szExeName, sizeof(szExeName),
         "/proc/%lu/exe",
         (unsigned long)pid);
      if (access(szExeName, F_OK) == 0)
      {
         realpath(szExeName, szBuffer);
         strncpy(pszFileNameBuf, szBuffer, nFileNameBufLen - 1);
         pszFileNameBuf[nFileNameBufLen - 1] = '\0';
         rc = 1;
      }

#if defined(__CYGWIN__)
      /* For older version of CYGWIN */
      if (rc == 0)
      {
         snprintf(szExeName, sizeof(szExeName),
            "/proc/%lu/exename",
            (unsigned long)pid);
         if (access(szExeName, F_OK) == 0)
         {
            int fh;
            fh = open(szExeName, O_RDONLY);
            if (fh != -1)
            {
               int readcnt = read(fh, pszFileNameBuf, nFileNameBufLen - 1);
               close(fh);
               if (readcnt > 0)
               {
                  pszFileNameBuf[readcnt] = '\0';
                  rc = 1;
               }
            }
         }
      }
#endif
   }
#endif

   if (!rc) pszFileNameBuf[0] = '\0';

   return rc;
}

#endif /* !def __OS400__ */

#endif /* __DEBUG_UNIX__ */

#if defined(__OS400__)

#include <qusec.h>
#include <qusrjobi.h>

static struct
{
#ifdef __DBGPROC_USE_PTHREAD__
   pthread_once_t once;
#endif
   int inited;
   char name[sizeof(((Qwc_JOBI0100_t *)NULL)->Job_Name) + 1];
} __dbgproc_CurrentJob =
   {
#ifdef __DBGPROC_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
#endif
      0,
      ""
   };

#ifdef __DBGPROC_USE_PTHREAD__
static void
__dbg_ProcessFileBaseName_once(void)
#else
static const char *
__dbg_ProcessFileBaseName(void)
#endif
{
   if (0 == __dbgproc_CurrentJob.inited)
   {
      Qwc_JOBI0100_t JobInfo;
      Qus_EC_t ErrBuffer;
      const char* jobname;
      int n;

      ErrBuffer.Bytes_Provided = sizeof(ErrBuffer);

      QUSRJOBI(
         &JobInfo, sizeof(JobInfo),
         "JOBI0100",
         "*                         ",
         "                 ",
         &ErrBuffer);

      if (ErrBuffer.Bytes_Available != 0)
      {
         jobname = "<N/A>";
         __dbgproc_CurrentJob.inited = -1;
      }
      else
      {
         jobname = JobInfo.Job_Name;
         __dbgproc_CurrentJob.inited = 1;
      }

      strncpy(__dbgproc_CurrentJob.name, jobname, sizeof(__dbgproc_CurrentJob.name)-1);
      __dbgproc_CurrentJob.name[sizeof(__dbgproc_CurrentJob.name)-1] = '\0';

      n = sizeof(__dbgproc_CurrentJob.name)-1;
      while (n > 0 && __dbgproc_CurrentJob.name[n-1] == ' ')
      {
         __dbgproc_CurrentJob.name[--n] = '\0';
      }
   }

#ifndef __DBGPROC_USE_PTHREAD__
   return __dbgproc_CurrentJob.name;
#endif
}

#ifdef __DBGPROC_USE_PTHREAD__
static const char *
__dbg_ProcessFileBaseName(void)
{
   pthread_once(&__dbgproc_CurrentJob.once, __dbg_ProcessFileBaseName_once);
   return __dbgproc_CurrentJob.name;
}
#endif

static const char *
__dbg_ProcessFileName(void)
{
   return __dbg_ProcessFileBaseName();
}

#else /* !def __OS400__ */

static struct
{
#ifdef __DBGPROC_USE_PTHREAD__
   pthread_once_t once;
#endif
   char FileName[__DBGPROC_FILENAME_SIZE__];
   const char *FileBaseName;
} __dbgproc_CurrentProcess =
   {
#ifdef __DBGPROC_USE_PTHREAD__
      PTHREAD_ONCE_INIT,
#endif
      "",
      NULL
   };

#if __DEBUG_WIN32__

static const char *
__dbg_ProcessFileName(void)
{
   static long __LoadLock = 0;
   static int volatile __Loaded = -1;

   if (__dbgproc_InterlockedBitTestAndSet(&__LoadLock, 0) == 0)
   {
      if (__Loaded < 0)
      {
         /*
          *  NOTE: Do not modify __Loaded until the last split second
          *  as the waiting loop below rely on that to work.
          */

         int iLoaded = 0;

         if (__dbg_Load_PSAPI_DLL() > 0)
         {
            if (__dbg_GetProcessFileName(
                  __dbgproc_GetCurrentProcessId(),
                  __dbgproc_CurrentProcess.FileName, sizeof(__dbgproc_CurrentProcess.FileName)))
            {
               size_t l = strlen(__dbgproc_CurrentProcess.FileName);
               while (l > 0 && !__DBGPROC_IS_PATH_SEP__(__dbgproc_CurrentProcess.FileName[l-1]))
               {
                  l--;
               }
               __dbgproc_CurrentProcess.FileBaseName = __dbgproc_CurrentProcess.FileName + l;
               iLoaded = 1;
            }
            __dbg_Unload_PSAPI_DLL();
         }

         if (!iLoaded)
         {
            __dbg_strcpy_s(__dbgproc_CurrentProcess.FileName, sizeof(__dbgproc_CurrentProcess.FileName), "<N/A>");
            __dbgproc_CurrentProcess.FileBaseName = __dbgproc_CurrentProcess.FileName;
            iLoaded = 1;
         }

         __Loaded = iLoaded;
      }
   }
   else
   {
      /*
       *  Some other thread is loading the process file name, wait until it finishes.
       */
      while (__Loaded < 0)
      {
         Sleep(0);
      }
   }

   return __dbgproc_CurrentProcess.FileName;
}

#else /* !__DEBUG_WIN32__ */

#ifdef __DBGPROC_USE_PTHREAD__
static void
__dbg_ProcessFileName_once(void)
#else
static const char *
__dbg_ProcessFileName(void)
#endif
{
   static int volatile __Loaded = -1;

   if (__Loaded < 0)
   {
      int iLoaded = 0;

      if (__dbg_GetProcessFileName(
            __dbgproc_GetCurrentProcessId(),
            __dbgproc_CurrentProcess.FileName, sizeof(__dbgproc_CurrentProcess.FileName)))
      {
         size_t l = strlen(__dbgproc_CurrentProcess.FileName);
         while (l > 0 && !__DBGPROC_IS_PATH_SEP__(__dbgproc_CurrentProcess.FileName[l-1]))
         {
            l--;
         }
         __dbgproc_CurrentProcess.FileBaseName = __dbgproc_CurrentProcess.FileName + l;
         iLoaded = 1;
      }

      if (!iLoaded)
      {
         __dbg_strcpy_s(__dbgproc_CurrentProcess.FileName, sizeof(__dbgproc_CurrentProcess.FileName), "<N/A>");
         __dbgproc_CurrentProcess.FileBaseName = __dbgproc_CurrentProcess.FileName;
         iLoaded = 1;
      }

      __Loaded = iLoaded;
   }

#ifndef __DBGPROC_USE_PTHREAD__
   return __dbgproc_CurrentProcess.FileName;
#endif
}

#ifdef __DBGPROC_USE_PTHREAD__
static const char *
__dbg_ProcessFileName(void)
{
   pthread_once(&__dbgproc_CurrentProcess.once, __dbg_ProcessFileName_once);
   return __dbgproc_CurrentProcess.FileName;
}
#endif

#endif /* ?__DEBUG_WIN32__ */

static const char *
__dbg_ProcessFileBaseName(void)
{
   __dbg_ProcessFileName();
   return __dbgproc_CurrentProcess.FileBaseName;
}

#endif /* ?def __OS400__ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#ifdef __TEST__
int main(void)
{
#if 0
#if __DEBUG_WIN32__
   if (__dbg_Load_PSAPI_DLL() > 0)
   {
      char fn[__DBGPROC_FILENAME_SIZE__];
      __dbgproc_pid_t pid = __dbgproc_GetCurrentProcessId();
      if (__dbg_GetProcessFileName(pid, fn, sizeof(fn)))
      {
         printf("process name is \"%.*s\"\n", sizeof(fn), fn);
      }
      else
      {
         printf("can't get name of process id %lu\n", (unsigned long)pid);
      }
      __dbg_Unload_PSAPI_DLL();
   }
   else
   {
      printf("can't load PSAPI.DLL\n");
   }
#endif
#endif

   printf("\"%s\"\n", __dbg_ProcessFileName());
   printf("\"%s\"\n", __dbg_ProcessFileBaseName());

   return 0;
}
#endif /* def __TEST__ */

#if defined(_MSC_VER) || defined(__WATCOMC__)
#pragma pack(pop)
#endif

#endif /* !def __INCL_DBGPROC_H__ */
/* vim:syntax=cpp:sw=3:sts=3:ts=8:et
*/
