#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 4

int main(void) {
    srand(time(NULL));

    int random_numbers[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            random_numbers[i][j] = rand();
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%10d ", random_numbers[i][j]);
        }

        printf("\b\n");
    }

    return 0;
}