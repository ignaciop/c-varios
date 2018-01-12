#include <stdio.h>

int main(void) {
	int in,m,d,y;
	float up;
	
	printf("Enter item number: ");
	scanf("%d",&in);
	printf("Enter unit price: ");
	scanf("%f",&up);
	printf("Enter purchase date (mm/dd/yy): ");
	scanf("%d/%d/%d",&m,&d,&y);
	
	printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
	printf("%d\t\t$%7.2f\t%d/%d/%d\n",in,up,m,d,y);
	
	return 0;
}