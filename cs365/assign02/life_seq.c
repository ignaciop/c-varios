/* Conway's Game of Life - sequential version */

#include <stdio.h>
#include <stdlib.h>

#include "grid.h"
#include "life.h"

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Usage: life_seq <filename> <numgens>\n");
		
		exit(EXIT_FAILURE);
	}

	const char *filename = argv[1];
	int numgens = atoi(argv[2]);

	/* read file */
	FILE *fp = fopen(filename, "r");
	
	if (fp == NULL) {
		fprintf(stderr, "Cannot open file.\n");
		
		exit(EXIT_FAILURE);
	}
	
	Grid *grid = life_load_board(fp);
	
	fclose(fp);

	/* simulation */
	for (int i = 0; i < numgens; i++) {
		life_compute_next_gen(grid);
		
		grid_flip(grid);
	}

	/* print result */
	life_save_board(stdout, grid);
	
	grid_destroy(grid);

	return EXIT_SUCCESS;
}