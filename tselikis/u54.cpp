#include <iostream>

int main() {
    const float SMALL_COST = 0.008F;
    const float BIG_COST = 0.02F;
    const float DISCOUNT_1 = 0.08F;
    const float DISCOUNT_2 = 0.2F;

    std::cout << "Enter number of small bottles: " << std::endl;
    int small_bottles = 0;
    std::cin >> small_bottles;

    std::cout << "Enter number of big bottles: " << std::endl;
    int big_bottles = 0;
    std::cin >> big_bottles;

    float total_cost = small_bottles * SMALL_COST + big_bottles * BIG_COST;

    if (total_cost > 200 || small_bottles + big_bottles > 3000) {
        total_cost -= total_cost * DISCOUNT_1; 
    } else if (total_cost > 600) {
        total_cost -= total_cost * DISCOUNT_2; 
    }

    std::cout << "Total cost: " << total_cost << std::endl;
    
    return 0;
}