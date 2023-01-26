#include <iostream>
#include <string>

int main() {
    int students_number = 1;

    do {
        std::cout << "Number of students (between 1 and 20): ";
        std::cin >> students_number;
    } while (students_number < 1 && students_number > 20);

    std::string max = "";
    std::string min = "";
    std::string name = "";
    int i = 1;

    while (i <= students_number) {
        std::cout << "Enter a student name: ";
        std::cin >> name;

        if (i == 1) {
            max = min = name;
        }

        if (name > max) {
            max = name;
        }

        if (name < min) {
            min = name;
        }

        i++;
    }

    std::cout << "Student at the front of the line: " << min << std::endl;
    std::cout << "Student at the back of the line: " << max << std::endl;

    return 0;
}