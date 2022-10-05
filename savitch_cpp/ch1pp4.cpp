#include <iostream>

using namespace std;

int main() {
    const float acceleration = 32.0;
    float time = 0.0;
    float distance = 0.0;

    cout << "Enter a time in seconds: ";
    cin >> time;

    distance = (acceleration*time*time)/2;

    cout << "The object will fall at " << distance << " feet.\n";

    return 0;
}