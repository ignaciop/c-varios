#include <stdio.h>
#include <stdlib.h>

void op_double(int *a);
void op_reset(int *a);
void op_invert(int *a);
void applyTo(void (*func)(int *), int *tab, int size);
void print(int *arr, int size);

int main(void) {
    int inputs = 0;

    printf("Number of inputs: ");
    scanf("%d", &inputs);

    int *numbers = (int *)malloc(inputs * sizeof(int));
    int *numbers_copy = (int *)malloc(inputs * sizeof(int));


    if (numbers == NULL) {
        perror("Memory allocation error");
        
        return 1;
    }

    if (numbers_copy == NULL) {
        perror("Memory allocation error");
        
        return 1;
    }

    for (int i = 0; i < inputs; i++) {
        printf("Give number %d: ", i);
        scanf("%d", numbers + i);

        *(numbers_copy + i) = *(numbers + i);
    }

    applyTo(&op_double, numbers, inputs);

    printf("Result of applying op_double: ");
    print(numbers, inputs);

    applyTo(&op_reset, numbers, inputs);

    printf("Result of applying op_reset: ");
    print(numbers, inputs);

    applyTo(&op_invert, numbers_copy, inputs);

    printf("Result of applying op_invert: ");
    print(numbers_copy, inputs);

    free(numbers);
    numbers = NULL;

    free(numbers_copy);
    numbers_copy = NULL;
    
    return 0;
}

void op_double(int *a) {
    *a *= 2; 
}

void op_reset(int *a) {
    *a = 0; 
}

void op_invert(int *a) {
    *a *= -1;
}

void applyTo(void (*func)(int *), int *tab, int size) {
    for (int i = 0; i < size; i++) {
        func(tab + i);
    }
}

void print(int *arr, int size) {
    printf("{ ");

    for (int i = 0; i < size; i++) {
        printf("%d, ", *(arr + i));
    }

    printf("\b\b }\n");
}