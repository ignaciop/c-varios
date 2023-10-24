#include <stdio.h>

int main(void) {
    int total_seconds = 0;

    printf("%s", "Seconds: ");
    scanf("%d", &total_seconds);

    int hours = total_seconds / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds =(total_seconds % 3600) % 60;

    printf("%d seconds is equivalent to %d hours %d minutes %d seconds\n", total_seconds, hours, minutes, seconds);

    return 0;
}