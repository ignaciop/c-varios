#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int static_array[5] = {0};
    int *dynamic_array = (int *)malloc(5 * sizeof(int));

    if (dynamic_array == NULL) {
        printf("Cannot allocate memory for dynamic array.\n");

        return 1;
    }

    for (int i = 0; i < 5; i++) {
        static_array[i] = i + 1;
        dynamic_array[i] = i + 1;
    }

    free(dynamic_array);
    dynamic_array = NULL;

    return 0;
}