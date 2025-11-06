#!/bin/bash

file=main/input.txt
if [[ "$1" == "" ]]; then
  file=main/input.txt
else
  file=main/input_$1.txt
fi

ninja clean > /dev/null 2>&1
rm -rf CMakeCache.txt CMakeSettings.json
rm -rf build/ target/ cmake-build-default/ cmake-build-debug/ CMakeFiles/
rm -rf ccpp ccpp.exe
rm -rf cmake_install.cmake Makefile
cmake .
cmake --build . --target clean
if [[ "$(uname -a)" == *"Darwin"* ]]; then
  cmake -S . -B build
else
  cmake --build .
fi
if [[ "$(uname -a)" == *"MINGW"* ]]; then
  ./ccpp.exe < $file
elif [[ -f ./build/ccpp.exe ]]; then
  ./build/ccpp.exe < $file
else
  ./ccpp < $file
fi
