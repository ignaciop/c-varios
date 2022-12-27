#include <iostream>

int main() {
    std::cout << "Enter two integers: ";
    int x, y;
    std::cin >> x >> y;

    std::cout << "Before swap: " << "x = " << x << ", y = " << y << std::endl;

    y = x^y;
    x = x^y;
    y = x^y;

    std::cout << "After swap: " << "x = " << x << ", y = " << y << std::endl;

    return 0;
}