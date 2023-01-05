#include <iostream>

int main() {
    float temperature = 0.0;
    int total_temps = 0;
    int equal_to_40F = 0;
    int less_than_40F = 0;
    int more_than_40F = 0;

    while (true) {
        std::cout << "Enter daily temperature (1000 to end insertion): ";
        std::cin >> temperature;

        if (temperature != 1000) {
            total_temps++;

            if (temperature < 40) {
                less_than_40F++;
            } else if (temperature > 40) {
                more_than_40F++;
            } else {
                equal_to_40F++;
            }
        } else {
            break;
        }
    }

    float less_percentage = (less_than_40F / static_cast<float>(total_temps)) * 100;
    float more_percentage = (more_than_40F / static_cast<float>(total_temps)) * 100;
    float equal_percentage = (equal_to_40F / static_cast<float>(total_temps)) * 100;

    std::cout << "Less than 40ºF: " << less_percentage << "%" << std::endl;
    std::cout << "More than 40ºF: " << more_percentage << "%" << std::endl;
    std::cout << "Equal to 40ºF: " << equal_percentage << "%" << std::endl;

    return 0;
}