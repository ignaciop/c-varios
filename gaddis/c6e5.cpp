#include <iostream>
#include <string>

double getSales(std::string name);
void findHighest(double s1, double s2, double s3, double s4);

int main() {
    double d1 = getSales("Northeast");
    double d2 = getSales("Southeast");
    double d3 = getSales("Northwest");
    double d4 = getSales("Southwest");

    findHighest(d1, d2, d3, d4);

    return 0;
}

double getSales(std::string name) {
    double d = 0.0;

    do {
        std::cout << "Enter " << name << " division's quarterly sales figure: ";
        std::cin >> d;
    } while (d < 0.0);

    return d;
}

void findHighest(double s1, double s2, double s3, double s4) {
    double max1 = (s1 < s2) ? s2 : s1;
    double max2 = (s3 < s4) ? s4 : s3;
    double max = (max1 < max2) ? max2 : max1;

    if (max == s1) {
        std::cout << "Northeast is the highest grossing division. ";
    } else if (max == s2) {
        std::cout << "Southeast is the highest grossing division. ";
    } else if (max == s3) {
        std::cout << "Northwest is the highest grossing division. ";
    } else {
        std::cout << "Southwest is the highest grossing division. ";
    }

    std::cout << "Total sales: $ " << max << std::endl;
}