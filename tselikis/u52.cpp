#include <iostream>

int main() {
    std::cout << "Enter three integers: ";
    int i, j, k;
    std::cin >> i >> j >> k;

    if (i < j) {
        if (j < k) {
            std::cout << "The numbers are in ascending order" << std::endl;
        }
    } else {
        std::cout << "The numbers are not in ascending order" << std::endl;
    }
    
    return 0;
}