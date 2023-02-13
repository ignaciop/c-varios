#include <iostream>

using namespace std;

int main() {
    const double K = 6.67e-8;

    double m1, m2, d;

    cout << "Enter mass 1: ";
    cin >> m1;

    cout << "Enter mass 2: ";
    cin >> m2;

    cout << "Enter distance between masses: ";
    cin >> d;

    double f = K * m1 * m2 / (d * d);

    cout << "Force between masses: " << f << endl;
    
    return 0;
}