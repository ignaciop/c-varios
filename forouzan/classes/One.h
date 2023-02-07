#ifndef ONE_H
#define ONE_H

class One {
    private:
        int x;
        int y;

    public:
        One();
        One(int iX, int iY);
        One(const One& oneCopy);
        ~One();

        int getX() const;
        int getY() const;
};

#endif