#include <iostream>

int main() {
    std::cout << "Enter two integer numbers: ";
    int a {}, b {};
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
    std::cout << a << " % " << b << " = " << a % b << std::endl;

    std::cout << "++" << a << " = ";
    ++a;
    std::cout << a << std::endl;

    std::cout << "--" << b << " = ";
    --b;
    std::cout << b << std::endl;

    return 0;
}