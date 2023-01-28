#include <iostream>

int projected_pop(int previous_pop, double birth_rate, double death_rate);

int main() {
    int starting_size = 2;
    double annual_birth_rate = 0.0;
    double annual_death_rate = 0.0;
    int years = 1;

    do {
        std::cout << "Enter the starting size of a population: ";
        std::cin >> starting_size;
    } while (starting_size < 2);

    std::cout << "Enter the annual birth rate: ";
    std::cin >> annual_birth_rate;

    std::cout << "Enter the annual death rate: ";
    std::cin >> annual_death_rate;

    do {
        std::cout << "Enter the number of years to display: ";
        std::cin >> years;
    } while (years < 2);
    
    annual_birth_rate /= 1000;
    annual_death_rate /= 1000;

    int prev_pop = starting_size;

    for (int i = 1; i <= years; i++) {
        int p = projected_pop(prev_pop, annual_birth_rate, annual_death_rate);

        std::cout << "Year " << i << " --> Population: " << p << std::endl;

        prev_pop = p;
    }
}

int projected_pop(int previous_pop, double birth_rate, double death_rate) {
    double p = previous_pop * (1 + birth_rate) * (1 - death_rate);

    return static_cast<int>(p);
}