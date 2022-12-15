#include <iostream>
  
short factor(int, int &, int &);
  
int main() {
    int number, squared, cubed;
    short error;
  
    std::cout << "Enter a number (0 - 20): ";
    std::cin >> number;
  
    error = factor(number, squared, cubed);
  
    if (!error) {
        std::cout << "number: " << number << "\n";
        std::cout << "square: " << squared << "\n";
        std::cout << "cubed: "  << cubed   << "\n";
    } else {
        std::cout << "Error encountered!!\n";
    }

    return 0;
}
  
short factor(int n, int &rSquared, int &rCubed) {
    short value = 0;

    if (n > 20) {
        value = 1;
    } else {
        rSquared = n*n;
        rCubed = n*n*n;
        value = 0;
    }

    return value;
}