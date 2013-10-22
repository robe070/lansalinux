#!/bin/sh
##############################################################
# This is the LANSA import script for UNIX and iSeries.
# Copyright (C), 2002 LANSA
##############################################################
#
# USAGE: compobj.sh [partition objtype objname userid password Language Dbid Workstation Package DBType Debug CompileAct1 CompileAct2 CompileAct3 Library]
#
# A logfile [workstation]_[package].log will be created in the
# partition source directory.
#
# This script assumes certain standard utilities exist and
# the directories they are in are in the PATH environment
# variable. The usual location is /usr/bin. It also assumes
# that the environment variable LANSAXROOT is defined.
#
# --------------------------------------------------------

# --------------------------------------------------------
# ============  THE ASSUMED STARTING POINT ==============
# --------------------------------------------------------
#
# LANSA has already been installed.
# All source, data, etc has been previously exported to
# the source path from the development environment.
#
# This script has been executed by LP@DPI invoking the
# COMPILE_OBJECT BIF. Independent execution is not supported.
#
# --------------------------------------------------------


# --------------------------------------------------------
# Get the text for messages with embedded variables
# --------------------------------------------------------

getmsgtext()
{
  eval echo "$1"
}

# --------------------------------------------------------
# Set the devnull value to use
# --------------------------------------------------------

getdevnull()
{
  DevNull=/dev/null

  if [ "$Platform" = "OS400" ]; then
    DevNull="$PWD/dev.null"
  fi
}

# --------------------------------------------------------
# Set the echo flag for processing special characters
# --------------------------------------------------------

getechoflag()
{
  E=
  if echo "\c" | grep c >"$DevNull" 2>&1; then
    E='-e'
  fi
}


# --------------------------------------------------------
# Utilities to convert to upper and lower case
# --------------------------------------------------------

uconv()
{
  echo "$1" | tr '[a-z]' '[A-Z]'
}

lconv()
{
  echo "$1" | tr '[A-Z]' '[a-z]'
}

# --------------------------------------------------------
# Get Language Overrides from LX_F60
# --------------------------------------------------------
uGetLanguageDetails()
{
  # Originally, this was to be updated with code to read LX_F60
  LanguageOverrides=
}

# --------------------------------------------------------
# Check if file is a PC Other File
# --------------------------------------------------------
CheckPCOtherFile()
{
  grep DSN= "$1" >"$DevNull" 2>&1

  # File is PC Other File
  if [ "$?" = "0" ]; then
    return 1
  fi

  #File is not PC Other File
  return 0
}

# --------------------------------------------------------
# Remove the Source Files for an Object
# --------------------------------------------------------
RemoveSource()
{
  ObjList=`find . -name "$Base.*"`

  for ObjectSrc in $ObjList; do

    CheckKeepFile

    if [ "$KeepFile" = "N" ]; then
      rm -f "$ObjectSrc" >>"$LogFile" 2>&1
    fi

  done
}

# --------------------------------------------------------
# Check if the Source File should be Kept (regardless)
# --------------------------------------------------------
CheckKeepFile()
{
  KeepFile=N

  for ObjectSfx in .ctd .dat .ret; do

    CompareBase=`basename "$ObjectSrc" "$ObjectSfx"`

    if [ "$KeepFile" = "N" ]; then

      if [ "$CompareBase" = "$Base" ]; then
        KeepFile=Y
      fi

    fi

  done
}

BuildOAM()
{
  echo "(S0022)  `getmsgtext "$S0022"` " >>"$LogFile"

  # Make the new OAM
  make -f "$ObjName.$PSuffix" >>"$LogFile" 2>&1
  if [ "$?" != "0" ]; then
    echo "$N0001: (S0023)  `getmsgtext "$S0023"` $N0027" >>"$LogFile"
    exit 1
  fi

  # Remove the Source
  if [ "$Debug3" != "Y" ]; then
    RemoveSource
  fi
}

if [ -n "$BASH" ]; then
  WaitForFile()
  {
    _waitcnt=0
    while [ $_waitcnt -lt 1200 ]; do # 2 mins
      _waitcnt=$((_waitcnt + 1))
      if [ -f "$1" ]; then break; fi
      echo "`date +'%H:%M:%S.%N'` [ $_waitcnt ] waiting 0.1s for $1" >>"$LogFile"
      usleep 100000 # 0.1 sec
    done
    unset _waitcnt
  }
