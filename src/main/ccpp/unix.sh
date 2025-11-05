#!/bin/bash

find . -type f -name "*.swp" -print -exec rm -f {} \;
find . -type f -name "*.swo" -print -exec rm -f {} \;
find ~/.local/state/nvim/swap/ -type f -name "*.swp" -print -exec rm -f {} \;
find ~/.local/state/nvim/swap/ -type f -name "*.swo" -print -exec rm -f {} \;
find . -type f -exec dos2unix {} \;
