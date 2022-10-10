#include <iostream>

using namespace std;

int main() {
    int day;
    int days_elapsed;

    cout << "Enter today's day: ";
    cin >> day;

    cout << "Enter the number of days elapsed since today: ";
    cin >> days_elapsed;

    cout << "Today is ";

    switch (day) {
        case 0:
            cout << "Sunday";
            break;
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        default:
            cout << "Saturday";
    }

    int future_day = (day + days_elapsed) % 7;

    cout << " and the future day is ";

    switch (future_day) {
        case 0:
            cout << "Sunday";
            break;
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        default:
            cout << "Saturday";
    }

    cout << "\n";
    
    return 0;
}