###############################################################################
#  LANSA/X Include Makefile for ODBC                                          #
#                                                                             #
#  Note: This is the ODBC makefile that gets included in lansaxxx.mak         #
###############################################################################

# Database Flags
DBDEFS=-DX_DATABASE_ODBC -DX_DBMS_COL_ALIAS
# Path to Database objects (currenly only used on Linux)
DBLIBPATH=.

