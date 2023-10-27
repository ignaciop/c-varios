#include <stdio.h>

void my_print(void) {
    printf("%s\n", "my_print");
}

int main(void) {
    int i;

    printf("The stack top is near %p\n", &i);

    my_print();
    int arr[1000];

    printf("The stack top is near %p\n", arr);

    return 0;
}