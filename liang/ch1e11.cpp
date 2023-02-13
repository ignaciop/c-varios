#include <iostream>

using namespace std;

int main() {
    float initial_population = 312032486.0;
    float seconds_in_year = 31536000.0;

    float births_per_year = seconds_in_year / 7;
    float deaths_per_year = seconds_in_year / 13;
    float immigrants_per_year = seconds_in_year / 45;

    float year_one = initial_population + births_per_year + immigrants_per_year - deaths_per_year;
    float year_two = year_one + births_per_year + immigrants_per_year - deaths_per_year;
    float year_three = year_two + births_per_year + immigrants_per_year - deaths_per_year;
    float year_four = year_three + births_per_year + immigrants_per_year - deaths_per_year;
    float year_five = year_four + births_per_year + immigrants_per_year - deaths_per_year;

    cout << "Initial population: " << initial_population << "\n";
    cout << "After one year: " << year_one << "\n";
    cout << "After two years: " << year_two << "\n";
    cout << "After three years: " << year_three << "\n";
    cout << "After four years: " << year_four << "\n";
    cout << "After five years: " << year_five << "\n";

    return 0;
}