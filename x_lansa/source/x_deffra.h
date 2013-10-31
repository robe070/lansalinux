/* ================================================================= */
/* ======= LANSA FOR WINDOWS PARTITION LEVEL DEFINITIONS =========== */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/*  ATTENTION  ATTENTION  ATTENTION  ATTENTION  ATTENTION  ATTENTION */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/*                                                                   */
/*  Pour toute modification effectu�e dans les param�tres de ce      */
/*  fichier X_DEFPPP.H, o� PPP est l'identifiant de la partition     */
/*  Vous devez (re)compiler TOUS LES PROCESS "POINT D'ENTREE".       */
/*                                                                   */
/*  Quand TOUS LES PROCESS "POINT D'ENTREE" ont �t� (re)compil�s     */
/*  vous devrez quitter et relancer votre application LANSA          */
/*  afin que les nouvelles valeurs soient prises en compte.          */
/*                                                                   */
/* ================================================================= */
/*                                                                   */
/*  ATTENTION : l'iSeries n'utilise pas ce fichier. Toutes les       */
/*  valeurs sont lues dans les data area de LANSA for iSeries ou de  */
/*  valeurs syst�me. Consutez les guides LANSA pour plus             */
/*  d'informations.                                                  */
/* ================================================================= */
/*  NB : les valeurs par d�faut suivantes sont initialis�es � partir */
/*  des param�tres de Microsoft Windows. Aussi les valeurs de ce     */
/*  fichier seront ignor�es.                                         */
/*  Consultez la documentation LANSA pour plus d'informations sur    */
/*  le moyen de ne pas utiliser ces valeurs par d�faut et utiliser   */
/*  les valeurs de ce fichier.                                       */
/* ================================================================= */
/*                                                                   */
/* X_DATE_SEPARATOR, X_CURRENCY_SYMBOL, X_DECIMAL_POINT_CHAR,        */
/* X_TIME_SEPARATOR                                                  */
/*                                                                   */
/* ================================================================= */
/*           Vous devriez �galement noter que ces valeurs            */
/* ================================================================= */
/*                                                                   */
/*   X_AUTOMATIC_HELP,X_CENTURY_COMPARE_DATE,X_CENTURY_GREATER_DATE  */
/*   X_CENTURY_LESS_DATE,X_DATE_SEPARATOR,X_CURRENCY_SYMBOL          */
/*   X_DECIMAL_POINT_CHAR,X_TIME_SEPARATOR,X_DOLLAR_SIGN_CHAR        */
/*   X_HASH_SIGN_CHAR,X_AT_SIGN_CHAR,X_GEN_AT_SIGN_CHAR              */
/*   X_STANDARD_MESSAGE_FILE                                         */
/*                                                                   */
/* peuvent �tre fix�es � partir de la commande LANSA X_RUN ou une    */
/* variable syst�me d'environnement. L'ordre d'initialisation de     */
/* ces variables est :                                               */
/*                                                                   */
/*   (1). Valeurs pr�cis�es par les param�tres XENV= de la commande  */
/*        X_RUN command.                                             */
/*   (2). Valeurs pr�cis�es par les variables syst�me                */
/*        d'environnement.                                           */
/*   (3), Valeurs pr�cis�es dans ce fichier.                         */
/*                                                                   */
/*                                                                   */
/* Par exemple, si vous voulez fixer la variable X_CENTURY_LESS_DATE */
/* � "20". Vous pouvez le faire de trois fa�ons diff�rentes. Ces     */
/* m�thodes peuvent �tre utilis�es ind�pendamment ou ensemble :      */
/*                                                                   */
/* (1). Pr�cisez la valeur dans ce fichier en modifiant la ligne     */
/*      ci-dessous en #define X_CENTURY_LESS_DATE "20" puis          */
/*      recompilez tous les process point d'entr�e de votre          */
/*      application, ce qui affectera la valeur � votre application  */
/*      Toutefois, cette valeur ne sera pas utilis�e par les         */
/*      �l�ments de l'application fonctionnant en mode super-serveur */
/*      ou en tant que services pour les applications LANSA/Server   */
/*      car elles n'ont pas de process point d'entr�e. Dans ce cas   */
/*      utilisez les options (2) ou (3) pour obtenir le r�sultat     */
/*      souhait� dans toutes les situations.                         */
/*                                                                   */
/* (2). Cr�ez une variable dans l'environnement d'ex�cution de       */
/*      l'application. En d�finissant dans le syst�me d'exploitation */
/*      la commande SET X_CENTURY_LESS_DATE=20 lors du d�marrage     */
/*      vous pourrez forcer l'utilisation d'une valeur correcte de   */
/*      cette variable. La valeur ainsi d�finie se substitue aux     */
/*      valeurs d�finies selon la m�thode 1. Attention � v�rifier    */
/*      la validit� de la variable car aucune v�rification ne sera   */
/*      effectu�e.                                                   */
/*                                                                   */
/* (3). D�finissez une variable d'environnement LANSA en pla�ant la  */
/*      valeur dans la commande X_RUN. Par exemple, X_RUN PROC=TEST  */
/*      LANG=ENG XENV=X_CENTURY_LESS_DATE=20 XENV=X_AUTOMATIC_HELP=Y */
/*      permet de d�finir la valeur de comparaison pour d�finition   */
/*      du si�cle et l'option d'aide automatique en se substituant   */
/*      aux variables d'environnement (m�thode 2) ou dans ce fichier */
/*      (methode 1). NB: une valeur ainsi fix�e remplace toute       */
/*      valeur fix�e selon la m�thode 1 ou la m�thode 2. Attention � */
/*      v�rifier la validit� de la variable car aucune v�rification  */
/*      ne sera effectu�e.                                           */
/*                                                                   */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/*  ATTENTION  ATTENTION  ATTENTION  ATTENTION  ATTENTION  ATTENTION */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/* ================================================================= */
/*                                                                   */
/* Fichier source                : X_DEFXXX.H                        */
/* D�pendant du syst. d'exploit. : Oui                               */
/* Modifiable par l'utilisateur  : Oui                               */
/* Description         : Valeurs par d�faut des param�tres de LANSA  */
/*                       d�finissables au niveau de la partition     */
/*                       Ce fichier doit exister pour chaque parti-  */
/*                       -tionsous le nom X_DEFXXX.H ou XXX est l'ID */
/*                       de partition, exple pour DEM, X_DEFDEM.H    */
/*                                                                   */
/* Historique des modifications  :                                   */
/*                                                                   */
/* Id t�che Date    Description                                      */
/* ========  ====    ===========                                     */
/*  2634  94/08/04  Suppression de X_SYSTEM_DATE_FORMAT.             */
/*        95/08/28  X_DOLLAR_SIGN_CHAR, X_HASH_SIGN_CHAR,            */
/*                  X_AT_SIGN_CHAR et X_STANDARD_MESSAGE_FILE sont   */
/*                  maintenant d�pendants du syst�me d'exploitation  */
/*                  pour prendre en compte les pages de code.        */
/*  3730  96/02/08  X_GEN_AT_SIGN_CHAR ajout�es.                     */
/* ================================================================= */
/* ================================================================= */
/*                                                                   */
/* ATTENTION : CE FICHIER EST ADAPTE POUR POUVOIR CONVENIR EN FRANCE */
/*                                                                   */
/*   A UN AS/400 EN PAGE DE CODE 297 ET A UN PC EN PAGE DE CODE 850  */
/*                                                                   */
/*      Environnement de d�v WINDOWS                                                             */
/*                                                                   */
/* ================================================================= */

