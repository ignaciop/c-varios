#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include <string>
#include "Student3.h"

class Undergrad : public Student {
    private:
        int year;

    public:
        Undergrad() = delete;
        Undergrad(std::string sName, double dGpa, int iYear);
        Undergrad(const Undergrad& undergradCopy) = delete;
        ~Undergrad();

        std::string getName() const;
        double getGPA() const;
        int getYear() const;
};

#endif