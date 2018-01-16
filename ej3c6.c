#include <stdio.h>

int main(void)
{
    int m, n, num, den, gcd;

	printf("Enter a fraction: ");
	scanf("%d/%d",&num, &den);
	
	m = num;
	n = den;
	
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
	
	num = num / gcd;
	den = den / gcd;

    printf("In lowest terms: %d/%d\n", num, den);

    return 0;
}