#ifndef TWO_H
#define TWO_H

class Two {
    private:
        int x;
        char a;

    public:
        Two();
        Two(int iX, char iA);
        Two(const Two& twoCopy);
        ~Two();

        int getX() const;
        char getA() const;
        void setX(int iX);
        void setA(char ch);
};

#endif