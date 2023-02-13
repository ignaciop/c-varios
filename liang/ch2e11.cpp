#include <iostream>

using namespace std;

int main() {
    int years;
    float initial_population = 312032486.0;
    float seconds_in_year = 31536000.0;

    float births_per_year = seconds_in_year / 7;
    float deaths_per_year = seconds_in_year / 13;
    float immigrants_per_year = seconds_in_year / 45;

    float pop_rate = births_per_year + immigrants_per_year - deaths_per_year;

    cout << "Enter the number of years: ";
    cin >> years;

    float final_pop = initial_population + years * pop_rate;

    cout << "The population in " << years << " years is " << final_pop << "\n";

    return 0;
}