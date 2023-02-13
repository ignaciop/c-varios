#include <iostream>

using namespace std;

int main() {
    int total_seconds;

    cout << "Enter the elapsed time in seconds: ";
    cin >> total_seconds;

    int hours = total_seconds / 3600;
    int rem = total_seconds % 3600;

    int minutes = rem / 60;
    int seconds = rem % 60;
    
    cout << hours << ":" << minutes << ":" << seconds << endl;
    
    return 0;
}