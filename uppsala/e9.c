#include <stdio.h>

#define ARRAY_SIZE 256

void append(char *str1, char *str2);

int main(void) {
    char w1[ARRAY_SIZE], w2[ARRAY_SIZE];
    
    printf("Enter first word: ");
    scanf("%s", w1);

    printf("Enter second word: ");
    scanf("%s", w2);

    append(w1, w2);
    printf("Result of append: %s\n", w1);

    return 0;
}

void append(char *str1, char *str2) {   
    while ( *str1 != '\0' )
        ++str1; // Find the end of string s1.

    while (( *str1++ = *str2++ ) != '\0' );
        // The first character from s2
        // replaces the terminator of s1.
}