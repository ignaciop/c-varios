#include <stdio.h>
#include <ctype.h>

int charToDigit(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        return tolower(c) - 'a' + 10;
    }

    return -1; // Invalid character
}

int main(void) {
    int base, value = 0;
    char c;
    
    printf("%s", "Enter the base: ");
    scanf("%d", &base);
    
    if (base < 2 || base > 36) {
        printf("Invalid base. Please enter a base between 2 and 36.\n");

        return 1;
    }
    
    printf("Enter a positive integer in base %d: ", base);
    
    // Skip over any leading non-valid characters
    while (1) {
        scanf("%c", &c);

        int digit = charToDigit(c);

        if (digit >= 0 && digit < base) {
            value = digit;

            break;
        }
    }
    
    // Read valid characters until an invalid one is encountered
    while (1) {
        scanf("%c", &c);

        int digit = charToDigit(c);
        
        if (digit >= 0 && digit < base) {
            value = value * base + digit;
        } else {
            break;
        }
    }
    
    printf("Decimal value: %d\n", value);
    
    return 0;
}