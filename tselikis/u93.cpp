#include <iostream>

int main() {
    int sign = 1;
    int digit_count = 0;
    char ch;

    std::cout << "Enter number (up to 10 digits): ";

    while ((ch = std::cin.get()) != '\n' && ch != EOF) {
        if (digit_count == 0 && ch == '-') {
            sign = -sign;
            std::cout << '-';
        }

        if (ch != '-' && (ch >= '0' && ch <= '9')) {
            digit_count++;
            std::cout << ch;
        }

        if (digit_count > 10) {
            break;
        }        
    }

    if (digit_count <= 10) {
        std::cout << "\nDigit count: " << digit_count << std::endl;
    } else {
        std::cout << "Sorry, you have entered more than 10 digits :>" << std::endl;
    }

    return 0;
}