#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main(void) {
    FILE *file;
    char filename[] = "c10e4.txt"; // Replace with your file name

    // Open the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char strings[3][MAX_STRING_LENGTH];

    // Read three strings from the file
    for (int i = 0; i < 3; i++) {
        if (fscanf(file, "%s", strings[i]) != 1) {
            printf("Error reading string %d from file\n", i + 1);
            fclose(file);
            return 1;
        }

        // Reverse each string
        reverseString(strings[i]);
    }

    // Print reversed strings
    printf("Reversed Strings:\n");
    
    for (int i = 0; i < 3; i++) {
        printf("%s\n", strings[i]);
    }

    // Close the file
    fclose(file);

    return 0;
}