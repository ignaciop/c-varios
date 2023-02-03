#include <iostream>
#include <iomanip>

int main() {
    const double TAX = 0.095F;
    const double SERVICE = 0.2F;

    std::cout << "Enter the bill: ";
    double bill = 0.0;
    std::cin >> bill;

    double total_bill = bill + bill * TAX + bill * SERVICE;
    double total_bill_per_adult = total_bill / 10;
    double total_bill_per_child = total_bill_per_adult * 3.0F / 4;

    // Difference to pay by each family for each children they have
    // because of children percentage over adult share
    double diff = total_bill_per_adult - total_bill_per_child;

    std::cout << "Total bill (after taxes): $" << std::fixed << std::setprecision(2) << total_bill << std::endl;

    double family1 = total_bill_per_adult * 2 + total_bill_per_child * 2 + diff * 2;
    double family2 = total_bill_per_adult * 2 + total_bill_per_child + diff;
    double family3 = family2;

    std::cout << "Family 1 (2 adults + 2 children): $" << std::fixed << family1 << std::endl;
    std::cout << "Family 2 (2 adults + 1 children): $" << std::fixed << family2 << std::endl;
    std::cout << "Family 3 (2 adults + 1 children): $" << std::fixed << family3 << std::endl;

    return 0;
}