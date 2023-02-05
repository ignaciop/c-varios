#include <iostream>

int main () {
    int year;
    int month;
    int day;
    int totalDays = 0;

    std::cout << "Enter year: ";
    std::cin >> year;

    std::cout << "Enter month: ";
    std::cin >> month;

    std::cout << "Enter day of month: ";
    std::cin >> day;

    int m01 = 31;
    int m02 = 28;

    bool leapYear = ((year % 400 == 0) || ((year % 4 == 0) && !(year % 100 == 0)));

    if (leapYear) {
        m02 = 29;
    }

    int m03 = 31;
    int m04 = 30;
    int m05 = 31;
    int m06 = 30;
    int m07 = 31;
    int m08 = 31;
    int m09 = 30;
    int m10 = 31;
    int m11 = 30;

    switch (month) {
        case 12 : totalDays += m11;
        case 11 : totalDays += m10;
        case 10 : totalDays += m09;
        case 9 : totalDays += m08;
        case 8 : totalDays += m07;
        case 7 : totalDays += m06;
        case 6 : totalDays += m05;
        case 5 : totalDays += m04;
        case 4 : totalDays += m03;
        case 3 : totalDays += m02;
        case 2 : totalDays += m01;
        case 1 : totalDays += 0;
    }

    totalDays += day;

    std::cout << "Day number: " << totalDays << std::endl;

    return 0;
}