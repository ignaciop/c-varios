#include <iostream>
#include <ctime>

using namespace std;

int main() {
    float v0, v1, t;

    cout << "Enter v0, v1 and t: ";
    cin >> v0 >> v1 >> t;

    float a = (v1 - v0) / t;
    
    cout << "The average acceleration is " << a << "\n";

    return 0;
}