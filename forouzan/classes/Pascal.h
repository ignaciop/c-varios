#ifndef PASCAL_H
#define PASCAL_H

class Pascal {
    private:
        int n;
        int** pascal;

    public:
        Pascal();
        Pascal(int iN);
        Pascal(const Pascal& pascalCopy);
        ~Pascal();

        void print() const;
};

#endif