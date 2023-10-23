#include <stdio.h>

int main(void) {
    int n = 0, m = 0;

    printf("%s", "Enter two integers: ");
    scanf("%d %d", &n, &m);

    if (m % n == 0) {
        printf("%d is a multiple of %d\n", n, m);
    }

    if (m % n != 0) {
        printf("%d is not a multiple of %d\n", n, m);
    }
    
    return 0;
}