#include <iostream>

int main() {
    for (unsigned x = 1; x <= 30; x++) {
        if (x % 3 != 0) {
            std::cout << x << " " << std::endl;
        }
    }
  
    return 0;
}