#include <iostream>

int main() {
    const int DIM = 3;

    int matrix[DIM * DIM] = {};
    int sum_cols[DIM] = {};
    int sum_rows[DIM] = {};

    int *p = nullptr;
    int *new_row = matrix + (DIM - 1);

    int *p_sum_rows = sum_rows;
    int *p_sum_cols = sum_cols;

    int sum_r = 0;

    for (p = matrix; p <= matrix + (DIM * DIM - 1); p++) {
        std::cout << "Enter integer: ";
        std::cin >> *p;
    }

    std::cout << '\n';

    // Sum of each row
    for (p = matrix; p <= matrix + (DIM * DIM - 1); p++) {
        sum_r += *p;

        if (p == new_row) {
            *p_sum_rows = sum_r;
            p_sum_rows++;
            sum_r = 0;
            new_row += DIM;
        }
    }

    // Sum of each column (fucking complicated!!)
    for (p = matrix; p <= matrix + (DIM - 1); p++) {
        int count = 0;
        int sum_c = 0;

        int *temp = p;

        while (count < DIM) {  
            sum_c += *temp;
            temp += 3;
            count++;
        }

        *p_sum_cols = sum_c;
        p_sum_cols++;        
    }

    new_row = matrix + (DIM - 1);

    // Display matrix
    for (p = matrix; p <= matrix + (DIM * DIM - 1); p++) {
        std::cout << *p << "\t";
        
        if (p == new_row) {
            std::cout << '\n';
            new_row += DIM;
        }
    }

    std::cout << '\n';

    int max_r = *p_sum_rows;
    int max_c = *p_sum_cols;

    for (p_sum_rows = sum_rows; p_sum_rows <= sum_rows + (DIM - 1); p_sum_rows++) {
        if (*p_sum_rows > max_r) {
            max_r = *p_sum_rows;
        }
    }

    for (p_sum_cols = sum_cols; p_sum_cols <= sum_cols + (DIM - 1); p_sum_cols++) {
        if (*p_sum_cols > max_c) {
            max_c = *p_sum_cols;
        }
    }

    std::cout << "Largest row sum: " << max_r << std::endl;
    std::cout << "Largest column sum: " << max_c << std::endl;

    return 0;
}