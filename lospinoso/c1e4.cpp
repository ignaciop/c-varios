#include <iostream>

int sum(int x, int y) {
    return (x + y);
}

int main() {
    int my_num = -10;
    int my_num2 = 12;

    std::cout << my_num << " + " << my_num2 << " = " << sum(my_num, my_num2)
                << std::endl;

    return 0;
}