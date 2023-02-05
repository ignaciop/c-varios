#include <iostream>

int main() {
    const int CAR_HOUR = 2;
    const int BUS_HOUR = 3;
    const int TRUCK_HOUR = 4;

    std::cout << "Please enter the type of vehicle (c: car, b: bus, t: truck): ";
    char t = getchar();

    if (t != 'c' && t != 'b' && t != 't') {
        std::cout << "Please enter a valid type of vehicle!" << std::endl;
        return 0;
    }

    std::cout << "Please enter total parking hours: ";
    int hours = 0;
    std::cin >> hours;

    int total_charge = 0;

    switch (t) {
        case 'c':
            total_charge = hours * CAR_HOUR;
            break;
        case 'b':
            total_charge = hours * BUS_HOUR;
            break;
        case 't':
            total_charge = hours * TRUCK_HOUR;
            break;
        default:
            break;
    }

    std::cout << "Parking charge: $" << total_charge << std::endl;

    return 0;
}