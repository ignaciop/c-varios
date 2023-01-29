#ifndef DICE_H
#define DICE_H

class Dice {
    private:
        int sides;
        int value;
    
    public:
        Dice(int iValue = 6);
        ~Dice();

        int getSides() const;
        int getValue() const;
        void roll();
};

#endif