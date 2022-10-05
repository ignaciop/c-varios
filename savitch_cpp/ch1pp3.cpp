#include <iostream>

using namespace std;

int main() {
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;

    cout << "Enter quarters: ";
    cin >> quarters;

    cout << "Enter dimes: ";
    cin >> dimes;

    cout << "Enter nickels: ";
    cin >> nickels;

    int cents = quarters*25 + dimes*10 + nickels*5;

    cout << "Your coins are worth " << cents << " cents.\n";

    return 0;
}