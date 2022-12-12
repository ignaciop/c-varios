#include <iostream>

int main() {
    unsigned count = 0;

    for (unsigned x = 1; x <= 100; x++) {
        if (x % 11 == 0) {
            count++;
        }
    }

    std::cout << count << std::endl;
    
    return 0;
}