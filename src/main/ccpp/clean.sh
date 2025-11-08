#!/bin/bash

ninja clean > /dev/null 2>&1
rm -rf CMakeCache.txt CMakeSettings.json
rm -rf build/ target/ cmake-build-default/ cmake-build-debug/ CMakeFiles/
rm -rf ccpp ccpp.exe
rm -rf cmake_install.cmake Makefile
cmake .
cmake --build . --target clean
