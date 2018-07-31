#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H
 
// Student_info.h
#include <iostream>
#include <string>
#include <vector>
 
struct Student_info {
  string name;
  double grade;
};	// note the semicolon--it's required

 
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
 
#endif // GUARD_STUDENT_INFO_H