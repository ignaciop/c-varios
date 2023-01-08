#include <iostream>

int main() {
    int n = 0;
    int digit = 0;
    int count = 4;

    do {
        std::cout << "Enter a integer up to five digits: ";
        std::cin >> n;
    } while (n < -99999 || n > 99999);

    if (n < 0) {
        std::cout << "minus";
        n = -n;
    }

    int d5 = n / 10000;
    int rest = n % 10000;

    int d4 = rest / 1000;
    rest %= 1000;

    int d3 = rest / 100;
    rest %= 100;

    int d2 = rest / 10;
    int d1 = rest % 10;

    if (d5) {
        digit = d5;
        goto DIGIT_2_WORD;
    }

    FOURTH_DIGIT:
    count--;
    if (d4 || (!d4 && d5)) {
        digit = d4;
        goto DIGIT_2_WORD;
    }

    THIRD_DIGIT:
    count--;
    if (d3 || (!d3 && d4) || (!d4 && d5)) {
        digit = d3;
        goto DIGIT_2_WORD;
    }

    SECOND_DIGIT:
    count--;
    if (d2 || (!d2 && d3) || (!d3 && d4) || (!d4 && d5)) {
        digit = d2;
        goto DIGIT_2_WORD;
    }

    FIRST_DIGIT:
    count--;
    if (d1 || (!d1 && d2) || (!d2 && d3) || (!d3 && d4) || (!d4 && d5)) {
        digit = d1;
        goto DIGIT_2_WORD;
    }

    DIGIT_2_WORD:
    switch (digit) {
        case 1:
            std::cout << " one ";
            break;
        case 2:
            std::cout << " two ";
            break;
        case 3:
            std::cout << " three ";
            break;
        case 4:
            std::cout << " four ";
            break;
        case 5:
            std::cout << " five ";
            break;
        case 6:
            std::cout << " six ";
            break;
        case 7:
            std::cout << " seven ";
            break;
        case 8:
            std::cout << " eight ";
            break;
        case 9:
            std::cout << " nine ";
            break;
        case 0:
            std::cout << " zero ";
            break;
        default:
            break;
    }

    switch (count) {
        case 4:
            goto FOURTH_DIGIT;
            break;
        case 3:
            goto THIRD_DIGIT;
            break;
        case 2:
            goto SECOND_DIGIT;
            break;
        case 1:
            goto FIRST_DIGIT;
            break;
        default:
            break;
    }
   
    std::cout << "\b." << std::endl;
    
    return 0;
}