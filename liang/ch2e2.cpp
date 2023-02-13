#include <iostream>

using namespace std;

int main() {
    const float PI = 3.14159;
    float radius;
    float length;

    cout << "Enter the radius and length of a cylinder: ";
    cin >> radius >> length;

    float area = radius * radius * PI;
    float volume = area * length;

    cout << "The area is " << area << "\n";
    cout << "The volume is " << volume << "\n";

    return 0;
}