#include <stdio.h>

#define TAX 0.05f

int main(void) {
    float amount = 0.0f;
    
    printf("Enter an amount: ");
    scanf("%f", &amount);

    float amount_tax = amount + amount * TAX;

    printf("With tax added: $%.2f\n", amount_tax);

    return 0;
}