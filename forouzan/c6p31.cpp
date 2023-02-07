#include <iostream>
#include <cmath>

int main() {
    double i, l, r, m, p, cnt = 1, tot_interest = 0;

    std::cout << "Enter the principal" << std::endl;
    std::cin >> p; //takes in the amount of the loan

    std::cout << "Enter the interest rate" << std::endl;
    std::cin >> r; //takes in the interest rate

    std::cout << "Enter the length of the loan in months" << std::endl;
    std::cin >> m; //takes in the duration of the loan in months

    r /= 100; //converts the rate into decimal form
    l = (p * (r / 12.0F)) / (1 - (pow((1 + r / 12.0F), -m))); //equation to calculate an amount of a loan
        
    std::cout << "Your payment will be " << l << " dollars" << std::endl;


    while( cnt <= m) { //the loop will continue as long as cnt is less than or equal to the loan duration
        i = 30.4167F * (p * (r / 365)); //this will calculate the interest paid in a given month
        tot_interest += i; //total interest equals what it was plus that interest for the month
        
        std::cout << "Interest charged in month " << cnt << ":  " << i << std::endl;
        std::cout << "" << std::endl;
        
        cnt++; //cnt is incremented by one each time the loop runs
        p -= (l - i); //the principal equals what is was minus the loan after the loan is substracted from interest

        std::cout << "Remaining balance: " << p << std::endl;
        std::cout << "" << std::endl;
    }

    std::cout << "Total interest paid " << tot_interest << " dollars" << std::endl;
        
    return 0;
}