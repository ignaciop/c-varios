#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, time, distance;
    int hours, minutes;

    cout << "Enter the average speed of car A (in mph): ";
    cin >> x;

    cout << "Enter the average speed of car B (in mph): ";
    cin >> y;

    cout << "Enter the elapsed time (in hours and minutes): ";
    cin >> hours >> minutes;

    time = hours + (double) minutes / 60;
    distance = sqrt(pow(x * time, 2) + pow(y * time, 2)); // Distance formula

    cout << "The shortest distance between the cars is " << distance << " miles." << endl;

    return 0;
}