#include <iostream>

int main() {
    std::cout << "Enter the number of calories in a food: ";
    double calories = 0.0;
    std::cin >> calories;

    std::cout << "Enter the fat grams in a food: ";
    double fat_grams = 0.0;
    std::cin >> fat_grams;

    double calories_from_fat = fat_grams * 9;

    if (calories_from_fat > calories) {
        std::cout << "\nCalories from fat cannot be greater than the total number of calories." << std::endl;
        std::cout << "Re-run the program and try again." << std::endl;
    } else {
        double percentage_cff = calories_from_fat / calories;

        std::cout << "Calories from fat: " << percentage_cff * 100 << "%" << std::endl;

        if (percentage_cff < 0.3F) {
            std::cout << "The food is low on fat" << std::endl;
        }
    }
    
    return 0;
}