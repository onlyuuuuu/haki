#!/bin/bash

file=main/input.txt
if [[ "$1" == "" ]]; then
  file=main/input.txt
else
  file=main/input_$1.txt
fi

./clean.sh
if [[ "$(uname -a)" == *"Darwin"* ]]; then
  cmake -S . -B build
  cmake --build build
else
  cmake --build .
fi
if [[ "$(uname -a)" == *"MINGW"* ]]; then
  ./ccpp.exe < $file
elif [[ -f ./build/ccpp.exe ]]; then
  ./build/ccpp.exe < $file
else
  ./build/ccpp < $file
fi
