#include <stdio.h>

int main(void) {
    int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0, i10 = 0;

    printf("Enter ten integer values: ");
    scanf("%d %d %d %d %d %d %d %d %d %d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10);

    printf("Sum: %d\n", i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10);

    return 0;
}