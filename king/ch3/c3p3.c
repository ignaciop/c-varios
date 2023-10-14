#include <stdio.h>

int main(void) {
    int first_group, second_group, third_group, fourth_group, fifth_group;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &first_group, &second_group, &third_group, &fourth_group, &fifth_group);

    printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n", first_group, second_group, third_group, fourth_group, fifth_group);

    return 0;
}