#/bin/bash

arm-linux-gnueabihf-gcc -Wl,-I/usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 test.c -o test -g -Og -L/usr/arm-linux-gnueabihf/lib
patchelf --set-rpath /usr/arm-linux-gnueabihf/lib test
