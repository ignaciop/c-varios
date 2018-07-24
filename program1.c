#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	double r, s;
	r = atof(argv[1]);
	s = sin(r);
	printf("Hello, World! sin(%g) = %g\n", r, s);
	
	return 0;
}