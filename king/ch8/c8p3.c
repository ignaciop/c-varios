#include <stdbool.h>
#include <stdio.h>

int main(void) {
    long n = 1;

    while (n > 0) {
        int counter[10] = {0};
        int digit = 0;

        printf("Enter a number: ");
        scanf("%ld", &n);

        int j = n;

        while (j > 0) {
            digit = j % 10;

            counter[digit]++;

            j /= 10;
        }

        if (n > 0) {
            printf("Digit:\t\t 0  1  2  3  4  5  6  7  8  9\n");

            printf("Ocurrences:\t");

            for (int i = 0; i < 10; i++) {
                printf("%2d ", counter[i]);
            }
        }

        printf("\n");
    }

    return 0;
}