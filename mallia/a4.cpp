#include <iostream>
#include <array>

int sum(int a, int b) {
    return a + b;
}

int& getMaxElement(std::array<int, 10>& a1, std::array<int, 10>& a2, int index) {
    // This function requires that index must be smaller than 10!
    
    if (a1[index] >= a2[index]) {
        return a1[index];
    } else {
        return a2[index];
    }
}

int main() {
    int s = sum(3, 4);
    std::array<int, 10> a1 = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    std::array<int, 10> a2 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int& elem = getMaxElement(a1, a2, 5);

    std::cout << s << std::endl;
    std::cout << elem << std::endl;
}