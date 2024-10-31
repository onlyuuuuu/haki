#/bin/bash

sudo apt install -y --allow-insecure-repositories   gcc \
                                                    gcc-arm-linux-gnueabi \
                                                    gcc-arm-linux-gnueabihf \
                                                    gdb \
                                                    gdb-multiarch \
                                                    qemu-user \
                                                    qemu-user-static \
                                                    qemu-system \
                                                    make \
                                                    cmake \
                                                    git \
                                                    flex \
                                                    bison \
                                                    bc \
                                                    libncurses-dev \
                                                    exuberant-ctags \
                                                    libssl-dev \
                                                    binutils \
                                                    util-linux \
                                                    e2fsprogs \
                                                    jfsutils \
                                                    reiserfsprogs \
                                                    xfsprogs \
                                                    squashfs-tools \
                                                    btrfs-progs \
                                                    pcmciautils \
                                                    quota \
                                                    ppp \
                                                    procps \
                                                    oprofile \
                                                    udev \
                                                    grub2-common \
                                                    iptables \
                                                    python3-sphinx

mkdir -p kernel/armhf/
rm -rf kernel/armhf/*

make O=$(pwd)/kernel/armhf -C $(pwd)/linux ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- multi_v7_defconfig
