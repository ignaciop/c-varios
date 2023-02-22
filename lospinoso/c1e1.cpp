#include <iostream>

int absolute_value(int x) {
    return ((x >= 0) ? x : -x);
}

int main() {
    int my_num = -10;

    std::cout << "The absolute value of " << my_num << " is "
                << absolute_value(my_num) << std::endl;

    return 0;
}