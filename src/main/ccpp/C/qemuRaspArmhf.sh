#/bin/bash

echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -drive if=sd,format=raw,file=2024-10-22-raspios-bookworm-armhf-lite.img \
  -dtb bcm2709-rpi-2-b.dtb \
  -kernel kernel7.img \
  -append "rw earlyprintk loglevel=8 console=ttyAMA0,115200 dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2 rootdelay=1" \
  -no-reboot \
  -nographic
