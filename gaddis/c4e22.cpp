#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const double PLAN_A_BASE_PRICE = 39.99F;
    const int PLAN_A_GB_PROVIDED = 2;
    const double PLAN_A_ADDITIONALS_PER_GB = 8.00F;
    const double PLAN_B_BASE_PRICE = 59.99F;
    const int PLAN_B_GB_PROVIDED = 8;
    const double PLAN_B_ADDITIONALS_PER_GB = 8.00F;
    const double PLAN_C_BASE_PRICE = 79.99F;

    std::cout << "Enter customer's name: ";
    std::string name = "";
    getline(std::cin, name);

    std::cout << "Purchased plan: ";
    char plan = getchar();

    std::cout << "How many gigabytes were used: ";
    double gigabytes = 0.0;
    std::cin >> gigabytes;

    double total = 0.0;
    double gbs_consumed = 0.0;
    double saved = 0.0;

    switch (plan) {
        case 'A':
        case 'a':
            gbs_consumed = gigabytes - PLAN_A_GB_PROVIDED;

            if (gbs_consumed > 0) {
                total = PLAN_A_BASE_PRICE + gbs_consumed * PLAN_A_ADDITIONALS_PER_GB;
            } else {
                total = PLAN_A_BASE_PRICE;
            }

            saved = total - PLAN_C_BASE_PRICE;
            break;
        case 'B':
        case 'b':
            gbs_consumed = gigabytes - PLAN_B_GB_PROVIDED;
            
            if (gbs_consumed > 0) {
                total = PLAN_B_BASE_PRICE + gbs_consumed * PLAN_B_ADDITIONALS_PER_GB;
            } else {
                total = PLAN_B_BASE_PRICE;
            }

            saved = total - PLAN_C_BASE_PRICE;
            break;
        case 'C':
        case 'c':
            gbs_consumed = gigabytes;
            total = PLAN_C_BASE_PRICE;
            break;
        default:
            break;
    }

    std::cout << "\nMobile Service Provider - Monthly Bill" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Customer: " << name << std::endl;
    std::cout << "Plan " << plan << std::endl;
    std::cout << "Additional gigabytes consumed: " << std::fixed << std::setprecision(2) << ((gbs_consumed > 0) ? gbs_consumed : 0) << " GBs" << std::endl;
    std::cout << "Total payment: $" << std::fixed << total << std::endl;

    if (saved > 0) {
        std::cout << "\nIf you purchase Plan C, you will save $" << std::fixed << saved << std::endl;
    }

    std::cout << "------------------------------------------" << std::endl;

    return 0;
}