#include <iostream>

int main() {
    const double CALS_PER_BURRITO = 357.0;
    const double CALS_PER_SALAD = 185.0;
    const double CALS_PER_MILKSHAKE = 388.0;
    const double CALS_BURNT_PER_MILE = 100.0;

    std::cout << "Number of bean burritos, bowls of salad, and milkshakes eaten? ";
    double burritos {}, salad {}, milkshakes {};
    std::cin >> burritos >> salad >> milkshakes;

    double total_cals = burritos * CALS_PER_BURRITO + salad * CALS_PER_SALAD + milkshakes * CALS_PER_MILKSHAKE;
    double total_run = total_cals / CALS_BURNT_PER_MILE;

    std::cout << "You have ingested " << total_cals << " Calories" << std::endl;
    std::cout << "You will have to run " << total_run << " miles to expend that much energy" << std::endl;

    return 0;
}