#include <stdio.h>

int main(void) {
	double i, n, sum;
	
	printf("Enter n: ");
	scanf("%lf", &n);
	
	sum = 0.0;
	
	for (i = 1; i <= n; i++) {
		sum += i;
	}
	
	printf("Sum: %.2lf\n",sum);
	
	return 0;
}