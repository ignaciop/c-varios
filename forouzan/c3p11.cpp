#include <iostream>

int main() {
    const int DOLLARS = 100;
    const int QUARTERS = 25;
    const int DIMES = 10;
    const int NICKELS = 5;

    std::cout << "Enter the amount of dollars and cents of item cost: ";
    int dollarsItem = 0, centsItem = 0;
    std::cin >> dollarsItem >> centsItem;

    int totalCentsItems = dollarsItem * 100 + centsItem;

    std::cout << "Enter the amount of dollars and cents of the customer pay: ";
    int dollarsPay = 0, centsPay = 0;
    std::cin >> dollarsPay >> centsPay;

    int totalCentsPay = dollarsPay * 100 + centsPay;

    int changeDollars = dollarsPay - dollarsItem;
    int changeCents = centsPay - centsItem;

    int totalCentsChange = changeDollars * 100 + changeCents;
    
    int totalCentsItemDollars = totalCentsItems / DOLLARS;
    int remaining_cents = totalCentsItems % DOLLARS;
    int totalCentsItemQuarters = remaining_cents / QUARTERS;
    remaining_cents %= QUARTERS;
    int totalCentsItemDimes = remaining_cents / DIMES;
    remaining_cents %= DIMES;
    int totalCentsItemNickels = remaining_cents / NICKELS;
    int totalCentsItemPennies = remaining_cents % NICKELS;

    int totalCentsPayDollars = totalCentsPay / DOLLARS;
    remaining_cents = totalCentsPay % DOLLARS;
    int totalCentsPayQuarters = remaining_cents / QUARTERS;
    remaining_cents %= QUARTERS;
    int totalCentsPayDimes = remaining_cents / DIMES;
    remaining_cents %= DIMES;
    int totalCentsPayNickels = remaining_cents / NICKELS;
    int totalCentsPayPennies = remaining_cents % NICKELS;

    int totalCentsChangeDollars = totalCentsChange / DOLLARS;
    remaining_cents = totalCentsChange % DOLLARS;
    int totalCentsChangeQuarters = remaining_cents / QUARTERS;
    remaining_cents %= QUARTERS;
    int totalCentsChangeDimes = remaining_cents / DIMES;
    remaining_cents %= DIMES;
    int totalCentsChangeNickels = remaining_cents / NICKELS;
    int totalCentsChangePennies = remaining_cents % NICKELS;

    std::cout << "\nPurchase is $: " << dollarsItem << "." << centsItem << std::endl;
    std::cout << "Or: " << totalCentsItemDollars << " dollars, " << totalCentsItemQuarters
                << " quarters, " << totalCentsItemDimes << " dimes, "
                    << totalCentsItemNickels << " nickels and " << totalCentsItemPennies
                        << " pennies." << std::endl;

    std::cout << "\nCustomer pay is $: " << dollarsPay << "." << centsPay << std::endl;
    std::cout << "Or: " << totalCentsPayDollars << " dollars, " << totalCentsPayQuarters
                << " quarters, " << totalCentsPayDimes << " dimes, "
                    << totalCentsPayNickels << " nickels and " << totalCentsPayPennies
                        << " pennies." << std::endl;

    std::cout << "\nChange is $: " << changeDollars << "." << changeCents << std::endl;
    std::cout << "Or: " << totalCentsChangeDollars << " dollars, " << totalCentsChangeQuarters
                << " quarters, " << totalCentsChangeDimes << " dimes, "
                    << totalCentsChangeNickels << " nickels and " << totalCentsChangePennies
                        << " pennies." << std::endl;

    return 0;
}