#include <iostream>

int main() {
    double sales = 8.6E6;
    double percentage = 0.58F;

    double ec_sales = sales * percentage;

    std::cout << "The East Cost division will generate $" << ec_sales
                << " in sales this year." << std::endl;

    return 0;
}