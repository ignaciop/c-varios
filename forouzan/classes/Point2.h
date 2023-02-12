#ifndef POINT2_H
#define POINT2_H

class Point {
    private:
        int x;
        int y;

    public:
        Point();
        Point(int iX, int iY);
        Point(const Point& pointCopy);
        ~Point();

        void print();
        double distance(const Point& otherPoint);
};

#endif