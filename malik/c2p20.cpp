#include <iostream>

using namespace std;

int main() {
    double fixedCommission, percentCommission, purchasingCost, minAdd, maxAdd, minSellingPrice, maxSellingPrice, minCommission, maxCommission;

    // Prompt user to enter fixed commission
    cout << "Enter the salesperson's fixed commission: ";
    cin >> fixedCommission;

    // Prompt user to enter percentage of commission
    cout << "Enter the percentage of the commission: ";
    cin >> percentCommission;
    percentCommission /= 100;

    // Prompt user to enter purchasing cost of car
    cout << "Enter the purchasing cost of the car: ";
    cin >> purchasingCost;

    // Prompt user to enter minimum amount to be added to purchasing cost
    cout << "Enter the minimum amount to be added to the purchasing cost: ";
    cin >> minAdd;

    // Prompt user to enter maximum amount to be added to purchasing cost
    cout << "Enter the maximum amount to be added to the purchasing cost: ";
    cin >> maxAdd;

    // Calculate minimum selling price
    minSellingPrice = purchasingCost + minAdd;

    // Calculate maximum selling price
    maxSellingPrice = purchasingCost + maxAdd;

    // Calculate minimum commission
    minCommission = fixedCommission + (percentCommission * (minSellingPrice - purchasingCost));

    // Calculate maximum commission
    maxCommission = fixedCommission + (percentCommission * (maxSellingPrice - purchasingCost));

    // Output minimum and maximum selling price of car
    cout << "Minimum selling price of car: " << minSellingPrice << endl;
    cout << "Maximum selling price of car: " << maxSellingPrice << endl;

    // Output salesperson's commission range
    cout << "Salesperson's commission range: " << minCommission << " to " << maxCommission << endl;

    return 0;
}