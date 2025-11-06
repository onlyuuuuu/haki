#!/bin/bash

if [[ "$1" == "--wipe" ]]; then
  echo 0 | sudo -S rm -rf /Library/Developer/CommandLineTools
fi
echo 0 | sudo -S xcode-select --install
# echo 0 | sudo -S xcode-select --reset
# echo 0 | sudo -S xcode-select --switch /Library/Developer/CommandLineTools
# ./updateLib.sh
