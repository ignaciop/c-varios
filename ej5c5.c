#include <stdio.h>

int main(void) {
	float income;
	float tax_due;
	
	printf("Enter amount of taxable income: ");
	scanf("%f", &income);
	
	if (income < 750.00f) {
		tax_due = income / 100.00f;
	} else if (income >= 750.00f && income < 2250.00f) {
		tax_due = 7.50f + 2 * 750.00f / 100.00f;
	} else if (income >= 2250.00f && income < 3750.00f) {
		tax_due = 37.50f + 3 * 2250.00f / 100.00f;
	} else if (income >= 3750.00f && income < 5250.00f) {
		tax_due = 82.50f + 4 * 3750.00f / 100.00f;
	} else if (income >= 5250.00f && income < 7000.00f) {
		tax_due = 142.50f + 5 * 5250.00f / 100.00f;
	} else {
		tax_due = 230.00f + 6 * 7000.00f / 100.00f;
	}
	
	printf("Tax due: $ %.2f\n", tax_due);
	
	return 0;
}