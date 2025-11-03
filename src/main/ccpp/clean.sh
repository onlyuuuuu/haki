#!/bin/bash

cmake --build . --target clean
sudo rm -rf .cmake/ cmake-build-debug/ CMakeFiles/ *.dSYM/ Testing/ ccpp cmake_install.cmake CMakeCache.txt Makefile sandbox
