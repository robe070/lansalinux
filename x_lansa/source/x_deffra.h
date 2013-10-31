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
/*  Pour toute modification effectuée dans les paramètres de ce      */
/*  fichier X_DEFPPP.H, où PPP est l'identifiant de la partition     */
/*  Vous devez (re)compiler TOUS LES PROCESS "POINT D'ENTREE".       */
/*                                                                   */
/*  Quand TOUS LES PROCESS "POINT D'ENTREE" ont été (re)compilés     */
/*  vous devrez quitter et relancer votre application LANSA          */
/*  afin que les nouvelles valeurs soient prises en compte.          */
/*                                                                   */
/* ================================================================= */
/*                                                                   */
/*  ATTENTION : l'iSeries n'utilise pas ce fichier. Toutes les       */
/*  valeurs sont lues dans les data area de LANSA for iSeries ou de  */
/*  valeurs système. Consutez les guides LANSA pour plus             */
/*  d'informations.                                                  */
/* ================================================================= */
/*  NB : les valeurs par défaut suivantes sont initialisées à partir */
/*  des paramètres de Microsoft Windows. Aussi les valeurs de ce     */
/*  fichier seront ignorées.                                         */
/*  Consultez la documentation LANSA pour plus d'informations sur    */
/*  le moyen de ne pas utiliser ces valeurs par défaut et utiliser   */
/*  les valeurs de ce fichier.                                       */
/* ================================================================= */
/*                                                                   */
/* X_DATE_SEPARATOR, X_CURRENCY_SYMBOL, X_DECIMAL_POINT_CHAR,        */
/* X_TIME_SEPARATOR                                                  */
/*                                                                   */
/* ================================================================= */
/*           Vous devriez également noter que ces valeurs            */
/* ================================================================= */
/*                                                                   */
/*   X_AUTOMATIC_HELP,X_CENTURY_COMPARE_DATE,X_CENTURY_GREATER_DATE  */
/*   X_CENTURY_LESS_DATE,X_DATE_SEPARATOR,X_CURRENCY_SYMBOL          */
/*   X_DECIMAL_POINT_CHAR,X_TIME_SEPARATOR,X_DOLLAR_SIGN_CHAR        */
/*   X_HASH_SIGN_CHAR,X_AT_SIGN_CHAR,X_GEN_AT_SIGN_CHAR              */
/*   X_STANDARD_MESSAGE_FILE                                         */
/*                                                                   */
/* peuvent être fixées à partir de la commande LANSA X_RUN ou une    */
/* variable système d'environnement. L'ordre d'initialisation de     */
/* ces variables est :                                               */
/*                                                                   */
/*   (1). Valeurs précisées par les paramètres XENV= de la commande  */
/*        X_RUN command.                                             */
/*   (2). Valeurs précisées par les variables système                */
/*        d'environnement.                                           */
/*   (3), Valeurs précisées dans ce fichier.                         */
/*                                                                   */
/*                                                                   */
/* Par exemple, si vous voulez fixer la variable X_CENTURY_LESS_DATE */
/* à "20". Vous pouvez le faire de trois façons différentes. Ces     */
/* méthodes peuvent être utilisées indépendamment ou ensemble :      */
/*                                                                   */
/* (1). Précisez la valeur dans ce fichier en modifiant la ligne     */
/*      ci-dessous en #define X_CENTURY_LESS_DATE "20" puis          */
/*      recompilez tous les process point d'entrée de votre          */
/*      application, ce qui affectera la valeur à votre application  */
/*      Toutefois, cette valeur ne sera pas utilisée par les         */
/*      éléments de l'application fonctionnant en mode super-serveur */
/*      ou en tant que services pour les applications LANSA/Server   */
/*      car elles n'ont pas de process point d'entrée. Dans ce cas   */
/*      utilisez les options (2) ou (3) pour obtenir le résultat     */
/*      souhaité dans toutes les situations.                         */
/*                                                                   */
/* (2). Créez une variable dans l'environnement d'exécution de       */
/*      l'application. En définissant dans le système d'exploitation */
/*      la commande SET X_CENTURY_LESS_DATE=20 lors du démarrage     */
/*      vous pourrez forcer l'utilisation d'une valeur correcte de   */
/*      cette variable. La valeur ainsi définie se substitue aux     */
/*      valeurs définies selon la méthode 1. Attention à vérifier    */
/*      la validité de la variable car aucune vérification ne sera   */
/*      effectuée.                                                   */
/*                                                                   */
/* (3). Définissez une variable d'environnement LANSA en plaçant la  */
/*      valeur dans la commande X_RUN. Par exemple, X_RUN PROC=TEST  */
/*      LANG=ENG XENV=X_CENTURY_LESS_DATE=20 XENV=X_AUTOMATIC_HELP=Y */
/*      permet de définir la valeur de comparaison pour définition   */
/*      du siècle et l'option d'aide automatique en se substituant   */
/*      aux variables d'environnement (méthode 2) ou dans ce fichier */
/*      (methode 1). NB: une valeur ainsi fixée remplace toute       */
/*      valeur fixée selon la méthode 1 ou la méthode 2. Attention à */
/*      vérifier la validité de la variable car aucune vérification  */
/*      ne sera effectuée.                                           */
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
/* Dépendant du syst. d'exploit. : Oui                               */
/* Modifiable par l'utilisateur  : Oui                               */
/* Description         : Valeurs par défaut des paramètres de LANSA  */
/*                       définissables au niveau de la partition     */
/*                       Ce fichier doit exister pour chaque parti-  */
/*                       -tionsous le nom X_DEFXXX.H ou XXX est l'ID */
/*                       de partition, exple pour DEM, X_DEFDEM.H    */
/*                                                                   */
/* Historique des modifications  :                                   */
/*                                                                   */
/* Id tâche Date    Description                                      */
/* ========  ====    ===========                                     */
/*  2634  94/08/04  Suppression de X_SYSTEM_DATE_FORMAT.             */
/*        95/08/28  X_DOLLAR_SIGN_CHAR, X_HASH_SIGN_CHAR,            */
/*                  X_AT_SIGN_CHAR et X_STANDARD_MESSAGE_FILE sont   */
/*                  maintenant dépendants du système d'exploitation  */
/*                  pour prendre en compte les pages de code.        */
/*  3730  96/02/08  X_GEN_AT_SIGN_CHAR ajoutées.                     */
/* ================================================================= */
/* ================================================================= */
/*                                                                   */
/* ATTENTION : CE FICHIER EST ADAPTE POUR POUVOIR CONVENIR EN FRANCE */
/*                                                                   */
/*   A UN AS/400 EN PAGE DE CODE 297 ET A UN PC EN PAGE DE CODE 850  */
/*                                                                   */
/*      Environnement de dév WINDOWS                                                             */
/*                                                                   */
/* ================================================================= */

