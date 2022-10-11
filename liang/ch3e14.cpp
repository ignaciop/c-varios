#include <iostream>
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions

using namespace std;

int main() {
    
    // Generate two digit random integer
    srand(time(0));
    int number = rand() % 90 + 10;

    int first_digit = number / 10;
    int second_digit = number % 10;

    cout << "Enter a two digit number as your guess: ";
    int guess;
    cin >> guess;

    int first_digit_guess = guess / 10;
    int second_digit_guess = guess % 10;

    if (first_digit_guess == first_digit && second_digit_guess == second_digit) {
        cout << "100\% accuracy!\n"; 
    } else if ((first_digit_guess != first_digit && first_digit_guess == second_digit) || (second_digit_guess != second_digit && second_digit_guess == first_digit)
                || (first_digit_guess == first_digit && first_digit_guess != second_digit) || (second_digit_guess == second_digit && second_digit_guess != first_digit)) {
        cout << "50\% accuracy\n"; 
    } else {
        cout << "0\% accuracy\n"; 
    }

    return 0;
}