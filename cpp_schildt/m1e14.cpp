#include <iostream>

using namespace std;

int main() {
    float jovian_years = 0.0;

    cout << "Enter Jovian years: ";
    cin >> jovian_years;

    float earth_years = jovian_years*12;

    cout << jovian_years << " jovian years are " << earth_years << " Earth years.\n";

    return 0;
}