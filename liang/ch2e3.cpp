#include <iostream>

using namespace std;

int main() {
    float feet;

    cout << "Enter a value for feet: ";
    cin >> feet;

    float meters = feet * 0.305;

    cout << feet << " feet is " << meters << " meters\n";

    return 0;
}