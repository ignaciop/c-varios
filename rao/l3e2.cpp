#include <iostream>

int main() {
    std::cout << "Size of unsigned integer: "
                << sizeof(unsigned int) << " bytes." <<  std::endl;
    std::cout << "Size of integer: "
                << sizeof(int) << " bytes." <<  std::endl;
    std::cout << "Size of long integer: "
                << sizeof(long int) << " bytes." <<  std::endl;

    return 0;
}
