#include <iostream>
#include <string>

#define GROUP_1_THRESHOLD 12
#define GROUP_2_THRESHOLD 28
#define GROUP_1_NAME "Group A"
#define GROUP_2_NAME "Group B"
#define GROUP_3_NAME "Group C"

std::string getGroup(int age);

int main() {
    std::cout << "Please enter your name: ";
    std::string name {};
    getline(std::cin, name);

    std::cout << "And please enter your age: ";
    int age {};
    std::cin >> age;

    std::string group = getGroup(age);

    std::cout << "Welcome " << name << ". You are in " << group << "." << std::endl;

    return 0;
}

std::string getGroup(int age) {
    if (age <= GROUP_1_THRESHOLD) {
        return GROUP_1_NAME;
    } else if (age <= GROUP_2_THRESHOLD) {
        return GROUP_2_NAME;
    } else {
        return GROUP_3_NAME;
    }
}