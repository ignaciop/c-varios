#include <iostream>
#include "classes/One.h"

int main() {
    One one_object(5,8);

    std::cout << "One object x: " << one_object.getX() << std::endl;
    std::cout << "One object y: " << one_object.getY() << std::endl;
 
    return 0;
}