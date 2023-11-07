#include <stdio.h>

int main(void) {
    int val = 0xCAFE;
    int bits = val & 0xF;

    if (bits == 0x7 || bits == 0xB || bits >= 0xD) {
        printf("%s\n", "at least three of last four bits (LSB) are on");
    }

    printf("Number: %x\n", val);

    int val2 = ((0xFF & val) << 8) | (val >> 8);
    printf("Reverse order: %x\n", val2);

    int val3 = (val >> 4) | ((val & 0xF) << 12);
    printf("Rotate four bits: %x\n", val3);

    return 0;
}