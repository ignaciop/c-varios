#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float s;

    cout << "Enter the side: ";
    cin >> s;

    float area = (3 * sqrt(3) / 2) * pow(s, 2);

    cout << "The area of the hexagon is " << area << "\n";
 
    return 0;
}       