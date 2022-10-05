#include <iostream>

using namespace std;

int main() {
    char c;

    cout << "Enter a character: ";
    cin >> c;

    cout << "\n";
    cout << "    " << c << " " << c << " " << c << "\n";
    cout << "   " << c << "    " << c << "\n";
    cout << "  " << c << "\n";
    cout << "  " << c << "\n";
    cout << "  " << c << "\n";
    cout << "  " << c << "\n";
    cout << "  " << c << "\n";
    cout << "   " << c << "    " << c << "\n";
    cout << "    " << c << " " << c << " " << c << "\n";

    return 0;
}