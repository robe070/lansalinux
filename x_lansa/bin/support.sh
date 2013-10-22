#!/bin/sh
##############################################################
# Create a text file with UNIX support information.
# Copyright (C), 2009 LANSA
##############################################################

# --------------------------------------------------------
# Set the devnull value to use
# --------------------------------------------------------

getdevnull()
{

   DevNull=/dev/null

   if [ "$Platform" = "OS400" ]; then
        DevNull=$PWD/dev.null
   fi
   
}

# --------------------------------------------------------
# Set the echo flag for processing special characters
# --------------------------------------------------------

getechoflag()
{

   E=
   if echo "\c" | grep c >$DevNull 2>&1; then
       E='-e'
   fi
}


# --------------------------------------------------------------------
#          ============  Start of body of script ==============  
# --------------------------------------------------------------------


# determine the operating platform
Platform=`uname`

# Determine dev null to use
getdevnull

# Set echo flag for special characters
getechoflag




LogFile=`pwd`/support.txt

echo $E "Support Details as of `date`\n" > $LogFile

# Operating Platform Information

echo "Operating Platform Information" >> $LogFile
echo $E "------------------------------\n" >> $LogFile
uname -a >> $LogFile 2>&1

# LANSA Build and Licence Details

echo $E "\nLANSA Build and Licence Details" >> $LogFile
echo $E "-------------------------------\n" >> $LogFile
x_run part=dem lang=eng user=support dbii=*none dbid=*none proc=*licences logo=y >> $LogFile 2>&1

echo $E "\nInstalled EPC Details" >> $LogFile
echo $E "---------------------\n" >> $LogFile
if [ -r $LANSAXROOT/epcheck.dat ]; then
	cat $LANSAXROOT/epcheck.dat >> $LogFile 2>&1
else
echo "No EPCs have been Installed" >> $LogFile
fi

echo $E "\nInstalled lansa.ini" >> $LogFile
echo $E "-------------------\n" >> $LogFile
if [ -r $LANSAXROOT/lansa.ini ]; then
	cat $LANSAXROOT/lansa.ini >> $LogFile 2>&1
else
echo "lansa.ini has not been Installed" >> $LogFile
fi

echo $E "\nInstalled listen.dat" >> $LogFile
echo $E "-------------------\n" >> $LogFile
if [ -r $LANSAXROOT/listen.dat ]; then
	cat $LANSAXROOT/listen.dat >> $LogFile 2>&1
else
echo "listen.dat has not been Installed" >> $LogFile
fi

echo $E "\nInstalled x_lansa.pro" >> $LogFile
echo $E "---------------------\n" >> $LogFile
if [ -r $LANSAXROOT/x_lansa/x_lansa.pro ]; then
	cat $LANSAXROOT/x_lansa/x_lansa.pro >> $LogFile 2>&1
else
echo "x_lansa.pro has not been Installed" >> $LogFile
fi

# System Environment Variables

echo $E "\nSystem Environment Variables" >> $LogFile
echo $E "----------------------------\n" >> $LogFile

env | sort >> $LogFile 2>&1

echo $E "\nEnd of System Environment Variables" >> $LogFile

exit 0
