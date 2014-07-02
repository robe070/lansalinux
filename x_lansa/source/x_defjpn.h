/* ================================================================= */
/* ===== LANSA FOR WINDOWS PARTITION LEVEL DEFINITIONS ============= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* WARNING   WARNING  WARNING  WARNING  WARNING  WARNING  WARNING    */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/*                                                                   */
/*  Any changes made to the values contained in the X_DEFPPP.H       */
/*  file, where PPP is the partition identifier, will require        */
/*  (re)compilation of ALL ENTRY POINT PROCESSES before the changes  */
/*  take effect.                                                     */
/*                                                                   */
/*  Once ALL entry point processes have been (re)compiled you will   */
/*  need to exit and re-enter your LANSA application for the         */
/*  new values to be picked up at execution time.                    */
/*                                                                   */
/* ================================================================= */
/*  Note that iSeries does not use this file. All values are         */
/*  derived from the LANSA for iSeries data areas or operating       */
/*  system values. Refer to the LANSA Guides for more information.   */
/* ================================================================= */
/*  Note that the following values default to operating values on    */
/*  Microsoft Windows. Thus the values in this file are IGNORED.     */
/*  Please refer to the LANSA Guides for more information including  */
/*  how to stop this occurring so that the values in this file ARE   */
/*  USED.                                                            */
/* ================================================================= */
/*                                                                   */
/* X_DATE_SEPARATOR, X_CURRENCY_SYMBOL, X_DECIMAL_POINT_CHAR,        */
/* X_TIME_SEPARATOR                                                  */
/*                                                                   */
/* ================================================================= */
/*           You should also note that these values                  */
/* ================================================================= */
/*                                                                   */
/*   X_AUTOMATIC_HELP,X_CENTURY_COMPARE_DATE,X_CENTURY_GREATER_DATE  */
/*   X_CENTURY_LESS_DATE,X_DATE_SEPARATOR,X_CURRENCY_SYMBOL          */
/*   X_DECIMAL_POINT_CHAR,X_TIME_SEPARATOR,X_DOLLAR_SIGN_CHAR        */
/*   X_HASH_SIGN_CHAR,X_AT_SIGN_CHAR,X_GEN_AT_SIGN_CHAR              */
/*   X_STANDARD_MESSAGE_FILE                                         */
/*                                                                   */
/* can be set from the LANSA X_RUN command or as a system environment*/
/* variable. The order of precedence for the setting of these values */
/* is :                                                              */
/*                                                                   */
/*   (1). Values specified in XENV= parameters on the X_RUN command. */
/*   (2). Values specified in normal system environment variables.   */
/*   (3). Multi-national Values specified in Development Environment */
/*   (4). Values specified in this file.                             */
/*                                                                   */
/*                                                                   */
/* For example, say that you needed to set the X_CENTURY_LESS_DATE   */
/* value to "20". You can do this using 3 different methods. These   */
/* methods can be used independently or together :                   */
/*                                                                   */
/* (1). Specify the value in this file by changing the line below    */
/*      to #define X_CENTURY_LESS_DATE "20" and then recompining     */
/*      all entry point processes in your application, This will     */
/*      effectively lock you application into this value. However,   */
/*      this value will not normally be used by application pieces   */
/*      running in super-server mode or as services to LANSA/Server  */
/*      applications because they do not have the concept of an      */
/*      entry point process available to them. In such cases         */
/*      you should use option(2) or (3) as well to achieve the       */
/*      required results in all situations.                          */
/*                                                                   */
/* (2). Set an environment variable for the environment in which     */
/*      application is executing. By putting the operating system    */
/*      command SET X_CENTURY_LESS_DATE=20 into your operating       */
/*      system start up you can cause the appropriate value to be    */
/*      set. A value set this way overrides any value specified by   */
/*      method 1. When setting a value this way you should take care */
/*      to ensure that value is appropriate and valid as no form of  */
/*      validation is applied to the value specified.                */
/*                                                                   */
/* (3). Set a LANSA environment variable by putting the value into   */
/*      the X_RUN command. For example, X_RUN PROC=TEST LANG=ENG     */
/*      XENV=X_CENTURY_LESS_DATE=20 XENV=X_AUTOMATIC_HELP=Y will     */
/*      set the century compare date and automatic help option to    */
/*      the values specified, overriding anything specified by       */
/*      environment variables (method 2) or in this file (method 1). */
/*      Note that a value set this way overrides any value set by    */
/*      method 1 or by method 2.When setting a value this way you    */
/*      should take care to ensure that value is appropriate and     */
/*      valid as no form of validation is applied to the value you   */
/*      specify.                                                     */
/*                                                                   */
/*                                                                   */
/* There is a fourth method of obtaining the multinational values    */
/* X_DOLLAR_SIGN_CHAR, X_HASH_SIGN_CHAR and X_AT_SIGN_CHAR. These    */
/* values are obtained from the LANSAPC registry entry.              */
/* This is primarily used for LANSA objects that are used to extend  */
/* the Development Environment. For example the Deployment Tool.     */
/*                                                                   */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* WARNING   WARNING  WARNING  WARNING  WARNING  WARNING  WARNING    */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/*                                                                   */
/*                                                                   */
/* Source File         : X_DEFJPN.H                                  */
/* OS/Dependencies     : Yes                                         */
/* End User Modifiable : Yes                                         */
/* Description         : LANSA User Definable Partition Level        */
/*                       Default Values                              */
/*                       This should be copied for each partition    */
/*                       and changed as required e.g. copy for       */
/*                       partition DEM as X_DEFDEM.H                 */
/*                                                                   */
/* Amendment History   :                                             */
/*                                                                   */
/* Task Id  Date    Description                                      */
/* =======  ====    ===========                                      */
/*  2634  94/08/04  Remove X_SYSTEM_DATE_FORMAT.                     */
/*        95/08/28  X_DOLLAR_SIGN_CHAR, X_HASH_SIGN_CHAR,            */
/*                  X_AT_SIGN_CHAR and X_STANDARD_MESSAGE_FILE are   */
/*                  now dependent on operating system to allow for   */
/*                  code page differences.                           */
/*  3730  96/02/08  X_GEN_AT_SIGN_CHAR added.                        */
/* ================================================================= */

