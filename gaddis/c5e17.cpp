#include <iostream>

int main() {
    int initial_organisms = 10;
    double avg_daily_population = 0.0F;
    int mult_days = 1;

    do {
        std::cout << "Enter the starting number of organisms: ";
        std::cin >> initial_organisms;
    } while (initial_organisms < 2);

    do {
        std::cout << "Enter the average daily population increase (%): ";
        std::cin >> avg_daily_population;
    } while (avg_daily_population < 0);

    do {
        std::cout << "Enter the number of days the organisms multiply: ";
        std::cin >> mult_days;
    } while (mult_days < 1);

    int organisms = initial_organisms;

    for (int i = 1; i <= mult_days; i++) {
        organisms += organisms * (avg_daily_population / 100);

        std::cout << "Day: " << i << " --> Population: " << organisms << std::endl; 
    }

    return 0;
}