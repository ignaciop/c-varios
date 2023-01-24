#include <iostream>

int main() {
    std::cout << "Enter a year: ";
    int year = 0;
    std::cin >> year;

    if (((year % 4 == 0) && ( year % 100 != 0)) || (year % 400 == 0)) {
        std::cout << "In " << year << " February has 29 days." << std::endl;
    } else {
        std::cout << "In " << year << " February has 28 days." << std::endl;
    }

    return 0;
}