#define X_SYSTEM_OWNER               "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* Special value *DATABASE indicates that the  */
                             /* value from the LX_F96 table column X96OWN   */
                             /* should be used                              */

#define X_SPECIAL_SECURITY_OFFICER   "QSECOFR"
                             /* max. "xxxxxxxxxx"                           */
                             /* Special value *DATABASE indicates that the  */
                             /* special security officer should be set to   */
                             /* the same value as the system owner.         */

#define X_PARTITION_SECURITY_OFFICER "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* Special value *DATABASE indicates that the  */
                             /* value from the LX_F46 table column X46SEC   */
                             /* associated with the current partition       */
                             /* should be used                              */

#define X_GROUP_AUTHORITY            "*ALL"
                             /* max. "xxxxxxxxxx" */

#define X_AUTOMATIC_HELP             NO
                             /* max. 'x'          */

#define X_CENTURY_COMPARE_DATE       "40"
                             /* max. "xx"         */

#define X_CENTURY_GREATER_DATE       "19"
                             /* max. "xx"         */

#define X_CENTURY_LESS_DATE          "20"
                             /* max. "xx"         */

#define X_DATE_SEPARATOR             '/'
                             /* max. 'x'          */

#define X_CURRENCY_SYMBOL            '\\'
                             /* max. 'x'          */

#define X_DECIMAL_POINT_CHAR         '.'
                             /* max. 'x'          */

#define X_TIME_SEPARATOR             ':'
                             /* max. 'x'          */

/* ================================================================= */
/*                                                                   */
/* The below X_FILE_SECURITY_DISABLED, X_PROCESS_SECURITY_DISABLED   */
/* and X_FUNCTION_SECURITY_DISABLED are set to a default value of    */
/* 'D' (Dynamic) which indicates that the value is retrieved from    */
/* internal file LX_F96 at runtime.  The System Owner or Partition   */
/* Security Officer can set these values from the System Maintenance */
/* option on the Visual LANSA main window, but if connecting to an   */
/* iSeries master, these values will be overwritten by any           */
/* subsequent System Initialisation (Plug-in or Refresh).            */
/*                                                                   */
/* ================================================================= */

