#include <stdio.h>

int main(void) {
    int n = 0, m = 0;

    printf("%s", "Enter two integers: ");
    scanf("%d %d", &n, &m);

    printf("%d + %d = %d\n", n, m, n + m);
    printf("%d * %d = %d\n", n, m, n * m);
    printf("%d - %d = %d\n", n, m, n - m);
    printf("%d / %d = %d\n", n, m, n / m);
    printf("%d %% %d = %d\n", n, m, n % m);

    return 0;
}