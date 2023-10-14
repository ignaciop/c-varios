#include <stdio.h>

int main(void) {
    int first_group, second_group, third_group;

    printf("Enter phone number [(xxx)  xxx-xxxx]: ");
    scanf("(%d)  %d-%d", &first_group, &second_group, &third_group);

    printf("You entered %d.%d.%d\n", first_group, second_group, third_group);

    return 0;
}