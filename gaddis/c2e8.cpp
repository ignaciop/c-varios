#include <iostream>

int main() {
    float one_acre = 43560.0F;
    float sq_meter = 10.7639F;
    float half_acre = one_acre / 2;

    float sq_meters = half_acre / sq_meter;

    std::cout << "Half acre is " <<  half_acre << " square feet and " 
                << sq_meters << " square meters." << std::endl;

    return 0;
}