#include <iostream>
  
class Tricycle{
public:
    Tricycle(int initialAge);
    ~Tricycle();
    int getSpeed();
    void setSpeed(int speed);
    int getWheelSize();
    void setWheelSize(int wheelSize);
    void pedal();
    void brake();
private:
    int speed;
    int wheelSize;
};
 
// constructor for the object
Tricycle::Tricycle(int initialSpeed) {
    setSpeed(initialSpeed);
    setWheelSize(4);
}
 
// destructor for the object
Tricycle::~Tricycle() {
    // do nothing
}

// get the trike's speed
int Tricycle::getSpeed() {
    return speed;
}
  
// set the trike's speed
void Tricycle::setSpeed(int newSpeed) {
    if (newSpeed >= 0) {
        speed = newSpeed;
    }
}

int Tricycle::getWheelSize() {
    return wheelSize;
}
  
// set the trike's speed
void Tricycle::setWheelSize(int newWheelSize) {
    if (newWheelSize >= 4) {
        wheelSize = newWheelSize;
    }
}
  
// pedal the trike
void Tricycle::pedal() {
    setSpeed(speed + 1);

    std::cout << "\nPedaling; tricycle speed " << getSpeed() << " mph\n";
}

// apply the brake on the trike
void Tricycle::brake() {
    setSpeed(speed - 1);

    std::cout << "\nBraking; tricycle speed " << getSpeed() << " mph\n";
}
  
// create a trike and ride it
int main() {
    Tricycle wichita(5);
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();
    wichita.setWheelSize(3);

    std::cout << "\nWheel size: " << wichita.getWheelSize() << "\n";
    
    wichita.setWheelSize(5);
    
    std::cout << "\nWheel size: " << wichita.getWheelSize() << "\n";

    return 0;
}