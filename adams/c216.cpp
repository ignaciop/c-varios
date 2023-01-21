#include <iostream>

int main() {
    std::cout << "Size and alignment of int: " << sizeof(int) << " and " 
                << alignof(int) << std::endl;
    std::cout << "Size and alignment of long: " << sizeof(long) << " and " 
                << alignof(long) << std::endl;
    std::cout << "Size and alignment of float: " << sizeof(float) << " and " 
                << alignof(float) << std::endl;
    std::cout << "Size and alignment of double: " << sizeof(double) << " and " 
                << alignof(double) << std::endl;
    
    std::cout << "Size and alignment of *int: " << sizeof(int*) << " and " 
                << alignof(int*) << std::endl;
    std::cout << "Size and alignment of *long: " << sizeof(long*) << " and " 
                << alignof(long*) << std::endl;
    std::cout << "Size and alignment of *float: " << sizeof(float*) << " and " 
                << alignof(float*) << std::endl;
    std::cout << "Size and alignment of *double: " << sizeof(double*) << " and " 
                << alignof(double*) << std::endl;

    return 0;
}