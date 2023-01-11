#include <iostream>
#include <cmath>

int main() {
    const int ARR_SIZE = 100;

    double values[ARR_SIZE] = {};
    double distances[ARR_SIZE - 1] = {};

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "Enter double value: ";
        std::cin >> values[i];
    }

    std::cout << "\n";

    for (int i = 0; i < ARR_SIZE - 1; i++) {
        distances[i] = fabs(values[i + 1] - values[i]);

        std::cout << "|" << values[i + 1] << " - " << values[i] << "| = "
                    << distances[i] << std::endl;
    }
    
    double min = distances[0];

    for (int i = 0; i < ARR_SIZE - 1; i++) {
         if (distances[i] < min) {
            min = distances[i];
         }
    }

    std::cout << "\n";

    std::cout << "Minimum distance: " << min << std::endl;
    
    return 0;
}