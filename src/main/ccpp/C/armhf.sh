#!/bin/bash

echo 0 | sudo -S cp -rf qemu-ifup /etc/
echo 0 | sudo -S cp -rf qemu-ifdown /etc/

mkdir -p /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/
cp -rf qemu-ifup /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/
cp -rf qemu-ifdown /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/

mkdir -p /tools/qemu/build/qemu-bundle/usr/local/etc/
cp -rf qemu-ifup /tools/qemu/build/qemu-bundle/usr/local/etc/
cp -rf qemu-ifdown /tools/qemu/build/qemu-bundle/usr/local/etc/

/etc/qemu-ifup tap1 br1
/etc/qemu-ifup tap2 br2

qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel tools.d/postnetinst-boot-vmlinuz-6.1.0-28-armmp-lpae -append 'root=/dev/vda2' \
  -initrd tools.d/postnetinst-boot-initrd.img-6.1.0-28-armmp-lpae \
  -drive if=none,format=raw,file=hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -netdev bridge,id=net1,br=br1 \
  -device virtio-net-device,netdev=net1 \
  -netdev user,id=net2 \
  -device virtio-net-device,netdev=net2 \
  -no-reboot \
  -monitor stdio
