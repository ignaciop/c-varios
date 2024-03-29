#include <stdio.h>
#include <stdlib.h>

#include "ex6_vector.h"

int main(int argc, char **argv) {
    vector_t *v;

    printf("%s\n", "Calling vector_new()");
    v = vector_new();

    printf("%s\n", "Calling vector_delete()");
    vector_delete(v);

    printf("%s\n", "vector_new() again");
    v = vector_new();

    printf("%s", "These should all return 0 (vector_get()): ");
    printf("%d ", vector_get(v, 0));
    printf("%d ", vector_get(v, 1));
    printf("%d\n", vector_get(v, 2));

    printf("%s\n", "Doing a bunch of vector_set()s");
    vector_set(v, 0, 98);
    vector_set(v, 11, 15);
    vector_set(v, 15, -23);
    vector_set(v, 24, 65);
    vector_set(v, 500, 3);
    vector_set(v, 12, -123);
    vector_set(v, 15, 21);
    vector_set(v, 25, 43);

    printf("%s\n", "These should be equal:");
    printf("98 = %d\n", vector_get(v, 0));
    printf("15 = %d\n", vector_get(v, 11));
    printf("65 = %d\n", vector_get(v, 24));
    printf("-123 = %d\n", vector_get(v, 12));
    printf("21 = %d\n", vector_get(v, 15));
    printf("43 = %d\n", vector_get(v, 25));
    printf("0 = %d\n", vector_get(v, 23));
    printf("0 = %d\n", vector_get(v, 1));
    printf("0 = %d\n", vector_get(v, 501));
    printf("3 = %d\n", vector_get(v, 500));

    vector_delete(v);

    printf("%s\n", "Test complete.");

    return 0;
}