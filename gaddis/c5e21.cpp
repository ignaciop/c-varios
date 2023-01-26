#include <iostream>
#include <iomanip>

int main() {
    const int MAX_ROWS = 10;

    std::cout << "Pattern A" << std::setw(18) << "Pattern B" << std::endl;

    for (int i = 1; i <= MAX_ROWS; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << '+';  
        }

        std::cout << std::setw(2 * MAX_ROWS - i - 1);

        for (int k = 0; k <= MAX_ROWS - i; k++) {
            std::cout << '+';
        }

        std::cout << '\n';
    }

    return 0;
}