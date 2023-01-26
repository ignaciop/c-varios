#include <iostream>
#include <iomanip>

int main() {
    const double PI = 3.14F;

    std::cout << "\nRadius\t\tArea" << std::endl;
    std::cout << "---------------------" << std::endl;

    for (int i = 1; i <= 8; i *= 2) {
        double area = PI * i * i;

        std::cout << std::setw(4) << i << "\t" << std::setw(12) << area << std::endl;
    }

    return 0;
}