#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_multiplication_table(int rows, int cols, FILE *output) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            fprintf(output, "%4d", i * j);
        }

        fprintf(output, "\n");
    }
}

int main(int argc, char *argv[]) {
    int rows, cols;
    FILE *input = stdin;
    FILE *output = stdout;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-in") == 0 && i + 1 < argc) {
            input = fopen(argv[i + 1], "r");

            if (input == NULL) {
                perror("Error opening input file");

                return 1;
            }
        } else if (strcmp(argv[i], "-out") == 0 && i + 1 < argc) {
            output = fopen(argv[i + 1], "w");

            if (output == NULL) {
                perror("Error opening output file");

                return 1;
            }
        }
    }
    
    if (fscanf(input, "%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Invalid input. Please provide two integers for rows and columns.\n");
        
        return 1;
    }

    print_multiplication_table(rows, cols, output);

    if (input != stdin) {
        fclose(input);
    }

    if (output != stdout) {
        fclose(output);
    }

    return 0;
}