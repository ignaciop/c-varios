#include <iostream>
#include <iomanip>

int main() {
    const double YEARLY_OCEAN_RISE = 3.1F;
    double cummulative_ocean_rise = 0;

    std::cout << "\nYear\tCumulative rise (mm)" << std::endl;
    std::cout << "----------------------------" << std::endl;

    for (int i = 1; i <= 25; i++) {
        cummulative_ocean_rise += YEARLY_OCEAN_RISE;

        std::cout << std::setw(3) << i << "\t" << std::setw(10) << cummulative_ocean_rise << std::endl;
    }

    return 0;
}