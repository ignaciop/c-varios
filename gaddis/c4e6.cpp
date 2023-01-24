#include <iostream>

int main() {
    const double PENNY = 0.01F;
    const double NICKEL = 0.05F;
    const double DIME = 0.10F;
    const double QUARTER = 0.25F;

    std::cout << "Enter the number of pennies: ";
    int pennies = 0;
    std::cin >> pennies;

    std::cout << "Enter the number of nickels: ";
    int nickels = 0;
    std::cin >> nickels;

     std::cout << "Enter the number of dimes: ";
    int dimes = 0;
    std::cin >> dimes;

     std::cout << "Enter the number of quarters: ";
    int quarters = 0;
    std::cin >> quarters;

    double money = pennies * PENNY + dimes * DIME + nickels * NICKEL + quarters * QUARTER;

    if (money == 1.00) {
        std::cout << "Congratulations! You won the game!" << std::endl;
    } else if (money < 1.00) {
        std::cout << "You entered less than one dollar!" << std::endl;
    } else {
        std::cout << "You entered more than one dollar!" << std::endl;
    }
    
    return 0;
}