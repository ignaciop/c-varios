#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void banana(void) {
    printf("%s\n", "in banana()");

    longjmp(buf, 1);
    /* NOTREACHED */
    printf("%s\n", "you'll never see this, because I longjmp'd");
}

int main(void) {
    if (setjmp(buf)) {
        printf("%s\n", "back in main");
    } else {
        printf("%s\n", "first time through");

        banana();
    }

    return 0;
}