#include <stdio.h>

int main(void) {
    long i, n;
    
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld", &n);

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
    }

    return 0;
}