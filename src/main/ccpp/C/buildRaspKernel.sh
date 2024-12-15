#/bin/bash

BASE_DIR=$(pwd)

echo 0 | sudo -S rm -rf kernel/raspberrypi/armhf/
echo 0 | sudo -S rm -rf kernel/raspberrypi/arm64/

mkdir -p kernel/raspberrypi/armhf/
mkdir -p kernel/raspberrypi/arm64/

# 32 bit
cd $BASE_DIR/raspberrypi-linux
git pull
KERNEL=kernel7
make -j$(nproc) O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcm2709_defconfig
sed -i -E 's/CONFIG_LOCALVERSION=.*/CONFIG_LOCALVERSION="-v7l-MY_CUSTOM_KERNEL"/' $BASE_DIR/kernel/raspberrypi/armhf/.config
make -j$(nproc) O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
cd $BASE_DIR
cp -rf $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/zImage $BASE_DIR/kernel/raspberrypi/armhf/$KERNEL.img

# 64 bit
# cd $BASE_DIR/raspberrypi-linux
# git pull
# KERNEL=kernel8
# make -j$(nproc) O=$BASE_DIR/kernel/raspberrypi/arm64 -C $BASE_DIR/raspberrypi-linux bcm2711_defconfig
# sed -i -E 's/CONFIG_LOCALVERSION=.*/CONFIG_LOCALVERSION="-v8l-MY_CUSTOM_KERNEL"/' $BASE_DIR/kernel/raspberrypi/arm64/.config
# make -j$(nproc) O=$BASE_DIR/kernel/raspberrypi/arm64 -C $BASE_DIR/raspberrypi-linux
# cd $BASE_DIR
# cp -rf $BASE_DIR/kernel/raspberrypi/arm64/arch/arm64/boot/Image.gz $BASE_DIR/$KERNEL.img

# Size: 8G
# qemu-img create -f raw rootfs.ext4
# dd if=/dev/zero of=rootfs.ext4 bs=4k count=2097152
# mkfs.ext4 rootfs.ext4
