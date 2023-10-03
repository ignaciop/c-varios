#include <stdio.h>

#define ARRAY_ELEMS 5

int sumarrays(int a1[], int a2[], int size);

int main(void) {
    int a1[ARRAY_ELEMS] = {1, 2, 3, 4, 5};
    int a2[ARRAY_ELEMS] = {6, 7, 8, 9, 10};

    for (int i = 0; i < ARRAY_ELEMS; i++) {
        printf("a1[%d] = %d, a2[%d] = %d\n", i, a1[i], i, a2[i]);
    }

    int total = sumarrays(a1, a2, ARRAY_ELEMS);

    printf("Totals: %d\n", total);
    
    return 0;
}

int sumarrays(int a1[], int a2[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += *(a1 + i) + *(a2 + i);
    }

    return total;
}