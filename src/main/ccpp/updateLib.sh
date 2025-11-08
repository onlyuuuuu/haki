#!/bin/bash

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/local/include/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/Library/Frameworks/bits
echo 0 | sudo -S mkdir -p /usr/local/include/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/usr/bin/../include/c++/v1/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/usr/lib/clang/17/include/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/usr/include/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/bits
echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/SubFrameworks/bits

echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/usr/include/c++/v1/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/SDKs/MacOSX26.sdk/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /usr/local/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /usr/include/bits/stdc++.h > /dev/null 2>&1
echo 0 | sudo -S cp -rf bits/stdc++aarch64-macos.h /usr/lib/bits/stdc++.h > /dev/null 2>&1

exit 0
