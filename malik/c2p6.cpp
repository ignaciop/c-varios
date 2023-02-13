#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    double studyHours;

    cout << "Name: ";
    cin >> name;

    cout << "Study hours: ";
    cin >> studyHours;

    cout << "Hello, " << name << "! on Saturday, you need to study "
            << studyHours << " hours for the exam." << endl;
    
    return 0;
}