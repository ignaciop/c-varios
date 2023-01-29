#include <iostream>
#include "classes/Population.h"

int main() {
    Population p1;

    std::cout << "Population 1: " << p1.getPopulation() << std::endl;
    std::cout << "Population 1 birth rate: " << p1.getBirthRate() << std::endl;
    std::cout << "Population 1 death rate: " << p1.getDeathRate() << std::endl;

    p1.setPopulation(7);
    p1.setBirths(450);
    p1.setDeaths(200);

    std::cout << "New Population 1: " << p1.getPopulation() << std::endl;
    std::cout << "Population 1 new birth rate: " << p1.getBirthRate() << std::endl;
    std::cout << "Population 1 new death rate: " << p1.getDeathRate() << std::endl;

    Population p2(150000, 1500, 350);

    std::cout << "Population 2: " << p2.getPopulation() << std::endl;
    std::cout << "Population 2 birth rate: " << p2.getBirthRate() << std::endl;
    std::cout << "Population 2 death rate: " << p2.getDeathRate() << std::endl;

    return 0;
}