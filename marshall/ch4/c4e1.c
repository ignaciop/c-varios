#include <stdio.h>

int main(void) {
    double x = 0.0;
    double max = 0.0, min = 0.0;
    double sum = 0.0;

    int i = 1;

    do {
        printf("Enter number %d: ", i);
        scanf("%lf", &x);

        if (i == 1) {
            max = min = x;
        }

        if (x < min) {
            min = x;
        }

        if (x > max) {
            max = x;
        }

        sum += x;
        i++;
    } while (i <= 10);

    printf("Average: %.2lf\n", sum / i);
    printf("Maximum: %.2lf\n", max);
    printf("Minimum: %.2lf\n", min);

    return 0;
}