else
  WaitForFile()
  {
    return
  }
fi

# --------------------------------------------------------
# ============  Start of body of script ==============
# --------------------------------------------------------

# Set the Variables

Part=`lconv $1`
ObjType=`uconv $2`
ObjName=`lconv $3`
UserID="$4/$5"
User="$4"
Pswd="$5"
Language="$6"
Dbid="$7"
Workstation=`lconv $8`
Package=`lconv $9`
DBType="${10}"
Debug="${11}"
if [ "$Debug" = "O" -o "$Debug" = "B" ] ; then 
   Debug3="Y" 
else
   Debug3="N" 
fi
if [ $# -ge 12 ]; then
   CompileAct1="${12}"
else
   # D = Default, i.e. behaviour before Arg 5 added to
   # COMPILE_OBJECT Built-In Function
   CompileAct1=D
fi
if [ $# -ge 13 ]; then
   CompileAct2="${13}"
else
   CompileAct2=D
fi
if [ $# -ge 14 ]; then
   CompileAct3="${14}"
else
   CompileAct3=D
fi

if [ $# -ge 15 ]; then
   Library="${15}"
fi

# Load the Text Variables (should be located together with this script)
X_SCRPTM="`dirname $0`/x_scrptm.dat"
if [ -r "$X_SCRPTM" ]; then
  . "$X_SCRPTM"
else
  echo "File $X_SCRPTM does not exist"
  exit 1
fi

# determine the operating platform
Platform=`uname`

# some platform dependent settings
if [ "$Platform" = "AIX" ]; then
  FIND_OPT=
else
  # to handle if the import directory is a symbolic link
  FIND_OPT=-follow
fi

# Determine dev null to use
getdevnull

# Set echo flag for special characters
getechoflag

# Partition Source Path
PartSourcePath="$LANSAXROOT/x_lansa/x_$Part/source"

# Partition Executeable Path
PartExePath="$LANSAXROOT/x_lansa/x_$Part/bin"

# System Source Path
SysSourcePath="$LANSAXROOT/x_lansa/source"

# Path to ccsid.txt
if [ -f "$PartSourcePath/ccsid.txt" ]; then
  # Use the Partition Override file
  CCSIdTxtPath="$PartSourcePath"
else
  # Use the System level file
  CCSIdTxtPath="$SysSourcePath"
fi
export CCSIdTxtPath

DATE_FMT="%Y/%m/%d %H:%M:%S"

# Logfile
LogFile="${PartSourcePath}/${Workstation}_${Package}.log"

#Language Overrides
uGetLanguageDetails

echo "[ start - `date +"$DATE_FMT"` ]" >>"$LogFile"

# Output a message if Ctrl-C pressed to exit
trap 'echo "[ abort - `date +"$DATE_FMT"` ]" >> "$LogFile"' 0
trap 'trap "" 0; echo "$N033" >>"$LogFile"; exit 1' 1
trap 'trap "" 0; echo "$N033" >>"$LogFile"; exit 2' 2

echo Logfile $LogFile >> $LogFile
echo USAGE: compobj.sh [partition objtype objname userid password Language Dbid Workstation Package DBType Debug CompileAct1 CompileAct2 CompileAct3 Library] >> $LogFile
echo compobj.sh $1 $2 $3 $4 XXXXXXX $6 $7 $8 $9 ${10} ${11} ${12} ${13} ${14} ${15} >> $LogFile
echo Part=$Part ObjType=$ObjType ObjName=$ObjName Debug=$Debug Debug3=$Debug3 >> $LogFile
echo NumArgs=$# Workstation=$Workstation CompileAct1=$CompileAct1 CompileAct2=$CompileAct2 CompileAct3=$CompileAct3 Library=$Library >> $LogFile

# Ensure LANSAXROOT has been defined
if [ "$LANSAXROOT" = "" ]; then
  echo "$N0001: (N0036)  $N0036" >>"$LogFile"
  exit 1
fi

# Set UNIX parameters
PSuffix=unx
DiffCmd="diff -w"
AWK=awk

if [ "$Debug3" != "Y" ]; then
  LNKFLAGS="-s"
fi

if [ "$Platform" = "SunOS" ]; then
  HASH=#
  export HASH
  AWK=nawk
  if [ "$Debug3" = "Y" ]; then
    CMPFLAGS="-g"
  else
    CMPFLAGS="-O"
  fi
fi

if [ "$Platform" = "Linux" ]; then
  HASH=#
  export HASH
  if [ "$Debug3" = "Y" ]; then
    CMPFLAGS="-ggdb"
  else
    CMPFLAGS="-O2"
  fi
fi

if [ "$Debug" = "Y" -o "$Debug" = "B" ] ; then 
  CMPFLAGS="$CMPFLAGS -DX_DEBUG"
fi
export CMPFLAGS LNKFLAGS
export AWK

# --------------------------------------------------------
# Make sure standard directories exist
# --------------------------------------------------------

for d in "" /source /object /bin /web /web/document.cache; do
  TARGET_DIR="${LANSAXROOT}/x_lansa/x_${Part}${d}"
  if [ ! -d "$TARGET_DIR" ]; then
    mkdir "$TARGET_DIR" >>"$LogFile" 2>&1
    chmod g+w "$TARGET_DIR"
  fi
done
unset TARGET_DIR

# ------------------
# Create the Object
# ------------------

# Change to Partition Source
cd "$PartSourcePath" >>"$LogFile" 2>&1
if [ "$?" != "0" ]; then
  echo "$N0001: (S0008)  `getmsgtext "$S0008"` $N0027" >>"$LogFile"
  exit 1
fi

if [ "$ObjType" = "FD" ]; then

# ---------------------------------------------------------------
# Create user defined tables, views, indexes and the related OAM
# ---------------------------------------------------------------

  # Variables defined for substitution in Messages
  File="$ObjName.ctd"
  Base="$ObjName"

  FileSourcePath=$PartSourcePath
  FileExePath=$PartExePath
   
  # Set the .CTD file to be used
  CTDFile="$FileSourcePath/$File"

# -------------------------------------------
# We use Partition source for temporary files
# -------------------------------------------
  rm -f "$PartSourcePath/$ObjName.ret" >"$DevNull" 2>&1
  rm -f "$PartSourcePath/$ObjName.tmp" >"$DevNull" 2>&1
  rm -f "$PartSourcePath/$ObjName.dat" >"$DevNull" 2>&1

  # Set defaults

  Reload=N
  Unload=Y
  DropTable=Y
  DropLogicals=Y
  CreateTable=Y
  CreateLogicals=Y

  # Note: OAM must always be compiled

  # Set compile actions - these match with Deliver To dialog

  # Rebuild table checkbox
  if [ "$CompileAct1" = "N" ]; then
    Unload=N
    DropTable=N
    CreateTable=N
  fi

  # Rebuild indexes and views checkbox
  # Note, if Table is dropped/rebuilt, indexes & views must also be dropped
  if [ "$CompileAct2" = "N" ]; then
    if [ "$DropTable" = "N" ]; then
      DropLogicals=N
      CreateLogicals=N
    fi
  fi

  # Skip unload/table build if it is a PC Other file
  CheckPCOtherFile "$CTDFile"
  if [ "$?" = "1" ]; then
    Unload=N
    DropTable=N
    DropLogicals=N
  fi

  # ----------------------------------------------------------
  # If an OAM exists and appropriate values selected, back up
  # ----------------------------------------------------------

  ExecFile="lib$ObjName.so"
  OldExecFile="$FileExePath/$ExecFile"
  OldOAM=N

  # If Library provided, check in library first, then in partition
  if [ -s $OldExecFile ]; then
    OldOAM=Y
  fi
  
  if [ "$OldOAM" = "Y" ]; then

    # Get internal file name

    if [ -s $CTDFile ]; then
      $AWK -v `grep INTERNAL= "$CTDFile" | head -n 1` '{print INTERNAL; exit}' "$CTDFile" >"$PartSourcePath/$ObjName.int" 2>>"$LogFile"
      Name=`cat "$PartSourcePath/$ObjName.int"` 2>>"$LogFile"
      rm -f "$PartSourcePath/$ObjName.int"

      if [ "$Name" = "" ]; then
        echo "$N0001: (S0013)  `getmsgtext "$S0013"` " >>"$LogFile"
        exit 1
      fi
    else
      echo "$N0001: (S0037)  `getmsgtext "$S0037"` " >>"$LogFile"  
      exit 1
    fi

    # Do the Unload
    if [ "$Unload" = "Y" ]; then
      echo "(S0012)  `getmsgtext "$S0012"` " >>"$LogFile"
      x_run PART="$Part" DBID="$Dbid" USER="$User" DBUS="$User" PSWD="$Pswd" proc='*BIF_UNLOAD_FILE_DATA' LANG="$Language" BRFN="$PartSourcePath/$ObjName.ret" BA01="$Name" BA04=Y BRMX=1 >>"$LogFile" 2>&1
      if [ "$?" != "0" ]; then
        echo "$N0001: (S0014)  `getmsgtext "$S0014"`  $N0027" >>"$LogFile"
        exit 1
      fi

      $AWK -v `grep BIF_RET01= "$PartSourcePath/$ObjName.ret"` '{print BIF_RET01; exit}' "$PartSourcePath/$ObjName.ret" >"$PartSourcePath/$ObjName.tmp" 2>>"$LogFile"
      Ret=`cat "$PartSourcePath/$ObjName.tmp"`

      if [ "$Ret" != "OK" ]; then
        rm -f "$PartSourcePath/$ObjName.dat"
      fi

      if [ "$Ret" = "ER" ]; then
        echo "$N0001: (S0015)  `getmsgtext "$S0015"` $N0027" >>"$LogFile"
        exit 1
      fi

      if [ "$Ret" = "NT" ]; then
        echo "$N0002: (N0050)  $N0050" >>"$LogFile"
        # Table doesn't exist - Reload is already N, but avoid drop as it's not there.
        DropTable=N
        DropLogicals=N
      else
        Reload=Y
      fi

      rm -f "$PartSourcePath/$ObjName.tmp" >"$DevNull" 2>&1
      rm -f "$PartSourcePath/$ObjName.ret" >"$DevNull" 2>&1

    fi #end of Unload is Y

  fi #end of if OAM exists


  # ----------------------------
  # Drop and recreate the table - if required
  # ----------------------------

  if [ -s $CTDFile ]; then
    # Get actual table name
    $AWK -v `grep TABLE= "$CTDFile" | head -n 1` '{print TABLE; exit}' "$CTDFile" >"$PartSourcePath/$ObjName.tab" 2>>"$LogFile"
    TableName=`cat $PartSourcePath/$ObjName.tab` 2>>"$LogFile"
    rm -f "$PartSourcePath/$ObjName.tab"

    # Get actual Collection name
    $AWK -v `grep COLLECTION= "$CTDFile" | head -n 1` '{print COLLECTION; exit}' "$CTDFile" >"$PartSourcePath/$ObjName.col" 2>>"$LogFile"
    Collection=`cat $PartSourcePath/$ObjName.col` 2>>"$LogFile"
    rm -f "$PartSourcePath/$ObjName.col"

  else
    echo "$N0001: (S0037)  `getmsgtext "$S0037"` " >>"$LogFile"  
    exit 1
  fi

  # Set Collection Name for RUNSQL
  TgtLibrary='*DEFAULT'

  if [ "$DropTable" = "Y" ]; then
    echo "(S0016)  `getmsgtext "$S0016"` " >>"$LogFile"

    # Drop the existing table
    if runsql "$CTDFile" "$Dbid" Y F "$DBType" "$UserID" "$LANSAXROOT/x_lansa" "$TgtLibrary" N N Y N >>"$LogFile" 2>&1; then
      echo "(S0017)  `getmsgtext "$S0017"`" >>"$LogFile"
    else
      echo "$N0002: (S0018)  `getmsgtext "$S0018"`  $N0027" >>"$LogFile"
    fi
  else
    if [ "$DropLogicals" = "Y" ]; then
      echo "(S0069)  `getmsgtext "$S0069"` " >>"$LogFile"

      if runsql "$CTDFile" "$Dbid" Y F "$DBType" "$UserID" "$LANSAXROOT/x_lansa" "$TgtLibrary" N N L N >>"$LogFile" 2>&1; then
        echo "(S0070)  `getmsgtext "$S0070"`" >>"$LogFile"
      else
        echo "$N0002: (S0071)  `getmsgtext "$S0071"`  $N0027" >>"$LogFile"
      fi
    fi
  fi

  if [ "$CreateTable" = "Y" -o "$CreateLogicals" = "Y" ]; then

    # Create the table, views, indexes
    echo "(S0019)  `getmsgtext "$S0019"` " >>"$LogFile"

    if runsql "$CTDFile" "$Dbid" Y F "$DBType" "$UserID" "$LANSAXROOT/x_lansa" "$TgtLibrary" >>"$LogFile" 2>&1; then

      # --------------------------------------
      # Build OAM - will exit if compile fails
      # --------------------------------------

      BuildOAM

    else  # runsql failed

      echo "$N0001: (S0025)  `getmsgtext "$S0025"` $N0027" >>"$LogFile"
      echo "`getmsgtext "$S0024"` " >>"$LogFile"
      exit 1

    fi # end of if runsql

  else

    # --------------------------------------
    # Build OAM - will exit if compile fails
    # --------------------------------------

    BuildOAM

  fi # end of if CreateTable

  if [ "$Reload" = "Y" ]; then
    echo "(S0026)  `getmsgtext "$S0026"` " >>"$LogFile"

    x_run PART="$Part" DBID="$Dbid" USER="$User" DBUS="$User" PSWD="$Pswd" proc='*BIF_LOAD_FILE_DATA' LANG="$Language" BRFN="$PartSourcePath/$ObjName.ret" BA01="$Name" BRMX=1 >>"$LogFile" 2>&1

    if [ "$?" != "0" ]; then
      echo "$N0001: (S0027)  `getmsgtext "$S0027"` $N0027" >>"$LogFile"
      echo "`getmsgtext "$S0024"` " >>"$LogFile"
      exit 1
    fi

    $AWK -v `grep BIF_RET01= "$PartSourcePath/$ObjName.ret"` '{print BIF_RET01; exit}' "$PartSourcePath/$ObjName.ret" >"$PartSourcePath/$ObjName.tmp"
    Ret=`cat "$PartSourcePath/$ObjName.tmp"`

    if [ "$Ret" != "OK" ]; then
      cat "$PartSourcePath/$ObjName.ret" >>"$LogFile" 2>&1
      echo "$N0001: (S0028)  `getmsgtext "$S0028"` $N0027" >>"$LogFile"
      echo "`getmsgtext "$S0024"` " >>"$LogFile"
      exit 1
    else
      rm -f "$PartSourcePath/$ObjName.dat" >"$DevNull" 2>&1
      rm -f "$PartSourcePath/$ObjName.ret" >"$DevNull" 2>&1
    fi

    rm -f "$PartSourcePath/$ObjName.tmp" >"$DevNull" 2>&1

  fi # end of SaveReload

else

# --------------------------------------------------------
# Compile all Processes,Functions, Components and WAMs
# --------------------------------------------------------

  # Variables defined for substitution in Messages
  File="$ObjName.$PSuffix"
  Base="$ObjName"

  # Make the new Executable
  make -f "$ObjName.$PSuffix" >>"$LogFile" 2>&1
  if [ "$?" != "0" ]; then
    echo "$N0001: (S0036)  `getmsgtext "$S0036"` $N0027" >>"$LogFile"
    exit 1
  fi

  # Remove the source
  if [ "$Debug3" != "Y" ]; then
    RemoveSource
  fi

fi # end of Object type is File (FD)


# --------------------------------------------------------
# Make x_part directory and its files writeable for group
# --------------------------------------------------------

for d in "" /source /object /bin /web /web/document.cache; do
  TARGET_DIR="${LANSAXROOT}/x_lansa/x_${Part}${d}"
  if [ -d "$TARGET_DIR" ]; then
    chmod g+w "$TARGET_DIR"
  fi
done
unset TARGET_DIR

# --------------------------------------------------------
# Complete execution
# --------------------------------------------------------

trap "" 0
echo "[ finish - `date +"$DATE_FMT"` ]" >>"$LogFile"

exit 0

# vim:sts=2:sw=2:ts=8:et:syntax=sh
