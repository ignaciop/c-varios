#include "Population.h"

Population::Population(int inputPop, int inputBirths, int inputDeaths) {
    if (inputPop < 2) {
        current_population = 2;
    } else {
        current_population = inputPop;
    }

    if (inputBirths < 0) {
        annual_births = 0;
    } else {
        annual_births = inputBirths;
    }

    if (inputDeaths < 0) {
        annual_deaths = 0;
    } else {
        annual_deaths = inputDeaths;
    }
}

void Population::setPopulation(int inputPop) {
    if (inputPop < 2) {
        current_population = 2;
    } else {
        current_population = inputPop;
    }
}

void Population::setBirths(int inputBirths) {
    if (inputBirths < 0) {
        annual_births = 0;
    } else {
        annual_births = inputBirths;
    }
}

void Population::setDeaths(int inputDeaths) {
    if (inputDeaths < 0) {
        annual_deaths = 0;
    } else {
        annual_deaths = inputDeaths;
    }
}

int Population::getPopulation() const {
    return current_population;
}

double Population::getBirthRate() const {
    const double BASE_POPULATION = 1000.0F;

    return (annual_births / BASE_POPULATION);
}

double Population::getDeathRate() const {
    const double BASE_POPULATION = 1000.0F;

    return (annual_deaths / BASE_POPULATION);
}