#include <iostream>

int main() {
    float purchase = 95.0F;
    float sales_tax = purchase * 0.065;
    float county_sales_tax = purchase * 0.02;

    float total_tax = sales_tax + county_sales_tax;
    float total_price = purchase + total_tax;

    std::cout << "Purchase price: $" << purchase << std::endl;
    std::cout << "Total tax: $" << total_tax << std::endl;
    std::cout << "Total price: $" << total_price << std::endl;

    return 0;
}