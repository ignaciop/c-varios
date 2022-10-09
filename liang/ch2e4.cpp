#include <iostream>

using namespace std;

int main() {
    float pounds;

    cout << "Enter a number in pounds: ";
    cin >> pounds;

    float kgs = pounds * 0.454;

    cout << pounds << " pounds is " << kgs << " kilograms\n";

    return 0;
}