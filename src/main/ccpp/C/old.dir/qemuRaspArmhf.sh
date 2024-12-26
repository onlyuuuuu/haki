#/bin/bash

# git clone https://gitlab.com/qemu-project/qemu.git
# sudo apt-get install git libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev ninja-build meson
# git clone https://gitlab.freedesktop.org/slirp/libslirp.git
# cd libslirp
# meson build
# ninja -C build install
# cd ..
# cd qemu
# mkdir -p bin/debug/native
# cd bin/debug/native
# ../../.././configure --enable-slirp --enable-debug
# make -j$(nproc)
# make install
# cd ../../..

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
ifconfig ens33 down
brctl addbr br0
ip addr flush dev ens33
brctl addif br0 ens33
tunctl -t tap0 -u zero
brctl addif br0 tap0
ifconfig ens33 up
ifconfig tap0 up
ifconfig br0 up
brctl show
dhclient -v br0

# Tap network cleanup
ifconfig ens33 down
ifconfig tap0 down
ifconfig br0 down
brctl delif br0 tap0
tunctl -d tap0
brctl delif br0 ens33
ifconfig br0 down
brctl delbr br0
ifconfig ens33 up
dhclient -v ens33

# dhclient - Auto configuration using a DHCP server
dhclient -v -r ens33 # Release IP
dhclient -v ens33    # Request IP

qemu-system-arm -machine virt -cpu cortex-a15 -smp 8 -m 8192 -hda hda.img -cdrom debian-12.8.0-armhf-DVD-1.iso -no-reboot -monitor stdio

echo 0 | sudo -S tunctl -t tap0 -u zero

203.113.131.2
203.113.188.8

# Armhf debian still not support -pci, vague memory...
# Online boot from net install ISO
# Net install phase
qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel installer-online-vmlinuz \
  -initrd installer-online-initrd.gz \
  -drive if=none,format=raw,file=hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -no-reboot \
  -monitor stdio

qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel installer-online-vmlinuz \
  -initrd installer-online-initrd.gz \
  -drive if=none,format=raw,file=hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -netdev bridge,id=net1 \
  -device virtio-net-device,netdev=net1 \
  -netdev user,id=net2 \
  -device virtio-net-device,netdev=net2 \
  -no-reboot \
  -monitor stdio

# Post install phase
qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel postnetinst-boot-vmlinuz-6.1.0-28-armmp-lpae -append 'root=/dev/vda2' \
  -initrd postnetinst-boot-initrd.img-6.1.0-28-armmp-lpae \
  -drive if=none,format=raw,file=hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -no-reboot \
  -monitor stdio

qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel postnetinst-boot-vmlinuz-6.1.0-28-armmp-lpae -append 'root=/dev/vda2' \
  -initrd postnetinst-boot-initrd.img-6.1.0-28-armmp-lpae \
  -drive if=none,format=raw,file=hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -netdev bridge,id=net1 \
  -device virtio-net-device,netdev=net1 \
  -netdev user,id=net2 \
  -device virtio-net-device,netdev=net2 \
  -no-reboot \
  -monitor stdio

# Offline boot from full ISO (not net install)
# ARM probably not supported booting from ISO/DVD/CDROM
# TODO: Confirm this theory on other architectures
qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -boot once=d \
  -drive format=raw,file=debian-12.8.0-armhf-DVD-1.iso,media=cdrom,id=cd \
  -drive format=raw,file=hda.img,media=disk,id=hd \
  -netdev tap,script=no,downscript=no,ifname=tap0,id=net0 \
  -device virtio-net-pci,netdev=net0,mac=1d:07:40:60:d3:da, \
  -no-reboot \
  -monitor stdio

# FOR NET INSTALL
# mount -o loop,offset=1048576 hda.img mnt/boot
# mount -o loop,offset=511705088 hda.img mnt/root

# FOR NON-NET INSTALL
# mount -o loop,offset=0 hda.img mnt/boot
# mount -o loop,offset=4677378048 hda.img mnt/root

qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel vmlinuz-6.1.0-28-armmp-lpae \
  -initrd initrd.img-6.1.0-28-armmp-lpae \
  -append 'root=/dev/vda2' \
  -drive if=none,file=hda.img,format=raw,id=hd \
  -device virtio-blk-device,drive=hd \
  -netdev tap,ifname=tap0,id=net0 \
  -device virtio-net-device,netdev=net0,mac=1d:07:40:60:d3:da, \
  -no-reboot \
  -monitor stdio
