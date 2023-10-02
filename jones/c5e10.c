#include <stdio.h>

float average5(float f1, float f2, float f3, float f4, float f5);

int main(void) {
    float f1 = 0.0f, f2 = 0.0f, f3 = 0.0f, f4 = 0.0f, f5 = 0.0f, avg = 0.0f;

    puts("Enter five float numbers: ");
    scanf("%f %f %f %f %f", &f1, &f2, &f3, &f4, &f5);

    avg = average5(f1, f2, f3, f4, f5);

    printf("\nAverage: %f\n", avg);

    return 0;
}

float average5(float f1, float f2, float f3, float f4, float f5) {
    return (f1 + f2 + f3 + f4 + f5) / 5;
}