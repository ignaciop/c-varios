#include <iostream>

int main() {
    const double CUPS_OF_SUGAR = 1.5F;
    const double CUPS_OF_BUTTER = 1.0F;
    const double CUPS_OF_FLOUR = 2.75F;
    const int COOKIES_PRODUCED = 48;

    std::cout << "How many cookies you want to make? ";
    int cookies = 0;
    std::cin >> cookies;

    double cups_of_sugar = cookies * CUPS_OF_SUGAR / COOKIES_PRODUCED;
    double cups_of_butter = cookies * CUPS_OF_BUTTER / COOKIES_PRODUCED;
    double cups_of_flour = cookies * CUPS_OF_FLOUR / COOKIES_PRODUCED;

    std::cout << "For " << cookies << " cookies you will need: " << std::endl;
    std::cout << cups_of_sugar << " cups of sugar" << std::endl;
    std::cout << cups_of_butter << " cups of butter" << std::endl;
    std::cout << cups_of_flour << " cups of flour" << std::endl;

    return 0;
}