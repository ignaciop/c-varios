#include <iostream>

float average(int i1, int i2);
float average(long l1, long l2);
float average(float f1, float f2);

float average(int i1, int i2) {
    return (i1 + i2) / 2;
}

float average(long l1, long l2) {
    return (l1 + l2) / 2;
}

float average(float f1, float f2) {
    return (f1 + f2) / 2;
}


int main() {
    int i1 = 5;
    int i2 = 6;
    long l1 = 2147483635;
    long l2 = 2127483647;
    float f1 = 5.7;
    float f2 = 8.4;

    std::cout << "Average between two integers: " << average(i1, i2) << std::endl;
    std::cout << "Average between two long integers: " << average(l1, l2) << std::endl;
    std::cout << "Average between two floats: " << average(f1, f2) << std::endl;

    return 0;
}