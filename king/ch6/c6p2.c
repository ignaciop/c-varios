#include <stdio.h>

int main(void) {
    int n1 = 0, n2 = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    int m = n1, n = n2;

    while (n != 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}