#include <stdio.h>

int main(void) {
    unsigned char topright = 187;
    unsigned char bottomright = 188;
    unsigned char topleft = 201; 
    unsigned char bottomleft = 200;

    printf("%c%c\n%c%c\n", topleft, topright, bottomleft, bottomright); 

    return 0;
}