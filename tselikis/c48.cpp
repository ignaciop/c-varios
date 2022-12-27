#include <iostream>

using std::cout;
using std::cin;

int main() {
    unsigned char data, ones, bit1, bit2, bit3, bit4, bit5, parity_bit;
    ones = 0;

    cout << "Enter bit1: ";
    cin >> bit1;

    if(bit1 == 1)
        ones++;

    cout << "Enter bit2: ";
    cin >> bit2;

    if(bit2 == 1)
        ones++;

    cout << "Enter bit3: ";
    cin >> bit3;

    if(bit3 == 1)
        ones++;

    cout << "Enter bit4: ";
    cin >> bit4;

    if(bit4 == 1)
        ones++;

    cout << "Enter bit5: ";
    cin >> bit5;

    if(bit5 == 1)
        ones++;

    if(ones & 1) // It means that the number of 1s is odd.
        parity_bit = 1;
    else
        parity_bit = 0;

    data = (bit1 << 6) + (bit2 << 5) + (bit3 << 4) + (bit4 << 3) + (bit5
            << 2) + (parity_bit << 1) + 1; // The last 1 represents the stop_bit.

    cout << (int)data << '\n'; /* The type cast is used to output the
integer value. */

    return 0;
}