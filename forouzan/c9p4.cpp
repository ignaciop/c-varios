#include <iostream>
#include "classes/Array.h"

int main() {
    Array a1;
    a1.print();

    Array a2(5, 3);
    a2.print();
    a2.insert(8);
    a2.insert(6);
    a2.print();

    Array a3(10, 10);
    a3.print();
    a3.insert(1);
    a3.print();

    Array a4(a2);
    a4.print();

    //Array a5(2, 6);
    // The line above terminates the program correctly because capacity < size 

    return 0;
}