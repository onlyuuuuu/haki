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
  pacman --noconfirm -S mingw-w64-ucrt-x86_64-toolchain
  pacman --noconfirm -S mingw-w64-ucrt-x86_64-clang
  pacman -S --needed --noconfirm \
      mingw-w64-ucrt-x86_64-gcc \
      mingw-w64-ucrt-x86_64-gcc-libs \
      mingw-w64-ucrt-x86_64-binutils
  pacman --noconfirm -Syu
else
  pacman -S \
    msys2-runtime \
    gcc \
    make \
    cmake \
    ninja
  pacman --noconfirm -S mingw-w64-ucrt-x86_64-toolchain
  pacman --noconfirm -S mingw-w64-ucrt-x86_64-clang
  pacman -S --needed --noconfirm \
      mingw-w64-ucrt-x86_64-gcc \
      mingw-w64-ucrt-x86_64-gcc-libs \
      mingw-w64-ucrt-x86_64-binutils
  pacman --noconfirm -Syu
fi