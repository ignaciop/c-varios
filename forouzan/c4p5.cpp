#include <iostream>

int main() {
    std::cout << "Enter three test scores: ";
    double a = 0.0, b = 0.0, c = 0.0;
    std::cin >> a >> b >> c;

    double avg = (a + b + c) / 3;
    
    char grade = ' ';

    if (avg >= 90) {
        grade = 'A';
    } else if (avg >= 80 && avg < 90) {
        if (c > 90) {
            grade = 'A';
        } else {
            grade = 'B';
        }
    } else if (avg >= 70 && avg < 80) {
        if (c > 80) {
            grade = 'B';
        } else {
            grade = 'C';
        }
    } else if (avg >= 60 && avg < 70) {
        if (c > 70) {
            grade = 'C';
        } else {
            grade = 'D';
        }
    } else if (avg < 60) {
        if (c > 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
    }

    std::cout << "Grade: " << grade << std::endl;

    return 0;
}