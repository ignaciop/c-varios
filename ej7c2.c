#include <stdio.h>

int main(void) {
	int am, twentys, tens, fives, ones = 0;
	
	printf("Enter a dollar amount: ");
	scanf("%i",&am);
	twentys = am / 20;
	tens = (am % 20) / 10;
	fives = ((am % 20) % 10) / 5;
	ones = (((am % 20) % 10) % 5) / 1;
	printf("$20 bills: %i\n",twentys);
	printf("$10 bills: %i\n",tens);
	printf(" $5 bills: %i\n",fives);
	printf(" $1 bills: %i\n",ones);
	return 0;
}