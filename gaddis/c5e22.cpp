#include <iostream>

int main() {
    const int MAX_ROWS = 7;

    for (int i = 1; i <= MAX_ROWS; i += 2) {
        for (int j = 1; j <= i; j++) {
            std::cout << '+';  
        }

        std::cout << '\n';
    }
    
    for (int i = 1; i < MAX_ROWS; i += 2) {
        for (int j = 1; j < MAX_ROWS - i; j++) {
            std::cout << '+';  
        }

        std::cout << '\n';
    }

    return 0;
}