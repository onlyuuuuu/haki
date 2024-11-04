#!/bin/bash

echo 0 | sudo -S apt install -y gcc \
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
                                ninja-build \
                                crossbuild-essential-armel \
                                crossbuild-essential-armhf \
                                crossbuild-essential-arm64 \
                                crossbuild-essential-i386 \
                                crossbuild-essential-amd64 \
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
                                python3-full \
                                python3-sphinx \
                                python3-pip \
                                python-is-python3 \
                                pipx \
                                java \
                                perl

echo 0 | sudo -S apt install -y libglib2.0-dev \
                                libgcrypt20-dev \
                                zlib1g-dev \
                                autoconf \
                                automake \
                                libtool \
                                bison \
                                flex \
                                libpixman-1-dev

echo 0 | sudo -S apt install -y git libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev ninja-build

echo 0 | sudo -S apt install -y git-email
echo 0 | sudo -S apt install -y libaio-dev libbluetooth-dev libcapstone-dev libbrlapi-dev libbz2-dev
echo 0 | sudo -S apt install -y libcap-ng-dev libcurl4-gnutls-dev libgtk-3-dev
echo 0 | sudo -S apt install -y libibverbs-dev libjpeg8-dev libncurses5-dev libnuma-dev
echo 0 | sudo -S apt install -y librbd-dev librdmacm-dev
echo 0 | sudo -S apt install -y libsasl2-dev libsdl2-dev libseccomp-dev libsnappy-dev libssh-dev
echo 0 | sudo -S apt install -y libvde-dev libvdeplug-dev libvte-2.91-dev libxen-dev liblzo2-dev
echo 0 | sudo -S apt install -y valgrind xfslibs-dev
echo 0 | sudo -S apt install -y libnfs-dev libiscsi-dev

pipx install sphinx_rtd_theme --include-deps
pipx ensurepath
pip install sphinx_rtd_theme --break-system-packages
