#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

double average(int array[], int size);
double stdDev(int array[], int size, double avg);
void print(int array[], int size);

int main() {
    const int LL = 1;
    const int UL = 100;
    const int ARRAY_SIZE = 10;

    int elements[ARRAY_SIZE] = {};

    srand(time(0));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        elements[i] = LL + (rand() % (UL - LL + 1));
    }

    double avg = average(elements, ARRAY_SIZE);
    double stdev = stdDev(elements, ARRAY_SIZE, avg);

    print(elements, ARRAY_SIZE);

    std::cout << "Average : " << avg << std::endl;
    std::cout << "Std. Dev: " << stdev << std::endl;

    return 0;
}

double average(int array[], int size) {
    double sum = 0.0;
    
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return (sum / size);
}

double stdDev(int array[], int size, double avg) {
    double sd = 0.0;
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += pow(array[i] - avg, 2);
    }

    sd = sqrt(sum) / size;

    return sd;
}

void print(int array[], int size) {    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << '\n';
}