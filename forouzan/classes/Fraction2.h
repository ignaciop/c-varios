#ifndef FRACTION2_H
#define FRACTION2_H

class Fraction {
    private:
        int numer;
        int denom;

    public:
        Fraction(int num, int den);
        Fraction();
        Fraction(const Fraction& fract);
        ~Fraction();

        int getNumer() const;
        int getDenom() const;
        void print() const;

        void setNumer(int num);
        void setDenom(int den);

        Fraction add(const Fraction& f);
        Fraction substract(const Fraction& f);
        Fraction multiply(const Fraction& f);
        Fraction divide(const Fraction& f);

    private:
        void normalize();
        int gcd(int n, int m);
};

#endif