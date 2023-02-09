#include <iostream>
#include <string>
#include <cmath>

int octal_to_decimal(std::string oct) {
    int dec = 0, power = 0;
    
    for (int i = oct.length() - 1; i >= 0; i--) {
        int num = oct[i] - '0';
        
        dec += num * pow(8, power);
        
        power++;
    }

    return dec;
}

int main() {
    std::string octal_num {};
    std::cout << "Enter an octal string: ";
    getline(std::cin, octal_num);

    int decimal_num = octal_to_decimal(octal_num);
    
    std::cout << "Decimal equivalent: " << decimal_num << std::endl;

    return 0;
}