#include <iostream>

int main() {
    int *arr[3], i, j, k, m, sum;

    i = 0;
    sum = 0;

    std::cout << "Enter number: ";
    arr[i] = &j;
    std::cin >> *arr[i];

    if (*arr[i] % 2 == 0) {
        sum += *arr[i];
    }

    i++;

    std::cout << "Enter number: ";
    arr[i] = &k;
    std::cin >> *arr[i];

    if (*arr[i] % 2 == 0) {
        sum += *arr[i];
    }

    i++;

    std::cout << "Enter number: ";
    arr[i] = &k;
    std::cin >> *arr[i];

    if (*arr[i] % 2 == 0) {
        sum += *arr[i];
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}