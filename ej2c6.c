#include <stdio.h>

int main(void)
{
    int m, n, gcd;

	printf("Enter two integers: ");
	scanf("%d %d",&m, &n);
	
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

    printf("Greatest common divisor: %d\n", gcd);

    return 0;
}