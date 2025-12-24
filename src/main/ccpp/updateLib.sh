#!/bin/bash

# Things are in here, at least... at the moment... until Apple decide to change it
# /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/bits
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/bits/stdc++.h

exit 0
