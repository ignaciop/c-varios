#include <iostream>

int main() {
    float car_gallons = 20.0F;
    float miles_per_gallon_town = 23.5F;
    float miles_per_gallon_highway = 28.9F;

    float total_miles_town = car_gallons * miles_per_gallon_town;
    float total_miles_highway = car_gallons * miles_per_gallon_highway;

    std::cout << "Miles per tank in town: " << total_miles_town << std::endl;
    std::cout << "Miles per tank in highway: " << total_miles_highway << std::endl;

    return 0;
}