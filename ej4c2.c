#include <stdio.h>


int main(void) {
	float r = 0.0f;
	float total = 0.0f;
	
	printf("Enter an amount: ");
	scanf("%f",&r);
	total = r + r * 5.0f / 100.0f;
	printf("                 ---------\n");
	printf("With tax added: $%.2f\n",total);
	return 0;
}