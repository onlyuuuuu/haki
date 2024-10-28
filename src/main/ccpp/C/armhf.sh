#/bin/bash

#qemu-system-arm [machine opts] \
#                [cpu opts] \
#                [accelerator opts] \
#                [device opts] \
#                [backend opts] \
#                [interface opts] \
#                [boot opts]

#qemu-img resize -f raw /Users/onlyu/Downloads/ubuntu-mate-22.04-desktop-armhf+raspi.img 8G
#
#qemu-system-arm -machine type=raspi0 \
#                -cpu cortex-a7 \
#                -drive file=/Users/onlyu/Downloads/ubuntu-mate-22.04-desktop-armhf+raspi.img,format=raw

#qemu-system-arm \
#  -M versatilepb \
#  -cpu cortex-a7 \
#  -m 256 \
#  -drive "file=2023-05-03-raspios-bullseye-armhf-lite.img,if=none,index=0,media=disk,format=raw,id=disk0" \
#  -device "virtio-blk-pci,drive=disk0,disable-modern=on,disable-legacy=off" \
#  -net "user,hostfwd=tcp::5022-:22" \
#  -dtb qemu-rpi-kernel/versatile-pb-bullseye-5.10.63.dtb \
#  -kernel qemu-rpi-kernel/kernel-qemu-5.10.63-bullseye \
#  -append 'root=/dev/vda2 panic=1' \
#  -no-reboot

if [[ "$(uname)" != "Darwin" ]]; then
  brctl addbr br0
  ip addr flush dev eth0
  brctl addif br0 eth0
  tunctl -t tap0 -u $(whoami)
  brctl addif br0 tap0
  ifconfig eth0 up
  ifconfig tap0 up
  ifconfig br0 up
  brctl show
  dhclient -v br0
fi

qemu-system-arm \
  -M versatilepb \
  -cpu arm1176 \
  -m 256 \
  -drive "file=2020-05-27-raspios-buster-lite-armhf.img,if=none,index=0,media=disk,format=raw,id=disk0" \
  -device "virtio-blk-pci,drive=disk0,disable-modern=on,disable-legacy=off" \
  -netdev tap,id=nd0,ifname=tap0,script=no,downscript=no \
  -dtb qemu-rpi-kernel/versatile-pb-buster-5.4.51.dtb \
  -kernel qemu-rpi-kernel/kernel-qemu-5.4.51-buster \
  -append 'root=/dev/vda2 panic=1' \
  -no-reboot
