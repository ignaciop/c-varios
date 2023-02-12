#include "Person2.h"

Person::Person(std::string sName) : name(sName) {}

Person::~Person() {}

std::string Person::getName() const {
    return name;
}