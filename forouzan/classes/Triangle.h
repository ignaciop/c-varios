#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
    private:
        double firstSide;
        double secondSide;
        double thirdSide;

    public:
        Triangle();
        Triangle(double iFirstSide, double iSecondSide, double iThirdSide);
        Triangle(const Triangle& triangleCopy);
        ~Triangle();

        void getSides(double& fs, double& ss, double& ts) const;
        double getPerimeter() const;
        double getArea() const;

    private:
        bool sumSides(double iFirstSide, double iSecondSide, double iThirdSide);
};

#endif