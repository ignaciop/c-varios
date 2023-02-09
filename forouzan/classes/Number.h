#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number {
    private:
        unsigned int value_;

    public:
        Number();
        
        void setNumber(const std::string &num, unsigned int base);
        std::string getNumber(unsigned int base) const;
        unsigned int toInt(char c) const;
        char toChar(unsigned int i) const;
        std::string pushFront(const std::string &str, char c) const;
        std::string popFront(const std::string &str) const;
        bool validate(const std::string &num, unsigned int base) const;
};

#endif