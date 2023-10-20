#include <stdio.h>

int main(void) {
    float base = 0.0f, height = 0.0f, area = 0.0f;

    printf("Enter base and height of a right triangle: ");
    scanf("%f %f", &base, &height);

    area = 0.5f * base * height;

    printf("The area of the right triangle is: %g\n", area);

    return 0;
}