#include <iostream>

int main() {
    std::cout << "Enter a year: ";
    int year = 0;
    std::cin >> year;

    if (((year % 4 == 0) && ( year % 100 != 0)) || (year % 400 == 0)) {
        std::cout << year << " is a leap year." << std::endl;
    } else {
        if ((((year + 1) % 4 == 0) && ((year + 1) % 100 != 0)) || ((year + 1) % 400 == 0)) {
            std::cout << "The next leap year is " << year + 1 << std::endl;
        }

        if ((((year + 2) % 4 == 0) && ((year + 2) % 100 != 0)) || ((year + 2) % 400 == 0)) {
            std::cout << "The next leap year is " << year + 2 << std::endl;
        }

        if ((((year + 3) % 4 == 0) && ((year + 3) % 100 != 0)) || ((year + 3) % 400 == 0)) {
            std::cout << "The next leap year is " << year + 3 << std::endl;
        }
    }

    return 0;
}