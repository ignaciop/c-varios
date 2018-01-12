#include <stdio.h>


int main(void) {
	float x = 0.0f;
	float fx = 0.0f;
	
	printf("x?: ");
	scanf("%f",&x);
	fx = 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6;
	printf("f(%.2f) = %.2f\n",x,fx);
	return 0;
}