#include <iostream>
using namespace std;

int main()
{
    int numOfStudents;
    int caloriesPerStudent;
    int caloriesPerPoundOfNuts;
    double caloriesPerPoundOfFruit;

    cout << "Enter the number of students: ";
    cin >> numOfStudents;
    cout << "Enter the number of calories required for each student: ";
    cin >> caloriesPerStudent;
    cout << "Enter the number of calories in each pound of nuts: ";
    cin >> caloriesPerPoundOfNuts;

    // Calculate the number of calories in each pound of fruit
    caloriesPerPoundOfFruit = caloriesPerPoundOfNuts / 0.70;

    // Calculate the total amount of calories needed
    double totalCalories = numOfStudents * caloriesPerStudent;

    // Calculate the total amount of nuts needed
    double totalNuts = totalCalories / caloriesPerPoundOfNuts;

    // Calculate the total amount of fruit needed
    double totalFruit = totalCalories / caloriesPerPoundOfFruit;

    cout << "Amount of nuts needed: " << totalNuts << " pounds" << endl;
    cout << "Amount of fruit needed: " << totalFruit << " pounds" << endl;

    return 0;
}
