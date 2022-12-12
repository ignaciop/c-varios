#include <iostream>

int main() {
    int m[3][3] = { };

    for (unsigned x = 0; x < 3; x++) {
        for (unsigned y = 0; y < 3; y++) {
            m[x][y] = x * y;
            std::cout << m[x][y] << " ";
        }
        
        std::cout << std::endl;
    }
  
    return 0;
}