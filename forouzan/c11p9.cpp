#include <iostream>
#include "classes/Person2.h"
#include "classes/Student3.h"
#include "classes/Employee3.h"
#include "classes/Undergrad.h"
#include "classes/Graduate.h"
#include "classes/Staff.h"
#include "classes/Professor.h"

int main() {
    Person p("John Doe");
    Student s("Mary Jane", 3.2);
    Employee e("Clark Kent", 1500);
    Undergrad u("Julia Stiles", 3.9, 4);
    Graduate g("Mona Lisa", 3.9, "phd");
    Staff sf("Will Hunting", 1200, "nonmanager");
    Professor pf("Gerard Lambeau", 1800, "full-time");

    std::cout << "Person: " << p.getName() << std::endl;
    std::cout << "Student: " << s.getName() << ", gpa: " << s.getGPA() << std::endl;
    std::cout << "Employee: " << e.getName() << ", salary: " << e.getSalary() << std::endl;
    std::cout << "Undergrad: " << u.getName() << ", gpa: " << u.getGPA() << ", year: " << u.getYear() << std::endl;
    std::cout << "Graduate: " << g.getName() << ", gpa: " << g.getGPA() << ", goal: " << g.getGoal() << std::endl;
    std::cout << "Staff: " << sf.getName() << ", salary: " << sf.getSalary() << ", status: " << sf.getStatus() <<  std::endl;
    std::cout << "Professor: " << pf.getName() << ", salary: " << pf.getSalary() << ", status: " << pf.getStatus() <<  std::endl;

    return 0;
}