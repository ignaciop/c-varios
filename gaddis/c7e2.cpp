#include <iostream>
#include "classes/Heading.h"

int main() {
    Heading h1;
    Heading h2("Gray Matter", "BB Report");
    Heading h3("Superkamiokande", "Neutrino Report");

    h1.printOneLiner();
    h1.printFourLiner();

    h2.printOneLiner();
    h2.printFourLiner();

    h3.printOneLiner();
    h3.printFourLiner();

    return 0;
}
