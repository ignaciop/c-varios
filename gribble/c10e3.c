#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
}

int main() {
    FILE *file;
    char str1[100], str2[100], str3[100];

    // Get input from the user
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Enter the third string: ");
    scanf("%s", str3);

    // Convert to uppercase and reverse the strings
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

    reverseString(str1);
    reverseString(str2);
    reverseString(str3);

    // Open the file for writing
    file = fopen("c10e3.txt", "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Write the reversed strings to the file
    fprintf(file, "Reversed and Uppercase Strings:\n");
    fprintf(file, "1. %s\n", str1);
    fprintf(file, "2. %s\n", str2);
    fprintf(file, "3. %s\n", str3);

    // Close the file
    fclose(file);

    printf("Strings written to output.txt successfully.\n");

    return 0;
}