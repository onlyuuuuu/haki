#!/bin/bash

# Download netinst debian iso
# Extract .iso content
# Get initrd and vmlinuz from install.ahf/ and use them to boot vm with qemu -kernel and initrd options
# Install debian onto hda.img and make sure that our qemu NIC is backed by a internet-connected host interface/bridge
# Make sure that we have internet connection to install Debian ARMHF (32 bit, ARMv7)

# These commands are for libslirp (related to -net user)

# Run this first as root: 
# cd /tools/libslirp/ && meson build && ninja -C build install

# Installing libslirp.so.0.4.0 to /usr/local/lib/x86_64-linux-gnu
# Installing /tools/libslirp/src/libslirp.h to /usr/local/include/slirp
# Installing /tools/libslirp/build/libslirp-version.h to /usr/local/include/slirp
# Installing /tools/libslirp/build/meson-private/slirp.pc to /usr/local/lib/x86_64-linux-gnu/pkgconfig
# Installing symlink pointing to libslirp.so.0.4.0 to /usr/local/lib/x86_64-linux-gnu/libslirp.so.0
# Installing symlink pointing to libslirp.so.0 to /usr/local/lib/x86_64-linux-gnu/libslirp.so

# mkdir -p /lib/x86_64-linux-gnu/OLD.libslirp.d/
# mv /lib/x86_64-linux-gnu/libslirp.a /lib/x86_64-linux-gnu/OLD.libslirp.d/
# mv /lib/x86_64-linux-gnu/libslirp.so /lib/x86_64-linux-gnu/OLD.libslirp.d/
# mv /lib/x86_64-linux-gnu/libslirp.so.0 /lib/x86_64-linux-gnu/OLD.libslirp.d/
# mv /lib/x86_64-linux-gnu/libslirp.so.0.4.0 /lib/x86_64-linux-gnu/OLD.libslirp.d/
# tar czvf /lib/x86_64-linux-gnu/OLD.libslirp.d.tgz /lib/x86_64-linux-gnu/OLD.libslirp.d

cp -rf /usr/local/lib/x86_64-linux-gnu/libslirp.so.0.4.0 /lib/x86_64-linux-gnu/
cp -rf /usr/local/lib/x86_64-linux-gnu/pkgconfig/slirp.pc /lib/x86_64-linux-gnu/pkgconfig/
cp -rf /usr/local/lib/x86_64-linux-gnu/libslirp.so /lib/x86_64-linux-gnu/
cp -rf /usr/local/lib/x86_64-linux-gnu/libslirp.so.0 /lib/x86_64-linux-gnu/
