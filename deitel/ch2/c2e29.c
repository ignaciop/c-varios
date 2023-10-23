#include <stdio.h>

int main(void) {
    int p = 0, q = 0, r = 0;

    printf("%s", "Enter three integers: ");
    scanf("%d %d %d", &p, &q, &r);

    printf("%s", "Increasing order: ");

    if (p <= q) {
        if (q <= r) {
            printf("%d %d %d\n", p, q, r);
        }

        if (q > r) {
            if (p <= r) {
                printf("%d %d %d\n", p, r, q);
            }

            if (p > r) {
                printf("%d %d %d\n", r, p, q);
            }
        }
    }

    if (p > q) {
        if (p <= r) {
            printf("%d %d %d\n", q, p, r);
        }

        if (p > r) {
            if (r <= q) {
                printf("%d %d %d\n", r, q, p);
            }

            if (r > q) {
                printf("%d %d %d\n", q, r, p);
            }
        }
    }

    return 0;
}