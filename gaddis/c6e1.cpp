#include <iostream>
#include <iomanip>

double calculateRetail(double cost, double markup_percentage);

int main() {
    std::cout << "Enter the item's wholesale cost: ";
    double cost = 0.0;
    std::cin >> cost;

    std::cout << "Enter its markup percentage: ";
    double markup_percentage = 0.0;
    std::cin >> markup_percentage;
    
    double retail_price = calculateRetail(cost, markup_percentage);

    std::cout << "If an item's wholesale cost is $" << std::fixed
                << std::setprecision(2) << cost << " and its markup percentage is "
                << markup_percentage << " percent then the item's retail price is $"
                << retail_price << std::endl;

    return 0;
}

double calculateRetail(double cost, double markup_percentage) {
    double rate = markup_percentage / 100;
    
    return (cost + cost * rate);
}