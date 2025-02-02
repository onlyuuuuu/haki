#!/bin/bash

echo 0 | sudo -S chown -R zero:zero /tools/qemu/

echo 0 | sudo -S mkdir -p /usr/local/etc/qemu/
echo 0 | sudo -S cp -rf bridge.conf /usr/local/etc/qemu/

echo 0 | sudo -S mkdir -p /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/qemu/
echo 0 | sudo -S cp -rf bridge.conf /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/qemu/

echo 0 | sudo -S cp -rf qemu-ifup /etc/
echo 0 | sudo -S cp -rf qemu-ifdown /etc/

echo 0 | sudo -S mkdir -p /usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifup /usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifdown /usr/local/etc/

echo 0 | sudo -S mkdir -p /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifup /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifdown /tools/qemu/bin/debug/native/qemu-bundle/usr/local/etc/

echo 0 | sudo -S mkdir -p /tools/qemu/build/qemu-bundle/usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifup /tools/qemu/build/qemu-bundle/usr/local/etc/
echo 0 | sudo -S cp -rf qemu-ifdown /tools/qemu/build/qemu-bundle/usr/local/etc/

echo 0 | sudo -S chmod -R 777 /dev/net/tun
echo 0 | sudo -S chown -R zero:zero /dev/net/tun

echo 0 | sudo -S chown -R zero:zero /tools/qemu/

echo 0 | sudo -S echo "Gained root access... Starting up VM now..."

# echo 0 | sudo -S qemu-system-arm \
#   -machine virt -cpu cortex-a15 -smp "${nproc}" -m "$((30*1024))" \
#   -kernel tools.dir/vmlinuz -append 'root=/dev/vda2' \
#   -initrd tools.dir/initrd.img \
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
  -machine virt -cpu cortex-a15 -smp "${nproc}" -m "$((30*1024))" \
  -kernel tools.dir/vmlinuz -append 'root=/dev/vda2' \
  -initrd tools.dir/initrd.img \
  -drive if=none,format=raw,file=tools.dir/hda.img,media=disk,id=hd0 \
  -device virtio-blk-device,drive=hd0 \
  -netdev tap,id=net0,ifname=tap0 \
  -device virtio-net-device,netdev=net0 \
  -monitor stdio

echo 0 | sudo -S chown -R zero:zero /tools/qemu/

# To inspect hda.img
# fdisk -l hda.img
# echo 0 | sudo -S mount -o loop,offset=1048576 hda.img mnt/boot
# echo 0 | sudo -S mount -o loop,offset=511705088 hda.img mnt/root
# echo 0 | sudo -S umount mnt/boot
# echo 0 | sudo -S umount mnt/root
