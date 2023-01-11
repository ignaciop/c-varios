#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const int ROWS = 3;
    const int COLS = 5;
    const int LL = 0;
    const int UL = 20;

    int matrix[ROWS][COLS] = {};
    int partial_sums[COLS] = {};

    // Seed
    srand(time(NULL));
   
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            // Random number between [0, 20]
            int num = LL + (rand() % (UL - LL + 1));

            matrix[i][j] = num;
        }
    }

    for (int j = 0; j < COLS; j++) {
        int partial_sum = 0;

        for (int i = 0; i < ROWS - 1; i++) {
            partial_sum += matrix[i][j];
        }

        partial_sums[j] = partial_sum;
    }

    int i = ROWS - 1;

    for (int j = 0; j < COLS; j++) {
        int num = 0;

        do {
            num = LL + (rand() % (UL - LL + 1));

            matrix[i][j] = num;
        } while (num + partial_sums[j] > 50);
        // Program takes too long if I compare
        // num + partial_sums[j] != 50
    }
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << matrix[i][j] << "\t";
        }

        std::cout << "\n";
    }

    return 0;
}