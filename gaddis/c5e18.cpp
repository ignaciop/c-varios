#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    const int LL = 10;
    const int UL = 50;

    while (true) {
        // Seed
        srand(time(NULL));

        // Random numbers between [LL, UL]
        int num1 = LL + (rand() % (UL - LL + 1));
        int num2 = LL + (rand() % (UL - LL + 1));

        int choice = 1;
        int correct_ans = 0;
        int guess_ans = 0;

        std::cout << "\nSelect an option" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cout << "\t1. Addition" << std::endl;
        std::cout << "\t2. Substraction" << std::endl;
        std::cout << "\t3. Multiplication" << std::endl;
        std::cout << "\t4. Quit" << std::endl;

        std::cout << "\nChoice? " << std::endl;
        std::cin >> choice;

        std::cout << '\n';

        if (choice == 1) {
            correct_ans = num1 + num2;

            std::cout << std::setw(3) << num1 << "\n+" << std::setw(1) << num2 << "\n---" << std::endl;
        } else if (choice == 2) {
            correct_ans = num1 - num2;

            std::cout << std::setw(3) << num1 << "\n-" << std::setw(1) << num2 << "\n---" << std::endl;
        } else if (choice == 3) {
            correct_ans = num1 * num2;

            std::cout << std::setw(3) << num1 << "\n*" << std::setw(1) << num2 << "\n---" << std::endl;
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Please select a valid choice!" << std::endl;
            continue;
        }

        std::cout << "Enter answer: ";
        std::cin >> guess_ans;

        if (guess_ans == correct_ans) {
            std::cout << "Congratulations! Your answer is correct." << std::endl;
        } else {
            std::cout << "Sorry, your answer is incorrect. The right answer is "
                            << correct_ans << std::endl;
        }

        continue;
    }
    
    return 0;
}