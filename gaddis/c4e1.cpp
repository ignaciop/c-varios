#include <iostream>

int main() {
    std::cout << "Enter two integers: ";
    int a, b = 0;
    std::cin >> a >> b;

    std::cout << "The larger number is " << ((a > b) ? a : b) << std::endl;

    return 0;
}