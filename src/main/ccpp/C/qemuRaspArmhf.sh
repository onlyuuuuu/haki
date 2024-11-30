#/bin/bash

  # -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  # -device usb-net,netdev=net0 \

# From kernel
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -drive if=sd,format=raw,file=2024-10-22-raspios-bookworm-armhf-lite.img \
  -dtb kernel/raspberrypi/armhf/arch/arm/boot/dts/broadcom/bcm2709-rpi-2-b.dtb \
  -kernel kernel7.img \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2" #-no-reboot -nographic

# From image
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -drive if=sd,format=raw,file=2024-11-19-raspios-bookworm-armhf-lite.img \
  -dtb bcm2709-rpi-2-b.dtb \
  -kernel kernel7.img \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2" #-no-reboot -nographic

# From image (Ubuntu Server)
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -drive if=sd,format=raw,file=ubuntu-22.04.5-preinstalled-server-armhf+raspi.img \
  -dtb bcm2709-rpi-2-b.dtb \
  -kernel vmlinuz \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2" #-no-reboot -nographic

# echo 0 | sudo -S qemu-system-aarch64 \
#   -machine raspi3b \
#   -drive if=sd,format=raw,file=2024-10-22-raspios-bookworm-arm64-lite.img \
#   -dtb kernel/raspberrypi/arm64/arch/arm64/boot/dts/broadcom/bcm2711-rpi-4-b.dtb \
#   -kernel kernel8.img \
#   -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2" #-no-reboot -nographic
