#include <iostream>

int main () {
    for (int year = 2000; year <= 2099; year++) {
        bool leapYear = ((year % 400 == 0) || ((year % 4 == 0) && !(year % 100 == 0)));

        if (leapYear) {
            std::cout << year << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}