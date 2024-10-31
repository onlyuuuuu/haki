#/bin/bash

mkdir -p kernel/armhf/
rm -rf kernel/armhf/*

make O=$(pwd)/kernel/armhf -C $(pwd)/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- multi_v7_defconfig
