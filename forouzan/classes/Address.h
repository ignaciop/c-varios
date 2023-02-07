#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
    private:
        int houseNo;
        std::string streetName;
        std::string cityName;
        std::string stateName;
        int zipCode;

    public:
        Address() = delete;
        Address(int iHouseNo, std::string iStreetName, std::string iCityName, std::string iStateName, int iZipCode);
        Address(const Address& addressCopy) = delete;
        ~Address();

        void print() const;
};

#endif