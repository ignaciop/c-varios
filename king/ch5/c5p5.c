#include <stdio.h>

int main(void) {
    float income = 0.0f;
    float tax = 0.0f;
    float amount_over = 0.0f;
    float base_income = 0.0f;
    float base_tax = 0.0f;
    float percentage = 0.0f;

    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);

    if (income < 750.0f) {
        percentage = 0.01f;
    } else if (income >= 750.0f && income <= 2250.0f) {
        base_income = 750.0f;
        base_tax = 7.50f;
        percentage = 0.02f;
    } else if (income > 2250.0f && income <= 3750.0f) {
        base_income = 2250.0f;
        base_tax = 37.50f;
        percentage = 0.03f;
    } else if (income > 3750.0f && income <= 5250.0f) {
        base_income = 3750.0f;
        base_tax = 82.50f;
        percentage = 0.04f;
    } else if (income > 5250.0f && income <= 7000.0f) {
        base_income = 5250.0f;
        base_tax = 142.50f;
        percentage = 0.05f;
    } else {
        base_income = 7000.0f;
        base_tax = 230.0f;
        percentage = 0.06f;
    }

    amount_over = income - base_income;
    tax = base_tax + amount_over * percentage;

    printf("Tax due: $ %.2f\n", tax);
    
    return 0;
}