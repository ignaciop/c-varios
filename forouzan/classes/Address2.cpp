#include "Address2.h"

Address::Address(std::string s) {
    unsigned int a = 0;
    int i = 0;
    int mul = 1;

    for (int j = s.length() - 1; j >= 0; j--) {
        if (s[j] == '.') {
            a += i * mul;

            mul *= 256;

            i = 0;
        } else {
            i = i * 10 + (s[j] - '0');
        }
    }

    a += i;

    address = a;
}

// function to convert to binary format
std::string Address::toBinary() {
    std::string binary = "";

    for (int i = 0; i < 32; i++) {
        binary = ((address >> i) & 1 ? "1" : "0") + binary;

        if ((i + 1) % 8 == 0 && i != 31) {
            binary = "." + binary;
        }
    }

    return binary;
}

// function to convert to dotted decimal format
std::string Address::toDottedDecimal() {
    std::string decimal = "";

    for (int i = 0; i < 4; i++) {
        decimal = std::to_string(address % 256) + decimal;

        address /= 256;

        if (i != 3) {
            decimal = "." + decimal;
        }
    }

    return decimal;
}