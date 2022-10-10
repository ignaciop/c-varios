#include <iostream>

using namespace std;

int main() {
    float a, b, c, d, e, f;

    cout << "Enter a, b, c, d, e, f: ";
    cin >> a >> b >> c >> d >> e >> f;

    float det = a * d - b * c;

    if (det == 0) {
        cout << "The equation has no solution\n";
    } else {
        float x = (e * d - b * f) / det;
        float y = (a * f - e * c) / det;

        cout << "x is " << x << " and y is " << y << "\n";
    }
    
    return 0;
}