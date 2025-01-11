#include <stdio.h>
#include <stdlib.h>

#define BOLD_FACE "\033[1;97m"
#define RED_COLOR "\033[38;2;228;50;44m"
#define GREEN_COLOR "\033[38;2;0;145;87m"
#define BLUE_COLOR "\033[38;2;0;103;171m"
#define LIGHTBLUE_COLOR "\033[38;2;25;168;208m"
#define PURPLE_COLOR "\033[38;2;174;39;131m"
#define YELLOW_COLOR "\033[38;2;248;207;0m"

#define RESET_COLOR "\033[0m"

#define RIGHT_ARROW_ICON "\U0001F872"
#define LEFT_ARROW_ICON "\U0001F870"
#define TRAIN_ICON "\U0001F687"
#define CLOCK_ICON "\U0001F557"
#define EVENT_ICON "\U0001F4DD"
#define TRAFFIC_LIGHT_ICON "\U0001F6A6"
#define REPAIR_ICON "\U0001F527"
#define BARRIER_ICON "\U0001F6A7"
#define LOAD_ICON "\U000023F3"

#define LINE1_SIGN "\U0001F535"
#define LINE2_SIGN "\U0001F7E3"
#define LINE3_SIGN "\U0001F534"
#define LINE4_SIGN "\U0001F7E1"
#define LINE0_SIGN "\U0001F7E2"
#define STATION_SIGN "\U00002B24"
#define PASSING_SIGN "\033[1;92m\U0001F781 Tunnel Passing \U0001F783\033[0m"
#define OVERLOAD_SIGN "\033[1;93m\U0001F7B2 System Overload \U0001F7B2\033[0m"
#define BREAKDOWN_SIGN "\033[1;91m\U0001F7AC Train Breakdown \U0001F7AC\033[0m"
#define CLEARED_SIGN "\033[1;95m\U00002BC1 Tunnel Cleared \U00002BC1\033[0m"

int main(void) {

    printf("%s%s%s%s%s%s%s%s\n", BOLD_FACE, GREEN_COLOR, STATION_SIGN, "============", STATION_SIGN, "============", STATION_SIGN, RESET_COLOR);
    printf("%s %s\nID: %s\nPax: %s\n", TRAIN_ICON, RIGHT_ARROW_ICON, "256", "155");
    printf("%s%s%s%s%s%s\n", BOLD_FACE, RED_COLOR, STATION_SIGN, "============", STATION_SIGN, RESET_COLOR);
     printf("%s%s%s%s%s%s\n", BOLD_FACE, LIGHTBLUE_COLOR, STATION_SIGN, "============", STATION_SIGN, RESET_COLOR);
    printf("%s%s%s%s%s%s\n", BOLD_FACE, PURPLE_COLOR, STATION_SIGN, "============", STATION_SIGN, RESET_COLOR);
    printf("%s%s%s%s%s%s\n", BOLD_FACE, YELLOW_COLOR, STATION_SIGN, "============", STATION_SIGN, RESET_COLOR);
     printf("%s%s%s%s%s%s\n", BOLD_FACE, BLUE_COLOR, STATION_SIGN, "============", STATION_SIGN, RESET_COLOR);
    
    return EXIT_SUCCESS;
}