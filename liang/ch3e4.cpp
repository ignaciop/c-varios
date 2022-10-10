#include <iostream>

using namespace std;

int main() {
    float v;

    cout << "Enter speed of a vehicle: ";
    cin >> v;

    if (v < 20) {
        cout << "too slow\n";
    } else if (v > 80) {
        cout << "too fast\n";
    } else {
        cout << "just right\n";
    }
    
    return 0;
}