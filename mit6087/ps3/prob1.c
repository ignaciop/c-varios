#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 25

static unsigned int results_buffer[NMAX];

void fibonacci(void) {
	/* here are the variables to set as registers */
	register unsigned int a = 0;
	register unsigned int b = 1;
	register unsigned int c;

	/* do not edit below this line */
	results_buffer[0] = a;
	results_buffer[1] = b;

	for (register int n = 2; n < NMAX; n++) {
		c = a + b;
		results_buffer[n] = c; /* store code in results buffer */
		a = b;
		b = c;
	}
}

int main(void) {
	int ntests = 10000000;
	clock_t tstart, tend;
	double favg;

	/* do profiling */
	tstart = clock();
	
	for (int n = 0; n < ntests; n++) {
		fibonacci();
	}

	tend = clock();
	/* end profiling */

	/* compute average execution time */
	favg = ((double)(tend - tstart)) / CLOCKS_PER_SEC / ntests;

	/* print avg execution time in milliseconds */
	printf("Avg. execution time: %g msec\n",favg*1000);

	return 0;
}