#include <iostream>

int main() {
    std::cout << "Enter number of lines: ";
    int lines = 0;
    std::cin >> lines;

    for (int i = 1; i <= lines - 1; i++) {
        for (int j = 1; j <= lines - i; j++) {
            std::cout << " ";
        }

        for (int k = lines - i; k < lines; k++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    for (int i = lines; i >= 0; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    return 0;
}