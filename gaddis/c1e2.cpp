#include <iostream>

int main() {
    double baseballs, price, total;

    std::cout << "How many baseballs you purchased? ";
    std::cin >> baseballs;

    std::cout << "How much do you paid per baseball? ";
    std::cin >> price;

    total = baseballs * price;

    std::cout << "You have payed $" << total << " for " << baseballs
                << " baseballs." << std::endl;

    return 0;
}