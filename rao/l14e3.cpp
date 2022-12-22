#include <iostream>
#include <string>

template<typename T> void swap(T &value1, T &value2) {
    T temp = value1;
    value1 = value2;
    value2 = temp;
}

int main() {
    int i1 = 6;
    int i2 = 7;
    float f1 = 6.3;
    float f2 = 7.8;
    std::string s1 = "Holas";
    std::string s2 = "Mundo";

    std::cout << "Before swap..." << std::endl;
    std::cout << "i1: " << i1 << std::endl;
    std::cout << "i2: " << i2 << std::endl;
    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    swap(i1, i2);
    swap(f1, f2);
    swap(s1, s2);

    std::cout << "After swap..." << std::endl;
    std::cout << "i1: " << i1 << std::endl;
    std::cout << "i2: " << i2 << std::endl;
    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    return 0;
}

