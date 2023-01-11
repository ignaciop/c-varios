#include <iostream>
#include <iomanip>

int main() {
    const int PARKING_SIZE = 20;
    const double CHARGE_LT_3HS = 6.00;
    const double CHARGE_EXTRA_HR = 1.50;
    const double MAX_CHARGE = 12.00;
    const int MAX_PARKING_HS = 24;

    int parking_station[PARKING_SIZE] = {};
    double parking_times[PARKING_SIZE] = {};
    double charges[PARKING_SIZE] = {};

    for (int i = 0; i < PARKING_SIZE; i++) {
        std::cout << "Number of parked car: ";
        std::cin >> parking_station[i];

        do {
            std::cout << "Parking time (< 24 hs): ";
            std::cin >> parking_times[i];

            double total_charge = CHARGE_LT_3HS;

            double temp = parking_times[i] - 3;

            while (temp > 0) {
                total_charge += CHARGE_EXTRA_HR;
                temp -= 1;
            }

            if (total_charge < MAX_CHARGE) {
                charges[i] = total_charge;
            } else {
                charges[i] = MAX_CHARGE;
            }
        } while (parking_times[i] < 0 || parking_times[i] > MAX_PARKING_HS);
    }

    double sum = 0.0;

    for (int i = 0; i < PARKING_SIZE; i++) {
        sum += charges[i];
    }

    std::cout << "Car\tTime\tCharge ($)\n";

    for (int i = 0; i < PARKING_SIZE; i++) {
        std::cout << parking_station[i] << "\t" << std::fixed << std::setprecision(2) << parking_times[i]
                    << "'\t" << charges[i] << std::endl;
    }

    std::cout << "Total\t\t" << sum << std::endl;

    return 0;
}