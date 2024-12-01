#/bin/bash

# 8192    x 512 = 4194304
# 1056768 x 512 = 541065216

# 2048    x 512 = 1048576
# 1050624 x 512 = 537919488

# 0       x 512 = 0
# 1595392 x 512 = 816840704

# echo 0 | sudo -S mount -o loop,offset=0 debian-12.7.0-armhf-netinst.iso mnt/boot
# echo 0 | sudo -S mount -o loop,offset=816840704 debian-12.7.0-armhf-netinst.iso mnt/root

# echo 0 | sudo -S umount mnt/boot
# echo 0 | sudo -S umount mnt/root

BASE_DIR=$(pwd)

mkdir -p mnt/boot
mkdir -p mnt/root
mkdir -p fromRaspiOSImage
mkdir -p fromUbuntuImage

rm -rf *.img
cp -rf /tools/2024-11-19-raspios-bookworm-armhf-lite.img 2024-11-19-raspios-bookworm-armhf-lite.img
cp -rf /tools/2024-11-19-raspios-bookworm-armhf-lite.img 2024-11-19-raspios-bookworm-armhf-lite-manual-kernel.img
cp -rf /tools/ubuntu-22.04.5-preinstalled-server-armhf+raspi.img ubuntu-22.04.5-preinstalled-server-armhf+raspi.img

