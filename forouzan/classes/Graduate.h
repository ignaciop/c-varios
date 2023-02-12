#ifndef GRADUATE_H
#define GRADUATE_H

#include <string>
#include "Student3.h"

class Graduate : public Student {
    private:
        std::string goal;

    public:
        Graduate() = delete;
        Graduate(std::string sName, double dGpa, std::string sGoal);
        Graduate(const Graduate& graduateCopy) = delete;
        ~Graduate();

        std::string getName() const;
        double getGPA() const;
        std::string getGoal() const;
};

#endif