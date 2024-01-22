// Conway's Game of Life - parallel version

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "grid.h"
#include "life.h"

int main(int argc, char **argv) {
	if (argc != 5) {
		fprintf(stderr, "Usage: ./runpar <filename> <numgens> <N> <M>\n");
		
		exit(EXIT_FAILURE);
	}

	const char *filename = argv[1];
	int numgens = atoi(argv[2]);
	int N = atoi(argv[3]);  // number of rows of processes
	int M = atoi(argv[4]);  // number of columns of processes

	// TODO: computation

	return EXIT_SUCCESS;
}