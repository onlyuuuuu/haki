#/bin/bash

  # -netdev user,id=net0,hostfwd=tcp::2222-:22 \
  # -device usb-net,netdev=net0 \

# From kernel
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -usb -device usb-host,hostbus=1,hostaddr=4 \
  -drive if=sd,format=raw,file=2024-11-19-raspios-bookworm-armhf-lite-manual-kernel.img \
  -dtb kernel/raspberrypi/armhf/arch/arm/boot/dts/broadcom/bcm2709-rpi-2-b.dtb \
  -kernel kernel/raspberrypi/armhf/kernel7.img \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait" -no-reboot -nographic

# From image
# No keyboard
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -drive if=sd,format=raw,file=2024-11-19-raspios-bookworm-armhf-lite.img \
  -dtb fromRaspiOSImage/bcm2709-rpi-2-b.dtb \
  -kernel fromRaspiOSImage/kernel7.img \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait" #-no-reboot -nographic
# With keyboard
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -usb \
  -device usb-host,hostbus=1,hostaddr=4 \
  -drive if=sd,format=raw,file=2024-11-19-raspios-bookworm-armhf-lite.img \
  -dtb fromRaspiOSImage/bcm2709-rpi-2-b.dtb \
  -kernel fromRaspiOSImage/kernel7.img \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait" #-no-reboot -nographic

# From image (Ubuntu Server)
# No keyboard
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -drive if=sd,format=raw,file=ubuntu-22.04.5-preinstalled-server-armhf+raspi.img \
  -dtb fromUbuntuImage/bcm2709-rpi-2-b.dtb \
  -kernel fromUbuntuImage/vmlinuz \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait" #-no-reboot -nographic
# With keyboard
echo 0 | sudo -S qemu-system-arm \
  -machine raspi2b \
  -device usb-host,hostbus=1,hostaddr=4 \
  -drive if=sd,format=raw,file=ubuntu-22.04.5-preinstalled-server-armhf+raspi.img \
  -dtb fromUbuntuImage/bcm2709-rpi-2-b.dtb \
  -kernel fromUbuntuImage/vmlinuz \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait" #-no-reboot -nographic

# echo 0 | sudo -S qemu-system-aarch64 \
#   -machine raspi3b \
#   -drive if=sd,format=raw,file=2024-10-22-raspios-bookworm-arm64-lite.img \
#   -dtb kernel/raspberrypi/arm64/arch/arm64/boot/dts/broadcom/bcm2711-rpi-4-b.dtb \
#   -kernel kernel8.img \
#   -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait" #-no-reboot -nographic
