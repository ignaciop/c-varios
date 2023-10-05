#include <stdio.h>
#include <stdlib.h>

void three_colors_sort(int *the_array, int array_size);

int main(void) {
    int inputs = 0;

    printf("Number of inputs: ");
    scanf("%d", &inputs);

    int *numbers_array = (int *)malloc(inputs * sizeof(int));

    for (int i = 0; i < inputs; i++) {
        printf("Give number %d: ", i);
        scanf("%d", numbers_array + i);
    }

    three_colors_sort(numbers_array, inputs);

    printf("Input when sorted:\n");

    for (int i = 0; i < inputs; i++) {
        printf("%d\n", *(numbers_array + i));
    }

    free(numbers_array);
    numbers_array = NULL;
    
    return 0;
}

void three_colors_sort(int *the_array, int array_size) {
    for (int i = 0; i < array_size - 1; i++) {
        for (int j = 0; j < array_size - i - 1; j++) {
            if (the_array[j] > the_array[j + 1]) {
                int temp = the_array[j];
                the_array[j] = the_array[j + 1];
                the_array[j + 1] = temp;
            }
        }
    }
}