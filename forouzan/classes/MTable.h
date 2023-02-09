#ifndef MTABLE_H
#define MTABLE_H

class MTable {
    private:
        int factor;
        int size;
        int* arr;

    public:
        MTable();
        MTable(int iFactor, int iSize);
        MTable(const MTable& tableCopy);
        ~MTable();

        void print() const;
};

#endif