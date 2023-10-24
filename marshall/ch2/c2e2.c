#include <stdio.h>
#include <stdlib.h>

#define BUFFER 80

int main(void) {
    char name[BUFFER];
    char address[BUFFER];
    char age_str[BUFFER];
    int age = 0;

    printf("%s", "Enter your name: ");

    if (fgets(name, BUFFER, stdin) == NULL) {
        printf("%s","Error reading name.\n");

        return 1;
    }

    printf("%s", "Enter your address: ");

    if (fgets(address, BUFFER, stdin) == NULL) {
        printf("%s","Error reading address.\n");

        return 1;
    }

    printf("%s", "Enter your age: ");

    if (fgets(age_str, BUFFER, stdin) == NULL) {
        printf("%s","Error reading age.\n");

        return 1;
    }

    age = atoi(age_str);

    printf("\nYour information:\n");
    printf("Name: %s", name);
    printf("Address: %s", address);
    printf("Age: %d\n", age);

    return 0;
}