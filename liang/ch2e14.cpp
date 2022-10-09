#include <iostream>

using namespace std;

int main() {
    float weight_pounds;
    float height_inches;

    cout << "Enter weight in pounds: ";
    cin >> weight_pounds;

    cout << "Enter height in inches: ";
    cin >> height_inches;

    float bmi = (weight_pounds * 0.45359237) / ((height_inches * 0.0254)
                                                * (height_inches * 0.0254)); 

    cout << "BMI is " << bmi << "\n";
 
    return 0;
}       