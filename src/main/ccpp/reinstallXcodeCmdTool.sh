#!/bin/bash

echo 0 | sudo -S rm -rf /Library/Developer/CommandLineTools
echo 0 | sudo -S xcode-select --install
echo 0 | sudo -S sudo xcode-select --reset
echo 0 | sudo -S xcode-select --switch /Library/Developer/CommandLineTools
