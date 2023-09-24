#include <stdio.h>

int main(void) {
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16;
    int r1_sum, r2_sum, r3_sum, r4_sum;
    int c1_sum, c2_sum, c3_sum, c4_sum;
    int d1_sum, d2_sum;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &i12, &i13, &i14, &i15, &i16);

    printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n", i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16);

    r1_sum = i1 + i2 + i3 + i4;
    r2_sum = i5 + i6 + i7 + i8;
    r3_sum = i9 + i10 + i11 + i12;
    r4_sum = i13 + i14 + i15 + i16;

    c1_sum = i1 + i5 + i9 + i13;
    c2_sum = i2 + i6 + i10 + i14;
    c3_sum = i3 + i7 + i11 + i15;
    c4_sum = i4 + i8 + i12 + i16;

    d1_sum = i1 + i6 + i11 + i16;
    d2_sum = i4 + i7 + i10 + i13;

    printf("Row sums: %d %d %d %d\n", r1_sum, r2_sum, r3_sum, r4_sum);
    printf("Column sums: %d %d %d %d\n", c1_sum, c2_sum, c3_sum, c4_sum);
    printf("Diagonal sums: %d %d\n", d1_sum, d2_sum);

    return 0;
}