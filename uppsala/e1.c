#include <stdio.h>

int main(void) {
    float f1 = 1.0f;
    float f2 = 3.0f;
    int i1 = 10;
    int i2 = 3;

    printf("One half is 50%%\n");
    printf("The difference between %d and %d is %d\n", i1, i2, i1 - i2);
    printf("%f / %f is %f\n", f1, f2, f1 / f2);

    return 0;
}