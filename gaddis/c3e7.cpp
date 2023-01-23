#include <iostream>
#include <string>

int main() {
    std::cout << "Name of month: ";
    std::string m1 = "";
    getline(std::cin, m1);

    std::cout << "Amount of rain fallen (in inches): ";
    double r1 = 0.0;
    std::cin >> r1;

    std::cin.ignore();

    std::cout << "Name of month: ";
    std::string m2 = "";
    getline(std::cin, m2);

    std::cout << "Amount of rain fallen (in inches): ";
    double r2 = 0.0;
    std::cin >> r2;

    std::cin.ignore();

    std::cout << "Name of month: ";
    std::string m3 = "";
    getline(std::cin, m3);

    std::cout << "Amount of rain fallen (in inches): ";
    double r3 = 0.0;
    std::cin >> r3;

    double avg = (r1 + r2 + r3) / 3;

    std::cout << "The average monthly rainfall for " << m1 << ", " << m2
                << ", and " << m3 << " was " << avg << " inches." << std::endl; 

    return 0;
}