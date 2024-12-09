/*  
 *  mean_temps.c
 *  Calculates the mean temperature of each season in Toronto
 *  Ignacio Poggi; 20240901
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/* Mean temperature in Toronto, on a month-by-month basis */
	/* Source: http://en.wikipedia.org/wiki/Toronto#Climate */
    double mean_temps[] = {-4.2, -3.2, 1.3, 7.6, 14.2, 19.2, 22.2, 21.3, 17.0, 10.6, 4.8, -0.9};
    int mt_len = sizeof(mean_temps) / sizeof(mean_temps[0]);
    
	/* Mean temperature of each season */
    const int NUM_SEASONS = 4;
    const int MONTHS_IN_SEASON = mt_len / NUM_SEASONS;
    
    /* create a list, mean_seasonal, initialized to [0, 0, 0, 0] */
    double mean_seasonal[4] = {0}; 

	/* 
	 * Now we want to calculate the mean temperature in Toronto during
	 * each of the four seasons; note that mean_temps begins with January
     */
    int curr_season = 0;
     
    for (int m = 0; m < mt_len; m++) {
        /* if we're at March (2), June (5), September (8) or December (11), update the season */
        if ((m + 1) % MONTHS_IN_SEASON == 0) {
            ++curr_season;
            
            /* We use mod to restore the season to 0 after passing the alloted number of seasons in a year (i.e more then 1 year) */
            curr_season %= NUM_SEASONS;
        }
        
        /* since we know how many months there are in a season, we can calculate the average as we go */
	    mean_seasonal[curr_season] += mean_temps[m] / MONTHS_IN_SEASON;
    }

    /* Finally, print each season's mean temp on a new line */
    printf("%s\n", "Mean seasonal temperatures in Toronto");
    
    char *seasons[] = {"winter", "spring", "summer", "autumn"};
    int ss_len = sizeof(seasons) / sizeof(seasons[0]);
    
    for (int s = 0; s < ss_len; s++) {
        printf("%s (%d): %lf deg C\n", seasons[s], s, mean_seasonal[s]);
    }
    
    return EXIT_SUCCESS;
}