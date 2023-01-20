#include <iostream>

int main() {
    std::cout << "Size and alignment of int: " << sizeof(int) << std::endl;
    std::cout << "Size and alignment of long: " << sizeof(long) << std::endl;
    std::cout << "Size and alignment of float: " << sizeof(float) << std::endl;
    std::cout << "Size and alignment of double: " << sizeof(double) << std::endl;
    
    std::cout << "Size and alignment of *int: " << sizeof(int*) << std::endl;
    std::cout << "Size and alignment of *long: " << sizeof(long*) << std::endl;
    std::cout << "Size and alignment of *float: " << sizeof(float*) << std::endl;
    std::cout << "Size and alignment of *double: " << sizeof(double*) << std::endl;

    return 0;
}