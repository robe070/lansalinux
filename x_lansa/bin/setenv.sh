#!/bin/sh

export LANSAXROOT="/opt/lansa.rg132"
export X_RUN="ROOT:$LANSAXROOT"

X_LANSA_BIN="$LANSAXROOT/x_lansa/bin"
CONNECT_ROOT="$LANSAXROOT/connect"
UNIXODBC_LIB="$LANSAXROOT/unixODBC/lib"
ORACLE_CLIENT_LIB="/usr/lib64"

. "$X_LANSA_BIN/pathhelp.sh"

_pathprepend "$CONNECT_ROOT"
_pathprepend "$X_LANSA_BIN"

_ldpathprepend "$ORACLE_CLIENT_LIB"
_ldpathprepend "$UNIXODBC_LIB"
_ldpathprepend "$CONNECT_ROOT"
_ldpathprepend "$X_LANSA_BIN"

export X_MAKINCLUDE=lansalnx.mak
export X_DBINCLUDE=lansaodb.mak
export HASH='#'

# vim:sts=2:sw=2:ts=8:et:syntax=sh
