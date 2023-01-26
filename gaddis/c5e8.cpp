#include <iostream>
#include <iomanip>

int main() {
    const double PENNIES_2_DOLLAR = 0.01F;
    double salary_per_day = 1.0F;
    double total_salary = 0.0;

    int days = 1;

    do {
        std::cout << "Enter number of days worked: ";
        std::cin >> days;
    } while (days < 1 && days > 31);

    std::cout << "\nDay\tSalary per day (U.S. Dollars)" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    for (int i = 1; i <= days; i++) {
        std::cout << std::setw(2) << i << std::setw(16) << "$ " 
                    << std::setw(12) << std::fixed << std::setprecision(2) 
                        << std::right << salary_per_day * PENNIES_2_DOLLAR << std::endl; 
        
        total_salary += salary_per_day * PENNIES_2_DOLLAR;
        salary_per_day *= 2;
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Pay earned " << std::setw(6) << "$ " 
                    << std::setw(12) << std::fixed << std::setprecision(2) 
                        << std::right << total_salary << std::endl; 

    return 0;
}