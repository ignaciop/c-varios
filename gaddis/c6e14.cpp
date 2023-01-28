#include <iostream>
#include <cmath>

double profit(int ns, double sp, double sc, double pp, double pc);

int main() {
    int ns = 0;
    double sp = 0.0;
    double sc = 0.0;
    double pp = 0.0;
    double pc = 0.0;

    do {
        std::cout << "Enter the number of shares: ";
        std::cin >> ns;
    } while (ns < 0);
    
    do {
        std::cout << "Enter the sales price per share: ";
        std::cin >> sp;
    } while (sp < 0.0);

    do {
        std::cout << "Enter the sales commission paid: ";
        std::cin >> sc;
    } while (sc < 0.0);

    do {
        std::cout << "Enter the purchase price per share: ";
        std::cin >> pp;
    } while (pp < 0.0);

    do {
        std::cout << "Enter the purchase commission paid: ";
        std::cin >> pc;
    } while (pc < 0.0);


    double profits = profit(ns, sp, sc, pp, pc);

    std::cout << "$" << fabs(profits) << ((profits > 0) ? " profit" : " loss") << std::endl;
    
    return 0;
}

double profit(int ns, double sp, double sc, double pp, double pc) {
    return (((ns * sp) - sc) - ((ns * pp) + pc));
}