#include <iostream>

class Coordinates {
private:
    float _latitude;
    float _longitude;

public:
    void set_latitude(float latitude);
    void set_longitude(float longitude);
    float get_latitude();
    float get_longitude();
    Coordinates(float latitude, float longitude): _latitude(latitude), _longitude(longitude) { }
};

void Coordinates::set_latitude(float latitude) {
    this->_latitude = latitude;
}

void Coordinates::set_longitude(float longitude) {
    this->_longitude = longitude;
}

float Coordinates::get_latitude() {
    return this->_latitude;
}

float Coordinates::get_longitude() {
    return this->_longitude;
}

class Map {

};


int main() {
    Coordinates washington_dc(38.8951, -77.0364);
    std::cout << "Object named washington_dc of type Coordinates created." << std::endl;
    
    std::cout << "Washington DC has a latitude of "
                << washington_dc.get_latitude()
                    << " and longitude of " << washington_dc.get_longitude() << std::endl;

    return 0;
}