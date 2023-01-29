#include <iostream>
#include <iomanip>
#include "classes/Tips.h"

int main() {
    Tips t(0.15);

    int i = 1;

    while(i <= 10) {
        std::cout << "Tip:" << std::setw(2) << "$" << std::setw(7) 
                    << std::right << std::fixed << std::setprecision(2)
                        << t.computeTip(i * 500.5, i / 100.0) << std::endl;

        i++;
    }

    return 0;
}