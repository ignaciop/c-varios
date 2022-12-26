#include <iostream>

using std::cout;
using std::cin;

int main() {
    int i;
    float j;

    cout << "Enter positive number: ";
    cin >> i;

    i = i+50;
    j = i/100.0; /* Divide by 10.0 and not by 10, so that the fractional
                part is not truncated. */
    i = static_cast<int>(j) * 100; // Cut off the decimal digit.

    cout << i << '\n';
    
    return 0;
}