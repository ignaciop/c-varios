#include <stdio.h>

#define PI 3.1415
#define R 10

int main(void) {
	float v = (4.0f / 3.0f)*PI*R*R*R;
	printf("Volume of sphere with radius of %i m.: %.2f m^3\n",R,v);
	return 0;
}