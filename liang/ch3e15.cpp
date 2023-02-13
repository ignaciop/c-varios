#include <iostream>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions

using namespace std;

int main() {
    
    // Generate random 0, 1 or 2
    srand(time(0));
    int number = rand() % 3;

    cout << "scissor (0), rock (1), paper (2): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 0:
            if (number == 1) {
                cout << "The computer is rock. You are scissor. You lose\n";
            } else if (number == 2) {
                cout << "The computer is paper. You are scissor. You won\n";
            } else {
                cout << "The computer is scissor. You are scissor too. It is a draw\n";
            }
            break;
        case 1:
            if (number == 0) {
                cout << "The computer is scissor. You are rock. You won\n";
            } else if (number == 2) {
                cout << "The computer is paper. You are rock. You lose\n";
            } else {
                cout << "The computer is rock. You are rock too. It is a draw\n";
            }
            break;
        case 2:
            if (number == 0) {
                cout << "The computer is scissor. You are paper. You lose\n";
            } else if (number == 1) {
                cout << "The computer is rock. You are paper. You won\n";
            } else {
                cout << "The computer is paper. You are paper too. It is a draw\n";
            }
            break;
        default:
            cout << "Please, try again with a valid input ¬¬\n";
    }

    return 0;
}