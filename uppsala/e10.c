#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int num_strings = 0;
    int max_str_length = 0;
    

    printf("Number of strings: ");
    scanf("%d", &num_strings);

    printf("Maximum string length: ");
    scanf("%d", &max_str_length);

    // Allocate memory for an array of strings
    char **strings = (char **)malloc(num_strings * sizeof(char *));

    if (strings == NULL) {
        perror("Memory allocation error");

        return 1;
    }

    for (int i = 0; i < num_strings; i++) {
        strings[i] = (char *)malloc((max_str_length + 1) * sizeof(char));

        if (strings[i] == NULL) {
            perror("Memory allocation error");

            return 1;
        }

        printf("Give string %d: ", i);
        scanf("%s", strings[i]);
    }

    // Perform bubble sort to alphabetically sort the strings
    for (int i = 0; i < num_strings - 1; i++) {
        for (int j = 0; j < num_strings - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                // Swap the strings
                char *temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }

    // Print the sorted strings
    printf("Input when sorted:\n");

    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
        strings[i] = NULL;
    }

    free(strings);
    strings = NULL;

    return 0;
}