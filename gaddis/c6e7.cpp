#include <iostream>
#include <string>

double calcMPG(float distInMiles, float gallon) {
    return distInMiles / gallon; //return miles per gallon
}

int main() {
    double distInMiles = 500;
    double effi_c1, effi_c2, effi_c3, gallons;
    std::string carMake1, carMake2, carMake3;

    // Ask for car make and amount of gallons used
    std::cout << " What is the make of the car? ";
    getline(std::cin, carMake1);

    std::cout << " How many gallons of gas did this car use? ";
    std::cin >> gallons;
    effi_c1 = calcMPG(distInMiles, gallons);

    std::cin.ignore();

    std::cout << " What is the make of the car? ";
    getline(std::cin, carMake2);

    std::cout << " How many gallons of gas did this car use? ";
    std::cin >> gallons;
    effi_c2 = calcMPG(distInMiles, gallons);

    std::cin.ignore();

    std::cout << " What is the make of the car? ";
    getline(std::cin, carMake3);

    std::cout << " How many gallons of gas did this car use? ";
    std::cin >> gallons;
    effi_c3 = calcMPG(distInMiles, gallons);

    // Determine which car is most efficent
    if (effi_c1 > effi_c2) {
        if (effi_c1 > effi_c3) {
            std::cout << "car 1 is most efficient.\n";
            std::cout << "efficiency (in miles per gallons) : " << effi_c1;
        } else {
            std::cout << "car 3 is most efficient.\n";
            std::cout << "efficiency (in miles per gallons) : " << effi_c3;
        }
    } else {
        if (effi_c2 > effi_c3) {
            std::cout << "car 2 is most efficient.\n";
            std::cout << "efficiency (in miles per gallons) : " << effi_c2;
        } else {
            std::cout << "car 3 is most efficient.\n";
            std::cout << "efficiency (in miles per gallons) : " << effi_c3;
        }
    }

    return 0;
}