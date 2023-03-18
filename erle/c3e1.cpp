#include <iostream>

int main() {
    std::cout << "Enter three angles: ";
    double a {}, b {}, c{};
    std::cin >> a >> b >> c;

    if (a + b + c == 180.0) {
        std::cout << "The angles make a triangle." << std::endl;
    } else {
        std::cout << "The angles do not make a triangle." << std::endl;
    }

    return 0;
}