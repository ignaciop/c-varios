#include <stdio.h>

struct personT {
    char name[80];
    int age;
    float height;
};

int main(void) {
    struct personT person = {"John Doe", 32, 84.5};

    printf("Name: %s\n", person.name);
    
    return 0;
}