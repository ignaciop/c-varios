#ifndef SQUARE_H
#define SQUARE_H

class Square {
    private:
       double side; 

    public:
        Square() = delete;
        Square(double dSide);
        Square(const Square& squareCopy);
        ~Square();

        double getPeri() const;
        double getArea() const;
};

#endif