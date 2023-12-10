#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    // Declare three strings with enough space to store user input
    char str1[100], str2[100], str3[100];

    // Ask the user to enter three strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    printf("Enter the third string: ");
    fgets(str3, sizeof(str3), stdin);

    // Convert strings to uppercase and print them in reverse order
    printf("\nStrings in reverse uppercase:\n");
    
    // String 3
    for (int i = strlen(str3) - 1; i >= 0; i--) {
        printf("%c", toupper(str3[i]));
    }
    printf("\n");

    // String 2
    for (int i = strlen(str2) - 1; i >= 0; i--) {
        printf("%c", toupper(str2[i]));
    }
    printf("\n");

    // String 1
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        printf("%c", toupper(str1[i]));
    }
    
    printf("\n");

    return 0;
}