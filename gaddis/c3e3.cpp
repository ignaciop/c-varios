#include <iostream>

int main() {
    std::cout << "Rent or mortgage payment: ";
    double rent = 0.0;
    std::cin >> rent;

    std::cout << "Phones payment: ";
    double phones = 0.0;
    std::cin >> phones;

    std::cout << "Internet service utilities payment: ";
    double isp = 0.0;
    std::cin >> isp;

    std::cout << "Cable payment: ";
    double cable = 0.0;
    std::cin >> cable;

    double pay_per_month = rent + phones + isp + cable;
    double pay_per_year = pay_per_month * 12;

    std::cout << "Total monthly cost: $" << pay_per_month << std::endl;
    std::cout << "Total annual cost: $" << pay_per_year << std::endl;

    return 0;
}