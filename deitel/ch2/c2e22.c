#include <stdio.h>

int main(void) {
    int n = 0;

    printf("%s", "Enter an integer: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("%d is even\n", n);
    }

    if (n % 2 != 0) {
        printf("%d is odd\n", n);
    }
    
    return 0;
}