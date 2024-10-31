#!/bin/bash

#/bin/bash

sudo apt install -y --allow-insecure-repositories   gcc \
                                                    gcc-arm-linux-gnueabi \
                                                    gcc-arm-linux-gnueabihf \
                                                    gdb \
                                                    gdb-multiarch \
                                                    qemu-user \
                                                    qemu-user-static \
                                                    qemu-system \
                                                    dtc \
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
                                                    python3-sphinx \
                                                    java \
                                                    perl

#git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git > /dev/null 2>&1 &

sudo mkdir -p /tools && sudo chown -R zero:zero /tools
sudo mkdir -p /x && sudo chown -R zero:zero /x
sudo mkdir -p /y && sudo chown -R zero:zero /y
sudo mkdir -p /z && sudo chown -R zero:zero /z
sudo mkdir -p /0 && sudo chown -R zero:zero /0

cd /tools
if [[ "$(uname -p)" == "aarch64" ]]; then
    curl -L -o code.deb 'https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-arm64'
else
    curl -L -o code.deb 'https://code.visualstudio.com/sha/download?build=stable&os=linux-deb-x64'
fi
sudo dpkg -i code.deb

if [[ "$(uname -p)" == "aarch64" ]]; then
    curl -L -o toolbox.tar.gz 'https://download.jetbrains.com/toolbox/jetbrains-toolbox-2.5.1.34629-arm64.tar.gz?_gl=1*1ntrigw*_gcl_au*MTE5NjA2NTU2Ni4xNzI0MzgwMDMx*_ga*MTkwODQ3NDU5My4xNjY0ODk2NjIz*_ga_9J976DJZ68*MTczMDM3MjA1OS4xMDcuMS4xNzMwMzcyMjIzLjU5LjAuMA..'
else
    curl -L -o toolbox.tar.gz 'https://download.jetbrains.com/toolbox/jetbrains-toolbox-2.5.1.34629.tar.gz?_gl=1*1g5a3bm*_gcl_au*MTE5NjA2NTU2Ni4xNzI0MzgwMDMx*_ga*MTkwODQ3NDU5My4xNjY0ODk2NjIz*_ga_9J976DJZ68*MTczMDM3MjA1OS4xMDcuMS4xNzMwMzcyMjQ4LjM0LjAuMA..'
fi
tar xzvf toolbox.tar.gz
find . -type d -name "jetbrains-toolbox-*" -exec mv {}/jetbrains-toolbox jetbrains-toolbox \; > /dev/null 2>&1
find . -type d -name "jetbrains-toolbox-*" -exec rm -rf {} \; > /dev/null 2>&1
./jetbrains-toolbox

git clone https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
