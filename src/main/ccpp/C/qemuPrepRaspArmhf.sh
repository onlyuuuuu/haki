#/bin/bash

BASE_DIR=$(pwd)
KERNEL=kernel7

mkdir -p mnt/boot
mkdir -p mnt/root

echo 0 | sudo -S rm -rf mnt/boot/*
echo 0 | sudo -S rm -rf mnt/root/*

# 8192    x 512 = 4194304
# 1056768 x 512 = 541065216

echo 0 | sudo -S mount -o loop,offset=4194304 2024-10-22-raspios-bookworm-armhf-lite.img mnt/boot
echo 0 | sudo -S cp $BASE_DIR/mnt/boot/$KERNEL.img $BASE_DIR/mnt/boot/$KERNEL-backup.img
echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/zImage $BASE_DIR/mnt/boot/$KERNEL.img
echo 0 | sudo -S cp $BASE_DIR/kernel/raspberrypi/armhf/arch/arm/boot/dts/overlays/*.dtb* $BASE_DIR/mnt/boot/overlays/
# cp mnt/boot/bcm2709-rpi-2-b.dtb bcm2709-rpi-2-b.dtb
# cp mnt/boot/bcm2710-rpi-2-b.dtb bcm2710-rpi-2-b.dtb
# cp mnt/boot/bcm2836-rpi-2-b.dtb bcm2836-rpi-2-b.dtb
# cp mnt/boot/kernel7.img kernel7.img
echo 0 | sudo -S touch mnt/boot/ssh
echo 0 | sudo -S touch mnt/boot/userconf
echo 0 | sudo -S echo 'zero:$6$nKazTU9UYkZ15LbS$aKazZgSp5z/ynlHPrDeaE7x5h4AF3bkioe0cJ02eGR7P75HEEOwaJGcunbh/bCzJipC/6UTT/Lh5KC8lhRaJP0' | sudo tee mnt/boot/userconf
echo 0 | sudo -S umount mnt/boot

echo 0 | sudo -S mount -o loop,offset=541065216 2024-10-22-raspios-bookworm-armhf-lite.img mnt/root
echo 0 | sudo -S make O=$BASE_DIR/kernel/raspberrypi/armhf -C $BASE_DIR/raspberrypi-linux ARCH=arm KERNEL=kernel7 CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=$BASE_DIR/mnt/root modules_install
echo 0 | sudo -S umount mnt/root

qemu-img resize -f raw 2024-10-22-raspios-bookworm-armhf-lite.img 4G
# qemu-img resize -f raw 2024-10-22-raspios-bookworm-armhf.img 8G
