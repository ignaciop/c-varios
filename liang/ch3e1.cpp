#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;

    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        float r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
        float r2 = (-b - pow(discriminant, 0.5)) / (2 * a);

        cout << "The roots are " << r1 << " and " << r2 << "\n";
    } else if (discriminant == 0) {
        float r1 = (-b + pow(discriminant, 0.5)) / (2 * a);

        cout << "The roots is " << r1 << "\n";
    } else {
        cout << "The equation has no real roots\n";
    }

    return 0;
}