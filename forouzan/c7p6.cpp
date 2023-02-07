#include <iostream>
#include "classes/Address.h"

int main() {
    Address a(1234, "Evergreen Av.", "Springfield", "Oregon", 90211);

    a.print();

    return 0;
}