#define X_SYSTEM_OWNER               "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* La valeur particulière *DATABASE indique    */
                             /* que la valeur de la colonne X96OWN de la    */
                             /* table LX_F96  devra être utilisée           */

#define X_SPECIAL_SECURITY_OFFICER   "QSECOFR"
                             /* max. "xxxxxxxxxx"                           */
                             /* La valeur particulière *DATABASE indique    */
                             /* que l'officier de sécurité particulier doit */
                             /* être identique au propriétaire du système.  */

#define X_PARTITION_SECURITY_OFFICER "*DATABASE"
                             /* max. "xxxxxxxxxx"                           */
                             /* La valeur particulière *DATABASE indique    */
                             /* que la valeur de la colonne X46SEC de la    */
                             /* table LX_F46 de la partition en cours devra */
                             /* être utilisée                               */

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

/* Paramètre supprimé en LANSA/X V1.30                                     */
/* -----------------------------------                                     */
/* Le format de date est maintenant uniquement spécifié par le paramètre   */
/* DATF de la commande X_RUN . La valeur par défaut de DATF est lue dans   */
/* la valeur de la colonne X96SDF de la table système LX_F96.              */

/* #define X_SYSTEM_DATE_FORMAT         "DMY"                   */
/*                                 max. "xxx"                   */

