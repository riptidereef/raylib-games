#!/bin/bash

commit_changes() {
  COMMIT_MSG="${1:-"Update files"}"
  git add .
  git commit -m "$COMMIT_MSG"
  echo "Changes committed with message: '$COMMIT_MSG'"
}

push_changes() {
  git push origin main
  echo "Changes pushed to GitHub!"
}

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
  echo "Usage: $0 {commit|push} [commit_message]"
  exit 1
fi

# Handle the action passed as the first argument
if [ "$1" == "commit" ]; then
  commit_changes "$2"
elif [ "$1" == "push" ]; then
  push_changes
else
  echo "Invalid action: $1. Use 'commit' or 'push'."
  exit 1
fi