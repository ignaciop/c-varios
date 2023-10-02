#include <stdio.h>

int main(void) {
    float f1 = 0.0f;
    float f2 = 0.0f;

    printf("Enter two floating-point values: ");
    scanf("%f %f", &f1, &f2);

    printf("%f * %f = %f\n", f1, f2, f1 * f2);

    return 0;
}