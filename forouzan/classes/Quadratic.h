#ifndef QUADRATIC_H
#define QUADRATIC_H

class Quadratic {
    private:
        double a;
        double b;
        double c;

    public:
        Quadratic();
        Quadratic(double iA, double iB, double iC);
        Quadratic(const Quadratic& quadraticCopy);
        ~Quadratic();

        void print() const;
        void roots() const;
};

#endif