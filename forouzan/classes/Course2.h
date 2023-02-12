#ifndef COURSE2_H
#define COURSE2_H

#include <string>

class Course {
    private:
        std::string name;
        int units;

    public:
        Course();
        Course(std::string sName, int iUnits);
        Course(const Course& courseCopy);
        ~Course();

        void print() const;
};

#endif