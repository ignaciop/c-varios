#include <iostream>

int main() {
    const int BASE_PRICE = 100;
    const float DISCOUNT = 0.05F;

    std::cout << "Enter total cost: ";
    float cost;
    std::cin >> cost;

    std::cout << "Amount to pay: " << (cost < BASE_PRICE)*cost + 
                (cost >= BASE_PRICE)*(cost - DISCOUNT * cost) << std::endl;

    return 0;
}