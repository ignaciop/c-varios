#include <iostream>

int main() {
    std::cout << "Enter current year: ";
    int current_year = 0;
    std::cin >> current_year;

    std::cout << "Enter year of birth: ";
    int birth_year = 0;
    std::cin >> birth_year;

    int age = current_year - birth_year;

    int age_dec = age / 10;
    int age_uni = age % 10;

    switch (age_dec) {
        case 9:
            std::cout << "ninety";
            break;
        case 8:
            std::cout << "eighty";
            break;
        case 7:
            std::cout << "seventy";
            break;
        case 6:
            std::cout << "sixty";
            break;
        case 5:
            std::cout << "fifty";
            break;
        case 4:
            std::cout << "fourty";
            break;
        case 3:
            std::cout << "thirty";
            break;
        case 2:
            std::cout << "twenty";
            break;
        case 1:
            if (age_uni == 0) {
                std::cout << "ten";
            } else if (age_uni == 1) {
                std::cout << "eleven";
            } else if (age_uni == 2) {
                std::cout << "twelve";
            } else if (age_uni == 3) {
                std::cout << "thirtheen";
            } else if (age_uni == 4) {
                std::cout << "fourteen";
            } else if (age_uni == 5) {
                std::cout << "fifteen";
            } else if (age_uni == 6) {
                std::cout << "sixteen";
            } else if (age_uni == 7) {
                std::cout << "seventeen";
            } else if (age_uni == 8) {
                std::cout << "eighteen";
            } else {
                std::cout << "nineteen";
            }
            break;
        default:
            break;
    }

    if (age_dec != 1) {
        switch (age_uni) {
            case 9:
                std::cout << "-nine";
                break;
            case 8:
                std::cout << "-eight";
                break;
            case 7:
                std::cout << "-seven";
                break;
            case 6:
                std::cout << "-six";
                break;
            case 5:
                std::cout << "-five";
                break;
            case 4:
                std::cout << "-four";
                break;
            case 3:
                std::cout << "-three";
                break;
            case 2:
                std::cout << "-two";
                break;
            case 1:
                std::cout << "-one";
                break;
            default:
                break;
        }
    }
    
    std::cout << std::endl;

    return 0;
}