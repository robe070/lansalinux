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
  return $status
}

# Add all untracked files
execCmd "git add ." 0

# TODO Need to get comment from file

execCmd "git commit -a -m\"A commit\"" 1

# Only push if commit did something
if [[ $? -eq 0 ]]
then
    execCmd "git push origin" 0
fi
