#include <iostream>

int main() {
    int n = 0;
    int largest = 0;
    int second_largest = 0;

    for (int i = 1; i <= 100; i++) {
        std::cout << "Enter an integer: ";
        std::cin >> n;

        if (i == 1) {
            largest = n;
            second_largest = n;
        }

        // The next ifs are separated like this to account for the two
        // largest DIFFERENT VALUES (if at some point largest and
        // second_largest are the same, the loop continues and do nothing,
        // hence "if n == largest then continue")
        if (n < largest) {
            if ((n >= second_largest) || i == 2) {
                second_largest = n;
            }
        } else  if (n > largest) {
            second_largest = largest;
            largest = n;
        } else {
            continue;
        }
    }
   
    std::cout << "The two largest different values are: " << largest
                << " and " << second_largest << std::endl;
    
    return 0;
}