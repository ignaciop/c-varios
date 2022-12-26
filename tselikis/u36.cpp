#include <iostream>

int main() {
    int i;

    std::cout << "Enter a two-digit positive number: ";
    std::cin >> i;

    int dec = i / 10;
    int uni = i % 10; 

    std::cout << dec << dec << uni << uni << '\n';
    
    return 0;
}