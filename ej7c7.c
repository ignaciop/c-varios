#include <stdio.h>

int main(void) {
	int n1, d1, n2, d2;
	char ch;
	
	printf("Enter two fractions separated by an operand: ");
	scanf("%d/%d %c %d/%d",&n1,&d1,&ch,&n2,&d2);
	
	int r_num = 0, r_den = 0;
	
	switch (ch) {
		case '+':
			r_num = n1*d2 + n2*d1;
			r_den = d1*d2;
			break;
		case '-':
			r_num = n1*d2 - n2*d1;
			r_den = d1*d2;
			break;
		case '*':
			r_num = n1*n2;
			r_den = d1*d2;
			break;
		case '/':
			r_num = n1*d2;
			r_den = d1*n2;
			break;
	}
	
	
	int gcd;
	int m = r_num;
	int n = r_den;
	
	for(;;) {
		if (n == 0) {
			gcd = m;
			break;
		} else {
			int r = m % n;
			m = n;
			n = r;
		}
	}
	
	r_num = r_num / gcd;
	r_den = r_den / gcd;
	
	printf("Result is %d/%d\n",r_num,r_den);
	
	return 0;
}