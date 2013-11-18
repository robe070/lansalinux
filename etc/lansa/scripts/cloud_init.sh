#!/bin/sh

# lansa_version: 13.2
# revision: 1

#
# This script is to be called after git pull and
# so to finalize installation for cloud.
#

pushd . >/dev/null
cd `dirname "$0"`
THIS_SCRIPT_ROOT=`pwd`
popd >/dev/null

# sanitize environment
unset LANSAXROOT

if [ $# -eq 0 ]; then
  LANSA_ROOTS=/etc/lansa/roots
  if [ -f $LANSA_ROOTS ]; then
    # take first entry of $LANSA_ROOTS as target root
    LANSAXROOT=`grep -v '^[ 	]*#' $LANSA_ROOTS | head -1`
  fi
  unset LANSA_ROOTS
  if [ -z "$LANSAXROOT" ]; then
    # default
    echo "$THIS_SCRIPT_ROOT" | grep -q "[^/]/etc/lansa/scripts$"
    if [ $? -eq 0 ]; then
      LANSAXROOT=`dirname "$THIS_SCRIPT_ROOT"`
      LANSAXROOT=`dirname "$LANSAXROOT"`
      LANSAXROOT=`dirname "$LANSAXROOT"`
    else
      LANSAXROOT=/opt/lansa
    fi
  fi
else
  LANSAXROOT=$1
fi

if [ ! -d "$LANSAXROOT" \
    -o ! \( -f "$LANSAXROOT/lansa.ini" -o -f "$LANSAXROOT/lansa.ini.cloud" \) \
    -o ! \( -f "$LANSAXROOT/version.dat" -o -f "$LANSAXROOT/version.dat.cloud" \) \
    -o ! \( -f "$LANSAXROOT/x_lansa/bin/setenv.sh" -o -f "$LANSAXROOT/x_lansa/bin/setenv.sh.cloud" \) \
    ]; then
  echo "LANSA installation not found in \"$LANSAXROOT\""
  exit 1
fi

cloud_setup() {
  # TODO: create files out of templates *.cloud
  true
}

lansa_setup() {
  local inst_owner_id=`stat -c '%u' "$LANSAXROOT"`
  local inst_group_id=`stat -c '%g' "$LANSAXROOT"`
  local d dd f ff
  # create directories
  for d in run run/conf run/dataqueues run/locks log tmp webserver/apache/locks webserver/apache/xsl.cache; do
    if [ ! -d "${LANSAXROOT}/${d}" ]; then
      sudo install -o $inst_owner_id -g $inst_group_id -m 2770 -d "${LANSAXROOT}/${d}"
    fi
  done
  if [ ! -e "${LANSAXROOT}/x_lansa/log" ]; then
    sudo ln -s ../log "${LANSAXROOT}/x_lansa/log"
    sudo chown -h $inst_owner_id:$inst_group_id "${LANSAXROOT}/x_lansa/log"
  fi
  if [ ! -e "${LANSAXROOT}/x_lansa/tmp" ]; then
    sudo ln -s ../log "${LANSAXROOT}/x_lansa/tmp"
    sudo chown -h $inst_owner_id:$inst_group_id "${LANSAXROOT}/x_lansa/tmp"
  fi
  if [ ! -e "${LANSAXROOT}/webserver/apache/log" ]; then
    sudo ln -s ../../log "${LANSAXROOT}/webserver/apache/log"
    sudo chown -h $inst_owner_id:$inst_group_id "${LANSAXROOT}/webserver/apache/log"
  fi
  # fix files/directories ownership and permissions
  for d in run log tmp x_lansa webserver/images webserver/apache/locks webserver/apache/xsl.cache webserver/apache/log; do
    dd="${LANSAXROOT}/${d}"
    if [ ! -L "${dd}" -a -d "${dd}" ]; then
      sudo find "${dd}" -type d -print0 | xargs -0 sudo chown $inst_owner_id:$inst_group_id
      sudo find "${dd}" -type d -print0 | xargs -0 sudo chmod 2770
    fi
  done
  for d in x_lansa/bin x_lansa/source; do
    dd="${LANSAXROOT}/${d}"
    sudo find "${dd}" -type d -print0 | xargs -0 sudo chmod 0755
  done
  for f in x_lansa/x_lansa.pro webserver/apache/l4w3serv.cfg webserver/apache/mod_lansa.conf; do
    ff="${LANSAXROOT}/${f}"
    if [ -f "$ff" ]; then
      sudo chown -h $inst_owner_id:$inst_group_id "$ff"
      sudo chmod 640 "$ff"
    fi
  done
}

init_setup() {
  # update /etc/lansa/roots
  local lansa_roots=/etc/lansa/roots
  if [ -f "$lansa_roots" ]; then
    grep -q "^[ 	]*${LANSAXROOT}[ 	]*$" "$lansa_roots"
    if [ $? -ne 0 ]; then
      grep -q "^[ 	]*#[ 	]*${LANSAXROOT}[ 	]*$" "$lansa_roots"
      if [ $? -eq 0 ]; then
        echo "enable LANSA installation ${LANSAXROOT} in ${lansa_roots}."
        sudo sed -i -e 's/^[ 	]*#[ 	]*\('`echo "${LANSAXROOT}" | sed -e 's/\//\\\\\//g'`'\)[ 	]*$/\1/' "$lansa_roots"
      else
        echo "add ${LANSAXROOT} to ${lansa_roots}."
        sudo sh -c "echo \"${LANSAXROOT}\" >> \"$lansa_roots\""
      fi
    fi
  else
    echo "create ${lansa_roots}."
    sudo install -o 0 -g 0 -m 0755 -d /etc/lansa
    sudo sh -c "echo \"${LANSAXROOT}\" > \"$lansa_roots\""
  fi
  # install service script
  local src_init="$LANSAXROOT/etc/init.d/lansa"
  if [ ! -f "$src_init" ]; then
    echo "$src_init does not exist."
    exit 1
  fi
  local tgt_init=/etc/init.d/lansa
  local COPY=1
  if [ -f "$tgt_init" ]; then
    local src_ver=`gawk -F': ' '/^# lansa_version: / { print $2 }' "$src_init"`
    local tgt_ver=`gawk -F': ' '/^# lansa_version: / { print $2 }' "$tgt_init"`
    if [ -n "$tgt_ver" ]; then
      if [ "$src_ver" != "$tgt_ver" ]; then
        echo "$tgt_init is of version $tgt_ver that is different from current version $src_ver, manual fixing required."
        exit 1
      fi
      local src_rev=`gawk -F': ' '/^# revision: / { print $2 }' "$src_init"`
      local tgt_rev=`gawk -F': ' '/^# revision: / { print $2 }' "$tgt_init"`
      if [ -n "$tgt_rev" ]; then
        if [ "$tgt_rev" -le "$src_rev" ]; then
          echo "$tgt_init is the same or newer. skip copying $src_init."
          COPY=0
        fi
      fi
    fi
  fi
  if [ $COPY -eq 1 ]; then
    echo "install $tgt_init."
    sudo install -o 0 -g 0 -m 0755 "$src_init" "$tgt_init"
  fi
  # install service
  if [ -f "$tgt_init" ]; then
    echo "install lansa as service."
    sudo chkconfig --add lansa
  fi
  sudo service lansa restart
}

apache_setup() {
  local sysconfig_httpd=/etc/sysconfig/httpd
  local httpd_conf=/etc/httpd/conf/httpd.conf
  if [ ! -f "$sysconfig_httpd" -o ! -f "$httpd_conf" ]; then
    echo "apache httpd is not installed."
    exit 1
  fi
  # stop apache httpd
  echo "stopping httpd..."
  sudo service httpd stop
  # change httpd mpm to worker
  echo "update $sysconfig_httpd to use httpd.worker."
  sudo sed -i -e 's/^[ 	]*#[ 	]*\(HTTPD[ 	]*=[ 	]*\/usr\/sbin\/httpd.worker\)[ 	]*$/\1/' "$sysconfig_httpd"
  # update LD_LIBRARY_PATH in $sysconfig_httpd
  grep -q "^[ 	]*export[ 	]*[ 	]LD_LIBRARY_PATH=$LANSAXROOT/connect:" "$sysconfig_httpd"
  if [ $? -ne 0 ]; then
    echo "update LD_LIBRARY_PATH in ${sysconfig_httpd}."
    sudo sh -c "echo \"export LD_LIBRARY_PATH=$LANSAXROOT/connect:\\\$LD_LIBRARY_PATH\" >> \"$sysconfig_httpd\""
  fi
  # add login apache to installation owner group
  local inst_group=`stat -c '%G' "$LANSAXROOT"`
  local inst_group_id=`stat -c '%g' "$LANSAXROOT"`
  id -G apache | grep -q "\<${inst_group_id}\>"
  if [ $? -ne 0 ]; then
    echo "add apache login to group \"${inst_group}\"."
    grep -q "^${inst_group}:x:${inst_group_id}:$" /etc/group
    if [ $? -eq 0 ]; then
      sudo sed -i -e "s/^\(${inst_group}:x:${inst_group_id}:\)$/\1apache/" /etc/group
    else
      sudo sed -i -e "s/^\(${inst_group}:x:${inst_group_id}:.*\)$/\1,apache/" /etc/group
    fi
    id -G apache | grep -q "\<${inst_group_id}\>"
    if [ $? -ne 0 ]; then
      echo "failed to add apache login to group \"${inst_group}\"."
      exit 1
    fi
  fi
  # update $httpd_conf to load LANSA for the Web apache module
  grep -q "^[ 	]*Include[ 	]*[ 	]${LANSAXROOT}\/webserver\/apache\/mod_lansa.conf[ 	]*$" "$httpd_conf"
  if [ $? -ne 0 ]; then
    # disable current apache module
    sudo sed -i -e 's/^[ 	]*\(Include[ 	].*\/webserver\/apache\/mod_lansa.conf\)[ 	]*$/#\1/' "$httpd_conf"
    grep -q "^[ 	]*#[ 	]*Include[ 	]*[ 	]${LANSAXROOT}\/webserver\/apache\/mod_lansa.conf[ 	]*$" "$httpd_conf"
    if [ $? -eq 0 ]; then
      echo "enable LANSA for the Web apache module in ${httpd_conf}."
      sudo sed -i -e 's/^[ 	]*#[ 	]*\(Include[ 	]*[ 	]'`echo "${LANSAXROOT}" | sed -e 's/\//\\\\\//g'`'\/webserver\/apache\/mod_lansa.conf\)[ 	]*$/\1/' "$httpd_conf"
    else
      echo "update ${httpd_conf} to load LANSA for the Web apache module."
      sudo sh -c "echo \"Include ${LANSAXROOT}/webserver/apache/mod_lansa.conf\" >> \"$httpd_conf\""
    fi
  else
    echo "${httpd_conf} is already loading LANSA for the Web apache module."
  fi
  # start apache httpd
  echo "starting httpd..."
  sudo service httpd start
}

cloud_install() {
  echo "### LANSA for Cloud Installation ###"
  echo "LANSAXROOT=$LANSAXROOT"
  cloud_setup
  lansa_setup
  init_setup
  apache_setup
  echo "DONE."
}

# commence cloud installation
cloud_install

# vim:sts=2:sw=2:ts=8:et:syntax=sh