#define X_SYSTEM_OWNER               "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* La valeur particuli�re *DATABASE indique    */
                             /* que la valeur de la colonne X96OWN de la    */
                             /* table LX_F96  devra �tre utilis�e           */

#define X_SPECIAL_SECURITY_OFFICER   "QSECOFR"
                             /* max. "xxxxxxxxxx"                           */
                             /* La valeur particuli�re *DATABASE indique    */
                             /* que l'officier de s�curit� particulier doit */
                             /* �tre identique au propri�taire du syst�me.  */

#define X_PARTITION_SECURITY_OFFICER "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* La valeur particuli�re *DATABASE indique    */
                             /* que la valeur de la colonne X46SEC de la    */
                             /* table LX_F46 de la partition en cours devra */
                             /* �tre utilis�e                               */

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

/* modification : valeur initiale    '$'                      */
#define X_CURRENCY_SYMBOL            'F'
                             /* max. 'x'          */

/* modification : valeur initiale    '.'                      */
#define X_DECIMAL_POINT_CHAR         ','
                             /* max. 'x'          */

#define X_TIME_SEPARATOR             ':'
                             /* max. 'x'          */

/* Param�tre supprim� en LANSA/X V1.30                                     */
/* -----------------------------------                                     */
/* Le format de date est maintenant uniquement sp�cifi� par le param�tre   */
/* DATF de la commande X_RUN . La valeur par d�faut de DATF est lue dans   */
/* la valeur de la colonne X96SDF de la table syst�me LX_F96.              */

/* #define X_SYSTEM_DATE_FORMAT         "DMY"                   */
/*                                 max. "xxx"                   */

/* ================================================================= */
/*                                                                   */
/* Les valeurs X_FILE_SECURITY_DISABLED, X_PROCESS_SECURITY_DISABLED */
/* et X_FUNCTION_SECURITY_DISABLED sont initialis�es par d�faut �    */
/* 'D' (Dynamique) qui indique que la valeur est lue dans le fichier */
/* interne LX_F96 � l'ex�cution.  Le propri�taire syst�me ou         */
/* l'officier de s�curit� de la partition peuvent modifier ces       */
/* valeurs � partir de l'option de maintenance syst�me de la fen�tre */
/* principale de Visual LANSA, mais si vous �tes connect�s � un h�te */
/* iSeries, ces valeurs seront remplac�es par toute initialisation   */
/* ult�rieure du syst�me (Plug-in ou Refresh).                       */
/*                                                                   */
/* ================================================================= */

#define X_FILE_SECURITY_DISABLED     'D'
                             /* max. 'x'          */

