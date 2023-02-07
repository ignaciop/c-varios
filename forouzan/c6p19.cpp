#include <iostream>
#include <cstdlib>
#include <ctime>

void fourRandomNumbers(int& n1, int& n2, int& n3, int& n4);

int main () {
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

    fourRandomNumbers(n1, n2, n3, n4);
    
    return 0;
}

void fourRandomNumbers(int& n1, int& n2, int& n3, int& n4) {
    const int LL = 1111;
    const int UL = 9999;

    // Seed
    srand(time(0));

    n1 = LL + (rand() % (UL - LL + 1));
    n2 = LL + (rand() % (UL - LL + 1));
    n3 = LL + (rand() % (UL - LL + 1));
    n4 = LL + (rand() % (UL - LL + 1));

    for (int i = 1; i <= 100; i++) {
        int n = LL + (rand() % (UL - LL + 1));

        std::cout << n << " ";

        if (i % 10 == 0) {
            std::cout << "\n";
        }
    }
}

// Cannot fully grasp what the exercise asks

/*
PRG-19. Write a function to create four-digit random integers in the range 1111 to 9999.
Eliminate any number that has a zero in it. Then create 100 numbers and print
them in a table with 10 numbers to a line.
*/