#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Enter a number between 0 and 1000: ";
    cin >> number;

    int unit = number % 10;
    number /= 10;

    int decs = number % 10;
    number /= 10;

    int cents = number % 10;

    cout << "The sum of the digits is " << unit + decs + cents << "\n";
    
    return 0;
}