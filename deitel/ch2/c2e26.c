#include <stdio.h>

int main(void) {
    int n;

    printf("%s", "Enter a five-digit integer: ");
    scanf("%d", &n);

    int first_digit = n / 10000;
    int rem = n % 10000;

    int second_digit = rem / 1000;
    rem %= 1000;

    int third_digit = rem / 100;
    rem %= 100;

    int fourth_digit = rem / 10;
    int fifth_digit = rem % 10;

    printf("%d %d %d %d %d\n", first_digit, second_digit, third_digit, fourth_digit, fifth_digit);
    
    return 0;
}