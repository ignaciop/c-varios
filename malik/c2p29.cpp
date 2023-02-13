#include <iostream>
#include <cmath>

using namespace std;

const int CUBIC_FEET_PER_CUBIC_YARD = 27;
const int INCHES_PER_FOOT = 12;

int main() {
    int concreteAmount, thickness;
    double lengthToWidthRatio;

    cout << "Enter the amount of premixed concrete ordered (in cubic yards): ";
    cin >> concreteAmount;

    cout << "Enter the thickness of the patio (in inches): ";
    cin >> thickness;

    cout << "Enter the ratio of length to width: ";
    cin >> lengthToWidthRatio;

    double volume = concreteAmount * CUBIC_FEET_PER_CUBIC_YARD;
    double area = volume / (thickness / INCHES_PER_FOOT);
    double length = sqrt(area * lengthToWidthRatio);
    double width = length / lengthToWidthRatio;

    cout << "The length of the patio is: " << length << " feet" << endl;
    cout << "The width of the patio is: " << width << " feet" << endl;

    return 0;
}