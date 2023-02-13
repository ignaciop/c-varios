#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3, average;

    num1 = 125;
    num2 = 28;
    num3 = -25;

    average = (num1 + num2 + num3) / 3;

    cout << "Num1: " << num1 << ", Num2: " << num2 << ", Num3: " << num3
            << " --> Average: " << average << endl;
    
    return 0;
}