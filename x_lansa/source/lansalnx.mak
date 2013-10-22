###############################################################################
#  LANSA/X Include Makefile for Linux                                         #
#                                                                             #
#  Note: This is the Linux equivalent of the lansax.mak makefile              #
###############################################################################

LANSAX=$(LANSAXROOT)/x_lansa

# Specific defines needed for Linux compiler
LNXSOURCE=

# Compile -D defines
DEFINES= -DX_OPERATING_SYSTEM_LNX -DX_OPERATING_SYSTEM_UNIX -DX_SPLIT_NO -DX_LX $(LNXSOURCE)

include $(LANSAXROOT)/x_lansa/source/$(X_DBINCLUDE)

# Delete command to use
DeleteCmd=rm

###############################################################################
# C Compiler                                                                   #
###############################################################################

#C compiler
CC = gcc

# Compiler Flags
# CFLAGS for object code required by shared lib
CFLAGS = -pthread -fPIC -w -c $(CMPFLAGS) -I. $(DEFINES) $(DBDEFS) $(DBINCL)

###############################################################################
# Linker                                                                      #
###############################################################################
# Linker
LD = ld

# Executable  Flags
EXEFLAGS= -ldl -s -o $@ 

# Dynamic loader library
DLDLIB=-ldl

# Shared Library extention 
SHR_PREFIX=lib
SHR_EXT=so

# Shared Library Flags
DYN_SHR_DEF=
SHR_FLAGS= -shared -E $(LNKFLAGS) -o $@ -L$(DBLIBPATH)

# Common System libraries.
SLIBS = -lm -lc


###############################################################################
# DBCS                                                                        #
###############################################################################

# DBCS Flags
DBCSFLGS=

###############################################################################
# Directories
###############################################################################
BLDDIR=$(LANSAX)
BNDDIR=$(BLDDIR)/source
DEFDIR=$(BLDDIR)/source
SHRDIR=$(BLDDIR)/bin
EXEDIR=$(BLDDIR)/bin
HLPDIR=$(BLDDIR)/source
INCDIR=$(BLDDIR)/source
LIBDIR=$(BLDDIR)/source
OBJDIR=$(BLDDIR)/object
RESDIR=$(BLDDIR)/source
SRCDIR=$(BLDDIR)/source

###############################################################################
# Export flags and export files
###############################################################################
# Export Flag
# define an export file
EXPDEF=$(HASH)
# export a symbol
EXPFLAG=


###############################################################################
# Import flags and import files
###############################################################################
# Import Flag
IMPFLAG=-l

# Import Files
BIFIMP=x_bif
DBMIMP=x_dbm
FUNIMP=x_fun
PDFIMP=x_pdf
PIMIMP=x_pim
JSMIMP=x_jsm
XQLIMP=x_xql
UIMIMP=empty
INSTPIMP=
INSTQIMP=
INSTRIMP=
INSTSIMP=
VARIMP=x_var
BASEIMP=x_base

###############################################################################
# LANSA/X Shared libraries
###############################################################################
SHRLIBS=

###############################################################################
# Automatically rename .sqc to .c for functions with SELECT_SQL
###############################################################################
.SUFFIXES: .sqc
.sqc.c:
	mv $< $@
