#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    private:
        std::string name;
        int age;

    public:
        Person() = delete;
        Person(std::string sName, int iAge);
        Person(const Person& personCopy) = delete;
        ~Person();

        void setName(std::string sName);
        void setAge(int iAge);
        std::string getName() const;
        int getAge() const;
};

#endif