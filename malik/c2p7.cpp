#include <iostream>

using namespace std;

int main() {
    double number;

    cout << "Enter a decimal number: ";
    cin >> number;

    int rounded_number = static_cast<int>(number + 0.5);

    cout << "Rounded number: " << rounded_number << endl;
    
    return 0;
}