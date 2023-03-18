#include <iostream>

int main() {
    int y {0};
    int x {6};

    if (x > y) {
        std::cout << "x is greater than y\n";

        if (x == 6) {
            std::cout << "x is equal to 6\n";  
        } else {
            std::cout << "x is not equal to 6\n";
        }
    } else {
        std::cout << "x is not greater than y\n";
    }

    return 0;
}