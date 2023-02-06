#include <iostream>

int main () {
    int sum = 0;
    double avg = 0;
    int count = 0;

    int n = 1;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> n;

        if (n != 1000) {
            count++;
        
            sum += n;

            avg = sum / static_cast<double>(count);

            std::cout << "Sum: " << sum << std::endl;
            std::cout << "Average: " << avg << std::endl;
        } else {
            break;
        }
    }
    
    return 0;
}