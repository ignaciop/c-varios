#include <iostream>

int absolute_value(int x) {
    return ((x >= 0) ? x : -x);
}

int main() {
    int my_num = -10;
    int my_num2 = 12;

    std::cout << "The absolute value of " << my_num << " is "
                << absolute_value(my_num) << std::endl;

    std::cout << "The absolute value of " << my_num2 << " is "
                << absolute_value(my_num2) << std::endl;

    return 0;
}