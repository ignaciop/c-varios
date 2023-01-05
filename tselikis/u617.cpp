#include <iostream>

int main() {
    std::cout << "Enter number of lines: ";
    int lines = 0;
    std::cin >> lines;

    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    return 0;
}

