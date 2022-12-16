#include <iostream>
  
class Tricycle {
public:
    Tricycle();
    // copy constructor and destructor use default
    int getSpeed() const { return *speed; }
    void setSpeed(int newSpeed) { *speed = newSpeed; }
    Tricycle operator=(const Tricycle&);
    bool operator==(const Tricycle&);
  
private:
    int *speed;
};
  
Tricycle::Tricycle() {
    speed = new int;
    *speed = 5;
}
  
Tricycle Tricycle::operator=(const Tricycle& rhs) {
    if (this == &rhs)
        return *this;

    delete speed;

    speed = new int;
    *speed = rhs.getSpeed();

    return *this;
}

bool Tricycle::operator==(const Tricycle& rhs) {
    if (this == &rhs) {
        return true;
    }

    if (this->getSpeed() >= rhs.getSpeed()) {
        return true;
    }

    return false;
}
  
int main() {
    Tricycle wichita;
    wichita.setSpeed(7);

    Tricycle dallas;    
    dallas.setSpeed(8);

    std::cout << "Wichita is equal to Dallas?: " << std::boolalpha << (wichita == dallas) << "\n";

    return 0;
}