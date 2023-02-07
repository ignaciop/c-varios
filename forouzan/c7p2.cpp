#include <iostream>
#include "classes/Two.h"

int main() {
    Two two_object(5,'a');

    std::cout << "Two object x: " << two_object.getX() << std::endl;
    std::cout << "Two object a: " << two_object.getA() << std::endl;

    two_object.setX(8);
    two_object.setA('b');

    std::cout << "Two object new x: " << two_object.getX() << std::endl;
    std::cout << "Two object new a: " << two_object.getA() << std::endl;
 
    return 0;
}