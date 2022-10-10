#include <iostream>

using namespace std;

int main() {
    cout << "Enter three integers: ";
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    if (n1 <= n2) {
        if (n2 <= n3) {
            cout << n1 << " < " << n2 << " < " << n3 << "\n";
        } else {
            if (n1 <= n3) {
                cout << n1 << " < " << n3 << " < " << n2 << "\n";
            } else {
                cout << n3 << " < " << n1 << " < " << n2 << "\n";
            }
        }
    } else {
        if (n1 <= n3) {
            cout << n2 << " < " << n1 << " < " << n3 << "\n";
        } else {
            if (n2 <= n3) {
                cout << n2 << " < " << n3 << " < " << n1 << "\n";
            } else {
                cout << n3 << " < " << n2 << " < " << n1 << "\n";
            }
        }
    }

    return 0;
}