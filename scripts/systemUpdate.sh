#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo "Script dir: $SCRIPT_DIR"
cd $SCRIPT_DIR

if [[ "$(uname -a)" == *"Darwin"* ]]; then
  echo "Nothing to do on MacOS..."
else
  echo 0 | sudo -S apt update -y
  echo 0 | sudo -S apt -o APT::Get::Always-Include-Phased-Updates=true upgrade -y
  echo 0 | sudo -S apt autoremove -y
fi

./brew.sh

if command -v sdk > /dev/null 2>&1; then
  sdk update
  sdk upgrade
  sdk selfupdate
fi

./buildNeovim.sh

