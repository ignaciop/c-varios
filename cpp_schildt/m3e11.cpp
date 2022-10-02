#include <iostream>

using namespace std;

int main() {
    char c = ' ';
    int count = 0;


    while (c != '.') {
        cout << "Type a character (. to quit): ";
        cin >> c;

        if (c >= 'A' && c <= 'Z' ) {
            cout << c << " to lowercase: " << char(c + 32) << "\n";
            ++count;
        } else if (c >= 'a' && c <= 'z' ) {
            cout << c << " to uppercase: " << char(c - 32) << "\n";
            ++count;
        } else {
            continue;
        }
    }

    cout << "Total case changes: " << count << "\n";

    return 0;
}