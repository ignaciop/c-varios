#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
    private:
        double radius;

    public:
        Circle() = delete;
        Circle(double dRadius);
        Circle(const Circle& circleCopy);
        ~Circle();

        double getPerimeter() const;
        double getArea() const;
};

#endif