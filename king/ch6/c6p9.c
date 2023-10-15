#include <stdio.h>

int main(void) {
    int payments = 0;
    float loan = 0.0f;
    float interest_rate = 0.0f;
    float monthly_payment = 0.0f;
    float balance = 0.0f;

    printf("Enter number of payments: ");
    scanf("%d", &payments);
    
    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest_rate = (interest_rate / 100.0f) / 12;

    for (int i = 1; i <= payments; i++) {
        balance = loan - monthly_payment + (loan * monthly_interest_rate);

        printf("\nBalance remaining after %dº payment: $%.2f\n", i, balance);

        loan = balance;
    }

    return 0;
}