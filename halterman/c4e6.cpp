#include <iostream>

int main() {
    std::cout << "Please enter the first number: ";
    int f {};
    std::cin >> f;

    std::cout << "Please enter the second number: ";
    int s {};
    std::cin >> s;

    std::cout << f << " + " << s << " = " << f + s << std::endl;
    std::cout << f << " - " << s << " = " << f - s << std::endl;
    std::cout << f << " * " << s << " = " << f * s << std::endl;
    std::cout << f << " / " << s << " = " << f / s << std::endl;
    std::cout << f << " % " << s << " = " << f % s << std::endl;

    return 0;
}