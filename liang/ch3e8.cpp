#include <iostream>

using namespace std;

int main() {
    cout << "Enter three edges of a triangle: ";
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if (n1 == n2 && n2 == n3) {
        cout << "Equilateral Triangle\n";
    } else {
        if (n1 == n3 || n1 == n2 || n2 == n3) {
            cout << "Isosceles Triangle\n";
        } else {
            cout << "Scalene Triangle\n";
        }
    }

    return 0;
}