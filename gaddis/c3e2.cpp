#include <iostream>
#include <iomanip>

int main() {
    const int CLASS_A_COST = 15;
    const int CLASS_B_COST = 12;
    const int CLASS_C_COST = 9;

    std::cout << "How many class A ticket were sold? ";
    int a_tickets = 0;
    std::cin >> a_tickets;

    std::cout << "How many class B ticket were sold? ";
    int b_tickets = 0;
    std::cin >> b_tickets;

    std::cout << "How many class C ticket were sold? ";
    int c_tickets = 0;
    std::cin >> c_tickets;

    int income = a_tickets * CLASS_A_COST + b_tickets * CLASS_B_COST + c_tickets * CLASS_C_COST;

    std::cout << "Total income: $" << std::fixed << std::setprecision(2)
                 << static_cast<double>(income) << std::endl;
    
    return 0;
}