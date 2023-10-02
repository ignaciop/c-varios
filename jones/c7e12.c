#include <stdio.h>

#define ARRAY_COUNT 10

int main(void) {
    int number = 1;
    int count = 0;
    int numbers[ARRAY_COUNT] = {0};

    while (number != 0 && count < ARRAY_COUNT) {
        printf("Please enter up to %d integer values (0 to exit): ", ARRAY_COUNT);
        scanf("%d", &number);

        numbers[count] = number;
        count++;
    }

    int min = numbers[0];
    int max = min;

    for (int i = 0; i < count; i++) {
        if (numbers[i] >= max) {
            max = numbers[i];
        }

        if (numbers[i] <= min) {
            min = numbers[i];
        }
    }

    printf("Largest number: %d\nSmallest number: %d\n", max, min);

    return 0;
}