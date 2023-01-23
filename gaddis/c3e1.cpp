#include <iostream>

int main() {
    std::cout << "Enter the number of gallons the car can hold: ";
    double car_gallons = 0.0;
    std::cin >> car_gallons;

    std::cout << "Enter the number of miles driven with a full tank: ";
    double miles_driven = 0.0;
    std::cin >> miles_driven;

    double miles_per_gallon = miles_driven / car_gallons;

    std::cout << "Miles per gallon: " << miles_per_gallon << std::endl;
    
    return 0;
}