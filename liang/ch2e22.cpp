#include <iostream>

using namespace std;

int main() {
    float balance, annualInterestRate;

    cout << "Enter balance and interest rate (e.g., 3 for 3%): ";
    cin >> balance >> annualInterestRate;

    float interest = balance * (annualInterestRate / 1200);

    cout << "The interest is " << interest << "\n";

    return 0;
}       