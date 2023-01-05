#include <iostream>

int main() {
    std::cout << "Enter initial population: ";
    float initial_population = 0.0;
    std::cin >> initial_population;

    std::cout << "Enter annual population growth (as a percentage): ";
    float growth = 0.0;
    std::cin >> growth;

    std::cout << "Enter numbers of years: ";
    int years = 0;
    std::cin >> years;

    int i = 1;
    float total_population = initial_population;

    while (i <= years) {
        total_population += total_population * (growth / 100);
        
        std::cout << "After " << i << ((i == 1) ? " year: " : " years: ") << total_population << std::endl;

        i++;
    }

    return 0;
}