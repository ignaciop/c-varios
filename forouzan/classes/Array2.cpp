#include "Array2.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

Array::Array() : Array(0, 0) {}

Array::Array(int iCapacity, int iSize) : capacity(iCapacity), size(iSize) {
    if (capacity < size) {
        std::cout << "Cannot create an array with a capacity less than its size." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    } else {
        arr = new int[size];

        const int LL = 10;
        const int UL = 99;

        srand(time(0));

        for (int i = 0; i < size; i++) {
            *(arr + i) = LL + (rand() % (UL - LL + 1));
        }
    }
}
        
Array::Array(const Array& arrayCopy) : capacity(arrayCopy.capacity), size(arrayCopy.size), arr(new int[size]) {
    for (int i = 0; i < size; i++) {
        //copy each member of arrayToCopy into object
        arr[i] = arrayCopy.arr[i];
    }
}

Array::~Array() {
    delete[] arr;
}

void Array::insert(int elem) {
    if (size < capacity) {
        *(arr + size) = elem;
        
        size++;
    } else {
        std::cout << "Cannot insert element. The array is full." << std::endl;
    }
}

void Array::selectionSort() {
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < size - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;

        for (j = i + 1; j < size; j++) {
            if (*(arr + j) < *(arr + min_idx)) {
                min_idx = j;
            }
        }
 
        // Swap the found minimum element with the first element
        swap(arr + min_idx, arr + i);
    }
}
   
void Array::print() const {
    std::cout << "{";

    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << ", ";
    }

    std::cout << ((size != 0) ? "\b\b}" : "}") << std::endl;
}

void Array::swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
