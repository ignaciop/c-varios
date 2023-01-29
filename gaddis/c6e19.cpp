#include <iostream>

int projected_pop(int previous_pop, int movein_pop, int moveout_pop, double birth_rate, double death_rate);

int main() {
    int starting_size = 2;
    int movein_pop = 0;
    int moveout_pop = 0;
    double annual_birth_rate = 0.0;
    double annual_death_rate = 0.0;
    int numYears = 1;

    do {
        std::cout << "Enter the starting size of a population: ";
        std::cin >> starting_size;
    } while (starting_size < 2);

    do {
        std::cout << "Enter the number of individuals that move in: ";
        std::cin >> movein_pop;
    } while (movein_pop < 0);

    do {
        std::cout << "Enter the number of individuals that move out: ";
        std::cin >> moveout_pop;
    } while (moveout_pop < 0);

    std::cout << "Enter the annual birth rate: ";
    std::cin >> annual_birth_rate;

    std::cout << "Enter the annual death rate: ";
    std::cin >> annual_death_rate;

    do {
        std::cout << "Enter the number of years to display: ";
        std::cin >> numYears;
    } while (numYears < 2);
    
    annual_birth_rate /= 1000;
    annual_death_rate /= 1000;

    int prev_pop = starting_size;

    for (int i = 1; i <= numYears; i++) {
        int p = projected_pop(prev_pop, movein_pop, moveout_pop, annual_birth_rate, annual_death_rate);

        std::cout << "Year " << i << " --> Population: " << p << std::endl;

        prev_pop = p;
    }

    return 0;
}

int projected_pop(int previous_pop, int movein_pop, int moveout_pop, double birth_rate, double death_rate) {
    double p = (previous_pop + movein_pop - moveout_pop) * (1 + birth_rate) * (1 - death_rate);

    return static_cast<int>(p);
}