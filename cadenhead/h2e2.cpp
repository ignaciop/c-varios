#include <iostream>

int add(int x, int y, int z) {
    std::cout << "Running calculator...\n";

    return (x + y + z);
}

int main() {
    /* this program calls an add() function to add three different
        sets of numbers together and display the results. The
        add() function doesn't do anything unless it is called by
        a line in the main() function. */

    std::cout << "What is 867 + 5309 + 4553?\n";
    std::cout << "The sum is " << add(867, 5309, 4553) << "\n\n";
    std::cout << "What is 777 + 9311 + 786?\n";
    std::cout << "The sum is " << add(777, 9311, 786) << "\n";
    
    return 0;
}