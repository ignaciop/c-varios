#include <iostream>

using namespace std;

int main() {
    double d1, d2, d3, d4, d5, avg;

    cout << "Enter a test score: ";
    cin >> d1;

    cout << "Enter a test score: ";
    cin >> d2;

    cout << "Enter a test score: ";
    cin >> d3;

    cout << "Enter a test score: ";
    cin >> d4;

    cout << "Enter a test score: ";
    cin >> d5;

    avg = (d1 + d2 + d3 + d4 + d5) / 5;

    cout << "The average test score is " << avg << endl;
    
    return 0;
}