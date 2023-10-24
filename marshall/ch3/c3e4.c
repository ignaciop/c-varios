#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0, m = 0;

    printf("%s", "Enter the first integer: ");

    if (scanf("%d", &n) != 1) {
        printf("%s\n", "Error: Invalid input for the first integer");

        exit(0);
    }

    printf("%s", "Enter the second integer: ");

    if (scanf("%d", &m) != 1) {
        printf("%s\n", "Error: Invalid input for the second integer");

        exit(0);
    }

    if (n < m) {
        printf("%s\n", "up");
    } else if (n > m) {
        printf("%s\n", "down");
    } else {
        printf("%s\n", "equal");
    }

    return 0;
}