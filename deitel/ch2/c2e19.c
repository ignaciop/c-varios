#include <stdio.h>

int main(void) {
    int p = 0, q = 0, r = 0;
    int min = 0, max = 0;

    printf("%s", "Enter three different integers: ");
    scanf("%d %d %d", &p, &q, &r);

    if (p <= q && p <= r) {
        min = p;
    }

    if (q <= p && q <= r) {
        min = q;
    }

    if (r <= p && r <= q) {
        min = r;
    }

    if (p >= q && p >= r) {
        max = p;
    }

    if (q >= p && q >= r) {
        max = q;
    }

    if (r >= p && r >= q) {
        max = r;
    }

    printf("Sum is %d\n", p + q + r);
    printf("Average is %d\n", (p + q + r) / 3);
    printf("Product is %d\n", p * q * r);
    printf("Smallest is %d\n", min);
    printf("Largest is %d\n", max);

    return 0;
}