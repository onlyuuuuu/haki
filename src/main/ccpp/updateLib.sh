#!/bin/bash

sudo mkdir -p /Library/Developer/CommandLineTools/usr/include/c++/v1/bits
sudo cp bits/stdc++.h /Library/Developer/CommandLineTools/usr/include/c++/v1/bits/

sudo mkdir -p /Library/Developer/CommandLineTools/usr/include/bits
sudo cp bits/stdc++.h /Library/Developer/CommandLineTools/usr/include/bits/

sudo mkdir -p /usr/local/include/bits
sudo cp bits/stdc++.h /usr/local/include/bits/

sudo mkdir -p /opt/homebrew/Cellar/llvm/19.1.2/include/c++/v1/bits
sudo cp bits/stdc++.h /opt/homebrew/Cellar/llvm/19.1.2/include/c++/v1/bits/

sudo mkdir -p /usr/local/opt/llvm/include/c++/v1/bits
sudo cp bits/stdc++.h /usr/local/opt/llvm/include/c++/v1/bits/
