#include <iostream>

int main() {
    // set up width and length
    unsigned short width = 26, length, height;
    length = 40;
    height = 34;

    // create an unsigned short initialized with the
    // result of multiplying width by length by height
    unsigned short volume = width * length * height;

    std::cout << "Width: " << width << "\n";
    std::cout << "Length: " << length << "\n";
    std::cout << "Height: " << height << "\n";
    std::cout << "Volume: " << volume << "\n";

    return 0;
}