#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Approximate value of PI: "
            << sqrt(6 * (1.0 + 1/4 + 1/9 + 1/16 + 1/25)) << "\n";

    cout << "Approximate value of PI (one more term): "
            << sqrt(6 * (1.0 + 1/4 + 1/9 + 1/16 + 1/25 + 1/36)) << "\n";  

    return 0;
}