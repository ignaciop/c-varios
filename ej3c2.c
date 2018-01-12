#include <stdio.h>

#define PI 3.1415

int main(void) {
	float r = 0.0f;
	printf("Radius in meters?: ");
	scanf("%f",&r);
	float v = (4.0f / 3.0f)*PI*r*r*r;
	printf("Volume of sphere with radius of %.2f m.: %.2f m^3\n",r,v);
	return 0;
}