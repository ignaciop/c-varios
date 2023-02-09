#include <iostream>
#include "classes/Address2.h"

int main() {
    Address address1(71832456);

    std::cout << "Decimal: " << address1.getAddress() << std::endl;
    std::cout << "Binary: " << address1.toBinary() << std::endl;
    std::cout << "Dotted Decimal: " << address1.toDottedDecimal() << std::endl;

    return 0;
}