#define X_FILE_SECURITY_DISABLED     'D'
                             /* max. 'x'          */

#define X_PROCESS_SECURITY_DISABLED  'D'
                             /* max. 'x'          */

#define X_FUNCTION_SECURITY_DISABLED 'D'
                             /* max. 'x'          */

/* ================================================================= */
/*                                                                   */
/* The following are special characters/strings required for         */
/* multinational character set conversion from ASCII to EBCDIC.      */
/*                                                                   */
/* NOTE : These special characters must be specified for each target */
/* ----   operating system.                                          */
/*                                                                   */
/*        Extreme care must be taken to specify the correct          */
/*        character for each operating system as the character may   */
/*        be different for each of the OS2 (OS/2), WIN31(Windows 3.1)*/
/*        and WIN95(Windows 95) operating systems.                   */
/*        environments.                                              */
/*                                                                   */
/*        Take the time to ensure that all values are thoroughly     */
/*        checked for correctness for each operating system.         */
/*                                                                   */
/*        Values should be entered in hexadecimal as these values    */
/*        are unequivocal and cannot be corrupted by code page       */
/*        variations.                                                */
/*                                                                   */
/* The X_STANDARD_MESSAGE_FILE string is the name of the standard    */
/* message file. The special character "@" contained in it is the    */
/* character that when converted via the translation tables          */
/* specified using PCMAINT (Translation Table In), LANSA/SuperServer */
/* (Client-to-Server conversion table) and SLLLL000.DAT conversion   */
/* table is converted to hex X'7C'.                                  */
/*                                                                   */
/* The X_DOLLAR_SIGN_CHAR is NOT a currency symbol, it is the        */
/* character that when converted via the translation table specified */
/* using PCMAINT (Translation Table In), LANSA/SuperServer           */
/* (Client-to-Server conversion table) and SLLLL000.DAT conversion   */
/* table is converted to hex X'5B'.                                  */
/*                                                                   */
/* The X_HASH_SIGN_CHAR is the character that when converted via the */
/* translation table specified using PCMAINT (Translation Table In), */
/* LANSA/SuperServer (Client-to-Server conversion table) and         */
/* SLLLL000.DAT conversion table is converted to hex X'7B'.          */
/*                                                                   */
/* The X_AT_SIGN_CHAR is the character that when converted via the   */
/* translation table specified using PCMAINT (Translation Table In), */
/* LANSA/SuperServer (Client-to-Server conversion table) and         */
/* SLLLL000.DAT conversion table is converted to hex X'7C'.          */
/*                                                                   */
/* ================================================================= */

/* The X_GEN_AT_SIGN_CHAR is not operating system specific.          */
/* It should be set to the X_AT_SIGN_CHAR value for the operating    */
/* system where code is generated (OS/2 or Windows 95).              */


#define X_GEN_AT_SIGN_CHAR           '\x40'
                             /* max. 1 character   */


      // All Windows 

#if defined(X_OS_WIN)

#define X_STANDARD_MESSAGE_FILE      "\x44\x43\x40\x4D\x30\x31"
                             /* max. 10 characters */

#define X_DOLLAR_SIGN_CHAR           '\x5c'
                             /* max. 1 character   */

#define X_HASH_SIGN_CHAR             '\x23'
                             /* max. 1 character   */

#define X_AT_SIGN_CHAR               '\x40'
                             /* max. 1 character   */
#endif


         /* Unix / AIX */

#if defined(X_OPERATING_SYSTEM_UNIX)

#define X_STANDARD_MESSAGE_FILE      "\x44\x43\x40\x4D\x30\x31"
                             /* max. 10 characters */

#define X_DOLLAR_SIGN_CHAR           '\x5c'
                             /* max. 1 character   */

#define X_HASH_SIGN_CHAR             '\x23'
                             /* max. 1 character   */

#define X_AT_SIGN_CHAR               '\x40'
                             /* max. 1 character   */

#endif
