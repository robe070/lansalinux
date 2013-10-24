#!/bin/bash -x
# Presumes that the current branch is the one to be updated
# typically that is master
# Requires that ssh key does NOT have a passphrase. This is because the
# passphrase MUST be entered interactively, but this is NOT run interactively!

function execCmd()
{
  eval "$1"

  status=$?

  if [[ $status -gt "$2" ]]
  then
        echo "Error..."
        exit $status
  fi
}

# Add all untracked files
execCmd "git add ." 0

# TODO Need to get comment from file

git commit -a -m"A commit"

status=$?

if [ $status -gt 0 ];then
    echo "error in commit"
    exit $status
fi

git push origin
