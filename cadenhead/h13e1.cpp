#include <iostream>
  
class SimpleCat {
public:
    SimpleCat (int age, int weight);
    ~SimpleCat() {}
    int GetAge() { return itsAge; }
    int GetWeight() { return itsWeight; }
  
private:
    int itsAge;
    int itsWeight;
};
  
SimpleCat::SimpleCat(int age, int weight): itsAge(age), itsWeight(weight) {}
  
SimpleCat * TheFunction();
  
int main() {
    SimpleCat *pCat = TheFunction();

    int age = pCat->GetAge();

    std::cout << "pCat is " << age << " years old!\n";
    std::cout << "&pCat: " << pCat << "\n";

    // How do you get rid of that memory?
    SimpleCat *pCat2 = pCat;
    delete pCat2;

    return 0;
}
  
SimpleCat *TheFunction() {
    SimpleCat *pFrisky = new SimpleCat(5,9);
    std::cout << "pFrisky: " << pFrisky << "\n";
    return pFrisky;
}