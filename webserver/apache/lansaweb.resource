########################################################################
#
# LANSA for the Web Plug-in Resource Texts
#
########################################################################
#-----------------------------------------------------------------------
# Home page message (HP)
#-----------------------------------------------------------------------
HP00=<head><title>Display Home Page</title>
HP01=<script type="text/javascript" language="javascript"> //<![CDATA[
HP02=function HomePage()'{' parent.location="{0}"; '}' //]]>
HP03=</script></head><body onload="HomePage()"></body></html>
#-----------------------------------------------------------------------
# Error message box (EM)
#-----------------------------------------------------------------------
EM00=<head><title>Error</title>
EM01=<script type="text/javascript" language="javascript"> //<![CDATA[
EM02=function HomePage()'{' parent.location="{0}"; '}' //]]>
EM03=</script></head><body><hr /><br /><h1>{1}</h1><br /><hr /><br /><br /><br />
EM04=<a href="JavaScript:HomePage()">Return to Home Page</a></body></html>
#-----------------------------------------------------------------------
# Reset message (RS)
#-----------------------------------------------------------------------
RS00=<head><title>Reset Parent</title>
RS01=<script type="text/javascript" language="javascript"> //<![CDATA[
RS02=function Reset()'{' parent.location="{0}"; '}' //]]>
RS03=</script></head><body onload="Reset()"></body></html>
#-----------------------------------------------------------------------
# Preamble (PR)
#-----------------------------------------------------------------------
PR00=<!-- <?xml version="1.0"?> -->
PR01=<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
PR02=  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
PR03=<html xmlns="http://www.w3.org/1999/xhtml">
#-----------------------------------------------------------------------
# Local messages (LW)
#-----------------------------------------------------------------------
LW00=Invalid request type of
LW01=The support for PRINT, REPORT and PRINTLIST requests is currently disabled
LW02=Static Page Output successfully stored on the Web Server
#-----------------------------------------------------------------------
# Host messages (HM)
#-----------------------------------------------------------------------
#    Status, Log, Text
HM00=500,Y,Application server is not set up correctly.
HM01=500,Y,Unable to locate data library for Application server.
HM02=500,N,Job has already timed out.
HM03=500,N,User information provided is not valid.
HM04=503,N,Application server is currently too busy to process your request.
HM05=500,Y,Application server does not have a valid licence.
HM06=400,N,Invalid request type of
HM07=500,Y,Unable to connect to Application server.
HM08=500,Y,Routing Table is not set up correctly.
HM09=200,N,Information:
HM10=400,N,Number or parameters is not correct.
HM11=500,Y,User registration cannot be accessed.
HM12=500,N,User information not found in current configuration.
HM13=500,N,Password supplied does not match the current password.
HM14=500,N,Update of user information failed.
HM15=500,N,Unable to restart WEBEVENT function. Request terminated.
HM16=400,N,Action is invalid. It must be ADD, CHG or DLT.
HM17=200,N,New record inserted successfully.
HM18=500,N,Insert of user information failed.
HM19=200,N,Update of user information is successful.
HM20=500,N,Update of user information failed.
HM21=200,N,Deletion of user information is successful.
HM22=500,N,Deletion of user information failed.
HM23=200,N,Static Page Output successfully stored on your Web server.
HM24=500,N,Static Page Output failed.
HM25=500,Y,Unable to start XSLT Engine. Request terminated.
HM26=404,N,XML application not found.
HM27=500,N,XSL style sheet not found.
HM28=500,N,Unable to transform input XML.
HM29=400,Y,Incomplete data transaction.
HM30=400,Y,Unrecoverable error occurred while executing the Web application.
HM31=400,Y,Posting data volume exceeded allowed limit.
HM32=403,Y,Access denied.
HM40=500,Y,Unrecoverable error occurred while executing the Web application routine.
HM41=500,Y,Web application execution aborted.
HM42=500,Y,Invalid Web application session.
HM43=500,Y,Web application session has expired.
HM44=500,Y,XML and/or XSLT processors are not available.
HM45=500,Y,Application server is disabled from executing Web applications.
HM46=500,Y,Application server is disabled from handling LXML requests.
HM47=500,Y,Web server is disabled from handling LXML requests.
HM48=500,Y,Formatted output feature not enabled.
HM49=500,Y,Invalid format request.
#-----------------------------------------------------------------------
# Message redirection (MR)
#-----------------------------------------------------------------------
#
# NOTE:
#   1.  There are 3 types of MR settings:
#       (1) MRnn_{ML} - MR per specific message per markup language
#       (2) MR_{ML} - MR per markup language
#       (3) MR - general MR default
#   2.  Each MR setting consists of 3 parts separated by commas:
#       (1) transform:{yes/no}
#           yes is not supported YET so must be no.
#       (2) content-type:{mime-type}
#           mime-type of the redirected message.
#           (used for file: and vfile: only)
#       (3) file:{physical_file} or vfile:{virtual_file} or url:{url}
#           file/url for the redirected message.
#   3.  Use file: to redirect messages to physical files. Note that any
#       extra path to a physical file is ignored (for security reason),
#       Web Plug-in will only locate physical files in the Web Plug-in
#       install directory using the base file name only, i.e. for
#       setting like "file:whatever/path/to/stderr.htm",
#       "whatever/path/to/" will be ignored and Web Plug-in will look
#       for the file stderr.htm in the install directory only.
#   4.  Use vfile: to redirect messages to virtual files (files
#       accessable through URL), e.g. "vfile:/lansaweb/stderr.htm".
#       Note that path to a virtual file must start from root, i.e.
#       starting with '/'.
#   5.  The number of MR settings is not limited and Web Plug-in will
#       find the redirection using the following order of perferences:
#       (1) MRnn_{ML} - MR per specific message per markup language
#       (2) MR_{ML} - MR per markup language
#       (3) MR - general MR default
#       e.g. For the following set of MR settings:
#                MR=....
#                MR_XHTML=....
#                MR00_XHTML=....
#                MR05_XHTML=....
#       MR00_XHTML will be used for message HM00 for XHTML requests.
#       MR05_XHTML will be used for message HM05 for XHTML requests.
#       MR_XHTML will be used for all other messages for XHTML requests.
#       MR will be used for all non XHTML requests.
#   6.  Web Functions use XHTML only.
#   7.  For the following example settings, remove the starting remarks
#       indicator ('#') to activate the settings.
#
#-----------------------------------------------------------------------
# Message redirection default for all
#-----------------------------------------------------------------------
# By default, all messages are redirected to stderr.htm.
MR=transform:no,content-type:text/html,file:stderr.htm
#-----------------------------------------------------------------------
# Message redirection default per markup language
#-----------------------------------------------------------------------
# e.g. 1. To redirect all XHTML requests (including all Web Function
#         requests) to stderr.htm.
#MR_XHTML=transform:no,content-type:text/html,file:stderr.htm
# e.g. 2. To redirect all TEXT requests to stderr.txt.
#MR_TEXT=transform:no,content-type:text/plain,file:stderr.txt
#-----------------------------------------------------------------------
# Message redirection per specific message per markup language
#-----------------------------------------------------------------------
# e.g. 3. To redirect message HM00 for all XHTML requests (including all
#         Web Function requests) to sys_not_setup.htm.
#MR00_XHTML=transform:no,content-type:text/html,file:sys_not_setup.htm
# e.g. 4. To redirect message HM00 for all TEXT requests to
#         sys_not_setup.txt.
#MR00_TEXT=transform:no,content-type:text/plain,file:sys_not_setup.txt
#-----------------------------------------------------------------------
### end of file ###
