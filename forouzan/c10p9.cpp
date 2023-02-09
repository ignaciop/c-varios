#include <iostream>
#include <string>

std::string decimalToOctal(int decimalNumber);

int main() {
    std::cout << "Enter a positive integer: ";
    int decimalNumber;
    std::cin >> decimalNumber;

    std::string octalString = decimalToOctal(decimalNumber);

    std::cout << "The octal representation of " << decimalNumber << " is " << octalString << std::endl;

    return 0;
}

std::string decimalToOctal(int decimalNumber) {
    std::string octalString = "";
    int octalDigit;

    while (decimalNumber != 0) {
        octalDigit = decimalNumber % 8;
        decimalNumber /= 8;
        octalString = std::to_string(octalDigit) + octalString;
    }

    return octalString;
}