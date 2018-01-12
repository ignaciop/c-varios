#include <stdio.h>


int main(void) {
	float x = 0.0f;
	float fx = 0.0f;
	
	printf("x?: ");
	scanf("%f",&x);
	fx = ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6;
	printf("f(%.2f) = %.2f\n",x,fx);
	return 0;
}