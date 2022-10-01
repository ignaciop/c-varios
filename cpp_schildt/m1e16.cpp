#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x1 = 0.0;
    float x2 = 0.0;
    float x3 = 0.0;
    float x4 = 0.0;
    float x5 = 0.0;

    cout << "Enter first number: ";
    cin >> x1;

    cout << "Enter second number: ";
    cin >> x2;

    cout << "Enter third number: ";
    cin >> x3;

    cout << "Enter fourth number: ";
    cin >> x4;

    cout << "Enter fifth number: ";
    cin >> x5;

    float avg = (abs(x1) + abs(x2) + abs(x3) + abs(x4) + abs(x5))/5;

    cout << "Averages of absolute values: " << avg << "\n";

    return 0;
}