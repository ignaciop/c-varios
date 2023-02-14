#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main() {
    double height;
    double radius;

    cout << "Enter the height of the cylinder: ";
    cin >> radius;
    cout << endl;

    cout << "Enter the radius of the base of the cylinder: ";
    cin >> height;
    cout << endl;

    cout << fixed << showpoint << setprecision(2);

    cout << "Volume of the cylinder = " << PI * pow(radius, 2.0) * height 
            << endl;
    cout << "Surface area: " << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0)
            << endl;
    
    return 0;
}