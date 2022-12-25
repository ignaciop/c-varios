#include <iostream>

using std::cout;
using std::cin;

int main() {
    int i, div;
    double d;

    cout << "Enter positives float and int (#0): ";
    cin >> d >> i;

    div = d/i; /* Suppose that the input values are 5.67 and 3. Since div
                is declared as integer it becomes 1. */
    
    cout << d - div*i << '\n';

    return 0;
}