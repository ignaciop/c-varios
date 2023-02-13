#include <iostream>

using namespace std;

int main() {
    float subtotal;
    float gratuity_rate;

    cout << "Enter the subtotal and a gratuity rate: ";
    cin >> subtotal >> gratuity_rate;

    float gratuity = gratuity_rate * subtotal / 100;
    float total = subtotal + gratuity;

    cout << "The gratuity is $" << gratuity << " and total is $" << total << "\n";

    return 0;
}