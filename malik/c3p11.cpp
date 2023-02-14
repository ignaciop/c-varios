#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double l, w, h, p;

    cout << "Enter the length of the candy bar: ";
    cin >> l;

    cout << "Enter the width of the candy bar: ";
    cin >> w;

    cout << "Enter the height of the candy bar: ";
    cin >> h;

    cout << "Enter the percentage reduction in volume: ";
    cin >> p;

    double reduction = p / 100.0;
    double newVolume = (1 - reduction) * l * w * h;
    double newArea = newVolume / h;
    double newL = sqrt(newArea * (l / w));
    double newW = newArea / newL;

    cout << "New dimensions of the candy bar: " << newL << " x " << newW << " x " << h << endl;

    return 0;
}