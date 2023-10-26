#include <stdio.h>

int main(void) {
    double x = 0.0;
    double sum = 0.0;

    while (1) {
        printf("%s", "Enter numbers (enter -999 to stop): ");
        scanf("%lf", &x);

        if (x == -999) {
            break;
        }

        sum += x;
    }

    printf("Sum: %.2lf\n", sum);

    return 0;
}