#include "classes/MTable.h"

int main() {
    MTable m1;
    m1.print();

    MTable m2(2, 3);
    m2.print();

    MTable m3(3, 7);
    m3.print();

    MTable m4(m2);
    m4.print();

    MTable m5(12, 10);
    m5.print();

    return 0;
}