#include <iostream>

int main() {
    std::cout << "Enter two numbers: ";
    double a {}, b {};
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << std::endl;

    return 0;
}