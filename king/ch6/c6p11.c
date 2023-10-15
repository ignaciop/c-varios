#include <stdio.h>

int main(void) {
    float e = 1.0f;
    int n = 0;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("e ~ 1 + ");

    for (int i = 1; i <= n; i++) {
        float fact_i = 1;
        int j = i;

        while (j > 1) {
            fact_i *= j;
            j--;
        }

        printf("1/%d! + ", i);

        e += 1/fact_i;
    }

    printf("\b\b\b = %.5f\n", e);

    return 0;
}