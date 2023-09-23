#include <stdio.h>

int main(void) {
    float loan = 0.0f;
    float interest_rate = 0.0f;
    float monthly_payment = 0.0f;
    
    printf("Enter amount of loan: ");
    scanf("%f", &loan);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest_rate = (interest_rate / 100.0f) / 12;

    float first_balance = loan - monthly_payment + (loan * monthly_interest_rate);
    float second_balance = first_balance - monthly_payment + (first_balance * monthly_interest_rate); 
    float third_balance = second_balance - monthly_payment + (second_balance * monthly_interest_rate); 

    printf("\nBalance remaining after first payment: $%.2f\n", first_balance);
    printf("Balance remaining after second payment: $%.2f\n", second_balance);
    printf("Balance remaining after third payment: $%.2f\n", third_balance);

    return 0;
}