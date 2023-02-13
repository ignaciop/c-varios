#include <iostream>

using namespace std;

int main() {
    const double LITERS_PER_CARTON = 3.78;
    const double COST_PER_LITER = 0.38;
    const double PROFIT_PER_CARTON = 0.27;

    double total_milk, total_cartons;

    cout << "Enter the liters of milk produced: ";
    cin >> total_milk;

    total_cartons = total_milk / LITERS_PER_CARTON;

    int cartons_needed = static_cast<int>(total_cartons + 0.5);

    cout << "Cost of producing milk  : $" << total_milk * COST_PER_LITER << endl;
    cout << "Profit of producing milk: $" << cartons_needed * PROFIT_PER_CARTON << endl;

    return 0;
}