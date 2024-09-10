/* array_traversal_row.m
 * Sums a two dimensional array of ones using row-major order
 * Ignacio Poggi; 20240901
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int N = 1773;
    
    /* Allocate memory for the 2D array using pointers to pointers */
    int **matrix = (int **)malloc(N * sizeof(int *));
    
    if (matrix == NULL) {
        perror("Could not allocate memory for matrix.");
        
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < N; i++) {
        matrix[i] = (int *)malloc(N * sizeof(int));
        
        if (matrix[i] == NULL) {
            perror("Could not allocate memory for matrix.");
        
            exit(EXIT_FAILURE);
        }
    }
    
    int sum = 0;

    /* Initialize all elements to 1 */
    /* Sum the elements by iterating over rows then columns */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 1;
            sum += matrix[i][j];
        }
    }

    /* Print the sum */
    printf("Sum of all elements (row traversal): %d\n", sum);

    /* Free the allocated memory */
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }
    
    free(matrix);
    matrix = NULL;

    return EXIT_SUCCESS;
}