#include <stdio.h>

int main(void) {
    for (int i = 100; i <= 200; i += 5) {
        printf("%d ", i);
    }

    printf("\b\n");

    return 0;
}