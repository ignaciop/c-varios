#include <iostream>

int main() {
    const int REGISTRATION_FEE = 10;

    std::cout << "How many units have you taken? ";
    int units = 0;
    std::cin >> units;

    int total_fee = 0;

    if (units >= 12) {
        total_fee = 12 * REGISTRATION_FEE;
    } else {
        if (units >= 0) {
            total_fee = units * REGISTRATION_FEE;
        }
    }

    std::cout << "Total tuition: $" << total_fee << std::endl;
    
    return 0;
}