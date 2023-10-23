#include <stdio.h>

int main(void) {
    int n = 0, m = 0;

    printf("%s", "Enter two integers: ");
    scanf("%d %d", &n, &m);

    if (n < m) {
        printf("%d is larger.\n", m);
    }

    if (n > m) {
        printf("%d is larger.\n", n);
    }

    if (n == m) {
        printf("%s\n", "These numbers are equal.");
    }

    return 0;
}