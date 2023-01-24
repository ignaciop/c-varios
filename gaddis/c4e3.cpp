#include <iostream>

int main() {
    std::cout << "Enter a month: ";
    int month = 0;
    std::cin >> month;

    std::cout << "Enter a day: ";
    int day = 0;
    std::cin >> day;

    std::cout << "Enter a two-digit year: ";
    int year = 0;
    std::cin >> year;

    if ((month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
        if (month * day == year) {
            std::cout << "The date is magic" << std::endl;
        } else {
            std::cout << "The date is not magic" << std::endl;
        }
    } else {
        std::cout << "Please enter a valid month or day" << std::endl;
    }
    
    return 0;
}