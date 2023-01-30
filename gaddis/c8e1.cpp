#include <iostream>

int countPerfect(int intArray[], int size);

int main() {
    const int ARRAY_SIZE = 20;
    int array[ARRAY_SIZE] = {};
    int n = 1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        do {
            std::cout << "Enter a number between 0 and 100: ";
            std::cin >> n;
        } while (n < 0 || n > 100);

        array[i] = n;
    }

    std::cout << "Perfect counts: " << countPerfect(array, ARRAY_SIZE) << std::endl;

	return 0;
}

int countPerfect(int intArray[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (intArray[i] == 100) {
            count++;
        }
    }

    return count;
}