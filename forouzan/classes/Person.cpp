#include "Person.h"
#include <iostream>

Person::Person(std::string sName, int iAge) : name(sName), age(iAge) {}

Person::~Person() {}

void Person::setName(std::string sName) {
    name = sName;
}

void Person::setAge(int iAge) {
    age = iAge;
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}
