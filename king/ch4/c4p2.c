#include <stdio.h>

int main(void) {
    int n;

    printf("Enter a three-digit number: ");
    scanf("%d", &n);

    int first_digit = n / 100;
    int second_digit = (n % 100) / 10;
    int third_digit = (n % 100) % 10;

    printf("The reversal is: %d%d%d\n", third_digit, second_digit, first_digit);
    
    return 0;
}