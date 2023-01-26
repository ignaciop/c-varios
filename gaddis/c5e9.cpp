#include <iostream>
#include <iomanip>

int main() {
    const double POUNDS_LOSEN_PER_MONTH = 4.0F;
    const int TOTAL_MONTHS = 6;

    std::cout << "Enter your weight (in lb): ";
    double weight = 0.0;
    std::cin >> weight;
    
    std::cout << "\nMonth\tExpected weight (lb)" << std::endl;
    std::cout << "----------------------------" << std::endl;

    for (int i = 1; i <= TOTAL_MONTHS; i++) {
        weight -= POUNDS_LOSEN_PER_MONTH;

        std::cout << std::setw(3) << i << std::setw(16) << std::fixed 
                    << std::setprecision(2) << std::right << weight << std::endl; 
    }

    return 0;
}