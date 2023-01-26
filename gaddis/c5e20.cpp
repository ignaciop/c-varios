#include <iostream>

int main() {
    int n1 = 2;
    int n2 = 2;

    do {
        std::cout << "Enter first integer between 2 and 10: ";
        std::cin >> n1;
    } while (n1 < 2 || n1 > 10);

    do {
        std::cout << "Enter second integer between 2 and 10: ";
        std::cin >> n2;
    } while (n2 < 2 || n2 > 10);

    int length = n1;
    int width = n1;

    if (n1 < n2) {
        length = n2;
    } else {
        width = n2;
    }

    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= length; j++) {
            std::cout << "X";

            if (j == length) {
                std::cout << '\n';
            }
        }
    }

    return 0;
}