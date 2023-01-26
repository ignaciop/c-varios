#include <iostream>
#include <iomanip>

int main() {
    std::cout << "What is the speed of the vehicle in mph? ";
    double speed = 0.0;
    std::cin >> speed;

    std::cout << "How many hours has it traveled? ";
    double hours = 0.0;
    std::cin >> hours;

    std::cout << "\nHour\tMiles Traveled" << std::endl;
    std::cout << "----------------------------" << std::endl;

    for (int i = 1; i <= hours; i++) {
        std::cout << std::setw(2) << i << "\t" << std::setw(8) << speed * i << std::endl;
    }

    return 0;
}