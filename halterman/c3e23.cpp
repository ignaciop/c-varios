#include <iostream>

int main() {
    for (int i = 0; i <= 127; i++) {
        std::cout << i << " --> " << static_cast<char>(i) << std::endl;
    }
    
    return 0;
}