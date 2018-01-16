#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int s = i*i;
		if  (s % 2 == 0) {
			printf("%d\n",s);
		}
	}

    return 0;
}