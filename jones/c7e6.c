#include <stdio.h>

#define ARRAY_COUNT 6

int main(void) {
    int number = 1;
    int count = 0;
    int even_arrays[ARRAY_COUNT] = {0};

    while (number != 99 && count < ARRAY_COUNT) {
        printf("Please enter an integer value (99 to exit): ");
        scanf("%d", &number);

        if (number % 2 == 0) {
            even_arrays[count] = number;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d\t", even_arrays[i]);
    }
    
    printf("\n");

    return 0;
}