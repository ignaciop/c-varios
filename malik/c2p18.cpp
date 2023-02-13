#include <iostream>

using namespace std;

int main() {
    double pay_rate_per_hour;
    double hours_worked;

    cout << "Enter the pay rate per hour: ";
    cin >> pay_rate_per_hour;

    cout << "Enter the hours worked: ";
    cin >> hours_worked;

    double partial_earned = hours_worked * pay_rate_per_hour;
    double earned_after_tax = partial_earned - partial_earned * 14 / 100;
    
    double clothes = earned_after_tax * 10 / 100;
    double supplies = earned_after_tax * 1 / 100;

    double rem = earned_after_tax - clothes - supplies;

    double bonds = rem * 25 / 100;
    double parent_spent = bonds * 0.50;

    cout << "Income before taxes         : $" << partial_earned << endl;
    cout << "Income after taxes          : $" << earned_after_tax << endl;
    cout << "Money spent on clothes      : $" << clothes << endl;
    cout << "Money spent on supplies     : $" << supplies << endl;
    cout << "Money spent on bonds        : $" << bonds << endl;
    cout << "Money spent on parents bonds: $" << parent_spent << endl;

    return 0;
}