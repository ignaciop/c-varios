#include <iostream>

int main() {
    const int INT_BITS = 32;

    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;

    std::cout << "Enter number of bytes to rotate (1, 2 or 3): ";
    int n;
    std::cin >> n;

    int num2 = (num >> n) | (num << (INT_BITS - n));

    std::cout << num2 << std::endl;
    
    return 0;
}


