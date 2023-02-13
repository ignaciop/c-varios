#include <iostream>

using namespace std;

int main() {
    const double LITERS_PER_CARTON = 3.78;

    double total_milk, total_cartons, cost_per_liter, profit_per_carton;

    cout << "Enter the liters of milk produced: ";
    cin >> total_milk;

    cout << "Enter the cost per liter of milk produced: ";
    cin >> cost_per_liter;

    cout << "Enter the profit per carton of milk produced: ";
    cin >> profit_per_carton;

    total_cartons = total_milk / LITERS_PER_CARTON;

    int cartons_needed = static_cast<int>(total_cartons + 0.5);

    cout << "Cost of producing milk  : $" << total_milk * cost_per_liter << endl;
    cout << "Profit of producing milk: $" << cartons_needed * profit_per_carton << endl;

    return 0;
}