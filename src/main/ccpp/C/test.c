#include <stdio.h>

int main()
{
    printf("If you are seeing this output, congrats...\n");
    printf("Use these commands to compile me:\n");
    printf("  * On Linux:\n");
    printf("      $ arm-linux-gnueabihf-gcc -Wl,-I/usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 test.c -o test -g -Og -L/usr/arm-linux-gnueabihf/lib\n");
    printf("      $ patchelf --set-rpath /usr/arm-linux-gnueabihf/lib test\n");
    return 0;
}
