#!/bin/bash

echo 0 | sudo -S rm -rf /tools/libslirp/build/*
cd /tools/libslirp
git pull
meson build
echo 0 | sudo -S chown -R zero:zero /tools/libslirp/
echo 0 | sudo -S ninja -C build install

