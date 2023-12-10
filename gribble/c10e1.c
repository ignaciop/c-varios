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

    // Convert each string to uppercase
    for (int i = 0; i < strlen(str1); i++) {
        str1[i] = toupper(str1[i]);
    }

    for (int i = 0; i < strlen(str2); i++) {
        str2[i] = toupper(str2[i]);
    }

    for (int i = 0; i < strlen(str3); i++) {
        str3[i] = toupper(str3[i]);
    }

    // Print the strings in uppercase
    printf("\nUppercase strings:\n");
    printf("String 1: %s", str1);
    printf("String 2: %s", str2);
    printf("String 3: %s", str3);

    return 0;
}