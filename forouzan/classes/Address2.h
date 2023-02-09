#ifndef ADDRESS2_H
#define ADDRESS2_H

#include <string>

class Address {
    private:
        unsigned int address;

    public:
        Address() { address = 0; } // default constructor
        Address(unsigned int a) { address = a; } // constructor with integer argument
        Address(std::string s); // constructor with string argument
    
        unsigned int getAddress() { return address; } // getter function for address
        void setAddress(unsigned int a) { address = a; } // setter function for address

        std::string toBinary(); // function to convert to binary format
        std::string toDottedDecimal(); // function to convert to dotted decimal format
};

#endif