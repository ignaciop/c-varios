#include <iostream>

using namespace std;

int main() {
    double merchandise_cost, employee_salary, yearly_rent, electricity_cost, total_expenses, desired_profit, marked_up_price;

    cout << "Enter the total cost of the merchandise: ";
    cin >> merchandise_cost;

    cout << "Enter the yearly salary of the employees (including yourself): ";
    cin >> employee_salary;

    cout << "Enter the yearly rent: ";
    cin >> yearly_rent;

    cout << "Enter the estimated electricity cost for the store: ";
    cin >> electricity_cost;

    total_expenses = merchandise_cost + employee_salary + yearly_rent + electricity_cost;

    cout << "Enter the desired net profit percentage (in decimal form): ";
    cin >> desired_profit;

    marked_up_price = (total_expenses / (1 - desired_profit)) * 1.15 / merchandise_cost;

    cout << "The merchandise should be marked up by " << marked_up_price << " times the cost price." << endl;

    return 0;
}