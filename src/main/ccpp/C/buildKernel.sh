#/bin/bash

BASE_DIR=$(pwd)

mkdir -p kernel/armhf/
rm -rf kernel/armhf/*

mkdir -p kernel/raspberrypi/armhf/
rm -rf kernel/raspberrypi/armhf/*

cd linux
git pull
make O=$BASE_DIR/kernel/armhf -C $BASE_DIR/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- multi_v7_defconfig
make O=$BASE_DIR/kernel/armhf -C $BASE_DIR/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-

cd $BASE_DIR

cd raspberrypi-linux
git pull
make O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm KERNEL=kernel7 CROSS_COMPILE=arm-linux-gnueabihf- bcm2709_defconfig
make O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm KERNEL=kernel7 CROSS_COMPILE=arm-linux-gnueabihf-

cd $BASE_DIR

cp -rf $BASE_DIR/kernel/armhf/arch/arm/boot/dts/arm/vexpress-v2p-ca15-tc1.dtb $BASE_DIR/vexpress-v2p-ca15-tc1.dtb
dtc -q -I dtb -O dts -o vexpress-v2p-ca15-tc1.dts vexpress-v2p-ca15-tc1.dtb

cd $BASE_DIR

cp -rf $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/dts/broadcom/bcm2710-rpi-2-b.dtb $BASE_DIR/bcm2710-rpi-2-b.dtb
dtc -q -I dtb -O dts -o bcm2710-rpi-2-b.dts bcm2710-rpi-2-b.dtb

# Size: 8G
#qemu-img create -f raw rootfs.ext4
dd if=/dev/zero of=rootfs.ext4 bs=4k count=2097152
mkfs.ext4 rootfs.ext4
