#include <iostream>

using namespace std;

int main() {

    int numRay[] = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int arr_size = sizeof(numRay) / sizeof(numRay[0]);

    cout << "Array : ";

    for (int i = 0; i < arr_size; i++) {
        cout << numRay[i] << " ";
    }

    // count the frequency
    for (int i = 0; i < arr_size; i++) {
        numRay[numRay[i] % arr_size] = numRay[numRay[i] % arr_size] + arr_size;
    }
    
    cout << "\nThe repeating elements are : ";

    for (int i = 0; i < arr_size; i++) {
        if (numRay[i] >= arr_size * 2) {
            cout << i << " ";
        }
    }

    cout << "\n";

    return 0;
}