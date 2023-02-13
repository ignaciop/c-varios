#include <iostream>

using namespace std;

int main() {
    cout << "Enter the amount of the loan: ";
    float amount;
    cin >> amount;

    if (amount < 1e4 || amount > 5e6) {
        cout << "Loan cannot be provided.\n";
    } else {
        float rate;
        float dollar_to_lakh = amount / 1e5;

        if (dollar_to_lakh > 0.1 && dollar_to_lakh <= 1) {
            rate = 15;
        } else if (dollar_to_lakh > 1 && dollar_to_lakh <= 5) {
            rate = 13.5;
        } else if (dollar_to_lakh > 5 && dollar_to_lakh <= 10) {
            rate = 12.5;
        } else {
            rate = 11.0;
        }

        cout << "Rate of interest: " << rate << "\n";
    }

    return 0;
}