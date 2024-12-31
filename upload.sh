#!/bin/bash

# Function to commit changes
commit_changes() {
  # Define the commit message (if provided, else default to "Update files")
  COMMIT_MSG="${1:-"Update files"}"
  
  # Add all changes
  git add .
  
  # Commit the changes with the provided message
  git commit -m "$COMMIT_MSG"
  
  # Output success message
  echo "Changes committed with message: '$COMMIT_MSG'"
}

# Function to push changes
push_changes() {
  # Push the changes to the remote repository
  git push origin main
  
  # Output success message
  echo "Changes pushed to GitHub!"
}

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
  echo "Usage: $0 {commit|push} [commit_message]"
  exit 1
fi

# Handle the action passed as the first argument
if [ "$1" == "commit" ]; then
  # Commit the changes with optional commit message
  commit_changes "$2"
elif [ "$1" == "push" ]; then
  # Push the changes
  push_changes
else
  echo "Invalid action: $1. Use 'commit' or 'push'."
  exit 1
fi
