#include <iostream>

using namespace std;

int main() {
    const double METRIC_TON_2_POUNDS = 2205;

    double rice;

    cout << "Enter the amount of rice a bag can hold (pounds): ";
    cin >> rice;

    int bags = static_cast<int>(METRIC_TON_2_POUNDS / rice + 0.5);

    cout << "You need " << bags << " bags with " << rice 
            << " pounds of rice each to store one metric ton of rice." << endl; 
    
    return 0;
}