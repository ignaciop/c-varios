#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const double COUNTY_TAX = 0.02F;
    const double SALES_TAX = 0.04F;
    const double TOTAL_SALES_TAX = COUNTY_TAX + SALES_TAX;

    std::cout << "Enter month: ";
    std::string month = "";
    getline(std::cin, month);

    std::cout << "Enter year: ";
    std::string year = "";
    getline(std::cin, year);

    std::cout << "Enter the total amount collected: ";
    double total= 0.0;
    std::cin >> total;

    double sales = total / (1 + TOTAL_SALES_TAX);
    double cst = sales * COUNTY_TAX;
    double sst = sales * SALES_TAX;
    double tst = cst + sst;

    std::cout << "Month: " << month << " " << year << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Total Collected: " << std::setw(7) << "$ " << std::setw(8) << std::fixed << std::setprecision(2) << std::right << total << std::endl;
    std::cout << "Sales: " << std::setw(17) << "$ " << std::setw(8) << std::fixed << std::setprecision(2) << std::right << sales << std::endl;
    std::cout << "Country Sales Tax: " << std::setw(5) << "$ " << std::setw(8) << std::fixed << std::setprecision(2) << std::right << cst << std::endl;
    std::cout << "State Sales Tax: " << std::setw(7) << "$ " << std::setw(8) << std::fixed << std::setprecision(2) << std::right << sst << std::endl;
    std::cout << "Total Sales Tax: " << std::setw(7) << "$ " << std::setw(8) << std::fixed << std::setprecision(2) << std::right << tst << std::endl; 
    
    return 0;
}