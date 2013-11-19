#!/bin/sh
# Presumes that the current branch is the one to be updated
# typically that is master
# Requires that ssh key does NOT have a passphrase. This is because the
# passphrase MUST be entered interactively, but this is NOT run interactively!

# Parameter 1: Filepath containing comment for commit

function execCmd()
{
  echo $1

  eval "$1"
  status=$?

  if [[ $status -gt "$2" ]]
  then
        echo "Error: $status"
	exit $status
  fi
  echo "Return: $status"
  return $status
}

whoami

# Currently LANSA Connect does not set the environment up vorrectly, and git needs the home directory to be set
# These quotes take the output from whoami and treat it as text for the command line
export HOME=/home/`whoami`

# Add all untracked files
# execCmd "git add . --dry-run" 0
execCmd "git add ." 0

# Display files that will be effected
execCmd "git commit -a --dry-run --short" 1

execCmd "git commit -a -F $1" 1

# Only push if commit did something
# return of 1 means there was nothing to commit
if [[ $? -eq 0 ]]
then
    execCmd "git push origin" 0
    
    # Trigger web server to pull from git
    if [[ $? -eq 0 ]]
    then
        execCmd "curl http://ec2-54-252-223-227.ap-southeast-2.compute.amazonaws.com/cgi-bin/github.php?update=goody1" 0
    fi
fi
