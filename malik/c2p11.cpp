#include <iostream>

using namespace std;

int main() {
    double capacity, miles_per_gallon;

    cout << "Enter the fuel tank capacity (gallons): ";
    cin >> capacity;

    cout << "Enter the miles per gallon: ";
    cin >> miles_per_gallon;
    
    double total_miles = capacity / miles_per_gallon;

    cout << "The car goes " << total_miles << " miles without refuelling" << endl;
    
    return 0;
}