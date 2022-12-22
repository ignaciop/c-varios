#include <iostream>
#include <string>

class Human {
    private:
        int age;
        std::string name;

    public:
        Human(std::string inputName, int inputAge) : 
            age(inputAge), name(inputName) {}
};

int main() {
    Human h1("Ignacio", 36);    

    return 0;
}

