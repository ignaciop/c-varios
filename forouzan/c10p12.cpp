#include <iostream>
#include <string>
#include <cmath>

int decFormat(char hexa) {
    int res = 0;
    
    switch (hexa) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            res = hexa - '0';
            break;
        case 'A':
        case 'a':
            res = 10;
            break;
        case 'B':
        case 'b':
            res = 11;
            break;
        case 'C':
        case 'c':
            res = 12;
            break;
        case 'D':
        case 'd':
            res = 13;
            break;
        case 'E':
        case 'e':
            res = 14;
            break;
        case 'F':
        case 'f':
            res = 15;
            break;
    }

    return res;
}

int hex_to_decimal(std::string hexa) {
    int dec = 0, power = 0;
    
    for (int i = hexa.length() - 1; i >= 0; i--) {
        int num = decFormat(hexa[i]);
        
        dec += num * pow(16, power);
        
        power++;
    }

    return dec;
}

int main() {
    std::string hexa_num {};
    std::cout << "Enter an hexadecimal string: ";
    getline(std::cin, hexa_num);

    int decimal_num = hex_to_decimal(hexa_num);
    
    std::cout << "Decimal equivalent: " << decimal_num << std::endl;

    return 0;
}