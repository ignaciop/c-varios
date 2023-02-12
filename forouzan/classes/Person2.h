#ifndef PERSON2_H
#define PERSON2_H

#include <string>

class Person {
    private:
        std::string name;

    public:
        Person() = delete;
        Person(std::string sName);
        Person(const Person& personCopy) = delete;
        ~Person();

        std::string getName() const;
};

#endif