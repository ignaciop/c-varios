#include <stdio.h>

void print_array(int arr[], int size);

int main(void) {
    int static_array[5] = {1, 2, 3, 4, 5};
    
    print_array(static_array, 5);

    return 0;
}

void print_array(int arr[], int size) {
    printf("{");

    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }

    printf("\b\b}\n");
}