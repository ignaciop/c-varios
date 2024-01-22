#include <stdio.h>
#include <stdlib.h>

#include "grid.h"

Grid *grid_alloc(int rows, int cols) {
	Grid *new_grid = (Grid *)malloc(sizeof(Grid));
	
	if (new_grid == NULL) {
		fprintf(stderr, "Cannot allocate memory for new grid.\n");
		
		exit(EXIT_FAILURE);
	}
	
	new_grid->rows = rows;
	new_grid->cols = cols;
	
	new_grid->curr_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (new_grid->rows * new_grid->cols));
	
	if (new_grid->curr_buffer == NULL) {
		fprintf(stderr, "Cannot allocate memory for current grid buffer.\n");
		
		exit(EXIT_FAILURE);
	}
	
	new_grid->next_buffer = (uint8_t *)malloc(sizeof(uint8_t) * (new_grid->rows * new_grid->cols));
	
	if (new_grid->next_buffer == NULL) {
		fprintf(stderr, "Cannot allocate memory for next grid buffer.\n");
		
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < new_grid->rows; i++) {
		for (int j = 0; j < new_grid->cols; j++) {
			*(new_grid->curr_buffer + (i * new_grid->cols + j)) = 0;
			*(new_grid->next_buffer + (i * new_grid->cols + j)) = 0;
		}
	}
	
	return new_grid;
}

void grid_destroy(Grid *grid) {
	free(grid->curr_buffer);
	grid->curr_buffer = NULL;
	
	free(grid->next_buffer);
	grid->next_buffer = NULL;
	
	free(grid);
	grid = NULL;
}

void grid_flip(Grid *grid) {
	uint8_t *tmp_buffer = grid->curr_buffer;
	
	grid->curr_buffer = grid->next_buffer;
	
	grid->next_buffer = tmp_buffer;
}

uint8_t grid_get_current(Grid *grid, int row, int col) {
	uint8_t value = *(grid->curr_buffer + (row * grid->cols + col));
	
	return value;
}

void grid_set_next(Grid *grid, int row, int col, uint8_t val) {
	*(grid->next_buffer + (row * grid->cols + col)) = val;
}