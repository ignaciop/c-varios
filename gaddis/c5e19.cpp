#include <iostream>

int main() {
    const int TOTAL_SUITES = 120;
    const int SUITES_PER_FLOOR = 20;

    int suites_occupied = 0;

    for (int i = 10; i <= 16; i++) {
        if (i == 13) {
            continue;
        }

        int suites_pf_i = 0;

        do {
            std::cout << "How many suites are occupied in the " << i << "th floor? ";
            std::cin >> suites_pf_i;
        } while (suites_pf_i < 0 || suites_pf_i > SUITES_PER_FLOOR);

        suites_occupied += suites_pf_i;
    }

    double occupancy_rate = static_cast<double>(suites_occupied) / TOTAL_SUITES * 100;
    
    std::cout << "The hotel has " << TOTAL_SUITES << " suites." << std::endl;
    std::cout << "Suites occupied: " << suites_occupied << " (" << occupancy_rate << "%)" << std::endl;
    
    return 0;
}