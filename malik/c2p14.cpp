#include <iostream>

using namespace std;

int main() {
    double hardDriveSize;

    cout << "Enter the size of the hard drive specified by the manufacturer: ";
    cin >> hardDriveSize;

    cout << "The actual storage capacity of the hard drive is approximately "
            << hardDriveSize * 0.93 << " GB." << endl;

    return 0;
}