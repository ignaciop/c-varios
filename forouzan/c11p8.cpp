#include <iostream>
#include "classes/Person2.h"
#include "classes/Student3.h"
#include "classes/Employee3.h"

int main() {
    Person p("John Doe");
    Student s("Mary Jane", 3.2);
    Employee e("Clark Kent", 1500);

    std::cout << "Person: " << p.getName() << std::endl;
    std::cout << "Student: " << s.getName() << ", gpa: " << s.getGPA() << std::endl;
    std::cout << "Employee: " << e.getName() << ", salary: " << e.getSalary() << std::endl;

    return 0;
}