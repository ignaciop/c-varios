#include <iostream>
#include <iomanip>

int main() {
    const double KG_2_POUND = 2.2;

    std::cout << "Enter the weight in kilograms: ";
    double kgs = 0.0;
    std::cin >> kgs;

    double pounds = kgs * KG_2_POUND;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << kgs << " kilograms equals to " << pounds << " pounds." << std::endl;
    
    return 0;
}