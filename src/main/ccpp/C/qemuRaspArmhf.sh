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
  -device usb-host,hostbus=3,hostaddr=5 \
  -drive if=sd,format=raw,file=2024-11-19-raspios-bookworm-armhf-lite.img \
  -dtb fromRaspiOSImage/bcm2709-rpi-2-b.dtb \
  -kernel fromRaspiOSImage/kernel7.img \
  -append "rw earlyprintk loglevel=8 root=/dev/mmcblk0p2 rootwait dwc_otg.lpm_enable=0 dwc_otg.speed=1" #-no-reboot -nographic

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
  -usb \
  -device usb-host,hostbus=3,hostaddr=5 \
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

echo 0 | sudo -S qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 4 -m 4096 \
  -hda ubuntu-22.04.5-preinstalled-server-armhf+raspi.img \
  -kernel fromUbuntuImage/vmlinuz \
  -append "rw earlyprintk loglevel=8 root=/dev/sda2 rootwait fdt_addr=r2" #-no-reboot -nographic

# cp -rf /tools/debian-12.8.0-armhf-netinst/install.ahf/netboot/initrd.gz installer-initrd.gz
# cp -rf /tools/debian-12.8.0-armhf-netinst/install.ahf/netboot/vmlinuz installer-vmlinuz
# cp -rf /tools/debian-12.8.0-armhf.iso debian-12.8.0-armhf.iso
# qemu-img create -f raw hda.img 16G
# qemu-img create -f qcow2 hda.qcow2 16G

# Tap network setup
ifconfig wlp0s20f3 down
brctl addbr br0
ip addr flush dev wlp0s20f3
brctl addif br0 wlp0s20f3
tunctl -t tap0 -u $(whoami)
brctl addif br0 tap0
ifconfig wlp0s20f3 up
ifconfig tap0 up
ifconfig br0 up
brctl show
dhclient -v br0

# Tap network cleanup
ifconfig wlp0s20f3 down
ifconfig tap0 down
ifconfig br0 down
brctl delif br0 tap0
tunctl -d tap0
brctl delif br0 wlp0s20f3
ifconfig br0 down
brctl delbr br0
ifconfig wlp0s20f3 up
dhclient -v wlp0s20f3

# dhclient - Auto configuration using a DHCP server
dhclient -v -r wlp0s20f3 # Release IP
dhclient -v wlp0s20f3    # Request IP

qemu-system-arm -machine virt -cpu cortex-a15 -smp 4 -m 4096 -hda hda.img -cdrom debian-12.8.0-armhf.iso

qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel installer-vmlinuz \
  -initrd installer-initrd.gz \
  -drive if=none,file=hda.img,format=raw,id=hd \
  -device virtio-blk-device,drive=hd \
  -netdev user,id=mynet \
  -device virtio-net-device,netdev=mynet \
  -no-reboot \
  -monitor stdio

# mount -o loop,offset=1048576 hda.img mnt/boot
# mount -o loop,offset=511705088 hda.img mnt/root

qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel vmlinuz-6.1.0-28-armmp-lpae \
  -initrd initrd.img-6.1.0-28-armmp-lpae \
  -append 'root=/dev/vda2' \
  -drive if=none,file=hda.img,format=raw,id=hd \
  -device virtio-blk-device,drive=hd \
  -netdev user,id=mynet \
  -device virtio-net-device,netdev=mynet \
  -no-reboot \
  -monitor stdio
