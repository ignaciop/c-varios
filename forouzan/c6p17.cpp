#include <iostream>

int pascal(int row, int col);

int main () {
    for (int n = 1; n <= 10; n++) {
        std::cout << "n = " << n << "\t";

        for (int k = 1; k <= n; k++) {
            std::cout << pascal(n, k) << " ";
        }

        std::cout << std::endl;
    }
    
    return 0;
}

int pascal(int row, int col) {
    if (col == 1 || row == col) {
        return 1;
    } else {
        return (pascal(row - 1, col - 1) + pascal(row - 1, col));
    }
}