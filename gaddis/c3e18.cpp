#include <iostream>

int main() {
    const double ASSESSED_PERCENTAGE = 0.6F;
    const double ASSESSED_UNIT = 100.0F;
    const double SENIOR_EXEMPTION = 5000.0F;

    std::cout << "Enter the property value: ";
    double property_value = 0.0;
    std::cin >> property_value;

    std::cout << "Enter tax rate for each $100 of assessed value: ";
    double tax_rate = 0.0;
    std::cin >> tax_rate;

    double assessed_value = property_value * ASSESSED_PERCENTAGE;
    assessed_value -= SENIOR_EXEMPTION;

    double units = assessed_value / ASSESSED_UNIT;
    double annual_property_tax = tax_rate * units;

    std::cout << "Annual property tax for senior citizen: $" 
                << annual_property_tax << std::endl;
    std::cout << "Quarterly tax: $" << annual_property_tax / 4 << std::endl;
    
    return 0;
}