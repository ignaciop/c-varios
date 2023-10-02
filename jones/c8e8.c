/* randomarray.c - Demonstrates using a multidimensional array */

#include <stdio.h>
#include <stdlib.h>

/* Declare a one-dimensional array with 1000 elements */
int random_array[1000];
int a, b;

int main(void) {
    long int sum = 0;
    /* Fill the array with random numbers. The C library */
    /* function rand() returns a random number. Use one */
    /* for loop for each array subscript. */
    for (a = 0; a < 1000; a++) {
        random_array[a] = rand();
        sum += random_array[a];
    }

    double avg = sum / 1000.0;

    /* Now display the array elements 10 at a time */
    for (a = 0; a < 1000; a++) {
        if (a % 10 == 0 && a != 0) {
            printf("\nPress Enter to continue, CTRL-C to quit.");

            getchar();
        }

        printf("Average: %f", avg);
        printf(", random_array[%d] = ", a);
        printf("%d\n", random_array[a]);
    }
    
    return 0;
}
/* end of main() */