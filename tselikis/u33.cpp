#include <iostream>

int main() {
    std::cout << "Enter an octal number (e.g 20): ";
    int octal = 0;
    std::cin >> std::oct >> octal;

    std::cout << "Enter an hexadecimal number (e.g 3f): ";
    int hexa = 0;
    std::cin >> std::hex >> hexa;

    std::cout << "Enter a decimal number (e.g 5): ";
    int dec = 0;
    std::cin >> dec;

    int sum = octal + hexa + dec;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}