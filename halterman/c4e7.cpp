#include <iostream>

int main() {
    std::cout << "Please enter the first number: ";
    double f {};
    std::cin >> f;

    std::cout << "Please enter the second number: ";
    double s {};
    std::cin >> s;

    std::cout << f << " + " << s << " = " << f + s << std::endl;
    std::cout << f << " - " << s << " = " << f - s << std::endl;
    std::cout << f << " * " << s << " = " << f * s << std::endl;
    std::cout << f << " / " << s << " = " << f / s << std::endl;

    return 0;
}