#include <iostream>

int main() {
    const int DIM = 3;

    int matrix[DIM][DIM] = {};

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << "Enter element " << i << "," << j << ": ";
            std::cin >> matrix[i][j];
        }

        std::cout << "\n";
    }

    std::cout << "Before:" << std::endl;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    for (int i = 0; i < DIM; i++) {
        for (int j = i; j < DIM; j++) {
            int temp = matrix[i][j];

            matrix[i][j] = matrix[j][i];

            matrix[j][i] = temp;
        }
    }

    std::cout << "\nAfter:" << std::endl;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}