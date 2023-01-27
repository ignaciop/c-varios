#include <iostream>

double calculateCharge(double weight, double distance);

int main() {
    double weight = 1.0;
    double distance = 0.0;

    while (true) {
        std::cout << "Enter weight: ";
        std::cin >> weight;

        if (weight == 0.0) {
            break;
        } else {
            std::cout << "Enter distance: ";
            std::cin >> distance;
            
            std::cout << "Total charge: $" << calculateCharge(weight, distance) << std::endl;
        }
    } 

    return 0;
}

double calculateCharge(double weight, double distance) {
    const int FIXED_MILES = 500;

    double rate_per_500_miles = 0.0;
    double total_distance = distance;

    if (weight <= 2.0) {
        rate_per_500_miles = 3.10;
    } else if (weight > 2.0 && weight <= 6.0) {
        rate_per_500_miles = 4.20;
    } else if (weight > 6.0 && weight <= 10.0) {
        rate_per_500_miles = 5.30;
    } else {
        rate_per_500_miles = 6.40;
    }

    if (distance < FIXED_MILES) {
        total_distance = FIXED_MILES;
    }

    if (static_cast<int>(distance) % FIXED_MILES != 0) {
        total_distance = distance + FIXED_MILES - (static_cast<int>(distance) % FIXED_MILES);
    }

    total_distance /= FIXED_MILES;

    double charge = total_distance * rate_per_500_miles;

    return charge;
}