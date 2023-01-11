#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const int DIM = 5;
    const int LL = 1000;
    const int UL = 2000;

    int matrix[DIM][DIM] = {};

    // Seed
    srand(time(NULL));

    for (int i = 0; i < DIM; i++) {
        // Random number between [1000, 2000]
        int num = LL + (rand() % (UL - LL + 1));

        matrix[i][i] = num;

        // Items below diagonal
        for (int j = 0; j < i; j++) {
            if (i != j) {
                do {
                    num = LL + (rand() % (UL - LL + 1));

                    matrix[i][j] = num;
                } while (matrix[i][j] > matrix[i][i]);
            }
        }

        // Items above diagonal
        for (int j = i + 1; j < DIM; j++) {
            if (i != j) {
                do {
                    num = LL + (rand() % (UL - LL + 1));

                    matrix[i][j] = num;
                } while (matrix[i][j] < matrix[i][i]);
            }
        }
    }

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}