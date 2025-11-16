#!/bin/bash

file=main/input.txt
if [[ "$1" == "" ]]; then
  file=main/input.txt
else
  file=main/input_$1.txt
fi

./clean.sh
cmake -S . -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY:PATH="$(pwd)"
cmake --build build
# Remove .exe extension if present (MinGW adds it regardless)
if [[ -f ./ccpp.exe ]]; then
  mv ./ccpp.exe ./ccpp
fi
./ccpp < $file
