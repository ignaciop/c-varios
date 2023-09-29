#include <stdio.h>

#define FLAT_EYEBROW 'a'
#define SQUIGGLE_EYEBROW 'b'
#define LEFT_ANGRY_EYE 'c'
#define RIGHT_ANGRY_EYE 'd'
#define UP_NOSE 'e'
#define SQUIGGLE_NOSE 'f'
#define SMILE_MOUTH 'g'
#define GRUMPY_MOUTH 'h'
#define SURPRISE_MOUTH 'i'

int main(void) {

    printf("How do you want to build a face?: ");

    // Get the first eye
    char first_eye;
    scanf("%c", &first_eye);

    char left_eyebrow = '?';

    if (first_eye == FLAT_EYEBROW) {
        left_eyebrow = '_';
    } else if (first_eye == SQUIGGLE_EYEBROW) {
        left_eyebrow = '~';
    } else if (first_eye == LEFT_ANGRY_EYE) {
        left_eyebrow = '\\';
    } else if (first_eye == RIGHT_ANGRY_EYE) {
        left_eyebrow = '/';
    }

    // Determine if the second letter is an eye or a nose
    char eye_nose = '?';
    scanf("%c", &eye_nose);

    char right_eyebrow = '?';

    // If we were given a different eye type
    if (eye_nose >= FLAT_EYEBROW && eye_nose <= RIGHT_ANGRY_EYE) {
        if (eye_nose == FLAT_EYEBROW) {
            right_eyebrow = '_';
        } else if (eye_nose == SQUIGGLE_EYEBROW) {
            right_eyebrow = '~';
        } else if (eye_nose == LEFT_ANGRY_EYE) {
            right_eyebrow = '\\';
        } else if (eye_nose == RIGHT_ANGRY_EYE) {
            right_eyebrow = '/';
        }

    // If we were given a nose, make the eyes the same
    } else {
        right_eyebrow = left_eyebrow;
    }

    // Print the eyes out
    printf("%c %c\n", left_eyebrow, right_eyebrow);
    printf("O O\n");

    // Nose
    char nose;
    
    // If we got a nose, don't scan for another nose.
    if (eye_nose <= RIGHT_ANGRY_EYE) {
        scanf("%c", &nose);
    } else {
        // copy across the nose we have already scanned.
        nose = eye_nose;
    }

    // Print the correct nose
    if (nose == UP_NOSE) {
        printf(" ^ \n");
    } else if (nose == SQUIGGLE_NOSE) {
        printf(" ~ \n");
    }

    // Mouth
    char mouth;
    scanf("%c", &mouth);

    // Find the correct mouth and print it out!
    if (mouth == SMILE_MOUTH) {
        printf("\\_/\n");
    } else if (mouth == GRUMPY_MOUTH) {
        printf("/-\\\n");
    } else if (mouth == SURPRISE_MOUTH) {
        printf(" o \n");
    }

    return 0;
}