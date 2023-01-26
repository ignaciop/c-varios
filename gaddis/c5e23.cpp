#include <iostream>

int main() {
    const int MAX_ROWS = 4;

    for (int i = 1; i <= MAX_ROWS; i++) {
        for (int k = 1; k <= MAX_ROWS - i; k++) {
            std::cout << ' ';
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << '+';  
        }

        std::cout << '\n';
    }
    
    for (int i = MAX_ROWS - 1; i >= 1; i--) {
        for (int k = 1; k <= MAX_ROWS - i; k++) {
            std::cout << ' ';
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << '+';  
        }

        std::cout << '\n';
    }

    return 0;
}