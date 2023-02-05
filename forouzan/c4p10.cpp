#include <iostream>

int main () {
    int year;
    int month;
    int day;

    std::cout << "Enter year: ";
    std::cin >> year;

    std::cout << "Enter month: ";
    std::cin >> month;

    std::cout << "Enter day of month: ";
    std::cin >> day;

    int weekday = (day + 13 / 5 * (month + 1) + year + year / 4 + (year / 100) / 4 + 5 * year / 100) % 7;

    switch (weekday) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 0:
            std::cout << "Sunday" << std::endl;
            break;
    }

    return 0;
}