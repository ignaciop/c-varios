#include <iostream>
#include <cstdlib>
#include <ctime>

double average(int n1, int n2, int n3);
int median(int n1, int n2, int n3);

int main () {
    const int LL = 1;
    const int UL = 10;

    // Seed
    srand(time(0));

    for (int i = 1; i <= 5; i++) {
        int n1 = LL + (rand() % (UL - LL + 1));
        int n2 = LL + (rand() % (UL - LL + 1));
        int n3 = LL + (rand() % (UL - LL + 1));

        std::cout << "\nAverage of {" << n1 << ", " << n2 << ", " << n3 << "}: " 
                    << average(n1, n2, n3) << std::endl;
        std::cout << "Median of {" << n1 << ", " << n2 << ", " << n3 << "}: " 
                    << median(n1, n2, n3) << std::endl;
    }
    
    return 0;
}

double average(int n1, int n2, int n3) {
    return ((n1 + n2 + n3) / 3.0F);
}

int median(int n1, int n2, int n3) {
    if (n1 <= n2 && n2 <= n3) {
        return n2;
    }

    if (n1 <= n3 && n3 <= n2) {
        return n3;
    }

    if (n2 <= n1 && n1 <= n3) {
        return n1;
    }

    if (n2 <= n3 && n3 <= n1) {
        return n3;
    }

    if (n3 <= n1 && n1 <= n2) {
        return n1;
    }

    return n2;
}