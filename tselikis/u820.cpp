#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    const int DIM = 5;
    const int LL = 0;
    const int UL = 5;

    int matrix[DIM * DIM] = {};
    int *p = nullptr;
    int *newline = matrix + (DIM - 1);
    int *main_diagonal = matrix;
    int *secondary_diagonal = matrix + (DIM - 1);
    int num = 0;

    int sum_md = 0;
    int sum_sd = 0;

    // Seed
    srand(time(NULL));

    for (p = matrix; p <= matrix + (DIM * DIM - 1); p++) {
        // Random number between [0, 10]
        num = LL + (rand() % (UL - LL + 1));
        *p = num;

        std::cout << *p << "\t";
        
        if (p == newline) {
            std::cout << '\n';
            newline += DIM;
        }

        if (p == main_diagonal) {
            sum_md += *p;
            main_diagonal += DIM + 1;
        }

        // Last guard because I dont want to count the last element as
        // a member of the secondary diagonal
        if (p == secondary_diagonal && secondary_diagonal != matrix + (DIM * DIM - 1)) {
            sum_sd += *p;
            secondary_diagonal += DIM - 1;
        }
    }

    std::cout << "\nMain diagonal sum: " << sum_md << std::endl;
    std::cout << "\nSecondary diagonal sum: " << sum_sd << std::endl;

    if (sum_md == sum_sd) {
        std::cout << "\nThe sums of the diagonals are equal!" << std::endl;
    }

    return 0;
}