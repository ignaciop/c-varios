#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float ta, v;

    cout << "Enter the temperature in Fahrenheit: ";
    cin >> ta;

    cout << "Enter the wind speed in miles per hour: ";
    cin >> v;

    float pot = pow(v, 0.16);
    float twc = 35.74 + 0.6215 * ta - 35.75 * pot + 0.4275 * ta * pot;

    cout << "The wind chill index is " << twc << "\n";
 
    return 0;
}       