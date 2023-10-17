#include <stdio.h>

#define ROWS 5
#define COLS 5

int main(void) {
    int matrix[ROWS][COLS] = {{0}};
    
    for (int i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i + 1);

        for (int j = 0; j < COLS; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }

    printf("\nRow totals: ");

    for (int i = 0; i < ROWS; i++) {
        int total_row = 0;

        for (int j = 0; j < COLS; j++) {
            total_row += matrix[i][j];            
        }

        printf("%d ", total_row);
    }


    printf("\nColumn totals: ");

    for (int j = 0; j < COLS; j++) {
        int total_column = 0;

        for (int i = 0; i < ROWS; i++) {
            total_column += matrix[i][j];            
        }

        printf("%d ", total_column);
    }

    printf("\n");

    return 0;
}