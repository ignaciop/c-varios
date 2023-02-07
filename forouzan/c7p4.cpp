#include <iostream>
#include "classes/Person.h"

int main() {
    Person p("John Doe", 34);

    std::cout << "Name: " << p.getName() << std::endl;
    std::cout << "Age: " << p.getAge() << std::endl;

    p.setName("Mary Jones");
    p.setAge(36);

    std::cout << "New name: " << p.getName() << std::endl;
    std::cout << "New age: " << p.getAge() << std::endl;

    return 0;
}