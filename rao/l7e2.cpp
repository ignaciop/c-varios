#include <iostream>

double average(double arr[], int length);

int main() {
    const int ARRAY_LENGTH = 5;
    double arr[ARRAY_LENGTH] = {1, 2.1, 3.3, 4.7, 5};

    double avg = average(arr, ARRAY_LENGTH);

    std::cout << "Array: {1, 2.1, 3.3, 4.7, 5}" << std::endl;
    std::cout << "Array average: " << avg << std::endl;
   
    return 0;
}

double average(double arr[], int length) {
    double s = 0.0;

    for (int i = 0; i < length; i++) {
        s += arr[i];
    }

    return (s / length);
}