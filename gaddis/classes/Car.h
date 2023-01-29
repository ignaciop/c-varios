#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
    private:
        int year;
        std::string make;
        int speed;
    
    public:
        Car(int inputYear, std::string inputMake) : 
            year(inputYear), make(inputMake), speed(0) {}
        ~Car() {};

        int getYear() const;
        std::string getMake() const;
        int getSpeed() const;

        void setSpeed(int inputSpeed);
        void accelerate();
        void brake();
};

#endif