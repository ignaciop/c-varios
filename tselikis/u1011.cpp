#include <iostream>
#include <cstring>
#include <cmath>

int main() {
    const int ARRAY_SIZE = 9;
    char str[ARRAY_SIZE];
    int hex2dec = 0;

    std::cout << "Enter up to eight characters between 0-9 or A-F: ";
    std::cin.getline(str, sizeof(str));
    
    for (int i = 0; i < strlen(str) ; i++) {
        int digit = 0;

        switch (str[i]) {
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
                digit = str[i] - '0';
                break;
            case 'A':
            case 'a':
                digit = 10;
                break;
            case 'B':
            case 'b':
                digit = 11;
                break;
            case 'C':
            case 'c':
                digit = 12;
                break;
            case 'D':
            case 'd':
                digit = 13;
                break;
            case 'E':
            case 'e':
                digit = 14;
                break;
            case 'F':
            case 'f':
                digit = 15;
                break;
            default:
                break;
        }

        hex2dec += digit * pow(16, strlen(str) - 1 - i);
    }

    std::cout << hex2dec << std::endl;
        
    return 0;
}