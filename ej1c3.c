#include <stdio.h>

int main(void) {
	int m,d,y;
	
	printf("Enter a date: ");
	scanf("%d/%d/%d",&m,&d,&y);
	
	printf("You entered the date %.4d%.2d%.2d \n",y,m,d);
	
	return 0;
}