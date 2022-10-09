#include <iostream>

using namespace std;

int main() {
    int minutes;

    cout << "Enter the number of minutes: ";
    cin >> minutes;

    int years = minutes / 525600;
    int remainingMinutes = minutes % 525600;
    int days = remainingMinutes / 1440;

    cout << minutes << " minutes is approximately " 
            << years << " years and " << days << " days\n";
    
    return 0;
}