#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;

    std::cout << "Sum of bits at positions 2, 4, 6 and 8: "
                << (1 & (num >> (2 - 1))) + (1 & (num >> (4 - 1)))
                    + (1 & (num >> (6 - 1))) + (1 & (num >> (8 - 1))) << std::endl;
    
    return 0;
}