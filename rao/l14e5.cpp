#include <iostream>

template <typename Array1Type, typename Array2Type>
class TwoArrays {
    private:
        Array1Type Array1[10];
        Array2Type Array2[10];
    public:
        Array1Type& GetArray1Element(unsigned int index) { return Array1[index]; }
        Array2Type& GetArray2Element(unsigned int index) { return Array2[index]; }
};

int main() {

    return 0;
}