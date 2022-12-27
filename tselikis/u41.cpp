#include <iostream>

int main() {
    std::cout << "Enter two integers: ";
    int i, j;
    std::cin >> i >> j;

    std::cout << "Smaller number: " << (i <= j)*i + (i > j)*j << std::endl;

    return 0;
}