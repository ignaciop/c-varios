#include <iostream>

int main() {
    const int DIM = 3;

    int matrix[DIM][DIM] = {};
    bool isUpper = false;
    bool isLower = false;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << "Enter element " << i << "," << j << ": ";
            std::cin >> matrix[i][j];
        }

        std::cout << "\n";
    }

    for (int i = 1; i < DIM; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] == 0) {
                isUpper = true;
            } else {
                isUpper = false;
            }
        }

        if (!isUpper) {
            break;
        }
    }

    for (int i = 0; i < DIM - 1; i++) {
        for (int j = DIM - 1; j > i; j--) {
            if (matrix[i][j] == 0) {
                isLower = true;
            } else {
                isLower = false;
            }
        }

        if (!isLower) {
            break;
        }
    }

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    if (isLower) {
        std::cout << "The matrix is lower triangular." << std::endl;
    }

    if (isUpper) {
        std::cout << "The matrix is upper triangular." << std::endl;
    }

    return 0;
}