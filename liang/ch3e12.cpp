#include <iostream>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions

using namespace std;

int main() {
    
    // Generate random integer
    srand(time(0));
    int number = rand();
    int parity = (number % 2 == 0) ? 0 : 1;

    cout << "What is the parity of the number (type 0 for even, 1 for odd)? ";
    int answer;
    cin >> answer;

    if (answer == parity) {
        cout << "You are correct!\n";
    } else {
        cout << "You are incorrect!\n";
    }

    return 0;
}