#include <iostream>

using namespace std;

int main() {

    cout << "Limit: ";
    int numsToCalculate;
    std::cin >> numsToCalculate;

    cout << "This program will calculate " << numsToCalculate
            << " Fibonacci Numbers" << endl;

    int num1 = 0, num2 = 1;

    cout << num1 << " " << num2 << " ";

    
    for (int counter = 2; counter < numsToCalculate; ++counter) {
        cout << num1 + num2 << " ";

        int num2Temp = num2;
        num2 = num1 + num2;
        num1 = num2Temp;
    }

    cout << endl;

    return 0;
}