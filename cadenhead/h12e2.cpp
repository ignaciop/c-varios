#include <iostream>
  
void swap(int &x, int &y, int &z);

int main() {
    int x = 5, y = 10, z = 18;
  
    std::cout << "Main. Before swap, x: " << x 
              << " y: " << y << " z: " << z << "\n";

    swap(x, y, z);

    std::cout << "Main. After swap, x: " << x 
              << " y: " << y << " z: " << z << "\n";

    return 0;
}
  
void swap(int &rx, int &ry, int &rz) {
    int temp;
  
    std::cout << "Swap. Before swap, rx: " << rx 
              << " ry: " << ry << " rz: " << rz << "\n";
  
    temp = rx;
    rx = ry;
    ry = rz;
    rz = temp;
  
    std::cout << "Swap. After swap, rx: " << rx 
              << " ry: " << ry << " rz: " << rz << "\n";
}