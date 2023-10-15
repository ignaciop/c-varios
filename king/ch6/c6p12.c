#include <stdio.h>

int main(void) {
    float e = 1.0f;
    float eps = 0.0f;
    int n = 1;

    printf("Enter a small epsilon: ");
    scanf("%f", &eps);

    printf("e ~ 1 + ");

    float term = 1;

    while(term > eps) {
        term /= n;

        printf("1/%d! + ", n);

        e += term;
        n++;
    }

    printf("\b\b\b = %.5f\n", e);

    return 0;
}