#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int LL = 1;
    const int UL = 100;

    srand(time(NULL));

    int random_number = LL + (rand() % (UL - LL + 1));
    int guess = random_number - 1;
    int total_guesses = 0;

    while (guess != random_number) {
        std::cout << "Enter a number: ";
        std::cin >> guess;

        total_guesses++;

        if (guess > random_number) {
            std::cout << "Too high. Try again." << std::endl;
        } else if (guess < random_number) {
            std::cout << "Too low. Try again." << std::endl;
        } else {
            std::cout << "Congratulations. You figured out my number." << std::endl;
            std::cout << "Number of guesses: " << total_guesses << std::endl;
        }
    }
    
    return 0;
}