/* ================================================================= */
/*                                                                   */
/* Les valeurs X_FILE_SECURITY_DISABLED, X_PROCESS_SECURITY_DISABLED */
/* et X_FUNCTION_SECURITY_DISABLED sont initialisées par défaut à    */
/* 'D' (Dynamique) qui indique que la valeur est lue dans le fichier */
/* interne LX_F96 à l'exécution.  Le propriétaire système ou         */
/* l'officier de sécurité de la partition peuvent modifier ces       */
/* valeurs à partir de l'option de maintenance système de la fenêtre */
/* principale de Visual LANSA, mais si vous êtes connectés à un hôte */
/* iSeries, ces valeurs seront remplacées par toute initialisation   */
/* ultérieure du système (Plug-in ou Refresh).                       */
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
/* Les paramètres suivants sont des valeurs hexadécimales nécessaires */
/* pour la conversion ASCII/ANSI <> EBCDIC. Ces valeurs sont en fait  */
/* le code hexadecimal du/des caractères PC qui permet d'obtenir sur  */
/* l'AS/400 un certain caractère hexadécimal en le convertissant :    */
/* - soit par la table ASCII-EBCDIC du menu PCMAINT + éventuellement  */
/*   au préalable la correction via la table SLLLL000.dat.            */
/* - soit par la table Client>Serveur utilisée dans Super-Serveur,    */
/*   REFRESH, PLUGIN .....                                            */
/*                                                                    */
/* NOTE : Ces caractères doivent être définis pour chaque système     */
/* ----   d'exploitation.                                             */
/*                                                                    */
/*        Vérifiez bien les caractères saisis pour CHAQUE système     */
/*        d'exploitation : OS2 (OS/2), WIN31(Windows 3.1) ou WIN95    */
/*        (Windows 95 ou NT)                                          */
/*        environments.                                               */
/*                                                                    */
/*        Toutes les valeurs doivent être saisies en hexadécimal      */
/*        afin de n'être pas affectées par les systèmes mixtes.       */
/*                                                                    */
/*                                                                    */
/* X_DOLLAR_SIGN_CHAR n'est pas le symbole monétaire, c'est le code   */
/* hexa du caractère PC qui étant converti avec l'une des tables      */
/* précisées ci-dessus) donne le caractère AS/400 X'5B'.              */
/*                                                                    */
/* X_HASH_SIGN_CHAR est le code du caractère qui étant converti avec  */
/* l'une des tables précisées ci-dessus) donne le caractère AS/400    */
/* X'7B'.                                                             */
/*                                                                    */
/* X_AT_SIGN_CHAR est le code du caractère qui étant converti avec    */
/* l'une des tables précisées ci-dessus) donne le caractère AS/400    */
/* X'7C'.                                                             */
/*                                                                    */
/* X_STANDARD_MESSAGE_FILE est le nom du fichier de messages système. */
/* En fait le caractère "à problème" est le caractère précedent, @ ou */
/* suivant la page de code c'est à dire en hexa X'7C'.                */
/* ================================================================== */

/* X_GEN_AT_SIGN_CHAR n'est pas lié au système d'exploitation cible   */
/* mais plutôt au système d'exploitation de génération (OS2 ou W95)   */
/* Il doit être égal à la valeur X_AT_SIGN_CHAR de ce système         */
/* d'exploitation                                                     */


/* Si AS400 037 ou 500, le car. AS400 est @, la valeur doit être '\x40'  */
/* Si AS400 297 le car. est à,   si génération à partir d'OS/2    '\x85' */
/*                              si génération à partir de windows '\xE0' */

#define X_GEN_AT_SIGN_CHAR           '\xE0'
                             /* max. 1 character   */

      // All Windows 

      // Leave as W95 for backward compatibility with prior installations

#if defined(X_OPERATING_SYSTEM_WIN95)

/* Si AS400 037 ou 500, le fichier est DC@M01 =>  "\x44\x43\x40\x4D\x30\x31"*/
/* Si AS400 297 le fichier est DCàM01 =>          "\x44\x43\xE0\x4D\x30\x31"*/
#define X_STANDARD_MESSAGE_FILE      "\x44\x43\xE0\x4D\x30\x31"
                             /* max. 10 characters */

#define X_DOLLAR_SIGN_CHAR           '\x24'
                             /* max. 1 character   */

/* Si AS400 037 ou 500, le car. AS400 est #, la valeur doit être '\x23'  */
/* Si AS400 297 le car. est £,  la valeur doit être '\xA3'               */
#define X_HASH_SIGN_CHAR             '\xA3'
                             /* max. 1 character   */

/* Sur AS400 037 ou 500, le car. AS400 est @, la valeur doit être '\x40' */
/* Sur AS400 297 le car. AS400  est à, la valeur doit être        '\xE0' */
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
