#include <stdio.h>
#include <ctype.h>

int main(void) {
    int vowels = 0;
    char c = ' ';

    printf("Enter a sentence: ");
    
    while ((c = getchar()) != '\n') {
        c = toupper(c);

        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        }
    }

    printf("Your sentence contains %d vowels.\n", vowels);
    
    return 0;
}