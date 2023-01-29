#ifndef POPULATION_H
#define POPULATION_H

class Population {
    private:
        int current_population;
        int annual_births;
        int annual_deaths;
    
    public:
        Population(int inputPop, int inputBirths, int inputDeaths);
        Population() : Population(2, 0, 0) {};
        ~Population() {};

        void setPopulation(int inputPop);
        void setBirths(int inputBirths);
        void setDeaths(int inputDeaths);

        int getPopulation() const;
        double getBirthRate() const;
        double getDeathRate() const;
};

#endif