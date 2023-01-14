#include <iostream>
#include <cmath>

int main() {

    int i, num, sum;
    bool set_good = true;
    int point_digit = 0;
    char ch;
    sum = 0;

    std::cout << "Enter IPv4 address (x.x.x.x): ";

    while (point_digit < 3) {
        BEGIN:
        for (i = 2; i >= 0; i--) { // Read the 3 digits of each set.
            ch = std::cin.get();

            if (ch == '.') {
                point_digit++;
                sum = 0;
                goto BEGIN;
            }

            if (ch != '\n') {
                num = ch - '0';
                num *= pow(10, i);
                sum += num;
            } else {
                break;
            }
        }

        if (sum >= 0 && sum <= 255) {
            set_good = true;
        } else {
            set_good = false;
            break;
        }

        sum = 0;
    }
       
    if (set_good) {
        std::cout << "The number is a valid IPv4 address." << std::endl;
    } else {
        std::cout << "The number is not a valid IPv4 address." << std::endl;
    }
    
    return 0;
}