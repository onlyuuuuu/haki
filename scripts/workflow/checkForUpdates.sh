#!/bin/bash

# Script: checkForUpdates.sh
# Description: Checks if a git repository has updates that need to be pulled from remote
# Usage: ./checkForUpdates.sh [directory]
# Default directory: /tools/eclipse.jdt.ls/

# Function to display error messages
error_message() {
    echo "ERROR: $1" >&2
    exit 2
}

# Set target directory with default value
TARGET_DIR="${1:-/tools/eclipse.jdt.ls/}"

# Check if target directory exists
if [ ! -d "$TARGET_DIR" ]; then
    error_message "Directory '$TARGET_DIR' does not exist"
fi

# Change to target directory
cd "$TARGET_DIR" || error_message "Failed to access directory '$TARGET_DIR'"

# Check if directory is a git repository
if ! git rev-parse --is-inside-work-tree &>/dev/null; then
    error_message "'$TARGET_DIR' is not a git repository"
fi

echo "Checking for updates in '$TARGET_DIR'..."

# Get current branch name
CURRENT_BRANCH=$(git symbolic-ref --short HEAD 2>/dev/null)
if [ -z "$CURRENT_BRANCH" ]; then
    error_message "Not on a branch (detached HEAD state)"
fi

# Check if remote exists for current branch
if ! git rev-parse --abbrev-ref --symbolic-full-name @{u} &>/dev/null; then
    error_message "No upstream branch configured for '$CURRENT_BRANCH'"
fi

# Fetch from remote without updating the working directory
if ! git fetch --quiet; then
    error_message "Failed to fetch from remote"
fi

# Compare local and remote
BEHIND=$(git rev-list HEAD..@{upstream} --count 2>/dev/null)
AHEAD=$(git rev-list @{upstream}..HEAD --count 2>/dev/null)

# Check exit code of comparison
if [ $? -ne 0 ]; then
    error_message "Failed to compare with upstream branch"
fi

# Report status
if [ "$BEHIND" -gt 0 ] && [ "$AHEAD" -gt 0 ]; then
    echo "Repository has diverged: $BEHIND commits behind and $AHEAD commits ahead of remote"
    exit 1
elif [ "$BEHIND" -gt 0 ]; then
    echo "Updates available: Repository is $BEHIND commit(s) behind remote"
    exit 1
elif [ "$AHEAD" -gt 0 ]; then
    echo "Local ahead: Repository is $AHEAD commit(s) ahead of remote"
    exit 0
else
    echo "Repository is up to date with remote"
    exit 0
fi

