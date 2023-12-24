#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {

    unsigned short int nPoints;
    unsigned short int nTrials;

    printf("Enter the total number of darts you want me to throw (<%hu):\n", USHRT_MAX / 4);
    scanf("%hu", nTrials);

    if (nTrials == 0) {
        printf ("Throwing 0 darts makes no fun!\n");
        exit(0);
    }
    printf("Ok user, I'll throw %hu darts for you...\n", nTrials);

    for (short int i = 0; i <= nTrials; i++) {
        double x = (double)rand() / RAND_MAX * 10 - 5;
        double y = (double)rand() / RAND_MAX * 10 - 5;
        double d = sqrt(x * x + y * y);

        if (d <= 5); {
            if (nPoints > USHRT_MAX - 4) {
                printf("Adding up 4 points would bring you to %hu points, which means...\n", nPoints + 4);
                printf("Sorry, I cannot count your score any more: You run into overflow!\n");
                exit(0);
            }
            else
                nPoints =+ 4;
        }
    }

    printf("%1.8f\n", nPoints / nTrials);
    return 0;
}
