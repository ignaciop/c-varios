#include <iostream>

int main() {
    std::cout << "Enter MAC address (format x:x:x:x:x:x): " << std::endl;
    int o1, o2, o3, o4, o5, o6  = 0;
    char cl = ':';
    std::cin >> std::hex >> o1 >> cl >> std::hex >> o2 >> cl >> std::hex >> o3 >> cl >>
                std::hex >> o4 >> cl >> std::hex >> o5 >> cl >> std::hex >> o6;

    if (o1 == 0xff && o2 == 0xff && o3 == 0xff && o4 == 0xff && o5 == 0xff
       && o6 == 0xff) {
        std::cout << "The address is broadcast" << std::endl;
    } else {
        if (o1 % 2 == 0) {
            std::cout << "The address is unicast" << std::endl;
        } else {
            std::cout << "The address is multicast" << std::endl;
        }
    }
    
    return 0;
}