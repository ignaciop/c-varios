#include <stdio.h>

#define ARRAY_ELEMS 10

int main(void) {
    int elements[ARRAY_ELEMS] = {0};

    for (int i = 0; i < ARRAY_ELEMS; i++) {
        elements[i] = i;
    }

    for (int i = 0; i < ARRAY_ELEMS; i++) {
        printf("elements[%d] = %d\n", i, elements[i]);
    }
    
    return 0;
}