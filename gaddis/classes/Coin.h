#ifndef COIN_H
#define COIN_H

#include <string>

class Coin {
    private:
       std::string sideUp;
    
    public:
        Coin();
        ~Coin();

        std::string getSideUp() const;
        void toss();
};

#endif