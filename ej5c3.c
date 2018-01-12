#include <stdio.h>

int main(void) {
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
	
	printf("Enter the numbers from 1 to 16 in any order:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,&n10,&n11,&n12,&n13,&n14,&n15,&n16);
	
	printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n",n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16);

	int r1 = n1 + n2 + n3 + n4;
	int r2 = n5 + n6 + n7 + n8;
	int r3 = n9 + n10 + n11 + n12;
	int r4 = n13 + n14 + n15 + n16;
	
	int c1 = n1 + n5 + n9 + n13;
	int c2 = n2 + n6 + n10 + n14;
	int c3 = n3 + n7 + n11 + n15;
	int c4 = n4 + n8 + n12 + n16;
	
	int d1 = n1 + n6 + n11 + n16;
	int d2 = n4 + n7 + n10 + n13;
	
	printf("Row sums: %d %d %d %d\n", r1, r2, r3, r4);
	printf("Column sums: %d %d %d %d\n", c1, c2, c3, c4);
	printf("Diagonal sums: %d %d\n", d1, d2);
	
	return 0;
}