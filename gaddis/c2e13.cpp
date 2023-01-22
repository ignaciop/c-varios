#include <iostream>

int main() {
    float annual_earnings = 39000.0F;
    float gross_pay_tam = annual_earnings / 24.0F;
    float gross_pay_bw = annual_earnings / 26.0F;

    std::cout << "Earning (twice a month): $" << gross_pay_tam << std::endl;
    std::cout << "Earning (bi-weekly): $" << gross_pay_bw << std::endl;

    return 0;
}