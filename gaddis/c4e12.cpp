#include <iostream>

int main() {
    std::cout << "Is anyone in your party a vegetarian (y/n)? ";
    char vegetarian_choice = getchar();

    std::cin.ignore();

    std::cout << "Is anyone in your party a vegan (y/n)? ";
    char vegan_choice = getchar();

    std::cin.ignore();

    std::cout << "Is anyone in your party gluten-free (y/n)? ";
    char glutenfree_choice = getchar();

    return 0;
}