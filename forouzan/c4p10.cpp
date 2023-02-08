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

    if (month < 3) {
        month += 12;
        year -= 1;
    }
  
    int k = year % 100;
    int j = year / 100;

    int weekday = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    switch (weekday) {
        case 2:
            std::cout << "Monday" << std::endl;
            break;
        case 3:
            std::cout << "Tuesday" << std::endl;
            break;
        case 4:
            std::cout << "Wednesday" << std::endl;
            break;
        case 5:
            std::cout << "Thursday" << std::endl;
            break;
        case 6:
            std::cout << "Friday" << std::endl;
            break;
        case 0:
            std::cout << "Saturday" << std::endl;
            break;
        case 1:
            std::cout << "Sunday" << std::endl;
            break;
    }

    return 0;
}