#include <stdio.h>

int main(void) {
	int n;
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d",&n);
	
	int r5 = n % 8;
	n = n / 8;
	
	int r4 = n % 8;
	n = n / 8;
	
	int r3 = n % 8;
	n = n / 8;
	
	int r2 = n % 8;
	n = n / 8;
	
	int r1 = n % 8;
	
	printf("In octal, your number is: %d%d%d%d%d\n",r1,r2,r3,r4,r5);
	
	return 0;
}