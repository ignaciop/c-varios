#include <iostream>

int main() {
    float total_drives = 64.0F;
    float cost_per_drive = 8.0F;
    float total_cost = total_drives * cost_per_drive;
    float sell_price = total_cost + total_cost * 0.35;

    std::cout << "Sell price must be $" << sell_price << std::endl;

    return 0;
}