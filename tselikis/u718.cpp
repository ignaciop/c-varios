#include <iostream>

int main() {
    const int ROWS = 3;
    const int COLS = 5;

    int matrix[ROWS][COLS] = {};
    int not_repeated[COLS] = {}; 
   
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << "Enter integer " << i << "," << j << ": ";
            std::cin >> matrix[i][j];
        }
        
        std::cout << "\n";
    }

    for (int j = 0; j < COLS; j++) {
        // Temporary column vector to store j-column
        int temp_column[ROWS] = {};

        // Store elements of current j-column in temp vector
        for (int i = 0; i < ROWS; i++) {
            temp_column[i] = matrix[i][j];
        }

        int total_count = 0;

        for (int i = 0; i < ROWS; i++) {
            int count = 0;

            // Compare each element of the matrix with
            // each element of temporary vector.
            for (int k = 0; k < ROWS; k++) {
                if (matrix[i][j] == temp_column[k]) {
                    count++;
                }
            }

            // Add count to the total amount.
            total_count += count;          
        }

        // If total amount is equal to the number of ROWS,
        // it means each element has appeared once
        if (total_count == ROWS) {
            not_repeated[j] = 1;
        }
    }

    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            if (not_repeated[j]) {
                std::cout << matrix[i][j] << " ";
            }
        }

        if (not_repeated[j]) {
            std::cout << "\n";
        }
    }

    return 0;
}