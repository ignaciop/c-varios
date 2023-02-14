#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile;
    std::ofstream outFile;

    inFile.open("data/Ch3_Ex5Data.txt");
    outFile.open("data/Ch3_Ex5Output.dat");

    std::string last_name1 = "";
    inFile >> last_name1;

    std::string first_name1 = "";
    inFile >> first_name1;

    double salary1 = 0.0;
    inFile >> salary1;

    double pay_increase1 = 0.0;
    inFile >> pay_increase1;
    pay_increase1 /= 100;

    std::string last_name2 = "";
    inFile >> last_name2;

    std::string first_name2 = "";
    inFile >> first_name2;

    double salary2 = 0.0;
    inFile >> salary2;

    double pay_increase2 = 0.0;
    inFile >> pay_increase2;
    pay_increase2 /= 100;

    std::string last_name3 = "";
    inFile >> last_name3;

    std::string first_name3 = "";
    inFile >> first_name3;

    double salary3 = 0.0;
    inFile >> salary3;

    double pay_increase3 = 0.0;
    inFile >> pay_increase3;
    pay_increase3 /= 100;

    double update_salary1 = salary1 + salary1 * pay_increase1;
    double update_salary2 = salary2 + salary2 * pay_increase2;
    double update_salary3 = salary3 + salary3 * pay_increase3;

    outFile << std::fixed << std::setprecision(2);
    outFile << first_name1 << " " << last_name1 << " " << update_salary1 << std::endl;
    outFile << first_name2 << " " << last_name2 << " " << update_salary2 << std::endl;
    outFile << first_name3 << " " << last_name3 << " " << update_salary3;

    std::cout << "File Saved!" << std::endl;

    inFile.close();
    outFile.close();

    return 0;
}