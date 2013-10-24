#/bin/sh -x
# Presumes that the current branch is the one to be updated
# typically that is master
# Requires that ssh key does NOT have a passphrase. This is because the
# passphrase MUST be entered interactively, but this is NOT run interactively!

# Add all untracked files
git add .
# TODO Need to get comment from file
git commit -a -m"A commit"
git push origin master
