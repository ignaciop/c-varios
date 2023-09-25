#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    int first_digit = n / 10;
    int second_digit = n % 10;

    printf("The reversal is: %d%d\n", second_digit, first_digit);
    
    return 0;
}