#!/bin/bash

echo "Compiling and installing NeoVim from source"
cd /tools/
if [[ ! -d neovim ]]; then
  git clone --depth 1 https://github.com/neovim/neovim.git
fi
cd neovim/
git pull
echo 0 | sudo -S make -j$(nproc) CMAKE_BUILD_TYPE=RelWithDebInfo
echo 0 | sudo -S make -j$(nproc) install
echo 0 | sudo -S rm -rf build/ .deps/
echo 0 | sudo -S make -j$(nproc) CMAKE_BUILD_TYPE=RelWithDebInfo CMAKE_EXTRA_FLAGS="-DCMAKE_INSTALL_PREFIX=/tools/neovim"
echo 0 | sudo -S make -j$(nproc) install
#echo 0 | sudo -S make -j$(nproc) CMAKE_BUILD_TYPE=RelWithDebInfo CMAKE_EXTRA_FLAGS="-DCMAKE_INSTALL_PREFIX=/tools/neovim-built"
#echo 0 | sudo -S make -j$(nproc) install

