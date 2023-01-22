#include <iostream>

int main() {
    double total_customers = 16500.0F;
    double one_drink = total_customers * 0.15F;
    double citrus = one_drink * 0.52F;

    std::cout << "Customers who purchase one or more energy drinks per week: "
                << one_drink << std::endl;
    std::cout << "Customers who purchased citrus flavored energy drinks: "
                << citrus << std::endl;

    return 0;
}