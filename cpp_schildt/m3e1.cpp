#include <iostream>

using namespace std;

int main() {
    char c = ' ';
    int sum_periods = 0;

    cout << "Type characters ($ to quit): ";

    while (c != '$') {
        cin >> c;

        if (c == '.') {
            sum_periods++;
        }
    }

    cout << "Periods typed: " << sum_periods << "\n";

    return 0;
}