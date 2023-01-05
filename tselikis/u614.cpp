#include <iostream>

int main() {
    unsigned int number = 0;
    unsigned int bit = 0;
    
    for (int i = 7; i >= 0; i--) {
        std::cout << "Enter a bit (1 or 0): ";
        std::cin >> bit;

        int pow = 1;

        for (int j = 1; j <= i; j++) {
            pow *= 2;
        }

        number += bit * pow;
    }
    
    std::cout << "Decimal number: " << number << std::endl;

    return 0;
}