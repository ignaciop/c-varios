#include <iostream>

using namespace std;

int main() {
    float a, v;

    cout << "Enter speed and acceleration: ";
    cin >> v >> a;

    float length = (v * v) / (2 * a);

    cout << "The minimum runway length for this airplane is " << length << "\n";
 
    return 0;
}