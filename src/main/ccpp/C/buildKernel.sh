#/bin/bash

BASE_DIR=$(pwd)

mkdir -p kernel/armhf/
rm -rf kernel/armhf/*

# 32 bit
# TODO: Need to fix this since we are building this linux kernel on native aarch64
cd linux
git pull
make -j6 O=$BASE_DIR/kernel/armhf -C $BASE_DIR/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- multi_v7_defconfig
make -j6 O=$BASE_DIR/kernel/armhf -C $BASE_DIR/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
cd $BASE_DIR
cp -rf $BASE_DIR/kernel/armhf/arch/arm/boot/dts/arm/vexpress-v2p-ca15-tc1.dtb $BASE_DIR/vexpress-v2p-ca15-tc1.dtb
dtc -q -I dtb -O dts -o vexpress-v2p-ca15-tc1.dts vexpress-v2p-ca15-tc1.dtb

# 64 bit


# Size: 8G
# qemu-img create -f raw rootfs.ext4
# dd if=/dev/zero of=rootfs.ext4 bs=4k count=2097152
# mkfs.ext4 rootfs.ext4
