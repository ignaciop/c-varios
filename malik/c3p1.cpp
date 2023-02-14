#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::ifstream inFile;
    std::ofstream outFile;

    inFile.open("data/inData.txt");
    outFile.open("data/outData.txt");

    std::string first_name = "";
    inFile >> first_name;

    std::string last_name = "";
    inFile >> last_name;

    std::string department = "";
    inFile >> department;

    double monthly_gross_salary = 0.0;
    inFile >> monthly_gross_salary;

    double bonus = 0.0;
    inFile >> bonus;

    double taxes = 0.0;
    inFile >> taxes;
    
    double distance_traveled = 0.0;
    inFile >> distance_traveled;

    double travelling_time = 0.0;
    inFile >> travelling_time;

    int cups_sold = 0;
    inFile >> cups_sold;

    double cost_per_cup = 0.0;
    inFile >> cost_per_cup;

    double paycheck = monthly_gross_salary + monthly_gross_salary * bonus / 100;
    paycheck -= paycheck * taxes / 100;
    double avg_speed = distance_traveled / travelling_time;
    double sales_amount = cups_sold * cost_per_cup;

    outFile << std::fixed << std::setprecision(2);
    outFile << "Name: " << first_name << " " << last_name << ", Department: " << department << std::endl;
    outFile << "MonthlyGrossSalary: $" << monthly_gross_salary << ", MonthlyBonus: "
            << bonus << "%, Taxes: " << taxes << "%" << std::endl;
    outFile << "Paycheck: $" << paycheck << std::endl;
    outFile << '\n';
    outFile << "Distance Traveled: " << distance_traveled << " miles, Travelling Time: "
            << travelling_time << " hours" << std::endl;
    outFile << "Average Speed: " << avg_speed << " miles per hour" << std::endl;
    outFile << '\n';
    outFile << "Number of Coffee Cups Sold: " << cups_sold << ", Cost: $"
            << cost_per_cup << " per cup" << std::endl;
    outFile << "Sales Amount = $" << sales_amount;

    std::cout << "File Saved!" << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}