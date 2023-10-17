#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int counter[10] = {0};
    int digit = 0;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;

        counter[digit]++;

        n /= 10;
    }

    printf("Digit:\t\t 0  1  2  3  4  5  6  7  8  9\n");

    printf("Ocurrences:\t");

    for (int i = 0; i < 10; i++) {
        printf("%2d ", counter[i]);
    }

    printf("\n");

    return 0;
}