#include <stdio.h>
#include <math.h>

int main() {
    double x = 0.0;
    double y = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    while (fabs((y + x / y) / 2 - y) > 0.00001 * y) {
        y = (y + x / y) / 2;
    }

    printf("Square root: %.5f\n", y);

    return 0;
}