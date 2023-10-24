#include <stdio.h>

int main(void) {
    int total_time = 0;
    int time_duration = 0;

    printf("%s", "Enter a time of day on a 24 hour clock (e.g. 1245): ");
    scanf("%d", &total_time);

    printf("%s", "Enter a duration (e.g. 345): ");
    scanf("%d", &time_duration);

    int total_time_hours = total_time / 100;
    int total_time_minutes = total_time % 100;

    int time_duration_hours = time_duration / 100;
    int time_duration_minutes = time_duration % 100;

    int end_time_hours = (total_time_hours + time_duration_hours + (total_time_minutes + time_duration_minutes) / 60) % 24;
    int end_time_minutes = (total_time_minutes + time_duration_minutes) % 60;

    printf("Start time is %04d. Duration is %d%02d. End time is %04d.\n", total_time, time_duration_hours, time_duration_minutes, end_time_hours * 100 + end_time_minutes);
    
    return 0;
}