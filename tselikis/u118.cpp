#include <iostream>
#include <ctime>
#include <cstdlib>

int is_sorted(int a[], int length);

int main() {
    const int LL = 5;
    const int UL = 20;
    const int ARRAY_SIZE = 10;
    int a[ARRAY_SIZE] = {};

    // Seed
    srand(time(NULL));

    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Random number between [5, 20]
        a[i] = LL + (rand() % (UL - LL + 1));
        
        std::cout << a[i] << " ";
    }

    int res = is_sorted(a, ARRAY_SIZE);

    if (res == 1) {
        std::cout << "\nThe array is sorted in ascending order." << std::endl;
    } else if (res == 2) {
        std::cout << "\nThe array is sorted in descending order." << std::endl;
    } else {
        std::cout << "\nThe array is not sorted." << std::endl;

    }
 
    return 0;
}

int is_sorted(int a[], int length) {
    bool ascending = true;
    bool descending = false;

    for (int i = 0; i < length - 1; i++) {
        if (a[i] < a[i + 1]) {
            ascending = true;
        } else {
            ascending = false;
            break;
        }
    }

    for (int i = 0; i < length - 1; i++) {
        if (a[i] > a[i + 1]) {
            descending = true;
        } else {
            descending = false;
            break;
        }
    }

    if (ascending) {
        return 1;
    }

    if (descending) {
        return 2;
    }

    return 0;
}