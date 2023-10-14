#include <stdio.h>

int main(void) {
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    int max1 = 0, max2 = 0, min1 = 0, min2 = 0;
    int max = 0, min = 0;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    if (n1 >= n2) {
        max1 = n1;
        min1 = n2;
    } else {
        max1 = n2;
        min1 = n1;
    }

    if (n3 >= n4) {
        max2 = n3;
        min2 = n4;
    } else {
        max2 = n4;
        min2 = n3;
    }

    max = (max1 >= max2) ? max1 : max2;
    min = (min1 <= min2) ? min1 : min2;

    printf("Largest: %d\nSmallest: %d\n", max, min);

    return 0;
}