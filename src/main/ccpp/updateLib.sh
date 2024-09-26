#!/bin/bash

sudo mkdir -p /Library/Developer/CommandLineTools/usr/include/c++/v1
sudo rm -rf /Library/Developer/CommandLineTools/usr/include/c++/v1/bits/
sudo cp -R bits /Library/Developer/CommandLineTools/usr/include/c++/v1/bits

sudo rm -rf /Library/Developer/CommandLineTools/usr/include/bits/
sudo cp -R bits /Library/Developer/CommandLineTools/usr/include/bits

sudo mkdir -p /usr/local/include
sudo rm -rf /usr/local/include/bits/
sudo cp -R bits /usr/local/include/bits
