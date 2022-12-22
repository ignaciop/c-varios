#include <iostream>

template<typename T> double split(const T &value) {
    return (value / 5);
}

int main() {
    std::cout << split(6) << std::endl;
    std::cout << split(7.8) << std::endl;
    
    return 0;
}

