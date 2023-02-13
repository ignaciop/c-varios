#include <iostream>

using namespace std;

int main() {
    float x1, y1, x2, y2;

    cout << "Enter the coordinates for two points: ";
    cin >> x1 >> y1 >> x2 >> y2;

    float slope = (y2 - y1) / (x2 - x1);

    cout << "The slope for the line that connects two points "
            << "(" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2
                << ") is " << slope << "\n"; 

    return 0;
}       