#define X_PROCESS_SECURITY_DISABLED  'D'
                             /* max. 'x'          */

#define X_FUNCTION_SECURITY_DISABLED 'D'
                             /* max. 'x'          */

/* =================================================================  */
/*                                                                    */
/* Les param�tres suivants sont des valeurs hexad�cimales n�cessaires */
/* pour la conversion ASCII/ANSI <> EBCDIC. Ces valeurs sont en fait  */
/* le code hexadecimal du/des caract�res PC qui permet d'obtenir sur  */
/* l'AS/400 un certain caract�re hexad�cimal en le convertissant :    */
/* - soit par la table ASCII-EBCDIC du menu PCMAINT + �ventuellement  */
/*   au pr�alable la correction via la table SLLLL000.dat.            */
/* - soit par la table Client>Serveur utilis�e dans Super-Serveur,    */
/*   REFRESH, PLUGIN .....                                            */
/*                                                                    */
/* NOTE : Ces caract�res doivent �tre d�finis pour chaque syst�me     */
/* ----   d'exploitation.                                             */
/*                                                                    */
/*        V�rifiez bien les caract�res saisis pour CHAQUE syst�me     */
/*        d'exploitation : OS2 (OS/2), WIN31(Windows 3.1) ou WIN95    */
/*        (Windows 95 ou NT)                                          */
/*        environments.                                               */
/*                                                                    */
/*        Toutes les valeurs doivent �tre saisies en hexad�cimal      */
/*        afin de n'�tre pas affect�es par les syst�mes mixtes.       */
/*                                                                    */
/*                                                                    */
/* X_DOLLAR_SIGN_CHAR n'est pas le symbole mon�taire, c'est le code   */
/* hexa du caract�re PC qui �tant converti avec l'une des tables      */
/* pr�cis�es ci-dessus) donne le caract�re AS/400 X'5B'.              */
/*                                                                    */
/* X_HASH_SIGN_CHAR est le code du caract�re qui �tant converti avec  */
/* l'une des tables pr�cis�es ci-dessus) donne le caract�re AS/400    */
/* X'7B'.                                                             */
/*                                                                    */
/* X_AT_SIGN_CHAR est le code du caract�re qui �tant converti avec    */
/* l'une des tables pr�cis�es ci-dessus) donne le caract�re AS/400    */
/* X'7C'.                                                             */
/*                                                                    */
/* X_STANDARD_MESSAGE_FILE est le nom du fichier de messages syst�me. */
/* En fait le caract�re "� probl�me" est le caract�re pr�cedent, @ ou */
/* suivant la page de code c'est � dire en hexa X'7C'.                */
/* ================================================================== */

/* X_GEN_AT_SIGN_CHAR n'est pas li� au syst�me d'exploitation cible   */
/* mais plut�t au syst�me d'exploitation de g�n�ration (OS2 ou W95)   */
/* Il doit �tre �gal � la valeur X_AT_SIGN_CHAR de ce syst�me         */
/* d'exploitation                                                     */


/* Si AS400 037 ou 500, le car. AS400 est @, la valeur doit �tre '\x40'  */
/* Si AS400 297 le car. est �,   si g�n�ration � partir d'OS/2    '\x85' */
/*                              si g�n�ration � partir de windows '\xE0' */

#define X_GEN_AT_SIGN_CHAR           '\xE0'
                             /* max. 1 character   */

      // All Windows 

      // Leave as W95 for backward compatibility with prior installations

#if defined(X_OPERATING_SYSTEM_WIN95)

/* Si AS400 037 ou 500, le fichier est DC@M01 =>  "\x44\x43\x40\x4D\x30\x31"*/
/* Si AS400 297 le fichier est DC�M01 =>          "\x44\x43\xE0\x4D\x30\x31"*/
#define X_STANDARD_MESSAGE_FILE      "\x44\x43\xE0\x4D\x30\x31"
                             /* max. 10 characters */

#define X_DOLLAR_SIGN_CHAR           '\x24'
                             /* max. 1 character   */

/* Si AS400 037 ou 500, le car. AS400 est #, la valeur doit �tre '\x23'  */
/* Si AS400 297 le car. est �,  la valeur doit �tre '\xA3'               */
#define X_HASH_SIGN_CHAR             '\xA3'
                             /* max. 1 character   */

/* Sur AS400 037 ou 500, le car. AS400 est @, la valeur doit �tre '\x40' */
/* Sur AS400 297 le car. AS400  est �, la valeur doit �tre        '\xE0' */
#define X_AT_SIGN_CHAR               '\xE0'
                             /* max. 1 character   */
#endif



         /* Unix / AIX */

#if defined(X_OPERATING_SYSTEM_UNIX)

#define X_STANDARD_MESSAGE_FILE      "\x44\x43\xE0\x4D\x30\x31"
                             /* max. 10 characters */

#define X_DOLLAR_SIGN_CHAR           '\x24'
                             /* max. 1 character   */

#define X_HASH_SIGN_CHAR             '\xA3'
                             /* max. 1 character   */

#define X_AT_SIGN_CHAR               '\xE0'
                             /* max. 1 character   */

#endif
