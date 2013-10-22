#!/bin/sh
#
# Path Helper shell macros
#

for _egrep in /usr/local/bin/gegrep /usr/bin/gegrep /bin/gegrep /usr/local/bin/egrep /usr/bin/egrep /bin/egrep; do
  [ -x $_egrep ] && _egrep_for_pathhelp=$_egrep && break
done
unset _egrep

_pathmunge () {
  if ! echo "$PATH" | $_egrep_for_pathhelp -q "(^|:)$1($|:)" ; then
    if [ "$PATH" = "" ]; then
      PATH="$1"
    elif [ "$2" = "after" ] ; then
      PATH="$PATH:$1"
    else
      PATH="$1:$PATH"
    fi
  fi
}

_pathappend() {
  for _p in "$@"; do
    if [ -d "$_p" ]; then
      _pathmunge "$_p" after
    fi
  done
  unset _p
}

_pathprepend() {
  for _p in "$@"; do
    if [ -d "$_p" ]; then
      _pathmunge "$_p"
    fi
  done
  unset _p
}

_ldpathmunge () {
  if ! echo "$LD_LIBRARY_PATH" | $_egrep_for_pathhelp -q "(^|:)$1($|:)" ; then
    if [ "$LD_LIBRARY_PATH" = "" ]; then
      export LD_LIBRARY_PATH="$1"
    elif [ "$2" = "after" ] ; then
      export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$1"
    else
      export LD_LIBRARY_PATH="$1:$LD_LIBRARY_PATH"
    fi
  fi
}

_ldpathappend() {
  for _p in "$@"; do
    if [ -d "$_p" ]; then
      _ldpathmunge "$_p" after
    fi
  done
  unset _p
}

_ldpathprepend() {
  for _p in "$@"; do
    if [ -d "$_p" ]; then
      _ldpathmunge "$_p"
    fi
  done
  unset _p
}

# vim:sts=2:sw=2:ts=8:et:syntax=sh
