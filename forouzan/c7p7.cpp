#include <iostream>
#include "classes/Employee.h"

int main() {
    Employee e("John Doe", 25, 5, 1500);

    std::cout << "Name: " << e.getName() << std::endl;
    std::cout << "Age: " << e.getAge() << std::endl;
    std::cout << "Service years: " << e.getServiceYear() << std::endl;
    std::cout << "Salary: " << e.getSalary() << std::endl;

    return 0;
}