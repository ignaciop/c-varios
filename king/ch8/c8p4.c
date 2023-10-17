#include <stdio.h>

#define ARR_SIZE (int)(sizeof(a) / sizeof(a[0]))

int main(void) {
    int a[10] = {0};

    printf("Enter %d numbers: ", ARR_SIZE);

    for (int i = 0; i < ARR_SIZE; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");

    for (int i = ARR_SIZE - 1; i >= 0; i--) {
        printf(" %d", a[i]);
    }

    printf("\n");

    return 0;
}