#ifndef POINT_H
#define POINT_H

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
        void location(const Point& otherPoint);
        double distance(const Point& otherPoint);
};

#endif