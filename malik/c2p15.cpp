#include <iostream>

using namespace std;

int main() {
    const double PI = 3.141593;

    double radius, price;

    cout << "Enter the pizza radius: ";
    cin >> radius;

    cout << "Enter the pizza price: ";
    cin >> price;

    double area = PI * radius * radius;
    double price_psi = price / area;

    cout << "The pizza price per square inch is " << price_psi << endl;

    return 0;
}