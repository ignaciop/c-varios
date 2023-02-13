#include <iostream>

using namespace std;

int main() {
    double d1, d2, d3, d4, d5, total;

    cout << "Enter a decimal number: ";
    cin >> d1;

    cout << "Enter a decimal number: ";
    cin >> d2;

    cout << "Enter a decimal number: ";
    cin >> d3;

    cout << "Enter a decimal number: ";
    cin >> d4;

    cout << "Enter a decimal number: ";
    cin >> d5;

    total = d1 + d2 + d3 + d4 + d5;

    int int_total = static_cast<int>(total + 0.5);

    cout << "The rounded sum is " << int_total << endl;
    
    return 0;
}