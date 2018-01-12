#include <stdio.h>

int main(void) {
	int n1;
	
	printf("Enter a two-digit number: ");
	scanf("%d",&n1);
	
	int fd = n1 / 10;
	int ld = n1 % 10;
	
	printf("The reversal is %d%d\n",ld,fd);
	
	return 0;
}