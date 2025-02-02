#!/bin/bash

echo 0 | sudo -S rm -rf /tools/qemu/bin/
mkdir -p /tools/qemu/bin/debug/native
cd /tools/qemu/bin/debug/native
../../../configure --enable-debug --enable-slirp
make -j${nproc}
echo 0 | sudo -S chown -R zero:zero /tools/qemu
echo 0 | sudo -S make install -j${nproc}
echo 0 | sudo -S chown -R zero:zero /tools/qemu
