#include <iostream>

using namespace std;

int main() {
    float distance, miles_per_gallon, price_per_gallon;

    cout << "Enter the driving distance: ";
    cin >> distance;

    cout << "Enter miles per gallon: ";
    cin >> miles_per_gallon;

    cout << "Enter price per gallon: ";
    cin >> price_per_gallon;

    float total_gallons = distance / miles_per_gallon;
    float total_price = total_gallons * price_per_gallon;

    cout << "The cost of driving is $" << total_price << "\n";

    return 0;
}       