#include <iostream>

int main() {
    std::cout << "Please enter the first point: ";
    double x1, y1;
    char left_paren, comma, right_paren;
    std::cin >> left_paren >> x1 >> comma >> y1 >> right_paren;

    std::cout << "Please enter the second point: ";
    double x2, y2;
    std::cin >> left_paren >> x2 >> comma >> y2 >> right_paren;

    double midpoint_x = (x1 + x2) / 2;
    double midpoint_y = (y1 + y2) / 2;

    std::cout << "The midpoint of (" << x1 << "," << y1 << ") and ("
                << x2 << "," << y2 << ") is (" << midpoint_x << "," 
                << midpoint_y << ")" << std::endl;

    return 0;
}