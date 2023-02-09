#include <iostream>
#include <string>

std::string decimalToHex(int decimalNumber);
std::string hexFormat(int n);

int main() {
    std::cout << "Enter a positive integer: ";
    int decimalNumber;
    std::cin >> decimalNumber;

    std::string hexString = decimalToHex(decimalNumber);

    std::cout << "The hexadecimal representation of " << decimalNumber << " is " << hexString << std::endl;

    return 0;
}

std::string decimalToHex(int decimalNumber) {
    std::string hexString = "";
    int hexDigit;

    while (decimalNumber != 0) {
        hexDigit = decimalNumber % 16;
        decimalNumber /= 16;
        hexString = hexFormat(hexDigit) + hexString;
    }

    return hexString;
}

std::string hexFormat(int n) {
    std::string res {};

    switch (n) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            res = std::to_string(n);
            break;
        case 10:
            res = "A";
            break;
        case 11:
            res = "B";
            break;
        case 12:
            res = "C";
            break;
        case 13:
            res = "D";
            break;
        case 14:
            res = "E";
            break;
        case 15:
            res = "F";
            break;
    }

    return res;
}