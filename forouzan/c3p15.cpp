#include <iostream>

int main() {
    const int HOURS_PER_WEEK = 40;
    const double EXTRA_PERCENTAGE = 0.6F;

    std::cout << "Enter the weekly rate: ";
    double rate = 0.0;
    std::cin >> rate;

    std::cout << "Enter the extra hours worked: ";
    double extra_hours = 0.0;
    std::cin >> extra_hours;

    double pay_per_hour = rate / HOURS_PER_WEEK;
    double extra_pay = extra_hours * (pay_per_hour * EXTRA_PERCENTAGE);

    double total_pay = rate + extra_pay;

    std::cout << "Last week you worked " << extra_hours << " extra hours."
                << " Your weekly rate is $" << rate << ". Your total salary is $"
                    << total_pay << std::endl;

    return 0;
}