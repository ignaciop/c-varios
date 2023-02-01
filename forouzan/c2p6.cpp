#include <iostream>

int main() {
    std::cout << "Enter the square side size: " << std::endl;
    double side = 0.0;
    std::cin >> side;

    double perimeter = side * 4;

    std::cout << "Perimeter: " << perimeter << std::endl;

    return 0;
}