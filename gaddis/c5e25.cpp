#include <iostream>
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
        std::cout << std::setprecision(2) << std::fixed << std::endl;
        std::cout << "Starting balance            = $" 
             << starting_balance << std::endl;

        std::cout << "Ending balance              = $" 
             << balance << std::endl;

        std::cout << "Total amount in deposits    = $" 
             << total_deposits << std::endl;

        std::cout << "Total amount in withdrawals = $" 
             << total_withdrawn << std::endl;

        std::cout << "Total interest earned       = $" 
             << total_interest_earned  
             << std::endl;
    }
    
    return 0;
}