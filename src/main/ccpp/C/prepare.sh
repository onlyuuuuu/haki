#!/bin/bash

# Download netinst debian iso
# Extract .iso content
# Get initrd and vmlinuz from install.ahf/ and use them to boot vm with qemu -kernel and initrd options
# Install debian onto hda.img and make sure that our qemu NIC is backed by a internet-connected host interface/bridge
# Make sure that we have internet connection to install Debian ARMHF (32 bit, ARMv7)
