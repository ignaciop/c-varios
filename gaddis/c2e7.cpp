#include <iostream>

int main() {
    float one_acre = 43450.0F;
    float height = 869.0F;
    float width = 360.0F;

    float size_sqft = height * width;
    float size_acres = size_sqft / one_acre;

    std::cout << size_sqft << " square feet is " << size_acres << " acres." << std::endl;

    return 0;
}