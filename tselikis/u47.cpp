#include <iostream>

int main() {
    unsigned char ch = 3;
    
    ch = ((ch&1) << 7) | ((ch&2) << 5) | ((ch&4) << 3) | ((ch&8) << 1) |
            ((ch&16) >> 1) | ((ch&32) >> 3) | ((ch&64) >> 5) | ((ch&128) >> 7);

    std::cout << (int)ch << '\n';

    return 0;
}