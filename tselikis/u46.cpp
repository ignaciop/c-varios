#include <iostream>

int main() {
    std::cout << "Enter an integer between 0 and 255: ";
    int x;
    std::cin >> x;

    int y = x << 4;

    std::cout << "4-bit shift: " << y << std::endl;

    return 0;
}