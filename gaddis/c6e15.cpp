#include <iostream>
#include <cmath>
#include <iomanip>

void getData(int &spools_ordered, int &spools_stock, double &charges);
void displayData(int spools_ordered, int spools_stock, double charges);

int main() {
    
    int spools_ordered = 0;
    int spools_stock = 0;
    double charges = 0.0;

    getData(spools_ordered, spools_stock, charges);

    displayData(spools_ordered, spools_stock, charges);
    
    return 0;
}

void getData(int &spools_ordered, int &spools_stock, double &charges) {
    const double FIXED_CHARGE = 10.0F;

    do {
        std::cout << "How many spools were ordered? ";
        std::cin >> spools_ordered;
    } while (spools_ordered < 0);

    do {
        std::cout << "How many spools are in stock? ";
        std::cin >> spools_stock;
    } while (spools_stock < 0);

    do {
        std::cout << "Any shipping and handling rate above $10? ";
        std::cin >> charges;
    } while (charges < 0);

    charges += FIXED_CHARGE;
}

void displayData(int spools_ordered, int spools_stock, double charges = 10.0) {
    double SPOOLS_UNIT_PRICE = 100.0F;

    int spools_ready = spools_stock - spools_ordered;
    int spools_backorder = 0;

    if (spools_ordered > spools_stock) {
        spools_backorder = fabs(spools_ready);
        spools_ready = spools_stock; 
    }

    double selling_price = spools_ready * SPOOLS_UNIT_PRICE;
    double shipping_price = charges * spools_ready;
    double total = selling_price + shipping_price;

    std::cout << "Order and shipping data" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Spools ready to ship:                              " << std::right 
                << spools_ready << std::endl;
    std::cout << "Spools on backorder:                               " << std::right
                << spools_backorder << std::endl;
    std::cout << "Total price of the items ready to ship:            " 
                << std::fixed << std::setprecision(2) << "$" << std::right
                    << selling_price << std::endl;
    std::cout << "Total shipping and handling charges ready to ship: "  
                << std::fixed << "$" << std::right << shipping_price << std::endl;
    std::cout << "Total of items ready to ship:                      " << "$"
                << std::right << std::fixed << total << std::endl;
    std::cout << "------------------------" << std::endl;
}