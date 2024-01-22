#include <stdio.h>

#include "life.h"

static int count_live_neighbour_cell(Grid *grid, int r, int c) {
    int count = 0;
    
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if ((i == r && j == c) || (i < 0 || j < 0) || (i >= grid->rows || j >= grid->cols)) {
                continue;
            }
            
            if (*(grid->curr_buffer + (i * grid->cols + j)) == 1) {
                count++;
            }
        }
    }
    
    return count;
}

Grid *life_load_board(FILE *fp) {
	int rows = 0, cols = 0;
	
	fscanf(fp, "%d %d", &rows, &cols);
	
	Grid *grid = grid_alloc(rows, cols);
	
	for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
        	int tmp_val = 0;
        	
        	fscanf(fp, "%d", &tmp_val);
        	
        	grid_set_next(grid, i, j, tmp_val);
        }
    }
	
	grid_flip(grid);
	
	return grid;
}

void life_compute_next_gen(Grid *grid) {
	for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            int neighbour_live_cell = count_live_neighbour_cell(grid, i, j);
            
            uint8_t curr_value = grid_get_current(grid, i, j);
            
            if (curr_value == 1 && (neighbour_live_cell == 2 || neighbour_live_cell == 3)) {
                grid_set_next(grid, i, j, 1);
            } else if (curr_value == 0 && neighbour_live_cell == 3) {
                grid_set_next(grid, i, j, 1);
            } else {
                grid_set_next(grid, i, j, 0);
            }
        }
    }
}

void life_save_board(FILE *fp, Grid *grid) {
	fprintf(fp, "%d %d\n", grid->rows, grid->cols);
	
	for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
        	int tmp_val = grid_get_current(grid, i, j);
        	
        	fprintf(fp, (j != grid->cols - 1) ? "%d " : "%d\n", tmp_val);
        }
    }
}