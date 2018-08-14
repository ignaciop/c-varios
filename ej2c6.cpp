#include <iostream>
#include <string>
#include <algorithm>

struct Student {
	std::string name;
	int grade;
};

void sortNames(Student *students, int length) {
	for (int startIndex = 0; startIndex < length; ++startIndex) {
		int largestIndex = startIndex;
		
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
			if (students[currentIndex].grade > students[largestIndex].grade) {
				largestIndex = currentIndex;
			}
		}
		
		std::swap(students[startIndex], students[largestIndex]);
	}
}

int main() {
	int numStudents = 0;
	
	do {
		std::cout << "How many students do you want to enter? ";
		std::cin >>numStudents;
	} while (numStudents <= 1);
	
	Student *students = new Student[numStudents];
	
	for (int index = 0; index < numStudents; ++index) {
		std::cout << "Enter name #" << index + 1 << ": ";
		std::cin >> students[index].name;
		std::cout << "Enter grade #" << index + 1 << ": ";
		std::cin >> students[index].grade;
	}
	
	sortNames(students, numStudents);
	
	for (int index = 0; index < numStudents; ++index) {
		std::cout << students[index].name << " got a grade of " << students[index].grade << "\n";
	}
	
	delete[] students;

	return 0;
}