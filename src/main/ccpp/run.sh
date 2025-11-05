#!/bin/bash

file=main/input.txt
if [[ "$1" == "" ]]; then
  file=main/input.txt
else
  file=main/input_$1.txt
fi

ninja clean > /dev/null 2>&1
rm -rf CMakeCache.txt
cmake .
cmake --build . --target clean
cmake --build .
if [[ "$(uname -a)" == *"MINGW"* ]]; then
  ./ccpp.exe < $file
elif [[ -f ./build/ccpp.exe ]]; then
  ./build/ccpp.exe < $file
else
  ./ccpp < $file
fi
