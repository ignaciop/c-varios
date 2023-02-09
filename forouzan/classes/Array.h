#ifndef ARRAY_H
#define ARRAY_H

class Array {
    private:
        int capacity;
        int size;
        int* arr;

    public:
        Array();
        Array(int iCapacity, int iSize);
        Array(const Array& arrayCopy);
        ~Array();

        void insert(int elem);
        void print() const;
};

#endif