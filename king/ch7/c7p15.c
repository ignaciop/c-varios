#include <stdio.h>

int main() {
    int n = 0;
    long double fact_n = 1.0;

    printf("Enter a positive number: ");
    scanf("%d", &n);

    int j = n;

    while (j > 1) {
        fact_n *= j;
        j--;
    }

    printf("Factorial of %d: %.0Lf\n", n, fact_n);

    return 0;
}