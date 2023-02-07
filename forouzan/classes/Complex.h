#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    private:
        double x;
        double y;

    public:
        Complex();
        Complex(double iX, double iY);
        Complex(const Complex& complexCopy);
        ~Complex();

        Complex add(const Complex& otherComplex);
        Complex substract(const Complex& otherComplex);
        Complex multiply(const Complex& otherComplex);
        Complex divide(const Complex& otherComplex);

        void print() const;
};

#endif