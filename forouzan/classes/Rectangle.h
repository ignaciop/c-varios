#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    private:
        double length;
        double width;

    public:
        Rectangle() = delete;
        Rectangle(double dLength, double dWidth);
        Rectangle(const Rectangle& rectangleCopy);
        ~Rectangle();

        double getLength() const;
        double getWidth() const;
        double getPeri() const;
        double getArea() const;
};

#endif