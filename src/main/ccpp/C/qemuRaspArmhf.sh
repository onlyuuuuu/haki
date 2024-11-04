#/bin/bash

echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -cpu cortex-a7 \
  -smp 4 \
  -m 1G \
  -sd 2024-10-22-raspios-bookworm-armhf-lite.img \
  -dtb bcm2709-rpi-2-b.dtb \
  -kernel kernel7.img \
  -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  -device usb-net,netdev=net0 \
  -append "rw earlyprintk loglevel=8 console=ttyAMA0,115200 dwc_otg.lpm_enable=0 root=/dev/mmcblk0p2 rootdelay=1" \
  -no-reboot
