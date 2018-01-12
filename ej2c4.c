#include <stdio.h>

int main(void) {
	int n1;
	
	printf("Enter a three-digit number: ");
	scanf("%d",&n1);
	
	int ld = n1 / 100;
	int fg = n1 % 100;
	
	int fd = fg / 10;
	int ld2 = fg % 10;
	
	printf("The reversal is %d%d%d\n",ld2,fd,ld);
	
	return 0;
}