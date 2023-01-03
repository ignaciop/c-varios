#include <iostream>

int main() {
    std::cout << "Enter a month number: " << std::endl;
    int month;
    std::cin >> month;

    int days_in_month = 0;

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days_in_month = 31;
            break;
        case 2:
            std::cout << "28 or 29 days in February? ";
            std::cin >> days_in_month;
            break;
        default:
            days_in_month = 30;
            break;
    }

    std::cout << "Enter a day number: " << std::endl;
    int day;
    std::cin >> day;

    int final_month = (month < 12) ? (month + 5/3) : ((month + 5/3) % 12);
    
    int final_days = day + 50;
    final_days %= days_in_month;

    std::cout << final_month << "/" << final_days << std::endl;

    return 0;
}