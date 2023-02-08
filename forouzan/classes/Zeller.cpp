#include "Zeller.h"
#include <iostream>

Zeller::Zeller() : Zeller(1, 1, 1970) {}

Zeller::Zeller(int iDay, int iMonth, int iYear) : day(iDay), month(iMonth), year(iYear) {}

Zeller::Zeller(const Zeller& zellerCopy) : day(zellerCopy.day), month(zellerCopy.month), year(zellerCopy.year) {}

Zeller::~Zeller() {}

void Zeller::weekday() {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
  
    int k = year % 100;
    int j = year / 100;
    int wkday = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    switch (wkday) {
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
}