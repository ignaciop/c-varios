#include <stdio.h>

int x = 2;

int main(void) {
    extern int x;
    
    printf("x = %d\n", x);

    {
        int x = 3;

        printf("x = %d\n", x);
    }
    
    return 0;
}