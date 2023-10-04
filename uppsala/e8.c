#include <stdio.h>

#define ARRAY_SIZE 10

int zeros(int *arr, int size);
void print(int *arr, int size);
void triple(int *arr, int size);

int main(void) {
    int arr[ARRAY_SIZE] = {0};

    printf("Input 10 numbers: ");

    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf(" %d", arr + i);
    }

    printf("Initial array: ");
    print(arr, ARRAY_SIZE);

    printf("Number of 0's: %d\n", zeros(arr, ARRAY_SIZE));

    printf("Tripled array: ");
    triple(arr, ARRAY_SIZE);
    print(arr, ARRAY_SIZE);

    return 0;
}

int zeros(int *arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (*(arr + i) == 0) {
            count++;
        }
    }

    return count;
}

void print(int *arr, int size) {
    printf("{ ");

    for (int i = 0; i < size; i++) {
        printf("%d, ", *(arr + i));
    }

    printf("\b\b }\n");
}

void triple(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) *= 3;
    }
}