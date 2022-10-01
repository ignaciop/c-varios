#include <iostream>

using namespace std;

int main() {
    const float g_earth = 9.81;
    const float g_moon = g_earth*17/100;

    cout << "Weight on Earth (lbs)\tWeight on Moon (lbs)\n";

    for (int i = 1; i <= 100; ++i) {
        cout << "\t" << i << "\t\t\t" << i/g_earth*g_moon << "\n";

        if (i % 25 == 0) {
            cout << "\n";
        }
    }

    return 0;
}