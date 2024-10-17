#!/bin/bash

sudo mkdir -p /Library/Developer/CommandLineTools/usr/include/c++/v1
sudo cp -R bits /Library/Developer/CommandLineTools/usr/include/c++/v1/bits

sudo cp -R bits /Library/Developer/CommandLineTools/usr/include/bits

sudo mkdir -p /usr/local/include
sudo cp -R bits /usr/local/include/bits
