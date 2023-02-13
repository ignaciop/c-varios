#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float investmentAmount, annualInterestRate, numberOfYears;

    cout << "Enter investment amount: ";
    cin >> investmentAmount;

    cout << "Enter annual interest rate in percentage: ";
    cin >> annualInterestRate;

    cout << "Enter number of years: ";
    cin >> numberOfYears;

    float monthlyInterestRate = (annualInterestRate / 12) / 100;

    float futureInvestmentValue = investmentAmount * pow(1 + monthlyInterestRate, numberOfYears * 12);

    cout << "Accumulated value is $" << futureInvestmentValue << "\n";

    return 0;
}       