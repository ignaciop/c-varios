#include <iostream>

int main() {
    const int INT_BITS = 8;

    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;

    std::cout << "Enter number of bytes to rotate (1, 2 or 3): ";
    int n;
    std::cin >> n;

    int num_right = (num >> n) | (num << (INT_BITS - n)); // rotate right
    int num_left = (num << n) | (num >> (INT_BITS - n)); // rotate left

    std::cout << num_right + num_left << std::endl;
    
    return 0;
}

//TODO

