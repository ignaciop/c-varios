#include <stdio.h>

int main(void) {
    int n = 0;

    printf("Enter an integer number: ");
    scanf("%d", &n);

    printf("The reversal is: ");

    do {
        int digit = n % 10;

        printf("%d", digit);

        n /= 10;

    } while (n != 0);
    
    printf("\n");
    
    return 0;
}