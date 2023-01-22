#include <iostream>

int main() {
    double ocean_rise_mm = 100.0F * 1.8F;
    double ocean_rise_cm = ocean_rise_mm * 0.1F;
    double ocean_rise_inches = ocean_rise_cm * 0.3937F;

    std::cout << "Ocean rise in 100 years (in cm): " << ocean_rise_cm << std::endl;
    std::cout << "Ocean rise in 100 years (in inches): " << ocean_rise_inches << std::endl;

    return 0;
}