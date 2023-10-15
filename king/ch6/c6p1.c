#include <stdio.h>

int main(void) {
    float n = 0.0f;
    float max = n;

    do {
        printf("Enter a number: ");
        scanf("%f", &n);

        if (n > max) {
            max = n;
        }
    } while (n > 0.0f);

    if (max > 0) {
        printf("The largest number entered was %.2f\n", max);
    }

    return 0;
}