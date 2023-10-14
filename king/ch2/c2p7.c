#include <stdio.h>

int main(void) {
    int amount = 0.0f;
    
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    int twenties = amount / 20;
    amount = amount - (20 * twenties);

    int tens = amount / 10;
    amount = amount - (10 * tens);

    int fives = amount / 5;
    amount = amount - (5 * fives);

    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n", twenties, tens, fives, amount);
    
    return 0;
}