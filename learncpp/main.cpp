#include <iostream>

int readNumber() {
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;
    return x;
}
 
void writeAnswer(int x) {
    std::cout << "The answer is " << x << std::endl;
}
 
int main() {
    int x = readNumber();
    int y = readNumber();
    writeAnswer(x + y); // using operator+ to pass the sum of x and y to writeAnswer()
    return 0;
}