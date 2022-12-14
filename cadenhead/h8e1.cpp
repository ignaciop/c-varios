#include <iostream>
  
class Tricycle {
public:
    int getSpeed();
    void setSpeed(int speed);
    void pedal();
    void brake();
private:
    int speed;
};
  
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
    Tricycle wichita;
    wichita.setSpeed(0);
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.brake();
    wichita.brake();

    Tricycle utah;
    utah.setSpeed(8);
    utah.pedal();
    utah.pedal();
    utah.brake();
    utah.brake();
    utah.brake();

    return 0;
}   