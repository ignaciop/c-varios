#include <stdio.h>
#include <ctype.h>

int main(void) {
    char ch1 = ' ', ch2 = ' ';

    printf("%s", "Enter two characters representing a 2-digit hex number: ");
    scanf("%c %c", &ch1, &ch2);

    int value1 = 0;

    switch (toupper(ch1)) {
    case 'A':
        value1 = 10;
        break;
    case 'B':
        value1 = 11;
        break;
    case 'C':
        value1 = 12;
        break;
    case 'D':
        value1 = 13;
        break;
    case 'E':
        value1 = 14;
        break;
    case 'F':
        value1 = 15;
        break;
    default:
        value1 = ch1 - '0';
        break;
    }

    int value2 = 0;

    switch (toupper(ch2)) {
    case 'A':
        value2 = 10;
        break;
    case 'B':
        value2 = 11;
        break;
    case 'C':
        value2 = 12;
        break;
    case 'D':
        value2 = 13;
        break;
    case 'E':
        value2 = 14;
        break;
    case 'F':
        value2 = 15;
        break;
    default:
        value2 = ch2 - '0';
        break;
    }

    int number = value1 * 16 + value2;

    printf("0x%c%c = %d\n", ch1, ch2, number);
    
    return 0;
}