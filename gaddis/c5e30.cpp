#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    const int MONTHS = 12;
    
    float starting_balance,
          annual_interest_rate,
          amount_deposited,
          amount_withdrawn,

          interest_rate,
          monthly_interest_rate,
          
          balance,
          total_deposits,
          total_withdrawn,
          total_interest_earned;

    int months_since_established;

    std::cout << "\nEnter annual interest rate: ";

    while (!(std::cin >> annual_interest_rate)) {
        std::cout << "Error: a number must be entered... ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    std::cout << "Enter starting balance: ";

    while (!(std::cin >> starting_balance)) {
        std::cout << "Error: a number must be entered... ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    balance = starting_balance;

    std::cout << "Enter # of months passed since account "
         << "was established: ";

    while (!(std::cin >> months_since_established) || 
             months_since_established < 0) {
        std::cout << "Error: a number must be entered... ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    monthly_interest_rate = annual_interest_rate / MONTHS;

    for (int i = 0; i < months_since_established; i++) {
        std::cout << "Enter the amount deposited for month " 
             << (i + 1) << ": ";

        while (!(std::cin >> amount_deposited) || 
                 amount_deposited < 0) {
            std::cout << "Error: a positive number must be "
                 << "entered.\nEnter the amount deposited "
                 << "for month " 
                 << (i + 1) << ": ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        total_deposits += amount_deposited;
        balance += amount_deposited;

        if (balance < 0)
            break;

        std::cout << "Enter the amount withdrawn for month " 
             << (i + 1) << ": ";

        while (!(std::cin >> amount_withdrawn) || 
                 amount_withdrawn < 0) {
            std::cout << "Error: a positive number must be "
                 << "entered. Enter the amount withdrawn "
                 << "for month " 
                 << (i + 1) << ": ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        total_withdrawn += amount_withdrawn;
        balance -= amount_withdrawn;

        if (balance < 0)
            break;

        interest_rate = (monthly_interest_rate * balance);
        balance += interest_rate;

        if (balance < 0)
            break;

        total_interest_earned += (interest_rate);
    } // for loop end

    if (balance < 0) {
        std::cout << "I'm sorry, your account has been closed\n"; 
        std::cout << "due to having a negative balance." << std::endl;
    } else {
        std::ofstream balances;
        balances.open("data/balances.txt");

        if (balances) {
            balances << std::setprecision(2) << std::fixed << '\n';
            balances << "Starting balance            = $" 
             << starting_balance << "\n";

            balances << "Ending balance              = $" 
             << balance << "\n";

            balances << "Total amount in deposits    = $" 
             << total_deposits << "\n";

            balances << "Total amount in withdrawals = $" 
             << total_withdrawn << "\n";

            balances << "Total interest earned       = $" 
             << total_interest_earned << "\n";
        
            std::cout << "File saved." << std::endl;
        } else {
            std::cout << "Error creating the file." << std::endl;
        }
    }

    return 0;
}