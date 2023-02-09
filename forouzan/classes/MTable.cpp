#include "MTable.h"
#include <iostream>
#include <cassert>
#include <iomanip>

MTable::MTable() : MTable(1, 1) {}

MTable::MTable(int iFactor, int iSize) : factor(iFactor), size(iSize) {
    if (size < 0 || size > 10) {
        std::cout << "Cannot create a multiplication table with size > 10 or size < 0." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    } else {
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            *(arr + i) = (i + 1) * factor;
        }
    }
}
        
MTable::MTable(const MTable& tableCopy) : factor(tableCopy.factor), size(tableCopy.size), arr(new int[size]) {
    for (int i = 0; i < size; i++) {
        //copy each member of arrayToCopy into object
        arr[i] = tableCopy.arr[i];
    }
}

MTable::~MTable() {
    delete[] arr;
}

void MTable::print() const {
    for (int i = 0; i < size; i++) {
        std::cout << factor << " x " << std::setw(2) << i + 1 << " = " 
                    << std::setw(3) << *(arr + i) << std::endl;
    }

    std::cout << '\n';
}