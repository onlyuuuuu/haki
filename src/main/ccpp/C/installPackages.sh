#!/bin/bash

echo 0 | sudo -S apt install -y gcc
echo 0 | sudo -S apt install -y gcc-arm-linux-gnueabi
echo 0 | sudo -S apt install -y gcc-arm-linux-gnueabihf
echo 0 | sudo -S apt install -y gdb
echo 0 | sudo -S apt install -y gdb-multiarch
echo 0 | sudo -S apt install -y qemu-user
echo 0 | sudo -S apt install -y qemu-user-static
echo 0 | sudo -S apt install -y qemu-system
echo 0 | sudo -S apt install -y dtc
echo 0 | sudo -S apt install -y make
echo 0 | sudo -S apt install -y cmake
echo 0 | sudo -S apt install -y ninja-build
echo 0 | sudo -S apt install -y crossbuild-essential-armel
echo 0 | sudo -S apt install -y crossbuild-essential-armhf
echo 0 | sudo -S apt install -y crossbuild-essential-arm64
echo 0 | sudo -S apt install -y crossbuild-essential-i386
echo 0 | sudo -S apt install -y crossbuild-essential-amd64
echo 0 | sudo -S apt install -y git
echo 0 | sudo -S apt install -y flex
echo 0 | sudo -S apt install -y bison
echo 0 | sudo -S apt install -y bc
echo 0 | sudo -S apt install -y libncurses-dev
echo 0 | sudo -S apt install -y exuberant-ctags
echo 0 | sudo -S apt install -y libssl-dev
echo 0 | sudo -S apt install -y binutils
echo 0 | sudo -S apt install -y util-linux
echo 0 | sudo -S apt install -y e2fsprogs
echo 0 | sudo -S apt install -y jfsutils
echo 0 | sudo -S apt install -y reiserfsprogs
echo 0 | sudo -S apt install -y xfsprogs
echo 0 | sudo -S apt install -y squashfs-tools
echo 0 | sudo -S apt install -y btrfs-progs
echo 0 | sudo -S apt install -y pcmciautils
echo 0 | sudo -S apt install -y quota
echo 0 | sudo -S apt install -y ppp
echo 0 | sudo -S apt install -y procps
echo 0 | sudo -S apt install -y oprofile
echo 0 | sudo -S apt install -y udev
echo 0 | sudo -S apt install -y grub2-common
echo 0 | sudo -S apt install -y iptables
echo 0 | sudo -S apt install -y python3-full
echo 0 | sudo -S apt install -y python3-sphinx
echo 0 | sudo -S apt install -y python3-pip
echo 0 | sudo -S apt install -y python-is-python3
echo 0 | sudo -S apt install -y pipx
echo 0 | sudo -S apt install -y java
echo 0 | sudo -S apt install -y perl

echo 0 | sudo -S apt install -y libglib2.0-dev
echo 0 | sudo -S apt install -y libgcrypt20-dev
echo 0 | sudo -S apt install -y zlib1g-dev
echo 0 | sudo -S apt install -y autoconf
echo 0 | sudo -S apt install -y automake
echo 0 | sudo -S apt install -y libtool
echo 0 | sudo -S apt install -y bison
echo 0 | sudo -S apt install -y flex
echo 0 | sudo -S apt install -y libpixman-1-dev

echo 0 | sudo -S apt install -y git
echo 0 | sudo -S apt install -y libglib2.0-dev
echo 0 | sudo -S apt install -y libfdt-dev
echo 0 | sudo -S apt install -y libpixman-1-dev
echo 0 | sudo -S apt install -y zlib1g-dev
echo 0 | sudo -S apt install -y ninja-build

echo 0 | sudo -S apt install -y git-email
echo 0 | sudo -S apt install -y libaio-dev
echo 0 | sudo -S apt install -y libbluetooth-dev 
echo 0 | sudo -S apt install -y libcapstone-dev 
echo 0 | sudo -S apt install -y libbrlapi-dev 
echo 0 | sudo -S apt install -y libbz2-dev
echo 0 | sudo -S apt install -y libcap-ng-dev
echo 0 | sudo -S apt install -y libcurl4-gnutls-dev 
echo 0 | sudo -S apt install -y libgtk-3-dev
echo 0 | sudo -S apt install -y libibverbs-dev
echo 0 | sudo -S apt install -y libjpeg8-dev 
echo 0 | sudo -S apt install -y libncurses5-dev 
echo 0 | sudo -S apt install -y libnuma-dev
echo 0 | sudo -S apt install -y librbd-dev
echo 0 | sudo -S apt install -y librdmacm-dev
echo 0 | sudo -S apt install -y libsasl2-dev
echo 0 | sudo -S apt install -y libsdl2-dev
echo 0 | sudo -S apt install -y libseccomp-dev
echo 0 | sudo -S apt install -y libsnappy-dev
echo 0 | sudo -S apt install -y libssh-dev
echo 0 | sudo -S apt install -y libvde-dev
echo 0 | sudo -S apt install -y libvdeplug-dev
echo 0 | sudo -S apt install -y libvte-2.91-dev
echo 0 | sudo -S apt install -y libxen-dev
echo 0 | sudo -S apt install -y liblzo2-dev
echo 0 | sudo -S apt install -y valgrind
echo 0 | sudo -S apt install -y xfslibs-dev
echo 0 | sudo -S apt install -y libnfs-dev
echo 0 | sudo -S apt install -y libiscsi-dev
echo 0 | sudo -S apt install libarchive-tools

pipx install sphinx_rtd_theme --include-deps
pipx ensurepath
pip install sphinx_rtd_theme --break-system-packages
