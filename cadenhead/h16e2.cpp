#include <iostream>
#include <string>
  
//enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

//static const char *enum_str[] = { "YORKIE", "CAIRN", "DANDIE", "SHETLAND", "DOBERMAN", "LAB" };

/*std::string getStringForEnum(int enum_val) {
    std::string tmp(enum_str[enum_val]);
    return tmp;
}*/

class Mammal {
public:
    // constructors
    Mammal(): age(2), weight(5) {}
    ~Mammal(){}
  
    // accessors
    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }
    int getWeight() const { return weight; }
    void setWeight(int newWeight) { weight = newWeight; }
  
    // other methods
    void speak() const { std::cout << "Mammal sound!\n"; }
    void sleep() const { std::cout << "Shhh. I'm sleeping.\n"; }
  
protected:
    int age;
    int weight;
};
  
class Dog : public Mammal {
public:
    // constructors
    Dog(): breed("Yorkie") {}
    ~Dog() {}
  
    // accessors
    std::string getBreed() const { return breed; }
    void setBreed(std::string newBreed) { breed = newBreed; }
  
    // other methods
    void wagTail() { std::cout << "Tail wagging ...\n"; }
    void begForFood() { std::cout << "Begging for food ...\n"; }
  
private:
    std::string breed;
};
  
int main() {
    Dog fido;
    fido.speak();
    fido.wagTail();

    std::cout << "Fido is " << fido.getAge() << " years old\n";
    std::cout << "Fido's breed: " << fido.getBreed() << "\n";

    fido.setBreed("Doberman");

    std::cout << "Fido's new breed: " << fido.getBreed() << "\n";

    return 0;
}