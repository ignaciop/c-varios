#include <iostream>

int main() {
    char name[50];
    char last_name[80];

    std::cout << "What is your name? ";
    std::cin.getline(name, 49);

    std::cout << "What is your last name? ";
    std::cin.getline(last_name, 79);

    std::cout << "Hello " << name << " " << last_name << "!" << std::endl;
    
    return 0;
}