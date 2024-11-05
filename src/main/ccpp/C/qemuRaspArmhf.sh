#/bin/bash

echo 0 | sudo -S qemu-system-arm -D raspi2b.debug.log \
  -machine raspi2b \
  -drive if=sd,format=raw,file=2024-10-22-raspios-bookworm-armhf-lite.img \
  -dtb kernel/raspberrypi/armhf/arch/arm/boot/dts/broadcom/bcm2709-rpi-2-b.dtb \
  -kernel kernel7.img \
  -append "rw earlyprintk loglevel=8 console=ttyAMA0,115200 dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2 rootdelay=1" \
  -no-reboot \
  -nographic

echo 0 | sudo -S qemu-system-aarch64 \
  -machine raspi3b \
  -drive if=sd,format=raw,file=2024-10-22-raspios-bookworm-arm64-lite.img \
  -dtb kernel/raspberrypi/arm64/arch/arm64/boot/dts/broadcom/bcm2711-rpi-4-b.dtb \
  -kernel kernel8.img \
  -append "rw earlyprintk loglevel=8 console=ttyAMA0,115200 dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2 rootdelay=1" \
  -no-reboot \
  -nographic
