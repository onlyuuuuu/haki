#include <stdio.h>

int main()
{
    printf("\nHello there!\n\n");
    printf("If you are seeing this output, congrats...\n\n");
    printf("Use these commands to compile me:\n\n");
    printf("  * On Linux (compile for OS-native target):\n");
    printf("      $ gcc test.c -o test -g -Og\n\n");
    printf("  * On Linux (compile for ARM 32-bit target):\n");
    printf("      $ arm-linux-gnueabihf-gcc -Wl,-I/usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 test.c -o test -g -O0 -L/usr/arm-linux-gnueabihf/lib\n");
    printf("      $ patchelf --set-rpath /usr/arm-linux-gnueabihf/lib test\n\n");
    return 0;
}
