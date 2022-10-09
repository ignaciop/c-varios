#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const float monthly_interest_rate = 0.05/12;
    float monthly_saving_amount;

    cout << "Enter the monthly saving amount: ";
    cin >> monthly_saving_amount;

    float rate = (1 + monthly_interest_rate);
    float sixth_month = (100 * rate) 
                            * (1 + rate + pow(rate, 2) + pow(rate, 3)
                                + pow(rate, 4) + pow(rate, 5));
    
    cout << "After the sixth month, the account value is $" << sixth_month << "\n";
 
    return 0;
}       