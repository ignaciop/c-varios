#include <iostream>

int main() {
    std::cout << "Enter the number of purchased books: ";
    int books = 0;
    std::cin >> books;

    int points = 0;

    if (books == 0) {
        points = 0;
    } else if (books == 1) {
        points = 5;
    } else if (books == 2) {
        points = 15;
    } else if (books == 3) {
        points = 30;
    } else {
        points = 50;
    }

    std::cout << "Points awarded: " << points << std::endl;
    
    return 0;
}