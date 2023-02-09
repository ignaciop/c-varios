#include <iostream>
#include "classes/Array2.h"

int main() {
    Array a2(5, 3);
    a2.print();
    a2.insert(8);
    a2.insert(6);
    a2.selectionSort();
    a2.print();

    Array a3(10, 10);
    a3.print();
    a3.selectionSort();
    a3.print();
    a3.insert(1);

    return 0;
}