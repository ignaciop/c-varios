#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 0;

    cout << "Maximum power of 2: ";
    cin >> n;

    for (int i = 0; i <= n; ++i) {
        cout << pow(2, i) << " ";
    }

    cout << "\n";

    return 0;
}