#include <iostream>

int main() {
    const int DIM = 5;
    int x = 1;

    int matrix[DIM][DIM] = {};
    int matrix_copy[DIM][DIM] = {};
   
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << "Enter integer " << i << "," << j << ": ";
            std::cin >> matrix[i][j];
        }
        
        std::cout << "\n";
    }

    do {
        std::cout << "Enter an integer in the [1,5] range: ";
        std::cin >> x;
    } while (x < 1 || x > 5);

    for (int i = 0; i < DIM; i++) {
        if (i != x - 1) {
            for (int j = 0; j < DIM; j++) {
                if (j != x - 1) {
                    matrix_copy[i][j] = matrix[i][j];
                }
            }
        }
        
        std::cout << "\n";
    }

    std::cout << "Before" << std::endl;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << matrix[i][j] << " ";
        }
        
        std::cout << "\n";
    }

    std::cout << "\nAfter" << std::endl;
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << matrix_copy[i][j] << " ";
        }
        
        std::cout << "\n";
    }

    return 0;
}