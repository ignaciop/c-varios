#include <iostream>

int main() {
    const int ROWS = 3;
    const int COLS = 4;

    int matrix[ROWS][COLS] = {};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << "Enter element " << i << "," << j << ": ";
            std::cin >> matrix[i][j];
        }

        std::cout << "\n";
    }

    std::cout << "Before:" << std::endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    for (int i = 0; i < ROWS; i++) {
        int max = matrix[i][0];
        int index_j = 0;

        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                index_j = j;
            }
        }

        for (int j = 0; j < index_j; j++) {
            matrix[i][j] = max;
        }
    }

    std::cout << "After:" << std::endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}