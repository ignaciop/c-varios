#include <iostream>

int main() {
    int prev = 0;
    int n = 0;
    int most = 0;

    for (int i = 1; i <= 100; i++) {
        std::cout << "Enter an integer: ";
        std::cin >> n;

        if (i == 1) {
            prev = n;
        }

        if (prev == n) {
            most = n;
        }

        prev = n;
    }
   
    std::cout << "Number entered most succesive times: " << most << std::endl;
    
    return 0;
}