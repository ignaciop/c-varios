#include <iostream>

int main() {
    float meal_charge = 44.50F;
    float meal_tax = meal_charge * 0.0675;
    float tip = (meal_charge + meal_tax) * 0.15;

    float total_bill = meal_charge + meal_tax + tip;

    std::cout << "Meal cost: $" << meal_charge << std::endl;
    std::cout << "Tax amount: $" << meal_tax << std::endl;
    std::cout << "Tip amount: $" << tip << std::endl;
    std::cout << "Total bill: $" << total_bill << std::endl;

    return 0;
}