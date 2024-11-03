#/bin/bash

# sudo qemu-system-arm \
#   -M versatilepb \
#   -cpu arm1176 \
#   -m 256 \
#   -drive file=2020-05-27-raspios-buster-lite-armhf.img,if=none,index=0,media=disk,format=raw,id=disk0 \
#   -net nic \
#   -net user,hostfwd=tcp::2222-:22 \
#   -device virtio-blk-pci,drive=disk0,disable-modern=on,disable-legacy=off \
#   -dtb qemu-rpi-kernel/versatile-pb-buster-5.4.51.dtb \
#   -kernel qemu-rpi-kernel/kernel-qemu-5.4.51-buster \
#   -append 'root=/dev/vda2 panic=1' \
#   -no-reboot

qemu-system-arm -cpu cortex-a15 -smp 1 -m 4096 \
    -machine type=vexpress-a15 -serial mon:stdio \
    -drive if=sd,driver=file,filename=rootfs.ext4 \
    -kernel kernel/armhf/arch/arm/boot/zImage  \
    -dtb vexpress-v2p-ca15-tc1.dtb \
    -append "console=ttyAMA0 root=/dev/mmcblk0 ro" \
    -nographic
