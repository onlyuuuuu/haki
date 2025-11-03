#!/bin/bash

if [[ "$(uname -a)" == *"ARM64"* ]]; then
  pacman -S \
    base-devel \
    msys2-runtime \
    make \
    cmake \
    ninja \
    pkg-config \
    python \
    clang
else
  pacman -S \
    msys2-runtime \
    gcc \
    g++ \
    make \
    cmake \
    ninja
  pacman -S --needed base-devel mingw-w64-x86_64-toolchain
fi