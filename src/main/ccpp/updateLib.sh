#!/bin/bash

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/usr/include/c++/v1/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Library/Developer/CommandLineTools/usr/include/c++/v1/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Library/Developer/CommandLineTools/usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Library/Developer/CommandLineTools/usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /usr/local/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /usr/local/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /usr/include/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /usr/include/bits/ > /dev/null 2>&1

echo 0 | sudo -S mkdir -p /usr/lib/bits > /dev/null 2>&1
echo 0 | sudo -S cp bits/stdc++.h /usr/lib/bits/ > /dev/null 2>&1

exit 0
