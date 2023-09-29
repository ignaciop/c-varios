#include <stdio.h>

int main(void) {
    int a = 0, b = 0;

    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter another number: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Error 2, %d == 0\n", b);
    } else if (a < b) {
        printf("Error, %d < %d\n", a, b);
    } else {
        printf("%d and %f\n", a / b, (a * 1.0) / (b * 1.0));
    }

    return 0;
}