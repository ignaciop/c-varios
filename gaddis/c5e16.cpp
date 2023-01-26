#include <iostream>

int main() {
    const int MAX_YEARS = 10;

    std::cout << "Enter the annual rate of inflation: ";
    double rate = 0.0;
    std::cin >> rate;

    double amount = 1000.0;

    std::cout << "Initial amount: $" << amount << std::endl;

    for (int i = 1; i <= MAX_YEARS; i++) {
        amount /= (1 + rate / 100);

        std::cout << "Year: " << i << ", Amount: $" << amount << std::endl; 
    }

    return 0;
}