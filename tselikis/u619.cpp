#include <iostream>

int main() {
    std::cout << "Enter number of rows: ";
    int rows = 0;
    std::cin >> rows;

    std::cout << "Enter number of columns: ";
    int columns = 0;
    std::cin >> columns;

    for (int i = 0; i <= 2 * rows; i++) {
        for (int j = 1; j <= columns; j++) {
            if (i % 2 == 0) {
                std::cout << "+--";
            } else {
                std::cout << "|  ";
            }

            if (j == columns) {
                if (i % 2 == 0) {
                    std::cout << "+";
                } else {
                    std::cout << "|";
                }
            }
        }

        std::cout << std::endl;
    } 

    std::cout << std::endl;

    return 0;
}