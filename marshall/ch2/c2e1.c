#include <stdio.h>

int main(void) {
    double n = 0.0, m = 0.0;

    printf("%s", "Enter two numbers: ");
    scanf("%lf %lf", &n, &m);

    printf("Sum: %.2lf\n", n + m);
    printf("Average: %.2lf\n", (n + m) / 2);
    printf("Sum of squares: %.2lf\n", n * n + m * m);

    return 0;
}