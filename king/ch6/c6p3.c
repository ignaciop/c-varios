#include <stdio.h>

int main(void) {
    int num = 0, den = 0;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &den);

    int m = num, n = den;

    while (n != 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }

    int red_num = num / m;
    int red_den = den / m;

    printf("In lowest terms: %d/%d\n", red_num, red_den);

    return 0;
}