#include <iostream>

int largerThanN(int intArray[], int size, int n);

int main() {
    const int ARRAY_SIZE = 10;
    int array[ARRAY_SIZE] = {};

    std::cout << "Enter a number: ";
    int n = 0;
    std::cin >> n;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Enter an integer number: ";
        std::cin >> array[i];
    }

    std::cout << "\nNumber of elements larger than " << n
                << ": " << largerThanN(array, ARRAY_SIZE, n) << std::endl;

	return 0;
}

int largerThanN(int intArray[], int size, int n) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (intArray[i] > n) {
            count++;
        }
    }

    return count;
}