#include <iostream>
#include "classes/Number.h"

int main() {
    Number num;
    num.setNumber("15", 10);

    std::cout << num.getNumber(2) << std::endl;
    std::cout << num.getNumber(8) << std::endl;
    std::cout << num.getNumber(10) << std::endl;
    std::cout << num.getNumber(16) << std::endl;

    return 0;
}