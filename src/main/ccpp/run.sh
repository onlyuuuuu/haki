#!/bin/bash

ninja clean > /dev/null 2>&1
cmake .
cmake --build . --target clean
cmake --build .
if [[ "$(uname -a)" == *"MINGW"* ]]; then
  ./ccpp.exe < main/input.txt
elif [[ -f ./build/ccpp.exe ]]; then
  ./build/ccpp.exe < main/input.txt
else
  ./ccpp < main/input.txt
fi
