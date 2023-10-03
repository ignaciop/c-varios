#include <stdio.h>

#define ROWS 12
#define COLS 12

int main(void) {
    char characters[ROWS][COLS] = {{'0'}};

    char *p_char = characters[0];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            *(p_char + i + j) = 'X';
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", *(p_char + i + j));
        }

        printf("\n");
    }

    p_char = NULL;
    
    return 0;
}