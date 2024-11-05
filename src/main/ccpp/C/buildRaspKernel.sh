#/bin/bash

BASE_DIR=$(pwd)

mkdir -p kernel/raspberrypi/armhf/
mkdir -p kernel/raspberrypi/arm64/

rm -rf kernel/raspberrypi/armhf/*
rm -rf kernel/raspberrypi/arm64/*

# 32 bit
cd $BASE_DIR/raspberrypi-linux
git pull
KERNEL=kernel7
make O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcm2709_defconfig
make O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
cd $BASE_DIR
cp -rf $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/zImage $BASE_DIR/$KERNEL.img

# 64 bit
cd $BASE_DIR/raspberrypi-linux
git pull
KERNEL=kernel8
make O=$BASE_DIR/kernel/raspberrypi/arm64 -C $BASE_DIR/raspberrypi-linux bcm2711_defconfig
make O=$BASE_DIR/kernel/raspberrypi/arm64 -C $BASE_DIR/raspberrypi-linux
cd $BASE_DIR
cp -rf $BASE_DIR/kernel/raspberrypi/arm64/arch/arm64/boot/Image.gz $BASE_DIR/$KERNEL.img

# Size: 8G
# qemu-img create -f raw rootfs.ext4
# dd if=/dev/zero of=rootfs.ext4 bs=4k count=2097152
# mkfs.ext4 rootfs.ext4