# 32 bit - Raspberry Pi OS - Bookworm
# This is for updating the image with the latest kernel
# This requires ./buildRaspKernel.sh to be run before this script
# Either use this block and comment out the other block
KERNEL=kernel7
echo 0 | sudo -S rm -rf mnt/boot/*
echo 0 | sudo -S rm -rf mnt/root/*
echo 0 | sudo -S umount mnt/boot 2> /dev/null
echo 0 | sudo -S mount -o loop,offset=4194304 2024-11-19-raspios-bookworm-armhf-lite-manual-kernel.img mnt/boot
echo 0 | sudo -S cp $BASE_DIR/mnt/boot/$KERNEL.img $BASE_DIR/mnt/boot/$KERNEL-backup.img
echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/zImage $BASE_DIR/mnt/boot/$KERNEL.img
echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/dts/broadcom/*.dtb $BASE_DIR/mnt/boot/
echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/dts/overlays/*.dtb* $BASE_DIR/mnt/boot/overlays/
echo 0 | sudo -S cp -rf $BASE_DIR/fromRaspiOSImage/cmdline.raspios.updated.txt $BASE_DIR/mnt/boot/cmdline.txt
echo 0 | sudo -S touch mnt/boot/ssh
echo 0 | sudo -S touch mnt/boot/userconf.txt
echo 0 | sudo -S touch mnt/boot/config.txt
echo 0 | sudo -S echo 'zero:$6$nKazTU9UYkZ15LbS$aKazZgSp5z/ynlHPrDeaE7x5h4AF3bkioe0cJ02eGR7P75HEEOwaJGcunbh/bCzJipC/6UTT/Lh5KC8lhRaJP0' | sudo tee mnt/boot/userconf.txt
echo 0 | sudo -S echo 'arm_64bit=0' | sudo tee -a mnt/boot/config.txt
echo 0 | sudo -S umount mnt/boot
echo 0 | sudo -S umount mnt/root 2> /dev/null
echo 0 | sudo -S mount -o loop,offset=541065216 2024-11-19-raspios-bookworm-armhf-lite-manual-kernel.img mnt/root
echo 0 | sudo -S make -j6 O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=$BASE_DIR/mnt/root modules_install
echo 0 | sudo -S umount mnt/root
qemu-img resize -f raw 2024-11-19-raspios-bookworm-armhf-lite-manual-kernel.img 4G

# 32 bit - Raspberry Pi OS - Bookworm
# This is for using existing image's available resources
# ./buildRaspKernel.sh is not required for this block
# Either use this block and comment out the other block
KERNEL=kernel7
echo 0 | sudo -S rm -rf mnt/boot/*
echo 0 | sudo -S rm -rf mnt/root/*
echo 0 | sudo -S umount mnt/boot 2> /dev/null
echo 0 | sudo -S mount -o loop,offset=4194304 2024-11-19-raspios-bookworm-armhf-lite.img mnt/boot
echo 0 | sudo -S cp -rf $BASE_DIR/mnt/boot/cmdline.txt $BASE_DIR/fromRaspiOSImage/cmdline.raspios.org.txt
echo 0 | sudo -S cp -rf $BASE_DIR/fromRaspiOSImage/cmdline.raspios.updated.txt $BASE_DIR/mnt/boot/cmdline.txt
echo 0 | sudo -S cp -rf $BASE_DIR/mnt/boot/bcm2709-rpi-2-b.dtb $BASE_DIR/fromRaspiOSImage/bcm2709-rpi-2-b.dtb
echo 0 | sudo -S cp -rf $BASE_DIR/mnt/boot/$KERNEL.img $BASE_DIR/fromRaspiOSImage/$KERNEL.img
echo 0 | sudo -S touch mnt/boot/ssh
echo 0 | sudo -S touch mnt/boot/userconf.txt
echo 0 | sudo -S touch mnt/boot/config.txt
echo 0 | sudo -S echo 'zero:$6$nKazTU9UYkZ15LbS$aKazZgSp5z/ynlHPrDeaE7x5h4AF3bkioe0cJ02eGR7P75HEEOwaJGcunbh/bCzJipC/6UTT/Lh5KC8lhRaJP0' | sudo tee mnt/boot/userconf.txt
echo 0 | sudo -S echo 'arm_64bit=0' | sudo tee -a mnt/boot/config.txt
echo 0 | sudo -S umount mnt/boot
echo 0 | sudo -S umount mnt/root 2> /dev/null
echo 0 | sudo -S mount -o loop,offset=541065216 2024-11-19-raspios-bookworm-armhf-lite.img mnt/root
echo 0 | sudo -S umount mnt/root
qemu-img resize -f raw 2024-11-19-raspios-bookworm-armhf-lite.img 4G

# 32 bit - Ubuntu Server
echo 0 | sudo -S rm -rf mnt/boot/*
echo 0 | sudo -S rm -rf mnt/root/*
echo 0 | sudo -S umount mnt/boot 2> /dev/null
echo 0 | sudo -S mount -o loop,offset=1048576 ubuntu-22.04.5-preinstalled-server-armhf+raspi.img mnt/boot
echo 0 | sudo -S cp -rf $BASE_DIR/fromUbuntuImage/cmdline.ubuntu.updated.txt $BASE_DIR/mnt/boot/cmdline.txt
echo 0 | sudo -S cp -rf $BASE_DIR/mnt/boot/bcm2709-rpi-2-b.dtb $BASE_DIR/fromUbuntuImage/bcm2709-rpi-2-b.dtb
echo 0 | sudo -S cp -rf $BASE_DIR/mnt/boot/vmlinuz $BASE_DIR/fromUbuntuImage/vmlinuz
echo 0 | sudo -S umount mnt/boot
echo 0 | sudo -S umount mnt/root 2> /dev/null
echo 0 | sudo -S mount -o loop,offset=537919488 ubuntu-22.04.5-preinstalled-server-armhf+raspi.img mnt/root
echo 0 | sudo -S umount mnt/root
qemu-img resize -f raw ubuntu-22.04.5-preinstalled-server-armhf+raspi.img 8G

# 64 bit
# KERNEL=kernel8
# echo 0 | sudo -S rm -rf mnt/boot/*
# echo 0 | sudo -S rm -rf mnt/root/*
# echo 0 | sudo -S umount mnt/boot 2> /dev/null
# echo 0 | sudo -S mount -o loop,offset=4194304 2024-10-22-raspios-bookworm-arm64-lite.img mnt/boot
# echo 0 | sudo -S mkdir -p $BASE_DIR/mnt/boot/overlays/
# echo 0 | sudo -S cp $BASE_DIR/mnt/boot/$KERNEL.img $BASE_DIR/mnt/boot/$KERNEL-backup.img
# echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/arm64/arch/arm64/boot/Image.gz $BASE_DIR/mnt/boot/$KERNEL.img
# echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/arm64/arch/arm64/boot/dts/broadcom/*.dtb $BASE_DIR/mnt/boot/
# echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/arm64/arch/arm64/boot/dts/overlays/*.dtb* $BASE_DIR/mnt/boot/overlays/
# echo 0 | sudo -S touch mnt/boot/ssh
# echo 0 | sudo -S touch mnt/boot/userconf.txt
# echo 0 | sudo -S echo 'zero:$6$nKazTU9UYkZ15LbS$aKazZgSp5z/ynlHPrDeaE7x5h4AF3bkioe0cJ02eGR7P75HEEOwaJGcunbh/bCzJipC/6UTT/Lh5KC8lhRaJP0' | sudo tee mnt/boot/userconf.txt
# echo 0 | sudo -S umount mnt/boot
# echo 0 | sudo -S umount mnt/root 2> /dev/null
# echo 0 | sudo -S mount -o loop,offset=541065216 2024-10-22-raspios-bookworm-arm64-lite.img mnt/root
# echo 0 | sudo -S make -j6 O=$BASE_DIR/kernel/raspberrypi/arm64 -C $BASE_DIR/raspberrypi-linux INSTALL_MOD_PATH=$BASE_DIR/mnt/root modules_install
# echo 0 | sudo -S umount mnt/root
# qemu-img resize -f raw 2024-10-22-raspios-bookworm-arm64-lite.img 8G
