#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Enter today's day: ";
    int day;
    cin >> day;

    cout << "Enter hours passed (0 - 24): ";
    int hours_passed;
    cin >> hours_passed;

    cout << "Today is ";

    switch (day) {
        case 1:
            cout << "Sunday";
            break;
        case 2:
            cout << "Monday";
            break;
        case 3:
            cout << "Tuesday";
            break;
        case 4:
            cout << "Wednesday";
            break;
        case 5:
            cout << "Thursday";
            break;
        case 6:
            cout << "Friday";
            break;
        default:
            cout << "Saturday";
    }

    cout << "\nRemaining hours: " << 24 - hours_passed << "\n";
    
    return 0;
}