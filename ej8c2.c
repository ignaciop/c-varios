#include <stdio.h>

int main(void) {
	float am = 0.0f, int_rate = 0.0f, mnt_paym = 0.0f;
	
	printf("Enter amount of loan: ");
	scanf("%f",&am);	
	printf("Enter interest rate: ");
	scanf("%f",&int_rate);	
	printf("Enter monthly payment: ");
	scanf("%f",&mnt_paym);
	
	float mnt_rate = (int_rate / 100) /12;
	
	float first = am - mnt_paym + am * mnt_rate;
	float second = first - mnt_paym + first * mnt_rate;
	float third = second - mnt_paym + second * mnt_rate;
	
	printf("Balance remaining after first payment: $%.2f\n", first);
	printf("Balance remaining after second payment: $%.2f\n", second);	
	printf("Balance remaining after third payment: $%.2f\n", third);	
		
	return 0;
}