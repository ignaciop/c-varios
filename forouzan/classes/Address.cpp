#include "Address.h"
#include <iostream>

Address::Address(int iHouseNo, std::string iStreetName, std::string iCityName, std::string iStateName, int iZipCode)
    : houseNo(iHouseNo), streetName(iStreetName), cityName(iCityName), stateName(iStateName), zipCode(iZipCode) {}

Address::~Address() {}

void Address::print() const {
    std::cout << houseNo << " " << streetName << ", " << cityName << " - "
                << stateName << ", " << zipCode << std::endl;
}