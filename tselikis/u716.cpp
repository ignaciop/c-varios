#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const int ROWS = 3;
    const int COLS = 5;
    const int LL = 0;
    const int UL = 20;

    int matrix[ROWS][COLS] = {};

    // Seed
    srand(time(NULL));

    // Random number between [0, 20]
    int num = LL + (rand() % (UL - LL + 1));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}