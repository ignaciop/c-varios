#ifndef ARRAY2_H
#define ARRAY2_H

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
        void selectionSort();
        void print() const;

    private:
        void swap(int* xp, int* yp);
};

#endif