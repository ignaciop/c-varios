#include <iostream>

using namespace std;

int main() {
    const int QUARTERS = 25;
    const int DIMES = 10;
    const int NICKELS = 5;

    int q, d, n;

    cout << "Number of quarters: ";
    cin >> q;

    cout << "Number of dimes: ";
    cin >> d;

    cout << "Number of nickels: ";
    cin >> n;

    int pennies = q * QUARTERS + d * DIMES + n * NICKELS;

    cout << "You have " << pennies << " pennies." << endl;

    return 0;
}