#/bin/bash

BASE_DIR=$(pwd)

mkdir -p kernel/armhf/
rm -rf kernel/armhf/*

cd linux

make zImage O=$BASE_DIR/kernel/armhf -C $BASE_DIR/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- multi_v7_defconfig
make dtbs O=$BASE_DIR/kernel/armhf -C $BASE_DIR/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- multi_v7_defconfig

cd $BASE_DIR

cp -rf $BASE_DIR/kernel/armhf/arch/arm/boot/dts/arm/vexpress-v2p-ca15-tc1.dtb $BASE_DIR/vexpress-v2p-ca15-tc1.dtb
dtc -q -I dtb -O dts -o vexpress-v2p-ca15-tc1.dts vexpress-v2p-ca15-tc1.dtb
