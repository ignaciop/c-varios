#include <iostream>

using namespace std;

int main() {
    double num1, num2, num3, average;

    num1 = 75.35;
    num2 = -35.56;
    num3 = 15.76;

    average = (num1 + num2 + num3) / 3;

    cout << "Num1: " << num1 << ", Num2: " << num2 << ", Num3: " << num3
            << " --> Average: " << average << endl;
    
    return 0;
}