#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int a {};
    std::cin >> a;

    if (a >= 1) {
        int i {1};

        while (i <= a) {
            int j {1};
            
            while (j <= a) {
                std::cout << "*";
                
                j++;
            }
            
            i++;

            std::cout << "\n";
        }
    }

    return 0;
}