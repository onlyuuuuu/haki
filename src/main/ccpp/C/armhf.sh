#!/bin/bash

echo 0 | sudo -S mkdir -p /usr/local/etc/qemu/
echo 0 | sudo -S cp -rf bridge.conf /usr/local/etc/qemu/

echo 0 | sudo -S mkdir -p /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/qemu/
echo 0 | sudo -S cp -rf bridge.conf /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/qemu/

echo 0 | sudo -S cp -rf qemu-ifup /etc/
echo 0 | sudo -S cp -rf qemu-ifdown /etc/

echo 0 | sudo -S mkdir -p /usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifup /usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifdown /usr/local/etc/

mkdir -p /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/
cp -rf qemu-ifup /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/
cp -rf qemu-ifdown /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/

mkdir -p /tools/qemu/build/qemu-bundle/usr/local/etc/
cp -rf qemu-ifup /tools/qemu/build/qemu-bundle/usr/local/etc/
cp -rf qemu-ifdown /tools/qemu/build/qemu-bundle/usr/local/etc/

echo 0 | sudo -S chmod -R 777 /dev/net/tun
echo 0 | sudo -S chown -R zero:zero /dev/net/tun

/etc/qemu-ifdown tap1 br1 ens38
/etc/qemu-ifdown tap2 br2 ens39
/etc/qemu-ifup tap1 br1 ens38
/etc/qemu-ifup tap2 br2 ens39

echo 0 | sudo -S echo "Gained root access... Starting up VM now..."
# echo 0 | sudo -S qemu-system-arm \
#   -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
#   -kernel tools.dir/postnetinst-boot-vmlinuz-6.1.0-28-armmp-lpae -append 'root=/dev/vda2' \
#   -initrd tools.dir/postnetinst-boot-initrd.img-6.1.0-28-armmp-lpae \
#   -drive if=none,format=raw,file=tools.dir/hda.img,media=disk,id=hd0 \
#   -device virtio-blk-device,drive=hd0 \
#   -netdev tap,id=net0,ifname=tap0 \
#   -device virtio-net-device,netdev=net0 \
#   -netdev bridge,id=net1,br=br1 \
#   -device virtio-net-device,netdev=net1 \
#   -netdev user,id=net2 \
#   -device virtio-net-device,netdev=net2 \
#   -no-reboot \
#   -monitor stdio
echo 0 | sudo -S qemu-system-arm \
  -machine virt -cpu cortex-a15 -smp 8 -m 8192 \
  -kernel tools.dir/postnetinst-boot-vmlinuz-6.1.0-28-armmp-lpae -append 'root=/dev/vda2' \
  -initrd tools.dir/postnetinst-boot-initrd.img-6.1.0-28-armmp-lpae \
  -drive if=none,format=raw,file=tools.dir/hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -monitor stdio
